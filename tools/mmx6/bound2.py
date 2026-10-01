#!/usr/bin/env python3
"""bound2.py -- second boundary oracle B2, built from retail bytes independently of splat (phase 1.5 T4; stdlib).

  bound2.py --all | --prog <p>
      -> build/bound2/<prog>.jsonl {"prog","vram","end","basis":"ghidra|jal|head|post-ret"} (end null if unended)
         build/bound2/disagreements.txt  `## <class>` groups, lines `<kind> <prog> <vram> <detail>`
         stdout ends `BOUND2 UNENDED <k>`, `BOUND2 CLASSES <class>=<n> ...`,
         `BOUND2 phantoms=<p> truncations=<t> ledgered=<x> of <N> functions in <P> programs`;
         rc 0 iff p = t = 0 and no stale ledger row; 1 otherwise; 2 bad input.
  bound2.py --self-test
      -> real data: the `banked` rows of config/probes.txt and func_80055A04 agree with B2; in-memory controls (a
         function split at a mid non-B2 word -> phantom there; a function's end cut by 8 -> truncation at its start)
         must be reported; HEAD_CONTROL starts have basis head; an in-memory ledger row on a known disagreement is
         ledgered and leaves the counts, a row matching nothing is stale with rc 1. Ends `BOUND2 CONTROL OK` (rc 0),
         else rc 1 naming what was missed. Merge controls (injected): synthetic forward branch past an interior
         jr ra -> multi-return at that site; synthetic straight pair -> over-merge; two adjacent agreeing exe
         functions fused in memory -> over-merge at the second start.
  --all/--prog also write build/bound2/merges.txt `<prog> <F vram> <s vram> multi-return|over-merge <site|->` (sorted
  prog, s) and build/bound2/independence.jsonl {"prog","vram","basis":"ghidra|pointer|none"}; stdout adds
  `BOUND2 INNER <n> (<prog> <n> x5)`, `BOUND2 merges=<over> multi-return=<m> of <N> functions`,
  `BOUND2 INDEPENDENT <i> of <S> declared starts (ghidra <g> pointer <p> none <z>)`. rc 1 also when over> 0, as for phantoms/truncations
      (1.6 T1.c2); multi-return merges do not affect rc.

Merge: inventory F=[v,e) holding a B2 start s, v < s < e. g = s, or for a post-ret s the word after the preceding
jr ra's delay slot. multi-return iff a crossing: a branch/j with site and target in F on opposite sides of g (site =
first such); else fallthrough (word at g-8 not jr/j/b) -> `fall:<s-4>`; else a jtbl row of F whose entries straddle g,
or all lie >= g with F's last jr <reg!=ra> before them < g -> `jtbl:<lo>`. No crossing -> over-merge.
Independence: config/symbols.<p>.txt `type:func` starts; basis ghidra (Ghidra func addr) > pointer (value stored as
an aligned word in the program's own image) > none.

B2 inputs (never asm/, config/*.yaml, splat output or corpus spans): retail bytes (boundaries.programs(): exe image
and rock/NN.bin, sha1-checked), text range = build/corpus/denominators.jsonl [text_lo, text_hi), config/ghidra/<p>.jsonl,
config/boundaries.txt `jtbl` rows (numeric hi only exclude post-ret starts).
Starts (basis precedence ghidra > jal > head > post-ret): (a) Ghidra `func` addrs in text; (b) post-ret: after each
`jr $ra` (0x03E00008) at a, the first non-zero word at/after a+8 unless inside a jtbl span; (b') head (overlays only):
f = first jr $ra at/after text_lo, scan back from f-4 while plausible() (stop at text_lo), skip zero words forward;
plausible(w) = w == 0 or a valid R3000 word that is not a load/store with base $zero, a non-jr/jalr/syscall/break/
mfhi/lo/mthi/lo/mult/div SPECIAL with rd $zero, or an I-type ALU with rt $zero; (c) jal targets of jal words inside
the trimmed bodies of (a)u(b)u(b'), target in the program's text or (overlay only) the exe's text.
Extent (C0021): start s, next start n (or text_hi): end = last jr $ra in [s, n) + 8; none -> unended (start kept, no
bytes). Inventory = build/corpus/functions.jsonl. phantom: an inventory vram that is not a B2 start. truncation: a
B2 function [s, end) with a word covered by != 1 inventory function, or the inventory function at s ends before end.
Classes (first match): jtbl-label (key word or problem run in/adjacent to a jtbl span; an unknown-hi row is its lo
word), carve (rock_17/43/45), q1-text-end (touches exe [0x8006D5D0, 0x8006D5D4]), data-tail (truncation whose
uncovered words all lie in corpus data|pad spans), ghidra-missed-start (phantom), unclassified.
Ledger config/boundary_exceptions.txt (optional): `<prog> <vram> <phantom|truncation> <class> <evidence...>`, `#`
comments; a matching disagreement counts as ledgered (listed under `## ledgered`); a row matching nothing is stale.
Firewall G12: addresses, names and counts only; no words or bytes are printed or written.
"""
import argparse
import bisect
import json
import struct
import sys
from collections import Counter
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import boundaries  # noqa: E402

