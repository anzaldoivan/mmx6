#!/usr/bin/env python3
"""journal.py -- the campaign journal: one record per drafting attempt, append-only (container, stdlib only).

  journal.py --append <json>      validate, set prev, append; rc 1 + `JOURNAL REFUSED <why>` (file untouched)
  journal.py --for <pv>           that pv's records (JSON lines), last `JOURNAL FOR <pv> <k> records`
  journal.py --rate [--wave W<n>] `RATE <bin> drafted <d> banked <b> instructions <i>` for all five bins
  journal.py --check              `JOURNAL OK <r> records` rc 0 | `JOURNAL BAD <line> <why>` rc 1
  journal.py --self-test          planted journal in .run/journal-selftest/; ends `JOURNAL CONTROL OK`
  --journal <path> overrides campaign/journal.jsonl.

Record keys exactly {wave, pv, func, words, band, runs, verdict, score, label, draft, lever, notes, prev}; prev =
sha1 of the previous line's text (40 zeros first), the append-only check (the container has no .git). band from
words: le16|17-40|41-80|81-160|gt160. notes: our prose, <= 400 chars, never MIPS register operands, `.word` or
`glabel` (G12).
"""
import argparse
import hashlib
import json
import os
import re
import shutil
import sys

JOURNAL = "campaign/journal.jsonl"
SELFTEST = ".run/journal-selftest"
KEYS = ("wave", "pv", "func", "words", "band", "runs", "verdict", "score", "label", "draft", "lever", "notes", "prev")
BINS = ("le16", "17-40", "41-80", "81-160", "gt160")
VERDICTS = ("banked", "fail", "nocompile", "verbatim", "missing", "plumbing")
ZERO = "0" * 40
PV_RE = re.compile(r"[^\s:]+:0x[0-9A-Fa-f]{8}")
REG_RE = re.compile(r"\$(?:zero|at|v[01]|a[0-3]|t[0-9]|s[0-8]|k[01]|gp|sp|fp|ra|[0-9]|[12][0-9]|3[01])\b")
ASM_RE = re.compile(r"\.word\b|\bglabel\b")


def band(words):
    for hi, b in ((16, "le16"), (40, "17-40"), (80, "41-80"), (160, "81-160")):
        if words <= hi:
            return b
    return "gt160"


def path_or_dash(v):
    return isinstance(v, str) and v != "" and not any(c.isspace() for c in v)


def why_bad(r):
    """None when record r (prev included) is well-formed, else the reason."""
    if not isinstance(r, dict):
        return "not an object"
    if set(r) != set(KEYS):
        miss, extra = sorted(set(KEYS) - set(r)), sorted(set(r) - set(KEYS))
        return f"keys missing {','.join(miss) or '-'} extra {','.join(extra) or '-'}"
    if not (isinstance(r["wave"], str) and re.fullmatch(r"W\d+|W-[a-z]+", r["wave"])):
        return "wave not W<n>"
    if not (isinstance(r["pv"], str) and PV_RE.fullmatch(r["pv"])):
        return "pv not <prog>:0x<vram>"
    if not (isinstance(r["func"], str) and re.fullmatch(r"[A-Za-z_]\w*", r["func"])):
        return "func not an identifier"
    for k in ("words", "runs"):
        if not isinstance(r[k], int) or isinstance(r[k], bool) or r[k] < (1 if k == "words" else 0):
            return f"{k} not a count"
    if r["band"] != band(r["words"]):
        return f"band {r['band']} disagrees with words {r['words']} ({band(r['words'])})"
    if r["verdict"] not in VERDICTS:
        return f"verdict not in {'|'.join(VERDICTS)}"
    if not (isinstance(r["score"], str) and re.fullmatch(r"\d+/\d+|-", r["score"])):
        return "score not m/n or -"
    for k in ("label", "draft", "lever"):
        if not path_or_dash(r[k]):
            return f"{k} not a token or -"
    n = r["notes"]
    if not isinstance(n, str) or len(n) > 400:
        return "notes not prose of <= 400 chars"
    if REG_RE.search(n) or ASM_RE.search(n):
        return "notes hold asm text (register operand, .word or glabel; G12)"
    if not (isinstance(r["prev"], str) and re.fullmatch(r"[0-9a-f]{40}", r["prev"])):
        return "prev not a sha1"
    return None


