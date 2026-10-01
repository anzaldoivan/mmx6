#!/usr/bin/env python3
"""census.py -- duplication, structural families, reach x size and the unique tail of the corpus (container, stdlib).

  census.py --all
      -> build/census/classes.jsonl {"kind":"dup|family","key","size","members":[[prog,vram],...],"reach"}, every
         fleet-wide class incl. singletons (size = words, reach = distinct programs), sorted (kind, key); stdout per
         lane (game, lib: classes recomputed on that lane's rows) and fleet, every line ending `of <N> functions`;
         last line `CENSUS dup_classes=<a> families=<b> reach_size=<c>/16 unique_tail=<d> of <N>` (fleet-wide).
  census.py --self-test
      -> planted functions assembled with the build's assembler (.run/census/selftest) through the real reader:
         jal/%hi/%lo twins -> one dup class; same with the mask off -> split; register-renamed copy -> same family,
         another dup class. Empty-body control on the real corpus: dup class of [jr $ra; nop] == corpus c-empty rows
         + asm|include_asm functions whose asm text is exactly `jr $ra` / `nop` (parsed from asm/**/*.s). Ends
         `CENSUS CONTROL OK` (rc 0), else rc 1.

Inputs: build/corpus/functions.jsonl (corpus.py). Words: the function's built TU object (asm -> build/asm/<p>/<tu>.s.o,
else build/src/<p>/<tu>.c.o), section of the function symbol, LE (C0041); equal to build/<p>.elf outside relocation
fields. Mask: the object's relocation sites (`readelf -rW`), field masks = probe.MASKS. dup key = sha1 of masked words;
family key = sha1 of the skeleton (per word opcode bits 31-26, + funct for SPECIAL, rt for REGIMM, rs for COPz).
dup class / family = functions sharing a key; reach = distinct programs in the function's dup class; unique tail =
functions in no dup class >= 2 and no family >= 2. A row with no resolvable object or symbol is refused (rc 1).
Firewall G12: prints counts only; keys and members go to build/ (untracked).
"""
import argparse
import hashlib
import json
import os
import re
import struct
import subprocess
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from probe import MASKS  # noqa: E402

FUNCS = "build/corpus/functions.jsonl"
OUT = "build/census"
SELFTEST = ".run/census/selftest"
READELF = "mipsel-linux-gnu-readelf"
AS = ["mipsel-linux-gnu-as", "-EL", "-march=r3000", "-mtune=r3000", "-mabi=32", "-no-pad-sections", "-G0"]
JR_RA = 0x03E00008
REACH = ((1, 1, "1"), (2, 3, "2-3"), (4, 10, "4-10"), (11, 1 << 30, "11+"))
SIZE = ((0, 8, "<=8"), (9, 32, "9-32"), (33, 128, "33-128"), (129, 1 << 30, "129+"))
REL_HDR = re.compile(r"^Relocation section '([^']+)'")
REL_ROW = re.compile(r"^([0-9a-f]{8})\s+([0-9a-f]{8})\s")
ASM_ROW = re.compile(r"/\*\s*[0-9A-Fa-f]+\s+[0-9A-Fa-f]{8}\s+[0-9A-Fa-f]{8}\s*\*/\s+(\S+)\s*(.*)")


class Refuse(Exception):
    pass


# ---- reader ---------------------------------------------------------------------------------------------------------

def elf_load(path):
    """({secname: bytes}, {symname: (secname, value)}) of an ELF32 LE relocatable object."""
    with open(path, "rb") as f:
        b = f.read()
    shoff, = struct.unpack_from("<I", b, 0x20)
    shentsize, shnum, shstrndx = struct.unpack_from("<HHH", b, 0x2E)
    secs = [struct.unpack_from("<IIIIIIIIII", b, shoff + i * shentsize) for i in range(shnum)]
    stro = secs[shstrndx][4]
    names = [b[stro + s[0]:b.index(b"\0", stro + s[0])].decode() for s in secs]
    data = {names[i]: b[s[4]:s[4] + s[5]] for i, s in enumerate(secs) if s[1] == 1}  # SHT_PROGBITS
    syms = {}
    for s in secs:
        if s[1] != 2:  # SHT_SYMTAB
            continue
        so = secs[s[6]][4]
        for o in range(s[4], s[4] + s[5], 16):
            nm, val, _, info, _, shndx = struct.unpack_from("<IIIBBH", b, o)
            name = b[so + nm:b.index(b"\0", so + nm)].decode()
            if name and 0 < shndx < len(secs) and (name not in syms or info & 0xF == 2):
                syms[name] = (names[shndx], val)
    return data, syms


