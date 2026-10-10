#!/usr/bin/env python3
"""scaffold.py -- the scaffold lane: m2c-scaffold, compile and masked-score every asm function (container, stdlib only).

  scaffold.py --all [-j N] [--limit K] [--prog P] [--jsonl PATH] [--packs DIR]
      -> per build/corpus/functions.jsonl row with state asm|include_asm (sorted by (prog, vram); --prog keeps one
         program; --limit K = a deterministic stride sample of K rows): m2c scaffold (decompile.py's command plus
         `--valid-syntax`) -> one fixed normalisation pass (`#include "common.h"`, a fixed #define prelude for
         NULL/s64/u64/f32/f64 and m2c's M2C_UNK*/M2C_FIELD/M2C_BITWISE, each only when used, m2c `?` types -> s32, top-level data
         definitions -> extern declarations; no per-function fixes) -> compiled through the product C
         rule (`make build/<src>.o` with the TU's cc1 flags as CFLAGS_<func>, as probe.draft_cflags/compile_obj do;
         Makefile TRIPLE) -> masked comparison vs the retail words (corpus extent, trimmed as probe.trim; relocated
         fields masked as probe.probe). One row per function appended to PATH (default build/scaffold/scaffold.jsonl)
         `{pv,func,words,score,n,state}`: state match|compile|nocompile, score = masked mismatches
         (max(retail, ours) - matched; 0 iff probe MATCH), null when nocompile; n = retail words (trimmed).
         Scaffold C kept at <dir of PATH>/src/<prog>/<func>.c. Resumable: pvs already in PATH are skipped. -j workers
         (default nproc). Last lines `SCAFFOLD RATE <k> functions in <s> s (<r>/s)` and
         `SCAFFOLD <done> of <a>: match <m> compile <c> nocompile <x>` (over the selected rows).
      --packs DIR (with or without --all): every match row of PATH -> a gate pack DIR/W0/<prog>_<func>/ (pack.json
         {pv,prog,func,tu,words}, draft.c = the kept scaffold C, verdict.json {pv,status:match,score:0,lever:-,
         notes:m2c scaffold}); gate them with `gate.py --wave W0 --root DIR`. Line `SCAFFOLD PACKS <k> in DIR/W0`.
         Never calls bank.py. --wave W (default W0): packs go to DIR/W/ instead.
  scaffold.py --undrawn [--ledger campaign/ledger.tsv] [--decls] [-j N] [--limit K] [--prog P] [--jsonl PATH]
      -> as --all, over the ledger rows whose blocker (col 7) is `undrawn` (their corpus rows; a ledger pv without one
         prints `SCAFFOLD UNDRAWN MISSING <pv>`).
      --decls (with --all|--undrawn): per function v0 = the fixed pass above, v1 = v0 with each top-level
         prototype/extern of a name the definition uses moved to the program's prevailing spelling (gate.declsync_fix:
         most common over declsync.unit_files; `#define M2C_UNK s32` when it uses M2C_UNK; a spelling bringing
         struct/union/enum/typedef is not taken), then, on `too few|many arguments`, those calls cast unprototyped
         (gate.cast_fix, C0124). The better is kept and recorded (match, then lower score, then compile over
         nocompile; tie -> v0), row + `"variant": "v0"|"v1"`; line `SCAFFOLD VARIANTS v1 <k> of <a>: match <m> compile
         <c> nocompile <x>` (a v1 match is one v0 did not match) before the summary.
  scaffold.py --merge LANEJSONL
      -> rewrite campaign/scaffold/scaffold.jsonl: each row whose pv has a LANEJSONL row replaced by it (file order
         kept), new pvs appended. Line `SCAFFOLD MERGE <k> replaced <a> appended`.
  scaffold.py --self-test
      -> in build/scaffold/selftest/: three c-empty functions (banked C, so they stay; retail words from their corpus
         rows) get planted .s files (generic `jr $ra` + delay slot, run through m2c directly): the trivial one must
         score 0 (match; retail extent checked against probe.retail_words), the one-word mutation (delay slot
         `addiu $v0, $zero, 1`) > 0, a planted syntax error nocompile; a re-run adds no rows; --packs writes exactly
         the match's pack; a planted ledger selects only its undrawn rows; a fourth c-empty function's planted body
         (two calls of a real >= 3-param prevailing prototype with 2 and 1 args, in a folded branch; scored vs the
         planted FOLDED words) is v0 nocompile and --decls v1 match (prevailing spelling + cast kept), the trivial one
         stays v0; --packs --wave W9 writes
         both; --merge on planted jsonl replaces 1, appends 1.
         Ends `SCAFFOLD CONTROL OK` (rc 0) | `SCAFFOLD CONTROL FAIL <cases>` (rc 1).
Firewall G12: scaffold C, packs and planted asm stay in ignored build/ (and the caller's waves/ DIR); prints names,
addresses and counts only.
"""
import argparse
import functools
import glob
import json
import multiprocessing
import os
import re
import shutil
import struct
import subprocess
import sys
import time

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(os.path.dirname(HERE))
sys.path.insert(0, HERE)
import cards  # noqa: E402  (Makefile TRIPLE)
import decompile  # noqa: E402  (M2C)
import declsync  # noqa: E402  (unit_files: the prevailing-spelling scope)
import dumps  # noqa: E402  (the C rule's dry-run recipe)
import gate  # noqa: E402  (declsync_fix, cast_fix, decls: --decls' v1; imported, never bank.py run)
import probe  # noqa: E402