def lines_of(path):
    if not os.path.isfile(path):
        return []
    with open(path, encoding="utf-8") as f:
        return f.read().split("\n")[:-1] if os.path.getsize(path) else []


def sha1(text):
    return hashlib.sha1(text.encode("utf-8")).hexdigest()


def check(path, say):
    lines = lines_of(path)
    if os.path.isfile(path) and os.path.getsize(path) and not open(path, encoding="utf-8").read().endswith("\n"):
        say(f"JOURNAL BAD {len(lines) + 1} no trailing newline")
        return 1
    prev = ZERO
    for i, line in enumerate(lines, 1):
        try:
            r = json.loads(line)
        except ValueError:
            say(f"JOURNAL BAD {i} not JSON")
            return 1
        why = why_bad(r)
        if why is None and r["prev"] != prev:
            why = "prev is not the sha1 of the line before (an earlier line was edited)"
        if why:
            say(f"JOURNAL BAD {i} {why}")
            return 1
        prev = sha1(line)
    say(f"JOURNAL OK {len(lines)} records")
    return 0


def append(path, text, say):
    try:
        r = json.loads(text)
    except ValueError:
        say("JOURNAL REFUSED not JSON")
        return 1
    if isinstance(r, dict):
        r = dict(r)
        r.pop("prev", None)
    lines = lines_of(path)
    if isinstance(r, dict):
        r["prev"] = sha1(lines[-1]) if lines else ZERO
    why = why_bad(r)
    if why:
        say(f"JOURNAL REFUSED {why}")
        return 1
    if check(path, lambda s: None):
        say("JOURNAL REFUSED the journal fails --check")
        return 1
    os.makedirs(os.path.dirname(path) or ".", exist_ok=True)
    with open(path, "a", encoding="utf-8") as f:
        f.write(json.dumps({k: r[k] for k in KEYS}, separators=(", ", ": ")) + "\n")
    say(f"JOURNAL APPENDED {r['pv']} {r['verdict']}")
    return 0


def records(path):
    return [json.loads(line) for line in lines_of(path)]


def for_pv(path, pv, say):
    rows = [line for line in lines_of(path) if json.loads(line)["pv"] == pv]
    for line in rows:
        say(line)
    say(f"JOURNAL FOR {pv} {len(rows)} records")
    return 0


def rate(path, wave, say):
    drafted = {b: set() for b in BINS}
    banked = {b: {} for b in BINS}
    for r in records(path):
        if (r["wave"] != wave) if wave else not re.fullmatch(r"W\d+", r["wave"]):  # no --wave: numbered waves only
            continue
        drafted[r["band"]].add(r["pv"])
        if r["verdict"] == "banked":
            banked[r["band"]][r["pv"]] = r["words"]
    out = {}
    for b in BINS:
        out[b] = (len(drafted[b]), len(banked[b]), sum(banked[b].values()))
        say(f"RATE {b} drafted {out[b][0]} banked {out[b][1]} instructions {out[b][2]}")
    return out


