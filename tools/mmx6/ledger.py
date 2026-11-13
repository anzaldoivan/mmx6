#!/usr/bin/env python3
"""ledger.py -- the ledger: one row per not-yet-C function, its class, closeness, best draft and blocker (container).

  ledger.py --build [--ledger P]
      -> P (default campaign/ledger.tsv): one row per build/corpus/functions.jsonl asm|include_asm row, sorted
         (prog, vram), tab-separated `<prog> <vram 0x%08X> <func> <class> <closeness> <best draft> <blocker> <pins>`;
         stdout `LEDGER classes <head> <k> …`, `LEDGER blockers <name> <k> …` (below), `LEDGER pins free <a> pinned
         <b> unknown <c> none <d>`, last `LEDGER BUILT <r> rows`.
         rc 1 + `LEDGER REFUSE missing <path>` on a missing required input.
  ledger.py --check [--ledger P]
      -> per bad row `LEDGER BAD <prog:vram> <why>` (missing: an asm function with no row; c-function / not-in-corpus /
         func-name / duplicate / unsorted / fields / class / closeness / pins / blocker / draft <why>: best draft
         absent or refused by verbatim.check); then the classes and blockers lines; last `LEDGER OK <r> rows; 0 missing,
         0 malformed` (rc 0) or `LEDGER FAIL <r> rows; <x> missing, <y> malformed` (rc 1). A `vendor:unproven/…`
         class is malformed (`class <cls> unproven`).
  ledger.py --self-test
      -> planted inputs in .run/ledger-selftest/ (fictional program PLANT, no game data): --build gives the exact
         expected rows (every class and blocker rule at its precedence; routed:ledger and the plateau cap from
         tools/mmx6/fixtures/routing-plateau.txt (config/routing.txt has `plateau 1` DISABLED, 3.1 T25); draw.pick_plant: draw.jsonl says B `cluster of A`, leverage picks B -> B undrawn,
         A member-of:B; words injected; a refused-R2 registry member -> plumbing:R2, a pending one stays
         member-of); the clean ledger passes --check; a dropped row (missing), a C function's row, an
         unknown blocker, a best draft holding INCLUDE_ASM, a `-` pins on a scored row and `plateau:bogus:lever` are
         each refused; f_m's pinned 184/196 loses to its pin-free 161/196, and its two journal fails (>= plateau cap
         1) make it `plateau:sched:lever`;
         a planted `- gap` provenance row names an otherwise unproven lib row, and without it --check refuses.
         Ends `LEDGER CONTROL OK` (rc 0), else rc 1. No tracked file is touched.
  ledger.py --reconcile [--ledger P]
      -> build/ledger/reconcile.txt: sorted `MISS <A|B> <prog> <name> <cause> <src path:line or ->`; A = an
         INCLUDE_ASM("asm/<prog>/…", <name>) line under src/**/*.c (prog rock_* or SLUS_013.95) with no game row
         (blocker not `vendor`), B = a game row with no line. Cause, first that holds: `vendor` (a vendor row or
         corpus lane lib), `member-of` (row blocker), `collision` ((prog, vram) > 1 in the corpus), `non-asm`
         (corpus row by name not asm|include_asm), `non-function` (no corpus row; asm/<folder>/<name>.s has no
         glabel and no instruction line), else `other`. Stdout `RECONCILE lines <L> (rock <a> SLUS <b>) rows <R>
         (rock <c> SLUS <d>) A <x> B <y>`, then sorted `CAUSE <A|B> <cause> <n>` (nonzero). rc 0 iff no `other`.
  ledger.py --drop-banked [--ledger P]
      -> rewrites P dropping exactly the rows --check flags `c-function` (corpus state no longer asm: banked since the
         last --build); every other line byte-identical, in order. Reads only the corpus (never journal or draw), so
         curated blockers survive, unlike --build. Stdout `LEDGER DROP-BANKED <k> rows dropped, <n> kept`, rc 0.

Rules (docs/ops/campaign.md ## Ledger), first that holds:
  class      lane lib -> exe vram with a docs/ops/compiler-pin.md `## Lib provenance` row `- gap <0xVRAM> <L>.LIB/<O>.OBJ`
             -> `vendor:<L>.LIB/<L>_<O>`; else `vendor:<LIB>/<tu>` (LIB = the config/boundaries.txt `lib` row holding
             vram, its LIB/OBJ's LIB part, else `unproven`); census dup class of >= 2 members -> `dup:<key>`; census family of >= 2 ->
             `family:<key>`; an exact sig twin -> `twin:<pv>` (lowest other member, (prog, vram), of its exact-twin
             component); `x4` (a pv with a campaign/x4/partners.tsv row: an exact mmx4 partner, x4share.py
             --partners); `unique`.
  closeness  `m/n`, m matched words, best (m/n, then m; ties by source order) of: the scaffold row
             (build/scaffold/scaffold.jsonl, else campaign/scaffold/scaffold.jsonl; m = max(0, n - score)), journal
             records with an `m/n` score (campaign/scaffold/journal.jsonl, then campaign/journal.jsonl), the tracked
             draft drafts/<prog>/<func>.c compiled and masked-scored (plateau.residual_retail; m = max(0, n - residual));
             `nocompile` if none compiled. Any pin-free candidate outranks every pinned or unknown one.
  pins       of the best candidate: `0` pin-free, `<n>` verbatim.check register-asm pins, `?` unknown, `-` nocompile.
             Scaffold row 0; journal record: its `draft` (relative to root) scanned, `-` -> `?`, unreadable -> `?`
             (scaffold journal: 0, an m2c scaffold); tracked draft scanned. Scanned, not a journal field: the journal
             is append-only and sha1-chained, so its history cannot gain a field.
  best draft the drafts/<prog>/<func>.c path when present, else `m2c` (the pinned scaffold regenerates it).
  blocker    lane lib -> `vendor`; build/draw/draw.jsonl L1 `jtbl not carved` -> `jtbl-uncarved`, `opt mismatch` ->
             `opt-mismatch`; a valid config/walls.txt row -> `wall:<pass>`; the latest journal record (files in the
             order above, line order): verdict fail with a plateau label -> `plateau:<label>` (`plateau:<label>:lever`,
             waiting for a lever, when campaign/journal.jsonl holds >= the config/routing.txt `plateau <cap>` fail
             records of the pv; 3.1 T9), fail `hash` (bank R5,
             probe matched) -> `plumbing:R5`, plumbing R<k> -> `plumbing:R<k>`, plumbing refused|conflict ->
             `plumbing:refused`, verbatim (gate refused the draft via verbatim.py) -> `plumbing:verbatim`; the
             tracked draft's plateau.classify label -> `plateau:<label>`; draw.jsonl L2 (registry member -> its
             exemplar, `banked twin <pv>`) -> `member-of:<pv>`; a draw.leverage_picks pick (the --rank leverage
             --routing config/routing.txt draw over campaign/journal.jsonl: a candidate in a component whose first
             survivor in leverage order is another pv) -> `member-of:<pick>`; the pick itself falls through; a
             would-be member-of row whose own config/dedup_registry.txt row (key = its class key, else the first
             refused) is `refused` -> `plumbing:R<k>` / `plumbing:preflight` by the reason's (or `family <rung>:`'s)
             first token, else `plumbing:refused`;
             corpus words in a config/routing.txt
             `ledger` row -> `routed:ledger`; else `undrawn`. Stdout `LEDGER blockers <name> <n> …`: blocker names,
             member-of:* and plateau:* folded to the prefix (plateau:*:lever -> `plateau-lever`), `undrawn <n>` always
             (0 included). A malformed or overlapping routing row (or order/plateau row) -> `LEDGER MALFORMED
             <path>:<line>` rc 1.
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
              partners="campaign/x4/partners.tsv", pin="docs/ops/compiler-pin.md", routing="config/routing.txt",
              exclude="config/draw_exclude.txt", carve="config/carve.{prog}.txt", makefile="Makefile",
              triples="config/triples.txt", root=".", exe="SLUS_013.95")
REQUIRED = ("funcs", "classes", "twins", "draw", "bounds", "walls", "partners", "pin", "routing", "exclude",
            "makefile", "triples", "registry")
SELFTEST = ".run/ledger-selftest"
ASM = ("asm", "include_asm")
LABELS = ("none", "length", "isel", "sched", "regalloc", "branch")  # plateau.classify's labels
PV = r"[A-Za-z0-9_.]+:0x[0-9A-F]{8}"
CLASS_RE = re.compile(rf"(dup|family):[0-9a-f]{{40}}|twin:{PV}|x4|vendor:[A-Za-z0-9_.]+/[A-Za-z0-9_.]+|unique")
CLOSE_RE = re.compile(r"(\d+)/(\d+)|nocompile")
BLOCK_RE = re.compile(rf"vendor|jtbl-uncarved|opt-mismatch|wall:(\S+)|plateau:({'|'.join(LABELS)})(?::lever)?"
                      rf"|plumbing:(R[1-5]|refused|verbatim|preflight)|member-of:{PV}|routed:ledger|undrawn")
SCORE_RE = re.compile(r"(\d+)/(\d+)")
DRAFT_RE = re.compile(r"drafts/([A-Za-z0-9_.]+)/([A-Za-z_]\w*)\.c")
GAP_RE = re.compile(r"- gap (0x[0-9A-Fa-f]{8}) ([A-Za-z0-9_]+)\.LIB/([A-Za-z0-9_]+)\.OBJ(?:\s|$)")
INC_RE = re.compile(r'^\s*INCLUDE_ASM\("(asm/([^/"]+)/[^"]*)",\s*([A-Za-z_]\w*)\)')
INSN_RE = re.compile(r"^\s*/\*[^*]*\*/\s*[A-Za-z]")  # `/* off vram bytes */ mnemonic`; data lines carry `.word` etc.
RECONCILE = "build/ledger/reconcile.txt"


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


def provenance(path):
    """{vram: `<L>.LIB/<L>_<O>`} from the `- gap` rows of compiler-pin.md `## Lib provenance` (exe inter-lib gaps)."""
    out, sec = {}, False
    with open(path) as f:
        for x in f:
            if x.startswith("## "):
                sec = x.strip() == "## Lib provenance"
            m = GAP_RE.match(x) if sec else None
            if m:
                out[int(m.group(1), 16)] = f"{m.group(2)}.LIB/{m.group(2)}_{m.group(3)}"
    return out


def classes_of(inp, funcs, asm):
    lib, _ = draw.boundaries(inp["bounds"])
    gap = provenance(inp["pin"])
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
            if k[0] == inp["exe"] and lo in gap:
                out[k] = f"vendor:{gap[lo]}"
                continue
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


def pins_of(root, rel, cache):
    """verbatim.check pin count of the draft at root/rel, None when unreadable (cached by rel)."""
    if rel not in cache:
        try:
            with open(os.path.join(root, rel), encoding="utf-8", errors="replace") as f:
                cache[rel] = verbatim.check(f.read())[2]
        except OSError:
            cache[rel] = None
    return cache[rel]


def journal_of(inp, cache):
    """({key: [(m, n, pins)]}, {key: latest record}) over both journals in order; pins of the record's draft
    (None unknown: `-`, or unreadable outside the scaffold journal, whose unreadable m2c drafts are pin-free: 0)."""
    scores, last = {}, {}
    for name in ("journal_scaffold", "journal"):
        for r in jl(inp[name]):
            k = pvkey(r["pv"])
            m = SCORE_RE.fullmatch(str(r.get("score", "")))
            if m:
                d = str(r.get("draft") or "-")
                p = None if d == "-" else pins_of(inp["root"], d, cache)
                p = 0 if p is None and d != "-" and name == "journal_scaffold" else p
                scores.setdefault(k, []).append((int(m.group(1)), int(m.group(2)), p))
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
    if v == "verbatim":
        return "plumbing:verbatim"
    return None


def refused_blocker(reason):
    """plumbing:R<k> | plumbing:preflight | plumbing:refused from a refused registry row's reason (`family <rung>: …` too)."""
    t = reason.split()
    t = t[1:] if t[:1] == ["family"] else t
    rung = t[0].rstrip(":") if t else ""
    return f"plumbing:{rung}" if re.fullmatch(r"R[1-5]|preflight", rung) else "plumbing:refused"


