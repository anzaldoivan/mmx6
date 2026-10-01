#!/usr/bin/env python3
"""optscan.py -- per-function codegen census over the splat asm of every program (container, stdlib only).

  optscan.py --prog <p>
  optscan.py --all            (programs = config/*.yaml stems, sorted)
      -> per function:  `<prog> <func> 0x<vram> <n>w <O0|O2> fp=<0|1> nopld=<a>/<b> gprel=<k> div=<expand>/<bare>`
         per program:   `<prog> functions <n> O0 <a> O2 <b> gprel <g> div-expand <d> div-bare <e> fp-only <f>`
                        (g, d, e = functions having >= 1), then
                        `RUN <prog> <O0|O2> 0x<first>-0x<last> <k> functions <firstTU>..<lastTU>` per maximal
                        same-class run in vram order (first = first function's start vram, last = last function's
                        last instruction vram; TU = nonmatchings/<TU>/ dir, else the .s file stem)
         last line:     `SCANNED <n> functions in <m> programs`; rc 1 if a program has no asm/<p>/ after
                        `make -s build/split/<p>.stamp`, or 0 functions
  optscan.py --self-test
      -> two synthetic functions (encoder helpers, no literal words) written as splat .s under
         .run/optscan/selftest/ and scanned by the same parser; planted -O0 must be O0 gprel=1 div=1/0, planted
         -O2 must be O2 div=0/1; `SELF-TEST OK` (rc 0) or `SELF-TEST FAIL` (rc 1)

Functions: `glabel <f>` .. `endlabel <f>` or the next glabel, under asm/<p>/ (incl. nonmatchings/); words from the
splat comment `/* <off> <vram> <word> */` (word printed in file byte order, i.e. little-endian bytes); deduped by vram, sorted by vram; nothing trimmed.
Classification decodes words (opcode/rs/rt/rd/funct), never mnemonic text:
  fp       `addu|or $fp,$sp,$zero` (rs=29 rt=0 rd=30) within the first 8 instructions
  nopld    a/b: b = loads (lb lh lwl lw lbu lhu lwr lwc2), a = loads immediately followed by word 0
  gprel    count of load/store/addiu with rs=28
  div      expand = div/divu followed within 4 instructions by `break 7`; bare = div/divu without it
  O0       fp and (b < 2 or a/b >= 0.5)
  O2       no -O0 tell (anything not O0)
  fp-only  fp tell without O0 (counted inside O2)
Firewall G12: prints names, addresses and counts only, never instruction words, bytes or disassembly; scratch
under .run/.
"""
import argparse
import os
import re
import subprocess
import sys

INSN_RE = re.compile(r"/\*\s+[0-9A-Fa-f]+\s+([0-9A-Fa-f]{8})\s+([0-9A-Fa-f]{8})\s+\*/")
LOAD_OPS = {0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x32}
STORE_OPS = {0x28, 0x29, 0x2A, 0x2B, 0x2E, 0x3A}
ADDIU = 0x09
F_ADDU, F_OR, F_DIV, F_DIVU, F_BREAK = 0x21, 0x25, 0x1A, 0x1B, 0x0D
SELFTEST_DIR = ".run/optscan/selftest"


# ---- encoders (self-test) ------------------------------------------------------------------------------------------

def r_type(rs, rt, rd, shamt, funct):
    return (rs << 21) | (rt << 16) | (rd << 11) | (shamt << 6) | funct


def i_type(op, rs, rt, imm):
    return (op << 26) | (rs << 21) | (rt << 16) | (imm & 0xFFFF)


def break_code(code):
    return (code << 16) | F_BREAK


# ---- parse ---------------------------------------------------------------------------------------------------------

