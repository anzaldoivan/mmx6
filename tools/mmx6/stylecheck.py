#!/usr/bin/env python3
"""stylecheck.py -- check of the mmx6 code style (docs/STYLE.md; rules S1 S3-S6 report-only, VER a refusal).

S1 names in config/<VERSION>/symbols.*.txt; S3 process ids, S4 banners, S6 prose runs and S6code commented-out code
in comments of src/ and include/ (.c, .h); S5 header guards. These never fail. VER (docs/ops/multi-version.md item 5):
`#ifdef VERSION_*`, `#ifndef VERSION_*` or `defined(VERSION_*)` in code of src/ or include/ is refused (C writes
`#if VERSION >= VER_US`, include/mmx6/version.h): rc 1 and `STYLECHECK REFUSE <n> version ifdefs`. Otherwise rc 0
(rc 1 also on a --self-test failure). Prints `STYLE <rule> <n>` per rule, then `STYLECHECK report-only <total>
findings`; writes the findings TSV `rule<TAB>path<TAB>line<TAB>text` to --out (default .run/3.3/stylecheck/findings.tsv).
"""
import argparse
import os
import re
import shutil
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from paths import CONFIG_V  # noqa: E402  (the version axis, 3.3 T37)
RULES = ("S1", "S3", "S4", "S5", "S6", "S6code", "VER")
# VER: a per-version ifdef; versions are ordered numbers compared with #if (include/mmx6/version.h).
VER_PAT = re.compile(r"^\s*#\s*(ifdef|ifndef)\s+VERSION_\w*|\bdefined\s*\(?\s*VERSION_\w*")

PLACEHOLDER = re.compile(r"^(func|D)_[0-9A-F]{8}$")
SNAKE = re.compile(r"^[a-z][a-z0-9_]*$")
GLOBAL = re.compile(r"^g_[A-Za-z0-9_]+$")
HEDGED = {"maybe", "likely", "probably"}
UNK_FIELD = re.compile(r"^unk[0-9A-Fa-f]+$")
SYMLINE = re.compile(r"^\s*([A-Za-z_]\w*)\s*=\s*0x[0-9A-Fa-f]+\s*;(.*)$")

# S3: case-sensitive, word-bounded; MIPS registers and prose are lowercase, so they never match. R excludes the
# MIPS CPU models (R3000, R4000), found in include/mmx6/types.h.
S3_PATS = [re.compile(p) for p in (
    r"\bT\d+(\.\d+)?\b", r"\bR(?![34]000\b)\d+(\.\d+)*(-\d+)?\b", r"\b[GM]\d+\b", r"\bC\d{4}\b", r"\(\d+/\d+\)")]
S4_PAT = re.compile(r"[-=*#/]{4,}")
ALLOWED = re.compile(
    r"^(prog \S+ \| system .*\| range |!\s*FAKE:|!\s*@bug|str\b|clang-format (off|on)\b|0x[0-9A-Fa-f]+ \S+:"
    r"|basis:|callers:|reads:|Shared file:|0x[0-9A-Fa-f]+$)")
CODE_END = re.compile(r"[;{}]$")
CODE_START = re.compile(r"^(if|for|while|return|switch)\s*\(")
# Prose that happens to end in `;` (include/mmx6/class4.h:4): four plain words in a row, or an apostrophe.
PROSE = re.compile(r"\b[A-Za-z_]\w*( [A-Za-z_]\w*){3}\b|\w'\w")


def load_verbs(path):
    with open(path, encoding="utf-8") as f:
        return {w for w in (ln.split("#", 1)[0].strip().lower() for ln in f) if w}


def load_sdk(path):
    names = set()
    if os.path.exists(path):
        with open(path, encoding="utf-8") as f:
            for ln in f:
                if ln.startswith("#"):
                    continue
                cols = ln.rstrip("\n").split("\t")
                if len(cols) >= 4 and cols[3] == "sdk":
                    names.add(cols[2])
    return names


def s1_name(name, is_func, verbs):
    """Return a reason string when the name breaks S1, else None."""
    if PLACEHOLDER.match(name):
        return None
    toks = name.split("_")
    for t in toks:
        if t.lower() in HEDGED or (t.lower().startswith("unk") and not UNK_FIELD.match(t)):
            return "hedged"
    if is_func:
        if not SNAKE.match(name):
            return "not snake_case"
        if toks[0] not in verbs:
            return "no leading verb"
        return None
    if SNAKE.match(name) or GLOBAL.match(name):
        return None
    return "not snake_case or g_"