def build(inp, path, say=print, words=None):
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
            scaf[pvkey(r["pv"])] = (max(0, r["n"] - r["score"]), r["n"], 0)  # m2c: pin-free
    cache = {}
    jscore, jlast = journal_of(inp, cache)
    dr = {key(r["prog"], r["vram"]): r for r in jl(inp["draw"])}
    exemplar, regs = {}, {}
    for _, t in propagate.registry_rows(inp["registry"]):
        exemplar.setdefault(pvkey(t[3]), pvkey(t[1]))
        regs.setdefault(pvkey(t[3]), []).append(t)
    wall, _, _ = walls.parse(inp["walls"], inp["funcs"])
    drafts = tracked_drafts(inp)
    try:
        led = [r for r in draw.routing(inp["routing"], "LEDGER") if r[2] == "ledger"]
        _, pcap = draw.routing_extra(inp["routing"], "LEDGER")  # plateau attempt cap -> plateau:<label>:lever
        dfuncs = {(r["prog"], r["vram"]): r for r in jl(inp["funcs"])}  # the draw's own keys
        picks = {key(*k): key(*p) for k, p in
                 draw.leverage_picks(inp, dfuncs, jl(inp["twins"]), words, inp["routing"])["picks"].items()}
    except draw.Refuse as e:
        raise Refuse("\n".join(e.lines))
    nfail = {}
    for r in jl(inp["journal"]):
        if r.get("verdict") == "fail":
            nfail[pvkey(r["pv"])] = nfail.get(pvkey(r["pv"]), 0) + 1
    rows = []
    for k in asm:
        r = funcs[k]
        prog, func = k[0], r["name"]
        src = drafts.get((prog, func))
        cand = ([scaf[k]] if k in scaf else []) + jscore.get(k, [])
        dlabel = None
        if src:
            mn, dlabel = score_draft(prog, func, k[1], src)
            cand += [mn + (pins_of(inp["root"], src, cache),)] if mn else []
        best = max(cand, key=lambda c: (c[2] == 0, Fraction(c[0], c[1]) if c[1] else Fraction(0), c[0]),
                   default=None)  # pin-free first, then m/n, then m
        close = f"{best[0]}/{best[1]}" if best else "nocompile"
        pins = "-" if not best else "?" if best[2] is None else str(best[2])
        d = dr.get(k, {})
        why = d.get("reason") or ""
        jb = journal_blocker(jlast[k]) if k in jlast else None
        if jb and jb.startswith("plateau:") and pcap is not None and nfail.get(k, 0) >= pcap:
            jb += ":lever"  # the plateau attempt cap is spent: waits for a lever
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
        elif d.get("layer") == "L2" and why.startswith("banked twin "):
            blk = f"member-of:{pv(pvkey(why.split()[-1]))}"
        elif k in picks:
            blk = f"member-of:{pv(picks[k])}"
        elif any(lo <= r["words"] <= hi for lo, hi, *_ in led):
            blk = "routed:ledger"
        else:
            blk = "undrawn"
        if blk.startswith("member-of:") and k in regs:  # a refused member's own registry row names its rung
            ts = regs[k]
            t = next((x for x in ts if x[0] == cls[k].partition(":")[2]), None) or \
                next((x for x in ts if x[4] == "refused"), None)
            if t and t[4] == "refused":
                blk = refused_blocker(t[5])
        rows.append("\t".join([prog, k[1], func, cls[k], close, src or "m2c", blk, pins]))
    os.makedirs(os.path.dirname(path) or ".", exist_ok=True)
    with open(path, "w") as f:
        f.write("".join(x + "\n" for x in rows))
    tallies(rows, say)
    say(f"LEDGER BUILT {len(rows)} rows")
    return rows


