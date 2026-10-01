#!/usr/bin/env python3
"""probe.py -- compile one function's C under a compiler triple and compare it to retail (container, stdlib only).

  probe.py <func> --prog <p> --src <c> --triple <name>
      -> `<func> <triple> MATCH|FAIL <matched>/<words> words`
  probe.py --ladder [--probes config/probes.txt] [--triples config/triples.txt]
      -> one line per triple x probe, then `PIN <t> <k> of <k>` | `PIN NONE` | `PIN AMBIGUOUS <t1>,<t2>,...`;
         rc 0 only on a unique PIN (exactly one triple matching every probe, k >= 1)
  probe.py --self-test [--triples ...]
      -> known-true control (src/probes/selftest_func_80055A04.c, INCLUDE_ASM) must MATCH under every triple;
         planted mutation (.run/probe/mut/, one unrelocated instruction -> nop) must FAIL n-1/n; ends
         `SELF-TEST OK` (rc 0) or `SELF-TEST FAIL` (rc 1)

Compiles through the product C rule (`make -s -B TRIPLE=<t> build/<src>.o`), serially, copying each object to
.run/probe/<t>/. Retail extent: splat glabel..endlabel (or next glabel) under asm/<p>/ (a body
#included from src/shared/: its build/corpus/functions.jsonl row); bytes from the yaml
target_path at segment start + (vram - segment vram); both sides trimmed to the last `jr $ra` + delay slot (C0021).
Relocated fields of the compiled .o (.rel.text) are masked on both sides: R_MIPS_26 low 26 bits, HI16/LO16/GPREL16
low 16 bits. Firewall G12: prints counts and offsets only, never bytes, words or disassembly; scratch under .run/.
"""
import argparse
import json
import os
import re
import shutil
import struct
import subprocess
import sys

JR_RA = 0x03E00008
MASKS = {4: 0x03FFFFFF, 5: 0xFFFF, 6: 0xFFFF, 7: 0xFFFF}  # R_MIPS_26, HI16, LO16, GPREL16
SELFTEST_FUNC = "func_80055A04"
SELFTEST_PROG = "SLUS_013.95"
SELFTEST_SRC = "src/probes/selftest_func_80055A04.c"
SELFTEST_ASM = "asm/SLUS_013.95/nonmatchings/LIBSPU_S_M_UTIL/func_80055A04.s"
MUT_DIR = ".run/probe/mut"
CORPUS = "build/corpus/functions.jsonl"
INSN_RE = re.compile(r"/\*\s+[0-9A-Fa-f]+\s+([0-9A-Fa-f]{8})\s+[0-9A-Fa-f]{8}\s+\*/\s+(\S+)(.*)")
MUT_OPS = ("addu", "subu", "and", "or", "xor", "nor", "slt", "sltu")  # one-word R-type, never relocated


def read_rows(path):
    rows = []
    with open(path) as f:
        for line in f:
            line = line.split("#", 1)[0].strip()
            if line:
                rows.append(line)
    return rows


def triple_names(path):
    return [r.split("|", 1)[0].strip() for r in read_rows(path)]


def trim(words):
    """Cut after the last `jr $ra` + its delay slot (C0021); unchanged when there is none."""
    for i in range(len(words) - 1, -1, -1):
        if words[i] == JR_RA:
            return words[: min(i + 2, len(words))]
    return words


# ---- retail side -------------------------------------------------------------------------------------------------

def yaml_layout(prog):
    """(target_path, segment start, segment vram) of config/<prog>.yaml (first dict-style code segment)."""
    target = start = vram = None
    in_segments = False
    with open(f"config/{prog}.yaml") as f:
        for line in f:
            m = re.match(r"\s+target_path:\s*(\S+)", line)
            if m and target is None:
                target = m.group(1)
            if line.startswith("segments:"):
                in_segments = True
            if not in_segments:
                continue
            m = re.match(r"\s+(?:- )?(start|vram):\s*(0x[0-9A-Fa-f]+|\d+)\s*$", line)
            if m:
                v = int(m.group(2), 0)
                if m.group(1) == "start" and start is None:
                    start = v
                elif m.group(1) == "vram" and vram is None and start is not None:
                    vram = v
            if start is not None and vram is not None:
                break
    if target is None or start is None or vram is None:
        sys.exit(f"probe: cannot read target_path/segment start/vram from config/{prog}.yaml")
    return target, start, vram


