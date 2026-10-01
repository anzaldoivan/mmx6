#!/usr/bin/env python3
"""loadmap.py --captures DIR --summary -- overlay load captures summary (T5.c1 stub; T6 adds --out/--self-test).

Reads DIR/*.jsonl (tools/mmx6/redux/loads.lua: one record per BinSeek load, caller = return address) and prints
event counts per dest base and per caller, plus the dest(s) used by the call at 0x80013E7C (caller 0x80013E84;
its base is the word at 0x80010000, recorded as w10000). rc 0 iff >= 1 record loads to each required base:
0x801EA000, 0x800FA000 and the 0x80013E7C target (>= 1 record from that caller); else rc 1 naming the missing
base; rc 2 on bad inputs. Stdlib only.

T6.c1: loadmap.py [--captures DIR] [--out FILE] [--self-test] -- the member -> base map (config/loadmap.txt).
Static side, decoded from the exe text (exeproof.load_image: extracted/retail/iso/SLUS_013.95, sha1 = manifest):
  each BinSeek (0x80016858) call site in SITES: a1 = the lui/ori (or lui + lw: the word at 0x80010000) reaching
  the jal; a0 from the instruction(s) named in SITES: `li`/`move` = one member, `lhu a0,0(v0)` = a halfword
  table whose address is the lui/addiu of the register added into v0. No caller bounds its table index, so a
  table ends at its first value >= 59; zero halfwords are unused slots (member 0 is the 0x801EA000 overlay),
  skipped. Members: extracted/retail/rock/NN.bin (sha1 = manifest).
Runtime side: a capture proves (index, dest) iff before[:size] != member[:size] and after[:size] == member[:size];
  a capture whose dest differs from its call site's static base, or whose index is not in the site's static
  member set, is a contradiction (rc 1).
Class: empty = size <= 4; code = >= 1 `addiu sp,sp,-N` and a `jr ra` (word-aligned) and a static or runtime
  base; data = the rest. N = 1 (exe) + count(code).
Controls: positive = exe function bodies (exeproof.load_bodies) equal in every .run/redux/smoke/*.bin and each
  proven member equal at its base; negative (each must fail to match) per proven member = the member at a
  4-byte-shifted base, the member vs another proven member's after-dump, a word-shuffled after-dump.
rc 0 iff every control passes and no contradiction; 1 otherwise; 2 on bad inputs. --self-test runs proof,
class and control logic on synthetic bytes (no game data).
"""
import argparse
import hashlib
import json
import random
import struct
import sys
from collections import Counter
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import exeproof  # noqa: E402

FIXED_BASES = (0x801EA000, 0x800FA000)
E7C_RA = 0x80013E84

REPO = exeproof.REPO
ROCK = REPO / "extracted/retail/rock"
SMOKE = REPO / ".run/redux/smoke"
LOAD, RAM_BASE, BINSEEK, NMEM = 0x80010000, 0x80000000, 0x80016858, 59
A0, A1, V0 = 4, 5, 2
# call site -> addresses of the instruction(s) that set a0 on the paths reaching it (read from the listing,
# docs/formats.md ## ROCK_X6.BIN; each is decoded and asserted below)
SITES = {
    0x80013CDC: (0x80013CD4,),
    0x80013CF0: (0x80013CD0,),  # bnez delay slot, branch to 0x80013CEC
    0x80013D54: (0x80013D4C,),
    0x80013E40: (0x80013E3C,),
    0x80013E7C: (0x80013E78,),
    0x80052E94: (0x80052E78, 0x80052E88, 0x80052E8C),
}
PROLOGUE_MASK, PROLOGUE = 0xFFFF8000, 0x27BD8000  # addiu sp,sp,-N
JR_RA = 0x03E00008


def s16(v):
    return v - 0x10000 if v & 0x8000 else v


def bad(msg):
    print(f"loadmap: {msg}", file=sys.stderr)
    sys.exit(2)


