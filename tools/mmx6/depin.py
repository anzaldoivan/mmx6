#!/usr/bin/env python3
"""depin.py -- trial-remove the register pins of a matched draft, mark the survivors (T46, container, stdlib only).

  depin.py <prog:0xVRAM> --src <file> [--lever C<nnnn>]
      The function name from build/corpus/functions.jsonl (prog, vram). One snapshot waves/.iso/depin_<func>.<pid>
      (cards.snapshot) for the run; each variant is written to drafts/<prog>/<func>.c inside it and scored with
      cards.score (Makefile TRIPLE, the TU flags of probe.draft_cflags). The input must MATCH, else
      `DEPIN <func> refused <state> <m>/<n>` rc 1 and --src untouched. Then greedy in file order: drop one pin
      (`register T x asm("$n")` -> `T x`, initializer kept; a standalone `// !FAKE:` line directly above goes too),
      re-score, keep the drop iff still match. A survivor with no `!FAKE:` on its line or the line above gets a
      standalone `<indent>// !FAKE: <reason>` line directly above it (never trailing): the --lever id (rc 2 unless a cookbook/INDEX.md row) else
      `depin: dropping it breaks the match (<m>/<n>)` (the score without it). The final text is re-scored and written
      to --src only on match; last line `DEPIN <func> pins <before> to <after>`, rc 0.
  depin.py --self-test  -> planted cases in .run/depin-selftest/ (C0054: planted, never borrowed), scorer = the words
      of the planted pinned body; last `DEPIN CONTROL OK` rc 0, else `DEPIN CONTROL FAIL <case>` rc 1.

Firewall G12: prints names, line numbers and counts only.
"""
import argparse
import json
import os
import re
import shutil
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(os.path.dirname(HERE))
sys.path.insert(0, HERE)
sys.path.insert(0, os.path.dirname(HERE))
import cards  # noqa: E402
import probe  # noqa: E402
import psxd_floor  # noqa: E402  (file_debt: the pin-unmarked debt rule)

SELFTEST = ".run/depin-selftest"
PIN = re.compile(r'\bregister\s+([^;{}=]*?)\s*\b(?:asm|__asm__)\s*\(\s*"\$\d+"\s*\)')
FAKE_LINE = re.compile(r"^\s*//\s*!FAKE:")


def pin_lines(lines):
    return [i for i, ln in enumerate(lines) if ln is not None and PIN.search(ln)]


def text_of(lines):
    return "".join(ln + "\n" for ln in lines if ln is not None)


def marked(lines, i):
    above = next((lines[j] for j in range(i - 1, -1, -1) if lines[j] is not None), None)
    # the line above marks this pin only as a standalone `// !FAKE:` line; another pin's trailing comment does not
    return "!FAKE:" in lines[i] or (above is not None and FAKE_LINE.match(above) is not None)


def depin(func, text, scorer, lever, say=print):
    """(rc, new text or None). scorer(text) -> (state, m, n)."""
    state, m, n = scorer(text)
    if state != "match":
        say(f"DEPIN {func} refused {state} {m}/{n}")
        return 1, None
    lines = text.split("\n")
    if text.endswith("\n"):
        lines.pop()  # text_of re-adds the final newline
    before = pin_lines(lines)
    broke = {}
    for i in before:
        trial = list(lines)
        trial[i] = PIN.sub(lambda g: g.group(1), trial[i], count=1)
        j = next((k for k in range(i - 1, -1, -1) if trial[k] is not None), None)
        if j is not None and FAKE_LINE.match(trial[j]):
            trial[j] = None
        st, tm, tn = scorer(text_of(trial))
        say(f"DEPIN {func} line {i + 1} drop {st} {tm}/{tn}")
        if st == "match":
            lines = trial
        else:
            broke[i] = (tm, tn)
    # collect before marking: a marker prepended to lines[i] would read as the mark of the pin on the next line
    for i in [k for k in pin_lines(lines) if not marked(lines, k)]:
        why = lever or "depin: dropping it breaks the match (%d/%d)" % broke.get(i, (0, n))
        # a standalone line above, never trailing: clang-format wraps a long pin line and moves a trailing comment
        indent = lines[i][: len(lines[i]) - len(lines[i].lstrip())]
        lines[i] = f"{indent}// !FAKE: {why}\n" + lines[i]
    out = text_of(lines)
    if not text.endswith("\n"):
        out = out[:-1]
    st, fm, fn = scorer(out)
    if st != "match":
        say(f"DEPIN {func} final {st} {fm}/{fn}")
        return 1, None
    say(f"DEPIN {func} pins {len(before)} to {len(pin_lines(lines))}")
    return 0, out


def lever_ok(lever):
    with open("cookbook/INDEX.md") as f:
        return any(line.startswith(f"{lever} |") for line in f)


def func_name(prog, vram):
    with open(cards.FUNCS) as f:
        for line in f:
            r = json.loads(line)
            if r["prog"] == prog and int(r["vram"], 16) == vram:
                return r["name"]
    return None


