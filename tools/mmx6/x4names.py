#!/usr/bin/env python3
"""x4names.py -- X4 names as aliases for X6 addresses, from the proven X4 partnerships (stdlib; host, except --widen).

  x4names.py --build
      -> reads campaign/x4/partners.tsv and the line-1 headers of src/shared/**/*.c (x4port.ADAPTED); admits a row
         when its X4 name is real (not func_8XXXXXXX), it has exactly one X4 partner and it is 8 words or more;
         writes config/x4/names.tsv, sorted by (prog, vram, kind), tab-separated, NO header row (so the row count of
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
  x4names.py --promote [--votes <path>]
      -> host; reads names.tsv, the votes (default .run/x4names/votes.tsv, the container's --widen output) and
         config/symbols/basis.tsv; rewrites the basis rows of kind `x4` only (hand rows kept verbatim) and writes
         config/x4/held.tsv (docs/naming.md). A func row is admitted when tier gate, scope engine, one partner
         (no ` same-name`/` slot` suffix) and a corroborator: caller (a vote at its address for its alias by another
         voter), callee (its own voter's vote on an address whose exact alias, never a slot one, is the voted symbol) or hand (a basis row of
         kind string|xref|oracle|debug|community there); a vote there for another symbol holds it. A data row is
         admitted when tier slot, scope engine, votes a/0 with a >= 3. Voters compare without `.c`. basis.tsv
         `prog vram name basis-kind basis-ref tier`, the x4 basis-ref = the names basis without `x4 ` plus
         `; corroborator caller <voter>|callee <voter> <prog>:<vram>|hand <kind>` (func rows); held.tsv
         `prog vram kind x6name alias tier scope reason` (every failing clause, comma-separated). The votes used are
         copied to campaign/x4/votes.tsv (rewrite later with --votes that path). A voter that is no names
         row's basis `path:function` -> `X4NAMES promote REFUSE stale votes <voter>` rc 1; no votes file ->
         `X4NAMES promote REFUSE no votes (run --widen in the container)` rc 1. Lines
         `X4NAMES promote rows <n> = admitted <a> + held <h>`, last `X4NAMES promote <a> admitted (func <f> data <d>);
         held <h>`
  x4names.py --upstream
      -> host; config/x4/upstream.tsv, one row per non-x4 basis.tsv row whose X6 function has one mmx4 partner
         (partners.tsv) under another name: `prog vram mmx4-path:function proposed-name basis-kind basis-ref`
         (handed to mmx4 by the developer only). Last line `X4NAMES upstream <n> rows`
  x4names.py --compare
      -> container only (the clone .run/mmx4 at the refs.toml pin, the pinned cc1); writes docs/x4-compare.md, never
         hand-edited. Functions: every `func` row of names.tsv, ours = the name at its vram in
         config/symbols.<prog>.txt (the alias when one of the names there is it, else the first non-func_/D_ one),
         mmx4's = alias + basis `path:function` (`-` for slot rows). Fields: every struct|union X4_<N> of
         include/mmx6/x4.h against mmx4's tag <N> in the first mmx4 .c defining it (x4.h's line-1 .c files first);
         offsets from an `(int)&((T *)0)->f` table compiled by the pinned cc1 on each preprocessed TU, read from the
         .s; bitfields and anonymous members get offset `-` (paired by ordinal among those); pairs by (offset,
         ordinal at that offset), an absent side a placeholder. Classes agree | conflict | X6-only | mmx4-only
         (+ held.tsv reason for functions) | unnamed (both placeholders, counted not listed); placeholder
         func `(func|sub|D)_<8 hex>`, field `(unk|pad|field|filler)_?(0x)?<hex>`. Sorted, no timestamps. Lines
         `X4NAMES compare structs <n> absent <a>`, `X4NAMES compare functions <class n>...; fields <class n>...`
  x4names.py --self-test
      -> planted table in .run/x4names-selftest/: a two-partner row, a func_8 partner and a 7-word row are each
         refused, one good row is admitted with its tier and scope. 2a: a planted class whose partners share one
         name is admitted, one with two names refused. 2b: two agreeing voters name a callee and a global and
         resolve a two-name class; one disagreeing voter removes them. data_probe (planted bytes): a datum
         with one occurrence is a unique hit, two occurrences in one program are refused, constant fill and an
         address-looking word are refused. slot_objects (container: needs
         build/src/SLUS_013.95/120A0.c.o and the corpus; on the host `X4NAMES CASE slot_objects skipped no-objects`):
         a renamed copy of our own object as the X4 side through the real relocation pairing. promote (planted, in
         .run/x4names-selftest/promote/): a caller-voted admit, an object-scope row held `scope object`, a lone
         gate+engine row held `no corroborator`, a hand string row that corroborates a row and yields one upstream
         row. Ends
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
    return x4adapter.doc()  # x4core.doc + the adapter's header prose (DOC_HEAD)


# ---- promotion: names.tsv rows -> config/symbols/basis.tsv `x4` rows (admitted) | config/x4/held.tsv --------------

BASIS = ROOT / "config/symbols/basis.tsv"
HELD = ROOT / "config/x4/held.tsv"
UPSTREAM = ROOT / "config/x4/upstream.tsv"
VOTES = SCRATCH / "votes.tsv"
VOTES_LOG = ROOT / "campaign/x4/votes.tsv"  # the votes a --promote used, for a rewrite without --widen
BASIS_HEAD = "# prog\tvram\tname\tbasis-kind\tbasis-ref\ttier"
HELD_HEAD = "# prog\tvram\tkind\tx6name\talias\ttier\tscope\treason"
UP_HEAD = "# prog\tvram\tmmx4-path:function\tproposed-name\tbasis-kind\tbasis-ref"
HAND = ("string", "xref", "oracle", "debug", "community")  # the hand basis kinds that corroborate an x4 row
MIN_DATA_VOTES = 3


def norm_voter(v):
    """`path[.c]:function` -> `path:function` (x4core votes name the source without `.c`, basis rows with it)."""
    path, _, fn = v.rpartition(":")
    return f"{path[:-2] if path.endswith('.c') else path}:{fn}"


def own_voter(basis):
    """The row's own `path:function` (normalised) from an `x4 exact|...` basis, else None (a slot row)."""
    f = basis.split()
    return norm_voter(f[4]) if len(f) >= 5 and f[1] == "exact" and ":" in f[4] else None


