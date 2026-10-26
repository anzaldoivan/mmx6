#!/usr/bin/env python3
"""sdk.py -- the vendor SDK leg (phase 1.9 T4): the ledger's vendor TUs linked from the PsyQ SDK's own objects (container).

  sdk.py --sdk DIR [--prog P] [--only RE]
      inputs: campaign/ledger.tsv (each distinct `vendor:<L>.LIB/<TU>` of P), config/boundaries.txt `lib` rows and
      docs/ops/compiler-pin.md `- gap` rows (TU -> LIB/OBJ), config/P.yaml (text subsegments), build/P.ld (splat),
      extracted/retail/iso/P (the retail exe, `PS-X EXE`). DIR is the SDK tree (tools/psyq, mounted at /sdk).
      `--only RE`: substitute only the TUs whose name matches RE (iteration aid; default every vendor TU).
      -> build/sdk/<TU>.o (psyk extract + psyq-obj-parser), build/sdk/P.ld (the fragment: one NOLOAD output section per
         non-text alloc section at its solved address, PROVIDE for each unresolved global), build/sdk/P.main.ld (the
         splat script with each substituted subsegment's .text pointing at its objects, its other sections dropped, the
         fragment INCLUDEd before /DISCARD/), build/sdk/P.mk (SDK_DROP_P / SDK_OBJS_P / SDK_LD_P for the link).
      stdout: per object `SDK DATA <TU> <cmp>/<masked>/<diff>` (its .data+.rdata words vs the image at the solved base,
      relocated words masked; `unsolved` when a base is unknown); per refused object `SDK REFUSE <TU> <why>` (+ first
      differing words); last `SDK <k> of <n> objects substituted`. rc 0 only when k == n.
Solving (REL, in-place addends): with an object's .text at its retail address, each relocated word of the image gives
the target S+A of its symbol (R_MIPS_32 the word, R_MIPS_26 the index, HI16/LO16 the pair); a section symbol fixes that
section's base, an undefined global its address, a global defined in another substituted object that object's section
base. Repeated to a fixpoint over every substituted object (data/rdata relocations join once their base is known).
Vendor bytes stay in build/sdk (firewall-purged) and the sdk volume; stdlib only.
"""
import argparse
import os
import re
import shutil
import struct
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import probe  # noqa: E402  (asm_labels: a label's address from its split asm row)

OUT = "build/sdk"
R_32, R_26, R_HI, R_LO = 2, 4, 5, 6
SHF_ALLOC = 2


