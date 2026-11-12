#!/usr/bin/env python3
"""layout.py -- one function-to-file locator over the C units' #include closure, the role-file layout map
config/layout.tsv (scheme L-B, phase 2.4 T4) and its applier (host PY or container python3, stdlib only).

  Library: locate(prog, func) -> (path, line_first, line_last, unit) | None; unit_of(prog, func) -> unit | None.
      func = a name or an int vram. Units in config/c_units.txt order; each unit's #include closure in textual
      order, paths relative to the including file (as cpp). A C function's range = its definition line through its
      column-0 `}`; an asm function's range = its INCLUDE_ASM line; an alias block (`#define <body def> <name>`
      before a body include, C0225) names the body's definition by the define target. Lines 1-based, path relative
      to the repo root, unit = the tu name. Same answer on the old layout (unit -> src/shared bodies) and on L-B
      (unit -> role files -> src/shared runs).
      includers(root) -> {path: [(prog, tu)]}: the units whose closure reaches each file (2.4 T6: docconv,
      namesqueue, renamecov, readcensus take a file's program from it, not from its path).
      Bank path (T5): asm_line(prog, tu, func) the one INCLUDE_ASM literal; find_asm(prog, func) -> (path, line, tu) |
      None (func's INCLUDE_ASM line, unit or role file); new_body(prog, func) the path of a newly drafted body
      (src/shared/<prog>/<func>.c); role_tree(prog, tu) a self-test context manager: the unit becomes a thin
      `#include "selftest_role/<tu>.c"` over one role file (token-identical; unit restored, sums checked on exit).

  layout.py propose
      -> writes config/layout.tsv for every program of c_units.txt. Rows `prog unit file first_vram last_vram
         system`, sorted by (prog, unit, first_vram, file). Role rows (file under src/<prog>/): a role file = a
         maximal contiguous run of one system in one unit (a run continues only while the system is equal); system
         of a named function = the longest docs/glossary.md "Our stem" equal to a run of the `_`-tokens of the name
         after its first (verb) token, else the whole name when it is a stem held by a docs/layout.md "## SLUS
         systems" row (T24: memcard_format), else its noun (those tokens joined by `_`; a one-token name: itself); a run of
         placeholder names (func_, D_) is its own run, named `<first vram 8hex>.c` (system `-`); an entry of static
         helpers only joins the run after it (the run before it at unit end); a name collision in one dir adds
         `_<first vram 8hex>`. Overlays: flat in src/<prog>/; SLUS_013.95: src/SLUS_013.95/<folder>/<system>.c, folder =
         the "## SLUS systems" row holding the stem (system `-`: flat), LIB* units under psyq/; a stem in no row:
         `LAYOUT unknown-system SLUS_013.95 <stem> <unit file>`, rc 1, nothing written. An applied (L-B) program is read with its role files
         inlined (its old role names may be reused). Shared rows (file under src/shared/, one per member and site): a twin = a body included at more
         than one site; consecutive plain twin includes with the same member set, same order and only blank lines
         between in every member (and inside one role run in each) collapse into src/shared/<system>/<first
         func>.c; any other twin stays single as src/shared/<system>/<func>.c; a twin with no system keeps its
         directory (a single keeps its path); src/shared/entity/ and src/shared/_selftest/ never move.
         vram: func_/D_<8hex> names, config/symbols.<prog>.txt, dedup_registry `member prog:vram` of the body,
         build/<prog>.map; never guessed. Prints per program `LAYOUT <prog> role_files <n> one_function <k>
         twin_collapse <c> twin_single <s>`, the single reasons, and `LAYOUT PROPOSE programs <n> ...`; rc 1 and
         nothing written on any unresolved vram (`LAYOUT unresolved <prog> <name> <path>:<line>`).
  layout.py apply --prog <p> [--dry-run]
      -> from layout.tsv: writes p's role files (entries verbatim in unit order: bodies with their preambles,
         INCLUDE_ASM lines, unit lines between entries; INCLUDE_ASM groups fenced `// clang-format off/on`, C0281),
         rewrites each unit to `#include "common.h"` + its leading lines + its role includes, writes shared files,
         deletes an old body (or old role file) no unit still includes, appends config/layout-moves.tsv rows
         `old_path old_first old_last new_path new_first prog`. Re-applies an L-B program: every unit is read through
         its role files before any write (old and new paths may coincide). Staged in .run/<phase>/layout/<p>/ (a copy of src/ + include/); token check per
         unit first: Makefile `$(CPP) $(CPPFLAGS)` (+ -DMMX6_OVERLAY for rock_*) output, `#` lines and blank lines
         dropped, identical old vs new, else nothing is written, rc 1. --dry-run stops after the check and report.
         The stage dir is deleted at the end.
  layout.py repoint [--dry-run] [files...]
      -> rewrites `path:N` (N inside a moved range) and bare paths (moved whole to one file) through the pending
         rows of config/layout-moves.tsv (6-column rows after the last `# repointed` line); a real run over the
         default files (the citation tables, CITES below) then appends `# repointed`, so a second run maps nothing
         (each cite moves once). A bare path whose rows have several destinations (a split file) maps to the one
         holding a `prog:0x<vram>` named on the same text line (dedup_registry rows), else stays unmapped. Stale
         fallback (T17): a stale cite (see check) no pending row maps: old text = git line N of the path at the last
         commit where it existed; destination = locate(prog, func) (prog = the path's src/shared/<prog>/ or
         src/<prog>/ dir, else a prog:0x<vram> on the line, else the config/symbols.<prog>.txt file's; func = the stem
         func_<8hex> -> vram, else the stem name, else the `via=` anchor, else that prog:0x<vram>); a bare path -> the
         function's file; new N (and M of `:N-M`) = the one line of its range (preamble included) whose stripped text
         equals the old line and (N) holds the via anchor; none or several -> unmapped. A cite-anchor cite (see check)
         takes the same rule, its old text = line N of the path at the newest commit (git log of the path, walked
         back from the commit that last wrote the citing line, git blame) where line N held \\b<a>\\b, and func
         first = the def of that old text holding line N (preamble included; the anchor is often a global or a
         callee). New N, in order (T17.c2): R1 that exact unique line; R2 a run of 1..4 lines equal to it minus
         whitespace (reflow) -> the run's line holding the anchor; R3 several R1/R2 hits -> the nearest to N (a tie
         refused); R4 (no old text, or nothing found) the one non-`//` line holding the anchor in the current file
         (a cite-anchor cite's own), else in the C function enclosing N: one, or the nearest (a tie refused). Prints
         `LAYOUT REPOINT <cfg>:<line> <src>:<old> -> [<dest>]:<new> rule=R<k> | <line>` per fallback map, then
         per-file counts.
  layout.py check [--prog p]
      -> one token per defect, rc 1 if any: `LAYOUT CHECK out-of-order|duplicate|duplicate-row|split <prog>
         <unit> <what>`: vram not increasing along a unit's closure; a function twice in a unit, or one vram in two
         role (or two shared) rows of one prog in layout.tsv; two adjacent role files of a unit with one system, or
         one role file included twice. Without --prog, a cite pass (T17) over CITES + config/symbols.*.txt +
         docs/ops/*.md + docs/*.md, less the ledgers config/psxdecomp.toml [own]/[trial]/[floor]/[debt] names (the
         commit gate keeps their lines, e.g. docs/ops/campaign.md): `LAYOUT CHECK stale-cite <file>:<n> <cite>` for a src/shared/** or
         src/<c_units prog>/** path (bare or :N) not on disk (src/shared/_selftest/, src/main/ and templated
         <>{}* paths skipped); `LAYOUT CHECK cite-anchor <file>:<n> <cite>` when `<path>:N via=<a>` is on disk but
         line N lacks \\b<a>\\b. Last line `LAYOUT CHECK <n> defects`.
  layout.py --self-test
      -> plants an old-layout tree under .run/<phase>/layout-selftest/ (never src/), makes its L-B equivalent with
         propose + apply, compares locate on both (same function, range text, unit), the same on a role_tree plant
         (`LAYOUT self-test role-tree pass ...`; find_asm lands in the role file), refuses three check plants,
         runs apply --dry-run and repoint --dry-run on the plant (token check skipped with a note only when no cpp
         is found); plants each T15.1 rule (placeholder run by vram, adjacent systems split, equal join, noun
         fallback, SLUS folder = the system holding the stem, whole-name stem, an unknown SLUS stem refused with
         nothing written), re-applies the applied plant after a glossary change (role file reused,
         one deleted) and repoints twice (the second maps 0); plants a body renamed in a scratch git repo with one
         stale cite and one cite-anchor cite (its file gains a line in git; both reported, repoint maps both, check
         then clean). Ends `LAYOUT CONTROL OK` rc 0, else `LAYOUT CONTROL FAIL <why>` rc 1; deletes its scratch dir.
  Firewall G12: prints names, paths and counts only, never bytes.
"""
import argparse
import contextlib
import glob
import os
import re
import shutil
import subprocess
import sys

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))


def _phase_run():
    """The open phase's temp folder, relative (`# Phase <id>` line 1 of the live plan, as tools/run.sh), else .run."""
    try:
        with open(os.path.join(ROOT, "phase-ends/current/PHASE_PLAN.md")) as f:
            line = f.readline()
    except OSError:
        line = ""
    m = re.match(r"#\s*Phase\s+([A-Za-z0-9._-]+)", line)
    return ".run" if not m or m.group(1) in (".", "..") else os.path.join(".run", m.group(1))


RUN = _phase_run()
FIXED = ("src/shared/entity/", "src/shared/_selftest/")
CITES = ["config/symbols/basis.tsv", "config/dedup_registry.txt", "config/names-verdicts.tsv",
         "config/x4/renames.tsv", "config/symbols.SLUS_013.95.txt", "config/ghidra/SLUS_013.95.jsonl",
         "docs/leads/assets.tsv", "config/x4/hold.tsv", "config/docconv.txt"]
EXE = "SLUS_013.95"
HEADER = ("# config/layout.tsv -- L-B role-file map (tools/mmx6/layout.py propose; generated, never hand-edited).\n"
          "# Role rows: file under src/<prog>/; shared rows: file under src/shared/, one per member site.\n"
          "# prog\tunit\tfile\tfirst_vram\tlast_vram\tsystem\n")
MOVES_HEADER = ("# config/layout-moves.tsv -- layout.py apply moves (append-only)\n"
                "# old_path\told_first\told_last\tnew_path\tnew_first\tprog (5-column rows: 2.4 T15, repointed)\n"
                "# `# repointed` = the rows above are repointed; repoint maps only the 6-column rows after the last one\n")
REPOINTED = "# repointed"

ASM_RE = re.compile(r'^INCLUDE_ASM\("[^"]*", *(\w+)\);')
INC_RE = re.compile(r'^#include "([^"]+\.c)"\s*$')
DEFINE_RE = re.compile(r'^#define\s+(\w+)\s+(\w+)\s*$')
UNDEF_RE = re.compile(r'^#undef\s+(\w+)\s*$')
HEAD_RE = re.compile(r'^(?:static\s+|inline\s+)*[A-Za-z_][\w \t\*]*?\b([A-Za-z_]\w*)\s*\(')
FENCE_RE = re.compile(r'^// clang-format (?:off|on)\s*$')
HEXNAME_RE = re.compile(r'^(?:func|D)_([0-9A-Fa-f]{8})$')
SYM_RE = re.compile(r'^\s*([A-Za-z_]\w*)\s*=\s*0x([0-9A-Fa-f]+)\s*;')
MAP_RE = re.compile(r'^\s+0x([0-9A-Fa-f]+)\s+([A-Za-z_]\w*)\s*$')
PROGVRAM_RE = re.compile(r'\b([A-Za-z]\w*(?:\.\d+)?):0x([0-9A-Fa-f]{8})\b')
CITE_RE = re.compile(r'(src/[A-Za-z0-9_./-]*?\.c)(?![A-Za-z0-9_])(?::(\d+))?')
CITE_RANGE_RE = re.compile(r'(src/[A-Za-z0-9_./-]*?\.c)(?![A-Za-z0-9_])(?::(\d+)(?:-(\d+))?)?')  # T17: `path:N-M` (M kept as is by the move path)
VIA_RE = re.compile(r'\s+via=(\w+)')


class Refuse(Exception):
    pass


