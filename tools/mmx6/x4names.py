#!/usr/bin/env python3
"""x4names.py -- X4 names as aliases for X6 addresses, from the proven X4 partnerships (stdlib; host, except --widen).

  x4names.py --build
      -> reads campaign/x4/partners.tsv and the line-1 headers of src/shared/**/*.c (x4port.ADAPTED); admits a row
         when its X4 name is real (not func_8XXXXXXX), it has exactly one X4 partner and it is 8 words or more;
         writes campaign/x4/names.tsv, sorted by (prog, vram, kind), tab-separated, NO header row (so the row count of
         the last line equals `wc -l`):
             prog  vram  kind  x6name  alias  tier  scope  votes  basis
         kind   func | data (--widen only)
         tier   gate   the X6 function is banked in C (partners state `c`, or its key / its name as a defined
                       function is in an attributed src/shared file): proven-at-gate
                bytes  exact signature, body still assembly: consistent-with-bytes
         scope  object the mmx4 source sits under mains/ items/ effects/ layers/ misc/ weapons/ visuals/ quads/
                       (an alias only, held back from renames until a role basis exists); else engine
         votes  -
         basis  x4 exact <key12> sozud/mmx4@<pin> <mmx4 path>:<function>
         The host cannot recompute the rows --widen added (tier `slot`, or a basis ending ` same-name <n>` /
         ` slot <n>`): --build recomputes the exact rows and carries those forward verbatim from the existing
         names.tsv, printing `X4NAMES carried <n> widened rows` before the last line.
         last line: X4NAMES <rows> rows; gate <g> bytes <b> slot <s>; engine <e> object <o>; func <f> data <d>
  x4names.py --widen
      -> container only (the build, build/corpus/functions.jsonl, the mmx4 clone .run/mmx4 at the pin and its objects
         .run/x4share/gcc2.95.2-psx-aspsx2.86/obj/, i.e. after `x4share.py --triple ... --partners`); the only writer
         of the widened rows. names.tsv = the --build rows plus two sources:
         2a full partner list: the key -> partners map of x4share.write_partners with every partner kept; a
            multi-partner class whose partners all carry one real name is admitted (basis gains ` same-name <n>`).
         2b relocation-slot votes: per anchor (an X6 function with an alias from --build or 2a) the relocations of
            its X4 object and its X6 object are paired word by word (x4port.Elf.refs, x4port.Addrs); each pair is one
            vote "this X6 address is that X4 symbol" (address = the base of the X4 symbol; an address inside the
            executable is filed under SLUS_013.95 whatever the anchor's program). A vote's voter is the anchor's X4
            function, so the copies of one function in several overlays count once. Admitted: >= 2 distinct voters
            name the address, with one name, and that name is on no other address of the program.
            - a multi-partner class with that name among its partners: tier gate|bytes, votes <n>/0, basis gains
              ` slot <n>`
            - else tier `slot` (a lead, never a rename by itself): kind func (jump slot, or a corpus function) or
              data; x6name = the build's symbol at that address or `-`; scope from the one mmx4 file whose object
              defines the symbol, else `-`; votes <agree>/<disagree>; basis
              `x4 slot <agree>/<disagree> sozud/mmx4@<pin> <symbol>`
            An address with two X4 names, an X4 name on two addresses of one program, or a slot name against an
            exact alias gives no slot alias and one line of .run/x4names/conflicts.log.
         Intermediates (.run/x4names/{partners.full.tsv,votes.tsv,conflicts.log}) are never pulled or tracked.
         Lines `X4NAMES anchors <a> unpaired <u>; votes <v> on <n> addresses, admitted <m>`, `X4NAMES conflicts <n>`,
         then the count line.
  x4names.py --x4-exe
      -> container only, with the X4 medium mounted at /disc (MX6_DISC_VOLUME=mmx4-disc): reads SLUS_005.61 out of
         the image with the ISO reader of extract.py (parse_cue, iso9660.walk, iso9660.extract_file) and writes it
         to .run/x4/SLUS_005.61 only when its sha1 equals the one the mmx4 clone records for the US executable
         (.run/mmx4/check.us.txt). No hash is printed or tracked; nothing leaves .run/. Lines
         `X4NAMES x4-exe check.us.txt <same|differs>, splat yaml <same|differs|absent>`, then `X4NAMES x4-exe sha1 match`
         (rc 0) or `X4NAMES x4-exe sha1 MISMATCH` (rc 1, nothing written)
  x4names.py --data-probe
      -> container only, after --x4-exe; a measurement, writes nothing tracked. For each sized (`size:`) symbol of
         the clone's config/symbols.us.txt: refused when its name is address-spelled, it lies outside the loaded
         image of SLUS_005.61 (bss), it is under 16 bytes, it is constant fill, or one of its address-aligned 32-bit
         little-endian words lies in 0x80010000-0x801FFFFF (a pointer: X4-specific content). The bytes of each
         candidate are searched in the loaded section of every build/*.elf; exactly one occurrence in a program is a
         unique hit there. .run/x4names/data-probe.tsv (prog, address, symbol, length; never pulled) lists them.
         Lines `X4NAMES data-funnel sized <n>; dropped draft-name <a> outside <b> short <c> fill <d> address <e>;
         multi-hit <m> no-hit <z>; unique at <p> (program, address, symbol)`, then the last line
         `X4NAMES data-probe <hits> unique of <candidates>` (hits = candidates unique in at least one program).
         Measured 2026-10-11: `X4NAMES data-probe 6 unique of 76`, below the 20-hit bar: the content lane is not
         built and --widen adds no `content` row (docs/prior-art.md L5a)
  x4names.py --who <text>
      -> the rows of names.tsv whose alias contains <text>, whose X6 name is <text>, or whose address is <text>
         written prog:0xVRAM; one line and rc 1 when nothing matches
  x4names.py --doc
      -> (re)writes docs/x4-names.md from names.tsv: the aliases grouped by mmx4 source file, the tier `slot` rows
         as leads, and `## For phase 1.10`
  x4names.py --self-test
      -> planted table in .run/x4names-selftest/: a two-partner row, a func_8 partner and a 7-word row are each
         refused, one good row is admitted with its tier and scope. 2a: a planted class whose partners share one
         name is admitted, one with two names refused. 2b: two agreeing voters name a callee and a global and
         resolve a two-name class; one disagreeing voter removes them. data_probe (planted bytes): a datum
         with one occurrence is a unique hit, two occurrences in one program are refused, constant fill and an
         address-looking word are refused. slot_objects (container: needs
         build/src/SLUS_013.95/120A0.c.o and the corpus; on the host `X4NAMES CASE slot_objects skipped no-objects`):
         a renamed copy of our own object as the X4 side through the real relocation pairing. Ends
         `X4NAMES CONTROL OK`, rc 1 on any miss
"""
import hashlib
import os
import re
import shutil
import struct
import subprocess
import sys
from pathlib import Path

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import census  # noqa: E402  (asm_index, obj_of)
import sig  # noqa: E402  (sig_of)
import x4port  # noqa: E402  (ADAPTED, PIN, TRIPLE, FUNCS, Elf, Addrs, Skip, jl)
import x4share  # noqa: E402  (functions, CLONE, SCR)

