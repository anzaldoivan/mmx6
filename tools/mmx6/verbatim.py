#!/usr/bin/env python3
"""verbatim.py -- a banked or ledgered body must be C (DK-29; container or host, stdlib only).

  verbatim.py <file>...     one line per file: `VERBATIM <file> ok pins <p>` | `VERBATIM <file> refused <why>`
  verbatim.py --all         every src/shared/**/*.c and tracked drafts/**/*.c (walked when there is no .git);
                            last `VERBATIM ALL <k> files; refused <r>; pins <p>`
  verbatim.py --self-test   planted bodies in .run/verbatim-selftest/; ends `VERBATIM CONTROL OK`
rc 0 iff no file refused, 1 otherwise, 2 on usage or an unreadable file.

After C comments are stripped: refused `include-asm` (INCLUDE_ASM/INCLUDE_RODATA anywhere: the file is the bank
body), `directive <d>` (assembler directive text), `inline-asm` (any asm statement or expression other than a
register pin). Register pins (`register <type> <name> asm(<reg>)`, also `__asm__`) are allowed and counted.
Python: check(text) -> (ok, why, pins).
"""
import os
import re
import shutil
import subprocess
import sys

SELFTEST = ".run/verbatim-selftest"
INCLUDE_RE = re.compile(r"\b(?:INCLUDE_ASM|INCLUDE_RODATA)\b")
DIRECTIVE_RE = re.compile(r"(?<![\w\])])\.(word|set|half|byte)\b")
PIN_RE = re.compile(r"\bregister\s+[A-Za-z_][\w\s*]*?\b(?:asm|__asm__|__asm)\s*\(\s*\"\$\w+\"\s*\)")
ASM_RE = re.compile(r"\b(?:asm|__asm__|__asm)\b")


def strip_comments(text):
    """Drop /* */ and // comments; string and char literals are kept intact."""
    out, i, n = [], 0, len(text)
    while i < n:
        c = text[i]
        if c == "/" and text.startswith("/*", i):
            j = text.find("*/", i + 2)
            i = n if j < 0 else j + 2
            out.append(" ")
        elif c == "/" and text.startswith("//", i):
            j = text.find("\n", i)
            i = n if j < 0 else j
        elif c in "\"'":
            j = i + 1
            while j < n and text[j] != c and text[j] != "\n":
                j += 2 if text[j] == "\\" else 1
            out.append(text[i:j + 1])
            i = j + 1
        else:
            out.append(c)
            i += 1
    return "".join(out)


def check(text):
    s = strip_comments(text)
    if INCLUDE_RE.search(s):
        return False, "include-asm", 0
    m = DIRECTIVE_RE.search(s)
    if m:
        return False, "directive ." + m.group(1), 0
    pins = len(PIN_RE.findall(s))
    if ASM_RE.search(PIN_RE.sub(" ", s)):
        return False, "inline-asm", pins
    return True, "", pins


def run(paths):
    """Print one line per file; return (refused, pins) or None on an unreadable file."""
    refused = pins = 0
    for p in paths:
        try:
            with open(p, encoding="utf-8", errors="replace") as f:
                text = f.read()
        except OSError as e:
            print(f"VERBATIM {p} unreadable {e.strerror}")
            return None
        ok, why, k = check(text)
        if ok:
            pins += k
            print(f"VERBATIM {p} ok pins {k}")
        else:
            refused += 1
            print(f"VERBATIM {p} refused {why}")
    return refused, pins


def walk_c(root):
    found = []
    for d, _, files in os.walk(root):
        found += [os.path.join(d, f) for f in files if f.endswith(".c")]
    return found


def all_files():
    files = walk_c("src/shared")
    try:
        r = subprocess.run(["git", "ls-files", "drafts"], capture_output=True, text=True, check=True)
        files += [p for p in r.stdout.splitlines() if p.endswith(".c")]
    except (OSError, subprocess.CalledProcessError):
        files += walk_c("drafts")
    return sorted(set(files))


CASES = (
    ("clean", "int f(int a) {\n    /* asm(\"nop\") in a comment */\n    return a + 1;\n}\n", True, "", 0),
    ("inline_asm", "void f(void) {\n    __asm__ volatile(\"nop\");\n}\n", False, "inline-asm", 0),
    ("word_string", "void f(void) {\n    asm(\".word 0x0\");\n}\n", False, "directive .word", 0),
    ("include_asm", "INCLUDE_ASM(\"asm/x\", f);\nint g(void) { return 0; }\n", False, "include-asm", 0),
    ("one_pin", "int f(int a) {\n    register int r asm(\"$2\") = a;\n    return r;\n}\n", True, "", 1),
    ("pin_in_comment", "int f(int a) {\n    // register int r __asm__(\"$2\");\n    return a;\n}\n", True, "", 0),
)


def self_test():
    shutil.rmtree(SELFTEST, ignore_errors=True)
    os.makedirs(SELFTEST)
    fails = []
    for name, body, ok, why, pins in CASES:
        path = os.path.join(SELFTEST, name + ".c")
        with open(path, "w") as f:
            f.write(body)
        with open(path) as f:
            got = check(f.read())
        line_ok = got[0] == ok and got[1] == why and (not ok or got[2] == pins)
        print(f"VERBATIM CASE {name} {'ok' if got[0] else 'refused'} {got[1] or 'pins %d' % got[2]}")
        if not line_ok:
            fails.append(name)
    for name in fails:
        print(f"VERBATIM CONTROL FAIL {name}")
    if fails:
        return 1
    print("VERBATIM CONTROL OK")
    return 0


def main(argv):
    if not argv or (argv[0].startswith("-") and (len(argv) != 1 or argv[0] not in ("--all", "--self-test"))):
        print(__doc__.strip(), file=sys.stderr)
        return 2
    if argv[0] == "--self-test":
        return self_test()
    files = all_files() if argv[0] == "--all" else argv
    res = run(files)
    if res is None:
        return 2
    if argv[0] == "--all":
        print(f"VERBATIM ALL {len(files)} files; refused {res[0]}; pins {res[1]}")
    return 1 if res[0] else 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
