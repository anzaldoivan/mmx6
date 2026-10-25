#!/usr/bin/env python3
"""x4adapter.py -- mmx6's side of the shared X4 core (tools/mmx6/x4core.py; stdlib): everything X6-specific the core asks for.

The core (x4core.py, the same bytes as mmx5's tools/sig/x4core.py) knows mmx4 and the tables; this module supplies
the game. Callers: x4share.py (the partner table), x4names.py (the names table and its doc).
  the pin         config/refs.toml `[[ref]] name = "mmx4"` (x4core.pin); the port lane (x4port.py, include/mmx6/x4.h and
                  the adapted src/shared files) stays at x4port.PIN until it is re-ported.
  the toolchain   triple(name) -> a config/triples.txt row (default: the plan's gcc2.6.3-psx + aspsx 2.63);
                  tools(t) -> the cc1 and maspsx commands of x4core.compile_one. X6's flags live in triples.txt only.
  the clone       CLONE = .run/mmx4; objects under SCR/<triple>/obj/ (OBJROOT: the pin triple's).
  the functions   game(x6, rows): (prog, vram, name, words, exact key, state) per build/sig/sigs.jsonl row, name and
                  state from build/corpus/functions.jsonl; the key is two-sided (X6 words under the X6 object's
                  relocation mask, mmx4 words under the mmx4 object's), equal to census.dup_key.
  tier gate       banked(): partners state `c`, or the function's name / key in an attributed src/shared file.
  game objects    slots() -> Build: the X6 object and linked symbols of an anchor (census.obj_of, x4port.Addrs).
  tables, doc     PARTNERS, NAMES, DOC, SCRATCH, DOC_TEXT.

  x4adapter.py --ghidra <prog> --out <path>
      -> the plate-comment mirror of the aliases of <prog> (x4core.ghidra_aliases) in mmx6's annotation record shape
         `{"k":"comment","addr":"0x…","type":"plate","text":…}`: config/ghidra/<prog>.jsonl with one line appended to
         the plate comment an aliased address already has, and one new record per aliased address without one (in
         the export's order; a function's own comment field follows its entry's plate comment), written
         to <path> (scratch; config/ghidra is never written here). Never a rename. Last line
         `X4NAMES ghidra <prog> <n> aliases: <new> new plate comments, <appended> appended, <kept> already there`
  x4adapter.py --mirror --out <dir>
      -> the symbol mirror into the Ghidra database (tools/mmx6/ghidra/mirror.sh applies it): per program
         (SLUS_013.95 + import.sh --list) <dir>/<prog>.jsonl = the program row of config/ghidra/<prog>.jsonl + delta
         records only. A renamed symbol (config/symbols.<prog>.txt: a `// basis:`-annotated name != func_/D_<ADDR>):
         a `func` record first when the export has no function there (creates it), a `label` {primary, USER_DEFINED,
         func for type:func}, the basis line as plate comment. Every other names.tsv row of <prog>: its plate line.
         Plate text = the export's plate + the new line unless already there. Every record is emitted on a rerun too
         (Ghidra counts it unchanged). Last line per program
         `X4NAMES mirror <prog> <r> renames (<f> new funcs): <new> new plate comments, <appended> appended, <kept> already there`
"""
import json
import os
import re
import sys
from pathlib import Path

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import census  # noqa: E402  (asm_index, obj_of)
import x4core  # noqa: E402

ROOT = Path(__file__).resolve().parents[2]
TAG, GAME = "X4NAMES", "X6"
CLONE = ".run/mmx4"
SCR = ".run/x4share"
TRIPLES = "config/triples.txt"
CORPUS = "build/corpus/functions.jsonl"
TRIPLE = "gcc2.95.2-psx-aspsx2.86"  # the pin triple (= x4port.TRIPLE, asserted by x4names.py --self-test)
DEFAULT = dict(name="gcc2.6.3-psx-aspsx2.63", cc1="/opt/cc/2.6.3-psx/cc1", row="gcc2.6.3-psx-aspsx2.86",
               maspsx="--aspsx-version=2.63 --expand-div")