ROOT = Path(__file__).resolve().parents[2]
PARTNERS = ROOT / "campaign/x4/partners.tsv"
SHARED = ROOT / "src/shared"
NAMES = ROOT / "campaign/x4/names.tsv"
DOC = ROOT / "docs/x4-names.md"
SELFTEST = ROOT / ".run/x4names-selftest"
SCRATCH = ROOT / ".run/x4names"  # --widen intermediates: container only, never pulled or tracked
EXE = "SLUS_013.95"
X4EXE = ROOT / ".run/x4/SLUS_005.61"  # --x4-exe output: container only, never pulled or tracked
SELF_OBJ, SELF_TU = "build/src/SLUS_013.95/120A0.c.o", "120A0"

DRAFT = re.compile(r"^func_8[0-9A-Fa-f]{7}$")
OBJECT_DIRS = frozenset("mains items effects layers misc weapons visuals quads".split())
MIN_WORDS = 8
MIN_VOTERS = 2
WIDENED = re.compile(r" (?:same-name|slot) \d+$")  # the basis suffix of an exact row only --widen can compute
X4DRAFT = re.compile(r"^[A-Za-z]{0,6}_?8[0-9A-Fa-f]{7}$")  # an address-spelled mmx4 symbol: votes, never names
RAM = (0x80010000, 0x80200000)
MIN_DATA = 16  # bytes: the shortest X4 datum searched by content
X4SYM = re.compile(r"^(\w+)\s*=\s*0x([0-9A-Fa-f]+);\s*//.*\bsize:(0x[0-9A-Fa-f]+|\d+)")
DATA_WHY = ("draft-name", "outside", "short", "fill", "address")
# a function definition at column 0: `<type words> name(<params>) {`
DEFINED = re.compile(r"^\w[^;{}()\n]*?\b(\w+)\s*\([^;{}]*\)\s*\{", re.M)


def attributed(shared):
    """(key prefixes, defined function names) of the src/shared files that carry the mmx4 attribution header."""
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


def refusal(x4name, partners, words):
    """'' when the row is admitted, else the reason."""
    if DRAFT.match(x4name):
        return "draft-name"
    if partners != 1:
        return f"partners {partners}"
    if words < MIN_WORDS:
        return f"words {words}"
    return ""


def partner_cols(partners):
    out = []
    for n, line in enumerate(Path(partners).read_text().splitlines(), 1):
        if not line:
            continue
        col = line.split("\t")
        if len(col) != 9:
            sys.exit(f"x4names: {partners}:{n}: {len(col)} columns, 9 expected")
        out.append(col)
    return out


def scope_of(x4src):
    return "object" if OBJECT_DIRS & set(x4src.split("/")[:-1]) else "engine"


