#!/usr/bin/env python3
"""plateau.py -- classify a draft's residual against retail into one plateau label and its triage rows (container).

  plateau.py --draft drafts/<prog>/<func>.c [--permuted <best.c>]
      -> per input `PLATEAU <func> <label> residual <m>/<n> rows <ids> src <draft|permuted>`; rc 0
  plateau.py --self-test
      -> own C pairs planted in .run/plateau-selftest/ (regalloc, sched, branch polarity, identical), each plant's
         precondition asserted; expects regalloc, sched, branch, none; last line `PLATEAU CONTROL OK` (rc 0), else rc 1

Compile: the draft through the product C rule (probe.compile_obj under the Makefile's pinned TRIPLE; a drafts/ path
carries its TU's cc1 flags, probe.draft_cflags). The permuted file is copied to .run/plateau/<func>/drafts/<prog>/
<func>.c so the same draft_cflags lookup applies (draft's TU flags). `make extract` runs first when
extracted/retail/iso/<prog> is missing (as permute.py). Compare: permuter/masked_scorer.masked masking (probe.MASKS +
PC16 low 16; an R_MIPS_26 into the function's own section compares opcode + target relative to function start)
against probe.retail_words; m = masked mismatched words + |length diff| (= masked_scorer.score_words, asserted),
n = retail word count. Self-test pairs: "retail" = b.o's words, masks = the union of a's and b's.

Classification (our convention: the Rationale's order with branch polarity folded out of isel/sched), first that holds:
  opk(w): op 0 -> (0, funct); op 1 (REGIMM) -> (1, rt); op 16-19 -> (op, rs[, rt&1 if rs == 8]); else (op,).
  fold(k): conditional-branch polarity pairs collapsed (beq/bne, blez/bgtz, bltz/bgez, bltzal/bgezal, beql/bnel,
  blezl/bgtzl, bc*t/bc*f). A flip = two conditional branches aligned in order (k-th of each side) with equal fold and
  different opk.
  none      m == 0
  length    word counts differ
  isel      multiset of fold(opk) differs
  sched     fold sequence differs, no flip
  regalloc  fold sequence equal, no flip, every residual word differs only in register fields (op 0: bits 11-25;
            other I-type: bits 16-25; a $sp-based load/store whose other difference is its offset = spill slot)
  branch    a flip, or every residual word is a conditional branch or an internal j
  isel      otherwise (operands, constants)
Rows: the lever cells of docs/codegen-map/README.md `## Triage` whose group is in the label's groups (table order,
comma-joined, `-> permuter` printed `permuter`; none -> `-`). G12: prints counts and labels only, never words.
"""
import argparse
import os
import re
import shutil
import subprocess
import sys
from collections import Counter

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
sys.path.insert(0, os.path.join(ROOT, "tools", "mmx6"))
sys.path.insert(0, os.path.join(ROOT, "tools", "mmx6", "permuter"))
import probe  # noqa: E402
import masked_scorer  # noqa: E402

RUN = ".run/plateau"
SELFTEST = ".run/plateau-selftest"
TRIAGE = "docs/codegen-map/README.md"
DRAFT_RE = re.compile(r"(?:^|/)drafts/([^/]+)/([A-Za-z_]\w*)\.c$")
GROUPS = {"length": ("G-expr", "G-combine", "G-loop", "G-jump"), "isel": ("G-expr", "G-combine"),
          "sched": ("G-sched",), "regalloc": ("G-alloc",), "branch": ("G-jump",), "none": ()}
