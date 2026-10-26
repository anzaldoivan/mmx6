#!/usr/bin/env python3
"""psyqnames.py -- SDK function names (and our prototypes) for the lib rows of every program (phase 2.3 T3, container).

  psyqnames.py [--sdk DIR] [--self-test]
      inputs: config/boundaries.txt `lib <lo> <hi> <LIB/OBJ>` rows of every `# program <P> base <b> size <s>`
      section, campaign/ledger.tsv (function starts; lane starts = SLUS_013.95 rows from the first lib row to
      LANE_END, for an overlay its rows inside a lib row span), retail images extracted/retail/iso/SLUS_013.95 and
      extracted/retail/rock/<NN>.bin (raw, at the header base; missing -> the program's rows `refused:<why>`),
      DIR/LIB (objects via sdk.py: psyk extract, psyq-obj-parser, lnk_symbolize) and DIR/INCLUDE (*.H declarations).
      DIR defaults to /sdk.
      -> config/psyq/names.tsv `prog vram name library object offset size verdict aliases`: one row per named
         function (aliases = other globals at that vram, `-` when none), one row with name `-` per lane start left
         unnamed (verdict = the reason); config/psyq/protos.tsv
         `name prototype forward basis` per distinct named function. Vendor scratch: build/psyqnames/ (never tracked).
      stdout: `PSYQNAMES <rows> rows: named <n> funcs, lane starts <s>: named <a>, unnamed <u> (by reason ...)`, then
      `PSYQNAMES VERDICT`, `PSYQNAMES LIB`, `PSYQNAMES PROTOS` count lines and one `PSYQNAMES CONFLICT` line per dropped
      duplicate.
  psyqnames.py --self-test
      control LIBSPU SPU.OBJ / S_CRWA.OBJ rows name their globals at lo + value (verdict ok); a one-word mutation of
      the image inside the SPU span refuses that row; a planted row with a wrong object at the SPU address refuses;
      (d) the trivial VM_VIB.OBJ at its two SLUS rows, with ledger starts on one placement only, names that one only.
      Last line `PSYQNAMES CONTROL OK`, rc 0.
Placement: for a row, the offsets k of the object's .text where retail [lo, hi) equals .text[k, k + hi - lo) with
every relocated word masked; one k -> base lo - k, none -> mismatch, several -> ambiguous. `ok` when the whole .text
matches at base (every global text symbol named at base + value), `span` when only the row span does (only the
symbols inside [lo, hi)). Reloc check, to a fixpoint: a text reloc of a placed row whose symbol is a global named once
by the table must decode in the retail word (sdk.targets) to that address + addend, else the row is `reloc-conflict`
and names nothing (identical-under-mask stubs, cookbook C0241). Trivial objects (.text without relocs, only
`jr ra`/`nop` words): only a placement whose every named vram is a ledger function start names; a single placement
off ledger starts is `refused:trivial-off-ledger`; several placements: exactly one on ledger starts names (the others
`refused:trivial-off-ledger`), else all `ambiguous:trivial` (C0273). One vram, several globals: the first by name is kept, the rest are `aliases`.
Prototypes (C0128): each declaration re-emitted in our own words: no parameter names, typedefs resolved (u_char etc.
to unsigned types, typedef'd structs to `struct X` with `struct X;` in forward, function-pointer typedefs expanded);
no declaration -> `int name();` basis none. Stdlib only.
"""
import argparse
import os
import re
import shutil
import struct
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import sdk  # noqa: E402  (read_elf, lnk_symbolize, targets)

PROG = "SLUS_013.95"
LANE_END = 0x8006D5D4
OUT = "build/psyqnames"
DST = "config/psyq"


# ---------------------------------------------------------------- inputs

def lib_rows():
    """Every lib row, all programs, in file order; prog/pbase from the `# program <P> base <b> ...` header."""
    rows, cur, pbase = [], None, None
    for l in open("config/boundaries.txt"):
        f = l.split()
        if l.startswith("# program "):
            cur, pbase = f[2], int(f[4], 16)
        elif f and f[0] == "lib" and cur:
            lib, obj = f[3].split("/")
            rows.append(dict(lo=int(f[1], 16), hi=int(f[2], 16), lib=lib, obj=obj, prog=cur, pbase=pbase))
    return rows