def dec(img, a):
    w = struct.unpack_from("<I", img, a - LOAD)[0]
    return w, w >> 26, (w >> 21) & 31, (w >> 16) & 31, (w >> 11) & 31, w & 0xFFFF, w & 63


def writes(d, reg):
    w, op, rs, rt, rd, imm, fn = d
    return (op == 0 and fn in (0x21, 0x25) and rd == reg) or (op in (0x09, 0x0D, 0x0F, 0x23, 0x25) and rt == reg)


def back_def(img, start, reg):
    for a in range(start, start - 0x80, -4):
        d = dec(img, a)
        if writes(d, reg):
            return a, d
    bad(f"no def of r{reg} within 0x80 B before 0x{start:08X}")


def eval_reg(img, start, reg):
    """Constant value of reg at `start` from lui/ori/addiu/lw chains (lw -> the exe word it loads)."""
    if reg == 0:
        return 0
    a, (w, op, rs, rt, rd, imm, fn) = back_def(img, start, reg)
    if op == 0x0F:
        return (imm << 16) & 0xFFFFFFFF
    if op == 0x0D:
        return eval_reg(img, a - 4, rs) | imm
    if op == 0x09:
        return (eval_reg(img, a - 4, rs) + s16(imm)) & 0xFFFFFFFF
    if op == 0x23:
        return dec(img, (eval_reg(img, a - 4, rs) + s16(imm)) & 0xFFFFFFFF)[0]
    bad(f"cannot evaluate r{reg} at 0x{a:08X}")


def read_table(img, addr):
    vals, n = [], 0
    while True:
        v = struct.unpack_from("<H", img, addr + 2 * n - LOAD)[0]
        if v >= NMEM:
            return vals, n
        vals.append(v)
        n += 1


def decode_static(img):
    """-> ({site: (base, members)}, [table header lines])"""
    sites, heads = {}, []
    for site, defs in sorted(SITES.items()):
        w, op = dec(img, site)[:2]
        if op != 3 or (0x80000000 | ((w & 0x3FFFFFF) << 2)) != BINSEEK:
            bad(f"0x{site:08X} is not jal BinSeek")
        base, members = eval_reg(img, site + 4, A1), set()
        for da in defs:
            d = dec(img, da)
            w, op, rs, rt, rd, imm, fn = d
            if not writes(d, A0):
                bad(f"0x{da:08X} does not set a0")
            if op == 0x09 and rs == 0:
                members.add(s16(imm))
            elif op == 0 and rs == 0 and rt == 0:
                members.add(0)
            elif op == 0x25 and rs == V0 and imm == 0:
                aa, (w2, op2, rs2, rt2, rd2, _, fn2) = back_def(img, da - 4, V0)
                if not (op2 == 0 and fn2 == 0x21 and rs2 == V0):
                    bad(f"0x{aa:08X}: want addu v0,v0,R before the lhu at 0x{da:08X}")
                taddr = eval_reg(img, aa - 4, rt2)
                vals, n = read_table(img, taddr)
                z = vals.count(0)
                members |= {v for v in vals if v}
                heads.append(f"# table 0x{taddr:08X} : {n} entries, no index bound at caller 0x{site:08X}; "
                             f"stop at first value >= {NMEM}; {z} zero slots skipped")
            else:
                bad(f"0x{da:08X}: unrecognised a0 def")
        sites[site] = (base, members)
    return sites, heads


def sha_checked(path, want):
    if not path.is_file():
        bad(f"missing {path} (run make extract)")
    data = path.read_bytes()
    if hashlib.sha1(data).hexdigest() != want:
        bad(f"sha1 mismatch {path}")
    return data


def load_members():
    recs = {}
    for line in exeproof.MANIFEST.read_text().splitlines():
        r = json.loads(line)
        if r.get("kind") == "rock":
            recs[r["index"]] = r
    if sorted(recs) != list(range(NMEM)):
        bad(f"manifest rock records != {NMEM}")
    return [sha_checked(exeproof.REPO / "extracted/retail" / recs[k]["path"], recs[k]["sha1"]) for k in range(NMEM)]