CORPUS = probe.CORPUS
JSONL = "build/scaffold/scaffold.jsonl"
SELFTEST = "build/scaffold/selftest"
# The fixed prelude: a line is emitted only when its name occurs in the scaffold (or in an emitted line), as #define,
# never typedef (bank's typecheck.py refuses a typedef outside include/mmx6/). m2c --valid-syntax names follow
# m2c_macros.h; its placeholders (M2C_ERROR, MULT_HI, ...) stay undefined, so a scaffold holding one is nocompile.
PRELUDE = (("NULL", "#define NULL ((void *)0)"),
           ("s64", "#define s64 long long"),
           ("u64", "#define u64 unsigned long long"),
           ("f32", "#define f32 float"),
           ("f64", "#define f64 double"),
           ("M2C_UNK", "#define M2C_UNK s32"),
           ("M2C_UNK8", "#define M2C_UNK8 s8"),
           ("M2C_UNK16", "#define M2C_UNK16 s16"),
           ("M2C_UNK32", "#define M2C_UNK32 s32"),
           ("M2C_UNK64", "#define M2C_UNK64 s64"),
           ("M2C_FIELD", "#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))"),
           ("M2C_BITWISE", "#define M2C_BITWISE(type, expr) ((type)(expr))"))
Q_LINE = re.compile(r"^(\s*(?:extern\s+|static\s+)*)\?(?=[\s*])", re.M)   # `? func(…);`, `extern ? D_…;`, `? var;`
Q_CAST = re.compile(r"([(,]\s*)\?(?=\s*[*),])")                          # `(?)`, `(? *)`, `, ?` in parameter lists
SKIP = re.compile(r'"(?:\\.|[^"\\])*"|\'(?:\\.|[^\'\\])*\'|/\*.*?\*/|//[^\n]*', re.S)
ARITY_RE = re.compile(r"too (?:few|many) arguments to function")    # the only conflict --decls casts (C0124)
TYPEKW = re.compile(r"\b(?:struct|union|enum|typedef)\b")           # never brought into a scaffold (bank R3)
LEDGER = "campaign/ledger.tsv"
MERGED = "campaign/scaffold/scaffold.jsonl"


def top_level(text):
    """[(start, end, kind)] of top-level items: kind 'decl' ends at a depth-0 `;`, 'body' at the `}` closing to 0."""
    items, depth, start, i = [], 0, 0, 0
    while i < len(text):
        m = SKIP.match(text, i)
        if m:
            i = m.end()
            continue
        ch = text[i]
        if ch == "{":
            depth += 1
        elif ch == "}":
            depth -= 1
            if depth == 0 and not re.match(r"[ \t]*[A-Za-z_*;=,]", text[i + 1:]):  # `} X;`, `};` continue
                items.append((start, i + 1, "body"))
                start = i + 1
        elif ch == ";" and depth == 0:
            items.append((start, i + 1, "decl"))
            start = i + 1
        i += 1
    return items, start


