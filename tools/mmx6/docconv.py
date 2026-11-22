#!/usr/bin/env python3
"""docconv.py -- the documentation-convention check for src/ and include/ files (banner, function headers, usage notes).

  docconv.py [--root DIR] check [paths]
      -> applies DC1-DC8 to the given files (repo-relative), else to the paths listed in config/docconv.txt
         (`#` comment lines, one repo-relative path per line). Prints `DOCCONV FAIL <path>:<line> DC<k> <reason>` per
         refusal, then `DOCCONV OK <n> files` rc 0 or `DOCCONV FAIL <n> refusals` rc 1. A listed path that does not
         exist is a refusal (DC0). Then DC9 over every function header in src/: a mismatch in a checked path is a
         refusal (`DOCCONV FAIL ... DC9`, rc 1); elsewhere it prints `DOCCONV FACT <path>:<line> DC9 <kind> ...` and the
         line `DOCCONV FACTS <n> mismatches in <k> unlisted files`, rc unchanged.
  docconv.py [--root DIR] show <func>
      -> the function's facts (rule M30): address per prog, basis.tsv rows, relocdef aliases (config/us/dedup_registry.txt),
         purpose (config/symbols/notes.tsv), callers (jal) and refs (lui+addiu/ori) decoded as
         tools/mmx6/systems/callgraph.py does over build/us/corpus/functions.jsonl and the retail images
         (`callers: unavailable (no build/us/corpus)` without it), and each includer unit with the entries either side of
         the #include.
  docconv.py --self-test
      -> planted tree under .run/<phase>/docconv-selftest/ (removed at the end): one passing file exercising every rule
         (also as a shared file, a role file and its unit) and one failing file per rule (DC1: a shared file without
         its line, a role file no unit includes, a role file whose banner prog is not its unit's); DC9: a mini tree
         passing, one mismatch per fact kind, an unlisted mismatch, a restates_name pass/skip pair, and show with and
         without build/us/corpus. Ends `DOCCONV CONTROL OK` rc 0, or `DOCCONV CONTROL FAIL <case>` rc 1.

Rules (line refs 1-based)
  DC1 banner: exactly one leading comment line `// prog <P> | system <s> | range 0x<lo>-0x<hi>` (or `range -` in a .h);
      config/us/symbols.<P>.txt exists; lo <= hi (hi = the last instruction word, not end-exclusive). A file under
      src/shared/ also needs a leading `// Shared file: included by <TU>, between <A> and <B>.` line, the TU existing
      and naming the file in an #include. A role file (a .c under src/<dir>/ other than src/shared/, not itself a unit
      of config/c_units.txt) needs no `// Shared file:` line: some unit's #include closure (layout.includers) must
      reach it, and its banner prog must equal the prog of every unit that does.
  DC2 no build path: no comment line holds a drive path, /Users/ /home/ /work/ /tmp/ /sdk/ /disc/ /mnt/ /private/,
      or `Source:`.
  DC3 header: each file-scope function definition is preceded by a `//` block opening `// 0x<8 HEX> <name>: <purpose>`
      (address from config/us/symbols.<P>.txt or a func_ name; purpose >= 3 words). Exempt (with DC4-DC6): a `static inline`
      helper with no address (not in config/us/symbols.<P>.txt, no func_ name); it may carry a short header
      `// <name>: <purpose>` (name matches, purpose >= 3 words) or none. Preprocessor lines and their backslash
      continuations (a `#define` body) are not scanned for definitions; the passing planted file holds such a macro.
  DC4 basis: `// basis: <kind> <ref>` matching a config/symbols/basis.tsv row (prog, vram, kind; ref >= 8 chars inside
      basis-ref), or `// basis: none` for a func_ name.
  DC5 callers: `// callers: a, b` (names from any config/us/symbols.*.txt) or `// callers: none known`.
  DC6 string: a (prog, vram) row of config/oracle.strnames.tsv needs a `// str 0x<8 HEX> ` line in the block.
  DC7 usage notes: a struct definition is preceded by a `//` line with `read by ` or `used by `; each member line ends
      with a `//` comment holding `by <identifier>` or `unreferenced`. An optional `// reads: Struct.field (+0xNN, type),
      role` line in a function block notes a read of a generated struct's field; a malformed one is refused.
  DC8 FAKE: each `!FAKE:` is followed on its line by a reason of >= 3 words.
  DC9 facts (rule M30; the tables are the source, the header a copy): for each `// 0x<ADDR> <name>: <purpose>` line
      in src/, its block being it and the `//` lines below (prog from the path, src/shared/<P>/ included, else the banner, else the first
      includer unit prog naming it, by name, then address, then any for a func_ name): `address` the
      address and name equal config/us/symbols.<P>.txt (a func_ name not in it: its own hex); `basis` the block's
      `// basis: <kind> <ref>` has a basis.tsv row (prog, vram, name, kind) whose basis-ref holds ref, and `basis: none`
      a func_ name with no row at (prog, vram); `purpose` equals its config/symbols/notes.tsv row (prog, vram, name),
      or restates the name (restates_name) with no row.
"""
import argparse
import json
import re
import shutil
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import layout  # noqa: E402  (includers: the C units' #include closure)
sys.path.insert(0, str(Path(__file__).resolve().parent / "systems"))
import callgraph  # noqa: E402  (edges, image_word: the jal decode)
from paths import BUILD, EXTRACTED, CONFIG_V  # noqa: E402  (the version axis, 3.3 T37)

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
NOTES = "config/symbols/notes.tsv"
REGISTRY = CONFIG_V + "/dedup_registry.txt"
CORPUS = f"{BUILD}/corpus/functions.jsonl"

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
    for p in sorted((root / CONFIG_V).glob("symbols.*.txt")):
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