def read_tsv(path):
    """Rows of a TAB file, `#` lines skipped; [] when absent."""
    if not os.path.isfile(path):
        return []
    return [x.split("\t") for x in Path(path).read_text().splitlines() if x and not x.startswith("#")]


def write_tsv(path, head, lines):
    os.makedirs(Path(path).parent, exist_ok=True)
    Path(path).write_text("\n".join([head] + lines) + "\n")


def promote(names, votes_path, basis, held, votes_log):
    """The admission rules of docs/naming.md over names.tsv + votes + the hand basis rows (module header)."""
    if not os.path.isfile(votes_path):
        print(f"{TAG} promote REFUSE no votes (run --widen in the container)")
        return 1
    rows = load(names)
    votes = read_tsv(votes_path)  # prog vram jump|addr symbol voter
    known = {own_voter(r[8]) for r in rows} - {None}
    for v in sorted({norm_voter(v[4]) for v in votes}):
        if v not in known:
            print(f"{TAG} promote REFUSE stale votes {v}")
            return 1
    if Path(votes_path).resolve() != Path(votes_log).resolve():
        os.makedirs(Path(votes_log).parent, exist_ok=True)
        shutil.copyfile(votes_path, votes_log)
    # callee targets: exact rows only; a slot row exists because of these same votes (circular, T6 review)
    alias = {(r[0], r[1]): r[4] for r in rows if r[8].startswith("x4 exact")}
    at, by = {}, {}
    for prog, vram, _, sym, voter in votes:
        at.setdefault((prog, vram), []).append((sym, norm_voter(voter)))
        by.setdefault(norm_voter(voter), []).append((prog, vram, sym))
    hand_raw = ["\t".join(f) for f in read_tsv(basis) if f[3] != "x4"]  # hand rows, kept verbatim
    hand = {}
    for x in hand_raw:
        f = x.split("\t")
        if f[3] in HAND:
            hand.setdefault((f[0], f[1]), set()).add(f[3])
    out, kept, nf, nd = [], [], 0, 0
    for r in rows:
        prog, vram, kind, x6, al, tier, scope, vt, bs = r
        why, corr = [], None
        if scope != "engine":
            why.append(f"scope {scope}")
        sym_at = at.get((prog, vram), [])
        conflict = any(s != al for s, _ in sym_at)
        if kind == "data":
            if tier != "slot":
                why.append(f"tier {tier}")
            a, _, d = vt.partition("/")
            if not a.isdigit() or int(a) < MIN_DATA_VOTES:
                why.append(f"anchors {a}")
            if conflict or d not in ("", "0"):
                why.append("vote conflict")
        else:
            if tier != "gate":
                why.append(f"tier {tier}")
            m = re.search(r" (same-name|slot) (\d+)$", bs)
            if m:
                why.append(f"partners {m.group(1)} {m.group(2)}")
            me = own_voter(bs)
            caller = sorted({v for s, v in sym_at if s == al and v != me})
            callee = sorted(f"{p}:{a}" for p, a, s in by.get(me, ()) if alias.get((p, a)) == s) if me else []
            hk = [k for k in HAND if k in hand.get((prog, vram), ())]
            if caller:
                corr = f"caller {caller[0]}"
            elif callee:
                corr = f"callee {me} {callee[0]}"
            elif hk:
                corr = f"hand {hk[0]}"
            if conflict:
                why.append("vote conflict")
            elif corr is None:
                why.append("no corroborator")
        if why:
            kept.append("\t".join([prog, vram, kind, x6, al, tier, scope, ", ".join(why)]))
            continue
        ref = bs[3:] if bs.startswith("x4 ") else bs
        if corr:
            ref += f"; corroborator {corr}"
        out.append((prog, vram, "x4", "\t".join([prog, vram, al, "x4", ref, tier])))
        nf, nd = nf + (kind != "data"), nd + (kind == "data")
    for x in hand_raw:
        f = x.split("\t")
        out.append((f[0], f[1], f[3], x))
    write_tsv(basis, BASIS_HEAD, [x for *_, x in sorted(out)])
    write_tsv(held, HELD_HEAD, sorted(kept, key=lambda x: (x.split("\t")[:3], x)))
    a = nf + nd
    assert a + len(kept) == len(rows), (a, len(kept), len(rows))
    print(f"{TAG} promote rows {len(rows)} = admitted {a} + held {len(kept)}")
    print(f"{TAG} promote {a} admitted (func {nf} data {nd}); held {len(kept)}")
    return 0


