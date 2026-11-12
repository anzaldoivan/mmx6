#!/usr/bin/env python3
"""carve.py -- deliberate segment edges per binary: jump-table rodata carves and opt-level unit splits (stdlib only).

    carve.py jtbl <prog> <table_lo>                         table = config/boundaries.txt `jtbl` row lo
    carve.py rodata <prog> <func_vram> [--bytes N]          tables = retail words of the rodata block inside func
    carve.py data <prog> <lo>                               same-unit const data run at a dlabel lo (T28.c1)
    carve.py opt <prog> <tu> <split vram> [--cflags "<f>"] [--gate]  split <tu> at a corpus function start
    carve.py --check                                        every record still valid (fail-closed)
    carve.py --self-test                                    planted refusals on a scratch copy under .run/

Record config/carve.<prog>.txt (tracked, written only here): `jtbl <table_lo> <tu>` | `rodata <lo> <hi> <tu>` |
`data <lo> <hi> <tu>` | `block <hi>` | `opt <tu> <vram> <newtu> [cflags...]`, newtu = vram hex without 0x80. tools/mmx6/segment.py applies it to
the generated yaml block: an opt row is a text edge (TU <newtu>, kind of its parent); a jtbl row cuts the rodata block
at [lo, hi) into `.rodata <tu>`, which splat pairs with unit <tu> (the table migrates into its dispatcher's INCLUDE_ASM
.s). rodata: the table ranges are the maximal runs (>= 2 words) of retail words in the rodata block whose values all
lie in [func, func end) (corpus); --bytes N asserts their byte sum T (T + pad P = N, 0 <= P < the unit object's
.rodata alignment; T44.c1); one `rodata` row per run. Several tables of one unit: the unit's rows are merged into one
contiguous range in TU function order, one row per table (its trailing zero pad < alignment included); any other byte
in that range refuses `foreign-rodata` (T44.c1). jtbl: a gap between the table and the unit's carved piece made only of
boundaries jtbl tables whose dispatchers are corpus functions of the unit (each followed by zero pad < alignment) is
carved with it, one row per table in address order (`jtbl <lo> <tu>`, or `rodata <lo> <hi+pad> <tu>` when padded) and
one `CARVE jtbl OK` line each; any other byte in the gap refuses `non-contiguous` (T11.c1). data (T28.c1): [lo, hi) = the dlabel at lo to the next asm symbol
(asm/<prog>); tu = the TU of every reference to a D_/jtbl_ name inside [lo, hi): asm .s of every program outside
asm/<prog>/nonmatchings/<tu>/ (dlabel/enddlabel/.size lines are the definition) and src C (comments stripped) outside
<tu>'s include closure; none, or any foreign one, refuses `foreign-rodata`. The run must touch a `jtbl`/`rodata`/`data`
row of tu or a boundaries jtbl row whose dispatcher is in tu (else `not-adjacent`), then the jtbl refusals; the row merges
with the unit's tables like a `rodata` row (its bytes: INCLUDE_RODATA in the unit's C at its rodata-order position, by
hand). Rodata block: exe
[0x80010000, 0x800120A0); overlay [base, first text function) when its first TU is a c unit whose .c holds
`INCLUDE_ASM(..., D_<base>)`: the first carve of an overlay drops that line and records `block <hi>` (hi = the first
text function), from which segment.py cuts [base, hi) and starts the unit at hi. On a c parent, opt moves the
tail of src/<prog>/<tu>.c (from the split function's chunk) to src/<prog>/<newtu>.c and adds `<prog> <newtu>` to
config/c_units.txt; a thin unit (L-B, layout.py) splits at its role-file includes only (a split point inside a role file
refuses `role-split`; a moved role file's INCLUDE_ASM folders are renamed to <newtu>, C0070); the self-test's second
pass plants a thin unit over two role files in its scratch. The tail's preamble is the head's header plus every
non-chunk, non-comment line between its chunks (declarations, externs, #defines) plus the file-scope extern/prototype
lines of the head's member bodies (their block's #defines applied); the head is written unchanged. opt moves the
parent's `jtbl` rows whose dispatcher, and `rodata` rows whose retail words' function (corpus), starts >= the split
vram to <newtu> (rodata-follow), and removes asm/<prog> and build/split/<prog>.stamp so the next make re-splits
(C0289; T23). --gate snapshots every file the carve writes (unit, tail, role files, c_units, record, .mk, yaml),
re-splits, rebuilds the program clean and runs `sha1sum -c config/check.<prog>.sha` (log
.run/carve/gate.<prog>.log): green prints `CARVE opt GATE OK ...`; red restores the snapshot, re-splits and refuses
`carve-red`. config/carve.<prog>.mk (generated from the record, included by the Makefile) sets the per-unit cc1 flags
`CFLAGS_<newtu>`. Inputs: build/corpus/functions.jsonl (corpus.py --all) for function starts and TUs.
Retail words: extracted/retail/iso/SLUS_013.95 | extracted/retail/rock/NN.bin.
Prints `CARVE jtbl OK <prog> 0x<lo>` / `CARVE data OK <prog> 0x<lo>-0x<hi> <tu>` / `CARVE rodata OK <prog> 0x<func> 0x<lo>-0x<hi> <bytes>` (per range) /
`CARVE opt OK <prog> <tu>@0x<vram>`; --check prints those per verified row (rodata: `CARVE rodata OK <prog> 0x<lo>-0x<hi>`; data:
`CARVE data OK <prog> 0x<lo>-0x<hi>`) and
ends `CARVE CHECK OK <n> carves`; --self-test ends `CARVE CONTROL OK`. A refusal prints `CARVE REFUSE <code> ...`, rc 1.
"""
import json
import os
import re
import shutil
import struct
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import layout  # noqa: E402  (ASM_RE, asm_line: the INCLUDE_ASM regex and literal)
import probe  # noqa: E402  (sym_name, plant_lookup: the self-test's names looked up by vram)
import segment  # noqa: E402

CORPUS = os.path.join(ROOT, "build", "corpus", "functions.jsonl")
SCRATCH = os.path.join(ROOT, ".run", "carve-selftest")
INC_RE = layout.ASM_RE  # an INCLUDE_ASM line (the one regex, tools/mmx6/layout.py)
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


