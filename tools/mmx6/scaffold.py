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
         Never calls bank.py.
  scaffold.py --self-test
      -> in build/scaffold/selftest/: three c-empty functions (banked C, so they stay; retail words from their corpus
         rows) get planted .s files (generic `jr $ra` + delay slot, run through m2c directly): the trivial one must
         score 0 (match; retail extent checked against probe.retail_words), the one-word mutation (delay slot
         `addiu $v0, $zero, 1`) > 0, a planted syntax error nocompile; a re-run adds no rows; --packs writes exactly
         the match's pack. Ends `SCAFFOLD CONTROL OK` (rc 0) | `SCAFFOLD CONTROL FAIL <cases>` (rc 1).
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
import dumps  # noqa: E402  (the C rule's dry-run recipe)
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


def run_one(job):
    """The jsonl row of one function; keeps its scaffold C under job['out']/src/."""
    prog, func, vram, end = job["prog"], job["func"], job["vram"], job["end"]
    row = dict(pv=f"{prog}:0x{vram:08X}", func=func, words=job["words"], score=None, n=None, state="nocompile")
    try:
        ret = retail(prog, vram, end)
        row["n"] = len(ret)
        rc, text = m2c_text(job)
        if rc or not text.strip():
            return row
        c = normalise(text)
        if job.get("edit") == "syntax":
            c += "\nint scaffold planted syntax error\n"
        src = os.path.join(job["out"], "src", prog, func + ".c")
        os.makedirs(os.path.dirname(src), exist_ok=True)
        with open(src, "w") as f:
            f.write(c)
        obj = f"build/{src}.o"
        if os.path.exists(obj):
            os.remove(obj)
        flags = tu_cflags(prog, job["tu"], job["triple"])
        over = [f"CFLAGS_{func}={' '.join(flags)}"] if flags else []
        p = subprocess.run(["make", "-s", f"TRIPLE={job['triple']}", obj] + over,
                           stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
        if p.returncode or not os.path.isfile(obj):
            return row
        try:
            ours, masks = probe.elf_function(obj, func)
        except SystemExit:
            return row
        finally:
            os.remove(obj)
        matched = 0
        for i in range(min(len(ret), len(ours))):
            keep = ~masks.get(i, 0) & 0xFFFFFFFF
            matched += (ret[i] & keep) == (ours[i] & keep)
        row["score"] = max(len(ret), len(ours)) - matched
        row["state"] = "match" if row["score"] == 0 else "compile"
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


def select(prog, limit):
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


def packs(path, root):
    """Every match row of path -> root/W0/<prog>_<func>/; returns the pack dirs."""
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
        d = os.path.join(root, "W0", f"{r['prog']}_{r['name']}")
        os.makedirs(d, exist_ok=True)
        shutil.copyfile(src, os.path.join(d, "draft.c"))
        with open(os.path.join(d, "pack.json"), "w") as f:
            json.dump(dict(pv=pv, prog=r["prog"], func=r["name"], tu=r["tu"], words=r["words"]), f)
        with open(os.path.join(d, "verdict.json"), "w") as f:
            json.dump(dict(pv=pv, status="match", score=0, lever="-", notes="m2c scaffold"), f)
        made.append(d)
    print(f"SCAFFOLD PACKS {len(made)} in {os.path.join(root, 'W0')}")
    return made


# ---- self-test -----------------------------------------------------------------------------------------------------

def plant_s(d, func, delay):
    path = os.path.join(d, func + ".s")
    with open(path, "w") as f:
        f.write(f"glabel {func}\n    jr          $ra\n    {delay}\nendlabel {func}\n")
    return path


def self_test(j):
    out = SELFTEST
    shutil.rmtree(out, ignore_errors=True)
    shutil.rmtree(os.path.join("build", out), ignore_errors=True)
    os.makedirs(os.path.join(out, "asm"))
    t = cards.triple()
    empties = [r for r in corpus_rows() if r["state"] == "c-empty" and r["prog"] == "SLUS_013.95"
               and r["words"] == 2 and os.path.isfile(f"src/{r['prog']}/{r['tu']}.c")]
    empties.sort(key=lambda r: int(r["vram"], 16))
    if len(empties) < 3:
        print("SCAFFOLD CONTROL FAIL planted (fewer than 3 c-empty functions)")
        return 1
    a, b, c = empties[:3]
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
    ap.add_argument("--self-test", action="store_true")
    a = ap.parse_args()
    os.chdir(ROOT)
    if a.self_test:
        return self_test(a.j)
    if not (a.all or a.packs):
        ap.error("need --all, --packs DIR or --self-test")
    if a.all:
        t = cards.triple()
        rows = select(a.prog, a.limit)
        out = os.path.dirname(a.jsonl) or "."
        got, ran, secs = run_jobs([job_of(r, out, t) for r in rows], a.jsonl, a.j)
        print(f"SCAFFOLD RATE {ran} functions in {secs:.0f} s ({ran / secs if secs else 0:.2f}/s)")
        if a.packs:
            packs(a.jsonl, a.packs)
        print(summary(got, len(rows)))
    else:
        packs(a.jsonl, a.packs)
    return 0


if __name__ == "__main__":
    sys.exit(main())