def upstream(basis, partners, out):
    """One row per non-x4 basis row whose X6 function has one mmx4 partner under another name (module header)."""
    part = {(c[0], c[1]): c for c in read_tsv(partners)}
    lines = []
    for f in read_tsv(basis):
        c = part.get((f[0], f[1]))
        if f[3] == "x4" or c is None or c[7] != "1" or c[6] == f[2]:
            continue
        lines.append("\t".join([f[0], f[1], f"{c[5]}:{c[6]}", f[2], f[3], f[4]]))
    lines = sorted(set(lines))
    write_tsv(out, UP_HEAD, lines)
    print(f"{TAG} upstream {len(lines)} rows")
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


def promote_cases():
    """Planted names/votes/basis/partners: caller-corroborated admit, object scope, no corroborator, hand string."""
    d = SELFTEST / "promote"
    os.makedirs(d)
    pin = f"sozud/mmx4@{x4port.PIN}"
    ex = lambda k, p, f: f"x4 exact {k * 12} {pin} {p}:{f}"  # noqa: E731
    names = [("0x80020000", "planted_admit", "gate", "engine", ex("a", "src/main/p.c", "planted_admit")),
             ("0x80020100", "planted_caller", "gate", "object", ex("b", "src/main/weapons/q.c", "planted_caller")),
             ("0x80020200", "planted_lonely", "gate", "engine", ex("c", "src/main/p.c", "planted_lonely")),
             ("0x80020300", "planted_hand", "gate", "engine", ex("d", "src/main/p.c", "planted_hand"))]
    (d / "names.tsv").write_text("".join(f"PLANTED\t{v}\tfunc\tfunc_{v[2:]}\t{al}\t{t}\t{s}\t-\t{b}\n"
                                         for v, al, t, s, b in names))
    (d / "votes.tsv").write_text("PLANTED\t0x80020000\tjump\tplanted_admit\tsrc/main/weapons/q:planted_caller\n")
    (d / "basis.tsv").write_text(f"{BASIS_HEAD}\nPLANTED\t0x80020300\thand_name\tstring\tplanted text ref\t-\n")
    (d / "partners.tsv").write_text("PLANTED\t0x80020300\tfunc_80020300\t9\t" + "d" * 12 +
                                    "\tsrc/main/p.c\tplanted_hand\t1\tinclude_asm\n")
    rc = promote(d / "names.tsv", d / "votes.tsv", d / "basis.tsv", d / "held.tsv", d / "votes.log.tsv")
    up = rc or upstream(d / "basis.tsv", d / "partners.tsv", d / "upstream.tsv")
    b = {(f[1], f[3]): f for f in read_tsv(d / "basis.tsv")}
    h = {f[1]: f[7] for f in read_tsv(d / "held.tsv")}
    u = read_tsv(d / "upstream.tsv") if not up else []
    a0, a3 = b.get(("0x80020000", "x4")), b.get(("0x80020300", "x4"))
    fails = case("promote_caller", rc == 0 and a0 is not None
                 and a0[4].endswith("; corroborator caller src/main/weapons/q:planted_caller"),
                 f"admitted {a0[2] + ' ' + a0[4].rpartition('; ')[2] if a0 else 'none'}")
    fails += case("promote_object", h.get("0x80020100") == "scope object", f"held {h.get('0x80020100')}")
    fails += case("promote_nocorr", h.get("0x80020200") == "no corroborator", f"held {h.get('0x80020200')}")
    good = (a3 is not None and a3[4].endswith("; corroborator hand string") and ("0x80020300", "string") in b
            and [f[2:4] for f in u] == [["src/main/p.c:planted_hand", "hand_name"]])
    return fails + case("promote_hand", good, f"admitted {a3[2] if a3 else 'none'} by hand string; "
                        f"hand row kept {('0x80020300', 'string') in b}; upstream {len(u)} rows")


