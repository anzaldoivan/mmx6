#!/usr/bin/env python3
"""docconv.py -- the documentation-convention check for src/ and include/ files (banner, function headers, usage notes).

  docconv.py [--root DIR] check [paths]
      -> applies DC1-DC8 to the given files (repo-relative), else to the paths listed in config/docconv.txt
         (`#` comment lines, one repo-relative path per line). Prints `DOCCONV FAIL <path>:<line> DC<k> <reason>` per
         refusal, then `DOCCONV OK <n> files` rc 0 or `DOCCONV FAIL <n> refusals` rc 1. A listed path that does not
         exist is a refusal (DC0).
  docconv.py --self-test
      -> planted tree under .run/<phase>/docconv-selftest/ (removed at the end): one passing file exercising every rule
         and one failing file per rule. Ends `DOCCONV CONTROL OK` rc 0, or `DOCCONV CONTROL FAIL <case>` rc 1.

Rules (line refs 1-based)
  DC1 banner: exactly one leading comment line `// prog <P> | system <s> | range 0x<lo>-0x<hi>` (or `range -` in a .h);
      config/symbols.<P>.txt exists; lo <= hi (hi = the last instruction word, not end-exclusive). A file under
      src/shared/ also needs a leading `// Shared file: included by <TU>, between <A> and <B>.` line, the TU existing
      and naming the file in an #include.
  DC2 no build path: no comment line holds a drive path, /Users/ /home/ /work/ /tmp/ /sdk/ /disc/ /mnt/ /private/,
      or `Source:`.
  DC3 header: each file-scope function definition is preceded by a `//` block opening `// 0x<8 HEX> <name>: <purpose>`
      (address from config/symbols.<P>.txt or a func_ name; purpose >= 3 words). Exempt (with DC4-DC6): a `static inline`
      helper with no address (not in config/symbols.<P>.txt, no func_ name); it may carry a short header
      `// <name>: <purpose>` (name matches, purpose >= 3 words) or none.
  DC4 basis: `// basis: <kind> <ref>` matching a config/symbols/basis.tsv row (prog, vram, kind; ref >= 8 chars inside
      basis-ref), or `// basis: none` for a func_ name.
  DC5 callers: `// callers: a, b` (names from any config/symbols.*.txt) or `// callers: none known`.
  DC6 string: a (prog, vram) row of config/oracle.strnames.tsv needs a `// str 0x<8 HEX> ` line in the block.
  DC7 usage notes: a struct definition is preceded by a `//` line with `read by ` or `used by `; each member line ends
      with a `//` comment holding `by <identifier>` or `unreferenced`. An optional `// reads: Struct.field (+0xNN, type),
      role` line in a function block notes a read of a generated struct's field; a malformed one is refused.
  DC8 FAKE: each `!FAKE:` is followed on its line by a reason of >= 3 words.
"""
import argparse
import re
import shutil
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]


def phase_scratch(root):
    """The open phase's temp folder (as tools/run.sh: `# Phase <id>` line 1 of PHASE_PLAN.md), else .run (no plan)."""
    try:
        line = (root / "phase-ends/current/PHASE_PLAN.md").read_text().split("\n", 1)[0]
    except OSError:
        line = ""
    m = re.match(r"#\s*Phase\s+([A-Za-z0-9._-]+)", line)
    return root / ".run" if not m or m.group(1) in (".", "..") else root / ".run" / m.group(1)


SELFTEST = phase_scratch(ROOT) / "docconv-selftest"
LIST = "config/docconv.txt"
BASIS = "config/symbols/basis.tsv"
STRNAMES = "config/oracle.strnames.tsv"