def role_file(rel):
    """A path that DC1 treats as a role file unless it is a unit: a .c under src/<dir>/, dir not shared."""
    return rel.endswith(".c") and rel.startswith("src/") and not rel.startswith("src/shared/") and rel.count("/") >= 2


def check_file(rel, text, tables, root=ROOT, inc=None):
    """inc: layout.includers of root (needed for a role file)."""
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
            fail(ln, 1, f"no {CONFIG_V}/symbols.{m.group(1)}.txt for prog {m.group(1)}")
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
    units = (inc or {}).get(rel, [])
    if role_file(rel) and not any(f"src/{p}/{tu}.c" == rel for p, tu in units):
        if not units:
            fail(1, 1, "role file included by no C unit (config/c_units.txt closure)")
        elif good and len(good) == 1:
            other = [f"{p}/{tu}" for p, tu in units if p != good[0][1].group(1)]
            if other:
                fail(good[0][0], 1, f"role file banner prog {good[0][1].group(1)}, included by {', '.join(other)}")

    depth, stmt, start, in_block, struct_depth, pp_cont = 0, None, 0, False, None, False
    for i, line in enumerate(lines):
        ln = i + 1
        if pp_cont:                                    # a backslash-continued preprocessor line (a #define body)
            pp_cont = line.rstrip().endswith("\\")
            continue
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
            pp_cont = line.rstrip().endswith("\\")
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
            out.append(f"{rel}:{ln} DC3 {name}: no address in {CONFIG_V}/symbols.{prog}.txt")
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
    inc = layout.includers(str(root)) if any(role_file(p) for p in paths) else {}
    for p in paths:
        rel = p
        path = root / p
        if not path.is_file():
            fails.append(f"{rel}:0 DC0 listed path does not exist")
            continue
        n += 1
        fails.extend("DOCCONV FAIL " + f for f in check_file(rel, path.read_text(encoding="utf-8",
                                                                                 errors="replace"), tables, root, inc))
    fails = [f if f.startswith("DOCCONV FAIL ") else "DOCCONV FAIL " + f for f in fails]
    if fails:
        return fails, f"DOCCONV FAIL {len(fails)} refusals", 1
    return fails, f"DOCCONV OK {n} files", 0


def listed(root):
    p = root / LIST
    if not p.exists():
        return []
    return [s.strip() for s in p.read_text(encoding="utf-8").splitlines() if s.strip() and not s.startswith("#")]


# ---- DC9 facts and show (rule M30, T34) ---------------------------------------------------------------------------

STOP = {"a", "an", "the", "of", "to", "for", "and", "or", "in", "on", "at", "by", "from", "with", "into", "its", "it",
        "is", "this", "that", "as"}


def restates_name(name, purpose):
    """True when the purpose only restates the name: its lowercase word tokens, less STOP, are all `_` tokens of name."""
    words = set(re.findall(r"[a-z0-9]+", purpose.lower())) - STOP
    return words <= set(name.lower().split("_"))


