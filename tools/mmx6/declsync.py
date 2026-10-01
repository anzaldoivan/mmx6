#!/usr/bin/env python3
"""declsync.py -- move a defined function's declarations across a program's C files to its definition's signature
(reconcile rung R3, tools/mmx6/bank.py; container python3, stdlib only, text only).

  declsync.py --prog <p> --def <body.c> [--dry-run]
      -> per C definition in <body.c>, over every src/<p>/*.c and each file they `#include "<rel>"` from src/:
         each prototype `<ret> <func>(<params>);` and each call-site cast `((<ret> (*)(<params>))<func>)` that
         differs from the definition is rewritten to the definition's signature (cast removed) when width-compatible
         (same return width, same param count, each param width equal; pointers/s32/u32/int = 4), else refused.
         One line per change `DECLSYNC synced|uncast|refused <path>:<line> <func> [<why>]`; last line
         `DECLSYNC <funcs> synced <s> uncast <c> refused <r> files <k>`; rc 0 iff r = 0. Nothing is written when any
         declaration is refused, or under --dry-run.
  declsync.py --self-test
      -> in memory: width-compatible prototype synced, width-incompatible (`s16` param) refused, cast removed.
         Ends `DECLSYNC CONTROL OK` (rc 0), else rc 1.
"""
import argparse
import glob
import os
import re
import sys

WIDTH = {"void": 0, "char": 1, "s8": 1, "u8": 1, "signed char": 1, "unsigned char": 1, "short": 2, "s16": 2,
         "u16": 2, "unsigned short": 2, "int": 4, "s32": 4, "u32": 4, "long": 4, "unsigned": 4, "unsigned int": 4,
         "unsigned long": 4, "signed": 4, "signed int": 4}
TYPE = r"[A-Za-z_][\w \t\*]*?"
DEF_RE = re.compile(rf"^(?:static\s+)?({TYPE})\s*\b([A-Za-z_]\w*)\s*\(([^;{{}}()]*)\)\s*\{{", re.M)
INCL_RE = re.compile(r"^#include \"([^\"]+)\"", re.M)


def width(t):
    """Byte width of a C type text (pointer 4), None when unknown."""
    t = " ".join(t.replace("*", " * ").split())
    t = re.sub(r"\b(const|volatile|extern|static|register)\b ?", "", t).strip()
    if "*" in t:
        return 4
    return WIDTH.get(t)


def ptype(p):
    """Type of one parameter text (its trailing name dropped)."""
    p = " ".join(p.replace("*", " * ").split())
    m = re.fullmatch(r"(.*?[\w\*])\s+([A-Za-z_]\w*)", p)
    if m and m.group(2) not in WIDTH and width(m.group(1)) is not None:
        return m.group(1)
    return p


def params(s):
    s = s.strip()
    return [] if s in ("", "void") else [ptype(p) for p in s.split(",")]


def norm(t):
    return " ".join(t.replace("*", " * ").split())


def sig(ret, ps):
    """(ret, [param types]) normalised."""
    return norm(ret), [norm(p) for p in params(ps)]


def compatible(a, b):
    """'' when sig b may be moved to sig a by width, else the reason."""
    (ra, pa), (rb, pb) = a, b
    if width(ra) is None or width(rb) is None or width(ra) != width(rb):
        return f"return {rb} vs {ra}"
    if len(pa) != len(pb):
        return f"{len(pb)} params vs {len(pa)}"
    for i, (x, y) in enumerate(zip(pa, pb)):
        if width(x) is None or width(y) is None or width(x) != width(y):
            return f"param {i} {y} vs {x}"
    return ""


def definitions(text):
    """[(name, ret, params text)] of the C definitions in text."""
    return [(m.group(2), m.group(1).strip(), m.group(3).strip()) for m in DEF_RE.finditer(text)]


def unit_files(prog):
    """src/<prog>/*.c plus each file they #include from src/ (relative to the including file), sorted."""
    out, todo = set(), sorted(glob.glob(f"src/{prog}/*.c"))
    while todo:
        p = todo.pop()
        if p in out or not os.path.isfile(p):
            continue
        out.add(p)
        with open(p, errors="replace") as f:
            for rel in INCL_RE.findall(f.read()):
                q = os.path.relpath(os.path.normpath(os.path.join(os.path.dirname(p), rel)))
                if q.startswith("src" + os.sep):
                    todo.append(q)
    return sorted(out)


