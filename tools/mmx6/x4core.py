#!/usr/bin/env python3
"""x4core.py -- the X4 core shared by the X5 and X6 decompilations: sozud/mmx4 as a source of partners and names (stdlib).

The same bytes live in both repositories (mmx6 tools/mmx6/x4core.py, mmx5 tools/sig/x4core.py; `parity` checks it).
Nothing here knows a game: the pin comes from the repository's config/refs.toml, and everything about the game (the
compiler triple and its flags, the clone directory, the game's functions, table and doc paths, the game objects) comes
from the repository's own x4adapter.py.

Library (called by the adapter and its callers):
  pin(root), short(pin), ensure_clone(dir, ref)   the [[ref]] name = "mmx4" commit of config/refs.toml; an exact-commit
      shallow fetch into dir; a clone at another commit is refused (never moved in place).
  sources(clone), compile_one(...), compile_all(...)   mmx4's US C files (the `c` subsegments of its splat yaml), each
      compiled alone with INCLUDE_ASM / INCLUDE_RODATA stubbed: host cpp (mmx4 build.py's defines) -> the adapter's
      cc1 -> the adapter's maspsx -> the adapter's assembler. Flags and tool paths are the adapter's, never the core's.
  Elf, functions(obj), key(words, mask)   ELF32 LE relocatable reader; [(name, words, mask)] per STT_FUNC, the mask
      from the object's own relocation sections (MASKS); key = sha1 of the little-endian words with the masked fields
      cleared. confirmed(words, cands): the mask-less game side, keyed under each candidate's own mmx4 mask.
  partner_map(objroot), write_partners(path, game, by_key)   key -> {(mmx4 path, function)}; the partner table, one row
      per game function with a partner, tab-separated, no header (SCHEMA["partners"]).
  refusal, exact_row, build, pick, pair, tally, merge, widen(ad), who, doc(ad)   the names table (SCHEMA["names"]):
      admission (a real name, one partner, >= MIN_WORDS words), tiers gate|bytes|slot, scope engine|object, widening by
      same-name classes and relocation-slot votes. An adapter without game objects (ad.slots() is None) gets the
      same-name rows and the line `<TAG> slot lane unavailable`.
  The adapter contract (a module or object `ad`): ROOT, TAG, GAME, CLONE, OBJROOT, PARTNERS, NAMES, DOC, SCRATCH,
      WIDEN_HINT, DOC_TEXT {title, tool, note, lookup, tail}, widen_inputs() -> paths, banked() -> (row -> bool),
      corpus() -> {(unit, vram): {"words", "name", ...}}, slots() -> None | object with votes(row, x4obj, x4func, voter)
      and x6sym(unit, address, is_text).

Commands:
  x4core.py xref --a <X6 partners.tsv> --b <X5 partners.tsv> [--out F]
      -> joins the two partner tables on the mmx4 `path:function` (each table's first partner); refuses when the two
         repositories' pins differ. Tab-separated, no header (SCHEMA["xref"]):
             mmx4 path, mmx4 function, X5 unit, vram, name, state, X6 unit, vram, name, state, single|multi, key =|!=
         single = both sides have exactly one partner; key compares the two key columns (different compiler flags:
         `!=` is expected). A row is a lead "same source function", never a byte claim.
         Last line (stderr when printing rows to stdout): `x4core: xref <rows> rows, <n> mmx4 functions, pin <pin7>`
  x4core.py parity --other <the sibling's x4core.py>
      -> core sha256, pin and SCHEMA of this copy against the sibling's; `x4core: parity OK`, else rc 1 and
         `x4core: parity FAIL <core|pin|schema>...`
  x4core.py ghidra-aliases --names <names.tsv> [--unit U]
      -> one line per alias, `<unit> TAB <vram> TAB x4: <alias> [<tier>/<scope>] sozud/mmx4@<pin7> <path>:<function>`
         (a slot lead ends with its symbol). A plate-comment line, never a rename; the adapter writes the repository's
         record shape and appends to an existing plate comment.
  x4core.py --selftest
      -> synthetic ELF objects built in Python (no compiler, no clone, no game data) under .run/x4core-selftest/:
         extents and masks, the key and its one-bit control, the mask-less confirmation, partner table, admission,
         same-name, slot votes with a disagreeing control, pin parsing, xref with a differing-pin refusal, the plate
         line, parity with itself. Ends `x4core: control OK`, rc 1 and `x4core: control FAIL <case>...` on any miss.

No game-derived byte leaves .run/: tables hold names, addresses, keys and mmx4 paths only.
"""
import argparse
import hashlib
import importlib.util
import os
import re
import shutil
import struct
import subprocess
import sys
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

REPO = "https://github.com/sozud/mmx4"
REF_NAME = "mmx4"
REFS = "config/refs.toml"
YAML = "config/SLUS_005.61.splat.yaml"
# mmx4 build.py: host `cpp` (its psy-q headers reach the host's <sys/types.h>) with cpp_flags (VERSION=us), minus -v.
CPP = ["cpp", "-undef", "-D__GNUC__=2", "-DVERSION_US=1", "-D__OPTIMIZE__"]
CPP_TAIL = ["-I./src/snd", "-I./include", "-lang-c", "-Dmips", "-D__mips__", "-D__mips", "-Dpsx", "-D__psx__", "-D__psx",
            "-D__EXTENSIONS__", "-D_MIPSEL", "-D__CHAR_UNSIGNED__", "-D_LANGUAGE_C", "-DLANGUAGE_C"]
AS = ["mipsel-linux-gnu-as", "-EL", "-march=r3000", "-mtune=r3000", "-mabi=32", "-no-pad-sections", "-G0",
      "-I./src/main"]
OVERRIDE = '/* x4share: INCLUDE_ASM / INCLUDE_RODATA -> nothing (mmx4 common.h SKIP_ASM branch) */\n' \
           '#define SKIP_ASM 1\n#include_next "common.h"\n'
