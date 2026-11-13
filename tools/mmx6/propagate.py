#!/usr/bin/env python3
"""propagate.py -- instantiate a shared body at every member of its dup class, byte-gate each (container, stdlib).

  propagate.py <dup key> [--dry-run]
      -> the key's exemplar row of config/dedup_registry.txt names the shared body; members from
         build/census/classes.jsonl. Per member (prog, vram order): defines `<exemplar name> -> <member corpus name>`
         and `D_<exemplar table> -> D_<member table>` (table address = the lui/lw (or addiu) pair of the member's
         retail words, probe.retail_words; the exemplar needs none; only when the body names D_<exemplar table>,
         else the name define alone; an identity table define is dropped when the unit's own `#define` lines directly
         above the member's INCLUDE_ASM alias that name), then bank.ladder R1-R4 (R1 probes a scratch
         wrapper, R2 writes the define/include/undef block; a unit already holding it is re-gated, not re-edited).
         R5 (bank.rung5: clean rebuild + hash, body sha1, typecheck, sig) once per program, then an unmasked compare of
         each member's linked extent vs retail; on a program R5 failure every member is retried alone, failing
         members restored. One line per member `<prog:vram> gated|refused <reason>`, last
         `PROPAGATE <key> gated <m> of <M> members` (rc 0 iff m = M); registry rows appended/updated in place.
         A member already holding a gated row of the key (its own bank, an earlier run) is not re-gated: row kept, counted.
         Recovery (real run only, T40.21.c2): an R4 `rodata needs placement (+N bytes)` -> gate.py's rodata step
         (carve.py rodata, re-split + rebuild, R1-R4 again); an R2 `does not compile` with a tudecl diagnostic -> the
         member's own copy src/shared/<prog>/<func>.c of the body (defines applied), tudecl variant A then B, R1-R4 under
         the same defines; a stop restores the carve files + re-splits / deletes the copy. Gated: `gated <reason> via
         tudecl|rodata`, the copy as the row's shared path; refused: `R<k>: <cause>; tudecl|rodata <cause>`.
         --repair declunify (3.1 T3, bank.repair_arg; off = unchanged; dry runs too): an R2 `does not compile` (after
         tudecl in a real run) whose log names `conflicting types for X` / `too few arguments to function X` ->
         declunify_step: bank.declunify edits the member's TU closure (never the body; cross-key edits through the R3
         guard, else `R2: declunify <cause>`), R1-R4 again; gated `... via declunify`, refused `...; declunify <note>`.
         T3.c2: also `redefinition of X` (DU_DEF_X include guards) and a body-side rewrite when the body's declaration
         is the looser one (bank.declunify; the exemplar's R1 re-probed); R5 (program_r5, refusecause) through
         rung5_unify: an `undefined reference to U` -> linkunify (`__asm__("U = N");` in that unit), rung5 again.
         --repair rolefeed (3.1 T4; dry runs too): a member whose shared path is outside src/shared/ and that stops
         on a path cause (bank.rf_due: R1 compile errors, R1/R2 `already defined`; never the exemplar's own re-gate,
         so a run extracts only for a member) -> rolefeed_step: bank.rolefeed
         moves the exemplar into layout.new_body (includers' objects unchanged), R1-R4 again on it (R1 through the
         exemplar's unit); gated `... via rolefeed` (row path the new body; a real run re-points the key's rows on the
         old path, write_registry), refused `<new stop>; rolefeed <note>`.
         --repair relocdef (3.1 T5; dry runs too): per member, after the name/table defines, reloc_defines: the
         exemplar object's R26 / HI16+LO16 relocations aligned word by word with the exemplar's and member's retail
         words (C0127); a symbol S of the body whose target moves by one delta maps to the member symbol at its
         address + delta (addend kept; name from build/<prog>.map, else func_/D_%08X); none for ex_name, the D_ table,
         an identity, a unit alias (C0225) or two deltas (`RELOCDEF conflict` in the bank log). Gated `define ... via
         relocdef` (the record's `reloc`), refused `<stop>; relocdef S=T ...`; off = unchanged.
         --repair unitcut (3.1 T6; dry runs too): a member whose shared path is the exemplar's whole unit holding other
         code (bank.uc_due) -> before its gate, rolefeed_step under that name: the exemplar cut to its own body, R1-R4
         on it; gated `... via unitcut` (rows re-pointed as rolefeed), refused `<stop>; unitcut <note>`.
         R5 (3.1 T6, always): a red hash with a gated member build/<prog>.map places away from its corpus vram
         (placement) -> `linked extent differs from retail (<pv> placed 0x<a> not 0x<vram>)`.
      --dry-run: the same gates in scratch copies of the tree (.run/propagate/tree/w<i>, one per worker process;
         programs run in parallel, output printed in program order); src/ and the registry are never
         written (their sha1 checked unchanged at the end); last `PROPAGATE DRY-RUN <key> gated <m> of <M> members`.
      --dry-run --expect-registry: the same dry run, rc 0 iff every member's verdict agrees with its registry row of the
         key (gated row -> gated, refused row -> refused, any reason; no row -> must gate, as plain --dry-run); each
         disagreement `PROPAGATE DRIFT <key> <prog:vram> <registry status> -> <dry-run verdict>` (rc 1). Members with a
         gated row are skipped (counted gated) as in every run; the exemplar is re-gated (a c/c-empty exemplar's
         preflight refusal agrees with its `gated exemplar` row).
  propagate.py --dry-run --expect-registry --keys-from FILE|-
      -> grouped dry run of many keys (one per line; T41.1): plan() makes units (key, program) of each key's run members
         (as the per-key mode: gated-row members skipped); a unit with a member holding a refused registry row of its
         key is scheduled isolated (a hint, never a verdict). Worker trees .run/propagate/tree/w<i> made once for the
         run (count capped: 2x the copy's blocks each, in half the free disk), one program at a time per tree: isolated units first, each exactly
         the per-key run_prog from the pristine program, then restored (edits undone + rebuild); then the group: R1-R4
         per member of every other unit, one program_r5 over all their gated members; green -> those verdicts stand.
         A group R1-R4 refusal (preflight excepted) -> restore, re-run those units isolated. A red group R5 (T4.c1) ->
         restore, bisect the other units (key order, halves): each half re-gated from the restored program under its
         own program_r5, green -> its verdicts stand, red -> split again, a red single unit re-run isolated (a grouped
         verdict stands only under a green R5 that includes its unit). Per program `PROPAGATE GROUP <prog> units <u>
         isolated <i> fallback yes|no reisolated <r> r5 <k> xkey <x> wall <s>s` (r: units re-run isolated after the plan, k:
         group program_r5 calls, x: cross-key edits bank.ladder R3 accepted byte-neutral, summed over the program's
         ladder runs, T2.c3), every 60 s before it `PROPAGATE PROGRESS <prog> units <d> of <u> wall <s>s` (d: units
         gated or run so far, flushed, 3.1 T23); per key the per-key lines (member lines, `PROPAGATE DRY-RUN <key> gated m of n members`, DRIFT lines); last
         `PROPAGATE DRY-RUN GROUPED <k> of <K> keys; drift <d>`, rc 0 iff every key passes, no DRIFT, src/ + registry
         sha1 unchanged.
  propagate.py --check
      -> per registry row the member's dup key recomputed from the built object (census.read_words + dup_key); refusal
         lines `REGISTRY refused drift|not in class|missing member ...` (rc 1) or `REGISTRY OK <r> rows` (rc 0).
         A row whose reason starts `family` (tools/mmx6/family_remap.py) is checked on census.family_key instead:
         drift vs its row key, not in that family class; exempt from the missing-member rule.
  propagate.py --self-test
      -> scratch registry/classes copies (.run/propagate/selftest/): every class member rowed -> OK; a row whose built
         key differs from its row key (drift), one member row dropped (missing member), a row for a function outside
         the class (not in class) -> each refused; --expect-registry on planted rows/verdicts: a refused row refused ->
         agrees, a gated row refused -> DRIFT, a c-empty exemplar refused -> agrees; a planted unit alias above a member's
         INCLUDE_ASM -> the identity define dropped (again on a layout.role_tree plant of that unit: `role-tree control
         unit alias`); grouped (plan on planted rows, planted verdicts): a gated exemplar
         row refused inside a 2+-key group -> DRIFT, rc 1; a refused member row -> its unit isolated, agrees, rc 0;
         exemplar row removed -> planned with the rows' named exemplar; rows disagreeing on it -> setup error;
         mark_inherited on a planted body (pin near column 80, a goto) -> standalone markers above, none trailing,
         psxd_floor 0 unmarked, again after a second pass of the repo clang-format; declunify_control (3.1 T3): a
         `conflicting types` and a `too few arguments` plant refused with the switch off, gated via declunify with it
         on (gate stubbed by the planted unit's real compile); T3.c2 adds body side, redefinition and link plants
         (link: rung5 stubbed by make + ld); rolefeed_control (3.1 T4): a role file opening with INCLUDE_ASM and a
         whole-unit same-program duplicate, each refused path off, gated via rolefeed on, gated off again after on,
         the exemplar object's bytes equal; relocdef_control (3.1 T5): a planted compiled body (an R26 callee, a
         HI16/LO16 store at D+0xA), retail words synthesized: rename, identity, unit alias, two-delta conflict, each
         off -> the name define only, on -> the expected reloc defines; unitcut_control (3.1 T6): a member fed a whole
         unit with a predecessor (ld-linked alone, its map): off placed away from its vram, on via unitcut at it. Ends `PROPAGATE CONTROL OK` (rc 0), else rc 1.
Firewall G12: names, addresses, counts and hashes of our own files only.
"""
import argparse
import hashlib
import json
import math
import multiprocessing
import os
import re
import shutil
import subprocess
import sys
import threading
import time

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import bank  # noqa: E402
import census  # noqa: E402
import layout  # noqa: E402
import probe  # noqa: E402

CLASSES = "build/census/classes.jsonl"
FUNCS = "build/corpus/functions.jsonl"
SCRATCH = ".run/propagate"
TREE = SCRATCH + "/tree"  # the dry run's worker trees TREE/w<i>
WORKERS = os.cpu_count() or 1
COPY = ("Makefile", "mk", "include", "config", "src", "tools", "asm", "build")  # the dry run's scratch tree
LINK = ("extracted",)  # read-only inputs
# build/ subtrees left out of each tree (T41.1.c3): no gating path (probe, bank.ladder, bank.rung5 incl. typecheck.py
# --all + sig.py --rescan, extent_same, mk/ rules) reads or writes them. build/dumps (115 MB post-fleet): written only by
# dumps.py / repro.py (OUT = "build/dumps"; `make dumps`, th-dumps, th-repro); probe.py uses only dumps.recipe (a
# `make -n` of the C rule, no I/O under OUT); bank/census/typecheck/sig/carve, Makefile and mk/ name no build/dumps.
# build/sig stays copied: sig.py --rescan reads and rewrites build/sig/{sigs,twins}.jsonl.
SKIP = ("build/dumps",)
TREE_GROW = 64 << 20  # a tree's growth over a run: T41.1.c1 measured 68 -> 121 MB per tree (+53 MB), rounded up
TREE_RESERVE = 300 << 20  # free disk kept back when sizing the tree count
LOAD_OPS = (0x23, 0x09)  # lw, addiu: the %lo half of the table address
_KEYS = {}  # (prog, vram) -> built dup key (or None), shared by --check calls
_FAMS = {}  # (prog, vram) -> built family key (or None), filled with _KEYS


def pv(m):
    return f"{m[0]}:0x{m[1]:08X}"


def parse_pv(s):
    p, _, v = s.rpartition(":")
    return p, int(v, 16)


def load_classes(path=CLASSES, kind="dup"):
    """{<kind> key: [(prog, vram)]}."""
    out = {}
    with open(path) as f:
        for line in f:
            c = json.loads(line)
            if c["kind"] == kind:
                out[c["key"]] = sorted((p, int(v, 16)) for p, v in c["members"])
    return out


def corpus_rows():
    with open(FUNCS) as f:
        return {(r["prog"], int(r["vram"], 16)): r for r in map(json.loads, f)}


def registry_rows(path=bank.REGISTRY):
    """[(line index, [key, exemplar, shared path, member, state, reason])] of the registry's data lines."""
    out = []
    if os.path.exists(path):
        with open(path) as f:
            for i, line in enumerate(f.read().split("\n")):
                t = line.split(None, 5)
                if line.strip() and not line.startswith("#") and len(t) >= 5:
                    out.append((i, t + [""] * (6 - len(t))))
    return out


def table_addr(words):
    """Address of the first lui + following lw/addiu pair in words, or None. Switch rolefeed (3.1 T4.c2): the pair's
    base register is the lui's rt, so a `li rt, n` (addiu rt, $zero, n) after the lui is not its %lo half."""
    hi, rt, strict = None, None, "rolefeed" in bank.REPAIR
    for w in words:
        if hi is None and w >> 26 == 0x0F:
            hi, rt = (w & 0xFFFF) << 16, (w >> 16) & 0x1F
        elif hi is not None and w >> 26 in LOAD_OPS and (not strict or (w >> 21) & 0x1F == rt):
            lo = w & 0xFFFF
            return (hi + (lo - 0x10000 if lo & 0x8000 else lo)) & 0xFFFFFFFF
    return None


def placement(prog, row):
    """`placed 0x<a> not 0x<vram>` when build/<prog>.map (refusecause.map_addrs, C0425) gives the member's name only
    addresses away from its corpus vram (a: the nearest), else '' (at its vram, or not in the map) (3.1 T6)."""
    import refusecause as rc  # lazy: refusecause imports this module
    vram = int(row["vram"], 16)
    try:
        ats = rc.map_addrs(prog, row["name"])
    except OSError:
        return ""
    if not ats or vram in ats:
        return ""
    return f"placed 0x{min(ats, key=lambda a: abs(a - vram)):08X} not 0x{vram:08X}"


