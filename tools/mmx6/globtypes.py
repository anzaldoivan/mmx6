#!/usr/bin/env python3
"""globtypes.py -- one global, one type: every global declaration keyed by address (stdlib, text only).

  globtypes.py --all
      -> scans src/**/*.{c,h} + include/**/*.h; one line per conflict, then last line
         `GLOBTYPES <g> globals <d> declarations; conflicts <n> (view <v>)`; the same lines go to
         build/globtypes/conflicts.txt. rc 1 iff the non-view count rises above config/globtypes-baseline.txt
         (`GLOBTYPES RISE <old> -> <new>`).
  globtypes.py --self-test [--all]
      -> in memory, real texts + planted texts: one sign, one width, one shape conflict and one view (a struct view
         macro over an s32 extern); asserts conflicts rise by exactly 3 non-view + 1 view, and that a name spelling an
         address keys apart from a planted table name at that address (C0248). Ends `GLOBTYPES CONTROL OK`. With
         --all the run reuses the self-test's real gather (C0283).

Declarations gathered: file-scope externs, file-scope definitions (no `static`), block-scope externs, view macros
`#define N (*(T *)0x8xxxxxxx)` or `(*(T *)&sym)`, alias defines `#define a b` (b a declared object name).
Key = address, from tables only, never from a name's spelling (C0248): config/symbols.<prog>.txt, then
config/symbols.SLUS_013.95.txt, then the link maps build/<prog>.map, build/SLUS_013.95.map (when built). An address
below the lowest overlay vram is the exe's (key `0x<addr>`), else the program's (`<prog>:0x<addr>`). A name no table
gives keys `<prog>:<name>`; such declarations are counted on `GLOBTYPES UNRESOLVED <u> declarations`. A view literal
keys its own address; an alias keys its target's key. Program: src/<prog>/; src/shared/ = each includer's program
(layout.includers()); include/ = SLUS_013.95.
Conflict classes (per key, over the typed declarations; aliases carry no type): `shape` (struct/unknown vs other,
array vs non-array), `width` (scalar sizes differ, or both array counts known and differ), `sign` (same width,
different signedness or pointer vs integer). Worst pair wins (shape > width > sign). Tagged `view` when the key also
holds a view macro (C0208, C0270 self-view), an alias define (C0225) or a per-field blob extern (C0117: a scalar extern
whose file declares another extern within 0x10 bytes above it).
Sizes: s8/u8/s16/u16/s32/u32 and every typedef/struct from typecheck.py's parse of the tree; char/short/int/long;
pointers 4; a type macro spelled one way across the tree (`#define M2C_UNK s32`) is its body; an unknown type counts
as its name.
"""
import argparse
import glob
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import layout  # noqa: E402
import typecheck  # noqa: E402

ROOT = typecheck.ROOT
EXE = "SLUS_013.95"
OUT = "build/globtypes/conflicts.txt"
BASELINE = "config/globtypes-baseline.txt"
QUAL = {"const", "volatile", "register", "extern"}
SYM_LINE = re.compile(r"^\s*([A-Za-z_]\w*)\s*=\s*0[xX]([0-9A-Fa-f]+)\s*;")
MAP_LINE = re.compile(r"^\s+0x([0-9A-Fa-f]{8,16})\s+(?:PROVIDE \()?([A-Za-z_]\w*)\s*(?:=|$)")
DEFINE = re.compile(r"^[ \t]*#[ \t]*define[ \t]+([A-Za-z_]\w*)(?![\w(])[ \t]*(.*)$", re.M)
VIEW = re.compile(r"\(\s*\*\s*\(\s*([A-Za-z_][\w\s]*?)\s*(\*+)\s*\)\s*(0[xX][0-9A-Fa-f]+|&\s*[A-Za-z_]\w*)\s*\)")
EXTERN = re.compile(r"\bextern\b([^;{}]*);")
FNPTR = re.compile(r"\(\s*(\*+)\s*([A-Za-z_]\w*)\s*\)\s*\(")
RANK = {"sign": 1, "width": 2, "shape": 3}


