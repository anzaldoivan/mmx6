#!/usr/bin/env python3
"""objmap.py [--captures FILE] [--out FILE] -- object-type map (T5.c1) -> docs/leads/objects.tsv.

Static side (extracted/retail: iso/SLUS_013.95 text at 0x80010000, rock/NN.bin at config/loadmap.txt bases):
  stage load 0x80013E8C..: index i = stage*2 + sub (bytes 0xC/0xD of the stage struct); members D_8006DB78[i]
  (u16); scratch 0x1F800080 = D_8006DC6C[i] (temp#1 type table), 0x1F800084 = D_8006DD24[i] (temp#2). The
  per-stage tables are contiguous (0x80, 0x84, 0x88 at +0, +0x134, +0x21C in every stage), so a table ends at
  the next one (temp#1 77 words, temp#2 58) or at its first word that is not a KSEG0 code pointer
  [0x80010000, 0x80200000) & ~3, whichever is first (none stops early in retail).
  origin: func_80029F38 / func_8002A4E4 walk D_8007349C[stage][sub] / D_80073554[stage][sub] records
  {flags, id, sub, type, x, y} to type 0xF; func_8002A3AC calls D_8007347C[type & 0xF] (8 allocators); the
  allocator picks the array, rec.id becomes obj[1] (the dispatch index).
Rows: one per (table, type_id, target) with the stages that share it in `note`; origin one per type 0..7.
Names: refs/leads/tweaks/ObjectTempTable_1.tsv r3 (temp#1 ids; not on `jr ra` stubs), config/x4/names.tsv (target is, or directly
  `jal`s, an x4 mains/ function), ObjectOriginTable.tsv record comments (WB_ORIGIN). Runtime: --captures = tools/mmx6/redux/objects.lua jsonl; a row is `proven`
  with >= 3 distinct frames for (table, id, fn) while one of the row's stages is loaded (the last set-* record)
  (origin: type -> obj inside the allocator's array).
Keys only: no table bytes are written. Stdlib only.
"""
import argparse
import json
import re
import struct
from collections import defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
EXE = ROOT / "extracted/retail/iso/SLUS_013.95"
ROCK = ROOT / "extracted/retail/rock"
EXE_BASE = 0x80010000
MEMBERS, DIR_T1, DIR_T2 = 0x8006DB78, 0x8006DC6C, 0x8006DD24
LEN = {"temp#1": 77, "temp#2": 58}
LISTS = ((0x8007349C, 23, "func_80029F38"), (0x80073554, 13, "func_8002A4E4"))
ALLOC = 0x8007347C
ARRAYS = {0: (0x8008EF48, 0x1D40), 1: (0x8008EF48, 0x1D40), 2: (0x8008EF48, 0x1D40), 3: (0x8009B7B0, 0x1200),
          4: (0x800C1220, 0x3340), 5: (0x800CD410, 0x2400), 6: (0x8009C9B0, 0x1800), 7: (0x800C4778, 0xC0)}
CLASS = {0: "enemy", 1: "enemy", 2: "enemy", 3: "effect", 4: "class4", 5: "misc", 6: "class6", 7: "class7"}
WB_T1 = {0x30: "intro_boss", 0x31: "commander_yammark", 0x32: "ground_scaravich", 0x35: "nightmare_zero",
         0x36: "blizzard_wolfang", 0x37: "high_max_intro", 0x3B: "gate", 0x3D: "sigma_1", 0x10: "nightmare_press",
         0x19: "nightmare_snake", 0x09: "purple_guard_robot", 0x0F: "nightmare_virus"}
WB_SRC = {**{k: "ObjectTempTable_1.tsv:r3c39" for k in range(0x30, 0x38)},
          **{k: "ObjectTempTable_1.tsv:r3c40" for k in range(0x38, 0x40)},
          0x10: "ObjectTempTable_1.tsv:r3c41", 0x19: "ObjectTempTable_1.tsv:r3c41",
          0x09: "ObjectTempTable_1.tsv:r3c42", 0x0F: "ObjectTempTable_1.tsv:r3c42"}