# ---- --compare: our names against mmx4's at the pin (functions: names.tsv rows; fields: include/mmx6/x4.h) -------

COMPARE = ROOT / "docs/x4-compare.md"
X4H = ROOT / "include/mmx6/x4.h"
CMP_SCR = SCRATCH / "compare"  # container only: the offset TUs and their .s, never pulled or tracked
PH_FUNC = re.compile(r"^(func|sub|D)_[0-9A-Fa-f]{8}$")
PH_FIELD = re.compile(r"^(unk|pad|field|filler)_?(0x)?[0-9A-Fa-f]*$")
CLASSES = ("conflict", "agree", "X6-only", "mmx4-only", "unnamed")
ANON = "(anonymous)"


def klass(ours, theirs, ph):
    """One of CLASSES; None (absent) and ANON are placeholders."""
    a = ours is not None and ours != ANON and not ph.match(ours)
    b = theirs is not None and theirs != ANON and not ph.match(theirs)
    if a and b:
        return "agree" if ours == theirs else "conflict"
    return "X6-only" if a else "mmx4-only" if b else "unnamed"


def our_name(names, alias):
    """Our name at an address among the symbols there: the alias if one is it, else the first real one, else the first."""
    if alias in names:
        return alias
    real = sorted(n for n in names if not re.match(r"(func|sub|D)_[0-9A-Fa-f]{8}", n))
    return (real or sorted(names) or [None])[0]


def func_rows(rows, syms, held):
    """[(prog, vram, ours, alias, path, class, held)] of the func rows of names.tsv. syms: {(prog, vram int): [names]};
    held: {(prog, vram): reason}."""
    out = []
    for r in rows:
        prog, vram, kind, _, alias = r[:5]
        if kind != "func":
            continue
        f = r[8].split()
        path = f[4] if len(f) >= 5 and f[1] == "exact" and ":" in f[4] else "-"
        ours = our_name(syms.get((prog, int(vram, 16)), []), alias)
        c = klass(ours, alias, PH_FUNC)
        out.append((prog, vram, ours or "-", alias, path, c, held.get((prog, vram), "-") if c == "mmx4-only" else ""))
    return sorted(out, key=lambda x: (x[0], int(x[1], 16)))