def tsv_rows(path, n):
    """The TAB rows (>= n fields) of a `#`-headed table, [] when it is missing."""
    if not path.exists():
        return []
    return [f for f in (ln.split("\t") for ln in path.read_text(encoding="utf-8", errors="replace").splitlines()
                        if ln and not ln.startswith("#")) if len(f) >= n]


def load_facts(root):
    """(syms, basis {(prog, vram): [(name, kind, ref, tier)]}, notes {(prog, vram): (name, purpose)})."""
    syms = load_tables(root)[0]
    basis, notes = {}, {}
    for f in tsv_rows(root / BASIS, 5):
        try:
            basis.setdefault((f[0], int(f[1], 16)), []).append((f[2], f[3], f[4], f[5] if len(f) > 5 else ""))
        except ValueError:
            continue
    for f in tsv_rows(root / NOTES, 4):
        try:
            notes[(f[0], int(f[1], 16))] = (f[2], f[3])
        except ValueError:
            continue
    return syms, basis, notes


def path_prog(rel, lines, syms):
    """The prog of a src/ file: src/<P>/ or src/shared/<P>/ when P has a symbols table, else the banner's, else None."""
    parts = rel.split("/")
    for p in (parts[1:2] + (parts[2:3] if parts[1:2] == ["shared"] else [])):
        if p in syms:
            return p
    for line in lines:
        m = BANNER.match(line.strip())
        if m and m.group(1) in syms:
            return m.group(1)
        if line.strip() and not line.strip().startswith("//"):
            break
    return None


def headers(root, syms):
    """(rel, line, prog, header addr, name, purpose, block from it down) for each `// 0x<ADDR> name: purpose` in src/."""
    out, inc = [], None
    for p in sorted((root / "src").rglob("*")):
        if p.suffix not in (".c", ".h") or not p.is_file():
            continue
        rel = p.relative_to(root).as_posix()
        lines = p.read_text(encoding="utf-8", errors="replace").splitlines()
        prog = None
        for i, line in enumerate(lines):
            h = HEAD.match(line.strip())
            if not h:
                continue
            j = i
            while j < len(lines) and lines[j].strip().startswith("//"):
                j += 1
            prog = prog or path_prog(rel, lines, syms)
            hp = prog
            if hp is None:   # no prog in the path or a banner: the includer unit progs, the one naming it first
                inc = inc if inc is not None else layout.includers(str(root))
                ps = sorted({p for p, _ in inc.get(rel, []) if p in syms})
                fm, a = FUNCNAME.match(h.group(2)), int(h.group(1), 16)
                hp = next((p for p in ps if h.group(2) in syms[p]), None) or \
                    next((p for p in ps if fm and a in syms[p].values()), None) or \
                    next((p for p in ps if fm), None)
            out.append((rel, i + 1, hp, int(h.group(1), 16), h.group(2), h.group(3),
                        [b.strip() for b in lines[i:j]]))
    return out


def fact_mismatches(prog, addr, name, purpose, block, syms, basis, notes):
    """[(kind, why)] of one header against the tables."""
    out = []
    table = syms.get(prog)
    if table is None:
        return [("address", f"{name}: no prog (path or banner) with a config/symbols table")]
    fm = FUNCNAME.match(name)
    want = table.get(name)
    if want is None and fm:
        want = int(fm.group(1), 16)
        if any(v == want for v in table.values()):
            out.append(("address", f"{name}: 0x{want:08X} has another name in {CONFIG_V}/symbols.{prog}.txt"))
    if want is None:
        out.append(("address", f"{name}: not in {CONFIG_V}/symbols.{prog}.txt"))
    elif want != addr:
        out.append(("address", f"{name}: header 0x{addr:08X} != table 0x{want:08X}"))
    v = want if want is not None else addr
    rows = basis.get((prog, v), [])
    bl = [m for m in (BASISLINE.match(b) for b in block if b.startswith("// basis:")) if m]
    if not bl:
        out.append(("basis", f"{name}: no `// basis:` line"))
    else:
        kind, ref = bl[0].group(1), bl[0].group(2) or ""
        if kind == "none" and not ref:
            if not fm:
                out.append(("basis", f"{name}: basis none for a non-placeholder name"))
            elif rows:
                out.append(("basis", f"{name}: basis none but basis.tsv has {len(rows)} row(s) at {prog} 0x{v:08X}"))
        elif not ref or not any(n == name and k == kind and ref in r for n, k, r, _ in rows):
            out.append(("basis", f"{name}: no basis.tsv row {prog} 0x{v:08X} {name} {kind} holding `{ref}`"))
    row = notes.get((prog, v))
    if row is not None:
        if row != (name, purpose):
            out.append(("purpose", f"{name}: header purpose != notes.tsv row ({row[0]}: {row[1]})"))
    elif not restates_name(name, purpose):
        out.append(("purpose", f"{name}: no notes.tsv row at {prog} 0x{v:08X} and the purpose is not the name"))
    return out


