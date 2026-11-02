#!/usr/bin/env python3
"""objfields.py -- the member census and field table of the object family (include/mmx6/object.h: ObjectHeader,
BaseObj, AnimatedObj, MainObj), the player object (include/mmx6/player.h: PlayerObj, g_Player 0x800970A0), the
projectile entry (include/mmx6/projectile.h: ProjectileObj, g_projectiles 0x80093C98, 32 x 0xA0) and the state block
(include/mmx6/state.h: TransitionState, MainBssState, D_80097420 0x80097420, 0xC)
(stdlib; container: the Makefile cpp and the pinned cc1; 2.5 T5.c4, PlayerObj 2.5 T6.c1, ProjectileObj 2.5 T6.c2,
MainBssState 2.5 T7.c1).

  objfields.py --census
      -> per struct member `<struct> +0xNN <name> <w><s>` then its accesses `R|W <function> <w><s>[@+sub] <typed|raw>
         <matched|unmatched>`; last line `OBJFIELDS CENSUS <n> fields; accesses <a> (typed <t> raw <r>) in <f> functions`.
  objfields.py --check
      -> refusal lines, then last line `OBJFIELDS <n> fields <s> structs; mismatches <m>; bad notes <b>; raw reads <r>
         off-start <o>`; rc 0 iff m = b = o = 0.
         mismatch   config/types/fields.tsv vs the C0260 offsetof table (cc1 over object.h, player.h, projectile.h, state.h): offset,
                    width, signedness, one row per member both ways (a missing or extra row is a mismatch; an
                    anonymous `s8: 8` row is keyed by its offset).
         bad note   a DC7 note `// +0xNN read by F|written by F|unreferenced` in object.h|player.h|projectile.h|state.h whose F the census
                    does not show reading|writing that member, an `unreferenced` member the census shows touched, or a
                    member with no note.
         off-start  a raw access whose offset is no member's start and inside no aggregate member (union, struct,
                    array, X4_f32), or past the struct.
  objfields.py --self-test
      -> real tree passes (PlayerObj, ProjectileObj and MainBssState typed and raw accesses > 0); planted wrong offset, missing row, bad note (MainObj,
         PlayerObj), off-start raw read (MainObj, PlayerObj past its end) each refused (its counter > 0). Ends
         `OBJFIELDS CONTROL OK`, rc 1 on any miss.

Census heuristic (text only, comments stripped, over every C definition of config/c_units.txt via layout.Tree):
  typed  an access `v->m` / `v[i].m` / `v.m` where v is declared `struct [X4_]<T>` (pointer, array or value) as a
         parameter or local of the function, or at file scope of its file (player-range D_<addr>: raw);
         `SP_CUR_MAIN_OBJ->m` (MainObj); `g_projectiles[i].m` (ProjectileObj; `struct X4_ShotObj` is ProjectileObj); a file's object-like macro `#define X ((struct [X4_]PlayerObj*)&g_Player)` or
         `(*(...)&g_Player)` (P, PLAYER, F1EC4_PL: PlayerObj); a cast `((struct [X4_]<T> *)expr)->m`. m must be a member
         of T. Width/sign = the member's, unless `*(U *)&v->m` (then U's). Chains through other structs' pointer
         members (`x->owner->m`) and other macros are not followed.
  raw    in the temp#1 object type functions of docs/leads/objects.tsv (the slot is a MainObj), on the function's
         first parameter p: `M2C_FIELD(p, U*, 0xNN)` and `*(U *)((u8 *)p + 0xNN)`; width/sign = U's (a struct or
         unknown U: width `?`). PlayerObj, in every function: a placeholder D_<addr> with addr in [0x800970A0,
         +sizeof), at its file's `extern U D_<addr>` width/sign (`?` when undeclared there; a struct PlayerObj
         placeholder followed by `.m`: addr - base + m's offset, m's width); `M2C_FIELD(&g_Player, U*, 0xNN)`,
         `*(U *)((u8 *)&g_Player + 0xNN)`, and a file's object-like macro defined as either. Census limit: a local
         `u8* p = (u8*)&g_Player` and its indexing are not followed. ProjectileObj, in every function: a pool pointer
         v (a local or macro every `v = X` of which assigns from g_projectiles, from D_800950A0 (the second 32 x 0xA0
         pool, func_8002C32C's) or from another pool pointer):
         `v[0xNN]` (v's declared pointee), `*v` (not `*v++`), `*(U *)v`, `*(U *)(v + 0xNN)`, the raw spellings on v,
         and a file's function-like macro `#define M(a, o) (*(U *)((u8 *)(a) + (o)))` as `M(v, 0xNN)`. Census limit:
         a pointer reused for other pools (func_80022960's `p`) is not a pool pointer. MainBssState, in every
         function: typed `D_80097420.m` (the head, declared in state.h) and `v.transition.m` / `v->transition.m` on a
         MainBssState v (TransitionState m); raw `*(U *)&D_80097420` (offset 0, U's width) and a byte pointer
         `v = (U *)&D_80097420` indexed `v[0xNN]`.
  write  the access is the left side of `=` / `op=` or an operand of `++` / `--` (after any `.x` / `[i]` suffix);
         else a read.
  matched  the function's build/corpus/functions.jsonl row (prog, name) has state `c` (absent corpus: unmatched).
An access at another width/sign than the member's (or at a sub-offset of an aggregate) is a second-width access: the
fields.tsv note names it, the member is never retyped and --check never fails on it.
"""
import argparse
import json
import os
import re
import shutil
import sys
from pathlib import Path

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import layout  # noqa: E402  (Tree, RUN)
import x4adapter  # noqa: E402  (triple, tools)
import x4names  # noqa: E402  (members, offsets)
import x4port  # noqa: E402  (run_cpp, TRIPLE)