OBJROOT = f"{SCR}/{TRIPLE}/obj"
EXE = "SLUS_013.95"
PARTNERS = ROOT / "campaign/x4/partners.tsv"
SHARED = ROOT / "src/shared"
NAMES = ROOT / "config/x4/names.tsv"
DOC = ROOT / "docs/x4-names.md"
SCRATCH = ROOT / ".run/x4names"  # --widen intermediates: container only, never pulled or tracked
GHIDRA = ROOT / "config/ghidra"
WIDEN_HINT = "--widen runs in the container, after x4share.py --partners"
# a function definition at column 0: `<type words> name(<params>) {`
DEFINED = re.compile(r"^\w[^;{}()\n]*?\b(\w+)\s*\([^;{}]*\)\s*\{", re.M)

PHASE_1_10 = """## For phase 1.10

Handoff for the planner of phase 1.10 (Readability). Nothing here is applied yet: every row above is an alias.

Proposed row amendment:
- Scope gains "X4-proven renames applied by script from `config/x4/names.tsv`".
- Milestone gains "every rename-admitted row of names.tsv is applied or listed with a reason".
- Milestone gains "no tool derives an address from a symbol's spelling".

Rename admission:
- `kind func` with tier `gate` and scope `engine`.
- `kind data` with tier `slot` and at least 3 agreeing anchors (the `content` tier was measured and not built:
  `X4NAMES data-probe 6 unique of 76`, docs/prior-art.md L5a).
- Everything else stays an alias.

Order of work:
1. Remove name-to-address code: `tools/mmx6/probe.py:184-228`, `tools/mmx6/bound2.py:512-530` and the `func_`
   filter at `tools/mmx6/cards.py:385`. Also `sdk.py:435`, `x4port.py:202` and `x4core.py:798`. The address-named
   self-test constants go too: `bank.py:61`, `gate.py:73`, `corpus.py:382`, `x4port.py:86`, `x4share.py:69`,
   `carve.py:657-715` and `mk/tools-health.mk:162-164`. Each self-test gains a planted non-address name.
2. A rename tool writes `alias = 0xADDR;` with its `// basis:` line into `config/symbols.<prog>.txt`. It rewrites
   definitions, calls, prototypes and `INCLUDE_ASM` names. It also rewrites the `define` fields of
   `config/dedup_registry.txt`, the `src/shared` file names and `THIRD_PARTY.md` (through `x4port.py --credits`).
   It never touches generated assembly (G6). It writes `config/x4/renames.tsv` old-to-new, so journal history stays
   searchable. Executable symbols referenced from overlays are renamed in every overlay's files (C0125).
3. Gate: a clean fleet N of N. A rename is byte-neutral, so any difference is a missed reference.
4. Rename-coverage scanner.
5. Ghidra mirror by script: `label` records with `func:true` through `ImportAnnotations.java`, round-trip green.
"""
DOC_TEXT = dict(title="X4 names for shared X6 code", tool="tools/mmx6/x4names.py",
                note=" Prior-art row: `docs/prior-art.md` L5a.", lookup="alias text | func_8XXXXXXX | PROG:0xVRAM",
                tail=PHASE_1_10)
# x4core.doc's header prose (shared with mmx5, byte-identical: never edited here), rewritten for the style gate
# (psxd_publish.py style): (core text, this repo's text). Each core text must match once, else doc() refuses.
_W, _G = x4core.MIN_WORDS, GAME
DOC_HEAD = (
    ("--doc` from `config/x4/names.tsv`; never hand-edited.", "--doc` from `config/x4/names.tsv`. Never hand-edited."),
    (f"A `gate` or `bytes`\nrow is an {_G} function of {_W} words or more whose compiled body equals an mmx4 function "
     f"under {_G}'s compiler: its\nonly partner, or partners that all carry one name (`same-name <n>` in the basis), "
     "or the one partner the\nrelocation slots of other aliased functions point at (`slot <n>`). The name is an alias: "
     "a search key for the\n",
     f"A `gate` or `bytes`\nrow is an {_G} function of {_W} words or more. Its compiled body equals an mmx4 function "
     f"under {_G}'s compiler.\n\nThat function is its only partner, or one of partners that all carry one name "
     "(`same-name <n>` in the basis).\nOtherwise it is the one partner the relocation slots of other aliased "
     "functions point at (`slot <n>`).\nThe name is an alias: a search key for the "),
    ("- scope `object`: the mmx4 source is one object's file; identical bytes do not prove the same role, so the\n"
     "  name stays an alias until a role basis exists.",
     "- scope `object`: the mmx4 source is one object's file. Identical bytes do not prove the same role. The\n"
     "  name stays an alias until a role basis exists."),
)