BANNER = re.compile(r"^// prog (\S+) \| system ([a-z0-9_]+) \| range (0x[0-9A-F]{8}-0x[0-9A-F]{8}|-)$")
BANNERISH = re.compile(r"^//\s*prog\b")
BUILDPATH = re.compile(r"[A-Za-z]:\\|/(Users|home|work|tmp|sdk|disc|mnt|private)/|Source:")
SYMLINE = re.compile(r"^\s*([A-Za-z_]\w*)\s*=\s*0x([0-9A-Fa-f]+)\s*;")
HEAD = re.compile(r"^// 0x([0-9A-F]{8}) ([A-Za-z_]\w*): (.*)$")
BASISLINE = re.compile(r"^// basis: (\S+)(?: (.+))?$")
CALLERS = re.compile(r"^// callers: (.+)$")
SHORTHEAD = re.compile(r"^// ([A-Za-z_]\w*): (.*)$")
FUNCNAME = re.compile(r"^func_([0-9A-Fa-f]{8})$")
STRUCT = re.compile(r"^\s*(?:typedef\s+struct(?:\s+\w+)?|struct\s+\w+)\s*\{")
FNAME = re.compile(r"([A-Za-z_]\w*)\s*\($")
USAGE = re.compile(r"\bby [A-Za-z_]\w*|unreferenced")
FAKE = re.compile(r"!FAKE:(.*)")
READS = re.compile(r"^// reads: [A-Za-z_]\w*\.[A-Za-z_]\w* \(\+0x[0-9A-Fa-f]+, [^()]+\), \S.*$")
SHARED = re.compile(r"^// Shared file: included by (\S+), between ([A-Za-z_]\w*) and ([A-Za-z_]\w*)\.$")
IDENT = re.compile(r"^[A-Za-z_]\w*$")


def split(line, in_block):
    """(code, comment text, in_block after) for one line; strings and char literals stay in code."""
    code, comment, i, n = [], [], 0, len(line)
    while i < n:
        if in_block:
            j = line.find("*/", i)
            if j < 0:
                comment.append(line[i:])
                return "".join(code), "".join(comment), True
            comment.append(line[i:j])
            i, in_block = j + 2, False
            continue
        c = line[i]
        if line.startswith("//", i):
            comment.append(line[i + 2:])
            break
        if line.startswith("/*", i):
            in_block, i = True, i + 2
            continue
        if c in "\"'":
            j = i + 1
            while j < n and line[j] != c:
                j += 2 if line[j] == "\\" else 1
            code.append(line[i:j + 1])
            i = j + 1
            continue
        code.append(c)
        i += 1
    return "".join(code), "".join(comment), in_block


def load_tables(root):
    """symbols per prog, every symbol name, basis rows, string-user (prog, vram) pairs."""
    syms, names = {}, set()
    for p in sorted((root / "config").glob("symbols.*.txt")):
        prog = p.name[len("symbols."):-len(".txt")]
        table = {}
        for line in p.read_text(encoding="utf-8", errors="replace").splitlines():
            m = SYMLINE.match(line)
            if m:
                table[m.group(1)] = int(m.group(2), 16)
                names.add(m.group(1))
        syms[prog] = table
    basis = []
    bp = root / BASIS
    if bp.exists():
        for line in bp.read_text(encoding="utf-8", errors="replace").splitlines():
            f = line.split("\t")
            if line.startswith("#") or len(f) < 5:
                continue
            try:
                basis.append((f[0], int(f[1], 16), f[3], f[4]))
            except ValueError:
                continue
    strs = set()
    sp = root / STRNAMES
    if sp.exists():
        for line in sp.read_text(encoding="utf-8", errors="replace").splitlines():
            f = line.split("\t")
            if line.startswith("#") or len(f) < 2:
                continue
            try:
                strs.add((f[0], int(f[1], 16)))
            except ValueError:
                continue
    return syms, names, basis, strs


def block_above(lines, idx):
    """The contiguous `//` lines right above 0-based line idx, top first."""
    out = []
    j = idx - 1
    while j >= 0 and lines[j].strip().startswith("//"):
        out.append(lines[j].strip())
        j -= 1
    return out[::-1]


