#!/usr/bin/env python3
"""exeproof.py <dumpdir> [--base 0x80010000] -- prove where SLUS_013.95 loads, from Redux RAM dumps (T4.c1).

Image = SLUS_013.95[0x800 : 0x800+0x7F000] (extracted/retail/iso/SLUS_013.95; sha1 must equal its
manifest/retail.jsonl record, else rc 2), mapped at --base. Each <dumpdir>/*.bin is main RAM (2 MiB at
0x80000000, tools/mmx6/redux/smoke.lua). Per dump:
  (a) every 32-bit word inside a function body equals the image word at the same address;
  (b) whole-image match fraction, printed as equal/total words.
Function bodies (config/ghidra/SLUS_013.95.jsonl, func rows carry no extent): [func addr, next start), next
start = next func row or next data row addr inside the CODE block 0x80010000..0x8008EFFF (last: block end).
rc 0 iff (a) holds at every dump; 1 otherwise; 2 on bad inputs. Stdlib only.
"""
import argparse
import hashlib
import json
import struct
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parents[2]
EXE = REPO / "extracted/retail/iso/SLUS_013.95"
MANIFEST = REPO / "manifest/retail.jsonl"
ANNOT = REPO / "config/ghidra/SLUS_013.95.jsonl"
HDR, TEXT_SIZE = 0x800, 0x7F000
CODE_LO, CODE_END = 0x80010000, 0x8008F000
RAM_BASE, RAM_SIZE = 0x80000000, 0x200000


def fail(msg):
    print(f"exeproof: {msg}", file=sys.stderr)
    sys.exit(2)


def load_image():
    want = None
    for line in MANIFEST.read_text().splitlines():
        rec = json.loads(line)
        if rec.get("path") == "iso/SLUS_013.95":
            want = rec["sha1"]
    if want is None:
        fail(f"no iso/SLUS_013.95 record in {MANIFEST}")
    if not EXE.is_file():
        fail(f"missing {EXE} (run make extract)")
    data = EXE.read_bytes()
    got = hashlib.sha1(data).hexdigest()
    if got != want:
        fail(f"sha1 {got} != manifest {want}")
    return data[HDR:HDR + TEXT_SIZE]


def load_bodies():
    funcs, starts = [], set()
    for line in ANNOT.read_text().splitlines():
        rec = json.loads(line)
        if rec.get("k") not in ("func", "data"):
            continue
        a = int(rec["addr"], 16)
        if not CODE_LO <= a < CODE_END:
            continue
        starts.add(a)
        if rec["k"] == "func":
            funcs.append((a, rec.get("name", "")))
    order = sorted(starts)
    nxt = {a: (order[i + 1] if i + 1 < len(order) else CODE_END) for i, a in enumerate(order)}
    return [(a, nxt[a], name) for a, name in sorted(funcs)]


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("dumpdir")
    ap.add_argument("--base", default="0x80010000", type=lambda s: int(s, 0))
    args = ap.parse_args()

    image = load_image()
    bodies = load_bodies()
    dumps = sorted(Path(args.dumpdir).glob("*.bin"))
    if not dumps:
        fail(f"no *.bin in {args.dumpdir}")
    body_words = sum((((hi - lo) + 3) // 4) for lo, hi, _ in bodies)
    img_words = TEXT_SIZE // 4
    print(f"image: SLUS_013.95 text 0x{TEXT_SIZE:X} B at base 0x{args.base:08X}; "
          f"{len(bodies)} func bodies, {body_words} body words (denominator)")

    def img_word(addr):
        off = addr - args.base
        if 0 <= off <= TEXT_SIZE - 4:
            return image[off:off + 4]
        return None

    all_ok = True
    for path in dumps:
        ram = path.read_bytes()
        if len(ram) != RAM_SIZE:
            fail(f"{path} is {len(ram)} B, want {RAM_SIZE}")
        eq, bad = 0, []
        for lo, hi, name in bodies:
            for addr in range(lo & ~3, hi, 4):
                ro = addr - RAM_BASE
                if img_word(addr) == ram[ro:ro + 4]:
                    eq += 1
                elif len(bad) < 20:
                    bad.append((addr, name, lo))
        ro = args.base - RAM_BASE
        whole = sum(1 for i in range(0, TEXT_SIZE, 4)
                    if 0 <= ro + i <= RAM_SIZE - 4 and image[i:i + 4] == ram[ro + i:ro + i + 4])
        ok = eq == body_words
        all_ok &= ok
        print(f"{path.name}: body words {eq}/{body_words} {'EQUAL' if ok else 'MISMATCH'}; "
              f"whole image {whole}/{img_words} ({whole / img_words:.4f})")
        for addr, name, lo in bad:
            print(f"  mismatch 0x{addr:08X} in {name or '?'}@0x{lo:08X}")
    print("exeproof: PASS" if all_ok else "exeproof: FAIL")
    return 0 if all_ok else 1


if __name__ == "__main__":
    sys.exit(main())
