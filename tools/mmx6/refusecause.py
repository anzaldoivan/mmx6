#!/usr/bin/env python3
"""refusecause.py -- one cause per plumbing-refused ledger row: why the member's byte gate refused (container, stdlib).

  refusecause.py --prog P
      -> every campaign/ledger.tsv row of P with blocker plumbing:R5|R2|R4: its refused config/dedup_registry.txt row
         (key = the ledger's dup key, else the member's first refused row), re-gated alone in a scratch tree
         (propagate.make_tree under .run/propagate/tree/rc_<P>; /work/src is never edited; removed at the end):
         propagate.key_plan(key, dry) -> gate_members on the one member (R1-R4, no recovery steps); a gated member
         gets bank.rung5 (clean rebuild + hash, typecheck, sig) and a word diff of its linked span vs retail; the
         member's edits always restored (propagate.restore_prog, try/finally). Writes build/refusecause/<P>.tsv,
         prints one line per member `<pv> <cause> <s>s`, then `REFUSECAUSE <P> members <n> wall <s>s`.
  refusecause.py --merge
      -> build/refusecause/*.tsv into the tracked campaign/refusecause.tsv, sorted (prog, vram); columns
         prog vram func key code cause detail, tab-separated, no header; prints cause counts per program.
  refusecause.py --count [--tsv PATH]
      -> the cause counts per program of campaign/refusecause.tsv (or PATH).
  --repair NAME (bank.repair_arg; repeatable; off = unchanged): the switch on in each member's gate
      (propagate.gate_member, e.g. declunify, 3.1 T3; rolefeed, 3.1 T4: past an extraction the stop's log is the one
      after the ROLEFEED line, R1 included); --prog writes build/refusecause.<names>/<P>.tsv, --merge
      writes campaign/refusecause.<names>.tsv (same columns; never campaign/refusecause.tsv, the 3.0 before), --count
      reads it. --skip-holdout (--prog): rows whose config/methods-sample.tsv split is `holdout` are not run.
      relocdef (3.1 T5): gated detail ends `[via relocdef S=T ...]`, refused `[relocdef S=T ...]` (the defines
      added). --rows-cause C (--prog, 3.1 T5): only rows whose campaign/refusecause.tsv cause is C.
      unitcut (3.1 T6): a member fed the exemplar's whole unit is fed the exemplar alone (propagate.gate_member,
         bank.uc_due); detail ends `[via unitcut]`, a refusal past the cut `[unitcut fed <body>]`.
  refusecause.py --self-test
      -> host, no container: one planted evidence record per cause through classify() (+ the precedence) and a merge
         sort/determinism check in .run/refusecause/selftest/ (removed); `REFUSECAUSE SELF-TEST OK`, else rc 1.

Causes (classify(), pure): R4 or a rodata stop -> rodata. R2: the compile log matches DECL_RE -> declaration, an
asm `already defined` symbol -> path, else body. R1 with compile errors in the probe wrapper's log (the shared path fed standalone): DECL_RE -> declaration, else
path (a stale or unusable shared path, C0130/C0215; e.g. a role file, a whole unit's duplicate symbol). R5 link failure,
by the first ld diagnostic: undefined/multiple definition -> declaration, overlap/section/region -> address, else body.
R5 member linked away from its retail vram (build/<prog>.map): the obj words (reloc fields masked) differ from retail ->
body, else address (placement). R5 per differing span word: a difference outside the word's reloc field (or a span size difference) -> body;
reloc kind differs or reloc vs absolute, or the retail and linked targets resolve (build/<prog>.map) to different
containing symbols -> reloc; same symbol, different value, or an absolute KSEG0 lui differs -> address; span identical
but hash red -> rodata when the first differing byte lies in a .rodata/.data/.sdata/.bss section, else address.
Precedence body > reloc > address > rodata. A rerun that no longer refuses -> stale (a preflight refusal: the row is
no longer include_asm). Not causes: `norow` (no refused registry row: a journal-only attempt with no stored body),
`error` (the rerun raised). Detail: the first differing word's offset and symbols, or the stop / first error line.
Firewall G12: names, addresses, offsets, keys and our paths only; never a retail word.
"""
import argparse
import bisect
import glob
import os
import re
import shutil
import struct
import sys
import time

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import bank  # noqa: E402
import probe  # noqa: E402
import propagate  # noqa: E402