def extent_same(prog, row):
    """Linked bytes of the member's extent == retail bytes (unmasked); False when the map places it away (placement)."""
    if placement(prog, row):
        return False
    target, seg_start, seg_vram = probe.yaml_layout(prog)
    vram = int(row["vram"], 16)
    off, n = seg_start + vram - seg_vram, int(row["end"], 16) - vram
    with open(target, "rb") as f:
        f.seek(off)
        want = f.read(n)
    with open(bank.bin_out(prog), "rb") as f:
        f.seek(off)
        got = f.read(n)
    return len(want) == n and got == want


def unit_aliases(prog, tu, func, name, root="src"):
    """True when the `#define` lines directly above func's INCLUDE_ASM line (layout.asm_line) in <root>/<prog>/<tu>.c
    or a file of its #include closure (a role file) define name (T40.c1)."""
    at, todo, seen = layout.asm_line(prog, tu, func), [f"{root}/{prog}/{tu}.c"], set()
    while todo:
        p = todo.pop(0)
        if p in seen:
            continue
        seen.add(p)
        try:
            with open(p) as f:
                lines = f.read().split("\n")
        except OSError:
            continue
        for i, line in enumerate(lines):
            m = layout.INC_RE.match(line)
            if m:
                todo.append(os.path.normpath(os.path.join(os.path.dirname(p), m.group(1))))
            if line == at:
                j = i - 1
                while j >= 0 and lines[j].startswith("#define "):
                    if lines[j].split()[1] == name:
                        return True
                    j -= 1
    return False


def ex_obj(ex, tu):
    """The exemplar's built object (relocdef reads its relocations)."""
    return f"build/src/{ex[0]}/{tu}.c.o"


_MAPS = {}  # build/<prog>.map path -> (mtime, {address: least symbol name}) (relocdef's member names)


def map_names(prog):
    import refusecause as rc  # lazy: refusecause imports this module
    p = f"build/{prog}.map"
    if not os.path.isfile(p):
        return {}
    t = os.path.getmtime(p)
    if _MAPS.get(p, (None,))[0] != t:
        _MAPS[p] = (t, dict(rc.read_map(prog)[0]))
    return _MAPS[p][1]


def reloc_defines(ctx, prog, r, log):
    """Repair switch relocdef (3.1 T5): [(S, member name)] for member r (its corpus row in prog). The exemplar object's
    relocations of ex_name (ex_obj, refusecause.obj_relocs) aligned word by word with the exemplar's and the member's
    retail words (C0127): per R26 / HI16+LO16 word, delta = member target - exemplar target (refusecause.target); S
    maps to the member symbol at its exemplar address (exemplar target - the object word's addend) + delta, so a
    `D_X+0xA` maps through D_X. Name: the exact-address symbol of build/<prog>.map (read_map's least name), else
    func_%08X (an R26) or D_%08X. Kept when S is a word of the body, not ex_name nor the D_ table already defined,
    delta != 0, the member unit does not alias S (unit_aliases, C0225), and all of S's words agree on one delta (else
    no define, a `RELOCDEF conflict` line in the bank log)."""
    import refusecause as rc  # lazy: refusecause imports this module
    ex, ex_name, ex_tab, src, rows = ctx[:5]
    obj = ex_obj(ex, rows[ex]["tu"])
    try:
        rel, ow = rc.obj_relocs(obj, ex_name), probe.elf_function(obj, ex_name)[0]
        ew, mw = probe.retail_words(ex[0], ex_name), probe.retail_words(prog, r["name"])
    except (Exception, SystemExit):
        return []
    with open(src) as f:
        body = f.read()
    seen, mv = {}, int(r["vram"], 16)
    for i, (kind, s) in sorted(rel.items()):
        pair = rc.partner(rel, i) if kind in (5, 6) else None
        if kind not in (4, 5, 6) or (kind != 4 and pair is None):
            continue
        et, mt = rc.target(ew, i, kind, pair, ex[1]), rc.target(mw, i, kind, pair, mv)
        if et is None or mt is None or i >= len(ow):
            continue
        add = (ow[i] & 0x03FFFFFF) << 2 if kind == 4 else rc.target(ow, i, kind, pair, 0)
        seen.setdefault(s, {})[(mt - et) & 0xFFFFFFFF] = ((mt - add) & 0xFFFFFFFF, kind)
    out, names = [], None
    for s in sorted(seen):
        if (not re.fullmatch(r"[A-Za-z_]\w*", s) or s == ex_name or (ex_tab is not None and s == f"D_{ex_tab:08X}")
                or not re.search(rf"\b{s}\b", body)):
            continue
        if len(seen[s]) > 1:
            os.makedirs(bank.LOGDIR, exist_ok=True)
            with open(os.path.join(bank.LOGDIR, log + ".log"), "a") as f:
                f.write(f"RELOCDEF conflict {s} deltas {' '.join(f'{d:#x}' for d in sorted(seen[s]))}\n")
            continue
        (d, (addr, kind)), = seen[s].items()
        if not d or unit_aliases(prog, r["tu"], r["name"], s):
            continue
        names = map_names(prog) if names is None else names
        out.append((s, names.get(addr) or (f"func_{addr:08X}" if kind == 4 else f"D_{addr:08X}")))
    return out


def tree_sha(paths):
    h = hashlib.sha1()
    for top in paths:
        for d, dirs, files in sorted(os.walk(top)) if os.path.isdir(top) else [("", [], [top])]:
            dirs.sort()
            for name in sorted(files):
                p = os.path.join(d, name)
                h.update(p.encode() + b"\0")
                with open(p, "rb") as f:
                    h.update(f.read())
    return h.hexdigest()


# ---- propagate -----------------------------------------------------------------------------------------------------

def gate(prog, vram, src, defines, log):
    """(member record or None, reason); R1-R4 of one member, its edits kept on success, restored on a stop."""
    r, func, cause = bank.preflight(prog, vram, src, defines)
    if cause:
        return None, f"refused preflight: {cause}"
    saved = {}
    try:
        h1 = bank.ladder(prog, vram, src, func, r["tu"], saved, log, defines, r5=False)
    except (bank.Stop, SystemExit) as e:
        rung, why = (e.rung, e.cause) if isinstance(e, bank.Stop) else (1, f"probe error: {e}")
        bank.restore(saved)
        bank.sh(["make", "-s", "-B", f"build/src/{prog}/{r['tu']}.c.o"], log)  # the next member's pre-bank object
        return None, f"refused R{rung}: {why}"
    return dict(prog=prog, vram=vram, row=r, defines=defines, saved=saved, h1=h1, src=src, via="", carved=False), ""


def resplit(prog, log):
    """Re-split + rebuild prog in this tree (gate.resplit without the snapshot's hardlink break); rc."""
    return bank.sh(["make", "-s", f"build/split/{prog}.stamp"], log) or bank.rebuild(prog, log)


def log_size(log):
    p = os.path.join(bank.LOGDIR, log + ".log")
    return os.path.getsize(p) if os.path.isfile(p) else 0


def log_tail(log, at):
    p = os.path.join(bank.LOGDIR, log + ".log")
    if not os.path.isfile(p):
        return ""
    with open(p, "rb") as f:
        f.seek(at)
        return f.read().decode(errors="replace")


def gate_member(prog, vram, src, defines, log, rec, ex=None):
    """gate(); when rec (real run, T40.21.c2) gate.py's recovery steps on a stop: R4 `rodata needs placement (+N
    bytes)` -> rodata_step, R2 `does not compile` -> tudecl_step. A recovered record's saved covers its copy/carve.
    ex: (exemplar prog, function) for declunify's exemplar R1 check of a body edit (T3.c2)."""
    at = log_size(log)
    if ex is not None and defines and bank.uc_due(ex, src):  # unitcut (3.1 T6): members fed the exemplar only
        return rolefeed_step(prog, vram, src, defines, log, f"refused R5: whole unit {src}", ex, "unitcut")
    g, why = gate(prog, vram, src, defines, log)
    if g is None and ex is not None and defines and "rolefeed" in bank.REPAIR and \
            bank.rf_due(prog, vram, src, defines, why, log_tail(log, at)):  # rolefeed (3.1 T4): members, not ex
        return rolefeed_step(prog, vram, src, defines, log, why, ex)
    unify = "declunify" in bank.REPAIR and why.startswith("refused R2: ") and " does not compile " in why
    if g is not None or not (rec or unify):
        return g, why
    if not rec:  # repair switch declunify (3.1 T3): also in dry runs
        return declunify_step(prog, vram, src, defines, log, log_tail(log, at), why, ex)
    import gate as gm  # lazy: gate.py imports this module
    mo = gm.RODATA_RE.match(why[len("refused R4: "):]) if why.startswith("refused R4: ") else None
    if mo:
        return rodata_step(prog, vram, src, defines, log, int(mo.group(1)), why)
    if why.startswith("refused R2: ") and " does not compile " in why:
        tail = log_tail(log, at)
        g, w = tudecl_step(prog, vram, src, defines, log, tail, why)
        return declunify_step(prog, vram, src, defines, log, tail, w, ex) if g is None and unify else (g, w)
    return g, why


def rolefeed_step(prog, vram, src, defines, log, why, ex, via="rolefeed"):
    """Repair switch `rolefeed` (3.1 T4): bank.rolefeed moves the exemplar ex = (prog, function) out of src into its
    own body (its includers' objects unchanged), then R1-R4 again on that body (R1 through the exemplar's unit, R2's
    block including the new body only). Gated: via rolefeed, the record's src the new body, its saved undoing the
    extraction too. Refused: `<the new stop>; rolefeed <note>` (the extraction restored, its includers and the
    member's unit rebuilt), or `<why>; rolefeed <cause>` when nothing was extracted. via `unitcut` (3.1 T6, before
    any gate): the same under that name, the body with src's preamble (bank.rolefeed preamble); nothing extracted -> the plain gate on src, a refusal `...; unitcut <cause>`."""
    saved = {}
    try:
        new, note, objs = bank.rolefeed(ex, src, saved, log, via == "unitcut")
    except bank.Stop as e:
        if via == "unitcut":
            g, w = gate(prog, vram, src, defines, log)
            return g, (w and f"{w}; unitcut {e.cause}")
        return None, f"{why}; rolefeed {e.cause}"
    g, w = gate(prog, vram, new, defines, log)
    if g is not None:  # the extraction snapshot predates the ladder's edits: it wins on shared paths
        return dict(g, saved={**g["saved"], **saved}, via=via, first=why), ""
    bank.restore(saved)
    for o in objs + [unit_of(prog, vram)[1]]:
        if os.path.isfile(o) or o in objs:
            bank.sh(["make", "-s", "-B", o], log)
    return None, f"{w}; {via} {note}"


def unit_of(prog, vram):
    """(unit .c, its object) of the member's corpus row (declunify_control stubs it)."""
    tu = bank.corpus_row(prog, vram)["tu"]
    return f"src/{prog}/{tu}.c", f"build/src/{prog}/{tu}.c.o"


def declunify_step(prog, vram, src, defines, log, tail, why, ex=None):
    """Repair switch `declunify` (3.1 T3): bank.declunify on the member's TU closure against the R2 diagnostics (tail),
    then R1-R4 again; a cross-key stop -> `R2: declunify <cause>`; on a gate stop its edits restored and the unit
    (and the edited files' built includers) rebuilt. Gated: via declunify."""
    unit, unit_o = unit_of(prog, vram)
    saved = {}
    try:
        k, note = bank.declunify(unit, src, defines, tail, saved, log, ex)
    except bank.Stop as e:
        return None, f"refused R2: {e.cause}"
    if not k:
        return None, f"{why}; declunify {note}"
    g, w = gate(prog, vram, src, defines, log)
    if g is not None:  # the unify snapshot predates the ladder's edits: it wins on shared paths
        return dict(g, saved={**g["saved"], **saved}, via="declunify", first=why), ""
    bank.restore(saved)
    inc = layout.includers(os.getcwd())
    objs = {f"build/src/{q}/{t}.c.o" for p in saved for q, t in inc.get(os.path.relpath(p), [])}
    for o in sorted(objs | {unit_o}):
        if os.path.isfile(o):
            bank.sh(["make", "-s", "-B", o], log)
    return None, f"{why}; declunify stop {short(w)}"


LINK_RE = re.compile(r"^(?:\S+: )?(\S+?):\([^)]*\): undefined reference to [`'‘](\w+)['’]", re.M)
ALIAS = {}  # link_alias's index of the corpus and dup classes, built once per process


def link_alias(prog, name):
    """prog's corpus name of the function named name elsewhere (any program; same dup class), when exactly one."""
    if not ALIAS:
        rows, of = corpus_rows(), {}
        for ms in load_classes().values():
            for m in ms:
                of[m] = ms
        by = {}
        for m, r in rows.items():
            by.setdefault(r["name"], []).append(m)
        ALIAS.update(rows=rows, of=of, by=by)
    got = {ALIAS["rows"][m]["name"] for x in ALIAS["by"].get(name, []) for m in ALIAS["of"].get(x, [])
           if m[0] == prog and m in ALIAS["rows"]}
    return got.pop() if len(got) == 1 else None