ROOT = Path(layout.ROOT)
TAG = "OBJFIELDS"
OBJH = "include/mmx6/object.h"
PLAYERH = "include/mmx6/player.h"
PROJH = "include/mmx6/projectile.h"
STATEH = "include/mmx6/state.h"
FIELDS = "config/types/fields.tsv"
LEADS = "docs/leads/objects.tsv"
CORPUS = "build/corpus/functions.jsonl"
STRUCTS = ("ObjectHeader", "BaseObj", "AnimatedObj", "MainObj", "PlayerObj", "ProjectileObj", "TransitionState",
           "MainBssState")
HEADERS = (OBJH, PLAYERH, PROJH, STATEH)  # the homes of STRUCTS (object.h: the first four; player.h, projectile.h: one
# each; state.h: the last two)
PROJ, POOL = "ProjectileObj", "g_projectiles"  # 0x80093C98, 32 x 0xA0 (config/symbols.SLUS_013.95.txt)
POOLS = r"\b(?:g_projectiles|D_800950A0)\b"  # + the second 32 x 0xA0 pool, func_8002C32C's (docs/types/projectile.md)
ALIAS = {"ShotObj": PROJ}  # x4 tags homed under another name (config/x4/homed.tsv)
STATE, TRANS, HEAD = "MainBssState", "TransitionState", "D_80097420"  # 0x80097420, 0xC (state.h; 2.5 T7.c1)
PLAYER, PBASE = "PlayerObj", 0x800970A0  # g_Player (config/symbols.SLUS_013.95.txt; next symbol 0x800971F8)
SLOT = "MainObj"  # temp#1 slots: the raw readers' struct
CPP = ["mipsel-linux-gnu-cpp", "-nostdinc", "-undef", "-D__GNUC__=2", "-DPSX", "-Iinclude"]  # Makefile CPP
SCR = ROOT / layout.RUN / "objfields"
ANON = "-"
COLS = ("struct", "offset", "width", "signedness", "name", "basis_kind", "ref", "tier", "note")
SCALAR = {"s8": (1, "s"), "u8": (1, "u"), "s16": (2, "s"), "u16": (2, "u"), "s32": (4, "s"), "u32": (4, "u"),
          "char": (1, "s"), "short": (2, "s"), "int": (4, "s"), "long": (4, "s")}
ST = "|".join(STRUCTS + tuple(ALIAS))
DECL = re.compile(rf"\bstruct\s+(?:X4_)?({ST})\b\s*((?:\*|\bconst\b|\s)*)([A-Za-z_]\w*)\s*(?=[;,=)\[])")
CAST = re.compile(rf"\(\s*\(\s*struct\s+(?:X4_)?({ST})\s*\*\s*\)\s*(?:[^()]|\([^()]*\))*?\)\s*->\s*(\w+)")
WRITE_AFTER = re.compile(r"(?:\s*(?:\.\s*\w+|\[[^\]]*\]))*\s*(?:(?:<<|>>|[-+*/%&|^])?=(?!=)|\+\+|--)")
WRITE_BEFORE = re.compile(r"(?:\+\+|--)\s*\(?\s*$")
WIDTH_CAST = re.compile(r"\*\s*\(\s*(\w+)\s*\*\s*\)\s*&\s*\(?\s*$")
NUM = r"(0[xX][0-9A-Fa-f]+|\d+)"
PADDR = r"D_(800970[A-F][0-9A-F]|800971[0-9A-F]{2})"
PDECL = re.compile(rf"\bextern\s+([\w\s]+?\**)\s*\b{PADDR}\b\s*(?:\[[^\]]*\])?\s*;")
PVIEW = re.compile(r"#define\s+(\w+)\s+\(\s*\*?\s*\(\s*struct\s+(?:X4_)?PlayerObj\s*\*\s*\)\s*&\s*g_Player\s*\)\s*$",
                   re.M)