# Polarity pairs: (op,) for beq/bne 4/5, blez/bgtz 6/7, beql/bnel 20/21, blezl/bgtzl 22/23; REGIMM rt 0/1, 16/17.
FOLD_OP = {5: 4, 7: 6, 21: 20, 23: 22}
FOLD_RT = {1: 0, 17: 16}
REGIMM_BR = {0, 1, 2, 3, 16, 17, 18, 19}
# Self-test plants: our own C, compiled under the pin; nothing game-derived (C0054: no repro/ file borrowed).
PLANTS = (
    ("regalloc", "extern int pk(int);\nextern int pm(int, int, int);\nint pa(int u, int v)\n{\n    int s, t;\n"
     "    s = u * 9;\n    t = v * 17;\n    if (pk(u)) { s -= 1; t -= 1; }\n    return pm(s, 2, t);\n}\n",
     "extern int pk(int);\nextern int pm(int, int, int);\nint pa(int u, int v)\n{\n    int t, s;\n"
     "    s = u * 9;\n    t = v * 17;\n    if (pk(u)) { s -= 1; t -= 1; }\n    return pm(s, 2, t);\n}\n"),
    ("sched", "struct Q { int m; };\nextern int K;\nint pa(int *q, int w)\n{\n    *q = w;\n    return K - 2;\n}\n",
     "struct Q { int m; };\nextern int K;\nint pa(struct Q *q, int w)\n{\n    q->m = w;\n    return K - 2;\n}\n"),
    ("branch", "extern void pm(int);\nextern void pn(int);\nvoid pa(int c)\n{\n    if (c < 0) pm(3); else pn(4);\n}\n",
     "extern void pm(int);\nextern void pn(int);\nvoid pa(int c)\n{\n    if (c >= 0) pn(4); else pm(3);\n}\n"),
    ("none", "extern int K;\nint pa(int w)\n{\n    return (K ^ w) + 6;\n}\n",
     "extern int K;\nint pa(int w)\n{\n    return (K ^ w) + 6;\n}\n"),
)


def pin_triple():
    with open("Makefile") as f:
        m = re.search(r"^TRIPLE \?= (\S+)", f.read(), re.M)
    return m.group(1)


def compile_o(src):
    o = probe.compile_obj(src, pin_triple())
    if not o:
        sys.exit(f"plateau: {src} does not compile")
    return o


def opk(w):
    op = w >> 26
    if op == 0:
        return (0, w & 0x3F)
    if op == 1:
        return (1, (w >> 16) & 0x1F)
    if 16 <= op <= 19:
        rs = (w >> 21) & 0x1F
        return (op, rs, (w >> 16) & 1) if rs == 8 else (op, rs)
    return (op,)


def fold(k):
    if k[0] == 1:
        return (1, FOLD_RT.get(k[1], k[1]))
    if len(k) == 3:  # bc*t / bc*f
        return (k[0], 8, 0)
    if len(k) == 1:
        return (FOLD_OP.get(k[0], k[0]),)
    return k


def is_cbranch(k):
    return (k[0] in (4, 5, 6, 7, 20, 21, 22, 23) or (k[0] == 1 and k[1] in REGIMM_BR) or len(k) == 3)


def reg_only(a, b, d):
    """d = masked difference of words a, b (same opk): register fields only, or a $sp load/store's offset too."""
    op = a >> 26
    if op == 0:
        return d & ~0x03FFF800 == 0
    if op in (2, 3):
        return False
    if d & ~0x03FF0000 == 0:
        return True
    return op >= 32 and (a >> 21) & 0x1F == 29 and (b >> 21) & 0x1F == 29 and d & ~0x03FFFFFF == 0


def classify(a, b, diffs, internal, m):
    """a = our words, b = target words, diffs = {residual index: masked xor}, internal = our internal-j indices."""
    if m == 0:
        return "none"
    if len(a) != len(b):
        return "length"
    ka, kb = [opk(w) for w in a], [opk(w) for w in b]
    fa, fb = [fold(k) for k in ka], [fold(k) for k in kb]
    if Counter(fa) != Counter(fb):
        return "isel"
    ba, bb = [k for k in ka if is_cbranch(k)], [k for k in kb if is_cbranch(k)]
    flip = any(x != y and fold(x) == fold(y) for x, y in zip(ba, bb))
    if fa != fb and not flip:
        return "sched"
    if fa == fb and not flip and all(reg_only(a[i], b[i], d) for i, d in diffs.items()):
        return "regalloc"
    if flip or all(is_cbranch(ka[i]) or i in internal for i in diffs):
        return "branch"
    return "isel"


def residual_retail(o, func, target, vram):
    """(our words, {residual index: masked xor}, internal set, m) against retail words, masked_scorer's masking."""
    words, keys, masks, internal = masked_scorer.masked(o, func)
    diffs = {}
    for i in range(min(len(words), len(target))):
        r = target[i]
        if i in internal:
            rel = (((vram + 4 * i + 4) & 0xF0000000) | ((r & 0x03FFFFFF) << 2)) - vram
            if keys[i] != (r >> 26, rel):
                diffs[i] = words[i] ^ r
        else:
            keep = ~masks.get(i, 0) & 0xFFFFFFFF
            if (r & keep) != keys[i][0]:
                diffs[i] = (words[i] ^ r) & keep
    m = len(diffs) + abs(len(words) - len(target))
    assert m == masked_scorer.score_words(o, func, target, vram)[0], "residual disagrees with score_words"
    return words, diffs, set(internal), m


