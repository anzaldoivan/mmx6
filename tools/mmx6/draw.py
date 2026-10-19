#!/usr/bin/env python3
"""draw.py -- the draw filter: which ranked not-yet-C functions a wave may draw (container, stdlib only).

  draw.py [--n K]
      -> build/draw/draw.jsonl, one row per build/reports/difficulty.json function in rank order
         {prog,vram,verdict:"draw|eligible|refused",layer,reason}: the first K survivors `draw` (no --n: all),
         later survivors `eligible`, the rest `refused` at the first layer that refuses them; stdout counts only (G12):
         `DRAW-DETAIL clusters <c> largest <k> survivors <s>`, last line
         `DRAW refused <r> of <n> (L1 <a> L2 <b> L3 <c> L4 <d>); drawn <k>` (r = a+b+c+d, independent of K).
         rc 1 on a missing input; rc 2 on a malformed (`DRAW MALFORMED <path>:<line>`) or stale exclude row (the audit,
         run first by every draw: its lines, then rc 2; no draw.jsonl written, a previous one removed).
  draw.py --audit
      -> the exclude audit of config/draw_exclude.txt over the universe U = corpus asm|include_asm rows (no
         difficulty.json needed): `DRAW STALE <prog> <vram> <layer> <why>` per stale row, last
         `EXCLUDE AUDIT <r> rows, <s> stale`; rc 0 iff s = 0, else rc 2. A row is stale if its function is not in U; an
         L1/L3 row whose layer's static check (below, computed for the rows' keys only) no longer refuses it; an L2 row
         with no registry/banked-twin refusal and no twin-component peer in U (components over U); L4 rows never.
  draw.py --rank leverage|difficulty --wave W<n> [--band <lo>-<hi>] [--routing FILE] [--n K]
      -> build/draw/W<n>.txt, one `<prog>:0x<VRAM>` per line, the first K survivors (no --n: all) in rank order; never
         writes draw.jsonl. n >= 1 needs campaign/harvest/W<n-1>.ok (checked first, before any input is read), else
         `DRAW HARVEST-MISSING W<n-1>` rc 2; W0 needs no stamp. Then the audit (its EXCLUDE AUDIT line; stale -> rc 2).
         difficulty: difficulty.json rank order. leverage: U by payoff = words x (1 + m) desc, m = distinct other U
         functions sharing f's census dup class or family (build/census/classes.jsonl) or an exact twin; ties by
         closeness (build/scaffold/scaffold.jsonl, else campaign/scaffold/scaffold.jsonl; `score` ascending; no
         file/row = last), then (prog, vram).
         --band keeps lo <= corpus words <= hi (inclusive) before the verdicts. Verdicts L1-L4 as below over the ranked
         candidates (components over U). Stdout `DRAW-DETAIL …`, last `DRAW refused <r> of <n> (…); drawn <k>`
         (n = candidates after the band). No W<n>.txt on any refusal (G12: names, addresses, counts only).
         --routing FILE (config/routing.txt rows `<lo>-<hi> <paid|permuter|ledger> <probe cap> <attempt cap>`): also
         keeps only candidates whose corpus words fall in a `paid` row (words in no row are dropped) and leaves out
         every pv with any campaign/journal.jsonl record (field `pv`; no journal: none), before the verdicts; W<n>.txt lines become `<prog>:0x<VRAM> probe=<p> attempts=<a>` (that row's caps); one
         `DRAW routing <lo>-<hi> <k>` per paid row in file order (k drawn in it) before the DRAW-DETAIL line. A
         malformed or overlapping row -> `DRAW MALFORMED <path>:<line>` rc 2. No --routing: unchanged.
         --detail (only with --rank, else rc 2): before the DRAW-DETAIL line, one `DRAW PV <prog>:0x<VRAM> <state>
         <reason>` per ranked pv in rank order; state drawn|eligible|L1..L4 (first refusing layer, as counted) or
         band|route|journal (dropped by --band, words in no paid routing row, journaled; before the verdicts); reason
         the draw.jsonl-style layer reason, `-` for drawn|eligible, `words=<w>` for band|route, `journaled`.
         The candidate+verdict core (rank order, --band, --routing filters, static, components, verdicts; no harvest
         stamp, audit or file write) is leverage_picks(); it also gives picks {key: pick}, every candidate of a
         component holding a survivor -> its first survivor in rank order (key != pick). ledger.py calls it
         (route = config/routing.txt) for its member-of blocker.
  draw.py --self-test
      -> planted inputs in .run/draw-selftest/ (words injected): lib-unproven, uncarved jtbl, registry member,
         banked exact twin, two-member cluster, wall row, L4 row, each at its layer, and the exact DRAW line; a planted
         stale exclude row -> rc 2 and nothing written; the audit (clean -> `EXCLUDE AUDIT 4 rows, 0 stale`; one stale
         row per class: not in U, L1, L3, L2 -> exact lines, rc 2, and a --rank draw refused with no W<n>.txt);
         leverage order (dup/family/twin members, closeness and (prog, vram) ties) and --band as exact W0.txt content;
         W2 without W1.ok -> `DRAW HARVEST-MISSING W1` rc 2; W1 with W0.ok drawn; --routing with the real
         config/routing.txt (a 950-word function not drawn, a 20-word one `probe=18 attempts=2`, five routing lines,
         a journaled pv not drawn) and an overlapping row -> DRAW MALFORMED rc 2; --detail (the L4 plant
         `DRAW PV <pv> L4 exclude planted hold`, a drawn plant `drawn -`, `band` under --band); pick_plant (shared with
         ledger.py: exact twins A, B; difficulty draw.jsonl B `cluster of A`, leverage draws B and refuses A
         `cluster of B`). Every control
         `DRAW CONTROL ok|FAIL <what>`; ends `DRAW CONTROL OK` (rc 0), else rc 1.

Layers, cheapest first:
  L1 lane lib and its boundaries `lib` OBJ (row holding vram, that program) not under docs/ops/compiler-pin.md
     `## Proven lib units` -> `lib triple unproven <OBJ>`; a boundaries `jtbl` row whose dispatcher func lies in
     [vram, end) and whose table lo has no config/carve.<prog>.txt `jtbl` row -> `jtbl not carved <table>`;
     optscan.classify of the words (census.read_words; no optscan output file is kept) O0|fp-only under unit cflags
     -O2 (Makefile TRIPLE row of config/triples.txt, or the carve `opt` row's cflags for its new TU), or O2 under
     non -O2 -> `opt mismatch`.
  L2 a config/dedup_registry.txt row names f -> `registry <state>`; an exact twin (build/sig/twins.jsonl) whose corpus
     state is c|c-empty -> `banked twin <prog:vram>`; f's open cluster (connected component of exact+near twins over
     difficulty functions) already holds an earlier survivor -> `cluster of <prog:vram>` (G46).
  L3 walls.bankable false -> its reason (`wall <pass> <ref>`).
  L4 a non-stale config/draw_exclude.txt `L4` row -> `exclude <reason>`; L1-L3 rows mirror their layer.
"""
import argparse
import json
import os
import re
import shutil
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import census  # noqa: E402
import optscan  # noqa: E402
import propagate  # noqa: E402
import walls  # noqa: E402