# ---- check ---------------------------------------------------------------------------------------------------------

def tallies(rows, say):
    for col, name in ((3, "classes"), (6, "blockers")):
        cnt = {"undrawn": 0} if col == 6 else {}
        for x in rows:
            t = x.split("\t")
            h = "?" if len(t) != 8 else t[col] if col == 6 and not t[col].startswith(("member-of:", "plateau:")) \
                else "plateau-lever" if col == 6 and t[col].endswith(":lever") else t[col].split(":")[0]
            cnt[h] = cnt.get(h, 0) + 1
        say(f"LEDGER {name} " + " ".join(f"{h} {cnt[h]}" for h in sorted(cnt)))
    cnt = dict(free=0, pinned=0, unknown=0, none=0)
    for x in rows:
        p = x.split("\t")[7] if len(x.split("\t")) == 8 else "?"
        cnt["free" if p == "0" else "none" if p == "-" else "unknown" if p == "?" else "pinned"] += 1
    say("LEDGER pins " + " ".join(f"{h} {cnt[h]}" for h in cnt))


def bad_row(t, funcs, root, passes):
    """None when the 8 fields t are a well-formed ledger row of an asm function, else the reason."""
    p, v, func, cls, close, best, blk, pins = t
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
    if cls.startswith("vendor:unproven/"):
        return f"class {cls} unproven"
    m = CLOSE_RE.fullmatch(close)
    if not m or (m.group(1) and not 0 <= int(m.group(1)) <= int(m.group(2)) or m.group(2) == "0"):
        return f"closeness {close}"
    if not re.fullmatch(r"\d+|\?|-", pins) or (pins == "-") != (close == "nocompile"):
        return f"pins {pins}"
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
        if len(t) != 8:
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