def normalise(m2c):
    """The one fixed pass: prelude, `?` -> s32, top-level initialised data definitions -> extern declarations."""
    text = Q_LINE.sub(r"\1s32", m2c)
    text = Q_CAST.sub(r"\1s32", text)
    items, tail = top_level(text)
    out, pos = [], 0
    for s, e, kind in items:
        stmt = text[s:e]
        head = SKIP.sub(lambda m: m.group(0) if m.group(0)[0] in "\"'" else " ", stmt)
        if kind == "decl" and "=" in head and "(" not in head.split("=", 1)[0]:
            lead = stmt[: len(stmt) - len(stmt.lstrip())]
            decl = " ".join(head.split("=", 1)[0].split())
            decl = re.sub(r"^(?:static\s+|extern\s+)*", "", decl)
            out.append(text[pos:s] + lead + "extern " + decl + ";")
            pos = e
    out.append(text[pos:])
    body = "".join(out)
    used = body
    for _ in range(2):  # a selected line may name another (M2C_UNK64 -> s64)
        lines = [line for name, line in PRELUDE if re.search(rf"\b{name}\b", used)]
        used = body + "\n".join(lines)
    return "#include \"common.h\"\n\n" + "".join(line + "\n" for line in lines) + ("\n" if lines else "") + body


# ---- one function (worker) ---------------------------------------------------------------------------------------

@functools.lru_cache(maxsize=None)
def layout(prog):
    return probe.yaml_layout(prog)


def retail(prog, vram, end):
    """Trimmed retail words of [vram, end) (the corpus extent; probe.find_extent's corpus fallback)."""
    target, seg_start, seg_vram = layout(prog)
    n = (end - vram) // 4
    with open(target, "rb") as f:
        f.seek(seg_start + vram - seg_vram)
        data = f.read(4 * n)
    if len(data) != 4 * n:
        raise RuntimeError(f"{target} short read")
    return probe.trim(list(struct.unpack(f"<{n}I", data)))


@functools.lru_cache(maxsize=None)
def tu_cflags(prog, tu, triple):
    """The TU's cc1 args from the C rule's dry-run recipe (probe.draft_cflags' source), None for a non-C TU."""
    tu_c = f"src/{prog}/{tu}.c"
    if not os.path.isfile(tu_c):
        return None
    return tuple(dumps.recipe(tu_c, [f"TRIPLE={triple}"])[1][1:])


def m2c_text(job):
    """(rc, stdout) of the m2c scaffold: decompile.py's command (its .s + the TU's data .s, `-t mipsel-gcc-c -f`)
    plus `--valid-syntax` (untyped field access as M2C_FIELD, defined in PRELUDE), or m2c on a planted .s."""
    files = [job["asm"]] if job.get("asm") else \
        sorted(glob.glob(f"asm/{job['prog']}/nonmatchings/**/{job['func']}.s", recursive=True))[:1]
    if not files:
        return 2, ""
    tu = os.path.basename(os.path.dirname(files[0]))
    data = [] if job.get("asm") else sorted(glob.glob(f"asm/{job['prog']}/data/{tu}.*.s"))
    cmd = [sys.executable, decompile.M2C, "-t", "mipsel-gcc-c", "--valid-syntax", "-f", job["func"], *files, *data]
    p = subprocess.run(cmd, capture_output=True, text=True)
    return p.returncode, p.stdout


