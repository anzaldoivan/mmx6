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
         A group R1-R4 refusal (preflight excepted) or a red group R5 -> restore, re-run those units (all of them on a
         red R5) isolated. Per program `PROPAGATE GROUP <prog> units <u> isolated <i> fallback yes|no wall <s>s`; per
         key the per-key lines (member lines, `PROPAGATE DRY-RUN <key> gated m of n members`, DRIFT lines); last
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
         INCLUDE_ASM -> the identity define dropped; grouped (plan on planted rows, planted verdicts): a gated exemplar
         row refused inside a 2+-key group -> DRIFT, rc 1; a refused member row -> its unit isolated, agrees, rc 0;
         exemplar row removed -> planned with the rows' named exemplar; rows disagreeing on it -> setup error;
         mark_inherited on a planted body (pin near column 80, a goto) -> standalone markers above, none trailing,
         psxd_floor 0 unmarked, again after a second pass of the repo clang-format. Ends `PROPAGATE CONTROL OK` (rc 0), else rc 1.
Firewall G12: names, addresses, counts and hashes of our own files only.
"""
import argparse
import hashlib
import json
import multiprocessing
import os
import re
import shutil
import subprocess
import sys
import time

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import bank  # noqa: E402
import census  # noqa: E402
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
    """Address of the first lui + following lw/addiu pair in words, or None."""
    hi = None
    for w in words:
        if hi is None and w >> 26 == 0x0F:
            hi = (w & 0xFFFF) << 16
        elif hi is not None and w >> 26 in LOAD_OPS:
            lo = w & 0xFFFF
            return (hi + (lo - 0x10000 if lo & 0x8000 else lo)) & 0xFFFFFFFF
    return None


def extent_same(prog, row):
    """Linked bytes of the member's extent == retail bytes (unmasked)."""
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
    """True when the `#define` lines directly above func's INCLUDE_ASM line in <root>/<prog>/<tu>.c define name (T40.c1)."""
    try:
        with open(f"{root}/{prog}/{tu}.c") as f:
            lines = f.read().split("\n")
    except OSError:
        return False
    at = f'INCLUDE_ASM("asm/{prog}/nonmatchings/{tu}", {func});'
    for i, line in enumerate(lines):
        if line == at:
            j = i - 1
            while j >= 0 and lines[j].startswith("#define "):
                if lines[j].split()[1] == name:
                    return True
                j -= 1
    return False


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


def gate_member(prog, vram, src, defines, log, rec):
    """gate(); when rec (real run, T40.21.c2) gate.py's recovery steps on a stop: R4 `rodata needs placement (+N
    bytes)` -> rodata_step, R2 `does not compile` -> tudecl_step. A recovered record's saved covers its copy/carve."""
    at = log_size(log)
    g, why = gate(prog, vram, src, defines, log)
    if g is not None or not rec:
        return g, why
    import gate as gm  # lazy: gate.py imports this module
    mo = gm.RODATA_RE.match(why[len("refused R4: "):]) if why.startswith("refused R4: ") else None
    if mo:
        return rodata_step(prog, vram, src, defines, log, int(mo.group(1)), why)
    if why.startswith("refused R2: ") and " does not compile " in why:
        return tudecl_step(prog, vram, src, defines, log, log_tail(log, at), why)
    return g, why


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
    copy = f"src/shared/{prog}/{func}.c"
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
    """Raise bank.Stop unless the program is green from a clean rebuild and every gated extent equals retail."""
    bank.rung5(prog, gated[0]["src"], gated[0]["h1"], log)
    moved = [g["src"] for g in gated[1:] if g["src"] != gated[0]["src"] and bank.sha1(g["src"]) != g["h1"]]
    if moved:
        raise bank.Stop(5, f"body sha1 changed since R1 ({moved[0]})")
    bad = [pv((g["prog"], g["vram"])) for g in gated if not extent_same(prog, g["row"])]
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
                g, why = gate_member(prog, g0["vram"], src, g0["defines"], log, rec)
                if g is not None:
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
        g, why = gate_member(prog, m[1], src, defines, log, rec)
        if g is None:
            results.append((pv(m), "refused", why[len("refused "):]))
            out(f"{pv(m)} {why}")
        else:
            gated.append(g)
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


def run_group(prog, units):
    """({key: (results, lines)}, GROUP line, notes) of one program in this tree: isolated units first (run_prog from
    the pristine program, then restored); then the group (R1-R4 per member, one program_r5 over all its gated); a
    group R1-R4 refusal (preflight excepted) or a red group R5 -> restore, re-run those units (all on a red R5) isolated.
    The tree is left with the program's edits restored."""
    t0, log, out, notes = time.time(), f"propagate-{prog}", {}, []

    def isolated(key, ms, ctx):
        lines, keep = [], []
        res = run_prog(prog, ms, ctx, lines.append, keep=keep)
        restore_prog(prog, keep, log)
        out[key] = (res, lines)

    for key, ms, ctx, iso in units:
        if iso:
            isolated(key, ms, ctx)
    group = [(key, ms, ctx) for key, ms, ctx, iso in units if not iso]
    done, all_gated = [], []
    for key, ms, ctx in group:
        lines = []
        res, gated = gate_members(prog, ms, ctx, lines.append)
        done.append((key, ms, ctx, res, gated, lines))
        all_gated += gated
    affected = {key for key, _, _, res, _, _ in done if any(not r.startswith("preflight:") for _, _, r in res)}
    if all_gated:
        try:
            program_r5(prog, None, all_gated, log)
        except bank.Stop as e:
            notes.append(f"propagate: {prog} group R5 {e.cause}; isolating {len(group)} units")
            affected = {key for key, _, _ in group}
    fallback = bool(affected)
    if all_gated:
        restore_prog(prog, all_gated, log)
    for key, ms, ctx, res, gated, lines in done:
        if key in affected:
            isolated(key, ms, ctx)
        else:
            out[key] = (res + gated_lines(prog, gated, ctx[3], lines.append), lines)
    n_iso = sum(iso for *_, iso in units)
    return out, (f"PROPAGATE GROUP {prog} units {len(units)} isolated {n_iso} fallback {'yes' if fallback else 'no'}"
                 f" wall {time.time() - t0:.0f}s"), notes


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
    ud = os.path.join(d, "src", "p")  # plant: the unit's own alias above the INCLUDE_ASM suppresses the identity define
    os.makedirs(ud, exist_ok=True)
    with open(os.path.join(ud, "u.c"), "w") as f:
        f.write('#define D_1 D_1_x4\nINCLUDE_ASM("asm/p/nonmatchings/u", f);\n\nINCLUDE_ASM("asm/p/nonmatchings/u", g);\n')
    got = [unit_aliases("p", "u", fn, nm, os.path.join(d, "src")) for fn, nm in (("f", "D_1"), ("f", "D_2"), ("g", "D_1"))]
    good = got == [True, False, False]
    print(f"control unit alias {'ok' if good else 'FAIL'}: {got}")
    fails += not good
    fails += inherited_control()
    if fails:
        print(f"PROPAGATE SELF-TEST FAIL {fails}")
        return 1
    print("PROPAGATE CONTROL OK")
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
    a = ap.parse_args()
    if a.self_test:
        return self_test()
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