def ledger(prog):
    out = set()
    for l in open("campaign/ledger.tsv"):
        f = l.rstrip("\n").split("\t")
        if f[0] == prog and len(f) > 1 and f[1].startswith("0x"):
            out.add(int(f[1], 16))
    return out


def lane_starts(prog, rows, led):
    if prog == PROG:
        lo = min(r["lo"] for r in rows)
        return sorted(v for v in led if lo <= v < LANE_END)
    return sorted(v for v in led if any(r["lo"] <= v < r["hi"] for r in rows))


def load_image(prog, base):
    """Image of a program, or a reason string."""
    p = f"extracted/retail/iso/{prog}" if prog == PROG else f"extracted/retail/rock/{prog.split('_')[1]}.bin"
    if not os.path.isfile(p):
        return f"no-image-{p}"
    return Image(open(p, "rb").read(), None if prog == PROG else base)


class Image:
    def __init__(self, exe, base=None):
        """A PS-X EXE (base None) or a raw overlay image loaded at base."""
        self.exe = exe
        if base is None:
            assert exe[:8] == b"PS-X EXE", "not a PS-X EXE"
            self.t_addr, self.t_size = struct.unpack_from("<II", exe, 0x18)
            self.hdr = 0x800
        else:
            self.t_addr, self.t_size, self.hdr = base, len(exe), 0

    def get(self, addr, n=4):
        o = addr - self.t_addr + self.hdr
        return self.exe[o:o + n] if self.t_addr <= addr and addr + n <= self.t_addr + self.t_size else None


class Objects:
    """(LIB, OBJ) -> (secs, syms, rels) or an error string; extracted + converted once under OUT."""

    def __init__(self, sdkdir):
        self.sdk, self.cache = sdkdir, {}
        shutil.rmtree(OUT, ignore_errors=True)
        os.makedirs(OUT + "/lib")

    def libfile(self, lib):
        for d in ("LIB", "lib", "."):
            p = os.path.join(self.sdk, d)
            if os.path.isdir(p):
                for f in os.listdir(p):
                    if f.lower() == lib.lower():
                        return os.path.join(p, f)
        return None

    def get(self, lib, obj):
        key = (lib.upper(), obj.upper())
        if key not in self.cache:
            self.cache[key] = self._load(lib, obj)
        return self.cache[key]

    def _load(self, lib, obj):
        lf = self.libfile(lib)
        if lf is None:
            return f"no {lib}"
        if lib.upper().endswith(".OBJ"):
            o = lf
        else:
            d = f"{OUT}/lib/{lib.split('.')[0].upper()}"
            if not os.path.isdir(d):
                os.makedirs(d)
                subprocess.run(["psyk", "extract", lf], cwd=d, check=True, stdout=subprocess.DEVNULL)
            o = next((os.path.join(d, f) for f in sorted(os.listdir(d)) if f.lower() == obj.lower()), None)
            if o is None:
                return f"{obj} not in {lib}"
        tag = f"{lib.split('.')[0]}_{obj.split('.')[0]}".upper()
        elf, log = f"{OUT}/{tag}.o", f"{OUT}/{tag}.log"

        def conv(src):
            with open(log, "w") as lg:
                return subprocess.run(["psyq-obj-parser", src, "-n", "-o", elf], stdout=lg, stderr=lg).returncode
        rc = conv(o)
        if rc and any("expression type" in l for l in open(log)):
            try:
                sdk.lnk_symbolize(o, f"{OUT}/{tag}.sym.obj")
            except ValueError as e:
                return f"lnk_symbolize {e}"
            rc = conv(f"{OUT}/{tag}.sym.obj")
        if rc:
            return f"psyq-obj-parser rc {rc}"
        return sdk.read_elf(elf)


# ---------------------------------------------------------------- placement and names

def text_of(o):
    secs, syms, rels = o
    ti = next((i for i, s in enumerate(secs) if s["name"] == ".text"), None)
    return (None, None, None) if ti is None else (ti, secs[ti], rels.get(ti, []))


def trivial(o):
    """A .text without relocs made only of `jr ra` / `nop` words: placement is weak evidence."""
    _ti, t, rl = text_of(o)
    return t is not None and not rl and all(sdk.word(t["data"], i) in (0x03E00008, 0)
                                            for i in range(0, t["size"], 4))