def check_symbols(cfg, verbs, sdk, rel):
    out = []
    for fn in sorted(os.listdir(cfg)):
        if not (fn.startswith("symbols.") and fn.endswith(".txt")):
            continue
        path = os.path.join(cfg, fn)
        with open(path, encoding="utf-8", errors="replace") as f:
            for i, ln in enumerate(f, 1):
                m = SYMLINE.match(ln)
                if not m or m.group(1) in sdk:
                    continue
                why = s1_name(m.group(1), "type:func" in m.group(2), verbs)
                if why:
                    out.append(("S1", rel(path), i, f"{m.group(1)} ({why})"))
    return out


def lex(src):
    """Per line: (has_code, [comment texts]) with openers, closers and block `*` gutters stripped."""
    lines = src.split("\n")
    code = [False] * len(lines)
    cmts = [[] for _ in lines]
    st, buf, ln, i, n = "code", [], 0, 0, len(src)

    def flush(kind):
        t = "".join(buf).strip()
        if kind == "block" and t.startswith("*") and not t.startswith("*/"):
            t = t[1:].strip()
        if t or kind == "block":
            cmts[ln].append(t)
        buf.clear()

    while i < n:
        c = src[i]
        nx = src[i + 1] if i + 1 < n else ""
        if c == "\n":
            if st == "line":
                flush("line")
                st = "code"
            elif st == "block":
                flush("block")
            ln += 1
            i += 1
            continue
        if st == "code":
            if c == "/" and nx == "/":
                st, i = "line", i + 2
                continue
            if c == "/" and nx == "*":
                st, i = "block", i + 2
                continue
            if c in "\"'":
                st = c
            if not c.isspace():
                code[ln] = True
        elif st == "line":
            buf.append(c)
        elif st == "block":
            if c == "*" and nx == "/":
                flush("block")
                st, i = "code", i + 2
                continue
            buf.append(c)
        else:  # inside a string or char literal
            if c == "\\":
                i += 2
                continue
            if c == st:
                st = "code"
        i += 1
    if st == "line":
        flush("line")
    return code, [[t for t in c if t] for c in cmts]


def check_source(path, rel):
    with open(path, encoding="utf-8", errors="replace") as f:
        src = f.read()
    code, cmts = lex(src)
    rp, out = rel(path), []
    for i, ln in enumerate(src.split("\n")):
        if code[i] and VER_PAT.search(ln):
            out.append(("VER", rp, i + 1, ln.strip()))
    for i, texts in enumerate(cmts):
        for t in texts:
            if any(p.search(t) for p in S3_PATS):
                out.append(("S3", rp, i + 1, t))
            if S4_PAT.search(t):
                out.append(("S4", rp, i + 1, t))
            if not t.startswith("str") and (CODE_START.match(t) or (CODE_END.search(t) and not PROSE.search(t))):
                out.append(("S6code", rp, i + 1, t))
    # S6: runs of >= 3 full-line comment lines of no allowed kind; the leading block is exempt.
    full = [bool(c) and not code[i] for i, c in enumerate(cmts)]
    k = 0
    while k < len(full) and (full[k] or not (code[k] or cmts[k])):
        k += 1
    run = []
    for i in range(k, len(full) + 1):
        bad = i < len(full) and full[i] and not all(ALLOWED.match(t) for t in cmts[i])
        if bad:
            run.append(i)
            continue
        if len(run) >= 3:
            out.append(("S6", rp, run[0] + 1, f"{len(run)} lines: {cmts[run[0]][0]}"))
        run = []
    if path.endswith(".h"):
        out += check_guard(path, rp, src, code)
    return out


def expected_guard(rp):
    for top in ("include/", "src/"):
        if rp.startswith(top):
            rp = rp[len(top):]
            break
    return re.sub(r"[/.]", "_", rp).upper()


def check_guard(path, rp, src, code):
    lines = src.split("\n")
    want = expected_guard(rp)
    if any(re.match(r"\s*#\s*pragma\s+once\b", ln) for ln in lines):
        return [("S5", rp, 1, "#pragma once")]
    directives = [(i, lines[i].strip()) for i in range(len(lines)) if code[i]][:2]
    got = [re.match(r"#\s*(ifndef|define)\s+(\w+)", d) for _, d in directives]
    if len(got) == 2 and all(got) and got[0].group(1) == "ifndef" and got[1].group(1) == "define" \
            and got[0].group(2) == got[1].group(2) == want:
        return []
    line = directives[0][0] + 1 if directives else 1
    return [("S5", rp, line, f"guard != {want}")]