def field_rows(layouts):
    """(rows, absent). layouts: {N: (ours, theirs | None)}, each side [(offset | None, name, note)] in declaration
    order. rows: (N, offset | None, ordinal, ours, theirs, class, note); paired by (offset, ordinal at that offset),
    offset None (bitfield, anonymous) as one more offset; a side without the pair is a placeholder."""
    rows, absent = [], []
    for n in sorted(layouts):
        ours, theirs = layouts[n]
        if theirs is None:
            absent.append(n)
            continue
        sides = []
        for fields in (ours, theirs):
            seen, d = {}, {}
            for off, name, note in fields:
                k = (off, seen.get(off, 0))
                seen[off] = k[1] + 1
                d[k] = (name, note)
            sides.append(d)
        for k in set(sides[0]) | set(sides[1]):
            a, b = sides[0].get(k, (None, "")), sides[1].get(k, (None, ""))
            note = ", ".join(sorted({a[1], b[1]} - {""}))
            rows.append((n, k[0], k[1], a[0], b[0], klass(a[0], b[0], PH_FIELD), note))
    rows.sort(key=lambda x: (x[0], x[1] is None, x[1] or 0, x[2]))
    return rows, absent


def compare_doc(funcs, fields, absent, pin, nstructs):
    """docs/x4-compare.md text: names, addresses, paths, field names and offsets only (no types, no C)."""
    cnt = {c: [sum(1 for x in funcs if x[5] == c), sum(1 for x in fields if x[5] == c)] for c in CLASSES}
    noff = sum(1 for x in fields if x[1] is None and x[5] != "unnamed")
    out = ["# X4 names compared with mmx4", "",
           f"This file is generated by `tools/mmx6/x4names.py --compare`. Do not edit it by hand. "
           f"The mmx4 pin is `{pin}`.", "",
           "The tool compares our names with the mmx4 names at the pin. The functions are the `func` rows of "
           "`config/x4/names.tsv`. Our function name is the name in `config/symbols.<prog>.txt` at that address. "
           "The fields are the members of each `X4_` struct and union in `include/mmx6/x4.h`. "
           "The pinned compiler gives the offset of each field on each side.", "",
           "A pair is `agree` when the two names are equal, and `conflict` when they differ. "
           "A pair is `X6-only` when only our name is real, and `mmx4-only` when only the mmx4 name is real. "
           "A pair with two placeholder names counts as `unnamed`. This file does not list these pairs.", "",
           "A field without an offset (a bitfield or an anonymous member) has the offset `-`. "
           "An unnamed padding bitfield is not a field here. X6 `-` means no symbol at that address.", "",
           "## Counts", "", "| class | functions | fields |", "|---|---|---|"]
    out += [f"| {c} | {cnt[c][0]} | {cnt[c][1]} |" for c in CLASSES]
    out += ["", f"Structs compared: {nstructs - len(absent)}. Absent at the pin: {len(absent)}. "
            f"Listed fields without an offset: {noff}.", ""]

    def fn(x):
        tail = f", held: {x[6]}" if x[5] == "mmx4-only" else ""
        return f"- `{x[0]}` `{x[1]}`: X6 `{x[2]}`, mmx4 `{x[3]}` (`{x[4]}`){tail}"

    def fld(c):
        lines, cur = [], None
        for x in fields:
            if x[5] != c:
                continue
            if x[0] != cur:
                cur = x[0]
                lines += ["", f"#### `X4_{cur}` (mmx4 `{cur}`)", ""]
            off = "-" if x[1] is None else f"+0x{x[1]:X}"
            ordn = f" #{x[2]}" if x[2] else ""
            note = f" ({x[6]})" if x[6] else ""
            lines.append(f"- `{off}`{ordn}: X6 `{x[3] or '-'}`, mmx4 `{x[4] or '-'}`{note}")
        return lines or ["", "None."]

    for title, c in (("Conflicts", "conflict"), ("Agree", "agree"), ("X6-only", "X6-only"),
                     ("mmx4-only", "mmx4-only")):
        f = [fn(x) for x in funcs if x[5] == c]
        out += [f"## {title}", "", "### Functions", ""] + (f or ["None."]) + ["", "### Fields"] + fld(c) + [""]
    out += ["## Absent at the pin", ""] + ([f"- `X4_{n}` (mmx4 `{n}`)" for n in absent] or ["None."])
    return "\n".join(out) + "\n"