INPUTS = dict(diff="build/reports/difficulty.json", funcs="build/corpus/functions.jsonl",
              bounds="config/boundaries.txt", carve="config/carve.{prog}.txt", pin="docs/ops/compiler-pin.md",
              registry="config/dedup_registry.txt", twins="build/sig/twins.jsonl", walls="config/walls.txt",
              exclude="config/draw_exclude.txt", makefile="Makefile", triples="config/triples.txt",
              classes="build/census/classes.jsonl", scaffold="build/scaffold/scaffold.jsonl",
              scaffold_tracked="campaign/scaffold/scaffold.jsonl", harvest="campaign/harvest", wdir="build/draw",
              journal="campaign/journal.jsonl")
AUDIT_IN = ("funcs", "bounds", "pin", "registry", "twins", "walls", "exclude", "makefile", "triples")
OUT = "build/draw/draw.jsonl"
SELFTEST = ".run/draw-selftest"
LAYERS = ("L1", "L2", "L3", "L4")


class Refuse(Exception):
    def __init__(self, rc, lines):
        super().__init__("\n".join(lines))
        self.rc, self.lines = rc, lines


def jl(path):
    with open(path) as f:
        return [json.loads(x) for x in f if x.strip()]


def hexs(v):
    return "0x%08X" % (int(v, 16) if isinstance(v, str) else v)


# ---- inputs --------------------------------------------------------------------------------------------------------

def proven(path):
    """{LIB/OBJ} of the `## Proven lib units` section; Refuse if the section is absent."""
    out, inside, seen = set(), False, False
    with open(path) as f:
        for line in f:
            if line.startswith("## "):
                inside = line.strip() == "## Proven lib units"
                seen |= inside
            elif inside and line.startswith("- ") and len(line.split()) >= 2:
                out.add(line.split()[1])
    if not seen:
        raise Refuse(1, [f"DRAW REFUSE no `## Proven lib units` in {path}"])
    return out


def boundaries(path):
    """({prog: [(lo, hi, OBJ)]}, {prog: [(table lo, func)]}) of the lib and jtbl rows."""
    lib, jt, cur = {}, {}, None
    with open(path) as f:
        for line in f:
            w = line.split()
            if line.startswith("# program "):
                cur = w[2]
            elif cur and len(w) >= 4 and w[0] == "lib":
                lib.setdefault(cur, []).append((int(w[1], 16), int(w[2], 16), w[3]))
            elif cur and len(w) >= 5 and w[0] == "jtbl" and w[3] != "-":
                jt.setdefault(cur, []).append((int(w[1], 16), int(w[3], 16)))
    return lib, jt


def carves(pattern, prog):
    """({carved table lo}, {newtu: cflags list}) of config/carve.<prog>.txt (empty if absent)."""
    path, tabs, opt = pattern.format(prog=prog), set(), {}
    if os.path.isfile(path):
        with open(path) as f:
            for w in (line.split() for line in f if not line.startswith("#")):
                if len(w) >= 3 and w[0] == "jtbl":
                    tabs.add(int(w[1], 16))
                elif len(w) >= 4 and w[0] == "opt" and len(w) > 4:
                    opt[w[3]] = w[4:]
    return tabs, opt


def pin_cflags(makefile, triples):
    with open(makefile) as f:
        m = re.search(r"^TRIPLE \?= (\S+)", f.read(), re.M)
    with open(triples) as f:
        for line in f:
            t = [x.strip() for x in line.split("|")]
            if m and t[0] == m.group(1):
                for x in t[1:]:
                    if x.startswith("cflags:"):
                        return x[len("cflags:"):].split()
    raise Refuse(1, [f"DRAW REFUSE no cflags for the Makefile TRIPLE in {triples}"])


def level(cflags):
    o = [x for x in cflags if x.startswith("-O")]
    return "O0" if not o or o[-1] == "-O0" else "O2"


def components(keys, twins):
    """{key: component id} over twin edges (exact+near) whose both ends are in keys; and the component sizes."""
    up = {k: k for k in keys}

    def find(k):
        while up[k] != k:
            up[k] = up[up[k]]
            k = up[k]
        return k

    for t in twins:
        a, b = tuple(t["a"]), tuple(t["b"])
        if a in up and b in up:
            ra, rb = find(a), find(b)
            if ra != rb:
                up[max(ra, rb)] = min(ra, rb)
    comp = {k: find(k) for k in keys}
    size = {}
    for c in comp.values():
        size[c] = size.get(c, 0) + 1
    return comp, size