def exact_row(col, x4src, x4name, suffix, votes, att):
    """The names.tsv row of partners.tsv row col under the mmx4 partner x4src:x4name."""
    prog, vram, x6name, _, key, _, _, _, state = col
    keys, names = att
    key = key.lower()
    banked = state == "c" or x6name in names or any(key.startswith(k) for k in keys)
    basis = f"x4 exact {key[:12]} sozud/mmx4@{x4port.PIN} {x4src}:{x4name}{suffix}"
    return (prog, vram, "func", x6name, x4name, "gate" if banked else "bytes", scope_of(x4src), votes, basis)


def order(r):
    return (r[0], int(r[1], 16), r[2])


def rows_of(partners, shared):
    att = attributed(shared)
    out = []
    for col in partner_cols(partners):
        if refusal(col[6], int(col[7]), int(col[3])):
            continue
        out.append(exact_row(col, col[5], col[6], "", "-", att))
    out.sort(key=order)
    return out


def count_line(rows):
    def n(i, v):
        return sum(1 for r in rows if r[i] == v)
    return (f"X4NAMES {len(rows)} rows; gate {n(5, 'gate')} bytes {n(5, 'bytes')} slot {n(5, 'slot')}; "
            f"engine {n(6, 'engine')} object {n(6, 'object')}; func {n(2, 'func')} data {n(2, 'data')}")


def write_names(names, rows):
    with open(names, "w", newline="\n") as f:
        f.write("".join("\t".join(r) + "\n" for r in rows))


def widened(r):
    return r[5] == "slot" or bool(WIDENED.search(r[8]))


def build(partners, shared, names):
    rows = rows_of(partners, shared)
    have = {(r[0], r[1]) for r in rows}
    # the rows only --widen can compute are carried forward verbatim
    carried = [r for r in (load(names) if os.path.isfile(names) else []) if widened(r) and (r[0], r[1]) not in have]
    rows = sorted(rows + carried, key=order)
    write_names(names, rows)
    print(f"X4NAMES carried {len(carried)} widened rows")
    print(count_line(rows))
    return rows


# ---- --widen: 2a full partner list, 2b relocation-slot votes ----------------------------------------------------------

def pick(ps):
    """(src, name, basis suffix) of a sorted partner list whose members all carry one name, else None (2a)."""
    if not ps or len({n for _, n in ps}) != 1:
        return None
    return ps[0][0], ps[0][1], "" if len(ps) == 1 else f" same-name {len(ps)}"


def pair(r4, r6, addr_of):
    """[(X6 address of the X4 symbol's base, jump slot, X4 symbol)] of the word-aligned relocation pairs of one
    anchor (r4, r6: x4port.Elf.refs of the X4 and the X6 function; the loop of x4port.port)."""
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


def merge(exact, pending, admitted, by_key, x6sym, defs, funcs, att):
    """exact: {(prog, vram): row} of the --build and 2a rows; pending: {(prog, vram): partners.tsv row} of the X6
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
                rows[pv] = exact_row(col, named[0][0], sym, f" slot {n}", f"{n}/0", att)
                continue
        kind = "func" if jump or pv in funcs else "data"
        srcs = sorted(defs.get(sym, ()))
        rows[pv] = (prog, pv[1], kind, x6sym(prog, a, kind == "func"), sym, "slot",
                    scope_of(srcs[0]) if len(srcs) == 1 else "-", f"{n}/0",
                    f"x4 slot {n}/0 sozud/mmx4@{x4port.PIN} {sym}")
    return sorted(rows.values(), key=order), conflicts


def partner_map(objroot):
    """(exact key -> {(mmx4 src, func)}, symbol -> {mmx4 src defining it}) over every X4 object (the map of
    x4share.write_partners, every partner kept)."""
    by_key, defs = {}, {}
    for o in sorted(Path(objroot).rglob("*.o")):
        src = str(o.relative_to(objroot))[:-2]
        for name, w, m in x4share.functions(str(o)):
            by_key.setdefault(sig.sig_of("X4", name, w, m)["exact"], set()).add((src, name))
        e = x4port.Elf(str(o))
        for name, _, _, info, sh in e.syms:
            if name and name[0] not in ".$" and info & 0xF in (0, 1, 2) and (0 < sh < len(e.secs) or sh == 0xFFF2):
                defs.setdefault(name, set()).add(src)
    return by_key, defs


def exe_range():
    """[lo, hi) of the executable's allocated sections (build/SLUS_013.95.elf)."""
    secs = [s for s in x4port.Elf(f"build/{EXE}.elf").secs if s[2] & 2 and s[5] and s[3] >= RAM[0]]
    return min(s[3] for s in secs), max(s[3] + s[5] for s in secs)