def check_file(rel, text, tables, root=ROOT):
    syms, names, basis, strs = tables
    lines = text.splitlines()
    fails = []

    def fail(ln, k, why):
        fails.append(f"{rel}:{ln} DC{k} {why}")

    # DC1: the banner among the leading comment lines.
    banners, shared, prog, in_block = [], [], None, False
    for i, line in enumerate(lines):
        code, _, in_block = split(line, in_block)
        s = line.strip()
        if code.strip():
            break
        if s.startswith("//") and BANNERISH.match(s):
            banners.append((i + 1, s))
        if SHARED.match(s):
            shared.append(SHARED.match(s))
    good = [(ln, BANNER.match(s)) for ln, s in banners if BANNER.match(s)]
    if not good:
        fail(1, 1, "no banner `// prog P | system s | range lo-hi`")
    elif len(good) > 1:
        fail(good[1][0], 1, "more than one banner")
    else:
        ln, m = good[0]
        if m.group(1) not in syms:
            fail(ln, 1, f"no config/symbols.{m.group(1)}.txt for prog {m.group(1)}")
        else:
            prog = m.group(1)
        rng = m.group(3)
        if rng == "-":
            if not rel.endswith(".h"):
                fail(ln, 1, "range - only in a .h file")
        elif int(rng[2:10], 16) > int(rng[13:], 16):
            fail(ln, 1, "range lo > hi")
    if rel.startswith("src/shared/"):
        if not shared:
            fail(1, 1, "shared file without `// Shared file: included by TU, between A and B.`")
        else:
            tu = root / shared[0].group(1)
            if not tu.is_file() or Path(rel).name not in tu.read_text(encoding="utf-8", errors="replace"):
                fail(1, 1, f"Shared file: {shared[0].group(1)} missing or not including {Path(rel).name}")

    depth, stmt, start, in_block, struct_depth = 0, None, 0, False, None
    for i, line in enumerate(lines):
        ln = i + 1
        code, comment, nb = split(line, in_block)
        holds_comment = in_block or nb or "//" in line or "/*" in line
        in_block = nb
        # DC2
        if holds_comment and BUILDPATH.search(line):
            fail(ln, 2, "build path or Source: in a comment")
        # DC8
        m = FAKE.search(line)
        if m and len(m.group(1).split()) < 3:
            fail(ln, 8, "!FAKE: reason under 3 words")
        # DC7 member lines
        if struct_depth is not None and depth >= struct_depth:
            c = code.strip()
            if c.endswith(";") and not c.startswith("}") and not USAGE.search(line.split("//", 1)[1] if "//" in line
                                                                               else ""):
                fail(ln, 7, "struct member without `by <identifier>` or `unreferenced` note")
        if depth == 0 and stmt is None and code.strip().startswith("#"):
            continue
        for c in code:
            if depth == 0:
                if stmt is None:
                    if c.isspace():
                        continue
                    stmt, start = "", i
                if c == ";":
                    stmt = None
                    continue
                if c == "{":
                    if STRUCT.match(stmt + "{"):
                        if not any("read by " in b or "used by " in b for b in block_above(lines, start)):
                            fail(start + 1, 7, "struct without a `read by`/`used by` note above")
                        struct_depth = 1
                    else:
                        fm = FNAME.search(stmt.split("(", 1)[0].rstrip() + "(")
                        if "(" in stmt and "=" not in stmt.split("(", 1)[0] and fm:
                            words = re.findall(r"\w+", stmt.split("(", 1)[0])
                            helper = "static" in words and ("inline" in words or "__inline__" in words)
                            fails.extend(check_func(rel, lines, start, fm.group(1), prog, tables, helper))
                    stmt = None
                    depth += 1
                    continue
                stmt += c
            else:
                if c == "{":
                    depth += 1
                elif c == "}":
                    depth -= 1
                    if depth == 0:
                        struct_depth = None
        if stmt is not None:
            stmt += " "
    return fails


