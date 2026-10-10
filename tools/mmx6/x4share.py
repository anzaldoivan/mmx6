#!/usr/bin/env python3
"""x4share.py -- how much of X6 the mmx4 decompilation's own C already covers (container, stdlib).

  x4share.py [--triple <name>]
      -> clones https://github.com/sozud/mmx4 into .run/mmx4 when absent (commit + date in .run/x4share/clone.txt),
         compiles every US C file of mmx4 (F = src/main/<name>.c of each `c` subsegment of its
         config/SLUS_005.61.splat.yaml, the files its build.py keeps via main.ld) one by one with INCLUDE_ASM /
         INCLUDE_RODATA stubbed to nothing (override common.h in .run/x4share/inc, first on -I: SKIP_ASM, then
         #include_next): host cpp (mmx4 build.py's defines/include dirs) -> cc1 -> maspsx -> mipsel as ->
         .run/x4share/<triple>/obj/<src>.o; a failing file is counted, its stage + stderr tail in
         .run/x4share/<triple>/log/<src>.log. Every STT_FUNC of every object -> words + relocation mask (extent:
         st_size, else symbol order as probe.elf_function, C0047; mask = census.elf_masks) -> sig.sig_of, matched
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
         Ends `X4SHARE CONTROL OK`, rc 1 on any miss.

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
import re
import struct
import subprocess
import sys
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import census  # noqa: E402
import sig  # noqa: E402

REPO = "https://github.com/sozud/mmx4"
CLONE = ".run/mmx4"
SCR = ".run/x4share"
YAML = "config/SLUS_005.61.splat.yaml"
TRIPLES = "config/triples.txt"
CORPUS = "build/corpus/functions.jsonl"
DEFAULT = dict(name="gcc2.6.3-psx-aspsx2.63", cc1="/opt/cc/2.6.3-psx/cc1", row="gcc2.6.3-psx-aspsx2.86",
               maspsx="--aspsx-version=2.63 --expand-div")
# mmx4 build.py: host `cpp` (its psy-q headers reach the host's <sys/types.h>) with cpp_flags (VERSION=us), minus -v.
CPP = ["cpp", "-undef", "-D__GNUC__=2", "-DVERSION_US=1", "-D__OPTIMIZE__"]
CPP_TAIL = ["-I./src/snd", "-I./include", "-lang-c", "-Dmips", "-D__mips__", "-D__mips", "-Dpsx", "-D__psx__", "-D__psx",
            "-D__EXTENSIONS__", "-D_MIPSEL", "-D__CHAR_UNSIGNED__", "-D_LANGUAGE_C", "-DLANGUAGE_C"]
AS = ["mipsel-linux-gnu-as", "-EL", "-march=r3000", "-mtune=r3000", "-mabi=32", "-no-pad-sections", "-G0",
      "-I./src/main"]
OVERRIDE = '/* x4share: INCLUDE_ASM / INCLUDE_RODATA -> nothing (mmx4 common.h SKIP_ASM branch) */\n' \
           '#define SKIP_ASM 1\n#include_next "common.h"\n'
C_SEG = re.compile(r"^\s*-\s*\[\s*0x([0-9A-Fa-f]+)\s*,\s*c\s*(?:,\s*([^\],]+?))?\s*\]")
SELF_OBJ = "build/src/SLUS_013.95/120A0.c.o"
SELF_FUNC, SELF_PROG, SELF_VRAM = "func_8001E78C", "SLUS_013.95", "0x8001E78C"
PARTNERS = "campaign/x4/partners.tsv"
OPEN = ("asm", "include_asm")


def die(msg):
    sys.exit(f"x4share: {msg}")


def triple(name):
    if name is None:
        cflags = triple(DEFAULT["row"])["cflags"]
        return dict(DEFAULT, cflags=cflags)
    for line in open(TRIPLES):
        f = [x.strip() for x in line.split("|")]
        if line.startswith("#") or f[0] != name:
            continue
        kv = dict(x.split(": ", 1) for x in f[1:])
        return dict(name=name, cc1=kv["cc1"], cflags=kv["cflags"], maspsx=kv["maspsx"])
    die(f"no row {name} in {TRIPLES}")


def clone():
    if not os.path.isdir(CLONE):
        subprocess.run(["git", "clone", "-q", REPO, CLONE], check=True)
    head = subprocess.run(["git", "-C", CLONE, "rev-parse", "--short", "HEAD"], capture_output=True, text=True,
                          check=True).stdout.strip()
    os.makedirs(SCR, exist_ok=True)
    if not os.path.isfile(f"{SCR}/clone.txt"):
        Path(f"{SCR}/clone.txt").write_text(f"{head} {datetime.date.today().isoformat()}\n")
    return head


def sources():
    """F: src/main/<name>.c of each `c` subsegment (unnamed -> hex offset, splat's default name)."""
    out = []
    for line in open(f"{CLONE}/{YAML}"):
        m = C_SEG.match(line)
        if m:
            src = f"src/main/{(m.group(2) or format(int(m.group(1), 16), 'X')).strip()}.c"
            if os.path.isfile(f"{CLONE}/{src}") and src not in out:
                out.append(src)
    return out


def compile_one(src, t, inc, objdir, logdir):
    """Object path, or None (stage + stderr tail in the per-file log)."""
    obj = os.path.abspath(f"{objdir}/{src}.o")
    log = f"{logdir}/{src}.log"
    os.makedirs(os.path.dirname(obj), exist_ok=True)
    os.makedirs(os.path.dirname(log), exist_ok=True)
    stages = [("cpp", CPP + [f"-I{inc}"] + CPP_TAIL + [src]), ("cc1", [t["cc1"]] + t["cflags"].split()),
              ("maspsx", ["maspsx"] + t["maspsx"].split()), ("as", AS + ["-o", obj, "--"])]
    data = b""
    for i, (stage, cmd) in enumerate(stages):
        p = subprocess.run(cmd, input=data if i else None, capture_output=True, cwd=CLONE)
        if p.returncode != 0:
            tail = p.stderr.decode(errors="replace").splitlines()[-20:]
            Path(log).write_text(f"FAIL {stage} rc {p.returncode}\n" + "\n".join(tail) + "\n")
            if os.path.exists(obj):
                os.remove(obj)
            return None
        data = p.stdout
    Path(log).write_text("OK\n")
    return obj


def functions(obj):
    """[(name, words, mask)] per STT_FUNC defined in obj; extent st_size, else symbol order (probe.elf_function)."""
    with open(obj, "rb") as f:
        b = f.read()
    shoff, = struct.unpack_from("<I", b, 0x20)
    shentsize, shnum, shstrndx = struct.unpack_from("<HHH", b, 0x2E)
    secs = [struct.unpack_from("<10I", b, shoff + i * shentsize) for i in range(shnum)]
    stro = secs[shstrndx][4]
    names = [b[stro + s[0]:b.index(b"\0", stro + s[0])].decode() for s in secs]
    syms = []
    for s in secs:
        if s[1] != 2:
            continue
        so = secs[s[6]][4]
        for o in range(s[4], s[4] + s[5], 16):
            nm, val, size, info, _, shndx = struct.unpack_from("<IIIBBH", b, o)
            if 0 < shndx < len(secs):
                syms.append((b[so + nm:b.index(b"\0", so + nm)].decode(), val, size, info, shndx))
    masks = census.elf_masks(obj)
    out = []
    for name, val, size, info, shndx in syms:
        if info & 0xF != 2 or secs[shndx][1] != 1:
            continue
        if size == 0:
            later = [x[1] for x in syms if x[4] == shndx and x[1] > val and ((x[3] & 0xF) == 2 or (x[3] >> 4) != 0)]
            size = (min(later) if later else secs[shndx][5]) - val
        n = size // 4
        if n == 0:
            continue
        sec, off = names[shndx], secs[shndx][4] + val
        out.append((name, list(struct.unpack_from(f"<{n}I", b, off)),
                    [masks.get((sec, val + 4 * i), 0) for i in range(n)]))
    return out


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
    the X6 side's name and state from the corpus rows."""
    base = os.path.abspath(objdir)
    by_key = {}
    for o in objs:
        src = os.path.relpath(o, base)[:-2]
        for name, w, m in functions(o):
            by_key.setdefault(sig.sig_of("X4", name, w, m)["exact"], set()).add((src, name))
    out = []
    for s in x6:
        r = rows.get((s["prog"], s["vram"]), {})
        ps = sorted(by_key.get(s["exact"], ()))
        if ps:
            out.append((s["prog"], int(s["vram"], 16), r.get("name", "-"), s["words"], s["exact"], ps[0][0], ps[0][1],
                        len(ps), r.get("state", "-")))
    out.sort(key=lambda x: (x[0], x[1]))
    os.makedirs(os.path.dirname(PARTNERS), exist_ok=True)
    with open(PARTNERS, "w") as f:
        for p, v, fn, w, k, src, name, n, st in out:
            f.write(f"{p}\t0x{v:08X}\t{fn}\t{w}\t{k}\t{src}\t{name}\t{n}\t{st}\n")
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
    inc = os.path.abspath(f"{SCR}/inc")
    os.makedirs(inc, exist_ok=True)
    Path(f"{inc}/common.h").write_text(OVERRIDE)
    objdir, logdir = f"{SCR}/{t['name']}/obj", f"{SCR}/{t['name']}/log"
    srcs = sources()
    with ThreadPoolExecutor(os.cpu_count() or 4) as ex:
        objs = [o for o in ex.map(lambda s: compile_one(s, t, inc, objdir, logdir), srcs) if o]
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