def doc():
    """x4core.doc over this adapter, then DOC_HEAD's rewrites of the core's header prose (DOC is regenerated whole)."""
    rc = x4core.doc(sys.modules[__name__])
    text = DOC.read_text()
    for old, new in DOC_HEAD:
        if text.count(old) != 1:
            sys.exit(f"{TAG} doc refused: x4core header text changed, DOC_HEAD needs a new match for {old[:40]!r}")
        text = text.replace(old, new)
    with open(DOC, "w", newline="\n") as f:
        f.write(text)
    return rc


# ---- the toolchain ---------------------------------------------------------------------------------------------------

def triple(name):
    if name is None:
        cflags = triple(DEFAULT["row"])["cflags"]
        return dict(DEFAULT, cflags=cflags)
    for line in open(TRIPLES):
        f = [x.strip() for x in line.split("|")]
        if line.startswith("#") or f[0] != name:
            continue
        kv = dict(x.split(": ", 1) for x in f[1:])
        return dict(name=name, cc1=kv["cc1"], cflags=kv["cflags"], maspsx=kv["maspsx"])
    sys.exit(f"x4share: no row {name} in {TRIPLES}")


def tools(t):
    """The cc1 and maspsx commands of x4core.compile_one for triple row t (cpp and the assembler: mmx4's, the core's)."""
    return {"cc1": [t["cc1"]] + t["cflags"].split(), "maspsx": ["maspsx"] + t["maspsx"].split()}


# ---- the game's functions --------------------------------------------------------------------------------------------

def corpus():
    """{(prog, vram): build/corpus/functions.jsonl row}."""
    out = {}
    with open(ROOT / CORPUS) as f:
        for line in f:
            if line.strip():
                r = json.loads(line)
                out[(r["prog"], r["vram"])] = r
    return out


def game(x6, rows):
    """x4core.write_partners' game side: x6 = the sigs.jsonl signatures, rows = corpus()."""
    for s in x6:
        r = rows.get((s["prog"], s["vram"]), {})
        yield s["prog"], int(s["vram"], 16), r.get("name", "-"), s["words"], s["exact"], r.get("state", "-")


# ---- tier gate: the attributed src/shared files ----------------------------------------------------------------------

def attributed(shared):
    """(key prefixes, defined function names) of the src/shared files that carry the mmx4 attribution header."""
    import x4port  # ADAPTED (imported here: x4port imports x4share, which imports this module)
    keys, names = set(), set()
    for f in sorted(Path(shared).rglob("*.c")):
        text = f.read_text()
        head = text.split("*/", 1)[0]  # the leading comment, reflow-proof (as x4port.credits)
        m = x4port.ADAPTED.match(" ".join(head.split()))
        if not m:
            continue
        if m.group(3):
            keys.add(m.group(3).lower())
        names.update(DEFINED.findall(text))
    return keys, names


def banked_by(att):
    """partner-table row -> True when the X6 function is banked in C; att: attributed()'s pair."""
    keys, names = att
    return lambda col: col[8] == "c" or col[2] in names or any(col[4].lower().startswith(k) for k in keys)


def banked(shared=SHARED):
    return banked_by(attributed(shared))


# ---- game objects: the X6 side of the relocation-slot pairing --------------------------------------------------------

def exe_range():
    """[lo, hi) of the executable's allocated sections (build/SLUS_013.95.elf)."""
    secs = [s for s in x4core.Elf(f"build/{EXE}.elf").secs if s[2] & 2 and s[5] and s[3] >= x4core.RAM[0]]
    return min(s[3] for s in secs), max(s[3] + s[5] for s in secs)


