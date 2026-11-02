#!/usr/bin/env python3
"""lift.py -- the type lifter: offset reads on a canonical struct base become member accesses (2.5 T8.c1).

  lift.py --prog <p> [--files <path> ...] [--struct <name>] [--unk] [--dry-run]
      -> over the program's C files (`layout.includers`: every src/**/*.c whose units include one of <p>; `--files`
         narrows), each offset access in tools/psxd_floor.py's OFFSET forms (`*(T *)(b + N)`, `*(T *)((U *)b + N)`,
         `*((T *)b + N)`, `((T *)b)[N]`, `M2C_FIELD(b, T *, N)`) whose base b is typed as a struct named in col 1 of
         config/types/fields.tsv (a parameter, local or file-scope/header global; `struct X4_<S>` and include/mmx6/x4.h
         aliases count) is rewritten `b->field` (`g.field` for `&g`) iff exactly one named row has its byte offset,
         width and signedness (stores too: the floor's "field read by its offset"). `--struct` restricts to one struct.
         An untyped base (`void *` or `s32` parameter or local) is retyped `struct S *` when every access on it in
         the function lifts onto S, every other use is a call argument or an assignment target, and (a parameter) no
         prototype of the function sits in its unit's files or include/; S = the smallest object-family struct that
         fits (ObjectHeader < BaseObj < AnimatedObj < MainObj < PlayerObj, ProjectileObj share the prefix).
         Refused (counted, no edit): an unkXX/fieldXX target without `--unk`; a width or sign mismatch (C0197);
         no field starting at the offset; a struct-pointer base summed without a byte cast (scaled); address uses
         (`(u8 *)b + N`, C0178; `&*...`; `((T *)((U *)b + N))->f`); an untyped base that does not retype.
         Gate: each touched unit (role files compile through their unit, C0301/C0302) is compiled before and after
         (`make build/src/<p>/<tu>.c.o`); alloc sections or relocations differing, or no object -> that unit's files
         restored, their reads counted `reverted`. Then a clean rebuild of <p> (C objects, elf, binary removed;
         C0034) with its sha1 check; red -> every file restored, rc 1. `--dry-run`: report only, nothing compiled or
         written. Lines `LIFT refused <reason> <n>` per reason, last line exactly
         `LIFT <n> reads lifted in <f> files; reverted <r>; refused <k>`. Logs .run/<phase>/lift/.
  lift.py --self-test
      -> scratch units under .run/<phase>/lift-selftest/ (deleted after), a fixture fields table (ObjectHeader with
         `on_screen` moved to 0x04, `state` dropped): (1) `M2C_FIELD(p, s8 *, 1)` on `void *p` -> retyped, lifted to
         `p->id`, bytes equal; (2) an s16 read of the s8 `active` -> refused; (3) `unk2` -> refused, then lifted with
         `--unk`; (4) `*(s8 *)((u8 *)p + 4)` -> lifted to the fixture's `on_screen` (0x03 in the header), bytes move ->
         reverted, file byte-exact. Ends `LIFT CONTROL OK` (C0066, C0132: controls that can fail).
"""
import argparse
import glob
import os
import re
import shutil
import struct
import subprocess
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
sys.path.insert(0, os.path.dirname(HERE))
import layout  # noqa: E402  (ROOT, Tree, includers)
from psxd_floor import FIELD, OFFSET, _STRIP  # noqa: E402  (the kit, read-only)

ROOT = layout.ROOT
FIELDS = os.path.join(ROOT, "config/types/fields.tsv")
FAMILY = ("ObjectHeader", "BaseObj", "AnimatedObj", "MainObj", "PlayerObj", "ProjectileObj")   # retype order
NUM = r"(0[xX][0-9A-Fa-f]+|\d+)"
TY = r"((?:(?:un)?signed\s+)?\w+)"
SCALAR = {"s8": (1, "s"), "u8": (1, "u"), "char": (1, "s"), "signed char": (1, "s"), "unsigned char": (1, "u"),
          "s16": (2, "s"), "u16": (2, "u"), "short": (2, "s"), "unsigned short": (2, "u"),
          "s32": (4, "s"), "u32": (4, "u"), "int": (4, "s"), "unsigned int": (4, "u"), "long": (4, "s"),
          "unsigned long": (4, "u"), "unsigned": (4, "u"), "signed": (4, "s")}