PMACRO = re.compile(r"#define\s+(\w+)\s+(\S[^\n]*?)\s*$", re.M)
FMACRO = re.compile(r"#define\s+(\w+)\(\s*(\w+)\s*,\s*(\w+)\s*\)\s*\(\s*\*\s*\(\s*([\w\s]+?\**)\s*\*\s*\)\s*"
                    r"\(\s*\(\s*(?:u8|s8|char|unsigned char)\s*\*\s*\)\s*\(\s*\2\s*\)\s*\+\s*\(\s*\3\s*\)\s*\)\s*\)\s*$", re.M)
NOTE = re.compile(r"//\s*\+0x([0-9A-Fa-f]+)\s+(?:(read|written) by (\w+)|(unreferenced))")


def canon(tag):
    """A census tag (group of DECL/CAST): its STRUCTS name (X4_ShotObj -> ProjectileObj)."""
    return ALIAS.get(tag, tag)


def home_text():
    """object.h, player.h, projectile.h and state.h, concatenated (the struct blocks and their notes)."""
    return "\n".join((ROOT / h).read_text() for h in HEADERS)


def rkey(s, name, off):
    """A member's row key: (struct, name); an anonymous `s8: 8` is (struct, '-0xNN') (PlayerObj has three)."""
    return (s, name if name != ANON else f"{ANON}{off}")


def strip_comments(text):
    """Comments -> spaces (newlines kept)."""
    return re.sub(r"/\*.*?\*/|//[^\n]*", lambda m: re.sub(r"[^\n]", " ", m.group(0)), text, flags=re.S)


# ---- the layout (C0260) ----------------------------------------------------------------------------------------------

def decls(text):
    """{struct: [(name, type text, aggregate)]} of the STRUCTS blocks of the home text, in order; the anonymous
    `s8: 8` is (ANON, 's8', False). Members split at top-level `;` (a nested `union { ... } input;` is one member)."""
    out = {}
    for s in STRUCTS:
        m = re.search(rf"\bstruct\s+{s}\s*\{{(.*?)\n\}};", text, re.S)
        rows, cur, d = [], "", 0
        decls_ = []
        for c in strip_comments(m.group(1) if m else ""):
            d += 1 if c == "{" else -1 if c == "}" else 0
            if c == ";" and d == 0:
                decls_.append(" ".join(cur.split()) + ";")
                cur = ""
            else:
                cur += c
        for line in decls_:
            b = re.fullmatch(r"(\w+)\s*:\s*\d+\s*;", line)
            if b:
                rows.append((ANON, b.group(1), False))
                continue
            d = re.fullmatch(r"(.+?)\s*\b(\w+)\s*(\[[^\]]+\])?\s*;", line)
            if d:
                ty = d.group(1)
                agg = bool(d.group(3)) or ("*" not in ty and (re.search(r"\b(union|struct)\b", ty) is not None
                                                           or ty.split()[-1] == "X4_f32"))
                rows.append((d.group(2), ty, agg))
        out[s] = rows
    return out


def sign_of(ty, agg):
    if agg or "*" in ty:
        return "-"
    return SCALAR.get(ty.replace("const", "").split()[-1], (0, "-"))[1]


