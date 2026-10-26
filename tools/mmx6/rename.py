#!/usr/bin/env python3
"""rename.py -- rename one X6 symbol everywhere the byte-neutral build reads it (stdlib; host PY or container python3).

  rename.py <prog:0xVRAM> <new> --basis <ref> [--dry-run] [--root DIR]
      -> renames the symbol at prog:vram to <new>; <ref> is the basis text (`<kind> <basis-ref>`).
  rename.py --from <basis.tsv> [--dry-run] [--root DIR]
      -> every row `prog vram name basis-kind basis-ref tier` (TAB, `#` lines skipped; the first row of a
         (prog, vram) wins) whose current name differs from `name`, in file order; basis = `<kind> <basis-ref>`.
  rename.py --self-test
      -> planted tree under .run/<phase>/rename-selftest/ (removed at the end). Ends `RENAME CONTROL OK` rc 0, or
         `RENAME CONTROL FAIL <case>` rc 1.
  --dry-run prints the edit list and the left-alone hits, writes nothing. --root plants a tree (default: the repo).

Scope (C0125). Overlay prog P: src/P/**, src/shared/P/**, and the shared path of every config/dedup_registry.txt
row whose exemplar prog is P. SLUS_013.95: all of src/ and include/. Never asm/, build/, expected/, extracted/ (G6).
A file's prog = the path part after src/ or src/shared/ (src/probes and files directly in src/ -> SLUS_013.95).

Edits (one plan per rename, applied only when nothing refuses)
  symbols   config/symbols.<prog>.txt: the `name = 0xVRAM;` line gets <new>; the `// basis:` line above it gains or
            replaces a `; name: <basis>` suffix. No line (an auto-named exe symbol): `// basis: name: <basis>` and
            `<new> = 0xVRAM;` (`// type:func` for a func_) are inserted before the first higher address.
  scope     every word-bounded old-name token in the scope's src/include files (definitions, calls, prototypes,
            INCLUDE_ASM names, `#define` aliases, include paths).
  moves     src/shared files in scope whose stem is the old name -> `<new>.c` in the same directory.
  foreign   a TU outside the scope that includes an edited scope file: its `#define old`/`#undef old` lines around
            that include get <new>, and the include path follows a move.
  registry  config/dedup_registry.txt: in `define a=b`, `a` (exemplar namespace) is rewritten when the exemplar prog
            is P, `b` (member namespace) when the member prog is P (SLUS_013.95: every row, both sides); the
            shared-path column follows a move.
  credits   `x4port.py --credits` (cwd = root) when THIRD_PARTY.md names a moved path.
  journal   config/x4/renames.tsv gains `prog vram old new basis` (TAB, no header).

Refusals (`RENAME REFUSE <prog:vram> <why>`, rc 1; nothing of that rename is written), checked in this order
  unknown prog:vram             no config/symbols.<prog>.txt, or no symbols line, no func_/D_<VRAM> token in scope and
                                no function start at VRAM: a `"k":"func"` of config/ghidra/<prog>.jsonl, or (the prog
                                of its `# program` line) a config/boundaries.txt `fstart`/`lib` start (an asm-only
                                function, e.g. a PsyQ library one: it is func_<VRAM>, only its symbols line is inserted)
  define cycle <x>-><y>         a rewritten define set maps x to y with y != x also a source (C0072)
  <new> already defined         <new> is a name in the prog's symbols file, or a token on a non-preprocessor line of a
                                scope file (`#define` alias lines do not count)
  <new> defined in overlay <p>  SLUS_013.95 only: config/symbols.<p>.txt (an overlay) names <new>. Overlay code that
                                calls an exe symbol by name links through the Makefile PROVIDE of every name
                                config/symbols.SLUS_013.95.txt defines (T9.c1; C0251's refusal is lifted), so an
                                overlay name equal to <new> would collide with it
  <f> included by <tu> without #define <old>
                                overlay prog only: an edited scope file uses old on a code line and a TU outside the
                                scope includes it with no `#define old` in the block above the include (it would
                                reference <new>; an exe <new> links in every overlay, so exe renames never refuse this)
  target exists <path>          a move target already exists

Lines (deterministic order)
  RENAME EDIT <path> <what>          one per edited file
  RENAME MOVE <old path> <new path>
  RENAME LEFT <path> <kind>          every other tracked hit of the old name (git ls-files, else a walk): kinds
                                     `other prog` (a C0125 repeat in src/include), `history` (journals, logs, docs,
                                     oracle/partner tables), `tool` (tools/ code and fixtures), `unclassified`
  RENAME <prog:vram> <old> -> <new>  per applied (or, with --dry-run, planned) rename
  RENAME OK <n> renamed <u> unchanged | RENAME FAIL <m> refused    last line
"""
import argparse
import json
import os
import re
import shutil
import subprocess
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parents[2]