LEDGER = "campaign/ledger.tsv"
SAMPLE = "config/methods-sample.tsv"  # 3.0 T12 sample: (prog col 2, vram col 3, split last col)
OUT = "campaign/refusecause.tsv"
PARTS = "build/refusecause"
CODES = ("plumbing:R2", "plumbing:R4", "plumbing:R5")
CAUSES = ("body", "reloc", "address", "rodata", "declaration", "path", "stale")  # precedence order of the first four
EXTRA = ("norow", "error")
DECL_RE = re.compile(r"conflicting types|previous definition|implicit declaration|undeclared"
                     r"|too (?:few|many) arguments|incompatible type|redefinition")
DIAG_RE = re.compile(r"^(?:\{standard input\}|\S+):\d+:(?:\d+:)? ")  # T3.c3: gas on a pipe names no file
LINK_DECL_RE = re.compile(r"undefined reference|multiple definition|undefined symbol")
LINK_ADDR_RE = re.compile(r"overlap|will not fit|region|section|placement")
KIND = {4: "R26", 5: "HI16", 6: "LO16", 7: "GPREL16"}
RET_RE = re.compile(r"%(hi|lo|gp_rel)\(\s*([A-Za-z_.$][\w.$]*)")
MAP_SYM_RE = re.compile(r"^\s+0x([0-9A-Fa-f]+)\s+(?:PROVIDE \()?([A-Za-z_]\w*)(?:\s*$|\s*=)")
MAP_SEC_RE = re.compile(r"^ (\.\S+)(?:\s+0x([0-9A-Fa-f]+)\s+0x([0-9A-Fa-f]+)\s+\S+)?\s*$")
MAP_CONT_RE = re.compile(r"^\s+0x([0-9A-Fa-f]+)\s+0x([0-9A-Fa-f]+)\s+\S+\s*$")
DATA_SECS = (".rodata", ".rdata", ".data", ".sdata", ".bss", ".sbss")


# ---- classify (pure) -----------------------------------------------------------------------------------------------

def word_cause(w):
    """(cause or None, detail) of one span word: w = {off, retail, linked, mask, ok, rk, os, rs, oa, ra} (ok/rk: .o /
    retail reloc kind or None; os/rs: containing symbol names; oa/ra: their addresses, None when unresolved)."""
    diff = (w["retail"] ^ w["linked"]) & 0xFFFFFFFF
    if not diff:
        return None, ""
    ok, rk = w.get("ok"), w.get("rk")
    det = (f"+0x{w['off']:X} retail {w.get('rs') or '-'} {KIND.get(rk, 'abs')} "
           f"obj {w.get('os') or '-'} {KIND.get(ok, 'abs')}")
    if ok is None and rk is None:
        r, l = w["retail"], w["linked"]
        kseg0 = (r >> 26 == 0x0F and l >> 26 == 0x0F and not diff & 0xFFFF0000
                 and 0x8000 <= (r & 0xFFFF) <= 0x80FF and 0x8000 <= (l & 0xFFFF) <= 0x80FF)
        return ("address" if kseg0 else "body"), det
    field = w.get("mask") if ok is not None else probe.MASKS.get(rk, 0)
    if diff & ~(field or 0) & 0xFFFFFFFF:
        return "body", det
    if ok != rk:
        return "reloc", det
    if w.get("oa") is not None and w.get("ra") is not None:
        return ("reloc" if w["oa"] != w["ra"] else "address"), det
    return ("reloc" if (w.get("os") or "") != (w.get("rs") or "") else "address"), det