def linkunify(prog, tail, saved, log):
    """Repair switch `declunify`, R5 link (T3.c2): per `<unit .c>:(...): undefined reference to U` of tail (a shared
    body's reference under another program's name: C code or its INCLUDE_ASM data) whose link_alias in prog is N,
    the unit gets `__asm__("U = N");` (an assembler alias, no bytes; C0065's per-member name at link level), through
    bank.put(saved). (units edited, note)."""
    refs = {}
    for m in LINK_RE.finditer(tail):
        p = m.group(1)
        p = p[len("build/"):-len(".o")] if p.startswith("build/") and p.endswith(".c.o") else p
        refs.setdefault(p, set()).add(m.group(2))
    if not refs:
        return 0, "n/a"
    edits, miss = {}, []
    for p, us in sorted(refs.items()):
        if not (p.endswith(".c") and os.path.isfile(p)):
            miss.append(f"{p} not a unit")
            continue
        al = {u: link_alias(prog, u) for u in sorted(us)}
        miss += [f"no alias for {u}" for u, n in al.items() if n is None or n == u]
        with open(p, errors="replace") as f:
            text = f.read()
        add = "".join(f'__asm__("{u} = {n}");\n' for u, n in al.items() if n is not None and n != u)
        if add:
            edits[p] = text + ("" if text.endswith("\n") else "\n") + add
    if miss or not edits:
        return 0, "link " + "; ".join(miss or ["no edit"])
    for p, t in sorted(edits.items()):
        bank.put(saved, p, t)
    with open(os.path.join(bank.LOGDIR, log + ".log"), "a") as f:
        f.write("".join(f"DECLUNIFY alias {p}\n" for p in sorted(edits)))
    return len(edits), f"link {len(edits)} units"


def rung5_unify(prog, gated, log, pos=None):
    """bank.rung5 of gated[0]'s body; under declunify an R5 stop whose log names `undefined reference to U` ->
    linkunify into gated[-1]'s saved, then rung5 once more (gated records via declunify). pos: [log size before the
    last rung5] (its evidence starts there). Switch off: bank.rung5 alone."""
    pos = [log_size(log)] if pos is None else pos
    try:
        bank.rung5(prog, gated[0]["src"], gated[0]["h1"], log)
        return
    except bank.Stop as e:
        if "declunify" not in bank.REPAIR or e.rung != 5:
            raise
        k, note = linkunify(prog, log_tail(log, pos[0]), gated[-1]["saved"], log)
        if not k:
            raise e if note == "n/a" else bank.Stop(5, f"{e.cause}; declunify {note}")
    pos[0] = log_size(log)
    try:
        bank.rung5(prog, gated[0]["src"], gated[0]["h1"], log)
    except bank.Stop as e:
        raise bank.Stop(5, f"{e.cause}; declunify {note}")
    for g in gated:
        g["via"] = g["via"] or "declunify"


def short(why):
    """A refusal reason without its leading `refused ` and trailing `(log …)`."""
    return re.sub(r" \(log [^)]*\)$", "", why[len("refused "):])


def rodata_step(prog, vram, src, defines, log, n, why):
    """gate.py's `rodata` step for one member: carve.py rodata, re-split + rebuild, R1-R4 again; on a carve refusal,
    a red rebuild or a stop every carve-touched file restored byte-exact and re-split."""
    import gate as gm
    saved = {p: (open(p, "rb").read() if os.path.isfile(p) else None) for p in gm.carve_files(prog)}
    r = subprocess.run([sys.executable, "tools/mmx6/carve.py", "rodata", prog, f"0x{vram:08X}", "--bytes", str(n)],
                       capture_output=True, text=True)
    saved.update({p: None for p in gm.carve_files(prog) if p not in saved})
    if r.returncode:
        mo = re.search(r"CARVE REFUSE (\S+)", r.stdout + r.stderr)
        note = f"CARVE REFUSE {mo.group(1)}" if mo else f"carve rc {r.returncode}"
        if any((open(p, "rb").read() if os.path.isfile(p) else None) != b for p, b in saved.items()):
            bank.restore(saved)
            note += ", restore red" if resplit(prog, log) else ""
        return None, f"{why}; rodata {note}"
    if resplit(prog, log):
        note = "rebuild red"
    else:
        g, w = gate(prog, vram, src, defines, log)
        if g is not None:  # the carve snapshot predates the ladder's edits: it wins on shared paths
            return dict(g, saved={**g["saved"], **saved}, via="rodata", carved=True, first=why), ""
        note = f"stop {short(w)}"
    bank.restore(saved)
    if resplit(prog, log):
        note += ", restore red"
    return None, f"{why}; rodata {note}"


def mark_inherited(text, src):
    """`text` with each pin/goto/barrier psxd_floor counts unmarked given a standalone `<indent>// !FAKE: inherited
    from <src>` line directly above it (indent = that line's; never trailing, so clang-format cannot reflow it away;
    depin.py's form). Comment-only: no code token changes."""
    sys.path.insert(0, os.path.dirname(HERE))
    import psxd_floor as pf
    note = f"// !FAKE: inherited from {src}"
    for _ in range(1000):
        lines = text.split("\n")
        todo = sorted({ln for kind, ln in pf.marked(pf.raw_keywords(text), pf.markers(text)) if kind.endswith("-unmarked")})
        if not todo:
            return text
        ln = todo[0]
        if ln and lines[ln - 1].strip() == note:  # a second construct on one line: one standalone marker covers one
            break
        lines.insert(ln, re.match(r"[ \t]*", lines[ln]).group(0) + note)
        text = "\n".join(lines)
    raise RuntimeError(f"mark_inherited: no fixpoint for a copy of {src}")


def tudecl_step(prog, vram, src, defines, log, tail, why):
    """gate.py's `tudecl` step for one member: the member's own copy src/shared/<prog>/<func>.c of the body (defines
    applied) with tudecl_fix variant A, then B, against the unit's diagnostics (tail), R1-R4 under the same defines;
    on a stop the copy deleted (gate() restored the unit)."""
    import gate as gm
    func = bank.corpus_row(prog, vram)["name"]
    copy = layout.new_body(prog, func)
    if not any(gm.TUDECL_RE.match(ln) for ln in tail.splitlines()):
        return None, f"{why}; tudecl n/a: {gm.err_key(tail)}"
    if os.path.exists(copy):
        return None, f"{why}; tudecl copy exists {copy}"
    with open(src) as f:
        text = bank.subst(f.read(), defines)
    start = gm.fmt(text, copy)
    vs = []
    for v in gm.tudecl_fix(src, text, tail, func):  # src: the diagnostics name the exemplar body's path
        v = gm.fmt(v, copy)
        if v != start and v not in vs:
            vs.append(v)
    if not vs:
        return None, f"{why}; tudecl no variant"
    notes = []
    for tag, v in zip("AB", vs):
        gm.write(copy, mark_inherited(v, src))
        g, w = gate(prog, vram, copy, defines, log)
        if g is not None:
            return dict(g, saved={**g["saved"], copy: None}, via="tudecl", first=why), ""
        os.remove(copy)
        notes.append(f"{tag} stop {short(w)}")
    return None, f"{why}; tudecl {', '.join(notes)}"


def program_r5(prog, src, gated, log):
    """Raise bank.Stop unless the program is green from a clean rebuild and every gated extent equals retail. A red
    hash with a gated member the map places away (placement, 3.1 T6) -> `linked extent differs from retail (<pv>
    placed 0x<a> not 0x<vram> ...)`."""
    try:
        rung5_unify(prog, gated, log)  # bank.rung5 (+ the declunify link step when that switch is on, T3.c2)
    except bank.Stop as e:
        away = [f"{pv((g['prog'], g['vram']))} {p}" for g in gated for p in [placement(prog, g["row"])] if p] \
            if e.rung == 5 and "hash red" in e.cause else []
        if away:
            raise bank.Stop(5, f"linked extent differs from retail ({' '.join(away)})")
        raise
    moved = [g["src"] for g in gated[1:] if g["src"] != gated[0]["src"] and bank.sha1(g["src"]) != g["h1"]]
    if moved:
        raise bank.Stop(5, f"body sha1 changed since R1 ({moved[0]})")
    bad = [pv((g["prog"], g["vram"])) + "".join(f" {p}" for p in [placement(prog, g["row"])] if p) for g in gated
           if not extent_same(prog, g["row"])]
    if bad:
        raise bank.Stop(5, f"linked extent differs from retail ({' '.join(bad)})")


def key_plan(key, dry, reg=None, classes=None, rows=None):
    """(ctx, class members, skipped members, {prog: run members}) of key; sys.exit on a missing exemplar row/class.
    Dry run of a key without an exemplar row: its rows' one named exemplar + shared path, members the class or else
    the rowed members (rows disagreeing on cols 2-3 still exit).
    reg: registry_rows() (default: the registry); classes: load_classes(); rows: corpus_rows()."""
    reg = registry_rows() if reg is None else reg
    ex_rows = [t for _, t in reg if t[0] == key and t[1] == t[3]]
    cls = (load_classes() if classes is None else classes).get(key)
    key_rows = [t for _, t in reg if t[0] == key]
    if dry and not ex_rows and key_rows and len({(t[1], t[2]) for t in key_rows}) == 1:
        # orphan key (exemplar row dropped, T41.1.c2): dry runs take the rows' one named exemplar pv + shared path;
        # members = the dup class, else the key's rowed members. Rows disagreeing on cols 2-3 still exit below.
        ex_rows = key_rows[:1]
        if cls is None:
            cls = sorted({parse_pv(t[3]) for t in key_rows})
    if not ex_rows or cls is None:
        sys.exit(f"propagate: {'no exemplar row in ' + bank.REGISTRY if not ex_rows else 'no dup class'} for {key}")
    ex, src = parse_pv(ex_rows[0][1]), ex_rows[0][2]
    rows = corpus_rows() if rows is None else rows
    ex_name = rows[ex]["name"]
    ex_tab = table_addr(probe.retail_words(ex[0], ex_name))
    with open(src) as f:
        body = f.read()
    if ex_name not in body:
        sys.exit(f"propagate: exemplar name {ex_name} not in {src} (contract)")
    if ex_tab is not None and f"D_{ex_tab:08X}" not in body:
        ex_tab = None  # no table in the body (the lui/lw pair is some other global): the name define only
    done = {t[3] for _, t in reg if t[0] == key and t[4] == "gated"}  # own banks / earlier runs: rows kept as they are
    skip = [m for m in cls if m != ex and pv(m) in done]
    by_prog = {}
    for m in cls:
        if m not in skip:
            by_prog.setdefault(m[0], []).append(m)
    ctx = (ex, ex_name, ex_tab, src, rows, not dry)  # recovery steps (tudecl, rodata) in a real run only
    return ctx, cls, skip, by_prog


def propagate(key, dry):
    """(gated count, member count, [(member pv, state, reason)])."""
    ctx, cls, skip, by_prog = key_plan(key, dry)
    ex, src = ctx[0], ctx[3]
    results, paths = [], {}
    if not dry:
        for prog in sorted(by_prog):
            results += run_prog(prog, by_prog[prog], ctx, lambda s: print(s, flush=True), paths)
    else:  # one scratch tree per worker; programs in parallel, output in program order
        n = min(WORKERS, len(by_prog))
        trees = [f"{TREE}/w{i}" for i in range(n)]
        for t in trees:
            make_tree(t)
        mp = multiprocessing.get_context("fork")
        q = mp.Queue()
        for t in trees:
            q.put(t)
        order = sorted(by_prog, key=lambda p: (-len(by_prog[p]), p))  # longest first
        with mp.Pool(n, initializer=_worker_init, initargs=(q,)) as pool:
            jobs = {p: pool.apply_async(_worker_prog, (p, by_prog[p], ctx)) for p in order}
            for prog in sorted(by_prog):
                res, lines = jobs[prog].get()
                print("\n".join(lines), flush=True)
                results += res
    if not dry:
        write_registry(key, pv(ex), src, results, paths)
    return sum(s == "gated" for _, s, _ in results) + len(skip), len(cls), results


def run_prog(prog, ms, ctx, out, paths=None, keep=None):
    """[(member pv, state, reason)] of one program: R1-R4 per member, then R5 (isolating members on a red R5);
    paths gets {member pv: its own body copy} of members gated via tudecl; keep gets the gated member records
    (their edits stay in the tree: the grouped dry run restores them)."""
    src, rec, log = ctx[3], ctx[5], f"propagate-{prog}"
    results, gated = gate_members(prog, ms, ctx, out)
    if gated:
        try:
            program_r5(prog, src, gated, log)
        except bank.Stop as e:  # isolate per member: undo all, retry each alone
            out(f"propagate: {prog} R5 {e.cause}; isolating {len(gated)} members")
            for g in reversed(gated):
                bank.restore(g["saved"])
            (resplit if any(g["carved"] for g in gated) else bank.rebuild)(prog, log)
            kept = []
            for g0 in gated:
                g, why = gate_member(prog, g0["vram"], src, g0["defines"], log, rec, (ctx[0][0], ctx[1]))
                if g is not None:
                    g = dict(g, reloc=g0["reloc"]) if g0.get("reloc") else g  # relocdef (3.1 T5)
                    try:
                        program_r5(prog, src, kept + [g], log)
                        kept.append(g)
                        continue
                    except bank.Stop as e2:  # its copy/carve undone too
                        bank.restore(g["saved"])
                        (resplit if g["carved"] else bank.rebuild)(prog, log)
                        why = (f"{g['first']}; {g['via']} stop R5: {short('refused ' + e2.cause)}" if g["via"]
                               else f"refused R5: {e2.cause}")
                results.append((pv((prog, g0["vram"])), "refused", why[len("refused "):]))
                out(f"{pv((prog, g0['vram']))} {why}")
            gated = kept
    if keep is not None:
        keep.extend(gated)
    return results + gated_lines(prog, gated, src, out, paths)


def gated_lines(prog, gated, src, out, paths=None):
    """[(member pv, "gated", reason)] of gated member records, each printed via out."""
    results = []
    for g in gated:
        d = g["defines"]
        reason = "exemplar" if not d else "define " + " ".join(f"{o}={n}" for o, n in d)
        if g["via"]:
            reason += f" via {g['via']}"
            if g["src"] != src and paths is not None:
                paths[pv((prog, g["vram"]))] = g["src"]
        if g.get("reloc"):  # relocdef (3.1 T5): its defines are in the define list above
            reason += " via relocdef"
        results.append((pv((prog, g["vram"])), "gated", reason))
        out(f"{pv((prog, g['vram']))} gated {reason}")
    return results