C_SEG = re.compile(r"^\s*-\s*\[\s*0x([0-9A-Fa-f]+)\s*,\s*c\s*(?:,\s*([^\],]+?))?\s*\]")
MASKS = {4: 0x03FFFFFF, 5: 0xFFFF, 6: 0xFFFF, 7: 0xFFFF}  # R_MIPS_26, HI16, LO16, GPREL16
NOISE = re.compile(r"gcc2_compiled\.|__gnu_compiled_\w+")
SCHEMA = {
    "partners": ("unit", "vram", "name", "words", "key", "mmx4 path", "mmx4 function", "partners", "state"),
    "names": ("unit", "vram", "kind", "name", "alias", "tier", "scope", "votes", "basis"),
    "xref": ("mmx4 path", "mmx4 function", "x5 unit", "x5 vram", "x5 name", "x5 state", "x6 unit", "x6 vram",
             "x6 name", "x6 state", "single|multi", "key"),
}

DRAFT = re.compile(r"^func_8[0-9A-Fa-f]{7}$")
OBJECT_DIRS = frozenset("mains items effects layers misc weapons visuals quads".split())
MIN_WORDS = 8
MIN_VOTERS = 2
WIDENED = re.compile(r" (?:same-name|slot) \d+$")  # the basis suffix of an exact row only widen can compute
X4DRAFT = re.compile(r"^[A-Za-z]{0,6}_?8[0-9A-Fa-f]{7}$")  # an address-spelled mmx4 symbol: votes, never names
RAM = (0x80010000, 0x80200000)
SELFTEST = Path(__file__).resolve().parents[2] / ".run/x4core-selftest"


class Skip(Exception):
    pass


def die(msg):
    sys.exit(f"x4core: {msg}")


# ---- the pin and the clone -------------------------------------------------------------------------------------------

def root_of(path):
    """The repository holding path: the nearest directory upward with config/refs.toml."""
    p = Path(path).resolve()
    for d in [p] + list(p.parents):
        if (d / REFS).is_file():
            return d
    die(f"no {REFS} above {path}")


def pin(root=None):
    """The 40-hex commit of the [[ref]] name = "mmx4" row of <root>/config/refs.toml."""
    import tomllib
    root = Path(root) if root else root_of(__file__)
    with open(root / REFS, "rb") as f:
        rows = [r for r in tomllib.load(f).get("ref", []) if r.get("name") == REF_NAME]
    if len(rows) != 1 or not re.fullmatch(r"[0-9a-f]{40}", rows[0].get("ref", "")):
        die(f"{root / REFS}: one [[ref]] name = \"{REF_NAME}\" with a 40-hex ref expected")
    return rows[0]["ref"]


def short(ref):
    return ref[:7]


def clone_head(d):
    """HEAD of the clone at d, '' when d is not a clone of its own."""
    if not os.path.exists(os.path.join(d, ".git")):
        return ""
    return subprocess.run(["git", "-C", str(d), "rev-parse", "-q", "--verify", "HEAD"], capture_output=True,
                          text=True).stdout.strip()


def ensure_clone(d, ref, url=REPO):
    """d holds url at exactly ref (shallow fetch of that commit when absent); a clone at another commit is refused."""
    head = clone_head(d)
    if head == ref:
        return ref
    if head:
        die(f"{d} at {short(head)}, pinned {short(ref)} (remove {d} to fetch the pin)")
    for cmd in (["git", "init", "-q", str(d)], ["git", "-C", str(d), "fetch", "-q", "--depth", "1", url, ref],
                ["git", "-C", str(d), "checkout", "-q", "FETCH_HEAD"]):
        if subprocess.run(cmd).returncode != 0:
            die(f"fetch {url} {ref} into {d} failed")
    return ref


# ---- mmx4's C files, compiled alone ----------------------------------------------------------------------------------

def sources(clone):
    """src/main/<name>.c of each `c` subsegment (unnamed -> hex offset, splat's default name)."""
    out = []
    for line in open(f"{clone}/{YAML}"):
        m = C_SEG.match(line)
        if m:
            src = f"src/main/{(m.group(2) or format(int(m.group(1), 16), 'X')).strip()}.c"
            if os.path.isfile(f"{clone}/{src}") and src not in out:
                out.append(src)
    return out


def compile_one(clone, src, tools, inc, objdir, logdir):
    """Object path, or None (stage + stderr tail in the per-file log). tools: {"cc1": [cmd...], "maspsx": [cmd...]}
    and optionally "cpp" (default CPP), "as" (default AS): the adapter's toolchain and flags."""
    obj = os.path.abspath(f"{objdir}/{src}.o")
    log = f"{logdir}/{src}.log"
    os.makedirs(os.path.dirname(obj), exist_ok=True)
    os.makedirs(os.path.dirname(log), exist_ok=True)
    stages = [("cpp", tools.get("cpp", CPP) + [f"-I{inc}"] + CPP_TAIL + [src]), ("cc1", tools["cc1"]),
              ("maspsx", tools["maspsx"]), ("as", tools.get("as", AS) + ["-o", obj, "--"])]
    data = b""
    for i, (stage, cmd) in enumerate(stages):
        p = subprocess.run(cmd, input=data if i else None, capture_output=True, cwd=clone)
        if p.returncode != 0:
            tail = p.stderr.decode(errors="replace").splitlines()[-20:]
            Path(log).write_text(f"FAIL {stage} rc {p.returncode}\n" + "\n".join(tail) + "\n")
            if os.path.exists(obj):
                os.remove(obj)
            return None
        data = p.stdout
    Path(log).write_text("OK\n")
    return obj