def jtbl_carved(prog, lo):
    """True when prog's boundaries jtbl row at lo lies inside a recorded `jtbl` or `rodata` range (a `rodata` row may
    cover a once-`jtbl`-carved table, T35.c53)."""
    hi = jtbl_rows(prog)[lo][0]
    _, jt, ro, _ = segment.read_carves(prog)
    return any(clo <= lo and hi <= chi for clo, chi, _ in segment.carved_rodata(prog, jt, ro))


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
    """(lo, hi, path) of prog's rodata block; path = the repo path of the file (the first c unit or a role file in its
    include closure, found via layout.find_asm) whose D_<base> line a first carve drops (None for the exe or an overlay
    whose record already has its `block` row)."""
    if prog == segment.EXE["name"]:
        return segment.EXE["rodata_lo"], segment.EXE["text_lo"], None
    base = segment.read_programs(segment.BOUNDARIES)[prog][0]
    his = [int(r[1], 16) for r in rec if r[0] == "block"]
    if his:
        return base, his[0], None
    tus = text_tus(prog)
    unit = tus[0][1] if tus and tus[0][0] == base else None
    hit = layout.find_asm(prog, d_line(prog, base), root) if unit in segment.c_units(prog) else None
    has = hit is not None and hit[2] == unit
    first = min([v for v in corpus(prog) if v > base], default=None)
    if not has or first is None:
        refuse("no-rodata-block", "%s first TU %s is not a c unit with INCLUDE_ASM(..., %s)" % (prog, unit, d_line(prog, base)))
    return base, first, hit[0]


def place(root, prog, rec, unit, hi, rows):
    """Append rows to the record; an overlay's first carve also drops its D_<base> line (in the file `unit`, a repo
    path from rodata_block) and records `block <hi>`."""
    if unit is not None:
        base = segment.read_programs(segment.BOUNDARIES)[prog][0]
        path = os.path.join(root, unit)
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
                "# jtbl <table_lo> <tu> | rodata <lo> <hi> <tu> | data <lo> <hi> <tu> | block <hi> | opt <tu> <vram> <newtu> [cflags...]\n"
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
    fns = corpus(prog)
    fn = fns.get(func)
    if fn is None:
        refuse("no-function", "%s dispatcher 0x%08X is not a corpus function start" % (prog, func))
    tables = bridge(prog, lo, hi, fn[1], carved, rows, fns) or [(lo, hi, hi)]
    placement_refusals(prog, [(a, p) for a, _, p in tables], fn[1], carved, blo, bhi)
    place(root, prog, rec, unit, bhi, [["jtbl", "0x%08X" % a, fn[1]] if p == b else
                                       ["rodata", "0x%08X" % a, "0x%08X" % p, fn[1]] for a, b, p in tables])
    for a, b, p in tables:
        print("CARVE jtbl OK %s 0x%08X%s" % (prog, a, "" if p == b else " as rodata 0x%08X-0x%08X (pad)" % (a, p)))


def bridge(prog, lo, hi, tu, carved, rows, fns):
    """T11.c1: [(lo, hi, hi_with_pad)] in address order of the target and the gap tables between it and tu's carved
    piece, when that gap is only boundaries jtbl tables whose dispatchers are corpus functions of tu, each followed by
    zero pad < the unit object's .rodata alignment; None when there is no gap or it holds anything else
    (placement_refusals then decides: overlaps-carve, straddles, non-contiguous)."""
    own = [(a, b) for a, b, t in carved if t == tu]
    if len(own) != 1 or not (hi <= own[0][0] or own[0][1] <= lo):
        return None
    glo, ghi = (hi, own[0][0]) if hi <= own[0][0] else (own[0][1], lo)
    if glo == ghi:
        return None
    align, words = unit_align(prog, tu), dict(retail_words(prog, glo, ghi))
    out, p = [[lo, hi, hi]] if hi <= own[0][0] else [], glo
    while p < ghi:
        if p in rows:
            h, f = rows[p][0], rows[p][1]
            if f is None or "label-inside-scan-table" in rows[p][3] or fns.get(f, (0, None))[1] != tu or h > ghi:
                break
            out.append([p, h, h])
            p = h
            continue
        q = p
        while q < ghi and q not in rows and words.get(q) == 0:
            q += 4
        if not out or q == p or q - p >= align or (q < ghi and q not in rows):
            break
        out[-1][2] = q
        p = q
    if p < ghi:  # not bridgeable: placement_refusals refuses (straddles, ..., non-contiguous) as before T11.c1
        return None
    if not out or out[0][0] != lo:
        out.append([lo, hi, hi])
    return [tuple(x) for x in out]


# ---- data ----------------------------------------------------------------------------------------------------------

ASM = os.path.join(ROOT, "asm")
NAME_RE = re.compile(r"\b(?:D|jtbl)_([0-9A-F]{8})\b")
LABEL_RE = re.compile(r"^\s*(dlabel|glabel|jlabel)\s+(\w+)")
WORD_RE = re.compile(r"^\s*/\*\s*[0-9A-F]+\s+([0-9A-F]{8})\s")
DEF_RE = re.compile(r"^\s*(dlabel|enddlabel|nonmatching|\.size)\b")


def asm_files(prog=None):
    """Every .s path under asm/ (asm/<prog>/ when prog is given), sorted."""
    top = os.path.join(ASM, prog) if prog else ASM
    return sorted(os.path.join(d, n) for d, _, ns in os.walk(top) for n in ns if n.endswith(".s"))


def data_hi(prog, lo):
    """hi of the data run at the dlabel lo: the next asm symbol after it in its .s, else the file's last word + 4."""
    for path in asm_files(prog):
        with open(path, errors="replace") as f:
            lines = f.read().split("\n")
        at = [i for i, l in enumerate(lines) if (lambda m: m and m.group(1) == "dlabel" and
                                                 NAME_RE.fullmatch(m.group(2)) and int(m.group(2)[-8:], 16) == lo)(LABEL_RE.match(l))]
        if not at:
            continue
        hi = None
        for l in lines[at[0] + 1:]:
            m, w = LABEL_RE.match(l), WORD_RE.match(l)
            if m and m.group(1) != "jlabel" and re.search(r"_([0-9A-F]{8})$", m.group(2)) and int(m.group(2)[-8:], 16) > lo:
                return int(m.group(2)[-8:], 16)
            if w:
                hi = int(w.group(1), 16) + 4
        if hi is not None:
            return hi
    refuse("no-symbol", "%s no `dlabel` at 0x%08X in asm/%s (split first)" % (prog, lo, prog))


def unit_closure(root, prog, tu):
    """Repo paths of src/<prog>/<tu>.c and every file it includes (transitively)."""
    tree, seen = layout.Tree(root), set()
    todo = [tree.unit_rel(prog, tu)]
    while todo:
        r = todo.pop()
        if r in seen or not tree.exists(r):
            continue
        seen.add(r)
        todo += [e.target if e.target.startswith("src/") else layout.norm(r, e.target)
                 for e in layout.parse(tree.lines(r)) if e.kind == "inc"]
    return seen