def excludes(path):
    """[(line, prog, vram, layer, reason)]; Refuse rc 2 on a malformed row."""
    out, bad = [], []
    with open(path) as f:
        for i, line in enumerate(f, 1):
            if not line.strip() or line.lstrip().startswith("#"):
                continue
            w = line.split(None, 3)
            try:
                ok = len(w) == 4 and w[1] == hexs(w[1]) and w[2] in LAYERS and w[3].strip()
            except ValueError:
                ok = False
            if not ok:
                bad.append(f"DRAW MALFORMED {path}:{i}")
            else:
                out.append((i, w[0], w[1], w[2], w[3].strip()))
    if bad:
        raise Refuse(2, bad)
    return out


ROUTES = ("paid", "permuter", "ledger")


def routing(path, head="DRAW"):
    """[(lo, hi, route, probe cap, attempt cap)] of config/routing.txt rows in file order; Refuse rc 2
    (`<head> MALFORMED <path>:<line>`) on a malformed row or one overlapping an earlier row."""
    out, bad = [], []
    with open(path) as f:
        for i, line in enumerate(f, 1):
            if not line.strip() or line.lstrip().startswith("#"):
                continue
            m = re.fullmatch(r"(\d+)-(\d+) (\S+) (\d+) (\d+)", line.strip())
            r = m and (int(m.group(1)), int(m.group(2)), m.group(3), int(m.group(4)), int(m.group(5)))
            if not r or r[0] > r[1] or r[2] not in ROUTES or any(r[0] <= o[1] and o[0] <= r[1] for o in out):
                bad.append(f"{head} MALFORMED {path}:{i}")
            else:
                out.append(r)
    if bad:
        raise Refuse(2, bad)
    return out


def journaled(path):
    """{(prog, vram int)} of every campaign/journal.jsonl record's `pv` (no file: empty)."""
    if not os.path.isfile(path):
        return set()
    return {(p, int(v, 16)) for p, v in (r["pv"].split(":") for r in jl(path) if r.get("pv"))}


# ---- verdicts ------------------------------------------------------------------------------------------------------

def need(inp, names):
    miss = [inp[k] for k in names if not os.path.isfile(inp[k])]
    if miss:
        raise Refuse(1, [f"DRAW REFUSE missing {p}" for p in miss])


def load(inp, diff=True):
    """(difficulty rows in rank order or None, {key: corpus row}, twins); Refuse rc 1 on a missing input."""
    need(inp, AUDIT_IN + (("diff",) if diff else ()))
    funcs = {(r["prog"], r["vram"]): r for r in jl(inp["funcs"])}
    rows = None
    if diff:
        with open(inp["diff"]) as f:
            rows = sorted(json.load(f), key=lambda d: d["rank"])
        miss = [d for d in rows if (d["prog"], d["vram"]) not in funcs]
        if miss:
            raise Refuse(1, [f"DRAW REFUSE {len(miss)} difficulty functions not in {inp['funcs']} (stale report)"])
    return rows, funcs, jl(inp["twins"])


def universe(funcs):
    """Keys of the corpus asm|include_asm rows, (prog, vram) order."""
    return sorted((k for k, r in funcs.items() if r["state"] in ("asm", "include_asm")),
                  key=lambda k: (k[0], int(k[1], 16)))


def static(inp, keys, funcs, twins, words=None):
    """Per key the order-independent refusals: {key: {"L1": reason|None, "L2": .., "L3": ..}}."""
    good = proven(inp["pin"])
    lib, jt = boundaries(inp["bounds"])
    pin = pin_cflags(inp["makefile"], inp["triples"])
    reg = {}
    for _, t in propagate.registry_rows(inp["registry"]):
        reg.setdefault(tuple(t[3].rsplit(":", 1)), t[4])
    banked = {}
    for t in twins:
        if t["tier"] == "exact":
            for x, y in ((t["a"], t["b"]), (t["b"], t["a"])):
                r = funcs.get(tuple(y))
                if r and r["state"] in ("c", "c-empty"):
                    banked.setdefault(tuple(x), []).append(tuple(y))
    out, cv = {}, {}
    for k in keys:
        p, v = k
        r = funcs[k]
        lo, hi = int(v, 16), r["end"] if isinstance(r["end"], int) else int(r["end"], 16)
        if p not in cv:
            cv[p] = carves(inp["carve"], p)
        tabs, opt = cv[p]
        l1 = None
        if r["lane"] == "lib":
            obj = next((o for a, b, o in lib.get(p, []) if a <= lo < b), "-")
            if obj not in good:
                l1 = f"lib triple unproven {obj}"
        if l1 is None:
            t = next((t for t, fn in sorted(jt.get(p, [])) if lo <= fn < hi and t not in tabs), None)
            if t is not None:
                l1 = f"jtbl not carved {hexs(t)}"
        out[k] = {"L1": l1, "opt": None if l1 else level(opt.get(r["tu"], pin)),
                  "L2": f"registry {reg[k]}" if k in reg else
                  (f"banked twin {':'.join(min(banked[k]))}" if k in banked else None),
                  "L3": None}
        b, why = walls.bankable(p, v, inp["walls"], inp["funcs"])
        out[k]["L3"] = None if b else why
    need = [k for k in keys if out[k]["opt"]]
    if words is None:
        words = dict(zip(need, (w for w, _ in census.read_words([funcs[k] for k in need]))))
    for k in need:
        c = optscan.classify(words[k])
        if ("O0" if c["cls"] == "O0" or c["fponly"] else "O2") != out[k]["opt"]:
            out[k]["L1"] = "opt mismatch"
    return out


