#!/usr/bin/env python3
"""loadmap.py --captures DIR --summary -- overlay load captures summary (T5.c1 stub; T6 adds --out/--self-test).

Reads DIR/*.jsonl (tools/mmx6/redux/loads.lua: one record per BinSeek load, caller = return address) and prints
event counts per dest base and per caller, plus the dest(s) used by the call at 0x80013E7C (caller 0x80013E84;
its base is the word at 0x80010000, recorded as w10000). rc 0 iff >= 1 record loads to each required base:
0x801EA000, 0x800FA000 and the 0x80013E7C target (>= 1 record from that caller); else rc 1 naming the missing
base; rc 2 on bad inputs. Stdlib only.
"""
import argparse
import json
import sys
from collections import Counter
from pathlib import Path

FIXED_BASES = (0x801EA000, 0x800FA000)
E7C_RA = 0x80013E84


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--captures", default=".run/redux/loads", help="dir of <run>.jsonl capture files")
    ap.add_argument("--summary", action="store_true", help="print counts per dest base and caller; gate on bases")
    a = ap.parse_args()
    if not a.summary:
        ap.error("only --summary exists yet (T6 grows the rest)")
    files = sorted(Path(a.captures).glob("*.jsonl"))
    if not files:
        print(f"loadmap: no *.jsonl in {a.captures}", file=sys.stderr)
        return 2
    recs = [json.loads(line) | {"run": f.stem} for f in files for line in f.read_text().splitlines() if line.strip()]
    by_dest = Counter(int(r["dest"], 16) for r in recs)
    by_caller = Counter(int(r["caller"], 16) for r in recs)
    e7c = Counter(int(r["dest"], 16) for r in recs if int(r["caller"], 16) == E7C_RA)
    no_after = sum(1 for r in recs if r.get("after") is None)
    print(f"runs {len(files)} ({', '.join(f.stem for f in files)}); loads {len(recs)}; without after-dump {no_after}")
    for base, n in sorted(by_dest.items()):
        print(f"dest 0x{base:08X}: {n}")
    for ra, n in sorted(by_caller.items()):
        print(f"caller 0x{ra:08X} (call 0x{ra - 8:08X}): {n}")
    print("0x80013E7C target: " + (", ".join(f"0x{b:08X} ({n})" for b, n in sorted(e7c.items())) or "none"))
    missing = [f"0x{b:08X}" for b in FIXED_BASES if not by_dest[b]] + ([] if e7c else ["0x80013E7C target"])
    if missing:
        print("MISSING base: " + ", ".join(missing))
        return 1
    print("all required bases loaded")
    return 0


if __name__ == "__main__":
    sys.exit(main())
