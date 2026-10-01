#!/usr/bin/env python3
"""report.py -- progress, difficulty and dup-payoff reports over the corpus and the census (container, stdlib).

  report.py --progress | --difficulty | --dup | --all
      -> build/reports/{progress,difficulty,dup}.{md,json} (names/addresses there only, G12); stdout counts only,
         every line ending `of <N> functions` / `of <B> bytes` / `of <T> text bytes`, except the progress line, last:
         `REPORT progress c <x> of <N> functions, <y> of <B> bytes; game <xg> of <Ng>, <yg> of <Bg>; lib <xl> of <Nl>,
         <yl> of <Bl>; banks <c> stubs <e>`.
  report.py --self-test
      -> planted corpus (.run/report/selftest, words injected) with hand-derived progress line, difficulty order and
         dup order; planted c->asm mutation moves progress by exactly that function; real-corpus sums. Ends
         `REPORT CONTROL OK` (rc 0), else rc 1.

Inputs: build/corpus/{functions,spans,denominators}.jsonl (corpus.py), build/census/classes.jsonl (census.py); words
of not-yet-C functions via census.read_words (TU object). No typed count: every number is computed from these.
Definitions: matched = state c (banks) + c-empty (empty-body stubs); bytes = 4 * words; remainder = denominator -
matched; per program, per lane (game, lib) and fleet. Text bytes = denominators text_bytes; span bytes by span kind.
difficulty (state asm|include_asm): branch = op 1 (REGIMM), ops 4-7 (beq/bne/blez/bgtz), COPz BC (ops 16-19, rs=8);
call = jal (op 3) + jalr (SPECIAL funct 9); jtbl = any jr (SPECIAL funct 8) with rs != 31. Ranked ascending by
(jtbl, words, branches, calls, prog, vram). dup: census dup classes with >= 2 members, payoff = (members-1) * words,
ranked by (-payoff, -members, key); c_members = members already c|c-empty.
Currency guard: refused (rc 1) if any input is missing or the (prog, vram) set of dup records != the corpus set.
"""
import argparse
import json
import os
import re
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import census  # noqa: E402
from census import JR_RA, SIZE, Refuse, bucket  # noqa: E402

INPUTS = dict(funcs="build/corpus/functions.jsonl", spans="build/corpus/spans.jsonl",
              denoms="build/corpus/denominators.jsonl", classes="build/census/classes.jsonl")
OUT = "build/reports"
SELFTEST = ".run/report/selftest"
MATCHED = ("c", "c-empty")
TODO = ("asm", "include_asm")
STATES = ("c", "c-empty", "asm", "include_asm")
SPAN_KINDS = ("jtbl", "pad", "libgap", "data")
TOP = 50


def jl(path):
    with open(path) as f:
        return [json.loads(line) for line in f if line.strip()]


def load(inp):
    """(rows, spans, denoms, classes) of the input set; Refuse when missing or the census is stale."""
    miss = [p for p in inp.values() if not os.path.isfile(p)]
    if miss:
        raise Refuse("\n".join(f"REFUSE missing {p}" for p in miss))
    rows = sorted(jl(inp["funcs"]), key=lambda r: (r["prog"], int(r["vram"], 16)))
    spans, denoms, cls = jl(inp["spans"]), jl(inp["denoms"]), jl(inp["classes"])
    fset = {(r["prog"], r["vram"]) for r in rows}
    dset = {(p, v) for c in cls if c["kind"] == "dup" for p, v in c["members"]}
    if fset != dset:
        raise Refuse(f"REFUSE stale census: {len(fset - dset)} corpus functions not in dup records, "
                     f"{len(dset - fset)} dup members not in corpus of {len(rows)} functions")
    return rows, spans, denoms, cls


def write(out, name, md, obj):
    os.makedirs(out, exist_ok=True)
    with open(f"{out}/{name}.md", "w") as f:
        f.write("\n".join(md) + "\n")
    with open(f"{out}/{name}.json", "w") as f:
        json.dump(obj, f, indent=1)
        f.write("\n")


# ---- progress --------------------------------------------------------------------------------------------------------

