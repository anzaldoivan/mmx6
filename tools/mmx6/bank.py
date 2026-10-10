#!/usr/bin/env python3
"""bank.py -- the reconcile ladder: bank one body into its real TU, rung by rung (container python3, stdlib only).

  bank.py <prog:vram> --src <file>
      -> preflight: the corpus row (build/corpus/functions.jsonl) is include_asm in a TU of config/c_units.txt, else
         `RECONCILE <func> refused: <cause>` (rc 2). Rungs:
         R1 sha1 of --src recorded; probe.probe under the Makefile default TRIPLE must MATCH.
         R2 in src/<prog>/<tu>.c the line `INCLUDE_ASM("asm/<prog>/nonmatchings/<tu>", <func>);` becomes
            `#include "<src relative to src/<prog>/>"`; the unit object must compile.
         R3 declsync.sync over the program's C files (refusal or declsync error stops); typecheck.py --files <edited + body>; edited
            units recompile.
         R4 stop on a config/boundaries.txt jtbl row of the program with lo inside the function ("jtbl not carved"),
            or on unit .rodata grown vs the pre-bank object ("rodata needs placement").
         R5 clean rebuild of the program (C objects, elf, binary removed; C0034) and its sha1 check; then the body
            sha1 must equal R1's, typecheck.py --all and sig.py --rescan must pass; a body under src/shared/ gets its
            config/dedup_registry.txt row (appended, line-preserving, only if absent).
         One verdict line: `RECONCILE <func> R5 banked; body sha1 <h> unchanged since R1` (rc 0) or
         `RECONCILE <func> stopped R<k>: <cause>` (rc 1). A stop restores every edited file byte-exact and rebuilds
         the program so build/ matches the tree; it never asks for a body redraft. Logs under .run/bank/.
  bank.py <prog:vram> --src <shared body> --define OLD=NEW [--define ...]
      -> a shared body under other names (T5, tools/mmx6/propagate.py): R1 probes a scratch wrapper
         .run/bank/wrap/<prog>/<func>.c (`#define OLD NEW` lines + `#include` of the body); R2 writes that block, then
         `#undef OLD` lines, in place of the INCLUDE_ASM line; R3 syncs against the renamed definition. A unit that
         already holds the block (corpus state c) is re-gated, not re-edited. No registry row (propagate.py writes it).
  bank.py --self-test
      -> planted controls (C0054) on planted include_asm siblings: X, Y = the two lowest-vram exe members of the
         exemplar's dup class whose unit holds a define block for src/shared/entity/state_dispatch.c; each block becomes
         `INCLUDE_ASM(...)` of a generated asm/<prog>/nonmatchings/<tu>/<func>.s (`.word`s of probe.retail_words plus
         the untrimmed tail); the program must rebuild to its pre-test sha1 (else FAIL); corpus.py --all regenerates
         the corpus. Bodies generated into src/shared/_selftest/: A = X with X's own table (its block's define) and a
         planted width-compatible prototype `void X(s32);` in src/SLUS_013.95/LIBSPU_S_M_UTIL.c -> R3 syncs it,
         `R5 banked`; B = Y with the exemplar's table (masked standalone MATCH, wrong binary) -> `stopped R5`. Never
         writes the registry; after each control the planted state is restored and rebuilt; teardown restores src/,
         the registry and build/corpus/*.jsonl byte-exact, deletes the planted .s files and rebuilds; fail-closed end
         check: src/ tree, registry and program binary sha1 equal their pre-test values.
         Prints each control's verdict line, then `RECONCILE CONTROL OK` (rc 0), else `RECONCILE SELF-TEST FAIL` rc 1.
Firewall G12: names, addresses, counts and hashes of our own files only.
"""
import argparse
import glob
import hashlib
import json
import os
import re
import shutil
import struct
import subprocess
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import corpus  # noqa: E402
import declsync  # noqa: E402
import probe  # noqa: E402

LOGDIR = ".run/bank"
REGISTRY = "config/dedup_registry.txt"
REGISTRY_HEAD = ("# config/dedup_registry.txt -- shared bodies and their members (tools/mmx6/bank.py); line-preserving.\n"
                 "# <dup key> <exemplar prog:vram> <shared path> <member prog:vram> <state gated|pending|refused> "
                 "<reason>\n")