def check_func(rel, lines, start, name, prog, tables, helper=False):
    syms, names, basis, strs = tables
    ln = start + 1
    out = []
    block = block_above(lines, start)
    if helper and not FUNCNAME.match(name) and (prog is None or name not in syms[prog]):
        # a static inline helper has no symbol: no address header, basis or callers; a short header is checked
        s = SHORTHEAD.match(block[0]) if block else None
        if s and s.group(1) != name:
            out.append(f"{rel}:{ln} DC3 header names {s.group(1)}, function is {name}")
        elif s and len(s.group(2).split()) < 3:
            out.append(f"{rel}:{ln} DC3 {name}: purpose under 3 words")
        return out
    h = HEAD.match(block[0]) if block else None
    if not h:
        return [f"{rel}:{ln} DC3 {name}: no `// 0x<ADDR> {name}: <purpose>` header block"]
    if h.group(2) != name:
        out.append(f"{rel}:{ln} DC3 header names {h.group(2)}, function is {name}")
    if len(h.group(3).split()) < 3:
        out.append(f"{rel}:{ln} DC3 {name}: purpose under 3 words")
    fm = FUNCNAME.match(name)
    addr = None
    if prog is not None:
        addr = syms[prog].get(name)
        if addr is None and fm:
            addr = int(fm.group(1), 16)
        if addr is None:
            out.append(f"{rel}:{ln} DC3 {name}: no address in config/symbols.{prog}.txt")
        elif int(h.group(1), 16) != addr:
            out.append(f"{rel}:{ln} DC3 {name}: header 0x{h.group(1)} != 0x{addr:08X}")
    # DC4
    bl = [BASISLINE.match(b) for b in block if b.startswith("// basis:")]
    bl = [m for m in bl if m]
    if not bl:
        out.append(f"{rel}:{ln} DC4 {name}: no `// basis:` line")
    else:
        kind, ref = bl[0].group(1), bl[0].group(2) or ""
        if kind == "none" and not ref:
            if not fm:
                out.append(f"{rel}:{ln} DC4 {name}: basis none only for a func_ name")
        elif len(ref) < 8:
            out.append(f"{rel}:{ln} DC4 {name}: basis ref under 8 chars")
        elif addr is not None and not any(p == prog and v == addr and k == kind and ref in r
                                          for p, v, k, r in basis):
            out.append(f"{rel}:{ln} DC4 {name}: no basis.tsv row {prog} 0x{addr:08X} {kind} holding the ref")
    # DC5
    cl = [CALLERS.match(b) for b in block if b.startswith("// callers:")]
    cl = [m for m in cl if m]
    if not cl:
        out.append(f"{rel}:{ln} DC5 {name}: no `// callers:` line")
    elif cl[0].group(1).strip() != "none known":
        bad = [c.strip() for c in cl[0].group(1).split(",")
               if not IDENT.match(c.strip()) or c.strip() not in names]
        if bad:
            out.append(f"{rel}:{ln} DC5 {name}: unknown caller {', '.join(bad)}")
    # DC7: optional `// reads:` notes in the header
    for b in block:
        if b.startswith("// reads:") and not READS.match(b):
            out.append(f"{rel}:{ln} DC7 {name}: `// reads:` not `Struct.field (+0xNN, type), role`")
    # DC6
    if addr is not None and (prog, addr) in strs and not any(re.match(r"^// str 0x[0-9A-F]{8} ", b) for b in block):
        out.append(f"{rel}:{ln} DC6 {name}: uses a game string, no `// str 0x<ADDR> ` line")
    return out


def check(root, paths):
    tables = load_tables(root)
    fails, n = [], 0
    for p in paths:
        rel = p
        path = root / p
        if not path.is_file():
            fails.append(f"{rel}:0 DC0 listed path does not exist")
            continue
        n += 1
        fails.extend("DOCCONV FAIL " + f for f in check_file(rel, path.read_text(encoding="utf-8",
                                                                                 errors="replace"), tables, root))
    fails = [f if f.startswith("DOCCONV FAIL ") else "DOCCONV FAIL " + f for f in fails]
    if fails:
        return fails, f"DOCCONV FAIL {len(fails)} refusals", 1
    return fails, f"DOCCONV OK {n} files", 0


def listed(root):
    p = root / LIST
    if not p.exists():
        return []
    return [s.strip() for s in p.read_text(encoding="utf-8").splitlines() if s.strip() and not s.startswith("#")]


def plant(base, files):
    if base.exists():
        shutil.rmtree(base)
    for rel, body in files.items():
        (base / rel).parent.mkdir(parents=True, exist_ok=True)
        (base / rel).write_text(body, encoding="utf-8")


GOOD = """\
// prog P | system test | range 0x80010000-0x80010100
// A planted file for the docconv self-test.
#include "common.h"

// The planted state, read by do_thing.
typedef struct Thing {
    int a; // set by do_thing
    int b; // unreferenced
} Thing;

int do_thing(Thing* t);

// put_thing: stores the planted field
static inline void put_thing(Thing* t) {
    t->a = 1;
}

// 0x80010000 do_thing: returns the planted field
// basis: x4 abcdef123456
// callers: func_80010040
// reads: Thing.a (+0x0, int), the returned value
int do_thing(Thing* t) {
    return t->a; // !FAKE: keeps the register order
}

// 0x80010040 func_80010040: calls the planted thing
// basis: none
// callers: none known
// str 0x80010050 sha1=0000000000000000000000000000000000000000 = "a test"
void func_80010040(void) {
    do_thing(0);
}

static inline int peek_thing(Thing* t) {
    return t->b;
}
"""
SHARED_LINE = "// Shared file: included by src/P/tu.c, between do_thing and func_80010040."
SHARED_TU = '#include "../shared/P/s.c"\n'
HEADER_H = "// prog P | system test | range -\nint do_thing(void* t);\n"
TREE = {
    "config/symbols.P.txt": "// planted\ndo_thing = 0x80010000;\nfunc_80010040 = 0x80010040;\ndo_thing2 = 0x80010080;\n",
    "config/symbols/basis.tsv": "# prog\tvram\tname\tbasis-kind\tbasis-ref\ttier\n"
                                "P\t0x80010000\tdo_thing\tx4\texact abcdef123456 planted/ref\tgate\n",
    "config/oracle.strnames.tsv": "# planted\n# unit\tvram\tname\nP\t0x80010040\tfunc_80010040\n",
}


