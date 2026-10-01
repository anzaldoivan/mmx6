#!/usr/bin/env python3
"""corpus.py -- the function corpus and its text denominator over the linked build (container, stdlib only).

  corpus.py --all | --prog <p>
      -> build/corpus/functions.jsonl  {"prog","vram","end","words","name","tu","state","lane","src"}
         build/corpus/spans.jsonl      {"prog","lo","hi","kind":"jtbl|libgap|data|pad"}
         build/corpus/denominators.jsonl {"prog","text_lo","text_hi","text_bytes","from"}
         (vram/end/lo/hi hex strings, end/hi exclusive); stdout, last two lines:
         `CORPUS SPANS jtbl <..> libgap <..> data <..> pad <..> bytes; game <gb> lib <lb> function bytes`
         `CORPUS <n> functions <b> bytes of <T> text bytes in <m> programs; game <g> lib <l>; c <c> c-empty <e>
          asm <a>; uncovered 0` (a = asm + include_asm)
  corpus.py --c-names
      -> fleet_c_names(), one name per line, sorted (fleet.sh `C MATCHED`, harness.py P1: one instrument)
  corpus.py --self-test
      -> on the real build: func_80055A04 include_asm/LIBSPU_S_M_UTIL/lib; the `banked` rows of config/probes.txt
         are the `c` set; c-empty = (fleet.sh `C MATCHED` method, readelf on build/src/**/*.c.o, minus INCLUDE_ASM
         names) - banked; planted control (one function start moved up one non-zero word, in memory) must refuse
         naming that vram. Ends `CORPUS CONTROL OK` (rc 0), else rc 1.

Programs = config/*.yaml stems, sorted. Functions: glabel..endlabel (or the next glabel/dlabel) rows of
asm/<p>/**/*.s; under asm/<p>/nonmatchings/<tu>/ and named by INCLUDE_ASM in src/<p>/<tu>.c -> include_asm, else
asm; C definitions in src/<p>/*.c and the `#include "<rel>.c"` files they include (src/shared/ bodies; clang-formatted,
name at column 0) -> c-empty when the body is `{` ws `}`, else c; C extent = build/<p>.elf symtab value + st_size (size 0: up to the next function start, C0047).
Lane: exe TU 120A0 -> game, other exe TUs -> lib, every overlay function -> game.
Text = [<seg>_TEXT_START, <seg>_TEXT_END) of build/<p>.elf (the only *_TEXT_START symbol). Every text word is a
function word or exactly one span kind, by precedence jtbl (config/boundaries.txt `jtbl lo hi` of the program) >
libgap (inside an exe hex-named non-game TU) > data (dlabel region) > pad (zero word).
Refuses (rc 1, prints prog and lo..hi): overlapping extents, a function outside text, an unclassified uncovered
word, function + span bytes != text bytes, 0 functions, a missing build output.
Firewall G12: names, addresses and counts only; no words or bytes are printed or written.
"""
import argparse
import glob
import json
import os
import re
import struct
import subprocess
import sys

ROW_RE = re.compile(r"/\*\s+[0-9A-Fa-f]+\s+([0-9A-Fa-f]{8})(?:\s+([0-9A-Fa-f]{8}))?\s+\*/")
INC_RE = re.compile(r"^INCLUDE_ASM\(\"[^\"]*\", *(\w+)\);", re.M)
CDEF_RE = re.compile(r"^(?!INCLUDE_ASM\b)[A-Za-z_][^;{}()#]*?\b([A-Za-z_]\w*)\s*\([^;{}]*?\)\s*\{(\s*\})?", re.M)
CINC_RE = re.compile(r"^#include \"([^\"]+\.c)\"[ \t]*$", re.M)  # a shared body included by its member TU
GAME_TU = "120A0"  # the exe game TU [0x800120A0, 0x80054AD0) (config/segmentation.md); every other exe TU is lib
HEX_TU = re.compile(r"[0-9A-F]+")
OUT = "build/corpus"


class Refuse(Exception):
    pass


# ---- inputs --------------------------------------------------------------------------------------------------------

def programs():
    return sorted(os.path.basename(y)[:-5] for y in glob.glob("config/*.yaml"))


def is_overlay(prog):
    return prog.startswith("rock_")