class Build:
    """The X6 side of the pairing: objects, linked symbols, the executable's range."""

    def __init__(self):
        self.elfs, self.addrs = {}, {}
        self.idx = census.asm_index() if os.path.isdir("asm") else {}
        self.lo, self.hi = exe_range()

    def elf(self, path):
        if path not in self.elfs:
            self.elfs[path] = x4core.Elf(path)
        return self.elfs[path]

    def addr(self, prog):
        import x4port  # Addrs
        if prog not in self.addrs:
            self.addrs[prog] = x4port.Addrs(prog)
        return self.addrs[prog]

    def x6sym(self, prog, a, text):
        name, fresh = self.addr(prog).name(a, text)
        return "-" if fresh else name

    def votes(self, row, x4obj, xf, voter, tamper=None):
        """The votes of one anchor (corpus row row, X4 function xf of x4obj), or raise x4core.Skip."""
        o6 = census.obj_of(row, self.idx)
        if not o6 or not os.path.isfile(o6) or not os.path.isfile(x4obj):
            raise x4core.Skip(f"no object {o6} | {x4obj}")
        r4 = self.elf(x4obj).refs(xf, row["words"])
        r6 = self.elf(o6).refs(row["name"], row["words"])
        if tamper:
            r4 = tamper(r4)
        prog = row["prog"]
        return [(EXE if self.lo <= a < self.hi else prog, a, jump, sym, voter)
                for a, jump, sym in x4core.pair(r4, r6, self.addr(prog).addr)]


def slots():
    return Build()


def widen_inputs():
    return OBJROOT, CORPUS, str(PARTNERS), f"build/{EXE}.elf"


# ---- the Ghidra plate-comment mirror ---------------------------------------------------------------------------------

COMMENT_KINDS = ["eol", "pre", "post", "plate", "repeat"]  # ExportAnnotations.java comments(): the sort's kind index


def ghidra(prog, out):
    src = GHIDRA / f"{prog}.jsonl"
    lines = src.read_text().splitlines() if src.is_file() else []
    plate = {}
    for i, line in enumerate(lines):
        if '"k":"comment"' in line:
            r = json.loads(line)
            if r.get("type") == "plate":
                plate[int(r["addr"], 16)] = i
    new = appended = kept = 0
    aliases = x4core.ghidra_aliases(NAMES, prog)
    for _, vram, text in aliases:
        i = plate.get(int(vram, 16))
        if i is None:
            plate[int(vram, 16)] = len(lines)
            lines.append(json.dumps({"k": "comment", "addr": vram.lower(), "type": "plate", "text": text},
                                    separators=(",", ":"), ensure_ascii=False))
            new += 1
            continue
        r = json.loads(lines[i])
        if text in r["text"].split("\n"):
            kept += 1
            continue
        r["text"] += "\n" + text
        lines[i] = json.dumps(r, separators=(",", ":"), ensure_ascii=False)
        appended += 1
    # The export's byte order (ExportAnnotations.java): one comment block sorted by (address, kind), and a function's
    # own comment is the plate comment at its entry (the func record's last field).
    text_at = {a: json.loads(lines[i])["text"] for a, i in plate.items()}
    com = [i for i, x in enumerate(lines) if x.startswith('{"k":"comment"')]
    recs = sorted((lines[i] for i in com), key=lambda x: (int(json.loads(x)["addr"], 16),
                                                           COMMENT_KINDS.index(json.loads(x)["type"])))
    first = min(com) if com else len(lines)
    lines = [x for i, x in enumerate(lines) if i not in set(com)]
    lines[first:first] = recs
    touched = {int(vram, 16) for _, vram, _ in aliases}
    for i, x in enumerate(lines):
        if x.startswith('{"k":"func"') and int(json.loads(x)["addr"], 16) in touched:
            lines[i] = x[:x.rindex(',"comment":')] + ',"comment":' + \
                json.dumps(text_at[int(json.loads(x)["addr"], 16)], ensure_ascii=False) + "}"
    os.makedirs(os.path.dirname(os.path.abspath(out)), exist_ok=True)
    with open(out, "w", newline="\n") as f:
        f.write("".join(x + "\n" for x in lines))
    print(f"{TAG} ghidra {prog} {len(aliases)} aliases: {new} new plate comments, {appended} appended, "
          f"{kept} already there")
    return 0


SYMBOL = re.compile(r"^(\w+) = (0x[0-9A-Fa-f]+);(.*)$")  # config/symbols.<prog>.txt: `name = 0xADDR; // attrs`
BASIS = "// basis: "


