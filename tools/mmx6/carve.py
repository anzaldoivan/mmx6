#!/usr/bin/env python3
"""carve.py -- deliberate segment edges per binary: jump-table rodata carves and opt-level unit splits (stdlib only).

    carve.py jtbl <prog> <table_lo>                         table = config/boundaries.txt `jtbl` row lo
    carve.py rodata <prog> <func_vram> [--bytes N]          tables = retail words of the rodata block inside func
    carve.py opt <prog> <tu> <split vram> [--cflags "<f>"]  split <tu> at a corpus function start
    carve.py --check                                        every record still valid (fail-closed)
    carve.py --self-test                                    planted refusals on a scratch copy under .run/

Record config/carve.<prog>.txt (tracked, written only here): `jtbl <table_lo> <tu>` | `rodata <lo> <hi> <tu>` |
`block <hi>` | `opt <tu> <vram> <newtu> [cflags...]`, newtu = vram hex without 0x80. tools/mmx6/segment.py applies it to
the generated yaml block: an opt row is a text edge (TU <newtu>, kind of its parent); a jtbl row cuts the rodata block
at [lo, hi) into `.rodata <tu>`, which splat pairs with unit <tu> (the table migrates into its dispatcher's INCLUDE_ASM
.s). rodata: the table ranges are the maximal runs (>= 2 words) of retail words in the rodata block whose values all
lie in [func, func end) (corpus); --bytes N asserts their byte sum T (T + pad P = N, 0 <= P < the unit object's
.rodata alignment; T44.c1); one `rodata` row per run. Several tables of one unit: the unit's rows are merged into one
contiguous range in TU function order, one row per table (its trailing zero pad < alignment included); any other byte
in that range refuses `foreign-rodata` (T44.c1). Rodata block: exe
[0x80010000, 0x800120A0); overlay [base, first text function) when its first TU is a c unit whose .c holds
`INCLUDE_ASM(..., D_<base>)`: the first carve of an overlay drops that line and records `block <hi>` (hi = the first
text function), from which segment.py cuts [base, hi) and starts the unit at hi. On a c parent, opt moves the
tail of src/<prog>/<tu>.c (from the split function's chunk) to src/<prog>/<newtu>.c and adds `<prog> <newtu>` to
config/c_units.txt. config/carve.<prog>.mk (generated from the record, included by the Makefile) sets the per-unit
cc1 flags `CFLAGS_<newtu>`. Inputs: build/corpus/functions.jsonl (corpus.py --all) for function starts and TUs.
Retail words: extracted/retail/iso/SLUS_013.95 | extracted/retail/rock/NN.bin.
Prints `CARVE jtbl OK <prog> 0x<lo>` / `CARVE rodata OK <prog> 0x<func> 0x<lo>-0x<hi> <bytes>` (per range) /
`CARVE opt OK <prog> <tu>@0x<vram>`; --check prints those per verified row (rodata: `CARVE rodata OK <prog> 0x<lo>-0x<hi>`) and
ends `CARVE CHECK OK <n> carves`; --self-test ends `CARVE CONTROL OK`. A refusal prints `CARVE REFUSE <code> ...`, rc 1.
"""
import json
import os
import re
import shutil
import struct
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import segment  # noqa: E402

CORPUS = os.path.join(ROOT, "build", "corpus", "functions.jsonl")
SCRATCH = os.path.join(ROOT, ".run", "carve-selftest")
INC_RE = re.compile(r"^INCLUDE_ASM\(\"[^\"]*\", *(\w+)\);")
CDEF_RE = re.compile(r"(?!INCLUDE_ASM\b)[A-Za-z_][^;{}()#]*?\b([A-Za-z_]\w*)\s*\([^;{}]*?\)\s*\{(\s*\})?")
CINC_RE = re.compile(r"^#include \"([^\"]+\.c)\"[ \t]*$")


class Refuse(Exception):
    pass


def refuse(code, msg):
    raise Refuse("CARVE REFUSE %s %s" % (code, msg))


def use_root(root):
    """Point segment.py's inputs at root (the repo, or the self-test scratch copy)."""
    segment.ROOT = root
    segment.BOUNDARIES = os.path.join(root, "config", "boundaries.txt")
    segment.C_UNITS = os.path.join(root, "config", "c_units.txt")


def cfg(root, *p):
    return os.path.join(root, "config", *p)


# ---- inputs --------------------------------------------------------------------------------------------------------

def jtbl_rows(prog):
    """{lo: (hi, func, src, note)} of prog's boundaries.txt jtbl rows (func None for `-`). Rows with hi `unknown`
    (label-inside-scan-table) are labels inside another table, not tables (config/segmentation.md): skipped."""
    out, cur = {}, None
    with open(segment.BOUNDARIES) as f:
        for line in f:
            w = line.split()
            if line.startswith("# program "):
                cur = w[2]
            elif cur == prog and len(w) >= 5 and w[0] == "jtbl" and w[2] != "unknown":
                out[int(w[1], 16)] = (int(w[2], 16), None if w[3] == "-" else int(w[3], 16), w[4], " ".join(w[5:]))
    return out