def phase_scratch(root):
    """The open phase's temp folder (as tools/run.sh: `# Phase <id>` line 1 of PHASE_PLAN.md), else .run (no plan)."""
    try:
        line = (root / "phase-ends/current/PHASE_PLAN.md").read_text().split("\n", 1)[0]
    except OSError:
        line = ""
    m = re.match(r"#\s*Phase\s+([A-Za-z0-9._-]+)", line)
    return root / ".run" if not m or m.group(1) in (".", "..") else root / ".run" / m.group(1)


EXE = "SLUS_013.95"
SELFTEST = phase_scratch(REPO) / "rename-selftest"
NEVER = ("asm/", "build/", "expected/", "extracted/")
SYM = re.compile(r"^(\w+)\s*=\s*0x([0-9A-Fa-f]+);")
INCL = re.compile(r'^\s*#\s*include\s+"([^"]+)"')
HISTORY = ("campaign/", "phase-ends/", "docs/", "drafts/", "tasks/", "research/", "cookbook/", "rules/", "waves/",
           "logs/", "config/oracle.", "PHASE", "GENERATION_PLAN")


class Refuse(Exception):
    pass


def word(name):
    return re.compile(r"(?<![A-Za-z0-9_])" + re.escape(name) + r"(?![A-Za-z0-9_])")


def is_pp(line):
    return line.lstrip().startswith("#")


NOISE = re.compile(r'/\*.*?\*/|//[^\n]*|"(?:\\.|[^"\\\n])*"', re.S)


def code_hit(text, rx):
    """rx on a code line: comments and string literals blanked (newlines kept), preprocessor lines skipped."""
    text = NOISE.sub(lambda m: re.sub(r"[^\n]", " ", m.group(0)), text)
    return any(rx.search(ln) for ln in text.split("\n") if not is_pp(ln))


def path_prog(rel):
    """prog of a src/include path per renamecov's rule (None outside src/)."""
    parts = rel.split("/")
    if parts[0] != "src":
        return None
    if len(parts) > 2 and parts[1] == "shared":
        return parts[2] if len(parts) > 3 else EXE
    if len(parts) == 2 or parts[1] == "probes":
        return EXE
    return parts[1]