# The access forms, anchored at an OFFSET match: (kind, regex); groups noted per kind.
FORMS = (
    ("A", re.compile(rf"\*\s*\(\s*{TY}\s*\*\s*\)\s*\(\s*(?:\(\s*{TY}\s*\*\s*\)\s*)?(&\s*)?(\w+)\s*([-+])\s*{NUM}\s*\)")),
    ("B", re.compile(rf"\*\s*\(\s*\(\s*{TY}\s*\*\s*\)\s*(&\s*)?(\w+)\s*\+\s*{NUM}\s*\)")),
    ("D", re.compile(rf"\(\s*\(\s*{TY}\s*\*\s*\)\s*(&\s*)?(\w+)\s*\)\s*\[\s*{NUM}\s*\]")),
    ("M", re.compile(rf"\bM2C_FIELD\s*\(\s*(&\s*)?(\w+)\s*,\s*{TY}\s*\*\s*,\s*{NUM}\s*\)")),
)
ADDR_BASE = re.compile(r"(&\s*)?([A-Za-z_]\w*)\s*[-+](?!>)")          # the base inside an address form
DEF_FUNC = re.compile(r"^(?:[A-Za-z_]\w*[\s*]+)+?([A-Za-z_]\w*)\s*\(([^;{}]*)\)\s*\{", re.M)
LOCAL = re.compile(r"(?:^|(?<=[;{}]))\s*(?:register\s+)?((?:struct\s+\w+|void|s32)\s*\**)\s*([A-Za-z_]\w*)\s*(=[^;]*)?;", re.M)
GLOBAL = re.compile(r"^(?:(?:extern|static)\s+)*((?:struct\s+)?\w+(?:\s+\w+)?)\s*(\**)\s*([A-Za-z_]\w*)\s*(\[[^\]]*\])?\s*(?:=[^;]*)?;",
                    re.M)


def phase_scratch():
    """The open phase's temp folder (as tools/run.sh), else .run."""
    try:
        with open(os.path.join(ROOT, "phase-ends/current/PHASE_PLAN.md")) as f:
            line = f.readline()
    except OSError:
        line = ""
    m = re.match(r"#\s*Phase\s+([A-Za-z0-9._-]+)", line)
    return os.path.join(".run", m.group(1)) if m and m.group(1) not in (".", "..") else ".run"


LOGDIR = os.path.join(phase_scratch(), "lift")


# ---- tables -----------------------------------------------------------------------------------------------------------

def read_rows(path):
    """{struct: [(offset, width, sign, name)]} of a fields.tsv."""
    out = {}
    with open(path) as f:
        for line in f:
            if line.startswith("#") or not line.strip():
                continue
            c = line.rstrip("\n").split("\t")
            out.setdefault(c[0], []).append((int(c[1], 0), int(c[2]), c[3], c[4]))
    return out


def aliases(structs):
    """{tag: struct}: each struct, `X4_<S>`, and include/mmx6/x4.h `#define X4_<a> <S>` lines."""
    out = {s: s for s in structs}
    out.update({"X4_" + s: s for s in structs})
    try:
        with open(os.path.join(ROOT, "include/mmx6/x4.h")) as f:
            for m in re.finditer(r"^#define\s+(X4_\w+)\s+(\w+)\s*$", f.read(), re.M):
                if m.group(2) in structs:
                    out[m.group(1)] = m.group(2)
    except OSError:
        pass
    return out


def mask(text):
    """text with comments, strings and preprocessor lines blanked (same length, newlines kept)."""
    def blank(m):
        return re.sub(r"[^\n]", " ", m.group(0))
    return re.sub(r"^[ \t]*#(?:\\\n|[^\n])*", blank, _STRIP.sub(blank, text), flags=re.M)


