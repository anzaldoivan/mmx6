#!/usr/bin/env python3
"""sig.py -- per-function signatures and the twin band (exact + near duplicates) of the corpus (container, stdlib).

  sig.py --all
      -> build/sig/sigs.jsonl {prog,vram,words,exact,norm,hist} per corpus function (words = count; exact =
         census.dup_key; norm = masked words w & ~mask, hex; hist = census.skel histogram of norm, {skel hex: n}),
         build/sig/twins.jsonl {a:[prog,vram],b:[prog,vram],tier:"exact|near",dist} a<b, sorted (tier,a,b);
         last line `TWINS exact_pairs <e> of <E> in band; near <n>; base_rate <r>% of <q> random pairs; of <N> functions`.
  sig.py --rescan
      -> as --all, reusing sigs rows whose TU object is not newer than sigs.jsonl; prints
         `SIG RESCAN recomputed <k> of <N> functions` before the TWINS line.
  sig.py --for <prog:vram>
      -> `TWIN <prog:vram> <tier> <dist> <name>` per twin over all N, last `FOR <p:v> exact <x> near <y> of <N> functions`.
  sig.py --self-test
      -> planted in memory (C0054): jal-relocated twin -> exact; masks off -> not exact (C0055); one-instruction edit
         -> near; unrelated -> out; edit past RATIO -> out; dropped class pair -> e<E, rc 1. Ends `SIG CONTROL OK`.

Band: exact = equal exact key (dist 0). near = not exact, max_len >= 4, len min/max >= 0.75, skel-hist L1 <=
2*RATIO*max_len (lossless: a substitution moves the histogram by <= 2, an indel by 1), Levenshtein(norm)/max_len <=
RATIO (dist = that ratio, 4 decimals). RATIO = 0.3. Near pairs are scanned over one representative per exact key and
expanded to members; candidates come from a lossless prefix filter (a near pair shares >= max_len - floor(RATIO*max_len)
norm tokens, so their rarest-first prefixes of floor(RATIO*len)+1 tokens intersect). E = sum C(n,2) over kind=dup
classes of build/census/classes.jsonl; e = those pairs this band places in band. rc 1 if e < E, the classes' member set
!= the corpus set (stale census), or census.read_words refuses. Base rate: q random distinct pairs, Random(0x516).
Words and masks come only from census.read_words. Firewall G12: stdout counts only (names/addresses only in --for).
"""
import argparse
import json
import os
import random
import sys
from collections import Counter
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import census  # noqa: E402

OUT = "build/sig"
SIGS = f"{OUT}/sigs.jsonl"
TWINS = f"{OUT}/twins.jsonl"
CLASSES = "build/census/classes.jsonl"
RATIO = 0.3
RN, RD = 3, 10  # RATIO as an exact fraction for integer comparisons
MIN_LEN = 4
LEN_NUM, LEN_DEN = 3, 4  # len ratio min/max >= 0.75
Q = 100000
SEED = 0x516
NEAR_CAP = 5000000


# ---- signatures ------------------------------------------------------------------------------------------------------

def sig_of(prog, vram, words, mask):
    norm = [w & ~m & 0xFFFFFFFF for w, m in zip(words, mask)]
    hist = Counter(census.skel(w) for w in norm)
    return dict(prog=prog, vram=vram, words=len(words), exact=census.dup_key(words, mask), norm=norm, hist=hist)


def to_json(s):
    return dict(prog=s["prog"], vram=s["vram"], words=s["words"], exact=s["exact"],
                norm=[f"{w:08x}" for w in s["norm"]], hist={f"{k:x}": s["hist"][k] for k in sorted(s["hist"])})


def from_json(d):
    return dict(prog=d["prog"], vram=d["vram"], words=d["words"], exact=d["exact"],
                norm=[int(w, 16) for w in d["norm"]], hist=Counter({int(k, 16): v for k, v in d["hist"].items()}))


def compute(rows):
    return [sig_of(r["prog"], r["vram"], w, m) for r, (w, m) in zip(rows, census.read_words(rows))]


# ---- band ------------------------------------------------------------------------------------------------------------