def trivial_check(rows, objs, led):
    """A trivial object names only at a placement on ledger starts (unique when placed at several rows)."""
    by = {}
    for r in rows:
        if r["verdict"] in ("ok", "span") and trivial(objs.get(r["lib"], r["obj"])):
            by.setdefault((r["lib"].upper(), r["obj"].upper()), []).append(r)
    for rs in by.values():
        good = [r for r in rs if r["names"] and all(n["vram"] in led for n in r["names"])]
        for r in rs:
            if len(good) == 1 and r is good[0]:
                continue
            r.update(verdict="ambiguous:trivial" if len(good) != 1 and len(rs) > 1 else "refused:trivial-off-ledger", names=[])


def place(row, o, img):
    """Sets row verdict/base/k/names (before the reloc check)."""
    row.update(base=None, names=[])
    if isinstance(o, str):
        row["verdict"] = "refused:" + re.sub(r"\s+", "-", o)
        return
    ti, t, rl = text_of(o)
    if t is None or not t["size"]:
        row["verdict"] = "refused:no-text"
        return
    mask = {off for off, _s, _t in rl}
    n = row["hi"] - row["lo"]
    r = img.get(row["lo"], n)
    if r is None or n <= 0 or n % 4:
        row["verdict"] = "refused:span-outside-image"
        return
    data, size = t["data"], t["size"]

    def same(k, ref, length):
        for o4 in range(0, length, 4):
            if k + o4 not in mask and ref[o4:o4 + 4] != data[k + o4:k + o4 + 4]:
                return False
        return True
    ks = [k for k in range(0, size - n + 1, 4) if same(k, r, n)]
    if not ks:
        row["verdict"] = "mismatch"
        return
    if len(ks) > 1:
        row["verdict"] = "ambiguous"
        return
    k = ks[0]
    base = row["lo"] - k
    whole = img.get(base, size)
    row.update(base=base, k=k, size=size, verdict="ok" if whole is not None and same(0, whole, size) else "span")
    secs, syms, _rels = o
    tsyms = sorted({s["value"] for s in syms if s["shndx"] == ti and s["name"] and s["type"] in (0, 2)})
    row["locals"] = {base + s["value"] for s in syms if s["shndx"] == ti and s["bind"] == 0 and s["name"]
                     and s["type"] in (0, 2)}
    for s in sorted(syms, key=lambda s: (s["value"], s["name"])):
        if s["shndx"] != ti or s["bind"] != 1 or not s["name"] or s["type"] not in (0, 2):
            continue
        v = base + s["value"]
        if row["verdict"] == "span" and not row["lo"] <= v < row["hi"]:
            continue
        nxt = next((x for x in tsyms if x > s["value"]), size)
        row["names"].append(dict(vram=v, name=s["name"], off=s["value"], size=nxt - s["value"]))


def reloc_check(rows, objs, img):
    """Fixpoint: a placed row whose relocated retail words contradict a name of the table -> reloc-conflict."""
    while True:
        table = {}
        for r in rows:
            if r["verdict"] in ("ok", "span"):
                for n in r["names"]:
                    table.setdefault(n["name"], set()).add(n["vram"])
        changed = False
        for r in rows:
            if r["verdict"] not in ("ok", "span"):
                continue
            o = objs.get(r["lib"], r["obj"])
            secs, syms, _rels = o
            ti, t, rl = text_of(o)
            lo_off, hi_off = (0, t["size"]) if r["verdict"] == "ok" else (r["k"], r["k"] + r["hi"] - r["lo"])

            def read(off, base=r["base"]):
                w = img.get(base + off) if lo_off <= off < hi_off else None
                return None if w is None else sdk.word(w, 0)
            try:
                tg = sdk.targets(t, rl, read)
            except ValueError as e:
                r["verdict"], changed = "refused:" + re.sub(r"\s+", "-", str(e)), True
                continue
            bad = []
            for off, si, got, a, typ in tg:
                s = syms[si]
                if got is None or s["bind"] == 0 or len(table.get(s["name"], ())) != 1:
                    continue
                want = (next(iter(table[s["name"]])) + a) & 0xFFFFFFFF
                if typ == sdk.R_26:
                    want &= 0x0FFFFFFF
                if got != want:
                    bad.append(f"{s['name']}@+{off:#x}:{got:#x}!={want:#x}")
            if bad:
                r.update(verdict="reloc-conflict", why=" ".join(bad[:3]))
                changed = True
        if not changed:
            return