class Tree:
    def __init__(self, root):
        self.root = Path(root)
        self.cache = {}
        self.starts = {}
        self.progs = sorted(p.name[len("symbols."):-len(".txt")] for p in (self.root / "config").glob("symbols.*.txt"))
        self.code = sorted(str(p.relative_to(self.root)) for d in ("src", "include") if (self.root / d).is_dir()
                           for p in (self.root / d).rglob("*") if p.is_file() and p.suffix in (".c", ".h"))

    def read(self, rel):
        if rel not in self.cache:
            self.cache[rel] = (self.root / rel).read_text(errors="replace")
        return self.cache[rel]

    def write(self, rel, text):
        self.cache[rel] = text
        (self.root / rel).write_text(text)

    def tracked(self):
        if (self.root / ".git").exists():
            out = subprocess.run(["git", "ls-files"], cwd=self.root, capture_output=True, text=True, check=True)
            files = out.stdout.splitlines()
        else:
            files = [str(p.relative_to(self.root)) for p in self.root.rglob("*") if p.is_file()]
        return sorted(f for f in files if not f.startswith(NEVER) and not f.startswith(".git/"))

    def symbols(self, prog):
        rel = f"config/symbols.{prog}.txt"
        return rel, self.read(rel).split("\n")

    def current(self, prog, vram):
        if prog not in self.progs:
            return None
        _, lines = self.symbols(prog)
        for ln in lines:
            m = SYM.match(ln)
            if m and int(m.group(2), 16) == vram:
                return m.group(1)
        for name in (f"func_{vram:08X}", f"D_{vram:08X}"):
            rx = word(name)
            if any(rx.search(self.read(f)) for f in self.scope(prog)):
                return name
        return f"func_{vram:08X}" if vram in self.funcs(prog) else None

    def funcs(self, prog):
        """function starts (tracked lists, asm-only functions included): config/ghidra/<prog>.jsonl `func` rows, and
        config/boundaries.txt `fstart`/`lib` lo when its `# program` is prog (ghidra misses a few library starts)."""
        if prog not in self.starts:
            path, got = self.root / f"config/ghidra/{prog}.jsonl", set()
            if path.exists():
                for ln in path.open():
                    if '"k":"func"' in ln:
                        got.add(int(json.loads(ln)["addr"], 16))
            path, mine = self.root / "config/boundaries.txt", False
            if path.exists():
                for ln in path.open():
                    w = ln.split()
                    if w[:2] == ["#", "program"] and len(w) > 2:
                        mine = w[2] == prog
                    elif mine and w and w[0] in ("fstart", "lib"):
                        got.add(int(w[1], 16))
            self.starts[prog] = got
        return self.starts[prog]

    def registry(self):
        rel = "config/dedup_registry.txt"
        return rel, (self.read(rel).split("\n") if (self.root / rel).exists() else [])

    def scope(self, prog):
        if prog == EXE:
            return list(self.code)
        _, reg = self.registry()
        bodies = {ln.split(" ")[2] for ln in reg if ln and not ln.startswith("#") and len(ln.split(" ")) > 2
                  and ln.split(" ")[1].split(":")[0] == prog}
        return sorted(f for f in self.code if f.startswith((f"src/{prog}/", f"src/shared/{prog}/")) or f in bodies)


def includes(tree, rel, text=None):
    """[(line index, resolved path)] of the quoted includes of rel (its text, or the given one)."""
    out = []
    for i, ln in enumerate((tree.read(rel) if text is None else text).split("\n")):
        m = INCL.match(ln)
        if m:
            out.append((i, os.path.normpath(os.path.join(os.path.dirname(rel), m.group(1)))))
    return out


def block(lines, i):
    """indices of the contiguous #define lines above line i and #undef lines below it."""
    idx, j = [], i - 1
    while j >= 0 and lines[j].lstrip().startswith("#define"):
        idx.append(j)
        j -= 1
    j = i + 1
    while j < len(lines) and lines[j].lstrip().startswith("#undef"):
        idx.append(j)
        j += 1
    return sorted(idx)


def cycle(pairs):
    srcs = {a for a, _ in pairs}
    for a, b in pairs:
        if b != a and b in srcs:
            return f"{a}->{b}"
    return None