def struct_layout(text=None):
    """{struct: [(offset, width, signedness, name, aggregate)]} by the pinned cc1 over the HEADERS (C0260:
    x4names.offsets; a width is the same table with `m * 0 + (int)sizeof(((T *)0)->m)`, so offset+1 becomes sizeof+1);
    plus {struct: size}."""
    text = text if text is not None else home_text()
    SCR.mkdir(parents=True, exist_ok=True)
    try:
        src = SCR / "objfields.c"
        src.write_text("".join(f'#include "{h[len("include/"):]}"\n' for h in HEADERS))
        pp = x4port.run_cpp(CPP + [str(src)], str(ROOT))
    finally:
        shutil.rmtree(SCR, ignore_errors=True)
    cc1 = x4adapter.tools(x4adapter.triple(x4port.TRIPLE))["cc1"]
    named = {s: [n for n, note in x4names.members(pp, "struct", s) if not note] for s in STRUCTS}
    reqs = [(i, f"struct {s}", named[s]) for i, s in enumerate(STRUCTS)]
    off = x4names.offsets(pp, reqs, cc1)
    sreq = [(i, f"struct {s}", [f"{f} * 0 + (int)sizeof(((struct {s} *)0)->{f})" for f in named[s]]
             + [f"{named[s][0]} * 0 + (int)sizeof(struct {s})"]) for i, s in enumerate(STRUCTS)]
    siz = x4names.offsets(pp, sreq, cc1)
    out, size = {}, {}
    for i, s in enumerate(STRUCTS):
        size[s] = siz[(i, sreq[i][2][-1])]
        rows, nxt = [], 0
        for n, ty, agg in decls(text)[s]:
            if n == ANON:  # the anonymous bitfield: right after the previous member, its type's width
                o, w = nxt, SCALAR[ty][0]
            else:
                o, w = off[(i, n)], siz[(i, f"{n} * 0 + (int)sizeof(((struct {s} *)0)->{n})")]
            rows.append((o, w, sign_of(ty, agg), n, agg))
            nxt = o + w
        out[s] = rows
    return out, size


# ---- the census ------------------------------------------------------------------------------------------------------

def utype(u):
    """(width | None, sign) of a pointee type text U (of `U*`)."""
    u = u.replace("const", "").strip()
    if u.endswith("*"):
        return 4, "-"
    if re.search(r"\b(struct|union)\b", u) or u == "void":
        return None, "-"
    return SCALAR.get(u.split()[-1], (None, "-"))


def temp1():
    """{(prog, function)} of the temp#1 rows of docs/leads/objects.tsv."""
    out = set()
    for line in (ROOT / LEADS).read_text().splitlines():
        f = line.split("\t")
        if f[0] == "temp#1" and len(f) > 3:
            out.add((f[3].split(":")[0], f[2]))
    return out


def corpus():
    """{(prog, name): state} of build/corpus/functions.jsonl ({} when absent)."""
    p = ROOT / CORPUS
    if not p.is_file():
        return {}
    out = {}
    for line in p.read_text().splitlines():
        if line.strip():
            r = json.loads(line)
            out[(r["prog"], r["name"])] = r["state"]
    return out


def is_write(body, a, b):
    return bool(WRITE_AFTER.match(body, b) or WRITE_BEFORE.search(body, 0, a))


def raw_pats(p):
    """The two raw-access spellings on base expression regex p: groups (U, offset)."""
    return (rf"M2C_FIELD\(\s*{p}\s*,\s*([^,]+?)\s*\*\s*,\s*{NUM}\s*\)",
            rf"\*\s*\(\s*([\w\s]+?\**)\s*\*\s*\)\s*\(\s*\(\s*(?:u8|s8|char|unsigned char)\s*\*\s*\)\s*{p}\s*\+\s*{NUM}\s*\)")


def player_scope(text):
    """(views, placeholders, macros) of one file's text (comments stripped): views {macro: PlayerObj} (the P/PLAYER/
    F1EC4_PL `(struct PlayerObj*)&g_Player` macros); placeholders {D_<addr>: U} of its `extern U D_<addr>` in the
    player range; macros {name: (U, offset)} of its object-like macros defined as a raw &g_Player access."""
    views = {m.group(1): PLAYER for m in PVIEW.finditer(text)}
    ph = {"D_" + m.group(2): " ".join(m.group(1).split()) for m in PDECL.finditer(text)}
    mac = {}
    for m in PMACRO.finditer(text):
        for pat in raw_pats(r"&\s*g_Player"):
            r = re.fullmatch(pat, m.group(2))
            if r:
                mac[m.group(1)] = (r.group(1), int(r.group(2), 0))
    return views, ph, mac