def read_elf(path):
    b = open(path, "rb").read()
    assert b[:6] == b"\x7fELF\x01\x01", path
    shoff, = struct.unpack_from("<I", b, 0x20)
    shent, shnum, shstr = struct.unpack_from("<HHH", b, 0x2E)
    raw = [struct.unpack_from("<10I", b, shoff + i * shent) for i in range(shnum)]

    def cstr(tab, off):
        return b[tab + off:b.index(b"\0", tab + off)].decode()
    secs = []
    for name, typ, flags, _a, off, size, link, info, _al, _es in raw:
        secs.append(dict(name=cstr(raw[shstr][4], name), type=typ, flags=flags, off=off, size=size, link=link,
                         info=info, data=b[off:off + size] if typ != 8 else b""))
    syms, rels = [], {}
    for s in secs:
        if s["type"] == 2:
            strtab = secs[s["link"]]["off"]
            for i in range(s["size"] // 16):
                nm, val, _sz, inf, _o, ndx = struct.unpack_from("<IIIBBH", s["data"], i * 16)
                syms.append(dict(name=cstr(strtab, nm), value=val, bind=inf >> 4, type=inf & 15, shndx=ndx))
    for s in secs:
        if s["type"] == 9:
            rels[s["info"]] = [(o, i >> 8, i & 0xFF) for o, i in struct.iter_unpack("<II", s["data"])]
    return secs, syms, rels


def sext16(v):
    return (v & 0xFFFF) - 0x10000 if v & 0x8000 else v & 0xFFFF


def word(data, off):
    return struct.unpack_from("<I", data, off)[0]


def targets(sec, rels, read):
    """[(offset, symidx, target or None, A, type)] for one section; read(off) -> image word at that offset or None.
    The target is S+A, except R_MIPS_26: the image's 28-bit index field (the caller adds the region bits)."""
    out, his = [], {}
    for off, sym, typ in rels:
        x, w = word(sec["data"], off), read(off)
        if typ == R_32:
            out.append((off, sym, w, x, typ))
        elif typ == R_26:
            a = (x & 0x3FFFFFF) << 2
            out.append((off, sym, None if w is None else ((w & 0x3FFFFFF) << 2), a, typ))
        elif typ == R_HI:
            his[sym] = (off, x, w)
        elif typ == R_LO:
            ho, hx, hw = his.get(sym, (None, 0, None))
            if ho is None:
                raise ValueError(f"LO16 without HI16 at {off:#x}")
            a = ((hx & 0xFFFF) << 16) + sext16(x)
            t = None if hw is None or w is None else (((hw & 0xFFFF) << 16) + sext16(w)) & 0xFFFFFFFF
            out.append((ho, sym, t, a, R_HI))
            out.append((off, sym, t, a, typ))
        else:
            raise ValueError(f"unsupported reloc type {typ} at {off:#x}")
    return out


def lnk_symbolize(src, dst):
    """Copy the LNK object src to dst with each `sectstart(N)` (0x0C) / `sectend(N)` (0x16) patch expression, which
    psyq-obj-parser refuses (crt0: 2MBYTE.OBJ), replaced by a reference (0x02) to a new XREF `__sdk_<op>_<section>`
    (same 3 bytes, so no record moves); the solver then fixes those as unresolved globals from the retail relocations.
    Records and expressions per the SDK's DOCS/File Format 47.pdf; an unknown record or expression raises ValueError.
    Returns the number of expressions replaced."""
    b = bytearray(open(src, "rb").read())
    if b[:4] != b"LNK\x02":
        raise ValueError("not LNK v2")
    p, secs, nums, new = 4, {}, set(), {}

    def name(at):
        return b[at + 1:at + 1 + b[at]].decode(), at + 1 + b[at]

    def expr(at):
        op = b[at]
        if op == 0x00:
            return at + 5
        if op in (0x02, 0x04):
            return at + 3
        if op in (0x0C, 0x16):
            sec = struct.unpack_from("<H", b, at + 1)[0]
            k = (("sectstart" if op == 0x0C else "sectend"), secs[sec])
            new.setdefault(k, None)
            b[at] = 0x02
            fix.append((at + 1, k))
            return at + 3
        if 0x20 <= op <= 0x3E:
            return expr(expr(at + 1))
        raise ValueError(f"LNK expression {op:#x} at {at:#x}")
    fix = []
    while True:
        t = b[p]
        if t == 0:
            break
        if t == 2:
            p += 3 + struct.unpack_from("<H", b, p + 1)[0]
        elif t == 6:
            p += 3
        elif t == 8:
            p += 5
        elif t == 10:
            p = expr(p + 4)
        elif t == 12:
            nums.add(struct.unpack_from("<H", b, p + 1)[0])
            p = name(p + 9)[1]
        elif t == 14:
            nums.add(struct.unpack_from("<H", b, p + 1)[0])
            p = name(p + 3)[1]
        elif t == 16:
            num = struct.unpack_from("<H", b, p + 1)[0]
            nums.add(num)
            secs[num], p = name(p + 6)
            secs[num] = secs[num].lstrip(".")
        elif t == 46:
            p += 2
        else:
            raise ValueError(f"LNK record {t} at {p:#x}")
    nxt = max(nums) + 1
    for k in new:
        new[k], nxt = nxt, nxt + 1
    for at, k in fix:
        struct.pack_into("<H", b, at, new[k])
    xref = b"".join(b"\x0e" + struct.pack("<H", n) + bytes([len(s)]) + s.encode()
                    for (op, sec), n in new.items() for s in [f"__sdk_{op}_{sec}"])
    open(dst, "wb").write(bytes(b[:p]) + xref + bytes(b[p:]))
    return len(fix)


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("--sdk", required=True)
    ap.add_argument("--prog", default="SLUS_013.95")
    ap.add_argument("--only", default="")
    a = ap.parse_args()
    prog = a.prog

    # TU list and TU -> (LIB file, OBJ, lo).
    tus = sorted({r.split("\t")[3].split("/", 1)[1] for r in open("campaign/ledger.tsv")
                  if r.startswith(prog + "\t") and r.split("\t")[3].startswith("vendor:")})
    src = {}
    for l in open("config/boundaries.txt"):
        f = l.split()
        if l.startswith("# program "):
            cur = f[2]
        elif f and f[0] == "lib" and cur == prog:
            lib, obj = f[3].split("/")
            src.setdefault(f"{lib.split('.')[0]}_{obj.split('.')[0]}", (lib, obj))
    gap = {}
    for m in re.finditer(r"^- gap (0x[0-9A-Fa-f]{8}) ([A-Za-z0-9_]+)\.LIB/([A-Za-z0-9_]+)\.OBJ", open(
            "docs/ops/compiler-pin.md").read(), re.M):
        src.setdefault(f"{m[2]}_{m[3]}", (m[2] + ".LIB", m[3] + ".OBJ"))
        gap[f"{m[2]}_{m[3]}"] = int(m[1], 16)
    segs = []
    for l in open(f"config/{prog}.yaml"):
        m = re.match(r"\s*- \[0x([0-9A-Fa-f]+), (\w+), (\w+)\]", l) or re.match(
            r"\s*- \{ start: 0x([0-9A-Fa-f]+), type: (\w+), .*name: (\w+)", l)
        if m:
            segs.append((int(m[1], 16), m[2], m[3]))
    exe = open(f"extracted/retail/iso/{prog}", "rb").read()
    assert exe[:8] == b"PS-X EXE", "not a PS-X EXE"
    t_addr, t_size = struct.unpack_from("<II", exe, 0x18)
    vbase = t_addr - 0x800  # yaml offsets are file offsets
    seg_of, seg_obj = {}, {}  # text subsegment -> span, its object in the splat link (asm .s.o or C .c.o)
    for i, (s, typ, name) in enumerate(segs):
        if typ in ("asm", "c"):
            seg_of[name] = (s + vbase, segs[i + 1][0] + vbase)
            seg_obj[name] = f"build/asm/{prog}/{name}.s.o" if typ == "asm" else f"build/src/{prog}/{name}.c.o"

    def img(addr, n=4):
        o = addr - t_addr + 0x800
        return exe[o:o + n] if t_addr <= addr and addr + n <= t_addr + t_size else None

    def libfile(lib):
        for d in ("LIB", "lib", "."):
            p = os.path.join(a.sdk, d)
            if os.path.isdir(p):
                for f in os.listdir(p):
                    if f.lower() == lib.lower():
                        return os.path.join(p, f)
        raise FileNotFoundError(lib)

    # Extract + convert.
    shutil.rmtree(OUT, ignore_errors=True)
    os.makedirs(OUT + "/lib")
    sel = [t for t in tus if re.search(a.only, t)]
    refuse, objs = {}, {}
    for tu in sel:
        if tu not in src:
            refuse[tu] = "no boundaries/gap row"
            continue
        lib, obj = src[tu]
        if lib.upper().endswith(".OBJ"):
            o = libfile(lib)
        else:
            d = f"{OUT}/lib/{lib.split('.')[0]}"
            if not os.path.isdir(d):
                os.makedirs(d)
                subprocess.run(["psyk", "extract", libfile(lib)], cwd=d, check=True, stdout=subprocess.DEVNULL)
            o = os.path.join(d, obj)
            if not os.path.exists(o):
                refuse[tu] = f"{obj} not in {lib}"
                continue
        with open(f"{OUT}/{tu}.log", "w") as lg:
            rc = subprocess.run(["psyq-obj-parser", o, "-n", "-o", f"{OUT}/{tu}.o"], stdout=lg, stderr=lg).returncode
        if rc and any("expression type" in l for l in open(f"{OUT}/{tu}.log")):
            try:  # sectstart/sectend patches (crt0): a scratch copy with those as synthetic symbols, then retry
                lnk_symbolize(o, f"{OUT}/{tu}.sym.obj")
            except ValueError as e:
                refuse[tu] = f"lnk_symbolize: {e}"
                continue
            o = f"{OUT}/{tu}.sym.obj"
            with open(f"{OUT}/{tu}.log", "w") as lg:
                rc = subprocess.run(["psyq-obj-parser", o, "-n", "-o", f"{OUT}/{tu}.o"], stdout=lg,
                                    stderr=lg).returncode
        if rc:
            refuse[tu] = "psyq-obj-parser: " + next((l.strip() for l in open(f"{OUT}/{tu}.log") if "failed" in l),
                                                    f"rc {rc}")
            continue
        objs[tu] = read_elf(f"{OUT}/{tu}.o")

    # Text placement: a named TU is its own subsegment; a gap TU starts at its gap vram inside a hex subsegment.
    lo, owner = {}, {}
    for tu in list(objs):
        secs = objs[tu][0]
        text = next((i for i, s in enumerate(secs) if s["name"] == ".text"), None)
        tsize = secs[text]["size"] if text is not None else 0
        if tu in seg_of:
            lo[tu] = seg_of[tu][0]
            owner[tu] = tu
            if tsize != seg_of[tu][1] - seg_of[tu][0]:
                refuse[tu] = f"text size {tsize:#x} != span {seg_of[tu][1] - seg_of[tu][0]:#x}"
        elif tu in gap:
            lo[tu] = gap[tu]
            owner[tu] = next((n for n, (s, e) in seg_of.items() if s <= gap[tu] < e), None)
        else:
            refuse[tu] = "no subsegment"
    # A hex gap subsegment is substituted only when its gap objects tile it exactly.
    groups = {}
    for tu in objs:
        if tu not in refuse and owner.get(tu):
            groups.setdefault(owner[tu], []).append(tu)
    for seg, members in list(groups.items()):
        members.sort(key=lambda t: lo[t])
        at = seg_of[seg][0]
        for t in members:
            secs = objs[t][0]
            sz = next((s["size"] for s in secs if s["name"] == ".text"), 0)
            if lo[t] != at:
                refuse[t] = f"tiling: {seg} expects {at:#x}, object at {lo[t]:#x}"
            at = lo[t] + sz
        if at != seg_of[seg][1]:
            for t in members:
                refuse.setdefault(t, f"tiling: {seg} ends {seg_of[seg][1]:#x}, objects end {at:#x}")

    # Text check (relocated words masked) for every object still in.
    for tu in sorted(objs):
        if tu in refuse:
            continue
        secs, syms, rels = objs[tu]
        ti = next(i for i, s in enumerate(secs) if s["name"] == ".text")
        t = secs[ti]
        mask = {o for o, _s, _t in rels.get(ti, [])}
        r = img(lo[tu], t["size"])
        if r is None:
            refuse[tu] = "text outside image"
            continue
        diffs = [o for o in range(0, t["size"], 4) if o not in mask and r[o:o + 4] != t["data"][o:o + 4]]
        if diffs:
            refuse[tu] = f"text {len(diffs)} words differ; first " + " ".join(
                f"+{o:#x} obj {word(t['data'], o):08x} retail {word(r, o):08x}" for o in diffs[:4])

    # Solve section bases and global addresses to a fixpoint over the substituted set. A global of a NOBITS section
    # is solved on its own (bss): psyq-obj-parser folds the LNK's XBSS commons into one .bss, while psylink placed
    # each one globally (retail order differs from the object's), so it gets a hard assignment, not a section base.
    live = sorted(t for t in objs if t not in refuse)
    defs, bssdef, base, addr, conflict = {}, {}, {}, {}, {}
    for tu in live:
        secs, syms, _r = objs[tu]
        for s in syms:
            if s["bind"] in (1, 2) and 0 < s["shndx"] < 0xFF00:  # 2: weak (an XBSS common)
                (bssdef if secs[s["shndx"]]["type"] == 8 else defs).setdefault(s["name"], (tu, s["shndx"], s["value"]))
        base[(tu, next(i for i, x in enumerate(secs) if x["name"] == ".text"))] = lo[tu]

    def setkey(k, v, tu):
        d = base if isinstance(k, tuple) else addr
        if k in d and d[k] != v:
            conflict.setdefault(tu, f"{k} solved {d[k]:#x} and {v:#x}")
        elif k not in d:
            d[k] = v
            return True
        return False

    changed = True
    while changed:
        changed = False
        for name, (tu, ndx, val) in defs.items():
            if (tu, ndx) in base and name not in addr:
                changed |= setkey(name, base[(tu, ndx)] + val, tu)
            elif name in addr and (tu, ndx) not in base:
                changed |= setkey((tu, ndx), addr[name] - val, tu)
        for tu in live:
            secs, syms, rels = objs[tu]
            for si, rl in rels.items():
                if (tu, si) not in base:
                    continue
                b0 = base[(tu, si)]

                def rd(off, b0=b0):
                    w = img(b0 + off)
                    return None if w is None else word(w, 0)
                try:
                    tg = targets(secs[si], rl, rd)
                except ValueError as e:
                    refuse[tu] = str(e)
                    continue
                for off, sym, t, add, typ in tg:
                    if t is None:
                        continue
                    s = syms[sym]
                    if typ == R_26:
                        t = ((t - add) & 0x0FFFFFFF) | ((b0 + off + 4) & 0xF0000000)
                        add = 0
                    v = (t - add) & 0xFFFFFFFF
                    if s["type"] == 3:
                        changed |= setkey((tu, s["shndx"]), v, tu)
                    elif s["name"] in bssdef:
                        changed |= setkey(s["name"], v, tu)
                    elif s["shndx"] == 0:
                        if s["name"] in defs:
                            d = defs[s["name"]]
                            changed |= setkey((d[0], d[1]), (v - d[2]) & 0xFFFFFFFF, tu)
                        else:
                            changed |= setkey(s["name"], v, tu)
                    else:
                        changed |= setkey((tu, s["shndx"]), (v - s["value"]) & 0xFFFFFFFF, tu)
    for tu, why in conflict.items():
        refuse.setdefault(tu, "conflict " + why)
    live = [t for t in live if t not in refuse]
    subst = {}
    for tu in sorted(live, key=lambda t: lo[t]):
        subst.setdefault(owner[tu], []).append(tu)
    subst = {s: m for s, m in subst.items() if all(t in live for t in groups.get(s, m))}
    live = [t for t in live if t in {x for m in subst.values() for x in m}]  # the objects that join the link

    # Fragment, main script, make include.
    frag = [f"/* generated by tools/mmx6/sdk.py: SDK object sections at their solved retail addresses (NOLOAD) */"]
    unsolved = 0
    for tu in live:
        secs, syms, rels = objs[tu]
        cmp_ = msk = dif = 0
        un = False
        for i, s in enumerate(secs):
            if not s["flags"] & SHF_ALLOC or s["name"] == ".text":
                continue
            b0 = base.get((tu, i))
            if b0 is None:
                unsolved += 1
                un |= s["type"] != 8  # an unreferenced bss base is no data gap
                frag.append(f".sdk.{tu}{s['name']} 0 (NOLOAD) : SUBALIGN(1) {{ {OUT}/{tu}.o({s['name']}) }}")
                continue
            frag.append(f".sdk.{tu}{s['name']} {b0:#x} (NOLOAD) : SUBALIGN(1) {{ {OUT}/{tu}.o({s['name']}) }}")
            if s["type"] == 8:
                continue
            r = img(b0, s["size"])
            if r is None:
                un = True
                continue
            mask = {o for o, _s, _t in rels.get(i, [])}
            for o in range(0, s["size"], 4):
                cmp_ += 1
                if o in mask:
                    msk += 1
                elif r[o:o + 4] != s["data"][o:o + 4]:
                    dif += 1
        print(f"SDK DATA {tu} {cmp_}/{msk}/{dif}" + (" unsolved" if un else ""))
    need, have = set(), set()
    for tu in live:
        need |= {s["name"] for s in objs[tu][1] if s["shndx"] == 0 and s["bind"] == 1 and s["name"]}
        have |= {s["name"] for s in objs[tu][1] if s["bind"] in (1, 2) and 0 < s["shndx"] < 0xFF00}
    for n in sorted(need - have):
        d = defs.get(n) or bssdef.get(n)  # defined only in an object left out of the link: its solved address
        v = addr.get(n, base[(d[0], d[1])] + d[2] if d and (d[0], d[1]) in base else None)
        frag.append(f"PROVIDE({n} = {v or 0:#x});")
        unsolved += v is None
    for n in sorted(bssdef):
        if bssdef[n][0] in live and n in addr:
            frag.append(f"{n} = {addr[n]:#x};")

    # Labels of the dropped subsegments that other objects may reference (jump tables in the shared rodata blocks
    # name `.L<addr>`): the replacing text is identical at those addresses, so each is PROVIDEd at its asm row's vram.
    for seg in sorted(subst):
        srcs = [f"asm/{prog}/{seg}.s"]
        nm = f"asm/{prog}/nonmatchings/{seg}"
        srcs += sorted(os.path.join(nm, f) for f in os.listdir(nm)) if os.path.isdir(nm) else []
        for path in srcs:
            if os.path.exists(path):
                for _, name, vram in probe.asm_labels(open(path).read()):
                    frag.append(f"PROVIDE({name} = 0x{vram:08X});")
    open(f"{OUT}/{prog}.ld", "w").write("\n".join(frag) + "\n")
    drop = [seg_obj[s] for s in subst]
    ld = []
    for l in open(f"build/{prog}.ld"):
        m = re.match(r"(\s*)build/(?:asm|src)/" + re.escape(prog) + r"/(\w+)\.[sc]\.o\((\.\w+)\);", l)
        if m and m[2] in subst:
            if m[3] == ".text":
                ld.append(m[1] + " ".join(f"{OUT}/{t}.o(.text);" for t in subst[m[2]]) + "\n")
            continue
        if l.strip() == "/DISCARD/ :":
            ld.append(f"    INCLUDE {OUT}/{prog}.ld\n\n")
        ld.append(l)
    open(f"{OUT}/{prog}.main.ld", "w").write("".join(ld))
    k = sum(len(m) for m in subst.values())
    with open(f"{OUT}/{prog}.mk", "w") as f:
        f.write(f"# generated by tools/mmx6/sdk.py\nSDK_DROP_{prog} := {' '.join(drop)}\n"
                f"SDK_OBJS_{prog} := {' '.join(f'{OUT}/{t}.o' for m in subst.values() for t in m)}\n"
                f"SDK_LD_{prog} := {OUT}/{prog}.main.ld\n")
    for tu in sorted(set(sel) - {t for m in subst.values() for t in m}):
        print(f"SDK REFUSE {tu} {refuse.get(tu, 'gap subsegment partner refused')}")
    print(f"SDK unsolved {unsolved} (section bases or globals referenced only from non-emitted sections)")
    print(f"SDK {k} of {len(sel)} objects substituted")
    return 0 if k == len(sel) else 1


if __name__ == "__main__":
    sys.exit(main())