def compile_all(clone, tools, inc, objdir, logdir, jobs=None):
    """(sources, objects that compiled): every source through compile_one, the override common.h written first."""
    inc = os.path.abspath(inc)
    os.makedirs(inc, exist_ok=True)
    Path(f"{inc}/common.h").write_text(OVERRIDE)
    srcs = sources(clone)
    with ThreadPoolExecutor(jobs or os.cpu_count() or 4) as ex:
        objs = [o for o in ex.map(lambda s: compile_one(clone, s, tools, inc, objdir, logdir), srcs) if o]
    return srcs, objs


# ---- ELF: functions, relocation masks, relocations as (symbol, offset into it) per word ------------------------------

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


def masks(e):
    """{(section index, offset): field mask} of the relocation sites of Elf e (types in MASKS)."""
    out = {}
    for sh, rels in e.rels.items():
        for off, info in rels:
            out[(sh, off)] = out.get((sh, off), 0) | MASKS.get(info & 0xFF, 0)
    return out


def functions(obj):
    """[(name, words, mask)] per STT_FUNC defined in obj (a path or an Elf); extent st_size, else symbol order."""
    e = obj if isinstance(obj, Elf) else Elf(obj)
    secs = e.secs
    syms = [s for s in e.syms if 0 < s[4] < len(secs)]
    mk = masks(e)
    out = []
    for name, val, size, info, shndx in syms:
        if info & 0xF != 2 or secs[shndx][1] != 1:
            continue
        if size == 0:
            later = [x[1] for x in syms if x[4] == shndx and x[1] > val and ((x[3] & 0xF) == 2 or (x[3] >> 4) != 0)]
            size = (min(later) if later else secs[shndx][5]) - val
        n = size // 4
        if n == 0:
            continue
        out.append((name, list(struct.unpack_from(f"<{n}I", e.b, secs[shndx][4] + val)),
                    [mk.get((shndx, val + 4 * i), 0) for i in range(n)]))
    return out


def key(words, mask):
    return hashlib.sha1(struct.pack(f"<{len(words)}I", *[w & ~m & 0xFFFFFFFF for w, m in zip(words, mask)])).hexdigest()


def confirmed(words, cands):
    """The keys of the candidates a mask-less game function equals: cands [(mmx4 words, mmx4 mask)], the game words
    keyed under each candidate's own relocation mask (the prefilter that chose cands is the adapter's)."""
    return {key(w, m) for w, m in cands if len(w) == len(words) and key(words, m) == key(w, m)}


# ---- the partner table -----------------------------------------------------------------------------------------------

def partner_map(objroot, objs=None):
    """(key -> {(mmx4 path, function)}, symbol -> {mmx4 path defining it}) over the mmx4 objects under objroot
    (objs: only these), every partner kept."""
    by_key, defs = {}, {}
    base = os.path.abspath(objroot)
    for o in sorted(os.path.abspath(x) for x in (objs if objs is not None else Path(objroot).rglob("*.o"))):
        src = os.path.relpath(o, base)[:-2]
        e = Elf(o)
        for name, w, m in functions(e):
            by_key.setdefault(key(w, m), set()).add((src, name))
        for name, _, _, info, sh in e.syms:
            if name and name[0] not in ".$" and info & 0xF in (0, 1, 2) and (0 < sh < len(e.secs) or sh == 0xFFF2):
                defs.setdefault(name, set()).add(src)
    return by_key, defs


def write_partners(path, game, by_key):
    """game: (unit, vram int, name, words, key, state) per game function. Writes one row per function with a partner
    (the first by (path, function) + the partner count), sorted (unit, vram); returns the rows."""
    out = []
    for unit, vram, name, words, k, state in game:
        ps = sorted(by_key.get(k, ()))
        if ps:
            out.append((unit, vram, name, words, k, ps[0][0], ps[0][1], len(ps), state))
    out.sort(key=lambda x: (x[0], x[1]))
    os.makedirs(os.path.dirname(os.path.abspath(path)), exist_ok=True)
    with open(path, "w", newline="\n") as f:
        for p, v, fn, w, k, src, name, n, st in out:
            f.write(f"{p}\t0x{v:08X}\t{fn}\t{w}\t{k}\t{src}\t{name}\t{n}\t{st}\n")
    return out


def partner_cols(partners, tag="x4core"):
    out = []
    for n, line in enumerate(Path(partners).read_text().splitlines(), 1):
        if not line:
            continue
        col = line.split("\t")
        if len(col) != len(SCHEMA["partners"]):
            sys.exit(f"{tag.lower()}: {partners}:{n}: {len(col)} columns, {len(SCHEMA['partners'])} expected")
        out.append(col)
    return out


# ---- the names table: admission, tiers -------------------------------------------------------------------------------

def refusal(x4name, partners, words):
    """'' when the row is admitted, else the reason."""
    if DRAFT.match(x4name):
        return "draft-name"
    if partners != 1:
        return f"partners {partners}"
    if words < MIN_WORDS:
        return f"words {words}"
    return ""


def scope_of(x4src):
    return "object" if OBJECT_DIRS & set(x4src.split("/")[:-1]) else "engine"


def exact_row(col, x4src, x4name, suffix, votes, banked, pin7):
    """The names row of partner-table row col under the mmx4 partner x4src:x4name; banked(col) -> tier gate."""
    prog, vram, x6name, _, k = col[:5]
    basis = f"x4 exact {k.lower()[:12]} sozud/mmx4@{pin7} {x4src}:{x4name}{suffix}"
    return (prog, vram, "func", x6name, x4name, "gate" if banked(col) else "bytes", scope_of(x4src), votes, basis)


def order(r):
    return (r[0], int(r[1], 16), r[2])


def rows_of(partners, banked, pin7, tag="x4core"):
    out = []
    for col in partner_cols(partners, tag):
        if refusal(col[6], int(col[7]), int(col[3])):
            continue
        out.append(exact_row(col, col[5], col[6], "", "-", banked, pin7))
    out.sort(key=order)
    return out