def split_members(ts):
    """The member declarations (token lists) of a struct body's tokens: `;` at depth 0 of ( [ {."""
    parts, cur, d = [], [], 0
    for t in ts:
        d += 1 if t in "([{" else -1 if t in ")]}" else 0
        if t == ";" and d == 0:
            parts.append(cur)
            cur = []
        else:
            cur.append(t)
    return [p for p in parts + [cur] if p]


def members(pp, kind, tag):
    """[(name, note)] of the first `kind tag {...}` in preprocessed text pp (None when absent); note `bitfield` or
    `anonymous` (no offset taken), else ''."""
    m = re.search(rf"\b{kind}\s+{tag}\s*\{{", pp)
    if not m:
        return None
    d, i = 0, m.end() - 1
    while True:
        d += {"{": 1, "}": -1}.get(pp[i], 0)
        if d == 0:
            break
        i += 1
    out = []
    for decl in split_members(x4port.toks(pp[m.end():i])):
        d, bit = 0, False
        for t in decl:
            d += 1 if t in "([{" else -1 if t in ")]}" else 0
            bit = bit or (t == ":" and d == 0)
        if bit:  # `T a : 3, b : 5`: the identifier before each `:`; `T : 8` (padding, no type before it) is skipped
            names = [p[p.index(":") - 1] for k, p in enumerate(x4port.top_split(decl, ",")) if ":" in p
                     and p.index(":") >= (2 if k == 0 else 1) and x4port.IDENT.fullmatch(p[p.index(":") - 1])]
            out += [(n, "bitfield") for n in names]
            continue
        text = " ".join("__attribute__" if t == "__attribute" else t for t in decl)  # unattr knows only __attribute__
        names = [n for n, _ in x4port.declarators(text)]
        if not names and "{" in decl:
            out.append((ANON, "anonymous"))
        out += [(n, "") for n in names]
    return out


def offsets(pp, reqs, cc1):
    """{(i, field): offset} from the pinned cc1: pp + one `int x4cmp_<i>[]` table per (i, C type, [fields]) of
    reqs (offset + 1, so no table is all zero), compiled to assembly and read back from its `.word` lines."""
    tab = [f"int x4cmp_{i}[] = {{ " + ", ".join(f"(int)&(({ct} *)0)->{f} + 1" for f in fl) + " };"
           for i, ct, fl in reqs if fl]
    src = pp + "\n" + "\n".join(tab) + "\n"
    p = x4port.subprocess.run(cc1, input=src, capture_output=True, text=True)
    if p.returncode != 0:
        (CMP_SCR / "failed.i").write_text(src)  # kept for the reader: the container's .run, never pulled
        sys.exit(f"{TAG} compare cc1 rc {p.returncode} ({CMP_SCR / 'failed.i'}): "
                 + " | ".join(p.stderr.strip().splitlines()[:4])[:400])
    words, cur = {}, None
    for line in p.stdout.splitlines():
        m = re.match(r"(x4cmp_\d+):", line)
        if m:
            cur = m.group(1)
            words[cur] = []
        elif cur and re.match(r"\s*\.(word|4byte)\s", line):
            words[cur].append(int(line.split()[1], 0) - 1)
        elif cur and not line.startswith(("\t.", " .")):
            cur = None
    out = {}
    for i, _, fl in reqs:
        if fl:
            got = words.get(f"x4cmp_{i}", [])
            if len(got) != len(fl):
                sys.exit(f"{TAG} compare offsets of table {i}: {len(got)} words for {len(fl)} fields")
            out.update({(i, f): o for f, o in zip(fl, got)})
    return out


def layout(pp, tags, cc1):
    """{N: [(offset | None, name, note)] | None} of the `kind N` tags in pp; tags: [(kind, N, C tag name)]."""
    mem = {n: members(pp, k, t) for k, n, t in tags}
    reqs = [(i, f"{k} {t}", [x for x, note in mem[n] if not note]) for i, (k, n, t) in enumerate(tags)
            if mem[n] is not None]
    off = offsets(pp, reqs, cc1)
    idx = {n: i for i, (_, n, _) in enumerate(tags)}
    return {n: None if mem[n] is None else [(off.get((idx[n], x)) if not note else None, x, note)
                                            for x, note in mem[n]] for n in mem}