class Fn:
    __slots__ = ("name", "defname", "path", "first", "last", "kind", "vram", "static")

    def __init__(self, name, defname, path, first, last, kind):
        self.name, self.defname, self.path, self.first, self.last, self.kind = name, defname, path, first, last, kind
        self.vram = None
        self.static = False


class Entry:
    """A top-level chunk of a file: asm (INCLUDE_ASM line), def (C definition), inc (optional #define lines, a .c
    include, #undef lines). first/last 0-based line indexes; fns = the functions it brings (recursive)."""
    __slots__ = ("kind", "first", "last", "name", "target", "ndef", "fns", "vram", "system")

    def __init__(self, kind, first, last, name=None, target=None, ndef=0):
        self.kind, self.first, self.last, self.name, self.target, self.ndef = kind, first, last, name, target, ndef
        self.fns, self.vram, self.system = [], None, None


def cdef(lines, i):
    """(name, last line) of a C definition starting at line i, else None."""
    l = lines[i]
    if not (l[:1].isalpha() or l[:1] == "_") or l.startswith(("extern ", "typedef ")):
        return None
    m = HEAD_RE.match(l)
    if not m:
        return None
    depth, j, pos = 0, i, m.end() - 1
    while j < len(lines) and j < i + 40:
        s = lines[j]
        k = pos if j == i else 0
        while k < len(s):
            c = s[k]
            if c == "(":
                depth += 1
            elif c == ")":
                depth -= 1
            elif depth == 0 and c in ";=":
                return None
            elif depth == 0 and c == "{":
                rest = s[k:]
                if rest.count("{") == rest.count("}"):
                    return m.group(1), j
                e = j + 1
                while e < len(lines) and not lines[e].startswith("}"):
                    e += 1
                if e >= len(lines):
                    return None
                return m.group(1), e
            k += 1
        j += 1
    return None


def parse(lines):
    """[Entry] of a file's lines (fns not filled)."""
    out, i, n = [], 0, len(lines)
    while i < n:
        l = lines[i]
        m = ASM_RE.match(l)
        if m:
            out.append(Entry("asm", i, i, name=m.group(1)))
            i += 1
            continue
        if DEFINE_RE.match(l) or INC_RE.match(l):
            j = i
            while j < n and DEFINE_RE.match(lines[j]):
                j += 1
            m = INC_RE.match(lines[j]) if j < n else None
            if m:
                k = j + 1
                while k < n and UNDEF_RE.match(lines[k]):
                    k += 1
                out.append(Entry("inc", i, k - 1, target=m.group(1), ndef=j - i))
                i = k
                continue
        d = cdef(lines, i)
        if d:
            out.append(Entry("def", i, d[1], name=d[0]))
            i = d[1] + 1
            continue
        i += 1
    return out


def norm(base, rel):
    return os.path.normpath(os.path.join(os.path.dirname(base), rel)).replace(os.sep, "/")


def rel_from(frm, to):
    return os.path.relpath(to, os.path.dirname(frm)).replace(os.sep, "/")


class Tree:
    """A repo-shaped root: src/, include/, config/, docs/glossary.md, Makefile."""

    def __init__(self, root=ROOT, cfg=None):
        self.root, self.cfg = root, cfg or root
        self._lines, self._ents, self._res, self._stems, self._systems = {}, {}, {}, None, None

    def path(self, rel):
        return os.path.join(self.root, rel)

    def exists(self, rel):
        return os.path.isfile(self.path(rel))

    def lines(self, rel):
        if rel not in self._lines:
            with open(self.path(rel), errors="replace") as f:
                t = f.read()
            self._lines[rel] = t[:-1].split("\n") if t.endswith("\n") else t.split("\n")
        return self._lines[rel]

    def units(self, prog=None):
        out = []
        with open(os.path.join(self.cfg, "config", "c_units.txt")) as f:
            for l in f:
                w = l.split()
                if len(w) == 2 and not l.startswith("#") and (prog is None or w[0] == prog):
                    out.append((w[0], w[1]))
        return out

    def progs(self):
        seen = []
        for p, _ in self.units():
            if p not in seen:
                seen.append(p)
        return seen

    def entries(self, rel, amap=None, ctx=None):
        """[Entry] of rel with fns filled (closure walked), amap = the defines in force at its top; ctx = the
        program (Fn objects carry its vrams)."""
        amap = dict(amap or {})
        key = (rel, tuple(sorted(amap.items())), ctx)
        if key in self._ents:
            return self._ents[key]
        lines, ents = self.lines(rel), parse(self.lines(rel))
        starts = {e.first: e for e in ents}
        i = 0
        while i < len(lines):
            e = starts.get(i)
            if e is None:
                m, u = DEFINE_RE.match(lines[i]), UNDEF_RE.match(lines[i])
                if m:
                    amap[m.group(1)] = m.group(2)
                elif u:
                    amap.pop(u.group(1), None)
                i += 1
                continue
            if e.kind == "inc":
                local = dict(amap)
                for l in lines[e.first:e.first + e.ndef]:
                    m = DEFINE_RE.match(l)
                    local[m.group(1)] = m.group(2)
                e.target = norm(rel, e.target) if not e.target.startswith("src/") else e.target
                if not self.exists(e.target):
                    raise Refuse("missing-include %s:%d %s" % (rel, e.first + 1, e.target))
                e.fns = [f for x in self.entries(e.target, local, ctx) for f in x.fns]
            else:
                e.fns = [Fn(amap.get(e.name, e.name), e.name, rel, e.first, e.last, e.kind)]
                e.fns[0].static = e.kind == "def" and lines[e.first].startswith("static")
            i = e.last + 1
        self._ents[key] = ents
        return ents

    def unit_rel(self, prog, tu):
        return "src/%s/%s.c" % (prog, tu)

    def fns(self, prog, tu):
        return [f for e in self.entries(self.unit_rel(prog, tu), ctx=prog) for f in e.fns]

    def resolver(self, prog):
        if prog not in self._res:
            self._res[prog] = Resolver(self, prog)
        return self._res[prog]

    def stems(self):
        if self._stems is None:
            self._stems = glossary_stems(os.path.join(self.cfg, "docs", "glossary.md"))
        return self._stems

    def systems(self):
        if self._systems is None:
            self._systems = slus_systems(os.path.join(self.cfg, "docs", "layout.md"))
        return self._systems

    def closure(self):
        """Every file reached from any unit."""
        seen, todo = set(), [self.unit_rel(p, t) for p, t in self.units()]
        while todo:
            r = todo.pop()
            if r in seen or not self.exists(r):
                continue
            seen.add(r)
            for e in parse(self.lines(r)):
                if e.kind == "inc":
                    todo.append(norm(r, e.target))
        return seen


class Flat(Tree):
    """The tree with each L-B unit read as if its role files were inlined (T15.1: propose and apply re-split an
    applied program). A role include = a unit's `.c` include outside src/shared/; its lines replace the include line,
    relative `.c` includes rebased to the unit, a blank line before each when the previous line is not blank.
    origin[unit] = per virtual line (path, 0-based line) or None (synthesized); roles[unit] = the inlined role files."""

    def __init__(self, root=ROOT, cfg=None):
        Tree.__init__(self, root, cfg)
        self.origin, self.roles, self._unitrels = {}, {}, None

    def lines(self, rel):
        if self._unitrels is None:
            self._unitrels = {self.unit_rel(p, t) for p, t in self.units()}
        if rel in self._lines or rel not in self._unitrels:
            return Tree.lines(self, rel)
        real, out, org, roles = Tree.lines(self, rel), [], [], []
        for j, l in enumerate(real):
            m = INC_RE.match(l)
            t = (m.group(1) if m.group(1).startswith("src/") else norm(rel, m.group(1))) if m else None
            if t is None or t.startswith("src/shared/") or not self.exists(t):
                out.append(l)
                org.append((rel, j))
                continue
            if out and out[-1].strip():
                out.append("")
                org.append(None)
            for i, rl in enumerate(Tree.lines(self, t)):
                m2 = INC_RE.match(rl)
                if m2 and not m2.group(1).startswith("src/"):
                    rl = '#include "%s"' % rel_from(rel, norm(t, m2.group(1)))
                out.append(rl)
                org.append((t, i))
            roles.append(t)
        if roles:
            self._lines[rel], self.origin[rel], self.roles[rel] = out, org, roles
        return self._lines[rel]


class Resolver:
    def __init__(self, tree, prog):
        self.prog, self.sym, self.reg, self.map = prog, {}, {}, {}
        p = os.path.join(tree.cfg, "config", "symbols.%s.txt" % prog)
        if os.path.isfile(p):
            with open(p, errors="replace") as f:
                for l in f:
                    m = SYM_RE.match(l)
                    if m:
                        self.sym.setdefault(m.group(1), int(m.group(2), 16))
        p = os.path.join(tree.cfg, "config", "dedup_registry.txt")
        if os.path.isfile(p):
            with open(p, errors="replace") as f:
                for l in f:
                    w = l.split()
                    if len(w) >= 4 and not l.startswith("#") and ":" in w[3]:
                        mp, mv = w[3].split(":", 1)
                        if mp == prog:
                            self.reg.setdefault(w[2], set()).add(int(mv, 16))
        p = os.path.join(tree.root, "build", "%s.map" % prog)
        if os.path.isfile(p):
            with open(p, errors="replace") as f:
                for l in f:
                    m = MAP_RE.match(l)
                    if m:
                        self.map.setdefault(m.group(2), int(m.group(1), 16))

    def vram(self, fn, nfns_in_body):
        m = HEXNAME_RE.match(fn.name)
        if m:
            return int(m.group(1), 16)
        if fn.name in self.sym:
            return self.sym[fn.name]
        r = self.reg.get(fn.path)
        if r and len(r) == 1 and nfns_in_body == 1:
            return next(iter(r))
        return self.map.get(fn.name)


def glossary_stems(path):
    stems, col = set(), None
    if not os.path.isfile(path):
        return stems
    with open(path) as f:
        terms = False
        for l in f:
            if l.startswith("## "):
                terms = l.strip() == "## Terms"
                continue
            if not terms or not l.startswith("|"):
                continue
            cells = [c.strip().strip("`") for c in l.strip().strip("|").split("|")]
            if col is None:
                col = cells.index("Our stem") if "Our stem" in cells else None
                continue
            if col < len(cells) and cells[col] and not cells[col].startswith("-") and "<" not in cells[col]:
                stems.add(cells[col])
    return stems


def slus_systems(path):
    """{stem: system} of docs/layout.md `## SLUS systems` (table `| system | holds | stems |`, T24)."""
    out = {}
    if not os.path.isfile(path):
        return out
    with open(path) as f:
        on = False
        for l in f:
            if l.startswith("## "):
                on = l.strip() == "## SLUS systems"
                continue
            cells = [c.strip() for c in l.strip().strip("|").split("|")]
            if not on or not l.startswith("|") or len(cells) < 3 or cells[1] == "holds" or cells[0][:1] in ("-", ""):
                continue
            for s in cells[2].split(","):
                out[s.strip().strip("`")] = cells[0]
    return out


def system_of(name, stems, whole=()):
    """Placeholder (func_, D_) -> None; else the longest glossary stem among the tokens after the verb; else the noun
    (the tokens after the verb, a one-token name itself) (T15.1); with no stem after the verb, a name that is itself a
    stem held by a SLUS system (whole = docs/layout.md ## SLUS systems) is its own system (T24: memcard_format,
    task_yield; a glossary row naming a whole verb-led function, start_player_attack, keeps its noun)."""
    if name.startswith(("func_", "D_")):
        return None
    rest = name.split("_")[1:]
    best = None
    for i in range(len(rest)):
        for j in range(len(rest), i, -1):
            s = "_".join(rest[i:j])
            if s in stems:
                k = (j - i, len(s), -i, s)
                if best is None or k > best[0]:
                    best = (k, s)
                break
    if best is None and name in stems and name in whole:
        return name
    return best[1] if best else ("_".join(rest).strip("_") or name)


def entry_system(e, stems, whole=()):
    """An entry's system: its first non-static named function's; None (placeholder: own run); "" when it brings only
    static helpers (they precede their user: join the run after them, the run before them at unit end)."""
    live = [f for f in e.fns if not f.static]
    if not live and e.fns:
        return ""
    return next((s for s in (system_of(f.name, stems, whole) for f in live) if s), None)