class Build:
    """The X6 side of the pairing: objects, linked symbols, the executable's range."""

    def __init__(self):
        self.elfs, self.addrs = {}, {}
        self.idx = census.asm_index() if os.path.isdir("asm") else {}
        self.lo, self.hi = exe_range()

    def elf(self, path):
        if path not in self.elfs:
            self.elfs[path] = x4port.Elf(path)
        return self.elfs[path]

    def addr(self, prog):
        if prog not in self.addrs:
            self.addrs[prog] = x4port.Addrs(prog)
        return self.addrs[prog]

    def x6sym(self, prog, a, text):
        name, fresh = self.addr(prog).name(a, text)
        return "-" if fresh else name

    def votes(self, row, x4obj, xf, voter, tamper=None):
        """The votes of one anchor (corpus row row, X4 function xf of x4obj), or raise x4port.Skip."""
        o6 = census.obj_of(row, self.idx)
        if not o6 or not os.path.isfile(o6) or not os.path.isfile(x4obj):
            raise x4port.Skip(f"no object {o6} | {x4obj}")
        r4 = self.elf(x4obj).refs(xf, row["words"])
        r6 = self.elf(o6).refs(row["name"], row["words"])
        if tamper:
            r4 = tamper(r4)
        prog = row["prog"]
        return [(EXE if self.lo <= a < self.hi else prog, a, jump, sym, voter)
                for a, jump, sym in pair(r4, r6, self.addr(prog).addr)]


def widen():
    os.chdir(ROOT)
    objroot = f"{x4share.SCR}/{x4port.TRIPLE}/obj"
    for p in (objroot, x4port.FUNCS, str(PARTNERS), f"build/{EXE}.elf"):
        if not os.path.exists(p):
            sys.exit(f"x4names: {p} missing (--widen runs in the container, after x4share.py --partners)")
    head = subprocess.run(["git", "-C", x4share.CLONE, "rev-parse", "--short", "HEAD"], capture_output=True,
                          text=True).stdout.strip()
    if head != x4port.PIN:
        sys.exit(f"x4names: {x4share.CLONE} at {head or 'absent'}, pinned {x4port.PIN}")
    by_key, defs = partner_map(objroot)
    att = attributed(SHARED)
    corpus = {(r["prog"], r["vram"]): r for r in x4port.jl(x4port.FUNCS)}
    exact, pending, anchors = {}, {}, []
    for col in partner_cols(PARTNERS):
        ps = sorted(by_key.get(col[4], ()))
        if len(ps) != int(col[7]) or ps[0] != (col[5], col[6]):
            sys.exit(f"x4names: {PARTNERS.name} {col[0]} {col[1]} disagrees with the X4 objects (rerun x4share.py)")
        p = pick(ps)
        if p and not refusal(p[1], 1, int(col[3])):
            exact[(col[0], col[1])] = exact_row(col, p[0], p[1], p[2], "-", att)
            anchors.append((col, p[0], p[1]))
        else:
            pending[(col[0], col[1])] = col
    b = Build()
    votes, unpaired = [], 0
    for col, src, xf in anchors:
        row = corpus.get((col[0], col[1]))
        try:
            if row is None or row["words"] != int(col[3]):
                raise x4port.Skip("no corpus row")
            votes += b.votes(row, f"{objroot}/{src}.o", xf, f"{src}:{xf}")
        except x4port.Skip:
            unpaired += 1
    admitted, c1 = tally(votes)
    rows, c2 = merge(exact, pending, admitted, by_key, b.x6sym, defs, set(corpus), att)
    conflicts = sorted(c1 + c2)
    os.makedirs(SCRATCH, exist_ok=True)
    with open(SCRATCH / "partners.full.tsv", "w") as f:
        for col in partner_cols(PARTNERS):
            for src, name in sorted(by_key[col[4]]):
                f.write(f"{col[0]}\t{col[1]}\t{col[4]}\t{src}\t{name}\n")
    with open(SCRATCH / "votes.tsv", "w") as f:
        for prog, a, jump, sym, voter in sorted(votes):
            f.write(f"{prog}\t0x{a:08X}\t{'jump' if jump else 'addr'}\t{sym}\t{voter}\n")
    with open(SCRATCH / "conflicts.log", "w") as f:
        for kind, prog, a, what in conflicts:
            f.write(f"{kind}\t{prog}\t0x{a:08X}\t{what}\n")
    write_names(NAMES, rows)
    print(f"X4NAMES anchors {len(anchors)} unpaired {unpaired}; votes {len(votes)} on "
          f"{len({(v[0], v[1]) for v in votes})} addresses, admitted {len(admitted)}")
    print(f"X4NAMES conflicts {len(conflicts)}")
    print(count_line(rows))
    return 0


# ---- 2c: the X4 executable off the medium, data tables by content (measured, lane not built) -------------------------

def x4_exe():
    import extract  # the ISO reader (parse_cue, iso9660); imported here: the host modes do not need it
    os.chdir(ROOT)
    cues = sorted(Path("/disc").glob("*.cue"))
    if len(cues) != 1:
        sys.exit(f"x4names: {len(cues)} *.cue at /disc (--x4-exe runs in the container with MX6_DISC_VOLUME=mmx4-disc)")
    with extract.parse_cue(cues[0]).open("rb") as f:
        e = next((e for e in extract.iso9660.walk(f) if e.path == X4EXE.name), None)
        if e is None:
            sys.exit(f"x4names: {X4EXE.name} not on the medium at /disc")
        data = extract.iso9660.extract_file(f, e)
    got = hashlib.sha1(data).hexdigest()
    check = Path(x4share.CLONE, "check.us.txt").read_text().split()[0].lower()
    m = re.search(r"^\s*sha1:\s*([0-9A-Fa-f]{40})", Path(x4share.CLONE, f"config/{X4EXE.name}.splat.yaml").read_text(),
                  re.M)
    same = lambda h: "same" if h == got else "differs" if h else "absent"
    print(f"X4NAMES x4-exe check.us.txt {same(check)}, splat yaml {same(m.group(1).lower() if m else '')}")
    if got != check:
        print("X4NAMES x4-exe sha1 MISMATCH")
        return 1
    os.makedirs(X4EXE.parent, exist_ok=True)
    X4EXE.write_bytes(data)
    print("X4NAMES x4-exe sha1 match")
    return 0