def struct_layouts():
    """{N: (ours, theirs | None)} for every struct|union X4_<N> of x4.h (container: the clone at the pin, cc1)."""
    os.chdir(ROOT)
    ctx = x4port.mmx4_ctx()  # exits unless the clone is at the pin
    cc1 = x4adapter.tools(x4adapter.triple(x4port.TRIPLE))["cc1"]
    text = X4H.read_text()
    kinds = {}
    for m in re.finditer(r"\b(struct|union)\s+X4_(\w+)\s*\{", text):
        kinds.setdefault(m.group(2), m.group(1))
    os.makedirs(CMP_SCR, exist_ok=True)
    src = CMP_SCR / "ours.c"
    src.write_text('#include "mmx6/x4.h"\n')
    ours_cpp = ["mipsel-linux-gnu-cpp", "-nostdinc", "-undef", "-D__GNUC__=2", "-DPSX", "-Iinclude"]  # Makefile CPP
    pp = x4port.run_cpp(ours_cpp + [str(src)], str(ROOT))
    ours = layout(pp, [(k, n, f"X4_{n}") for n, k in sorted(kinds.items())], cc1)
    # mmx4: the first .c that defines tag N, the files x4.h is adapted from first (its line 1), then all sorted
    first = re.findall(r"\b(src/\S+?\.c)\b", text.split("\n", 1)[0])
    clone = Path(ctx.clone)
    rest = sorted(str(p.relative_to(clone)) for p in clone.glob("src/**/*.c"))
    theirs, todo = {}, dict(kinds)
    for c in sorted(set(first)) + [x for x in rest if x not in first]:
        if not todo:
            break
        try:
            tpp = x4port.run_cpp(ctx.cpp + [c], str(clone))
        except x4port.Skip:
            continue
        here = [(k, n, n) for n, k in sorted(todo.items()) if re.search(rf"\b{k}\s+{n}\s*\{{", tpp)]
        if here:
            theirs.update(layout(tpp, here, cc1))
            for _, n, _ in here:
                del todo[n]
    shutil.rmtree(CMP_SCR, ignore_errors=True)
    return {n: (ours[n], theirs.get(n)) for n in kinds}


def compare():
    rows = load(NAMES)
    syms = {}
    for prog in sorted({r[0] for r in rows}):
        for line in (ROOT / f"config/symbols.{prog}.txt").read_text().splitlines():
            m = x4adapter.SYMBOL.match(line)
            if m:
                syms.setdefault((prog, int(m.group(2), 16)), []).append(m.group(1))
    held = {(r[0], r[1]): r[7] for r in read_tsv(HELD)}
    funcs = func_rows(rows, syms, held)
    lay = struct_layouts()
    fields, absent = field_rows(lay)
    COMPARE.write_text(compare_doc(funcs, fields, absent, pin7(), len(lay)))
    cf = " ".join(f"{c} {sum(1 for x in funcs if x[5] == c)}" for c in CLASSES)
    cd = " ".join(f"{c} {sum(1 for x in fields if x[5] == c)}" for c in CLASSES)
    print(f"{TAG} compare structs {len(lay)} absent {len(absent)}")
    print(f"{TAG} compare functions {cf}; fields {cd}")
    return 0


