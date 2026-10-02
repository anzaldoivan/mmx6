#!/usr/bin/env python3
"""ledger.py -- the ledger: one row per not-yet-C function, its class, closeness, best draft and blocker (container).

  ledger.py --build [--ledger P]
      -> P (default campaign/ledger.tsv): one row per build/corpus/functions.jsonl asm|include_asm row, sorted
         (prog, vram), tab-separated `<prog> <vram 0x%08X> <func> <class> <closeness> <best draft> <blocker>`;
         stdout `LEDGER classes <head> <k> …`, `LEDGER blockers <head> <k> …`, last `LEDGER BUILT <r> rows`.
         rc 1 + `LEDGER REFUSE missing <path>` on a missing required input.
  ledger.py --check [--ledger P]
      -> per bad row `LEDGER BAD <prog:vram> <why>` (missing: an asm function with no row; c-function / not-in-corpus /
         func-name / duplicate / unsorted / fields / class / closeness / blocker / draft <why>: best draft absent or
         refused by verbatim.check); then the classes and blockers lines; last `LEDGER OK <r> rows; 0 missing,
         0 malformed` (rc 0) or `LEDGER FAIL <r> rows; <x> missing, <y> malformed` (rc 1).
  ledger.py --self-test
      -> planted inputs in .run/ledger-selftest/ (fictional program PLANT, no game data): --build gives the exact
         expected rows (every class and blocker rule at its precedence); the clean ledger passes --check; a dropped
         row (missing), a C function's row, an unknown blocker and a best draft holding INCLUDE_ASM are each refused.
         Ends `LEDGER CONTROL OK` (rc 0), else rc 1. No tracked file is touched.

Rules (docs/ops/campaign.md ## Ledger), first that holds:
  class      lane lib -> `vendor:<LIB>/<tu>` (LIB = the config/boundaries.txt `lib` row holding vram, its LIB/OBJ's LIB
             part, else `unproven`); census dup class of >= 2 members -> `dup:<key>`; census family of >= 2 ->
             `family:<key>`; an exact sig twin -> `twin:<pv>` (lowest other member, (prog, vram), of its exact-twin
             component); `x4` (a pv with a campaign/x4/partners.tsv row: an exact mmx4 partner, x4share.py
             --partners); `unique`.
  closeness  `m/n`, m matched words, best (m/n, then m; ties by source order) of: the scaffold row
             (build/scaffold/scaffold.jsonl, else campaign/scaffold/scaffold.jsonl; m = max(0, n - score)), journal
             records with an `m/n` score (campaign/scaffold/journal.jsonl, then campaign/journal.jsonl), the tracked
             draft drafts/<prog>/<func>.c compiled and masked-scored (plateau.residual_retail; m = max(0, n - residual));
             `nocompile` if none compiled.
  best draft the drafts/<prog>/<func>.c path when present, else `m2c` (the pinned scaffold regenerates it).
  blocker    lane lib -> `vendor`; build/draw/draw.jsonl L1 `jtbl not carved` -> `jtbl-uncarved`, `opt mismatch` ->
             `opt-mismatch`; a valid config/walls.txt row -> `wall:<pass>`; the latest journal record (files in the
             order above, line order): verdict fail with a plateau label -> `plateau:<label>`, fail `hash` (bank R5,
             probe matched) -> `plumbing:R5`, plumbing R<k> -> `plumbing:R<k>`, plumbing refused|conflict ->
             `plumbing:refused`; the tracked draft's plateau.classify label -> `plateau:<label>`; draw L2 (registry
             member -> its exemplar, `banked twin <pv>`, `cluster of <pv>`) -> `member-of:<pv>`; else `undrawn`.
Firewall G12: the ledger and stdout hold names, addresses, numbers, keys and our draft paths only.
"""
import argparse
import json
import os
import re
import shutil
import sys
from fractions import Fraction

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(os.path.dirname(HERE))
sys.path.insert(0, HERE)
import draw  # noqa: E402  (boundaries)
import propagate  # noqa: E402  (registry_rows)
import verbatim  # noqa: E402
import walls  # noqa: E402