def data_refusal(name, addr, blob):
    """'' when the X4 datum (its bytes, None outside the loaded image) is a content candidate, else the reason."""
    if X4DRAFT.match(name):
        return "draft-name"
    if blob is None:
        return "outside"
    if len(blob) < MIN_DATA:
        return "short"
    if len(set(blob)) == 1:
        return "fill"
    for o in range(-addr % 4, len(blob) - 3, 4):
        if RAM[0] <= struct.unpack_from("<I", blob, o)[0] < RAM[1]:
            return "address"
    return ""


def probe(syms, images):
    """syms: [(name, X4 address, bytes | None)]; images: {prog: [(address, bytes)]}.
    -> (unique [(prog, address, name, length)], funnel {reason: symbols}); a datum with two occurrences in a
    program gives nothing there."""
    unique, funnel = [], dict.fromkeys(DATA_WHY + ("candidates", "multi-hit", "no-hit", "hits"), 0)
    for name, addr, blob in sorted(syms):
        why = data_refusal(name, addr, blob)
        if why:
            funnel[why] += 1
            continue
        funnel["candidates"] += 1
        seen = one = 0
        for prog in sorted(images):
            at = []
            for a, b in images[prog]:
                i = b.find(blob)
                while i >= 0:
                    at.append(a + i)
                    i = b.find(blob, i + 1)
            seen += len(at)
            if len(at) == 1:
                one += 1
                unique.append((prog, at[0], name, len(blob)))
        funnel["hits" if one else "multi-hit" if seen else "no-hit"] += 1
    return sorted(unique), funnel


def data_probe():
    os.chdir(ROOT)
    syms4 = Path(x4share.CLONE, "config/symbols.us.txt")
    for p in (X4EXE, syms4, f"build/{EXE}.elf"):
        if not os.path.exists(p):
            sys.exit(f"x4names: {p} missing (--data-probe runs in the container, after --x4-exe)")
    exe = X4EXE.read_bytes()
    t_addr, t_size = struct.unpack_from("<II", exe, 0x18)  # PS-X EXE: 0x800-byte header, then t_size bytes at t_addr
    syms = []
    for line in syms4.read_text().splitlines():
        m = X4SYM.match(line)
        if m:
            a, n = int(m.group(2), 16), int(m.group(3), 0)
            inside = t_addr <= a and a + n <= t_addr + min(t_size, len(exe) - 0x800)
            syms.append((m.group(1), a, exe[0x800 + a - t_addr:0x800 + a - t_addr + n] if inside else None))
    images = {}
    for path in sorted(Path("build").glob("*.elf")):
        e = x4port.Elf(str(path))
        images[path.stem] = [(s[3], e.b[s[4]:s[4] + s[5]]) for s in e.secs if s[1] == 1 and s[2] & 2 and s[3] >= RAM[0]]
    unique, fn = probe(syms, images)
    os.makedirs(SCRATCH, exist_ok=True)
    with open(SCRATCH / "data-probe.tsv", "w") as f:
        for prog, a, name, n in unique:
            f.write(f"{prog}\t0x{a:08X}\t{name}\t{n}\n")
    print(f"X4NAMES data-funnel sized {len(syms)}; dropped " + " ".join(f"{w} {fn[w]}" for w in DATA_WHY) +
          f"; multi-hit {fn['multi-hit']} no-hit {fn['no-hit']}; unique at {len(unique)}")
    print(f"X4NAMES data-probe {fn['hits']} unique of {fn['candidates']}")
    return 0


def load(names):
    if not os.path.isfile(names):
        sys.exit(f"x4names: {names} missing (run --build)")
    return [tuple(x.split("\t")) for x in Path(names).read_text().splitlines() if x]


def who(text):
    t = text.lower()
    hits = [r for r in load(NAMES) if t in r[4].lower() or t == r[3].lower() or t == f"{r[0]}:{r[1]}".lower()]
    if not hits:
        print(f"X4NAMES no alias for {text}")
        return 1
    for r in hits:
        print("\t".join(r))
    return 0


