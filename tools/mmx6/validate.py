#!/usr/bin/env python3
"""validate.py -- the target validator (G49): is each wave target a real, open, drawable asm function (container, stdlib).

  validate.py --targets <file>
      -> one pv `<prog>:0x<VRAM 8 hex>` per line (`#` and blank lines ignored; a malformed line is a usage error, rc 1);
         per target in file order `VALID <pv>` | `INVALID <pv> <reason>`, last `VALIDATE <ok> of <n>`; rc 0 if ok >= 1,
         rc 3 if ok = 0.
  validate.py --drawn
      -> the targets are the `draw` rows of build/draw/draw.jsonl (cross-check: the draw filter never passes an invalid
         target); prints the INVALID lines only, last `VALIDATE <ok> of <n>`; rc 1 on any invalid, rc 3 on no draw rows.
  validate.py --self-test
      -> planted roots in .run/validate-selftest/: an out-of-range, phantom, banked, no-asm and lib target each refused
         with exactly its reason, one VALID, `VALIDATE 1 of 6` rc 0; the invalid ones alone -> rc 3; the no-asm target
         with its .s planted -> VALID (load-bearing). Ends `VALIDATE CONTROL OK` (rc 0), else `VALIDATE CONTROL FAIL <k>`
         (rc 1).

Checks per target, the first failing one reported:
  out-of-range  prog without a config/boundaries.txt `# program <P> base <B> size <S>` header, or vram outside [B, B+S)
  phantom       no build/corpus/functions.jsonl row starting at that exact vram
  banked        corpus state c|c-empty, or a config/dedup_registry.txt row naming it (col 4) with state (col 5) gated
  no-asm        include_asm -> asm/<prog>/nonmatchings/<tu>/<name>.s; asm -> a whole-TU asm/<prog>/**/<tu>.s (not under
                nonmatchings); absent, or holding no `glabel <name>`
  lib-unproven  lane lib and its boundaries `lib` OBJ not under docs/ops/compiler-pin.md `## Proven lib units`
Stdout carries names and addresses only (G12).
"""
import argparse
import json
import os
import re
import shutil
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import draw  # noqa: E402
import propagate  # noqa: E402

ROOTS = dict(asm="asm", funcs="build/corpus/functions.jsonl", bounds="config/boundaries.txt",
             registry="config/dedup_registry.txt", pin="docs/ops/compiler-pin.md")
DRAWN = "build/draw/draw.jsonl"
SELFTEST = ".run/validate-selftest"
PV = re.compile(r"([^\s:]+):0x([0-9A-Fa-f]{8})")


class Usage(Exception):
    pass


def programs(path):
    """{prog: (base, size)} of the boundaries `# program <P> base <B> size <S>` headers."""
    out = {}
    with open(path) as f:
        for line in f:
            w = line.split()
            if line.startswith("# program ") and len(w) >= 7 and w[3] == "base" and w[5] == "size":
                out[w[2]] = (int(w[4], 16), int(w[6], 16))
    return out


def has_glabel(path, name):
    if not os.path.isfile(path):
        return False
    with open(path, errors="replace") as f:
        return re.search(r"^\s*glabel\s+%s(\s|$)" % re.escape(name), f.read(), re.M) is not None