def corpus(prog):
    """{vram: (name, tu, end)} of prog's corpus functions."""
    if not os.path.exists(CORPUS):
        refuse("no-corpus", "%s missing (run corpus.py --all after the build)" % CORPUS)
    out = {}
    with open(CORPUS) as f:
        for line in f:
            r = json.loads(line)
            if r["prog"] == prog:
                out[int(r["vram"], 16)] = (r["name"], r["tu"], int(r["end"], 16))
    return out


def retail_words(prog, lo, hi):
    """[(vram, word)] of the retail image of prog over [lo, hi), little-endian, lo 4-aligned."""
    base = segment.read_programs(segment.BOUNDARIES)[prog][0]
    if prog == segment.EXE["name"]:
        path, off = os.path.join(ROOT, "extracted", "retail", "iso", prog), lo - base + segment.EXE["header"]
    else:
        path, off = os.path.join(ROOT, "extracted", "retail", "rock", "%02d.bin" % int(prog[5:])), lo - base
    with open(path, "rb") as f:
        f.seek(off)
        b = f.read(hi - lo)
    return [(lo + i, int.from_bytes(b[i:i + 4], "little")) for i in range(0, len(b) - 3, 4)]


def d_line(prog, base):
    """The overlay's leading data-chunk INCLUDE_ASM name."""
    return "D_%08X" % base


def rodata_block(root, prog, rec):
    """(lo, hi, unit) of prog's rodata block; unit = the overlay c unit whose D_<base> line a first carve drops
    (None for the exe or an overlay whose record already has its `block` row)."""
    if prog == segment.EXE["name"]:
        return segment.EXE["rodata_lo"], segment.EXE["text_lo"], None
    base = segment.read_programs(segment.BOUNDARIES)[prog][0]
    his = [int(r[1], 16) for r in rec if r[0] == "block"]
    if his:
        return base, his[0], None
    tus = text_tus(prog)
    unit = tus[0][1] if tus and tus[0][0] == base else None
    path = os.path.join(root, "src", prog, "%s.c" % unit)
    has = False
    if unit in segment.c_units(prog) and os.path.exists(path):
        with open(path) as f:
            has = any((m.group(1) if m else None) == d_line(prog, base) for m in map(INC_RE.match, f))
    first = min([v for v in corpus(prog) if v > base], default=None)
    if not has or first is None:
        refuse("no-rodata-block", "%s first TU %s is not a c unit with INCLUDE_ASM(..., %s)" % (prog, unit, d_line(prog, base)))
    return base, first, unit


def place(root, prog, rec, unit, hi, rows):
    """Append rows to the record; an overlay's first carve also drops its D_<base> line and records `block <hi>`."""
    if unit is not None:
        base = segment.read_programs(segment.BOUNDARIES)[prog][0]
        path = os.path.join(root, "src", prog, "%s.c" % unit)
        with open(path) as f:
            lines = f.read().split("\n")
        i = [k for k, l in enumerate(lines) if (lambda m: m and m.group(1) == d_line(prog, base))(INC_RE.match(l))][0]
        del lines[i:i + (2 if i + 1 < len(lines) and not lines[i + 1].strip() else 1)]
        with open(path, "w") as f:
            f.write("\n".join(lines))
        sym = cfg(root, "symbols.%s.txt" % prog)  # a sized D_<base> hides the block's jtbls from spimdisasm (no migration)
        if os.path.exists(sym):
            with open(sym) as f:
                s = f.read()
            with open(sym, "w") as f:
                f.write(re.sub(r"(?m)^(%s = 0x%08X;)[ \t]*//.*$" % (d_line(prog, base), base), r"\1", s))
        rec = rec + [["block", "0x%08X" % hi]]
    regenerate(root, prog, rec + rows)


def placement_refusals(prog, ranges, tu, carved, blo, bhi):
    """The jtbl refusals for new ranges [(lo, hi)] of TU tu against the carved ranges and the block pieces."""
    for lo, hi in ranges:
        for clo, chi, ctu in carved:
            if lo < chi and clo < hi:
                refuse("overlaps-carve", "%s [0x%08X,0x%08X) overlaps carved [0x%08X,0x%08X) %s" % (prog, lo, hi, clo, chi, ctu))
    pieces = segment.rodata_pieces(blo, bhi, carved)
    ends = [p[0] for p in pieces[1:]] + [bhi]
    for lo, hi in ranges:
        if not any(p[0] <= lo and hi <= e for p, e in zip(pieces, ends)):
            refuse("straddles", "%s [0x%08X,0x%08X) is not inside one rodata subsegment" % (prog, lo, hi))
    if tu not in segment.c_units(prog):
        refuse("not-c", "%s TU %s is asm (rodata pairs only with a c unit)" % (prog, tu))
    merged = []
    for a, b in sorted([(a, b) for a, b, t in carved if t == tu] + list(ranges)):
        if merged and merged[-1][1] == a:
            merged[-1] = (merged[-1][0], b)
        else:
            merged.append((a, b))
    if len(merged) > 1:
        refuse("non-contiguous", "%s TU %s rodata would not be contiguous (%s)" % (
            prog, tu, " ".join("0x%08X-0x%08X" % m for m in merged)))


def read_record(root, prog):
    """[[kind, ...fields]] rows of config/carve.<prog>.txt, comments dropped."""
    path = cfg(root, "carve.%s.txt" % prog)
    if not os.path.exists(path):
        return []
    with open(path) as f:
        return [w for w in (l.split("#", 1)[0].split() for l in f) if w]