def build_score(job, ret, src, c):
    """(state, score, compiler stderr) of the C text c written at src, compiled and masked-scored vs ret."""
    prog, func = job["prog"], job["func"]
    with open(src, "w") as f:
        f.write(c)
    obj = f"build/{src}.o"
    if os.path.exists(obj):
        os.remove(obj)
    flags = tu_cflags(prog, job["tu"], job["triple"])
    over = [f"CFLAGS_{func}={' '.join(flags)}"] if flags else []
    p = subprocess.run(["make", "-s", f"TRIPLE={job['triple']}", obj] + over,
                       stdout=subprocess.DEVNULL, stderr=subprocess.PIPE, text=True, errors="replace")
    if p.returncode or not os.path.isfile(obj):
        return "nocompile", None, p.stderr
    try:
        ours, masks = probe.elf_function(obj, func)
    except SystemExit:
        return "nocompile", None, p.stderr
    finally:
        os.remove(obj)
    matched = 0
    for i in range(min(len(ret), len(ours))):
        keep = ~masks.get(i, 0) & 0xFFFFFFFF
        matched += (ret[i] & keep) == (ours[i] & keep)
    score = max(len(ret), len(ours)) - matched
    return ("match" if score == 0 else "compile"), score, p.stderr


def rank(state, score):
    """Sort key of a variant: match first, then lower score, then compile over nocompile."""
    return state != "match", float("inf") if score is None else score, state == "nocompile"


def decls_v1(prog, func, src):
    """v1 text of the v0 scaffold at src: gate.declsync_fix with the names the definition bodies use (minus func), a
    name whose prevailing spelling brings a struct/union/enum/typedef dropped; None when nothing changes."""
    with open(src) as f:
        v0 = f.read()
    items, _ = top_level(v0)
    names = set()
    for s, e, kind in items:
        if kind == "body":
            names |= set(re.findall(r"\b([A-Za-z_]\w*)\b", SKIP.sub(" ", v0[s:e])))
    names.discard(func)
    for _ in range(2):
        new = gate.declsync_fix(prog, src, " ".join(sorted(names)), func)
        if new is None:
            return None
        old = gate.decls(v0)
        bad = {n for n, (_, s) in gate.decls(new).items() if TYPEKW.search(s) and old.get(n, (0, ""))[1] != s}
        if not bad:
            return new
        names -= bad
    return None


def run_one(job):
    """The jsonl row of one function; keeps its scaffold C (the chosen variant's) under job['out']/src/."""
    prog, func, vram, end = job["prog"], job["func"], job["vram"], job["end"]
    row = dict(pv=f"{prog}:0x{vram:08X}", func=func, words=job["words"], score=None, n=None, state="nocompile")
    if job.get("decls"):
        row["variant"] = "v0"
    try:
        ret = job.get("retail") or retail(prog, vram, end)  # self-test: planted words
        row["n"] = len(ret)
        rc, text = m2c_text(job)
        if rc or not text.strip():
            return row
        c = normalise(text)
        if job.get("edit") == "syntax":
            c += "\nint scaffold planted syntax error\n"
        src = os.path.join(job["out"], "src", prog, func + ".c")
        os.makedirs(os.path.dirname(src), exist_ok=True)
        row["state"], row["score"], _ = build_score(job, ret, src, c)
        if not job.get("decls"):
            return row
        try:
            v1 = decls_v1(prog, func, src)
            if v1 is None:
                return row
            state, score, err = build_score(job, ret, src, v1)
            arity = "\n".join(ln for ln in err.splitlines() if ARITY_RE.search(ln))
            if state == "nocompile" and arity:  # cast only the calls whose arg count differs from the prevailing proto
                cast = gate.cast_fix(prog, src, arity, func)
                if cast is not None:
                    state, score, _ = build_score(job, ret, src, cast)
            if rank(state, score) < rank(row["state"], row["score"]):
                row.update(state=state, score=score, variant="v1")
        finally:
            if row["variant"] == "v0":  # the kept C is the recorded variant's
                with open(src, "w") as f:
                    f.write(c)
    except Exception as e:  # one function's failure is its nocompile row, never the run's
        print(f"scaffold: {row['pv']} {type(e).__name__}: {str(e)[:160]}", file=sys.stderr)
    return row


# ---- the run -------------------------------------------------------------------------------------------------------

def corpus_rows():
    with open(CORPUS) as f:
        return [json.loads(line) for line in f if line.strip()]


def read_jsonl(path):
    rows = {}
    if os.path.isfile(path):
        with open(path) as f:
            for line in f:
                if line.strip():
                    r = json.loads(line)
                    rows[r["pv"]] = r
    return rows