def verdicts(keys, st, comp, l4):
    """[(key, layer|None, reason)] in rank order (keys ranked); l4 = {key: reason} of the L4 excludes."""
    out, held = [], {}
    for k in keys:
        s = st[k]
        if s["L1"]:
            out.append((k, "L1", s["L1"]))
        elif s["L2"]:
            out.append((k, "L2", s["L2"]))
        elif comp[k] in held:
            out.append((k, "L2", f"cluster of {':'.join(held[comp[k]])}"))
        elif s["L3"]:
            out.append((k, "L3", s["L3"]))
        elif k in l4:
            out.append((k, "L4", f"exclude {l4[k]}"))
        else:
            held[comp[k]] = k
            out.append((k, None, ""))
    return out


def audit(inp, funcs, twins, words=None):
    """(lines, stale count, exclude rows): `DRAW STALE …` per stale row, last `EXCLUDE AUDIT <r> rows, <s> stale`."""
    ex = excludes(inp["exclude"])
    uni = universe(funcs)
    inu = set(uni)
    keys = sorted({(p, v) for _, p, v, layer, _ in ex if (p, v) in inu and layer != "L4"})
    st = static(inp, keys, funcs, twins, words)
    comp, size = components(uni, twins)
    stale = []
    for _, p, v, layer, _ in ex:
        k = (p, v)
        if k not in inu:
            stale.append(f"DRAW STALE {p} {v} {layer} not in universe")
        elif layer in ("L1", "L3") and not st[k][layer]:
            stale.append(f"DRAW STALE {p} {v} {layer} {layer} no longer refuses it")
        elif layer == "L2" and not st[k]["L2"] and size[comp[k]] < 2:
            stale.append(f"DRAW STALE {p} {v} {layer} L2 no longer refuses it")
    return stale + [f"EXCLUDE AUDIT {len(ex)} rows, {len(stale)} stale"], len(stale), ex


def audited(inp, funcs, twins, words, say, drop):
    """Runs the audit before a draw: says its EXCLUDE AUDIT line; on a stale row removes drop and Refuses rc 2."""
    lines, s, ex = audit(inp, funcs, twins, words)
    if s:
        if os.path.exists(drop):
            os.remove(drop)
        raise Refuse(2, lines)
    say(lines[-1])
    return {(p, v): why for _, p, v, layer, why in ex if layer == "L4"}


def counted(vs, n):
    """[(key, verdict, layer, reason)] of verdict rows (first n survivors `draw`), {layer: count}, drawn count."""
    rows, k_drawn, cnt = [], 0, dict.fromkeys(LAYERS, 0)
    for k, layer, why in vs:
        if layer:
            cnt[layer] += 1
            verdict = "refused"
        elif n is None or k_drawn < n:
            verdict, k_drawn = "draw", k_drawn + 1
        else:
            verdict = "eligible"
        rows.append((k, verdict, layer, why))
    return rows, cnt, k_drawn


def summary(say, size, rows, cnt, k_drawn):
    r = sum(cnt.values())
    say(f"DRAW-DETAIL clusters {len(size)} largest {max(size.values(), default=0)} survivors {len(rows) - r}")
    say(f"DRAW refused {r} of {len(rows)} (" + " ".join(f"{x} {cnt[x]}" for x in LAYERS) + f"); drawn {k_drawn}")


def run(inp, out, n=None, words=None, say=print):
    """Writes out; returns the draw.jsonl rows. Refuse on a missing input or a stale exclude (the audit, run first)."""
    diff, funcs, twins = load(inp)
    l4 = audited(inp, funcs, twins, words, say, out)
    keys = [(d["prog"], d["vram"]) for d in diff]
    st = static(inp, keys, funcs, twins, words)
    comp, size = components(keys, twins)
    vs, cnt, k_drawn = counted(verdicts(keys, st, comp, l4), n)
    rows = [dict(prog=k[0], vram=k[1], verdict=v, layer=layer, reason=why) for k, v, layer, why in vs]
    os.makedirs(os.path.dirname(out), exist_ok=True)
    with open(out, "w") as f:
        for r in rows:
            f.write(json.dumps(r) + "\n")
    summary(say, size, rows, cnt, k_drawn)
    return rows


def leverage(inp, keys, funcs, twins):
    """keys ordered by payoff = words x (1 + m) desc, then closeness (scaffold score asc, none last), then (prog, vram)."""
    uni = set(universe(funcs))
    cls = {"dup": {}, "family": {}}
    for c in jl(inp["classes"]):
        if c["kind"] in cls:
            mem = frozenset(m for m in ((p, hexs(v)) for p, v in c["members"]) if m in uni)
            for m in mem:
                cls[c["kind"]][m] = mem
    tw = {}
    for t in twins:
        a, b = (t["a"][0], hexs(t["a"][1])), (t["b"][0], hexs(t["b"][1]))
        if t["tier"] == "exact" and a in uni and b in uni:
            tw.setdefault(a, set()).add(b)
            tw.setdefault(b, set()).add(a)
    close = {}
    sc = inp["scaffold"] if os.path.isfile(inp["scaffold"]) else inp["scaffold_tracked"]  # sync wipes build/
    if os.path.isfile(sc):
        for r in jl(sc):
            p, _, v = r["pv"].rpartition(":")
            if r.get("score") is not None:
                close[(p, hexs(v))] = r["score"]
    cache, pay = {}, {}
    for k in keys:
        d, f = cls["dup"].get(k, frozenset()), cls["family"].get(k, frozenset())
        if (d, f) not in cache:
            cache[(d, f)] = d | f
        base = cache[(d, f)]
        pay[k] = funcs[k]["words"] * (1 + len(base - {k}) + len(tw.get(k, set()) - base - {k}))
    return sorted(keys, key=lambda k: (-pay[k], (0, close[k]) if k in close else (1, 0), k[0], int(k[1], 16)))