def write_record(root, prog, rows):
    with open(cfg(root, "carve.%s.txt" % prog), "w") as f:
        f.write("# config/carve.%s.txt -- carves of %s, written only by tools/mmx6/carve.py (config/segmentation.md).\n"
                "# jtbl <table_lo> <tu> | rodata <lo> <hi> <tu> | block <hi> | opt <tu> <vram> <newtu> [cflags...]\n"
                % (prog, prog))
        f.writelines(" ".join(r) + "\n" for r in rows)


def render_mk(prog, rows):
    out = ["# config/carve.%s.mk -- generated by tools/mmx6/carve.py from config/carve.%s.txt; included by the "
           "Makefile.\n" % (prog, prog)]
    out += ["build/src/%s/%s.c.o: CFLAGS_%s := %s\n" % (prog, r[3], r[3], " ".join(r[4:]))
            for r in rows if r[0] == "opt" and len(r) > 4]
    return "".join(out)


def text_tus(prog):
    """[(vram, name)] text TUs of prog's generated block (carves applied)."""
    progs = segment.read_programs(segment.BOUNDARIES)
    out = []
    for l in segment.block(prog, progs)[1:-1]:
        w = l.strip()[3:-1].split(", ")
        if len(w) == 3 and w[1] in ("asm", "c"):
            out.append((int(w[0], 16), w[2]))
    base = progs[prog][0]
    off = (lambda o: o - segment.EXE["header"] + base) if prog == segment.EXE["name"] else (lambda o: o + base)
    return [(off(o), n) for o, n in out]


def regenerate(root, prog, rows):
    """Record, .mk and yaml block of prog from rows."""
    write_record(root, prog, rows)
    with open(cfg(root, "carve.%s.mk" % prog), "w") as f:
        f.write(render_mk(prog, rows))
    out = segment.block(prog, segment.read_programs(segment.BOUNDARIES))
    if segment.splice(cfg(root, prog + ".yaml"), out):
        refuse("yaml", "%s has no single BEGIN/END block" % cfg(root, prog + ".yaml"))


# ---- jtbl ----------------------------------------------------------------------------------------------------------

def carve_jtbl(root, prog, lo):
    rows = jtbl_rows(prog)
    if lo not in rows:
        refuse("not-a-row", "%s 0x%08X is not a jtbl row lo of config/boundaries.txt" % (prog, lo))
    hi, func, _, note = rows[lo]
    if func is None or "label-inside-scan-table" in note:
        refuse("no-dispatcher", "%s 0x%08X row has func `-` or note label-inside-scan-table" % (prog, lo))
    rec = read_record(root, prog)
    blo, bhi, unit = rodata_block(root, prog, rec)
    _, jt, ro, _ = segment.read_carves(prog)
    carved = segment.carved_rodata(prog, jt, ro)
    fn = corpus(prog).get(func)
    if fn is None:
        refuse("no-function", "%s dispatcher 0x%08X is not a corpus function start" % (prog, func))
    placement_refusals(prog, [(lo, hi)], fn[1], carved, blo, bhi)
    place(root, prog, rec, unit, bhi, [["jtbl", "0x%08X" % lo, fn[1]]])
    print("CARVE jtbl OK %s 0x%08X" % (prog, lo))


# ---- rodata --------------------------------------------------------------------------------------------------------

def table_runs(prog, blo, bhi, flo, fend):
    """[(lo, hi)] maximal runs (>= 2 words) of retail words in [blo, bhi) whose values all lie in [flo, fend)."""
    runs, cur = [], None
    for v, w in retail_words(prog, blo, bhi) + [(bhi, None)]:
        if w is not None and flo <= w < fend:
            cur = [cur[0], v + 4] if cur else [v, v + 4]
            continue
        if cur and cur[1] - cur[0] >= 8:
            runs.append(tuple(cur))
        cur = None
    return runs


def unit_align(prog, tu):
    """sh_addralign of the .rodata section of the built unit object build/src/<prog>/<tu>.c.o (1 when absent: no pad)."""
    path = os.path.join(ROOT, "build", "src", prog, "%s.c.o" % tu)
    if not os.path.exists(path):
        return 1
    with open(path, "rb") as f:
        b = f.read()
    shoff, = struct.unpack_from("<I", b, 0x20)
    shentsize, shnum, shstrndx = struct.unpack_from("<HHH", b, 0x2E)
    secs = [struct.unpack_from("<10I", b, shoff + i * shentsize) for i in range(shnum)]
    stro = secs[shstrndx][4]
    for s in secs:
        if b[stro + s[0]:b.index(b"\0", stro + s[0])] == b".rodata":
            return max(1, s[8])
    return 1