def data_refs(root, prog, lo, hi):
    """[("path:line", tu | None)] of the references to a D_/jtbl_ name inside [lo, hi): asm .s of every program
    (definition lines skipped; tu = <x> under asm/<prog>/nonmatchings/<x>/, else None) and src C (comments stripped;
    tu = each unit of prog whose include closure holds the file, None when none does)."""
    out = []
    hit = lambda l: any(lo <= int(x, 16) < hi for x in NAME_RE.findall(l))
    mine = os.path.join(ASM, prog, "nonmatchings") + os.sep
    for path in asm_files():
        with open(path, errors="replace") as f:
            for i, l in enumerate(f, 1):
                if hit(l) and not DEF_RE.match(l):
                    tu = path[len(mine):].split(os.sep)[0] if path.startswith(mine) else None
                    out.append(("%s:%d" % (os.path.relpath(path, ROOT), i), tu))
    closures = [(t, unit_closure(root, prog, t)) for _, t in layout.Tree(root).units(prog)]
    for d, _, ns in os.walk(os.path.join(root, "src")):
        for n in sorted(ns):
            if not n.endswith((".c", ".h")):
                continue
            rel = os.path.relpath(os.path.join(d, n), root)
            with open(os.path.join(d, n), errors="replace") as f:
                t = re.sub(r"/\*.*?\*/", lambda m: "\n" * m.group(0).count("\n"), f.read(), flags=re.S)
            for i, l in enumerate(t.split("\n"), 1):
                if hit(l.split("//", 1)[0]):
                    out += [("%s:%d" % (rel, i), u) for u in ([u for u, c in closures if rel in c] or [None])]
    return out


def data_adjacent(prog, lo, hi, tu, rec, fns):
    """True when [lo, hi) touches a `jtbl`/`rodata`/`data` row of tu, or a boundaries jtbl row whose dispatcher is in tu."""
    rows = jtbl_rows(prog)
    ranges = [(int(r[1], 16), rows.get(int(r[1], 16), (0,))[0]) for r in rec if r[0] == "jtbl" and r[2] == tu]
    ranges += [(int(r[1], 16), int(r[2], 16)) for r in rec if r[0] in ("rodata", "data") and r[3] == tu]
    ranges += [(a, b) for a, (b, f, _, n) in rows.items() if f is not None and "label-inside-scan-table" not in n
               and fns.get(f, (None, None))[1] == tu]
    return any(b == lo or a == hi for a, b in ranges)


def carve_data(root, prog, lo, tu=None, hi=None):
    """Carve the const data run at the dlabel lo into the rodata of the one TU that references it (tu: asserted, hi: given
    instead of read from asm/; the self-test's plants)."""
    rec = read_record(root, prog)
    blo, bhi, unit = rodata_block(root, prog, rec)
    hi = data_hi(prog, lo) if hi is None else hi
    refs = data_refs(root, prog, lo, hi)
    tus = sorted({u or "-" for _, u in refs})
    if len(tus) != 1 or tus[0] == "-" or tu not in (None, tus[0]):
        refuse("foreign-rodata", "%s [0x%08X,0x%08X) referenced from TUs %s: %s" % (
            prog, lo, hi, " ".join(tus) or "none", " ".join("%s(%s)" % (p, u or "-") for p, u in refs) or "no reference"))
    tu = tus[0]
    if not data_adjacent(prog, lo, hi, tu, rec, corpus(prog)):
        refuse("not-adjacent", "%s [0x%08X,0x%08X) touches no table of TU %s" % (prog, lo, hi, tu))
    _, jt, ro, _ = segment.read_carves(prog)
    placement_refusals(prog, [(lo, hi)], tu, segment.carved_rodata(prog, jt, ro), blo, bhi)
    place(root, prog, rec, unit, bhi, [["data", "0x%08X" % lo, "0x%08X" % hi, tu]])
    print("CARVE data OK %s 0x%08X-0x%08X %s" % (prog, lo, hi, tu))


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


def unit_layout(prog, tu, lo, hi, align, data=()):
    """[(lo, hi_with_pad, owner)] of the tables of tu's functions tiling [lo, hi), each followed by its zero pad
    (< align bytes); refuse foreign-rodata on any other byte, a table of another TU, or tables out of TU order.
    data = tu's recorded `data` runs [(lo, hi)] (T28.c1): tiles with owner None, no pad after them."""
    fns = corpus(prog)
    starts = {}
    for v, (_, t, e) in fns.items():
        for a, b in table_runs(prog, lo, hi, v, e):
            starts[a] = (b, v, t)
    dstarts = dict(data)
    words = dict(retail_words(prog, lo, hi))
    out, p = [], lo
    while p < hi:
        if p in dstarts:
            out.append([p, dstarts[p], None])
            p = dstarts[p]
            continue
        if p in starts:
            b, v, t = starts[p]
            last = [x[2] for x in out if x[2] is not None]
            if t != tu or (last and v < last[-1]):
                refuse("foreign-rodata", "%s [0x%08X,0x%08X) holds 0x%08X-0x%08X, a table of 0x%08X (TU %s)%s" % (
                    prog, lo, hi, p, b, v, t, "" if t != tu else " out of TU function order"))
            out.append([p, b, v])
            p = b
            continue
        q = p
        while q < hi and q not in starts and q not in dstarts and words.get(q) == 0:
            q += 4
        if not out or out[-1][2] is None or q == p or q - p >= align or q >= hi or (q not in starts and q not in dstarts):
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
    own = [(a, b) for a, b, t in ro if t == tu]  # its `rodata` and `data` rows (segment.read_carves)
    data = [(int(r[1], 16), int(r[2], 16)) for r in rec if r[0] == "data" and r[3] == tu]
    mlo, mhi = min([a for a, _ in runs + own]), max([b for _, b in runs + own])
    layout = [x for x in unit_layout(prog, tu, mlo, mhi, align, data) if x[2] is not None]
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
    """[(start, end, names, role)] of the function chunks of a C unit: INCLUDE_ASM lines, C definitions, and
    `#define ... #include "<body>.c" #undef ...` member blocks (names = the define targets, or the body's defs); a
    bare include of a file outside src/shared/ is a role file (L-B, layout.py): names = every function of its chunks,
    role = (its path, the names of its first chunk); else role = None."""
    out, i, text = [], 0, "\n".join(lines)
    offs = [0]
    for l in lines:
        offs.append(offs[-1] + len(l) + 1)
    while i < len(lines):
        l = lines[i]
        m = INC_RE.match(l)
        if m:
            out.append((i, i, {m.group(1)}, None))
            i += 1
            continue
        if l.startswith("#define ") or CINC_RE.match(l):
            j, names = i, set()
            while j < len(lines) and lines[j].startswith("#define "):
                names.update(lines[j].split()[2:3])
                j += 1
            m = CINC_RE.match(lines[j]) if j < len(lines) else None
            if m:
                role, target = None, os.path.normpath(os.path.join(srcdir, m.group(1)))
                if not names and "shared" not in target.split(os.sep):  # a role file: its own chunks, in order
                    with open(target) as f:
                        sub = anchors(f.read().rstrip("\n").split("\n"), os.path.dirname(target))
                    names = set().union(*(a[2] for a in sub))
                    role = (target, sub[0][2] if sub else set())
                elif not names:
                    with open(target) as f:
                        names = {d.group(1) for d in (CDEF_RE.match(x) for x in f) if d}
                k = j + 1
                while k < len(lines) and lines[k].startswith("#undef "):
                    k += 1
                out.append((i, k - 1, names, role))
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
            out.append((i, e, {m.group(1)}, None))
            i = e + 1
            continue
        i += 1
    return out