def matches(mem, ram, n):
    return len(ram) >= n and len(mem) >= n and ram[:n] == mem[:n]


def proves(before, after, mem, size):
    return before[:size] != mem[:size] and matches(mem, after, size)


def is_code(b):
    ws = [w for (w,) in struct.iter_unpack("<I", b[:len(b) & ~3])]
    return any((w & PROLOGUE_MASK) == PROLOGUE for w in ws) and JR_RA in ws


def classify(mem, has_base):
    return "empty" if len(mem) <= 4 else "code" if has_base and is_code(mem) else "data"


def shuffled(b, seed):
    ws = [b[i:i + 4] for i in range(0, len(b) & ~3, 4)]
    random.Random(seed).shuffle(ws)
    return b"".join(ws)


def member_controls(proven):
    """proven: sorted [(index, base, mem, after, size)] -> [(label, ok)]; ok = matched as expected."""
    out = []
    for i, (k, base, mem, after, size) in enumerate(proven):
        out.append((f"positive member {k} at 0x{base:08X}", matches(mem, after, size)))
        out.append((f"negative member {k} at 0x{base + 4:08X} (shifted)", not matches(mem[:size - 4], after[4:], size - 4)))
        others = [p for p in proven if p[0] != k]
        if others:
            j, _, _, aj, sj = others[i % len(others)]
            n = min(size, sj)
            out.append((f"negative member {k} vs member {j} after-dump", not matches(mem, aj, n)))
        else:
            out.append((f"negative member {k} vs another member: none proven", False))
        sh = shuffled(after[:size], k)
        out.append((f"negative member {k} vs word-shuffled after-dump", not matches(mem, sh, len(sh)) and len(sh) > 4))
    return out


def self_test():
    rng = random.Random(6)
    mems = {7: bytes(rng.randrange(256) for _ in range(66)), 9: bytes(rng.randrange(256) for _ in range(40))}
    ok = True
    proven = []
    for k, m in sorted(mems.items()):
        after = m + b"\0\0"
        ok &= proves(bytes(len(m)), after, m, len(m))
        ok &= not proves(m, after, m, len(m))                       # already resident: not a proof
        ok &= not proves(bytes(len(m)), after[:5] + b"\xff" + after[6:], m, len(m))
        proven.append((k, 0x80100000 + 0x1000 * k, m, after, len(m)))
    ctl = member_controls(proven)
    ok &= len(ctl) == 8 and all(c for _, c in ctl)
    ok &= not all(c for _, c in member_controls(proven[:1]))       # one member: cross control cannot pass
    code = struct.pack("<4I", 1, 0x27BDFFE8, JR_RA, 0)
    ok &= classify(code, True) == "code" and classify(code, False) == "data"
    ok &= classify(struct.pack("<I", JR_RA) * 3, True) == "data" and classify(b"\1\0\0\0", True) == "empty"
    print(f"loadmap self-test: {'PASS' if ok else 'FAIL'} ({len(ctl)} synthetic controls)")
    return 0 if ok else 1