def uncomment(text):
    """Comments -> spaces (newlines kept); preprocessor lines kept."""
    return re.sub(r"/\*.*?\*/|//[^\n]*", lambda m: re.sub(r"[^\n]", " ", m.group(0)), text, flags=re.S)


def blank_pp(text):
    lines, cont = text.split("\n"), False
    for k, ln in enumerate(lines):
        if cont or ln.lstrip().startswith("#"):
            cont = ln.rstrip().endswith("\\")
            lines[k] = ""
    return "\n".join(lines)


# ---- types --------------------------------------------------------------------------------------------------------

def known_types(files):
    known = {}
    for p in sorted(files):
        if p.endswith(".h"):
            for _ in typecheck.defs_of(typecheck.strip(files[p]), known):
                pass
    return known


def type_macros(files, known):
    """`#define T <type>` spelled the same everywhere (M2C_UNK = s32) -> {T: <type>} when <type> is a known type."""
    bodies = {}
    for t in files.values():
        if "#" in t:
            for m in DEFINE.finditer(uncomment(t)):
                bodies.setdefault(m.group(1), set()).add(" ".join(m.group(2).split()))
    return {n: next(iter(b)) for n, b in bodies.items() if len(b) == 1 and (
        next(iter(b)) in known or next(iter(b)).split() and set(next(iter(b)).split()) <= typecheck.SCALAR_WORDS)}


def base_canon(base, known):
    base = known.get("#" + base, base)
    if base in known and known[base] is not None:
        key = known[base][0]
        if key[0] == "scalar":
            return ("int", key[1], key[2])
        if key[0] == "float":
            return ("float", key[1])
        if key[0] == "ptr":
            return ("ptr",)
        if key[0] == "array":
            return ("array", ("blob", key[1]), None)
        return ("struct", key)
    words = base.split()
    if words and set(words) <= typecheck.SCALAR_WORDS:
        try:
            key = typecheck.scalar(words)
        except typecheck.Unkeyable:
            return ("named", base)
        return ("int", key[1], key[2]) if key[0] == "scalar" else ("float", key[1])
    if words and words[0] in ("struct", "union"):
        return ("struct", base)
    return ("named", base)


def canon(base, depth, dims, known):
    if dims:
        return ("array", canon(base, depth, dims[1:], known), dims[0])
    if depth:
        return ("ptr",)
    return base_canon(base, known)


def show(base, depth, dims):
    return base + "*" * depth + "".join("[%s]" % ("" if d is None else hex(d) if d > 9 else d) for d in dims)


def scal(c):
    if c[0] == "int":
        return (c[1], "s" if c[2] else "u")
    if c[0] == "ptr":
        return (4, "p")
    if c[0] == "float":
        return (c[1], "f")
    return None


def cls(a, b):
    if a == b:
        return None
    if a[0] == "array" and b[0] == "array":
        return cls(a[1], b[1]) or ("width" if a[2] and b[2] and a[2] != b[2] else None)
    if "array" in (a[0], b[0]):
        return "shape"
    sa, sb = scal(a), scal(b)
    if sa is None or sb is None:
        return "shape"
    return "width" if sa[0] != sb[0] else "sign"


def parse_type(toks):
    """tokens of `<quals> <base> <declarators,...>` -> (base, [(name, depth, dims)]) or None."""
    i = 0
    while i < len(toks) and toks[i] in QUAL:
        i += 1
    if i < len(toks) and toks[i] in ("struct", "union"):
        if i + 1 >= len(toks):
            return None
        base, i = toks[i] + " " + toks[i + 1], i + 2
    elif i < len(toks) and toks[i] in typecheck.SCALAR_WORDS:
        j = i
        while j < len(toks) and toks[j] in typecheck.SCALAR_WORDS:
            j += 1
        base, i = " ".join(toks[i:j]), j
    elif i < len(toks) and re.fullmatch(r"[A-Za-z_]\w*", toks[i]):
        base, i = toks[i], i + 1
    else:
        return None
    decls, cur = [], []
    for t in toks[i:] + [","]:
        if t != ",":
            cur.append(t)
            continue
        cur = [x for x in cur if x not in QUAL]
        depth = 0
        while cur and cur[0] == "*":
            depth, cur = depth + 1, cur[1:]
        if not cur or not re.fullmatch(r"[A-Za-z_]\w*", cur[0]) or any(not x.startswith("[") for x in cur[1:]):
            return None
        dims = []
        for d in cur[1:]:
            s = d[1:-1].strip()
            dims.append(int(s, 0) if re.fullmatch(r"0[xX][0-9A-Fa-f]+|\d+", s) else None)
        decls.append((cur[0], depth, dims))
        cur = []
    return base, decls