EXEMPLAR = ("SLUS_013.95", 0x8003744C, "func_8003744C", "D_80073C1C", "src/shared/entity/state_dispatch.c")
SELFTEST_DIR = "src/shared/_selftest"
PLANT_UNIT = "src/SLUS_013.95/LIBSPU_S_M_UTIL.c"


class Stop(Exception):
    def __init__(self, rung, cause):
        super().__init__(cause)
        self.rung, self.cause = rung, cause


# ---- helpers -------------------------------------------------------------------------------------------------------

def sha1(path):
    with open(path, "rb") as f:
        return hashlib.sha1(f.read()).hexdigest()


def sh(cmd, log):
    """rc of cmd (list), its output appended to .run/bank/<log>.log."""
    os.makedirs(LOGDIR, exist_ok=True)
    with open(os.path.join(LOGDIR, log + ".log"), "a") as f:
        f.write("$ " + " ".join(cmd) + "\n")
        f.flush()
        return subprocess.run(cmd, stdout=f, stderr=subprocess.STDOUT).returncode


def makefile_triple():
    with open("Makefile") as f:
        return re.search(r"^TRIPLE \?= (\S+)", f.read(), re.M).group(1)


def corpus_row(prog, vram):
    with open("build/corpus/functions.jsonl") as f:
        for line in f:
            r = json.loads(line)
            if r["prog"] == prog and int(r["vram"], 16) == vram:
                return r
    return None


def c_units(prog):
    with open("config/c_units.txt") as f:
        return {t[1] for t in (l.split() for l in f) if len(t) >= 2 and t[0] == prog}


def bin_out(prog):
    return f"build/rock/{prog[5:]}.bin" if prog.startswith("rock_") else f"build/{prog}"


def rodata_size(obj):
    """Total size of the .rodata* sections of an ELF32 LE object."""
    with open(obj, "rb") as f:
        b = f.read()
    shoff, = struct.unpack_from("<I", b, 0x20)
    shentsize, shnum, shstrndx = struct.unpack_from("<HHH", b, 0x2E)
    secs = [struct.unpack_from("<10I", b, shoff + i * shentsize) for i in range(shnum)]
    names = secs[shstrndx][4]
    total = 0
    for s in secs:
        if b[names + s[0]:b.index(b"\0", names + s[0])].decode().startswith(".rodata"):
            total += s[5]
    return total


def rebuild(prog, log):
    """Clean rebuild of prog (its C objects, elf and binary removed first, C0034); rc of make."""
    for p in glob.glob(f"build/src/{prog}/**/*.c.o", recursive=True) + [f"build/{prog}.elf", bin_out(prog)]:
        if os.path.exists(p):
            os.remove(p)
    return sh(["make", "-s", bin_out(prog)], log)


def put(saved, path, text):
    """Write text to path, recording the original bytes (None: absent) once."""
    if path not in saved:
        saved[path] = open(path, "rb").read() if os.path.exists(path) else None
    with open(path, "w") as f:
        f.write(text)


def restore(saved):
    for p, b in saved.items():
        if b is None:
            if os.path.exists(p):
                os.remove(p)
        else:
            with open(p, "wb") as f:
                f.write(b)


def dup_key(prog, vram):
    with open("build/census/classes.jsonl") as f:
        for line in f:
            r = json.loads(line)
            if r["kind"] == "dup" and any(m[0] == prog and int(m[1], 16) == vram for m in r["members"]):
                return r
    return None


def subst(text, defines):
    """text with each whole-word OLD of defines [(OLD, NEW)] replaced by NEW (what cpp makes of the body)."""
    for old, new in defines:
        text = re.sub(rf"\b{re.escape(old)}\b", new, text)
    return text


def block(src, where, defines):
    """Lines that instantiate src from a file in directory where: defines, the #include, the #undefs."""
    return ([f"#define {o} {n}" for o, n in defines] + [f'#include "{os.path.relpath(src, where)}"']
            + [f"#undef {o}" for o, _ in defines])