def build(captures):
    img = exeproof.load_image()
    mems = load_members()
    sites, heads = decode_static(img)
    w10000 = dec(img, LOAD)[0]
    static = {}  # member -> {base: {sites}}
    for site, (base, members) in sites.items():
        for m in members:
            static.setdefault(m, {}).setdefault(base, set()).add(site)
    files = sorted(Path(captures).glob("*.jsonl"))
    if not files:
        bad(f"no *.jsonl in {captures}")
    runtime, contra, proven, nrec = {}, [], {}, 0
    for f in files:
        for line in f.read_text().splitlines():
            if not line.strip():
                continue
            r, nrec = json.loads(line), nrec + 1
            k, dest, size, site = r["index"], int(r["dest"], 16), r["size"], int(r["caller"], 16) - 8
            sbase, smem = sites.get(site, (None, set()))
            if dest != sbase or k not in smem:
                contra.append(f"CONTRADICTION {f.stem} seq {r['seq']}: member {k} dest 0x{dest:08X} via 0x{site:08X}")
            if r.get("before") is None or r.get("after") is None:
                continue
            before, after = (f.parent / r["before"]).read_bytes(), (f.parent / r["after"]).read_bytes()
            if proves(before, after, mems[k], size):
                runtime.setdefault(k, {}).setdefault(dest, set()).add(f.stem)
                proven.setdefault((k, dest), (after, size))
    lines = ["# config/loadmap.txt -- generated by tools/mmx6/loadmap.py (make loadmap); do not edit",
             "# rows: index base class evidence",
             f"# word 0x{LOAD:08X} = 0x{w10000:08X} (base of the 0x80013E7C path)"]
    lines += heads
    for site, (base, members) in sorted(sites.items()):
        lines.append(f"# site 0x{site:08X} : base 0x{base:08X}, members {','.join(map(str, sorted(members)))}")
    lines.append(f"# captures: {', '.join(f.stem for f in files)} ({nrec} loads)")
    lines.append(f"exe 0x{LOAD:08X} code exe-header")
    counts = Counter()
    for k in range(NMEM):
        bases = sorted(set(static.get(k, {})) | set(runtime.get(k, {})))
        cls = classify(mems[k], bool(bases))
        counts[cls] += 1
        if k in runtime:
            ev = "runtime-diff:" + ",".join(sorted(set().union(*runtime[k].values())))
        elif k in static:
            ev = "static:" + ",".join(f"0x{s:08X}" for s in sorted(set().union(*static[k].values())))
        else:
            ev = "none"
        lines.append(f"{k} {','.join(f'0x{b:08X}' for b in bases) or '-'} {cls} {ev}")
    lines.append(f"# classes: code {counts['code']}, data {counts['data']}, empty {counts['empty']}")
    lines.append(f"N = {1 + counts['code']}")
    # controls
    image_bodies = exeproof.load_bodies(img)
    dumps = sorted(SMOKE.glob("*.bin"))
    if not dumps:
        bad(f"no *.bin in {SMOKE}")
    ctl = []
    for p in dumps:
        ram = p.read_bytes()
        ok = all(img[a - LOAD:a - LOAD + 4] == ram[a - RAM_BASE:a - RAM_BASE + 4]
                 for lo, hi, _ in image_bodies for a in range(lo & ~3, hi, 4))
        ctl.append((f"positive exe at 0x{LOAD:08X} vs {p.parent.name}/{p.name}", ok))
    ctl += member_controls([(k, d, mems[k], a, s) for (k, d), (a, s) in sorted(proven.items())])
    for label, ok in ctl:
        lines.append(f"control {'PASS' if ok else 'FAIL'} {label}")
    lines += contra
    npass = sum(ok for _, ok in ctl)
    lines.append(f"CONTROLS {npass}/{len(ctl)} pass")
    return lines, 0 if npass == len(ctl) and not contra else 1


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--captures", default=".run/redux/loads", help="dir of <run>.jsonl capture files")
    ap.add_argument("--summary", action="store_true", help="print counts per dest base and caller; gate on bases")
    ap.add_argument("--out", help="write the map here (default: stdout)")
    ap.add_argument("--self-test", action="store_true", help="run the proof/class/control logic on synthetic bytes")
    a = ap.parse_args()
    if a.self_test:
        return self_test()
    if not a.summary:
        lines, rc = build(a.captures)
        text = "\n".join(lines) + "\n"
        if a.out:
            Path(a.out).write_text(text)
            print("\n".join(ln for ln in lines if ln.startswith(("# classes", "N =", "CONTROLS", "CONTRADICTION",
                                                                     "control FAIL"))))
            print(f"loadmap: wrote {a.out}")
        else:
            sys.stdout.write(text)
        return rc
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
