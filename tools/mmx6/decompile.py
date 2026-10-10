#!/usr/bin/env python3
"""decompile.py <func> [--prog p] — m2c C scaffold of one splat function, on stdout (container).

Finds asm/<p>/nonmatchings/**/<func>.s (splat output of an INCLUDE_ASM function; run `make split` first), adds the
TU's own data/rodata asm when splat split them (asm/<p>/data/<tu>.*.s), and runs m2c (/opt/m2c, pinned in the
Makefile) with `-t mipsel-gcc-c -f <func>`. The scaffold is a starting point; converge with tools/mmx6/diff.sh.
m2c's stderr goes to .run/decompile/<func>.err. rc 2 when the function is not found, else m2c's rc.
Output is derived from the game: never commit it (G12).
"""
import argparse
import glob
import os
import subprocess
import sys

REPO = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
M2C = os.environ.get("M2C", "/opt/m2c/m2c.py")


def main():
    ap = argparse.ArgumentParser(description="m2c scaffold of one splat function")
    ap.add_argument("func", help="splat function label, e.g. func_80055A04")
    ap.add_argument("--prog", default="SLUS_013.95", help="program (asm/<prog>/), default SLUS_013.95")
    args = ap.parse_args()

    root = os.path.join(REPO, "asm", args.prog)
    hits = sorted(glob.glob(os.path.join(root, "nonmatchings", "**", args.func + ".s"), recursive=True))
    if not hits:
        print(f"decompile.py: no asm/{args.prog}/nonmatchings/**/{args.func}.s "
              "(not an INCLUDE_ASM function, or `make split` not run)", file=sys.stderr)
        return 2
    if len(hits) > 1:
        print(f"decompile.py: {len(hits)} matches, using {os.path.relpath(hits[0], REPO)}", file=sys.stderr)
    tu = os.path.basename(os.path.dirname(hits[0]))
    data = sorted(glob.glob(os.path.join(root, "data", tu + ".*.s")))

    scratch = os.path.join(REPO, ".run", "decompile")
    os.makedirs(scratch, exist_ok=True)
    cmd = [sys.executable, M2C, "-t", "mipsel-gcc-c", "-f", args.func, hits[0], *data]
    with open(os.path.join(scratch, args.func + ".err"), "w") as err:
        rc = subprocess.run(cmd, stderr=err).returncode
    if rc:
        print(f"decompile.py: m2c rc {rc} (stderr in .run/decompile/{args.func}.err)", file=sys.stderr)
    return rc


if __name__ == "__main__":
    sys.exit(main())