PHASE_1_10 = """## For phase 1.10

Handoff for the planner of phase 1.10 (Readability). Nothing here is applied yet: every row above is an alias.

Proposed row amendment:
- Scope gains "X4-proven renames applied by script from `campaign/x4/names.tsv`".
- Milestone gains "every rename-admitted row of names.tsv is applied or listed with a reason; no tool derives an
  address from a symbol's spelling".

Rename admission:
- `kind func` with tier `gate` and scope `engine`.
- `kind data` with tier `slot` and at least 3 agreeing anchors (the `content` tier was measured and not built:
  `X4NAMES data-probe 6 unique of 76`, docs/prior-art.md L5a).
- Everything else stays an alias.

Order of work:
1. Remove name-to-address code: `tools/mmx6/probe.py:105-131`, `tools/mmx6/bound2.py:526`, the `func_` filter at
   `tools/mmx6/cards.py:350`, the address-named self-test constants (`bank.py:61`, `gate.py:73`, `corpus.py:381`,
   `x4port.py:74`, `x4share.py:68`, `carve.py:641`, `mk/tools-health.mk:162-164`); each self-test gains a planted
   non-address name.
2. A rename tool: writes `alias = 0xADDR;` with its `// basis:` line into `config/symbols.<prog>.txt`, rewrites
   definitions, calls, prototypes, `INCLUDE_ASM` names, the `define` fields of `config/dedup_registry.txt`,
   `src/shared` file names and `THIRD_PARTY.md` (through `x4port.py --credits`); never touches generated assembly
   (G6); writes `campaign/x4/renames.tsv` old-to-new so journal history stays searchable. Executable symbols
   referenced from overlays are renamed in every overlay's files (C0125).
3. Gate: clean fleet N of N; a rename is byte-neutral, so any difference is a missed reference.
4. Rename-coverage scanner.
5. Ghidra mirror by script: `label` records with `func:true` through `ImportAnnotations.java`, round-trip green.
"""


def doc():
    rows = load(NAMES)
    groups = {}
    leads = [r for r in rows if r[5] == "slot"]
    for r in rows:
        if r[5] != "slot":
            groups.setdefault(r[8].split(" ")[4].rsplit(":", 1)[0], []).append(r)
    out = [
        "# X4 names for shared X6 code\n",
        "\n",
        "Generated by `tools/mmx6/x4names.py --doc` from `campaign/x4/names.tsv`; never hand-edited.\n",
        "\n",
        f"Each row is an X6 address with a real name from sozud/mmx4 (AGPL-3.0, pin `{x4port.PIN}`). A `gate` or `bytes`\n"
        "row is an X6 function of 8 words or more whose compiled body equals an mmx4 function under X6's compiler: its\n"
        "only partner, or partners that all carry one name (`same-name <n>` in the basis), or the one partner the\n"
        "relocation slots of other aliased functions point at (`slot <n>`). The name is an alias: a search key for the\n"
        "X6 address, not a symbol. Prior-art row: `docs/prior-art.md` L5a.\n",
        "\n",
        "- tier `gate`: the X6 function is banked in C (proven-at-gate).\n",
        "- tier `bytes`: the signature is exact and the body is still assembly (consistent-with-bytes).\n",
        "- tier `slot`: a lead, not a proof. Two or more aliased functions reference this address in the relocation\n"
        "  slot where their mmx4 twin references that symbol, and none says otherwise. Votes are agree/disagree.\n",
        "- scope `object`: the mmx4 source is one object's file; identical bytes do not prove the same role, so the\n"
        "  name stays an alias until a role basis exists. Scope `engine`: everything else.\n",
        "\n",
        f"`{count_line(rows)}`\n",
        "\n",
        "Lookup: `python3 tools/mmx6/x4names.py --who <alias text | func_8XXXXXXX | PROG:0xVRAM>`.\n",
        "\n",
        "## Aliases by mmx4 source file\n",
    ]
    for src in sorted(groups):
        out.append(f"\n### {src}\n\n")
        out.append("| alias | X6 address | X6 name | tier | scope |\n|---|---|---|---|---|\n")
        for r in groups[src]:
            out.append(f"| `{r[4]}` | `{r[0]}:{r[1]}` | `{r[3]}` | {r[5]} | {r[6]} |\n")
    out.append("\n## Leads: tier `slot`\n\nLeads only: named by relocation-slot votes, never a rename by themselves.\n")
    for kind, title in (("func", "Functions (lead)"), ("data", "Globals (lead)")):
        out.append(f"\n### {title}\n\n")
        out.append("| alias (lead) | X6 address | X6 name | votes | scope |\n|---|---|---|---|---|\n")
        for r in leads:
            if r[2] == kind:
                out.append(f"| `{r[4]}` | `{r[0]}:{r[1]}` | `{r[3]}` | {r[7]} | {r[6]} |\n")
    out.append("\n" + PHASE_1_10)
    with open(DOC, "w", newline="\n") as f:
        f.write("".join(out))
    print(f"X4NAMES doc {len(rows)} rows in {len(groups)} mmx4 files, {len(leads)} leads -> {DOC.relative_to(ROOT)}")
    return 0


# planted rows: name, (x6name, words, key, x4src, x4name, partners, state), expected (tier, scope) or None = refused
CASES = (
    ("two_partner", ("func_80010000", 20, "1" * 40, "src/main/player.c", "planted_twice", 2, "c"), None),
    ("draft_partner", ("func_80010100", 20, "2" * 40, "src/main/player.c", "func_80012345", 1, "c"), None),
    ("seven_words", ("func_80010200", 7, "3" * 40, "src/main/player.c", "planted_short", 1, "c"), None),
    ("good", ("func_80010300", 8, "4" * 40, "src/main/weapons/weapon_00_planted.c", "planted_good", 1,
              "include_asm"), ("gate", "object")),
)