def sync_text(path, text, defs):
    """(new text, [lines], refused count) of one file against defs [(name, ret, params)]."""
    lines, refused = [], 0
    for name, ret, ps in defs:
        want = sig(ret, ps)
        proto = re.compile(rf"^((?:extern\s+)?)({TYPE})\s*\b{name}\s*\(([^;{{}}()]*)\)\s*;", re.M)
        cast = re.compile(rf"\(\(\s*({TYPE})\s*\(\s*\*\s*\)\s*\(([^;{{}}()]*)\)\s*\)\s*{name}\s*\)")

        def at(m):
            return text.count("\n", 0, m.start()) + 1

        def fix_proto(m):
            nonlocal refused
            got = sig(m.group(2), m.group(3))
            if got == want:
                return m.group(0)
            why = compatible(want, got)
            if why:
                refused += 1
                lines.append(f"DECLSYNC refused {path}:{at(m)} {name} {why}")
                return m.group(0)
            lines.append(f"DECLSYNC synced {path}:{at(m)} {name}")
            return f"{m.group(1)}{ret} {name}({ps});"

        def fix_cast(m):
            nonlocal refused
            why = compatible(want, sig(m.group(1), m.group(2)))
            if why:
                refused += 1
                lines.append(f"DECLSYNC refused {path}:{at(m)} {name} cast {why}")
                return m.group(0)
            lines.append(f"DECLSYNC uncast {path}:{at(m)} {name}")
            return name

        text = proto.sub(fix_proto, text)
        text = cast.sub(fix_cast, text)
    return text, lines, refused


def sync(prog, def_path, files=None, texts=None):
    """({path: new text} of changed files, [lines], refused, defs); texts {path: text} overrides the disk."""
    texts = dict(texts or {})
    if def_path not in texts:
        with open(def_path, errors="replace") as f:
            texts[def_path] = f.read()
    defs = definitions(texts[def_path])
    if not defs:
        sys.exit(f"declsync: no C definition in {def_path}")
    edits, out, refused = {}, [], 0
    for p in (files if files is not None else unit_files(prog)):
        if p not in texts:
            with open(p, errors="replace") as f:
                texts[p] = f.read()
        new, lines, r = sync_text(p, texts[p], defs)
        out += lines
        refused += r
        if new != texts[p]:
            edits[p] = new
    return edits, out, refused, defs


def summary(defs, lines, refused, edits):
    n = lambda k: sum(1 for l in lines if l.split()[1] == k)  # noqa: E731
    return (f"DECLSYNC {','.join(d[0] for d in defs)} synced {n('synced')} uncast {n('uncast')} refused {refused} "
            f"files {len(edits)}")


def self_test():
    body = "src/shared/_t/body.c"
    texts = {body: '#include "common.h"\n\nvoid func_T(s8* arg0, s32 arg1) {\n    func_U(arg0);\n}\n',
             "src/P/a.c": "void func_T(s32, u32);\nvoid f(void) {\n    ((void (*)(s32, s32))func_T)(0, 1);\n}\n",
             "src/P/b.c": "extern void func_T(s8*, s16);\n"}
    fails = []

    def ok(cond, what):
        if not cond:
            fails.append(what)
        print(f"self-test {'ok' if cond else 'FAIL'}: {what}")

    edits, lines, refused, _ = sync("P", body, files=["src/P/a.c"], texts=texts)
    a = edits.get("src/P/a.c", "")
    ok("void func_T(s8* arg0, s32 arg1);" in a and "DECLSYNC synced src/P/a.c:1 func_T" in lines,
       "width-compatible prototype synced")
    ok("    func_T(0, 1);" in a and any(l.startswith("DECLSYNC uncast src/P/a.c:3") for l in lines), "cast removed")
    ok(refused == 0, "no refusal on the compatible file")
    edits, lines, refused, _ = sync("P", body, files=["src/P/b.c"], texts=texts)
    ok(refused == 1 and not edits and any("refused src/P/b.c:1 func_T param 1 s16" in l for l in lines),
       "width-incompatible (s16 param) refused")
    if fails:
        print(f"DECLSYNC SELF-TEST FAIL {len(fails)}")
        return 1
    print("DECLSYNC CONTROL OK")
    return 0


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n", 1)[0])
    ap.add_argument("--prog")
    ap.add_argument("--def", dest="defn")
    ap.add_argument("--dry-run", action="store_true")
    ap.add_argument("--self-test", action="store_true")
    a = ap.parse_args()
    if a.self_test:
        return self_test()
    if not (a.prog and a.defn):
        ap.error("need --prog <p> --def <body.c>, or --self-test")
    edits, lines, refused, defs = sync(a.prog, a.defn)
    for l in lines:
        print(l)
    if not refused and not a.dry_run:
        for p, t in edits.items():
            with open(p, "w") as f:
                f.write(t)
    print(summary(defs, lines, refused, edits))
    return 1 if refused else 0


if __name__ == "__main__":
    sys.exit(main())