def classify(ev):
    """(cause, detail) of one member's rerun evidence ev = {stop: None | (rung, why) (rung 0: preflight), log: R2
    compile-log text, r5: None | {stop: rung5 cause or None, linked: bin built, size: (obj words, retail words),
    words: [word records, span order], first: None | (first differing binary vram, its map section or None)}}."""
    stop = ev.get("stop")
    if stop is not None:
        rung, why = stop
        if rung == 0:
            return "stale", f"preflight: {why}"
        if rung == 4 or why.startswith("rodata") or "; rodata " in why:
            return "rodata", f"R{rung}: {why}"
        if rung in (1, 2) and ev.get("log"):  # R2 unit compile log; R1 the probe wrapper's compile log
            # gcc 2.95 errors carry no `error:` tag: a `<path>:<line>:` diagnostic that is no warning or note
            errs = [ln for ln in ev["log"].splitlines() if DIAG_RE.match(ln) and "warning:" not in ln
                    and "note:" not in ln]
            hit = next((ln for ln in errs if DECL_RE.search(ln)), None)
            if hit:
                return "declaration", f"R{rung}: " + err_text(hit)
            if rung == 1 and errs:  # the shared path fed standalone does not compile (C0130/C0215): no body verdict
                return "path", "R1: " + err_text(errs[0])
            dup = next((ln for ln in errs if "already defined" in ln), None)
            if dup:  # R2 asm duplicate symbol: the whole unit fed twice (as c2's R1 rule), no declaration to fix
                return "path", f"R{rung}: " + err_text(dup)
            return "body", f"R{rung}: " + (err_text(errs[0]) if errs else why)
        if rung == 3:
            return "declaration", f"R3: {why}"
        return "body", f"R{rung}: {why}"
    r5 = ev.get("r5") or {}
    if not r5.get("linked", True):  # by the ld error text: a symbol -> declaration; a placement -> address
        why = r5.get("stop") or "no binary"
        c = ("declaration" if LINK_DECL_RE.search(why) else "address" if LINK_ADDR_RE.search(why) else "body")
        return c, f"R5 link: {why}"
    on, rn = r5.get("size") or (0, 0)
    if on != rn:
        return "body", f"R5 size obj {on} retail {rn} words"
    if r5.get("placed"):  # linked away from its retail vram: the span diff reads another function; the obj decides
        at, vram, odiff = r5["placed"]
        if odiff is not None:
            return "body", f"R5 obj +0x{odiff:X} differs from retail (placed 0x{at:08X} not 0x{vram:08X})"
        return "address", f"R5 placed 0x{at:08X} not 0x{vram:08X}, obj matches retail"
    best, det = None, ""
    for w in r5.get("words") or []:
        c, d = word_cause(w)
        if c is not None and (best is None or CAUSES.index(c) < CAUSES.index(best)):
            best, det = c, d
    if best is not None:
        return best, "R5 " + det
    why = r5.get("stop")
    if why is None:
        return "stale", "rerun gated, R5 green"
    if "hash red" not in why:
        return ("declaration" if "typecheck" in why else "body"), f"R5: {why}"
    first = r5.get("first")
    if first is None:
        return "address", "R5 span identical, no differing byte found"
    v, sec = first
    return ("rodata" if sec and sec.startswith(DATA_SECS) else "address"), f"R5 span identical; first diff 0x{v:08X} in {sec or '-'}"


def err_text(line):
    """A compiler diagnostic without its path prefix, one line, <= 160 chars."""
    line = re.sub(r"^(?:\{standard input\}|\S*?):\d+(?::\d+)?:\s*", "", line.strip())
    return clean(line)


def clean(s):
    return re.sub(r"[\t\r\n]+", " ", s)[:160]


# ---- evidence (container) ------------------------------------------------------------------------------------------