class Checker:
    def __init__(self, roots):
        self.r = roots
        self.progs = programs(roots["bounds"])
        self.lib, _ = draw.boundaries(roots["bounds"])
        self.good = draw.proven(roots["pin"])
        self.funcs = {(x["prog"], int(x["vram"], 16)): x for x in draw.jl(roots["funcs"])}
        self.gated = {propagate.parse_pv(t[3]) for _, t in propagate.registry_rows(roots["registry"])
                      if t[4] == "gated"}
        self.tus = {}

    def tu_files(self, prog, tu):
        """Whole-TU asm/<prog>/**/<tu>.s paths (nonmatchings skipped), indexed once per program."""
        if prog not in self.tus:
            idx = {}
            for d, dirs, files in os.walk(os.path.join(self.r["asm"], prog)):
                dirs[:] = sorted(x for x in dirs if x != "nonmatchings")
                for fname in sorted(files):
                    if fname.endswith(".s"):
                        idx.setdefault(fname[:-2], []).append(os.path.join(d, fname))
            self.tus[prog] = idx
        return self.tus[prog].get(tu, [])

    def check(self, prog, vram):
        """None if valid, else the first failing reason."""
        if prog not in self.progs or not self.progs[prog][0] <= vram < sum(self.progs[prog]):
            return "out-of-range"
        row = self.funcs.get((prog, vram))
        if row is None:
            return "phantom"
        if row["state"] in ("c", "c-empty") or (prog, vram) in self.gated:
            return "banked"
        if row["state"] == "include_asm":
            paths = [os.path.join(self.r["asm"], prog, "nonmatchings", row["tu"], row["name"] + ".s")]
        else:
            paths = self.tu_files(prog, row["tu"])
        if not any(has_glabel(p, row["name"]) for p in paths):
            return "no-asm"
        if row["lane"] == "lib":
            obj = next((o for a, b, o in self.lib.get(prog, []) if a <= vram < b), "-")
            if obj not in self.good:
                return "lib-unproven"
        return None


def read_targets(path):
    """[(prog, vram)] of a targets file; Usage on a malformed line."""
    out = []
    with open(path) as f:
        for i, line in enumerate(f, 1):
            s = line.strip()
            if not s or s.startswith("#"):
                continue
            m = PV.fullmatch(s)
            if not m:
                raise Usage(f"VALIDATE USAGE malformed target {path}:{i}")
            out.append((m.group(1), int(m.group(2), 16)))
    return out


def validate(roots, targets, say=print, invalid_only=False):
    """Says one line per target (INVALID only if invalid_only), then `VALIDATE <ok> of <n>`; returns (ok, n)."""
    c, ok = Checker(roots), 0
    for p, v in targets:
        pv = propagate.pv((p, v))
        why = c.check(p, v)
        if why is None:
            ok += 1
            if not invalid_only:
                say(f"VALID {pv}")
        else:
            say(f"INVALID {pv} {why}")
    say(f"VALIDATE {ok} of {len(targets)}")
    return ok, len(targets)


def rc_targets(ok):
    return 0 if ok else 3


def drawn(path=DRAWN):
    return [(r["prog"], int(r["vram"], 16)) for r in draw.jl(path) if r["verdict"] == "draw"]


# ---- self-test: planted roots under .run/validate-selftest/ (C0054/C0038) -------------------------------------------

P = "SELFTEST"


def plant(root):
    """Planted roots; returns (roots, {name: pv}, path of the no-asm target's absent .s)."""
    shutil.rmtree(root, ignore_errors=True)
    roots = {k: os.path.join(root, os.path.basename(v)) for k, v in ROOTS.items()}
    v = lambda i: 0x80100000 + 0x100 * i  # noqa: E731
    rows = [("valid", 1, "T", "asm", "game"), ("banked", 2, "T", "asm", "game"), ("noasm", 3, "U", "include_asm", "game"),
            ("lib", 4, "T", "asm", "lib")]
    os.makedirs(os.path.join(roots["asm"], P, "nonmatchings", "U"))
    with open(roots["funcs"], "w") as f:
        for name, i, tu, state, lane in rows:
            f.write(json.dumps(dict(prog=P, vram="0x%08X" % v(i), end="0x%08X" % v(i + 1), words=64, name=f"f_{name}",
                                    tu=tu, state=state, lane=lane, src="glabel")) + "\n")
    with open(os.path.join(roots["asm"], P, "T.s"), "w") as f:
        f.write("".join(f"glabel f_{n}\n  nop\n" for n, _, tu, _, _ in rows if tu == "T"))
    with open(roots["bounds"], "w") as f:
        f.write(f"# program {P} base 0x80100000 size 0x2000\nlib 0x{v(4):08X} 0x{v(5):08X} LIBX.LIB/A.OBJ\n")
    with open(roots["registry"], "w") as f:
        f.write(f"# registry\nk {P}:0x{v(9):08X} src/shared/x.c {P}:0x{v(2):08X} gated planted\n")
    with open(roots["pin"], "w") as f:
        f.write("# pin\n## Proven lib units\n- LIBX.LIB/B.OBJ planted\n## Next\n")
    pvs = dict(oor=f"{P}:0x90000000", phantom=f"{P}:0x{v(1) + 4:08X}",
               **{n: f"{P}:0x{v(i):08X}" for n, i, _, _, _ in rows})
    return roots, pvs, os.path.join(roots["asm"], P, "nonmatchings", "U", "f_noasm.s")