def facts(root, checked):
    """(refusals in checked paths, FACT lines elsewhere, summary line) of DC9 over every header in src/."""
    syms, basis, notes = load_facts(root)
    fails, other, files = [], [], set()
    for rel, ln, prog, addr, name, purpose, block in headers(root, syms):
        for kind, why in fact_mismatches(prog, addr, name, purpose, block, syms, basis, notes):
            if rel in checked:
                fails.append(f"DOCCONV FAIL {rel}:{ln} DC9 {kind} {why}")
            else:
                other.append(f"DOCCONV FACT {rel}:{ln} DC9 {kind} {why}")
                files.add(rel)
    return fails, other, f"DOCCONV FACTS {len(other)} mismatches in {len(files)} unlisted files"


def run_check(root, paths):
    """(printed lines, rc) of `check`: DC0-DC8 over the paths (else config/docconv.txt), then DC9 over src/."""
    paths = paths or listed(root)
    fails, summary, rc = check(root, paths)
    ff, other, fsum = facts(root, set(paths))
    if ff:
        fails, rc = fails + ff, 1
        summary = f"DOCCONV FAIL {len(fails)} refusals"
    return fails + other + [fsum, summary], rc


def show(root, func):
    """The lines of `show <func>`."""
    syms, basis, notes = load_facts(root)
    keys = sorted((p, t[func]) for p, t in syms.items() if func in t)
    fm = FUNCNAME.match(func)
    if not keys and fm:
        keys = sorted((p, int(fm.group(1), 16)) for p, t in syms.items() if p in func_progs(root, func))
    out = [f"show {func}"]
    out += [f"address {p} 0x{v:08X}" for p, v in keys] or ["address: none in config/us/symbols.*.txt"]
    rows = [(p, v, r) for (p, v), rs in sorted(basis.items()) for r in rs if r[0] == func]
    out += [f"basis {p} 0x{v:08X} {r[1]} {r[2]} [{r[3]}]" for p, v, r in rows] or ["basis: no basis.tsv row"]
    names = {(p, v): n for p, t in syms.items() for n, v in t.items()}
    pv = lambda s: (s.split(":")[0], int(s.split(":")[1], 16))
    nm = lambda s: names.get(pv(s), "?")
    al = []
    reg = root / REGISTRY
    for ln in (reg.read_text(encoding="utf-8", errors="replace").splitlines() if reg.exists() else []):
        f = ln.split()
        if ln.startswith("#") or len(f) < 6 or "relocdef" not in f[5:]:
            continue
        try:
            ex, mem = pv(f[1]), pv(f[3])
        except (IndexError, ValueError):
            continue
        if ex in keys or mem in keys:
            al.append(f"alias {f[3]} {nm(f[3])} of exemplar {f[1]} {nm(f[1])} ({f[2]}, {f[4]})")
    out += al or ["aliases: no relocdef row"]
    out += [f"purpose {p} 0x{v:08X} {notes[(p, v)][1]}" for p, v in keys if (p, v) in notes] \
        or ["purpose: no notes.tsv row (the name carries it)"]
    out += show_callers(root, keys)
    out += show_includers(root, func)
    return out


def func_progs(root, func):
    """Progs whose corpus names func (a placeholder not in any symbols table)."""
    c = root / CORPUS
    if not c.exists():
        return set()
    return {r["prog"] for r in map(json.loads, c.read_text().splitlines()) if r.get("name") == func}