def resolve_unit(tree, prog, tu, unresolved):
    """Top-level entries of a unit with vrams and systems filled."""
    rel = tree.unit_rel(prog, tu)
    ents, res, stems = tree.entries(rel, ctx=prog), tree.resolver(prog), tree.stems()
    for e in ents:
        for f in e.fns:
            if f.vram is None:
                n = sum(1 for g in e.fns if g.path == f.path)
                f.vram = res.vram(f, n)
                if f.vram is None and not f.static:  # a static helper has no address of its own
                    unresolved.append("%s %s %s:%d" % (prog, f.name, f.path, f.first + 1))
        if not e.fns:
            unresolved.append("%s <no-function-include> %s:%d" % (prog, rel, e.first + 1))
        e.vram = next((f.vram for f in e.fns if f.vram is not None), None)
        e.system = entry_system(e, stems, tree.systems())
    return ents


def runs_of(ents):
    """[[system, [entry index]]] of a unit (scheme L-B): a run continues only while the system is equal; a placeholder
    run (system None) is its own run; static-only entries join the run after them (before them at unit end)."""
    runs, pending = [], []
    for i, e in enumerate(ents):
        if e.system == "":
            pending.append(i)
        elif runs and runs[-1][0] == e.system:
            runs[-1][1].extend(pending + [i])
            pending = []
        else:
            runs.append([e.system, pending + [i]])
            pending = []
    if pending:
        if runs:
            runs[-1][1].extend(pending)
        else:
            runs = [[None, pending]]
    return runs


def hx(v):
    return "%08X" % v


def fixed(path):
    return path.startswith(FIXED)


# ---- propose -------------------------------------------------------------------------------------------------------

def plan(tree):
    """(rows, report lines, unresolved)."""
    tree = tree if isinstance(tree, Flat) else Flat(tree.root, tree.cfg)
    unresolved, unknown, U = [], [], {}
    for prog, tu in tree.units():
        U[(prog, tu)] = resolve_unit(tree, prog, tu, unresolved)
    if unresolved:
        return None, [], unresolved
    order = list(U)
    runs, runidx = {}, {}
    for k in order:
        runs[k] = runs_of(U[k])
        runidx[k] = {i: r for r, (_, idx) in enumerate(runs[k]) for i in idx}
    sites = {}
    for k in order:
        for i, e in enumerate(U[k]):
            if e.kind == "inc":
                sites.setdefault(e.target, []).append((k, i))
    twin = {p for p, s in sites.items() if len(s) > 1 or fixed(p)}

    def blank_between(k, i):
        ents, lines = U[k], tree.lines(tree.unit_rel(*k))
        return all(not l.strip() for l in lines[ents[i].last + 1:ents[i + 1].first])

    def nxt(path, why):
        """The body following path in every member, or None with why[0] set."""
        ss = sites[path]
        mem = {k for k, _ in ss}
        if fixed(path) or len(mem) != len(ss):
            why[0] = "fixed dir" if fixed(path) else "repeated in a unit"
            return None
        if any(U[k][i].ndef for k, i in ss):
            why[0] = "alias block (C0225)"
            return None
        cand = None
        for k, i in ss:
            ents = U[k]
            if i + 1 >= len(ents):
                why[0] = "unit end"
                return None
            e2 = ents[i + 1]
            if runidx[k][i + 1] != runidx[k][i]:
                why[0] = "role run end"
                return None
            if e2.kind == "asm":
                why[0] = "asm between"
                return None
            if e2.kind == "def":
                why[0] = "C between"
                return None
            if e2.ndef:
                why[0] = "alias block (C0225)"
                return None
            if e2.target not in twin or fixed(e2.target):
                why[0] = "neighbour single-site"
                return None
            if cand is None:
                cand = e2.target
            if e2.target != cand or {x for x, _ in sites[cand]} != mem or len(sites[cand]) != len(ss):
                why[0] = "neighbours differ"
                return None
            if not blank_between(k, i):
                why[0] = "lines between"
                return None
        return cand

    trun, done = [], set()   # [(paths, reason or None)]
    for k in order:
        for i, e in enumerate(U[k]):
            if e.kind != "inc" or e.target not in twin or e.target in done:
                continue
            paths, why = [e.target], [None]
            while True:
                n = nxt(paths[-1], why)
                if n is None or n in done or n in paths:
                    break
                paths.append(n)
            done.update(paths)
            trun.append((paths, None if len(paths) > 1 else why[0]))
    # shared paths
    taken = set()
    for root, _, files in os.walk(tree.path("src")):
        for fn in files:
            taken.add(os.path.relpath(os.path.join(root, fn), tree.root).replace(os.sep, "/"))
    shared = {}
    for paths, why in trun:
        k0, i0 = sites[paths[0]][0]
        e0 = U[k0][i0]
        system = runs[k0][runidx[k0][i0]][0]
        if fixed(paths[0]) or (system is None and len(paths) == 1):
            shared[paths[0]] = (paths[0], system)
            continue
        d = "src/shared/%s" % system if system else os.path.dirname(paths[0])
        name = os.path.basename(paths[0])[:-2] if system is None else e0.fns[0].defname
        cand = ["%s/%s.c" % (d, name), "%s/%s_%s.c" % (d, name, hx(e0.vram)),
                "%s/%s_%s_%s.c" % (d, name, hx(e0.vram), k0[0])]
        p = next(c for c in cand if c not in taken or (len(paths) == 1 and c == paths[0]))
        taken.add(p)
        for b in paths:
            shared[b] = (p, system)
    rows, report, tot = [], [], {"roles": 0, "one": 0}
    by_prog = {}
    for k in order:
        by_prog.setdefault(k[0], []).append(k)
    for prog, ks in by_prog.items():
        names = set()
        nrole = none = 0
        reuse = {r for k in ks for r in tree.roles.get(tree.unit_rel(*k), [])}  # an applied prog's role files
        folder = tree.systems()
        for k in ks:
            tu, ents = k[1], U[k]
            for system, idx in runs[k]:
                v0 = next(f.vram for i in idx for f in ents[i].fns if f.vram is not None)
                if prog == EXE and tu.startswith("LIB"):
                    d = "src/%s/psyq" % prog
                elif prog == EXE and system and system not in folder:
                    unknown.append("%s %s %s" % (prog, system, tree.unit_rel(prog, tu)))
                    continue
                elif prog == EXE:
                    d = "src/%s/%s" % (prog, folder.get(system, ""))
                else:
                    d = "src/%s" % prog
                d = d.rstrip("/")
                base = system or hx(v0)
                cand = ["%s/%s.c" % (d, base), "%s/%s_%s.c" % (d, base, hx(v0))]
                p = next((c for c in cand if c not in names and (c not in taken or c in reuse)), None)
                if p is None:
                    raise Refuse("role-name-collision %s %s" % (prog, cand[-1]))
                names.add(p)
                vr = [f.vram for i in idx for f in ents[i].fns if f.vram is not None]
                rows.append((prog, tu, p, min(vr), max(vr), system or "-"))
                nrole += 1
                none += len(vr) == 1
            # one shared row per site: a collapsed run's bodies sit at consecutive entries, each body once
            groups, prev = [], None
            for i, e in enumerate(ents):
                if e.kind != "inc" or e.target not in shared:
                    prev = None
                    continue
                sp = shared[e.target][0]
                if prev is not None and prev[0] == i - 1 and prev[1] == sp and e.target not in prev[2]:
                    groups[-1].append(e)
                    prev[2].add(e.target)
                    prev[0] = i
                else:
                    groups.append([e])
                    prev = [i, sp, {e.target}]
            for g in groups:
                vr = [f.vram for e in g for f in e.fns if f.vram is not None]
                rows.append((prog, tu, shared[g[0].target][0], min(vr), max(vr), shared[g[0].target][1] or "-"))
        mine = [(paths, why) for paths, why in trun if any(kk[0] == prog for kk, _ in sites[paths[0]])]
        col = sum(1 for p, w in mine if w is None)
        reasons = {}
        for p, w in mine:
            if w:
                reasons[w] = reasons.get(w, 0) + 1
        report.append("LAYOUT %s role_files %d one_function %d twin_collapse %d twin_single %d%s" % (
            prog, nrole, none, col, len(mine) - col,
            "".join(" [%s: %d]" % (w, c) for w, c in sorted(reasons.items()))))
        tot["roles"] += nrole
        tot["one"] += none
    col = sum(1 for p, w in trun if w is None)
    reasons = {}
    for p, w in trun:
        if w:
            reasons[w] = reasons.get(w, 0) + 1
    report.append("LAYOUT PROPOSE programs %d role_files %d one_function %d twin_runs %d collapse %d (%d bodies) "
                  "single %d unresolved 0" % (len(by_prog), tot["roles"], tot["one"], len(trun), col,
                                              sum(len(p) for p, w in trun if w is None), len(trun) - col))
    report.append("LAYOUT PROPOSE single reasons:%s" % "".join(" [%s: %d]" % x for x in sorted(reasons.items())))
    if unknown:
        for u in unknown:
            print("LAYOUT unknown-system %s" % u)
        raise Refuse("unknown-system %d (docs/layout.md ## SLUS systems)" % len(unknown))
    rows.sort(key=lambda r: (r[0], r[1], r[3], r[2]))
    return rows, report, []


def write_rows(tree, rows):
    with open(os.path.join(tree.cfg, "config", "layout.tsv"), "w") as f:
        f.write(HEADER)
        for r in rows:
            f.write("%s\t%s\t%s\t0x%08X\t0x%08X\t%s\n" % r)


def read_rows(tree, prog=None):
    p = os.path.join(tree.cfg, "config", "layout.tsv")
    if not os.path.isfile(p):
        return None
    out = []
    with open(p) as f:
        for l in f:
            if l.startswith("#") or not l.strip():
                continue
            w = l.rstrip("\n").split("\t")
            if prog is None or w[0] == prog:
                out.append((w[0], w[1], w[2], int(w[3], 16), int(w[4], 16), w[5]))
    return out


def cmd_propose(tree):
    rows, report, unresolved = plan(tree)
    if unresolved:
        for u in unresolved:
            print("LAYOUT unresolved %s" % u)
        print("LAYOUT PROPOSE refused: %d unresolved" % len(unresolved))
        return 1
    write_rows(tree, rows)
    for l in report:
        print(l)
    print("LAYOUT wrote config/layout.tsv rows %d" % len(rows))
    return 0


# ---- apply ---------------------------------------------------------------------------------------------------------

def cpp_of(tree, fallback=False):
    cpp, flags = None, None
    with open(os.path.join(tree.cfg, "Makefile")) as f:
        for l in f:
            m = re.match(r"^(CPP|CPPFLAGS)\s*:?=\s*(.*)$", l.rstrip("\n"))
            if m and m.group(1) == "CPP":
                cpp = m.group(2).strip()
            elif m:
                flags = m.group(2).split()
    if cpp and shutil.which(cpp):
        return [cpp], flags
    if fallback and shutil.which("cc"):  # self-test only; host `cpp` (clang traditional) keeps // comments
        return ["cc", "-E", "-x", "c"], flags
    return None, flags


def tokens(root, rel, prog, cpp, flags):
    a = cpp + flags + (["-DMMX6_OVERLAY"] if prog.startswith("rock_") else []) + [rel]
    r = subprocess.run(a, cwd=root, stdout=subprocess.PIPE, stderr=subprocess.PIPE, universal_newlines=True)
    if r.returncode:
        raise Refuse("cpp-failed %s (%s)" % (rel, r.stderr.strip().splitlines()[-1:] or ""))
    return [l for l in r.stdout.split("\n") if l.strip() and not l.startswith("#")]


