#!/usr/bin/env python3
"""x4port.py -- the X4 lane: spelling-first port packs from mmx4's C for X6 functions with an exact mmx4 partner (container, stdlib).

  x4port.py --wave W-x4 [--root waves] [--pv P]... [--limit K]
      -> reads campaign/x4/partners.tsv (x4share.py --partners), the mmx4 clone .run/mmx4 (pinned 29b62af) and its
         objects .run/x4share/gcc2.95.2-psx-aspsx2.86/obj/<src>.o. Per census dup class (= exact key) with an open
         member (corpus asm|include_asm): skipped `class gated` (a gated registry row of the key) or `class banked <pv>`
         (a c|c-empty member: propagate's job) or `skipped no-c-unit` (no member bank can take); else the representative,
         its lowest (prog, vram) member that is include_asm in a config/c_units.txt unit (--pv: among those pvs), is
         ported from its partners.tsv partner (the first by src, func) into <root>/<wave>/<prog>_<func>/: pack.json
         {pv,prog,func,tu,words}, draft.c, verdict.json {pv,status:"draft",score:"-",lever:"-",notes}. --limit K: a
         deterministic stride sample of K representatives. Writes include/mmx6/x4.h (every run, the union of the run's
         packs' type/macro blocks; a pack whose block differs from an earlier pack's same-named block is skipped
         `x4.h conflict <name>`). Lines `X4PORT <pv> drafted <mmx4 src>:<func>` | `X4PORT <pv> skipped <why>`, last
         `X4PORT <wave> <k> packs of <o> open; <n> classes skipped no-c-unit; include/mmx6/x4.h <b> blocks`
         (o = open X6 functions in partners.tsv). Blocks whose mmx4 origin is include/psy-q-4.0/* (mmx4's copies of
         Sony SDK headers, not mmx4's AGPL) never reach x4.h: x4.h includes our include/mmx6/psyq_api.h instead (G102).
  x4port.py --wave W-x4 --x4h [--root waves]
      -> x4.h only, no packs written: the pv of every <root>/<wave>/*/pack.json (open or banked since) re-ported, in
         (prog, vram) order. Last line `X4PORT <wave> x4h <k> packs; include/mmx6/x4.h <b> blocks`.
  x4port.py --credits
      -> (re)writes the marked block (`<!-- x4port credits -->` .. `<!-- /x4port credits -->`, else in place of
         `*(none yet)*` and the table head above it) of THIRD_PARTY.md: the components table, one row per adapted file
         (include/mmx6/x4.h, each src/shared/**/*.c that opens with the attribution header), sorted by path. Line
         `X4PORT CREDITS <n> rows`.
  x4port.py --self-test
      -> planted control (C0054) in .run/x4port-selftest/: our banked func_8001E78C (src/SLUS_013.95/120A0.c) as a fake
         mmx4 source and object, every D_8/func_8 name renamed (Q_8/fanc_8, the object's strtab patched in place, same
         length). (1) the port maps every name back by address arithmetic: draft body == our body, verbatim ok, its
         pack probes `match`; (2) one unmasked bit of the fake object flipped -> `not exact`; (3) one X6 relocation
         addend shifted by 4 -> the draft names another symbol; (4) a psy-q-origin block never reaches x4.h. Ends `X4PORT CONTROL OK` | `X4PORT CONTROL FAIL <cases>`.

Port (G54, spelling first): the mmx4 definition's own text (raw source lines; the preprocessed text when the body holds
a preprocessor line), `static`/`inline` dropped from its head, then renamed: every mmx4 symbol the body relocates ->
the X6 name by relocation alignment (X4 object relocation at word i = symbol + addend; X6 TU object relocation at word
i = the splat name + addend; X6 base = X6 address - X4 offset into its symbol; name = an X6 ELF symbol at that address,
else D_/func_<ADDR>), the mmx4 function -> the X6 function. Context, only what the body uses (closure over the
preprocessed mmx4 TU's items before the definition, as mmx4's compile saw them, and cpp -dM): mmx4 macros (`#ifndef` guarded, ours win) and struct/union/enum definitions and
typedefs (tags and typedef names prefixed X4_, except typedef names our include/common.h already defines; each
guarded `#ifndef X4_D_<name>`) go to include/mmx6/x4.h (types and macros only, no data; a macro naming a relocated
symbol stays in the draft; a declaration defining a tag is split: the tag to x4.h, the declaration to the draft); the
draft holds `#include "common.h"`, `#include "mmx6/x4.h"` (when it uses a block), extern/prototype declarations
(definitions become `extern`, initialisers dropped: no initialised data is copied, G12), inline helpers whole, the
body. Refused (skipped): string literals, function-scope statics, a draft verbatim.check refuses. First line of a
draft and of x4.h: the attribution header (THIRD_PARTY.md; x4.h lists its mmx4 source files instead of a key).
"""
import argparse
import bisect
import json
import os
import re
import shutil
import struct
import subprocess
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import census  # noqa: E402
import propagate  # noqa: E402  (registry_rows)
import sig  # noqa: E402
import verbatim  # noqa: E402
import x4share  # noqa: E402

PARTNERS = "campaign/x4/partners.tsv"
FUNCS = "build/corpus/functions.jsonl"
CLASSES = "build/census/classes.jsonl"
REGISTRY = "config/dedup_registry.txt"
C_UNITS = "config/c_units.txt"
TRIPLE = "gcc2.95.2-psx-aspsx2.86"
PIN = "29b62af"
OPEN = ("asm", "include_asm")
SELFTEST = ".run/x4port-selftest"
SELF_PROG, SELF_FUNC, SELF_VRAM, SELF_TU = "SLUS_013.95", "func_8001E78C", "0x8001E78C", "120A0"
HEADER = ("/* Adapted from sozud/mmx4 @{pin} {src}:{func}, AGPL-3.0; proven shared with X6 by exact signature {key} "
          "(see THIRD_PARTY.md). */\n")
