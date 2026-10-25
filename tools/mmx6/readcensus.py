#!/usr/bin/env python3
"""readcensus.py -- the readability census: four counts of the source, read from the logs of the real checks (stdlib).

  readcensus.py --all
      -> runs `psxd_floor.py debt`, `typecheck.py --all` and its own macro scan; writes each one's stdout+stderr and
         a trailer `STEP rc <n>` as debt.log, typecheck.log, macroscan.log in .run/<phase>/readcensus/; then builds the
         line from those logs only (the --from-logs path).
  readcensus.py --from-logs <dir>
      -> the line from the three step logs of <dir>; no check is run.
  readcensus.py --self-test
      -> planted trees under .run/<phase>/readcensus-selftest/ (removed at the end), counted by the real tools (psxd_floor
         `debt --repo` on a planted git repo; typecheck.check on the planted {path: text}) and parsed through the step
         logs: one of each kind -> each count 1 (macro bodies: one per kind); a clean tree with the negative controls
         (helper macros, a sanctioned shared include, a struct outside include/ under include/) -> all 0. Ends
         `READCENSUS CONTROL OK`.

Last line: `READCENSUS pins-unmarked <n> macro-bodies <n> raw-casts <n> struct-dups <n>`, rc 0 (the counts are the
output, not a gate); before it `READCENSUS INFO shared-includes <n> (C files per system; not debt)`. rc 2 when a step
log is missing or unparseable.
  pins-unmarked  `pin-unmarked N` of psxd_floor's `DEBT INFO totals:` line (its rc is not read).
  raw-casts      `raw casts M` of typecheck's summary line.
  struct-dups    distinct path:line over `TYPES REFUSE dup` lines and `TYPES REFUSE outside` lines not under include/.
  macro-bodies   this tool's scan of src/**/*.c|h and include/**/*.h, `MACROBODY <kind> <path>:<line> <text>`:
                 define          a #define (continuations joined) whose replacement defines a function
                                 (`<type>[ *]<name>(params) {`, control keywords excluded);
                 include-in-body a #include of a .c/.inc file at brace depth > 0;
                 include-chain   a #include of a .c from a file under src/shared/.
                 Not counted: helper macros (M2C_FIELD, PAIR, do{}while statement macros) and the top-level includes of
                 src/shared/<prog>/*.c by a program's TU (the sanctioned C files per system: the INFO count).
"""
import argparse
import os
import re
import shutil
import subprocess
import sys

ROOT = os.path.abspath(os.path.join(os.path.dirname(__file__), "..", ".."))


def phase_scratch(root):
    """The open phase's temp folder (as tools/run.sh: `# Phase <id>` line 1 of PHASE_PLAN.md), else .run (no plan)."""
    try:
        with open(os.path.join(root, "phase-ends", "current", "PHASE_PLAN.md")) as f:
            line = f.readline()
    except OSError:
        line = ""
    m = re.match(r"#\s*Phase\s+([A-Za-z0-9._-]+)", line)
    return os.path.join(root, ".run") if not m or m.group(1) in (".", "..") else os.path.join(root, ".run", m.group(1))


OUT = os.path.join(phase_scratch(ROOT), "readcensus")
SELF = os.path.join(phase_scratch(ROOT), "readcensus-selftest")
STEPS = ("debt", "typecheck", "macroscan")

COMMENT = re.compile(r'//[^\n]*|/\*.*?\*/|"(?:\\.|[^"\\\n])*"|\'(?:\\.|[^\'\\\n])*\'', re.S)
DEFINE = re.compile(r'^\s*#\s*define\s+\w+(?:\([^)]*\))?(.*)$', re.S)
INCLUDE = re.compile(r'^\s*#\s*include\s*"([^"]+)"')
FUNC = re.compile(r'\b([A-Za-z_]\w*)[\s*]+\**\s*([A-Za-z_][\w#]*)\s*\([^(){};]*\)\s*\{')
CONTROL = {"if", "while", "for", "switch", "return", "sizeof", "do", "else", "case", "goto", "defined"}


def blank(text):
    """Comments -> spaces (newlines kept); string and char literals kept, as #include needs its path."""
    def sub(m):
        s = m.group(0)
        return s if s[0] in "\"'" else re.sub(r"[^\n]", " ", s)
    return COMMENT.sub(sub, text)