def placed(lines, blk, defines):
    """Indexes where blk starts in lines (a bare include preceded by a #define is another member's block)."""
    return [i for i in range(len(lines)) if lines[i:i + len(blk)] == blk
            and (defines or not (i and lines[i - 1].startswith("#define ")))]


def wrapper(src, func, defines, prog=""):
    """Scratch C file instantiating src as func (R1 under defines); under wrap/<prog>/ (names repeat across programs)."""
    d = os.path.join(LOGDIR, "wrap", prog)
    os.makedirs(d, exist_ok=True)
    p = os.path.join(d, func + ".c")
    with open(p, "w") as f:
        f.write("\n".join(block(src, d, defines)) + "\n")
    return p


# ---- the ladder ----------------------------------------------------------------------------------------------------

def ladder(prog, vram, src, func, tu, saved, log, defines=(), r5=True):
    """Walk R1-R4 (and R5 when r5); raises Stop; returns the R1 sha1."""
    h1 = sha1(src)
    try:
        ok, m, n = probe.probe(func, prog, wrapper(src, func, defines, prog) if defines else src, makefile_triple())
    except SystemExit as e:
        raise Stop(1, f"probe error: {e}")
    if not ok:
        raise Stop(1, f"standalone probe FAIL {m}/{n} words")
    unit_c, unit_o = f"src/{prog}/{tu}.c", f"build/src/{prog}/{tu}.c.o"
    if not os.path.isfile(unit_o) and sh(["make", "-s", unit_o], log):
        raise Stop(2, f"pre-bank {unit_o} does not build")
    pre_ro = rodata_size(unit_o)
    # R2 (a unit already holding the block is re-gated: compiled, not edited)
    line = f'INCLUDE_ASM("asm/{prog}/nonmatchings/{tu}", {func});'
    with open(unit_c) as f:
        text = f.read()
    lines = text.split("\n")
    blk = block(src, os.path.dirname(unit_c), defines)
    at = placed(lines, blk, defines)
    if lines.count(line) == 1 and not at:
        i = lines.index(line)
        put(saved, unit_c, "\n".join(lines[:i] + blk + lines[i + 1:]))
    elif lines.count(line) or len(at) != 1:
        raise Stop(2, f"{lines.count(line)} lines `{line}`, {len(at)} placed blocks in {unit_c}")
    if sh(["make", "-s", "-B", unit_o], log):
        raise Stop(2, f"{unit_o} does not compile (log {LOGDIR}/{log}.log)")
    # R3
    with open(src, errors="replace") as f:
        body = f.read()
    try:
        edits, dl, refused, _ = declsync.sync(prog, src, texts={src: subst(body, defines)})
    except SystemExit as e:  # e.g. a definition DEF_RE cannot read (function-pointer parameter): a stop, not a crash
        raise Stop(3, f"declsync error: {e}")
    with open(os.path.join(LOGDIR, log + ".log"), "a") as f:
        f.write("\n".join(dl) + "\n")
    if refused:
        raise Stop(3, "declaration " + next(l for l in dl if " refused " in l)[len("DECLSYNC "):])
    if os.path.abspath(src) in {os.path.abspath(p) for p in edits}:
        raise Stop(3, f"declsync would edit the body {src}")
    for p, t in sorted(edits.items()):
        put(saved, p, t)
    if sh([sys.executable, "tools/mmx6/typecheck.py", "--files"] + sorted(edits) + [src], log):
        raise Stop(3, f"typecheck.py --files rc != 0 (log {LOGDIR}/{log}.log)")
    units = {p for p in edits if os.path.dirname(p) == f"src/{prog}" and p.endswith(".c")} | ({unit_c} if edits else set())
    for p in sorted(units):
        if sh(["make", "-s", "-B", f"build/{p}.o"], log):
            raise Stop(3, f"edited unit {p} does not recompile")
    # R4
    lo, hi = vram, int(corpus_row(prog, vram)["end"], 16)
    for a, _ in corpus.jtbl_rows(prog):
        if lo <= a < hi:
            raise Stop(4, f"jtbl not carved (0x{a:08X})")
    post_ro = rodata_size(unit_o)
    if post_ro > pre_ro:
        raise Stop(4, f"rodata needs placement (+{post_ro - pre_ro} bytes)")
    if r5:
        rung5(prog, src, h1, log)
    return h1