def classify(decl, alias):
    """('ptr'|'obj', S) | ('void'|'int', None) | None of a declaration's type text."""
    t = " ".join(decl.replace("*", " * ").split())
    m = re.fullmatch(r"(?:const )?struct (\w+)( \*)?", t)
    if m and m.group(1) in alias:
        return ("ptr" if m.group(2) else "obj", alias[m.group(1)])
    if t == "void *":
        return ("void", None)
    if t == "s32":
        return ("int", None)
    return None


def header_globals(alias):
    out = {}
    for h in sorted(glob.glob(os.path.join(ROOT, "include/**/*.h"), recursive=True)):
        with open(h) as f:
            for m in GLOBAL.finditer(mask(f.read())):
                c = classify(m.group(1) + m.group(2), alias)
                if c and c[0] in ("ptr", "obj") and not m.group(4):
                    out.setdefault(m.group(3), c)
    return out


def header_protos():
    names = set()
    for h in sorted(glob.glob(os.path.join(ROOT, "include/**/*.h"), recursive=True)):
        with open(h) as f:
            names.update(re.findall(r"\b([A-Za-z_]\w*)\s*\([^;{}()]*(?:\([^;{}()]*\)[^;{}()]*)*\)\s*;", mask(f.read())))
    return names


# ---- the scan -----------------------------------------------------------------------------------------------------------

def bodies(mtext):
    """[(name, params, head_start, body_open, body_end)] of the function definitions of a masked text."""
    out = []
    for m in DEF_FUNC.finditer(mtext):
        i, depth = m.end() - 1, 0
        for j in range(i, len(mtext)):
            if mtext[j] == "{":
                depth += 1
            elif mtext[j] == "}":
                depth -= 1
                if depth == 0:
                    out.append((m.group(1), m.group(2), m.start(2), i, j))
                    break
    return out


def access(mtext, s, alias_scale):
    """(kind, base, amp, offset_or_None, read (w, sg) | None, end, why) of the OFFSET match at s, or None (unparsed).
    alias_scale(base, amp, inner) -> bytes per unit of `base + N` (None: scaled by a struct)."""
    for kind, rx in FORMS:
        m = rx.match(mtext, s)
        if not m:
            continue
        if kind == "A":
            t, inner, amp, base, sign, n = m.groups()
            if sign == "-":
                return (kind, base, bool(amp), None, None, m.end(), "address")
            scale = alias_scale(base, bool(amp), inner)
            off = None if scale is None else int(n, 0) * scale
        elif kind in ("B", "D"):
            t, amp, base, n = m.groups()
            size = SCALAR.get(" ".join(t.split()), (None,))[0]
            off = None if size is None else int(n, 0) * size
        else:
            amp, base, t, n = m.groups()
            off = int(n, 0)
        why = "scaled" if off is None else None
        return (kind, base, bool(amp), off, SCALAR.get(" ".join(t.split())), m.end(), why)
    m = ADDR_BASE.search(mtext, s, s + 200)
    return ("X", m.group(2), bool(m.group(1)), None, None, s + 1, "address") if m else None


def unit_files(inc, prog):
    """{(prog, tu): [files]} and {file: [(prog, tu)]} of the src/ .c files."""
    by_file = {p: u for p, u in inc.items() if p.startswith("src/") and p.endswith(".c")}
    by_unit = {}
    for p, us in by_file.items():
        for u in us:
            by_unit.setdefault(tuple(u), []).append(p)
    return by_unit, by_file