X4H = "include/mmx6/x4.h"
PSYQ = "include/psy-q-4.0/"  # mmx4's copies of the Sony SDK headers: never emitted; include/mmx6/psyq_api.h instead
X4H_HEADER = ("/* Adapted from sozud/mmx4 @{pin} {srcs}, AGPL-3.0; proven shared with X6 by the exact signature each "
              "including draft names (see THIRD_PARTY.md). */")
KEYWORDS = set("auto break case char const continue default do double else enum extern float for goto if int long "
               "register return short signed sizeof static struct switch typedef union unsigned void volatile while "
               "inline __inline__ __inline __attribute__ __asm__ asm __extension__ __volatile__ __const __signed__ "
               "__restrict defined".split())
MARK = re.compile(r'^#\s*(\d+)\s+"([^"]*)"')
TOK = re.compile(r'"(?:\\.|[^"\\\n])*"|\'(?:\\.|[^\'\\\n])*\'|/\*.*?\*/|//[^\n]*|[A-Za-z_]\w*|\S', re.S)
IDENT = re.compile(r"[A-Za-z_]\w*")
TAG = re.compile(r"\b(struct|union|enum)\s+([A-Za-z_]\w*)")
TAGDEF = re.compile(r"\b(struct|union|enum)\s+([A-Za-z_]\w*)\s*\{")
DEFINE = re.compile(r"#define\s+([A-Za-z_]\w*)(\([^)]*\))?[ \t]?(.*)")
ASMY = re.compile(r"\$[a-z]{1,2}[0-9]?\b|\$[0-9]{1,2}\b|\.word\b|\bglabel\b")
NOISE = re.compile(r"gcc2_compiled\.|__gnu_compiled_\w+")


class Skip(Exception):
    pass


def jl(path):
    with open(path) as f:
        return [json.loads(x) for x in f if x.strip()]


def strip_comments(text):
    return re.sub(r"/\*.*?\*/|//[^\n]*", lambda m: re.sub(r"[^\n]", " ", m.group(0)), text, flags=re.S)


# ---- ELF: relocations as (symbol, offset into it) per word -----------------------------------------------------------