def scan_player(body, pscope, by_name, size):
    """[(PLAYER, None, offset, width | None, sign, 'r'|'w', 'raw')] of one body: the D_<addr> placeholders, the raw
    &g_Player spellings and the file's raw macros (player_scope)."""
    _, ph, mac = pscope
    out = []
    body = PDECL.sub(lambda m: " " * len(m.group(0)), body)  # declarations are not accesses
    for m in re.finditer(rf"\b{PADDR}\b", body):
        o, end = int(m.group(1), 16) - PBASE, m.end()
        if o >= size:
            continue
        u = ph.get(m.group(0))
        w, sg = utype(u) if u else (None, "-")
        mem = re.match(r"\s*\.\s*(\w+)", body[end:])
        if u and re.search(rf"\bstruct\s+(?:X4_)?{PLAYER}\b", u) and mem and mem.group(1) in by_name:
            r = by_name[mem.group(1)]
            o, w, sg, end = o + r[0], r[1], r[2], end + mem.end()
        out.append((PLAYER, None, o, w, sg, "w" if is_write(body, m.start(), end) else "r", "raw"))
    pats = [(pat, None) for pat in raw_pats(r"&\s*g_Player")] + [(rf"(?<![\w.>]){re.escape(n)}\b", uo)
                                                                  for n, uo in mac.items()]
    for pat, uo in pats:
        for m in re.finditer(pat, body):
            u, o = uo if uo else (m.group(1), int(m.group(2), 0))
            w, sg = utype(u)
            out.append((PLAYER, None, o, w, sg, "w" if is_write(body, m.start(), m.end()) else "r", "raw"))
    return out


def pool_scope(text):
    """{macro: U} of one file's function-like raw macros `#define M(a, o) (*(U *)((u8 *)(a) + (o)))`."""
    return {m.group(1): " ".join(m.group(4).split()) for m in FMACRO.finditer(text)}


def scan_pool(body, fmac):
    """[(PROJ, None, offset, width | None, sign, 'r'|'w', 'raw')] of one body through its pool pointers (a name every
    `v = X` of which assigns from g_projectiles, D_800950A0 or another pool pointer)."""
    asg = {}
    for m in re.finditer(r"(?<![\w.>\]])(\w+)\s*=(?!=)\s*([^;,)]+(?:\)[^;,)]*)*)", body):
        asg.setdefault(m.group(1), []).append(m.group(2).strip())
    pool = {v for v, xs in asg.items() if any(re.search(POOLS, x) for x in xs)}
    while True:
        keep = {v for v in pool if all(re.search(POOLS, x) or x in pool for x in asg[v])}
        keep |= {v for v, xs in asg.items() if v not in pool and xs and all(x in keep for x in xs)}
        if keep == pool:
            break
        pool = keep
    out = []

    def add(o, u, a, b):
        w, sg = utype(u) if u else (None, "-")
        out.append((PROJ, None, o, w, sg, "w" if is_write(body, a, b) else "r", "raw"))

    for v in sorted(pool):
        ev = re.escape(v)
        d = re.search(rf"\b((?:unsigned\s+)?\w+)\s*\*\s*{ev}\s*[;,=)]", body)
        elem = d.group(1) if d else None
        for m in re.finditer(rf"(?<![\w.>]){ev}\s*\[\s*{NUM}\s*\]", body):
            add(int(m.group(1), 0), elem, m.start(), m.end())
        for m in re.finditer(rf"(?<![\w*)])\*\s*{ev}\b(?!\s*(?:\+\+|--|\[|\+|-))", body):
            add(0, elem, m.start(), m.end())
        for m in re.finditer(rf"\*\s*\(\s*([\w\s]+?\**)\s*\*\s*\)\s*{ev}\b(?!\s*[+\[])", body):
            add(0, m.group(1), m.start(), m.end())
        for m in re.finditer(rf"\*\s*\(\s*([\w\s]+?\**)\s*\*\s*\)\s*\(\s*{ev}\s*\+\s*{NUM}\s*\)", body):
            add(int(m.group(2), 0), m.group(1), m.start(), m.end())
        for pat in raw_pats(ev):
            for m in re.finditer(pat, body):
                add(int(m.group(2), 0), m.group(1), m.start(), m.end())
        for name, u in fmac.items():
            for m in re.finditer(rf"(?<![\w.>]){re.escape(name)}\(\s*{ev}\s*,\s*{NUM}\s*\)", body):
                add(int(m.group(1), 0), u, m.start(), m.end())
    return out