def gate_members(prog, ms, ctx, out):
    """(refusals [(member pv, "refused", reason)], gated member records): R1-R4 per member of one program, in order."""
    ex, ex_name, ex_tab, src, rows, rec = ctx
    log, results, gated = f"propagate-{prog}", [], []
    for m in ms:
        r = rows.get(m)
        if r is None:
            results.append((pv(m), "refused", "preflight: no corpus row"))
            out(f"{pv(m)} refused preflight: no corpus row")
            continue
        if m == ex:
            defines = []
        elif ex_tab is None:
            defines = [(ex_name, r["name"])]
        else:
            t = table_addr(probe.retail_words(prog, r["name"]))
            if t is None:
                results.append((pv(m), "refused", "R1: no lui/lw table pair in retail words"))
                out(f"{pv(m)} refused R1: no lui/lw table pair in retail words")
                continue
            defines = [(ex_name, r["name"]), (f"D_{ex_tab:08X}", f"D_{t:08X}")]
            if t == ex_tab and unit_aliases(prog, r["tu"], r["name"], f"D_{t:08X}"):
                defines = defines[:1]  # an identity define would override the unit's own alias of the name (T40.c1)
        rd = reloc_defines(ctx, prog, r, log) if m != ex and "relocdef" in bank.REPAIR else []  # 3.1 T5
        g, why = gate_member(prog, m[1], src, defines + rd, log, rec, (ex[0], ex_name))
        if g is None:
            why += "; relocdef " + " ".join(f"{o}={n}" for o, n in rd) if rd else ""
            results.append((pv(m), "refused", why[len("refused "):]))
            out(f"{pv(m)} {why}")
        else:
            gated.append(dict(g, reloc=rd) if rd else g)
    return results, gated


def _worker_init(q):
    os.chdir(q.get())


def _worker_prog(prog, ms, ctx):
    lines = []
    return run_prog(prog, ms, ctx, lines.append), lines


# ---- grouped dry run -----------------------------------------------------------------------------------------------

def plan(keys, reg_path=bank.REGISTRY):
    """({key: (ctx, class members, skipped members)}, {key: setup error line}, {prog: [(key, run members, isolated)]}).
    A unit (key, prog) is isolated when one of its run members holds a refused registry row of key (a scheduling
    hint, never a verdict); units in key order."""
    reg, classes, rows = registry_rows(reg_path), load_classes(), corpus_rows()
    refused = {(t[0], t[3]) for _, t in reg if t[4] == "refused"}
    info, errors, units = {}, {}, {}
    for key in keys:
        try:
            ctx, cls, skip, by_prog = key_plan(key, True, reg, classes, rows)
        except SystemExit as e:
            errors[key] = str(e)
            continue
        info[key] = (ctx, cls, skip)
        for prog in sorted(by_prog):
            ms = by_prog[prog]
            units.setdefault(prog, []).append((key, ms, any((key, pv(m)) in refused for m in ms)))
    return info, errors, units


def restore_prog(prog, gated, log):
    """Undo the gated records' edits (newest first) and rebuild prog."""
    for g in reversed(gated):
        bank.restore(g["saved"])
    (resplit if any(g["carved"] for g in gated) else bank.rebuild)(prog, log)


GROUP_BISECT = True  # a red group R5 bisects the group units (T4.c1); False: the pre-T4 all-isolate (self-test control)


def run_group(prog, units):
    """({key: (results, lines)}, GROUP line, notes) of one program in this tree: isolated units first (run_prog from
    the pristine program, then restored); then the group (R1-R4 per member, one program_r5 over all its gated); a
    group R1-R4 refusal (preflight excepted) -> restore, re-run those units isolated; a red group R5 -> restore, bisect
    the other units (key order, halves; each half re-gated from the restored program, its own program_r5: green keeps
    its grouped verdicts, red splits again, a red single unit is re-run isolated; T4.c1).
    The tree is left with the program's edits restored."""
    t0, log, out, notes, x0 = time.time(), f"propagate-{prog}", {}, [], bank.XKEY[0]
    count = {"re": 0, "r5": 0}  # units re-run isolated after the plan; group program_r5 calls
    seen, stop = set(), threading.Event()  # heartbeat (3.1 T23): print-only, verdicts and GROUP line unchanged

    def beat():
        while not stop.wait(60):
            print(f"PROPAGATE PROGRESS {prog} units {len(seen)} of {len(units)} wall {time.time() - t0:.0f}s",
                  flush=True)

    def isolated(key, ms, ctx):
        lines, keep = [], []
        res = run_prog(prog, ms, ctx, lines.append, keep=keep)
        restore_prog(prog, keep, log)
        out[key] = (res, lines)
        seen.add(key)

    def bisect(us):
        """Gate us from the restored program, one program_r5 over all their gated; True when it was red."""
        done, all_gated = [], []
        for key, ms, ctx in us:
            lines = []
            res, gated = gate_members(prog, ms, ctx, lines.append)
            done.append((key, ms, ctx, res, gated, lines))
            seen.add(key)
            all_gated += gated
        affected = {key for key, _, _, res, _, _ in done if any(not r.startswith("preflight:") for _, _, r in res)}
        cause = ""
        if all_gated:
            count["r5"] += 1
            try:
                program_r5(prog, None, all_gated, log)
            except bank.Stop as e:
                cause = e.cause
            restore_prog(prog, all_gated, log)
        rest = [(key, ms, ctx) for key, ms, ctx in us if key not in affected]
        split = cause and len(rest) > 1 and GROUP_BISECT
        if cause:
            notes.append(f"propagate: {prog} group R5 {cause}; "
                         + (f"bisecting {len(rest)} units" if split else f"isolating {len(rest)} units"))
        for key, ms, ctx, res, gated, lines in done:
            if key in affected or (cause and not split):
                isolated(key, ms, ctx)
                count["re"] += 1
            elif not cause:
                out[key] = (res + gated_lines(prog, gated, ctx[3], lines.append), lines)
        if split:
            h = len(rest) // 2
            bisect(rest[:h])
            bisect(rest[h:])
        return bool(affected or cause)

    threading.Thread(target=beat, daemon=True).start()
    try:
        for key, ms, ctx, iso in units:
            if iso:
                isolated(key, ms, ctx)
        group = [(key, ms, ctx) for key, ms, ctx, iso in units if not iso]
        fallback = bisect(group) if group else False
    finally:
        stop.set()
    n_iso = sum(iso for *_, iso in units)
    return out, (f"PROPAGATE GROUP {prog} units {len(units)} isolated {n_iso} fallback {'yes' if fallback else 'no'}"
                 f" reisolated {count['re']} r5 {count['r5']} xkey {bank.XKEY[0] - x0} wall {time.time() - t0:.0f}s"), notes


def _worker_group(a):
    return a[0], run_group(*a)


def tree_bytes(paths, skip=SKIP):
    """On-disk bytes (allocated blocks) of the regular files under paths, the skip subtrees left out."""
    n = 0
    for top in paths:
        for d, ds, fs in os.walk(top):
            ds[:] = [x for x in ds if os.path.join(d, x) not in skip]
            n += sum(os.lstat(os.path.join(d, f)).st_blocks * 512 for f in fs
                     if not os.path.islink(os.path.join(d, f)))
    return n


def key_verdict(key, m, n, results, reg=bank.REGISTRY, states=None):
    """(lines, passes, drift count) of one key: `PROPAGATE DRY-RUN <key> gated m of n members` + its DRIFT lines;
    passes as per-key --expect-registry (no DRIFT, no unrowed refusal)."""
    drift, unrowed = expect_drift(key, results, reg, states)
    return [f"PROPAGATE DRY-RUN {key} gated {m} of {n} members"] + drift, not drift and not unrowed, len(drift)


def grouped_summary(k, n_keys, d, unchanged):
    """(last line, rc): rc 0 iff every key passes, no DRIFT and src/ + registry unchanged."""
    return f"PROPAGATE DRY-RUN GROUPED {k} of {n_keys} keys; drift {d}", 0 if k == n_keys and d == 0 and unchanged else 1