def count_line(rows, tag):
    def n(i, v):
        return sum(1 for r in rows if r[i] == v)
    return (f"{tag} {len(rows)} rows; gate {n(5, 'gate')} bytes {n(5, 'bytes')} slot {n(5, 'slot')}; "
            f"engine {n(6, 'engine')} object {n(6, 'object')}; func {n(2, 'func')} data {n(2, 'data')}")


def write_names(names, rows):
    with open(names, "w", newline="\n") as f:
        f.write("".join("\t".join(r) + "\n" for r in rows))


def widened(r):
    return r[5] == "slot" or bool(WIDENED.search(r[8]))


def load(names, tag="x4core"):
    if not os.path.isfile(names):
        sys.exit(f"{tag.lower()}: {names} missing (run --build)")
    return [tuple(x.split("\t")) for x in Path(names).read_text().splitlines() if x]


def build(partners, names, banked, pin7, tag):
    rows = rows_of(partners, banked, pin7, tag)
    have = {(r[0], r[1]) for r in rows}
    # the rows only widen can compute are carried forward verbatim
    carried = [r for r in (load(names, tag) if os.path.isfile(names) else []) if widened(r) and (r[0], r[1]) not in have]
    rows = sorted(rows + carried, key=order)
    write_names(names, rows)
    print(f"{tag} carried {len(carried)} widened rows")
    print(count_line(rows, tag))
    return rows


# ---- widening: 2a full partner list, 2b relocation-slot votes --------------------------------------------------------

def pick(ps):
    """(src, name, basis suffix) of a sorted partner list whose members all carry one name, else None (2a)."""
    if not ps or len({n for _, n in ps}) != 1:
        return None
    return ps[0][0], ps[0][1], "" if len(ps) == 1 else f" same-name {len(ps)}"


def pair(r4, r6, addr_of):
    """[(game address of the X4 symbol's base, jump slot, X4 symbol)] of the word-aligned relocation pairs of one
    anchor (r4, r6: Elf.refs of the X4 and the game function)."""
    out = []
    for i in sorted(r4):
        t4, n4, e4 = r4[i]
        if i not in r6 or n4.startswith("."):  # unaligned; a section-relative X4 reference has no name
            continue
        t6, n6, e6 = r6[i]
        a6 = addr_of(n6)
        if a6 is None or (t4 == 4) != (t6 == 4):
            continue
        a = (a6 + e6 - e4) & 0xFFFFFFFF
        if RAM[0] <= a < RAM[1]:
            out.append((a, t4 == 4, n4))
    return out


def tally(votes):
    """votes: (prog, address, jump slot, X4 symbol, voter). -> ({(prog, address): (symbol, voters, jump)}, conflicts):
    an address is admitted when one symbol is voted for it, by >= MIN_VOTERS voters, the symbol is not
    address-spelled and it is voted for no other address of the program."""
    at, jumps, where = {}, set(), {}
    for prog, a, jump, sym, voter in votes:
        at.setdefault((prog, a), {}).setdefault(sym, set()).add(voter)
        if jump:
            jumps.add((prog, a))
        if not X4DRAFT.match(sym):
            where.setdefault((prog, sym), set()).add(a)
    conflicts, bad = [], set()
    for (prog, a), e in at.items():
        if len(e) > 1:
            conflicts.append(("two-names", prog, a, " ".join(f"{s}:{len(e[s])}" for s in sorted(e))))
            bad.add((prog, a))
    for (prog, sym), addrs in where.items():
        if len(addrs) > 1:
            for a in addrs:
                conflicts.append(("two-addresses", prog, a, f"{sym} " + " ".join(f"0x{x:08X}" for x in sorted(addrs))))
                bad.add((prog, a))
    out = {}
    for pa, e in at.items():
        if pa in bad:
            continue
        (sym, voters), = e.items()
        if len(voters) >= MIN_VOTERS and not X4DRAFT.match(sym):
            out[pa] = (sym, len(voters), pa in jumps)
    return out, conflicts


def merge(exact, pending, admitted, by_key, x6sym, defs, funcs, banked, pin7):
    """exact: {(prog, vram): row} of the build and 2a rows; pending: {(prog, vram): partner-table row} of the game
    functions with partners and no alias; admitted: tally's. -> (rows, conflicts)."""
    rows, conflicts, alias_at = dict(exact), [], {}
    for (prog, vram), r in exact.items():
        alias_at.setdefault((prog, r[4]), set()).add(int(vram, 16))
    for (prog, a), (sym, n, jump) in sorted(admitted.items()):
        pv = (prog, f"0x{a:08X}")
        if pv in exact:
            if exact[pv][4] != sym:
                conflicts.append(("exact-vs-slot", prog, a, f"{exact[pv][4]} {sym}:{n}"))
            continue
        other = alias_at.get((prog, sym), set()) - {a}
        if other:
            conflicts.append(("two-addresses", prog, a, f"{sym} exact " + " ".join(f"0x{x:08X}" for x in sorted(other))))
            continue
        col = pending.get(pv)
        if col is not None and int(col[3]) >= MIN_WORDS:
            ps = sorted(by_key.get(col[4], ()))
            named = [p for p in ps if p[1] == sym]
            if named and len({p[1] for p in ps}) > 1:  # the slots pick the partner inside a multi-partner class
                rows[pv] = exact_row(col, named[0][0], sym, f" slot {n}", f"{n}/0", banked, pin7)
                continue
        kind = "func" if jump or pv in funcs else "data"
        srcs = sorted(defs.get(sym, ()))
        rows[pv] = (prog, pv[1], kind, x6sym(prog, a, kind == "func"), sym, "slot",
                    scope_of(srcs[0]) if len(srcs) == 1 else "-", f"{n}/0",
                    f"x4 slot {n}/0 sozud/mmx4@{pin7} {sym}")
    return sorted(rows.values(), key=order), conflicts