def show_callers(root, keys):
    c = root / CORPUS
    if not c.exists():
        return [f"callers: unavailable (no {BUILD}/corpus)"]
    byprog = {}
    for r in map(json.loads, c.read_text().splitlines()):
        byprog.setdefault(r["prog"], {})[int(r["vram"], 16)] = r
    out = []
    for prog, v in keys:
        scan = sorted(byprog) if prog == callgraph.PROG else [prog]   # an overlay calls the exe; overlays share vram
        jc, rc, miss = [], [], []
        for q in scan:
            if q not in byprog:
                continue
            word = callgraph.image_word(q, str(root))
            if word is None:
                miss.append(q)
                continue
            jal, ref = callgraph.edges(byprog[q], word, {v})
            tag = "" if q == prog else f" ({q})"
            jc += [byprog[q][a]["name"] + tag for a in sorted(jal) if v in jal[a]]
            rc += [byprog[q][a]["name"] + tag for a in sorted(ref) if v in ref[a]]
        if prog not in byprog or v not in byprog[prog]:
            out.append(f"callers {prog} 0x{v:08X}: unavailable (not in {BUILD}/corpus)")
            continue
        out.append(f"callers {prog} 0x{v:08X}: " + (", ".join(jc) or "none decoded"))
        if rc:
            out.append(f"refs {prog} 0x{v:08X}: " + ", ".join(rc))
        if miss:
            out.append(f"callers {prog} 0x{v:08X}: no image for {', '.join(miss)}")
    return out


def show_includers(root, func):
    """Each file defining func (C body or INCLUDE_ASM) and, per unit reaching it, the entries either side of its #include."""
    tree = layout.Tree(str(root))
    defs = []
    for p in sorted((root / "src").rglob("*.c")):
        rel = p.relative_to(root).as_posix()
        if any(e.kind in ("def", "asm") and e.name == func for e in layout.parse(tree.lines(rel))):
            defs.append(rel)
    if not defs:
        return ["includers: no definition in src/"]
    inc = layout.includers(tree)
    label = lambda e: e.name if e.kind != "inc" else Path(e.target).name
    out = []
    for rel in defs:
        units = inc.get(rel, [])
        if not units:
            out.append(f"defined in {rel}: included by no C unit")
        for p, tu in units:
            if tree.unit_rel(p, tu) == rel:
                out.append(f"defined in {rel}: unit {p}/{tu} itself")
                continue
            for f in sorted(k for k, us in inc.items() if (p, tu) in us):
                ents = layout.parse(tree.lines(f))
                for i, e in enumerate(ents):
                    t = e.target if e.kind == "inc" and e.target.startswith("src/") else \
                        layout.norm(f, e.target) if e.kind == "inc" else None
                    if t == rel:
                        a = label(ents[i - 1]) if i else "(start)"
                        b = label(ents[i + 1]) if i + 1 < len(ents) else "(end)"
                        out.append(f"defined in {rel}: unit {p}/{tu} includes it at {f}:{e.first + 1}, "
                                   f"between {a} and {b}")
    return out


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

#define CLEAR(x)                                                               \\
    if (x) {                                                                   \\
        x = 0;                                                                 \\
    }