# ObjectOriginTable.tsv comments on a type-0 record (rec.id = temp#1 index), stage = the list holding the record
WB_ORIGIN = {(0x1C, "st4.0"): ("hidden_area_teleport", "ObjectOriginTable.tsv:r6 (rec 0x800F2B0C in D_8007349C[4][0])"),
             (0x04, "st1.0"): ("butterfly", "ObjectOriginTable.tsv:r25 (rec 0x800F6610 in D_8007349C[1][0])")}
HEADER = "table\ttype_id\tfunction\tprog_vram\tentity_name\tname_source\tdatapoints\tdatapoint_log\ttier\tnote"


def bases():
    out = {}
    for line in (ROOT / "config/loadmap.txt").read_text().splitlines():
        f = line.split()
        if len(f) >= 3 and f[0].isdigit() and f[1].startswith("0x"):
            out[int(f[0])] = int(f[1], 16)
    return out


class Img:
    def __init__(self, base, data, prog):
        self.base, self.data, self.prog = base, data, prog

    def has(self, a):
        return self.base <= a < self.base + len(self.data)

    def w(self, a):
        return struct.unpack_from("<I", self.data, a - self.base)[0]


def jal_targets(img, fn, cap=0x2000):
    """jal targets in fn's body up to its first `jr ra` (+ delay slot)."""
    out, a = [], fn
    while img.has(a + 4) and a < fn + cap:
        w = img.w(a)
        if w >> 26 == 3:
            out.append(((a + 4) & 0xF0000000) | ((w & 0x3FFFFFF) << 2))
        if w == 0x03E00008:
            break
        a += 4
    return out