def scan(body, filescope, raw_param, members):
    """[(struct, member | None, offset | None, width | None, sign, 'r'|'w', via)] of one function body (comments
    stripped); filescope: {var: struct}; raw_param: the first parameter name when raw reads count, else None;
    members: {struct: {name}}. Raw rows carry (SLOT, None, offset, width, sign); typed rows (struct, member)."""
    out = []
    vars_ = dict(filescope)
    for m in DECL.finditer(body):
        vars_[m.group(3)] = canon(m.group(1))
    vars_ = {v: t for v, t in vars_.items() if not re.fullmatch(PADDR, v)}  # player-range placeholders: raw
    vars_["SP_CUR_MAIN_OBJ"] = "MainObj"
    vars_[POOL] = PROJ
    vars_[HEAD] = STATE

    def typed(s, mem, a, b):
        if mem not in members[s]:
            return
        wc = WIDTH_CAST.search(body, 0, a)
        w, sg = utype(wc.group(1)) if wc else (None, None)
        out.append((s, mem, None, w, sg, "w" if is_write(body, a, b) else "r", "typed"))

    for v, s in vars_.items():
        for m in re.finditer(rf"(?<![\w.>]){re.escape(v)}\s*(?:\[[^\]]*\]\s*)?(?:->|\.)\s*(\w+)", body):
            typed(s, m.group(1), m.start(), m.end())
    for m in CAST.finditer(body):
        typed(canon(m.group(1)), m.group(2), m.start(), m.end())
    for v in [v for v, s in vars_.items() if s == STATE]:  # the head's nested transition: TransitionState members
        for m in re.finditer(rf"(?<![\w.>]){re.escape(v)}\s*(?:->|\.)\s*transition\s*\.\s*(\w+)", body):
            typed(TRANS, m.group(1), m.start(), m.end())
    if raw_param:
        p = re.escape(raw_param)
        for pat in raw_pats(p):
            for m in re.finditer(pat, body):
                w, sg = utype(m.group(1))
                out.append((SLOT, None, int(m.group(2), 0), w, sg,
                            "w" if is_write(body, m.start(), m.end()) else "r", "raw"))
    return out


def first_param(head):
    m = re.search(r"\(\s*([^)]*)\)", head)
    if not m or not m.group(1).strip() or m.group(1).strip() == "void":
        return None
    ids = re.findall(r"[A-Za-z_]\w*", m.group(1).split(",")[0])
    return ids[-1] if ids else None


def scan_state(body):
    """[(STATE, None, offset, width | None, sign, 'r'|'w', 'raw')] of one body: `*(U *)&D_80097420` (not followed by a
    member) and the byte pointers `v = (U *)&D_80097420` indexed `v[0xNN]` (docs/types/state.md views)."""
    out = []
    h = re.escape(HEAD)
    for m in re.finditer(rf"\*\s*\(\s*([\w\s]+?\**)\s*\*\s*\)\s*&\s*{h}\b(?!\s*\.)", body):
        w, sg = utype(m.group(1))
        out.append((STATE, None, 0, w, sg, "w" if is_write(body, m.start(), m.end()) else "r", "raw"))
    for d in re.finditer(rf"\b(\w+)\s*=\s*\(\s*((?:unsigned\s+)?\w+)\s*\*\s*\)\s*&\s*{h}\b(?!\s*\.)", body):
        w, sg = utype(d.group(2))
        for m in re.finditer(rf"(?<![\w.>]){re.escape(d.group(1))}\s*\[\s*{NUM}\s*\]", body):
            out.append((STATE, None, int(m.group(1), 0), w, sg, "w" if is_write(body, m.start(), m.end()) else "r",
                        "raw"))
    return out


def census(lay, size):
    """[(struct, offset, width, sign, rw, function, matched, via, sub)] over the tree: sub = the access offset minus
    the member's start (0 on the start, None off-start); offset = the member's start (the access offset when off-start)."""
    tree = layout.Tree(str(ROOT))
    raw_fns, state = temp1(), corpus()
    members = {s: {r[3] for r in lay[s]} for s in STRUCTS}
    by_name = {s: {r[3]: r for r in lay[s]} for s in STRUCTS}
    fscope, pscope, fmac, seen, out = {}, {}, {}, {}, []
    for prog, tu in tree.units():
        for f in tree.fns(prog, tu):
            if f.kind != "def":
                continue
            key = (f.path, f.first, f.name)
            seen.setdefault(key, [f, set()])[1].add(prog)
    spans = {}
    for (path, _, _), (f, _) in seen.items():
        spans.setdefault(path, []).append((f.first, f.last))
    for (path, first, name), (f, progs) in sorted(seen.items(), key=lambda kv: kv[0]):
        if path not in fscope:  # file-scope declarations: the file's lines outside its function bodies
            lines = list(tree.lines(path))
            for a, b in spans[path]:
                lines[a:b + 1] = [""] * (b + 1 - a)
            fscope[path] = {m.group(3): canon(m.group(1)) for m in DECL.finditer(strip_comments("\n".join(lines)))}
            pscope[path] = player_scope(strip_comments("\n".join(tree.lines(path))))
            fmac[path] = pool_scope(strip_comments("\n".join(tree.lines(path))))
            fscope[path].update(pscope[path][0])
        body = strip_comments("\n".join(tree.lines(path)[first:f.last + 1]))
        raw = first_param(body) if any((p, name) in raw_fns for p in progs) else None
        matched = any(state.get((p, name)) == "c" for p in progs)
        for s, mem, o, w, sg, rw, via in (scan(body, fscope[path], raw, members)
                                          + scan_player(body, pscope[path], by_name[PLAYER], size[PLAYER])
                                          + scan_pool(body, fmac[path]) + scan_state(body)):
            if mem is not None:
                r = by_name[s][mem]
                out.append((s, r[0], w or r[1], sg or r[2], rw, name, matched, via, 0))
                continue
            hit = next((r for r in lay[s] if r[0] <= o < r[0] + r[1] and (r[0] == o or r[4])), None)
            out.append((s, hit[0] if hit else o, w, sg, rw, name, matched, via, (o - hit[0]) if hit else None))
    return sorted(set(out), key=lambda a: (STRUCTS.index(a[0]), a[1], a[5], a[4], a[7], a[8] or 0, a[2] or 0, a[3]))


