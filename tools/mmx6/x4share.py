#!/usr/bin/env python3
"""x4share.py -- how much of X6 the mmx4 decompilation's own C already covers (container, stdlib).

  x4share.py [--triple <name>]
      -> fetches https://github.com/sozud/mmx4 into .run/mmx4 at the pin of config/refs.toml (`[[ref]] name =
         "mmx4"`; x4core.ensure_clone: the exact commit, shallow; a clone at another commit is refused; commit + date
         in .run/x4share/clone.txt), compiles every US C file of mmx4 (F = src/main/<name>.c of each `c` subsegment of its
         config/SLUS_005.61.splat.yaml, the files its build.py keeps via main.ld) one by one with INCLUDE_ASM /
         INCLUDE_RODATA stubbed to nothing (override common.h in .run/x4share/inc, first on -I: SKIP_ASM, then
         #include_next): host cpp (mmx4 build.py's defines/include dirs) -> cc1 -> maspsx -> mipsel as ->
         .run/x4share/<triple>/obj/<src>.o; a failing file is counted, its stage + stderr tail in
         .run/x4share/<triple>/log/<src>.log. Every STT_FUNC of every object -> words + relocation mask (extent:
         st_size, else symbol order as probe.elf_function, C0047; mask = the object's relocation sections,
         x4core.functions) -> sig.sig_of, matched
         against build/sig/sigs.jsonl. Last two lines:
         `X4SHARE-DETAIL commit <hash> triple <name> exact_ge8w <k> failed <F-f>`
         `X4SHARE exact <a> near <b> of <N> X6 functions; X4 side <x> functions from <f> of <F> C files; lib <l> game <g>`
  x4share.py --triple <name> --partners
      -> the same run, then keeps exact key -> [(mmx4 src, func)] and writes tracked campaign/x4/partners.tsv, one row
         per X6 function with an exact X4 partner, sorted (prog, vram), tab-separated
         `<prog> <0xVRAM> <x6 func> <words> <exact key> <mmx4 src> <mmx4 func> <partners> <state>` (src, func = the
         first partner by (src, func); partners = their count; x6 func, state: corpus row);
         line `X4SHARE partners <rows> rows; x6 <p> functions, open <o>, open keys <k>` (open = state asm|include_asm,
         k = their distinct exact keys). Names, addresses, keys and mmx4 paths only (G12).
  x4share.py --self-test
      -> build/src/SLUS_013.95/120A0.c.o as a fake X4 object through the same object -> sig -> match path: X6
         SLUS_013.95 func_8001E78C must be exact; control: one unmasked bit of its words flipped -> not exact.
         Also: x4core.MASKS equals probe.MASKS, and every function of that object carries the same words and mask
         under x4core.functions as under census (elf_load + elf_masks). Ends `X4SHARE CONTROL OK`, rc 1 on any miss.

The mmx4 recipe, the ELF reader, the key and the table writer live in x4core.py (shared with mmx5, byte-identical);
the triple, the clone directory and the X6 functions come from x4adapter.py. This file keeps the CLI, the near
measure and the names other tools import (CLONE, SCR, CPP, CPP_TAIL, OVERRIDE, functions, load_x6).

Default triple (plan): cc1 /opt/cc/2.6.3-psx/cc1, cflags of config/triples.txt row gcc2.6.3-psx-aspsx2.86, maspsx
--aspsx-version=2.63 --expand-div. --triple takes a config/triples.txt row. Definitions: a = X6 functions with >= 1
exact X4 partner (equal sig exact key); b = X6 functions with a near X4 partner (sig.near, via sig.near_reps' prefix
filter) and no exact one; N = sigs.jsonl rows; x = X4 functions signed; f of F = C files compiled; l/g = a+b split by
build/corpus/functions.jsonl lane; exact_ge8w = a restricted to X6 functions of >= 8 words.
Firewall G12/G102: the clone, objects and signatures stay in .run/ (untracked); stdout prints counts only.
"""
import argparse
import datetime
import json
import os
import struct
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import census  # noqa: E402
import probe  # noqa: E402  (MASKS: the self-test's check of the core's table)
import sig  # noqa: E402
import x4adapter  # noqa: E402  (the triple, the clone directory, the X6 functions)
import x4core  # noqa: E402  (the mmx4 recipe, ELF reader, key, table writer)