LEDGER = "campaign/ledger.tsv"
INPUTS = dict(funcs="build/corpus/functions.jsonl", classes="build/census/classes.jsonl",
              twins="build/sig/twins.jsonl", draw="build/draw/draw.jsonl", bounds="config/boundaries.txt",
              walls="config/walls.txt", registry="config/dedup_registry.txt",
              scaffold="build/scaffold/scaffold.jsonl", scaffold_tracked="campaign/scaffold/scaffold.jsonl",
              journal_scaffold="campaign/scaffold/journal.jsonl", journal="campaign/journal.jsonl",
              partners="campaign/x4/partners.tsv", root=".")
REQUIRED = ("funcs", "classes", "twins", "draw", "bounds", "walls", "partners")
SELFTEST = ".run/ledger-selftest"
ASM = ("asm", "include_asm")
LABELS = ("none", "length", "isel", "sched", "regalloc", "branch")  # plateau.classify's labels
PV = r"[A-Za-z0-9_.]+:0x[0-9A-F]{8}"
CLASS_RE = re.compile(rf"(dup|family):[0-9a-f]{{40}}|twin:{PV}|x4|vendor:[A-Za-z0-9_.]+/[A-Za-z0-9_.]+|unique")
CLOSE_RE = re.compile(r"(\d+)/(\d+)|nocompile")
BLOCK_RE = re.compile(rf"vendor|jtbl-uncarved|opt-mismatch|wall:(\S+)|plateau:({'|'.join(LABELS)})"
                      rf"|plumbing:(R[1-5]|refused)|member-of:{PV}|undrawn")
SCORE_RE = re.compile(r"(\d+)/(\d+)")
DRAFT_RE = re.compile(r"drafts/([A-Za-z0-9_.]+)/([A-Za-z_]\w*)\.c")


def hexs(v):
    return "0x%08X" % (int(v, 16) if isinstance(v, str) else v)


def key(prog, vram):
    return prog, hexs(vram)


def pvkey(pv):
    p, _, v = pv.rpartition(":")
    return key(p, v)


def pv(k):
    return f"{k[0]}:{k[1]}"


def order(k):
    return k[0], int(k[1], 16)


def jl(path):
    if not os.path.isfile(path):
        return []
    with open(path) as f:
        return [json.loads(x) for x in f if x.strip()]


class Refuse(Exception):
    pass


def corpus(inp):
    if not os.path.isfile(inp["funcs"]):
        raise Refuse(f"LEDGER REFUSE missing {inp['funcs']}")
    return {key(r["prog"], r["vram"]): r for r in jl(inp["funcs"])}


# ---- build ---------------------------------------------------------------------------------------------------------

def tracked_drafts(inp):
    """{key name (prog, func): path relative to root} of drafts/<prog>/<func>.c under root."""
    out, base = {}, os.path.join(inp["root"], "drafts")
    for d, _, files in os.walk(base):
        for f in files:
            rel = os.path.relpath(os.path.join(d, f), inp["root"]).replace(os.sep, "/")
            m = DRAFT_RE.fullmatch(rel)
            if m:
                out[m.groups()] = rel
    return out


def score_draft(prog, func, vram, src):
    """((m, n), plateau label) of a tracked draft, or (None, None) when it does not compile."""
    import cards  # noqa: E402  (Makefile TRIPLE; container toolchain, imported only when a draft exists)
    import plateau  # noqa: E402
    import probe  # noqa: E402
    try:
        o = probe.compile_obj(src, cards.triple())
        if not o:
            return None, None
        target = probe.retail_words(prog, func)
        w, diffs, internal, mm = plateau.residual_retail(o, func, target, int(vram, 16))
        return (max(0, len(target) - mm), len(target)), plateau.classify(w, target, diffs, internal, mm)
    except (Exception, SystemExit):
        return None, None