# ---- fields.tsv, notes, the check ------------------------------------------------------------------------------------

def read_fields(text):
    """{(struct, name): row dict} of fields.tsv text (`#` lines skipped)."""
    out = {}
    for line in text.splitlines():
        if line.startswith("#") or not line.strip():
            continue
        f = line.split("\t")
        r = dict(zip(COLS, f + [""] * (len(COLS) - len(f))))
        out[rkey(r["struct"], r["name"], r["offset"])] = r
    return out


def notes(text):
    """{(struct, offset): (kind 'read'|'written'|'unreferenced', function | None)} of the DC7 notes in the home text."""
    out = {}
    for s in STRUCTS:
        m = re.search(rf"\bstruct\s+{s}\s*\{{(.*?)\n\}};", text, re.S)
        for line in (m.group(1) if m else "").splitlines():
            n = NOTE.search(line)
            if n:
                out[(s, int(n.group(1), 16))] = (n.group(2) or "unreferenced", n.group(3))
    return out


def check(lay, ftext, htext, cen, say=print):
    """(n fields, mismatches, bad notes, raw reads, off-start); refusal lines through say."""
    rows, mis, bad = read_fields(ftext), 0, 0
    want = {rkey(s, r[3], f"0x{r[0]:02X}"): r for s in STRUCTS for r in lay[s]}
    for k, r in sorted(want.items()):
        got = rows.get(k)
        if got is None:
            say(f"{TAG} REFUSE mismatch {k[0]}.{k[1]} missing from {FIELDS}")
            mis += 1
        elif (got["offset"], got["width"], got["signedness"]) != (f"0x{r[0]:02X}", str(r[1]), r[2]):
            say(f"{TAG} REFUSE mismatch {k[0]}.{k[1]} tsv {got['offset']} {got['width']} {got['signedness']}"
                f" vs cc1 0x{r[0]:02X} {r[1]} {r[2]}")
            mis += 1
    for k in sorted(set(rows) - set(want)):
        say(f"{TAG} REFUSE mismatch {k[0]}.{k[1]} in {FIELDS}, not a member")
        mis += 1
    nt = notes(htext)
    for s in STRUCTS:
        for o, _, _, n, _ in lay[s]:
            acc = [a for a in cen if a[0] == s and a[1] == o and a[8] is not None]
            got = nt.get((s, o))
            if got is None:
                ok, why = False, "no note"
            elif got[0] == "unreferenced":
                ok, why = not acc, f"unreferenced but touched by {acc[0][5]}" if acc else ""
            else:
                ok = any(a[5] == got[1] and a[4] == got[0][0] for a in acc)
                why = f"{got[0]} by {got[1]} not in the census"
            if not ok:
                say(f"{TAG} REFUSE bad-note {s}.{n} +0x{o:02X} {why}")
                bad += 1
    raws = [a for a in cen if a[7] == "raw"]
    off = [a for a in raws if a[8] is None]
    for a in off:
        say(f"{TAG} REFUSE off-start {a[0]} +0x{a[1]:02X} by {a[5]}")
    return len(want), mis, bad, len(raws), len(off)


def summary(n, mis, bad, raws, off):
    return f"{TAG} {n} fields {len(STRUCTS)} structs; mismatches {mis}; bad notes {bad}; raw reads {raws} off-start {off}"