def x4_names():
    names = {}
    for n, line in enumerate((ROOT / "config/x4/names.tsv").read_text().splitlines(), 1):
        f = line.split("\t")
        if len(f) >= 9 and f[2] == "func":
            m = re.search(r"mains/main_(\d+)_([a-z0-9_]+)\.c", f[8])
            names[(f[0], int(f[1], 16))] = (f[3], f[4], m.group(2) if m else None, n)
    return names


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--captures", default=str(ROOT / ".run/redux/objects/intro_stage.jsonl"))
    ap.add_argument("--out", default=str(ROOT / "docs/leads/objects.tsv"))
    a = ap.parse_args()
    exe = Img(EXE_BASE, Path(EXE).read_bytes()[0x800:], "SLUS_013.95")
    base = bases()
    mem = {}

    def member(m):
        if m not in mem:
            mem[m] = Img(base[m], (ROCK / f"{m:02d}.bin").read_bytes(), f"rock_{m:02d}")
        return mem[m]

    stage_member = [struct.unpack_from("<H", exe.data, MEMBERS - EXE_BASE + 2 * i)[0] for i in range(46)]
    x4 = x4_names()

    def where(v, img):
        if exe.has(v):
            return exe
        if img.has(v):
            return img
        return None

    # (table, id, prog, vram) -> stages
    rows = defaultdict(list)
    for tname, d in (("temp#1", DIR_T1), ("temp#2", DIR_T2)):
        for i in range(46):
            t = exe.w(d + 4 * i)
            if t == 0:
                continue
            img = member(stage_member[i])
            for k in range(LEN[tname]):
                v = img.w(t + 4 * k)
                if v & 3 or not 0x80010000 <= v < 0x80200000:
                    break
                h = where(v, img)
                prog = h.prog if h else "ovl_800FA000"
                rows[(tname, k, prog, v)].append(f"st{i // 2}.{i % 2}")

    # runtime datapoints
    frames = defaultdict(set)
    live_stages = set()
    cur = None
    cap = Path(a.captures)
    if cap.exists():
        for line in cap.read_text().splitlines():
            r = json.loads(line)
            t = r["table"]
            if t.startswith("set-"):
                cur = f"st{r['stage']}.{r['sub']}"
                live_stages.add(cur)
            elif t == "origin":
                lo, size = ARRAYS[r["type"]]
                if lo <= int(r["obj"], 16) < lo + size:
                    frames[("origin", r["type"], int(r["alloc"], 16))].add(r["frame"])
            else:
                frames[(t, r["id"], int(r["fn"], 16), cur)].add(r["frame"])
    log = cap.relative_to(ROOT).as_posix() if cap.is_relative_to(ROOT) else cap.name

    def namefor(prog, v, img):
        hit = x4.get((prog, v))
        if hit:
            return hit[0], (hit[2] or hit[1]), f"config/x4/names.tsv:{hit[3]}"
        for j in jal_targets(img, v) if img else []:
            for p in ("SLUS_013.95", img.prog):
                h = x4.get((p, j))
                if h and h[2]:
                    return None, h[2], f"config/x4/names.tsv:{h[3]} (callee)"
        return None, "-", "-"

    out = [f"# docs/leads/objects.tsv -- written by tools/mmx6/objmap.py (T5.c1); keys only. table temp#1 = "
           f"*0x1F800080 (array 0x8008EF48 stride 0x9C, 48 slots), temp#2 = *0x1F800084 (array 0x80093C98 stride "
           f"0xA0 per func_80020258, workbook says 0x9C, 32 slots), origin = record type & 0xF -> D_8007347C; "
           f"tier proven = >= 3 distinct frames logged", HEADER]
    named = proven = 0
    for (tname, k, prog, v), stages in sorted(rows.items(), key=lambda r: (r[0][0], r[0][1], r[0][2], r[0][3])):
        img = exe if prog == "SLUS_013.95" else (mem.get(int(prog[5:])) if prog.startswith("rock_") else None)
        fname, ent, src = namefor(prog, v, img)
        stub = img is not None and img.w(v) == 0x03E00008  # `jr ra` first: empty handler, never named
        if tname == "temp#1" and k in WB_T1 and not stub:
            ent, src = WB_T1[k], f"refs/leads/tweaks/{WB_SRC[k]}" + ("; x4 " + src if src != "-" else "")
        for st in stages:
            if tname == "temp#1" and (k, st) in WB_ORIGIN and not stub:
                ent, src = WB_ORIGIN[(k, st)][0], "refs/leads/tweaks/" + WB_ORIGIN[(k, st)][1]
        dp = len(set().union(*(frames.get((tname, k, v, st), set()) for st in stages)))
        tier = "proven" if dp >= 3 else "lead"
        named += ent != "-"
        proven += tier == "proven"
        note = ("empty stub (jr ra); " if stub else "") + f"stages {','.join(stages)}"
        if prog == "ovl_800FA000":
            note += "; target in the 0x800FA000 overlay (member not fixed by this stage)"
        out.append("\t".join([tname, f"0x{k:02X}", fname or f"func_{v:08X}", f"{prog}:0x{v:08X}", ent, src,
                              str(dp), log if dp else "-", tier, note]))
    for typ in range(8):
        v = exe.w(ALLOC + 4 * typ)
        fname, ent, src = namefor("SLUS_013.95", v, exe)
        lo, size = ARRAYS[typ]
        dp = len(frames.get(("origin", typ, v), ()))
        tier = "proven" if dp >= 3 else "lead"
        proven += tier == "proven"
        named += src != "-"
        note = (f"array 0x{lo:08X} +0x{size:X}; rec.id -> obj[1]; high nibble = spawn state (0x10/0x30/0x50 +0x10 "
                f"off-screen, func_80029F38); type 0xF ends a list; lists D_8007349C[23][2] (func_80029F38), "
                f"D_80073554[13][2] (func_8002A4E4); workbook 0x800734BC = D_8007349C[4][0]")
        out.append("\t".join(["origin", f"0x{typ:X}", fname or f"func_{v:08X}", f"SLUS_013.95:0x{v:08X}",
                              f"{CLASS[typ]}_slot_alloc" if ent == "-" else ent, src if src != "-" else
                              "SLUS_013.95 bytes (allocator array)", str(dp), log if dp else "-", tier, note]))
    Path(a.out).write_text("\n".join(out) + "\n")
    print(f"objmap: rows={len(out) - 2} proven={proven} named={named} live={','.join(sorted(live_stages)) or '-'}")


if __name__ == "__main__":
    main()