def build(tree, prog):
    """(writes {rel: text}, moves [rows], inlined/moved old bodies, report counts) for prog from layout.tsv."""
    rows = read_rows(tree, prog)
    if not rows:
        raise Refuse("no-rows %s (run propose)" % prog)
    tree = tree if isinstance(tree, Flat) else Flat(tree.root, tree.cfg)
    writes, moves, olds, runs = {}, [], set(), {}
    cnt = {"roles": 0, "shared_new": 0, "shared_reused": 0, "inlined": 0}
    unresolved = []
    # an applied (L-B) prog is read through its role files, every one before any write; they may be reused or go
    for p, tu in tree.units(prog):
        tree.lines(tree.unit_rel(p, tu))
    reuse = {r for p, tu in tree.units(prog) for r in tree.roles.get(tree.unit_rel(p, tu), [])}
    olds.update(reuse)

    def emit(src, a, b, rp, n):
        """moves rows of src lines a..b (1-based) -> rp:n, a flattened unit's lines split by their origin."""
        org = tree.origin.get(src)
        if org is None:
            moves.append((src, a, b, rp, n))
            return
        k = a
        while k <= b:
            o = org[k - 1]
            j = k
            while o is not None and j < b and org[j] is not None and org[j] == (o[0], o[1] + j - k + 1):
                j += 1
            if o is not None:  # identity rows too: a bare cite maps only when every row has one destination
                moves.append((o[0], o[1] + 1, o[1] + 1 + j - k, rp, n + k - a))
            k = j + 1

    for p, tu in tree.units(prog):
        urel = tree.unit_rel(p, tu)
        ents = resolve_unit(tree, p, tu, unresolved)
        if unresolved:
            raise Refuse("unresolved %s" % unresolved[0])
        if any(e.kind == "inc" and not e.target.startswith("src/shared/") for e in ents):
            raise Refuse("nested-role %s" % urel)
        lines = tree.lines(urel)
        org = tree.origin.get(urel)
        # the unit's own leading lines end at the first entry or the first inlined role line
        head = ents[0].first if ents else len(lines)
        if org:
            head = min(head, next((j for j, o in enumerate(org) if o is not None and o[0] != urel), head))
        roles = [r for r in rows if r[1] == tu and not r[2].startswith("src/shared/")]
        shrs = [r for r in rows if r[1] == tu and r[2].startswith("src/shared/")]
        if not ents:
            continue
        owner = []
        for e in ents:
            if all(f.vram is None for f in e.fns):  # static helpers only: they go with the run after them
                owner.append(None)
                continue
            rs = [r for r in roles if all(r[3] <= f.vram <= r[4] for f in e.fns if f.vram is not None)]
            if len(rs) != 1:
                raise Refuse("entry-row %s:%d rows %d" % (urel, e.first + 1, len(rs)))
            owner.append(roles.index(rs[0]))
        for i in range(len(owner) - 1, -1, -1):
            if owner[i] is None:
                owner[i] = owner[i + 1] if i + 1 < len(owner) else None
        for i in range(len(owner)):
            if owner[i] is None:
                owner[i] = owner[i - 1] if i else 0
        if owner != sorted(owner) or sorted(set(owner)) != list(range(len(roles))):
            raise Refuse("rows-not-contiguous %s" % urel)
        # a body's closing `#undef` lines stay with it at a role boundary (the next role file opens on its banner)
        tail = [0] * len(ents)
        for i in range(len(ents) - 1):
            if owner[i] != owner[i + 1]:
                j = end = ents[i].last + 1
                while j < ents[i + 1].first and (UNDEF_RE.match(lines[j]) or not lines[j].strip()):
                    j += 1
                    end = j if lines[j - 1].strip() else end
                tail[i] = end - ents[i].last - 1
        incl = []
        first_site = {}
        for ri, role in enumerate(roles):
            rp = role[2]
            out, fence = [], False

            def copy(src, a, chunk):
                while not out and chunk and not chunk[0].strip():
                    a, chunk = a + 1, chunk[1:]
                if chunk:
                    emit(src, a + 1, a + len(chunk), rp, len(out) + 1)
                    out.extend(chunk)

            def copy_unit(a, b):
                seg = []
                for j in range(a, b):
                    if FENCE_RE.match(lines[j]):
                        copy(urel, j - len(seg), seg)
                        seg = []
                    else:
                        seg.append(lines[j])
                copy(urel, b - len(seg), seg)

            idx = [i for i, o in enumerate(owner) if o == ri]
            for i in idx:
                e = ents[i]
                prev_end = ents[i - 1].last + 1 + tail[i - 1] if i else head
                sh = None
                if e.kind == "inc":
                    sr = [r for r in shrs if all(r[3] <= f.vram <= r[4] for f in e.fns if f.vram is not None)]
                    sh = sr[0] if sr else None
                    if sh is None and fixed(e.target):
                        raise Refuse("fixed-without-row %s" % e.target)
                if sh is not None and sh in first_site:
                    first_site[sh].append(e)
                    continue
                if e.kind == "asm" and not fence:
                    copy_unit(prev_end, e.first)
                    out.append("// clang-format off")
                    fence = True
                elif e.kind != "asm" and fence:
                    out.append("// clang-format on")
                    fence = False
                    copy_unit(prev_end, e.first)
                else:
                    copy_unit(prev_end, e.first)
                if e.kind in ("asm", "def"):
                    copy(urel, e.first, lines[e.first:e.last + 1])
                elif sh is not None:
                    first_site[sh] = [e]
                    copy(urel, e.first, lines[e.first:e.first + e.ndef])
                    emit(urel, e.first + e.ndef + 1, e.first + e.ndef + 1, rp, len(out) + 1)
                    out.append('#include "%s"' % rel_from(rp, sh[2]))
                    copy(urel, e.first + e.ndef + 1, lines[e.first + e.ndef + 1:e.last + 1])
                else:
                    copy(urel, e.first, lines[e.first:e.first + e.ndef])
                    emit(urel, e.first + e.ndef + 1, e.first + e.ndef + 1, rp, len(out) + 1)
                    copy(e.target, 0, tree.lines(e.target))
                    copy(urel, e.first + e.ndef + 1, lines[e.first + e.ndef + 1:e.last + 1])
                    olds.add(e.target)
                    cnt["inlined"] += 1
                if tail[i]:
                    copy(urel, e.last + 1, lines[e.last + 1:e.last + 1 + tail[i]])
            if ri == len(roles) - 1:
                if fence:
                    out.append("// clang-format on")
                    fence = False
                copy_unit(ents[-1].last + 1, len(lines))
            if fence:
                out.append("// clang-format on")
            while out and not out[-1].strip():
                out.pop()
            if rp in writes or (tree.exists(rp) and rp not in reuse):
                raise Refuse("role-exists %s" % rp)
            writes[rp] = "\n".join(out) + "\n"
            incl.append('#include "%s"' % rel_from(urel, rp))
            cnt["roles"] += 1
        # shared files
        for sh, es in first_site.items():
            bodies = []
            for e in es:
                if not bodies or e.target != bodies[-1]:
                    bodies.append(e.target)
            sp = sh[2]
            if bodies == [sp]:
                continue
            text, mv = [], []
            for b in bodies:
                if text:
                    text.append("")
                mv.append((b, 1, len(tree.lines(b)), sp, len(text) + 1))
                text.extend(tree.lines(b))
                olds.add(b)
            text = "\n".join(text) + "\n"
            if sp in writes:
                if writes[sp] != text:
                    raise Refuse("shared-differs %s" % sp)
            elif tree.exists(sp):
                if "\n".join(tree.lines(sp)) + "\n" != text:
                    raise Refuse("shared-differs %s" % sp)
                if tuple(bodies) not in runs:
                    moves.extend(mv)  # the old copies go too (twin rewrite), their cites follow
                cnt["shared_reused"] += 1
            else:
                writes[sp] = text
                moves.extend(mv)
                cnt["shared_new"] += 1
            runs[tuple(bodies)] = sp
        # the unit
        lead = [j for j in range(head) if not FENCE_RE.match(lines[j])
                and lines[j].strip() != '#include "common.h"']
        while lead and not lines[lead[0]].strip():
            lead.pop(0)
        while lead and not lines[lead[-1]].strip():
            lead.pop()
        new = ['#include "common.h"', ""]
        if lead:
            seg = []
            for j in lead:
                if seg and j != seg[-1] + 1:
                    emit(urel, seg[0] + 1, seg[-1] + 1, urel, len(new) + 1 - len(seg))
                    seg = []
                seg.append(j)
                new.append(lines[j])
            emit(urel, seg[0] + 1, seg[-1] + 1, urel, len(new) + 1 - len(seg))
            new.append("")
        writes[urel] = "\n".join(new + incl) + "\n"
    cnt["runs"] = runs
    return writes, moves, olds, cnt


def rewrite_twins(st, runs):
    """Twin rewrite on the staged tree st: in every file of the closure, a run of plain includes of a moved run's old
    bodies (in order, blank lines between) becomes one include of its new shared file. ({rel: text}, runs rewritten,
    [kept: rel:line of an old body include not rewritable])."""
    first = {}
    for bodies, sp in runs.items():
        first.setdefault(bodies[0], []).append((bodies, sp))
    olds = {b for bodies in runs for b in bodies}
    out, n, kept = {}, 0, []
    for rel in sorted(st.closure()):
        lines = list(st.lines(rel))
        ents = [e for e in parse(lines) if e.kind == "inc"]
        res = [e.target if e.target.startswith("src/") else norm(rel, e.target) for e in ents]
        cut, i = [], 0
        while i < len(ents):
            hit = None
            for bodies, sp in sorted(first.get(res[i], []), key=lambda x: -len(x[0])):
                k = len(bodies)
                grp = ents[i:i + k]
                if res[i:i + k] != list(bodies):
                    continue
                if k > 1 and (any(e.ndef or e.last != e.first for e in grp[1:]) or grp[0].last != grp[0].first
                              + grp[0].ndef or any(lines[j].strip() for a, b in zip(grp, grp[1:])
                                                   for j in range(a.last + 1, b.first))):
                    continue
                hit = (k, sp)
                break
            if hit is None:
                if res[i] in olds:
                    kept.append("%s:%d" % (rel, ents[i].first + ents[i].ndef + 1))
                i += 1
                continue
            k, sp = hit
            e0 = ents[i]
            j0 = e0.first + e0.ndef
            to = sp if e0.target.startswith("src/") else rel_from(rel, sp)
            lines[j0] = '#include "%s"' % to
            if k > 1:
                cut.append((j0 + 1, ents[i + k - 1].last + 1))
            n += 1
            i += k
        for a, b in reversed(cut):
            del lines[a:b]
        if lines != st.lines(rel):
            with open(st.path(rel), "rb") as f:
                try:
                    f.read().decode("utf-8")
                except UnicodeDecodeError:
                    raise Refuse("twin-rewrite-not-utf8 %s" % rel)
            out[rel] = "\n".join(lines) + "\n"
    return out, n, kept


def stage(tree, dest):
    if os.path.isdir(dest):
        shutil.rmtree(dest)
    os.makedirs(dest)
    for d in ("src", "include"):
        shutil.copytree(tree.path(d), os.path.join(dest, d))