def widen(ad):
    """names = the build rows + 2a + 2b for adapter ad (see the module header); intermediates in ad.SCRATCH."""
    os.chdir(ad.ROOT)
    tag, lo = ad.TAG, ad.TAG.lower()
    ref = pin(ad.ROOT)
    for p in ad.widen_inputs():
        if not os.path.exists(p):
            sys.exit(f"{lo}: {p} missing ({ad.WIDEN_HINT})")
    head = clone_head(ad.CLONE)
    if head != ref:
        sys.exit(f"{lo}: {ad.CLONE} at {short(head) or 'absent'}, pinned {short(ref)}")
    by_key, defs = partner_map(ad.OBJROOT)
    banked = ad.banked()
    corpus = ad.corpus()
    exact, pending, anchors = {}, {}, []
    cols = partner_cols(ad.PARTNERS, tag)
    for col in cols:
        ps = sorted(by_key.get(col[4], ()))
        if len(ps) != int(col[7]) or ps[0] != (col[5], col[6]):
            sys.exit(f"{lo}: {Path(ad.PARTNERS).name} {col[0]} {col[1]} disagrees with the X4 objects (rebuild the "
                     "partner table)")
        p = pick(ps)
        if p and not refusal(p[1], 1, int(col[3])):
            exact[(col[0], col[1])] = exact_row(col, p[0], p[1], p[2], "-", banked, short(ref))
            anchors.append((col, p[0], p[1]))
        else:
            pending[(col[0], col[1])] = col
    b = ad.slots()
    votes, unpaired = [], 0
    for col, src, xf in anchors if b is not None else ():
        row = corpus.get((col[0], col[1]))
        try:
            if row is None or row["words"] != int(col[3]):
                raise Skip("no corpus row")
            votes += b.votes(row, f"{ad.OBJROOT}/{src}.o", xf, f"{src}:{xf}")
        except Skip:
            unpaired += 1
    admitted, c1 = tally(votes)
    rows, c2 = merge(exact, pending, admitted, by_key, b.x6sym if b is not None else None, defs, set(corpus), banked,
                     short(ref))
    conflicts = sorted(c1 + c2)
    scratch = Path(ad.SCRATCH)
    os.makedirs(scratch, exist_ok=True)
    with open(scratch / "partners.full.tsv", "w") as f:
        for col in cols:
            for src, name in sorted(by_key[col[4]]):
                f.write(f"{col[0]}\t{col[1]}\t{col[4]}\t{src}\t{name}\n")
    with open(scratch / "votes.tsv", "w") as f:
        for prog, a, jump, sym, voter in sorted(votes):
            f.write(f"{prog}\t0x{a:08X}\t{'jump' if jump else 'addr'}\t{sym}\t{voter}\n")
    with open(scratch / "conflicts.log", "w") as f:
        for kind, prog, a, what in conflicts:
            f.write(f"{kind}\t{prog}\t0x{a:08X}\t{what}\n")
    write_names(ad.NAMES, rows)
    if b is None:
        print(f"{tag} slot lane unavailable")
    print(f"{tag} anchors {len(anchors)} unpaired {unpaired}; votes {len(votes)} on "
          f"{len({(v[0], v[1]) for v in votes})} addresses, admitted {len(admitted)}")
    print(f"{tag} conflicts {len(conflicts)}")
    print(count_line(rows, tag))
    return 0


# ---- lookup, the doc -------------------------------------------------------------------------------------------------

def who(names, text, tag):
    t = text.lower()
    hits = [r for r in load(names, tag) if t in r[4].lower() or t == r[3].lower() or t == f"{r[0]}:{r[1]}".lower()]
    if not hits:
        print(f"{tag} no alias for {text}")
        return 1
    for r in hits:
        print("\t".join(r))
    return 0


def doc(ad):
    """(Re)writes ad.DOC from ad.NAMES: the aliases grouped by mmx4 source file, the tier `slot` rows as leads, then
    ad.DOC_TEXT["tail"]."""
    rows = load(ad.NAMES, ad.TAG)
    g, t = ad.GAME, ad.DOC_TEXT
    groups = {}
    leads = [r for r in rows if r[5] == "slot"]
    for r in rows:
        if r[5] != "slot":
            groups.setdefault(r[8].split(" ")[4].rsplit(":", 1)[0], []).append(r)
    names_rel = Path(ad.NAMES).resolve().relative_to(Path(ad.ROOT).resolve()).as_posix()
    out = [
        f"# {t['title']}\n",
        "\n",
        f"Generated by `{t['tool']} --doc` from `{names_rel}`; never hand-edited.\n",
        "\n",
        f"Each row is an {g} address with a real name from sozud/mmx4 (AGPL-3.0, pin `{short(pin(ad.ROOT))}`). A `gate` "
        "or `bytes`\n"
        f"row is an {g} function of {MIN_WORDS} words or more whose compiled body equals an mmx4 function under {g}'s "
        "compiler: its\n"
        "only partner, or partners that all carry one name (`same-name <n>` in the basis), or the one partner the\n"
        "relocation slots of other aliased functions point at (`slot <n>`). The name is an alias: a search key for the\n"
        f"{g} address, not a symbol.{t['note']}\n",
        "\n",
        f"- tier `gate`: the {g} function is banked in C (proven-at-gate).\n",
        "- tier `bytes`: the signature is exact and the body is still assembly (consistent-with-bytes).\n",
        "- tier `slot`: a lead, not a proof. Two or more aliased functions reference this address in the relocation\n"
        "  slot where their mmx4 twin references that symbol, and none says otherwise. Votes are agree/disagree.\n",
        "- scope `object`: the mmx4 source is one object's file; identical bytes do not prove the same role, so the\n"
        "  name stays an alias until a role basis exists. Scope `engine`: everything else.\n",
        "\n",
        f"`{count_line(rows, ad.TAG)}`\n",
        "\n",
        f"Lookup: `python3 {t['tool']} --who <{t['lookup']}>`.\n",
        "\n",
        "## Aliases by mmx4 source file\n",
    ]
    for src in sorted(groups):
        out.append(f"\n### {src}\n\n")
        out.append(f"| alias | {g} address | {g} name | tier | scope |\n|---|---|---|---|---|\n")
        for r in groups[src]:
            out.append(f"| `{r[4]}` | `{r[0]}:{r[1]}` | `{r[3]}` | {r[5]} | {r[6]} |\n")
    out.append("\n## Leads: tier `slot`\n\nLeads only: named by relocation-slot votes, never a rename by themselves.\n")
    for kind, title in (("func", "Functions (lead)"), ("data", "Globals (lead)")):
        out.append(f"\n### {title}\n\n")
        out.append(f"| alias (lead) | {g} address | {g} name | votes | scope |\n|---|---|---|---|---|\n")
        for r in leads:
            if r[2] == kind:
                out.append(f"| `{r[4]}` | `{r[0]}:{r[1]}` | `{r[3]}` | {r[7]} | {r[6]} |\n")
    if t["tail"]:
        out.append("\n" + t["tail"])
    with open(ad.DOC, "w", newline="\n") as f:
        f.write("".join(out))
    doc_rel = Path(ad.DOC).resolve().relative_to(Path(ad.ROOT).resolve()).as_posix()
    print(f"{ad.TAG} doc {len(rows)} rows in {len(groups)} mmx4 files, {len(leads)} leads -> {doc_rel}")
    return 0