def elf_symbols(path):
    """[(name, value, size, type)] of the ELF32 LE symtab at path."""
    with open(path, "rb") as f:
        b = f.read()
    shoff, = struct.unpack_from("<I", b, 0x20)
    shentsize, shnum = struct.unpack_from("<HH", b, 0x2E)
    secs = [struct.unpack_from("<IIIIIIIIII", b, shoff + i * shentsize) for i in range(shnum)]
    out = []
    for s in secs:
        if s[1] != 2:  # SHT_SYMTAB
            continue
        stoff = secs[s[6]][4]
        for o in range(s[4], s[4] + s[5], 16):
            nm, val, size, info = struct.unpack_from("<IIIB", b, o)
            name = b[stoff + nm:b.index(b"\0", stoff + nm)].decode()
            out.append((name, val, size, info & 0xF))
    return out


def parse_asm(prog):
    """(funcs [(name, vram, end, tu, nonmatching)], words {vram: word}, data {vram}, tu_range {tu: (lo, hi)})."""
    root = f"asm/{prog}"
    funcs, words, data, tus = [], {}, set(), {}
    for d, dirs, files in sorted(os.walk(root)):
        dirs.sort()
        for fname in sorted(files):
            if not fname.endswith(".s"):
                continue
            path = os.path.join(d, fname)
            rel = os.path.relpath(path, root).split(os.sep)
            nonm = "nonmatchings" in rel[:-1]
            tu = rel[rel.index("nonmatchings") + 1] if nonm else fname[:-2]
            text, cur, rows, dl = nonm, None, [], False  # a nonmatchings .s has no .section: INCLUDE_ASM puts it in .text

            def close():
                if cur is not None and rows:
                    funcs.append((cur, rows[0], rows[-1] + 4, tu, nonm))

            with open(path, errors="replace") as f:
                for line in f:
                    s = line.strip()
                    if s.startswith(".section") or s in (".text", ".data", ".rodata", ".bss"):
                        close()
                        text, cur, rows, dl = s.split(",")[0].split()[-1] == ".text", None, [], False
                        continue
                    if s.startswith("glabel "):
                        close()
                        cur, rows, dl = s.split()[1], [], False
                        continue
                    if s.startswith("dlabel "):
                        close()
                        cur, rows, dl = None, [], True
                        continue
                    if s.startswith("enddlabel "):
                        dl = False
                        continue
                    if cur is not None and s == f"endlabel {cur}":
                        close()
                        cur, rows = None, []
                        continue
                    m = ROW_RE.search(line)
                    if not m or not text:
                        continue
                    v = int(m.group(1), 16) & ~3  # a `.short`/`.byte` row has no word: it marks its word
                    if m.group(2):
                        words[v] = int.from_bytes(bytes.fromhex(m.group(2)), "little")
                    lo, hi = tus.get(tu, (v, v + 4))
                    tus[tu] = (min(lo, v), max(hi, v + 4))
                    if cur is not None and m.group(2):
                        rows.append(v)
                    elif dl:
                        data.add(v)
            close()
    return funcs, words, data, tus


def read_c(path):
    """Text of the C file at path with each local `#include "<rel>.c"` (relative to it) inlined (src/shared/ bodies)."""
    with open(path, errors="replace") as f:
        src = f.read()
    return CINC_RE.sub(lambda m: read_c(os.path.normpath(os.path.join(os.path.dirname(path), m.group(1)))), src)


def parse_c(prog):
    """({name: (tu, empty)} of C definitions, {tu: {INCLUDE_ASM names}}) of src/<prog>/*.c (+ their included .c)."""
    defs, inc = {}, {}
    for path in sorted(glob.glob(f"src/{prog}/*.c")):
        tu = os.path.basename(path)[:-2]
        src = read_c(path)
        inc[tu] = set(INC_RE.findall(src))
        for m in CDEF_RE.finditer(src):
            defs[m.group(1)] = (tu, m.group(2) is not None)
    return defs, inc


def jtbl_rows(prog):
    rows, cur = [], None
    with open("config/boundaries.txt") as f:
        for line in f:
            t = line.split()
            if line.startswith("# program "):
                cur = t[2]
            elif t and t[0] == "jtbl" and cur == prog and t[2] != "unknown":  # `unknown` hi: a label, no extent
                rows.append((int(t[1], 16), int(t[2], 16)))
    return rows