def case(name, ok, text):
    print(f"X4NAMES CASE {name} {text}")
    return [] if ok else [name]


def widen_cases():
    """The 2a and 2b planted cases; the names of the failed ones."""
    fails = []
    # 2a: a class whose partners all carry one name is admitted, one with two names is not
    same = pick([("src/main/a.c", "planted_same"), ("src/main/b.c", "planted_same")])
    fails += case("same_name", same == ("src/main/a.c", "planted_same", " same-name 2"),
                  f"admitted {same[1]}{same[2]}" if same else "refused")
    two = pick([("src/main/a.c", "planted_one"), ("src/main/b.c", "planted_other")])
    fails += case("two_names", two is None, "refused two names" if two is None else f"admitted {two[1]}")
    # 2b: two voters name a callee and a global and pick planted_one inside the two-name class
    key = "5" * 40
    col = ["PLANTED", "0x80040000", "func_80040000", "20", key, "src/main/a.c", "planted_one", "2", "asm"]
    by_key = {key: {("src/main/a.c", "planted_one"), ("src/main/b.c", "planted_other")}}
    defs = {"planted_global": {"src/main/weapons/weapon_00_planted.c"}}
    votes = [("PLANTED", a, jump, sym, voter) for voter in ("src/main/a.c:v1", "src/main/b.c:v2")
             for a, jump, sym in ((0x80020000, True, "planted_callee"), (0x80030000, False, "planted_global"),
                                  (0x80040000, True, "planted_one"))]

    def run(vs):
        admitted, c1 = tally(vs)
        rows, c2 = merge({}, {(col[0], col[1]): col}, admitted, by_key, lambda p, a, t: "-", defs, set(),
                         (set(), set()))
        return {r[1]: r for r in rows}, c1 + c2

    got, conf = run(votes)
    want = {"0x80020000": ("func", "planted_callee", "slot", "-", "2/0"),
            "0x80030000": ("data", "planted_global", "slot", "object", "2/0"),
            "0x80040000": ("func", "planted_one", "bytes", "engine", "2/0")}
    ok = not conf and {v: (r[2], r[4], r[5], r[6], r[7]) for v, r in got.items()} == want and \
        got["0x80040000"][8].endswith("src/main/a.c:planted_one slot 2") and \
        all(widened(r) for r in got.values())
    fails += case("slot_agree", ok, " ".join(f"{r[4]} {r[2]} {r[5]} {r[7]}" for _, r in sorted(got.items())) or "none")
    # one disagreeing voter on each address removes all three
    got, conf = run(votes + [("PLANTED", a, a != 0x80030000, "planted_elsewhere_" + str(i), "src/main/c.c:v3")
                             for i, a in enumerate((0x80020000, 0x80030000, 0x80040000))])
    fails += case("slot_disagree", not got and len(conf) == 3, f"rows {len(got)} conflicts {len(conf)}")
    # one name on two addresses of a program removes both
    got, conf = run(votes[:2] + [("PLANTED", 0x80020010, True, "planted_callee", v) for v in ("x:v1", "y:v2")])
    fails += case("slot_two_addresses", not got and len(conf) == 2, f"rows {len(got)} conflicts {len(conf)}")
    return fails + probe_cases() + slot_objects()


def probe_cases():
    """2c on planted bytes: one occurrence is a unique hit; two in one program, constant fill and an address-looking
    word are refused."""
    once, twice = bytes(range(1, 21)), bytes(range(101, 121))
    ptr = bytes(range(1, 13)) + struct.pack("<I", 0x80012345) + bytes(4)
    syms = [("planted_once", 0x80100000, once), ("planted_twice", 0x80100100, twice),
            ("planted_fill", 0x80100200, bytes(20)), ("planted_ptr", 0x80100300, ptr),
            ("planted_bss", 0x80100400, None), ("planted_short", 0x80100500, once[:15]), ("D_80100600", 0x80100600, once)]
    images = {"PLANTED": [(0x80020000, bytes(8) + once + bytes(4) + twice + ptr + twice + bytes(40))]}
    unique, fn = probe(syms, images)
    want = dict.fromkeys(DATA_WHY, 1) | {"candidates": 2, "multi-hit": 1, "no-hit": 0, "hits": 1}
    return case("data_probe", unique == [("PLANTED", 0x80020008, "planted_once", 20)] and fn == want,
                " ".join(f"{name} {n} bytes" for _, _, name, n in unique) + "; " +
                " ".join(f"{k} {fn[k]}" for k in DATA_WHY + ("multi-hit",)))