def plan(tree, prog, vram, new, basis):
    """(old, edits {rel: text}, moves [(old, new)], left [(rel, kind)]) or raise Refuse."""
    old = tree.current(prog, vram)
    if old is None:
        raise Refuse("unknown prog:vram")
    if old == new:
        return old, {}, [], []
    rx, scope = word(old), tree.scope(prog)
    edits, moves = {}, []
    # symbols file
    srel, lines = tree.symbols(prog)
    lines = list(lines)
    hit = next((i for i, ln in enumerate(lines) if (m := SYM.match(ln)) and int(m.group(2), 16) == vram), None)
    if hit is not None:
        lines[hit] = SYM.sub(lambda m: f"{new} = 0x{m.group(2)};", lines[hit], count=1)
        if hit > 0 and lines[hit - 1].startswith("// basis:"):
            lines[hit - 1] = lines[hit - 1].split("; name: ")[0] + f"; name: {basis}"
        else:
            lines.insert(hit, f"// basis: name: {basis}")
    else:
        at = next((i for i, ln in enumerate(lines) if (m := SYM.match(ln)) and int(m.group(2), 16) > vram), None)
        if at is None:
            at = len(lines) - 1 if lines and lines[-1] == "" else len(lines)
        else:
            while at > 0 and lines[at - 1].startswith("// basis:"):
                at -= 1
        typ = " // type:func" if old.startswith("func_") else ""
        lines[at:at] = [f"// basis: name: {basis}", f"{new} = 0x{vram:08X};{typ}"]
    edits[srel] = "\n".join(lines)
    # scope token rewrite
    for f in scope:
        text = tree.read(f)
        if rx.search(text):
            edits[f] = rx.sub(new, text)
    for f in scope:
        if f.startswith("src/shared/") and Path(f).stem == old:
            moves.append((f, str(Path(f).with_name(new + Path(f).suffix))))
    moved = dict(moves)
    # foreign includers
    inscope = set(scope)
    used = {f for f in scope if code_hit(tree.read(f), rx)}
    foreign = [f for f in tree.code if f not in inscope] if prog != EXE else \
        [f for f in tree.code if path_prog(f) in tree.progs and path_prog(f) != EXE]
    refusals = []
    for t in foreign:
        orig = tree.read(t).split("\n")
        lines = edits.get(t, tree.read(t)).split("\n")
        changed = False
        for i, inc in includes(tree, t):
            if inc not in used and inc not in moved:
                continue
            blk = block(orig, i)
            if prog != EXE and inc in used and not any(orig[j].split()[1:2] == [old] for j in blk
                                       if orig[j].lstrip().startswith("#define")):
                refusals.append(f"{inc} included by {t} without #define {old}")
                continue
            if prog != EXE:
                for j in blk:
                    parts = lines[j].split(None, 2)
                    if len(parts) > 1 and parts[1] == old:
                        lines[j] = lines[j].replace(old, new, 1)
                        changed = True
                if inc in moved:
                    lines[i] = lines[i].replace(f"{old}{Path(inc).suffix}\"", f"{new}{Path(inc).suffix}\"", 1)
                    changed = True
        if changed:
            edits[t] = "\n".join(lines)
    # registry
    rrel, reg = tree.registry()
    reg = list(reg)
    sets = []
    for i, ln in enumerate(reg):
        if not ln or ln.startswith("#"):
            continue
        f = ln.split(" ", 5)
        if len(f) < 6:
            continue
        exp, mem = f[1].split(":")[0], f[3].split(":")[0]
        pairs = []
        if f[2] in moved:
            f[2] = moved[f[2]]
        if f[5].startswith("define "):
            words = f[5].split(" ")
            for k, m in enumerate(words[1:], 1):
                if "=" not in m:
                    continue  # trailing notes (`via tudecl`) stay verbatim
                a, _, b = m.partition("=")
                if a == old and (prog == EXE or exp == prog):
                    a = new
                if b == old and (prog == EXE or mem == prog):
                    b = new
                pairs.append((a, b))
                words[k] = f"{a}={b}"
            f[5] = " ".join(words)
        line = " ".join(f)
        if line != ln:
            reg[i] = line
            sets.append(pairs)
    if any(r != o for r, o in zip(reg, tree.registry()[1])):
        edits[rrel] = "\n".join(reg)
    # TU define blocks that now name <new>
    for t, text in edits.items():
        if t.startswith(("src/", "include/")):
            tl = text.split("\n")
            for i, _ in includes(tree, t, text):
                blk = [tuple(tl[j].split()[1:3]) for j in block(tl, i)
                       if tl[j].lstrip().startswith("#define") and len(tl[j].split()) >= 3]
                if any(new in pair for pair in blk):
                    sets.append(blk)
    cyc = next((c for c in map(cycle, sets) if c), None)
    if cyc:
        raise Refuse(f"define cycle {cyc}")
    nrx = word(new)
    if any(SYM.match(ln) and SYM.match(ln).group(1) == new for ln in tree.symbols(prog)[1]) or \
            any(code_hit(tree.read(f), nrx) for f in scope):
        raise Refuse(f"{new} already defined")
    if prog == EXE:
        for p in (q for q in tree.progs if q != EXE):
            if any(SYM.match(ln) and SYM.match(ln).group(1) == new for ln in tree.symbols(p)[1]):
                raise Refuse(f"{new} defined in overlay {p}")
    if refusals:
        raise Refuse(refusals[0])
    for a, b in moves:
        if (tree.root / b).exists():
            raise Refuse(f"target exists {b}")
    # left-alone hits
    handled = set(edits) | set(moved) | {"THIRD_PARTY.md", "config/x4/renames.tsv"}
    left = []
    for f in tree.tracked():
        if f in handled:
            continue
        try:
            text = tree.read(f)
        except OSError:
            continue
        if not rx.search(text):
            continue
        kind = "other prog" if f.startswith(("src/", "include/", "config/symbols.")) else \
            "history" if f.startswith(HISTORY) else "tool" if f.startswith("tools/") else "unclassified"
        left.append((f, kind))
    return old, edits, moves, left