def drop_banked(inp, path, say=print):
    """Drop the rows bad_row flags `c-function`; keep every other line byte-identical."""
    funcs = corpus(inp)
    if not os.path.isfile(path):
        raise Refuse(f"LEDGER REFUSE missing {path}")
    with open(path, newline="") as f:
        lines = f.read().splitlines(keepends=True)
    keep = [x for x in lines if not (len(t := x.rstrip("\n").split("\t")) == 8
                                     and bad_row(t, funcs, inp["root"], walls.PASSES) == "c-function")]
    with open(path, "w", newline="") as f:
        f.write("".join(keep))
    say(f"LEDGER DROP-BANKED {len(lines) - len(keep)} rows dropped, {len(keep)} kept")
    return 0


# ---- reconcile -----------------------------------------------------------------------------------------------------

def src_lines(root):  # [(prog, name, asm folder, `src path:line`)] of every INCLUDE_ASM line under root/src/**/*.c
    out = []
    for d, ds, fs in os.walk(os.path.join(root, "src")):
        ds.sort()
        for f in sorted(fs):
            if f.endswith(".c"):
                p = os.path.join(d, f)
                with open(p, errors="replace") as h:
                    for i, x in enumerate(h, 1):
                        m = INC_RE.match(x)
                        if m:
                            out.append((m.group(2), m.group(3), m.group(1), f"{os.path.relpath(p, root)}:{i}"))
    return out


