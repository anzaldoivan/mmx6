#!/usr/bin/env python3
"""harness.py -- the differential harness: one question answered by two existing instruments (container, stdlib only).

  harness.py --sampled   pairs P1 P2 P4 P5 P6 P7
  harness.py --full      all seven pairs (adds P3: touch + rebuild)
      -> appends to build/harness/runs.log, and prints, one line per pair
         `<utc> P<n> <question> AGREE|DISAGREE|NOT-RUN <a> <b> of <N> <unit>`, then
         `HARNESS <d> disagreements in <p> pairs`; d counts DISAGREE and NOT-RUN (an instrument that raises or
         lacks its input); rc 0 iff d = 0.
  harness.py --self-test
      -> per pair one disagreement planted in memory into one instrument's result must be DISAGREE; a pair whose
         instrument raises must be NOT-RUN and counted; log .run/harness/selftest.log (never runs.log); ends
         `HARNESS CONTROL OK` (rc 0), else rc 1.

Pairs (A vs B; each side calls an existing instrument, never re-implements it, G33):
  P1 matched?    corpus.parse_c C definitions (all programs) vs corpus.fleet_c_names() (object FUNC symbols); names.
  P2 compiles?   per corpus `c` function: probe.compile_obj of its config/probes.txt `banked` src under the Makefile
                 TRIPLE + probe.elf_function vs the words of build/<p>.elf at the corpus extent, under probe's
                 relocation mask (both trimmed by probe.trim).
  P3 fleet?      sha1 of every BINS output now vs after `touch` of src/SLUS_013.95/120A0.c and one asm unit and
                 `make -s build`; NOT-RUN if either unit's .o was not rebuilt (mtime).
  P4 coverage?   optscan.parse_dir (carve_dir fallback, as optscan.scan) per-program count vs optscan.corpus_counts.
  P5 boundaries? build/corpus (bound2.load_inputs) vs build/bound2/<p>.jsonl through bound2.account with the ledger;
                 AGREE iff phantoms = truncations = 0.
  P6 programs?   config/*.yaml stems (corpus.programs) vs config/loadmap.txt `N = <k>` vs config/ghidra/*.jsonl stems.
  P7 stubs?      corpus c-empty rows + asm|include_asm rows whose optscan.parse_dir words are `jr $ra; nop` vs the
                 members of the census dup class of `jr $ra; nop` (build/census/classes.jsonl); (prog, vram) sets.
Firewall G12: names, counts and hashes of build outputs only; never words or bytes.
"""
import argparse
import datetime
import glob
import hashlib
import json
import os
import re
import struct
import subprocess
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import bound2  # noqa: E402
import census  # noqa: E402
import corpus  # noqa: E402
import optscan  # noqa: E402
import probe  # noqa: E402

RUNS = "build/harness/runs.log"
SELFLOG = ".run/harness/selftest.log"
FUNCS = "build/corpus/functions.jsonl"
CLASSES = "build/census/classes.jsonl"
JR_NOP = [probe.JR_RA, 0]
P3_C = "src/SLUS_013.95/120A0.c"
SAMPLED = [1, 2, 4, 5, 6, 7]
FULL = [1, 2, 3, 4, 5, 6, 7]


class NotRun(Exception):
    pass


def rows():
    if not os.path.isfile(FUNCS):
        raise NotRun(f"missing {FUNCS}")
    with open(FUNCS) as f:
        return [json.loads(x) for x in f if x.strip()]


_parsed = {}


def parsed(p):
    """optscan's own parser over asm/<p> (carve_dir fallback, as optscan.scan)."""
    if p not in _parsed:
        root = f"asm/{p}"
        if not os.path.isdir(root):
            raise NotRun(f"no {root}/")
        funcs = optscan.parse_dir(root)
        _parsed[p] = funcs if funcs else optscan.carve_dir(root)[0]
    return _parsed[p]