def apply(tree, prog, vram, new, basis, dry):
    old, edits, moves, left = plan(tree, prog, vram, new, basis)
    if old == new:
        return False
    for f in sorted(edits):
        what = "symbols line" if f.startswith("config/symbols.") else "registry rows" if "dedup_registry" in f \
            else "tokens"
        print(f"RENAME EDIT {f} {what}")
    for a, b in moves:
        print(f"RENAME MOVE {a} {b}")
    for f, kind in left:
        print(f"RENAME LEFT {f} {kind}")
    print(f"RENAME {prog}:0x{vram:08X} {old} -> {new}")
    if dry:
        return True
    for f in sorted(edits):
        tree.write(f, edits[f])
    for a, b in moves:
        text = tree.read(a)
        (tree.root / a).rename(tree.root / b)
        tree.cache.pop(a, None)
        tree.cache[b] = text
    tree.code = sorted(set(tree.code) - set(dict(moves)) | {b for _, b in moves})
    third = tree.root / "THIRD_PARTY.md"
    if moves and third.exists() and any(f"`{a}`" in third.read_text() for a, _ in moves):
        r = subprocess.run([sys.executable, str(REPO / "tools/mmx6/x4port.py"), "--credits"], cwd=tree.root,
                           capture_output=True, text=True)
        if r.returncode:
            sys.exit(f"rename: x4port --credits failed: {r.stdout}{r.stderr}")
        print(r.stdout.strip())
    log = tree.root / "config/x4/renames.tsv"
    log.parent.mkdir(parents=True, exist_ok=True)
    with log.open("a") as fh:
        fh.write(f"{prog}\t0x{vram:08X}\t{old}\t{new}\t{basis}\n")
    return True


def run(root, jobs, dry):
    tree = Tree(root)
    n = u = 0
    refused = []
    for prog, vram, new, basis in jobs:
        pv = f"{prog}:0x{vram:08X}"
        try:
            if apply(tree, prog, vram, new, basis, dry):
                n += 1
            else:
                u += 1
        except Refuse as e:
            refused.append(f"RENAME REFUSE {pv} {e}")
    for r in refused:
        print(r)
    print(f"RENAME FAIL {len(refused)} refused" if refused else f"RENAME OK {n} renamed {u} unchanged")
    return 1 if refused else 0


def parse_pv(pv):
    prog, _, v = pv.partition(":")
    return prog, int(v, 16)


def from_tsv(path):
    jobs, seen = [], set()
    for ln in Path(path).read_text().splitlines():
        if not ln or ln.startswith("#"):
            continue
        f = ln.split("\t")
        key = (f[0], int(f[1], 16))
        if key in seen:
            continue
        seen.add(key)
        jobs.append((f[0], key[1], f[2], f"{f[3]} {f[4]}"))
    return jobs


# ---- self-test -------------------------------------------------------------------------------------------------------

HDR = "/* Adapted from sozud/mmx4 @6a6b455 src/main/a.c:dust_end, AGPL-3.0; proven shared with X6 by exact signature " \
      "abcdef123456 (see THIRD_PARTY.md). */\n"
TP = "| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `6a6b455` | AGPL-3.0 | `{}` | " \
     "exact signature `abcdef123456`, `src/main/a.c:dust_end` |\n"
REG = "# registry\n" \
      "k1 rock_09:0x800EE934 src/shared/rock_09/func_800EE934.c rock_09:0x800EE934 gated exemplar\n" \
      "k1 rock_09:0x800EE934 src/shared/rock_09/func_800EE934.c rock_24:0x800ED454 gated define " \
      "func_800EE934=func_800ED454 func_800E0100=func_800E5100 via tudecl\n" \
      "k2 rock_15:0x800EE934 src/shared/rock_15/func_800EE934.c rock_15:0x800EE934 gated exemplar\n" \
      "k3 SLUS_013.95:0x8003744C src/shared/entity/state_dispatch.c SLUS_013.95:0x8003744C gated exemplar\n" \
      "k3 SLUS_013.95:0x8003744C src/shared/entity/state_dispatch.c rock_24:0x800EDD54 gated define " \
      "func_8003744C=func_800EDD54\n" \
      "k4 rock_02:0x800E0000 src/shared/rock_02/func_800E0000.c rock_02:0x800E0000 gated exemplar\n" \
      "k4 rock_02:0x800E0000 src/shared/rock_02/func_800E0000.c rock_06:0x800E5000 gated define " \
      "func_800E0000=func_800E5000 func_800E0100=func_800E5100\n"