def self_test():
    lines, fails = [], []

    def ok(cond, what):
        lines.append(f"VALIDATE CONTROL {'ok' if cond else 'FAIL'} {what}")
        if not cond:
            fails.append(what)

    roots, pv, noasm = plant(SELFTEST)
    want = [("oor", "INVALID", "out-of-range"), ("phantom", "INVALID", "phantom"), ("banked", "INVALID", "banked"),
            ("noasm", "INVALID", "no-asm"), ("lib", "INVALID", "lib-unproven"), ("valid", "VALID", "")]
    tfile = os.path.join(SELFTEST, "targets.txt")
    with open(tfile, "w") as f:
        f.write("# planted\n\n" + "".join(pv[n] + "\n" for n, _, _ in want))
    said = []
    got = validate(roots, read_targets(tfile), said.append)
    for (n, kind, why), line in zip(want, said):
        e = f"{kind} {pv[n]} {why}".rstrip()
        ok(line == e, f"{n} -> {e}")
    ok(said[-1] == "VALIDATE 1 of 6" and got == (1, 6) and rc_targets(got[0]) == 0,
       f"planted set -> VALIDATE 1 of 6 rc 0: {said[-1]}")
    with open(tfile, "w") as f:
        f.write("".join(pv[n] + "\n" for n, k, _ in want if k == "INVALID"))
    said = []
    got = validate(roots, read_targets(tfile), said.append)
    ok(rc_targets(got[0]) == 3 and said[-1] == "VALIDATE 0 of 5", "invalid targets file -> VALIDATE 0 of 5, rc 3")
    with open(tfile, "w") as f:
        f.write("SELFTEST:80100100\n")
    try:
        read_targets(tfile)
        ok(False, "malformed target line -> usage error")
    except Usage:
        ok(True, "malformed target line -> usage error (rc 1)")
    with open(noasm, "w") as f:
        f.write("glabel f_noasm\n  nop\n")
    said = []
    validate(roots, [propagate.parse_pv(pv["noasm"])], said.append)
    ok(said == [f"VALID {pv['noasm']}", "VALIDATE 1 of 1"], "load-bearing: the no-asm target with its .s planted -> VALID")
    lines.append("VALIDATE CONTROL OK" if not fails else f"VALIDATE CONTROL FAIL {len(fails)}")
    for x in lines:
        print(x)
    return 1 if fails else 0


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    g = ap.add_mutually_exclusive_group(required=True)
    g.add_argument("--targets", metavar="FILE")
    g.add_argument("--drawn", action="store_true")
    g.add_argument("--self-test", action="store_true")
    a = ap.parse_args()
    targets_file = os.path.abspath(a.targets) if a.targets else None
    os.chdir(os.path.join(HERE, "..", ".."))
    if a.self_test:
        return self_test()
    try:
        if targets_file:
            ok, n = validate(ROOTS, read_targets(targets_file))
            return rc_targets(ok)
        targets = drawn()
        ok, n = validate(ROOTS, targets, invalid_only=True)
        return 3 if not n else (1 if ok < n else 0)
    except Usage as e:
        print(e)
        return 1
    except draw.Refuse as e:
        print("\n".join(e.lines))
        return 1
    except OSError as e:
        print(f"VALIDATE REFUSE missing {e.filename}")
        return 1


if __name__ == "__main__":
    sys.exit(main())