def classes_of(inp, funcs, asm):
    lib, _ = draw.boundaries(inp["bounds"])
    cls = {"dup": {}, "family": {}}
    for c in jl(inp["classes"]):
        if c["kind"] in cls and len(c["members"]) >= 2:
            for p, v in c["members"]:
                cls[c["kind"]].setdefault(key(p, v), c["key"])
    parent, nodes = {}, set()

    def find(k):
        while parent.get(k, k) != k:
            k = parent[k]
        return k
    for t in jl(inp["twins"]):
        if t["tier"] == "exact":
            nodes |= {key(*t["a"]), key(*t["b"])}
            a, b = find(key(*t["a"])), find(key(*t["b"]))
            if a != b:
                parent[max(a, b, key=order)] = min(a, b, key=order)
    with open(inp["partners"]) as f:
        x4 = {key(*x.split("\t")[:2]) for x in f if x.strip()}
    comp = {}
    for k in nodes:
        comp.setdefault(find(k), []).append(k)
    out = {}
    for k in asm:
        r = funcs[k]
        if r["lane"] == "lib":
            lo = int(k[1], 16)
            obj = next((o for a, b, o in lib.get(k[0], []) if a <= lo < b), None)
            out[k] = f"vendor:{obj.split('/')[0] if obj else 'unproven'}/{r['tu']}"
        elif k in cls["dup"]:
            out[k] = f"dup:{cls['dup'][k]}"
        elif k in cls["family"]:
            out[k] = f"family:{cls['family'][k]}"
        elif k in nodes:
            out[k] = "twin:" + pv(min((x for x in comp[find(k)] if x != k), key=order))
        elif k in x4:
            out[k] = "x4"
        else:
            out[k] = "unique"
    return out


def journal_of(inp):
    """({key: [(m, n)]}, {key: latest record}) over both journals in order."""
    scores, last = {}, {}
    for name in ("journal_scaffold", "journal"):
        for r in jl(inp[name]):
            k = pvkey(r["pv"])
            m = SCORE_RE.fullmatch(str(r.get("score", "")))
            if m:
                scores.setdefault(k, []).append((int(m.group(1)), int(m.group(2))))
            last[k] = r
    return scores, last


def journal_blocker(r):
    v, lab = r.get("verdict"), r.get("label")
    if v == "fail" and lab in LABELS:
        return f"plateau:{lab}"
    if v == "fail" and lab == "hash":
        return "plumbing:R5"
    if v == "plumbing":
        return f"plumbing:{lab}" if re.fullmatch(r"R[1-5]", str(lab)) else "plumbing:refused"
    return None


def build(inp, path, say=print):
    miss = [inp[k] for k in REQUIRED if not os.path.isfile(inp[k])]
    if miss:
        raise Refuse("\n".join(f"LEDGER REFUSE missing {p}" for p in miss))
    funcs = corpus(inp)
    asm = sorted((k for k, r in funcs.items() if r["state"] in ASM), key=order)
    cls = classes_of(inp, funcs, asm)
    sc = inp["scaffold"] if os.path.isfile(inp["scaffold"]) else inp["scaffold_tracked"]
    scaf = {}
    for r in jl(sc):
        if r.get("score") is not None:
            scaf[pvkey(r["pv"])] = (max(0, r["n"] - r["score"]), r["n"])
    jscore, jlast = journal_of(inp)
    dr = {key(r["prog"], r["vram"]): r for r in jl(inp["draw"])}
    exemplar = {}
    for _, t in propagate.registry_rows(inp["registry"]):
        exemplar.setdefault(pvkey(t[3]), pvkey(t[1]))
    wall, _, _ = walls.parse(inp["walls"], inp["funcs"])
    drafts = tracked_drafts(inp)
    rows = []
    for k in asm:
        r = funcs[k]
        prog, func = k[0], r["name"]
        src = drafts.get((prog, func))
        cand = ([scaf[k]] if k in scaf else []) + jscore.get(k, [])
        dlabel = None
        if src:
            mn, dlabel = score_draft(prog, func, k[1], src)
            cand += [mn] if mn else []
        best = max(cand, key=lambda c: (Fraction(c[0], c[1]) if c[1] else Fraction(0), c[0]), default=None)
        close = f"{best[0]}/{best[1]}" if best else "nocompile"
        d = dr.get(k, {})
        why = d.get("reason") or ""
        jb = journal_blocker(jlast[k]) if k in jlast else None
        if r["lane"] == "lib":
            blk = "vendor"
        elif d.get("layer") == "L1" and why.startswith("jtbl not carved"):
            blk = "jtbl-uncarved"
        elif d.get("layer") == "L1" and why.startswith("opt mismatch"):
            blk = "opt-mismatch"
        elif (k[0], int(k[1], 16)) in wall:
            blk = f"wall:{wall[(k[0], int(k[1], 16))][0]}"
        elif jb:
            blk = jb
        elif dlabel:
            blk = f"plateau:{dlabel}"
        elif d.get("layer") == "L2" and why.startswith("registry ") and exemplar.get(k, k) != k:
            blk = f"member-of:{pv(exemplar[k])}"
        elif d.get("layer") == "L2" and why.startswith(("banked twin ", "cluster of ")):
            blk = f"member-of:{pv(pvkey(why.split()[-1]))}"
        else:
            blk = "undrawn"
        rows.append("\t".join([prog, k[1], func, cls[k], close, src or "m2c", blk]))
    os.makedirs(os.path.dirname(path) or ".", exist_ok=True)
    with open(path, "w") as f:
        f.write("".join(x + "\n" for x in rows))
    tallies(rows, say)
    say(f"LEDGER BUILT {len(rows)} rows")
    return rows