# ---- pairs: gather(A, B, ctx) and compare -> (agree, a, b, N, unit) ----------------------------------------------------

def p1_gather():
    a = set()
    for p in corpus.programs():
        a |= set(corpus.parse_c(p)[0])
    return a, corpus.fleet_c_names(), len(rows())


def p1_compare(a, b, n):
    return a == b, len(a), len(b), n, "functions"


def makefile_triple():
    with open("Makefile") as f:
        m = re.search(r"^TRIPLE \?= (\S+)", f.read(), re.M)
    if not m:
        raise NotRun("no `TRIPLE ?=` in Makefile")
    return m.group(1)


def linked_words(elf, lo, hi):
    """Words [lo, hi) of the linked ELF32 LE at elf, from the PROGBITS section holding them."""
    with open(elf, "rb") as f:
        b = f.read()
    shoff, = struct.unpack_from("<I", b, 0x20)
    shentsize, shnum = struct.unpack_from("<HH", b, 0x2E)
    for i in range(shnum):
        s = struct.unpack_from("<10I", b, shoff + i * shentsize)
        if s[1] == 1 and s[3] <= lo and hi <= s[3] + s[5]:
            return list(struct.unpack_from(f"<{(hi - lo) // 4}I", b, s[4] + lo - s[3]))
    raise NotRun(f"{elf}: no section holds 0x{lo:08X}..0x{hi:08X}")


def p2_gather():
    triple = makefile_triple()
    src = {(t[1], t[0]): t[2] for t in (r.split() for r in probe.read_rows("config/probes.txt")) if t[-1] == "banked"}
    out = []
    cs = [r for r in rows() if r["state"] == "c"]
    for r in cs:
        key = (r["prog"], r["name"])
        if key not in src:
            raise NotRun(f"{r['prog']} {r['name']} has no banked row in config/probes.txt")
        obj = probe.compile_obj(src[key], triple)
        if obj is None:
            raise NotRun(f"{src[key]} does not compile under {triple}")
        ours, masks = probe.elf_function(obj, r["name"])
        linked = probe.trim(linked_words(f"build/{r['prog']}.elf", int(r["vram"], 16), int(r["end"], 16)))
        out.append((r["name"], ours, masks, linked))
    if not out:
        raise NotRun("no corpus `c` function")
    return out, len(cs)


def p2_compare(fs, n):
    good = 0
    for _, ours, masks, linked in fs:
        keep = [~masks.get(i, 0) & 0xFFFFFFFF for i in range(len(ours))]
        good += len(ours) == len(linked) and all((x & k) == (y & k) for x, y, k in zip(ours, linked, keep))
    return good == len(fs), good, len(fs), n, "c functions"


def bins_sha1():
    out = {}
    for p in corpus.programs():
        path = f"build/rock/{p[5:]}.bin" if p.startswith("rock_") else f"build/{p}"
        if os.path.isfile(path):
            with open(path, "rb") as f:
                out[path] = hashlib.sha1(f.read()).hexdigest()
        else:
            out[path] = None
    return out


def p3_asm_unit():
    s = sorted(glob.glob("asm/SLUS_013.95/*.s"))
    if not s:
        raise NotRun("no asm/SLUS_013.95/*.s")
    return s[0]