def acc_text(a):
    w = "?" if a[2] is None else str(a[2])
    sub = f"@+{a[8]}" if a[8] else ""
    return f"{'R' if a[4] == 'r' else 'W'} {a[5]} {w}{a[3]}{sub} {a[7]} {'matched' if a[6] else 'unmatched'}"


def cmd_census():
    lay, size = struct_layout()
    cen = census(lay, size)
    for s in STRUCTS:
        for o, w, sg, n, _ in lay[s]:
            print(f"{s} +0x{o:02X} {n} {w}{sg}")
            for a in cen:
                if a[0] == s and a[1] == o and a[8] is not None:
                    print("  " + acc_text(a))
    for a in cen:
        if a[8] is None:
            print(f"{a[0]} +0x{a[1]:02X} OFF-START {acc_text(a)}")
    t = sum(a[7] == "typed" for a in cen)
    print(f"{TAG} CENSUS {sum(len(lay[s]) for s in STRUCTS)} fields; accesses {len(cen)} (typed {t} raw {len(cen) - t})"
          f" in {len({a[5] for a in cen})} functions")
    return 0


def cmd_check():
    lay, size = struct_layout()
    res = check(lay, (ROOT / FIELDS).read_text(), home_text(), census(lay, size))
    print(summary(*res))
    return 0 if res[1] == res[2] == res[4] == 0 else 1


def self_test():
    lay, size = struct_layout()
    cen = census(lay, size)
    ftext, htext = (ROOT / FIELDS).read_text(), home_text()
    quiet = lambda s: None  # noqa: E731
    fails = []

    def case(name, ok):
        print(f"{TAG} CASE {name} {'ok' if ok else 'FAIL'}")
        if not ok:
            fails.append(name)

    n, mis, bad, raws, off = check(lay, ftext, htext, cen, quiet)
    case("clean", mis == bad == off == 0 and n > 0 and raws > 0)
    case("player-census", any(a[0] == PLAYER and a[7] == "typed" for a in cen)
         and any(a[0] == PLAYER and a[7] == "raw" for a in cen) and size[PLAYER] > 0)
    case("projectile-census", any(a[0] == PROJ and a[7] == "typed" for a in cen)
         and any(a[0] == PROJ and a[7] == "raw" for a in cen) and size[PROJ] == 0xA0)
    case("state-census", any(a[0] == STATE and a[7] == "typed" for a in cen) and any(a[0] == TRANS for a in cen)
         and any(a[0] == STATE and a[7] == "raw" for a in cen) and size[STATE] == 0xC)
    lines = ftext.splitlines()
    k = next(i for i, l in enumerate(lines) if l.startswith(f"{SLOT}\t0x5C\t"))
    f = lines[k].split("\t")
    wrong = "\n".join(lines[:k] + ["\t".join(f[:1] + ["0x5D"] + f[2:])] + lines[k + 1:])
    case("wrong-offset", check(lay, wrong, htext, cen, quiet)[1] > 0)
    case("missing-row", check(lay, "\n".join(lines[:k] + lines[k + 1:]), htext, cen, quiet)[1] > 0)
    planted = re.sub(r"(s8 hp;\s*//\s*\+0x5C)[^\n]*", r"\1 read by func_DEADBEEF", htext, count=1)
    case("bad-note", planted != htext and check(lay, ftext, planted, cen, quiet)[2] > 0)
    planted = re.sub(r"(s8 hud_hp;\s*//\s*\+0x5D)[^\n]*", r"\1 written by func_DEADBEEF", htext, count=1)
    case("player-bad-note", planted != htext and check(lay, ftext, planted, cen, quiet)[2] > 0)
    stray = cen + [(SLOT, 0x6D, 1, "u", "r", "func_DEADBEEF", False, "raw", None)]
    case("off-start", check(lay, ftext, htext, stray, quiet)[4] > 0)
    stray = cen + [(PLAYER, size[PLAYER], 1, "s", "r", "func_DEADBEEF", False, "raw", None)]
    case("player-past-end", check(lay, ftext, htext, stray, quiet)[4] > 0)
    if fails:
        print(f"{TAG} CONTROL FAIL {' '.join(fails)}")
        return 1
    print(f"{TAG} CONTROL OK")
    return 0


def main(argv):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    g = ap.add_mutually_exclusive_group(required=True)
    g.add_argument("--census", action="store_true")
    g.add_argument("--check", action="store_true")
    g.add_argument("--self-test", action="store_true")
    a = ap.parse_args(argv)
    os.chdir(ROOT)
    return cmd_census() if a.census else cmd_check() if a.check else self_test()


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