def leverage_picks(inp, funcs, twins, words, route, l4=None, keys=None, band=None):
    """The --rank core (no harvest stamp, no audit, no file write): keys (None: U in leverage order) through --band, the
    --routing paid/journal filters (route: the routing path or None), static, components over U | keys, verdicts.
    l4 None: the exclude file's L4 rows. Returns dict(ranked, dropped {key: (state, reason)}, keys (candidates), vs,
    size, comp, paid, row, picks {key: pick}): every candidate of a component holding a survivor -> that component's
    first survivor in rank order, key != pick."""
    routes = routing(route) if route else []
    if l4 is None:
        l4 = {(p, v): why for _, p, v, layer, why in excludes(inp["exclude"]) if layer == "L4"}
    uni = universe(funcs)
    if keys is None:
        keys = leverage(inp, uni, funcs, twins)
    ranked, dropped = keys, {}  # dropped: {key: (state, reason)} of the pre-verdict filters
    if band:
        dropped.update((k, ("band", f"words={funcs[k]['words']}")) for k in keys
                       if not band[0] <= funcs[k]["words"] <= band[1])
        keys = [k for k in keys if band[0] <= funcs[k]["words"] <= band[1]]
    paid = [r for r in routes if r[2] == "paid"]
    row = lambda k: next((r for r in paid if r[0] <= funcs[k]["words"] <= r[1]), None)  # noqa: E731
    if route:
        tried = journaled(inp["journal"])
        isj = lambda k: (k[0], int(k[1], 16) if isinstance(k[1], str) else k[1]) in tried  # noqa: E731
        dropped.update((k, ("route", f"words={funcs[k]['words']}") if not row(k) else ("journal", "journaled"))
                       for k in keys if not row(k) or isj(k))
        keys = [k for k in keys if row(k) and not isj(k)]
    st = static(inp, keys, funcs, twins, words)
    comp, size = components(sorted(set(uni) | set(keys)), twins)
    vs = verdicts(keys, st, comp, l4)
    first = {}
    for k, layer, _ in vs:
        if not layer:
            first.setdefault(comp[k], k)
    picks = {k: first[comp[k]] for k in keys if comp[k] in first and first[comp[k]] != k}
    return dict(ranked=ranked, dropped=dropped, keys=keys, vs=vs, size=size, comp=comp, paid=paid, row=row,
                picks=picks)


def rank_run(inp, rank, wave, n=None, band=None, words=None, say=print, route=None, detail=False):
    """Writes <wdir>/W<n>.txt; returns its lines. Refuse rc 2 on a missing harvest stamp, a stale exclude or a
    malformed routing file (route: its path). detail: one `DRAW PV <pv> <state> <reason>` per ranked pv."""
    w = int(wave[1:])
    out = os.path.join(inp["wdir"], f"{wave}.txt")
    if os.path.exists(out):
        os.remove(out)
    if w >= 1 and not os.path.isfile(os.path.join(inp["harvest"], f"W{w - 1}.ok")):
        raise Refuse(2, [f"DRAW HARVEST-MISSING W{w - 1}"])
    if route:
        routing(route)  # a malformed routing file refuses before any input is read
    if rank == "leverage":
        need(inp, ("classes",))
    diff, funcs, twins = load(inp, diff=rank == "difficulty")
    l4 = audited(inp, funcs, twins, words, say, out)
    lp = leverage_picks(inp, funcs, twins, words, route, l4,
                        [(d["prog"], d["vram"]) for d in diff] if rank == "difficulty" else None, band)
    ranked, dropped, keys, comp, size, paid, row = (lp[x] for x in ("ranked", "dropped", "keys", "comp", "size",
                                                                    "paid", "row"))
    vs, cnt, k_drawn = counted(lp["vs"], n)
    drawn = [k for k, v, _, _ in vs if v == "draw"]
    pvs = [f"{k[0]}:{hexs(k[1])}" + (" probe=%d attempts=%d" % row(k)[3:] if route else "") for k in drawn]
    os.makedirs(os.path.dirname(out), exist_ok=True)
    with open(out, "w") as f:
        f.write("".join(x + "\n" for x in pvs))
    for r in paid:
        say(f"DRAW routing {r[0]}-{r[1]} {sum(row(k) == r for k in drawn)}")
    if detail:
        got = {k: ({"draw": "drawn"}.get(v, v) if not layer else layer, why or "-") for k, v, layer, why in vs}
        for k in ranked:
            say(f"DRAW PV {k[0]}:{hexs(k[1])} %s %s" % (dropped.get(k) or got[k]))
    held = {comp[k] for k in keys}
    summary(say, {c: s for c, s in size.items() if c in held}, vs, cnt, k_drawn)
    return pvs


# ---- self-test: planted inputs under .run/draw-selftest/, words injected ---------------------------------------------

P = "SELFTEST"


def pick_plant(prog, va, vb, rank=1, tu="T"):
    """The shared leverage-pick plant (draw and ledger self-tests): exact twins A (va, 8 words) and B (vb, 24 words),
    game lane, asm. Difficulty order puts A first (draw.jsonl: B `cluster of A`); leverage payoff (B 24 x 2 > A 8 x 2)
    picks B (A `cluster of B`). Returns (corpus rows, [exact twin row], difficulty rows A then B from rank)."""
    ab = (("A", va, 8), ("B", vb, 24))
    funcs = [dict(prog=prog, vram=v, end=hexs(int(v, 16) + 4 * w), words=w, name=f"pick_{n}", tu=tu, state="asm",
                  lane="game") for n, v, w in ab]
    diff = [dict(prog=prog, vram=v, name=f"pick_{n}", state="asm", lane="game", words=w, branches=0, calls=0, jtbl=0,
                 rank=rank + i) for i, (n, v, w) in enumerate(ab)]
    return funcs, [dict(a=[prog, va], b=[prog, vb], tier="exact", dist=0)], diff