def data_only(path):  # True when the .s exists and holds no glabel and no instruction line
    if not os.path.isfile(path):
        return False
    with open(path, errors="replace") as f:
        return not any(x.lstrip().startswith("glabel") or INSN_RE.match(x) for x in f)


def reconcile(inp, path, out, say=print):
    root, game = inp["root"], (lambda p: p == inp["exe"] or p.startswith("rock_"))
    if not os.path.isfile(inp["funcs"]):
        raise Refuse(f"LEDGER REFUSE missing {inp['funcs']}")
    if not os.path.isfile(path):
        raise Refuse(f"LEDGER REFUSE missing {path}")
    with open(path) as f:
        rows = [t for t in (x.split("\t") for x in f.read().split("\n") if x) if len(t) == 8 and game(t[0])]
    vendor = {(t[0], t[2]) for t in rows if t[6] == "vendor"}
    grow = {(t[0], t[2]): t for t in rows if t[6] != "vendor"}
    funcs, byname, npv = jl(inp["funcs"]), {}, {}
    for r in funcs:
        byname.setdefault((r["prog"], r["name"]), []).append(r)
        k = key(r["prog"], r["vram"])
        npv[k] = npv.get(k, 0) + 1
    lines = [x for x in src_lines(root) if game(x[0])]
    have = {(p, n) for p, n, _, _ in lines}

    def cause(p, n, vram, blocker, folder):
        rs = byname.get((p, n), [])
        if (p, n) in vendor or any(r.get("lane") == "lib" for r in rs):
            return "vendor"
        if blocker.startswith("member-of"):
            return "member-of"
        pvs = {key(r["prog"], r["vram"]) for r in rs} | ({key(p, vram)} if vram else set())
        if any(npv.get(k, 0) > 1 for k in pvs):
            return "collision"
        if any(r["state"] not in ASM for r in rs):
            return "non-asm"
        if not rs and folder and data_only(os.path.join(root, folder, n + ".s")):
            return "non-function"
        return "other"

    miss = [("A", p, n, cause(p, n, None, "", fo), loc) for p, n, fo, loc in lines if (p, n) not in grow]
    miss += [("B", p, n, cause(p, n, t[1], t[6], None), "-") for (p, n), t in grow.items() if (p, n) not in have]
    miss.sort()
    os.makedirs(os.path.dirname(out) or ".", exist_ok=True)
    with open(out, "w") as f:
        f.write("".join(f"MISS {' '.join(m)}\n" for m in miss))
    rock = lambda xs: sum(p.startswith("rock_") for p in xs)  # noqa: E731
    lp, rp = [x[0] for x in lines], [p for p, _ in grow]
    say(f"RECONCILE lines {len(lp)} (rock {rock(lp)} SLUS {len(lp) - rock(lp)}) rows {len(rp)} (rock {rock(rp)} "
        f"SLUS {len(rp) - rock(rp)}) A {sum(m[0] == 'A' for m in miss)} B {sum(m[0] == 'B' for m in miss)}")
    tally = {}
    for m in miss:
        tally[m[0], m[3]] = tally.get((m[0], m[3]), 0) + 1
    for (s, c), n in sorted(tally.items()):
        say(f"CAUSE {s} {c} {n}")
    return 1 if any(m[3] == "other" for m in miss) else 0


# ---- self-test -----------------------------------------------------------------------------------------------------

K1, K2 = "1" * 40, "2" * 40