def solve(rows, objs, img, led=frozenset()):
    for r in rows:
        place(r, objs.get(r["lib"], r["obj"]), img)
    trivial_check(rows, objs, led)
    reloc_check(rows, objs, img)
    rank = {"ok": 0, "span": 1}
    cands = sorted(((rank[r["verdict"]], n["vram"], n["name"], i) for i, r in enumerate(rows)
                    if r["verdict"] in rank for n in r["names"]))
    named, by_name, by_vram, conflicts, dropped, at = [], {}, {}, [], set(), {}
    for _rk, v, nm, i in cands:
        if nm in by_name:
            if by_name[nm] != v:
                conflicts.append(f"name {nm} kept {by_name[nm]:#010x} dropped {v:#010x}")
                dropped.add(v)
            continue
        if v in by_vram:
            conflicts.append(f"vram {v:#010x} kept {by_vram[v]} alias {nm}")
            by_name[nm] = v
            at[v]["aliases"].append(nm)
            continue
        by_name[nm], by_vram[v] = v, nm
        r = rows[i]
        n = next(n for n in r["names"] if n["name"] == nm)
        at[v] = dict(n, lib=r["lib"], obj=r["obj"], verdict=r["verdict"], aliases=[])
        named.append(at[v])
    named.sort(key=lambda n: (n["vram"], n["name"]))
    return named, conflicts, dropped - set(by_vram)


def lane_reasons(rows, named, starts, dropped):
    have = {n["vram"] for n in named}
    pri = ["reloc-conflict", "ambiguous", "mismatch"]
    out = []
    for v in starts:
        if v in have:
            continue
        cov = [r for r in rows if r["lo"] <= v < r["hi"]
               or r["verdict"] == "ok" and r["base"] <= v < r["base"] + r["size"]]
        if not cov:
            out.append((v, "no-lib-row", None))
            continue
        live = [r for r in cov if r["verdict"] in ("ok", "span")]
        if live:
            why = "dup-name" if v in dropped else "local-symbol" if any(v in r["locals"] for r in live) else \
                "no-global-symbol"
            out.append((v, "refused:" + why, live[0]))
            continue
        cov.sort(key=lambda r: (pri.index(r["verdict"]) if r["verdict"] in pri else len(pri), r["lo"]))
        out.append((v, cov[0]["verdict"], cov[0]))
    return out


# ---------------------------------------------------------------- prototypes (C0128: our words, never header text)

BASE = {"void", "char", "short", "int", "long", "float", "double", "unsigned", "signed", "const", "volatile",
        "struct", "union", "enum"}
FIXED = {"u_char": "unsigned char", "u_short": "unsigned short", "u_long": "unsigned long", "u_int": "unsigned int"}


def header_statements(inc):
    for root, _dirs, files in sorted(os.walk(inc)):
        for f in sorted(files):
            if not f.upper().endswith(".H"):
                continue
            p = os.path.join(root, f)
            txt = open(p, encoding="latin-1").read()
            txt = re.sub(r"/\*.*?\*/", " ", txt, flags=re.S)
            txt = re.sub(r"//[^\n]*", " ", txt)
            txt = re.sub(r"\\\n", " ", txt)
            txt = "\n".join(l for l in txt.split("\n") if not l.lstrip().startswith("#"))
            txt = re.sub(r'extern\s*"C"\s*\{', " ", txt)
            depth, start = 0, 0
            for i, c in enumerate(txt):
                if c == "{":
                    depth += 1
                elif c == "}":
                    depth -= 1
                    if depth < 0:
                        depth, start = 0, i + 1
                elif c == ";" and depth == 0:
                    yield os.path.relpath(p, inc).replace(os.sep, "/").upper(), " ".join(txt[start:i].split())
                    start = i + 1


def split_top(s, sep=","):
    out, d, cur = [], 0, ""
    for c in s:
        if c in "([{":
            d += 1
        elif c in ")]}":
            d -= 1
        if c == sep and d == 0:
            out.append(cur.strip())
            cur = ""
        else:
            cur += c
    if cur.strip():
        out.append(cur.strip())
    return out