# ---- one program ---------------------------------------------------------------------------------------------------

def load(prog):
    """Everything check() needs, read from the build of prog."""
    elf = f"build/{prog}.elf"
    if not os.path.isfile(elf) or not os.path.isdir(f"asm/{prog}"):
        raise Refuse(f"REFUSE {prog} missing build output {elf if not os.path.isfile(elf) else 'asm/' + prog}")
    syms = elf_symbols(elf)
    starts = [(n[:-len("_TEXT_START")], v) for n, v, _, _ in syms if n.endswith("_TEXT_START")]
    if len(starts) != 1:
        raise Refuse(f"REFUSE {prog} {len(starts)} *_TEXT_START symbols in {elf}")
    seg, lo = starts[0]
    ends = [v for n, v, _, _ in syms if n == f"{seg}_TEXT_END"]
    if len(ends) != 1:
        raise Refuse(f"REFUSE {prog} no {seg}_TEXT_END in {elf}")
    hi = ends[0]
    afuncs, words, data, tus = parse_asm(prog)
    defs, inc = parse_c(prog)
    lane = (lambda tu: "game") if is_overlay(prog) else (lambda tu: "game" if tu == GAME_TU else "lib")
    funcs = []
    for name, v, e, tu, nonm in afuncs:
        if name in defs:
            continue  # defined in C; the C definition is the function
        if nonm and name not in inc.get(tu, ()):
            raise Refuse(f"REFUSE {prog} {name} nonmatchings/{tu} not referenced by INCLUDE_ASM 0x{v:08X}..0x{e:08X}")
        funcs.append(dict(name=name, vram=v, end=e, tu=tu, state="include_asm" if nonm else "asm", src="glabel"))
    fsym = {n: (v, s) for n, v, s, t in syms if t == 2}
    cpend = []
    for name, (tu, empty) in sorted(defs.items()):
        if name not in fsym:
            raise Refuse(f"REFUSE {prog} C function {name} not in {elf} symtab")
        v, size = fsym[name]
        f = dict(name=name, vram=v, end=v + size, tu=tu, state="c-empty" if empty else "c", src="c")
        funcs.append(f)
        if size == 0:
            cpend.append(f)
    allstarts = sorted({f["vram"] for f in funcs} | {hi})
    for f in cpend:  # C0047: no st_size -> next function start
        f["end"] = min(a for a in allstarts if a > f["vram"])
    for f in funcs:
        f["prog"], f["lane"], f["words"] = prog, lane(f["tu"]), (f["end"] - f["vram"]) // 4
    gaps = [r for t, r in tus.items() if not is_overlay(prog) and t != GAME_TU and HEX_TU.fullmatch(t)]
    return dict(prog=prog, lo=lo, hi=hi, elf=elf, funcs=funcs, words=words, data=data, jtbl=jtbl_rows(prog),
                gaps=gaps)


def runs(vs):
    """Maximal [lo, hi) runs of a sorted word-vram list."""
    out = []
    for v in vs:
        if out and out[-1][1] == v:
            out[-1][1] = v + 4
        else:
            out.append([v, v + 4])
    return out