def unit_layout(prog, tu, lo, hi, align):
    """[(lo, hi_with_pad, owner)] of the tables of tu's functions tiling [lo, hi), each followed by its zero pad
    (< align bytes); refuse foreign-rodata on any other byte, a table of another TU, or tables out of TU order."""
    fns = corpus(prog)
    starts = {}
    for v, (_, t, e) in fns.items():
        for a, b in table_runs(prog, lo, hi, v, e):
            starts[a] = (b, v, t)
    words = dict(retail_words(prog, lo, hi))
    out, p = [], lo
    while p < hi:
        if p in starts:
            b, v, t = starts[p]
            if t != tu or (out and v < out[-1][2]):
                refuse("foreign-rodata", "%s [0x%08X,0x%08X) holds 0x%08X-0x%08X, a table of 0x%08X (TU %s)%s" % (
                    prog, lo, hi, p, b, v, t, "" if t != tu else " out of TU function order"))
            out.append([p, b, v])
            p = b
            continue
        q = p
        while q < hi and q not in starts and words.get(q) == 0:
            q += 4
        if not out or q == p or q - p >= align or q >= hi or q not in starts:
            refuse("foreign-rodata", "%s [0x%08X,0x%08X) holds 0x%08X-0x%08X, neither a table of TU %s nor pad < %d" % (
                prog, lo, hi, p, max(q, p + 4), tu, align))
        out[-1][1] = q
        p = q
    return [tuple(x) for x in out]


def carve_rodata(root, prog, func, nbytes):
    """Carve func's tables; several tables of one unit become one contiguous range in TU function order (the unit's
    existing `rodata` rows merged), one row per table with its trailing pad. --bytes N accepts tables T + pad P = N,
    0 <= P < the unit object's .rodata alignment."""
    fn = corpus(prog).get(func)
    if fn is None:
        refuse("no-function", "%s 0x%08X is not a corpus function start" % (prog, func))
    tu = fn[1]
    rec = read_record(root, prog)
    blo, bhi, unit = rodata_block(root, prog, rec)
    runs = table_runs(prog, blo, bhi, func, fn[2])
    if not runs:
        refuse("no-table", "%s no run of >= 2 words in [0x%08X,0x%08X) points into 0x%08X" % (prog, blo, bhi, func))
    total = sum(b - a for a, b in runs)
    align = unit_align(prog, tu)
    if nbytes is not None and not 0 <= nbytes - total < align:
        refuse("size-mismatch", "%s 0x%08X tables are %d bytes, not %d (pad < %d; %s)" % (
            prog, func, total, nbytes, align, " ".join("0x%08X-0x%08X" % r for r in runs)))
    _, jt, ro, _ = segment.read_carves(prog)
    carved = segment.carved_rodata(prog, jt, ro)
    for lo, hi in runs:
        for clo, chi, ctu in carved:
            if lo < chi and clo < hi:
                refuse("overlaps-carve", "%s [0x%08X,0x%08X) overlaps carved [0x%08X,0x%08X) %s" % (prog, lo, hi, clo, chi, ctu))
    own = [(a, b) for a, b, t in ro if t == tu]
    mlo, mhi = min([a for a, _ in runs + own]), max([b for _, b in runs + own])
    layout = unit_layout(prog, tu, mlo, mhi, align)
    placement_refusals(prog, [(mlo, mhi)], tu, segment.carved_rodata(prog, jt, [r for r in ro if r[2] != tu]), blo, bhi)
    keep = [r for r in rec if not (r[0] == "rodata" and r[3] == tu)]
    place(root, prog, keep, unit, bhi, [["rodata", "0x%08X" % a, "0x%08X" % b, tu] for a, b, _ in layout])
    for a, b in runs:
        print("CARVE rodata OK %s 0x%08X 0x%08X-0x%08X %d" % (prog, func, a, b, b - a))
    if len(layout) > 1:
        print("CARVE rodata MERGED %s %s 0x%08X-0x%08X %d rows" % (prog, tu, mlo, mhi, len(layout)))


def uncarve_rodata(root, prog, func):
    """Inverse of carve_rodata for a planted control (gate.py --self-test case I): drop func's `rodata` rows and
    regenerate; the `block` row and the dropped D_ line stay (the next carve of func re-adds the same rows)."""
    fn = corpus(prog).get(func)
    rec = read_record(root, prog)
    blo, bhi, _ = rodata_block(root, prog, rec)
    runs = {"0x%08X" % a for a, b in table_runs(prog, blo, bhi, func, fn[2])} if fn else set()
    keep = [r for r in rec if not (r[0] == "rodata" and r[1] in runs)]  # by lo: a merged row carries its pad
    if len(keep) == len(rec):
        refuse("not-carved", "%s 0x%08X has no rodata row" % (prog, func))
    regenerate(root, prog, keep)


# ---- opt -----------------------------------------------------------------------------------------------------------

def anchors(lines, srcdir):
    """[(start, end, names)] of the function chunks of a C unit: INCLUDE_ASM lines, C definitions, and
    `#define ... #include "<body>.c" #undef ...` member blocks (names = the define targets, or the body's defs)."""
    out, i, text = [], 0, "\n".join(lines)
    offs = [0]
    for l in lines:
        offs.append(offs[-1] + len(l) + 1)
    while i < len(lines):
        l = lines[i]
        m = INC_RE.match(l)
        if m:
            out.append((i, i, {m.group(1)}))
            i += 1
            continue
        if l.startswith("#define ") or CINC_RE.match(l):
            j, names = i, set()
            while j < len(lines) and lines[j].startswith("#define "):
                names.update(lines[j].split()[2:3])
                j += 1
            m = CINC_RE.match(lines[j]) if j < len(lines) else None
            if m:
                if not names:
                    with open(os.path.join(srcdir, m.group(1))) as f:
                        names = {d.group(1) for d in (CDEF_RE.match(x) for x in f) if d}
                k = j + 1
                while k < len(lines) and lines[k].startswith("#undef "):
                    k += 1
                out.append((i, k - 1, names))
                i = k
                continue
        m = CDEF_RE.match(text, offs[i]) if l[:1].isalpha() and not l.startswith("extern") else None
        if m and "{" in text[offs[i]:m.end()]:
            e = i
            while offs[e + 1] <= m.end() - 1:
                e += 1
            if not m.group(2):
                while lines[e] != "}":
                    e += 1
            out.append((i, e, {m.group(1)}))
            i = e + 1
            continue
        i += 1
    return out