# ---- cross-repository: xref, parity, the Ghidra plate lines ----------------------------------------------------------

def xref(a, b):
    """(rows, pin): the X6 table a and the X5 table b joined on each row's mmx4 path:function."""
    pa, pb = pin(root_of(a)), pin(root_of(b))
    if pa != pb:
        die(f"xref refused: pins differ ({a} at {short(pa)}, {b} at {short(pb)})")
    by = {}
    for col in partner_cols(b):
        by.setdefault((col[5], col[6]), []).append(col)
    rows = []
    for x6 in partner_cols(a):
        for x5 in by.get((x6[5], x6[6]), ()):
            rows.append((x6[5], x6[6], x5[0], x5[1], x5[2], x5[8], x6[0], x6[1], x6[2], x6[8],
                         "single" if x5[7] == x6[7] == "1" else "multi", "=" if x5[4] == x6[4] else "!="))
    rows.sort(key=lambda r: (r[0], r[1], r[2], int(r[3], 16), r[6], int(r[7], 16)))
    return rows, pa


def parity(other, me=__file__):
    """The names of what differs between this copy and the sibling copy at other: core, pin, schema."""
    bad = []
    if hashlib.sha256(Path(me).read_bytes()).digest() != hashlib.sha256(Path(other).read_bytes()).digest():
        bad.append("core")
    if pin(root_of(me)) != pin(root_of(other)):
        bad.append("pin")
    spec = importlib.util.spec_from_file_location("x4core_other", other)
    mod = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(mod)
    if getattr(mod, "SCHEMA", None) != SCHEMA:
        bad.append("schema")
    return bad


def plate_line(r, pin7=None):
    """The plate-comment line of names row r; the pin is the basis's unless given."""
    b = r[8].split(" ")
    at = f"sozud/mmx4@{pin7}" if pin7 else next(x for x in b if x.startswith("sozud/mmx4@"))
    return f"x4: {r[4]} [{r[5]}/{r[6]}] {at} {b[4]}"


def ghidra_aliases(names, unit=None):
    """[(unit, vram, plate line)] of the names table, in table order; unit: only that unit's rows."""
    return [(r[0], r[1], plate_line(r)) for r in load(names) if unit in (None, r[0])]


# ---- self-test on synthetic objects ----------------------------------------------------------------------------------

def make_obj(path, funcs, externs=()):
    """A minimal ELF32 LE relocatable: .text, .rel.text, .symtab, .strtab, .shstrtab.
    funcs: [(name, words, sized, [(word index, reloc type, symbol)])]; externs: undefined symbol names."""
    text, strtab, syms, pend = b"", b"\0", [bytes(16)], []
    index = {}

    def sym(name, val, size, info, shndx):
        nonlocal strtab
        index[name] = len(syms)
        syms.append(struct.pack("<IIIBBH", len(strtab), val, size, info, 0, shndx))
        strtab += name.encode() + b"\0"

    for name, words, sized, rel in funcs:
        sym(name, len(text), 4 * len(words) if sized else 0, 0x12, 1)
        pend += [(len(text) + 4 * i, t, s) for i, t, s in rel]
        text += struct.pack(f"<{len(words)}I", *words)
    for name in externs:
        sym(name, 0, 0, 0x10, 0)
    rel = b"".join(struct.pack("<II", off, (index[s] << 8) | t) for off, t, s in pend)
    shstr = b"\0.text\0.rel.text\0.symtab\0.strtab\0.shstrtab\0"
    body = [(b"", 0, 0, 0, 0, 0), (text, 1, 6, 0, 0, 0), (rel, 9, 0, 3, 1, 8), (b"".join(syms), 2, 0, 4, 1, 16),
            (strtab, 3, 0, 0, 0, 0), (shstr, 3, 0, 0, 0, 0)]
    blob, heads = bytearray(52), []
    for i, (data, typ, flags, link, info, entsize) in enumerate(body):
        name = shstr.index(b"\0" + (b".text", b".rel.text", b".symtab", b".strtab", b".shstrtab")[i - 1] + b"\0") + 1 \
            if i else 0
        heads.append(struct.pack("<10I", name, typ, flags, 0, len(blob) if i else 0, len(data), link, info, 4, entsize))
        blob += data + bytes(-len(data) % 4)
    struct.pack_into("<4sBBB9xHHIIIIIHHHHHH", blob, 0, b"\x7fELF", 1, 1, 1, 1, 8, 1, 0, 0, len(blob), 0, 52, 0, 0, 40,
                     len(body), 5)
    os.makedirs(os.path.dirname(path), exist_ok=True)
    Path(path).write_bytes(bytes(blob) + b"".join(heads))