def cmd_apply(tree, prog, dry, allow_no_cpp=False):
    cpp, flags = cpp_of(tree, fallback=allow_no_cpp)
    if cpp is None and not allow_no_cpp:
        print("LAYOUT APPLY %s refused: no cpp (run in the container)" % prog)
        return 1
    scratch = os.path.join(tree.root, RUN, "layout", prog)
    try:
        writes, moves, olds, cnt = build(tree, prog)
        stage(tree, scratch)
        st = Tree(scratch, cfg=tree.cfg)
        for rel, text in writes.items():
            os.makedirs(os.path.dirname(st.path(rel)), exist_ok=True)
            with open(st.path(rel), "w") as f:
                f.write(text)
        # twin rewrite: every other includer of a moved body now includes its new shared file
        rew, nrew, kept = rewrite_twins(Tree(scratch, cfg=tree.cfg), cnt["runs"])
        for rel, text in rew.items():
            with open(st.path(rel), "w") as f:
                f.write(text)
            writes[rel] = text
        st = Tree(scratch, cfg=tree.cfg)
        reached = st.closure()
        dels = sorted(b for b in olds if b not in reached and not fixed(b) and b not in writes)
        for b in dels:
            os.remove(st.path(b))
        for k in kept:
            print("LAYOUT twin-kept %s (old body include not rewritable; copy stays)" % k)
        inc = includers(tree)
        others = []
        for rel in rew:
            for u in inc.get(rel, []):
                if u[0] != prog and u not in others:
                    others.append(u)
        bad = 0
        for p, tu in tree.units(prog) + others:
            urel = tree.unit_rel(p, tu)
            if cpp is None:
                print("LAYOUT note: no cpp found; token check skipped for %s" % urel)
                continue
            ok = tokens(tree.root, urel, p, cpp, flags) == tokens(scratch, urel, p, cpp, flags)
            print("LAYOUT token-check %s %s" % (urel, "OK" if ok else "MISMATCH"))
            bad += not ok
        # every unit still resolves on the new tree, in the same order
        for p, tu in tree.units(prog) + others:
            a = [(f.name, f.path, f.first, f.last) for f in tree.fns(p, tu)]
            b = [(f.name, f.path, f.first, f.last) for f in st.fns(p, tu)]
            if [x[0] for x in a] != [x[0] for x in b]:
                print("LAYOUT order-mismatch %s %s" % (p, tu))
                bad += 1
        print("LAYOUT apply %s roles %d shared_new %d shared_reused %d inlined %d deleted %d moves %d "
              "twin-rewrites %d in %d files (%d other-program units) twin-kept %d%s" % (
                  prog, cnt["roles"], cnt["shared_new"], cnt["shared_reused"], cnt["inlined"], len(dels), len(moves),
                  nrew, len(rew), len(others), len(kept), " (dry-run)" if dry else ""))
        if bad:
            print("LAYOUT APPLY %s FAIL: %d unit(s) differ; nothing written" % (prog, bad))
            return 1
        if not dry:
            for rel, text in writes.items():
                os.makedirs(os.path.dirname(tree.path(rel)), exist_ok=True)
                with open(tree.path(rel), "w") as f:
                    f.write(text)
            for b in dels:
                os.remove(tree.path(b))
            mp = os.path.join(tree.cfg, "config", "layout-moves.tsv")
            new = not os.path.isfile(mp)
            with open(mp, "a") as f:
                if new:
                    f.write(MOVES_HEADER)
                for m in moves:
                    f.write("%s\t%d\t%d\t%s\t%d\t%s\n" % (m + (prog,)))
        print("LAYOUT APPLY %s OK%s" % (prog, " (dry-run, nothing written)" if dry else ""))
        return 0
    except Refuse as e:
        print("LAYOUT APPLY %s refused: %s" % (prog, e))
        return 1
    finally:
        if os.path.isdir(scratch):
            shutil.rmtree(scratch)


# ---- repoint -------------------------------------------------------------------------------------------------------

def read_moves(tree):
    """The pending moves {old_path: [(first, last, new_path, new_first)]}: 6-column rows after the last `# repointed`
    line (5-column rows are 2.4 T15's, repointed then). One batch maps each cite once, so a path that is both an old
    and a new path (task/task.c) is never mapped twice."""
    mv = {}
    p = os.path.join(tree.cfg, "config", "layout-moves.tsv")
    if os.path.isfile(p):
        with open(p) as f:
            for l in f:
                if l.rstrip("\n") == REPOINTED:
                    mv = {}
                    continue
                w = l.rstrip("\n").split("\t")
                if len(w) == 6 and not l.startswith("#"):
                    mv.setdefault(w[0], []).append((int(w[1]), int(w[2]), w[3], int(w[4])))
    return mv


def repoint_text(text, mv, where=None, stale=None):
    """where(prog, vram) -> the function's current path: a bare cite whose rows have several destinations (a file
    split, T15.1) maps to the destination holding a `prog:0x<vram>` named on its own text line. stale(line, m) -> the
    new cite text of a stale cite no pending move maps (T17), "" when unmapped, None when the cite is not stale."""
    n = [0, 0, 0]  # cites, repointed, unmapped
    vt = []
    cur = ["", 0]

    def sub(m):
        path, line = m.group(1), m.group(2)
        rest = "-" + m.group(3) if m.group(3) else ""
        rows = mv.get(path)
        if rows is None:
            s = stale(cur[0], m, cur[1]) if stale else None
            if s is None:
                return m.group(0)
            n[0] += 1
            n[1 if s else 2] += 1
            return s or m.group(0)
        n[0] += 1
        if line:
            k = int(line)
            r = next((r for r in rows if r[0] <= k <= r[1]), None)
            if r and (r[2], r[3] + k - r[0]) != (path, k):
                n[1] += 1
                return "%s:%d%s" % (r[2], r[3] + k - r[0], rest)
            n[2] += r is None
            return m.group(0)
        dests = {r[2] for r in rows}
        if len(dests) == 1 and path not in dests:
            n[1] += 1
            return next(iter(dests)) + rest
        q = next((q for q in (where(p, int(v, 16)) for p, v in vt) if q in dests), None) if where else None
        if q is not None and q != path:
            n[1] += 1
            return q + rest
        n[2] += q is None
        return m.group(0)

    out = []
    for i, l in enumerate(text.splitlines(True), 1):
        vt[:] = PROGVRAM_RE.findall(l) if where else []
        cur[:] = [l, i]
        out.append(CITE_RANGE_RE.sub(sub, l))
    return "".join(out), n


def stale_cite(tree, l, m):
    """True when match m (CITE_RE/CITE_RANGE_RE) on line l is a src/shared/** or src/<c_units prog>/** path not on
    disk (src/shared/_selftest/, src/main/ (mmx4-side) and templated paths skipped)."""
    path = m.group(1)
    if m.start() and re.match(r'[A-Za-z0-9_./<>{}*-]', l[m.start() - 1]) or \
            m.end() < len(l) and l[m.end()] in "<>{}*" or path.startswith(("src/shared/_selftest/", "src/main/")):
        return False
    w = path.split("/")
    if not (w[1] == "shared" or w[1] in tree.progs()) or len(w) < 3:
        return False
    return not tree.exists(path)


def git_out(root, *args):
    r = subprocess.run(["git", "-C", root] + list(args), capture_output=True, text=True, errors="replace")
    return r.stdout if r.returncode == 0 else None


def blame_of(root, rel, cache={}):
    """{line number: commit} of rel's committed lines (git blame), {} outside git."""
    if (root, rel) not in cache:
        out, txt = {}, git_out(root, "blame", "--porcelain", "--", rel) or ""
        for l in txt.split("\n"):
            m = re.match(r'^([0-9a-f]{40}) \d+ (\d+)', l)
            if m and m.group(1).strip("0"):
                out[int(m.group(2))] = m.group(1)
        cache[(root, rel)] = out
    return cache[(root, rel)]


def old_lines(tree, path, since=None, cache={}):
    """The lines of path as the cite saw it: at commit since (the cite line's blame) or its parent, else at the last
    commit where path existed (git, run in tree.root); None when git has neither."""
    key = (tree.root, path, since)
    if key not in cache:
        cache[key] = None
        try:
            c = (git_out(tree.root, "rev-list", "-1", "HEAD", "--", path) or "").strip()
            revs = ((since + ":", since + "^:") if since else ()) + ((c + ":", c + "^:") if c else ())
            for rev in revs:
                t = git_out(tree.root, "show", rev + path)
                if t is not None:
                    cache[key] = t.split("\n")
                    break
        except OSError:
            pass
    return cache[key]


def anchor_lines(tree, path, k, a, since=None, cache={}, shown={}):
    """The lines of path at the newest commit (git log of path, walked back from since, else HEAD) whose line k holds
    \\b<a>\\b: the text a cite-anchor cite saw (T17); None when no commit's does."""
    key = (tree.root, path, k, a, since)
    if key not in cache:
        cache[key] = None
        pat = re.compile(r'\b%s\b' % re.escape(a))
        for c in (git_out(tree.root, "log", "--format=%H", since or "HEAD", "--", path) or "").split():
            if (tree.root, c, path) not in shown:
                t = git_out(tree.root, "show", "%s:%s" % (c, path))
                shown[(tree.root, c, path)] = None if t is None else t.split("\n")
            ls = shown[(tree.root, c, path)]
            if ls is not None and 1 <= k <= len(ls) and pat.search(ls[k - 1]):
                cache[key] = ls
                break
    return cache[key]


def remap_line(old, k, lines, lo, hi, anchor):
    """(new line, rule) of old line k (1-based) in lines[lo..hi] (0-based) (T17.c2): R1 the one line whose stripped
    text equals the old line's and holds \\b<anchor>\\b; R2 a run of 1..4 lines whose text minus whitespace equals the
    old line's (clang-format reflow) -> the run's line holding the anchor (no anchor: its first line); R3 several R1
    (else R2) hits -> the nearest to k, equal distance refused (None, "R3"). (None, None) when nothing matches."""
    if old is None or not 1 <= k <= len(old) or not old[k - 1].strip():
        return None, None
    pat = re.compile(r'\b%s\b' % re.escape(anchor)) if anchor else None
    t = old[k - 1].strip()
    hits, rule = [i + 1 for i in range(lo, hi + 1) if lines[i].strip() == t and (not pat or pat.search(lines[i]))], "R1"
    if not hits:
        s, hs, rule = re.sub(r'\s+', "", t), set(), "R2"
        for i in range(lo, hi + 1):
            run = ""
            for j in range(i, min(i + 4, hi + 1)):
                if not lines[j].strip():
                    break
                run += re.sub(r'\s+', "", lines[j])
                if not s.startswith(run):
                    break
                if run == s:
                    h = next((x for x in range(i, j + 1) if not pat or pat.search(lines[x])), None)
                    if h is not None:
                        hs.add(h + 1)
                    break
        hits = sorted(hs)
    if len(hits) < 2:
        return (hits[0], rule) if hits else (None, None)
    d = sorted(hits, key=lambda h: (abs(h - k), h))
    return (None, "R3") if abs(d[0] - k) == abs(d[1] - k) else (d[0], "R3")


def anchor_line(lines, k, anchor):
    """(new line, "R4") of a cite to line k whose old text is lost (T17.c2): the one non-comment line (not starting
    `//`) holding \\b<anchor>\\b in lines; several -> those inside the C function enclosing line k (definition line ..
    column-0 `}`): one -> it, several -> the nearest to k (equal distance refused: (None, "R4")); else (None, None)."""
    pat = re.compile(r'\b%s\b' % re.escape(anchor))
    hits = [i + 1 for i, l in enumerate(lines) if not l.lstrip().startswith("//") and pat.search(l)]
    if len(hits) == 1:
        return hits[0], "R4"
    e = next((e for e in parse(lines) if e.kind == "def" and e.first <= k - 1 <= e.last), None) if hits else None
    hits = [h for h in hits if e and e.first < h <= e.last + 1]
    if len(hits) < 2:
        return (hits[0], "R4") if hits else (None, None)
    d = sorted(hits, key=lambda h: (abs(h - k), h))
    return (None, "R4") if abs(d[0] - k) == abs(d[1] - k) else (d[0], "R4")


