#!/usr/bin/env python3
"""dumps.py -- per-pass cc1 dumps of one C unit, compiled through the product C rule (container, stdlib only).

  dumps.py --src <c>             any repo-relative .c (key = its basename without .c)
  dumps.py --tu <prog>/<tu>      src/<prog>/<tu>.c (key = <prog>/<tu>)
      -> build/dumps/<key>/<base>.<suffix> (+ <base>.s, <base>.o); last line `DUMPS <key> <n> passes: <suffixes>`
      cpp output with no non-blank, non-`#` line -> `DUMPS CPP-EMPTY <key>`, rc 3, nothing else run.
      --tu also compares .text of the dump-run object with the built build/src/<prog>/<tu>.c.o:
      -> `DUMPS TEXT <key> words <a> built <b> identical|DIFFER`; DIFFER (count or bytes) -> rc 1.
  dumps.py --self-test
      plants a 6-line function (a value live across a call and a branch) in .run/dumps-selftest/: every SUFFIXES
      file exists and is nonempty, .greg holds a `regs to allocate` line, observed set == SUFFIXES; a planted empty
      .c is refused CPP-EMPTY rc 3; ends `DUMPS CONTROL OK` (rc 0), else rc 1.

Never re-typed flags: `make -s -n -B build/<c>.o` gives the C rule's recipe (with target-specific CFLAGS_<tu> and
overlay -DMMX6_OVERLAY); its `cpp | cc1 | maspsx | as` line is split and each stage run separately, rc checked
(pipefail by construction). cc1 gets the rule's exact args plus `-da -dumpbase <base>`, run in the dump dir.
SUFFIXES: cc1 2.95.2's `-da` dump files in pass order (toplev.c rest_of_compilation; observed, phase 1.7 T2).
"""
import argparse
import os
import shlex
import struct
import subprocess
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.normpath(os.path.join(HERE, "..", ".."))
OUT = "build/dumps"
SELFTEST = ".run/dumps-selftest"
SUFFIXES = ("rtl", "jump", "cse", "addressof", "gcse", "loop", "cse2", "bp", "flow", "combine", "regmove", "sched",
            "lreg", "greg", "flow2", "sched2", "jump2", "mach", "dbr")
PLANT = "extern int g(int);\nint f(int a)\n{\n    int b = a * 3;\n    if (g(a)) b += a;\n    return b + g(b);\n}\n"


def recipe(c, extra=()):
    """[cpp, cc1, maspsx, as] argv lists of the C rule for repo-relative c, from make's dry run (extra: make args)."""
    p = subprocess.run([os.environ.get("MAKE", "make"), "-s", "-n", "-B", f"build/{c}.o", *extra],
                       capture_output=True, text=True)
    if p.returncode != 0:
        raise RuntimeError(f"make -n build/{c}.o rc {p.returncode}: {p.stderr.strip()[-200:]}")
    for line in p.stdout.splitlines():
        if " | " in line:
            toks, stages = shlex.split(line), [[]]
            for t in toks:
                if t == "|":
                    stages.append([])
                else:
                    stages[-1].append(t)
            if len(stages) == 4:
                return stages
    raise RuntimeError(f"no cpp|cc1|maspsx|as line in the recipe of build/{c}.o")


def stage(argv, data, what, cwd=None):
    p = subprocess.run(argv, input=data, capture_output=True, cwd=cwd)
    if p.returncode != 0:
        raise RuntimeError(f"{what} rc {p.returncode}: {p.stderr.decode(errors='replace').strip()[-300:]}")
    return p.stdout


def run(c, key, outdir, out=print):
    """Dumps of c into outdir; returns (rc, observed suffixes in pass order)."""
    base = os.path.splitext(os.path.basename(c))[0]
    cpp, cc1, masp, as_ = recipe(c)
    i = stage(cpp, None, "cpp")
    if not any(x.strip() and not x.lstrip().startswith(b"#") for x in i.splitlines()):
        out(f"DUMPS CPP-EMPTY {key}")
        return 3, ()
    os.makedirs(outdir, exist_ok=True)
    for f in os.listdir(outdir):
        if f.startswith(base + "."):
            os.remove(os.path.join(outdir, f))
    s = stage(cc1 + ["-da", "-dumpbase", base], i, "cc1", cwd=outdir)
    with open(os.path.join(outdir, base + ".s"), "wb") as f:
        f.write(s)
    o = os.path.join(outdir, base + ".o")
    k = as_.index("-o")
    stage(as_[:k + 1] + [o] + as_[k + 2:], stage(masp, s, "maspsx"), "as")
    got = {f[len(base) + 1:] for f in os.listdir(outdir) if f.startswith(base + ".")} - {"s", "o"}
    seen = tuple(x for x in SUFFIXES if x in got) + tuple(sorted(got - set(SUFFIXES)))
    out(f"DUMPS {key} {len(seen)} passes: {' '.join(seen)}")
    return 0, seen