def plant(root):
    """Planted inputs (fictional program PLANT) and the expected ledger text."""
    shutil.rmtree(root, ignore_errors=True)
    os.makedirs(root)
    inp = {k: os.path.join(root, os.path.basename(v)) for k, v in INPUTS.items() if k != "exe"}
    inp.update(journal_scaffold=os.path.join(root, "journal_scaffold.jsonl"),
               scaffold=os.path.join(root, "absent", "scaffold.jsonl"), root=root, exe="PLANT",
               routing=draw.FIXTURE,  # the plateau-cap-on routing fixture (its 901-99999 ledger row, plateau 1)
               makefile=INPUTS["makefile"], triples=INPUTS["triples"])
    P, wpass = "PLANT", walls.PASSES[0]
    v = lambda i: "0x%08X" % (0x80000000 + 0x20 * i)  # noqa: E731
    pf, pt, _ = draw.pick_plant(P, v(12), v(13), tu="TA")  # A f12, B f13: draw.jsonl rep A, leverage pick B
    fn = [("f_a", "asm", "game", "TA"), ("f_b", "asm", "game", "TA"), ("f_c", "include_asm", "game", "TA"),
          ("f_d", "c", "game", "TA"), ("f_e", "asm", "game", "TA"), ("f_f", "asm", "game", "TA"),
          ("f_g", "asm", "lib", "LG"), ("f_h", "asm", "game", "TA"), ("f_i", "asm", "game", "TA"),
          ("f_j", "asm", "lib", "LJ"), ("f_k", "asm", "game", "TA"), ("f_l", "asm", "game", "TA")]
    files = {
        "funcs": [json.dumps(dict(prog=P, vram=v(i), end=v(i + 1), words=950 if n == "f_l" else 8, name=n,
                                  tu=tu, state=s, lane=ln, src="glabel")) for i, (n, s, ln, tu) in enumerate(fn)]
                 + [json.dumps(dict(r, src="glabel")) for r in pf]
                 + [json.dumps(dict(prog=P, vram=v(14), end=v(15), words=8, name="f_m", tu="TA", state="asm",
                                    lane="game", src="glabel"))],
        "classes": [json.dumps(dict(kind="dup", key=K1, size=8, members=[[P, v(0)], [P, v(1)]], reach=1)),
                    json.dumps(dict(kind="dup", key="3" * 40, size=8, members=[[P, v(7)]], reach=1)),
                    json.dumps(dict(kind="family", key=K2, size=8, members=[[P, v(2)], [P, v(3)]], reach=1))],
        "twins": [json.dumps(dict(a=[P, v(4)], b=[P, v(5)], tier="exact", dist=0)),
                  json.dumps(dict(a=[P, v(5)], b=[P, v(8)], tier="near", dist=2))] + [json.dumps(t) for t in pt],
        "draw": [json.dumps(dict(prog=P, vram=v(0), verdict="refused", layer="L1", reason="jtbl not carved 0x80001000")),
                 json.dumps(dict(prog=P, vram=v(1), verdict="refused", layer="L2", reason=f"banked twin {P}:{v(3)}")),
                 json.dumps(dict(prog=P, vram=v(8), verdict="refused", layer="L2", reason="registry pending")),
                 json.dumps(dict(prog=P, vram=v(13), verdict="refused", layer="L2", reason=f"cluster of {P}:{v(12)}"))],
        "exclude": ["# planted, no rows"],
        "bounds": ["# program PLANT", f"lib {v(6)} {v(7)} LIBX.LIB/LG.OBJ"],
        "walls": [f"{P} {v(2)} {wpass} plant.dump:1 planted evidence"],
        "registry": [f"{K1} {P}:{v(5)} src/shared/plant.c {P}:{v(8)} pending planted",
                     f"{K1} {P}:{v(5)} src/shared/plant.c {P}:{v(1)} refused R2: planted does not compile"],
        "scaffold_tracked": [json.dumps(dict(pv=f"{P}:{v(0)}", func="f_a", words=8, score=2, n=8, state="compile")),
                             json.dumps(dict(pv=f"{P}:{v(4)}", func="f_e", words=8, score=None, n=8,
                                             state="nocompile"))],
        "journal_scaffold": [json.dumps(dict(wave="W0", pv=f"{P}:{v(5)}", verdict="fail", score="3/8", label="isel"))],
        "journal": [json.dumps(dict(wave="W1", pv=f"{P}:{v(5)}", verdict="plumbing", score="8/8", label="R2")),
                    json.dumps(dict(wave="W1", pv=f"{P}:{v(10)}", verdict="verbatim", score="-", label="-")),
                    # f_m: a pinned 184/196 loses to a later pin-free 161/196
                    json.dumps(dict(wave="W12", pv=f"{P}:{v(14)}", verdict="fail", score="184/196", label="sched",
                                    draft="pins/f_m_pinned.c")),
                    json.dumps(dict(wave="W13", pv=f"{P}:{v(14)}", verdict="fail", score="161/196", label="sched",
                                    draft="pins/f_m_free.c"))],
        "pin": ["## Lib provenance", f"- gap {v(9)} LIBY.LIB/OJ.OBJ planted evidence", "## Proven lib units"],
        "partners": [f"{P}\t{v(i)}\t{fn[i][0]}\t8\t{'4' * 40}\tsrc/main/plant.c\tx4_{i}\t1\tasm" for i in (0, 7)],
    }
    for k, lines in files.items():
        with open(inp[k], "w") as f:
            f.write("".join(x + "\n" for x in lines))
    os.makedirs(os.path.join(root, "pins"))
    for n, body in (("pinned", 'int f_m(int a) {\n    register int r asm("$2") = a;\n    return r;\n}\n'),
                    ("free", "int f_m(int a) {\n    return a;\n}\n")):
        with open(os.path.join(root, "pins", f"f_m_{n}.c"), "w") as f:
            f.write(body)
    want = [(0, f"dup:{K1}", "6/8", "jtbl-uncarved", "0"), (1, f"dup:{K1}", "nocompile", "plumbing:R2", "-"),
            (2, f"family:{K2}", "nocompile", f"wall:{wpass}", "-"),
            (4, f"twin:{P}:{v(5)}", "nocompile", "undrawn", "-"),
            (5, f"twin:{P}:{v(4)}", "8/8", "plumbing:R2", "?"),
            (6, "vendor:LIBX.LIB/LG", "nocompile", "vendor", "-"),
            (7, "x4", "nocompile", "undrawn", "-"), (8, "unique", "nocompile", f"member-of:{P}:{v(5)}", "-"),
            (9, "vendor:LIBY.LIB/LIBY_OJ", "nocompile", "vendor", "-"),
            (10, "unique", "nocompile", "plumbing:verbatim", "-"), (11, "unique", "nocompile", "routed:ledger", "-"),
            (12, f"twin:{P}:{v(13)}", "nocompile", f"member-of:{P}:{v(13)}", "-"),
            (13, f"twin:{P}:{v(12)}", "nocompile", "undrawn", "-"),
            (14, "unique", "161/196", "plateau:sched:lever", "0")]
    names = [n for n, *_ in fn] + [r["name"] for r in pf] + ["f_m"]
    text = "".join(f"{P}\t{v(i)}\t{names[i]}\t{c}\t{cl}\tm2c\t{b}\t{pn}\n" for i, c, cl, b, pn in want)
    words = {key(P, v(i)): [draw.census.JR_RA, 0] for i in range(len(names))}
    return inp, text, words