def stale_of(tree, rel):
    """stale(line, m) for repoint_text (T17): old text = git line N of the vanished path; destination = locate(prog,
    func) (stem func_<8hex> -> vram, else the stem name, else the via anchor / a prog:0x<vram> on the line); new N =
    the one line of that range (preamble included) whose stripped text equals the old line and holds the via anchor.
    A cite-anchor cite (on disk, line N lacks the via anchor) takes the same rule, old text from anchor_lines."""
    idx = {}

    def index(prog):
        if prog not in idx:
            idx[prog] = {}
            for p, tu in tree.units(prog):
                for e in resolve_unit(tree, p, tu, []):
                    for f in e.fns:
                        idx[prog].setdefault(f.name, f)
                        if f.vram is not None:
                            idx[prog].setdefault(f.vram, f)
        return idx[prog]

    sm = re.match(r'config/symbols\.(.+)\.txt$', rel)

    def stale(l, m, n=0):
        anchor = not stale_cite(tree, l, m)
        if anchor:  # a cite-anchor cite (cite_defects): on disk, line N lacks the via anchor
            va = VIA_RE.match(l, m.end())
            if not (m.group(2) and va and tree.exists(m.group(1))):
                return None
            k, cur = int(m.group(2)), tree.lines(m.group(1))
            if 1 <= k <= len(cur) and re.search(r'\b%s\b' % re.escape(va.group(1)), cur[k - 1]):
                return None
        path, progs = m.group(1), tree.progs()
        w, pv = path.split("/"), PROGVRAM_RE.findall(l)
        prog = (w[2] if w[1] == "shared" and w[2] in progs else w[1] if w[1] in progs else
                next((p for p, _ in pv if p in progs), None) or (sm.group(1) if sm and sm.group(1) in progs else None))
        if prog is None:
            return ""
        via = VIA_RE.match(l, m.end())
        via = via.group(1) if via else None
        stem = os.path.basename(path)[:-2]
        hm = re.match(r'^func_([0-9A-Fa-f]{8})$', stem)
        keys = ([int(hm.group(1), 16)] if hm else []) + [stem] + ([via] if via else []) + \
               [int(v, 16) for p, v in pv if p == prog]
        since = blame_of(tree.cfg, rel).get(n)
        old = anchor_lines(tree, path, int(m.group(2)), via, since) if anchor else None
        if old is not None:  # the anchor is often a global or callee: func = the old def holding line N (preamble in)
            ents = parse(old)
            e = next((e for i, e in enumerate(ents) if e.kind == "def" and
                      (ents[i - 1].last if i else -1) < int(m.group(2)) - 1 <= e.last), None)
            keys = ([e.name] if e else []) + keys
        ix = index(prog)
        f = next((ix[k] for k in keys if k in ix), None)
        if f is None and not anchor:
            return ""
        if not m.group(2):
            return f.path
        if not anchor:
            old = old_lines(tree, path, since)
        dest = f.path if f else path  # a cite-anchor cite with no located function: its own file, whole
        lines = tree.lines(dest)
        lo = max([e.last + 1 for e in parse(lines) if e.last < f.first] + [0]) if f else 0
        hi = f.last if f else len(lines) - 1
        k = int(m.group(2))
        a, rule = remap_line(old, k, lines, lo, hi, via)
        if a is None and rule is None and via:  # R4 in the current file: a cite-anchor cite's own (via may be a callee)
            if anchor and dest != path:
                dest, lines = path, tree.lines(path)
            a, rule = anchor_line(lines, k, via)
        b = remap_line(old, int(m.group(3)), lines, lo, hi, None)[0] if m.group(3) else None
        if a is None or m.group(3) and b is None:
            return ""
        print("LAYOUT REPOINT %s:%d %s:%d -> %s:%d rule=%s | %s" % (
            rel, n, path, k, "" if dest == path else dest, a, rule, lines[a - 1].strip()))
        return "%s:%d%s" % (dest, a, "-%d" % b if m.group(3) else "")

    return stale


def where_of(tree):
    """where(prog, vram) -> the path of the function at vram in prog's unit closure (lazily, per prog), else None."""
    cache = {}

    def where(prog, vram):
        if prog not in cache:
            cache[prog] = {}
            if prog in tree.progs():
                for p, tu in tree.units(prog):
                    for e in resolve_unit(tree, p, tu, []):
                        for f in e.fns:
                            if f.vram is not None:
                                cache[prog].setdefault(f.vram, f.path)
        return cache[prog].get(vram)

    return where


def cmd_repoint(tree, files, dry):
    mv = read_moves(tree)
    where = where_of(tree)
    tot = [0, 0, 0]
    for rel in files or CITES:
        p = os.path.join(tree.cfg, rel)
        if not os.path.isfile(p):
            print("LAYOUT REPOINT %s missing" % rel)
            continue
        with open(p, errors="surrogateescape") as f:
            text = f.read()
        new, n = repoint_text(text, mv, where, stale_of(tree, rel))
        print("LAYOUT REPOINT %s cites %d repointed %d unmapped %d" % (rel, n[0], n[1], n[2]))
        tot = [a + b for a, b in zip(tot, n)]
        if not dry and new != text:
            with open(p, "w", errors="surrogateescape") as f:
                f.write(new)
    mp = os.path.join(tree.cfg, "config", "layout-moves.tsv")
    if not dry and not files and mv:  # the default citation set is done: mark the batch
        with open(mp, "a") as f:
            f.write(REPOINTED + "\n")
    print("LAYOUT REPOINT moves %d cites %d repointed %d unmapped %d%s" % (
        sum(len(v) for v in mv.values()), tot[0], tot[1], tot[2], " (dry-run)" if dry else ""))
    return 0


# ---- check / locate ------------------------------------------------------------------------------------------------

def defects(tree, prog=None):
    out, stems = [], tree.stems()
    progs = [prog] if prog else tree.progs()
    for p in progs:
        rows = read_rows(tree, p) or []
        for _, tu in tree.units(p):
            urel = tree.unit_rel(p, tu)
            ents = resolve_unit(tree, p, tu, [])
            seen, last = set(), None
            fns = [f for e in ents for f in e.fns]
            for f in fns:
                if f.name in seen:
                    out.append("duplicate %s %s %s" % (p, tu, f.name))
                seen.add(f.name)
                if f.vram is not None:
                    if last is not None and f.vram <= last:
                        out.append("out-of-order %s %s %s" % (p, tu, f.name))
                    last = f.vram
            roles = [e for e in ents if e.kind == "inc" and not e.target.startswith("src/shared/")]
            sysof = {}
            for e in roles:
                sysof[e.target] = next((s for s in (system_of(f.name, stems, tree.systems()) for f in e.fns if not f.static) if s), "-")
            ts = [e.target for e in roles]
            for t in sorted(set(x for x in ts if ts.count(x) > 1)):
                out.append("split %s %s %s twice" % (p, tu, t))
            for a, b in zip(ents, ents[1:]):
                if a in roles and b in roles and a.target != b.target and sysof[a.target] == sysof[b.target]:
                    out.append("split %s %s %s+%s" % (p, tu, a.target, b.target))
            for kind in ("role", "shared"):
                rs = [r for r in rows if r[1] == tu and r[2].startswith("src/shared/") == (kind == "shared")]
                for f in fns:
                    if f.vram is not None and sum(1 for r in rs if r[3] <= f.vram <= r[4]) > 1:
                        out.append("duplicate-row %s %s %s" % (p, tu, f.name))
    return out


def cite_files(tree):
    """The cite set of check (T17): CITES + config/symbols.*.txt + docs/ops/*.md + docs/*.md (those present)."""
    out = list(CITES)
    for g in ("config/symbols.*.txt", "docs/ops/*.md", "docs/*.md"):
        out += sorted(os.path.relpath(p, tree.cfg).replace(os.sep, "/") for p in glob.glob(os.path.join(tree.cfg, g)))
    led = ledgers(tree)
    return [r for i, r in enumerate(out) if r not in out[:i] and r not in led and os.path.isfile(os.path.join(tree.cfg, r))]


def ledgers(tree):
    """Files named by the own/trial/floor/debt tables of config/psxdecomp.toml: the commit gate keeps their lines
    (psxd_floor RECORD_TABLES), so a cite there is a record of its time, never repointed or checked (T17)."""
    p = os.path.join(tree.cfg, "config/psxdecomp.toml")
    if not os.path.isfile(p):
        return set()
    import tomllib
    with open(p, "rb") as f:
        rec = tomllib.load(f)
    return {v for t in ("own", "trial", "floor", "debt") for v in (rec.get(t) or {}).values() if isinstance(v, str)}


def cite_defects(tree):
    """`stale-cite <file>:<n> <cite>` (stale_cite) and `cite-anchor <file>:<n> <cite>` (`<path>:N via=<a>` on disk,
    line N lacks \\b<a>\\b) over cite_files."""
    out = []
    for rel in cite_files(tree):
        with open(os.path.join(tree.cfg, rel), errors="surrogateescape") as f:
            for n, l in enumerate(f, 1):
                for m in CITE_RE.finditer(l):
                    if stale_cite(tree, l, m):
                        out.append("stale-cite %s:%d %s" % (rel, n, m.group(0)))
                        continue
                    via = VIA_RE.match(l, m.end())
                    if not (m.group(2) and via and tree.exists(m.group(1))):
                        continue
                    k, lines = int(m.group(2)), tree.lines(m.group(1))
                    if not 1 <= k <= len(lines) or not re.search(r'\b%s\b' % re.escape(via.group(1)), lines[k - 1]):
                        out.append("cite-anchor %s:%d %s" % (rel, n, m.group(0)))
    return out


def cmd_check(tree, prog=None):
    try:
        d = defects(tree, prog) + ([] if prog else cite_defects(tree))
    except Refuse as e:
        print("LAYOUT CHECK refused: %s" % e)
        return 1
    for x in d:
        print("LAYOUT CHECK %s" % x)
    print("LAYOUT CHECK %d defects" % len(d))
    return 1 if d else 0


def locate(prog, func, root=ROOT):
    """(path, line_first, line_last, unit) of func (a name or an int vram) in prog, else None."""
    tree = Tree(root) if isinstance(root, str) else root
    for p, tu in tree.units(prog):
        ents = (resolve_unit(tree, p, tu, []) if isinstance(func, int)
                else tree.entries(tree.unit_rel(p, tu), ctx=p))
        for e in ents:
            for f in e.fns:
                if (f.vram == func) if isinstance(func, int) else (f.name == func):
                    return f.path, f.first + 1, f.last + 1, tu
    return None


def unit_of(prog, func, root=ROOT):
    r = locate(prog, func, root)
    return r[3] if r else None


def includers(root=ROOT):
    """{path: [(prog, tu)]}: each file of the units' #include closure (a unit itself included) -> the units whose
    closure reaches it, in config/c_units.txt order ({} without c_units.txt). Includes resolve as Tree.entries."""
    tree = Tree(root) if isinstance(root, str) else root
    if not os.path.isfile(os.path.join(tree.cfg, "config", "c_units.txt")):
        return {}
    out = {}
    for p, tu in tree.units():
        seen, todo = set(), [tree.unit_rel(p, tu)]
        while todo:
            r = todo.pop()
            if r in seen or not tree.exists(r):
                continue
            seen.add(r)
            out.setdefault(r, []).append((p, tu))
            for e in parse(tree.lines(r)):
                if e.kind == "inc":
                    todo.append(e.target if e.target.startswith("src/") else norm(r, e.target))
    return out


# ---- bank-path helpers (2.4 T5): the one place the body path and the INCLUDE_ASM literal are spelled ----------------

def asm_line(prog, tu, func):
    """The INCLUDE_ASM line of func in unit tu (its folder names the unit wherever the line lives, C0070)."""
    return 'INCLUDE_ASM("asm/%s/nonmatchings/%s", %s);' % (prog, tu, func)


def new_body(prog, func):
    """Repo path of a newly drafted body of func (gate's draft, propagate's tudecl copy)."""
    return "src/shared/%s/%s.c" % (prog, func)


def find_asm(prog, func, root=ROOT):
    """(path, line, tu) of func's INCLUDE_ASM line in prog's unit closure (unit or role file; line 1-based), else None."""
    tree = Tree(root) if isinstance(root, str) else root
    for p, tu in tree.units(prog):
        for e in tree.entries(tree.unit_rel(p, tu), ctx=p):
            for f in e.fns:
                if f.kind == "asm" and f.name == func:
                    return f.path, f.first + 1, tu
    return None


ROLE_DIR = "selftest_role"


@contextlib.contextmanager
def role_tree(prog, tu, root=ROOT):
    """Self-test plant: unit src/<prog>/<tu>.c becomes the thin wrapper `#include "selftest_role/<tu>.c"` over one role
    file holding its text verbatim (each relative `.c` include re-pointed from the role's dir). Tokens identical old
    vs new under the Makefile cpp when it is found (else by construction). Yields the role file's repo path. On exit
    the unit's bytes are restored and the role file (and its dir, if empty) deleted; Refuse when the role file then
    differs from its planted text (a test left an edit) or the unit's sha1 differs from its pre-plant value."""
    unit = "src/%s/%s.c" % (prog, tu)
    role = "src/%s/%s/%s.c" % (prog, ROLE_DIR, tu)
    up, rp = os.path.join(root, unit), os.path.join(root, role)
    if os.path.exists(rp):
        raise Refuse("role-tree %s exists" % role)
    with open(up, "rb") as f:
        orig = f.read()
    lines = orig.decode().split("\n")
    for i, l in enumerate(lines):
        m = INC_RE.match(l)
        if m and not m.group(1).startswith("src/"):
            lines[i] = '#include "%s"' % rel_from(role, norm(unit, m.group(1)))
    text = "\n".join(lines)
    cpp, flags = cpp_of(Tree(root)) if os.path.isfile(os.path.join(root, "Makefile")) else (None, None)
    before = tokens(root, unit, prog, cpp, flags) if cpp else None
    os.makedirs(os.path.dirname(rp), exist_ok=True)
    with open(rp, "w") as f:
        f.write(text)
    with open(up, "w") as f:
        f.write('#include "%s"\n' % rel_from(unit, role))
    why = None
    try:
        if cpp and tokens(root, unit, prog, cpp, flags) != before:
            raise Refuse("role-tree %s tokens differ" % unit)
        yield role
    finally:
        left = open(rp).read() if os.path.exists(rp) else None
        with open(up, "wb") as f:
            f.write(orig)
        if os.path.exists(rp):
            os.remove(rp)
        if os.path.isdir(os.path.dirname(rp)) and not os.listdir(os.path.dirname(rp)):
            os.rmdir(os.path.dirname(rp))
        if left != text:
            why = "role-tree %s edited and not restored" % role
        with open(up, "rb") as f:
            if f.read() != orig:
                why = "role-tree %s sha1 differs on restore" % unit
    if why:
        raise Refuse(why)