PLANT = {
    "config/symbols.SLUS_013.95.txt": "// exe\n// basis: pc0\n__start = 0x80054AD8;\n",
    "config/ghidra/SLUS_013.95.jsonl": '{"k":"program","name":"SLUS_013.95"}\n'
                                       '{"k":"func","addr":"0x80069f04","name":"read"}\n',
    "config/boundaries.txt": "# program SLUS_013.95 base 0x80010000\nlib 0x800615f4 0x80061624 LIBETC.LIB/VMODE.OBJ\n",
    "config/symbols.rock_09.txt": "// r9\n// basis: first code word\nfunc_800EE934 = 0x800EE934; // type:func\n",
    "config/symbols.rock_15.txt": "// basis: x\nfunc_800EE934 = 0x800EE934; // type:func\n",
    "config/symbols.rock_24.txt": "// basis: y\nfunc_800ED454 = 0x800ED454; // type:func\n"
                                  "// basis: z\nfunc_800EDD54 = 0x800EDD54; // type:func\n",
    "config/symbols.rock_02.txt": "// basis: a\nfunc_800E0000 = 0x800E0000;\n// basis: b\nfunc_800E0100 = 0x800E0100;\n",
    "config/symbols.rock_06.txt": "// basis: c\nfunc_800E5000 = 0x800E5000;\n// basis: d\nfunc_800E5100 = 0x800E5100;\n",
    "config/symbols.rock_07.txt": "// basis: e\nfunc_800E7000 = 0x800E7000;\n// basis: f\nwall_hit = 0x800E7100;\n",
    "config/dedup_registry.txt": REG,
    "THIRD_PARTY.md": "x\n<!-- x4port credits -->\n| Component | Upstream | Commit / version | License | Paths here | "
                      "Basis (proof it is shared) |\n|---|---|---|---|---|---|\n"
                      + TP.format("src/shared/rock_09/func_800EE934.c") + "<!-- /x4port credits -->\n",
    "include/exe.h": "void func_8003744C(s8* arg0);\nvoid func_8002D2B0(void*);\n",
    "src/SLUS_013.95/main.c": '#include "common.h"\n#include "../shared/entity/state_dispatch.c"\n'
                              "void f(void) { func_8003744C(0); }\nINCLUDE_ASM(\"asm/x\", func_8002D2B0);\n",
    "src/shared/entity/state_dispatch.c": "void func_8003744C(s8* arg0) {\n    D_80073C1C[arg0[6]](arg0);\n}\n",
    "src/shared/rock_09/func_800EE934.c": HDR + "void func_800EE934(void* self) {\n    func_800E0100(self);\n}\n",
    "src/rock_09/E9860.c": '#include "../shared/rock_09/func_800EE934.c"\nvoid g(void) { func_800EE934(0); }\n',
    "src/rock_15/E9860.c": '#include "../shared/rock_15/func_800EE934.c"\nvoid h(void) { func_800EE934(0); }\n',
    "src/shared/rock_15/func_800EE934.c": "void func_800EE934(void* self) {\n}\n",
    "src/rock_24/E9860.c": "#define func_800EE934 func_800ED454\n#define func_800E0100 func_800E5100\n"
                           '#include "../shared/rock_09/func_800EE934.c"\n#undef func_800EE934\n#undef func_800E0100\n'
                           "#define func_8003744C func_800EDD54\n"
                           '#include "../shared/entity/state_dispatch.c"\n#undef func_8003744C\n',
    "src/rock_07/E9860.c": '#include "../shared/rock_07/func_800E7000.c"\nvoid k(void) { func_8002D2B0(0); }\n',
    "src/shared/rock_07/func_800E7000.c": "void func_800E7000(void) {\n    func_8002D2B0(1);\n}\n",
    "src/shared/rock_02/func_800E0000.c": "void func_800E0000(void) {\n    func_800E0100();\n}\n",
    "src/rock_02/E9860.c": '#include "../shared/rock_02/func_800E0000.c"\n',
    "src/rock_06/E9860.c": "#define func_800E0000 func_800E5000\n#define func_800E0100 func_800E5100\n"
                           '#include "../shared/rock_02/func_800E0000.c"\n#undef func_800E0000\n#undef func_800E0100\n',
    "basis.tsv": "# prog\tvram\tname\tbasis-kind\tbasis-ref\ttier\n"
                 "SLUS_013.95\t0x80054AD8\t__start\tdebug\tpc0\t-\n"
                 "rock_09\t0x800EE934\tdust_end\tx4\texact abcdef123456\tgate\n",
}