# ---- gather -------------------------------------------------------------------------------------------------------

def parse_file(text):
    """-> [(kind, name, line, base, depth, dims, target)]; kind extern|block|def|view|alias; target = literal int,
    a symbol name (view over &sym, alias), or None."""
    cm = uncomment(text)
    line = lambda off: cm.count("\n", 0, off) + 1  # noqa: E731
    out = []
    for m in DEFINE.finditer(cm):
        name, body = m.group(1), m.group(2).strip()
        v = VIEW.fullmatch(body)
        if v:
            ty = parse_type(typecheck.TOKEN.findall(v.group(1)) + ["_v_"])
            if ty:
                tgt = v.group(3)
                tgt = int(tgt, 16) if tgt[0] == "0" else tgt[1:].strip()
                out.append(("view", name, line(m.start()), ty[0], len(v.group(2)) - 1, [], tgt))
        elif re.fullmatch(r"[A-Za-z_]\w*", body):
            out.append(("alias", name, line(m.start()), None, 0, [], body))
    code = blank_pp(cm)
    line = lambda off: code.count("\n", 0, off) + 1  # noqa: E731 (blank_pp keeps lines, not offsets)
    depth_at, depth, last = 0, 0, 0
    for m in EXTERN.finditer(code):
        seg = code[last:m.start()]
        depth_at += seg.count("{") - seg.count("}")
        last = m.start()
        body = m.group(1)
        if "(" in body:
            f = FNPTR.search(body)
            if not f:
                continue
            decls = [(f.group(2), len(f.group(1)), [])]
            base = "fnptr"
        else:
            ty = parse_type(typecheck.TOKEN.findall(body))
            if not ty:
                continue
            base, decls = ty
        for name, d, dims in decls:
            out.append(("block" if depth_at > 0 else "extern", name, line(m.start()), base, d, dims, None))
    # file-scope definitions: depth-0 statements, function bodies skipped
    start, in_fn, depth = 0, False, 0
    for i, c in enumerate(code):
        if c == "{":
            if depth == 0:
                head = code[start:i]
                in_fn = "(" in head and "=" not in head
            depth += 1
        elif c == "}":
            depth -= 1
            if depth == 0 and in_fn:
                start, in_fn = i + 1, False
        elif c == ";" and depth == 0:
            chunk, off = code[start:i], start + len(code[start:i]) - len(code[start:i].lstrip())
            head = chunk.split("=", 1)[0]
            toks = typecheck.TOKEN.findall(head)
            start = i + 1
            if not toks or toks[0] in ("typedef", "extern", "static", "enum") or "(" in head or "{" in head:
                continue
            ty = parse_type(toks)
            if ty:
                for name, d, dims in ty[1]:
                    out.append(("def", name, line(off), ty[0], d, dims, None))
    return out


def progs_of(path, inc):
    parts = path.split("/")
    if parts[0] == "include":
        return [EXE]
    if parts[1] == "shared":
        ps = sorted({p for p, _ in inc.get(path, [])})
        return ps or [EXE]
    return [parts[1]]


def load_tables(root, files):
    tabs, maps = {}, {}
    progs = {EXE} | {p.split("/")[1] for p in files if p.startswith("src/") and p.split("/")[1] != "shared"}
    for prog in sorted(progs):
        t = {}
        path = os.path.join(root, "config", "symbols.%s.txt" % prog)
        if os.path.isfile(path):
            for ln in open(path, encoding="utf-8"):
                m = SYM_LINE.match(ln)
                if m:
                    t[m.group(1)] = int(m.group(2), 16)
        tabs[prog] = t
        mp = {}
        path = os.path.join(root, "build", "%s.map" % prog)
        if os.path.isfile(path):
            for ln in open(path, encoding="utf-8", errors="replace"):
                m = MAP_LINE.match(ln)
                if m:
                    mp.setdefault(m.group(2), int(m.group(1), 16) & 0xFFFFFFFF)
        maps[prog] = mp
    return tabs, maps


