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
  imgadapter.py --self-test
      A planted executable and archive (synthetic words, no game data): the units rows. Last line `IMGTAB CONTROL OK`.

Then, from the repository: `python3 tools/psxd_img.py proto --id <id> --build <folder> --exe <its executable>`,
`strnames [--proto <id>:<folder>:<executable>]... [--check]`, `show <key>`. config/oracle.retail names
extracted/retail/iso.
"""
import argparse
import json
import os
import struct
import sys
import tempfile
from pathlib import Path

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
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
    a = ap.parse_args(argv)
    if a.self_test:
        return selftest()
    if a.cmd == "units":
        return cmd_units(a)
    if a.cmd == "functions":
        return cmd_functions(a)
    ap.print_usage(sys.stderr)
    return 2


if __name__ == "__main__":
    sys.exit(main())