def selftest():
    def mut(old, new):
        assert old in GOOD, old
        return GOOD.replace(old, new, 1)

    cases = [
        ("pass", None, []),
        ("DC0", None, ["src/none.c:0 DC0"]),
        ("DC1s", None, ["src/shared/P/s.c:1 DC1"]),
        ("DC1", mut("0x80010000-0x80010100", "0x80010100-0x80010000"), ["src/b.c:1 DC1"]),
        ("DC2", mut("// A planted file", "// Built in /tmp/x: a planted file"), ["src/b.c:2 DC2"]),
        ("DC3", mut("returns the planted field", "returns field"), ["src/b.c:22 DC3"]),
        ("DC4", mut("basis: x4 abcdef123456", "basis: x4 abcdef999999"), ["src/b.c:22 DC4"]),
        ("DC5", mut("callers: func_80010040", "callers: nosuch_fn"), ["src/b.c:22 DC5"]),
        ("DC6", mut("// str 0x80010050", "// st 0x80010050"), ["src/b.c:30 DC6"]),
        ("DC7", mut("// unreferenced", "// a field"), ["src/b.c:8 DC7"]),
        ("DC7r", mut("(+0x0, int), the", "(0x0) the"), ["src/b.c:22 DC7"]),
        ("DC3i", mut("// put_thing: stores the planted field", "// put_thing: stores it"), ["src/b.c:14 DC3"]),
        ("DC3s", mut("static inline void put_thing", "void put_thing"), ["src/b.c:14 DC3"]),
        ("DC3a", mut("static inline int peek_thing", "static inline int do_thing2"), ["src/b.c:34 DC3"]),
        ("DC8", mut("keeps the register order", "keeps order"), ["src/b.c:23 DC8"]),
    ]
    rc = 0
    try:
        for case, body, want in cases:
            files = dict(TREE)
            if case == "pass":
                files.update({"src/a.c": GOOD, "include/a.h": HEADER_H, "src/P/tu.c": SHARED_TU,
                              "src/shared/P/s.c": GOOD.replace("\n#include", "\n" + SHARED_LINE + "\n#include", 1)})
                paths = ["src/a.c", "include/a.h", "src/shared/P/s.c"]
            elif case == "DC0":
                paths = ["src/none.c"]
            elif case == "DC1s":
                files.update({"src/shared/P/s.c": GOOD, "src/P/tu.c": SHARED_TU})
                paths = ["src/shared/P/s.c"]
            else:
                files["src/b.c"] = body
                paths = ["src/b.c"]
            plant(SELFTEST, files)
            fails, summary, code = check(SELFTEST, paths)
            got = [" ".join(f[len("DOCCONV FAIL "):].split()[:2]) for f in fails]
            ok = got == want and code == (1 if want else 0)
            if case == "pass":
                ok = ok and summary == "DOCCONV OK 3 files"
            if not ok:
                print(f"DOCCONV CONTROL FAIL {case}")
                for line in fails + [summary]:
                    print(f"  {line}")
                rc = 1
    finally:
        shutil.rmtree(SELFTEST, ignore_errors=True)
    if rc == 0:
        print("DOCCONV CONTROL OK")
    return rc


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__.split("\n", 1)[0])
    ap.add_argument("--self-test", action="store_true", help="planted controls; ends DOCCONV CONTROL OK")
    ap.add_argument("--root", default=str(ROOT), help="repository root (default: this repo)")
    sub = ap.add_subparsers(dest="cmd")
    c = sub.add_parser("check", help="check the given paths, else those in config/docconv.txt")
    c.add_argument("paths", nargs="*")
    a = ap.parse_args(argv)
    if a.self_test:
        return selftest()
    if a.cmd == "check":
        root = Path(a.root).resolve()
        fails, summary, rc = check(root, a.paths if a.paths else listed(root))
        for line in fails + [summary]:
            print(line)
        return rc
    ap.print_help()
    return 2


if __name__ == "__main__":
    sys.exit(main())