def scan_text(path, text):
    """([(kind, line, text)], shared-include count) of one file."""
    hits, shared, depth = [], 0, 0
    lines = blank(text).split("\n")
    i = 0
    while i < len(lines):
        start, line = i + 1, lines[i]
        if line.lstrip().startswith("#"):
            while line.endswith("\\") and i + 1 < len(lines):
                i += 1
                line = line[:-1] + " " + lines[i]
            show = " ".join(line.split())[:100]
            m = DEFINE.match(line)
            if m:
                body = re.sub(r'"(?:\\.|[^"\\])*"', '""', m.group(1))
                if any(f.group(1) not in CONTROL and f.group(2) not in CONTROL for f in FUNC.finditer(body)):
                    hits.append(("define", start, show))
            m = INCLUDE.match(line)
            if m:
                target = m.group(1)
                tc = target.endswith(".c")
                if (tc or target.endswith(".inc")) and depth > 0:
                    hits.append(("include-in-body", start, show))
                elif tc and path.startswith("src/shared/"):
                    hits.append(("include-chain", start, show))
                elif tc:
                    dest = os.path.normpath(os.path.join(os.path.dirname(path), target)).replace(os.sep, "/")
                    if re.fullmatch(r"src/shared/[^/]+/[^/]+\.c", dest):
                        shared += 1
        else:
            code = re.sub(r'"(?:\\.|[^"\\])*"|\'(?:\\.|[^\'\\])*\'', "", line)
            depth = max(0, depth + code.count("{") - code.count("}"))
        i += 1
    return hits, shared


def source_paths(root):
    found = []
    for top, exts in (("src", (".c", ".h")), ("include", (".h",))):
        for d, _, names in os.walk(os.path.join(root, top)):
            for n in names:
                if n.endswith(exts):
                    found.append(os.path.relpath(os.path.join(d, n), root).replace(os.sep, "/"))
    return sorted(found)


def macroscan(root):
    """The step's output lines and rc: MACROBODY lines and the summary."""
    out, nbody, nshared, paths = [], 0, 0, source_paths(root)
    for p in paths:
        with open(os.path.join(root, p), encoding="utf-8", errors="replace") as f:
            hits, shared = scan_text(p, f.read())
        nshared += shared
        for kind, line, show in hits:
            nbody += 1
            out.append("MACROBODY %s %s:%d %s" % (kind, p, line, show))
    out.append("MACROSCAN files %d macro-bodies %d shared-includes %d" % (len(paths), nbody, nshared))
    return out, 0


def write_step(logdir, name, text, rc):
    with open(os.path.join(logdir, name + ".log"), "w", encoding="utf-8") as f:
        f.write(text if not text or text.endswith("\n") else text + "\n")
        f.write("STEP rc %d\n" % rc)


def run_step(logdir, name, cmd, cwd):
    r = subprocess.run(cmd, cwd=cwd, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True)
    write_step(logdir, name, r.stdout, r.returncode)


class Unparseable(Exception):
    pass


def read_log(logdir, name):
    p = os.path.join(logdir, name + ".log")
    if not os.path.isfile(p):
        raise Unparseable("missing step log " + p)
    lines = open(p, encoding="utf-8").read().split("\n")
    if not any(re.fullmatch(r"STEP rc -?\d+", l) for l in lines):
        raise Unparseable("no `STEP rc` trailer in " + p)
    return lines


def census(logdir):
    """(pins, bodies, casts, dups, shared) from the three step logs; raises Unparseable."""
    tot = [l for l in read_log(logdir, "debt") if l.startswith("DEBT INFO totals:")]
    if len(tot) != 1:
        raise Unparseable("debt.log: %d `DEBT INFO totals:` lines" % len(tot))
    m = re.search(r"\bpin-unmarked (\d+)\b", tot[0])
    pins = int(m.group(1)) if m else 0
    tl = read_log(logdir, "typecheck")
    summ = [l for l in tl if re.match(r"TYPES \d+ definitions .*; raw casts \d+$", l)]
    if len(summ) != 1:
        raise Unparseable("typecheck.log: %d summary lines" % len(summ))
    casts = int(summ[0].rsplit(" ", 1)[1])
    where = set()
    for l in tl:
        w = l.split()
        if len(w) >= 4 and w[:2] == ["TYPES", "REFUSE"] and (
                w[2] == "dup" or (w[2] == "outside" and not w[3].startswith("include/"))):
            where.add(w[3])
    ms = [l for l in read_log(logdir, "macroscan") if l.startswith("MACROSCAN ")]
    m = re.fullmatch(r"MACROSCAN files \d+ macro-bodies (\d+) shared-includes (\d+)", ms[0]) if len(ms) == 1 else None
    if not m:
        raise Unparseable("macroscan.log: no summary line")
    return pins, int(m.group(1)), casts, len(where), int(m.group(2))


def report(logdir):
    try:
        pins, bodies, casts, dups, shared = census(logdir)
    except Unparseable as e:
        print("READCENSUS FAIL %s" % e)
        return 2
    for l in read_log(logdir, "macroscan"):
        if l.startswith("MACROBODY "):
            print(l)
    print("READCENSUS INFO shared-includes %d (C files per system; not debt)" % shared)
    print("READCENSUS pins-unmarked %d macro-bodies %d raw-casts %d struct-dups %d" % (pins, bodies, casts, dups))
    return 0