"""
SHARED_LINE = "// Shared file: included by src/P/tu.c, between do_thing and func_80010040."
SHARED_TU = '#include "../shared/P/s.c"\n'
ROLE_TU = '#include "sys/r.c"\n'                   # unit src/P/tu.c -> role file src/P/sys/r.c (layout L-B)
UNITS = "# planted\nP tu\n"
HEADER_H = "// prog P | system test | range -\nint do_thing(void* t);\n"
TREE = {
    CONFIG_V + "/symbols.P.txt": "// planted\ndo_thing = 0x80010000;\nfunc_80010040 = 0x80010040;\ndo_thing2 = 0x80010080;\n",
    "config/symbols/basis.tsv": "# prog\tvram\tname\tbasis-kind\tbasis-ref\ttier\n"
                                "P\t0x80010000\tdo_thing\tx4\texact abcdef123456 planted/ref\tgate\n",
    "config/oracle.strnames.tsv": "# planted\n# unit\tvram\tname\nP\t0x80010040\tfunc_80010040\n",
}
# DC9 and show: unit rock_99/tu (caller_fn, then shared do_thing, then tail_fn); caller_fn's first word is
# `jal do_thing` in a planted 0x20-byte image; do_thing is relocdef-aliased as rock_98 do_thing_b.
FACT_S = """\
// prog rock_99 | system test | range 0x80100010-0x80100014
// Shared file: included by src/rock_99/tu.c, between caller_fn and tail_fn.
// 0x80100010 do_thing: returns the planted field
// basis: x4 abcdef123456
// callers: caller_fn
int do_thing(int* t) {
    return *t;
}
"""
FACT_T = """\
// prog rock_99 | system test | range 0x80100018-0x8010001C
// 0x80100018 tail_fn: the tail fn
// basis: x4 123456abcdef
// callers: none known
void tail_fn(void) {
}
"""
FACT_TREE = {
    CONFIG_V + "/symbols.rock_99.txt": "caller_fn = 0x80100000;\ndo_thing = 0x80100010;\ntail_fn = 0x80100018;\n",
    CONFIG_V + "/symbols.rock_98.txt": "do_thing_b = 0x80100020;\n",
    "config/symbols/basis.tsv": "# prog\tvram\tname\tbasis-kind\tbasis-ref\ttier\n"
                                "rock_99\t0x80100010\tdo_thing\tx4\texact abcdef123456 planted/ref\tgate\n"
                                "rock_99\t0x80100018\ttail_fn\tx4\texact 123456abcdef planted/ref\tgate\n",
    "config/symbols/notes.tsv": "# prog\tvram\tname\tpurpose\nrock_99\t0x80100010\tdo_thing\treturns the planted field\n",
    CONFIG_V + "/dedup_registry.txt": "# planted\nk rock_99:0x80100010 src/shared/rock_99/s.c rock_98:0x80100020 gated "
                                 "define do_thing=do_thing_b via relocdef\n",
    "config/c_units.txt": "rock_99 tu\n",
    CONFIG_V + "/boundaries.txt": "# program rock_99 base 0x80100000 size 0x20\n",
    f"{BUILD}/corpus/functions.jsonl": "".join(
        f'{{"prog": "rock_99", "vram": "0x{a:08X}", "end": "0x{b:08X}", "name": "{n}"}}\n'
        for a, b, n in ((0x80100000, 0x80100010, "caller_fn"), (0x80100010, 0x80100018, "do_thing"),
                        (0x80100018, 0x80100020, "tail_fn"))),
    "src/rock_99/tu.c": '// prog rock_99 | system test | range 0x80100000-0x8010001C\n'
                        'INCLUDE_ASM("rock_99/nonmatchings/tu", caller_fn);\n\n'
                        '#include "../shared/rock_99/s.c"\n\n'
                        'INCLUDE_ASM("rock_99/nonmatchings/tu", tail_fn);\n',
    "src/shared/rock_99/s.c": FACT_S,
    "src/rock_99/t.c": FACT_T,
}
FACT_IMAGE = (0x0C040004).to_bytes(4, "little") + bytes(0x1C)      # jal 0x80100010, then nops
FACT_SHOW = [
    "address rock_99 0x80100010",
    "basis rock_99 0x80100010 x4 exact abcdef123456 planted/ref [gate]",
    "alias rock_98:0x80100020 do_thing_b of exemplar rock_99:0x80100010 do_thing (src/shared/rock_99/s.c, gated)",
    "purpose rock_99 0x80100010 returns the planted field",
    "callers rock_99 0x80100010: caller_fn",
    "defined in src/shared/rock_99/s.c: unit rock_99/tu includes it at src/rock_99/tu.c:4, between caller_fn and tail_fn",
]


def fact_selftest():
    """The DC9 and show controls; [failing case names]."""
    s, t = "src/shared/rock_99/s.c", "src/rock_99/t.c"
    cases = [
        ("F-pass", {}, {s, t}, [], 0),
        ("F-address", {s: FACT_S.replace("// 0x80100010", "// 0x80100014")}, {s, t}, [(s, "address")], 0),
        ("F-basis", {s: FACT_S.replace("x4 abcdef123456", "x4 abcdef999999")}, {s, t}, [(s, "basis")], 0),
        ("F-purpose", {s: FACT_S.replace("planted field", "planted value")}, {s, t}, [(s, "purpose")], 0),
        ("F-restate-skip", {t: FACT_T.replace("the tail fn", "ends the tail fn")}, {s, t}, [(t, "purpose")], 0),
        ("F-unlisted", {s: FACT_S.replace("// 0x80100010", "// 0x80100014")}, set(), [], 1),
    ]
    bad = []
    if not restates_name("tail_fn", "the tail fn") or restates_name("tail_fn", "ends the tail fn"):
        bad.append("F-restates_name")
    for case, mut, checked, want, nother in cases:
        plant(SELFTEST, {**FACT_TREE, **mut})
        fails, other, summary = facts(SELFTEST, checked)
        got = [(f.split()[2].rsplit(":", 1)[0], f.split()[4]) for f in fails]
        if got != want or len(other) != nother or \
                summary != f"DOCCONV FACTS {nother} mismatches in {nother} unlisted files":
            bad.append(case)
            print("\n".join(f"  {x}" for x in fails + other + [summary]))
    plant(SELFTEST, FACT_TREE)
    (SELFTEST / f"{EXTRACTED}/rock").mkdir(parents=True)
    (SELFTEST / f"{EXTRACTED}/rock/99.bin").write_bytes(FACT_IMAGE)
    got = show(SELFTEST, "do_thing")
    if [x for x in FACT_SHOW if x not in got]:
        bad.append("F-show")
        print("\n".join(f"  {x}" for x in got))
    (SELFTEST / CORPUS).unlink()
    got = show(SELFTEST, "do_thing")
    if f"callers: unavailable (no {BUILD}/corpus)" not in got:
        bad.append("F-show-nocorpus")
        print("\n".join(f"  {x}" for x in got))
    return bad


def selftest():
    def mut(old, new):
        assert old in GOOD, old
        return GOOD.replace(old, new, 1)

    cases = [
        ("pass", None, []),
        ("DC0", None, ["src/none.c:0 DC0"]),
        ("DC1s", None, ["src/shared/P/s.c:1 DC1"]),
        ("DC1r", None, ["src/P/sys/r.c:1 DC1"]),
        ("DC1p", None, ["src/P/sys/r.c:1 DC1"]),
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
                files.update({"src/a.c": GOOD, "include/a.h": HEADER_H, "src/P/tu.c": SHARED_TU + ROLE_TU,
                              "src/shared/P/s.c": GOOD.replace("\n#include", "\n" + SHARED_LINE + "\n#include", 1),
                              "config/c_units.txt": UNITS, "src/P/sys/r.c": GOOD})
                paths = ["src/a.c", "include/a.h", "src/shared/P/s.c", "src/P/sys/r.c"]
            elif case == "DC0":
                paths = ["src/none.c"]
            elif case == "DC1s":
                files.update({"src/shared/P/s.c": GOOD, "src/P/tu.c": SHARED_TU})
                paths = ["src/shared/P/s.c"]
            elif case == "DC1r":                           # a role file no unit includes
                files.update({"config/c_units.txt": UNITS, "src/P/tu.c": SHARED_TU, "src/P/sys/r.c": GOOD})
                paths = ["src/P/sys/r.c"]
            elif case == "DC1p":                           # banner prog P, included by a unit of prog Q
                files.update({"config/c_units.txt": "Q tu\n", "src/Q/tu.c": '#include "../P/sys/r.c"\n',
                              "src/P/sys/r.c": GOOD})
                paths = ["src/P/sys/r.c"]
            else:
                files["src/b.c"] = body
                paths = ["src/b.c"]
            plant(SELFTEST, files)
            fails, summary, code = check(SELFTEST, paths)
            got = [" ".join(f[len("DOCCONV FAIL "):].split()[:2]) for f in fails]
            ok = got == want and code == (1 if want else 0)
            if case == "pass":
                ok = ok and summary == "DOCCONV OK 4 files"
            if not ok:
                print(f"DOCCONV CONTROL FAIL {case}")
                for line in fails + [summary]:
                    print(f"  {line}")
                rc = 1
        for case in fact_selftest():
            print(f"DOCCONV CONTROL FAIL {case}")
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
    s = sub.add_parser("show", help="a function's facts: addresses, basis, aliases, purpose, callers, includers")
    s.add_argument("func")
    a = ap.parse_args(argv)
    if a.self_test:
        return selftest()
    if a.cmd == "check":
        lines, rc = run_check(Path(a.root).resolve(), a.paths)
        for line in lines:
            print(line)
        return rc
    if a.cmd == "show":
        for line in show(Path(a.root).resolve(), a.func):
            print(line)
        return 0
    ap.print_help()
    return 2


if __name__ == "__main__":
    sys.exit(main())