def elf_masks(path):
    """{(secname, offset): field mask} of the object's relocation sites (`readelf -rW`, types in probe.MASKS)."""
    out = subprocess.run([READELF, "-rW", path], capture_output=True, text=True, check=True).stdout
    masks, sec = {}, None
    for line in out.splitlines():
        m = REL_HDR.match(line)
        if m:
            sec = m.group(1)[4:] if m.group(1).startswith(".rel.") else m.group(1)[5:]
            continue
        m = REL_ROW.match(line)
        if m and sec is not None:
            k = (sec, int(m.group(1), 16))
            masks[k] = masks.get(k, 0) | MASKS.get(int(m.group(2), 16) & 0xFF, 0)
    return masks


def asm_index():
    """{(prog, tu): path} of the non-nonmatchings asm/<p>/**/<tu>.s files."""
    idx = {}
    for prog in sorted(os.listdir("asm")):
        for d, dirs, files in os.walk(f"asm/{prog}"):
            dirs[:] = sorted(x for x in dirs if x != "nonmatchings")
            for fname in sorted(files):
                if fname.endswith(".s"):
                    idx.setdefault((prog, fname[:-2]), []).append(os.path.join(d, fname))
    return idx


def obj_of(r, idx):
    if r.get("obj"):
        return r["obj"]
    if r["state"] == "asm":
        paths = idx.get((r["prog"], r["tu"]), [])
        return f"build/{paths[0]}.o" if len(paths) == 1 else None
    return f"build/src/{r['prog']}/{r['tu']}.c.o"


def read_words(rows):
    """Per row (words, mask) from its TU object, or Refuse naming every unresolvable row."""
    idx = asm_index() if os.path.isdir("asm") else {}
    cache, out, bad = {}, [], []
    for r in rows:
        obj = obj_of(r, idx)
        if obj is None or not os.path.isfile(obj):
            bad.append(f"REFUSE {r['prog']} {r['name']} {r['vram']} no TU object ({obj or 'tu ' + r['tu']})")
            continue
        if obj not in cache:
            cache[obj] = elf_load(obj) + (elf_masks(obj),)
        data, syms, masks = cache[obj]
        if r["name"] not in syms:
            bad.append(f"REFUSE {r['prog']} {r['name']} {r['vram']} no symbol in {obj}")
            continue
        sec, off = syms[r["name"]]
        n = r["words"]
        b = data.get(sec, b"")
        if off + 4 * n > len(b):
            bad.append(f"REFUSE {r['prog']} {r['name']} {r['vram']} {n} words past {sec} of {obj}")
            continue
        out.append((list(struct.unpack_from(f"<{n}I", b, off)), [masks.get((sec, off + 4 * i), 0) for i in range(n)]))
    if bad:
        raise Refuse("\n".join(bad))
    return out


# ---- keys and classes ------------------------------------------------------------------------------------------------

def dup_key(words, mask):
    return hashlib.sha1(struct.pack(f"<{len(words)}I", *[w & ~m & 0xFFFFFFFF for w, m in zip(words, mask)])).hexdigest()


def skel(w):
    op = w >> 26
    if op == 0:
        return (op << 8) | (w & 0x3F)
    if op == 1:
        return (op << 8) | ((w >> 16) & 0x1F)
    if 16 <= op <= 19:
        return (op << 8) | ((w >> 21) & 0x1F)
    return op << 8


def family_key(words):
    return hashlib.sha1(struct.pack(f"<{len(words)}H", *[skel(w) for w in words])).hexdigest()