class Protos:
    def __init__(self, inc):
        self.td, self.decl = {}, {}  # typedef name -> ("scalar", text) | ("struct", tag) | ("fn", ret, params)
        self.unknown = set()
        for hdr, st in header_statements(inc):
            if st.startswith("typedef "):
                self.typedef(st[8:])
            else:
                self.function(hdr, st)

    def typedef(self, st):
        m = re.match(r"(?:struct|union)\s*(\w*)\s*\{.*\}\s*(.*)$", st)
        if m:
            for d in split_top(m[2]):
                nm = d.lstrip("*").strip()
                if re.fullmatch(r"\w+", nm):
                    self.td.setdefault(nm, ("struct", nm) if not d.startswith("*") else ("scalar", f"struct {nm} *"))
            return
        m = re.match(r"(?:struct|union)\s+(\w+)\s+(\**)\s*(\w+)$", st)
        if m:
            self.td.setdefault(m[3], ("struct", m[1]) if not m[2] else ("scalar", f"struct {m[1]} *"))
            return
        m = re.match(r"(.+?)\(\s*\*\s*(\w+)\s*\)\s*\((.*)\)$", st)
        if m:
            self.td.setdefault(m[2], ("fn", m[1].strip(), m[3]))
            return
        m = re.match(r"(.+?)\s*\b(\w+)\s*(\[[^\]]*\])?$", st)
        if m and "{" not in st:
            self.td.setdefault(m[2], ("scalar", m[1].strip() + (" *" if m[3] else "")))

    def function(self, hdr, st):
        st = re.sub(r"^(extern|static)\s+", "", st)
        m = re.match(r"([\w\s\*]+?)\s*\b(\w+)\s*\((.*)\)$", st)
        if not m or m[2] in BASE or "{" in st or "=" in st:
            return
        self.decl.setdefault(m[2], []).append((hdr, m[1], m[3]))

    def ctype(self, text, fwd, depth=0):
        """A type (no declarator name) in our notation."""
        toks = re.findall(r"\w+|\*", text)
        out, i = [], 0
        while i < len(toks):
            t = toks[i]
            if t in ("struct", "union") and i + 1 < len(toks):
                out.append(f"{t} {toks[i + 1]}")
                fwd.add(f"{t} {toks[i + 1]};")
                i += 2
                continue
            if t in FIXED:
                out.append(FIXED[t])
            elif t == "*" or t in BASE:
                out.append(t)
            elif t in self.td and depth < 8:
                k = self.td[t]
                if k[0] == "struct":
                    out.append(f"struct {k[1]}")
                    fwd.add(f"struct {k[1]};")
                elif k[0] == "scalar":
                    out.append(self.ctype(k[1], fwd, depth + 1))
                else:
                    out.append(f"{self.ctype(k[1], fwd, depth + 1)} (*)({self.params(k[2], fwd, depth + 1)})")
            else:
                out.append(t)
                self.unknown.add(t)
            i += 1
        return re.sub(r"\s*\*", " *", " ".join(out)).replace("* *", "**").strip()

    def param(self, p, fwd, depth):
        if p == "...":
            return p
        m = re.match(r"(.+?)\(\s*\*\s*\w*\s*\)\s*\((.*)\)$", p)
        if m:
            return f"{self.ctype(m[1], fwd, depth)} (*)({self.params(m[2], fwd, depth)})"
        arr = "[" in p
        p = re.sub(r"\[[^\]]*\]", "", p).strip()
        toks = re.findall(r"\w+|\*", p)
        if len(toks) >= 2 and re.fullmatch(r"\w+", toks[-1]) and toks[-1] not in BASE | set(FIXED) \
                and toks[-2] not in ("struct", "union", "enum"):
            core = [t for t in toks[:-1] if t not in ("const", "volatile", "*")]
            if core and not all(t in ("unsigned", "signed") for t in core):
                toks = toks[:-1]
        return self.ctype(" ".join(toks), fwd, depth) + (" *" if arr else "")

    def params(self, text, fwd, depth=0):
        text = text.strip()
        if not text:
            return ""
        return ", ".join(self.param(p, fwd, depth) for p in split_top(text))

    def proto(self, name, lib):
        ds = self.decl.get(name)
        if not ds:
            return f"int {name}();", "-", "none"
        stem = lib.split(".")[0].upper()
        hdr, ret, ps = sorted(ds, key=lambda d: (d[0].split(".")[0] != stem, d[0]))[0]
        fwd = set()
        r = self.ctype(ret, fwd)
        proto = f"{r}{'' if r.endswith('*') else ' '}{name}({self.params(ps, fwd)});"
        return proto, " ".join(sorted(fwd)) or "-", f"header:{hdr}"