class Lifter:
    def __init__(self, rows, unk=False, only=None):
        self.rows = {s: r for s, r in rows.items() if not only or s == only}
        self.alias = aliases(set(rows))
        self.unk = unk
        self.hglob = header_globals(self.alias)
        self.hproto = header_protos()
        self.refused = {}

    def refuse(self, why, n=1):
        self.refused[why] = self.refused.get(why, 0) + n

    def match(self, s, off, rd):
        """(name, None) | (None, why) of a read (w, sg) at off on struct s."""
        at = [r for r in self.rows.get(s, ()) if r[0] == off]
        if not at:
            return None, "no-field"
        hit = [r for r in at if rd and r[1] == rd[0] and r[2] == rd[1]]
        if len(hit) != 1:
            return None, "mismatch"
        if FIELD.fullmatch(hit[0][3]) and not self.unk:
            return None, "unk"
        return hit[0][3], None

    def file(self, path, text, proto_text):
        """(new text, lifted count) of one file; refusals counted on self."""
        mt = mask(text)
        fscope = {}
        outside = list(mt)
        fns = bodies(mt)
        for _, _, h, a, b in fns:
            outside[a:b + 1] = [" " if c != "\n" else c for c in mt[a:b + 1]]
        for m in GLOBAL.finditer("".join(outside)):
            c = classify(m.group(1) + m.group(2), self.alias)
            fscope[m.group(3)] = None if m.group(4) else c
        edits, lifted = [], 0
        for name, params, h, a, b in fns:
            e, n = self.function(mt, name, params, h, a, b, fscope, proto_text)
            edits += e
            lifted += n
        for s, e, rep in sorted(edits, reverse=True):
            text = text[:s] + rep + text[e:]
        return text, lifted

    def function(self, mt, name, params, h, a, b, fscope, proto_text):
        decl = {}          # name -> (classification, (start, end) of its type text, 'param'|'local')
        dup = set()
        pos = h
        simple = "(" not in params
        for piece in params.split(","):
            ids = re.findall(r"[A-Za-z_]\w*", piece)
            if simple and ids and piece.strip() != "void":
                v = ids[-1]
                tstart = pos + len(piece) - len(piece.lstrip())
                tend = pos + piece.rfind(v)
                decl[v] = (classify(piece[:piece.rfind(v)], self.alias), (tstart, tend), "param")
            pos += len(piece) + 1
        for m in LOCAL.finditer(mt, a + 1, b):
            v = m.group(2)
            if v in decl:
                dup.add(v)
            decl[v] = (classify(m.group(1), self.alias), (m.start(1), m.end(1)), "local")

        def btype(base, amp):
            if base in dup:
                return None
            if base in decl:
                c = decl[base][0]
            else:
                c = fscope[base] if base in fscope else self.hglob.get(base)
            if c is None or (c[0] in ("ptr", "obj") and c[1] not in self.rows):
                return None
            if base not in decl and c[0] in ("void", "int"):
                return None
            if amp:
                return c if c[0] == "obj" else None
            return c if c[0] in ("ptr", "void", "int") else None

        def scale(base, amp, inner):
            c = btype(base, amp)
            if inner:
                return SCALAR.get(" ".join(inner.split()), (None,))[0]
            return None if c is None or c[0] in ("ptr", "obj") else 1

        found = {}         # base -> [(start, end, offset, read, why, amp)]
        for m in OFFSET.finditer(mt, a + 1, b):
            r = access(mt, m.start(), scale)
            if not r:
                continue
            kind, base, amp, off, rd, end, why = r
            if btype(base, amp) is None:
                continue
            k = m.start() - 1
            while k > a and mt[k].isspace():
                k -= 1
            if mt[k] == "&" and mt[k - 1] != "&" and kind != "X":
                why = "address"
            found.setdefault((base, amp), []).append((m.start(), end, off, rd, why))
        edits, lifted = [], 0
        for (base, amp), accs in sorted(found.items()):
            c = btype(base, amp)
            if c[0] in ("ptr", "obj"):
                for s, e, off, rd, why in accs:
                    nm, why = (None, why) if why else self.match(c[1], off, rd)
                    if why:
                        self.refuse(why)
                        continue
                    edits.append((s, e, f"{base}.{nm}" if amp else f"{base}->{nm}"))
                    lifted += 1
                continue
            # untyped base: retype onto the smallest family struct every access lifts onto
            fit, why0 = None, "retype"
            if all(not w for _, _, _, _, w in accs) and self.other_uses_ok(mt, base, accs, decl[base], a, b) \
                    and not (decl.get(base, (0, 0, ""))[2] == "param" and self.has_proto(name, proto_text)):
                for s_ in [f for f in FAMILY if f in self.rows]:
                    names = [self.match(s_, off, rd) for _, _, off, rd, _ in accs]
                    if all(n for n, _ in names):
                        fit = (s_, names)
                        break
            if not fit:
                for s, e, off, rd, why in accs:
                    self.refuse(why or why0)
                continue
            s_, names = fit
            ts, te = decl[base][1]
            ws = mt[ts:te][len(mt[ts:te].rstrip()):]
            edits.append((ts, te, f"struct {s_}*" + ws + ("" if ws or mt[te].isspace() else " ")))
            for (s, e, *_), (nm, _) in zip(accs, names):
                edits.append((s, e, f"{base}->{nm}"))
                lifted += 1
        return edits, lifted

    @staticmethod
    def other_uses_ok(mt, base, accs, d, a, b):
        """Every use of base in the body, outside its accesses and its own declaration, is a call argument or an
        assignment target."""
        spans = [(s, e) for s, e, *_ in accs]
        te = d[1][1]
        for m in re.compile(rf"(?<![\w.>]){re.escape(base)}\b").finditer(mt, a + 1, b):
            i = m.start()
            if any(s <= i < e for s, e in spans) or (d[2] == "local" and not mt[te:i].strip()):
                continue
            before = mt[:i].rstrip()[-1:]
            after = mt[m.end():m.end() + 4].lstrip()
            if before in ("(", ",") and after[:1] in (",", ")"):
                continue
            if before in (";", "{", "}") and after[:1] == "=" and after[:2] != "==":
                continue
            return False
        return True

    def has_proto(self, name, proto_text):
        return name in self.hproto or re.search(rf"\b{re.escape(name)}\s*\([^;{{}}]*\)\s*;", proto_text) is not None