def check(p):
    """(funcs sorted, spans) of program p, or Refuse naming prog and lo..hi."""
    prog, lo, hi = p["prog"], p["lo"], p["hi"]
    funcs = sorted(p["funcs"], key=lambda f: (f["vram"], f["end"]))
    if not funcs:
        raise Refuse(f"REFUSE {prog} 0 functions (C0042) 0x{lo:08X}..0x{hi:08X}")
    if lo % 4 or hi % 4:
        raise Refuse(f"REFUSE {prog} text not word-aligned 0x{lo:08X}..0x{hi:08X}")
    errs = []
    for a, b in zip(funcs, funcs[1:]):
        if b["vram"] < a["end"]:
            errs.append(f"REFUSE {prog} overlap {a['name']} {b['name']} 0x{b['vram']:08X}..0x{min(a['end'], b['end']):08X}")
    for f in funcs:
        if f["vram"] < lo or f["end"] > hi or f["end"] <= f["vram"] or (f["end"] - f["vram"]) % 4:
            errs.append(f"REFUSE {prog} extent {f['name']} 0x{f['vram']:08X}..0x{f['end']:08X} outside text or empty")
    if errs:
        raise Refuse("\n".join(errs))
    covered = set()
    for f in funcs:
        covered.update(range(f["vram"], f["end"], 4))
    kinds, bad = {}, []
    for v in range(lo, hi, 4):
        if v in covered:
            continue
        if any(a <= v < b for a, b in p["jtbl"]):
            kinds[v] = "jtbl"
        elif any(a <= v < b for a, b in p["gaps"]):
            kinds[v] = "libgap"
        elif v in p["data"]:
            kinds[v] = "data"
        elif p["words"].get(v) == 0:
            kinds[v] = "pad"
        else:
            bad.append(v)
    if bad:
        rs = runs(bad)
        raise Refuse("\n".join(f"REFUSE {prog} uncovered 0x{a:08X}..0x{b:08X}" for a, b in rs[:10])
                     + (f"\nREFUSE {prog} ... {len(rs)} uncovered runs" if len(rs) > 10 else ""))
    spans = []
    for v in sorted(kinds):
        if spans and spans[-1]["hi"] == v and spans[-1]["kind"] == kinds[v]:
            spans[-1]["hi"] = v + 4
        else:
            spans.append(dict(prog=prog, lo=v, hi=v + 4, kind=kinds[v]))
    fb = sum(f["end"] - f["vram"] for f in funcs)
    sb = sum(s["hi"] - s["lo"] for s in spans)
    if fb + sb != hi - lo:
        raise Refuse(f"REFUSE {prog} function {fb} + span {sb} bytes != text {hi - lo} 0x{lo:08X}..0x{hi:08X}")
    return funcs, spans


# ---- run -----------------------------------------------------------------------------------------------------------

def corpus(progs):
    """[(p, funcs, spans)] of every program, or Refuse (all programs' refusals)."""
    out, errs = [], []
    for prog in progs:
        try:
            p = load(prog)
            out.append((p,) + check(p))
        except Refuse as e:
            errs.append(str(e))
    if errs:
        raise Refuse("\n".join(errs))
    return out


def hx(v):
    return f"0x{v:08X}"


def write(res):
    os.makedirs(OUT, exist_ok=True)
    with open(f"{OUT}/functions.jsonl", "w") as ff, open(f"{OUT}/spans.jsonl", "w") as sf, \
            open(f"{OUT}/denominators.jsonl", "w") as df:
        for p, funcs, spans in res:
            for f in funcs:
                ff.write(json.dumps(dict(prog=f["prog"], vram=hx(f["vram"]), end=hx(f["end"]), words=f["words"],
                                         name=f["name"], tu=f["tu"], state=f["state"], lane=f["lane"],
                                         src=f["src"])) + "\n")
            for s in spans:
                sf.write(json.dumps(dict(prog=s["prog"], lo=hx(s["lo"]), hi=hx(s["hi"]), kind=s["kind"])) + "\n")
            df.write(json.dumps({"prog": p["prog"], "text_lo": hx(p["lo"]), "text_hi": hx(p["hi"]),
                                 "text_bytes": p["hi"] - p["lo"], "from": p["elf"]}) + "\n")


def summary(res):
    fs = [f for _, funcs, _ in res for f in funcs]
    ss = [s for _, _, spans in res for s in spans]
    nb = lambda it: sum(f["end"] - f["vram"] for f in it)
    kb = {k: sum(s["hi"] - s["lo"] for s in ss if s["kind"] == k) for k in ("jtbl", "libgap", "data", "pad")}
    st = {k: sum(1 for f in fs if f["state"] == k) for k in ("c", "c-empty", "asm", "include_asm")}
    game = [f for f in fs if f["lane"] == "game"]
    lib = [f for f in fs if f["lane"] == "lib"]
    T = sum(p["hi"] - p["lo"] for p, _, _ in res)
    print(f"CORPUS SPANS jtbl {kb['jtbl']} libgap {kb['libgap']} data {kb['data']} pad {kb['pad']} bytes; "
          f"game {nb(game)} lib {nb(lib)} function bytes")
    print(f"CORPUS {len(fs)} functions {nb(fs)} bytes of {T} text bytes in {len(res)} programs; game {len(game)} "
          f"lib {len(lib)}; c {st['c']} c-empty {st['c-empty']} asm {st['asm'] + st['include_asm']}; uncovered 0")