# ---------------------------------------------------------------- run

def run(a):
    rows = lib_rows()
    objs = Objects(a.sdk)
    named, conflicts, unnamed, starts, lines = [], [], [], [], []
    progs = list(dict.fromkeys(r["prog"] for r in rows))
    for prog in progs:
        pr_rows = [r for r in rows if r["prog"] == prog]
        img = load_image(prog, pr_rows[0]["pbase"])
        if isinstance(img, str):
            for r in pr_rows:
                r.update(verdict="refused:" + img, base=None, names=[])
            continue
        led = ledger(prog)
        p_named, p_conf, dropped = solve(pr_rows, objs, img, led)
        p_starts = lane_starts(prog, pr_rows, led)
        p_un = lane_reasons(pr_rows, p_named, p_starts, dropped)
        have = {n["vram"] for n in p_named}
        starts += [(prog, v, v in have) for v in p_starts]
        named += [dict(n, prog=prog) for n in p_named]
        unnamed += p_un
        conflicts += [f"{prog} {c}" for c in p_conf]
        lines += [(prog, n["vram"], 0, f"{prog}\t{n['vram']:#010x}\t{n['name']}\t{n['lib']}\t{n['obj']}\t"
                   f"{n['off']:#x}\t{n['size']:#x}\t{n['verdict']}\t{' '.join(n['aliases']) or '-'}")
                  for n in p_named]
        lines += [(prog, v, 1, f"{prog}\t{v:#010x}\t-\t{r['lib'] if r else '-'}\t{r['obj'] if r else '-'}\t-\t-\t"
                   f"{why}\t-") for v, why, r in p_un]
    pr = Protos(os.path.join(a.sdk, "INCLUDE"))
    os.makedirs(DST, exist_ok=True)
    order = {p: i for i, p in enumerate(progs)}
    with open(f"{DST}/names.tsv", "w") as f:
        f.write("# prog vram name library object offset size verdict aliases\n")
        f.writelines(l + "\n" for _p, _v, _k, l in sorted(lines, key=lambda x: (order[x[0]], x[1], x[2])))
    basis, seen = {}, set()
    with open(f"{DST}/protos.tsv", "w") as f:
        f.write("# name prototype forward basis\n")
        for n in sorted(named, key=lambda n: (n["name"], order[n["prog"]])):
            if n["name"] in seen:
                continue
            seen.add(n["name"])
            p, fw, b = pr.proto(n["name"], n["lib"])
            basis[b] = basis.get(b, 0) + 1
            f.write(f"{n['name']}\t{p}\t{fw}\t{b}\n")
    a_named = sum(1 for _p, _v, h in starts if h)
    why = {}
    for _v, w, _r in unnamed:
        why[w] = why.get(w, 0) + 1
    print(f"PSYQNAMES {len(rows)} rows: named {len(named)} funcs, lane starts {len(starts)}: named {a_named}, "
          f"unnamed {len(unnamed)} (by reason {', '.join(f'{k} {v}' for k, v in sorted(why.items()))})")
    vc, lc = {}, {}
    for r in rows:
        vc[r["verdict"]] = vc.get(r["verdict"], 0) + 1
        lib = r["lib"].split(".")[0].upper()
        lc.setdefault(lib, [0, 0])
        lc[lib][0] += 1
    for n in named:
        lc[n["lib"].split(".")[0].upper()][1] += 1
    print("PSYQNAMES VERDICT " + ", ".join(f"{k} {v}" for k, v in sorted(vc.items())))
    print("PSYQNAMES LIB " + ", ".join(f"{k} rows {v[0]} named {v[1]}" for k, v in sorted(lc.items())))
    print("PSYQNAMES PROTOS " + ", ".join(f"{k} {v}" for k, v in sorted(basis.items()))
          + f"; unresolved type names {len(pr.unknown)}: {' '.join(sorted(pr.unknown)) or '-'}")
    for r in rows:
        if r["verdict"] == "reloc-conflict":
            print(f"PSYQNAMES RELOC {r['prog']} {r['lo']:#010x} {r['lib']}/{r['obj']} {r['why']}")
    for c in conflicts:
        print("PSYQNAMES CONFLICT " + c)
    return 0