def keyed(rows, wm, masked=True):
    """rows annotated with dup/fam keys (masked=False: mask ignored, the control)."""
    out = []
    for r, (w, m) in zip(rows, wm):
        out.append(dict(r, dup=dup_key(w, m if masked else [0] * len(w)), fam=family_key(w)))
    return out


def classes(rows, kind):
    """{key: [rows]} of rows grouped by kind ('dup'|'fam')."""
    g = {}
    for r in rows:
        g.setdefault(r[kind], []).append(r)
    return g


def reach(members):
    return len({r["prog"] for r in members})


def bucket(v, table):
    return next(i for i, (lo, hi, _) in enumerate(table) if lo <= v <= hi)


def report(name, rows):
    """Census lines of one grouping (lane or fleet) and its summary numbers."""
    n = len(rows)
    dups, fams = classes(rows, "dup"), classes(rows, "fam")
    d2 = [m for m in dups.values() if len(m) >= 2]
    f2 = [m for m in fams.values() if len(m) >= 2]
    lines = [f"CENSUS {name} dup_classes={len(d2)} members={sum(map(len, d2))} of {n} functions",
             f"CENSUS {name} families={len(f2)} members={sum(map(len, f2))} of {n} functions"]
    cells = [[[0, 0] for _ in SIZE] for _ in REACH]
    for m in dups.values():
        c = cells[bucket(reach(m), REACH)][bucket(m[0]["words"], SIZE)]
        c[0] += 1
        c[1] += len(m)
    for i, (_, _, rl) in enumerate(REACH):
        row = " ".join(f"{SIZE[j][2]} {c[0]}/{c[1]}" for j, c in enumerate(cells[i]))
        lines.append(f"CENSUS {name} reach {rl}: {row} (classes/functions) of {n} functions")
    in2 = {id(r) for m in d2 + f2 for r in m}
    tail = [r for r in rows if id(r) not in in2]
    hist = [0] * len(SIZE)
    for r in tail:
        hist[bucket(r["words"], SIZE)] += 1
    h = " ".join(f"{SIZE[j][2]} {c}" for j, c in enumerate(hist))
    lines.append(f"CENSUS {name} unique_tail={len(tail)} bytes={4 * sum(r['words'] for r in tail)} {h} of {n} functions")
    nonempty = sum(1 for row in cells for c in row if c[1])
    return lines, dict(d=len(d2), f=len(f2), cells=nonempty, tail=len(tail), n=n)


def write(rows):
    os.makedirs(OUT, exist_ok=True)
    recs = []
    for kind, k in (("dup", "dup"), ("family", "fam")):
        for key, m in classes(rows, k).items():
            mem = sorted([r["prog"], r["vram"]] for r in m)
            recs.append(dict(kind=kind, key=key, size=m[0]["words"], members=mem, reach=reach(m)))
    recs.sort(key=lambda c: (c["kind"], c["key"]))
    with open(f"{OUT}/classes.jsonl", "w") as f:
        for c in recs:
            f.write(json.dumps(c) + "\n")


def load_rows():
    if not os.path.isfile(FUNCS):
        raise Refuse(f"REFUSE missing {FUNCS} (run corpus.py --all)")
    with open(FUNCS) as f:
        rows = [json.loads(line) for line in f if line.strip()]
    return sorted(rows, key=lambda r: (r["prog"], int(r["vram"], 16)))


def census():
    rows = load_rows()
    rows = keyed(rows, read_words(rows))
    write(rows)
    for lane in ("game", "lib"):
        print("\n".join(report(lane, [r for r in rows if r["lane"] == lane])[0]))
    lines, s = report("fleet", rows)
    print("\n".join(lines))
    print(f"CENSUS dup_classes={s['d']} families={s['f']} reach_size={s['cells']}/{len(REACH) * len(SIZE)} "
          f"unique_tail={s['tail']} of {s['n']}")
    return 0


# ---- self-test -------------------------------------------------------------------------------------------------------

