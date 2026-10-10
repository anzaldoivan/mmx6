#!/usr/bin/env python3
"""walls.py -- the wall oracle: config/walls.txt rows name functions no bank can match (container, stdlib only).

  walls.py --check
      -> per bad row `WALLS BAD <line> <prog> <vram> <why>` (unknown pass, ref not <file>:<int>, empty evidence,
         function not in build/corpus/functions.jsonl, function already c|c-empty = stale wall), rc 1;
         else `WALLS CHECK OK <r> rows` (rc 0)
  walls.py --for <prog:vram>
      -> `BANKABLE <prog:vram> yes|no <pass> <ref>` (`- -` when yes); rc 1 if the function is not in the corpus
  walls.py --self-test
      -> real file passes; planted (in .run/walls-selftest/) valid row -> its function `no`, a neighbour `yes`;
         unknown pass, missing dump ref, row on a C function each refused; ends `WALLS CONTROL OK` (rc 0), else rc 1.

Record config/walls.txt (tracked, G52): `<prog> <vram 0x%08X> <pass> <dumpfile>:<line> <evidence>`, evidence = the
quoted dump line, rest of row; pass in PASSES (gcc 2.95 cc1 dump passes + maspsx). `#` lines are comments.
Importable: `bankable(prog, vram) -> (bool, reason)`: False iff a valid row names the function; reason `wall <pass> <ref>`.
"""
import argparse
import json
import os
import re
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
WALLS = "config/walls.txt"
FUNCS = "build/corpus/functions.jsonl"
SELFTEST = ".run/walls-selftest"
sys.path.insert(0, HERE)
from dumps import SUFFIXES  # noqa: E402
PASSES = SUFFIXES + ("maspsx",)  # cc1 2.95.2 -da suffixes (dumps.py, observed T2) + maspsx; was + peephole2 stack
REF = re.compile(r"^[^:\s]+:[0-9]+$")


def corpus(funcs=FUNCS):
    """{(prog, vram int): state} of the function corpus."""
    with open(funcs) as f:
        return {(r["prog"], int(r["vram"], 16)): r["state"] for r in (json.loads(x) for x in f if x.strip())}


def parse(walls=WALLS, funcs=FUNCS):
    """(valid {(prog, vram int): (pass, ref)}, bad [(line no, prog, vram, why)], data rows) of a walls file."""
    states, valid, bad, n = corpus(funcs), {}, [], 0
    with open(walls) as f:
        for i, line in enumerate(f, 1):
            if not line.strip() or line.lstrip().startswith("#"):
                continue
            n += 1
            t = line.split(None, 4)
            prog, vs = (t + ["-", "-"])[:2]
            try:
                v = int(vs, 16)
            except ValueError:
                v = None
            ev = t[4].strip().strip('"').strip() if len(t) == 5 else ""
            if v is None or vs != "0x%08X" % v:
                why = "vram not 0x%08X"
            elif t[2] not in PASSES:
                why = f"unknown pass {t[2]}"
            elif not REF.match(t[3]):
                why = "dump ref not <file>:<int>"
            elif not ev:
                why = "empty evidence"
            elif (prog, v) not in states:
                why = "function not in corpus"
            elif states[(prog, v)] in ("c", "c-empty"):
                why = f"stale wall: function is {states[(prog, v)]}"
            else:
                valid[(prog, v)] = (t[2], t[3])
                continue
            bad.append((i, prog, vs, why))
    return valid, bad, n


_cache = {}


def bankable(prog, vram, walls=WALLS, funcs=FUNCS):
    """(False, `wall <pass> <ref>`) iff a valid wall row names prog:vram, else (True, "")."""
    key = (os.path.abspath(walls), os.path.abspath(funcs))
    if key not in _cache:
        _cache[key] = parse(walls, funcs)[0]
    v = int(vram, 16) if isinstance(vram, str) else vram
    w = _cache[key].get((prog, v))
    return (True, "") if w is None else (False, f"wall {w[0]} {w[1]}")