def find_extent(prog, func):
    """(first vram, word count) of func's glabel..endlabel in asm/<prog>/."""
    root = f"asm/{prog}"
    if not os.path.isdir(root):
        subprocess.run(["make", "-s", f"build/split/{prog}.stamp"], check=True, stdout=subprocess.DEVNULL)
    tag = f"glabel {func}"
    starts = set()  # every glabel func_<addr> / D_<addr> vram: bounds a function banked as C (no .s, T8)
    for d, dirs, files in sorted(os.walk(root)):
        dirs.sort()
        for name in sorted(files):
            if not name.endswith(".s"):
                continue
            with open(os.path.join(d, name), errors="replace") as f:
                text = f.read()
            starts.update(int(a, 16) for a in re.findall(r"^\s*glabel \w+_([0-9A-Fa-f]{8})\s*$", text, re.M))
            if tag not in text:
                continue
            vrams, inside = [], False
            for line in text.splitlines():
                s = line.strip()
                if not inside:
                    inside = s == tag
                    continue
                if s.startswith("glabel ") or s == f"endlabel {func}":
                    break
                m = INSN_RE.search(line)
                if m:
                    vrams.append(int(m.group(1), 16))
            if vrams:
                return vrams[0], len(vrams)
    # Banked as C in src/<prog>/ (splat writes no .s): [func_<addr>, next function start); retail_words trims (C0021).
    m = re.fullmatch(r"func_([0-9A-Fa-f]{8})", func)
    if m:
        for d, dirs, files in os.walk(f"src/{prog}"):
            for name in files:
                if name.endswith(".c"):
                    with open(os.path.join(d, name), errors="replace") as f:
                        src = f.read()
                    if not re.search(rf"^\w[^;(]*\b{func}\(", src, re.M):
                        continue
                    starts.update(int(a, 16) for a in re.findall(r"^\w[^;(]*\bfunc_([0-9A-Fa-f]{8})\(", src, re.M))
                    starts.update(int(a, 16) for a in re.findall(r"^INCLUDE_ASM\([^,]*, *\w+_([0-9A-Fa-f]{8})\)", src, re.M))
                    lo = int(m.group(1), 16)
                    hi = min((a for a in starts if a > lo), default=None)
                    if hi is not None:
                        return lo, (hi - lo) // 4
    # A body reached through an #include (src/shared, T5: no .s, no def text under its name): its corpus row extent.
    if os.path.isfile(CORPUS):
        with open(CORPUS) as f:
            for line in f:
                r = json.loads(line)
                if r["prog"] == prog and r["name"] == func:
                    lo = int(r["vram"], 16)
                    return lo, (int(r["end"], 16) - lo) // 4
    sys.exit(f"probe: {func} not found under {root}/")


def retail_words(prog, func):
    target, seg_start, seg_vram = yaml_layout(prog)
    vram, n = find_extent(prog, func)
    off = seg_start + vram - seg_vram
    with open(target, "rb") as f:
        f.seek(off)
        data = f.read(4 * n)
    if len(data) != 4 * n:
        sys.exit(f"probe: {target} short read at 0x{off:X}")
    return trim(list(struct.unpack(f"<{n}I", data)))


# ---- compiled side -----------------------------------------------------------------------------------------------