def p3_gather():
    units = [P3_C, p3_asm_unit()]
    objs = [f"build/{u}.o" for u in units]
    before = bins_sha1()
    for o in objs:
        if not os.path.isfile(o):
            raise NotRun(f"missing {o}")
    mt = [os.stat(o).st_mtime_ns for o in objs]
    for u in units:
        os.utime(u)
    subprocess.run(["make", "-s", "build"], stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
    for o, t in zip(objs, mt):
        if not os.path.isfile(o) or os.stat(o).st_mtime_ns <= t:
            raise NotRun(f"{o} not rebuilt after touch")
    return before, bins_sha1()


def p3_compare(before, after):
    same = sum(1 for k, v in before.items() if v is not None and after.get(k) == v)
    return before == after and None not in before.values(), same, len(after), len(before), "binaries"


def p4_gather():
    want = optscan.corpus_counts()
    if want is None:
        raise NotRun(f"missing {FUNCS}")
    return {p: len(parsed(p)) for p in optscan.all_progs()}, want


def p4_compare(a, b):
    return a == b, sum(a.values()), sum(b.values()), sum(b.values()), "asm functions"


def p5_gather():
    dens, inv, spans, _ = bound2.load_inputs()
    b2 = {}
    for p in sorted(dens):
        path = f"{bound2.OUT}/{p}.jsonl"
        if not os.path.isfile(path):
            raise NotRun(f"missing {path}")
        with open(path) as f:
            b2[p] = {int(r["vram"], 16): (int(r["end"], 16) if r["end"] else None, r["basis"])
                     for r in (json.loads(x) for x in f if x.strip())}
    return sorted(dens), inv, spans, bound2.load_jtbl(), b2, bound2.load_ledger()


def p5_compare(names, inv, spans, jt, b2, ledger):
    r = bound2.account(names, inv, spans, jt, b2, ledger)
    return r["ph"] == r["tr"] == 0, f"phantoms={r['ph']}", f"truncations={r['tr']}", r["nfun"], "functions"


def p6_gather():
    with open("config/loadmap.txt") as f:
        m = re.search(r"^N = ([0-9]+)$", f.read(), re.M)
    if not m:
        raise NotRun("no `N = <k>` in config/loadmap.txt")
    ghidra = sorted(os.path.basename(x)[:-6] for x in glob.glob("config/ghidra/*.jsonl"))
    return corpus.programs(), int(m.group(1)), ghidra


def p6_compare(yaml, n, ghidra):
    return (len(yaml) == n == len(ghidra) and set(yaml) == set(ghidra)), len(yaml), f"{n}/{len(ghidra)}", n, "programs"


def p7_gather():
    rs = rows()
    a = {(r["prog"], r["vram"]) for r in rs if r["state"] == "c-empty"}
    for r in rs:
        if r["state"] in ("asm", "include_asm"):
            f = parsed(r["prog"]).get(int(r["vram"], 16))
            if f is not None and f[2] == JR_NOP:
                a.add((r["prog"], r["vram"]))
    if not os.path.isfile(CLASSES):
        raise NotRun(f"missing {CLASSES}")
    key = census.dup_key(JR_NOP, [0, 0])
    b = set()
    with open(CLASSES) as f:
        for x in f:
            c = json.loads(x) if x.strip() else None
            if c and c["kind"] == "dup" and c["key"] == key:
                b = {(p, v) for p, v in c["members"]}
    return a, b, len(rs)


def p7_compare(a, b, n):
    return a == b, len(a), len(b), n, "functions"


PAIRS = {
    1: ("matched?", p1_gather, p1_compare),
    2: ("compiles?", p2_gather, p2_compare),
    3: ("fleet?", p3_gather, p3_compare),
    4: ("coverage?", p4_gather, p4_compare),
    5: ("boundaries?", p5_gather, p5_compare),
    6: ("programs?", p6_gather, p6_compare),
    7: ("stubs?", p7_gather, p7_compare),
}


def utc():
    return datetime.datetime.now(datetime.timezone.utc).strftime("%Y-%m-%dT%H:%M:%SZ")


def line(n, verdict, a="-", b="-", N="-", unit="-"):
    return f"{utc()} P{n} {PAIRS[n][0]} {verdict} {a} {b} of {N} {unit}"


def judge(n, gather, compare):
    """(line, disagreement?) of one pair; an instrument that raises or lacks input is NOT-RUN."""
    try:
        agree, a, b, N, unit = compare(*gather())
    except (Exception, SystemExit) as e:
        print(f"harness: P{n} NOT-RUN: {type(e).__name__}: {str(e).splitlines()[0] if str(e) else ''}")
        return line(n, "NOT-RUN"), True
    return line(n, "AGREE" if agree else "DISAGREE", a, b, N, unit), not agree


def emit(lines, path):
    os.makedirs(os.path.dirname(path), exist_ok=True)
    with open(path, "a") as f:
        for x in lines:
            f.write(x + "\n")
            print(x, flush=True)


def run(sel):
    lines, d = [], 0
    for n in sel:
        ln, bad = judge(n, PAIRS[n][1], PAIRS[n][2])
        lines.append(ln)
        d += bad
    lines.append(f"HARNESS {d} disagreements in {len(sel)} pairs")
    emit(lines, RUNS)
    return 1 if d else 0


# ---- self-test: one planted disagreement per pair, in memory --------------------------------------------------------

def plant(n, g):
    """g = the pair's real gather result; returns it with one disagreement planted into one instrument's result."""
    if n == 1:
        return g[0] | {"harness_plant"}, g[1], g[2]
    if n == 2:
        fs, N = g
        name, ours, masks, linked = fs[0]
        return [(name, [ours[0] ^ 0x80000000] + ours[1:], masks, linked)] + fs[1:], N
    if n == 3:
        before, after = g
        k = sorted(after)[0]
        return before, dict(after, **{k: "0" * 40})
    if n == 4:
        a, b = g
        p = sorted(b)[0]
        return a, dict(b, **{p: b[p] + 1})
    if n == 5:
        names, inv, spans, jt, b2, ledger = g
        p = next(p for p in names if any(e - v >= 8 for v, e, _ in inv.get(p, [])))
        v, e, _ = next(f for f in sorted(inv[p]) if f[1] - f[0] >= 8)
        return names, dict(inv, **{p: inv[p] + [(v + 4, e, "harness_plant")]}), spans, jt, b2, ledger
    if n == 6:
        return g[0] + ["harness_plant"], g[1], g[2]
    if n == 7:
        a, b, N = g
        return a, b - {sorted(b)[0]}, N


def self_test():
    lines, fails = [], []

    def ok(cond, what):
        lines.append(f"HARNESS CONTROL {'ok' if cond else 'FAIL'} {what}")
        if not cond:
            fails.append(what)

    for n in FULL:
        q, gather, compare = PAIRS[n]
        if n == 3:  # no rebuild in the control: B = the current outputs' sha1, then one planted
            gather = lambda: (bins_sha1(), bins_sha1())  # noqa: E731
        try:
            g = gather()
            real = compare(*g)[0]
        except (Exception, SystemExit) as e:
            ok(False, f"P{n} {q} gather raised {type(e).__name__}")
            continue
        ln, bad = judge(n, lambda: plant(n, g), compare)
        lines.append(ln)
        ok(bad and " DISAGREE " in ln, f"P{n} {q} planted disagreement -> DISAGREE (unplanted {'AGREE' if real else 'DISAGREE'})")

    def raises():
        raise NotRun("planted: instrument raised")

    ln, bad = judge(1, raises, p1_compare)
    lines.append(ln)
    ok(bad and " NOT-RUN " in ln, "NOT-RUN control counted as a disagreement")
    lines.append("HARNESS CONTROL OK" if not fails else f"HARNESS CONTROL FAIL {len(fails)}")
    emit(lines, SELFLOG)
    return 1 if fails else 0


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    g = ap.add_mutually_exclusive_group(required=True)
    g.add_argument("--sampled", action="store_true")
    g.add_argument("--full", action="store_true")
    g.add_argument("--self-test", action="store_true")
    a = ap.parse_args()
    os.chdir(os.path.join(HERE, "..", ".."))
    if a.self_test:
        return self_test()
    return run(FULL if a.full else SAMPLED)


if __name__ == "__main__":
    sys.exit(main())