def tally(rows):
    t = dict(n=len(rows), b=4 * sum(r["words"] for r in rows), **{s: 0 for s in STATES})
    for r in rows:
        t[r["state"]] += 1
    m = [r for r in rows if r["state"] in MATCHED]
    t.update(mf=len(m), mb=4 * sum(r["words"] for r in m))
    t.update(rf=t["n"] - t["mf"], rb=t["b"] - t["mb"])
    return t


def progress(rows, spans, denoms):
    progs = sorted({r["prog"] for r in rows} | {d["prog"] for d in denoms})
    sb = {p: {k: 0 for k in SPAN_KINDS} for p in progs}
    for s in spans:
        sb[s["prog"]][s["kind"]] += int(s["hi"], 16) - int(s["lo"], 16)
    text = {d["prog"]: d["text_bytes"] for d in denoms}
    per = {p: dict(tally([r for r in rows if r["prog"] == p]), text=text.get(p, 0), spans=sb[p]) for p in progs}
    lanes = {ln: tally([r for r in rows if r["lane"] == ln]) for ln in ("game", "lib")}
    fleet = tally(rows)
    fleet.update(text=sum(text.values()), spans={k: sum(sb[p][k] for p in progs) for k in SPAN_KINDS})
    return dict(fleet=fleet, lanes=lanes, programs=per)


def progress_line(p):
    f, g, lb = p["fleet"], p["lanes"]["game"], p["lanes"]["lib"]
    return (f"REPORT progress c {f['mf']} of {f['n']} functions, {f['mb']} of {f['b']} bytes; "
            f"game {g['mf']} of {g['n']}, {g['mb']} of {g['b']}; lib {lb['mf']} of {lb['n']}, {lb['mb']} of {lb['b']}; "
            f"banks {f['c']} stubs {f['c-empty']}")


def progress_lines(p):
    out = []
    for name, t in list(p["lanes"].items()) + [("fleet", p["fleet"])]:
        out.append(f"REPORT progress {name} matched {t['mf']} (banks {t['c']} stubs {t['c-empty']}) "
                   f"remaining {t['rf']} (asm {t['asm']} include_asm {t['include_asm']}) of {t['n']} functions")
        out.append(f"REPORT progress {name} matched {t['mb']} remaining {t['rb']} of {t['b']} bytes")
    f = p["fleet"]
    sp = " ".join(f"{k} {f['spans'][k]}" for k in SPAN_KINDS)
    out.append(f"REPORT text functions {f['b']} spans {sp} of {f['text']} text bytes")
    return out


def progress_md(p):
    hdr = "| {} | matched fn | of N | remaining fn | banks (c) | stubs (c-empty) | asm | include_asm | " \
          "matched bytes | of B | remaining bytes |"
    sep = "|---" * 11 + "|"

    def row(name, t):
        return (f"| {name} | {t['mf']} | {t['n']} | {t['rf']} | {t['c']} | {t['c-empty']} | {t['asm']} | "
                f"{t['include_asm']} | {t['mb']} | {t['b']} | {t['rb']} |")
    md = ["# Progress", "", "matched = c + c-empty; bytes = 4 * words; remaining = denominator - matched.", "",
          "## Fleet and lanes", "", hdr.format("group"), sep]
    md += [row(n, t) for n, t in list(p["lanes"].items()) + [("fleet", p["fleet"])]]
    md += ["", "## Programs", "", hdr.format("program"), sep] + [row(n, t) for n, t in p["programs"].items()]
    md += ["", "## Text bytes", "", "| program | text bytes | function bytes | " + " | ".join(SPAN_KINDS) + " |",
           "|---" * (3 + len(SPAN_KINDS)) + "|"]
    for n, t in list(p["programs"].items()) + [("fleet", p["fleet"])]:
        md.append(f"| {n} | {t['text']} | {t['b']} | " + " | ".join(str(t["spans"][k]) for k in SPAN_KINDS) + " |")
    return md


# ---- difficulty ------------------------------------------------------------------------------------------------------