def parse_dir(root):
    """{vram: (name, tu, [words])} of every glabel function under root."""
    funcs = {}
    for d, dirs, files in sorted(os.walk(root)):
        dirs.sort()
        for fname in sorted(files):
            if not fname.endswith(".s"):
                continue
            path = os.path.join(d, fname)
            rel = os.path.relpath(path, root).split(os.sep)
            tu = rel[rel.index("nonmatchings") + 1] if "nonmatchings" in rel[:-1] else fname[:-2]
            cur, rows = None, []

            def close():
                if cur is not None and rows:
                    v = rows[0][0]
                    if v not in funcs:
                        funcs[v] = (cur, tu, [w for _, w in sorted(rows)])

            with open(path, errors="replace") as f:
                for line in f:
                    s = line.strip()
                    if s.startswith("glabel "):
                        close()
                        cur, rows = s.split()[1], []
                        continue
                    if cur is None:
                        continue
                    if s == f"endlabel {cur}":
                        close()
                        cur, rows = None, []
                        continue
                    m = INSN_RE.search(line)
                    if m:
                        rows.append((int(m.group(1), 16), int.from_bytes(bytes.fromhex(m.group(2)), "little")))
            close()
    return funcs


# ---- classify ------------------------------------------------------------------------------------------------------

def classify(words):
    op = [w >> 26 for w in words]
    rs = [(w >> 21) & 31 for w in words]
    rt = [(w >> 16) & 31 for w in words]
    rd = [(w >> 11) & 31 for w in words]
    fn = [w & 63 for w in words]
    n = len(words)
    fp = any(op[i] == 0 and fn[i] in (F_ADDU, F_OR) and rs[i] == 29 and rt[i] == 0 and rd[i] == 30
             for i in range(min(8, n)))
    loads = [i for i in range(n) if op[i] in LOAD_OPS]
    b = len(loads)
    a = sum(1 for i in loads if i + 1 < n and words[i + 1] == 0)
    gprel = sum(1 for i in range(n) if (op[i] in LOAD_OPS or op[i] in STORE_OPS or op[i] == ADDIU) and rs[i] == 28)
    expand = bare = 0
    for i in range(n):
        if op[i] == 0 and fn[i] in (F_DIV, F_DIVU):
            if any(words[j] & 0xFC00003F == F_BREAK and ((words[j] >> 6) & 0xFFFFF) in (7 << 10, 7)
                   for j in range(i + 1, min(i + 5, n))):
                expand += 1
            else:
                bare += 1
    o0 = fp and (b < 2 or a / b >= 0.5)
    return {"cls": "O0" if o0 else "O2", "fp": int(fp), "a": a, "b": b, "gprel": gprel,
            "expand": expand, "bare": bare, "fponly": fp and not o0}


def scan(prog, root, out):
    """Print function, summary and RUN lines; return the function count."""
    funcs = parse_dir(root)
    recs = []
    for v in sorted(funcs):
        name, tu, words = funcs[v]
        c = classify(words)
        recs.append((v, name, tu, len(words), c))
        out(f"{prog} {name} 0x{v:08X} {len(words)}w {c['cls']} fp={c['fp']} nopld={c['a']}/{c['b']} "
            f"gprel={c['gprel']} div={c['expand']}/{c['bare']}")
    cs = [r[4] for r in recs]
    o0 = sum(1 for c in cs if c["cls"] == "O0")
    out(f"{prog} functions {len(recs)} O0 {o0} O2 {len(recs) - o0} gprel {sum(1 for c in cs if c['gprel'])} "
        f"div-expand {sum(1 for c in cs if c['expand'])} div-bare {sum(1 for c in cs if c['bare'])} "
        f"fp-only {sum(1 for c in cs if c['fponly'])}")
    i = 0
    while i < len(recs):
        j = i
        while j + 1 < len(recs) and recs[j + 1][4]["cls"] == recs[i][4]["cls"]:
            j += 1
        last = recs[j][0] + 4 * (recs[j][3] - 1)
        out(f"RUN {prog} {recs[i][4]['cls']} 0x{recs[i][0]:08X}-0x{last:08X} {j - i + 1} functions "
            f"{recs[i][2]}..{recs[j][2]}")
        i = j + 1
    return len(recs)