DECL_RE = re.compile(r"(extern\s[^;{}]*|(?!static\b|typedef\b|return\b)[A-Za-z_][\w \t*]*[ \t*]\w+\s*\([^;{}=]*\))"
                     r"\s*;\s*$")  # a file-scope extern or prototype line


def member_decls(block, srcdir):
    """File-scope `extern` and prototype lines (and `#include "<x>.h"` lines, no `..`) of the .c body a member block
    (#define... #include #undef...) includes, in order, each with the block's #defines applied as cpp would (whole
    words); a line using a macro the body itself defines is skipped; [] for an INCLUDE_ASM or C-definition chunk."""
    m = next((CINC_RE.match(l) for l in block if CINC_RE.match(l)), None)
    if m is None:
        return []
    defs = [l.split()[1:3] for l in block if l.startswith("#define ") and len(l.split()) == 3]
    out, depth, own = [], 0, set()  # own: the body's own macros active at this line (a line using one is not carried)
    with open(os.path.normpath(os.path.join(srcdir, m.group(1)))) as f:
        for l in f:
            w = l.split()
            if w[:1] in (["#define"], ["#undef"]) and len(w) > 1:
                (own.add if w[0] == "#define" else own.discard)(w[1].split("(")[0])
            elif depth == 0 and re.match(r'#include "[^".]+(/[^".]+)*\.h"\s*$', l):  # the header a decl's types need
                out.append(l.rstrip())
            elif depth == 0 and DECL_RE.match(l) and not own & set(re.findall(r"\w+", l)):
                d = l.rstrip()
                for a, b in defs:
                    d = re.sub(r"\b%s\b" % re.escape(a), b, d)
                out.append(d)
            depth += l.count("{") - l.count("}")
    return out


def split_c(path, newpath, name, tu, newtu):
    with open(path) as f:
        lines = f.read().rstrip("\n").split("\n")
    an = anchors(lines, os.path.dirname(path))
    k = [i for i, a in enumerate(an) if name in a[2]]
    if not k:
        refuse("no-chunk", "%s has no INCLUDE_ASM, C definition or member block of %s" % (path, name))
    if an[k[0]][3] and name not in an[k[0]][3][1]:  # a thin unit splits at its role includes only
        refuse("role-split", "%s is inside role file %s, not its first function" % (name, an[k[0]][3][0]))
    if k[0] == 0:
        refuse("tu-start", "%s is the first chunk of %s" % (name, path))
    cut = an[k[0] - 1][1] + 1
    head = lines[:cut]
    while head and not head[-1].strip():
        head.pop()
    inside = {j for a in an[:k[0]] for j in range(a[0], a[1] + 1)}
    pre, cmt = lines[:an[0][0]], False  # the tail's preamble: the header + every non-chunk, non-comment line between
    for j in range(an[0][0], cut):  # the head's chunks (declarations, externs, #defines; T23)
        s = lines[j].strip()
        if j in inside or cmt or s.startswith("//") or s.startswith("/*"):
            cmt = (cmt or s.startswith("/*")) and "*/" not in s
            continue
        if s or (pre and pre[-1].strip()):
            pre.append(lines[j])
    while pre and not pre[-1].strip():
        pre.pop()
    carried = []  # file-scope declarations the head's member bodies made, which later bodies rely on (rock_39; T23)
    for a in an[:k[0]]:
        for d in member_decls(lines[a[0]:a[1] + 1], os.path.dirname(path)) if not a[3] else []:
            if d not in carried and d not in pre:
                carried.append(d)
    pre += [""] + carried if carried else []
    tail = lines[cut:]
    while tail and not tail[0].strip():
        tail.pop(0)
    old = "nonmatchings/%s\"" % tu
    tail = [l.replace(old, "nonmatchings/%s\"" % newtu) if INC_RE.match(l) else l for l in tail]
    for a in an[k[0]:]:  # role files moving to newtu: their INCLUDE_ASM folders name the new unit (C0070)
        if a[3]:
            with open(a[3][0]) as f:
                rl = f.read().split("\n")
            with open(a[3][0], "w") as f:
                f.write("\n".join(l.replace(old, "nonmatchings/%s\"" % newtu) if INC_RE.match(l) else l for l in rl))
    with open(path, "w") as f:
        f.write("\n".join(head) + "\n")
    with open(newpath, "w") as f:
        f.write("\n".join(pre + [""] + tail) + "\n")


def table_owner(fns, prog, lo, hi):
    """Start vram of the corpus function holding the first retail word of [lo, hi) (as table_runs), or None."""
    ws = retail_words(prog, lo, hi) if lo % 4 == 0 and hi > lo else []
    return next((v for v, (_, _, e) in fns.items() if ws and v <= ws[0][1] < e), None)


def opt_paths(root, prog, tu, newtu):
    """Every path carve_opt may write: the unit, its tail, the unit's role files, c_units, record, .mk, yaml."""
    src = os.path.join(root, "src", prog)
    out = [os.path.join(src, tu + ".c"), os.path.join(src, newtu + ".c")]
    if os.path.exists(out[0]):
        with open(out[0]) as f:
            out += [a[3][0] for a in anchors(f.read().rstrip("\n").split("\n"), src) if a[3]]
    return out + [cfg(root, p) for p in ("c_units.txt", "carve.%s.txt" % prog, "carve.%s.mk" % prog, prog + ".yaml")]


def resplit(root, prog):
    """Drop asm/<prog> and its split stamp: the next make re-splits (splat never deletes a moved function's .s; C0289)."""
    shutil.rmtree(os.path.join(root, "asm", prog), ignore_errors=True)
    stamp = os.path.join(root, "build", "split", prog + ".stamp")
    if os.path.exists(stamp):
        os.remove(stamp)