PLANT = """\
.set noreorder
.set noat
.text
.globl twin_a
twin_a:
    lui $a0, %hi(dat_x)
    addiu $a0, $a0, %lo(dat_x)
    jal tgt_1
    nop
    jr $ra
    nop
.globl twin_b
twin_b:
    lui $a0, %hi(dat_y)
    addiu $a0, $a0, %lo(dat_y)
    jal tgt_2
    nop
    jr $ra
    nop
.globl renamed
renamed:
    lui $a1, %hi(dat_x)
    addiu $a1, $a1, %lo(dat_x)
    jal tgt_1
    nop
    jr $ra
    nop
tgt_1:
    jr $ra
    nop
    nop
    nop
tgt_2:
    jr $ra
    nop
.data
dat_x: .word 0
    .space 0x120
dat_y: .word 0
"""


def asm_empty_names():
    """{(prog, name)} of asm/**/*.s functions whose rows are exactly `jr $ra` / `nop` (asm text, own parser)."""
    out = set()
    for prog in sorted(os.listdir("asm")):
        for d, dirs, files in os.walk(f"asm/{prog}"):
            dirs.sort()
            for fname in sorted(files):
                if not fname.endswith(".s"):
                    continue
                cur, ins = None, []
                with open(os.path.join(d, fname), errors="replace") as f:
                    lines = f.read().splitlines() + ["glabel <eof>"]
                for line in lines:
                    s = line.strip()
                    if s.startswith(("glabel ", "dlabel ", "endlabel ", ".section")):
                        if cur is not None and ins == [("jr", "$ra"), ("nop", "")]:
                            out.add((prog, cur))
                        cur = s.split()[1] if s.startswith("glabel ") else None
                        ins = []
                        continue
                    m = ASM_ROW.search(line)
                    if m and cur is not None:
                        ins.append((m.group(1), m.group(2).strip()))
    return out


def self_test():
    fails = []

    def ok(cond, what):
        print(f"CENSUS CONTROL {'ok' if cond else 'FAIL'} {what}")
        if not cond:
            fails.append(what)

    os.makedirs(SELFTEST, exist_ok=True)
    src, obj = f"{SELFTEST}/plant.s", f"{SELFTEST}/plant.o"
    with open(src, "w") as f:
        f.write(PLANT)
    subprocess.run(AS + ["-o", obj, src], check=True)
    plant = [dict(prog=p, vram=v, name=n, tu="plant", state="asm", lane="game", words=6, obj=obj)
             for p, v, n in (("selftest_a", "0x80010000", "twin_a"), ("selftest_b", "0x80020000", "twin_b"),
                             ("selftest_c", "0x80030000", "renamed"))]
    wm = read_words(plant)
    on, off = keyed(plant, wm), keyed(plant, wm, masked=False)
    ok(on[0]["dup"] == on[1]["dup"], "jal/%hi/%lo twin -> one dup class")
    ok(off[0]["dup"] != off[1]["dup"], "twin with mask off -> split (mask is load-bearing)")
    ok(on[2]["fam"] == on[0]["fam"] and on[2]["dup"] != on[0]["dup"], "register-renamed copy -> same family, other dup")
    try:
        read_words([dict(plant[0], name="no_such_func")])
        ok(False, "unresolvable symbol refused")
    except Refuse:
        ok(True, "unresolvable symbol refused")

    rows = load_rows()
    rows = keyed(rows, read_words(rows))
    empty = dup_key([JR_RA, 0], [0, 0])
    got = len(classes(rows, "dup").get(empty, []))
    cempty = sum(1 for r in rows if r["state"] == "c-empty")
    asm_rows = {(r["prog"], r["name"]) for r in rows if r["state"] in ("asm", "include_asm")}
    asm_empty = len(asm_empty_names() & asm_rows)
    ok(got == cempty + asm_empty, f"empty-body class {got} == c-empty {cempty} + asm jr/nop {asm_empty}")
    if fails:
        print(f"CENSUS CONTROL FAIL {len(fails)}")
        return 1
    print("CENSUS CONTROL OK")
    return 0


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    g = ap.add_mutually_exclusive_group(required=True)
    g.add_argument("--all", action="store_true")
    g.add_argument("--self-test", action="store_true")
    a = ap.parse_args()
    try:
        sys.exit(self_test() if a.self_test else census())
    except Refuse as e:
        print(e)
        sys.exit(1)


if __name__ == "__main__":
    main()
