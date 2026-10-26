#!/usr/bin/env python3
"""imgadapter.py -- mmx6's two contract files for tools/psxd_img.py (psxdecomp's map core; stdlib).

psxd_img.py reads the units and the function list in one form for every game (docs/ops/psxdecomp-floor.md, "The
tables of a build"); this module writes them from mmx6's own files. Offsets, addresses and counts only: no word of a
game reaches a tracked file.
  units      SLUS_013.95 (the words after the PS-X EXE header, at the header's address) and rock_NN: each member of
             ROCK_X6.BIN (rock.read_toc) that config/loadmap.txt gives class `code`, at that row's base.
  functions  Each row of build/corpus/functions.jsonl, its lane and state as the list states them. A `lib` row is
             named `lib:<tu>:<name>`: SDK code that takes its library signature's name, never an alias.

  imgadapter.py units [--retail-root <checkout>]
      -> config/oracle.units.tsv (tracked). Retail's files: extracted/retail/iso/ of <checkout> (default: this one).
  imgadapter.py functions --functions <functions.jsonl>
      -> .run/oracle/functions.tsv (ignored).
  imgadapter.py strings [--proto <id>:<folder>:<executable>]... [--check]
      -> docs/leads/strings.tsv (tracked: keys, addresses and counts only) and refs/leads/strings/<prog>.tsv (retail)
         or <build>.<prog>.tsv (a proto), ignored, every string with its text. --check: the table regenerated in
         memory must equal the tracked one; it writes nothing.
  imgadapter.py --self-test
      A planted executable and archive (synthetic words, no game data): the units rows, the strings rows. Last line
      `IMGTAB CONTROL OK`.

The strings of a build (`strings`). Programs: the executable (vram from its header) and each of the 59 members
rock_NN of ROCK_X6.BIN; a member with a config/oracle.units.tsv row is code at that row's vram (a proto's member by
its index), any other is scanned at `+0x<offset in the member>` with no references. A string is psxd_img's text_at
(Ghidra's ASCII rule, else spimdisasm's Shift-JIS decoder) read at: each 4-aligned offset after a NUL, each ASCII run
of psxd_img's STRING that ends in a NUL (a start inside a string already read is skipped), and each address that a
lui + addiu/ori pair or a word of any program builds. encoding: sjis when a byte is >= 0x80, else ascii.
An address resolves in the program that builds it when its range holds it, else in the executable, else in every
other program at another base whose range holds it (programs at one base are never resident together).
Pointer tables: psxd_img's pointer_tables over the words that resolve to a string. Referencing functions: the
function of each lui whose pair builds the string's address or an address inside a table that holds it; the start
from the census list (.run/oracle/functions.tsv, retail only) when it holds the lui, else psxd_img's start_of scan.
None: `unreferenced`. class, the first that holds: table (reached through a pointer table); story (> 256 bytes of
UTF-8 or >= 4 lines); dialogue (> 1 line or > 64 bytes of UTF-8); short (the rest: one line of <= 64 bytes, rule M16).
UTF-8 and lines: the Shift-JIS decode, CR LF / CR as LF, trailing LFs dropped.

Then, from the repository: `python3 tools/psxd_img.py proto --id <id> --build <folder> --exe <its executable>`,
`strnames [--proto <id>:<folder>:<executable>]... [--check]`, `show <key>`. config/oracle.retail names
extracted/retail/iso.
"""
import argparse
import hashlib
import json
import os
import struct
import sys
import tempfile
from bisect import bisect_right
from pathlib import Path

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, os.path.join(os.path.dirname(os.path.abspath(__file__)), ".."))
import psxd_img as kit  # noqa: E402
import rock  # noqa: E402