def scan(root, verbs_path):
    def rel(p):
        return os.path.relpath(p, root).replace(os.sep, "/")
    verbs = load_verbs(verbs_path)
    out = check_symbols(os.path.join(root, CONFIG_V), verbs,
                        load_sdk(os.path.join(root, "config", "symbols", "basis.tsv")), rel)
    for top in ("src", "include"):
        for d, dirs, files in os.walk(os.path.join(root, top)):
            dirs.sort()
            for fn in sorted(files):
                if fn.endswith((".c", ".h")) and not fn.startswith("."):
                    out += check_source(os.path.join(d, fn), rel)
    return out


def report(found, out_file):
    os.makedirs(os.path.dirname(out_file), exist_ok=True)
    with open(out_file, "w", encoding="utf-8") as f:
        for r, p, ln, t in found:
            f.write(f"{r}\t{p}\t{ln}\t{t.replace(chr(9), ' ')}\n")
    for r in RULES:
        print(f"STYLE {r} {sum(1 for x in found if x[0] == r)}")
    print(f"STYLECHECK report-only {len(found)} findings")
    ver = sum(1 for x in found if x[0] == "VER")
    if ver:
        print(f"STYLECHECK REFUSE {ver} version ifdefs (write #if VERSION >= VER_<X>, include/mmx6/version.h)")
    return 1 if ver else 0


SELF_FILES = {
    f"{CONFIG_V}/symbols.t.txt": "func_80010000 = 0x80010000; // type:func\nupdate_bomb = 0x80010004; // type:func\n"
                            "bomb_update = 0x80010008; // type:func\n",
    "config/symbols/basis.tsv": "# prog\tvram\tname\tbasis-kind\tbasis-ref\ttier\n",
    "include/ok.h": "// ok.h: fine.\n#ifndef OK_H\n#define OK_H\n#endif\n",
    "include/bad.h": "#pragma once\n",
    "src/a.c": "// leading\n// block\n// lines\nint x; // see T12 and (3/4)\n/* ---- banner ---- */\n"
               "// 0x80010004 update_bomb: moves the bomb.\n// basis: none\n// callers: none known\n"
               "// Tier 2 is fine here\nvoid f(void) {\n// x = 1;\n// prose one\n// prose two\n// prose three\n"
               "    const char* s = \"// T9 ----\";\n}\n",
    "src/v.c": "#ifdef VERSION_US\n#endif\n#if defined(VERSION_EU)\n#endif\n#if VERSION >= VER_US\n#endif\n"
               "// #ifdef VERSION_JP in a comment\n",
}
SELF_WANT = {("S1", f"{CONFIG_V}/symbols.t.txt", 3), ("VER", "src/v.c", 1), ("VER", "src/v.c", 3), ("S3", "src/a.c", 4), ("S4", "src/a.c", 5),
             ("S5", "include/bad.h", 1), ("S6", "src/a.c", 11), ("S6code", "src/a.c", 11)}


def self_test(out_dir):
    tmp = os.path.join(out_dir, "selftest")
    shutil.rmtree(tmp, ignore_errors=True)
    try:
        for rp, body in SELF_FILES.items():
            p = os.path.join(tmp, rp)
            os.makedirs(os.path.dirname(p), exist_ok=True)
            with open(p, "w", encoding="utf-8") as f:
                f.write(body)
        verbs = os.path.join(tmp, "verbs.txt")
        with open(verbs, "w", encoding="utf-8") as f:
            f.write("# test\nupdate\n")
        got = {(r, p, ln) for r, p, ln, _ in scan(tmp, verbs)}
    finally:
        shutil.rmtree(tmp, ignore_errors=True)
    if got != SELF_WANT:
        print(f"STYLECHECK SELF-TEST FAIL missing={sorted(SELF_WANT - got)} extra={sorted(got - SELF_WANT)}")
        return 1
    print("STYLECHECK SELF-TEST OK")
    return 0


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--out", default=os.path.join(ROOT, ".run", "3.3", "stylecheck"), help="output directory")
    ap.add_argument("--self-test", action="store_true", help="run the planted cases and exit")
    a = ap.parse_args()
    if a.self_test:
        return self_test(a.out)
    return report(scan(ROOT, os.path.join(ROOT, "config", "style", "verbs.txt")), os.path.join(a.out, "findings.tsv"))


if __name__ == "__main__":
    sys.exit(main())