REPO = boundaries.REPO
CORPUS = REPO / "build/corpus"
OUT = REPO / "build/bound2"
BOUNDS = REPO / "config/boundaries.txt"
LEDGER = REPO / "config/boundary_exceptions.txt"
PROBES = REPO / "config/probes.txt"
EXE = "SLUS_013.95"
JR_RA = 0x03E00008
CARVE = {"rock_17", "rock_43", "rock_45"}
Q1 = (0x8006D5D0, 0x8006D5D8)  # words 0x8006D5D0..0x8006D5D4 inclusive
CLASSES = ["jtbl-label", "carve", "q1-text-end", "data-tail", "ghidra-missed-start", "unclassified"]
BASIS_RANK = {"ghidra": 0, "jal": 1, "head": 2, "post-ret": 3}
CONTROL_FUNC = 0x80055A04
# T1's retail-derived "first code word after header" starts; must carry basis head
HEAD_CONTROL = [("rock_17", 0x800E986C), ("rock_43", 0x800FA054), ("rock_45", 0x800FA028), ("rock_46", 0x800FA004)]
OPS_OK = set(range(2, 16)) | {16, 18, 32, 33, 34, 35, 36, 37, 38, 40, 41, 42, 43, 46, 50, 58}
OPS_MEM = {32, 33, 34, 35, 36, 37, 38, 40, 41, 42, 43, 46, 50, 58}
SPECIAL_OK = {0, 2, 3, 4, 6, 7, 8, 9, 12, 13, 16, 17, 18, 19, 24, 25, 26, 27} | set(range(32, 40)) | {42, 43}
SPECIAL_RD0 = {8, 9, 12, 13, 16, 17, 18, 19, 24, 25, 26, 27}  # functs that may have rd = $zero
REGIMM_OK = {0, 1, 16, 17}


def h(a):
    return f"0x{a:08x}"


def bad(msg):
    print(f"bound2: {msg}", file=sys.stderr)
    sys.exit(2)


def plausible(w):
    """w is zero or a valid R3000 word that real code would plausibly contain."""
    if w == 0:
        return True
    op, rs, rt, rd = w >> 26, (w >> 21) & 31, (w >> 16) & 31, (w >> 11) & 31
    if op == 0:
        f = w & 63
        return f in SPECIAL_OK and (rd != 0 or f in SPECIAL_RD0)
    if op == 1:
        return rt in REGIMM_OK
    if op not in OPS_OK:
        return False
    if op in OPS_MEM:
        return rs != 0
    if 8 <= op <= 15:
        return rt != 0
    return True


def jsonl(path):
    if not path.is_file():
        bad(f"missing {path}")
    return [json.loads(x) for x in path.read_text().splitlines() if x.strip()]


# ---- inputs ----
def load_inputs():
    dens = {d["prog"]: (int(d["text_lo"], 16), int(d["text_hi"], 16)) for d in jsonl(CORPUS / "denominators.jsonl")}
    inv = {}
    for f in jsonl(CORPUS / "functions.jsonl"):
        inv.setdefault(f["prog"], []).append((int(f["vram"], 16), int(f["end"], 16), f.get("name", "")))
    spans = {}
    for s in jsonl(CORPUS / "spans.jsonl"):
        if s["kind"] in ("data", "pad"):
            spans.setdefault(s["prog"], []).append((int(s["lo"], 16), int(s["hi"], 16)))
    progs = {p.name: p for p in boundaries.programs()}
    for name in dens:
        if name not in progs:
            bad(f"corpus program {name} has no retail image")
    for name in inv:
        if name not in dens:
            bad(f"corpus functions of {name} have no denominator")
    return dens, inv, spans, progs