def compare_cases():
    """Planted functions, fields and struct text: every class, a held clause, a both-placeholder, an absent side, a
    bitfield and an anonymous member, and the same doc from shuffled input (pure Python, host)."""
    import random
    b = "x4 exact 0123456789ab sozud/mmx4@abcdef0 src/main/p.c:"
    rows = [["P", "0x80010000", "func", "-", "same", "gate", "engine", "-", b + "same"],
            ["P", "0x80010100", "func", "-", "func_80999999", "slot", "engine", "-", "x4 slot 2/0 sozud/mmx4@abcdef0 x"],
            ["P", "0x80010200", "func", "-", "theirs_only", "bytes", "engine", "-", b + "theirs_only"],
            ["P", "0x80010300", "func", "-", "theirs_name", "gate", "engine", "-", b + "theirs_name"],
            ["P", "0x80010400", "func", "-", "func_80010400", "slot", "engine", "-", "x4 slot 2/0 sozud/mmx4@abcdef0 y"],
            ["P", "0x80010500", "data", "-", "datum", "slot", "engine", "3/0", "x4 slot 3/0 sozud/mmx4@abcdef0 datum"]]
    syms = {("P", 0x80010000): ["same"], ("P", 0x80010100): ["ours_only"], ("P", 0x80010200): ["func_80010200"],
            ("P", 0x80010300): ["ours_name", "func_80010300_2p"], ("P", 0x80010400): ["func_80010400"]}
    held = {("P", "0x80010200"): "tier bytes, no corroborator"}
    funcs = func_rows(rows, syms, held)
    fc = {x[1]: (x[5], x[6]) for x in funcs}
    lay = {"S": ([(0, "a", ""), (4, "ours_b", ""), (8, "unk_8", ""), (12, "pad", ""), (16, "same_arr", ""),
                  (None, "bits", "bitfield")],
                 [(0, "a", ""), (4, "their_b", ""), (8, "theirs_c", ""), (12, "filler_C", ""), (16, "same_arr", ""),
                  (20, "tail", ""), (None, "bits", "bitfield")]),
           "U": ([(0, "x", ""), (0, "y", "")], [(0, "x", "")]),
           "Gone": ([(0, "z", "")], None)}
    fields, absent = field_rows(lay)
    fd = {(x[0], x[1], x[2]): x[5] for x in fields}
    want_f = {"0x80010000": ("agree", ""), "0x80010100": ("X6-only", ""),
              "0x80010200": ("mmx4-only", "tier bytes, no corroborator"), "0x80010300": ("conflict", ""),
              "0x80010400": ("unnamed", "")}
    want_d = {("S", 0, 0): "agree", ("S", 4, 0): "conflict", ("S", 8, 0): "mmx4-only", ("S", 12, 0): "unnamed",
              ("S", 16, 0): "agree", ("S", 20, 0): "mmx4-only", ("S", None, 0): "agree", ("U", 0, 0): "agree",
              ("U", 0, 1): "X6-only"}
    fails = case("compare_funcs", fc == want_f and len(funcs) == 5, f"{sorted(fc.items())}")
    fails += case("compare_fields", fd == want_d and absent == ["Gone"], f"{sorted(fd.items(), key=str)} absent {absent}")
    doc1 = compare_doc(funcs, fields, absent, "abcdef0", len(lay))
    rnd = random.Random(7)
    rows2, lay2 = rows[:], list(lay.items())
    rnd.shuffle(rows2)
    rnd.shuffle(lay2)
    doc2 = compare_doc(func_rows(rows2, syms, held), *field_rows(dict(lay2)), "abcdef0", len(lay))
    good = (doc1 == doc2 and "held: tier bytes, no corroborator" in doc1 and "| unnamed | 1 | 1 |" in doc1
            and "func_80010400" not in doc1 and ";" not in doc1.replace("x4names.py --compare", ""))
    fails += case("compare_doc", good, f"shuffled same {doc1 == doc2}, {len(doc1)} chars")
    pp = ("struct T { int a; unsigned b : 3, c : 5; union { int u; short v; }; struct { char q; } nest; "
          "void (*fp)(int); char unk_10[4]; s16 : 4; struct { int w; } __attribute((packed)) pk; };")
    got = members(pp, "struct", "T")
    want = [("a", ""), ("b", "bitfield"), ("c", "bitfield"), (ANON, "anonymous"), ("nest", ""), ("fp", ""),
            ("unk_10", ""), ("pk", "")]
    fails += case("compare_members", got == want and members(pp, "union", "T") is None, f"{got}")
    return fails


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
    fails += promote_cases()
    fails += compare_cases()
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
    if argv == ["--promote"] or (len(argv) == 3 and argv[:2] == ["--promote", "--votes"]):
        votes = Path(argv[2]) if len(argv) == 3 else VOTES
        return promote(NAMES, votes if votes.is_absolute() else ROOT / votes, BASIS, HELD, VOTES_LOG)
    if argv == ["--upstream"]:
        return upstream(BASIS, PARTNERS, UPSTREAM)
    if argv == ["--compare"]:
        return compare()
    if argv == ["--self-test"]:
        return self_test()
    print(__doc__.strip(), file=sys.stderr)
    return 2


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