# ---- check ---------------------------------------------------------------------------------------------------------

def tallies(rows, say):
    for col, name in ((3, "classes"), (6, "blockers")):
        cnt = {}
        for x in rows:
            t = x.split("\t")
            h = t[col].split(":")[0] if len(t) == 7 else "?"
            cnt[h] = cnt.get(h, 0) + 1
        say(f"LEDGER {name} " + " ".join(f"{h} {cnt[h]}" for h in sorted(cnt)))


def bad_row(t, funcs, root, passes):
    """None when the 7 fields t are a well-formed ledger row of an asm function, else the reason."""
    p, v, func, cls, close, best, blk = t
    if not re.fullmatch(r"0x[0-9A-F]{8}", v):
        return "fields vram"
    r = funcs.get((p, v))
    if r is None:
        return "not-in-corpus"
    if r["state"] not in ASM:
        return "c-function"
    if func != r["name"]:
        return "func-name"
    if not CLASS_RE.fullmatch(cls):
        return f"class {cls}"
    m = CLOSE_RE.fullmatch(close)
    if not m or (m.group(1) and not 0 <= int(m.group(1)) <= int(m.group(2)) or m.group(2) == "0"):
        return f"closeness {close}"
    b = BLOCK_RE.fullmatch(blk)
    if not b or (b.group(1) and b.group(1) not in passes):
        return f"blocker {blk}"
    if best != "m2c":
        if best != f"drafts/{p}/{func}.c":
            return f"draft {best} not drafts/{p}/{func}.c"
        fp = os.path.join(root, best)
        if not os.path.isfile(fp):
            return f"draft {best} absent"
        with open(fp, encoding="utf-8", errors="replace") as f:
            ok, why, _ = verbatim.check(f.read())
        if not ok:
            return f"draft {best} verbatim {why}"
    return None


def check(inp, path, say=print):
    funcs = corpus(inp)
    if not os.path.isfile(path):
        raise Refuse(f"LEDGER REFUSE missing {path}")
    with open(path) as f:
        rows = [x for x in f.read().split("\n") if x]
    bad, seen, prev = [], set(), None
    for x in rows:
        t = x.split("\t")
        if len(t) != 7:
            bad.append((x.split("\t")[0], f"fields {len(t)}"))
            continue
        k = (t[0], t[1])
        why = bad_row(t, funcs, inp["root"], walls.PASSES)
        if why is None and k in seen:
            why = "duplicate"
        if why is None and prev is not None and order(k) <= order(prev):
            why = "unsorted"
        seen.add(k)
        prev = k if why is None else prev
        if why:
            bad.append((pv(k), why))
    missing = sorted((k for k, r in funcs.items() if r["state"] in ASM and k not in seen), key=order)
    for k in missing:
        say(f"LEDGER BAD {pv(k)} missing")
    for p, why in bad:
        say(f"LEDGER BAD {p} {why}")
    tallies(rows, say)
    if missing or bad:
        say(f"LEDGER FAIL {len(rows)} rows; {len(missing)} missing, {len(bad)} malformed")
        return 1
    say(f"LEDGER OK {len(rows)} rows; 0 missing, 0 malformed")
    return 0