def shape(words):
    """(branches, calls, jtbl) of a function's words."""
    br = ca = jt = 0
    for w in words:
        op, rs = w >> 26, (w >> 21) & 0x1F
        if op == 1 or 4 <= op <= 7 or (16 <= op <= 19 and rs == 8):
            br += 1
        elif op == 3 or (op == 0 and w & 0x3F == 9):
            ca += 1
        elif op == 0 and w & 0x3F == 8 and rs != 31:
            jt = 1
    return br, ca, jt


def difficulty(rows, words):
    """Ranked not-yet-C functions; words: {(prog, vram): [word, ...]}."""
    out = []
    for r in rows:
        if r["state"] not in TODO:
            continue
        br, ca, jt = shape(words[(r["prog"], r["vram"])])
        out.append(dict(prog=r["prog"], vram=r["vram"], name=r["name"], state=r["state"], lane=r["lane"],
                        words=r["words"], branches=br, calls=ca, jtbl=jt))
    out.sort(key=lambda d: (d["jtbl"], d["words"], d["branches"], d["calls"], d["prog"], int(d["vram"], 16)))
    for i, d in enumerate(out, 1):
        d["rank"] = i
    return out


def todo_words(rows):
    todo = [r for r in rows if r["state"] in TODO]
    return {(r["prog"], r["vram"]): w for r, (w, _) in zip(todo, census.read_words(todo))}


def difficulty_out(diff, n):
    hist = [[0, 0] for _ in SIZE]
    for d in diff:
        hist[bucket(d["words"], SIZE)][d["jtbl"]] += 1
    lines = [f"REPORT difficulty todo {len(diff)} jtbl {sum(d['jtbl'] for d in diff)} of {n} functions"]
    for j in (0, 1):
        h = " ".join(f"{SIZE[i][2]} {c[j]}" for i, c in enumerate(hist))
        lines.append(f"REPORT difficulty jtbl={j} {h} of {n} functions")
    md = ["# Difficulty", "", "Not-yet-C functions (asm, include_asm), easiest first by (jtbl, words, branches, calls, "
          "prog, vram).", "", "## Size x jtbl", "", "| words | no jtbl | jtbl |", "|---|---|---|"]
    md += [f"| {SIZE[i][2]} | {c[0]} | {c[1]} |" for i, c in enumerate(hist)]
    md += ["", f"## Top {TOP}", "", "| rank | prog | vram | name | state | lane | words | branches | calls | jtbl |",
           "|---" * 10 + "|"]
    md += [f"| {d['rank']} | {d['prog']} | {d['vram']} | {d['name']} | {d['state']} | {d['lane']} | {d['words']} | "
           f"{d['branches']} | {d['calls']} | {d['jtbl']} |" for d in diff[:TOP]]
    return lines, md


# ---- dup -------------------------------------------------------------------------------------------------------------

def dup(rows, cls):
    state = {(r["prog"], r["vram"]): r["state"] for r in rows}
    out = []
    for c in cls:
        if c["kind"] != "dup" or len(c["members"]) < 2:
            continue
        m = len(c["members"])
        out.append(dict(key=c["key"], size=c["size"], members=m, payoff=(m - 1) * c["size"], reach=c["reach"],
                        c_members=sum(1 for p, v in c["members"] if state[(p, v)] in MATCHED),
                        member_list=c["members"]))
    out.sort(key=lambda d: (-d["payoff"], -d["members"], d["key"]))
    for i, d in enumerate(out, 1):
        d["rank"] = i
    return out


def dup_out(dp, n, b):
    mem = sum(d["members"] for d in dp)
    pay = sum(d["payoff"] for d in dp)
    lines = [f"REPORT dup classes {len(dp)} members {mem} c_members {sum(d['c_members'] for d in dp)} "
             f"payoff_functions {mem - len(dp)} of {n} functions",
             f"REPORT dup payoff {4 * pay} of {b} bytes"]
    md = ["# Dup payoff", "", "Dup classes with >= 2 members; payoff = (members-1) * words, descending.", "",
          "| rank | key | words | members | payoff words | reach | c members |", "|---" * 7 + "|"]
    md += [f"| {d['rank']} | {d['key'][:12]} | {d['size']} | {d['members']} | {d['payoff']} | {d['reach']} | "
           f"{d['c_members']} |" for d in dp]
    return lines, md