def rung5(prog, src, h1, log):
    """R5 over the whole program (once per program when propagating); raises Stop."""
    if rebuild(prog, log):
        raise Stop(5, f"{bin_out(prog)} whole-binary hash red from a clean rebuild (log {LOGDIR}/{log}.log)")
    if sha1(src) != h1:
        raise Stop(5, f"body sha1 changed since R1 ({src})")
    if sh([sys.executable, "tools/mmx6/typecheck.py", "--all"], log):
        raise Stop(5, "typecheck.py --all rc != 0")
    if sh([sys.executable, "tools/mmx6/sig.py", "--rescan"], log):
        raise Stop(5, "sig.py --rescan rc != 0")


def preflight(prog, vram, src, defines=()):
    """(corpus row or None, func, refusal cause or ''); a c row passes only when its unit holds src's block."""
    r = corpus_row(prog, vram) if os.path.isfile("build/corpus/functions.jsonl") else None
    func = r["name"] if r else f"{prog}:0x{vram:08X}"
    regate = False
    if r is not None and r["state"] == "c" and os.path.isfile(f"src/{prog}/{r['tu']}.c") and os.path.isfile(src):
        unit_c = f"src/{prog}/{r['tu']}.c"
        with open(unit_c) as f:
            regate = len(placed(f.read().split("\n"), block(src, os.path.dirname(unit_c), defines), defines)) == 1
    cause = ("no corpus row" if r is None
             else f"state {r['state']}, not include_asm" if r["state"] != "include_asm" and not regate
             else f"TU {r['tu']} not in config/c_units.txt" if r["tu"] not in c_units(prog)
             else f"no file {src}" if not os.path.isfile(src) else "")
    return r, func, cause


def bank(pv, src, registry=True, defines=()):
    """(rc, verdict line); prints the verdict line."""
    prog, _, v = pv.rpartition(":")
    vram = int(v, 16)
    r, func, cause = preflight(prog, vram, src, defines)
    if cause:
        out = f"RECONCILE {func} refused: {cause}"
        print(out, flush=True)
        return 2, out
    log = f"{prog}.{func}"  # per program: overlays share function names
    if os.path.exists(os.path.join(LOGDIR, log + ".log")):
        os.remove(os.path.join(LOGDIR, log + ".log"))
    saved = {}
    try:
        h1 = ladder(prog, vram, src, func, r["tu"], saved, log, defines)
    except Stop as e:
        restore(saved)
        rc = rebuild(prog, log)
        out = f"RECONCILE {func} stopped R{e.rung}: {e.cause}" + (f" (restore rebuild rc {rc})" if rc else "")
        print(out, flush=True)
        return 1, out
    if registry and not defines and os.path.abspath(src).startswith(os.path.abspath("src/shared") + os.sep):
        cls = dup_key(prog, vram)
        if cls is not None:
            ex = f"{prog}:0x{vram:08X}"
            row = f"{cls['key']} {ex} {os.path.relpath(src)} {ex} gated exemplar"
            text = open(REGISTRY).read() if os.path.exists(REGISTRY) else REGISTRY_HEAD
            lines = text.split("\n")
            stale = [i for i, x in enumerate(lines) if x.split(None, 5)[:4:3] == [cls["key"], ex] and x != row
                     and not x.startswith("#") and x.split(None, 5)[4:5] != ["gated"]]
            if stale:  # a refused/open row of this member (an earlier propagate) becomes its gated row, in place
                lines[stale[0]] = row
                with open(REGISTRY, "w") as f:
                    f.write("\n".join(lines))
            elif row not in lines:
                with open(REGISTRY, "w") as f:
                    f.write(text + ("" if text.endswith("\n") else "\n") + row + "\n")
    out = f"RECONCILE {func} R5 banked; body sha1 {h1} unchanged since R1"
    print(out, flush=True)
    return 0, out


# ---- self-test -----------------------------------------------------------------------------------------------------