REPO = x4core.REPO
CLONE = x4adapter.CLONE
SCR = x4adapter.SCR
TRIPLES = x4adapter.TRIPLES
CORPUS = x4adapter.CORPUS
DEFAULT = x4adapter.DEFAULT
# the mmx4 recipe (x4core): host cpp flags, assembler, the common.h override
CPP = x4core.CPP
CPP_TAIL = x4core.CPP_TAIL
AS = x4core.AS
OVERRIDE = x4core.OVERRIDE
SELF_OBJ = "build/src/SLUS_013.95/120A0.c.o"
SELF_FUNC, SELF_PROG, SELF_VRAM = "func_8001E78C", "SLUS_013.95", "0x8001E78C"
PARTNERS = "campaign/x4/partners.tsv"
OPEN = ("asm", "include_asm")


def die(msg):
    sys.exit(f"x4share: {msg}")


triple = x4adapter.triple


def clone():
    """The clone at the pin of config/refs.toml (x4core.ensure_clone); its short commit."""
    head = x4core.short(x4core.ensure_clone(CLONE, x4core.pin(x4adapter.ROOT)))
    os.makedirs(SCR, exist_ok=True)
    if not os.path.isfile(f"{SCR}/clone.txt"):
        Path(f"{SCR}/clone.txt").write_text(f"{head} {datetime.date.today().isoformat()}\n")
    return head


def sources():
    """F: src/main/<name>.c of each `c` subsegment (unnamed -> hex offset, splat's default name)."""
    return x4core.sources(CLONE)


def compile_one(src, t, inc, objdir, logdir):
    """Object path, or None (stage + stderr tail in the per-file log)."""
    return x4core.compile_one(CLONE, src, x4adapter.tools(t), inc, objdir, logdir)


def functions(obj):
    """[(name, words, mask)] per STT_FUNC defined in obj; extent st_size, else symbol order (probe.elf_function)."""
    return x4core.functions(obj)


def sign(objs):
    return [sig.sig_of("X4", f"{os.path.basename(o)}:{name}", w, m) for o in objs for name, w, m in functions(o)]


def match(x6, x4):
    """(exact X6 indices, near-not-exact X6 indices)."""
    keys = set(s["exact"] for s in x4)
    exact = {i for i, s in enumerate(x6) if s["exact"] in keys}
    groups = {}
    for i, s in enumerate(x6):
        groups.setdefault(s["exact"], [None, [], False])[1].append(i)
        groups[s["exact"]][0] = groups[s["exact"]][0] or s
    for s in x4:
        g = groups.setdefault(s["exact"], [s, [], False])
        g[2] = True
    ks = sorted(groups)
    reps = [groups[k][0] for k in ks]
    near = set()
    for i, j, _ in sig.near_reps(reps):
        gi, gj = groups[ks[i]], groups[ks[j]]
        if gj[2]:
            near.update(gi[1])
        if gi[2]:
            near.update(gj[1])
    return exact, near - exact


def load_x6():
    if not os.path.isfile(sig.SIGS):
        die(f"{sig.SIGS} missing (run corpus.py/census.py/sig.py --all)")
    with open(sig.SIGS) as f:
        return [sig.from_json(json.loads(line)) for line in f]