def fleet_c_names():
    """fleet.sh :29-34: global non-UND sized FUNC symbols of build/src/**/*.c.o minus INCLUDE_ASM names of src/**/*.c."""
    objs = sorted(glob.glob("build/src/**/*.c.o", recursive=True))
    out = subprocess.run(["mipsel-linux-gnu-readelf", "-sW"] + objs, capture_output=True, text=True).stdout if objs else ""
    defd = {t[7] for t in (l.split() for l in out.splitlines())
            if len(t) >= 8 and t[3] == "FUNC" and t[4] == "GLOBAL" and t[6] != "UND" and t[2] != "0"}
    inc = set()
    for path in glob.glob("src/**/*.c", recursive=True):
        with open(path, errors="replace") as f:
            inc |= set(INC_RE.findall(f.read()))
    return defd - inc


def self_test():
    fails = []

    def ok(cond, what):
        if not cond:
            fails.append(what)
        print(f"self-test {'ok' if cond else 'FAIL'}: {what}")

    res = corpus(programs())
    fs = [f for _, funcs, _ in res for f in funcs]
    by = {(f["prog"], f["name"]): f for f in fs}
    f = by.get(("SLUS_013.95", "func_80055A04"))
    ok(f is not None and (f["state"], f["tu"], f["lane"]) == ("include_asm", "LIBSPU_S_M_UTIL", "lib"),
       "func_80055A04 include_asm LIBSPU_S_M_UTIL lib")
    banked = set()
    with open("config/probes.txt") as pf:
        for line in pf:
            t = line.split()
            if t and not t[0].startswith("#") and t[-1] == "banked":
                banked.add((t[1], t[0]))
    cset = {(f["prog"], f["name"]) for f in fs if f["state"] == "c"}
    ok(len(banked) == 4 and cset == banked,  # was 3 (T4.c1 banked func_8003744C)
       f"banked {len(banked)} == c set {len(cset)}")
    fleet = fleet_c_names()
    empty = {f["name"] for f in fs if f["state"] == "c-empty"}
    want = fleet - {n for _, n in banked}
    ok(empty == want, f"c-empty {len(empty)} == fleet C MATCHED {len(fleet)} - banked {len(fleet & {n for _, n in banked})}")
    # Planted control: one game function whose first word is non-zero and in no jtbl/data region starts a word later.
    p = next(p for p, _, _ in res if p["prog"] == "SLUS_013.95")
    cand = next(f for f in sorted(p["funcs"], key=lambda f: f["vram"])
                if f["src"] == "glabel" and f["lane"] == "game" and f["words"] > 1 and p["words"].get(f["vram"])
                and f["vram"] not in p["data"] and not any(a <= f["vram"] < b for a, b in p["jtbl"]))
    v = cand["vram"]
    cand["vram"] += 4
    try:
        check(p)
        ok(False, f"control 0x{v:08X} refused")
    except Refuse as e:
        ok(f"uncovered 0x{v:08X}..0x{v + 4:08X}" in str(e), f"control 0x{v:08X} refused ({str(e).splitlines()[0]})")
    finally:
        cand["vram"] = v
    if fails:
        print(f"CORPUS SELF-TEST FAIL {len(fails)}")
        return 1
    print("CORPUS CONTROL OK")
    return 0


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    g = ap.add_mutually_exclusive_group(required=True)
    g.add_argument("--all", action="store_true")
    g.add_argument("--prog")
    g.add_argument("--self-test", action="store_true")
    g.add_argument("--c-names", action="store_true")
    a = ap.parse_args()
    os.chdir(os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", ".."))
    try:
        if a.c_names:
            for n in sorted(fleet_c_names()):
                print(n)
            return 0
        if a.self_test:
            return self_test()
        progs = programs()
        if a.prog and a.prog not in progs:
            raise Refuse(f"REFUSE {a.prog} no config/{a.prog}.yaml")
        res = corpus([a.prog] if a.prog else progs)
        write(res)
        summary(res)
        return 0
    except Refuse as e:
        print(e)
        return 1


if __name__ == "__main__":
    sys.exit(main())