def grouped(keys):
    """Grouped dry run --expect-registry of keys: one worker tree per process for the whole run, one program at a
    time per tree; per key the per-key mode's lines; rc as grouped_summary."""
    t0 = time.time()
    watch = ["src", bank.REGISTRY]
    before = tree_sha(watch)
    shutil.rmtree(TREE, ignore_errors=True)
    info, errors, units = plan(keys)
    os.makedirs(SCRATCH, exist_ok=True)
    size, free = tree_bytes(COPY) + TREE_GROW, shutil.disk_usage(SCRATCH).free  # was 2 * tree_bytes(COPY)
    n = max(1, min(WORKERS, len(units), (free - TREE_RESERVE) // size))  # was (free // 2) // size
    print(f"propagate: grouped {len(keys)} keys, {len(units)} programs, {n} trees "
          f"({size >> 20} MB each, {free >> 20} MB free)", flush=True)
    trees = [f"{TREE}/w{i}" for i in range(n)]
    for t in trees:
        make_tree(t)
    res = {}
    if units:
        mp = multiprocessing.get_context("fork")
        q = mp.Queue()
        for t in trees:
            q.put(t)
        order = sorted(units, key=lambda p: (-sum(len(u[1]) for u in units[p]), p))  # largest first
        args = {p: [(key, ms, info[key][0], iso) for key, ms, iso in units[p]] for p in order}
        with mp.Pool(n, initializer=_worker_init, initargs=(q,)) as pool:
            for prog, (out, line, notes) in pool.imap_unordered(_worker_group,[(p, args[p]) for p in order]):
                print("\n".join(notes + [line]), flush=True)
                res[prog] = out
    k = d = 0
    for key in keys:
        if key in errors:
            print(errors[key])
            continue
        ctx, cls, skip = info[key]
        results, lines = [], []
        for prog in sorted(res):
            if key in res[prog]:
                results += res[prog][key][0]
                lines += res[prog][key][1]
        m = sum(s == "gated" for _, s, _ in results) + len(skip)
        vl, ok, nd = key_verdict(key, m, len(cls), results)
        print("\n".join(lines + vl), flush=True)
        k, d = k + ok, d + nd
    after = tree_sha(watch)
    print(f"propagate: grouped dry run wall {time.time() - t0:.0f}s; src/ + registry sha1 {after[:12]} "
          f"{'unchanged' if after == before else 'CHANGED from ' + before[:12]}")
    line, rc = grouped_summary(k, len(keys), d, after == before)
    print(line)
    return rc


def write_registry(key, ex, src, results, paths=None):
    """Rows updated in place (same key + member) or appended; comments, order and the exemplar row kept; a member
    in paths gets its own body copy as the row's shared path."""
    with open(bank.REGISTRY) as f:
        lines = f.read().split("\n")
    at = {(t[0], t[3]): i for i, t in registry_rows()}
    feed = sorted({(paths or {}).get(m) for m, state, reason in results if state == "gated"
                   and re.search(r" via (?:rolefeed|unitcut)(?: |$)", reason)} - {None})
    if feed:  # repair switch rolefeed (3.1 T4), unitcut (T6): the exemplar left src for its own body, rows follow
        lines, src = bank.repoint(lines, key, src, feed[0]), feed[0]
    for m, state, reason in sorted(results):
        if m == ex:
            continue  # the exemplar row stays (a refused re-gate, e.g. a c-empty exemplar, never overwrites it)
        row = f"{key} {ex} {(paths or {}).get(m, src)} {m} {state} {reason}"
        if (key, m) in at:
            lines[at[(key, m)]] = row
        else:
            lines.insert(len(lines) - 1 if lines and lines[-1] == "" else len(lines), row)
    with open(bank.REGISTRY, "w") as f:
        f.write("\n".join(lines))


def make_tree(tree):
    os.makedirs(tree)
    for p in COPY:  # copy2/copytree keep mtimes, so make sees the copied build/ as up to date
        if os.path.isdir(p):
            shutil.copytree(p, os.path.join(tree, p), symlinks=True,
                            ignore=lambda d, names: [x for x in names if os.path.join(d, x) in SKIP])
        else:
            shutil.copy2(p, os.path.join(tree, p))
    for p in LINK:
        os.symlink(os.path.abspath(p), os.path.join(tree, p))


def expect_drift(key, results, reg=bank.REGISTRY, states=None):
    """(DRIFT lines, unrowed refusals): each dry-run verdict vs the member's registry row of key (refused row ->
    refused, any other row -> gated); a member without a row must gate (counted, no DRIFT line). The run's exemplar
    on a `gated` row whose corpus state is c or c-empty agrees refused too (write_registry keeps that row).
    states: {member pv: corpus state} (default: build/corpus)."""
    rows = [t for _, t in registry_rows(reg) if t[0] == key]
    st = {t[3]: t[4] for t in rows}
    exs = {t[3] for t in rows if t[1] == t[3] and t[4] == "gated"}
    if exs and states is None:
        states = {pv(m): r["state"] for m, r in corpus_rows().items()}
    drift, unrowed = [], 0
    for m, state, _ in sorted(results):
        want = "refused" if st.get(m) == "refused" else "gated"
        if state == "refused" and m in exs and states.get(m) in ("c", "c-empty"):
            continue  # a c/c-empty exemplar's re-gate is refused at preflight; its gated row stands
        if state != want:
            if m in st:
                drift.append(f"PROPAGATE DRIFT {key} {m} {st[m]} -> {state}")
            else:
                unrowed += 1
    return drift, unrowed


# ---- registry check ------------------------------------------------------------------------------------------------

def member_keys(ms, rows):
    """{(prog, vram): built dup key or None} (cached)."""
    todo = [m for m in ms if m not in _KEYS]
    have = [m for m in todo if m in rows]
    for m in todo:
        _KEYS.setdefault(m, None)
        _FAMS.setdefault(m, None)
    try:
        for m, (w, k) in zip(have, census.read_words([rows[m] for m in have])):
            _KEYS[m], _FAMS[m] = census.dup_key(w, k), census.family_key(w)
    except census.Refuse:  # some rows unreadable: one at a time
        for m in have:
            try:
                (w, k), = census.read_words([rows[m]])
                _KEYS[m], _FAMS[m] = census.dup_key(w, k), census.family_key(w)
            except census.Refuse:
                pass
    return {m: _KEYS[m] for m in ms}


def check(reg=bank.REGISTRY, cls_path=CLASSES, quiet=False):
    """(rc, refusal lines); prints them and the verdict line unless quiet."""
    rows = [t for _, t in registry_rows(reg)]
    cls, fams, cr = load_classes(cls_path), load_classes(cls_path, "family"), corpus_rows()
    mems = [parse_pv(t[3]) for t in rows]
    got = member_keys(mems, cr)
    bad = []
    for t, m in zip(rows, mems):
        if t[5].startswith("family"):  # family_remap.py rows: the family key, no missing-member rule
            k = _FAMS[m]
            if k != t[0]:
                bad.append(f"REGISTRY refused drift {t[3]}: built family key {k or 'none'} != row key {t[0]}")
            if m not in fams.get(t[0], ()):
                bad.append(f"REGISTRY refused not in class {t[3]} family {t[0]}")
            continue
        k = got[m]
        if k != t[0]:
            bad.append(f"REGISTRY refused drift {t[3]}: built key {k or 'none'} != row key {t[0]}")
        if m not in cls.get(t[0], ()):
            bad.append(f"REGISTRY refused not in class {t[3]} key {t[0]}")
    have = set(zip((t[0] for t in rows), mems))
    for key in sorted({t[0] for t in rows if not t[5].startswith("family")}):
        for m in cls.get(key, ()):
            if (key, m) not in have:
                bad.append(f"REGISTRY refused missing member {pv(m)} key {key}")
    out = bad + ([f"REGISTRY REFUSED {len(bad)} of {len(rows)} rows"] if bad else [f"REGISTRY OK {len(rows)} rows"])
    if not quiet:
        print("\n".join(out))
    return (1 if bad else 0), bad


def grouped_controls(d, cls):
    """Build-free plants of the grouped mode (plan + key_verdict + grouped_summary on planted rows and verdicts):
    a gated exemplar row refused inside a 2+-key group -> DRIFT, rc 1; a refused member row -> its unit isolated,
    the refusal agrees, rc 0. Returns the failure count."""
    exr = {t[0]: t for _, t in registry_rows() if t[1] == t[3] and t[0] in cls}
    ex_in = {}
    for k in sorted(exr):
        ex_in.setdefault(parse_pv(exr[k][1])[0], []).append(k)
    pick = next(((a, b, m) for a in sorted(exr) for m in cls[a] if pv(m) != exr[a][1]
                 for b in ex_in.get(m[0], ()) if b != a), None)
    if pick is None:
        print("control grouped FAIL: no two keys with an exemplar row sharing a program")
        return 1
    a, b, ma = pick
    prog, exb = ma[0], exr[b][1]
    reg = os.path.join(d, "registry.txt")
    fails = 0
    for name, extra, want_iso, bad in (("grouped drift", [], False, (b, exb)),
                                       ("grouped refused isolated", [f"{a} {exr[a][1]} {exr[a][2]} {pv(ma)} refused R2: "
                                                                     "control"], True, (a, pv(ma)))):
        with open(reg, "w") as f:
            f.write(bank.REGISTRY_HEAD + "\n".join([" ".join(exr[a]).rstrip(), " ".join(exr[b]).rstrip()] + extra) + "\n")
        info, errors, units = plan([a, b], reg)
        iso = {k: i for k, _, i in units.get(prog, ())}
        k = nd = 0
        drift = []
        for key in (a, b):
            res = [(pv(m), "refused" if (key, pv(m)) == bad else "gated", "control")
                   for us in units.values() for kk, ms, _ in us if kk == key for m in ms]
            vl, ok, n1 = key_verdict(key, 0, 0, res, reg, {})
            drift += vl[1:]
            k, nd = k + ok, nd + n1
        _, rc = grouped_summary(k, 2, nd, True)
        want_drift = [f"PROPAGATE DRIFT {b} {exb} gated -> refused"] if not want_iso else []
        good = (not errors and iso.get(a) is want_iso and iso.get(b) is False and drift == want_drift
                and rc == (0 if want_iso else 1))
        print(f"control {name} {'ok' if good else 'FAIL'}: {prog} units {len(units.get(prog, ()))} isolated "
              f"{sum(iso.values())}, rc {rc}, {len(drift)} drift" + (f", {drift[0]}" if drift else ""))
        fails += not good
    # orphan key (T41.1.c2): exemplar row removed -> plans with the rows' named exemplar; rows disagreeing -> setup error
    mrow = f"{a} {exr[a][1]} {exr[a][2]} {pv(ma)} gated control"
    for name, lines in (("orphan exemplar", [mrow]),
                        ("orphan disagree", [mrow, f"{a} {pv(ma)} {exr[a][2]} {exr[a][1]} gated control"])):
        with open(reg, "w") as f:
            f.write(bank.REGISTRY_HEAD + "\n".join(lines) + "\n")
        info, errors, _ = plan([a], reg)
        if name == "orphan exemplar":
            good = not errors and a in info and info[a][0][0] == parse_pv(exr[a][1]) and info[a][0][3] == exr[a][2]
            got = f"exemplar {pv(info[a][0][0])}" if a in info else errors.get(a, "")
        else:
            good = a not in info and "no exemplar row" in errors.get(a, "")
            got = errors.get(a, "planned")
        print(f"control {name} {'ok' if good else 'FAIL'}: {got}")
        fails += not good
    return fails


def bisect_control():
    """Build-free plant of run_group's red-R5 bisect (T4.c1, C0054): gate_members/program_r5/run_prog/restore_prog
    stubbed; program_r5 red when both pair units are in its set, or the always-red unit is. Verdicts must equal
    isolation, reisolated 0 (pair) / 1 (always-red), r5 <= 1 + 2*ceil(log2 n); the pre-T4 all-isolate
    (GROUP_BISECT False) must fail the pair plant. Returns fails."""
    names = ("gate_members", "program_r5", "run_prog", "restore_prog")
    saved = {n: globals()[n] for n in names}
    keys = [f"k{i:02d}" for i in range(24)]
    pair, red = {"k03", "k07"}, "k09"  # the pair shares the first halves: the bisect recurses before it splits

    def iso_res(key, ms):
        return [(pv(m), "refused", "R5: plant") if key == red else (pv(m), "gated", "exemplar") for m in ms]

    def stub_gm(prog, ms, ctx, out):
        return [], [dict(prog=prog, vram=m[1], defines=[], via="", src=ctx[3], key=ctx[0]) for m in ms]

    def stub_r5(prog, src, gated, log):
        ks = {g["key"] for g in gated}
        if pair <= ks or red in ks:
            raise bank.Stop(5, "plant")

    def stub_run(prog, ms, ctx, out, paths=None, keep=None):
        return iso_res(ctx[0], ms)

    global GROUP_BISECT
    fails = 0
    globals().update(gate_members=stub_gm, program_r5=stub_r5, run_prog=stub_run, restore_prog=lambda *a: None)
    try:
        for name, ks, bis, want_re in (("pair", [k for k in keys if k != red], True, 0),
                                       ("always-red", [k for k in keys if k != "k07"], True, 1),
                                       ("pair old all-isolate", [k for k in keys if k != red], False, 0)):
            GROUP_BISECT = bis
            units = [(k, [("P", 0x80010000 + 0x100 * i)], (k, None, None, "src/plant.c", None, False), False)
                     for i, k in enumerate(ks)]
            out, line, _ = run_group("P", units)
            mo = re.search(r" fallback (\w+) reisolated (\d+) r5 (\d+) ", line)
            same = all(out.get(k, ([],))[0] == iso_res(k, ms) for k, ms, _, _ in units)
            bound = 1 + 2 * math.ceil(math.log2(len(units)))
            ok = bool(mo) and same and mo.group(1) == "yes" and int(mo.group(2)) == want_re and int(mo.group(3)) <= bound
            good = ok if bis else not ok  # the pre-T4 behaviour must fail the plant
            print(f"control group bisect {name} {'ok' if good else 'FAIL'}: {line.split(' wall ')[0]}, verdicts "
                  f"{'equal' if same else 'differ'} to isolation, r5 bound {bound}" + ("" if bis else ", plant fails"))
            fails += not good
    finally:
        GROUP_BISECT = True
        globals().update(saved)
    return fails


DU_PLANTS = (  # (name, unit text, body file, body text, extra files {name: text}, edited side): each unit already
    # holds its body's #include (R2's edit); side: the file the switch must edit (unit, body, or an extra file)
    ("conflicting types", "#include \"common.h\"\n\nvoid du_f(s32);\n\nvoid du_user(s32 x) {\n    du_f(x);\n}\n\n"
     "#include \"du_a.c\"\n", "du_a.c", "s32 du_f(s32);\n\nvoid du_member(s32 a) {\n    du_f(a);\n}\n", {}, "unit"),
    ("too few arguments", "#include \"common.h\"\n\n#include \"du_b.c\"\n\nvoid du_g();\n\nvoid du_user(void) {\n"
     "    du_g();\n}\n", "du_b.c", "void du_g(s32);\n\nvoid du_member(s32 a) {\n    du_g(a);\n}\n", {}, "unit"),
    ("body side", "#include \"common.h\"\n\nstruct DuS {\n    s32 a;\n    s32 b;\n};\n\nextern struct DuS du_v;\n\n"
     "s32 du_user(void) {\n    return du_v.b;\n}\n\n#include \"du_d.c\"\n", "du_d.c",
     "extern s32 du_v;\n\nvoid* du_member(void) {\n    return &du_v;\n}\n", {}, "body"),
    ("redefinition", "#include \"common.h\"\n\n#include \"du_s.c\"\n\ns32 du_user(s32 x) {\n    return du_h(x);\n}\n\n"
     "#include \"du_e.c\"\n", "du_e.c", "#include \"du_s.c\"\n\ns32 du_member(s32 a) {\n    return du_h(a) + 2;\n}\n",
     {"du_s.c": "static inline s32 du_h(s32 a) {\n    return a + 1;\n}\n"}, "du_s.c"),
)
DU_LINK = ("#include \"common.h\"\n\nextern s32 du_lu;\n\ns32* du_lf(void) {\n    return &du_lu;\n}\n",
           "#include \"common.h\"\n\ns32 du_ln;\n")  # (unit referencing du_lu, the unit defining du_ln)


def declunify_control():
    """Repair switch declunify through gate_member on planted units (C0054) under .run/propagate/selftest/du/:
    `conflicting types` (unit `void du_f(s32)` vs body `s32 du_f(s32)`: the body the specific side, T3.c2 C0434),
    `too few arguments` (body `void
    du_g(s32)`, then a unit call `du_g()`), body side (body `extern s32 du_v;` vs the unit's struct: the body's
    line rewritten, T3.c2) and `redefinition` (unit and body both include du_s.c's static inline du_h: guarded,
    T3.c2). gate() and unit_of() stubbed: R1-R4 = the real compile of the planted unit object (make -B). Switch off
    -> refused R2 does not compile; on -> gated via declunify, only the plant's side file edited, the record's saved
    restoring every file byte-exact. Link (T3.c2): rung5_unify over a planted unit referencing du_lu and one defining
    du_ln, bank.rung5 stubbed by make -B + ld, link_alias stubbed du_lu -> du_ln: off -> Stop R5, on -> linked via
    declunify, the unit restored by the record's saved. Returns fails."""
    d, log = os.path.join(SCRATCH, "selftest", "du"), "selftest-declunify"
    names = ("gate", "unit_of", "link_alias")
    saved_fns = {n: globals()[n] for n in names}
    rung5_fn = bank.rung5
    fails, rep = 0, set(bank.REPAIR)
    shutil.rmtree(d, ignore_errors=True)
    os.makedirs(d)
    if os.path.exists(os.path.join(bank.LOGDIR, log + ".log")):
        os.remove(os.path.join(bank.LOGDIR, log + ".log"))
    try:
        for i, (name, utext, bname, btext, extra, side) in enumerate(DU_PLANTS):
            unit, body = os.path.join(d, f"u{i}.c"), os.path.join(d, bname)
            unit_o = f"build/{unit}.o"
            texts = {unit: utext, body: btext, **{os.path.join(d, n): t for n, t in extra.items()}}
            for p, t in texts.items():
                with open(p, "w") as f:
                    f.write(t)

            def stub_gate(prog, vram, src, defines, log_, unit=unit, unit_o=unit_o):
                if bank.sh(["make", "-s", "-B", unit_o], log_):
                    return None, f"refused R2: {unit_o} does not compile (log {bank.LOGDIR}/{log_}.log)"
                return dict(prog=prog, vram=vram, row={}, defines=defines, saved={}, h1="", src=src, via="",
                            carved=False), ""

            globals().update(gate=stub_gate, unit_of=lambda prog, vram, unit=unit, unit_o=unit_o: (unit, unit_o))
            got = []
            for on in (False, True):
                bank.REPAIR.clear()
                bank.REPAIR.update({"declunify"} if on else set())
                g, why = gate_member("P", 0x80010000, body, [], log, False)
                got.append((g, why))
            (g0, w0), (g1, w1) = got
            want = {"unit": unit, "body": body}.get(side, os.path.join(d, side))
            edited = sorted(p for p, t in texts.items() if open(p).read() != t)
            if g1 is not None:
                bank.restore(g1["saved"])
            good = (g0 is None and " does not compile " in w0 and g1 is not None and g1["via"] == "declunify"
                    and edited == [want] and all(open(p).read() == t for p, t in texts.items()))
            print(f"control declunify {name} {'ok' if good else 'FAIL'}: off {w0 or 'gated'}; on "
                  f"{'gated via ' + g1['via'] if g1 is not None else w1}; edited {' '.join(edited) or '-'}")
            fails += not good
        unit, other = os.path.join(d, "ul.c"), os.path.join(d, "ln.c")
        for p, t in ((unit, DU_LINK[0]), (other, DU_LINK[1])):
            with open(p, "w") as f:
                f.write(t)
        objs = [f"build/{unit}.o", f"build/{other}.o"]

        def stub_rung5(prog, src, h1, log_):
            if bank.sh(["make", "-s", "-B"] + objs, log_) or \
                    bank.sh(["mipsel-linux-gnu-ld", "-e", "du_lf", "-o", f"build/{d}/l.elf"] + objs, log_):
                raise bank.Stop(5, "planted link red")

        bank.rung5 = stub_rung5
        globals().update(link_alias=lambda prog, name: "du_ln" if name == "du_lu" else None)
        got = []
        for on in (False, True):
            bank.REPAIR.clear()
            bank.REPAIR.update({"declunify"} if on else set())
            rec = dict(src=unit, h1="", saved={}, via="")
            try:
                rung5_unify("P", [rec], log)
                got.append(("linked", rec))
            except bank.Stop as e:
                got.append((f"R{e.rung}: {e.cause}", rec))
        (w0, _), (w1, r1) = got
        edited = open(unit).read() != DU_LINK[0]
        bank.restore(r1["saved"])
        good = w0.startswith("R5: ") and w1 == "linked" and r1["via"] == "declunify" and edited \
            and open(unit).read() == DU_LINK[0]
        print(f"control declunify link {'ok' if good else 'FAIL'}: off {w0}; on {w1}"
              f"{' via ' + r1['via'] if r1['via'] else ''}")
        fails += not good
    finally:
        bank.REPAIR.clear()
        bank.REPAIR.update(rep)
        bank.rung5 = rung5_fn
        globals().update(saved_fns)
        shutil.rmtree(d, ignore_errors=True)
        shutil.rmtree(os.path.join("build", d), ignore_errors=True)
    return fails


RF_SLOT = "@SLOT@"  # the member's INCLUDE_ASM site in a rolefeed plant's member unit
RF_PLANTS = (  # (name, {file: text}, exemplar unit, shared path, exemplar function, member unit, defines)
    ("role INCLUDE_ASM", {
        "ex.c": "#include \"common.h\"\n#undef INCLUDE_ASM\n#define INCLUDE_ASM(FOLDER, NAME) extern void NAME(void)\n"
                "#include \"role.c\"\n",
        "role.c": "INCLUDE_ASM(\"asm/rf\", rf_x);\n\nextern s32 rf_t[];\n\ns32 rf_e(s32 a) {\n    return rf_t[a] * 3 + 1;\n"
                  "}\n\nvoid rf_y(void) {\n}\n",
        "mu.c": f"#include \"common.h\"\n\nextern s32 rf_t[];\n\n{RF_SLOT}\n"},
     "ex.c", "role.c", "rf_e", "mu.c", [("rf_e", "rf_m")]),
    ("whole-unit duplicate", {
        "wu.c": "#include \"common.h\"\n\ns32 rf_w(s32 a) {\n    return a - 7;\n}\n\ns32 rf_o(s32 a) {\n    return a ^ 5;\n}\n",
        "wm.c": f"#include \"common.h\"\n\n__asm__(\".globl rf_o\\nrf_o:\\n\");\n\n{RF_SLOT}\n"},
     "wu.c", "wu.c", "rf_w", "wm.c", [("rf_w", "rf_n")]),
)


def rolefeed_control():
    """Repair switch rolefeed (3.1 T4) through gate_member on planted files under .run/propagate/selftest/rf/: a role
    file opening with INCLUDE_ASM (fed standalone: R1 parse error) and a whole unit fed into a same-program unit that
    already holds one of its other functions in asm (R2 gas `already defined`). gate() stubbed: R1 = make -B of the
    shared path (of a rolefeed body: its marker's unit, bank.rf_unit), R2 = the member unit with the block in its slot,
    compiled; bank.rf_where stubbed (the planted definition's lines, the exemplar unit, new body shared/<f>.c).
    Each: off -> refused R1|R2; on -> gated via rolefeed, src the new body; off again on that body -> gated; the
    exemplar unit's object bytes (bank.obj_text) equal before and after; the records' saved restore every planted file
    byte-exact and delete the new body. Returns fails."""
    d, log = os.path.join(SCRATCH, "selftest", "rf"), "selftest-rolefeed"
    names = ("gate", "unit_of")
    saved_fns, where_fn = {n: globals()[n] for n in names}, bank.rf_where
    fails, rep = 0, set(bank.REPAIR)
    if os.path.exists(os.path.join(bank.LOGDIR, log + ".log")):
        os.remove(os.path.join(bank.LOGDIR, log + ".log"))
    try:
        for name, files, exu, sname, fn, mname, defines in RF_PLANTS:
            shutil.rmtree(d, ignore_errors=True)
            os.makedirs(d)
            texts = {os.path.join(d, n): t for n, t in files.items()}
            for p, t in texts.items():
                with open(p, "w") as f:
                    f.write(t)
            exu, src, mu = (os.path.join(d, x) for x in (exu, sname, mname))
            new, exo = os.path.join(d, "shared", fn + ".c"), f"build/{exu}.o"

            def stub_gate(prog, vram, src_, defines_, log_, mu=mu):
                u = bank.rf_unit(src_)
                if bank.sh(["make", "-s", "-B", f"build/{u[1] if u else src_}.o"], log_):
                    return None, "refused R1: standalone probe FAIL 0/1 words"
                saved = {}
                bank.put(saved, mu, texts[mu].replace(RF_SLOT, "\n".join(bank.block(src_, d, defines_))))
                if bank.sh(["make", "-s", "-B", f"build/{mu}.o"], log_):
                    bank.restore(saved)
                    return None, f"refused R2: build/{mu}.o does not compile (log {bank.LOGDIR}/{log_}.log)"
                return dict(prog=prog, vram=vram, row={}, defines=defines_, saved=saved, h1="", src=src_, via="",
                            carved=False), ""

            def stub_where(ex, src_, exu=exu, new=new, src=src):
                for p in (new, src):
                    lines = open(p).read().split("\n") if os.path.isfile(p) else []
                    i = next((k for k, x in enumerate(lines) if re.match(rf"\w.* {ex[1]}\(.*\{{$", x)), None)
                    if i is not None:
                        return p, i + 1, lines.index("}", i) + 1, [exu], new
                return None

            globals().update(gate=stub_gate, unit_of=lambda prog, vram, mu=mu: (mu, f"build/{mu}.o"))
            bank.rf_where = stub_where
            bank.sh(["make", "-s", "-B", exo], log)
            before = bank.obj_text(exo)
            got = []
            for on, s in ((False, src), (True, src), (False, None)):
                bank.REPAIR.clear()
                bank.REPAIR.update({"rolefeed"} if on else set())
                got.append(gate_member("P", 0x80010000, s or (got[1][0] or {}).get("src", src), defines, log, False,
                                       ("P", fn)))
            (g0, w0), (g1, w1), (g2, w2) = got
            same = os.path.isfile(exo) and bank.obj_text(exo) == before
            fed = g1 is not None and g1["via"] == "rolefeed" and g1["src"] == new and os.path.isfile(new)
            for g in (g2, g1):
                if g is not None:
                    bank.restore(g["saved"])
            good = (g0 is None and w0.startswith(("refused R1: ", "refused R2: ")) and fed and g2 is not None
                    and same and not os.path.exists(new) and all(open(p).read() == t for p, t in texts.items()))
            print(f"control rolefeed {name} {'ok' if good else 'FAIL'}: off {w0 or 'gated'}; on "
                  f"{'gated via ' + g1['via'] if g1 is not None else w1}; off again {w2 or 'gated'}; exemplar object "
                  f"{'equal' if same else 'differs'}")
            fails += not good
        # T4.c2: `lui v0; li v0, 7; addiu v0, v0, %lo` (synthetic words): off pairs the li, on the v0-based %lo
        words, got = (0x3C028001, 0x24020007, 0x24421230), []
        for on in (False, True):
            bank.REPAIR.clear()
            bank.REPAIR.update({"rolefeed"} if on else set())
            got.append(table_addr(words))
        good = got == [0x80010007, 0x80011230]
        print(f"control rolefeed table_addr {'ok' if good else 'FAIL'}: off {got[0]:#x}, on {got[1]:#x}")
        fails += not good
    finally:
        bank.REPAIR.clear()
        bank.REPAIR.update(rep)
        bank.rf_where = where_fn
        globals().update(saved_fns)
        shutil.rmtree(d, ignore_errors=True)
        shutil.rmtree(os.path.join("build", d), ignore_errors=True)
    return fails


UC_FILES = {  # unitcut_control's plant: a whole unit whose exemplar uc_w (under its preamble's UC_K) has a predecessor uc_p
    "wu.c": "#include \"common.h\"\n#define UC_K 5\n\ns32 uc_p(s32 a) {\n    return a - 7;\n}\n\ns32 uc_w(s32 a) {\n"
            "    return a ^ UC_K;\n}\n",  # UC_K: the unit preamble the cut body carries (T6)
    "mu.c": f"#include \"common.h\"\n\n{RF_SLOT}\n"}
UC_BASE = 0x80010000  # the plant member's retail vram: its unit's first (and only) function, linked at -Ttext


def unitcut_control():
    """Repair switch unitcut (3.1 T6) through gate_member on planted files under .run/propagate/selftest/uc/: the
    member unit mu.c fed the whole unit wu.c (uc_p before the exemplar uc_w), gate() stubbed as rolefeed_control's
    (R1 make -B of the shared path or the marker's unit, R2 mu.c with the block in its slot), bank.rf_where stubbed.
    Per state the gated mu.c object is linked alone at UC_BASE (ld -Map build/<P>.map) and placement() read on it.
    Off -> gated, bank.uc_due false, `placed 0x... not 0x80010000` (shifted by uc_p); on -> gated via unitcut, src the
    new body, the map names uc_m at UC_BASE (placement ''), the exemplar object's bytes equal; saved restores every
    planted file byte-exact and deletes the new body. Returns fails."""
    d, log = os.path.join(SCRATCH, "selftest", "uc"), "selftest-unitcut"
    names = ("gate", "unit_of")
    saved_fns, where_fn = {n: globals()[n] for n in names}, bank.rf_where
    fails, rep, prog = 0, set(bank.REPAIR), os.path.join(SCRATCH, "selftest", "uc", "P")
    row = dict(name="uc_m", vram=f"0x{UC_BASE:08X}")
    try:
        shutil.rmtree(d, ignore_errors=True)
        os.makedirs(d)
        texts = {os.path.join(d, n): t for n, t in UC_FILES.items()}
        for p, t in texts.items():
            with open(p, "w") as f:
                f.write(t)
        src, mu = os.path.join(d, "wu.c"), os.path.join(d, "mu.c")
        new, exo, defines = os.path.join(d, "shared", "uc_w.c"), f"build/{src}.o", [("uc_w", "uc_m")]

        def stub_gate(prog_, vram, src_, defines_, log_):
            u = bank.rf_unit(src_)
            if bank.sh(["make", "-s", "-B", f"build/{u[1] if u else src_}.o"], log_):
                return None, "refused R1: standalone probe FAIL 0/1 words"
            saved = {}
            bank.put(saved, mu, texts[mu].replace(RF_SLOT, "\n".join(bank.block(src_, d, defines_))))
            if bank.sh(["make", "-s", "-B", f"build/{mu}.o"], log_):
                bank.restore(saved)
                return None, f"refused R2: build/{mu}.o does not compile (log {bank.LOGDIR}/{log_}.log)"
            return dict(prog=prog_, vram=vram, row=row, defines=defines_, saved=saved, h1="", src=src_, via="",
                        carved=False), ""

        def stub_where(ex, src_):
            for p in (new, src):
                lines = open(p).read().split("\n") if os.path.isfile(p) else []
                i = next((k for k, x in enumerate(lines) if re.match(rf"\w.* {ex[1]}\(.*\{{$", x)), None)
                if i is not None:
                    return p, i + 1, lines.index("}", i) + 1, [src], new
            return None

        globals().update(gate=stub_gate, unit_of=lambda prog_, vram: (mu, f"build/{mu}.o"))
        bank.rf_where = stub_where
        bank.sh(["make", "-s", "-B", exo], log)
        before = bank.obj_text(exo)
        got = []
        for on in (False, True):
            bank.REPAIR.clear()
            bank.REPAIR.update({"unitcut"} if on else set())
            due = bank.uc_due(("P", "uc_w"), src)
            g, w = gate_member(prog, UC_BASE, src, defines, log, False, ("P", "uc_w"))
            link = g is not None and not bank.sh(["mipsel-linux-gnu-ld", "-e", "uc_m", "-Ttext", f"0x{UC_BASE:08X}",
                                                  "-Map", f"build/{prog}.map", "-o", f"build/{prog}.elf",
                                                  f"build/{mu}.o"], log)
            import refusecause as rc  # lazy: refusecause imports this module
            got.append((due, g, w, placement(prog, row) if link else "no link",
                        link and UC_BASE in rc.map_addrs(prog, "uc_m")))
            if g is not None:
                bank.restore(g["saved"])
        (d0, g0, w0, p0, a0), (d1, g1, w1, p1, a1) = got
        same = os.path.isfile(exo) and bank.obj_text(exo) == before
        good = (not d0 and g0 is not None and p0.startswith("placed 0x") and p0.endswith(f" not 0x{UC_BASE:08X}")
                and not a0 and d1 and g1 is not None and g1["via"] == "unitcut" and g1["src"] == new and p1 == ""
                and a1 and same and not os.path.exists(new) and all(open(p).read() == t for p, t in texts.items()))
        print(f"control unitcut whole unit with predecessor {'ok' if good else 'FAIL'}: off "
              f"{('gated, ' + (p0 or 'at retail vram')) if g0 is not None else w0}; on "
              f"{('gated via ' + g1['via'] + ', ' + (p1 or 'at retail vram')) if g1 is not None else w1}; "
              f"exemplar object {'equal' if same else 'differs'}")
        fails += not good
    finally:
        bank.REPAIR.clear()
        bank.REPAIR.update(rep)
        bank.rf_where = where_fn
        globals().update(saved_fns)
        shutil.rmtree(d, ignore_errors=True)
        shutil.rmtree(os.path.join("build", d), ignore_errors=True)
    return fails


RD_BODY = ("#include \"common.h\"\n\nextern s16 D_80100000[];\nextern void func_80020000(void);\n\n"
           "void func_80030000(void) {\n    func_80020000();\n    D_80100000[5] = 1;\n    func_80020000();\n}\n")
RD_CASES = (  # (name, member unit, member bases {symbol: address} (callee: per call site), defines added with it on)
    ("rename", "nu", {"func_80020000": (0x80020400, 0x80020400), "D_80100000": 0x80100200},
     [("D_80100000", "D_80100200"), ("func_80020000", "func_80020400")]),
    ("identity", "nu", {"func_80020000": (0x80020000, 0x80020000), "D_80100000": 0x80100000}, []),
    ("unit alias", "mu", {"func_80020000": (0x80020400, 0x80020400), "D_80100000": 0x80100200},
     [("D_80100000", "D_80100200")]),
    ("conflict", "nu", {"func_80020000": (0x80020400, 0x80020800), "D_80100000": 0x80100200},
     [("D_80100000", "D_80100200")]))


def relocdef_control():
    """Repair switch relocdef (3.1 T5) through gate_members on a planted body compiled to a real object
    (.run/propagate/selftest/rd/bd.c: an R26 callee twice, a HI16/LO16 store at D_80100000+0xA). Retail words
    synthesized from the object's words with the exemplar's / member's targets patched in (probe.retail_words, ex_obj
    stubbed); gate_member stubbed (records the defines, gates). Cases: callee + data renamed (the data through its
    base, addend kept); identity; a member unit aliasing the callee above its INCLUDE_ASM (the real unit_aliases on a
    planted unit); two call sites with different deltas (no callee define). Each: off -> the name define only, no
    reloc key; on -> the name define + the expected reloc defines, `via relocdef` iff any. Returns fails."""
    import refusecause as rc  # lazy: refusecause imports this module
    d, log = os.path.join(SCRATCH, "selftest", "rd"), "selftest-relocdef"
    names = ("ex_obj", "gate_member", "unit_aliases")
    saved_fns, rw_fn, ua = {n: globals()[n] for n in names}, probe.retail_words, unit_aliases
    fails, rep = 0, set(bank.REPAIR)
    ex, m, exn = ("P", 0x80030000), ("P", 0x80040000), "func_80030000"
    try:
        shutil.rmtree(d, ignore_errors=True)
        os.makedirs(os.path.join(d, "src", "P"))
        body, obj = os.path.join(d, "bd.c"), f"build/{d}/bd.c.o"
        with open(body, "w") as f:
            f.write(RD_BODY)
        with open(os.path.join(d, "src", "P", "mu.c"), "w") as f:
            f.write(f"#define func_80020000 func_80020000\n{layout.asm_line('P', 'mu', 'rd_m')}\n")
        if bank.sh(["make", "-s", "-B", obj], log):
            print(f"control relocdef FAIL: {obj} does not compile")
            return 1
        rel, ow = rc.obj_relocs(obj, exn), probe.elf_function(obj, exn)[0]

        def words(bases):  # the object's words with each relocated field resolved at bases (+ the field's addend)
            w, seen = list(ow), {}
            for i, (k, s) in sorted(rel.items()):
                b = bases[s][seen.setdefault(s, [0])[0]] if isinstance(bases[s], tuple) else bases[s]
                if k == 4:
                    seen[s][0] += 1
                    w[i] = (ow[i] & 0xFC000000) | ((b + ((ow[i] & 0x03FFFFFF) << 2)) >> 2 & 0x03FFFFFF)
                elif k in (5, 6):
                    p = rc.partner(rel, i)
                    t = (b + rc.target(ow, i, k, p, 0)) & 0xFFFFFFFF
                    w[i] = (ow[i] & 0xFFFF0000) | ((t + 0x8000) >> 16 if k == 5 else t) & 0xFFFF
            return w

        exw = words({"func_80020000": (0x80020000, 0x80020000), "D_80100000": 0x80100000})
        globals().update(ex_obj=lambda ex_, tu: obj,
                         unit_aliases=lambda p, tu, fn, nm, root=None: ua(p, tu, fn, nm, os.path.join(d, "src")),
                         gate_member=lambda prog, vram, src, defines, log_, rec, ex_=None: (
                             dict(prog=prog, vram=vram, row={}, defines=defines, saved={}, h1="", src=src, via="",
                                  carved=False), ""))
        for name, tu, bases, want in RD_CASES:
            mw = words(bases)
            probe.retail_words = lambda prog, func, mw=mw: exw if func == exn else mw
            rows = {ex: dict(name=exn, tu="ex", vram="0x80030000"), m: dict(name="rd_m", tu=tu, vram="0x80040000")}
            ctx, got = (ex, exn, None, body, rows, False), []
            for on in (False, True):
                bank.REPAIR.clear()
                bank.REPAIR.update({"relocdef"} if on else set())
                res, gated = gate_members("P", [m], ctx, lambda s: None)
                g = gated[0] if gated else {}
                got.append((g.get("defines"), g.get("reloc", []), gated_lines("P", gated, body, lambda s: None)))
            (d0, r0, l0), (d1, r1, l1) = got
            via = [x[2].endswith(" via relocdef") for x in l0 + l1]
            good = (d0 == [(exn, "rd_m")] and not r0 and d1 == [(exn, "rd_m")] + want and r1 == want
                    and via == [False, bool(want)])
            print(f"control relocdef {name} {'ok' if good else 'FAIL'}: off {d0}; on {d1}")
            fails += not good
    finally:
        bank.REPAIR.clear()
        bank.REPAIR.update(rep)
        probe.retail_words = rw_fn
        globals().update(saved_fns)
        shutil.rmtree(d, ignore_errors=True)
        shutil.rmtree(os.path.join("build", d), ignore_errors=True)
    return fails


def inherited_control():
    """mark_inherited on a planted body (C0054: planted, never borrowed): a pin near column 80 and a goto each get a
    standalone marker above (never trailing) on the clang-formatted body (as tudecl_step), and a second clang-format
    pass leaves psxd_floor 0 unmarked. Returns fails."""
    sys.path.insert(0, os.path.dirname(HERE))
    import psxd_floor as pf
    src = "src/planted/inherited.c"
    body = ("void planted_inherited(int arg)\n{\n"
            "    register int planted_counter_long_name asm(\"$s0\") = arg + 0x1234 * 0x5678;\n"
            "    if (arg) goto planted_exit;\n    planted_counter_long_name++;\nplanted_exit:\n    return;\n}\n")
    unmarked = lambda t: sum(k.endswith("-unmarked") for k, _ in pf.marked(pf.raw_keywords(t), pf.markers(t)))
    fmt = lambda t: subprocess.run(["clang-format", "--style=file", "--assume-filename=src/planted_inherited.c"],
                                   input=t, capture_output=True, text=True)
    pre = fmt(body)  # tudecl_step marks a gm.fmt-formatted body
    out = mark_inherited(pre.stdout, src)
    note = f"// !FAKE: inherited from {src}"
    trailing = [ln for ln in out.split("\n") if note in ln and ln.strip() != note]
    fmt = fmt(out)
    good = (pre.returncode == 0 and unmarked(pre.stdout) == 2 and out.count(note) == 2 and not trailing
            and unmarked(out) == 0 and fmt.returncode == 0 and unmarked(fmt.stdout) == 0)
    print(f"control inherited marker {'ok' if good else 'FAIL'}: unmarked {unmarked(pre.stdout)} -> {unmarked(out)}, "
          f"{len(trailing)} trailing, clang-format rc {fmt.returncode} -> {unmarked(fmt.stdout)} unmarked")
    return not good


def self_test():
    d = os.path.join(SCRATCH, "selftest")
    os.makedirs(d, exist_ok=True)
    ex_rows = [t for _, t in registry_rows() if t[1] == t[3]]
    if not ex_rows:
        print(f"propagate: no exemplar row in {bank.REGISTRY}\nPROPAGATE SELF-TEST FAIL")
        return 1
    key, ex, src = ex_rows[0][:3]
    cls = load_classes()
    members = cls[key]
    rows = corpus_rows()
    outsider = next(m for m in sorted(rows) if m not in members and rows[m]["state"] == "c")
    other = next(k for k in sorted(cls) if k != key)
    exrow = " ".join(ex_rows[0][:5] + [ex_rows[0][5]]).rstrip()
    full = [exrow] + [f"{key} {ex} {src} {pv(m)} gated control" for m in members if pv(m) != ex]
    out_row = f"{key} {ex} {src} {pv(outsider)} gated control"
    with open(CLASSES) as f:  # drift: the outsider counted in the class, its built key is not the class key
        planted = [json.loads(line) for line in f]
    for c in planted:
        if c["kind"] == "dup" and c["key"] == key:
            c["members"] = sorted(c["members"] + [[outsider[0], f"0x{outsider[1]:08X}"]])
    pcls = os.path.join(d, "classes.jsonl")
    with open(pcls, "w") as f:
        f.write("".join(json.dumps(c) + "\n" for c in planted))
    controls = [  # (name, registry rows, classes, expect refusal kind or None, only that kind)
        ("clean", full, CLASSES, None),
        ("drift", full + [out_row], pcls, "drift"),
        ("missing member", full[:-1], CLASSES, "missing member"),
        ("not in class", full + [out_row], CLASSES, "not in class"),
        ("foreign key", [exrow.replace(key, other, 1)] + full[1:], CLASSES, "drift"),
    ]
    fails = 0
    for name, lines, cpath, want in controls:
        reg = os.path.join(d, "registry.txt")
        with open(reg, "w") as f:
            f.write(bank.REGISTRY_HEAD + "\n".join(lines) + "\n")
        rc, bad = check(reg, cpath, quiet=True)
        kinds = {b.split(" refused ", 1)[1].split(" ")[0] for b in bad}
        good = rc == 0 and not bad if want is None else rc != 0 and any(f" refused {want} " in b for b in bad)
        if name in ("drift", "missing member"):
            good &= kinds == {want.split()[0]}
        print(f"control {name} {'ok' if good else 'FAIL'}: rc {rc}, {len(bad)} refusals"
              + (f", first: {next((b for b in bad if want in b), bad[0])}" if bad else ""))
        fails += not good
    ms = [pv(m) for m in members if pv(m) != ex][:2]  # --expect-registry controls on planted rows and verdicts
    if len(ms) < 2:
        print(f"control expect FAIL: class {key} has < 2 non-exemplar members")
        fails += 1
    else:
        reg = os.path.join(d, "registry.txt")
        with open(reg, "w") as f:
            f.write(bank.REGISTRY_HEAD + "\n".join([exrow, f"{key} {ex} {src} {ms[0]} refused R5: control",
                                                    f"{key} {ex} {src} {ms[1]} gated control"]) + "\n")
        pre = "preflight: state c-empty, not include_asm"
        for name, res, want, sts in (
                ("expect agree", [(ex, "gated", ""), (ms[0], "refused", "R5: x")], 0, {}),
                ("expect drift", [(ex, "gated", ""), (ms[1], "refused", "R5: x")], 1, {}),
                ("expect c-empty exemplar", [(ex, "refused", pre), (ms[0], "refused", "R5: x")], 0,
                 {ex: "c-empty"})):
            drift, unrowed = expect_drift(key, res, reg, sts)
            rc = 1 if drift or unrowed else 0
            want_drift = [] if want == 0 else [f"PROPAGATE DRIFT {key} {ms[1]} gated -> refused"]
            good = rc == want and drift == want_drift
            print(f"control {name} {'ok' if good else 'FAIL'}: rc {rc}, {len(drift)} drift"
                  + (f", {drift[0]}" if drift else ""))
            fails += not good
    fails += grouped_controls(d, cls)
    fails += bisect_control()
    ud =os.path.join(d, "src", "p")  # plant: the unit's own alias above the INCLUDE_ASM suppresses the identity define
    os.makedirs(ud, exist_ok=True)
    with open(os.path.join(ud, "u.c"), "w") as f:
        f.write(f'#define D_1 D_1_x4\n{layout.asm_line("p", "u", "f")}\n\n{layout.asm_line("p", "u", "g")}\n')
    want = [("f", "D_1"), ("f", "D_2"), ("g", "D_1")]
    got = [unit_aliases("p", "u", fn, nm, os.path.join(d, "src")) for fn, nm in want]
    good = got == [True, False, False]
    print(f"control unit alias {'ok' if good else 'FAIL'}: {got}")
    fails += not good
    try:  # second pass: the planted unit as a layout.role_tree thin wrapper; the alias read from the role file
        with layout.role_tree("p", "u", d) as role:
            got = [unit_aliases("p", "u", fn, nm, os.path.join(d, "src")) for fn, nm in want]
        good = got == [True, False, False]
        print(f"role-tree control unit alias {'ok' if good else 'FAIL'}: {got} ({role})")
    except layout.Refuse as e:
        good = False
        print(f"role-tree control unit alias FAIL: {e}")
    fails += not good
    fails += inherited_control()
    fails += declunify_control()
    fails += rolefeed_control()
    fails += relocdef_control()
    fails += unitcut_control()
    if fails:
        print(f"PROPAGATE SELF-TEST FAIL {fails}")
        return 1
    print("PROPAGATE CONTROL OK")
    return 0


# ---- equivalence: per-key vs grouped dry run (T3.c1) ----------------------------------------------------------------

EQUIV_KEYS = "config/equiv-keys.txt"
EQUIV_PER = 6  # keys per stratum
MEMBER_RE = re.compile(r"^(\S+:0x[0-9A-Fa-f]+) (gated|refused|pending)(?: (\S+))?")
VERDICT_RE = re.compile(r"^PROPAGATE DRY-RUN (\S+) gated (\d+) of (\d+) members$")


def equiv_pick(reg=bank.REGISTRY, path=EQUIV_KEYS):
    """Write path: registry keys (PROPAGATE_KEYS_CMD's filter) in 4 strata (SLUS member? x refused row?), each pool
    limited to keys with non-exemplar member rows (T3.c2: refused strata need a refused row and, where any key in the
    stratum has one, a gated non-exemplar row; gated strata need a gated non-exemplar row); per stratum the first
    EQUIV_PER by (row count, key). Returns rc."""
    keys = {}  # key -> [rows, slus, refused rows, gated non-exemplar rows]
    with open(reg) as f:
        for line in f:
            c = line.split()
            if line.startswith("#") or len(c) < 5 or (len(c) > 5 and c[5] == "family"):
                continue
            k = keys.setdefault(c[0], [0, False, 0, 0])
            k[0] += 1
            k[1] |= c[3].startswith("SLUS_013.95:")
            k[2] += c[4] == "refused"
            k[3] += c[4] == "gated" and (len(c) < 6 or c[5] != "exemplar")
    out = [f"# {path} -- keys of propagate.py --equiv (per-key vs grouped dry run); written by propagate.py "
           f"--equiv-pick, never by hand.",
           f"# Picked from {reg} (rows: non-comment, >= 5 fields, field 6 != family) in 4 strata (any SLUS_013.95 "
           f"member? x any refused row?);",
           f"# pool per stratum: keys with a non-exemplar member row (field 6 != exemplar) -- refused strata: >= 1 "
           f"refused row and >= 1 gated non-exemplar row,",
           f"# else (no such key in the stratum) >= 1 refused row; gated strata: >= 1 gated non-exemplar row;",
           f"# per stratum the first {EQUIV_PER} pool keys by (row count, key) ascending. Deterministic: a re-run on "
           f"the same registry gives this file."]
    for slus in (True, False):
        for refd in (True, False):
            st = {k: v for k, v in keys.items() if v[1] == slus and bool(v[2]) == refd}
            both = {k: v for k, v in st.items() if v[2] and v[3]}
            pool = (both or st) if refd else {k: v for k, v in st.items() if v[3]}
            ks = sorted((v[0], k) for k, v in pool.items())
            rule = ("refused+gated" if both else "refused only") if refd else "gated non-exemplar"
            out.append(f"# stratum slus={'yes' if slus else 'no'} refused={'yes' if refd else 'no'}: "
                       f"{min(EQUIV_PER, len(ks))} of {len(ks)} pool keys ({rule}; {len(st)} in stratum)")
            out += [k for _, k in ks[:EQUIV_PER]]
    with open(path, "w") as f:
        f.write("\n".join(out) + "\n")
    print(f"EQUIV PICK {sum(not x.startswith('#') for x in out)} keys -> {path}")
    return 0


def equiv_parse(text):
    """{key: ((m, n), {member pv: (state, reason code)})}: member lines attributed to the next verdict line."""
    res, pending = {}, {}
    for line in text.splitlines():
        v = VERDICT_RE.match(line)
        if v:
            res[v.group(1)] = ((int(v.group(2)), int(v.group(3))), pending)
            pending = {}
            continue
        mm = MEMBER_RE.match(line)
        if mm:
            tok = mm.group(3) or ""
            code = tok if re.match(r"^(R\d+:|preflight:)$", tok) else "-"
            pending[mm.group(1)] = (mm.group(2), code)
    return res


def equiv_compare(per_text, grp_text, keys):
    """(lines, rc) of the per-key vs grouped outputs over keys."""
    a, b = equiv_parse(per_text), equiv_parse(grp_text)
    fmt = lambda v: "missing" if v is None else f"{v[0]}/{v[1]}"  # noqa: E731
    diffs, members, mix = [], 0, {"gated": 0, "refused": 0, "pending": 0}
    for key in keys:
        if key not in a or key not in b:
            diffs.append(f"EQUIV DIFF {key} - per-key {'ok' if key in a else 'missing'} grouped "
                         f"{'ok' if key in b else 'missing'}")
            continue
        (mna, va), (mnb, vb) = a[key], b[key]
        if mna != mnb:
            diffs.append(f"EQUIV DIFF {key} - per-key gated {mna[0]} of {mna[1]} grouped gated {mnb[0]} of {mnb[1]}")
        for p in sorted(set(va) | set(vb)):
            members += 1
            mix[(va.get(p) or vb.get(p))[0]] += 1
            if va.get(p) != vb.get(p):
                diffs.append(f"EQUIV DIFF {key} {p} per-key {fmt(va.get(p))} grouped {fmt(vb.get(p))}")
    g, r = mix["gated"], mix["refused"]
    head = diffs + [f"EQUIV mix gated {g} refused {r} pending {mix['pending']} (compared member verdicts)"]
    if diffs:
        return head + [f"EQUIV differ {len(diffs)} of {members} members ({len(keys)} keys)"], 1
    if not g or not r:  # a vacuous sample never prints identical (T3.c2)
        return head + [f"EQUIV EMPTY gated {g} refused {r}"], 1
    return head + [f"EQUIV identical {len(keys)} keys {members} members"], 0


def equiv_keys(path):
    with open(path) as f:
        return list(dict.fromkeys(k for k in (line.strip() for line in f) if k and not k.startswith("#")))


def equiv(path):
    """Per key a `<key> --dry-run --expect-registry` subprocess (serially), then one grouped subprocess over all keys;
    never two at once (they share TREE). Compare verdicts; rc 0 iff identical."""
    keys = equiv_keys(path)
    me = [sys.executable, os.path.abspath(__file__)] + [f"--repair={r}" for r in sorted(bank.REPAIR)]  # T3: switches carry over
    t0, per, rcs = time.time(), [], []
    for key in keys:
        p = subprocess.run(me + [key, "--dry-run", "--expect-registry"], stdout=subprocess.PIPE,
                           stderr=subprocess.STDOUT, text=True)
        per.append(p.stdout)
        rcs.append(p.returncode)
    t1 = time.time()
    g = subprocess.run(me + ["--dry-run", "--expect-registry", "--keys-from", "-"], input="\n".join(keys) + "\n",
                       stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True)
    t2 = time.time()
    print(f"equiv: per-key {len(keys)} runs, rc nonzero {sum(r != 0 for r in rcs)}, wall {t1 - t0:.0f}s")
    print(f"equiv: grouped rc {g.returncode}, wall {t2 - t1:.0f}s")
    print("\n".join(x for x in g.stdout.splitlines() if x.startswith("PROPAGATE GROUP ")))  # T3.c2: group evidence
    lines, rc = equiv_compare("\n".join(per), g.stdout, keys)
    print("\n".join(lines))
    return rc


def equiv_self_test():
    """Pure text: the comparator on a synthetic pair (identical), then with one verdict flipped and one member
    dropped (both must differ), then an all-refused pair (vacuous: must be EMPTY)."""
    k1, k2 = "a" * 40, "b" * 40
    m1 = ["SLUS_013.95:0x80010000 gated exemplar", "SLUS_013.95:0x80010100 gated define f=g",
          "ST00_00.ARC:0x80120000 refused R3: diff 4 words"]
    m2 = ["ST01_00.ARC:0x80130000 gated exemplar", "ST01_00.ARC:0x80130200 refused preflight: no corpus row"]
    per = "\n".join(["propagate: dry run wall 3s; src/ + registry sha1 0123456789ab unchanged"] + m1
                    + [f"PROPAGATE DRY-RUN {k1} gated 2 of 3 members"] + m2
                    + [f"PROPAGATE DRY-RUN {k2} gated 1 of 2 members", f"PROPAGATE DRIFT {k2} x gated -> refused"])
    grp = lambda a, b: "\n".join(  # noqa: E731
        ["propagate: grouped 2 keys, 3 programs, 2 trees", "PROPAGATE GROUP ST00_00.ARC units 1 isolated 1 "
         "fallback no wall 9s"] + a + [f"PROPAGATE DRY-RUN {k1} gated 2 of 3 members"] + b
        + [f"PROPAGATE DRY-RUN {k2} gated 1 of 2 members", "PROPAGATE DRY-RUN GROUPED 2 of 2 keys; drift 0"])
    flip = m1[:2] + ["ST00_00.ARC:0x80120000 refused R4: diff 4 words"]
    v1, v2 = ["ST00_00.ARC:0x80120000 refused R3: diff 4 words"], ["ST01_00.ARC:0x80130200 refused preflight: x"]
    vper = "\n".join(v1 + [f"PROPAGATE DRY-RUN {k1} gated 0 of 1 members"] + v2
                     + [f"PROPAGATE DRY-RUN {k2} gated 0 of 1 members"])
    vgrp = "propagate: grouped 2 keys, 2 programs, 2 trees\n" + vper  # identical verdicts: only the mix is vacuous
    fails = 0
    for name, pt, g, want, last in (("identical", per, grp(m1, m2), 0, "EQUIV identical"),
                                    ("flipped verdict", per, grp(flip, m2), 1, "EQUIV differ"),
                                    ("dropped member", per, grp(m1, m2[:1]), 1, "EQUIV differ"),
                                    ("vacuous all-refused", vper, vgrp, 1, "EQUIV EMPTY")):  # T3.c2
        lines, rc = equiv_compare(pt, g, [k1, k2])
        good = rc == want and lines[-1].startswith(last)
        print(f"control {name} {'ok' if good else 'FAIL'}: rc {rc}; " + "; ".join(lines))
        fails += not good
    if fails:
        print(f"EQUIV SELF-TEST FAIL {fails}")
        return 1
    print("EQUIV CONTROL OK")
    return 0


def main():
    root = os.path.abspath(os.path.join(HERE, "..", ".."))
    os.chdir(root)
    ap = argparse.ArgumentParser(description=__doc__.split("\n", 1)[0])
    ap.add_argument("key", nargs="?")
    ap.add_argument("--dry-run", action="store_true")
    ap.add_argument("--expect-registry", action="store_true")
    ap.add_argument("--check", action="store_true")
    ap.add_argument("--self-test", action="store_true")
    ap.add_argument("--keys-from", metavar="FILE|-", help="grouped dry run of these keys (with --dry-run "
                    "--expect-registry, no <dup key>)")
    ap.add_argument("--equiv", metavar="FILE", help="per-key vs grouped dry run of FILE's keys: `EQUIV identical`")
    ap.add_argument("--equiv-pick", action="store_true", help=f"write {EQUIV_KEYS} (stratified registry keys)")
    ap.add_argument("--equiv-self-test", action="store_true", help="the --equiv comparator on planted text")
    bank.repair_arg(ap)
    a = ap.parse_args()
    bank.repair_set(a)
    if a.self_test:
        return self_test()
    if a.equiv_self_test:
        return equiv_self_test()
    if a.equiv_pick:
        return equiv_pick()
    if a.equiv:
        if a.key or a.keys_from:
            ap.error("--equiv excludes <dup key> and --keys-from")
        return equiv(a.equiv)
    if a.check:
        return check()[0]
    if a.expect_registry and not a.dry_run:
        ap.error("--expect-registry needs --dry-run")
    if a.keys_from:
        if a.key or not a.expect_registry:
            ap.error("--keys-from needs --dry-run --expect-registry and no <dup key>")
        with (sys.stdin if a.keys_from == "-" else open(a.keys_from)) as f:
            keys = list(dict.fromkeys(k for k in (line.strip() for line in f) if k))
        return grouped(keys)
    if not a.key:
        ap.error("need <dup key> [--dry-run], --check or --self-test")
    t0 = time.time()
    if not a.dry_run:
        m, n, _ = propagate(a.key, False)
        print(f"PROPAGATE {a.key} gated {m} of {n} members")
        return 0 if m == n else 1
    watch = ["src", bank.REGISTRY]
    before = tree_sha(watch)
    shutil.rmtree(TREE, ignore_errors=True)
    m, n, results = propagate(a.key, True)
    after = tree_sha(watch)
    print(f"propagate: dry run wall {time.time() - t0:.0f}s; src/ + registry sha1 {after[:12]} "
          f"{'unchanged' if after == before else 'CHANGED from ' + before[:12]}")
    print(f"PROPAGATE DRY-RUN {a.key} gated {m} of {n} members")
    if a.expect_registry:
        drift, unrowed = expect_drift(a.key, results)
        if drift:
            print("\n".join(drift))
        return 0 if not drift and not unrowed and after == before else 1
    return 0 if m == n and after == before else 1


if __name__ == "__main__":
    sys.exit(main())