def member_block(prog, func):
    """(unit .c, line index, the member's table) of func's define block for the exemplar body, or None."""
    _, _, ename, etable, esrc = EXEMPLAR
    for unit_c in sorted(glob.glob(f"src/{prog}/*.c")):
        with open(unit_c) as f:
            lines = f.read().split("\n")
        for i in range(len(lines) - 1):
            m = re.fullmatch(rf"#define {etable} (\w+)", lines[i + 1])
            if lines[i] == f"#define {ename} {func}" and m:
                blk = block(esrc, os.path.dirname(unit_c), [(ename, func), (etable, m.group(1))])
                if lines[i:i + len(blk)] == blk:
                    return unit_c, i, m.group(1)
    return None


def plant_words(prog, func, vram, end):
    """Retail words of [vram, end): probe.retail_words (trimmed, C0021) plus the untrimmed tail words."""
    words = probe.retail_words(prog, func)
    n = (end - vram) // 4
    if len(words) < n:
        target, seg_start, seg_vram = probe.yaml_layout(prog)
        with open(target, "rb") as f:
            f.seek(seg_start + vram - seg_vram + 4 * len(words))
            words += list(struct.unpack(f"<{n - len(words)}I", f.read(4 * (n - len(words)))))
    return words


def tree_sums(root):
    return {p: sha1(p) for p in sorted(glob.glob(f"{root}/**/*", recursive=True)) if os.path.isfile(p)}