# ---- self-test -----------------------------------------------------------------------------------------------------

PLANT = {
    "Makefile": "CPP := mipsel-linux-gnu-cpp\nCPPFLAGS := -nostdinc -undef -D__GNUC__=2 -DPSX -Iinclude\n",
    "include/common.h": "#ifndef COMMON_H\n#define COMMON_H\n#define INCLUDE_ASM(FOLDER, NAME) "
                        "__asm__(\".include \\\"\" FOLDER \"/\" #NAME \".s\\\"\")\ntypedef int s32;\n#endif\n",
    "config/c_units.txt": "# plant\nrock_90 E9860\nrock_91 E9860\nSLUS_013.95 120A0\n",
    "config/symbols.rock_90.txt": "update_text_box = 0x800E9A00;\ninit_capsule_gfx = 0x800E9F00;\n"
                                  "draw_text_box = 0x800E9B00;\nfill_text_box = 0x800E9B10;\n"
                                  "update_text_box_cursor = 0x800E9B20;\nplay_sound = 0x800E9F40;\n",
    "config/symbols.rock_91.txt": "draw_text_box = 0x800E98A0;\nfill_text_box = 0x800E98B0;\n",
    "config/symbols.SLUS_013.95.txt": "update_guard_shell = 0x80012100;\n",
    "config/dedup_registry.txt": "# plant\n",
    "docs/glossary.md": "## Terms\n\n| English term | Our stem | Source |\n|---|---|---|\n"
                        "| text box | text_box | plant |\n| capsule | capsule | plant |\n"
                        "| guard shell | guard_shell | plant |\n",
    "docs/layout.md": "## SLUS systems\n\n| system | holds | stems |\n|---|---|---|\n"
                      "| weapon | plant | `guard_shell`, `memcard_format` |\n",
    "src/shared/rock_90/func_800E9900.c": '#include "common.h"\n\n/* single-site body */\n'
                                          "void func_800E9900(void) {\n}\n",
    "src/shared/rock_90/update_text_box.c": '#include "common.h"\n\nvoid update_text_box(s32 a,\n'
                                            "                     s32 b) {\n    if (a) {\n        b++;\n    }\n}\n",
    "src/shared/rock_90/func_800E9B00.c": '#include "common.h"\n\nvoid draw_text_box(void) {\n}\n',
    "src/shared/rock_90/func_800E9B10.c": '#include "common.h"\n\ns32 fill_text_box(void) { return 1; }\n',
    "src/shared/SLUS_013.95/update_guard_shell.c": '#include "common.h"\n\nvoid update_guard_shell(void) {\n}\n',
    "src/SLUS_013.95/120A0.c": '#include "common.h"\n\nINCLUDE_ASM("asm/SLUS_013.95/nonmatchings/120A0", '
                               'func_80012000);\n\n#include "../shared/SLUS_013.95/update_guard_shell.c"\n',
    "src/shared/entity/state_dispatch.c": '#include "common.h"\n\nvoid func_80001000(void) {\n}\n',
    "src/rock_90/E9860.c": '#include "common.h"\n\ns32 D_800E9800;\n\n#include "../shared/rock_90/func_800E9900.c"\n\n'
                           'INCLUDE_ASM("asm/rock_90/nonmatchings/E9860", func_800E9950);\n\n'
                           '#include "../shared/rock_90/update_text_box.c"\n\n'
                           '#include "../shared/rock_90/func_800E9B00.c"\n\n#include "../shared/rock_90/func_800E9B10.c"\n\n'
                           'INCLUDE_ASM("asm/rock_90/nonmatchings/E9860", update_text_box_cursor);\n\n'
                           'INCLUDE_ASM("asm/rock_90/nonmatchings/E9860", func_800E9C00);\n\n'
                           "// inline preamble\nvoid func_800E9D00(void) {\n    D_800E9800 = 1;\n}\n\n"
                           "#define func_80001000 func_800E9E00\n#include \"../shared/entity/state_dispatch.c\"\n"
                           "#undef func_80001000\n\n"
                           '// clang-format off\nINCLUDE_ASM("asm/rock_90/nonmatchings/E9860", init_capsule_gfx);\n\n'
                           'INCLUDE_ASM("asm/rock_90/nonmatchings/E9860", play_sound);\n\n'
                           'INCLUDE_ASM("asm/rock_90/nonmatchings/E9860", func_800E9F80);\n// clang-format on\n',
    "src/rock_91/E9860.c": '#include "common.h"\n\nINCLUDE_ASM("asm/rock_91/nonmatchings/E9860", func_800E9890);\n\n'
                           '#include "../shared/rock_90/func_800E9B00.c"\n\n#include "../shared/rock_90/func_800E9B10.c"\n\n'
                           "#define func_80001000 func_800E9E40\n#include \"../shared/entity/state_dispatch.c\"\n"
                           "#undef func_80001000\n",
    "cites.txt": "a src/shared/rock_90/update_text_box.c:4 via=x\nb src/shared/rock_90/func_800E9900.c\n"
                 "c src/rock_90/E9860.c:9\n",
}
BAD = {
    "config/c_units.txt": "rock_92 E9860\nrock_93 E9860\nrock_94 E9860\n",
    "src/rock_92/E9860.c": '#include "common.h"\nINCLUDE_ASM("a", func_800E9200);\nINCLUDE_ASM("a", func_800E9100);\n',
    "src/rock_93/E9860.c": '#include "common.h"\nINCLUDE_ASM("a", func_800E9300);\nINCLUDE_ASM("a", func_800E9300);\n',
    "src/rock_94/E9860.c": '#include "common.h"\n#include "text_box.c"\n#include "text_box_800E9420.c"\n'
                           '#include "text_box.c"\n',
    "src/rock_94/text_box.c": 'INCLUDE_ASM("a", func_800E9400);\n',
    "src/rock_94/text_box_800E9420.c": 'INCLUDE_ASM("a", func_800E9420);\n',
    "config/symbols.rock_94.txt": "",
}


def plant(root, files):
    for rel, text in files.items():
        p = os.path.join(root, rel)
        os.makedirs(os.path.dirname(p), exist_ok=True)
        with open(p, "w") as f:
            f.write(text)


def snapshot(root):
    out = {}
    for d, _, fs in os.walk(root):
        for fn in fs:
            p = os.path.join(d, fn)
            with open(p, "rb") as f:
                out[os.path.relpath(p, root)] = f.read()
    return out