ROOT = Path(__file__).resolve().parents[2]
TAG = "IMGTAB"
EXE, OVL = "SLUS_013.95", "ROCK_X6.BIN"
ISO = "extracted/retail/iso"
LOADMAP = "config/loadmap.txt"
UNITS, FUNCTIONS = "config/oracle.units.tsv", ".run/oracle/functions.tsv"
UNIT_COLUMNS = "unit\tfile\toffset\tvram\twords\tclass"
FUNCTION_COLUMNS = "unit\tvram\twords\tname\tlane\tstate"
HEADER = 0x800
STRINGS, SIDECAR = "docs/leads/strings.tsv", "refs/leads/strings"
STRING_COLUMNS = "prog\tvram\tsha1\tbytes\tclass\tencoding\treferencing-function\tbuild"
SIDECAR_HEADER = "vram\tsha1\tbytes\tclass\ttext"   # = gamestr.HEADER
CLASSES = ("short", "dialogue", "story", "table")
RETAIL = "retail"


def die(msg):
    sys.exit(f"imgadapter: {msg}")


def bases(loadmap):
    """{member index: base} of the `code` rows of config/loadmap.txt."""
    out = {}
    for line in Path(loadmap).read_text().splitlines():
        col = line.split()
        if len(col) >= 3 and col[0].isdigit() and col[2] == "code":
            out[int(col[0])] = int(col[1], 16)
    return out