def self_test():
    prog, ev, ename, etable, esrc = EXEMPLAR
    corpus_out = [f"build/corpus/{n}.jsonl" for n in ("functions", "spans", "denominators")]
    pre_src, pre_reg, pre_bin = tree_sums("src"), sha1(REGISTRY), sha1(bin_out(prog))
    pre_corpus = {p: open(p, "rb").read() for p in corpus_out}
    saved, fails = {}, 0
    try:
        cls = dup_key(prog, ev)
        rows = {int(r["vram"], 16): r for r in map(json.loads, open(corpus_out[0])) if r["prog"] == prog}
        sibs = [(v, member_block(prog, rows[v]["name"])) for v in sorted(int(m[1], 16) for m in (cls["members"] if cls else [])
                                                                         if m[0] == prog and int(m[1], 16) != ev)
                if v in rows]
        sibs = [(v, b) for v, b in sibs if b][:2]
        if len(sibs) < 2:
            raise Stop(0, f"{len(sibs)} c-unit siblings of {ename}'s dup class with a define block; need 2")
        # plant (C0054): each member's define block -> INCLUDE_ASM of a generated .s of its retail words
        for v, (unit_c, i, _) in sorted(sibs, key=lambda s: (s[1][0], -s[1][1])):  # bottom-up within a unit
            func, tu = rows[v]["name"], os.path.basename(unit_c)[:-2]
            words = plant_words(prog, func, v, int(rows[v]["end"], 16))
            _, seg_start, seg_vram = probe.yaml_layout(prog)
            off = seg_start + v - seg_vram
            with open(unit_c) as f:
                lines = f.read().split("\n")
            put(saved, unit_c, "\n".join(lines[:i] + [f'INCLUDE_ASM("asm/{prog}/nonmatchings/{tu}", {func});']
                                         + lines[i + 5:]))
            put(saved, f"asm/{prog}/nonmatchings/{tu}/{func}.s",
                ".set noat      /* allow manual use of $at */\n.set noreorder /* don't insert nops after branches */\n\n"
                f"nonmatching {func}, 0x{4 * len(words):X}\n\nglabel {func}\n"
                + "".join(f"    /* {off + 4 * k:X} {v + 4 * k:08X} {struct.pack('<I', w).hex().upper()} */  .word 0x{w:08X}\n"
                          for k, w in enumerate(words)) + f"endlabel {func}\n")  # neighbour row comment (corpus ROW_RE)
        if rebuild(prog, "selftest-plant") or sha1(bin_out(prog)) != pre_bin:
            raise Stop(0, f"plant rebuild of {prog} red (log {LOGDIR}/selftest-plant.log)")
        if sh([sys.executable, "tools/mmx6/corpus.py", "--all"], "selftest-plant"):
            raise Stop(0, "corpus.py --all rc != 0 on the planted tree")
        rows = {int(r["vram"], 16): r for r in map(json.loads, open(corpus_out[0])) if r["prog"] == prog}
        (vx, (ux, _, tx)), (vy, (uy, _, _)) = sibs
        if any(rows[v]["state"] != "include_asm" for v in (vx, vy)):
            raise Stop(0, "planted siblings not include_asm in the regenerated corpus")
        with open(esrc) as f:
            body = f.read()
        x, y = rows[vx]["name"], rows[vy]["name"]
        controls = [  # (name, func, vram, table, plant prototype, expect)
            ("A", x, vx, tx, True, " R5 banked; "),
            ("B", y, vy, etable, False, " stopped R5: "),
        ]
        snap = sorted({ux, uy}) + [PLANT_UNIT, REGISTRY]
        for name, func, vram, table, plant, expect in controls:
            orig = {p: (open(p, "rb").read() if os.path.exists(p) else None) for p in snap}
            try:
                os.makedirs(SELFTEST_DIR, exist_ok=True)
                src = os.path.join(SELFTEST_DIR, func + ".c")
                with open(src, "w") as f:
                    f.write(body.replace(ename, func).replace(etable, table))
                h0 = sha1(src)
                if plant:
                    with open(PLANT_UNIT, "a") as f:
                        f.write(f"\nvoid {func}(s32);\n")
                rc, out = bank(f"{prog}:0x{vram:08X}", src, registry=False)
                good = expect in out and (rc == 0) == plant
                if plant:
                    synced = f"void {func}(s8* arg0);" in open(PLANT_UNIT).read()
                    good &= synced and f"body sha1 {h0} unchanged" in out
                print(f"control {name} {func} {'ok' if good else 'FAIL'}: want {expect.strip(' :;')}")
                fails += not good
            finally:
                restore(orig)
                shutil.rmtree(SELFTEST_DIR, ignore_errors=True)
                shutil.rmtree(f"build/{SELFTEST_DIR}", ignore_errors=True)
                if rebuild(prog, "selftest-restore"):
                    print(f"control {name}: restore rebuild of {prog} red")
                    fails += 1
    except (Exception, SystemExit) as e:
        print(f"bank: self-test {e}")
        fails += 1
    finally:
        restore(saved)
        shutil.rmtree(SELFTEST_DIR, ignore_errors=True)
        shutil.rmtree(f"build/{SELFTEST_DIR}", ignore_errors=True)
        for p, b in pre_corpus.items():
            with open(p, "wb") as f:
                f.write(b)
        if rebuild(prog, "selftest-teardown"):
            print(f"bank: teardown rebuild of {prog} red")
            fails += 1
    # fail-closed: the tree, the registry and the binary are what they were before the test
    for what, ok in (("src/", tree_sums("src") == pre_src), (REGISTRY, sha1(REGISTRY) == pre_reg),
                     (bin_out(prog), os.path.exists(bin_out(prog)) and sha1(bin_out(prog)) == pre_bin)):
        if not ok:
            print(f"bank: {what} sha1 differs from the pre-test value")
            fails += 1
    if fails:
        print(f"RECONCILE SELF-TEST FAIL {fails}")
        return 1
    print("RECONCILE CONTROL OK")
    return 0


def main():
    os.chdir(os.path.join(HERE, "..", ".."))
    ap = argparse.ArgumentParser(description=__doc__.split("\n", 1)[0])
    ap.add_argument("pv", nargs="?", metavar="prog:vram")
    ap.add_argument("--src")
    ap.add_argument("--define", action="append", default=[], metavar="OLD=NEW")
    ap.add_argument("--self-test", action="store_true")
    a = ap.parse_args()
    if a.self_test:
        return self_test()
    if not (a.pv and a.src) or any(d.count("=") != 1 for d in a.define):
        ap.error("need <prog:vram> --src <file> [--define OLD=NEW ...], or --self-test")
    return bank(a.pv, a.src, defines=[tuple(d.split("=")) for d in a.define])[0]


if __name__ == "__main__":
    sys.exit(main())