def selftest():
    shutil.rmtree(SELFTEST, ignore_errors=True)
    fails = []

    def case(name, ok, text):
        print(f"x4core: case {name} {text}")
        if not ok:
            fails.append(name)

    jal, lui, lo, nop = 0x0C000000, 0x3C020000, 0x8C420000, 0
    body = [0x27BDFFE8, 0xAFBF0010, jal, lui, lo, 0x00021040, 0x8FBF0010, 0x27BD0018, 0x03E00008, nop]
    rel = [(2, 4, "planted_callee"), (3, 5, "planted_global"), (4, 6, "planted_global")]
    tail = [0x03E00008, nop, nop]
    objroot = SELFTEST / "obj"
    make_obj(str(objroot / "src/main/a.c.o"), [("planted_one", body, True, rel), ("planted_tail", tail, False, [])],
             ("planted_callee", "planted_global"))
    make_obj(str(objroot / "src/main/weapons/b.c.o"),
             [("planted_two", body[:5] + [0x00021080] + body[6:], True, rel), ("planted_same", [9] * 8, True, []),
              ("func_80012345", [7] * 8, True, []), ("planted_short", [5] * 7, True, [])],
             ("planted_callee", "planted_global"))
    make_obj(str(objroot / "src/main/c.c.o"), [("planted_same", [9] * 8, True, [])])
    fs = {n: (w, m) for n, w, m in functions(str(objroot / "src/main/a.c.o"))}
    w1, m1 = fs["planted_one"]
    case("functions", w1 == body and m1 == [0, 0, MASKS[4], MASKS[5], MASKS[6], 0, 0, 0, 0, 0]
         and fs["planted_tail"][0] == tail, f"{len(fs)} functions, {sum(1 for m in m1 if m)} masked words, "
         f"unsized extent {len(fs['planted_tail'][0])}")
    # the game side: other relocated fields, same code
    game = list(body)
    game[2] |= 0x12345
    game[3] |= 0x8001
    game[4] |= 0x2340
    k = key(w1, m1)
    flip = list(game)
    flip[5] ^= 1
    case("key", key(game, m1) == k and key(flip, m1) != k, f"masked fields ignored {key(game, m1) == k}; "
         f"one unmasked bit -> other key {key(flip, m1) != k}")
    case("confirmed", confirmed(game, [(w1, m1), (tail, [0] * 3)]) == {k} and not confirmed(flip, [(w1, m1)]),
         "mask-less game words keyed under the mmx4 mask")
    by_key, defs = partner_map(objroot)
    k2 = key(*{n: (w, m) for n, w, m in functions(str(objroot / "src/main/weapons/b.c.o"))}["planted_two"])
    ksame, kdraft, kshort = key([9] * 8, [0] * 8), key([7] * 8, [0] * 8), key([5] * 7, [0] * 7)
    rows = write_partners(SELFTEST / "partners.tsv", [
        ("PLANTED", 0x80010000, "func_80010000", 10, k, "c"), ("PLANTED", 0x80010100, "func_80010100", 10, k2, "asm"),
        ("PLANTED", 0x80010200, "func_80010200", 8, ksame, "asm"), ("PLANTED", 0x80010300, "func_80010300", 8, kdraft, "c"),
        ("PLANTED", 0x80010400, "func_80010400", 7, kshort, "c"), ("PLANTED", 0x80010500, "func_80010500", 9, "0" * 40, "c"),
    ], by_key)
    case("partners", [(r[2], r[6], r[7]) for r in rows] == [
        ("func_80010000", "planted_one", 1), ("func_80010100", "planted_two", 1), ("func_80010200", "planted_same", 2),
        ("func_80010300", "func_80012345", 1), ("func_80010400", "planted_short", 1)]
        and defs["planted_one"] == {"src/main/a.c"}, f"{len(rows)} rows of 6 game functions")
    built = build(SELFTEST / "partners.tsv", SELFTEST / "names.tsv", lambda col: col[8] == "c", "abcdef0", "X4CORE")
    case("admission", [(r[4], r[5], r[6]) for r in built] == [("planted_one", "gate", "engine"),
                                                               ("planted_two", "bytes", "object")]
         and built[0][8] == f"x4 exact {k[:12]} sozud/mmx4@abcdef0 src/main/a.c:planted_one",
         "admitted " + " ".join(r[4] for r in built) + "; refused two partners, a draft name, 7 words")
    same = pick(sorted(by_key[ksame]))
    case("same_name", same == ("src/main/c.c", "planted_same", " same-name 2")
         and pick([("a", "x"), ("b", "y")]) is None, "one name over two partners admitted, two names refused")
    # slot votes: the game objects reference func_/D_ names where the mmx4 objects name the callee and the global
    grel = [(2, 4, "func_80020000"), (3, 5, "D_80030000"), (4, 6, "D_80030000")]
    make_obj(str(SELFTEST / "game/g.o"), [("func_80010000", body, True, grel),
                                          ("func_80010100", body[:5] + [0x00021080] + body[6:], True, grel)],
             ("func_80020000", "D_80030000"))
    ge = Elf(str(SELFTEST / "game/g.o"))
    addr_of = lambda n: int(n.rsplit("_", 1)[1], 16)
    votes = []
    for gname, src, xf in (("func_80010000", "src/main/a.c", "planted_one"),
                           ("func_80010100", "src/main/weapons/b.c", "planted_two")):
        r4 = Elf(str(objroot / f"{src}.o")).refs(xf, 10)
        votes += [("PLANTED", a, j, s, f"{src}:{xf}") for a, j, s in pair(r4, ge.refs(gname, 10), addr_of)]
    admitted, conf = tally(votes)
    got, conf2 = merge({}, {}, admitted, by_key, lambda p, a, t: "-", defs, set(), lambda col: False, "abcdef0")
    case("slot_votes", not conf and not conf2 and [(r[1], r[2], r[4], r[5], r[7]) for r in got] == [
        ("0x80020000", "func", "planted_callee", "slot", "2/0"), ("0x80030000", "data", "planted_global", "slot", "2/0")]
        and all(widened(r) for r in got), f"{len(votes)} votes, admitted {len(admitted)}")
    bent = votes + [("PLANTED", a, a == 0x80020000, f"planted_else_{i}", "src/main/c.c:v3")
                    for i, a in enumerate((0x80020000, 0x80030000))]
    adm2, conf3 = tally(bent)
    case("slot_disagree", not adm2 and len(conf3) == 2, f"admitted {len(adm2)} conflicts {len(conf3)}")
    # pin, xref, plate line, parity
    ref_a, ref_b = "a" * 40, "b" * 40
    for repo, ref in (("r6", ref_a), ("r5", ref_a), ("r5x", ref_b)):
        os.makedirs(SELFTEST / repo / "config")
        (SELFTEST / repo / REFS).write_text(f'[[ref]]\nname = "other"\nref = "{"c" * 40}"\n\n'
                                            f'[[ref]]\nname = "{REF_NAME}"\nurl = "{REPO}"\nref = "{ref}"\n')
        shutil.copy(SELFTEST / "partners.tsv", SELFTEST / repo / "partners.tsv")
    five = (SELFTEST / "r5/partners.tsv").read_text().splitlines()[:3]
    five = "".join(x.replace("PLANTED", "five").replace("func_8001", "FUN_8009") + "\n" for x in five)
    for repo in ("r5", "r5x"):
        (SELFTEST / repo / "partners.tsv").write_text(five.replace(k, "f" * 40))
    case("pin", pin(SELFTEST / "r6") == ref_a and short(ref_a) == "a" * 7 and clone_head(SELFTEST / "r6") == "",
         "the mmx4 row of a planted refs.toml")
    xr, xp = xref(SELFTEST / "r6/partners.tsv", SELFTEST / "r5/partners.tsv")
    try:
        xref(SELFTEST / "r6/partners.tsv", SELFTEST / "r5x/partners.tsv")
        refused = False
    except SystemExit:
        refused = True
    case("xref", xp == ref_a and [(r[1], r[2], r[4], r[6], r[8], r[10], r[11]) for r in xr] == [
        ("planted_one", "five", "FUN_80090000", "PLANTED", "func_80010000", "single", "!="),
        ("planted_same", "five", "FUN_80090200", "PLANTED", "func_80010200", "multi", "="),
        ("planted_two", "five", "FUN_80090100", "PLANTED", "func_80010100", "single", "=")] and refused,
        f"{len(xr)} rows; differing pins refused {refused}")
    lines = ghidra_aliases(SELFTEST / "names.tsv", "PLANTED")
    case("plate", lines[0] == ("PLANTED", "0x80010000",
                               "x4: planted_one [gate/engine] sozud/mmx4@abcdef0 src/main/a.c:planted_one")
         and plate_line(got[0]) == "x4: planted_callee [slot/-] sozud/mmx4@abcdef0 planted_callee"
         and not ghidra_aliases(SELFTEST / "names.tsv", "OTHER"), lines[0][2])
    twins = [SELFTEST / repo / "tools/x4core.py" for repo in ("r6", "r5", "r5x")]
    for twin in twins:
        os.makedirs(twin.parent)
        shutil.copy(__file__, twin)
    same, other_pin = parity(twins[1], twins[0]), parity(twins[2], twins[0])
    twins[1].write_bytes(twins[1].read_bytes() + b"# drift\n")
    case("parity", not same and other_pin == ["pin"] and parity(twins[1], twins[0]) == ["core"],
         "an identical copy passes; another pin and an edited copy fail")
    if fails:
        print("x4core: control FAIL " + " ".join(fails))
        return 1
    print("x4core: control OK")
    return 0


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("--selftest", action="store_true")
    sub = ap.add_subparsers(dest="cmd")
    x = sub.add_parser("xref", help="join two partner tables on the mmx4 path:function")
    x.add_argument("--a", required=True, help="the X6 partner table")
    x.add_argument("--b", required=True, help="the X5 partner table")
    x.add_argument("--out", help="write the rows here (default: stdout)")
    p = sub.add_parser("parity", help="core hash, pin and schema against the sibling copy")
    p.add_argument("--other", required=True, help="the sibling repository's x4core.py")
    g = sub.add_parser("ghidra-aliases", help="one plate-comment line per alias")
    g.add_argument("--names", required=True)
    g.add_argument("--unit")
    a = ap.parse_args(argv)
    if a.selftest:
        return selftest()
    if a.cmd == "xref":
        rows, ref = xref(a.a, a.b)
        text = "".join("\t".join(r) + "\n" for r in rows)
        if a.out:
            with open(a.out, "w", newline="\n") as f:
                f.write(text)
        else:
            sys.stdout.write(text)
        print(f"x4core: xref {len(rows)} rows, {len({(r[0], r[1]) for r in rows})} mmx4 functions, pin {short(ref)}",
              file=sys.stdout if a.out else sys.stderr)
        return 0
    if a.cmd == "parity":
        bad = parity(a.other)
        print("x4core: parity " + ("FAIL " + " ".join(bad) if bad else "OK"))
        return 1 if bad else 0
    if a.cmd == "ghidra-aliases":
        for unit, vram, line in ghidra_aliases(a.names, a.unit):
            print(f"{unit}\t{vram}\t{line}")
        return 0
    ap.print_usage(sys.stderr)
    return 2


if __name__ == "__main__":
    sys.exit(main())