def self_test(a):
    rows = [r for r in lib_rows() if r["prog"] == PROG]
    exe = open(f"extracted/retail/iso/{PROG}", "rb").read()
    img = Image(exe)
    objs = Objects(a.sdk)
    ctl = [dict(r) for r in rows if r["lib"].upper() == "LIBSPU.LIB" and r["obj"].upper() in ("SPU.OBJ", "S_CRWA.OBJ")]
    assert {r["obj"].upper() for r in ctl} == {"SPU.OBJ", "S_CRWA.OBJ"}, "control rows missing"
    named, _c, _d = solve(ctl, objs, img)
    got = {(n["vram"], n["name"]) for n in named}
    for r in ctl:
        o = objs.get(r["lib"], r["obj"])
        ti = text_of(o)[0]
        want = {(r["lo"] + s["value"], s["name"]) for s in o[1]
                if s["shndx"] == ti and s["bind"] == 1 and s["name"] and s["type"] in (0, 2)}
        assert r["verdict"] == "ok" and r["base"] == r["lo"], f"control {r['obj']}: {r['verdict']} {r.get('base')}"
        assert want and want <= got, f"control {r['obj']}: names {len(want & got)}/{len(want)}"
        print(f"PSYQNAMES control {r['obj']} ok base {r['base']:#010x} names {len(want)}")
    # (b) a one-word mutation inside the SPU span refuses that row.
    spu = next(r for r in ctl if r["obj"].upper() == "SPU.OBJ")
    _ti, t, rl = text_of(objs.get(spu["lib"], spu["obj"]))
    mask = {o for o, _s, _t in rl}
    off = next(o for o in range((spu["hi"] - spu["lo"]) // 8 * 4, spu["hi"] - spu["lo"], 4) if o not in mask)
    mut = bytearray(exe)
    p = spu["lo"] - img.t_addr + 0x800 + off
    mut[p] ^= 1
    r = dict(spu)
    solve([r], objs, Image(bytes(mut)))
    assert r["verdict"] not in ("ok", "span"), f"mutation: {r['verdict']}"
    print(f"PSYQNAMES mutation +{off:#x} -> {r['verdict']}")
    # (c) a wrong (non-identical) object planted at the control address refuses.
    wrong = next(x for x in rows if x["lib"].upper() == "LIBSPU.LIB"
                 and x["obj"].upper() not in ("SPU.OBJ", "S_CRWA.OBJ"))
    wo = objs.get(wrong["lib"], wrong["obj"])
    assert not isinstance(wo, str), wo
    r = dict(lo=spu["lo"], hi=spu["lo"] + text_of(wo)[1]["size"], lib=wrong["lib"], obj=wrong["obj"])
    solve([r], objs, img)
    assert r["verdict"] not in ("ok", "span"), f"planted {wrong['obj']}: {r['verdict']}"
    print(f"PSYQNAMES planted {wrong['obj']} at {spu['lo']:#010x} -> {r['verdict']}")
    # (d) a trivial object at two rows, ledger starts on one placement only: only that one names.
    tv = [dict(x) for x in rows if x["obj"].upper() == "VM_VIB.OBJ"]
    to = objs.get(tv[0]["lib"], tv[0]["obj"])
    assert len(tv) == 2 and trivial(to), f"trivial rows {len(tv)}"
    ti = text_of(to)[0]
    offs = [s["value"] for s in to[1] if s["shndx"] == ti and s["bind"] == 1 and s["name"] and s["type"] in (0, 2)]
    on, off_ = tv[1], tv[0]
    led = {on["lo"] + v for v in offs}
    named, _c, _d = solve(tv, objs, img, led)
    assert on["verdict"] == "ok" and off_["verdict"] not in ("ok", "span"), f"trivial: {on['verdict']} {off_['verdict']}"
    assert offs and {n["vram"] for n in named} == led, f"trivial names {sorted(n['vram'] for n in named)}"
    print(f"PSYQNAMES trivial {on['obj']} {on['lo']:#010x} ok names {len(named)}, {off_['lo']:#010x} -> "
          f"{off_['verdict']}")
    print("PSYQNAMES CONTROL OK")
    return 0


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("--sdk", default="/sdk")
    ap.add_argument("--self-test", action="store_true")
    a = ap.parse_args()
    return self_test(a) if a.self_test else run(a)


if __name__ == "__main__":
    sys.exit(main())