def split_c(path, newpath, name, tu, newtu):
    with open(path) as f:
        lines = f.read().rstrip("\n").split("\n")
    an = anchors(lines, os.path.dirname(path))
    k = [i for i, a in enumerate(an) if name in a[2]]
    if not k:
        refuse("no-chunk", "%s has no INCLUDE_ASM, C definition or member block of %s" % (path, name))
    if k[0] == 0:
        refuse("tu-start", "%s is the first chunk of %s" % (name, path))
    cut = an[k[0] - 1][1] + 1
    head = lines[:cut]
    while head and not head[-1].strip():
        head.pop()
    pre = lines[:an[0][0]]
    while pre and not pre[-1].strip():
        pre.pop()
    tail = lines[cut:]
    while tail and not tail[0].strip():
        tail.pop(0)
    old = "nonmatchings/%s\"" % tu
    tail = [l.replace(old, "nonmatchings/%s\"" % newtu) if INC_RE.match(l) else l for l in tail]
    with open(path, "w") as f:
        f.write("\n".join(head) + "\n")
    with open(newpath, "w") as f:
        f.write("\n".join(pre + [""] + tail) + "\n")


def carve_opt(root, prog, tu, vram, cflags):
    fns = corpus(prog)
    fn = fns.get(vram)
    if fn is None or fn[1] != tu:
        refuse("not-a-start", "%s 0x%08X is not a corpus function start inside TU %s" % (prog, vram, tu))
    start = dict((n, v) for v, n in text_tus(prog)).get(tu)
    if start is None:
        refuse("no-tu", "%s has no text TU %s" % (prog, tu))
    if vram == start:
        refuse("tu-start", "%s 0x%08X is the start of TU %s" % (prog, vram, tu))
    newtu = segment.hexname(vram)
    rec = read_record(root, prog)
    if tu in segment.c_units(prog):
        src = os.path.join(root, "src", prog)
        split_c(os.path.join(src, tu + ".c"), os.path.join(src, newtu + ".c"), fn[0], tu, newtu)
        with open(cfg(root, "c_units.txt"), "a") as f:
            f.write("%s %s\n" % (prog, newtu))
    for r in rec:  # a carved table whose dispatcher moves to the new TU follows it
        if r[0] == "jtbl":
            f = jtbl_rows(prog)[int(r[1], 16)][1]
            if r[2] == tu and f >= vram:
                r[2] = newtu
    regenerate(root, prog, rec + [["opt", tu, "0x%08X" % vram, newtu] + cflags.split()])
    print("CARVE opt OK %s %s@0x%08X" % (prog, tu, vram))


# ---- check ---------------------------------------------------------------------------------------------------------