# ---- the gate ----------------------------------------------------------------------------------------------------------

def sh(cmd, log):
    os.makedirs(LOGDIR, exist_ok=True)
    with open(os.path.join(LOGDIR, log + ".log"), "a") as f:
        f.write("$ " + " ".join(cmd) + "\n")
        f.flush()
        return subprocess.run(cmd, stdout=f, stderr=subprocess.STDOUT, cwd=ROOT).returncode


def bin_out(prog):
    return f"build/rock/{prog[5:]}.bin" if prog.startswith("rock_") else f"build/{prog}"


def rebuild(prog, log):
    """Clean rebuild of prog (C objects, elf, binary removed; C0034) with its sha1 check; rc of make."""
    for p in glob.glob(f"build/src/{prog}/**/*.c.o", recursive=True) + [f"build/{prog}.elf", bin_out(prog)]:
        if os.path.exists(p):
            os.remove(p)
    return sh(["make", "-s", bin_out(prog)], log)


def put(saved, path, text):
    if path not in saved:
        saved[path] = open(path, "rb").read() if os.path.exists(path) else None
    with open(path, "w") as f:
        f.write(text)


def restore(saved, only=None):
    for p, raw in saved.items():
        if only is not None and p not in only:
            continue
        if raw is None:
            if os.path.exists(p):
                os.remove(p)
        else:
            with open(p, "wb") as f:
                f.write(raw)