def self_test():
    os.chdir(ROOT)
    inp, want, words = plant(SELFTEST)
    led = os.path.join(SELFTEST, "ledger.tsv")
    fails, out = [], []
    say = out.append
    build(inp, led, say, words)
    with open(led) as f:
        got = f.read()
    print(f"LEDGER CONTROL {'ok' if got == want else 'FAIL'} build rows")
    if got != want:
        fails.append("build")
    rc = check(inp, led, say)
    print(f"LEDGER CONTROL {'ok' if rc == 0 else 'FAIL'} clean ledger passes")
    if rc:
        fails.append("clean")
    pin = os.path.join(SELFTEST, "pin-nogap.md")
    with open(pin, "w") as f:
        f.write("## Lib provenance\n## Proven lib units\n")
    out.clear()
    build(dict(inp, pin=pin), led, say, words)
    out.clear()
    rc = check(inp, led, say)
    ok = rc == 1 and "LEDGER BAD PLANT:0x80000120 class vendor:unproven/LJ unproven" in out \
        and sum(x.startswith("LEDGER BAD ") for x in out) == 1
    print(f"LEDGER CONTROL {'ok' if ok else 'FAIL'} provenance row removed refused")
    if not ok:
        fails.append("provenance")
        print("\n".join(out))
    rows = want.splitlines()
    d_row = "PLANT\t0x80000060\tf_d\tunique\tnocompile\tm2c\tundrawn\t-"
    os.makedirs(os.path.join(SELFTEST, "drafts", "PLANT"))
    with open(os.path.join(SELFTEST, "drafts", "PLANT", "f_h.c"), "w") as f:
        f.write('INCLUDE_ASM("asm/PLANT/nonmatchings/TA", f_h);\n')
    cases = (("missing function", rows[:8] + rows[9:], "LEDGER BAD PLANT:0x80000120 missing"),
             ("C function on the ledger", rows[:3] + [d_row] + rows[3:], "LEDGER BAD PLANT:0x80000060 c-function"),
             ("unknown blocker", rows[:6] + [rows[6].replace("\tundrawn", "\ttired")] + rows[7:],
              "LEDGER BAD PLANT:0x800000E0 blocker tired"),
             ("asm best draft", rows[:6] + [rows[6].replace("\tm2c\t", "\tdrafts/PLANT/f_h.c\t")] + rows[7:],
              "LEDGER BAD PLANT:0x800000E0 draft drafts/PLANT/f_h.c verbatim include-asm"),
             ("malformed pins", [rows[0][:-1] + "-"] + rows[1:], "LEDGER BAD PLANT:0x80000000 pins -"),
             ("unknown lever label",
              rows[:-1] + [rows[-1].replace("\tplateau:sched:lever\t", "\tplateau:bogus:lever\t")],
              "LEDGER BAD PLANT:0x800001C0 blocker plateau:bogus:lever"))
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
    # reconcile: a line per game row, a vendor line (f_g), a dlabel-only line (D_plant), a game row with no line
    # whose corpus state is c (f_d); then an injected glabel line with no row (f_zz) must yield `other`, rc 1.
    with open(led, "w") as f:
        f.write(want + d_row + "\n")
    folder = "asm/PLANT/nonmatchings/TA"
    os.makedirs(os.path.join(SELFTEST, folder))
    os.makedirs(os.path.join(SELFTEST, "src"))
    for n, body in (("D_plant", "dlabel D_plant\n    /* 0 80001000 01000000 */ .word 0x00000001\n"),
                    ("f_zz", "glabel f_zz\n    /* 0 80002000 0800E003 */  jr         $ra\n")):
        with open(os.path.join(SELFTEST, folder, n + ".s"), "w") as f:
            f.write(f'.set noat\n\nnonmatching {n}\n\n{body}')
    names = [t.split("\t")[2] for t in rows if t.split("\t")[6] != "vendor"] + ["f_g", "D_plant"]
    rpath = os.path.join(SELFTEST, "reconcile.txt")
    for extra, wrc, lines_ in (([], 0, ["MISS A PLANT D_plant non-function src/plant.c:14",
                                       "MISS A PLANT f_g vendor src/plant.c:13", "MISS B PLANT f_d non-asm -"]),
                               (["f_zz"], 1, ["MISS A PLANT f_zz other src/plant.c:15"])):
        with open(os.path.join(SELFTEST, "src", "plant.c"), "w") as f:
            f.write("".join(f'INCLUDE_ASM("{folder}", {n});\n' for n in names + extra))
        out.clear()
        rc = reconcile(inp, led, rpath, say)
        with open(rpath) as f:
            got = f.read().splitlines()
        ok = rc == wrc and all(x in got for x in lines_) and len(got) == 3 + len(extra) \
            and ("CAUSE A other 1" in out) == bool(extra) \
            and out[0] == f"RECONCILE lines {14 + len(extra)} (rock 0 SLUS {14 + len(extra)}) rows 13 (rock 0 SLUS 13)" \
                          f" A {2 + len(extra)} B 1"
        print(f"LEDGER CONTROL {'ok' if ok else 'FAIL'} reconcile {'injected other rc 1' if extra else 'causes'}")
        if not ok:
            fails.append("reconcile")
            print("\n".join(out + got))
    # drop-banked: a banked row (f_d, corpus state c) goes; a curated blocker no input derives and the asm rows stay
    # byte-identical; --check on the result then has no c-function.
    cur = rows[6].replace("\tundrawn\t", "\tplumbing:curated-T12\t")
    kept = rows[:6] + [cur] + rows[7:]
    with open(led, "w") as f:
        f.write("".join(x + "\n" for x in rows[:3] + [d_row] + rows[3:6] + [cur] + rows[7:]))
    out.clear()
    rc = drop_banked(inp, led, say)
    with open(led) as f:
        got = f.read()
    said = list(out)
    out.clear()
    check(inp, led, say)
    ok = rc == 0 and got == "".join(x + "\n" for x in kept) \
        and said == [f"LEDGER DROP-BANKED 1 rows dropped, {len(kept)} kept"] \
        and not any(x.endswith(" c-function") for x in out)
    print(f"LEDGER CONTROL {'ok' if ok else 'FAIL'} drop-banked drops the banked row only")
    if not ok:
        fails.append("drop-banked")
        print("\n".join(said + out + [got]))
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
    g.add_argument("--reconcile", action="store_true")
    g.add_argument("--drop-banked", action="store_true")
    ap.add_argument("--ledger", default=LEDGER)
    a = ap.parse_args()
    if a.self_test:
        return self_test()
    os.chdir(ROOT)
    try:
        if a.reconcile:
            return reconcile(INPUTS, a.ledger, RECONCILE)
        if a.drop_banked:
            return drop_banked(INPUTS, a.ledger)
        return check(INPUTS, a.ledger) if a.check else (build(INPUTS, a.ledger), 0)[1]
    except Refuse as e:
        print(e)
        return 1


if __name__ == "__main__":
    sys.exit(main())