def run_log(root, prog, cmd):
    """rc of cmd run in root, output appended to .run/carve/gate.<prog>.log."""
    os.makedirs(os.path.join(root, ".run", "carve"), exist_ok=True)
    with open(os.path.join(root, ".run", "carve", "gate.%s.log" % prog), "a") as f:
        f.write("$ " + " ".join(cmd) + "\n")
        f.flush()
        return subprocess.run(cmd, cwd=root, stdout=f, stderr=subprocess.STDOUT).returncode


def gate_build(root, prog):
    """Re-split, clean rebuild of prog, `sha1sum -c config/check.<prog>.sha`: '' when green, else the failing step."""
    resplit(root, prog)
    if run_log(root, prog, ["make", "-s", "build/split/%s.stamp" % prog]):
        return "split"
    out = "build/rock/%s.bin" % prog[5:] if prog.startswith("rock_") else "build/" + prog
    objs = [os.path.join(dp, n) for dp, _, ns in os.walk(os.path.join(root, "build", "src", prog)) for n in ns
            if n.endswith(".c.o")]
    for p in objs + [os.path.join(root, "build", prog + ".elf"), os.path.join(root, out)]:
        if os.path.exists(p):
            os.remove(p)
    if run_log(root, prog, ["make", "-s", out]):
        return "build"
    return "sha" if run_log(root, prog, ["sha1sum", "-c", "config/check.%s.sha" % prog]) else ""


def gate_split(root, prog):
    """Re-split prog after a restore; rc."""
    resplit(root, prog)
    return run_log(root, prog, ["make", "-s", "build/split/%s.stamp" % prog])


def carve_opt_gated(root, prog, tu, vram, cflags):
    """carve_opt, then the gate: a red split/build/hash restores every written file byte-exact, re-splits and refuses
    `carve-red` (the gate is the arbiter; T23)."""
    newtu = segment.hexname(vram)
    saved = {}
    for p in opt_paths(root, prog, tu, newtu):
        saved[p] = None
        if os.path.exists(p):
            with open(p, "rb") as f:
                saved[p] = f.read()
    carve_opt(root, prog, tu, vram, cflags)
    step = gate_build(root, prog)
    if not step:
        print("CARVE opt GATE OK %s %s@0x%08X" % (prog, tu, vram))
        return
    for p, b in saved.items():
        if b is None:
            if os.path.exists(p):
                os.remove(p)
        else:
            with open(p, "wb") as f:
                f.write(b)
    rc = gate_split(root, prog)
    refuse("carve-red", "%s %s@0x%08X: %s red after the carve; restored%s" % (
        prog, tu, vram, step, "" if rc == 0 else ", re-split FAILED"))


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
        elif r[0] == "rodata" and r[3] == tu:  # rodata-follow (T23): rows are in TU function order, so a suffix moves
            f = table_owner(fns, prog, int(r[1], 16), int(r[2], 16))
            if f is not None and f >= vram:
                r[3] = newtu
    regenerate(root, prog, rec + [["opt", tu, "0x%08X" % vram, newtu] + cflags.split()])
    resplit(root, prog)  # the tail's INCLUDE_ASM .s regenerate at the next make (C0289)
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
            elif r[0] == "data" and len(r) == 4:  # T28.c1: kinds here; contiguity with the unit's tables below
                lo, hi = int(r[1], 16), int(r[2], 16)
                if r[3] not in cset or lo % 4 or hi <= lo or not data_adjacent(prog, lo, hi, r[3], rec, fns):
                    errs.append("%s data %s %s: not a 4-aligned run of c-unit TU %s touching one of its tables" % (
                        prog, r[1], r[2], r[3]))
                else:
                    n += 1
                    say("CARVE data OK %s %s-%s" % (prog, r[1], r[2]))
            elif r[0] == "block" and len(r) == 2:
                base = segment.read_programs(segment.BOUNDARIES)[prog][0]
                tus = text_tus(prog)
                src = "src/%s/%s.c (closure)" % (prog, tus[0][1])
                hit = layout.find_asm(prog, d_line(prog, base), root)
                dl = hit is not None and hit[2] == tus[0][1]
                sym = cfg(root, "symbols.%s.txt" % prog)
                dl = dl or os.path.exists(sym) and re.search(r"(?m)^%s = 0x%08X;[ \t]*//" % (d_line(prog, base), base),
                                                              open(sym).read()) is not None
                if prog == segment.EXE["name"] or int(r[1], 16) != min(v for v in fns if v > base) or dl:
                    errs.append("%s block %s: not the first text function, or %s still in %s or attributed in %s" % (
                        prog, r[1], d_line(prog, base), src, sym))
            else:
                errs.append("%s: malformed record row %s" % (prog, " ".join(r)))
        if prog != segment.EXE["name"] and any(r[0] in ("jtbl", "rodata", "data") for r in rec) and \
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
OVL = ["rock_04", "rock_01"]  # rock_04: D_800E9860 rodata block [0x800E9860, 0x800E9B30); rock_01: c unit, scratch
# copy loses its D_801EA000 line, no block (was: first TU asm; a c unit since T40.13.1)


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


def noncontig_target(root, prog):
    """First uncarved jtbl row lo of prog (address order) that carve_jtbl would refuse non-contiguous on the live carve
    record, probed without placing (T15.c3: a fixed address goes stale once a wave carves it); None when there is none."""
    rows = jtbl_rows(prog)
    blo, bhi, _ = rodata_block(root, prog, read_record(root, prog))
    _, jt, ro, _ = segment.read_carves(prog)
    carved = segment.carved_rodata(prog, jt, ro)
    fns = corpus(prog)
    for lo in sorted(rows):
        hi, func, _, note = rows[lo]
        fn = fns.get(func)
        if func is None or "label-inside-scan-table" in note or fn is None or jtbl_carved(prog, lo):
            continue
        try:
            tables = bridge(prog, lo, hi, fn[1], carved, rows, fns) or [(lo, hi, hi)]
            placement_refusals(prog, [(a, p) for a, _, p in tables], fn[1], carved, blo, bhi)
        except Refuse as e:
            if " non-contiguous " in str(e) + " ":
                return lo
    return None


def plant_target(fns):
    """(vram, tu, role path | None) of the self-test's opt carve: in the exe's units on the current tree (c_units order),
    the first chunk after a unit's first that is a C definition or a role file's first function (L-B, layout.py) and a
    corpus start of that unit; a mid-role function would refuse `role-split` by design."""
    byname = dict((n, (v, t)) for v, (n, t, _) in fns.items())
    src = os.path.join(SCRATCH, "src", EXE)
    for _, tu in layout.Tree(SCRATCH).units(EXE):
        with open(os.path.join(src, tu + ".c")) as f:
            lines = f.read().rstrip("\n").split("\n")
        for a in anchors(lines, src)[1:]:
            names = a[3][1] if a[3] else a[2] if not INC_RE.match(lines[a[0]]) and len(a[2]) == 1 else set()
            for n in sorted(names):
                if byname.get(n, (0, None))[1] == tu:
                    return byname[n][0], tu, a[3][0] if a[3] else None
    refuse("no-plant", "no unit of %s has a C definition or role file past its first chunk" % EXE)