def job_of(r, out, triple, **extra):
    return dict(prog=r["prog"], func=r["name"], vram=int(r["vram"], 16), end=int(r["end"], 16), words=r["words"],
                tu=r["tu"], out=out, triple=triple, **extra)


def undrawn(ledger):
    """{(prog, vram)} of the ledger rows whose blocker (col 7) is `undrawn`."""
    out = set()
    with open(ledger) as f:
        for line in f:
            c = line.rstrip("\n").split("\t")
            if len(c) >= 7 and c[6] == "undrawn":
                out.add((c[0], int(c[1], 16)))
    return out


def select(prog, limit, ledger=None):
    """Corpus rows of the asm|include_asm functions, or (ledger) of the ledger's undrawn rows; (prog, vram) order."""
    if ledger:
        want = undrawn(ledger)
        rows = [r for r in corpus_rows() if (r["prog"], int(r["vram"], 16)) in want and (prog is None or r["prog"] == prog)]
        for p, v in sorted(want - {(r["prog"], int(r["vram"], 16)) for r in corpus_rows()}):
            print(f"SCAFFOLD UNDRAWN MISSING {p}:0x{v:08X}")
    else:
        rows = [r for r in corpus_rows() if r["state"] in ("asm", "include_asm") and (prog is None or r["prog"] == prog)]
    rows.sort(key=lambda r: (r["prog"], int(r["vram"], 16)))
    if limit and limit < len(rows):
        rows = [rows[i * len(rows) // limit] for i in range(limit)]
    return rows


def run_jobs(jobs, path, j):
    """Append a row per job not yet in path; returns (rows of the jobs' pvs, functions run now, seconds)."""
    done = read_jsonl(path)
    todo = [x for x in jobs if f"{x['prog']}:0x{x['vram']:08X}" not in done]
    os.makedirs(os.path.dirname(path) or ".", exist_ok=True)
    t0 = time.time()
    with open(path, "a") as f, multiprocessing.Pool(max(1, j)) as pool:
        for k, row in enumerate(pool.imap_unordered(run_one, todo, chunksize=1), 1):
            f.write(json.dumps(row) + "\n")
            f.flush()
            done[row["pv"]] = row
            if k % 250 == 0:
                print(f"SCAFFOLD progress {k} of {len(todo)}", flush=True)
    secs = time.time() - t0
    pvs = {f"{x['prog']}:0x{x['vram']:08X}" for x in jobs}
    return [done[p] for p in sorted(pvs) if p in done], len(todo), secs


def summary(rows, a):
    st = [r["state"] for r in rows]
    return f"SCAFFOLD {len(rows)} of {a}: match {st.count('match')} compile {st.count('compile')} nocompile {st.count('nocompile')}"


def variants(rows):
    """--decls line: rows that chose v1 by state (a v1 match is one v0 did not match: ties keep v0)."""
    st = [r["state"] for r in rows if r.get("variant") == "v1"]
    return (f"SCAFFOLD VARIANTS v1 {len(st)} of {len(rows)}: match {st.count('match')} compile {st.count('compile')} "
            f"nocompile {st.count('nocompile')}")


def packs(path, root, wave="W0"):
    """Every match row of path -> root/<wave>/<prog>_<func>/; returns the pack dirs."""
    by_pv = {f"{r['prog']}:0x{int(r['vram'], 16):08X}": r for r in corpus_rows()}
    src_root = os.path.join(os.path.dirname(path), "src")
    made = []
    for pv, row in sorted(read_jsonl(path).items()):
        if row["state"] != "match" or pv not in by_pv:
            continue
        r = by_pv[pv]
        src = os.path.join(src_root, r["prog"], r["name"] + ".c")
        if not os.path.isfile(src):
            print(f"SCAFFOLD PACK MISSING {pv} {src}")
            continue
        d = os.path.join(root, wave, f"{r['prog']}_{r['name']}")
        os.makedirs(d, exist_ok=True)
        shutil.copyfile(src, os.path.join(d, "draft.c"))
        with open(os.path.join(d, "pack.json"), "w") as f:
            json.dump(dict(pv=pv, prog=r["prog"], func=r["name"], tu=r["tu"], words=r["words"]), f)
        with open(os.path.join(d, "verdict.json"), "w") as f:
            json.dump(dict(pv=pv, status="match", score=0, lever="-", notes="m2c scaffold"), f)
        made.append(d)
    print(f"SCAFFOLD PACKS {len(made)} in {os.path.join(root, wave)}")
    return made


def merge(lane, into):
    """Rewrite into: each row whose pv has a lane row is replaced by it (file order kept), new pvs appended."""
    new = read_jsonl(lane)
    with open(into) as f:
        old = [json.loads(line) for line in f if line.strip()]
    seen, out, k = set(), [], 0
    for r in old:
        if r["pv"] in new:
            r, k = new[r["pv"]], k + 1
        seen.add(r["pv"])
        out.append(r)
    extra = [r for pv, r in new.items() if pv not in seen]
    tmp = into + ".tmp"
    with open(tmp, "w") as f:
        f.writelines(json.dumps(r) + "\n" for r in out + extra)
    os.replace(tmp, into)
    print(f"SCAFFOLD MERGE {k} replaced {len(extra)} appended")
    return k, len(extra)


# ---- self-test -----------------------------------------------------------------------------------------------------

def plant_s(d, func, delay):
    path = os.path.join(d, func + ".s")
    with open(path, "w") as f:
        f.write(f"glabel {func}\n    jr          $ra\n    {delay}\nendlabel {func}\n")
    return path


# Planted retail of plant_arity's body: gcc 2.95 folds the calls but keeps their 16-byte outgoing-args frame
# (`addiu $sp,$sp,-16; jr $ra; addiu $sp,$sp,16`, measured T2.c1); no 3-word retail function has this shape.
FOLDED = [0x27BDFFF0, 0x03E00008, 0x27BD0010]


def plant_arity(d, func, callee):
    """A body m2c scaffolds with one prototype of callee and two calls of different arity (2 and 1 args), both in a
    branch the compiler folds away (`arg0 == arg0`): v0 nocompile, v1 (callee's prevailing prototype, calls cast) FOLDED."""
    path = os.path.join(d, func + ".s")
    with open(path, "w") as f:
        f.write(f"glabel {func}\n    addiu       $sp, $sp, -0x18\n    bne         $a0, $a0, .L1\n"
                f"     sw         $ra, 0x10($sp)\n    j           .L2\n     nop\n.L1:\n"
                f"    addiu       $a0, $zero, 1\n    jal         {callee}\n     addiu      $a1, $zero, 2\n"
                f"    jal         {callee}\n     addiu      $a0, $zero, 3\n.L2:\n    lw          $ra, 0x10($sp)\n"
                f"    addiu       $sp, $sp, 0x18\n    jr          $ra\n     nop\nendlabel {func}\n")
    return path


def prevailing_proto(prog):
    """(name, spelling) of the first name (sorted) whose prevailing spelling in prog's unit files (as
    gate.declsync_fix counts) is a prototype of >= 3 params of known width, no struct/union/enum/typedef; else None."""
    spell = {}
    for p in declsync.unit_files(prog):
        with open(p, errors="replace") as f:
            for n, (_, s) in gate.decls(f.read()).items():
                spell.setdefault(n, {}).setdefault(s, 0)
                spell[n][s] += 1
    for n in sorted(spell):
        best = sorted(spell[n].items(), key=lambda x: (-x[1], x[0]))[0][0]
        m = cards.PROTO_RE.match(best)
        if not m or m.group(2) != n or TYPEKW.search(best):
            continue
        ps = declsync.params(m.group(3))
        if len(ps) >= 3 and all(declsync.width(x.replace("M2C_UNK", "s32")) is not None for x in [m.group(1)] + ps):
            return n, best
    return None


def self_test(j):
    out = SELFTEST
    shutil.rmtree(out, ignore_errors=True)
    shutil.rmtree(os.path.join("build", out), ignore_errors=True)
    os.makedirs(os.path.join(out, "asm"))
    t = cards.triple()
    empties = [r for r in corpus_rows() if r["state"] == "c-empty" and r["prog"] == "SLUS_013.95"
               and r["words"] == 2 and os.path.isfile(f"src/{r['prog']}/{r['tu']}.c")]
    empties.sort(key=lambda r: int(r["vram"], 16))
    proto = prevailing_proto("SLUS_013.95")
    if len(empties) < 4 or proto is None:
        print("SCAFFOLD CONTROL FAIL planted (fewer than 4 c-empty functions, or no >= 3-param prevailing prototype)")
        return 1
    a, b, c, d = empties[:4]
    asm = os.path.join(out, "asm")
    jobs = [job_of(a, out, t, asm=plant_s(asm, a["name"], "nop")),
            job_of(b, out, t, asm=plant_s(asm, b["name"], "addiu       $v0, $zero, 1")),
            job_of(c, out, t, asm=plant_s(asm, c["name"], "nop"), edit="syntax")]
    path = os.path.join(out, "scaffold.jsonl")
    fails = []
    print(f"SCAFFOLD planted match {a['name']} mutation {b['name']} nocompile {c['name']} (TU {a['tu']})")
    rows, ran, _ = run_jobs(jobs, path, j)
    got = {r["func"]: r for r in rows}
    for r in rows:
        print(f"SCAFFOLD {r['pv']} {r['func']} {r['state']} score {r['score']} n {r['n']}")
    ra, rb, rc_ = got.get(a["name"], {}), got.get(b["name"], {}), got.get(c["name"], {})
    if not (ra.get("state") == "match" and ra.get("score") == 0):
        fails.append("match")
    if probe.retail_words(a["prog"], a["name"]) != retail(a["prog"], int(a["vram"], 16), int(a["end"], 16)):
        fails.append("retail-extent")
    if not (rb.get("state") == "compile" and (rb.get("score") or 0) > 0):
        fails.append("mutation")
    if not (rc_.get("state") == "nocompile" and "score" in rc_ and rc_["score"] is None):
        fails.append("nocompile")
    with open(path) as f:
        before = f.read()
    rows2, ran2, _ = run_jobs(jobs, path, j)
    with open(path) as f:
        after = f.read()
    if ran2 != 0 or before != after or len(rows2) != 3:
        fails.append("resume")
    made = packs(path, os.path.join(out, "packs"))
    want = os.path.join(out, "packs", "W0", f"{a['prog']}_{a['name']}")
    if made != [want] or sorted(os.listdir(want)) != ["draft.c", "pack.json", "verdict.json"]:
        fails.append("packs")
    else:
        with open(os.path.join(want, "verdict.json")) as f:
            v = json.load(f)
        if v != dict(pv=ra.get("pv"), status="match", score=0, lever="-", notes="m2c scaffold"):
            fails.append("verdict")
    print(summary(rows2, len(jobs)))
    # --undrawn: only the planted ledger's `undrawn` rows, in (prog, vram) order
    led = os.path.join(out, "ledger.tsv")
    with open(led, "w") as f:
        for r, blk in ((b, "undrawn"), (c, "wall"), (a, "undrawn")):
            f.write(f"{r['prog']}\t0x{int(r['vram'], 16):08X}\t{r['name']}\tunique\t-\t-\t{blk}\n")
    if [r["name"] for r in select(a["prog"], None, led)] != [a["name"], b["name"]]:
        fails.append("undrawn")
    # --decls: v1 matches where v0 does not (prevailing prototype + arity cast); a v0 match stays v0
    callee, best = proto
    print(f"SCAFFOLD planted decls {d['name']} calls {callee} (prevailing prototype, >= 3 params)")
    pd = plant_arity(asm, d["name"], callee)
    v0rows, _, _ = run_jobs([job_of(d, out, t, asm=pd, retail=FOLDED)], os.path.join(out, "v0.jsonl"), j)
    path2 = os.path.join(out, "decls.jsonl")
    rows3, _, _ = run_jobs([job_of(a, out, t, asm=os.path.join(asm, a["name"] + ".s"), decls=True),
                            job_of(d, out, t, asm=pd, decls=True, retail=FOLDED)], path2, j)
    got = {r["func"]: r for r in rows3}
    for r in v0rows + rows3:
        print(f"SCAFFOLD {r['pv']} {r['func']} {r['state']} score {r['score']} variant {r.get('variant', '-')}")
    with open(os.path.join(out, "src", d["prog"], d["name"] + ".c")) as f:
        kept = f.read()
    if [r["state"] for r in v0rows] == ["match"] or got.get(d["name"], {}).get("variant") != "v1" \
            or got[d["name"]]["state"] != "match" or best not in kept or f"(*)()){callee})" not in kept:
        fails.append("decls-v1")
    if got.get(a["name"], {}).get("variant") != "v0" or got[a["name"]]["state"] != "match":
        fails.append("decls-v0")
    # --packs --wave: DIR/<W>/ from the match rows of the jsonl in use
    made = packs(path2, os.path.join(out, "packs"), "W9")
    want_d = os.path.join(out, "packs", "W9", f"{d['prog']}_{d['name']}")
    if sorted(made) != sorted([os.path.join(out, "packs", "W9", f"{a['prog']}_{a['name']}"), want_d]):
        fails.append("wave")
    else:
        with open(os.path.join(want_d, "draft.c")) as f:
            if f.read() != kept:
                fails.append("wave-draft")
    # --merge: replaced in file order, new pvs appended
    base, lane = os.path.join(out, "merged.jsonl"), os.path.join(out, "lane.jsonl")
    for p, rs in ((base, [dict(pv="P:1", state="compile"), dict(pv="P:2", state="nocompile")]),
                  (lane, [dict(pv="P:2", state="match", variant="v1"), dict(pv="P:3", state="compile")])):
        with open(p, "w") as f:
            f.writelines(json.dumps(r) + "\n" for r in rs)
    k = merge(lane, base)
    with open(base) as f:
        m = [json.loads(line) for line in f]
    if k != (1, 1) or [(r["pv"], r["state"]) for r in m] != [("P:1", "compile"), ("P:2", "match"), ("P:3", "compile")]:
        fails.append("merge")
    if fails:
        print("SCAFFOLD CONTROL FAIL " + " ".join(fails))
        return 1
    print("SCAFFOLD CONTROL OK")
    return 0


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n", 1)[0])
    ap.add_argument("--all", action="store_true")
    ap.add_argument("-j", type=int, default=os.cpu_count() or 1)
    ap.add_argument("--limit", type=int)
    ap.add_argument("--prog")
    ap.add_argument("--jsonl", default=JSONL)
    ap.add_argument("--packs")
    ap.add_argument("--wave", default="W0")
    ap.add_argument("--undrawn", action="store_true")
    ap.add_argument("--ledger", default=LEDGER)
    ap.add_argument("--decls", action="store_true")
    ap.add_argument("--merge", metavar="LANEJSONL")
    ap.add_argument("--self-test", action="store_true")
    a = ap.parse_args()
    os.chdir(ROOT)
    if a.self_test:
        return self_test(a.j)
    if a.merge:
        merge(a.merge, MERGED)
        return 0
    if not (a.all or a.undrawn or a.packs):
        ap.error("need --all, --undrawn, --packs DIR, --merge LANEJSONL or --self-test")
    if a.all or a.undrawn:
        t = cards.triple()
        rows = select(a.prog, a.limit, a.ledger if a.undrawn else None)
        out = os.path.dirname(a.jsonl) or "."
        extra = dict(decls=True) if a.decls else {}
        got, ran, secs = run_jobs([job_of(r, out, t, **extra) for r in rows], a.jsonl, a.j)
        print(f"SCAFFOLD RATE {ran} functions in {secs:.0f} s ({ran / secs if secs else 0:.2f}/s)")
        if a.packs:
            packs(a.jsonl, a.packs, a.wave)
        if a.decls:
            print(variants(got))
        print(summary(got, len(rows)))
    else:
        packs(a.jsonl, a.packs, a.wave)
    return 0


if __name__ == "__main__":
    sys.exit(main())