def obj_sig(path):
    """(alloc sections (name, type, size, data), relocations (section, offset, type, symbol)) of an ELF32 LE object."""
    with open(path, "rb") as f:
        b = f.read()
    shoff, = struct.unpack_from("<I", b, 0x20)
    shentsize, shnum, shstrndx = struct.unpack_from("<HHH", b, 0x2E)
    secs = [struct.unpack_from("<10I", b, shoff + i * shentsize) for i in range(shnum)]
    names = secs[shstrndx][4]

    def nm(off, base):
        return b[base + off:b.index(b"\0", base + off)].decode()
    syms = []
    for s in secs:
        if s[1] == 2:                                   # SHT_SYMTAB
            strs = secs[s[6]][4]
            syms = [nm(struct.unpack_from("<I", b, s[4] + k * 16)[0], strs) for k in range(s[5] // 16)]
    alloc, rels = [], []
    for s in secs:
        n = nm(s[0], names)
        if s[2] & 2:                                    # SHF_ALLOC
            alloc.append((n, s[1], s[5], b"" if s[1] == 8 else b[s[4]:s[4] + s[5]]))
        if s[1] in (9, 4):                              # SHT_REL, SHT_RELA
            ent = 8 if s[1] == 9 else 12
            for k in range(s[5] // ent):
                off, info = struct.unpack_from("<II", b, s[4] + k * ent)
                rels.append((n, off, info & 0xFF, syms[info >> 8] if info >> 8 < len(syms) else info >> 8))
    return sorted(alloc), sorted(rels)


def compile_units(srcs, log):
    """{src: signature | None}: each unit source compiled by make (its object removed first)."""
    objs = {s: f"build/{s}.o" for s in srcs}
    for o in objs.values():
        if os.path.exists(os.path.join(ROOT, o)):
            os.remove(os.path.join(ROOT, o))
    sh(["make", "-s", "-k", "-j8"] + sorted(objs.values()), log)
    out = {}
    for s, o in objs.items():
        p = os.path.join(ROOT, o)
        out[s] = obj_sig(p) if os.path.exists(p) else None
    return out


def run(lifter, files, unit_srcs, protos, dry, log):
    """Lift files; gate each unit (unit_srcs: {file: [unit source]}). (lifted, files changed, reverted, rows)."""
    new, counts = {}, {}
    for p in files:
        with open(os.path.join(ROOT, p)) as f:
            text = f.read()
        t2, n = lifter.file(p, text, protos(p))
        if n:
            new[p], counts[p] = t2, n
    if dry or not new:
        return sum(counts.values()), len(new), 0
    units = sorted({u for p in new for u in unit_srcs[p]})
    before = compile_units(units, log)
    saved = {}
    for p, t in new.items():
        put(saved, os.path.join(ROOT, p), t)
    after = compile_units(units, log)
    bad = {u for u in units if before[u] is None or after[u] != before[u]}
    out = set()
    while bad:
        drop = {p for p in new if p not in out and set(unit_srcs[p]) & bad}
        restore(saved, {os.path.join(ROOT, p) for p in drop})
        out |= drop
        redo = sorted({u for p in drop for u in unit_srcs[p]} - bad)
        again = compile_units(redo, log) if redo else {}
        bad = {u for u in redo if again[u] != before[u]}
    kept = [p for p in new if p not in out]
    return sum(counts[p] for p in kept), len(kept), sum(counts[p] for p in out)


def report(lifter, n, f, r):
    for why, k in sorted(lifter.refused.items()):
        print(f"LIFT refused {why} {k}")
    print(f"LIFT {n} reads lifted in {f} files; reverted {r}; refused {sum(lifter.refused.values())}")


def main_prog(args):
    os.chdir(ROOT)
    inc = layout.includers(ROOT)
    by_unit, by_file = unit_files(inc, args.prog)
    tree = layout.Tree(ROOT)
    files = sorted(p for p, us in by_file.items() if any(u[0] == args.prog for u in us))
    if args.files:
        want = {os.path.relpath(os.path.abspath(p), ROOT) for p in args.files}
        files = [p for p in files if p in want]
    unit_srcs = {p: sorted({tree.unit_rel(*u) for u in by_file[p]}) for p in files}

    cache = {}

    def protos(p):
        texts = []
        for u in by_file[p]:
            if tuple(u) not in cache:
                ts = []
                for q in by_unit[tuple(u)]:
                    with open(q) as fh:
                        ts.append(mask(fh.read()))
                cache[tuple(u)] = "\n".join(ts)
            texts.append(cache[tuple(u)])
        return "\n".join(texts)
    rows = read_rows(FIELDS)
    if args.struct and args.struct not in rows:
        print(f"lift: --struct {args.struct} is not a struct of {FIELDS}")
        return 2
    lifter = Lifter(rows, args.unk, args.struct)
    pre = {p: open(p, "rb").read() for p in files}
    n, f, r = run(lifter, files, unit_srcs, protos, args.dry_run, "lift")
    if not args.dry_run and n and rebuild(args.prog, "lift"):
        for p, raw in pre.items():
            with open(p, "wb") as fh:
                fh.write(raw)
        print(f"lift: {bin_out(args.prog)} rebuild/sha1 red; every file restored (log {LOGDIR}/lift.log)")
        report(lifter, 0, 0, r + n)
        return 1
    report(lifter, n, f, r)
    return 0


# ---- self-test ---------------------------------------------------------------------------------------------------------

PLANTS = {
    "lift_a": "s32 lift_a(void *p) {\n    return M2C_FIELD(p, s8*, 1);\n}\n",
    "lift_b": "s32 lift_b(struct ObjectHeader* p) {\n    return *(s16*)((u8*)p + 0);\n}\n",
    "lift_c": "s32 lift_c(struct ObjectHeader* p) {\n    return M2C_FIELD(p, s8*, 2);\n}\n",
    "lift_d": "s32 lift_d(struct ObjectHeader* p) {\n    return *(s8*)((u8*)p + 4);\n}\n",
}
HEAD = ('#include "common.h"\n#include "mmx6/object.h"\n'
        "#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))\n\n")


def self_test():
    os.chdir(ROOT)
    scratch = os.path.join(phase_scratch(), "lift-selftest")
    shutil.rmtree(scratch, ignore_errors=True)
    os.makedirs(scratch)
    fails = []
    try:
        rows = read_rows(FIELDS)
        hdr = [r for r in rows["ObjectHeader"] if r[3] != "state"]
        hdr = [(4, w, sg, n) if n == "on_screen" else (o, w, sg, n) for o, w, sg, n in hdr]
        if not any(n == "on_screen" and o == 3 for o, _, _, n in rows["ObjectHeader"]):
            fails.append("fixture premise: ObjectHeader.on_screen is not at 0x03 in fields.tsv")
        fixture = {"ObjectHeader": hdr}
        paths = {}
        for k, body in PLANTS.items():
            paths[k] = os.path.join(scratch, k + ".c")
            with open(paths[k], "w") as f:
                f.write(HEAD + body)
        srcs = {p: [p] for p in paths.values()}
        orig = {p: open(p).read() for p in paths.values()}

        def go(keys, unk):
            lf = Lifter(fixture, unk)
            res = run(lf, [paths[k] for k in keys], srcs, lambda p: "", False, "selftest")
            return lf, res

        def check(what, cond):
            if not cond:
                fails.append(what)
        lf, res = go(["lift_a"], False)
        t = open(paths["lift_a"]).read()
        check(f"(1) liftable: {res} {lf.refused}", res == (1, 1, 0) and "p->id" in t and "struct ObjectHeader* p" in t)
        lf, res = go(["lift_b"], False)
        check(f"(2) width mismatch: {res} {lf.refused}", res == (0, 0, 0) and lf.refused == {"mismatch": 1}
              and open(paths["lift_b"]).read() == orig[paths["lift_b"]])
        lf, res = go(["lift_c"], False)
        check(f"(3) unk refused: {res} {lf.refused}", res == (0, 0, 0) and lf.refused == {"unk": 1}
              and open(paths["lift_c"]).read() == orig[paths["lift_c"]])
        lf, res = go(["lift_c"], True)
        check(f"(3) unk with --unk: {res} {lf.refused}", res == (1, 1, 0) and "p->unk2" in open(paths["lift_c"]).read())
        lf, res = go(["lift_d"], False)
        check(f"(4) byte-moving: {res} {lf.refused}", res == (0, 0, 1)
              and open(paths["lift_d"]).read() == orig[paths["lift_d"]])
    finally:
        shutil.rmtree(scratch, ignore_errors=True)
        shutil.rmtree(os.path.join("build", scratch), ignore_errors=True)
        for d in (os.path.join("build", phase_scratch()), os.path.join("build", ".run")):
            if os.path.isdir(d) and not os.listdir(d):
                os.rmdir(d)
    for x in fails:
        print(f"LIFT CONTROL FAIL {x}")
    if fails:
        return 1
    print("LIFT CONTROL OK")
    return 0


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--prog")
    ap.add_argument("--files", nargs="+")
    ap.add_argument("--struct")
    ap.add_argument("--unk", action="store_true")
    ap.add_argument("--dry-run", action="store_true")
    ap.add_argument("--self-test", action="store_true")
    args = ap.parse_args()
    if args.self_test:
        return self_test()
    if not args.prog:
        ap.error("--prog is required (or --self-test)")
    return main_prog(args)


if __name__ == "__main__":
    sys.exit(main())