# ---- self-test -----------------------------------------------------------------------------------------------------

K1, K2 = "1" * 40, "2" * 40


def plant(root):
    """Planted inputs (fictional program PLANT) and the expected ledger text."""
    shutil.rmtree(root, ignore_errors=True)
    os.makedirs(root)
    inp = {k: os.path.join(root, os.path.basename(v)) for k, v in INPUTS.items()}
    inp.update(journal_scaffold=os.path.join(root, "journal_scaffold.jsonl"),
               scaffold=os.path.join(root, "absent", "scaffold.jsonl"), root=root)
    P, wpass = "PLANT", walls.PASSES[0]
    v = lambda i: "0x%08X" % (0x80000000 + 0x20 * i)  # noqa: E731
    fn = [("f_a", "asm", "game", "TA"), ("f_b", "asm", "game", "TA"), ("f_c", "include_asm", "game", "TA"),
          ("f_d", "c", "game", "TA"), ("f_e", "asm", "game", "TA"), ("f_f", "asm", "game", "TA"),
          ("f_g", "asm", "lib", "LG"), ("f_h", "asm", "game", "TA"), ("f_i", "asm", "game", "TA")]
    files = {
        "funcs": [json.dumps(dict(prog=P, vram=v(i), end=v(i + 1), words=8, name=n, tu=tu, state=s, lane=ln,
                                  src="glabel")) for i, (n, s, ln, tu) in enumerate(fn)],
        "classes": [json.dumps(dict(kind="dup", key=K1, size=8, members=[[P, v(0)], [P, v(1)]], reach=1)),
                    json.dumps(dict(kind="dup", key="3" * 40, size=8, members=[[P, v(7)]], reach=1)),
                    json.dumps(dict(kind="family", key=K2, size=8, members=[[P, v(2)], [P, v(3)]], reach=1))],
        "twins": [json.dumps(dict(a=[P, v(4)], b=[P, v(5)], tier="exact", dist=0)),
                  json.dumps(dict(a=[P, v(5)], b=[P, v(8)], tier="near", dist=2))],
        "draw": [json.dumps(dict(prog=P, vram=v(0), verdict="refused", layer="L1", reason="jtbl not carved 0x80001000")),
                 json.dumps(dict(prog=P, vram=v(1), verdict="refused", layer="L2", reason=f"banked twin {P}:{v(3)}")),
                 json.dumps(dict(prog=P, vram=v(8), verdict="refused", layer="L2", reason="registry pending"))],
        "bounds": ["# program PLANT", f"lib {v(6)} {v(7)} LIBX.LIB/LG.OBJ"],
        "walls": [f"{P} {v(2)} {wpass} plant.dump:1 planted evidence"],
        "registry": [f"{K1} {P}:{v(5)} src/shared/plant.c {P}:{v(8)} pending planted"],
        "scaffold_tracked": [json.dumps(dict(pv=f"{P}:{v(0)}", func="f_a", words=8, score=2, n=8, state="compile")),
                             json.dumps(dict(pv=f"{P}:{v(4)}", func="f_e", words=8, score=None, n=8,
                                             state="nocompile"))],
        "journal_scaffold": [json.dumps(dict(wave="W0", pv=f"{P}:{v(5)}", verdict="fail", score="3/8", label="isel"))],
        "journal": [json.dumps(dict(wave="W1", pv=f"{P}:{v(5)}", verdict="plumbing", score="8/8", label="R2"))],
        "partners": [f"{P}\t{v(i)}\t{fn[i][0]}\t8\t{'4' * 40}\tsrc/main/plant.c\tx4_{i}\tasm" for i in (0, 7)],
    }
    for k, lines in files.items():
        with open(inp[k], "w") as f:
            f.write("".join(x + "\n" for x in lines))
    want = [(0, f"dup:{K1}", "6/8", "jtbl-uncarved"), (1, f"dup:{K1}", "nocompile", f"member-of:{P}:{v(3)}"),
            (2, f"family:{K2}", "nocompile", f"wall:{wpass}"), (4, f"twin:{P}:{v(5)}", "nocompile", "undrawn"),
            (5, f"twin:{P}:{v(4)}", "8/8", "plumbing:R2"), (6, "vendor:LIBX.LIB/LG", "nocompile", "vendor"),
            (7, "x4", "nocompile", "undrawn"), (8, "unique", "nocompile", f"member-of:{P}:{v(5)}")]
    text = "".join(f"{P}\t{v(i)}\t{fn[i][0]}\t{c}\t{cl}\tm2c\t{b}\n" for i, c, cl, b in want)
    return inp, text