# ---- run -------------------------------------------------------------------------------------------------------------

def run(inp, out, want, words=None):
    """Writes the wanted reports under out; returns (stdout lines, progress dict, difficulty, dup)."""
    rows, spans, denoms, cls = load(inp)
    p = progress(rows, spans, denoms)
    n, b = p["fleet"]["n"], p["fleet"]["b"]
    lines, diff, dp = [], None, None
    if "difficulty" in want:
        diff = difficulty(rows, words if words is not None else todo_words(rows))
        ln, md = difficulty_out(diff, n)
        write(out, "difficulty", md, diff)
        lines += ln
    if "dup" in want:
        dp = dup(rows, cls)
        ln, md = dup_out(dp, n, b)
        write(out, "dup", md, dp)
        lines += ln
    if "progress" in want:
        write(out, "progress", progress_md(p), p)
        lines += progress_lines(p) + [progress_line(p)]
    return lines, p, diff, dp


# ---- self-test -------------------------------------------------------------------------------------------------------

BEQ, BLTZ, JAL, J, MFC0 = 4 << 26, 1 << 26, 3 << 26, 2 << 26, 16 << 26
BC1T, BC0F = (17 << 26) | (8 << 21) | (1 << 16), (16 << 26) | (8 << 21)
JALR, JR_V0 = (2 << 21) | (31 << 11) | 9, (2 << 21) | 8
# (prog, vram, name, state, lane, words)
PLANT = (("pa", "0x80010000", "f1", "c", "game", [0, 0, JR_RA, 0]),
         ("pa", "0x80010010", "f2", "c-empty", "game", [JR_RA, 0]),
         ("pa", "0x80010018", "f3", "asm", "game", [BEQ, 0, JAL, 0, JR_RA, 0]),
         ("pa", "0x80010030", "f4", "include_asm", "game", [JR_V0, 0, MFC0, J]),
         ("pb", "0x80020000", "g1", "asm", "lib", [BEQ, 0, JAL, 0, JR_RA, 0]),
         ("pb", "0x80020018", "g2", "asm", "lib", [JR_RA, 0]),
         ("pb", "0x80020020", "g3", "asm", "lib", [BLTZ, 0, BC1T, 0, BC0F, JALR, 0, JR_RA, 0]))
PLANT_DUPS = (("k1", 6, [["pa", "0x80010018"], ["pb", "0x80020000"]], 2),
              ("k2", 2, [["pa", "0x80010010"], ["pb", "0x80020018"]], 2),
              ("k3", 4, [["pa", "0x80010000"]], 1), ("k4", 4, [["pa", "0x80010030"]], 1),
              ("k5", 9, [["pb", "0x80020020"]], 1))
# hand-derived: pa 4 fns 16 words (matched f1 4 + f2 2 = 6 words), pb 3 fns 17 words, none matched
PLANT_LINE = ("REPORT progress c 2 of 7 functions, 24 of 132 bytes; game 2 of 4, 24 of 64; lib 0 of 3, 0 of 68; "
              "banks 1 stubs 1")
PLANT_DIFF = ["g2", "f3", "g1", "g3", "f4"]  # (jtbl, words, branches, calls, prog): g3 3 br 1 call; f4 jtbl
PLANT_DUP = [("k1", 6, 0), ("k2", 2, 1)]     # (key, payoff, c_members)


def plant(d, rows, dups):
    os.makedirs(d, exist_ok=True)
    inp = {k: f"{d}/{os.path.basename(v)}" for k, v in INPUTS.items()}

    def jw(path, recs):
        with open(path, "w") as f:
            f.writelines(json.dumps(r) + "\n" for r in recs)
    jw(inp["funcs"], [dict(prog=p, vram=v, end=hex(int(v, 16) + 4 * len(w)), words=len(w), name=n, tu="plant",
                           state=s, lane=ln, src="glabel") for p, v, n, s, ln, w in rows])
    jw(inp["spans"], [dict(prog="pa", lo="0x80010040", hi="0x80010048", kind="pad"),
                      dict(prog="pb", lo="0x80020044", hi="0x80020050", kind="jtbl")])
    jw(inp["denoms"], [dict(prog="pa", text_lo="0x80010000", text_hi="0x80010048", text_bytes=72, **{"from": "x"}),
                       dict(prog="pb", text_lo="0x80020000", text_hi="0x80020050", text_bytes=80, **{"from": "x"})])
    jw(inp["classes"], [dict(kind="dup", key=k, size=s, members=m, reach=r) for k, s, m, r in dups]
       + [dict(kind="family", key="fa", size=6, members=[["pa", "0x80010018"]], reach=1)])
    return inp