def ovl_base(root):
    vs = []
    for y in glob.glob(os.path.join(root, "config", "rock_*.yaml")):
        m = re.search(r"vram:\s*0[xX]([0-9A-Fa-f]+)", open(y, encoding="utf-8").read())
        if m:
            vs.append(int(m.group(1), 16))
    return min(vs) if vs else 0x80100000


class Ctx:
    """The shared gather (C0283): parsed files, tables, types; reused by the self-test and the run."""

    def __init__(self, files, root=ROOT):
        self.files = files
        self.parsed = {p: parse_file(t) for p, t in files.items()}
        self.inc = layout.includers(root)
        self.tabs, self.maps = load_tables(root, files)
        self.known = known_types(files)
        self.known.update({"#" + n: b for n, b in type_macros(files, self.known).items()})
        self.base = ovl_base(root)
        self.nmaps = sum(1 for m in self.maps.values() if m)


def addr_key(prog, a, base):
    return ("", a) if a < base else (prog, a)


def resolve(ctx, prog, name, tabs):
    for t in (tabs.get(prog, {}), tabs.get(EXE, {}), ctx.maps.get(prog, {}), ctx.maps.get(EXE, {})):
        if name in t:
            return addr_key(prog, t[name], ctx.base)
    return None


def analyse(ctx, files, extra_tabs=None):
    """files: {path: parsed decls} -> (conflict lines, summary, n, v, unresolved)."""
    tabs = {k: dict(v) for k, v in ctx.tabs.items()}
    for k, v in (extra_tabs or {}).items():
        tabs.setdefault(k, {}).update(v)
    objects = {d[1] for decls in files.values() for d in decls if d[0] in ("extern", "block", "def")}
    by_key, unresolved, seen = {}, 0, set()
    for path in sorted(files):
        resolved_here = []
        for prog in progs_of(path, ctx.inc):
            for kind, name, ln, base, depth, dims, tgt in files[path]:
                if kind == "alias" and not (tgt in objects or name in objects):
                    continue
                if kind == "view" and isinstance(tgt, int):
                    key = addr_key(prog, tgt, ctx.base)
                else:
                    sym = tgt if kind in ("alias", "view") else name
                    key = resolve(ctx, prog, sym, tabs)
                    if key is None:
                        key = (prog, sym)
                ident = (key, path, ln, name, kind)
                if ident in seen:
                    continue
                seen.add(ident)
                if isinstance(key[1], str):
                    unresolved += 1
                c = None if kind == "alias" else canon(base, depth, dims, ctx.known)
                text = ("alias->%s" % tgt) if kind == "alias" else show(base, depth, dims) + (
                    " view" if kind == "view" else "")
                rec = (kind, name, path, ln, c, text)
                by_key.setdefault(key, []).append(rec)
                if kind == "extern" and isinstance(key[1], int):
                    resolved_here.append((key, rec))
        # C0117 per-field blob externs: a scalar extern with another extern of its file within 0x10 bytes above
        for key, rec in resolved_here:
            if rec[4] and rec[4][0] in ("int", "ptr") and any(
                    k[0] == key[0] and 0 < k[1] - key[1] <= 0x10 for k, _ in resolved_here):
                by_key[key][by_key[key].index(rec)] = ("field",) + rec[1:]
    lines, n, v, d = [], 0, 0, 0
    for key in sorted(by_key, key=lambda k: (isinstance(k[1], str), k[0], k[1])):
        recs = by_key[key]
        d += len(recs)
        typed = [r for r in recs if r[4] is not None]
        worst = None
        for i in range(len(typed)):
            for j in range(i + 1, len(typed)):
                c = cls(typed[i][4], typed[j][4])
                if c and (worst is None or RANK[c] > RANK[worst]):
                    worst = c
        if not worst:
            continue
        view = any(r[0] in ("view", "alias", "field") for r in recs)
        n += 1
        v += view
        groups = {}
        for r in recs:
            groups.setdefault(r[5], []).append(r)
        parts = ["%s %s:%d%s" % (t, g[0][2], g[0][3], " +%d" % (len(g) - 1) if len(g) > 1 else "")
                 for t, g in sorted(groups.items(), key=lambda kv: (kv[1][0][2], kv[1][0][3]))]
        names = ",".join(sorted({r[1] for r in recs}))
        where = ("0x%08X" % key[1]) if not key[0] else ("%s:0x%08X" % key if isinstance(key[1], int) else "%s:%s" % key)
        lines.append("GLOBTYPES CONFLICT %s%s %s %s: %s" % (worst, " view" if view else "", where, names,
                                                           "; ".join(parts)))
    summary = "GLOBTYPES %d globals %d declarations; conflicts %d (view %d)" % (len(by_key), d, n, v)
    return lines, summary, n, v, unresolved