def self_test():
    shutil.rmtree(SELFTEST, ignore_errors=True)
    os.makedirs(SELFTEST)
    path = os.path.join(SELFTEST, "journal.jsonl")
    out, ok = [], True

    def fail(msg):
        nonlocal ok
        ok = False
        print(f"SELFTEST FAIL {msg}")

    def rec(**kw):
        r = dict(wave="W1", pv="P:0x80010000", func="func_80010000", words=12, band="le16", runs=1, verdict="fail",
                 score="10/12", label="regalloc", draft="waves/W1/P_func_80010000/draft.c", lever="-",
                 notes="loop counter kept in a register too early")
        r.update(kw)
        return json.dumps(r)

    if append(path, rec(), out.append) != 0 or check(path, out.append) != 0:
        fail(f"good append: {out[-2:]}")
    before = open(path, "rb").read()
    bad = {
        "missing key": json.dumps({k: v for k, v in json.loads(rec()).items() if k != "label"}),
        "extra key": rec(extra=1),
        "band mismatch": rec(words=50),
        "verdict": rec(verdict="maybe"),
        "score": rec(score="12"),
        "wave": rec(wave="1"),
        "pv": rec(pv="P:80010000"),
        "lever": rec(lever=""),
        "notes length": rec(notes="x" * 401),
        "notes register": rec(notes="spilled $a0 to the stack"),
        "notes register sp": rec(notes="frame uses $sp + 0x18"),
        "notes .word": rec(notes="tail is a .word table"),
        "notes glabel": rec(notes="glabel at the top"),
        "not json": "{",
    }
    for name, text in bad.items():
        o = []
        if append(path, text, o.append) != 1 or not o[-1].startswith("JOURNAL REFUSED"):
            fail(f"refusal {name}: {o}")
        if open(path, "rb").read() != before:
            fail(f"refusal {name} touched the file")
    plant = [rec(pv="P:0x80010000", words=12, band="le16", verdict="banked", score="12/12"),
             rec(pv="P:0x80020000", words=30, band="17-40", verdict="fail"),
             rec(pv="P:0x80020000", words=30, band="17-40", verdict="banked", score="30/30", wave="W2"),
             rec(pv="P:0x80030000", words=200, band="gt160", verdict="nocompile", score="-")]
    for t in plant:
        if append(path, t, out.append) != 0:
            fail(f"plant: {out[-1]}")
    o = []
    got = rate(path, None, o.append)
    want = {"le16": (1, 1, 12), "17-40": (1, 1, 30), "41-80": (0, 0, 0), "81-160": (0, 0, 0), "gt160": (1, 0, 0)}
    if got != want or len(o) != 5:
        fail(f"rate {got}")
    got = rate(path, "W2", lambda s: None)
    if got["17-40"] != (1, 1, 30) or got["le16"] != (0, 0, 0):
        fail(f"rate --wave W2 {got}")
    o = []
    for_pv(path, "P:0x80020000", o.append)
    if o[-1] != "JOURNAL FOR P:0x80020000 2 records" or len(o) != 3:
        fail(f"for {o[-1:]}")
    o = []
    if check(path, o.append) != 0 or o[-1] != "JOURNAL OK 5 records":
        fail(f"check {o}")
    lines = open(path, encoding="utf-8").read().split("\n")
    lines[1] = lines[1].replace('"runs": 1', '"runs": 2')
    with open(path, "w", encoding="utf-8") as f:
        f.write("\n".join(lines))
    o = []
    if check(path, o.append) != 1 or not o[-1].startswith("JOURNAL BAD 3 "):
        fail(f"edited line 2 not caught: {o}")
    print("JOURNAL CONTROL OK" if ok else "JOURNAL CONTROL FAIL")
    return 0 if ok else 1


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n", 1)[0])
    g = ap.add_mutually_exclusive_group(required=True)
    g.add_argument("--append", metavar="JSON")
    g.add_argument("--for", dest="for_pv", metavar="PV")
    g.add_argument("--rate", action="store_true")
    g.add_argument("--check", action="store_true")
    g.add_argument("--self-test", action="store_true")
    ap.add_argument("--wave")
    ap.add_argument("--journal", default=JOURNAL)
    a = ap.parse_args()
    if a.self_test:
        return self_test()
    if a.append is not None:
        return append(a.journal, a.append, print)
    if a.for_pv:
        return for_pv(a.journal, a.for_pv, print)
    if a.rate:
        rate(a.journal, a.wave, print)
        return 0
    return check(a.journal, print)


if __name__ == "__main__":
    sys.exit(main())