def selftest():
    shutil.rmtree(SELFTEST, ignore_errors=True)
    for rel, text in PLANT.items():
        p = SELFTEST / rel
        p.parent.mkdir(parents=True, exist_ok=True)
        p.write_text(text)
    rd = lambda rel: (SELFTEST / rel).read_text()
    fails = []

    def case(name, ok):
        if not ok:
            fails.append(name)

    import contextlib
    import io

    def go(jobs, dry=False):
        buf = io.StringIO()
        with contextlib.redirect_stdout(buf):
            rc = run(SELFTEST, jobs, dry)
        return rc, buf.getvalue()

    before = {r: rd(r) for r in PLANT}
    rc, out = go(from_tsv(SELFTEST / "basis.tsv"), dry=True)
    case("dry-run", rc == 0 and "RENAME LEFT basis.tsv" not in out and "RENAME MOVE" in out
         and "RENAME LEFT src/rock_15/E9860.c other prog" in out and all(rd(r) == before[r] for r in PLANT))
    rc, out = go(from_tsv(SELFTEST / "basis.tsv"))
    case("overlay rename", rc == 0 and "RENAME OK 1 renamed 1 unchanged" in out)
    case("symbols", "// basis: first code word; name: x4 exact abcdef123456\ndust_end = 0x800EE934; // type:func"
         in rd("config/symbols.rock_09.txt"))
    case("move", not (SELFTEST / "src/shared/rock_09/func_800EE934.c").exists()
         and "void dust_end(void* self)" in rd("src/shared/rock_09/dust_end.c"))
    case("tu", rd("src/rock_09/E9860.c") == '#include "../shared/rock_09/dust_end.c"\nvoid g(void) { dust_end(0); }\n')
    case("foreign tu", rd("src/rock_24/E9860.c").startswith(
        "#define dust_end func_800ED454\n#define func_800E0100 func_800E5100\n"
        '#include "../shared/rock_09/dust_end.c"\n#undef dust_end\n'))
    case("registry", "k1 rock_09:0x800EE934 src/shared/rock_09/dust_end.c rock_24:0x800ED454 gated define "
         "dust_end=func_800ED454 func_800E0100=func_800E5100 via tudecl\n" in rd("config/dedup_registry.txt"))
    case("repeat untouched", all(rd(r) == before[r] for r in
                                 ("src/rock_15/E9860.c", "src/shared/rock_15/func_800EE934.c",
                                  "config/symbols.rock_15.txt"))
         and "k2 rock_15:0x800EE934 src/shared/rock_15/func_800EE934.c" in rd("config/dedup_registry.txt"))
    case("credits", "`src/shared/rock_09/dust_end.c`" in rd("THIRD_PARTY.md")
         and "func_800EE934.c" not in rd("THIRD_PARTY.md"))
    case("journal", rd("config/x4/renames.tsv") ==
         "rock_09\t0x800EE934\tfunc_800EE934\tdust_end\tx4 exact abcdef123456\n")
    rc, out = go([(EXE, 0x8003744C, "state_dispatch", "debug d")])
    case("exe rename", rc == 0 and "void state_dispatch(s8* arg0)" in rd("src/shared/entity/state_dispatch.c")
         and "{ state_dispatch(0); }" in rd("src/SLUS_013.95/main.c")
         and "void state_dispatch(s8* arg0);" in rd("include/exe.h")
         and "#define state_dispatch func_800EDD54\n" in rd("src/rock_24/E9860.c")
         and "define state_dispatch=func_800EDD54" in rd("config/dedup_registry.txt")
         and "// basis: name: debug d\nstate_dispatch = 0x8003744C; // type:func\n// basis: pc0\n__start"
         in rd("config/symbols.SLUS_013.95.txt"))
    # an exe name overlay code calls directly: the overlay token is rewritten (Makefile PROVIDEs exe names, T9.c1)
    rc, out = go([(EXE, 0x8002D2B0, "move_object", "x")])
    case("exe name in overlay", rc == 0 and rd("src/rock_07/E9860.c") ==
         '#include "../shared/rock_07/func_800E7000.c"\nvoid k(void) { move_object(0); }\n'
         and "    move_object(1);\n" in rd("src/shared/rock_07/func_800E7000.c")
         and "void move_object(void*);" in rd("include/exe.h")
         and 'INCLUDE_ASM("asm/x", move_object);' in rd("src/SLUS_013.95/main.c"))
    # an asm-only function (no token in src/include): a ghidra function start; only its symbols line is inserted
    rc, out = go([(EXE, 0x80069F04, "read", "sdk LIBAPI/A52+0x0"), (EXE, 0x800615F4, "SetVideoMode", "sdk v")])
    case("asm-only start", rc == 0 and "RENAME SLUS_013.95:0x80069F04 func_80069F04 -> read" in out
         and rd("config/symbols.SLUS_013.95.txt").endswith(
             "__start = 0x80054AD8;\n// basis: name: sdk v\nSetVideoMode = 0x800615F4; // type:func\n"
             "// basis: name: sdk LIBAPI/A52+0x0\nread = 0x80069F04; // type:func\n"))
    snap = {r: rd(r) for r in ("src/rock_07/E9860.c", "include/exe.h", "config/symbols.SLUS_013.95.txt")}
    refusals = [
        ("refuse overlay name", [(EXE, 0x8003744C, "wall_hit", "x")],
         "RENAME REFUSE SLUS_013.95:0x8003744C wall_hit defined in overlay rock_07"),
        ("refuse cycle", [("rock_02", 0x800E0100, "func_800E5000", "x")],
         "RENAME REFUSE rock_02:0x800E0100 define cycle func_800E0000->func_800E5000"),
        ("refuse no define", [("rock_09", 0x800EE934, "dust_end2", "x")], None),
        ("refuse defined", [("rock_02", 0x800E0100, "func_800E0000", "x")],
         "RENAME REFUSE rock_02:0x800E0100 func_800E0000 already defined"),
        ("refuse unknown", [("rock_09", 0x800EF000, "nope", "x")], "RENAME REFUSE rock_09:0x800EF000 unknown prog:vram"),
    ]
    # the no-define case: rock_24's block loses its alias for the rock_09 body
    t = rd("src/rock_24/E9860.c").replace("#define dust_end func_800ED454\n", "")
    (SELFTEST / "src/rock_24/E9860.c").write_text(t)
    refusals[2] = (refusals[2][0], refusals[2][1], "RENAME REFUSE rock_09:0x800EE934 src/shared/rock_09/dust_end.c "
                   "included by src/rock_24/E9860.c without #define dust_end")
    for name, jobs, want in refusals:
        rc, out = go(jobs)
        case(name, rc == 1 and want in out.splitlines() and out.rstrip().endswith("RENAME FAIL 1 refused"))
    case("refusals write nothing", all(rd(r) == snap[r] for r in snap)
         and (SELFTEST / "src/shared/rock_09/dust_end.c").exists()
         and rd("config/x4/renames.tsv").count("\n") == 5)
    shutil.rmtree(SELFTEST, ignore_errors=True)
    if fails:
        print(f"RENAME CONTROL FAIL {fails[0]}")
        return 1
    print("RENAME CONTROL OK")
    return 0


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("pv", nargs="?", help="prog:0xVRAM")
    ap.add_argument("new", nargs="?")
    ap.add_argument("--basis")
    ap.add_argument("--from", dest="src", metavar="BASIS_TSV")
    ap.add_argument("--dry-run", action="store_true")
    ap.add_argument("--root", default=str(REPO))
    ap.add_argument("--self-test", action="store_true")
    a = ap.parse_args()
    if a.self_test:
        return selftest()
    if a.src:
        jobs = from_tsv(a.src)
    elif a.pv and a.new and a.basis:
        prog, vram = parse_pv(a.pv)
        jobs = [(prog, vram, a.new, a.basis)]
    else:
        ap.error("give <prog:0xVRAM> <new> --basis <ref>, or --from <basis.tsv>")
    return run(a.root, jobs, a.dry_run)


if __name__ == "__main__":
    sys.exit(main())