def residual_pair(a_o, b_o, func):
    """Self-test: (a words, b words, diffs, internal, m) with masks = union of a's and b's."""
    aw, _, am, ai = masked_scorer.masked(a_o, func)
    bw, _, bm, _ = masked_scorer.masked(b_o, func)
    diffs = {}
    for i in range(min(len(aw), len(bw))):
        keep = ~(am.get(i, 0) | bm.get(i, 0)) & 0xFFFFFFFF
        if (aw[i] ^ bw[i]) & keep:
            diffs[i] = (aw[i] ^ bw[i]) & keep
    return aw, bw, diffs, set(ai), len(diffs) + abs(len(aw) - len(bw))


def rows(label):
    with open(TRIAGE) as f:
        text = f.read().split("## Triage", 1)[1]
    out = []
    for line in text.splitlines():
        cells = [c.strip() for c in line.split(" | ")]
        if len(cells) == 4 and cells[1] in GROUPS[label]:
            out.append("permuter" if cells[2] == "→ permuter" else cells[2])
    return ",".join(out) or "-"


def line(func, label, m, n, src):
    s = f"PLATEAU {func} {label} residual {m}/{n} rows {rows(label)} src {src}"
    print(s, flush=True)
    return s


def self_test():
    ok = True
    shutil.rmtree(SELFTEST, ignore_errors=True)
    os.makedirs(SELFTEST)
    for want, a_src, b_src in PLANTS:
        objs = []
        for side, text in (("a", a_src), ("b", b_src)):
            c = os.path.join(SELFTEST, f"{want}_{side}.c")
            with open(c, "w") as f:
                f.write(text)
            objs.append(compile_o(c))
        aw, bw, diffs, internal, m = residual_pair(objs[0], objs[1], "pa")
        pre = (aw == bw) if want == "none" else (aw != bw)
        if want == "regalloc":
            pre = pre and len(aw) == len(bw) and all(
                opk(aw[i]) == opk(bw[i]) and reg_only(aw[i], bw[i], d) for i, d in diffs.items()) and m > 0
        got = classify(aw, bw, diffs, internal, m)
        line("pa", got, m, len(bw), f"plant-{want}")
        if not pre:
            print(f"PLATEAU SELFTEST FAIL precondition {want}", flush=True)
            ok = False
        if got != want:
            print(f"PLATEAU SELFTEST FAIL {want} classified {got}", flush=True)
            ok = False
    print("PLATEAU CONTROL OK" if ok else "PLATEAU CONTROL FAIL", flush=True)
    return 0 if ok else 1


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n", 1)[0])
    ap.add_argument("--draft")
    ap.add_argument("--permuted")
    ap.add_argument("--self-test", action="store_true")
    a = ap.parse_args()
    os.chdir(ROOT)
    if a.self_test:
        return self_test()
    m = DRAFT_RE.search(a.draft or "")
    if not m:
        ap.error("need --draft drafts/<prog>/<func>.c [--permuted <best.c>], or --self-test")
    prog, func = m.groups()
    if not os.path.isfile(f"extracted/retail/iso/{prog}"):  # a fresh sync wipes extracted/ (as permute.py)
        subprocess.run(["make", "-s", "extract"], check=True, stdout=subprocess.DEVNULL)
    vram = probe.find_extent(prog, func)[0]
    target = probe.retail_words(prog, func)
    srcs = [("draft", a.draft)]
    if a.permuted:
        dst = os.path.join(RUN, func, "drafts", prog, f"{func}.c")  # draft_cflags keys on a drafts/<prog>/<func>.c path
        os.makedirs(os.path.dirname(dst), exist_ok=True)
        shutil.copyfile(a.permuted, dst)
        srcs.append(("permuted", dst))
    for kind, src in srcs:
        words, diffs, internal, mm = residual_retail(compile_o(src), func, target, vram)
        line(func, classify(words, target, diffs, internal, mm), mm, len(target), kind)
    return 0


if __name__ == "__main__":
    sys.exit(main())