def unit_rows(exe, ovl, loadmap):
    """The rows of config/oracle.units.tsv: the executable, then each `code` member of the archive."""
    base = bases(loadmap)
    return [(EXE, EXE, f"0x{HEADER:X}", f"0x{struct.unpack_from('<I', exe, 0x18)[0]:08X}", str((len(exe) - HEADER) // 4),
             "exe")] + [(f"rock_{m.index:02d}", OVL, f"0x{m.sector * rock.SECTOR:X}", f"0x{base[m.index]:08X}",
                         str(m.size // 4), "code") for m in rock.read_toc(ovl) if m.index in base]


def function_rows(fns):
    """The rows of .run/oracle/functions.tsv."""
    return [(f["prog"], f["vram"], str(f["words"]), f["name"] if f["lane"] == "game" else f"lib:{f['tu']}:{f['name']}",
             f["lane"], f["state"]) for f in fns if f["lane"] in ("game", "lib")]


class Prog:
    """One program of a build: name, base (None: not code), bytes, words (None: not code)."""
    def __init__(self, name, base, data):
        self.name, self.base, self.data = name, base, data
        self.ws = kit.words(data) if base is not None else None
        self.end = base + len(data) if base is not None else None


def programs(exe, exe_name, ovl, vrams):
    """[Prog]: the executable (after its header, at the header's address), then each member of ovl (None: no archive)
    at vrams[index], or not code without one."""
    out = [Prog(exe_name, struct.unpack_from("<I", exe, 0x18)[0], exe[HEADER:])]
    for m in rock.read_toc(ovl) if ovl is not None else []:
        out.append(Prog(f"rock_{m.index:02d}", vrams.get(m.index), ovl[m.sector * rock.SECTOR:][:m.size]))
    return out


def scan_strings(b):
    """{offset: bytes} of b: text_at at each 4-aligned offset after a NUL and each NUL-ended STRING run, a start
    inside a string already read skipped."""
    cands = {o for o in range(0, len(b), 4) if b[o] and (o == 0 or not b[o - 1])}
    cands |= {m.start() for m in kit.STRING.finditer(b) if b[m.end():m.end() + 1] == b"\x00"}
    out, end = {}, 0
    for o in sorted(cands):
        if o < end:
            continue
        t = kit.text_at(b, o)
        if t:
            out[o], end = t[0], o + len(t[0])
    return out


def utf8_lines(b):
    t = b.decode("shift_jis", "backslashreplace").replace("\r\n", "\n").replace("\r", "\n").rstrip("\n")
    return len(t.encode("utf-8")), t.count("\n") + 1


def str_class(b, table):
    n, lines = utf8_lines(b)
    return "table" if table else "story" if n > 256 or lines >= 4 else "dialogue" if lines > 1 or n > 64 else "short"


def build_strings(progs, fns=None):
    """([dict(prog, vram, sha1, n, cls, enc, refs, text)] in program then address order, {start source: lui count},
    [every program's name]). progs: programs(), the executable first. fns: {prog: [(vram, words)] sorted}
    (the census), or None."""
    exe, code = progs[0], [p for p in progs if p.base is not None]
    lo, hi = min(p.base for p in code), max(p.end for p in code)

    def holders(q, x):
        if q.base <= x < q.end:
            return [q]
        if exe.base <= x < exe.end:
            return [exe]
        return [r for r in code if r.base != q.base and r.base <= x < r.end] if lo <= x < hi else []

    refs_of = {q.name: kit.refs(q.ws, q.base) for q in code}
    cand = {p.name: set() for p in progs}
    for q in code:
        for x in set(q.ws) | set(refs_of[q.name]):
            for r in holders(q, x):
                cand[r.name].add(x)
    strs = {}
    for p in progs:
        found = scan_strings(p.data)
        base = p.base or 0
        for x in cand[p.name]:
            if x - base not in found:
                t = kit.text_at(p.data, x - base)
                if t:
                    found[x - base] = t[0]
        strs[p.name] = {base + o: b for o, b in found.items()}
    in_table, tables = set(), {}
    for q in code:
        reach = {x for x in set(q.ws) if any(x in strs[r.name] for r in holders(q, x))}
        for t, xs in kit.pointer_tables(q.ws, q.base, reach).items():
            members = [(r.name, x) for x in xs for r in holders(q, x) if x in strs[r.name]]
            in_table.update(members)
            tables.setdefault(q.name, []).append((t, t + 4 * len(xs), members))
    starts = {u: [v for v, _ in fs] for u, fs in (fns or {}).items()}
    how, refs = {"list": 0, "scan": 0}, {}

    def owner(q, c):
        k = bisect_right(starts.get(q.name, []), c) - 1
        if k >= 0 and c < fns[q.name][k][0] + 4 * fns[q.name][k][1]:
            how["list"] += 1
            return f"{q.name}:0x{fns[q.name][k][0]:08X}"
        how["scan"] += 1
        return f"{q.name}:0x{kit.start_of(q.ws, q.base, c):08X}"

    for q in code:
        for x, luis in refs_of[q.name].items():
            for r in holders(q, x):
                hit = [(r.name, x)] if x in strs[r.name] else []
                hit += [m for t, e, ms in tables.get(r.name, []) if t <= x < e for m in ms]
                if hit:
                    who = {owner(q, c) for c in luis}
                    for m in hit:
                        refs.setdefault(m, set()).update(who)
    out = []
    for p in progs:
        for x, b in sorted(strs[p.name].items()):
            out.append(dict(prog=p.name, vram=f"0x{x:08X}" if p.base is not None else f"+0x{x:X}",
                            sha1=hashlib.sha1(b).hexdigest(), n=len(b), cls=str_class(b, (p.name, x) in in_table),
                            enc="sjis" if max(b) > 0x7F else "ascii",
                            refs=",".join(sorted(refs.get((p.name, x), ()))) or "unreferenced", text=b))
    return out, how, [p.name for p in progs]


def string_table(builds):
    """The text of docs/leads/strings.tsv. builds: [(build, build_strings() rows, program names)], retail first."""
    rows, counts = [], []
    for build, ss, names in builds:
        for p in names:
            mine = [s for s in ss if s["prog"] == p]
            for c in CLASSES:
                cs = [s for s in mine if s["cls"] == c]
                counts.append(f"# count\t{build}\t{p}\t{c}\t{len(cs)}\tascii {sum(s['enc'] == 'ascii' for s in cs)}\t"
                              f"sjis {sum(s['enc'] == 'sjis' for s in cs)}\t"
                              f"unreferenced {sum(s['refs'] == 'unreferenced' for s in cs)}\n")
        rows += ["\t".join((s["prog"], s["vram"], s["sha1"], str(s["n"]), s["cls"], s["enc"], s["refs"], build)) + "\n"
                 for s in ss]
    return (f"# {STRINGS} -- written by tools/mmx6/imgadapter.py strings; do not edit (keys only: the text is in "
            f"ignored {SIDECAR}/)\n# {STRING_COLUMNS}\n" + "".join(rows) + "".join(counts))


def write_sidecars(ss, build=RETAIL, prog=None, root=ROOT):
    """refs/leads/strings/<prog>.tsv (retail) or <build>.<prog>.tsv: every string of ss, with its text; the one writer
    of the sidecars (gamestr.py sidecar calls it). Returns {prog: rows}."""
    (root / SIDECAR).mkdir(parents=True, exist_ok=True)
    out = {}
    for p in dict.fromkeys(s["prog"] for s in ss):
        if prog is not None and p != prog:
            continue
        lines = [SIDECAR_HEADER] + [f"{s['vram']}\t{s['sha1']}\t{s['n']}\t{s['cls']}\t{kit.shown(s['text'])}"
                                    for s in ss if s["prog"] == p]
        name = f"{p}.tsv" if build == RETAIL else f"{build}.{p}.tsv"
        (root / SIDECAR / name).write_text("\n".join(lines) + "\n", encoding="utf-8")
        out[p] = len(lines) - 1
    return out


def retail_vrams(root=ROOT):
    """(the executable's unit and file, {member index: vram}) of config/oracle.units.tsv."""
    rows = kit.contract(root / UNITS, kit.UNIT_COLUMNS)
    exe = next(r for r in rows if r[5] == "exe")
    return (exe[0], exe[1]), {int(r[0][5:]): int(r[3], 16) for r in rows if r[0].startswith("rock_")}


def census(root=ROOT):
    """{prog: [(vram, words)] sorted} of .run/oracle/functions.tsv, or None without it."""
    fns = kit.functions(root / FUNCTIONS)
    if fns is None:
        return None
    out = {}
    for u, v, n, *_ in fns:
        out.setdefault(u, []).append((v, n))
    return {u: sorted(fs) for u, fs in out.items()}


def retail_strings(root=ROOT):
    """build_strings() of retail, with the census when present."""
    (unit, file), vrams = retail_vrams(root)
    iso = kit.retail_dir(root, None)
    return build_strings(programs((iso / file).read_bytes(), unit, (iso / OVL).read_bytes(), vrams), census(root))


def cmd_strings(a):
    builds = [(RETAIL, *retail_strings())]
    _, vrams = retail_vrams()
    for spec in a.proto:
        bid, folder, exe = kit.build_spec(spec)
        ovl = Path(folder) / OVL
        progs = programs((Path(folder) / exe).read_bytes(), Path(exe).name,
                         ovl.read_bytes() if ovl.is_file() else None, vrams)
        builds.append((bid, *build_strings(progs)))
    text = string_table([(b, ss, names) for b, ss, _, names in builds])
    for b, ss, how, names in builds:
        print(f"{TAG} strings {b}: {len(ss)} strings in {len(names)} programs, "
              f"{sum(s['refs'] != 'unreferenced' for s in ss)} referenced; starts list {how['list']} scan {how['scan']}")
    if a.check:
        old = (ROOT / STRINGS).read_text() if (ROOT / STRINGS).is_file() else ""
        if old != text:
            print(f"{TAG} strings --check FAIL: {STRINGS} is stale: run strings again")
            return 1
        print(f"{TAG} strings --check OK")
        return 0
    (ROOT / STRINGS).write_text(text, newline="\n")
    for b, ss, _, _ in builds:
        write_sidecars(ss, b)
    print(f"{TAG} strings: {STRINGS} {text.count(chr(10)) - 2} lines; sidecars in {SIDECAR}/")
    return 0


def write(path, rows, cols, how):
    path.parent.mkdir(parents=True, exist_ok=True)
    with open(path, "w", newline="\n") as f:
        f.write(f"# {path.relative_to(ROOT) if path.is_relative_to(ROOT) else path.name} -- written by "
                f"tools/mmx6/imgadapter.py {how}; do not edit\n# {cols}\n" + "".join("\t".join(r) + "\n" for r in rows))


def cmd_units(a):
    root = Path(a.retail_root) if a.retail_root else ROOT
    for p in (root / ISO / EXE, root / ISO / OVL, ROOT / LOADMAP):
        if not p.is_file():
            die(f"{p} missing (--retail-root: an mmx6 checkout with its extracted files)")
    rows = unit_rows((root / ISO / EXE).read_bytes(), (root / ISO / OVL).read_bytes(), ROOT / LOADMAP)
    write(ROOT / UNITS, rows, UNIT_COLUMNS, "units")
    print(f"{TAG} units: {len(rows)} rows ({len(rows) - 1} members of {OVL} with class code)")
    return 0


def cmd_functions(a):
    if not Path(a.functions).is_file():
        die(f"{a.functions} missing (build/corpus/functions.jsonl, written by tools/mmx6/corpus.py)")
    rows = function_rows([json.loads(x) for x in Path(a.functions).read_text().splitlines() if x])
    write(ROOT / FUNCTIONS, rows, FUNCTION_COLUMNS, "functions")
    print(f"{TAG} functions: {len(rows)} rows ({sum(r[4] == 'game' for r in rows)} game, "
          f"{sum(r[4] == 'lib' for r in rows)} lib)")
    return 0


def selftest():
    fails = []

    def case(name, ok, text):
        print(f"self-test: {name} {'pass' if ok else 'FAIL'} ({text})")
        if not ok:
            fails.append(name)

    exe = bytearray(HEADER + 4 * 40)
    exe[:8], exe[0x18:0x1C] = b"PS-X EXE", struct.pack("<I", 0x80010000)
    member = {2: 72, 33: 82}
    toc, data = b"", b""
    for i in range(rock.COUNT):
        b = bytes(4 * member.get(i, 1))
        toc += struct.pack("<II", rock.HEADER // rock.SECTOR + len(data) // rock.SECTOR, len(b))
        data += b + bytes(-len(b) % rock.SECTOR)
    ovl = toc + bytes(rock.HEADER - len(toc)) + data
    with tempfile.TemporaryDirectory() as tmp:
        lm = Path(tmp) / "loadmap.txt"
        lm.write_text("exe 0x80010000 code exe-header\n2 0x800E9860 code planted\n33 0x800FA000 code planted\n13 - data -\n")
        rows = unit_rows(bytes(exe), ovl, lm)
    at2, at33 = rock.HEADER + 2 * rock.SECTOR, rock.HEADER + 33 * rock.SECTOR    # one sector per member
    case("units", rows == [(EXE, EXE, "0x800", "0x80010000", "40", "exe"),
                           ("rock_02", OVL, f"0x{at2:X}", "0x800E9860", "72", "code"),
                           ("rock_33", OVL, f"0x{at33:X}", "0x800FA000", "82", "code")],
         "the executable at its header's address; the code members at their file offsets and loadmap bases")
    fns = [dict(prog=EXE, vram="0x80010000", words=12, name="f0", state="c", lane="game", tu="a"),
           dict(prog="rock_33", vram="0x800FA000", words=50, name="vendor", state="asm", lane="lib", tu="libc"),
           dict(prog=EXE, vram="0x80010030", words=3, name="pad", state="asm", lane="other", tu="a")]
    case("functions", function_rows(fns) == [(EXE, "0x80010000", "12", "f0", "game", "c"),
                                             ("rock_33", "0x800FA000", "50", "lib:libc:vendor", "lib", "asm")],
         "a game row by its name, a lib row by its signature's, any other lane left out")
    base, blob, at = 0x80010000, bytearray(4 * 8), {}
    for name, b in (("short", b"HELLO WORLD"), ("story", b"l1\nl2\nl3\nl4"), ("t1", b"TABLE1A"), ("t2", b"TABLE2B"),
                    ("dialogue", b"\x82\xa0\n\x82\xa2")):
        at[name] = base + len(blob)
        blob += b + bytes(4 - len(b) % 4)
    at["tbl"] = base + len(blob)
    blob += struct.pack("<II", at["t1"], at["t2"])
    lui, add = (lambda rt, a: kit.i_type(15, 0, rt, a >> 16)), (lambda op, rt, a: kit.i_type(op, rt, rt, a & 0xFFFF))
    blob[:32] = struct.pack("<8I", lui(4, at["short"]), add(9, 4, at["short"]), kit.JR_RA, 0,
                            lui(2, at["tbl"]), add(9, 2, at["tbl"]), kit.JR_RA, 0)
    exe = bytearray(HEADER) + blob
    exe[:8], exe[0x18:0x1C] = b"PS-X EXE", struct.pack("<I", base)
    body2 = struct.pack("<4I", lui(5, at["story"]), add(13, 5, at["story"]), kit.JR_RA, 0)
    toc, data = b"", b""
    for i in range(rock.COUNT):
        b = body2 if i == 2 else b"NOCODE STRING\x00\x00\x00" if i == 13 else bytes(4)
        toc += struct.pack("<II", rock.HEADER // rock.SECTOR + len(data) // rock.SECTOR, len(b))
        data += b + bytes(-len(b) % rock.SECTOR)
    progs = programs(bytes(exe), EXE, toc + bytes(rock.HEADER - len(toc)) + data, {2: 0x800E9860})
    ss, how, names = build_strings(progs, {EXE: [(base, 4)]})
    got = {(s["prog"], s["vram"]): (s["cls"], s["enc"], s["refs"]) for s in ss}
    f0, f1, r2 = f"{EXE}:0x{base:08X}", f"{EXE}:0x{base + 16:08X}", "rock_02:0x800E9860"
    want = {(EXE, f"0x{at['short']:08X}"): ("short", "ascii", f0), (EXE, f"0x{at['story']:08X}"): ("story", "ascii", r2),
            (EXE, f"0x{at['t1']:08X}"): ("table", "ascii", f1), (EXE, f"0x{at['t2']:08X}"): ("table", "ascii", f1),
            (EXE, f"0x{at['dialogue']:08X}"): ("dialogue", "sjis", "unreferenced"),
            ("rock_13", "+0x0"): ("short", "ascii", "unreferenced")}
    text = string_table([(RETAIL, ss, names)])
    with tempfile.TemporaryDirectory() as tmp:
        side = write_sidecars(ss, "proto-2001-01-01", root=Path(tmp))
        heads = {p.name: p.read_text().splitlines()[0] for p in (Path(tmp) / SIDECAR).glob("*.tsv")}
    case("strings", got == want and how == {"list": 1, "scan": 2} and len(names) == 1 + rock.COUNT
         and f"# count\t{RETAIL}\t{EXE}\ttable\t2\tascii 2\tsjis 0\tunreferenced 0\n" in text
         and f"# count\t{RETAIL}\trock_41\tshort\t0\tascii 0\tsjis 0\tunreferenced 0\n" in text
         and "HELLO" not in text and side == {EXE: 5, "rock_13": 1}
         and heads == {f"proto-2001-01-01.{EXE}.tsv": SIDECAR_HEADER, "proto-2001-01-01.rock_13.tsv": SIDECAR_HEADER},
         "a text by code, a table, an exe text from an overlay, sjis, a member that is no code; keys only, all classes")
    print(f"{TAG} CONTROL " + ("FAIL " + " ".join(fails) if fails else "OK"))
    return 1 if fails else 0


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("--self-test", action="store_true")
    sub = ap.add_subparsers(dest="cmd")
    u = sub.add_parser("units", help=UNITS)
    u.add_argument("--retail-root", help="an mmx6 checkout with extracted/retail/iso/ (default: this one)")
    f = sub.add_parser("functions", help=FUNCTIONS)
    f.add_argument("--functions", required=True, help="X6's function list (build/corpus/functions.jsonl)")
    s = sub.add_parser("strings", help=f"{STRINGS} and {SIDECAR}/")
    s.add_argument("--proto", action="append", default=[], help="<id>:<the build's folder>:<its executable>")
    s.add_argument("--check", action="store_true", help=f"{STRINGS} regenerated in memory must equal the tracked one")
    a = ap.parse_args(argv)
    if a.self_test:
        return selftest()
    if a.cmd == "units":
        return cmd_units(a)
    if a.cmd == "functions":
        return cmd_functions(a)
    if a.cmd == "strings":
        return cmd_strings(a)
    ap.print_usage(sys.stderr)
    return 2


if __name__ == "__main__":
    sys.exit(main())