def self_test():
    base = os.path.join(ROOT, RUN, "layout-selftest")
    if os.path.isdir(base):
        shutil.rmtree(base)
    old, new, bad = (os.path.join(base, x) for x in ("old", "new", "bad"))
    why = None
    try:
        plant(old, PLANT)
        # the bad plant's role files name a system the plant glossary knows
        plant(bad, dict((k, v) for k, v in PLANT.items() if k in ("Makefile", "include/common.h", "docs/glossary.md")))
        plant(bad, BAD)
        # the role file of rock_94 names its system through a stem-matching function
        with open(os.path.join(bad, "src/rock_94/text_box.c"), "a") as f:
            f.write("void update_text_box(void) {\n}\n")
        with open(os.path.join(bad, "src/rock_94/text_box_800E9420.c"), "a") as f:
            f.write("void open_text_box(void) {\n}\n")
        plant(bad, {"config/symbols.rock_94.txt": "update_text_box = 0x800E9410;\nopen_text_box = 0x800E9430;\n"})
        t = Tree(old)
        if cmd_propose(t):
            raise Refuse("propose failed on the plant")
        rows = read_rows(Tree(old))
        roles90 = [r for r in rows if r[0] == "rock_90" and not r[2].startswith("src/shared/")]
        # T15.1: placeholder runs split out by vram, adjacent systems split (capsule|sound), equal systems join
        # (update/draw/fill/update_text_box_cursor under the text_box stem), noun fallback (play_sound -> sound)
        want = [("src/rock_90/800E9900.c", "-"), ("src/rock_90/text_box.c", "text_box"),
                ("src/rock_90/800E9C00.c", "-"), ("src/rock_90/capsule.c", "capsule"), ("src/rock_90/sound.c", "sound"),
                ("src/rock_90/800E9F80.c", "-")]
        if [(r[2], r[5]) for r in roles90] != want:
            raise Refuse("role rows %s" % [(r[2], r[5]) for r in roles90])
        exe = [(r[2], r[5]) for r in rows if r[0] == EXE]
        if exe != [("src/SLUS_013.95/80012000.c", "-"), ("src/SLUS_013.95/weapon/guard_shell.c", "guard_shell")]:
            raise Refuse("SLUS rows (folder = the system holding the stem, placeholder flat) %s" % exe)
        # T24: a whole name that is a system-held stem is its own system; a glossary row alone is not
        if system_of("memcard_format", {"memcard_format"}, {"memcard_format": "weapon"}) != "memcard_format" or \
                system_of("start_capsule", {"start_capsule"}, {}) != "capsule":
            raise Refuse("whole-name stem rule")
        # T24: a SLUS stem in no system is refused, nothing written
        unk = os.path.join(base, "unknown")
        plant(unk, PLANT)
        plant(unk, {"docs/layout.md": "## SLUS systems\n\n| system | holds | stems |\n|---|---|---|\n"})
        ub = snapshot(unk)
        try:
            urc = cmd_propose(Tree(unk))
        except Refuse:
            urc = 1
        if urc != 1 or snapshot(unk) != ub:
            raise Refuse("unknown-system stem not refused (rc %s)" % urc)
        if not any(r[2] == "src/shared/text_box/draw_text_box.c" for r in rows):
            raise Refuse("twin run did not collapse")
        print("LAYOUT self-test rules: placeholder runs by vram, systems split/join, noun fallback, SLUS system folder, "
              "whole-name stem, unknown system refused")
        if cmd_check(Tree(old)):
            raise Refuse("check refused the old plant")
        before = snapshot(old)
        if cmd_apply(Tree(old), "rock_90", dry=True, allow_no_cpp=True):
            raise Refuse("apply --dry-run failed")
        after = snapshot(old)
        if before != after:
            raise Refuse("apply --dry-run touched the plant")
        # twin whose other member is not applied: rock_91 now includes the collapsed run, the old copies are gone
        half = os.path.join(base, "half")
        shutil.copytree(old, half)
        if cmd_apply(Tree(half), "rock_90", dry=False, allow_no_cpp=True):
            raise Refuse("apply rock_90 alone failed")
        u91 = open(os.path.join(half, "src/rock_91/E9860.c")).read()
        if u91.count('#include "../shared/text_box/draw_text_box.c"\n') != 1 or "shared/rock_90/" in u91 or \
                any(os.path.exists(os.path.join(half, "src/shared/rock_90", b))
                    for b in ("func_800E9B00.c", "func_800E9B10.c")):
            raise Refuse("twin of an unapplied member not rewritten")
        if cmd_apply(Tree(half), "rock_91", dry=False, allow_no_cpp=True) or cmd_check(Tree(half)):
            raise Refuse("apply rock_91 after its twin moved")
        print("LAYOUT self-test twin rewrite: unapplied member repointed, one copy")
        shutil.copytree(old, new)
        for p in ("rock_90", "rock_91", EXE):
            if cmd_apply(Tree(new), p, dry=False, allow_no_cpp=True):
                raise Refuse("apply %s failed" % p)
        if os.path.exists(os.path.join(new, "src/shared/rock_90/func_800E9B00.c")):
            raise Refuse("collapsed twin body not deleted")
        if not os.path.exists(os.path.join(new, "src/shared/entity/state_dispatch.c")):
            raise Refuse("fixed dir touched")
        role = open(os.path.join(new, "src/rock_90/capsule.c")).read()
        if "// clang-format off\nINCLUDE_ASM" not in role or not role.rstrip().endswith("// clang-format on"):
            raise Refuse("INCLUDE_ASM fence missing")
        to, tn = Tree(old), Tree(new)
        n = 0
        for p, tu in to.units():
            for f in to.fns(p, tu):
                a, b = locate(p, f.name, to), locate(p, f.name, tn)
                ta = to.lines(a[0])[a[1] - 1:a[2]]
                tb = tn.lines(b[0])[b[1] - 1:b[2]]
                if ta != tb or a[3] != b[3] or a[0] == b[0] and not a[0].startswith(FIXED):
                    raise Refuse("locate %s %s: %s vs %s" % (p, f.name, a, b))
                n += 1
        if locate("rock_90", 0x800E9A00, to)[0] != "src/shared/rock_90/update_text_box.c" or \
                unit_of("rock_90", "update_text_box", tn) != "E9860":
            raise Refuse("locate by vram / unit_of")
        print("LAYOUT self-test locate same on both layouts: %d functions" % n)
        # role-tree pass (T5): the plant's rock_90 unit as a thin wrapper over one role file; same answers
        sb, k = snapshot(old), 0
        with role_tree("rock_90", "E9860", root=old) as role:
            tr = Tree(old)
            for f in to.fns("rock_90", "E9860"):
                a, b = locate("rock_90", f.name, to), locate("rock_90", f.name, tr)
                if to.lines(a[0])[a[1] - 1:a[2]] != tr.lines(b[0])[b[1] - 1:b[2]] or a[3] != b[3] or \
                        (a[0] == "src/rock_90/E9860.c") != (b[0] == role):
                    raise Refuse("role-tree locate %s: %s vs %s" % (f.name, a, b))
                k += 1
            fa = find_asm("rock_90", "func_800E9950", tr)
            if fa is None or fa[0] != role or fa[2] != "E9860" or \
                    tr.lines(role)[fa[1] - 1] != asm_line("rock_90", "E9860", "func_800E9950"):
                raise Refuse("role-tree find_asm %s" % (fa,))
            if find_asm("rock_90", "func_800E9900", tr) is not None or \
                    new_body("rock_90", "f") != "src/shared/rock_90/f.c":
                raise Refuse("find_asm of a C body / new_body")
        if snapshot(old) != sb:
            raise Refuse("role-tree left the plant changed")
        print("LAYOUT self-test role-tree pass: %d functions, find_asm in the role file" % k)
        if cmd_check(tn):
            raise Refuse("check refused the applied plant")
        d = defects(Tree(bad))
        want = {"out-of-order rock_92 E9860 func_800E9100", "duplicate rock_93 E9860 func_800E9300",
                "split rock_94 E9860 src/rock_94/text_box.c twice",
                "split rock_94 E9860 src/rock_94/text_box.c+src/rock_94/text_box_800E9420.c",
                "split rock_94 E9860 src/rock_94/text_box_800E9420.c+src/rock_94/text_box.c"}
        if not want <= set(d):
            raise Refuse("check plants: missing %s" % sorted(want - set(d)))
        mv = read_moves(tn)
        with open(os.path.join(new, "cites.txt")) as f:
            txt = f.read()
        out, cnt = repoint_text(txt, mv)
        if cnt[1] != 3 or "src/rock_90/text_box.c:" not in out or "src/shared/rock_90/" in out:
            raise Refuse("repoint %s" % cnt)
        cb = snapshot(new)
        cmd_repoint(tn, ["cites.txt"], dry=True)
        if snapshot(new) != cb:
            raise Refuse("repoint --dry-run wrote")
        # T15.1 re-apply of an L-B program: the T15 batch is repointed first (marks it), then the glossary loses
        # text_box and capsule: update_text_box_cursor leaves text_box.c (reused in place) for text_box_cursor.c,
        # capsule.c goes (capsule_gfx.c); the cites follow once, a second repoint maps 0
        re_ = os.path.join(base, "re")
        shutil.copytree(new, re_)
        tr = Tree(re_)
        cur, cap = locate("rock_90", "update_text_box_cursor", tr), locate("rock_90", "init_capsule_gfx", tr)
        plant(re_, {CITES[0]: "e %s:%d\nf %s:%d\ng %s rock_90:0x800E9B20\n" % (cur[0], cur[1], cap[0], cap[1],
                                                                                  cur[0])})
        cmd_repoint(tr, None, dry=False)
        plant(re_, {"docs/glossary.md": "## Terms\n\n| English term | Our stem | Source |\n|---|---|---|\n"
                                        "| guard shell | guard_shell | plant |\n"})
        if cmd_propose(Tree(re_)) or cmd_apply(Tree(re_), "rock_90", dry=False, allow_no_cpp=True):
            raise Refuse("re-apply of an applied program failed")
        tr = Tree(re_)
        roles = [r[2] for r in read_rows(tr, "rock_90") if not r[2].startswith("src/shared/")]
        if "src/rock_90/text_box_cursor.c" not in roles or "src/rock_90/capsule_gfx.c" not in roles or \
                os.path.exists(os.path.join(re_, "src/rock_90/capsule.c")) or defects(tr):
            raise Refuse("re-apply roles %s" % roles)
        for p, tu in to.units():
            for f in to.fns(p, tu):
                a, b = locate(p, f.name, to), locate(p, f.name, tr)
                if to.lines(a[0])[a[1] - 1:a[2]] != tr.lines(b[0])[b[1] - 1:b[2]] or a[3] != b[3]:
                    raise Refuse("re-apply locate %s %s: %s vs %s" % (p, f.name, a, b))
        cmd_repoint(tr, None, dry=False)
        with open(os.path.join(re_, CITES[0])) as f:
            got = [l.split()[1].rsplit(":", 1) for l in f if l.strip()]
        if got[2] != ["src/rock_90/text_box_cursor.c"]:
            raise Refuse("re-apply repoint of a split file's bare cite by vram %s" % got[2])
        got = got[:2]
        if [g[0] for g in got] != ["src/rock_90/text_box_cursor.c", "src/rock_90/capsule_gfx.c"] or \
                any(n not in tr.lines(g)[int(k) - 1] for (g, k), n in zip(got, ("update_text_box_cursor",
                                                                                 "init_capsule_gfx"))):
            raise Refuse("re-apply repoint %s" % got)
        with open(os.path.join(re_, CITES[0])) as f:
            if repoint_text(f.read(), read_moves(Tree(re_)))[1][1] != 0:
                raise Refuse("repoint not idempotent")
        print("LAYOUT self-test re-apply: role file reused in place, one deleted, cites moved once")
        # T17: a body renamed in git (one line added above its definition) leaves a stale cite no move maps; repoint
        # finds it through git + locate; a cite-anchor cite (update_text_box.c gains a line) is repointed the same way
        st = os.path.join(base, "stale")
        plant(st, PLANT)
        g = ["git", "-C", st, "-c", "user.name=t", "-c", "user.email=t@t", "-c", "commit.gpgsign=false",
             "-c", "core.hooksPath=/dev/null"]
        subprocess.run(["git", "init", "-q", st], check=True)
        subprocess.run(g + ["add", "-A"], check=True)
        subprocess.run(g + ["commit", "-qm", "a"], check=True)
        old_body = "src/shared/rock_90/func_800E9900.c"
        os.remove(os.path.join(st, old_body))
        plant(st, {"src/shared/rock_90/single_site.c": '#include "common.h"\n\n/* single-site body */\n/* moved */\n'
                                                       "void func_800E9900(void) {\n}\n",
                   "src/rock_90/E9860.c": PLANT["src/rock_90/E9860.c"].replace("func_800E9900.c", "single_site.c"),
                   "src/shared/rock_90/update_text_box.c": PLANT["src/shared/rock_90/update_text_box.c"].replace(
                       "\n\nvoid", "\n\n/* text box */\nvoid")})
        subprocess.run(g + ["add", "-A"], check=True)
        subprocess.run(g + ["commit", "-qm", "b"], check=True)
        plant(st, {CITES[0]: "x code:%s:4 via=func_800E9900\ny code:src/shared/rock_90/update_text_box.c:3 "
                             "via=update_text_box\nz %s\n" % (old_body, old_body)})
        ts = Tree(st)
        d = cite_defects(ts)
        want = ["stale-cite %s:1 %s:4" % (CITES[0], old_body),
                "cite-anchor %s:2 src/shared/rock_90/update_text_box.c:3" % CITES[0],
                "stale-cite %s:3 %s" % (CITES[0], old_body)]
        if d != want:
            raise Refuse("cite check plants %s" % d)
        cmd_repoint(ts, None, dry=False)
        with open(os.path.join(st, CITES[0])) as f:
            got = f.read().split("\n")
        if got[0] != "x code:src/shared/rock_90/single_site.c:5 via=func_800E9900" or \
                got[1] != "y code:src/shared/rock_90/update_text_box.c:4 via=update_text_box" or \
                got[2] != "z src/shared/rock_90/single_site.c" or cite_defects(Tree(st)):
            raise Refuse("stale repoint %s" % got)
        print("LAYOUT self-test stale and cite-anchor cites: repointed through git + locate, check clean")
        # T17.c2: one plant per fallback rule, plus the refusals (equidistant duplicate, anchor absent)
        two = ["void f(void) {", "    g_t = 1;", "}", "void h(void) {", "    g_t = 2;", "    x();", "    y();",
               "    g_t = 3;", "}"]
        dup = ["void f(void) {", "", "    g_t = 1;", "", "", "", "", "", "    g_t = 1;", "}", "    g_t = 1;"]
        got = [remap_line(["", "  g_t = 1;"], 2, ["x", "", "g_t = 1;"], 0, 2, "g_t"),
               remap_line(["    v = foo(a, b);"], 1, ["void f(void) {", "    v = foo(a,", "        b);", "}"], 0, 3,
                          "foo"),
               remap_line(["    g_t = 1;"] * 4, 4, dup, 0, 9, "g_t"),
               remap_line(["    g_t = 1;"] * 6, 6, dup, 0, 10, "g_t"),
               anchor_line(["// g_t", "void f(void) {", "    g_t = 1;", "}"], 1, "g_t"),
               anchor_line(two, 6, "g_t"),
               anchor_line(two, 6, "g_u"),
               anchor_line(two + ["void k(void) {", "    g_v = 1;", "    z();", "    g_v = 2;", "}"], 12, "g_v")]
        want = [(3, "R1"), (2, "R2"), (3, "R3"), (None, "R3"), (3, "R4"), (5, "R4"), (None, None), (None, "R4")]
        if got != want:
            raise Refuse("fallback rules %s" % got)
        print("LAYOUT self-test fallback rules: R1 exact, R2 reflow, R3 nearest dup, R4 file-unique and "
              "function-scoped nearest; equidistant dup, equidistant anchor and absent anchor refused")
    except (Refuse, OSError, TypeError, IndexError, KeyError, ValueError, subprocess.SubprocessError) as e:
        why = "%s: %s" % (type(e).__name__, e)
    finally:
        shutil.rmtree(base, ignore_errors=True)
    if why:
        print("LAYOUT CONTROL FAIL %s" % why)
        return 1
    print("LAYOUT CONTROL OK")
    return 0


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--self-test", action="store_true")
    sub = ap.add_subparsers(dest="cmd")
    sub.add_parser("propose")
    a = sub.add_parser("apply")
    a.add_argument("--prog", required=True)
    a.add_argument("--dry-run", action="store_true")
    r = sub.add_parser("repoint")
    r.add_argument("--dry-run", action="store_true")
    r.add_argument("files", nargs="*")
    c = sub.add_parser("check")
    c.add_argument("--prog")
    args = ap.parse_args()
    if args.self_test:
        return self_test()
    tree = Tree(ROOT)
    try:
        if args.cmd == "propose":
            return cmd_propose(tree)
        if args.cmd == "apply":
            return cmd_apply(tree, args.prog, args.dry_run)
        if args.cmd == "repoint":
            return cmd_repoint(tree, args.files, args.dry_run)
        if args.cmd == "check":
            return cmd_check(tree, args.prog)
    except Refuse as e:
        print("LAYOUT refused: %s" % e)
        return 1
    ap.print_help()
    return 2


if __name__ == "__main__":
    sys.exit(main())