def text(path):
    """.text bytes of an ELF32 little-endian object."""
    with open(path, "rb") as f:
        b = f.read()
    shoff, = struct.unpack_from("<I", b, 0x20)
    shentsize, shnum, shstrndx = struct.unpack_from("<HHH", b, 0x2E)
    sh = [struct.unpack_from("<IIIIII", b, shoff + n * shentsize) for n in range(shnum)]
    stro = sh[shstrndx][4]
    for name, typ, _, _, off, size in sh:
        if b[stro + name:b.index(b"\0", stro + name)] == b".text":
            return b"" if typ == 8 else b[off:off + size]
    return b""


def tu(spec):
    prog, name = spec.split("/", 1)
    c = f"src/{prog}/{name}.c"
    rc, _ = run(c, spec, os.path.join(OUT, prog, name))
    if rc:
        return rc
    built = f"build/{c}.o"
    if not os.path.isfile(built):
        print(f"dumps: missing built object {built}")
        return 1
    a, b = text(os.path.join(OUT, prog, name, name + ".o")), text(built)
    same = a == b
    print(f"DUMPS TEXT {spec} words {len(a) // 4} built {len(b) // 4} {'identical' if same else 'DIFFER'}")
    return 0 if same else 1


def self_test():
    lines, fails = [], []

    def ok(cond, what):
        lines.append(f"DUMPS CONTROL {'ok' if cond else 'FAIL'} {what}")
        if not cond:
            fails.append(what)

    os.makedirs(SELFTEST, exist_ok=True)
    plant, empty = os.path.join(SELFTEST, "plant.c"), os.path.join(SELFTEST, "empty.c")
    with open(plant, "w") as f:
        f.write(PLANT)
    with open(empty, "w") as f:
        f.write("/* planted by dumps.py --self-test: no tokens */\n")
    d = os.path.join(SELFTEST, "out")
    rc, seen = run(plant, "selftest", d, lines.append)
    ok(rc == 0, "planted function compiles with -da")
    for x in SUFFIXES:
        p = os.path.join(d, "plant." + x)
        ok(os.path.isfile(p) and os.path.getsize(p) > 0, f"plant.{x} exists, nonempty")
    g = os.path.join(d, "plant.greg")
    ok(os.path.isfile(g) and any("regs to allocate" in x for x in open(g, errors="replace")),
       "plant.greg holds a `regs to allocate` line")
    ok(set(seen) == set(SUFFIXES), "observed suffix set == SUFFIXES")
    rc, _ = run(empty, "selftest-empty", os.path.join(SELFTEST, "out-empty"), lines.append)
    ok(rc == 3 and not os.path.isdir(os.path.join(SELFTEST, "out-empty")), "planted empty .c refused CPP-EMPTY rc 3")
    lines.append("DUMPS CONTROL OK" if not fails else f"DUMPS CONTROL FAIL {len(fails)}")
    for x in lines:
        print(x)
    return 1 if fails else 0


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    g = ap.add_mutually_exclusive_group(required=True)
    g.add_argument("--src", metavar="C")
    g.add_argument("--tu", metavar="PROG/TU")
    g.add_argument("--self-test", action="store_true")
    a = ap.parse_args()
    src = a.src and os.path.relpath(os.path.abspath(a.src), ROOT)
    os.chdir(ROOT)
    try:
        if a.self_test:
            return self_test()
        if a.tu:
            return tu(a.tu)
        key = os.path.splitext(os.path.basename(src))[0]
        return run(src, key, os.path.join(OUT, key))[0]
    except RuntimeError as e:
        print(f"dumps: {e}")
        return 1


if __name__ == "__main__":
    sys.exit(main())