class Elf:
    def __init__(self, path):
        with open(path, "rb") as f:
            self.b = b = f.read()
        shoff, = struct.unpack_from("<I", b, 0x20)
        shentsize, shnum, shstrndx = struct.unpack_from("<HHH", b, 0x2E)
        self.secs = [struct.unpack_from("<10I", b, shoff + i * shentsize) for i in range(shnum)]
        stro = self.secs[shstrndx][4]
        self.names = [b[stro + s[0]:b.index(b"\0", stro + s[0])].decode() for s in self.secs]
        self.syms, self.rels = [], {}
        for s in self.secs:
            if s[1] == 2:
                so = self.secs[s[6]][4]
                for o in range(s[4], s[4] + s[5], 16):
                    nm, val, size, info, _, shndx = struct.unpack_from("<IIIBBH", b, o)
                    self.syms.append((b[so + nm:b.index(b"\0", so + nm)].decode(), val, size, info, shndx))
        for s in self.secs:
            if s[1] == 9:  # SHT_REL
                self.rels[s[7]] = [struct.unpack_from("<II", b, s[4] + 8 * k) for k in range(s[5] // 8)]

    def word(self, sh, off):
        return struct.unpack_from("<I", self.b, self.secs[sh][4] + off)[0]

    def defined(self, name):
        return next((s for s in self.syms if s[0] == name and 0 < s[4] < len(self.secs)), None)

    def resolve(self, si, a):
        """(name, offset into it) of relocation symbol si + addend a; a section symbol -> the symbol holding a."""
        name, _, _, info, sh = self.syms[si]
        if info & 0xF != 3 or not 0 < sh < len(self.secs):
            return name, a
        cand = [s for s in self.syms if s[4] == sh and s[0] and s[3] & 0xF in (0, 1, 2) and not NOISE.fullmatch(s[0])
                and s[1] <= a]
        if not cand:
            return self.names[sh], a
        best = max(cand, key=lambda s: (s[1], s[3] & 0xF in (1, 2), s[0]))
        return best[0], a - best[1]

    def refs(self, func, n):
        """{word index: (reloc type, symbol, offset into it)} of func's n words (LO16, GPREL16, 26)."""
        s = self.defined(func)
        if s is None:
            raise Skip(f"no symbol {func}")
        sh, base = s[4], s[1]
        rels = [(off, info & 0xFF, info >> 8) for off, info in self.rels.get(sh, [])]
        his = {}
        for off, t, si in rels:
            if t == 5:
                his.setdefault(si, []).append((off, self.word(sh, off) & 0xFFFF))
        out = {}
        for off, t, si in rels:
            if not base <= off < base + 4 * n or t not in (4, 6, 7):
                continue
            w = self.word(sh, off)
            if t == 4:
                a = (w & 0x3FFFFFF) << 2
            else:
                a = (w & 0xFFFF) - ((w & 0x8000) << 1)
                h = his.get(si) if t == 6 else None
                if h:
                    before = [x for x in h if x[0] <= off]
                    a += (max(before) if before else min(h))[1] << 16
                    a = (a + 0x80000000) % (1 << 32) - 0x80000000
            name, e = self.resolve(si, a)
            out[(off - base) // 4] = (t, name, e)
        return out


class Addrs:
    """X6 symbol addresses of a linked program (build/<prog>.elf, absolute symbols included)."""

    def __init__(self, prog):
        e = Elf(f"build/{prog}.elf")
        self.by_name, self.by_addr = {}, {}
        for name, val, _, info, sh in e.syms:
            if name and info & 0xF != 4 and sh != 0 and not name.startswith(".") and not NOISE.fullmatch(name):
                self.by_name.setdefault(name, val)
                self.by_addr.setdefault(val, set()).add(name)

    def addr(self, name):
        if name in self.by_name:
            return self.by_name[name]
        m = re.search(r"_([0-9A-Fa-f]{8})$", name)
        return int(m.group(1), 16) if m else None

    def name(self, a, text):
        names = self.by_addr.get(a)
        if names:
            pref = [x for x in names if re.fullmatch(r"(D|func|jtbl)_[0-9A-F]{8}", x)]
            return min(pref or names), False
        return f"{'func' if text else 'D'}_{a:08X}", True


# ---- the mmx4 TU: preprocessed items and macros ----------------------------------------------------------------------

def run_cpp(cmd, cwd):
    p = subprocess.run(cmd, capture_output=True, text=True, cwd=cwd)
    if p.returncode != 0:
        raise Skip("cpp " + (p.stderr.strip().splitlines() or ["rc"])[-1][:80])
    return p.stdout


def toks(text):
    return [t for t in TOK.findall(text) if not t.startswith(("/*", "//"))]


def split_items(pp):
    """[(text, file, line)] top-level items of preprocessed C (`;`-ended, or a function definition's closing brace)."""
    lines, where, cur_f, cur_l = [], [], "", 1
    for raw in pp.split("\n"):
        m = MARK.match(raw)
        if m:
            cur_l, cur_f = int(m.group(1)), m.group(2)
            continue
        if raw.startswith("#"):
            cur_l += 1
            continue
        lines.append(raw)
        where.append((cur_f, cur_l))
        cur_l += 1
    text = "\n".join(lines)
    starts, o = [], 0
    for x in lines:
        starts.append(o)
        o += len(x) + 1
    items, depth, paren, start, brace, i, n = [], 0, 0, 0, 0, 0, len(text)

    def emit(a, b):
        s = text[a:b]
        k = len(s) - len(s.lstrip())
        if s.strip():
            items.append((s.strip(), *where[bisect.bisect_right(starts, a + k) - 1]))
    while i < n:
        c = text[i]
        if c in "\"'":
            j = i + 1
            while j < n and text[j] != c:
                j += 2 if text[j] == "\\" else 1
            i = j + 1
            continue
        if c == "{":
            if depth == 0:
                brace = i
            depth += 1
        elif c == "}":
            depth -= 1
            if depth == 0 and paren == 0 and re.search(r"\)\s*$", text[start:brace]) and \
                    not re.match(r"\s*typedef\b", text[start:brace]) and "=" not in text[start:brace]:
                emit(start, i + 1)
                start = i + 1
        elif c == "(":
            paren += 1
        elif c == ")":
            paren -= 1
        elif c == ";" and depth == 0 and paren == 0:
            emit(start, i + 1)
            start = i + 1
        i += 1
    return items


def unbrace(s, mark=""):
    """s with every {...} group removed (balanced), each outermost group replaced by mark."""
    out, depth = [], 0
    for c in s:
        if c == "{":
            depth += 1
        elif c == "}":
            depth -= 1
            if depth == 0:
                out.append(mark)
        elif depth == 0:
            out.append(c)
    return "".join(out)


def unattr(s):
    while True:
        m = re.search(r"__attribute__\s*\(", s)
        if not m:
            return s
        d, i = 0, m.end() - 1
        while i < len(s):
            d += {"(": 1, ")": -1}.get(s[i], 0)
            if d == 0:
                break
            i += 1
        s = s[:m.start()] + s[i + 1:]


def top_split(ts, sep):
    parts, cur, d = [], [], 0
    for t in ts:
        if t in "([":
            d += 1
        elif t in ")]":
            d -= 1
        if t == sep and d == 0:
            parts.append(cur)
            cur = []
        else:
            cur.append(t)
    return parts + [cur]


def declarators(s):
    """[(name, is a function declarator)] of a declaration's text (no typedef keyword, braces removed)."""
    out = []
    for part in top_split(toks(unattr(unbrace(s, " {} ")).rstrip(";")), ","):  # `union {} f32`: f32 is no tag
        part = top_split(part, "=")[0]
        if "(" in part:
            p = part.index("(")
            if p + 1 < len(part) and part[p + 1] == "*":
                nm = next((t for t in part[p + 1:] if IDENT.fullmatch(t) and t not in KEYWORDS), None)
                if nm:
                    out.append((nm, False))
                continue
            if p > 0 and IDENT.fullmatch(part[p - 1]) and part[p - 1] not in KEYWORDS:
                out.append((part[p - 1], True))
                continue
        cut = part[:part.index("[")] if "[" in part else part
        ids = [t for t in cut if IDENT.fullmatch(t) and t not in KEYWORDS]
        if ids and not (len(cut) >= 2 and cut[-2] in ("struct", "union", "enum")):
            out.append((ids[-1], False))
    return out


class Item:
    def __init__(self, idx, text, file, line):
        self.idx, self.text, self.file, self.line = idx, text, file, line
        self.names, self.tags, self.consts, self.proto = set(), set(), set(), False
        body = text.split("{", 1)
        self.kind = "decl"
        if re.match(r"(__asm__|asm)\b", text):
            self.kind = "asm"
            return
        if text.endswith("}") and re.search(r"\)\s*$", body[0]) and not text.startswith("typedef"):
            self.kind = "fdef"
            head = toks(body[0])
            d, k = 0, len(head) - 1
            while k >= 0:
                d += {")": 1, "(": -1}.get(head[k], 0)
                if d == 0:
                    break
                k -= 1
            self.names = {head[k - 1]} if k > 0 else set()
            self.head = body[0].strip()
            return
        for m in TAGDEF.finditer(text):
            self.tags.add(m.group(2))
        for m in re.finditer(r"\benum\b[^{;]*\{([^}]*)\}", text):
            for c in m.group(1).split(","):
                c = c.split("=")[0].strip()
                if IDENT.fullmatch(c):
                    self.consts.add(c)
        if text.startswith("typedef"):
            self.kind = "typedef"
            self.names = {n for n, _ in declarators(text[len("typedef"):])}
        elif re.fullmatch(r"(struct|union|enum)\s*(\w+\s*)?\{.*\}\s*;", text, re.S):
            self.kind = "tag"
        elif re.fullmatch(r"(struct|union|enum)\s+\w+\s*;", text):
            self.kind = "fwd"
        else:
            ds = declarators(text)
            self.names = {n for n, _ in ds}
            self.proto = any(f for _, f in ds)
        self.extern = text.startswith("extern")


def uses(text):
    t = toks(text)
    ids = {x for x in t if IDENT.fullmatch(x) and x not in KEYWORDS}
    return ids, {m.group(2) for m in TAG.finditer(" ".join(t))}


class TU:
    """One preprocessed mmx4 C file: items, name index, macros."""

    def __init__(self, cpp, cwd, src, builtins):
        self.src, self.cwd = src, cwd
        pp = run_cpp(cpp + [src], cwd)
        self.items = [Item(i, *x) for i, x in enumerate(split_items(pp))]
        self.files = sorted({os.path.normpath(m.group(1)) for m in re.finditer(r'^#\s*\d+\s+"([^"<]*)"', pp, re.M)})
        self.texts = {}
        self.macros = {}
        for line in run_cpp(cpp + ["-dM", src], cwd).split("\n"):
            m = DEFINE.match(line)
            if m and line not in builtins:
                self.macros[m.group(1)] = line
        self.by = {}
        for it in self.items:
            for n in it.names | {f"tag {t}" for t in it.tags} | it.consts:
                self.by.setdefault(n, []).append(it)

    def macro_file(self, name):
        """The first file of this TU (sorted) holding `#define name`, '' if none (a builtin or command-line macro)."""
        pat = re.compile(rf"^\s*#\s*define\s+{re.escape(name)}\b", re.M)
        for f in self.files:
            if f not in self.texts:
                p = os.path.join(self.cwd, f)
                self.texts[f] = Path(p).read_text(errors="replace") if os.path.isfile(p) else ""
            if pat.search(self.texts[f]):
                return f
        return ""


def ours_of(cpp, cwd, builtins):
    """Names our include/common.h defines (typedefs, tags, enum constants, declarations) and its macros."""
    p = os.path.abspath(".run/x4port/ours.c")
    os.makedirs(os.path.dirname(p), exist_ok=True)
    Path(p).write_text('#include "common.h"\n')
    items = [Item(i, *x) for i, x in enumerate(split_items(run_cpp(cpp + [p], cwd)))]
    typedefs = {}
    names, tags = set(), set()
    for it in items:
        names |= it.names | it.consts
        tags |= it.tags
        if it.kind == "typedef":
            for n in it.names:
                typedefs[n] = " ".join(toks(it.text))
    macros = {DEFINE.match(x).group(1) for x in run_cpp(cpp + ["-dM", p], cwd).split("\n")
              if DEFINE.match(x) and x not in builtins}
    return dict(names=names, tags=tags, typedefs=typedefs, macros=macros)


# ---- rename ----------------------------------------------------------------------------------------------------------

def rename(text, ids, tags):
    """text with tag names (after struct/union/enum) per tags and other identifiers per ids (never after . or ->)."""
    text = TAG.sub(lambda m: f"{m.group(1)} {tags.get(m.group(2), m.group(2))}", text)

    def one(m):
        pre = text[:m.start()].rstrip()
        if pre.endswith((".", "->")) or re.search(r"\b(struct|union|enum)$", pre):
            return m.group(0)
        return ids.get(m.group(0), m.group(0))
    out, last = [], 0
    for m in TOK.finditer(text):
        tk = m.group(0)
        if IDENT.fullmatch(tk) and tk in ids:
            out.append(text[last:m.start()])
            out.append(one(m))
            last = m.end()
    out.append(text[last:])
    return "".join(out)


# ---- port ------------------------------------------------------------------------------------------------------------

class Ctx:
    def __init__(self, clone, objroot, cpp, ours_cpp, root_cwd="."):
        self.clone, self.objroot, self.cpp = clone, objroot, cpp
        b = set(run_cpp(cpp + ["-dM", "/dev/null"], clone).split("\n"))
        self.builtins = b
        ob = set(run_cpp(ours_cpp + ["-dM", "/dev/null"], root_cwd).split("\n"))
        self.ours = ours_of(ours_cpp, root_cwd, ob)
        self.tus, self.addrs, self.elfs = {}, {}, {}
        self.asm_idx = census.asm_index() if os.path.isdir("asm") else {}

    def tu(self, src):
        if src not in self.tus:
            try:
                self.tus[src] = TU(self.cpp, self.clone, src, self.builtins)
            except Skip as e:
                self.tus[src] = e
        if isinstance(self.tus[src], Skip):
            raise self.tus[src]
        return self.tus[src]

    def elf(self, path):
        if path not in self.elfs:
            self.elfs[path] = Elf(path)
        return self.elfs[path]

    def addr(self, prog):
        if prog not in self.addrs:
            self.addrs[prog] = Addrs(prog)
        return self.addrs[prog]


def raw_body(ctx, it, name):
    """The definition's own source text from its file and line, or the preprocessed item text."""
    path = os.path.join(ctx.clone, it.file)
    if os.path.isfile(path):
        lines = Path(path).read_text(errors="replace").split("\n")[it.line - 1:]
        text = "\n".join(lines)
        depth, i, n, seen = 0, 0, len(text), False
        while i < n:
            m = re.compile(r'/\*.*?\*/|//[^\n]*|"(?:\\.|[^"\\\n])*"|\'(?:\\.|[^\'\\\n])*\'', re.S).match(text, i)
            if m:
                i = m.end()
                continue
            depth += {"{": 1, "}": -1}.get(text[i], 0)
            seen = seen or text[i] == "{"
            if seen and depth == 0:
                raw = text[:i + 1]
                head = raw.split("{", 1)[0]
                if re.search(rf"\b{re.escape(name)}\s*\(", head) and \
                        not any(x.lstrip().startswith("#") for x in raw.split("\n")):
                    return raw, "raw"
                break
            i += 1
    return it.text, "pp"


def port(ctx, prog, row, key, src, xf, tamper=None):
    """(draft text, notes) of mmx4 src:xf for X6 corpus row, or raise Skip."""
    obj = os.path.join(ctx.objroot, src + ".o")
    if not os.path.isfile(obj):
        raise Skip(f"no object {obj}")
    fns = {n: (w, m) for n, w, m in x4share.functions(obj)}
    if xf not in fns:
        raise Skip(f"no symbol {xf}")
    if sig.sig_of("X4", xf, *fns[xf])["exact"] != key:
        raise Skip("not exact")
    n = len(fns[xf][0])
    r4 = ctx.elf(obj).refs(xf, n)
    o6 = census.obj_of(row, ctx.asm_idx)
    if not o6 or not os.path.isfile(o6):
        raise Skip(f"no X6 object {o6}")
    r6 = ctx.elf(o6).refs(row["name"], n)
    if tamper:
        r6 = tamper(r6)
    ad = ctx.addr(prog)
    ids, new, bad = {xf: row["name"]}, set(), []
    for i in sorted(r4):
        t4, n4, e4 = r4[i]
        if i not in r6:
            bad.append(f"unaligned {i}")
            continue
        t6, n6, e6 = r6[i]
        a6 = ad.addr(n6)
        if a6 is None:
            bad.append(f"unresolved {n6}")
            continue
        if e4 == e6:
            nm, fresh = n6, False
        else:
            nm, fresh = ad.name(a6 + e6 - e4, t4 == 4)
        if ids.setdefault(n4, nm) != nm:
            bad.append(f"conflict {n4}")
        elif fresh:
            new.add(nm)
    tu = ctx.tu(src)
    fd = next((it for it in tu.items if it.kind == "fdef" and xf in it.names), None)
    if fd is None:
        raise Skip(f"no definition of {xf} in {src}")
    body, how = raw_body(ctx, fd, xf)
    code = strip_comments(body)
    if re.search(r'"', re.sub(r"'(?:\\.|[^'\\])*'", "''", code)):
        raise Skip("string literal")
    if re.search(r"\bstatic\b", code.split("{", 1)[1]):
        raise Skip("function-scope static")
    body = re.sub(r"/\*.*?\*/|//[^\n]*", lambda m: "" if ASMY.search(m.group(0)) else m.group(0), body, flags=re.S)
    head, rest = body.split("{", 1)
    body = re.sub(r"\b(static|inline|__inline__|__inline)\s+", "", head) + "{" + rest
    # closure: macros first (raw body), then items
    want_ids, want_tags = uses(code)
    mac, todo = {}, list(want_ids)
    while todo:
        x = todo.pop()
        if x in tu.macros and x not in mac and x not in ctx.ours["macros"]:
            mac[x] = tu.macros[x]
            i2, t2 = uses(DEFINE.match(mac[x]).group(3))
            todo += list(i2)
            want_ids |= i2
            want_tags |= t2
    chosen, inline, seen = {}, set(), set()
    todo = [x for x in want_ids] + [f"tag {t}" for t in want_tags]
    while todo:
        x = todo.pop()
        if x in seen or x == xf:
            continue
        seen.add(x)
        cands = [it for it in tu.by.get(x, []) if it.idx < fd.idx]  # visible at the definition (else implicit, as mmx4)
        if x.startswith("tag "):
            pick = next((it for it in cands if it.kind in ("tag", "typedef", "decl") and x[4:] in it.tags), None)
        elif x in ctx.ours["typedefs"] and any(it.kind == "typedef" for it in cands):
            continue
        else:
            pick = next((it for it in cands if it.kind in ("typedef", "tag") or x in it.consts), None) or \
                next((it for it in cands if it.kind == "decl" and (it.extern or it.proto)), None) or \
                next((it for it in cands if it.kind == "decl"), None) or \
                next((it for it in cands if it.kind == "fdef"), None)
        if pick is None or pick.idx in chosen:
            continue
        if pick.kind == "fdef" and re.search(r"\binline\b|\b__inline", pick.head):
            inline.add(pick.idx)
            text = pick.text
        elif pick.kind == "fdef":
            text = pick.head + ";"
        else:
            text = pick.text
        chosen[pick.idx] = (pick, text)
        a, b = uses(text)
        todo += list(a) + [f"tag {t}" for t in b]
    # renames: X6 names (relocation map), X4_ types
    tmap, idmap = {}, dict(ids)
    for pick, text in chosen.values():
        for t in pick.tags:
            tmap[t] = f"X4_{t}"
        if pick.kind == "typedef":
            for nm in pick.names:
                if nm not in ctx.ours["typedefs"]:
                    idmap[nm] = f"X4_{nm}"
    for text in [body] + [t for _, t in chosen.values()] + list(mac.values()):
        for m in TAG.finditer(text):
            if m.group(2) not in ctx.ours["tags"]:
                tmap.setdefault(m.group(2), f"X4_{m.group(2)}")
    for c in {c for p, _ in chosen.values() for c in p.consts} & ctx.ours["names"]:
        idmap[c] = f"X4_{c}"
    # types and macros -> include/mmx6/x4.h (blocks keyed by guard); a macro naming a relocated symbol stays here
    hblocks, dmac, ext = [], [], []
    for nm in sorted(mac):
        t = f"#ifndef {nm}\n{rename(mac[nm], idmap, tmap)}\n#endif"
        if uses(DEFINE.match(mac[nm]).group(3))[0] & set(ids):
            dmac.append(t + "\n")
        else:
            hblocks.append(("m " + nm, t, tu.macro_file(nm)))
    order = sorted(chosen.values(), key=lambda x: x[0].idx)
    for pick, text in order:
        if pick.kind in ("typedef", "tag") or (pick.kind == "decl" and pick.tags):
            dec = None
            if pick.kind == "decl":
                text, dec = split_tagged(text)
                g = sorted(pick.tags)
            else:
                g = sorted(pick.names) or sorted(pick.tags) or sorted(pick.consts)
            gname = "X4_D_" + rename(g[0], idmap, tmap).replace("X4_", "")
            hblocks.append(("t " + gname, f"#ifndef {gname}\n#define {gname}\n{rename(text, idmap, tmap)}\n#endif",
                            pick.file))
            if dec:
                ext.append(extern_of(rename(dec, idmap, tmap), pick) + "\n")
        elif pick.kind == "decl" or pick.kind == "fdef" and pick.idx not in inline:
            ext.append(extern_of(rename(text, idmap, tmap), pick) + "\n")
    out = [HEADER.format(pin=PIN, src=src, func=xf, key=key[:12]), '#include "common.h"\n']
    out += (['#include "mmx6/x4.h"\n'] if hblocks else []) + dmac + ext
    for pick, text in order:
        if pick.idx in inline:
            g = "X4_D_" + sorted(pick.names)[0]
            out.append(f"#ifndef {g}\n#define {g}\n{rename(text, idmap, tmap)}\n#endif\n")
    out.append("\n" + rename(body, idmap, tmap).rstrip() + "\n")
    draft = "\n".join(x.rstrip("\n") for x in out) + "\n"
    ok, why, _ = verbatim.check(draft)
    if not ok:
        raise Skip(f"verbatim {why}")
    notes = [f"x4 port {src}:{xf} ({how})"] + (["new " + " ".join(sorted(new))] if new else []) + bad
    return draft, "; ".join(notes), hblocks


def split_tagged(text):
    """(`struct T {...};`, the declaration with the body removed) of a declaration that defines tag T."""
    m = TAGDEF.search(text)
    d, i = 0, m.end() - 1
    while True:
        d += {"{": 1, "}": -1}.get(text[i], 0)
        if d == 0:
            break
        i += 1
    return text[m.start():i + 1] + ";", text[:m.start()] + f"{m.group(1)} {m.group(2)}" + text[i + 1:]


def x4h(blocks):
    """include/mmx6/x4.h text: attribution, guard, common.h, psyq_api.h, macros (sorted), then types (first-seen
    order). blocks: {guard: (text, mmx4 file)}; a block from PSYQ is dropped (psyq_api.h re-expresses it)."""
    blocks = {g: v for g, v in blocks.items() if not v[1].startswith(PSYQ)}
    srcs = ", ".join(sorted({f for _, f in blocks.values() if f})) or "-"
    out = [X4H_HEADER.format(pin=PIN, srcs=srcs),
           "/* Generated by tools/mmx6/x4port.py --wave (never hand-edited): the X4_ types and mmx4 macros the W-x4 "
           "drafts use. */", "#ifndef MMX6_X4_H", "#define MMX6_X4_H", "", '#include "common.h"',
           '#include "mmx6/psyq_api.h"', ""]
    out += [t for g, (t, _) in sorted(blocks.items()) if g.startswith("m ")]
    out += [t for g, (t, _) in blocks.items() if g.startswith("t ")]
    return "\n".join(out + ["", "#endif /* MMX6_X4_H */", ""])


def extern_of(text, pick):
    """A declaration: static/inline dropped; a definition becomes `extern`, its initialisers dropped."""
    text = re.sub(r"\b(static|inline|__inline__|__inline)\s+", "", text).strip()
    if pick.kind == "fdef" or pick.proto:
        return text if text.endswith(";") else text + ";"
    parts = []
    for p in top_split_text(text.rstrip(";")):
        parts.append(top_split_text(p, "=")[0].rstrip())
    text = ", ".join(parts) + ";"
    return text if text.startswith("extern") else "extern " + text


def top_split_text(s, sep=","):
    out, cur, d = [], "", 0
    for c in s:
        if c in "([{":
            d += 1
        elif c in ")]}":
            d -= 1
        if c == sep and d == 0:
            out.append(cur)
            cur = ""
        else:
            cur += c
    return out + [cur]


# ---- the lane --------------------------------------------------------------------------------------------------------

def mmx4_ctx():
    head = subprocess.run(["git", "-C", x4share.CLONE, "rev-parse", "--short", "HEAD"], capture_output=True,
                          text=True).stdout.strip()
    if head != PIN:
        sys.exit(f"x4port: {x4share.CLONE} at {head or 'absent'}, pinned {PIN} (run x4share.py --partners first)")
    inc = os.path.abspath(f"{x4share.SCR}/inc")
    os.makedirs(inc, exist_ok=True)
    Path(f"{inc}/common.h").write_text(x4share.OVERRIDE)
    cpp = x4share.CPP + [f"-I{inc}"] + x4share.CPP_TAIL
    ours = ["cpp", "-undef", "-D__GNUC__=2", f"-I{os.path.abspath('include')}"] + x4share.CPP_TAIL[2:]
    return Ctx(x4share.CLONE, os.path.abspath(f"{x4share.SCR}/{TRIPLE}/obj"), cpp, ours)


def write_pack(root, wave, row, prog, draft, notes):
    d = os.path.join(root, wave, f"{prog}_{row['name']}")
    shutil.rmtree(d, ignore_errors=True)
    os.makedirs(d)
    pv = f"{prog}:{row['vram']}"
    with open(os.path.join(d, "pack.json"), "w") as f:
        json.dump(dict(pv=pv, prog=prog, func=row["name"], tu=row["tu"], words=row["words"]), f)
    Path(os.path.join(d, "draft.c")).write_text(draft)
    with open(os.path.join(d, "verdict.json"), "w") as f:
        json.dump(dict(pv=pv, status="draft", score="-", lever="-", notes=notes[:400]), f)
    return d


def lane(wave, root, pvs, limit, only_h=False):
    for p in (PARTNERS, FUNCS, CLASSES):
        if not os.path.isfile(p):
            sys.exit(f"x4port: {p} missing")
    funcs = {(r["prog"], r["vram"]): r for r in jl(FUNCS)}
    rows = [x.rstrip("\n").split("\t") for x in open(PARTNERS) if x.strip()]
    partners, key_of = {}, {}
    for p, v, _, _, k, src, fn, _, _ in rows:
        partners.setdefault((p, v), []).append((src, fn))
        key_of[(p, v)] = k
    opn = sorted((pv for pv in key_of if funcs.get(pv, {}).get("state") in OPEN), key=lambda x: (x[0], int(x[1], 16)))
    members = {}
    for c in jl(CLASSES):
        if c["kind"] == "dup":
            members[c["key"]] = [tuple(m) for m in c["members"]]
    gated = {t[0] for _, t in propagate.registry_rows(REGISTRY) if t[4] == "gated"}
    want = {tuple(x.rsplit(":", 1)) for x in pvs}
    reps, lines, nounit = [], [], 0
    by_key, units = {}, {}
    for pv in opn:
        by_key.setdefault(key_of[pv], []).append(pv)
    for p in sorted({p for p, _ in opn}):
        units[p] = {t[1] for t in (x.split() for x in open(C_UNITS) if not x.startswith("#")) if len(t) >= 2
                    and t[0] == p}
    for k in sorted(by_key, key=lambda k: (by_key[k][0][0], int(by_key[k][0][1], 16))):
        ms = by_key[k]
        if want and not want & set(ms):
            continue
        cand = sorted(want & set(ms), key=lambda x: (x[0], int(x[1], 16))) if want else ms
        # representative: the lowest (prog, vram) member bank can take (include_asm in a c unit), else none
        bankable = [m for m in cand if funcs[m]["state"] == "include_asm" and funcs[m]["tu"] in units[m[0]]]
        rep = bankable[0] if bankable else cand[0]
        banked = [m for m in members.get(k, []) if funcs.get(m, {}).get("state") in ("c", "c-empty")]
        if k in gated:
            lines.append((rep, "class gated"))
        elif banked:
            lines.append((rep, f"class banked {banked[0][0]}:{banked[0][1]}"))
        elif not bankable:
            lines.append((rep, "skipped no-c-unit"))
            nounit += 1
        else:
            reps.append(rep)
    if limit and len(reps) > limit:
        reps = [reps[i * len(reps) // limit] for i in range(limit)]
    if only_h:  # the wave's own packs, open or banked since
        reps = sorted({tuple(json.load(open(f))["pv"].rsplit(":", 1)) for f in Path(root, wave).glob("*/pack.json")},
                      key=lambda x: (x[0], int(x[1], 16)))
        lines = []
    ctx = mmx4_ctx()
    k, blocks = 0, {}
    for rep in reps:
        row, why, done = funcs[rep], [], None
        for src, fn in sorted(partners[rep]):
            try:
                draft, notes, hb = port(ctx, rep[0], row, key_of[rep], src, fn)
                clash = sorted(g[2:] for g, t, _ in hb if blocks.get(g, (t,))[0] != t)
                if clash:
                    raise Skip("x4.h conflict " + " ".join(clash))
            except Skip as e:
                why.append(str(e))
                continue
            for g, t, f in hb:
                f = os.path.normpath(f) if f else ""
                blocks.setdefault(g, (t, f if f and not os.path.isabs(f) and not f.startswith("..") else ""))
            if not only_h:
                write_pack(root, wave, row, rep[0], draft, notes)
            done = f"{src}:{fn}"
            break
        lines.append((rep, f"drafted {done}" if done else "skipped " + "; ".join(dict.fromkeys(why))))
        k += bool(done)
    text = x4h(blocks)
    ok, why, _ = verbatim.check(text)
    if not ok:
        sys.exit(f"x4port: {X4H} refused by verbatim ({why})")
    Path(X4H).write_text(text)
    for rep, what in sorted(lines, key=lambda x: (x[0][0], int(x[0][1], 16))):
        print(f"X4PORT {rep[0]}:{rep[1]} {what}")
    psyq = sorted(g[2:] for g, (_, f) in blocks.items() if f.startswith(PSYQ))
    print(f"X4PORT psy-q blocks not emitted ({len(psyq)}): {' '.join(psyq) or '-'}")
    if only_h:
        print(f"X4PORT {wave} x4h {k} packs; {X4H} {len(blocks) - len(psyq)} blocks")
        return 0
    print(f"X4PORT {wave} {k} packs of {len(opn)} open; {nounit} classes skipped no-c-unit; {X4H} "
          f"{len(blocks) - len(psyq)} blocks")
    return 0


# ---- credits ---------------------------------------------------------------------------------------------------------

THIRD = "THIRD_PARTY.md"
CREDITS = ("<!-- x4port credits -->", "<!-- /x4port credits -->")
TABLE = ("| Component | Upstream | Commit / version | License | Paths here | Basis (proof it is shared) |\n"
         "|---|---|---|---|---|---|\n")
ADAPTED = re.compile(r"/\* Adapted from sozud/mmx4 @(\w+) (.+?), AGPL-3\.0; proven shared with X6 by "
                     r"(?:exact signature (\w+)|the exact signature each including draft names)")


def credits():
    rows = []
    for f in [X4H] + sorted(str(x) for x in Path("src/shared").rglob("*.c")):
        if not os.path.isfile(f):
            continue
        head = Path(f).read_text().split("*/", 1)[0]  # the leading comment, reflow-proof (clang-format)
        m = ADAPTED.match(" ".join(head.split()))
        if not m:
            continue
        pin, what, key = m.groups()
        basis = f"exact signature `{key}`, `{what}`" if key else f"types and macros of `{what}` used by the rows below"
        rows.append(f"| mmx4 port | [sozud/mmx4](https://github.com/sozud/mmx4) | `{pin}` | AGPL-3.0 | `{f}` | {basis} |")
    block = CREDITS[0] + "\n" + TABLE + "".join(r + "\n" for r in rows) + CREDITS[1]
    text = Path(THIRD).read_text()
    if CREDITS[0] in text:
        a, b = text.index(CREDITS[0]), text.index(CREDITS[1]) + len(CREDITS[1])
    elif TABLE + "\n*(none yet)*" in text:
        a = text.index(TABLE + "\n*(none yet)*")
        b = a + len(TABLE + "\n*(none yet)*")
    else:
        sys.exit(f"x4port: {THIRD} has neither the credits block nor the empty table")
    Path(THIRD).write_text(text[:a] + block + text[b:])
    print(f"X4PORT CREDITS {len(rows)} rows")
    return 0


# ---- self-test -------------------------------------------------------------------------------------------------------

def self_test():
    import cards  # noqa: E402  (top_decls, body_of)
    fails = []
    shutil.rmtree(SELFTEST, ignore_errors=True)
    clone, objroot = os.path.abspath(f"{SELFTEST}/clone"), os.path.abspath(f"{SELFTEST}/obj")
    src = "src/main/120A0.c"
    text = Path(f"src/{SELF_PROG}/{SELF_TU}.c").read_text()
    body = cards.body_of(text, SELF_FUNC)
    fake = '#include "common.h"\n' + "\n".join(cards.top_decls(text)) + "\n\n" + body
    fake = re.sub(r"\bfunc_8", "fanc_8", re.sub(r"\bD_8", "Q_8", fake))
    os.makedirs(os.path.dirname(f"{clone}/{src}"))
    Path(f"{clone}/{src}").write_text(fake)
    obj = f"{objroot}/{src}.o"
    os.makedirs(os.path.dirname(obj))
    b = bytearray(Path(f"build/src/{SELF_PROG}/{SELF_TU}.c.o").read_bytes())
    e = Elf(f"build/src/{SELF_PROG}/{SELF_TU}.c.o")
    for i, s in enumerate(e.secs):
        if s[1] == 3 and i != struct.unpack_from("<H", b, 0x32)[0]:  # the symbol string table
            seg = bytes(b[s[4]:s[4] + s[5]]).replace(b"\0D_8", b"\0Q_8").replace(b"\0func_8", b"\0fanc_8")
            b[s[4]:s[4] + s[5]] = seg
    Path(obj).write_bytes(b)
    x6 = next(s for s in x4share.load_x6() if (s["prog"], s["vram"]) == (SELF_PROG, SELF_VRAM))
    row = next(r for r in jl(FUNCS) if (r["prog"], r["vram"]) == (SELF_PROG, SELF_VRAM))
    inc = os.path.abspath("include")
    cpp = ["cpp", "-undef", "-D__GNUC__=2", f"-I{inc}"] + x4share.CPP_TAIL[2:]
    ctx = Ctx(clone, objroot, cpp, cpp)
    xf = "fanc_" + SELF_FUNC[5:]
    try:
        draft, notes, _ = port(ctx, SELF_PROG, row, x6["exact"], src, xf)
    except Skip as ex:
        draft, notes = None, str(ex)
    got = draft.split("\n\n")[-1] if draft else ""
    Path(f"{SELFTEST}/draft.c").write_text(draft or "")
    ok1 = draft is not None and got.strip() == body.strip() and "Q_8" not in draft.split("\n", 1)[1] and "fanc_8" not in draft.split("\n", 1)[1]
    print(f"X4PORT self positive: names mapped back {ok1} ({notes})")
    if ok1:
        d = write_pack(SELFTEST, "W-x4", row, SELF_PROG, draft, notes)
        p = subprocess.run([sys.executable, "tools/mmx6/cards.py", "--probe-pack", d], capture_output=True, text=True)
        line = next((x for x in p.stdout.splitlines() if x.startswith("PACK ")), "no PACK line")
        print(f"X4PORT self probe: {line}")
        ok1 = " match " in line
    if not ok1:
        fails.append("positive")
    # control: one unmasked bit of the fake object's function flipped
    w, m = {n: (w, m) for n, w, m in x4share.functions(obj)}[xf]
    k = next(i for i, x in enumerate(m) if x == 0)
    s = e.defined(SELF_FUNC)
    off = e.secs[s[4]][4] + s[1] + 4 * k
    b2 = bytearray(Path(obj).read_bytes())
    b2[off] ^= 1
    flip = f"{objroot}/flip/{src}.o"
    os.makedirs(os.path.dirname(flip))
    Path(flip).write_bytes(b2)
    ctx.objroot = f"{objroot}/flip"
    try:
        port(ctx, SELF_PROG, row, x6["exact"], src, xf)
        why = "ported"
    except Skip as ex:
        why = str(ex)
    print(f"X4PORT self control: word {k} bit 0 flipped -> {why}")
    if why != "not exact":
        fails.append("flip")
    ctx.objroot = objroot

    def shift(r6):
        i = next(i for i in sorted(r6) if r6[i][0] == 6)
        return {**r6, i: (r6[i][0], r6[i][1], r6[i][2] + 4)}
    try:
        d2, _, _ = port(ctx, SELF_PROG, row, x6["exact"], src, xf, tamper=shift)
        moved = d2.split("\n\n")[-1].strip() != body.strip()
    except Skip as ex:
        moved = False
        print(f"X4PORT self control: shift skipped {ex}")
    print(f"X4PORT self control: X6 addend +4 -> other symbol {moved}")
    if not moved:
        fails.append("shift")
    # control: a psy-q-origin block never reaches x4.h, nor its file the attribution
    t = x4h({"t X4_D_X4_RECT": ("#ifndef X4_D_X4_RECT\n#define X4_D_X4_RECT\nPSYQ_PLANT\n#endif", PSYQ + "LIBGPU.H"),
             "m FOO": ("#ifndef FOO\n#define FOO 1\n#endif", "include/common.h")})
    clean = "PSYQ_PLANT" not in t and PSYQ not in t and "#define FOO 1" in t and '#include "mmx6/psyq_api.h"' in t
    print(f"X4PORT self control: psy-q block kept out of x4.h {clean}")
    if not clean:
        fails.append("psyq")
    if fails:
        print(f"X4PORT CONTROL FAIL {' '.join(fails)}")
        return 1
    shutil.rmtree(SELFTEST, ignore_errors=True)
    print("X4PORT CONTROL OK")
    return 0


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("--wave", help="lane wave id (W-x4)")
    ap.add_argument("--root", default="waves")
    ap.add_argument("--pv", action="append", default=[], help="port only the class of this prog:0xVRAM (repeatable)")
    ap.add_argument("--limit", type=int, default=0, help="a deterministic stride sample of K representatives")
    ap.add_argument("--x4h", action="store_true", help="with --wave: rewrite include/mmx6/x4.h only, no packs")
    ap.add_argument("--credits", action="store_true", help=f"rewrite the mmx4 credits table of {THIRD}")
    ap.add_argument("--self-test", action="store_true")
    a = ap.parse_args()
    if a.self_test:
        sys.exit(self_test())
    if a.credits:
        sys.exit(credits())
    if not (a.wave and re.fullmatch(r"W-[a-z0-9]+", a.wave)):
        ap.error("--wave W-<lane> required")
    sys.exit(lane(a.wave, a.root, a.pv, a.limit, a.x4h))


if __name__ == "__main__":
    main()
