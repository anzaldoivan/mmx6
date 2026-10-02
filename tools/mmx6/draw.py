#!/usr/bin/env python3
"""draw.py -- the draw filter: which ranked not-yet-C functions a wave may draw (container, stdlib only).

  draw.py [--n K]
      -> build/draw/draw.jsonl, one row per build/reports/difficulty.json function in rank order
         {prog,vram,verdict:"draw|eligible|refused",layer,reason}: the first K survivors `draw` (no --n: all),
         later survivors `eligible`, the rest `refused` at the first layer that refuses them; stdout counts only (G12):
         `DRAW-DETAIL clusters <c> largest <k> survivors <s>`, last line
         `DRAW refused <r> of <n> (L1 <a> L2 <b> L3 <c> L4 <d>); drawn <k>` (r = a+b+c+d, independent of K).
         rc 1 on a missing input; rc 2 on a malformed or stale config/draw_exclude.txt row (`DRAW STALE <prog> <vram>
         <layer> <why>` per stale row; no draw.jsonl written).
  draw.py --self-test
      -> planted inputs in .run/draw-selftest/ (words injected): lib-unproven, uncarved jtbl, registry member,
         banked exact twin, two-member cluster, wall row, L4 row, each at its layer, and the exact DRAW line; a planted
         stale exclude row -> rc 2 and nothing written; ends `DRAW CONTROL OK` (rc 0), else rc 1.

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
              exclude="config/draw_exclude.txt", makefile="Makefile", triples="config/triples.txt")
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


# ---- verdicts ------------------------------------------------------------------------------------------------------

def load(inp):
    req = [v for k, v in inp.items() if k != "carve"]
    miss = [p for p in req if not os.path.isfile(p)]
    if miss:
        raise Refuse(1, [f"DRAW REFUSE missing {p}" for p in miss])
    with open(inp["diff"]) as f:
        diff = sorted(json.load(f), key=lambda d: d["rank"])
    funcs = {(r["prog"], r["vram"]): r for r in jl(inp["funcs"])}
    miss = [d for d in diff if (d["prog"], d["vram"]) not in funcs]
    if miss:
        raise Refuse(1, [f"DRAW REFUSE {len(miss)} difficulty functions not in {inp['funcs']} (stale report)"])
    return diff, funcs


def static(inp, diff, funcs, words=None):
    """Per difficulty key the order-independent refusals: {key: {"L1": reason|None, "L2": .., "L3": ..}}."""
    good = proven(inp["pin"])
    lib, jt = boundaries(inp["bounds"])
    pin = pin_cflags(inp["makefile"], inp["triples"])
    reg = {}
    for _, t in propagate.registry_rows(inp["registry"]):
        reg.setdefault(tuple(t[3].rsplit(":", 1)), t[4])
    twins = jl(inp["twins"])
    banked = {}
    for t in twins:
        if t["tier"] == "exact":
            for x, y in ((t["a"], t["b"]), (t["b"], t["a"])):
                r = funcs.get(tuple(y))
                if r and r["state"] in ("c", "c-empty"):
                    banked.setdefault(tuple(x), []).append(tuple(y))
    keys = [(d["prog"], d["vram"]) for d in diff]
    out, cv = {}, {}
    for d, k in zip(diff, keys):
        p, v = k
        r = funcs[k]
        lo, hi = int(v, 16), r["end"] if isinstance(r["end"], int) else int(r["end"], 16)
        if p not in cv:
            cv[p] = carves(inp["carve"], p)
        tabs, opt = cv[p]
        l1 = None
        if d["lane"] == "lib":
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
    return out, components(keys, twins)


def verdicts(diff, st, comp, l4):
    """[(key, layer|None, reason)] in rank order; l4 = {key: reason} of the L4 excludes."""
    out, held = [], {}
    for d in diff:
        k = (d["prog"], d["vram"])
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


def run(inp, out, n=None, words=None, say=print):
    """Writes out; returns the (key, verdict, layer, reason) rows. Refuse on a missing input or a stale exclude."""
    diff, funcs = load(inp)
    ex = excludes(inp["exclude"])
    st, (comp, size) = static(inp, diff, funcs, words)
    base = {k: (layer, why) for k, layer, why in verdicts(diff, st, comp, {})}
    stale = []
    for _, p, v, layer, _ in ex:
        k = (p, v)
        if k not in st:
            stale.append(f"DRAW STALE {p} {v} {layer} not in difficulty")
        elif layer in ("L1", "L3") and not st[k][layer]:
            stale.append(f"DRAW STALE {p} {v} {layer} {layer} no longer refuses it")
        elif layer == "L2" and not st[k]["L2"] and not base[k][1].startswith("cluster of "):
            stale.append(f"DRAW STALE {p} {v} {layer} L2 no longer refuses it")
    if stale:
        if os.path.exists(out):
            os.remove(out)
        raise Refuse(2, stale)
    vs = verdicts(diff, st, comp, {(p, v): why for _, p, v, layer, why in ex if layer == "L4"})
    rows, k_drawn, cnt = [], 0, dict.fromkeys(LAYERS, 0)
    for k, layer, why in vs:
        if layer:
            cnt[layer] += 1
            verdict = "refused"
        elif n is None or k_drawn < n:
            verdict, k_drawn = "draw", k_drawn + 1
        else:
            verdict = "eligible"
        rows.append(dict(prog=k[0], vram=k[1], verdict=verdict, layer=layer, reason=why))
    os.makedirs(os.path.dirname(out), exist_ok=True)
    with open(out, "w") as f:
        for r in rows:
            f.write(json.dumps(r) + "\n")
    r = sum(cnt.values())
    say(f"DRAW-DETAIL clusters {len(size)} largest {max(size.values(), default=0)} survivors {len(rows) - r}")
    say(f"DRAW refused {r} of {len(rows)} (" + " ".join(f"{x} {cnt[x]}" for x in LAYERS) + f"); drawn {k_drawn}")
    return rows


# ---- self-test: planted inputs under .run/draw-selftest/, words injected ---------------------------------------------

P = "SELFTEST"


def plant(root, stale=False):
    """Writes the planted input set under root; returns (inp, words, expected {vram: (verdict, layer, reason)})."""
    os.makedirs(root, exist_ok=True)
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
    diff, funcs = [], []
    for rank, (i, lane, _) in enumerate(plan, 1):
        diff.append(dict(prog=P, vram=v(i), name=f"f{i}", state="asm", lane=lane, words=4, branches=0, calls=0,
                         jtbl=0, rank=rank))
        funcs.append(dict(prog=P, vram=v(i), end=v(i + 1), words=64, name=f"f{i}", tu="T", state="asm", lane=lane))
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
            dict(a=[P, v(7)], b=[P, v(8)], tier="near", dist=0.1))),
        "walls": f'# walls\n{P} {v(9)} combine dump.combine:7 "(insn 7)"',
        "exclude": f"# exclude\n{P} {v(10)} L4 planted hold\n{P} {v(9)} L3 mirror"
                   + (f"\n{P} {v(11)} L3 stale" if stale else ""),
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
        ok(len(jl(out)) == 11, "draw.jsonl one row per difficulty function")
    except Refuse as e:
        ok(False, f"planted set refused rc {e.rc}: {e.lines[0]}")
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
    lines.append("DRAW CONTROL OK" if not fails else f"DRAW CONTROL FAIL {len(fails)}")
    for x in lines:
        print(x)
    return 1 if fails else 0


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--n", type=int, metavar="K")
    ap.add_argument("--self-test", action="store_true")
    a = ap.parse_args()
    os.chdir(os.path.join(HERE, "..", ".."))
    if a.self_test:
        return self_test()
    try:
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