def check(root, quiet=False):
    """Fail-closed: every record row valid against boundaries.txt + corpus, yaml block, .mk, c_units; count."""
    use_root(root)
    errs, n = [], 0
    say = (lambda s: None) if quiet else print
    progs = sorted(os.path.basename(p)[len("carve."):-len(".txt")] for p in os.listdir(cfg(root))
                   if p.startswith("carve.") and p.endswith(".txt"))
    mks = sorted(p[len("carve."):-len(".mk")] for p in os.listdir(cfg(root)) if p.startswith("carve.") and p.endswith(".mk"))
    errs += ["%s: config/carve.%s.mk without a record" % (p, p) for p in mks if p not in progs]
    for prog in progs:
        rec, fns, cset, rows = read_record(root, prog), corpus(prog), segment.c_units(prog), jtbl_rows(prog)
        for r in rec:
            if r[0] == "opt" and len(r) >= 4:
                fn = fns.get(int(r[2], 16))
                if fn is None or fn[1] != r[3] or r[3] != segment.hexname(int(r[2], 16)):
                    errs.append("%s opt %s %s: not a corpus function start of TU %s" % (prog, r[1], r[2], r[3]))
                elif r[1] in cset and r[3] not in cset:
                    errs.append("%s opt %s: c parent but no `%s %s` in config/c_units.txt" % (prog, r[3], prog, r[3]))
                else:
                    n += 1
                    say("CARVE opt OK %s %s@%s" % (prog, r[1], r[2]))
            elif r[0] == "jtbl" and len(r) == 3:
                row = rows.get(int(r[1], 16))
                fn = fns.get(row[1]) if row and row[1] is not None else None
                if row is None or "label-inside-scan-table" in row[3] or fn is None or fn[1] != r[2]:
                    errs.append("%s jtbl %s: row gone, no dispatcher, or dispatcher not in TU %s" % (prog, r[1], r[2]))
                else:
                    n += 1
                    say("CARVE jtbl OK %s %s" % (prog, r[1]))
            elif r[0] == "rodata" and len(r) == 4:
                lo, hi = int(r[1], 16), int(r[2], 16)
                ws = retail_words(prog, lo, hi) if lo % 4 == 0 and hi - lo >= 8 else []
                pad = 0
                while len(ws) > 2 and ws[-1][1] == 0:  # a merged row's trailing pad (< the unit's .rodata alignment)
                    ws, pad = ws[:-1], pad + 4
                f = [(v, e) for v, (_, t, e) in fns.items() if t == r[3] and ws and v <= ws[0][1] < e]
                if r[3] not in cset or not f or not all(f[0][0] <= w < f[0][1] for _, w in ws) \
                        or (pad and pad >= unit_align(prog, r[3])):
                    errs.append("%s rodata %s %s: not a c-unit TU %s table (retail words outside one function, or pad"
                                " >= alignment)" % (prog, r[1], r[2], r[3]))
                else:
                    n += 1
                    say("CARVE rodata OK %s %s-%s" % (prog, r[1], r[2]))
            elif r[0] == "block" and len(r) == 2:
                base = segment.read_programs(segment.BOUNDARIES)[prog][0]
                tus = text_tus(prog)
                src = os.path.join(root, "src", prog, "%s.c" % tus[0][1])
                dl = os.path.exists(src) and any((m.group(1) if m else None) == d_line(prog, base)
                                                 for m in map(INC_RE.match, open(src)))
                sym = cfg(root, "symbols.%s.txt" % prog)
                dl = dl or os.path.exists(sym) and re.search(r"(?m)^%s = 0x%08X;[ \t]*//" % (d_line(prog, base), base),
                                                              open(sym).read()) is not None
                if prog == segment.EXE["name"] or int(r[1], 16) != min(v for v in fns if v > base) or dl:
                    errs.append("%s block %s: not the first text function, or %s still in %s or attributed in %s" % (
                        prog, r[1], d_line(prog, base), src, sym))
            else:
                errs.append("%s: malformed record row %s" % (prog, " ".join(r)))
        if prog != segment.EXE["name"] and any(r[0] in ("jtbl", "rodata") for r in rec) and \
                not any(r[0] == "block" for r in rec):
            errs.append("%s: rodata carves without a `block` row" % prog)
        _, jt, ro, _ = segment.read_carves(prog)
        pts = [t for _, _, t in segment.carved_rodata(prog, jt, ro)]
        errs += ["%s: TU %s rodata is not one contiguous `.rodata` piece" % (prog, t) for t in sorted(set(pts))
                 if pts.count(t) > 1]
        mk = cfg(root, "carve.%s.mk" % prog)
        if not os.path.exists(mk) or open(mk).read() != render_mk(prog, rec):
            errs.append("%s: config/carve.%s.mk != the record" % (prog, prog))
    allprogs = segment.read_programs(segment.BOUNDARIES)
    for prog in sorted(p for p in allprogs if os.path.exists(cfg(root, p + ".yaml"))):
        with open(cfg(root, prog + ".yaml")) as f:
            lines = f.read().split("\n")
        m = segment.marked(lines)
        want = segment.block(prog, allprogs)
        if m is None or lines[m[0]:m[1] + 1] != want:
            errs.append("%s: config/%s.yaml block != segment.py regeneration" % (prog, prog))
    for e in [] if quiet else errs:
        print("CARVE CHECK FAIL " + e)
    if errs:
        return 1
    say("CARVE CHECK OK %d carves" % n)
    return 0


# ---- self-test -----------------------------------------------------------------------------------------------------

EXE = segment.EXE["name"]
PLANTS = ["jtbl 0x80011E00 0x80011E10 - scan planted",
          "jtbl 0x80011E40 0x80011E50 0x800328b0 scan label-inside-scan-table",
          "jtbl 0x80012090 0x800120B0 0x800328b0 both planted-straddle",
          "jtbl 0x80011380 0x80011390 0x800328b0 both planted-overlap",
          "jtbl 0x80011E80 unknown - ghidra label-inside-scan-table"]  # hi `unknown` in a prog with jtbl carves (T45)
UNKNOWN = "jtbl 0x800E9B04 unknown - ghidra label-inside-scan-table"  # hi `unknown`, in rock_04 (record, no jtbl carve)
OVL = ["rock_04", "rock_01"]  # rock_04: D_800E9860 rodata block [0x800E9860, 0x800E9B30); rock_01: first TU asm, no block


def scratch():
    """Fresh copy of the exe's carve inputs under .run/carve-selftest/ (never the real config/src)."""
    shutil.rmtree(SCRATCH, ignore_errors=True)
    os.makedirs(cfg(SCRATCH))
    for p in ["boundaries.txt", "c_units.txt"] + [x % q for q in [EXE] + OVL for x in ("%s.yaml", "carve.%s.txt", "carve.%s.mk",
                                                                                  "symbols.%s.txt")]:
        if os.path.exists(cfg(ROOT, p)):
            shutil.copy(cfg(ROOT, p), cfg(SCRATCH, p))
    for q in [EXE] + OVL:
        if os.path.isdir(os.path.join(ROOT, "src", q)):
            shutil.copytree(os.path.join(ROOT, "src", q), os.path.join(SCRATCH, "src", q))
    shutil.copytree(os.path.join(ROOT, "src", "shared"), os.path.join(SCRATCH, "src", "shared"))
    use_root(SCRATCH)


