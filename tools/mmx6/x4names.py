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
         basis  x4 exact <key12> sozud/mmx4@<pin> <mmx4 path>:<function>   (pin: config/refs.toml `[[ref]] name =
                "mmx4"`, 7 hex; the names pin, not the port lane's x4port.PIN)
         The host cannot recompute the rows --widen added (tier `slot`, or a basis ending ` same-name <n>` /
         ` slot <n>`): --build recomputes the exact rows and carries those forward verbatim from the existing
         names.tsv, printing `X4NAMES carried <n> widened rows` before the last line.
         last line: X4NAMES <rows> rows; gate <g> bytes <b> slot <s>; engine <e> object <o>; func <f> data <d>
  x4names.py --widen
      -> container only (the build, build/corpus/functions.jsonl, the mmx4 clone .run/mmx4 at the refs.toml pin and
         its objects
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

Admission, tiers, widening, --who and the doc writer live in x4core.py (shared with mmx5, byte-identical; its own
`--selftest` covers them on synthetic objects); the X6 side (attributed files, the build's objects and symbols, paths,
the doc's X6 text) is x4adapter.py. This file keeps the CLI, the self-test and the X4 data measurement (--x4-exe,
--data-probe).
"""
import hashlib
import os
import re
import shutil
import struct
import sys
from pathlib import Path

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import census  # noqa: E402  (asm_index, obj_of)
import x4adapter  # noqa: E402  (paths, attributed, banked, Build)
import x4core  # noqa: E402  (admission, tiers, widening, who, doc)
import x4port  # noqa: E402  (PIN and TRIPLE of the port lane, FUNCS, Elf, jl)
import x4share  # noqa: E402  (CLONE)

ROOT = x4adapter.ROOT
TAG = x4adapter.TAG
PARTNERS = x4adapter.PARTNERS
SHARED = x4adapter.SHARED
NAMES = x4adapter.NAMES
DOC = x4adapter.DOC
SELFTEST = ROOT / ".run/x4names-selftest"
SCRATCH = x4adapter.SCRATCH  # --widen intermediates: container only, never pulled or tracked
EXE = x4adapter.EXE
X4EXE = ROOT / ".run/x4/SLUS_005.61"  # --x4-exe output: container only, never pulled or tracked
SELF_OBJ, SELF_TU = "build/src/SLUS_013.95/120A0.c.o", "120A0"

MIN_WORDS = x4core.MIN_WORDS
MIN_VOTERS = x4core.MIN_VOTERS
X4DRAFT = x4core.X4DRAFT  # an address-spelled mmx4 symbol: votes, never names
RAM = x4core.RAM
MIN_DATA = 16  # bytes: the shortest X4 datum searched by content
X4SYM = re.compile(r"^(\w+)\s*=\s*0x([0-9A-Fa-f]+);\s*//.*\bsize:(0x[0-9A-Fa-f]+|\d+)")
DATA_WHY = ("draft-name", "outside", "short", "fill", "address")

# ---- the names table: x4core over x4adapter (this file's names kept for the CLI and the self-test) ------------------

attributed = x4adapter.attributed
refusal = x4core.refusal
widened = x4core.widened
pick = x4core.pick
tally = x4core.tally
Build = x4adapter.Build


def pin7():
    """The names pin: config/refs.toml `[[ref]] name = "mmx4"`, 7 hex."""
    return x4core.short(x4core.pin(ROOT))


def count_line(rows):
    return x4core.count_line(rows, TAG)


def load(names):
    return x4core.load(names, TAG)


def build(partners, shared, names):
    return x4core.build(partners, names, x4adapter.banked(shared), pin7(), TAG)


def merge(exact, pending, admitted, by_key, x6sym, defs, funcs, att):
    return x4core.merge(exact, pending, admitted, by_key, x6sym, defs, funcs, x4adapter.banked_by(att), pin7())


def widen():
    return x4core.widen(x4adapter)


def who(text):
    return x4core.who(NAMES, text, TAG)


def doc():
    return x4core.doc(x4adapter)


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

    folded = set()

    def plain(r4):  # our INCLUDE_ASM objects alias every asm function as <name>.NON_MATCHING; mmx4's have none.
        # Our banked C may also declare a link-only second name <name>_<tag> at the same address (func_800139A0_2p in
        # func_8001CC1C.c, D_80090C90_flat in func_8002ABA8.c; T48): folded to <name> here only, never in the tool;
        # a fold onto a wrong address fails `right` below.
        out = {}
        for i, (t, n, e) in r4.items():
            n = n.replace(".NON_MATCHING", "")
            f = re.sub(r"^((?:fanc_g|G_g)[0-9A-F]{7})_\w+$", r"\1", n)
            if f != n:
                folded.add(n)
            out[i] = (t, f, e)
        return out

    b = Build()
    rows = [r for r in x4port.jl(x4port.FUNCS) if r["prog"] == EXE and census.obj_of(r, b.idx) == SELF_OBJ]
    votes = []
    for r in rows:
        try:
            votes += b.votes(r, fake, re.sub(r"^func_8", "fanc_g", r["name"]), r["name"], tamper=plain)
        except x4core.Skip:
            pass
    admitted, conf = tally(votes)
    right = all(back(sym) in b.addr(EXE).by_addr.get(a, ()) for (_, a), (sym, _, _) in admitted.items())
    func = next((pa for pa in sorted(admitted) if admitted[pa][2]), None)
    data = next((pa for pa in sorted(admitted) if not admitted[pa][2]), None)
    fails = case("slot_objects", bool(admitted) and right and func is not None and data is not None and not conf,
                 f"{len(rows)} anchors, {len(votes)} votes, admitted {len(admitted)} "
                 f"(every name maps back {right}), folded {len(folded)} link-only names, conflicts {len(conf)}")
    for kind, prog, a, what in conf:
        print(f"X4NAMES CONFLICT slot_objects {kind} {prog} 0x{a:08X} {what}")
    if func is None or data is None:
        return fails or ["slot_objects"]
    # control: one voter of each of the two addresses renamed on the X4 side -> both gone
    hit = {next(v[4] for v in votes if (v[0], v[1]) == pa) for pa in (func, data)}
    bent = [(p, a, j, sym + "_x" if voter in hit and (p, a) in (func, data) else sym, voter)
            for p, a, j, sym, voter in votes]
    adm2, conf2 = tally(bent)
    gone = func not in adm2 and data not in adm2
    return fails + case("slot_objects_disagree", gone and len(conf2) == 2,  # was >= 2
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
    fails += case("lane_triple", x4adapter.TRIPLE == x4port.TRIPLE, f"x4adapter.TRIPLE {x4adapter.TRIPLE}")
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