def scan_prog(prog):
    root = f"asm/{prog}"
    if not os.path.isdir(root):
        subprocess.run(["make", "-s", f"build/split/{prog}.stamp"], check=False, stdout=subprocess.DEVNULL)
    if not os.path.isdir(root):
        print(f"optscan: no {root}/")
        return 0
    return scan(prog, root, print)


# ---- self-test -----------------------------------------------------------------------------------------------------

def self_test():
    nop = 0
    o0 = [
        i_type(ADDIU, 29, 29, -24),           # addiu sp,sp,-24
        i_type(0x2B, 29, 30, 16),             # sw fp,16(sp)
        r_type(29, 0, 30, 0, F_ADDU),         # addu fp,sp,zero
        i_type(0x23, 30, 2, 0), nop,          # lw v0,0(fp); nop
        i_type(0x23, 30, 3, 4), nop,          # lw v1,4(fp); nop
        i_type(0x23, 28, 4, 0x10), nop,       # lw a0,%gp_rel(x)(gp); nop
        r_type(2, 3, 0, 0, F_DIV),            # div v0,v1
        i_type(0x05, 3, 0, 2), nop,           # bnez v1,+2; nop
        break_code(7),                        # break 7
        r_type(31, 0, 0, 0, 0x08), nop,       # jr ra; nop
    ]
    o2 = [
        i_type(0x23, 4, 2, 0),                # lw v0,0(a0)
        i_type(0x23, 4, 3, 4),                # lw v1,4(a0)
        r_type(4, 5, 6, 0, F_ADDU),           # addu a2,a0,a1 (no nop after the loads)
        r_type(2, 3, 0, 0, F_DIVU),           # divu v0,v1
        r_type(31, 0, 0, 0, 0x08),            # jr ra
        r_type(4, 0, 2, 0, F_ADDU),           # addu v0,a0,zero
    ]
    root = os.path.join(SELFTEST_DIR, "asm", "SELFTEST")
    os.makedirs(os.path.join(root, "nonmatchings", "planted"), exist_ok=True)
    vram = 0x80010000
    for name, words in (("planted_O0", o0), ("planted_O2", o2)):
        with open(os.path.join(root, "nonmatchings", "planted", f"{name}.s"), "w") as f:
            f.write(f"glabel {name}\n")
            for k, w in enumerate(words):
                v = vram + 4 * k
                f.write(f"  /* {v - 0x80010000:X} {v:08X} {w.to_bytes(4, 'little').hex().upper()} */  insn\n")
            f.write(f"endlabel {name}\n")
        vram += 4 * len(words) + 0x100
    funcs = parse_dir(root)
    got = {name: classify(words) for name, _, words in funcs.values()}
    ok = (len(got) == 2
          and got["planted_O0"]["cls"] == "O0" and got["planted_O0"]["gprel"] == 1
          and (got["planted_O0"]["expand"], got["planted_O0"]["bare"]) == (1, 0)
          and got["planted_O2"]["cls"] == "O2" and got["planted_O2"]["fp"] == 0
          and (got["planted_O2"]["expand"], got["planted_O2"]["bare"]) == (0, 1))
    for name in sorted(got):
        c = got[name]
        print(f"{name} {c['cls']} fp={c['fp']} nopld={c['a']}/{c['b']} gprel={c['gprel']} "
              f"div={c['expand']}/{c['bare']}")
    print("SELF-TEST OK" if ok else "SELF-TEST FAIL")
    return 0 if ok else 1


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    g = ap.add_mutually_exclusive_group(required=True)
    g.add_argument("--prog")
    g.add_argument("--all", action="store_true")
    g.add_argument("--self-test", action="store_true")
    args = ap.parse_args()
    if args.self_test:
        return self_test()
    progs = [args.prog] if args.prog else sorted(f[:-5] for f in os.listdir("config") if f.endswith(".yaml"))
    total, rc = 0, 0
    for p in progs:
        n = scan_prog(p)
        if n == 0:
            print(f"optscan: {p} has 0 functions")
            rc = 1
        total += n
    print(f"SCANNED {total} functions in {len(progs)} programs")
    return rc


if __name__ == "__main__":
    sys.exit(main())