def self_test():
    x6 = load_x6()
    tgt = next((i for i, s in enumerate(x6) if (s["prog"], s["vram"]) == (SELF_PROG, SELF_VRAM)), None)
    fails = []
    if tgt is None or not os.path.isfile(SELF_OBJ):
        die(f"self-test inputs missing ({SELF_PROG} {SELF_VRAM} in {sig.SIGS}, {SELF_OBJ})")
    fs = {n: (w, m) for n, w, m in functions(SELF_OBJ)}
    x4 = sign([SELF_OBJ])
    ex, _ = match(x6, x4)
    print(f"X4SHARE self positive: {SELF_FUNC} exact {tgt in ex}; {len(x4)} functions signed")
    if tgt not in ex:
        fails.append("positive")
    # the core's mask table and reader against the fleet's own (probe.MASKS; census.elf_load + elf_masks)
    data, syms = census.elf_load(SELF_OBJ)
    masks = census.elf_masks(SELF_OBJ)
    same = x4core.MASKS == probe.MASKS and bool(fs) and all(
        n in syms and w == list(struct.unpack_from(f"<{len(w)}I", data[syms[n][0]], syms[n][1])) and
        m == [masks.get((syms[n][0], syms[n][1] + 4 * i), 0) for i in range(len(w))] and
        x4core.key(w, m) == census.dup_key(w, m) for n, (w, m) in fs.items())
    print(f"X4SHARE self masks: x4core.MASKS == probe.MASKS, {len(fs)} functions words/mask/key as census {same}")
    if not same:
        fails.append("masks")
    if SELF_FUNC not in fs:
        fails.append("no symbol")
    else:
        w, m = fs[SELF_FUNC]
        k = next(i for i, x in enumerate(m) if x == 0)
        w = list(w)
        w[k] ^= 1
        ex, _ = match(x6, [sig.sig_of("X4", "flip", w, m)])
        print(f"X4SHARE self control: word {k} bit 0 flipped -> exact {tgt in ex}")
        if tgt in ex:
            fails.append("control")
    if fails:
        print(f"X4SHARE CONTROL FAIL {' '.join(fails)}")
        return 1
    print("X4SHARE CONTROL OK")
    return 0


def write_partners(x6, objs, objdir, rows):
    """partners.tsv: one row per X6 function with an exact X4 partner (the first by (src, func) + the partner count);
    the X6 side's name and state from the corpus rows (x4core.write_partners over x4adapter.game)."""
    by_key, _ = x4core.partner_map(objdir, objs)
    out = x4core.write_partners(PARTNERS, x4adapter.game(x6, rows), by_key)
    x6f = {(x[0], x[1]) for x in out}
    op = {(x[0], x[1]): x[4] for x in out if x[8] in OPEN}
    print(f"X4SHARE partners {len(out)} rows; x6 {len(x6f)} functions, open {len(op)}, open keys {len(set(op.values()))}")


def run(name, partners=False):
    t = triple(name)
    x6 = load_x6()
    lane, rows = {}, {}
    with open(CORPUS) as f:
        for line in f:
            r = json.loads(line)
            lane[(r["prog"], r["vram"])] = r["lane"]
            rows[(r["prog"], r["vram"])] = r
    head = clone()
    objdir, logdir = f"{SCR}/{t['name']}/obj", f"{SCR}/{t['name']}/log"
    srcs, objs = x4core.compile_all(CLONE, x4adapter.tools(t), f"{SCR}/inc", objdir, logdir)
    x4 = sign(objs)
    exact, near = match(x6, x4)
    both = exact | near
    lib = sum(1 for i in both if lane.get((x6[i]["prog"], x6[i]["vram"])) == "lib")
    ge8 = sum(1 for i in exact if x6[i]["words"] >= 8)
    print(f"X4SHARE-DETAIL commit {head} triple {t['name']} exact_ge8w {ge8} failed {len(srcs) - len(objs)}")
    print(f"X4SHARE exact {len(exact)} near {len(near)} of {len(x6)} X6 functions; X4 side {len(x4)} functions "
          f"from {len(objs)} of {len(srcs)} C files; lib {lib} game {len(both) - lib}")
    if partners:
        write_partners(x6, objs, objdir, rows)
    return 0


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("--triple", help="a config/triples.txt row (default: the plan's gcc2.6.3-psx + aspsx 2.63)")
    ap.add_argument("--partners", action="store_true", help=f"also write {PARTNERS} (exact partners per X6 function)")
    ap.add_argument("--self-test", action="store_true")
    a = ap.parse_args()
    sys.exit(self_test() if a.self_test else run(a.triple, a.partners))


if __name__ == "__main__":
    main()