def follow_target():
    """(prog, tu, vram) of the self-test's rodata-follow split, through the current layout (T16.c4): the first unit of
    [EXE] + OVL (c_units order) with a chunk as plant_target's whose start lies in (min, max] of the unit's carved
    `rodata` table owners, so tables stay and move; a split mid role file would refuse `role-split` by design."""
    tree = layout.Tree(SCRATCH)
    for prog in [EXE] + OVL:
        fns = corpus(prog)
        byname = dict((n, v) for v, (n, t, _) in fns.items())
        owners = {}
        for r in read_record(SCRATCH, prog):
            f = table_owner(fns, prog, int(r[1], 16), int(r[2], 16)) if r[0] == "rodata" else None
            if f is not None:
                owners.setdefault(r[3], []).append(f)
        src = os.path.join(SCRATCH, "src", prog)
        for _, tu in tree.units(prog):
            if not owners.get(tu):
                continue
            with open(os.path.join(src, tu + ".c")) as f:
                lines = f.read().rstrip("\n").split("\n")
            for a in anchors(lines, src)[1:]:
                names = a[3][1] if a[3] else a[2] if not INC_RE.match(lines[a[0]]) and len(a[2]) == 1 else set()
                for n in sorted(names):
                    v = byname.get(n)
                    if v is not None and fns[v][1] == tu and min(owners[tu]) < v <= max(owners[tu]):
                        return prog, tu, v
    refuse("no-plant", "no unit of %s has carved tables on both sides of a splittable chunk" % ", ".join([EXE] + OVL))


def self_test():
    ok = probe.plant_lookup("carve", EXE, 0x800429C4)
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
    if not jtbl_carved(EXE, 0x80011378):
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
    # was TU 32208's gap at 0x80011398 / 0x800113B0 (T35.c53), carved by W301; now probed from the live record (T15.c3)
    nc = noncontig_target(SCRATCH, EXE)
    t = nc is not None
    print("control non-contiguous target %s" % ("0x%08X" % nc if t else "NONE"))
    ok &= t and expect("non-contiguous", carve_jtbl, SCRATCH, EXE, nc)
    ok &= bridge_controls()
    hit01 = layout.find_asm("rock_01", d_line("rock_01", 0x801EA000), SCRATCH)  # unit or L-B role file (T16.c4)
    c01 = os.path.join(SCRATCH, hit01[0]) if hit01 else os.path.join(SCRATCH, "src", "rock_01", "1EA000.c")
    # plant: a first c unit without its D_<base> line
    with open(c01) as f:
        keep = [ln for ln in f if (INC_RE.match(ln) or [None, None])[1] != d_line("rock_01", 0x801EA000)]
    with open(c01, "w") as f:
        f.writelines(keep)
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
    _, jt0, ro0, _ = segment.read_carves(EXE)  # the 120A0 piece holding 0x8001004C (its jtbl/data rows widen it, T28.c1)
    p120 = [a for a, b, t in segment.carved_rodata(EXE, jt0, ro0) if t == "120A0" and a <= 0x8001004C < b]
    off120 = p120[0] - segment.EXE["rodata_lo"] + segment.EXE["header"] if p120 else -1
    d4 = d_line("rock_04", 0x800E9860)  # the overlay's data-chunk name, as carve itself spells it
    t = (d4 not in c4s and ["block", "0x800E9B30"] in read_record(SCRATCH, "rock_04")
         and "\n%s = 0x800E9860;\n" % d4 in open(cfg(SCRATCH, "symbols.rock_04.txt")).read()
         and "- [0x34, .rodata, E9860]\n" in y4 and "- [0x2D0, c, E9860]\n" in y4
         and "- [0x%X, .rodata, 120A0]\n" % off120 in open(cfg(SCRATCH, EXE + ".yaml")).read()
         and check(SCRATCH, quiet=True) == 0)
    print("control rodata-carve  %s" % ("placed" if t else "WRONG"))
    ok &= t
    t = jtbl_carved(EXE, 0x8001004C)  # planted (T35.c53): boundaries jtbl row inside the exe `rodata` row just placed
    print("control jtbl-in-rodata %s" % ("carved" if t else "WRONG"))
    ok &= t and expect("overlaps-carve", carve_jtbl, SCRATCH, EXE, 0x8001004C)
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
        f.write(c4s.replace("\n\n", "\n\n%s\n\n" % layout.asm_line("rock_04", "E9860", d4), 1))
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
    ok &= data_controls()
    fns = corpus(EXE)
    tgt, tu, role = plant_target(fns)  # through the current layout (T15.c2): never a fixed address
    nt = segment.hexname(tgt)
    print("control plant target %s 0x%08X %s%s" % (tu, tgt, fns[tgt][0], " (role file %s)" % role if role else ""))
    ok &= expect("not-a-start", carve_opt, SCRATCH, EXE, tu, tgt + 4, "")
    start = dict((n, v) for v, n in text_tus(EXE))[tu]
    ok &= expect("tu-start", carve_opt, SCRATCH, EXE, tu, start, "")
    global gate_build, gate_split  # gate (T23): an injected red hash restores every written file, refuses carve-red
    real_gate = (gate_build, gate_split)
    gate_build, gate_split = (lambda root, prog: "sha"), (lambda root, prog: 0)
    paths = opt_paths(SCRATCH, EXE, tu, nt)
    before = [open(p, "rb").read() if os.path.exists(p) else None for p in paths]
    t = expect("carve-red", carve_opt_gated, SCRATCH, EXE, tu, tgt, "-O0 -G0")
    gate_build, gate_split = real_gate
    t = t and before == [open(p, "rb").read() if os.path.exists(p) else None for p in paths]
    print("control opt-gate-restore %s" % ("restored" if t else "WRONG"))
    ok &= t
    os.makedirs(os.path.join(SCRATCH, "asm", EXE), exist_ok=True)  # stale split output a carve must drop (C0289)
    os.makedirs(os.path.join(SCRATCH, "build", "split"), exist_ok=True)
    open(os.path.join(SCRATCH, "asm", EXE, "stale.s"), "w").close()
    open(os.path.join(SCRATCH, "build", "split", EXE + ".stamp"), "w").close()
    carve_opt(SCRATCH, EXE, tu, tgt, "-O0 -G0")  # positive control: a C-definition chunk (or its role file) moves
    t = not os.path.exists(os.path.join(SCRATCH, "asm", EXE)) and \
        not os.path.exists(os.path.join(SCRATCH, "build", "split", EXE + ".stamp"))
    print("control opt-resplit   %s" % ("dropped" if t else "WRONG"))
    ok &= t
    src = os.path.join(SCRATCH, "src", EXE)
    with open(os.path.join(src, nt + ".c")) as f:
        new = f.read()
    with open(os.path.join(src, tu + ".c")) as f:
        head = f.read()
    f429 = fns[tgt][0]
    if role:  # a role file's first function: its include moves, its INCLUDE_ASM folders name the new unit
        inc = '#include "%s"' % os.path.relpath(role, src)
        moved = inc in new.split("\n") and inc not in head.split("\n") and \
            "nonmatchings/%s\"" % tu not in open(role).read()
    else:  # a C definition: it moves, the carried block between (T23) precedes it
        d = re.search(r"\n\n[^\n]*\b%s\s*\(" % f429, new)
        moved = d is not None and f429 not in new[:d.start()] and f429 not in head
    t = (new.startswith('#include "common.h"\n\n') and moved
         and "nonmatchings/%s\"" % tu not in new and "CFLAGS_%s := -O0 -G0" % nt in open(cfg(SCRATCH, "carve.%s.mk" % EXE)).read()
         and "%s %s" % (EXE, nt) in open(cfg(SCRATCH, "c_units.txt")).read())
    print("control opt-split     %s" % ("moved" if t else "WRONG"))
    ok &= t
    # rodata-follow (T23): a unit's carved rows split at a chunk between their owners: the later owners' rows move.
    # Target through the current layout (T16.c4): on L-B rock_04 ED3A4 sits mid role file (refuses role-split).
    p4, tu4, v4 = follow_target()
    n4 = segment.hexname(v4)
    print("control follow target %s %s 0x%08X" % (p4, tu4, v4))
    fns4 = corpus(p4)
    own = [(r[1], r[3], table_owner(fns4, p4, int(r[1], 16), int(r[2], 16)))
           for r in read_record(SCRATCH, p4) if r[0] == "rodata"]
    carve_opt(SCRATCH, p4, tu4, v4, "")
    got = [(r[1], r[3]) for r in read_record(SCRATCH, p4) if r[0] == "rodata"]
    want = [(lo, n4 if t == tu4 and f is not None and f >= v4 else t) for lo, t, f in own]
    lo1 = min([int(lo, 16) for lo, t in want if t == n4] or [0])
    blo = rodata_block(SCRATCH, p4, read_record(SCRATCH, p4))[0] - (segment.EXE["header"] if p4 == EXE else 0)
    t = got == want and {n4, tu4} <= {t for _, t in want} and \
        "- [0x%X, .rodata, %s]\n" % (lo1 - blo, n4) in open(cfg(SCRATCH, p4 + ".yaml")).read()
    print("control opt-rodata-follow %s" % ("moved" if t else "WRONG %s" % got))
    ok &= t
    ok &= preamble_control()
    ok &= role_controls()
    use_root(ROOT)
    if not ok:
        print("CARVE CONTROL FAILED")
        return 1
    print("CARVE CONTROL OK")
    return 0