def run(pv, src, lever):
    m = cards.PV_RE.fullmatch(pv)
    if not m:
        sys.exit(f"depin: bad target {pv}")
    prog, vram = m.group(1), int(m.group(2), 16)
    if lever and not (re.fullmatch(r"C\d{4}", lever) and lever_ok(lever)):
        print(f"DEPIN refused lever {lever}")
        return 2
    func = func_name(prog, vram)
    if not func:
        sys.exit(f"depin: {pv} not in {cards.FUNCS}")
    with open(src) as f:
        text = f.read()
    t = cards.triple()
    rel = f"drafts/{prog}/{func}.c"
    snap = cards.snapshot(f"depin_{func}.{os.getpid()}")
    try:
        os.chdir(snap)
        os.makedirs(os.path.dirname(rel), exist_ok=True)

        def scorer(body):
            with open(rel, "w") as f:
                f.write(body)
            return cards.score(func, prog, rel, t)

        rc, out = depin(func, text, scorer, lever)
    finally:
        os.chdir(ROOT)
        shutil.rmtree(snap, ignore_errors=True)
    if rc == 0 and out != text:
        with open(src, "w") as f:
            f.write(out)
    return rc


# ---- self-test (C0054: a planted function; the scorer compares to the planted pinned body, never retail) ------------
PLANT = '''#include "common.h"

s32 depin_plant(s32 a, s32 b) {
%s    register s32 x asm("$12") = a + b;
%s    register s32 y asm("$2") = x << %d;
    return y;
}
'''


def self_test():
    shutil.rmtree(SELFTEST, ignore_errors=True)
    os.makedirs(SELFTEST)
    t = cards.triple()
    func = "depin_plant"
    seq = [0]

    def words(body):
        seq[0] += 1
        path = os.path.join(SELFTEST, f"v{seq[0]}.c")
        with open(path, "w") as f:
            f.write(body)
        obj = probe.compile_obj(path, t)
        return None if obj is None else probe.elf_function(obj, func)

    ref, _ = words(PLANT % ("", "", 1))

    def scorer(body):
        got = words(body)
        if got is None:
            return "nocompile", 0, len(ref)
        ours, masks = got
        m = sum((ref[i] & ~masks.get(i, 0)) == (ours[i] & ~masks.get(i, 0)) for i in range(min(len(ref), len(ours))))
        return ("match" if len(ours) == len(ref) and m == len(ref) else "fail"), m, len(ref)

    def unmarked(text):
        return psxd_floor.file_debt("depin.c", text).get("pin-unmarked", 0)

    quiet = []
    fail = None
    # case pins: the $12 pin changes the code (kept, marked), the $2 pin does not (dropped)
    rc, out = depin(func, PLANT % ("", "", 1), scorer, None, say=quiet.append)
    if not (rc == 0 and out and quiet[-1] == f"DEPIN {func} pins 2 to 1" and 'asm("$12")' in out
            and 'asm("$2")' not in out and "// !FAKE: depin: dropping it breaks the match (" in out
            and unmarked(out) == 0):
        fail = "pins"
    # case refused: an input that does not match is refused and the file stays byte-identical
    if not fail:
        path = os.path.join(SELFTEST, "refused.c")
        with open(path, "w") as f:
            f.write(PLANT % ("", "", 2))
        with open(path, "rb") as f:
            pre = f.read()
        q = []
        rc, out = depin(func, pre.decode(), scorer, None, say=q.append)
        with open(path, "rb") as f:
            same = f.read() == pre
        if not (rc == 1 and out is None and q and q[-1].startswith(f"DEPIN {func} refused fail ") and same):
            fail = "refused"
    # case marked: a pre-marked survivor keeps its marker unchanged; the dropped pin's marker line goes with it
    if not fail:
        keep, gone = "    // !FAKE: planted keep\n", "    // !FAKE: planted gone\n"
        q = []
        rc, out = depin(func, PLANT % (keep, gone, 1), scorer, "C0054", say=q.append)
        if not (rc == 0 and out and keep in out and "planted gone" not in out and out.count("!FAKE:") == 1
                and q[-1] == f"DEPIN {func} pins 2 to 1" and unmarked(out) == 0):
            fail = "marked"
    # case adjacent: two kept pins on adjacent lines each get their own marker
    if not fail:
        two = 'void f(void) {\n    register int a asm("$4");\n    register int b asm("$5");\n}\n'
        q = []
        rc, out = depin(func, two, lambda b: ("match", 1, 1) if b.count('asm("') == 2 else ("fail", 0, 1), None,
                        say=q.append)
        if not (rc == 0 and out and out.count("!FAKE:") == 2 and unmarked(out) == 0):
            fail = "adjacent"
    shutil.rmtree(SELFTEST, ignore_errors=True)
    print(f"DEPIN CONTROL FAIL {fail}" if fail else "DEPIN CONTROL OK")
    return 1 if fail else 0


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n", 1)[0])
    ap.add_argument("pv", nargs="?", metavar="prog:0xVRAM")
    ap.add_argument("--src")
    ap.add_argument("--lever")
    ap.add_argument("--self-test", action="store_true")
    a = ap.parse_args()
    src = os.path.abspath(a.src) if a.src else None
    os.chdir(ROOT)
    if a.self_test:
        return self_test()
    if not (a.pv and src):
        ap.error("needs <prog:0xVRAM> --src <file>")
    return run(a.pv, src, a.lever)


if __name__ == "__main__":
    sys.exit(main())