def slot_objects():
    """The real pairing path on a renamed copy of our own object as the X4 side (C0054, as x4port --self-test)."""
    os.chdir(ROOT)
    if not (os.path.isfile(SELF_OBJ) and os.path.isfile(x4port.FUNCS) and os.path.isfile(f"build/{EXE}.elf")):
        print("X4NAMES CASE slot_objects skipped no-objects")
        return []
    fake = str(SELFTEST / "obj/src/main/120A0.c.o")
    os.makedirs(os.path.dirname(fake))
    raw = bytearray(Path(SELF_OBJ).read_bytes())
    e = x4port.Elf(SELF_OBJ)
    for i, s in enumerate(e.secs):
        if s[1] == 3 and i != struct.unpack_from("<H", raw, 0x32)[0]:  # the symbol string table
            raw[s[4]:s[4] + s[5]] = bytes(raw[s[4]:s[4] + s[5]]).replace(b"\0D_8", b"\0G_g").replace(b"\0func_8",
                                                                                                     b"\0fanc_g")
    Path(fake).write_bytes(raw)

    def back(sym):
        return re.sub(r"^fanc_g", "func_8", re.sub(r"^G_g", "D_8", sym))

    def plain(r4):  # our INCLUDE_ASM objects alias every asm function as <name>.NON_MATCHING; mmx4's have none
        return {i: (t, n.replace(".NON_MATCHING", ""), e) for i, (t, n, e) in r4.items()}

    b = Build()
    rows = [r for r in x4port.jl(x4port.FUNCS) if r["prog"] == EXE and census.obj_of(r, b.idx) == SELF_OBJ]
    votes = []
    for r in rows:
        try:
            votes += b.votes(r, fake, re.sub(r"^func_8", "fanc_g", r["name"]), r["name"], tamper=plain)
        except x4port.Skip:
            pass
    admitted, conf = tally(votes)
    right = all(back(sym) in b.addr(EXE).by_addr.get(a, ()) for (_, a), (sym, _, _) in admitted.items())
    func = next((pa for pa in sorted(admitted) if admitted[pa][2]), None)
    data = next((pa for pa in sorted(admitted) if not admitted[pa][2]), None)
    fails = case("slot_objects", bool(admitted) and right and func is not None and data is not None and not conf,
                 f"{len(rows)} anchors, {len(votes)} votes, admitted {len(admitted)} "
                 f"(every name maps back {right}), conflicts {len(conf)}")
    if func is None or data is None:
        return fails or ["slot_objects"]
    # control: one voter of each of the two addresses renamed on the X4 side -> both gone
    hit = {next(v[4] for v in votes if (v[0], v[1]) == pa) for pa in (func, data)}
    bent = [(p, a, j, sym + "_x" if voter in hit and (p, a) in (func, data) else sym, voter)
            for p, a, j, sym, voter in votes]
    adm2, conf2 = tally(bent)
    gone = func not in adm2 and data not in adm2
    return fails + case("slot_objects_disagree", gone and len(conf2) >= 2,
                        f"{admitted[func][0]} and {admitted[data][0]} removed {gone}, conflicts {len(conf2)}")


def self_test():
    shutil.rmtree(SELFTEST, ignore_errors=True)
    os.makedirs(SELFTEST / "shared/planted")
    with open(SELFTEST / "partners.tsv", "w") as f:
        for i, (_, (x6, words, key, src, x4, npart, state), _) in enumerate(CASES):
            f.write(f"PLANTED\t0x{0x80010000 + i * 0x100:08X}\t{x6}\t{words}\t{key}\t{src}\t{x4}\t{npart}\t{state}\n")
    # the good row is still include_asm in the table; its key in an attributed file is what makes it `gate`
    (SELFTEST / "shared/planted/planted_good.c").write_text(
        f"/* Adapted from sozud/mmx4 @{x4port.PIN} src/main/weapons/weapon_00_planted.c:planted_good, AGPL-3.0; "
        f"proven shared with X6 by exact signature {'4' * 12} (see THIRD_PARTY.md). */\nvoid planted(void) {{\n}}\n")
    build(SELFTEST / "partners.tsv", SELFTEST / "shared", SELFTEST / "names.tsv")
    got = {r[3]: r for r in load(SELFTEST / "names.tsv")}
    fails = []
    for name, (x6, words, _, _, x4, npart, _), want in CASES:
        r = got.get(x6)
        why = refusal(x4, npart, words)
        print(f"X4NAMES CASE {name} " + (f"admitted {r[4]} {r[5]} {r[6]}" if r else f"refused {why}"))
        ok = (r is None and why != "") if want is None else (r is not None and (r[5], r[6]) == want and r[4] == x4)
        if not ok:
            fails.append(name)
    fails += widen_cases()
    for name in fails:
        print(f"X4NAMES CONTROL FAIL {name}")
    if fails:
        return 1
    print("X4NAMES CONTROL OK")
    return 0


def main(argv):
    if argv in (["--help"], ["-h"]):
        print(__doc__.strip())
        return 0
    if argv == ["--build"]:
        build(PARTNERS, SHARED, NAMES)
        return 0
    if argv == ["--widen"]:
        return widen()
    if argv == ["--x4-exe"]:
        return x4_exe()
    if argv == ["--data-probe"]:
        return data_probe()
    if len(argv) == 2 and argv[0] == "--who":
        return who(argv[1])
    if argv == ["--doc"]:
        return doc()
    if argv == ["--self-test"]:
        return self_test()
    print(__doc__.strip(), file=sys.stderr)
    return 2


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