def expect(code, fn, *a):
    try:
        fn(*a)
    except Refuse as e:
        ok = (" %s " % code) in str(e) + " "
        print("control %-15s %s" % (code, "tripped" if ok else "WRONG: " + str(e)))
        return ok
    print("control %-15s NOT refused" % code)
    return False


def self_test():
    ok = True
    scratch()
    ok &= check(SCRATCH, quiet=True) == 0
    print("control check-baseline %s" % ("passed" if ok else "FAILED"))
    y = cfg(SCRATCH, EXE + ".yaml")
    with open(y) as f:
        orig = f.read()
    with open(y, "w") as f:
        f.write(orig.replace(", rodata, 10000]", ", rodata, 10004]", 1))
    t = check(SCRATCH, quiet=True) != 0
    print("control check-yaml-edit %s" % ("tripped" if t else "NOT refused"))
    ok &= t
    with open(y, "w") as f:
        f.write(orig)
    bp = segment.BOUNDARIES
    with open(bp) as f:
        b = f.read()
    hdr = b.index("# program %s " % EXE)
    eol = b.index("\n", hdr) + 1
    with open(bp, "w") as f:
        f.write(b[:eol] + "\n".join(PLANTS) + "\n" + b[eol:])
    with open(bp) as f:
        b = f.read()
    eol = b.index("\n", b.index("# program rock_04 ")) + 1
    with open(bp, "w") as f:
        f.write(b[:eol] + UNKNOWN + "\n" + b[eol:])
    if not any(r[0] == "jtbl" and int(r[1], 16) == 0x80011378 for r in read_record(SCRATCH, EXE)):
        carve_jtbl(SCRATCH, EXE, 0x80011378)  # the positive control (when the real record lacks it)
    ok &= expect("not-a-row", carve_jtbl, SCRATCH, EXE, 0x80011379)
    ok &= expect("not-a-row", carve_jtbl, SCRATCH, "rock_04", 0x800E9B04)  # hi `unknown`: a label, not a table
    t = check(SCRATCH, quiet=True) == 0  # reaches segment.carved_rodata(EXE) past the exe's `unknown`-hi plant
    print("control check-unknown-hi %s" % ("passed" if t else "FAILED"))
    ok &= t
    ok &= expect("not-a-row", carve_jtbl, SCRATCH, EXE, 0x80011E80)  # hi `unknown`: a label, not a table
    ok &= expect("no-dispatcher", carve_jtbl, SCRATCH, EXE, 0x80011E00)
    ok &= expect("no-dispatcher", carve_jtbl, SCRATCH, EXE, 0x80011E40)
    ok &= expect("straddles", carve_jtbl, SCRATCH, EXE, 0x80012090)
    ok &= expect("overlaps-carve", carve_jtbl, SCRATCH, EXE, 0x80011380)
    ok &= expect("non-contiguous", carve_jtbl, SCRATCH, EXE, 0x80011398)
    ok &= expect("no-rodata-block", carve_rodata, SCRATCH, "rock_01", 0x801EA004, None)
    if any(r[0] == "rodata" and r[1] == "0x800E9894" for r in read_record(SCRATCH, "rock_04")):
        uncarve_rodata(SCRATCH, "rock_04", 0x800EA2A8)  # the real record has it (T4.c2 gate): block row and D_ drop stay
    rec4 = read_record(SCRATCH, "rock_04")  # a merged E9860 record (T44.c1) keeps other tables' rows: drop them too
    if any(r[0] == "rodata" for r in rec4):
        regenerate(SCRATCH, "rock_04", [r for r in rec4 if r[0] != "rodata"])
    ok &= expect("no-function", carve_rodata, SCRATCH, "rock_04", 0x800EA2AC, None)
    ok &= expect("no-table", carve_rodata, SCRATCH, "rock_04", 0x800E9C84, None)
    ok &= expect("size-mismatch", carve_rodata, SCRATCH, "rock_04", 0x800EA2A8, 16)  # 24: a legal pad < 8 (T44.c1)
    carve_rodata(SCRATCH, "rock_04", 0x800EA2A8, 20)  # positive control: overlay block + D_ line drop
    if any(r[0] == "rodata" and r[1] == "0x8001004C" for r in read_record(SCRATCH, EXE)):
        uncarve_rodata(SCRATCH, EXE, 0x8001574C)  # the real record has it (T13 W13 gate)
    carve_rodata(SCRATCH, EXE, 0x8001574C, 28)  # positive control: exe
    c4 = os.path.join(SCRATCH, "src", "rock_04", "E9860.c")
    with open(c4) as f:
        c4s = f.read()
    y4 = open(cfg(SCRATCH, "rock_04.yaml")).read()
    t = ("D_800E9860" not in c4s and ["block", "0x800E9B30"] in read_record(SCRATCH, "rock_04")
         and "\nD_800E9860 = 0x800E9860;\n" in open(cfg(SCRATCH, "symbols.rock_04.txt")).read()
         and "- [0x34, .rodata, E9860]\n" in y4 and "- [0x2D0, c, E9860]\n" in y4
         and "- [0x84C, .rodata, 120A0]\n" in open(cfg(SCRATCH, EXE + ".yaml")).read() and check(SCRATCH, quiet=True) == 0)
    print("control rodata-carve  %s" % ("placed" if t else "WRONG"))
    ok &= t
    ok &= expect("overlaps-carve", carve_rodata, SCRATCH, "rock_04", 0x800EA2A8, None)
    ok &= expect("overlaps-carve", carve_rodata, SCRATCH, EXE, 0x8001574C, None)
    global CORPUS  # planted: 0x800EBAA0 (its table lies between EA2A8's and EF738's) in another TU
    real, CORPUS = CORPUS, os.path.join(SCRATCH, "functions.jsonl")
    with open(real) as f, open(CORPUS, "w") as g:
        g.writelines(l.replace('"tu": "E9860"', '"tu": "EBAA0"') if '"prog": "rock_04"' in l and '"vram": "0x800EBAA0"' in l
                     else l for l in f)
    ok &= expect("foreign-rodata", carve_rodata, SCRATCH, "rock_04", 0x800EF738, None)  # was non-contiguous before T44.c1
    CORPUS = real
    with open(c4, "w") as f:
        f.write(c4s.replace("\n\n", '\n\nINCLUDE_ASM("asm/rock_04/nonmatchings/E9860", D_800E9860);\n\n', 1))
    t = check(SCRATCH, quiet=True) != 0
    print("control check-d-line  %s" % ("tripped" if t else "NOT refused"))
    ok &= t
    with open(c4, "w") as f:
        f.write(c4s)
    r4 = cfg(SCRATCH, "carve.rock_04.txt")
    with open(r4) as f:
        r4s = f.read()
    with open(r4, "w") as f:
        f.write(r4s.replace("rodata 0x800E9894 0x800E98A8", "rodata 0x800E9890 0x800E98A8"))
    t = check(SCRATCH, quiet=True) != 0
    print("control check-rodata  %s" % ("tripped" if t else "NOT refused"))
    ok &= t
    with open(r4, "w") as f:
        f.write(r4s)
    # second table in one unit (T44.c1): ED3A4's 244 B table merges with EA2A8's into one `.rodata E9860` range
    ok &= expect("size-mismatch", carve_rodata, SCRATCH, "rock_04", 0x800ED3A4, 252)  # pad 8 >= alignment 8
    carve_rodata(SCRATCH, "rock_04", 0x800ED3A4, 248)  # pad 4 < alignment 8: accepted
    y4 = open(cfg(SCRATCH, "rock_04.yaml")).read()
    t = ([r for r in read_record(SCRATCH, "rock_04") if r[0] == "rodata"] == [
        ["rodata", a, b, "E9860"] for a, b in (("0x800E9894", "0x800E98AC"), ("0x800E98AC", "0x800E98C0"),
                                               ("0x800E98C0", "0x800E98F4"), ("0x800E98F4", "0x800E99E8"))]
         and y4.count(", .rodata, E9860]") == 1 and "- [0x34, .rodata, E9860]\n" in y4 and "- [0x188, rodata, E99E8]\n" in y4
         and check(SCRATCH, quiet=True) == 0)
    print("control rodata-merge  %s" % ("placed" if t else "WRONG"))
    ok &= t
    fns = corpus(EXE)
    tu = fns[0x800429C4][1]
    ok &= expect("not-a-start", carve_opt, SCRATCH, EXE, tu, 0x800429C8, "")
    start = dict((n, v) for v, n in text_tus(EXE))[tu]
    ok &= expect("tu-start", carve_opt, SCRATCH, EXE, tu, start, "")
    carve_opt(SCRATCH, EXE, tu, 0x800429C4, "-O0 -G0")  # positive control: a C-definition chunk moves
    src = os.path.join(SCRATCH, "src", EXE)
    with open(os.path.join(src, "429C4.c")) as f:
        new = f.read()
    with open(os.path.join(src, tu + ".c")) as f:
        head = f.read()
    t = (new.startswith('#include "common.h"\n\nvoid func_800429C4(void) {') and "func_800429C4" not in head
         and "nonmatchings/%s\"" % tu not in new and "CFLAGS_429C4 := -O0 -G0" in open(cfg(SCRATCH, "carve.%s.mk" % EXE)).read()
         and "%s 429C4" % EXE in open(cfg(SCRATCH, "c_units.txt")).read())
    print("control opt-split     %s" % ("moved" if t else "WRONG"))
    ok &= t
    use_root(ROOT)
    if not ok:
        print("CARVE CONTROL FAILED")
        return 1
    print("CARVE CONTROL OK")
    return 0


def main(argv):
    try:
        if argv[:1] == ["--self-test"]:
            return self_test()
        if argv[:1] == ["--check"]:
            return check(ROOT)
        use_root(ROOT)
        if len(argv) == 3 and argv[0] == "jtbl":
            carve_jtbl(ROOT, argv[1], int(argv[2], 16))
            return 0
        if len(argv) in (3, 5) and argv[0] == "rodata" and (len(argv) == 3 or argv[3] == "--bytes"):
            carve_rodata(ROOT, argv[1], int(argv[2], 16), int(argv[4], 0) if len(argv) == 5 else None)
            return 0
        if len(argv) in (4, 6) and argv[0] == "opt" and (len(argv) == 4 or argv[4] == "--cflags"):
            carve_opt(ROOT, argv[1], argv[2], int(argv[3], 16), argv[5] if len(argv) == 6 else "")
            return 0
    except Refuse as e:
        print(e)
        return 1
    print(__doc__.strip())
    return 2


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