def elf_function(path, func):
    """(words, {word index: mask}) of func in an ELF32 LE relocatable object."""
    with open(path, "rb") as f:
        elf = f.read()
    if elf[:4] != b"\x7fELF" or elf[4] != 1 or elf[5] != 1:
        sys.exit(f"probe: {path} is not ELF32 LE")
    e_shoff, = struct.unpack_from("<I", elf, 0x20)
    e_shentsize, e_shnum = struct.unpack_from("<HH", elf, 0x2E)
    secs = [struct.unpack_from("<10I", elf, e_shoff + i * e_shentsize) for i in range(e_shnum)]
    # (name, type, flags, addr, offset, size, link, info, align, entsize)
    symtab = next((i for i, s in enumerate(secs) if s[1] == 2), None)
    if symtab is None:
        sys.exit(f"probe: {path} has no .symtab")
    st = secs[symtab]
    strtab = secs[st[6]]

    def name_at(off):
        b = strtab[4] + off
        return elf[b : elf.index(b"\0", b)].decode()

    syms = []
    for k in range(st[5] // 16):
        st_name, st_value, st_size, st_info, _, st_shndx = struct.unpack_from("<IIIBBH", elf, st[4] + 16 * k)
        syms.append((name_at(st_name), st_value, st_size, st_info, st_shndx))
    hit = next((s for s in syms if s[0] == func and s[4] not in (0, 0xFFF1, 0xFFF2) and s[4] < 0xFF00), None)
    if hit is None:
        sys.exit(f"probe: {func} not defined in {path}")
    _, value, size, _, shndx = hit
    text = secs[shndx]
    if size == 0:
        later = [s[1] for s in syms if s[4] == shndx and s[1] > value and ((s[3] & 0xF) == 2 or (s[3] >> 4) != 0)]
        size = (min(later) if later else text[5]) - value
    n = size // 4
    words = list(struct.unpack_from(f"<{n}I", elf, text[4] + value))
    masks = {}
    for s in secs:
        if s[1] == 9 and s[7] == shndx:  # SHT_REL against the function's section
            for k in range(s[5] // 8):
                r_offset, r_info = struct.unpack_from("<II", elf, s[4] + 8 * k)
                m = MASKS.get(r_info & 0xFF)
                if m and value <= r_offset < value + size:
                    masks[(r_offset - value) // 4] = masks.get((r_offset - value) // 4, 0) | m
    return trim(words), masks


def compile_obj(src, triple):
    obj = f"build/{src}.o"
    outdir = f".run/probe/{triple}"
    os.makedirs(outdir, exist_ok=True)
    log = os.path.join(outdir, os.path.basename(src) + ".log")
    with open(log, "w") as lf:
        rc = subprocess.run(["make", "-s", "-B", f"TRIPLE={triple}", obj], stdout=lf, stderr=subprocess.STDOUT).returncode
    if rc != 0:
        print(f"probe: compile failed under {triple} (rc {rc}), log {log}", file=sys.stderr)
        return None
    dst = os.path.join(outdir, os.path.basename(obj))
    shutil.copyfile(obj, dst)
    return dst


def probe(func, prog, src, triple):
    """(match, matched, retail word count); prints the result line."""
    ret = retail_words(prog, func)
    obj = compile_obj(src, triple)
    if obj is None:
        matched, ok = 0, False
    else:
        ours, masks = elf_function(obj, func)
        matched = 0
        for i in range(min(len(ret), len(ours))):
            keep = ~masks.get(i, 0) & 0xFFFFFFFF
            matched += (ret[i] & keep) == (ours[i] & keep)
        ok = len(ours) == len(ret) and matched == len(ret)
    print(f"{func} {triple} {'MATCH' if ok else 'FAIL'} {matched}/{len(ret)} words", flush=True)
    return ok, matched, len(ret)


# ---- modes -------------------------------------------------------------------------------------------------------

def ladder(probes_path, triples_path):
    probes = [r.split() for r in read_rows(probes_path)]
    triples = triple_names(triples_path)
    k = len(probes)
    full = []
    for t in triples:
        good = 0
        for p in probes:
            good += probe(p[0], p[1], p[2], t)[0]
        if k and good == k:
            full.append(t)
    if len(full) == 1:
        print(f"PIN {full[0]} {k} of {k}")
        return 0
    print("PIN NONE" if not full else "PIN AMBIGUOUS " + ",".join(full))
    return 1


def make_mutation():
    """Copy the control .s with the first one-word R-type instruction -> nop; returns the .c path."""
    os.makedirs(MUT_DIR, exist_ok=True)
    with open(SELFTEST_ASM) as f:
        lines = f.read().split("\n")
    for i, line in enumerate(lines):
        m = INSN_RE.search(line)
        if m and m.group(2) in MUT_OPS and "%" not in m.group(3):
            lines[i] = line[: m.start(2)] + "nop"
            break
    else:
        sys.exit("probe: no mutable instruction in the control")
    with open(os.path.join(MUT_DIR, SELFTEST_FUNC + ".s"), "w") as f:
        f.write("\n".join(lines))
    src = os.path.join(MUT_DIR, "selftest_mut.c")
    with open(src, "w") as f:
        f.write(f'#include "common.h"\n\nINCLUDE_ASM("{MUT_DIR}", {SELFTEST_FUNC});\n')
    return src


def self_test(triples_path):
    triples = triple_names(triples_path)
    find_extent(SELFTEST_PROG, SELFTEST_FUNC)  # splits the program first when asm/ is missing
    mut = make_mutation()
    ok = bool(triples)
    for t in triples:
        ok &= probe(SELFTEST_FUNC, SELFTEST_PROG, SELFTEST_SRC, t)[0]
    for t in triples:
        match, matched, n = probe(SELFTEST_FUNC, SELFTEST_PROG, mut, t)
        ok &= (not match) and matched == n - 1
    print("SELF-TEST OK" if ok else "SELF-TEST FAIL")
    return 0 if ok else 1


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n", 1)[0])
    ap.add_argument("func", nargs="?")
    ap.add_argument("--prog")
    ap.add_argument("--src")
    ap.add_argument("--triple")
    ap.add_argument("--ladder", action="store_true")
    ap.add_argument("--self-test", action="store_true")
    ap.add_argument("--probes", default="config/probes.txt")
    ap.add_argument("--triples", default="config/triples.txt")
    a = ap.parse_args()
    if a.self_test:
        return self_test(a.triples)
    if a.ladder:
        return ladder(a.probes, a.triples)
    if not (a.func and a.prog and a.src and a.triple):
        ap.error("need <func> --prog --src --triple, or --ladder, or --self-test")
    return 0 if probe(a.func, a.prog, a.src, a.triple)[0] else 1


if __name__ == "__main__":
    sys.exit(main())