def load_jtbl():
    """{prog: [(lo, hi|None)]} from config/boundaries.txt `jtbl` rows under `# program <p>` headers."""
    out, cur = {}, None
    for line in BOUNDS.read_text().splitlines():
        f = line.split()
        if line.startswith("# program "):
            cur = f[2]
        elif f and f[0] == "jtbl":
            if cur is None:
                bad("jtbl row before any `# program` header in config/boundaries.txt")
            hi = None if f[2] == "unknown" else int(f[2], 16)
            out.setdefault(cur, []).append((int(f[1], 16), hi))
    return out


def load_ghidra_funcs(name, lo, hi):
    return {int(r["addr"], 16) for r in boundaries.load_ghidra(name)
            if r.get("k") == "func" and "addr" in r and lo <= int(r["addr"], 16) < hi}


# ---- B2 ----
class Text:
    def __init__(self, p, lo, hi, jt):
        if not p.inimg(lo, hi - lo):
            bad(f"{p.name} text {h(lo)}..{h(hi)} outside its image")
        self.p, self.lo, self.hi = p, lo, hi
        self.jt = sorted((a, b) for a, b in jt if b is not None)
        self.jrs = [a for a in range(lo, hi, 4) if p.word(a) == JR_RA]

    def in_jtbl(self, a):
        return any(x <= a < y for x, y in self.jt)

    def word(self, a):
        return self.p.word(a)

    def end_of(self, s, n):
        """last jr $ra in [s, n) + 8, else None."""
        i = bisect.bisect_left(self.jrs, n) - 1
        return self.jrs[i] + 8 if i >= 0 and self.jrs[i] >= s else None

    def post_ret(self):
        out = set()
        for a in self.jrs:
            b = a + 8
            while b < self.hi and self.word(b) == 0:
                b += 4
            if b < self.hi and not self.in_jtbl(b):
                out.add(b)
        return out

    def head(self):
        """overlay head start: back from the first jr $ra over plausible words, then past zero words; else None."""
        if not self.jrs:
            return None
        s = self.jrs[0]
        while s - 4 >= self.lo and plausible(self.word(s - 4)):
            s -= 4
        while s < self.hi and self.word(s) == 0:
            s += 4
        return s if s < self.hi else None


def extents(t, starts):
    ss = sorted(starts)
    return {s: t.end_of(s, ss[i + 1] if i + 1 < len(ss) else t.hi) for i, s in enumerate(ss)}


def build_b2(texts, ghidra):
    """-> {prog: {start: (end|None, basis)}}"""
    basis = {}
    for name, t in texts.items():
        b = {a: "post-ret" for a in t.post_ret()}
        hd = t.head() if name != EXE else None
        if hd is not None:
            b[hd] = "head"
        b.update({a: "ghidra" for a in ghidra[name]})
        basis[name] = b
    jal = {name: set() for name in texts}
    ex = texts.get(EXE)
    for name, t in texts.items():
        for s, e in extents(t, basis[name]).items():
            if e is None:
                continue
            for a in range(s, min(e, t.hi), 4):
                w = t.word(a)
                if w >> 26 != 3:
                    continue
                tg = (a & 0xF0000000) | ((w & 0x3FFFFFF) << 2)
                if t.lo <= tg < t.hi:
                    jal[name].add(tg)
                elif name != EXE and ex is not None and ex.lo <= tg < ex.hi:
                    jal[EXE].add(tg)
    out = {}
    for name, t in texts.items():
        b = basis[name]
        for a in jal[name]:
            if a not in b or BASIS_RANK["jal"] < BASIS_RANK[b[a]]:
                b[a] = "jal"
        out[name] = {s: (e, b[s]) for s, e in extents(t, b).items()}
    return out


# ---- disagreements ----
def runs(words):
    out = []
    for a in sorted(words):
        if out and out[-1][1] == a:
            out[-1][1] = a + 4
        else:
            out.append([a, a + 4])
    return [tuple(r) for r in out]