def run_all():
    os.makedirs(OUT, exist_ok=True)
    run_step(OUT, "debt", [sys.executable, os.path.join("tools", "psxd_floor.py"), "debt"], ROOT)
    run_step(OUT, "typecheck", [sys.executable, os.path.join("tools", "mmx6", "typecheck.py"), "--all"], ROOT)
    out, rc = macroscan(ROOT)
    write_step(OUT, "macroscan", "\n".join(out), rc)
    return report(OUT)


# ---- the self-test: planted trees, counted by the real tools ------------------------------------------------------
CLEAN = {
    "include/mmx6/types.h": "typedef struct {\n    int a;\n    char b;\n} PlantedA;\n"
                            "#define M2C_FIELD(base, type, off) (*(type *)((char *)(base) + (off)))\n"
                            "#define PAIR(a, b) ((a) << 16 | (b))\n"
                            "#define DIGIT(c) ((c) - '0')\n"
                            "#define STEP(x) do { if (x) { (x)--; } } while (0)\n",
    "include/planted_lib.h": "struct LibOnly {\n    int x;\n    int y;\n    int z;\n};\n",
    "src/SLUS_013.95/main.c": '#include "../shared/SLUS_013.95/func_80010000.c"\n\nvoid Main(void) {\n}\n',
    "src/shared/SLUS_013.95/func_80010000.c": "void func_80010000(void) {\n}\n",
}
PLANTED = {
    "src/SLUS_013.95/pin.c": 'void Walk(void) {\n    register int i asm("$16");\n    i = 1;\n}\n',
    "src/SLUS_013.95/cast.c": "void Poke(void) {\n    *(volatile int *)0x80001000 = 0;\n}\n",
    "src/SLUS_013.95/twin.c": "struct PlantedB {\n    int a;\n    char b;\n};\n",
    "src/SLUS_013.95/getter.h": "#define DEFINE_GETTER(n) \\\n    static int get_##n(void) { return n; }\n",
    "src/SLUS_013.95/body.c": 'void Body(void) {\n#include "body_part.inc"\n}\n',
    "src/shared/SLUS_013.95/chain.c": '#include "func_80010000.c"\n',
}


def census_tree(base, name, files):
    sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
    import typecheck
    tree, logdir = os.path.join(base, name), os.path.join(base, name + "-logs")
    for p, t in files.items():
        os.makedirs(os.path.dirname(os.path.join(tree, p)), exist_ok=True)
        with open(os.path.join(tree, p), "w", encoding="utf-8") as f:
            f.write(t)
    os.makedirs(logdir)
    for args in (["init", "--quiet"], ["add", "-A"]):
        subprocess.run(["git"] + args, cwd=tree, check=True)
    run_step(logdir, "debt", [sys.executable, os.path.join(ROOT, "tools", "psxd_floor.py"), "debt", "--repo", tree], ROOT)
    texts = {p: t for p, t in files.items() if p.endswith(".h") or (p.startswith("src/") and p.endswith(".c"))}
    refusals, summary, _, _ = typecheck.check(texts)
    write_step(logdir, "typecheck", "\n".join(refusals + [summary]), 1 if refusals else 0)
    out, rc = macroscan(tree)
    write_step(logdir, "macroscan", "\n".join(out), rc)
    kinds = [l.split()[1] for l in read_log(logdir, "macroscan") if l.startswith("MACROBODY ")]
    return census(logdir), kinds, logdir


def self_test():
    shutil.rmtree(SELF, ignore_errors=True)
    os.makedirs(SELF)
    try:
        clean, ck, _ = census_tree(SELF, "clean", CLEAN)
        print("clean: pins %d bodies %d casts %d dups %d shared %d" % clean)
        assert clean == (0, 0, 0, 0, 1) and ck == [], (clean, ck)
        got, kinds, logdir = census_tree(SELF, "planted", dict(CLEAN, **PLANTED))
        print("planted: pins %d bodies %d casts %d dups %d shared %d" % got)
        assert got == (1, 3, 1, 1, 1), got
        assert sorted(kinds) == ["define", "include-chain", "include-in-body"], kinds
        assert report(logdir) == 0
        os.remove(os.path.join(logdir, "typecheck.log"))
        assert report(logdir) == 2  # a missing step log
    finally:
        shutil.rmtree(SELF, ignore_errors=True)
    print("READCENSUS CONTROL OK")
    return 0


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    g = ap.add_mutually_exclusive_group(required=True)
    g.add_argument("--all", action="store_true")
    g.add_argument("--from-logs", metavar="DIR")
    g.add_argument("--self-test", action="store_true")
    a = ap.parse_args()
    if a.self_test:
        return self_test()
    if a.all:
        return run_all()
    return report(a.from_logs)


if __name__ == "__main__":
    sys.exit(main())