def renamed(prog):
    """[(vram int, name, basis text, is_func)] of config/symbols.<prog>.txt: annotated names != func_/D_<ADDR>."""
    out, prev = [], ""
    for line in (ROOT / f"config/symbols.{prog}.txt").read_text().splitlines():
        m = SYMBOL.match(line)
        if m:
            a = int(m.group(2), 16)
            if prev.startswith(BASIS) and not re.fullmatch(r"(func|D)_%08X" % a, m.group(1), re.I):
                out.append((a, m.group(1), prev[len(BASIS):], "type:func" in m.group(3)))
        prev = line
    return out


def mirror_one(prog, out):
    lines = (GHIDRA / f"{prog}.jsonl").read_text().splitlines()
    head = [x for x in lines if x.startswith('{"k":"program"')]
    funcs = {int(json.loads(x)["addr"], 16) for x in lines if x.startswith('{"k":"func"')}
    plate = {}
    for x in lines:
        if x.startswith('{"k":"comment"'):
            r = json.loads(x)
            if r["type"] == "plate":
                plate[int(r["addr"], 16)] = r["text"]
    n = dict(new=0, appended=0, kept=0)

    def merge(a, text):  # the full plate text at a with text as one of its lines
        cur = plate.get(a)
        if cur is None:
            plate[a], k = text, "new"
        elif text in cur.split("\n"):
            k = "kept"
        else:
            plate[a], k = cur + "\n" + text, "appended"
        n[k] += 1
        return plate[a]

    def rec(d):
        return json.dumps(d, separators=(",", ":"), ensure_ascii=False)

    body, made = [], 0
    ren = renamed(prog)
    for a, name, basis, is_func in ren:
        addr, text = f"0x{a:08x}", merge(a, basis)
        if is_func and a not in funcs:
            body.append(rec({"k": "func", "addr": addr, "name": name, "ret": "/undefined", "cc": "unknown",
                             "varargs": False, "noreturn": False, "inline": False, "custom": False, "sigsrc": "DEFAULT",
                             "params": [], "locals": [], "comment": text}))
            made += 1
        body.append(rec({"k": "label", "addr": addr, "name": name, "primary": True, "src": "USER_DEFINED",
                         "func": is_func or a in funcs}))
        body.append(rec({"k": "comment", "addr": addr, "type": "plate", "text": text}))
    done = {a for a, *_ in ren}
    for _, vram, line in x4core.ghidra_aliases(NAMES, prog):
        a = int(vram, 16)
        if a in done:
            continue
        body.append(rec({"k": "comment", "addr": f"0x{a:08x}", "type": "plate", "text": merge(a, line)}))
    # a later line at the same address carries the merged text of all; keep only the last plate record per address
    last = {}
    for i, x in enumerate(body):
        if x.startswith('{"k":"comment"'):
            last[json.loads(x)["addr"]] = i
    body = [x for i, x in enumerate(body) if not x.startswith('{"k":"comment"') or last[json.loads(x)["addr"]] == i]
    with open(out / f"{prog}.jsonl", "w", newline="\n") as f:
        f.write("".join(x + "\n" for x in head + body))
    print(f"{TAG} mirror {prog} {len(ren)} renames ({made} new funcs): {n['new']} new plate comments, "
          f"{n['appended']} appended, {n['kept']} already there")


def mirror(out):
    import subprocess
    out = Path(out)
    os.makedirs(out, exist_ok=True)
    listed = subprocess.run(["bash", str(ROOT / "tools/mmx6/ghidra/import.sh"), "--list"], capture_output=True,
                            text=True, check=True).stdout
    progs = [EXE] + [x.split()[0] for x in listed.splitlines() if x.strip()]
    for prog in progs:
        mirror_one(prog, out)
    print(f"{TAG} mirror {len(progs)} programs -> {out}")
    return 0


def main(argv):
    if len(argv) == 4 and argv[0] == "--ghidra" and argv[2] == "--out":
        return ghidra(argv[1], argv[3])
    if len(argv) == 3 and argv[0] == "--mirror" and argv[1] == "--out":
        return mirror(argv[2])
    print(__doc__.strip(), file=sys.stdout if argv in (["--help"], ["-h"]) else sys.stderr)
    return 0 if argv in (["--help"], ["-h"]) else 2


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