def disagree(prog, b2, inv):
    """-> [(kind, addr, detail, problem runs, uncovered words)] for one program, sorted by (addr, kind)."""
    cov = Counter()
    at = {}
    for v, e, _ in inv:
        at[v] = e
        for a in range(v, e, 4):
            cov[a] += 1
    starts = sorted(b2)
    out = []
    for v, e, name in inv:
        if v not in b2:
            i = bisect.bisect_right(starts, v) - 1
            enc = h(starts[i]) if i >= 0 else "-"
            out.append(("phantom", v, f"inv_end={h(e)} b2_prev={enc} name={name}", [(v, v + 4)], []))
    for s in starts:
        e = b2[s][0]
        if e is None:
            continue
        badw = [a for a in range(s, e, 4) if cov[a] != 1]
        short = s in at and at[s] < e
        if not badw and not short:
            continue
        rs = runs(badw)
        if short:
            rs = sorted(set(rs) | {(at[s], e)})
        inv_e = h(at[s]) if s in at else "-"
        det = f"b2_end={h(e)} inv_end={inv_e} runs=" + ",".join(f"{h(x)}..{h(y)}" for x, y in rs[:4])
        if len(rs) > 4:
            det += f",+{len(rs) - 4}"
        out.append(("truncation", s, det, rs, [a for a in badw if cov[a] == 0]))
    out.sort(key=lambda d: (d[1], d[0]))
    return out


def touch(x, y, lo, hi):
    """[x, y) intersects or abuts [lo, hi)."""
    return x <= hi and lo <= y


def classify(prog, d, jt, dp):
    kind, a, _, rs, unc = d
    spans = [(lo, hi if hi is not None else lo + 4) for lo, hi in jt]
    if any(touch(x, y, lo, hi) for x, y in rs for lo, hi in spans):
        return "jtbl-label"
    if prog in CARVE:
        return "carve"
    if prog == EXE and any(x < Q1[1] and Q1[0] < y for x, y in rs):
        return "q1-text-end"
    if kind == "truncation" and unc and all(any(lo <= w < hi for lo, hi in dp) for w in unc):
        return "data-tail"
    if kind == "phantom":
        return "ghidra-missed-start"
    return "unclassified"


# ---- merges (1.6 T1) ----
def f_jtbl(word, v, e, rows):
    """F=[v,e)'s jtbl rows -> [(table_lo, [targets in F])]; numeric hi: words in [lo, hi); unknown hi: read while in F."""
    out = []
    for lo, hi in rows:
        ts, a = [], lo
        while hi is None or a < hi:
            w = word(a)
            if w is None or (hi is None and not v <= w < e):
                break
            if v <= w < e:
                ts.append(w)
            a += 4
        if ts:
            out.append((lo, ts))
    return out


def inner_class(word, v, e, s, jrows):
    """pure: inner start s of F=[v,e) -> (multi-return|over-merge, site|-, branch|fall|jtbl|None).
    word(a) -> int|None; jrows = f_jtbl(...) rows of F."""
    g, b = s, s
    while True:  # post-ret start: g = word after the preceding jr ra's delay slot (zero gap counts as >= g)
        if b - 8 >= v and word(b - 8) == JR_RA:
            g = b
            break
        if b - 4 >= v and word(b - 4) == 0:
            b -= 4
            continue
        break
    for u in range(v, e, 4):
        w = word(u)
        if w is None:
            continue
        op = w >> 26
        if op == 1 and ((w >> 16) & 31) in REGIMM_OK or op in (4, 5, 6, 7, 20, 21, 22, 23):
            imm = w & 0xFFFF
            t = u + 4 + ((imm - 0x10000 if imm & 0x8000 else imm) << 2)
        elif op == 2:
            t = ((u + 4) & 0xF0000000) | ((w & 0x3FFFFFF) << 2)
        else:
            continue
        if v <= t < e and (u < g) != (t < g):
            return "multi-return", h(u), "branch"
    w = word(g - 8) if g - 8 >= v else None
    stop = w is not None and (w >> 26 == 0 and w & 63 == 8 or w >> 26 == 2 or w >> 16 == 0x1000
                              or w >> 16 == 0x0401)  # jr / j / beq $0,$0 / bgez $0 (b)
    if not stop:
        return "multi-return", f"fall:{h(s - 4)}", "fall"
    for lo, ts in jrows:
        if min(ts) < g <= max(ts):
            return "multi-return", f"jtbl:{h(lo)}", "jtbl"
        if min(ts) >= g:
            jr = [u for u in range(v, min(ts), 4) if (word(u) or 0) & 0xFC1FFFFF == 8 and word(u) != JR_RA]
            if jr and jr[-1] < g:
                return "multi-return", f"jtbl:{h(lo)}", "jtbl"
    return "over-merge", "-", None