def self_test():
    fails = []

    def ok(cond, what):
        print(f"REPORT CONTROL {'ok' if cond else 'FAIL'} {what}")
        if not cond:
            fails.append(what)

    words = {(p, v): w for p, v, _, _, _, w in PLANT}
    out = f"{SELFTEST}/reports"
    inp = plant(SELFTEST, PLANT, PLANT_DUPS)
    lines, p, diff, dp = run(inp, out, ("progress", "difficulty", "dup"), words)
    ok(lines[-1] == PLANT_LINE, "planted progress line exact")
    ok([d["name"] for d in diff] == PLANT_DIFF, "planted difficulty order exact")
    ok([(d["key"], d["payoff"], d["c_members"]) for d in dp] == PLANT_DUP, "planted dup order exact")
    ok(all(re.search(r" of \d+ (functions|bytes|text bytes)$", ln) for ln in lines[:-1]),
       "planted stdout lines end with a denominator")
    mut = [(pp, v, n, "asm" if n == "f1" else s, ln, w) for pp, v, n, s, ln, w in PLANT]
    _, q, _, _ = run(plant(f"{SELFTEST}/mut", mut, PLANT_DUPS), f"{SELFTEST}/mut/reports", ("progress",))
    a, b = p["fleet"], q["fleet"]
    ok((a["mf"] - b["mf"], a["mb"] - b["mb"], a["c"] - b["c"], a["n"], a["b"]) == (1, 16, 1, b["n"], b["b"]),
       "planted c->asm flip moves progress by exactly 1 function, 16 bytes")
    try:
        load(plant(f"{SELFTEST}/stale", PLANT, PLANT_DUPS[:-1]))
        ok(False, "stale census refused")
    except Refuse:
        ok(True, "stale census refused")

    rows, spans, denoms, cls = load(INPUTS)
    rp = progress(rows, spans, denoms)
    per = rp["programs"].values()
    fb = 4 * sum(r["words"] for r in rows)
    ok(sum(t["n"] for t in per) == len(rows) and sum(t["b"] for t in per) == fb,
       f"real per-program N, B sum to {len(rows)} functions, {fb} bytes")
    f = rp["fleet"]
    ok(sum(f[s] for s in STATES) == f["n"], f"real c+c-empty+asm+include_asm = {f['n']}")
    bad = [n for n, t in rp["programs"].items() if t["b"] + sum(t["spans"].values()) != t["text"]]
    ok(not bad, f"real function bytes + span bytes = text bytes in {len(per) - len(bad)} of {len(per)} programs")
    dsum = sum(len(c["members"]) for c in cls if c["kind"] == "dup")
    ok(dsum == len(rows), f"real dup members {dsum} = {len(rows)} functions")
    if fails:
        print(f"REPORT CONTROL FAIL {len(fails)}")
        return 1
    print("REPORT CONTROL OK")
    return 0


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    g = ap.add_mutually_exclusive_group(required=True)
    for k in ("progress", "difficulty", "dup", "all", "self-test"):
        g.add_argument(f"--{k}", action="store_true")
    a = ap.parse_args()
    try:
        if a.self_test:
            sys.exit(self_test())
        want = ("progress", "difficulty", "dup") if a.all else \
            tuple(k for k in ("progress", "difficulty", "dup") if getattr(a, k))
        print("\n".join(run(INPUTS, OUT, want)[0]))
        sys.exit(0)
    except Refuse as e:
        print(e)
        sys.exit(1)


if __name__ == "__main__":
    main()