# ---- entry points -------------------------------------------------------------------------------------------------

_REAL = {}


def real_ctx():
    if "ctx" not in _REAL:
        _REAL["ctx"] = Ctx(typecheck.read(typecheck.all_paths()))
    return _REAL["ctx"]


def baseline():
    path = os.path.join(ROOT, BASELINE)
    if not os.path.isfile(path):
        return None
    m = re.search(r"^conflicts\s+(\d+)", open(path, encoding="utf-8").read(), re.M)
    return int(m.group(1)) if m else None


def run_all():
    ctx = real_ctx()
    lines, summary, n, v, u = analyse(ctx, ctx.parsed)
    out = lines + ["GLOBTYPES UNRESOLVED %d declarations (link maps %d of %d)" % (u, ctx.nmaps, len(ctx.maps)),
                   summary]
    for ln in out:
        print(ln)
    os.makedirs(os.path.join(ROOT, os.path.dirname(OUT)), exist_ok=True)
    with open(os.path.join(ROOT, OUT), "w", encoding="utf-8") as f:
        f.write("\n".join(out) + "\n")
    old = baseline()
    if old is not None and n - v > old:
        print("GLOBTYPES RISE %d -> %d" % (old, n - v))
        return 1
    return 0


PLANTS = {
    "src/%s/zz_globtypes_plant_a.c" % EXE: (
        "extern s8 g_plant_sign;\nextern s16 g_plant_width;\nextern u8 g_plant_shape[];\nextern s32 g_plant_view;\n"
        "extern s8 D_8000F000;\n"),
    "src/%s/zz_globtypes_plant_b.c" % EXE: (
        "u8 g_plant_sign;\ns32 g_plant_width;\nvoid f(void) {\n    extern s32 g_plant_shape;\n}\n"
        "#define g_plant_view (*(struct X4_ObjectHeader *)&g_plant_view)\nextern s32 alpha_global;\n"),
}


def self_test():
    ctx = real_ctx()
    _, s0, n0, v0, _ = analyse(ctx, ctx.parsed)
    files = dict(ctx.parsed)
    files.update({p: parse_file(t) for p, t in PLANTS.items()})
    lines, s1, n1, v1, _ = analyse(ctx, files, {EXE: {"alpha_global": 0x8000F000}})
    planted = [ln for ln in lines if "g_plant_" in ln or "alpha_global" in ln or "D_8000F000" in ln]
    got = sorted(ln.split()[2] + (" view" if ln.split()[3] == "view" else "") for ln in planted)
    ok = (n1 - n0, v1 - v0) == (4, 1) and got == ["shape", "shape view", "sign", "width"]
    for ln in planted:
        print("control: " + ln)
    if not ok:
        print("GLOBTYPES CONTROL FAIL: %s -> %s; planted %s" % (s0, s1, got))
        return 1
    print("GLOBTYPES CONTROL OK")
    return 0


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--all", action="store_true")
    ap.add_argument("--self-test", action="store_true")
    a = ap.parse_args()
    if not (a.all or a.self_test):
        ap.error("one of --all, --self-test")
    if a.self_test and self_test():
        return 1
    return run_all() if a.all else 0


if __name__ == "__main__":
    sys.exit(main())