def merges(word, rows, starts, jt):
    """inventory rows [(v, e, name)] x B2 starts -> [(v, s, class, site, how)] for every s with v < s < e."""
    ss = sorted(starts)
    out = []
    for v, e, _ in rows:
        i = bisect.bisect_right(ss, v)
        inner = []
        while i < len(ss) and ss[i] < e:
            inner.append(ss[i])
            i += 1
        if not inner:
            continue
        jrows = f_jtbl(word, v, e, jt)
        for s in inner:
            out.append((v, s) + inner_class(word, v, e, s, jrows))
    return out


def accessor(p):
    return lambda a: p.word(a) if p.inimg(a) else None


def independence(names, progs):
    """declared type:func starts of config/symbols.<p>.txt -> [(prog, vram, ghidra|pointer|none)]."""
    out = []
    for p in names:
        path = REPO / f"config/symbols.{p}.txt"
        if not path.is_file():
            continue
        starts = []
        for line in path.read_text().splitlines():
            if "type:func" in line and "=" in line and not line.lstrip().startswith("//"):
                starts.append(int(line.split("=", 1)[1].split(";", 1)[0].strip(), 16))
        gh = load_ghidra_funcs(p, 0, 1 << 32)
        img = progs[p].img
        words = {x for (x,) in struct.iter_unpack("<I", img[:len(img) // 4 * 4])}
        for s in sorted(set(starts)):
            out.append((p, s, "ghidra" if s in gh else "pointer" if s in words else "none"))
    return out


def load_ledger():
    rows = {}
    if not LEDGER.is_file():
        return rows
    for n, line in enumerate(LEDGER.read_text().splitlines(), 1):
        f = line.split("#", 1)[0].split()
        if not f:
            continue
        if len(f) < 4 or f[2] not in ("phantom", "truncation") or f[3] not in CLASSES[:-1]:
            bad(f"{LEDGER.name}:{n}: bad row (want <prog> <vram> <phantom|truncation> <class> <evidence...>)")
        try:
            key = (f[0], int(f[1], 16), f[2])
        except ValueError:
            bad(f"{LEDGER.name}:{n}: bad vram {f[1]}")
        rows[key] = (f[3], line.strip())
    return rows


# ---- driver ----
def compute():
    dens, inv, spans, progs = load_inputs()
    jt = load_jtbl()
    texts = {n: Text(progs[n], lo, hi, jt.get(n, [])) for n, (lo, hi) in dens.items()}
    ghidra = {n: load_ghidra_funcs(n, t.lo, t.hi) for n, t in texts.items()}
    b2 = build_b2(texts, ghidra)
    return dens, inv, spans, jt, b2, texts


def account(names, inv, spans, jt, b2, ledger):
    """ledger accounting, no I/O -> dict groups, cls_n, ph, tr, led, nfun, stale, rc."""
    groups = {c: [] for c in CLASSES + ["ledgered"]}
    cls_n = Counter()
    used, ph, tr, led, nfun = set(), 0, 0, 0, 0
    for p in names:
        rows = sorted(inv.get(p, []))
        nfun += len(rows)
        for d in disagree(p, b2[p], rows):
            kind, a, det = d[0], d[1], d[2]
            line = f"{kind} {p} {h(a)} {det}"
            key = (p, a, kind)
            if key in ledger:
                used.add(key)
                led += 1
                groups["ledgered"].append(f"{line} class={ledger[key][0]}")
                continue
            c = classify(p, d, jt.get(p, []), spans.get(p, []))
            cls_n[c] += 1
            groups[c].append(line)
            if kind == "phantom":
                ph += 1
            else:
                tr += 1
    stale = sorted(k for k in ledger if k not in used and k[0] in names)
    return {"groups": groups, "cls_n": cls_n, "ph": ph, "tr": tr, "led": led, "nfun": nfun, "stale": stale,
            "rc": 0 if ph == tr == 0 and not stale else 1}


def run(sel):
    dens, inv, spans, jt, b2, texts = compute()
    names = sorted(dens) if sel is None else [sel]
    if sel is not None and sel not in dens:
        bad(f"unknown program {sel}")
    ledger = load_ledger()
    OUT.mkdir(parents=True, exist_ok=True)
    unended = 0
    for p in names:
        with open(OUT / f"{p}.jsonl", "w") as fh:
            for s, (e, bs) in sorted(b2[p].items()):
                fh.write(json.dumps({"prog": p, "vram": h(s), "end": h(e) if e is not None else None,
                                     "basis": bs}) + "\n")
                unended += e is None
    r = account(names, inv, spans, jt, b2, ledger)
    with open(OUT / "disagreements.txt", "w") as fh:
        fh.write("# generated by tools/mmx6/bound2.py; do not edit\n")
        for c in CLASSES + ["ledgered"]:
            fh.write(f"## {c}\n")
            for line in r["groups"][c]:
                fh.write(line + "\n")
    for k in r["stale"]:
        print(f"BOUND2 STALE {ledger[k][1]}")
    mg = []
    for p in names:
        mg += [(p,) + m for m in merges(accessor(texts[p].p), sorted(inv.get(p, [])), b2[p], jt.get(p, []))]
    mg.sort(key=lambda m: (m[0], m[2]))
    with open(OUT / "merges.txt", "w") as fh:
        for p, v, s, c, site, _ in mg:
            fh.write(f"{p} {h(v)} {h(s)} {c} {site}\n")
    ind = independence(names, {p: texts[p].p for p in names})
    with open(OUT / "independence.jsonl", "w") as fh:
        for p, s, bs in ind:
            fh.write(json.dumps({"prog": p, "vram": h(s), "basis": bs}) + "\n")
    per = Counter(m[0] for m in mg)
    cls = Counter(m[3] for m in mg)
    bn = Counter(x[2] for x in ind)
    print(f"BOUND2 UNENDED {unended}")
    print("BOUND2 CLASSES " + " ".join(f"{c}={r['cls_n'][c]}" for c in CLASSES))
    print(f"BOUND2 INNER {len(mg)} (" + " ".join(f"{p} {n}" for p, n in
                                              sorted(per.items(), key=lambda x: (-x[1], x[0]))[:5]) + ")")
    print(f"BOUND2 merges={cls['over-merge']} multi-return={cls['multi-return']} of {r['nfun']} functions")
    print(f"BOUND2 INDEPENDENT {bn['ghidra'] + bn['pointer']} of {len(ind)} declared starts (ghidra {bn['ghidra']} "
          f"pointer {bn['pointer']} none {bn['none']})")
    print(f"BOUND2 phantoms={r['ph']} truncations={r['tr']} ledgered={r['led']} of {r['nfun']} functions in "
          f"{len(names)} programs")
    return 1 if cls["over-merge"] else r["rc"]


def self_test():
    dens, inv, spans, jt, b2, texts = compute()
    fails = []
    ex = sorted(inv.get(EXE, []))
    byv = {v: (v, e, n) for v, e, n in ex}

    def keys(rows):
        return {(k, a) for k, a, *_ in disagree(EXE, b2[EXE], rows)}

    base = keys(ex)
    want = []
    for line in PROBES.read_text().splitlines():
        f = line.split()
        if len(f) >= 5 and not f[0].startswith("#") and f[1] == EXE and f[-1] == "banked":
            want.append(int(f[0].split("_")[-1], 16))
    if len(want) != 3:
        fails.append(f"probes.txt banked rows = {len(want)}, want 3")
    want.append(CONTROL_FUNC)
    agree = []
    for v in want:
        if v not in byv:
            fails.append(f"{h(v)} not in the inventory")
        elif ("phantom", v) in base or ("truncation", v) in base:
            fails.append(f"{h(v)} disagrees with B2")
        else:
            agree.append(v)
    bad_starts = {a for _, a in base}
    pool = [v for v in [CONTROL_FUNC] + want + sorted(byv) if v in byv and v not in bad_starts
            and b2[EXE][v][0] == byv[v][1] and byv[v][1] - v >= 12]
    pool = list(dict.fromkeys(pool))
    split = next((v for v in pool if any(m not in b2[EXE] for m in range(v + 4, byv[v][1], 4))), None)
    if split is None:
        fails.append("no agreeing function to split")
    else:
        v, e, n = byv[split]
        m = next(m for m in range(v + 4, e, 4) if m not in b2[EXE])
        rows = [r for r in ex if r[0] != v] + [(v, m, n), (m, e, n + "_split")]
        if ("phantom", m) not in keys(sorted(rows)):
            fails.append(f"split control missed: no phantom at {h(m)}")
    cut = next((v for v in pool if v != split), None)
    if cut is None:
        fails.append("no second agreeing function to cut")
    else:
        v, e, n = byv[cut]
        rows = [r for r in ex if r[0] != v] + [(v, e - 8, n)]
        if ("truncation", v) not in keys(sorted(rows)):
            fails.append(f"cut control missed: no truncation at {h(v)}")
    for p, a in HEAD_CONTROL:
        bs = b2.get(p, {}).get(a, (None, None))[1]
        if bs != "head":
            fails.append(f"head control: {p} {h(a)} basis {bs}, want head")
    names = sorted(dens)
    # ledger control on an injected disagreement (the cut above), so it holds when the real run is 0/0 (T5)
    known, inv2 = None, dict(inv)
    if cut is not None:
        v, e, n = byv[cut]
        inv2[EXE] = sorted([r for r in ex if r[0] != v] + [(v, e - 8, n)])
        known = (EXE, v, "truncation")
    r0 = account(names, inv2, spans, jt, b2, {})
    if known is None:
        fails.append("ledger control: no injected disagreement to ledger")
    else:
        r1 = account(names, inv2, spans, jt, b2, {known: ("carve", "control row")})
        if r1["led"] != 1 or r1["ph"] + r1["tr"] != r0["ph"] + r0["tr"] - 1 or r1["stale"]:
            fails.append(f"ledger control: row on {known[0]} {h(known[1])} {known[2]} not counted ledgered")
        ghost = (names[0], 0, "phantom")
        r2 = account(names, inv2, spans, jt, b2, {ghost: ("carve", "ghost row")})
        if r2["stale"] != [ghost] or r2["rc"] != 1:
            fails.append("ledger control: row matching nothing not reported stale with rc 1")
    # merge controls (1.6 T1, injected, C0054): synthetic words, then two agreeing exe functions fused in memory
    nop, li, beq = 0, 0x24020001, 0x10800003  # li v0,1; beq a0,$0,+3
    syn = {"multi-return": [beq, nop, JR_RA, nop, li, JR_RA, nop], "over-merge": [li, JR_RA, nop, li, JR_RA, nop]}
    want_m = {"multi-return": (0x1010, "multi-return", h(0x1000)), "over-merge": (0x100C, "over-merge", "-")}
    for k, ws in syn.items():
        s, c, site = want_m[k]
        got = inner_class(lambda a, ws=ws: ws[(a - 0x1000) // 4] if 0x1000 <= a < 0x1000 + 4 * len(ws) else None,
                          0x1000, 0x1000 + 4 * len(ws), s, [])[:2]
        if got != (c, site):
            fails.append(f"merge control {k}: got {got}, want {(c, site)}")
    fz = next(((a, b) for a, b in zip(sorted(byv), sorted(byv)[1:]) if a in pool and b in pool
               and byv[a][1] == b), None)
    if fz is None:
        fails.append("merge control: no adjacent agreeing exe pair to fuse")
    else:
        a, b = fz
        rows = sorted([r for r in ex if r[0] not in fz] + [(a, byv[b][1], byv[a][2])])
        got = [m for m in merges(accessor(texts[EXE].p), rows, b2[EXE], jt.get(EXE, [])) if m[0] == a]
        if [(m[1], m[2]) for m in got] != [(b, "over-merge")]:
            fails.append(f"merge control fused {h(a)}+{h(b)}: got {[(h(m[1]), m[2], m[3]) for m in got]}")
    for f in fails:
        print(f"BOUND2 FAIL {f}")
    if fails:
        return 1
    print(f"BOUND2 agree {' '.join(h(v) for v in agree)}; split {h(split)}, cut {h(cut)}; "
          f"head {len(HEAD_CONTROL)}; ledger {known[0]} {h(known[1])} {known[2]}; merge synth 2, fused {h(fz[1])}")
    print("BOUND2 CONTROL OK")
    return 0


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    g = ap.add_mutually_exclusive_group(required=True)
    g.add_argument("--all", action="store_true")
    g.add_argument("--prog")
    g.add_argument("--self-test", action="store_true")
    a = ap.parse_args()
    if a.self_test:
        sys.exit(self_test())
    sys.exit(run(None if a.all else a.prog))


if __name__ == "__main__":
    main()