def obj_relocs(path, func):
    """{word index: (kind, symbol name)} of func's relocations in an ELF32 LE relocatable object (probe.elf_function's
    walk; a section symbol is named by its section)."""
    with open(path, "rb") as f:
        elf = f.read()
    shoff, = struct.unpack_from("<I", elf, 0x20)
    shentsize, shnum, shstrndx = struct.unpack_from("<HHH", elf, 0x2E)
    secs = [struct.unpack_from("<10I", elf, shoff + i * shentsize) for i in range(shnum)]

    def cstr(off):
        return elf[off:elf.index(b"\0", off)].decode(errors="replace")

    symtab = next(i for i, s in enumerate(secs) if s[1] == 2)
    st, stroff = secs[symtab], secs[secs[symtab][6]][4]
    syms = [struct.unpack_from("<IIIBBH", elf, st[4] + 16 * k) for k in range(st[5] // 16)]
    hit = next(s for s in syms if cstr(stroff + s[0]) == func and 0 < s[5] < 0xFF00)
    value, shndx = hit[1], hit[5]
    size = hit[2] or 1 << 30
    out = {}
    for s in secs:
        if s[1] == 9 and s[7] == shndx and s[6] == symtab:
            for k in range(s[5] // 8):
                r_off, r_info = struct.unpack_from("<II", elf, s[4] + 8 * k)
                if value <= r_off < value + size and (r_info & 0xFF) in KIND:
                    sym = syms[r_info >> 8]
                    name = (cstr(secs[shstrndx][4] + secs[sym[5]][0]) if sym[3] & 0xF == 3 and sym[5] < len(secs)
                            else cstr(stroff + sym[0]))
                    out.setdefault((r_off - value) // 4, (r_info & 0xFF, name))
    return out


def retail_kinds(prog, func, vram):
    """{word index: (kind, symbol name)} of the relocated operands of func's retail .s (spimdisasm %hi/%lo/%gp_rel,
    jal/j to a named symbol)."""
    hits = sorted(glob.glob(f"asm/{prog}/**/{func}.s", recursive=True))
    out = {}
    if not hits:
        return out
    with open(hits[0], errors="replace") as f:
        for line in f:
            m = probe.INSN_RE.search(line)
            if not m:
                continue
            i, op, rest = (int(m.group(1), 16) - vram) // 4, m.group(2), m.group(3)
            r = RET_RE.search(rest)
            if r:
                out[i] = ({"hi": 5, "lo": 6, "gp_rel": 7}[r.group(1)], r.group(2))
            elif op in ("jal", "j") and re.match(r"\s*[A-Za-z_]\w*\s*$", rest):
                out[i] = (4, rest.strip())
    return out


def read_map(prog):
    """(sorted [(addr, name)], [(name, lo, hi)] input sections) of build/<prog>.map."""
    syms, secs, pend = {}, [], None
    with open(f"build/{prog}.map", errors="replace") as f:
        for line in f:
            m = MAP_SEC_RE.match(line)
            if m:
                if m.group(2):
                    lo, n = int(m.group(2), 16), int(m.group(3), 16)
                    if n:
                        secs.append((m.group(1), lo, lo + n))
                    pend = None
                else:
                    pend = m.group(1)
                continue
            m = MAP_CONT_RE.match(line) if pend else None
            if m:
                lo, n = int(m.group(1), 16), int(m.group(2), 16)
                if n:
                    secs.append((pend, lo, lo + n))
                pend = None
                continue
            pend = None
            m = MAP_SYM_RE.match(line)
            if m:
                a, name = int(m.group(1), 16), m.group(2)
                if a not in syms or name < syms[a]:
                    syms[a] = name
    return sorted(syms.items()), secs


def map_addrs(prog, name):
    """Every address build/<prog>.map gives the symbol name (read_map keeps one name per address)."""
    with open(f"build/{prog}.map", errors="replace") as f:
        return sorted({int(m.group(1), 16) for m in map(MAP_SYM_RE.match, f) if m and m.group(2) == name})


def containing(symlist, addr):
    """(name, address) of the map symbol at or below addr, or (None, None)."""
    if addr is None:
        return None, None
    i = bisect.bisect_right(symlist, (addr, "￿")) - 1
    return (symlist[i][1], symlist[i][0]) if i >= 0 else (None, None)


def target(words, i, kind, pair, vram):
    """The address word i references (R26: its jump target; HI16/LO16: the pair's sum), or None."""
    if i >= len(words):
        return None
    w = words[i]
    if kind == 4:
        return ((vram + 4 * i + 4) & 0xF0000000) | ((w & 0x03FFFFFF) << 2)
    if kind in (5, 6) and pair is not None and pair < len(words):
        hi, lo = (w, words[pair]) if kind == 5 else (words[pair], w)
        lo = lo & 0xFFFF
        return (((hi & 0xFFFF) << 16) + (lo - 0x10000 if lo & 0x8000 else lo)) & 0xFFFFFFFF
    return None


def partner(rel, i):
    """The HI16/LO16 partner index of word i in rel {index: (kind, name)} (same symbol; LO16 after, HI16 before)."""
    kind, name = rel[i]
    if kind == 5:
        return next((j for j in sorted(rel) if j > i and rel[j] == (6, name)), None)
    if kind == 6:
        return next((j for j in sorted(rel, reverse=True) if j < i and rel[j] == (5, name)), None)
    return None


def r5_evidence(prog, row, stop5, log, at):
    """The r5 evidence dict of a gated member after bank.rung5 (in this tree); log/at: the rung5 log and its size before."""
    out, elf = bank.bin_out(prog), f"build/{prog}.elf"
    if not os.path.isfile(out) and os.path.isfile(elf):  # a red sha1sum -c deletes the binary (.DELETE_ON_ERROR)
        os.makedirs(os.path.dirname(out) or ".", exist_ok=True)
        bank.sh(["mipsel-linux-gnu-objcopy", "-O", "binary", elf, out], log)  # Makefile OBJCOPY, the bin rules
    if not os.path.isfile(out):
        tail = propagate.log_tail(log, at).splitlines()
        err = next((ln for ln in tail if LINK_DECL_RE.search(ln) or ("ld:" in ln and LINK_ADDR_RE.search(ln))),
                   None)  # the first ld diagnostic; make's `Error 1` line only when there is none
        err = err or next((ln for ln in reversed(tail) if "error" in ln.lower()), stop5 or "no binary")
        return dict(stop=clean(re.sub(r"^.*?\(\.\w+\+0x[0-9A-Fa-f]+\):\s*", "", err.strip())), linked=False)
    func, vram = row["name"], int(row["vram"], 16)
    obj = f"build/src/{prog}/{row['tu']}.c.o"
    ow, masks = probe.elf_function(obj, func)
    rw = probe.retail_words(prog, func)
    target_path, seg_start, seg_vram = probe.yaml_layout(prog)
    with open(out, "rb") as f:
        f.seek(seg_start + vram - seg_vram)
        b = f.read(4 * len(rw))
    lw = list(struct.unpack(f"<{len(b) // 4}I", b[:len(b) // 4 * 4]))
    symlist, secs = read_map(prog)
    rel, ret = obj_relocs(obj, func), retail_kinds(prog, func, vram)
    placed = None
    ats = map_addrs(prog, func)
    if ats and vram not in ats:  # a shifted link (earlier code grew): compare the obj (reloc fields masked) with retail instead
        odiff = next((4 * i for i, (o, r) in enumerate(zip(ow, rw)) if (o ^ r) & ~masks.get(i, 0) & 0xFFFFFFFF),
                     None)
        placed = (min(ats, key=lambda a: abs(a - vram)), vram, odiff)
    words = []
    for i, (r, l) in enumerate(zip(rw, lw)):
        if r == l:
            continue
        ok, os_name = rel.get(i, (None, None))
        rk, rs_name = ret.get(i, (None, None))
        la = target(lw, i, ok, partner(rel, i) if ok in (5, 6) else None, vram) if ok else None
        ra = (target(rw, i, rk, partner(ret, i) if rk in (5, 6) else None, vram) if rk else None)
        os_c, oa = containing(symlist, la) if la is not None else (os_name, None)
        rs_c, ra_c = containing(symlist, ra) if ra is not None else (rs_name, None)
        words.append(dict(off=4 * i, retail=r, linked=l, mask=masks.get(i, 0), ok=ok, rk=rk, os=os_c, rs=rs_c,
                          oa=oa, ra=ra_c))
    first = None
    if stop5 and "hash red" in stop5:
        with open(target_path, "rb") as f:
            want = f.read()
        with open(out, "rb") as f:
            got = f.read()
        at = next((k for k in range(min(len(want), len(got))) if want[k] != got[k]),
                  None if len(want) == len(got) else min(len(want), len(got)))
        if at is not None:
            v = at - seg_start + seg_vram
            first = (v, next((n for n, lo, hi in secs if lo <= v < hi), None))
    return dict(stop=stop5, linked=True, size=(len(ow), len(rw)), words=words, first=first, placed=placed)


def member_rows(prog):
    with open(LEDGER) as f:
        rows = [ln.rstrip("\n").split("\t") for ln in f if ln.strip()]
    return [r for r in rows if r[0] == prog and r[6] in CODES]


def holdout():
    """{(prog, vram int)} of the methods sample's holdout rows (never run under --skip-holdout)."""
    with open(SAMPLE) as f:
        rows = [ln.rstrip("\n").split("\t") for ln in f if ln.strip() and not ln.startswith("#")]
    return {(r[1], int(r[2], 16)) for r in rows if r[-1] == "holdout"}


def suffix():
    """`.<switch>[.<switch>]` of the repair switches on, '' when all are off (the 3.0 paths)."""
    return "".join("." + r for r in sorted(bank.REPAIR))


def refused_row(reg, member, key):
    """The member's refused registry row of key (ledger dup key), else its first refused row, else None."""
    rows = [t for _, t in reg if t[3] == member and t[4] == "refused"]
    return next((t for t in rows if t[0] == key), rows[0] if rows else None)


def run_member(prog, lrow, reg, ctxs, log):
    """(key, cause, detail) of one ledger row, in this tree; the tree left as it was."""
    member = f"{prog}:{lrow[1]}"
    key = lrow[3][4:] if lrow[3].startswith("dup:") else None
    t = refused_row(reg, member, key)
    if t is None:
        return key or "-", "norow", "no refused registry row"
    key = t[0]
    if key not in ctxs:
        if not ctxs:
            ctxs[None] = (propagate.load_classes(), propagate.corpus_rows())
        ctxs[key] = propagate.key_plan(key, True, reg, *ctxs[None])[0]
    ctx = ctxs[key]
    if os.path.isfile(t[2]) and t[2] != ctx[3]:
        ctx = ctx[:3] + (t[2],) + ctx[4:]
    m = propagate.parse_pv(member)
    at = propagate.log_size(log)
    res, gated = propagate.gate_members(prog, [m], ctx, lambda s: None)
    if not gated:
        why = res[0][2]
        rd = re.search(r"; (relocdef .*)$", why) if "relocdef" in bank.REPAIR else None
        why = why[:rd.start()] if rd else why  # switch relocdef (3.1 T5): its note last, the stop parsed without it
        mo = re.match(r"R(\d): (.*)", why)
        stop = (int(mo.group(1)), propagate.short("refused " + why)[4:]) if mo else (0, why[len("preflight: "):])
        text = propagate.log_tail(log, at)
        mo = re.search(r"; declunify stop R(\d): (.*)$", why) if bank.REPAIR else None
        if mo:  # switch on (3.1 T3): past the repaired stop, the member's next wall is its cause
            stop = (int(mo.group(1)), mo.group(2))
            k = text.rfind("\nDECLUNIFY ")  # T3.c2: that wall's log only, after the repair's last edit line
            text = text[k + 1:] if k >= 0 else text
        k = text.rfind("\nROLEFEED ") if bank.REPAIR and re.search(r"; (?:rolefeed|unitcut) fed ", why) else -1
        if k >= 0:  # switch rolefeed (3.1 T4), unitcut (T6): the ladder after the extraction; R1's log in the bank log
            text = text[k + 1:]
        elif stop[0] == 1:  # the probe wrapper's compile log (probe.compile_obj), when it failed to compile
            hits = sorted(glob.glob(f".run/probe/*/*_{prog}/{lrow[2]}.c.log"))
            text = "".join(open(h, errors="replace").read() for h in hits) if hits else text
        cause, detail = classify(dict(stop=stop, log=text))
        if stop[0] and f"R{stop[0]}" != lrow[6][len("plumbing:"):]:
            detail += f" (recorded {lrow[6][len('plumbing:'):]})"
        mo = re.search(r"(?:^R2: |; )((?:declunify|rolefeed|unitcut) .*)$", why) if bank.REPAIR else None
        if mo:  # switch on (3.1 T3, T4, T6): the repair step's own note
            detail += f" [{propagate.short('refused ' + mo.group(1))}]"
        return key, cause, detail + (f" [{rd.group(1)}]" if rd else "")
    try:
        g, pos = gated[0], [propagate.log_size(log)]
        try:
            propagate.rung5_unify(prog, gated, log, pos)  # bank.rung5; switch on: + the declunify link step (T3.c2)
            stop5 = None
        except bank.Stop as e:
            stop5 = e.cause
        ev = r5_evidence(prog, g["row"], stop5, log, pos[0])
    finally:
        propagate.restore_prog(prog, gated, log)
    cause, detail = classify(dict(stop=None, r5=ev))
    return key, cause, detail + (f" [via {g['via']}]" if bank.REPAIR and g["via"] else "") + (
        " [via relocdef " + " ".join(f"{o}={n}" for o, n in g["reloc"]) + "]" if g.get("reloc") else "")


def run_prog(prog, skip_holdout=False, rows_cause=None):
    t0 = time.time()
    root = os.getcwd()
    rows = member_rows(prog)
    if rows_cause:  # 3.1 T5: only rows whose OUT cause (col 6) is rows_cause
        want = {(r[0], int(r[1], 16)) for r in read_tsv(OUT) if r[5] == rows_cause}
        rows = [r for r in rows if (r[0], int(r[1], 16)) in want]
    if skip_holdout:
        held = holdout()
        rows = [r for r in rows if (r[0], int(r[1], 16)) not in held]
    tree = os.path.join(propagate.TREE, f"rc_{prog}")
    shutil.rmtree(tree, ignore_errors=True)
    propagate.make_tree(tree)
    out, ctxs, log = [], {}, f"propagate-{prog}"
    try:
        os.chdir(tree)
        reg = propagate.registry_rows()
        for r in rows:
            t1 = time.time()
            try:
                key, cause, detail = run_member(prog, r, reg, ctxs, log)
            except (Exception, SystemExit) as e:  # one member's crash is that member's row, never the run's
                key, cause, detail = (r[3][4:] if r[3].startswith("dup:") else "-"), "error", clean(f"{type(e).__name__}: {e}")
            out.append((prog, r[1], r[2], key, r[6][len("plumbing:"):], cause, clean(detail)))
            print(f"{prog}:{r[1]} {cause} {time.time() - t1:.0f}s {clean(detail)}", flush=True)
    finally:
        os.chdir(root)
        shutil.rmtree(tree, ignore_errors=True)
    os.makedirs(PARTS + suffix(), exist_ok=True)
    write_tsv(os.path.join(PARTS + suffix(), f"{prog}.tsv"), out)
    print(counts_lines(out)[0] if out else f"REFUSECAUSE {prog} none")
    print(f"REFUSECAUSE {prog} members {len(out)} wall {time.time() - t0:.0f}s")
    return 0


# ---- merge / count -------------------------------------------------------------------------------------------------

def sort_key(r):
    return r[0], int(r[1], 16), r[3]


def write_tsv(path, rows):
    with open(path, "w") as f:
        f.write("".join("\t".join(r) + "\n" for r in sorted(rows, key=sort_key)))


def read_tsv(path):
    with open(path) as f:
        return [ln.rstrip("\n").split("\t") for ln in f if ln.strip()]


def counts_lines(rows):
    by = {}
    for r in rows:
        by.setdefault(r[0], {}).setdefault(r[5], 0)
        by[r[0]][r[5]] += 1
    return [f"REFUSECAUSE {p} " + " ".join(f"{c} {by[p][c]}" for c in CAUSES + EXTRA if c in by[p])
            for p in sorted(by)]


def merge(parts=PARTS, out=OUT):
    rows = [r for p in sorted(glob.glob(os.path.join(parts, "*.tsv"))) for r in read_tsv(p)]
    write_tsv(out, rows)
    return rows


# ---- self-test -----------------------------------------------------------------------------------------------------

def self_test():
    ok = True

    def w(**k):
        base = dict(off=8, retail=0, linked=0, mask=0, ok=None, rk=None, os=None, rs=None, oa=None, ra=None)
        return dict(base, **k)

    lui = 0x3C020000
    plants = {
        "rodata": dict(stop=(4, "rodata needs placement (+8 bytes)")),
        "declaration": dict(stop=(2, "build/src/p/x.c.o does not compile"),
                            log="src/p/x.c:12: error: conflicting types for 'func_80010000'\n"),
        "body": dict(stop=(2, "build/src/p/x.c.o does not compile"), log="src/p/x.c:3: error: parse error before '}'\n"),
        "reloc": dict(stop=None, r5=dict(stop="hash red", size=(4, 4), words=[
            w(retail=lui | 0x8010, linked=lui | 0x8011, mask=0xFFFF, ok=5, rk=5, os="D_80110000", rs="D_80100000",
              oa=0x80110000, ra=0x80100000)])),
        "address": dict(stop=None, r5=dict(stop="hash red", size=(4, 4), words=[
            w(retail=0x24420010, linked=0x24420014, mask=0xFFFF, ok=6, rk=6, os="D_80100000", rs="D_80100000",
              oa=0x80100000, ra=0x80100000)])),
        "path": dict(stop=(1, "standalone probe FAIL 0/9 words"),
                     log="a.s:40: Error: symbol `func_80010000' is already defined\n"),
        "stale": dict(stop=None, r5=dict(stop=None, size=(4, 4), words=[])),
    }
    extra = [
        ("rodata", dict(stop=None, r5=dict(stop="hash red", size=(4, 4), words=[], first=(0x80100020, ".rodata")))),
        ("address", dict(stop=None, r5=dict(stop="hash red", size=(4, 4), words=[], first=(0x80100020, ".text")))),
        ("body", dict(stop=None, r5=dict(stop="hash red", size=(5, 4), words=[]))),
        ("reloc", dict(stop=None, r5=dict(stop="hash red", size=(4, 4), words=[  # reloc vs absolute
            w(retail=lui | 0x8010, linked=lui | 0x1234, rk=5, rs="D_80100000")]))),
        ("body", dict(stop=None, r5=dict(stop="hash red", size=(4, 4), words=[  # precedence body > reloc > address
            w(off=4, retail=0x24420010, linked=0x24420014, mask=0xFFFF, ok=6, rk=6, os="D_1", rs="D_1", oa=1, ra=1),
            w(off=8, retail=lui | 0x8010, linked=lui | 0x8011, mask=0xFFFF, ok=5, rk=5, os="D_2", rs="D_3", oa=2,
              ra=3),
            w(off=12, retail=0x00851021, linked=0x00851023)]))),
        ("stale", dict(stop=(0, "state c, not include_asm"))),
        ("declaration", dict(stop=(2, "build/src/p/x.c.o does not compile"),
                             log="src/p/x.c:9: redefinition of `func_80010000'\n")),
        ("body", dict(stop=(1, "standalone probe FAIL 3/9 words"))),  # compiled, words differ: no compile log
        ("path", dict(stop=(1, "standalone probe FAIL 0/9 words"),  # a warning's note is no declaration error
                      log="a.c:10: warning: \"F\" redefined\na.c:4: note: this is the location of the previous "
                          "definition\nb.c:2: parse error before string constant\n")),
        ("path", dict(stop=(2, "build/src/p/x.c.o does not compile"),  # R2 asm duplicate local label
                      log="/tmp/cc1.s:88: Error: symbol `.L80010008' is already defined\n")),
        ("path", dict(stop=(2, "build/src/p/x.c.o does not compile"),  # T3.c3: gas fed by a pipe (declunify stop)
                      log="src/p/x.c:5: warning: \"F\" redefined\n{standard input}: Assembler messages:\n"
                          "{standard input}:18121: Error: symbol `func_80010000' is already defined\n"
                          "make: *** [Makefile:155: build/src/p/x.c.o] Error 1\n")),
        ("address", dict(stop=None, r5=dict(stop="hash red", size=(4, 4), placed=(0x80100BCC, 0x80100000, None),
                                            words=[w(off=0, retail=0x27BDFFE0, linked=0x03E00008)]))),  # shifted
        ("body", dict(stop=None, r5=dict(stop="hash red", size=(4, 4), placed=(0x80100BCC, 0x80100000, 8),
                                         words=[]))),  # shifted, and the obj itself differs
        ("declaration", dict(stop=None, r5=dict(linked=False, stop="undefined reference to `func_80010000'"))),
        ("address", dict(stop=None, r5=dict(linked=False, stop="section .text LMA [80010000,80010fff] overlaps "
                                                              "section .data"))),
        ("body", dict(stop=None, r5=dict(linked=False, stop="make: *** [Makefile:1: build/p.elf] Error 1"))),
    ]
    for want, ev in list(plants.items()) + extra:
        got, det = classify(ev)
        if got != want or "\t" in det or "\n" in det:
            print(f"refusecause self-test: planted {want} -> {got} ({det})")
            ok = False
    if set(plants) != set(CAUSES):
        print("refusecause self-test: a cause has no plant")
        ok = False
    d = ".run/refusecause/selftest"
    shutil.rmtree(d, ignore_errors=True)
    os.makedirs(d + "/parts")
    try:
        a = [("rock_07", "0x800F5934", "f3", "k1", "R5", "body", "x"), ("rock_07", "0x800EBAD8", "f1", "k1", "R5",
             "reloc", "y")]
        b = [("SLUS_013.95", "0x80100000", "f4", "-", "R2", "norow", "z"), ("rock_07", "0x800EDDD8", "f2", "k2", "R2",
             "declaration", "w")]
        with open(d + "/parts/rock_07.tsv", "w") as f:
            f.write("".join("\t".join(r) + "\n" for r in a + b[1:]))
        with open(d + "/parts/SLUS_013.95.tsv", "w") as f:
            f.write("\t".join(b[0]) + "\n")
        merge(d + "/parts", d + "/one.tsv")
        merge(d + "/parts", d + "/two.tsv")
        one, two = open(d + "/one.tsv", "rb").read(), open(d + "/two.tsv", "rb").read()
        order = [tuple(r[:2]) for r in read_tsv(d + "/one.tsv")]
        want = [("SLUS_013.95", "0x80100000"), ("rock_07", "0x800EBAD8"), ("rock_07", "0x800EDDD8"),
                ("rock_07", "0x800F5934")]
        if one != two or order != want:
            print(f"refusecause self-test: merge order {order} or not deterministic")
            ok = False
    finally:
        shutil.rmtree(".run/refusecause", ignore_errors=True)
    print("REFUSECAUSE SELF-TEST OK" if ok else "REFUSECAUSE SELF-TEST FAIL")
    return 0 if ok else 1


def main():
    os.chdir(os.path.abspath(os.path.join(HERE, "..", "..")))
    ap = argparse.ArgumentParser(description=__doc__.split("\n", 1)[0])
    g = ap.add_mutually_exclusive_group(required=True)
    g.add_argument("--prog", metavar="P")
    g.add_argument("--merge", action="store_true")
    g.add_argument("--count", action="store_true")
    g.add_argument("--self-test", action="store_true")
    bank.repair_arg(ap)
    ap.add_argument("--skip-holdout", action="store_true", help=f"--prog: skip {SAMPLE} holdout rows")
    ap.add_argument("--tsv", metavar="PATH", help="--count: read PATH")
    ap.add_argument("--rows-cause", metavar="C", help=f"--prog: only rows whose {OUT} cause is C")
    a = ap.parse_args()
    bank.repair_set(a)
    if a.self_test:
        return self_test()
    if a.prog:
        return run_prog(a.prog, a.skip_holdout, a.rows_cause)
    out = OUT.replace(".tsv", suffix() + ".tsv")
    rows = merge(PARTS + suffix(), out) if a.merge else read_tsv(a.tsv or out)
    print("\n".join(counts_lines(rows)))
    print(f"REFUSECAUSE rows {len(rows)}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