def bridge_controls():
    """T11.c1: a jtbl carve bridging a gap of same-TU tables. Target through the record and boundaries (C0307): the
    first exe TU whose record rows are jtbl/rodata rows, one of them (the cut; any row, T11.c3) followed by a chain (>= 2)
    of tables of its dispatchers' TU (zero pad < alignment between); the scratch record keeps the TU's rows up to the cut,
    the chain's last table is carved. A gap dispatcher planted into another TU refuses non-contiguous; as is, one row per
    table."""
    global CORPUS
    rec, rows, fns = read_record(SCRATCH, EXE), jtbl_rows(EXE), corpus(EXE)
    tus = []
    for r in rec:
        if r[0] in ("jtbl", "rodata", "data") and r[-1] not in tus:
            tus.append(r[-1])
    found = None
    for t in tus:
        tr = sorted([r for r in rec if r[0] in ("jtbl", "rodata", "data") and r[-1] == t], key=lambda r: int(r[1], 16))
        if any(r[0] == "data" for r in tr):
            continue
        align = unit_align(EXE, t)
        for i, cut in enumerate(tr):
            if int(cut[1], 16) not in rows:
                continue
            # a rodata row's hi already carries its pad; a jtbl row ends at its boundaries hi
            chain, p = [], int(cut[2], 16) if cut[0] == "rodata" else rows[int(cut[1], 16)][0]
            while p in rows and rows[p][1] is not None and fns.get(rows[p][1], (0, None))[1] == t:
                chain.append(p)
                q = rows[p][0]
                while q not in rows and q - rows[p][0] < align and dict(retail_words(EXE, q, q + 4)).get(q) == 0:
                    q += 4
                p = q
            gap = [g for g in chain[:-1] if rows[g][1] != rows[chain[-1]][1]] if len(chain) >= 2 else []
            if gap:
                found = (t, tr[:i + 1], tr[i + 1:], chain, gap)
                break
        if found:
            break
    if not found:
        print("control bridge target  NOT FOUND")
        return False
    t, kept, tr, chain, gap = found
    print("control bridge target  %s 0x%08X <- 0x%08X (%d gap tables)" % (t, int(kept[-1][1], 16), chain[-1], len(chain) - 1))
    regenerate(SCRATCH, EXE, [r for r in rec if r not in tr])
    real, CORPUS = CORPUS, os.path.join(SCRATCH, "functions.jsonl")
    with open(real) as f, open(CORPUS, "w") as g:
        for line in f:
            j = json.loads(line)
            if j["prog"] == EXE and int(j["vram"], 16) == rows[gap[0]][1]:
                j["tu"] = "PLANT"
                line = json.dumps(j) + "\n"
            g.write(line)
    ok = expect("non-contiguous", carve_jtbl, SCRATCH, EXE, chain[-1])  # a foreign-TU table in the gap
    CORPUS = real
    carve_jtbl(SCRATCH, EXE, chain[-1])
    got = sorted(int(r[1], 16) for r in read_record(SCRATCH, EXE) if r[0] in ("jtbl", "rodata") and r[-1] == t)
    t2 = got == [int(r[1], 16) for r in kept] + chain and check(SCRATCH, quiet=True) == 0
    print("control jtbl-bridge    %s" % ("placed" if t2 else "WRONG %s" % " ".join("0x%08X" % v for v in got)))
    regenerate(SCRATCH, EXE, rec)
    return ok and t2