def plant(root, stale=False):
    """Writes the planted input set under root; returns (inp, words, expected {vram: (verdict, layer, reason)})."""
    shutil.rmtree(root, ignore_errors=True)
    os.makedirs(root)
    inp = {k: os.path.join(root, os.path.basename(v)) for k, v in INPUTS.items()}
    inp["carve"] = os.path.join(root, "carve.{prog}.txt")
    inp["makefile"], inp["triples"] = INPUTS["makefile"], INPUTS["triples"]
    v = lambda i: "0x%08X" % (0x80100000 + 0x100 * i)  # noqa: E731
    #       i  lane   expected (verdict, layer, reason)
    plan = [(1, "lib", ("refused", "L1", "lib triple unproven LIBX.LIB/A.OBJ")),
            (2, "lib", ("draw", None, "")),
            (3, "game", ("refused", "L1", "jtbl not carved 0x80200000")),
            (4, "game", ("draw", None, "")),
            (5, "game", ("refused", "L2", "registry pending")),
            (6, "game", ("refused", "L2", f"banked twin {P}:{v(20)}")),
            (7, "game", ("eligible", None, "")),
            (8, "game", ("refused", "L2", f"cluster of {P}:{v(7)}")),
            (9, "game", ("refused", "L3", "wall combine dump.combine:7")),
            (10, "game", ("refused", "L4", "exclude planted hold")),
            (11, "game", ("eligible", None, ""))]
    lw = {2: 16, 4: 16, 7: 32, 8: 40, 11: 20}  # corpus words (leverage payoff, --band); others 64
    diff, funcs = [], []
    for rank, (i, lane, _) in enumerate(plan, 1):
        diff.append(dict(prog=P, vram=v(i), name=f"f{i}", state="asm", lane=lane, words=4, branches=0, calls=0,
                         jtbl=0, rank=rank))
        funcs.append(dict(prog=P, vram=v(i), end=v(i + 1), words=lw.get(i, 64), name=f"f{i}", tu="T", state="asm",
                          lane=lane))
    funcs.append(dict(prog=P, vram=v(20), end=v(21), words=64, name="f20", tu="T", state="c", lane="game"))
    files = {
        "diff": json.dumps(diff),
        "funcs": "\n".join(json.dumps(r) for r in funcs),
        "bounds": f"# program {P} base 0x80100000 size 0x2000\nlib {v(1)} {v(2)} LIBX.LIB/A.OBJ\n"
                  f"lib {v(2)} {v(3)} LIBX.LIB/B.OBJ\njtbl 0x80200000 0x80200010 {hexs(int(v(3), 16) + 8)} scan\n"
                  f"jtbl 0x80200010 0x80200020 {hexs(int(v(4), 16) + 8)} scan",
        "pin": "# pin\n## Proven lib units\n- LIBX.LIB/B.OBJ planted\n## Next",
        "registry": f"# registry\nk {P}:{v(30)} src/shared/x.c {P}:{v(5)} pending planted",
        "twins": "\n".join(json.dumps(t) for t in (
            dict(a=[P, v(6)], b=[P, v(20)], tier="exact", dist=0),
            dict(a=[P, v(3)], b=[P, v(11)], tier="exact", dist=0),
            dict(a=[P, v(7)], b=[P, v(8)], tier="near", dist=0.1))),
        "walls": f'# walls\n{P} {v(9)} combine dump.combine:7 "(insn 7)"',
        "exclude": f"# exclude\n{P} {v(10)} L4 planted hold\n{P} {v(9)} L3 mirror\n{P} {v(1)} L1 mirror\n"
                   f"{P} {v(8)} L2 mirror"
                   + (f"\n{P} {v(20)} L4 banked\n{P} {v(2)} L1 stale\n{P} {v(11)} L3 stale\n{P} {v(4)} L2 stale"
                      if stale else ""),
        "classes": "\n".join(json.dumps(c) for c in (
            dict(kind="dup", key="d1", size=16, members=[[P, v(2)], [P, v(4)]], reach=1),
            dict(kind="family", key="f1", size=16, members=[[P, v(2)], [P, v(3)], [P, v(4)]], reach=1))),
        "scaffold": json.dumps(dict(pv=f"{P}:{v(4)}", func="f4", words=16, score=3, n=16, state="compile")),
    }
    files[f"carve.{P}"] = "# carve\njtbl 0x80200010 T"
    for k, body in files.items():
        with open(inp[k] if k in inp else os.path.join(root, k + ".txt"), "w") as f:
            f.write(body + "\n")
    words = {(P, v(i)): [census.JR_RA, 0] for i, _, _ in plan}
    return inp, words, {v(i): e for i, _, e in plan}