def lev(a, b, k):
    """Levenshtein distance of token lists a, b (Myers/Hyyro bit-vector, bigint), or None once it must exceed k."""
    if len(a) < len(b):
        a, b = b, a
    m, n = len(a), len(b)
    if n == 0:
        return m if m <= k else None
    peq = {}
    for i, c in enumerate(a):
        peq[c] = peq.get(c, 0) | (1 << i)
    mask, hb = (1 << m) - 1, 1 << (m - 1)
    pv, mv, score = mask, 0, m
    for j, c in enumerate(b):
        eq = peq.get(c, 0)
        xv = eq | mv
        xh = (((eq & pv) + pv) ^ pv) | eq
        ph = mv | ~(xh | pv)
        mh = pv & xh
        if ph & hb:
            score += 1
        elif mh & hb:
            score -= 1
        if score - (n - 1 - j) > k:
            return None
        ph = (ph << 1) | 1
        pv = ((mh << 1) | ~(xv | ph)) & mask
        mv = ph & xv
    return score if score <= k else None


def l1(ha, hb):
    return sum(abs(ha.get(x, 0) - hb.get(x, 0)) for x in ha.keys() | hb.keys())


def near(a, b):
    """dist ratio if a, b are a near pair (exact keys assumed different), else None."""
    la, lb = a["words"], b["words"]
    mx, mn = max(la, lb), min(la, lb)
    if mx < MIN_LEN or LEN_DEN * mn < LEN_NUM * mx:
        return None
    if RD * l1(a["hist"], b["hist"]) > 2 * RN * mx:
        return None
    d = lev(a["norm"], b["norm"], (RN * mx) // RD)
    return None if d is None else round(d / mx, 4)


def band(a, b):
    """(tier, dist) or None."""
    if a["exact"] == b["exact"]:
        return ("exact", 0)
    d = near(a, b)
    return None if d is None else ("near", d)


def ident(s):
    return [s["prog"], s["vram"]]


def near_reps(reps):
    """[(i, j, dist)] near pairs among representatives (distinct exact keys), via the lossless prefix filter."""
    tok = []
    for s in reps:
        seen = Counter()
        t = []
        for w in s["norm"]:
            t.append((w, seen[w]))
            seen[w] += 1
        tok.append(t)
    freq = Counter(x for t in tok for x in t)
    order = sorted(range(len(reps)), key=lambda i: (reps[i]["words"], i))
    index, out = {}, []
    for i in order:
        s = reps[i]
        li = s["words"]
        if li < MIN_LEN:
            continue
        pre = sorted(tok[i], key=lambda x: (freq[x], x))[:(RN * li) // RD + 1]
        cand = set()
        for x in pre:
            lst = index.setdefault(x, [])
            for j in reversed(lst):
                if LEN_DEN * reps[j]["words"] < LEN_NUM * li:
                    break
                cand.add(j)
            lst.append(i)
        for j in sorted(cand):
            d = near(reps[j], s)
            if d is not None:
                out.append((i, j, d))
    return out


def twins(sigs):
    """(twin rows, near pair count) or (None, near count) past NEAR_CAP."""
    groups = {}
    for s in sigs:
        groups.setdefault(s["exact"], []).append(s)
    rows = []
    for m in groups.values():
        for x in range(len(m)):
            for y in range(x + 1, len(m)):
                a, b = sorted([ident(m[x]), ident(m[y])])
                rows.append(dict(a=a, b=b, tier="exact", dist=0))
    keys = sorted(groups)
    reps = [groups[k][0] for k in keys]
    pairs = near_reps(reps)
    n_near = sum(len(groups[keys[i]]) * len(groups[keys[j]]) for i, j, _ in pairs)
    if n_near > NEAR_CAP:
        return None, n_near
    for i, j, d in pairs:
        for p in groups[keys[i]]:
            for q in groups[keys[j]]:
                a, b = sorted([ident(p), ident(q)])
                rows.append(dict(a=a, b=b, tier="near", dist=d))
    rows.sort(key=lambda r: (r["tier"], r["a"], r["b"]))
    return rows, n_near


def class_check(classes, by_id):
    """(e, E) over kind=dup classes: e = member pairs in band."""
    e = E = 0
    for c in classes:
        if c["kind"] != "dup":
            continue
        m = [by_id[tuple(x)] for x in c["members"]]
        n = len(m)
        E += n * (n - 1) // 2
        if len({s["exact"] for s in m}) == 1:
            e += n * (n - 1) // 2
            continue
        e += sum(1 for x in range(n) for y in range(x + 1, n) if band(m[x], m[y]) is not None)
    return e, E


def base_rate(sigs):
    rng = random.Random(SEED)
    n = len(sigs)
    seen = set()
    while len(seen) < min(Q, n * (n - 1) // 2):
        i, j = rng.randrange(n), rng.randrange(n)
        if i != j:
            seen.add((min(i, j), max(i, j)))
    hits = sum(1 for i, j in sorted(seen) if band(sigs[i], sigs[j]) is not None)
    return f"{100 * hits / max(len(seen), 1):.2f}", len(seen)


# ---- runs ------------------------------------------------------------------------------------------------------------

def load_classes():
    if not os.path.isfile(CLASSES):
        raise census.Refuse(f"REFUSE missing {CLASSES} (run census.py --all)")
    with open(CLASSES) as f:
        return [json.loads(line) for line in f if line.strip()]


def write_sigs(sigs):
    os.makedirs(OUT, exist_ok=True)
    with open(SIGS, "w") as f:
        for s in sigs:
            f.write(json.dumps(to_json(s)) + "\n")


def load_sigs():
    if not os.path.isfile(SIGS):
        return None
    with open(SIGS) as f:
        return [from_json(json.loads(line)) for line in f if line.strip()]


def finish(sigs):
    """Write twins, check against the census, print the TWINS line; rc."""
    classes = load_classes()
    by_id = {(s["prog"], s["vram"]): s for s in sigs}
    cset = {tuple(x) for c in classes if c["kind"] == "dup" for x in c["members"]}
    if cset != set(by_id):
        print(f"SIG REFUSE stale census: {len(cset - set(by_id))} class members not in corpus, "
              f"{len(set(by_id) - cset)} corpus functions not in classes of {len(sigs)} functions")
        return 1
    rows, n_near = twins(sigs)
    if rows is None:
        print(f"SIG STOP near pairs {n_near} > {NEAR_CAP} of {len(sigs)} functions")
        return 1
    with open(TWINS, "w") as f:
        for r in rows:
            f.write(json.dumps(r) + "\n")
    e, E = class_check(classes, by_id)
    r, q = base_rate(sigs)
    print(f"TWINS exact_pairs {e} of {E} in band; near {n_near}; base_rate {r}% of {q} random pairs; "
          f"of {len(sigs)} functions")
    return 0 if e == E else 1


def run_all():
    sigs = compute(census.load_rows())
    write_sigs(sigs)
    return finish(sigs)


def rescan():
    rows = census.load_rows()
    old = load_sigs()
    keep = {}
    if old is not None:
        t = os.path.getmtime(SIGS)
        idx = census.asm_index() if os.path.isdir("asm") else {}
        olds = {(s["prog"], s["vram"]): s for s in old}
        for r in rows:
            s, obj = olds.get((r["prog"], r["vram"])), census.obj_of(r, idx)
            if s and s["words"] == r["words"] and obj and os.path.isfile(obj) and os.path.getmtime(obj) <= t:
                keep[(r["prog"], r["vram"])] = s
    todo = [r for r in rows if (r["prog"], r["vram"]) not in keep]
    fresh = {(s["prog"], s["vram"]): s for s in compute(todo)}
    sigs = [keep.get((r["prog"], r["vram"])) or fresh[(r["prog"], r["vram"])] for r in rows]
    write_sigs(sigs)
    print(f"SIG RESCAN recomputed {len(todo)} of {len(rows)} functions")
    return finish(sigs)


def for_one(pv):
    rows = census.load_rows()
    sigs = load_sigs()
    if sigs is None:
        sigs = compute(rows)
    names = {(r["prog"], r["vram"]): r["name"] for r in rows}
    prog, _, v = pv.rpartition(":")
    try:
        key = (prog, f"0x{int(v, 16):08X}")
    except ValueError:
        key = None
    me = next((s for s in sigs if (s["prog"], s["vram"]) == key), None)
    if me is None:
        print(f"FOR {pv} unknown of {len(sigs)} functions")
        return 1
    hits = []
    for s in sigs:
        if s is not me:
            b = band(me, s)
            if b is not None:
                hits.append((b[0], s["prog"], s["vram"], b[1]))
    hits.sort(key=lambda h: (h[0], h[1], h[2]))
    for tier, p, vr, d in hits:
        print(f"TWIN {p}:{vr} {tier} {d} {names.get((p, vr), '?')}")
    x = sum(1 for h in hits if h[0] == "exact")
    print(f"FOR {key[0]}:{key[1]} exact {x} near {len(hits) - x} of {len(sigs)} functions")
    return 0


# ---- self-test -------------------------------------------------------------------------------------------------------

LUI_A0, ADDIU_A0, JAL, NOP, JR_RA = 0x3C040000, 0x24840000, 0x0C000000, 0, census.JR_RA
BODY = [0x27BDFFE8, 0xAFBF0010, 0x8C820004, 0x00431021, 0x24420001, 0xAC820004, 0x8FBF0010, 0x27BD0018]
OTHER = [0x10400003, 0x00851023, 0x00021080, 0x3C028001, 0x90420123, 0x14400002, 0x00052900, 0x0005282B,
         0x30A500FF, 0x03E00008, 0x00000000, 0x00001025]
HILO_JAL = [0xFFFF, 0xFFFF, 0x03FFFFFF, 0, 0, 0]


def self_test():
    fails = []

    def ok(cond, what):
        print(f"SIG CONTROL {'ok' if cond else 'FAIL'} {what}")
        if not cond:
            fails.append(what)

    ta = [LUI_A0 | 0x8001, ADDIU_A0 | 0x1230, JAL | 0x0004000, NOP, JR_RA, NOP]
    tb = [LUI_A0 | 0x8002, ADDIU_A0 | 0x0040, JAL | 0x0008800, NOP, JR_RA, NOP]
    a, b = sig_of("st", "0x80010000", ta, HILO_JAL), sig_of("st", "0x80020000", tb, HILO_JAL)
    ok(band(a, b) == ("exact", 0), "jal/%hi/%lo-relocated twin -> exact")
    a0, b0 = sig_of("st", "0x80010000", ta, [0] * 6), sig_of("st", "0x80020000", tb, [0] * 6)
    ok(band(a0, b0) is None or band(a0, b0)[0] != "exact", "same twin with masks off -> not exact (C0055)")
    base = BODY + [JR_RA, NOP]
    edit = list(base)
    edit[4] = 0x24420002
    f, g = sig_of("st", "0x80030000", base, [0] * 10), sig_of("st", "0x80040000", edit, [0] * 10)
    ok(band(f, g) is not None and band(f, g)[0] == "near", f"one-instruction edit of a 10-word fn -> near {band(f, g)}")
    u = sig_of("st", "0x80050000", OTHER, [0] * 12)
    ok(band(f, u) is None, "unrelated pair -> out of band")
    far = list(base)
    for i in (1, 2, 4, 5):
        far[i] ^= 0x8
    h = sig_of("st", "0x80060000", far, [0] * 10)
    ok(lev(f["norm"], h["norm"], 10) == 4 and band(f, h) is None, "4 edits of 10 words (dist 0.4 > RATIO) -> out")
    by_id = {(s["prog"], s["vram"]): s for s in (a, b, f, u)}
    cls = [dict(kind="dup", key="x", size=6, members=[["st", "0x80010000"], ["st", "0x80020000"]]),
           dict(kind="dup", key="y", size=10, members=[["st", "0x80030000"], ["st", "0x80050000"]])]
    e, E = class_check(cls, by_id)
    ok(e == 1 and E == 2 and e < E, f"dropped class pair -> e {e} < E {E} (rc 1 path)")
    if fails:
        print(f"SIG CONTROL FAIL {len(fails)}")
        return 1
    print("SIG CONTROL OK")
    return 0


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    g = ap.add_mutually_exclusive_group(required=True)
    g.add_argument("--all", action="store_true")
    g.add_argument("--self-test", action="store_true")
    g.add_argument("--rescan", action="store_true")
    g.add_argument("--for", dest="for_", metavar="PROG:VRAM")
    a = ap.parse_args()
    try:
        if a.self_test:
            rc = self_test()
        elif a.rescan:
            rc = rescan()
        elif a.for_:
            rc = for_one(a.for_)
        else:
            rc = run_all()
    except census.Refuse as e:
        print(e)
        rc = 1
    sys.exit(rc)


if __name__ == "__main__":
    main()