def data_controls():
    """T28.c1: a same-unit run between two of a unit's exe tables (a middle `rodata` row dropped, a C reference planted
    in the unit) carves `data` as one block; the same run referenced from another unit's C refuses `foreign-rodata`.
    The record and the C files are restored after."""
    rec0 = read_record(SCRATCH, EXE)
    ro = [(int(r[1], 16), int(r[2], 16), r[3]) for r in rec0 if r[0] == "rodata"]
    mid = [m for m in ro if any(a[1] == m[0] and a[2] == m[2] for a in ro) and any(b[0] == m[1] and b[2] == m[2] for b in ro)]
    if not mid:
        print("control data-plant    WRONG: no unit with three adjacent exe rodata rows")
        return False
    lo, hi, tu = mid[0]
    other = [t for _, t in layout.Tree(SCRATCH).units(EXE) if t != tu][0]
    paths = [os.path.join(SCRATCH, "src", EXE, x + ".c") for x in (tu, other)]
    saved = [open(x).read() for x in paths]
    regenerate(SCRATCH, EXE, [r for r in rec0 if r[:3] != ["rodata", "0x%08X" % lo, "0x%08X" % hi]])
    with open(paths[0], "a") as f:
        f.write("extern s32 D_%08X[];\n" % lo)
    with open(paths[1], "a") as f:
        f.write("extern s32 D_%08X[];\n" % lo)
    ok = expect("foreign-rodata", carve_data, SCRATCH, EXE, lo, tu, hi)
    with open(paths[1], "w") as f:
        f.write(saved[1])
    carve_data(SCRATCH, EXE, lo, tu, hi)
    _, jt, ro2, _ = segment.read_carves(EXE)
    pieces = [(a, b) for a, b, t in segment.carved_rodata(EXE, jt, ro2) if t == tu]
    t = (["data", "0x%08X" % lo, "0x%08X" % hi, tu] in read_record(SCRATCH, EXE) and len(pieces) == 1
         and pieces[0][0] < lo and hi < pieces[0][1] and check(SCRATCH, quiet=True) == 0)
    print("control data-merge    %s %s 0x%08X-0x%08X" % ("placed" if t else "WRONG", tu, lo, hi))
    with open(paths[0], "w") as f:
        f.write(saved[0])
    regenerate(SCRATCH, EXE, rec0)
    return ok and t


def preamble_control():
    """T23: a declaration between chunks of the head, and a member body's file-scope extern/prototype (the block's
    #defines applied), reach the tail's preamble (a comment there does not); the head is written unchanged."""
    d = os.path.join(SCRATCH, "src", "Q")
    os.makedirs(d, exist_ok=True)
    unit, new = os.path.join(d, "unit.c"), os.path.join(d, "C0000.c")
    with open(os.path.join(d, "body.c"), "w") as f:  # a member body whose file-scope extern later bodies rely on
        f.write('#include "common.h"\n#include "mmx6/x4.h"\n'
                "extern s16 D_Y;\nvoid func_q(s32);\n#define MU s32\nMU func_m(void);\n#undef MU\n\n"  # MU: its own
                "void func_q(s32 a) {\n    D_Y = a;\n}\n")  # macro, so func_m's prototype is not carried
    head = ['#include "common.h"', "", layout.asm_line("Q", "unit", "func_a"), "", "extern u8 D_X;",
            "void func_b(void);", "", "// func_c: its doc comment stays with it", "void func_c(void) {", "}", "",
            "#define D_Y D_Y_s16", "#define func_q func_e", '#include "body.c"', "#undef D_Y", "#undef func_q"]
    with open(unit, "w") as f:
        f.write("\n".join(head + ["", layout.asm_line("Q", "unit", "func_d")]) + "\n")
    split_c(unit, new, "func_d", "unit", "C0000")
    t = (open(unit).read() == "\n".join(head) + "\n" and open(new).read() == "\n".join(
        ['#include "common.h"', "", "extern u8 D_X;", "void func_b(void);", "", '#include "mmx6/x4.h"', "extern s16 D_Y_s16;",
         "void func_e(s32);", "", layout.asm_line("Q", "C0000", "func_d")]) + "\n")
    print("control opt-preamble  %s" % ("kept" if t else "WRONG"))
    return t


def role_controls():
    """Second pass (T5): split_c on a planted thin unit over two role files (scratch src/P/, never src/): a split point
    inside a role file refuses `role-split`, the first chunk `tu-start`; the second role file's first function splits
    at its include, the moved role file's INCLUDE_ASM folders renamed to the new unit."""
    d = os.path.join(SCRATCH, "src", "P")
    thin, new, ra, rb = (os.path.join(d, x) for x in ("thin.c", "B0000.c", "sys/a.c", "sys/b.c"))
    plant = {thin: '#include "common.h"\n\n#include "sys/a.c"\n\n#include "sys/b.c"\n',
             ra: "%s\n\nvoid func_a2(void) {\n}\n" % layout.asm_line("P", "thin", "func_a1"),
             rb: "%s\n\n%s\n" % (layout.asm_line("P", "thin", "func_b1"), layout.asm_line("P", "thin", "func_b2"))}
    os.makedirs(os.path.dirname(ra), exist_ok=True)
    for p, t in plant.items():
        with open(p, "w") as f:
            f.write(t)
    print("control role-tree pass: thin unit %s over sys/a.c sys/b.c" % os.path.relpath(thin, SCRATCH))
    ok = expect("role-split", split_c, thin, new, "func_b2", "thin", "B0000")
    ok &= expect("role-split", split_c, thin, new, "func_a2", "thin", "B0000")
    ok &= expect("tu-start", split_c, thin, new, "func_a1", "thin", "B0000")
    split_c(thin, new, "func_b1", "thin", "B0000")
    t = (open(thin).read() == '#include "common.h"\n\n#include "sys/a.c"\n'
         and open(new).read() == '#include "common.h"\n\n#include "sys/b.c"\n'
         and open(rb).read() == plant[rb].replace("nonmatchings/thin\"", "nonmatchings/B0000\"") and open(ra).read() == plant[ra])
    print("control role-opt-split %s" % ("moved" if t else "WRONG"))
    return ok and t


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
        if len(argv) == 3 and argv[0] == "data":
            carve_data(ROOT, argv[1], int(argv[2], 16))
            return 0
        if len(argv) in (3, 5) and argv[0] == "rodata" and (len(argv) == 3 or argv[3] == "--bytes"):
            carve_rodata(ROOT, argv[1], int(argv[2], 16), int(argv[4], 0) if len(argv) == 5 else None)
            return 0
        gate = argv[-1:] == ["--gate"]
        args = argv[:-1] if gate else argv
        if len(args) in (4, 6) and args[0] == "opt" and (len(args) == 4 or args[4] == "--cflags"):
            (carve_opt_gated if gate else carve_opt)(ROOT, args[1], args[2], int(args[3], 16),
                                                       args[5] if len(args) == 6 else "")
            return 0
    except Refuse as e:
        print(e)
        return 1
    print(__doc__.strip())
    return 2


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