def check(walls=WALLS, funcs=FUNCS, out=print):
    valid, bad, n = parse(walls, funcs)
    for i, p, v, why in bad:
        out(f"WALLS BAD {i} {p} {v} {why}")
    if not bad:
        out(f"WALLS CHECK OK {n} rows")
    return 1 if bad else 0


def for_(pv, walls=WALLS, funcs=FUNCS):
    p, _, v = pv.rpartition(":")
    try:
        key = (p, int(v, 16))
    except ValueError:
        key = None
    if key not in corpus(funcs):
        print(f"walls: {pv} is not a corpus function")
        return 1
    w = parse(walls, funcs)[0].get(key)
    print(f"BANKABLE {pv} " + ("yes - -" if w is None else f"no {w[0]} {w[1]}"))
    return 0


# ---- self-test: planted rows in .run/walls-selftest/, never the real file -------------------------------------------

def self_test():
    lines, fails = [], []

    def ok(cond, what):
        lines.append(f"WALLS CONTROL {'ok' if cond else 'FAIL'} {what}")
        if not cond:
            fails.append(what)

    quiet = lambda s: None  # noqa: E731
    ok(check(WALLS, FUNCS, quiet) == 0, f"real {WALLS} passes --check")
    with open(FUNCS) as f:
        rs = sorted((json.loads(x) for x in f if x.strip()), key=lambda r: (r["prog"], int(r["vram"], 16)))
    asm = [r for r in rs if r["state"] in ("asm", "include_asm")]
    f0, nb = asm[0], next(r for r in asm[1:] if r["prog"] == asm[0]["prog"])
    cf = next(r for r in rs if r["state"] == "c")
    os.makedirs(SELFTEST, exist_ok=True)

    def plant(name, row):
        path = os.path.join(SELFTEST, name)
        with open(path, "w") as f:
            f.write("# planted by walls.py --self-test\n" + row + "\n")
        _cache.clear()
        return path

    good = plant("valid.txt", f'{f0["prog"]} {f0["vram"]} combine dump.combine:12 "(insn 12 (set (reg 2)))"')
    ok(check(good, FUNCS, quiet) == 0, "planted valid row passes --check")
    ok(not bankable(f0["prog"], f0["vram"], good)[0], f"planted wall {f0['prog']}:{f0['vram']} -> no")
    ok(bankable(nb["prog"], nb["vram"], good)[0], f"neighbour {nb['prog']}:{nb['vram']} -> yes")
    for name, row in (("pass", f'{f0["prog"]} {f0["vram"]} peephole2 dump.combine:12 "x"'),
                      ("ref", f'{f0["prog"]} {f0["vram"]} combine dump.combine "x"'),
                      ("cfunc", f'{cf["prog"]} {cf["vram"]} combine dump.combine:12 "x"')):
        p = plant(f"bad_{name}.txt", row)
        ok(check(p, FUNCS, quiet) != 0 and bankable(*row.split()[:2], p)[0], f"planted bad {name} row refused")
    lines.append("WALLS CONTROL OK" if not fails else f"WALLS CONTROL FAIL {len(fails)}")
    for x in lines:
        print(x)
    return 1 if fails else 0


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    g = ap.add_mutually_exclusive_group(required=True)
    g.add_argument("--check", action="store_true")
    g.add_argument("--for", dest="for_", metavar="PROG:VRAM")
    g.add_argument("--self-test", action="store_true")
    a = ap.parse_args()
    os.chdir(os.path.join(HERE, "..", ".."))
    for p in (WALLS, FUNCS):
        if not os.path.isfile(p):
            print(f"walls: missing {p}")
            return 1
    if a.self_test:
        return self_test()
    if a.check:
        return check()
    return for_(a.for_)


if __name__ == "__main__":
    sys.exit(main())
