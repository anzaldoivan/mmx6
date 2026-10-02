#!/usr/bin/env python3
"""gccsrc.py -- the citation auditor: every gcc 2.95.2 source citation in the codegen map and the cookbook resolves
(stdlib only, python 3.8+).

  gccsrc.py --check [--root R]
      scans docs/codegen-map/*.md and cookbook/C*.md (repo-relative; an absent dir = no files) for citations
      `src:gcc-2.95.2/<path>:<line> "<fragment>"` and resolves each under R (default /opt/gcc-2.95.2-src):
      -> `CITES MISSING <cite>`            file absent under R
      -> `CITES DRIFT <cite> nearest <n|->` line out of range or fragment not a verbatim substring of it;
                                           n = line nearest the cited one holding the fragment (tie: lower), `-` if none
      -> `CITES MALFORMED <text>`          a `src:gcc-2.95.2/` token that does not parse (bad line, empty or
                                           >80-char fragment)
      any of these -> rc 1; else last line `CITES OK <c> of <c> citations` (rc 0).
      c>0 and R absent -> `CITES NOSRC <R>` rc 2; c=0 needs no R.
  gccsrc.py --self-test
      plants a scratch source tree + docs under .run/gccsrc-selftest (never the real ones) and runs the same check:
      good cite OK; drifted line DRIFT nearest <exact>; missing file MISSING; wrong fragment DRIFT nearest -;
      ends `CITES CONTROL OK` (rc 0), else a `CITES CONTROL FAIL` line, rc 1.

Sources are read as bytes decoded latin-1 (gcc 2.95 sources are not UTF-8); lines 1-based; the fragment is compared
verbatim (no whitespace folding) and cannot itself contain `"`.
"""
import argparse
import glob
import os
import re
import shutil
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
REPO = os.path.normpath(os.path.join(HERE, "..", ".."))
DEFAULT_ROOT = "/opt/gcc-2.95.2-src"
DOC_GLOBS = ("docs/codegen-map/*.md", "cookbook/C*.md")
SELFTEST = ".run/gccsrc-selftest"
TOKEN = "src:gcc-2.95.2/"
CITE = re.compile(r'src:gcc-2\.95\.2/(?P<path>[^\s:"]+):(?P<line>[0-9]+) "(?P<frag>[^"]*)"')
MAXFRAG = 80


def docs(base):
    out = []
    for g in DOC_GLOBS:
        out.extend(sorted(glob.glob(os.path.join(base, g))))
    return out


def scan(paths):
    """-> (cites [(path, line, frag, text)], malformed [text]) in document order."""
    cites, bad = [], []
    for p in paths:
        with open(p, "rb") as f:
            text = f.read().decode("utf-8", "replace")
        for ln in text.splitlines():
            i = ln.find(TOKEN)
            while i >= 0:
                m = CITE.match(ln, i)
                if m and 0 < len(m.group("frag")) <= MAXFRAG and int(m.group("line")) > 0:
                    cites.append((m.group("path"), int(m.group("line")), m.group("frag"), m.group(0)))
                    i = ln.find(TOKEN, m.end())
                else:
                    bad.append(ln[i:i + 120].rstrip())
                    i = ln.find(TOKEN, i + len(TOKEN))
    return cites, bad


def check(paths, root):
    """-> (rc, output lines)."""
    cites, bad = scan(paths)
    out = [f"CITES MALFORMED {t}" for t in bad]
    if cites and not os.path.isdir(root):
        return 2, out + [f"CITES NOSRC {root}"]
    cache = {}
    for path, line, frag, text in cites:
        fp = os.path.join(root, path)
        if not os.path.isfile(fp):
            out.append(f"CITES MISSING {text}")
            continue
        if fp not in cache:
            with open(fp, "rb") as f:
                cache[fp] = f.read().decode("latin-1").splitlines()
        src = cache[fp]
        if line <= len(src) and frag in src[line - 1]:
            continue
        hits = [n for n, s in enumerate(src, 1) if frag in s]
        near = min(hits, key=lambda n: (abs(n - line), n)) if hits else "-"
        out.append(f"CITES DRIFT {text} nearest {near}")
    if out:
        return 1, out
    return 0, [f"CITES OK {len(cites)} of {len(cites)} citations"]


# ---- self-test: planted tree + docs in .run/gccsrc-selftest/, never the real ones -------------------------------------

def self_test():
    base = os.path.join(REPO, SELFTEST)
    shutil.rmtree(base, ignore_errors=True)
    root = os.path.join(base, "src")
    os.makedirs(os.path.join(root, "gcc"))
    with open(os.path.join(root, "gcc", "planted.c"), "wb") as f:
        f.write(b"/* planted by gccsrc.py --self-test */\n"   # 1
                b"int a;\n"                                     # 2
                b"static int\n"                                 # 3
                b"alpha (x)\n"                                  # 4
                b"{\n"                                          # 5
                b"  return x + 1;  /* caf\xe9 */\n"             # 6 latin-1 byte, not UTF-8
                b"}\n"                                          # 7
                b"int beta_marker;\n")                          # 8
    lines, fails = [], []

    def run(name, body, want_rc, want):
        d = os.path.join(base, name, "cookbook")
        os.makedirs(d)
        with open(os.path.join(d, "C9999.md"), "w") as f:
            f.write("# C9999 — planted\n" + body + "\n")
        rc, got = check(docs(os.path.join(base, name)), root)
        good = rc == want_rc and got == want
        lines.append(f"CITES CONTROL {'ok' if good else 'FAIL'} {name}: rc {rc} {' | '.join(got)}")
        if not good:
            fails.append(name)

    g = 'src:gcc-2.95.2/gcc/planted.c:6 "return x + 1;  /* café */"'
    d = 'src:gcc-2.95.2/gcc/planted.c:3 "beta_marker"'
    m = 'src:gcc-2.95.2/gcc/absent.c:1 "int"'
    w = 'src:gcc-2.95.2/gcc/planted.c:4 "gamma (x)"'
    run("good", "see " + g + " and again " + g, 0, ["CITES OK 2 of 2 citations"])
    run("drift", d, 1, [f"CITES DRIFT {d} nearest 8"])
    run("missing", m, 1, [f"CITES MISSING {m}"])
    run("wrong", w, 1, [f"CITES DRIFT {w} nearest -"])
    run("malformed", 'src:gcc-2.95.2/gcc/planted.c:x "int"', 1, ['CITES MALFORMED src:gcc-2.95.2/gcc/planted.c:x "int"'])
    run("empty", "no citations here", 0, ["CITES OK 0 of 0 citations"])
    lines.append("CITES CONTROL OK" if not fails else f"CITES CONTROL FAIL {len(fails)}: {' '.join(fails)}")
    for x in lines:
        print(x)
    return 1 if fails else 0


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    g = ap.add_mutually_exclusive_group(required=True)
    g.add_argument("--check", action="store_true")
    g.add_argument("--self-test", action="store_true")
    ap.add_argument("--root", default=DEFAULT_ROOT, help="the gcc-2.95.2 source tree (default %(default)s)")
    a = ap.parse_args()
    if a.self_test:
        return self_test()
    rc, out = check(docs(REPO), a.root)
    for x in out:
        print(x)
    return rc


if __name__ == "__main__":
    sys.exit(main())