def self_test():
    lines, fails = [], []

    def ok(cond, what):
        lines.append(f"DRAW CONTROL {'ok' if cond else 'FAIL'} {what}")
        if not cond:
            fails.append(what)

    inp, words, want = plant(SELFTEST)
    out, said = os.path.join(SELFTEST, "draw.jsonl"), []
    try:
        rows = run(inp, out, 2, words, said.append)
        got = {r["vram"]: (r["verdict"], r["layer"], r["reason"]) for r in rows}
        for vr, e in want.items():
            ok(got.get(vr) == e, f"{P}:{vr} -> {e[0]} {e[1] or '-'} {e[2]}")
        ok(said[-1:] == ["DRAW refused 7 of 11 (L1 2 L2 3 L3 1 L4 1); drawn 2"], f"DRAW line: {said[-1:]}")
        ok(said[:1] == ["EXCLUDE AUDIT 4 rows, 0 stale"], f"draw runs the audit first: {said[:1]}")
        ok(len(jl(out)) == 11, "draw.jsonl one row per difficulty function")
        _, funcs, twins = load(inp, diff=False)
        ok(audit(inp, funcs, twins, words)[:2] == (["EXCLUDE AUDIT 4 rows, 0 stale"], 0),
           "clean audit (L1 L2 L3 L4 rows) -> EXCLUDE AUDIT 4 rows, 0 stale")
    except Refuse as e:
        ok(False, f"planted set refused rc {e.rc}: {e.lines[0]}")
    pv = lambda i: f"{P}:0x{0x80100000 + 0x100 * i:08X}"  # noqa: E731
    wfile = lambda w: os.path.join(inp["wdir"], f"{w}.txt")  # noqa: E731

    def wave(what, want, rank="leverage", w="W0", n=3, band=None, line=None):
        said = []
        try:
            got = rank_run(inp, rank, w, n, band, words, said.append)
            with open(wfile(w)) as f:
                body = f.read().split()
            ok(got == body == [pv(i) for i in want] and (line is None or said[-1] == line), f"{what}: {body}")
        except Refuse as e:
            ok(False, f"{what}: refused rc {e.rc} {e.lines[0]}")

    wave("leverage W0 = payoff order, closeness and (prog, vram) ties", [4, 2, 8],
         line="DRAW refused 7 of 11 (L1 2 L2 3 L3 1 L4 1); drawn 3")
    wave("leverage --band 16-20", [4, 2, 11], band=(16, 20), n=9, line="DRAW refused 0 of 3 (L1 0 L2 0 L3 0 L4 0); drawn 3")
    said = []
    try:
        rank_run(inp, "leverage", "W0", 3, (16, 20), words, said.append, detail=True)
        dl = [x for x in said if x.startswith("DRAW PV ")]
        ok(f"DRAW PV {pv(10)} band words=64" in dl and f"DRAW PV {pv(4)} drawn -" in dl and len(dl) == 11
           and said.index(dl[-1]) < len(said) - 2, f"--detail band: L4 plant band, drawn plant drawn: {dl}")
        said = []
        rank_run(inp, "leverage", "W0", 3, None, words, said.append, detail=True)
        dl = [x for x in said if x.startswith("DRAW PV ")]
        ok(f"DRAW PV {pv(10)} L4 exclude planted hold" in dl and f"DRAW PV {pv(4)} drawn -" in dl
           and sum(x.split()[3] == "drawn" for x in dl) == 3 and said[-2].startswith("DRAW-DETAIL ")
           and said[-1] == "DRAW refused 7 of 11 (L1 2 L2 3 L3 1 L4 1); drawn 3",
           f"--detail: L4 plant -> DRAW PV <pv> L4, drawn plant -> drawn, counts unchanged: {dl}")
    except Refuse as e:
        ok(False, f"--detail: refused rc {e.rc} {e.lines[0]}")
    wave("difficulty --wave W0 = difficulty order", [2, 4, 7], rank="difficulty")
    try:
        rank_run(inp, "leverage", "W2", 3, None, words, lambda s: None)
        ok(False, "W2 without W1.ok -> rc 2")
    except Refuse as e:
        ok(e.rc == 2 and e.lines == ["DRAW HARVEST-MISSING W1"] and not os.path.exists(wfile("W2")),
           "W2 without W1.ok -> DRAW HARVEST-MISSING W1, rc 2, no W2.txt")
    os.makedirs(inp["harvest"], exist_ok=True)
    with open(os.path.join(inp["harvest"], "W0.ok"), "w") as f:
        f.write("planted\n")
    wave("W1 with W0.ok -> drawn", [4, 2, 8], w="W1")
    root = os.path.join(SELFTEST, "routing")  # the real config/routing.txt; f7 planted at 950 words (a ledger row)
    rinp, rwords, _ = plant(root)
    rows = jl(rinp["funcs"])
    for r in rows:
        r["words"] = 950 if r["name"] == "f7" else r["words"]
    with open(rinp["funcs"], "w") as f:
        f.write("".join(json.dumps(r) + "\n" for r in rows))
    said = []
    try:
        got = rank_run(rinp, "leverage", "W0", 9, None, rwords, said.append, route="config/routing.txt")
        rl = [x for x in said if x.startswith("DRAW routing ")]
        ok(pv(7) not in [x.split()[0] for x in got] and f"{pv(11)} probe=18 attempts=2" in got and len(rl) == 5,
           f"--routing: 950-word f7 not drawn, 20-word f11 probe=18 attempts=2, 5 routing lines: {got} {rl}")
        was = pv(4) in [x.split()[0] for x in got]
        with open(rinp["journal"], "w") as f:  # the plant root's journal, never campaign/journal.jsonl
            f.write(json.dumps(dict(wave="W0", pv=pv(4), func="f4", words=16, verdict="fail")) + "\n")
        said = []
        got = rank_run(rinp, "leverage", "W0", 9, None, rwords, said.append, route="config/routing.txt")
        rl = [x for x in said if x.startswith("DRAW routing ")]
        ok(was and pv(4) not in [x.split()[0] for x in got] and f"{pv(11)} probe=18 attempts=2" in got
           and len(rl) == 5, f"--routing: journaled f4 (drawn without the record) not drawn: {got} {rl}")
    except Refuse as e:
        ok(False, f"--routing: refused rc {e.rc} {e.lines[0]}")
    bad = os.path.join(root, "routing-overlap.txt")
    with open(bad, "w") as f:
        f.write("# planted\n1-16 paid 6 2\n10-20 paid 6 2\n")
    try:
        rank_run(rinp, "leverage", "W0", 9, None, rwords, lambda s: None, route=bad)
        ok(False, "overlapping routing row -> rc 2")
    except Refuse as e:
        ok(e.rc == 2 and e.lines == [f"DRAW MALFORMED {bad}:3"]
           and not os.path.exists(os.path.join(rinp["wdir"], "W0.txt")),
           "overlapping routing row -> DRAW MALFORMED <path>:3, rc 2, no W0.txt")
    root = os.path.join(SELFTEST, "pick")  # pick_plant: difficulty rep A, leverage pick B
    pinp, pwords, _ = plant(root)
    va, vb = pv(40)[len(P) + 1:], pv(41)[len(P) + 1:]
    pf, pt, pd = pick_plant(P, va, vb, rank=20)
    for k, extra in (("funcs", pf), ("twins", pt)):
        with open(pinp[k], "a") as f:
            f.write("".join(json.dumps(r) + "\n" for r in extra))
    with open(pinp["diff"]) as f:
        diff = json.load(f)
    with open(pinp["diff"], "w") as f:
        json.dump(diff + pd, f)
    pwords.update({(P, va): [census.JR_RA, 0], (P, vb): [census.JR_RA, 0]})
    try:
        got = {r["vram"]: (r["layer"], r["reason"]) for r in run(pinp, os.path.join(root, "draw.jsonl"), None, pwords,
                                                                 lambda s: None)}
        said = []
        drew = rank_run(pinp, "leverage", "W0", None, None, pwords, said.append, detail=True)
        ok(got[vb] == ("L2", f"cluster of {pv(40)}") and got[va] == (None, "") and pv(41) in drew
           and pv(40) not in drew and f"DRAW PV {pv(40)} L2 cluster of {pv(41)}" in said,
           f"pick plant: difficulty B cluster of A; leverage draws B, refuses A cluster of B: {drew}")
    except Refuse as e:
        ok(False, f"pick plant: refused rc {e.rc} {e.lines[0]}")
    root = os.path.join(SELFTEST, "stale")
    inp, words, _ = plant(root, stale=True)
    out = os.path.join(root, "draw.jsonl")
    with open(out, "w") as f:  # a previous draw.jsonl must not survive a refused audit
        f.write("{}\n")
    try:
        run(inp, out, None, words, lambda s: None)
        ok(False, "planted stale exclude row -> rc 2")
    except Refuse as e:
        ok(e.rc == 2 and any(x.startswith("DRAW STALE ") for x in e.lines) and not os.path.exists(out),
           "planted stale exclude row -> DRAW STALE, rc 2, no draw.jsonl")
    _, funcs, twins = load(inp, diff=False)
    want = [f"DRAW STALE {P} {pv(20)[len(P) + 1:]} L4 not in universe",
            f"DRAW STALE {P} {pv(2)[len(P) + 1:]} L1 L1 no longer refuses it",
            f"DRAW STALE {P} {pv(11)[len(P) + 1:]} L3 L3 no longer refuses it",
            f"DRAW STALE {P} {pv(4)[len(P) + 1:]} L2 L2 no longer refuses it",
            "EXCLUDE AUDIT 8 rows, 4 stale"]
    got = audit(inp, funcs, twins, words)
    ok(got[:2] == (want, 4), "audit: one stale row per class (not in universe, L1, L3, L2) -> exact lines, s 4")
    os.makedirs(inp["wdir"], exist_ok=True)
    with open(wfile("W0"), "w") as f:
        f.write("planted\n")
    try:
        rank_run(inp, "leverage", "W0", 3, None, words, lambda s: None)
        ok(False, "stale exclude row refuses a --rank draw")
    except Refuse as e:
        ok(e.rc == 2 and e.lines == want and not os.path.exists(wfile("W0")),
           "stale exclude row refuses a --rank draw: rc 2, no W0.txt")
    lines.append("DRAW CONTROL OK" if not fails else f"DRAW CONTROL FAIL {len(fails)}")
    for x in lines:
        print(x)
    return 1 if fails else 0


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--n", type=int, metavar="K")
    ap.add_argument("--audit", action="store_true")
    ap.add_argument("--rank", choices=("leverage", "difficulty"))
    ap.add_argument("--band", metavar="LO-HI")
    ap.add_argument("--wave", metavar="W<n>")
    ap.add_argument("--routing", metavar="FILE")
    ap.add_argument("--detail", action="store_true")
    ap.add_argument("--self-test", action="store_true")
    a = ap.parse_args()
    if bool(a.rank) != bool(a.wave) or ((a.band or a.routing or a.detail) and not a.rank):
        ap.error("--rank needs --wave; --wave, --band, --routing and --detail need --rank")
    if a.wave and not re.fullmatch(r"W\d+", a.wave):
        ap.error("--wave takes W<n>, n >= 0")
    band = None
    if a.band:
        m = re.fullmatch(r"(\d+)-(\d+)", a.band)
        if not m:
            ap.error("--band takes <lo>-<hi>")
        band = (int(m.group(1)), int(m.group(2)))
    os.chdir(os.path.join(HERE, "..", ".."))
    if a.self_test:
        return self_test()
    try:
        if a.audit:
            _, funcs, twins = load(INPUTS, diff=False)
            lines, s, _ = audit(INPUTS, funcs, twins)
            print("\n".join(lines))
            return 2 if s else 0
        if a.rank:
            rank_run(INPUTS, a.rank, a.wave, a.n, band, route=a.routing, detail=a.detail)
            return 0
        run(INPUTS, OUT, a.n)
    except Refuse as e:
        for x in e.lines:
            print(x)
        return e.rc
    except census.Refuse as e:
        print(str(e).splitlines()[0])
        return 1
    return 0


if __name__ == "__main__":
    sys.exit(main())