def self_test():
    os.chdir(ROOT)
    inp, want = plant(SELFTEST)
    led = os.path.join(SELFTEST, "ledger.tsv")
    fails, out = [], []
    say = out.append
    build(inp, led, say)
    with open(led) as f:
        got = f.read()
    print(f"LEDGER CONTROL {'ok' if got == want else 'FAIL'} build rows")
    if got != want:
        fails.append("build")
    rc = check(inp, led, say)
    print(f"LEDGER CONTROL {'ok' if rc == 0 else 'FAIL'} clean ledger passes")
    if rc:
        fails.append("clean")
    rows = want.splitlines()
    d_row = "PLANT\t0x80000060\tf_d\tunique\tnocompile\tm2c\tundrawn"
    os.makedirs(os.path.join(SELFTEST, "drafts", "PLANT"))
    with open(os.path.join(SELFTEST, "drafts", "PLANT", "f_h.c"), "w") as f:
        f.write('INCLUDE_ASM("asm/PLANT/nonmatchings/TA", f_h);\n')
    cases = (("missing function", rows[:-1], "LEDGER BAD PLANT:0x80000100 missing"),
             ("C function on the ledger", rows[:3] + [d_row] + rows[3:], "LEDGER BAD PLANT:0x80000060 c-function"),
             ("unknown blocker", rows[:-2] + [rows[-2].replace("\tundrawn", "\ttired")] + rows[-1:],
              "LEDGER BAD PLANT:0x800000E0 blocker tired"),
             ("asm best draft", rows[:-2] + [rows[-2].replace("\tm2c\t", "\tdrafts/PLANT/f_h.c\t")] + rows[-1:],
              "LEDGER BAD PLANT:0x800000E0 draft drafts/PLANT/f_h.c verbatim include-asm"))
    for what, lines, line in cases:
        with open(led, "w") as f:
            f.write("".join(x + "\n" for x in lines))
        out.clear()
        rc = check(inp, led, say)
        ok = rc == 1 and line in out and sum(x.startswith("LEDGER BAD ") for x in out) == 1
        print(f"LEDGER CONTROL {'ok' if ok else 'FAIL'} {what} refused")
        if not ok:
            fails.append(what)
            print("\n".join(out))
    if fails:
        print("LEDGER CONTROL FAIL " + ", ".join(fails))
        return 1
    print("LEDGER CONTROL OK")
    return 0


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n", 1)[0])
    g = ap.add_mutually_exclusive_group(required=True)
    g.add_argument("--build", action="store_true")
    g.add_argument("--check", action="store_true")
    g.add_argument("--self-test", action="store_true")
    ap.add_argument("--ledger", default=LEDGER)
    a = ap.parse_args()
    if a.self_test:
        return self_test()
    os.chdir(ROOT)
    try:
        return check(INPUTS, a.ledger) if a.check else (build(INPUTS, a.ledger), 0)[1]
    except Refuse as e:
        print(e)
        return 1


if __name__ == "__main__":
    sys.exit(main())
