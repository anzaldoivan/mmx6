#!/usr/bin/env python3
"""badges.py -- the README's shields.io endpoint badges: docs/badges/*.json from the tree (stdlib, no network).

  badges.py --write       regenerate docs/badges/*.json.
  badges.py --maps [DIR]  (container, after a build) parse the GNU ld maps DIR/<prog>.map (default build/) into
                          the tracked snapshot config/data_bytes.tsv, then --write.
  badges.py --check       regenerate in memory; `BADGES STALE <name>` per differing or missing file (rc 1); when
                          build/*.map exist, also `BADGES STALE data_bytes <prog>` per snapshot row that differs from
                          the maps (rc 1); else `BADGES OK 8 badges` (rc 0).
  badges.py --self-test   planted dir under .run/<phase>/badges-selftest/ (removed at the end): one stale and one
                          fresh badge; check names only the stale one; a planted git tree with one two-function role
                          file (src/<prog>/<system>/, beside an INCLUDE_ASM stub; file state `stubs`) counts 1
                          finished, 1 matched of 3 functions; a fixture map parses to its counts; a planted stale
                          snapshot row and a planted stale data badge are named. Ends `BADGES CONTROL OK` rc 0.

Badges (each `{"schemaVersion": 1, "label", "message", "color"}` + newline)
  functions        named function symbols over all function symbols of config/symbols.*.txt (renamecov's parser).
                   A function symbol: a `func_<8 hex>[_tag]` placeholder, or a named symbol whose basis tier is not
                   slot (data). Data: `D_` placeholders and slot-tier names.
                   Segment symbols are skipped. Named: not a placeholder.
  finished         finished C files over all C files (psxd_floor file_states, the `debt --files` line).
  function-states  per function over the same C files, however many functions a file holds (a role file, a
                   src/shared body): each C body of psxd_floor debt_bodies is finished (no debt kind in the body)
                   or matched (some); each INCLUDE_ASM stub (psxd_floor scan_file `stubs`) counts in the total only.
                   File-scope debt (psxd_floor SCOPE: externs, a placeholder file name) is the file's, not a
                   function's. Message `<finished> / <matched> of <total>`, colour by finished share.
  debt-<cat>       cat in main, rock, sdk: pin, barrier, goto and placeholder counts summed over the cat's C files.
                   A unit file takes its category from gen_objdiff.collect(). Any other C file takes the categories
                   of the units that include it, transitively, once per category. A debt-bearing file with none fails.
                   src/probes/ (planted probe copies, no unit) stays out of the debt badges, in the finished total.
  data-main, data-rock  from config/data_bytes.tsv (numbers only; no build needed): C bytes over all bytes of
                   SLUS_013.95, and of the rock_* overlays summed. Bytes: input sections named .data .rodata .sdata
                   .bss .sbss COMMON .scommon in the map's memory-map part, outside /DISCARD/ and the .header output
                   section (the PS-X EXE header); *fill* skipped. C: the object is build/src/**.c.o.
Colours: percent >= 100 brightgreen, >= 90 green, >= 60 yellow, >= 30 orange, else red.
         debt by pins + barriers: 0 brightgreen, < 500 yellow, < 1500 orange, else red.
"""
import argparse
import ast
import json
import os
import re
import shutil
import subprocess
import sys
import types
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / "tools"))
import psxd_floor  # noqa: E402
import psxd_publish  # noqa: E402
from mmx6 import renamecov  # noqa: E402

OUT = ROOT / "docs/badges"
CATS = ("main", "rock", "sdk")
DEBT_KEYS = ("pin", "barrier", "goto", "placeholder")
PROBES = "src/probes/"
INCLUDE = re.compile(r'^\s*#\s*include\s+"([^"]+)"', re.M)
SNAPSHOT = ROOT / "config/data_bytes.tsv"
MAIN_PROG = "SLUS_013.95"
DATA_SECS = {".data", ".rodata", ".sdata", ".bss", ".sbss", "COMMON", ".scommon"}
SKIP_OUT = {"/DISCARD/", ".header"}
MAP_START = "Linker script and memory map"
INPUT = re.compile(r"^ (\S+)\s+0x[0-9a-fA-F]+\s+0x([0-9a-fA-F]+)\s+(\S+)")
SPLIT_NAME = re.compile(r"^ (\S+)$")
SPLIT_REST = re.compile(r"^\s+0x[0-9a-fA-F]+\s+0x([0-9a-fA-F]+)\s+(\S+)")
C_OBJ = re.compile(r"^build/src/.+\.c\.o$")


class Fail(Exception):
    pass


def load_gen_objdiff():
    """tools/gen_objdiff.py as a module. It calls main() at import, so its top-level bare calls are dropped first."""
    path = ROOT / "tools/gen_objdiff.py"
    tree = ast.parse(path.read_text(), str(path))
    tree.body = [n for n in tree.body if not (isinstance(n, ast.Expr) and isinstance(n.value, ast.Call))]
    mod = types.ModuleType("gen_objdiff")
    mod.__file__ = str(path)
    exec(compile(tree, str(path), "exec"), mod.__dict__)
    return mod


def pct_colour(p):
    return "brightgreen" if p >= 100 else "green" if p >= 90 else "yellow" if p >= 60 else "orange" if p >= 30 else "red"


def debt_colour(n):
    return "brightgreen" if n == 0 else "yellow" if n < 500 else "orange" if n < 1500 else "red"


def badge(label, message, colour):
    return json.dumps({"schemaVersion": 1, "label": label, "message": message, "color": colour}) + "\n"


def ratio(label, n, total):
    p = 100.0 * n / total if total else 0.0
    return badge(label, "%d/%d (%.1f%%)" % (n, total, p), pct_colour(p))


def render(named, functions, finished, files, debt, fstates=(0, 0, 0)):
    """{name: text} of the six badges; `debt`: {cat: {key: count}}; `fstates`: (finished, matched, total) functions."""
    out = {"functions": ratio("named functions", named, functions), "finished": ratio("finished files", finished, files)}
    fin, mat, tot = fstates
    out["function-states"] = badge("functions finished / matched", "%d / %d of %d" % (fin, mat, tot),
                                   pct_colour(100.0 * fin / tot if tot else 0.0))
    for c in CATS:
        d = debt[c]
        msg = "%d pins / %d barriers / %d gotos / %d placeholders" % tuple(d[k] for k in DEBT_KEYS)
        out["debt-" + c] = badge("debt: " + c, msg, debt_colour(d["pin"] + d["barrier"]))
    return out


def data_badges(snap):
    """{name: text} of data-main and data-rock from a snapshot {prog: (c_bytes, all_bytes)}."""
    out = {}
    for key, progs in (("main", [p for p in snap if p == MAIN_PROG]), ("rock", [p for p in snap if p.startswith("rock_")])):
        if not progs:
            raise Fail("%s: no %s row" % (SNAPSHOT.relative_to(ROOT), key))
        c = sum(snap[p][0] for p in progs)
        a = sum(snap[p][1] for p in progs)
        p = 100.0 * c / a if a else 0.0
        out["data-" + key] = badge("data in C: " + key, "%d/%d bytes (%.1f%%)" % (c, a, p), pct_colour(p))
    return out


def parse_map(text):
    """(c_bytes, all_bytes) of one GNU ld map: see the data badges in the module doc."""
    c = a = 0
    on, out_sec, pend = False, None, None
    for line in text.splitlines():
        if not on:
            on = line.startswith(MAP_START)
            continue
        if pend is not None:
            name, pend = pend, None
            m = SPLIT_REST.match(line)
            if m:
                size, obj = int(m.group(1), 16), m.group(2)
                if name in DATA_SECS and out_sec not in SKIP_OUT:
                    a += size
                    c += size if C_OBJ.match(obj) else 0
                continue
        if line[:1] not in ("", " ", "\t"):
            tok = line.split()[0]
            if not tok.startswith(("LOAD", "OUTPUT(")):
                out_sec = tok
            continue
        m = INPUT.match(line)
        if m:
            if m.group(1) in DATA_SECS and out_sec not in SKIP_OUT:
                size = int(m.group(2), 16)
                a += size
                c += size if C_OBJ.match(m.group(3)) else 0
            continue
        m = SPLIT_NAME.match(line)
        if m and m.group(1) != "*fill*":
            pend = m.group(1)
    if not on:
        raise Fail("not a GNU ld map (no %r line)" % MAP_START)
    return c, a


def parse_maps(d):
    """{prog: (c_bytes, all_bytes)} of every d/<prog>.map."""
    out = {}
    for f in sorted(Path(d).glob("*.map")):
        try:
            out[f.stem] = parse_map(f.read_text(errors="replace"))
        except Fail as e:
            raise Fail("%s: %s" % (f, e))
    return out


def snapshot_text(snap):
    rows = ["# data_bytes.tsv -- generated by tools/mmx6/badges.py --maps (container, after a build); never hand-edited.",
            "# Per prog: input-section bytes of .data .rodata .sdata .bss .sbss COMMON .scommon (see badges.py doc).",
            "# prog\tc_bytes\tall_bytes"]
    rows += ["%s\t%d\t%d" % (p, c, a) for p, (c, a) in sorted(snap.items())]
    return "\n".join(rows) + "\n"


def read_snapshot(path=SNAPSHOT):
    if not path.is_file():
        raise Fail("%s missing: run `make badges` in the container" % path.relative_to(ROOT))
    out = {}
    for n, line in enumerate(path.read_text().splitlines(), 1):
        if not line.strip() or line.startswith("#"):
            continue
        f = line.split("\t")
        if len(f) != 3 or not f[1].isdigit() or not f[2].isdigit():
            raise Fail("%s:%d: want `prog<TAB>c_bytes<TAB>all_bytes`" % (path.relative_to(ROOT), n))
        out[f[0]] = (int(f[1]), int(f[2]))
    return out


def stale_snapshot(snap, maps):
    """The progs whose snapshot row is missing, extra or differs from the parsed maps, sorted."""
    return sorted(p for p in set(snap) | set(maps) if snap.get(p) != maps.get(p))


def function_counts():
    """(named, all) function symbols of config/symbols.*.txt, by renamecov's parser and placeholder pattern."""
    slot = {(r[0], r[2]) for r in renamecov.read_tsv(ROOT / "config/symbols/basis.tsv") if len(r) >= 6 and r[5] == "slot"}
    named = total = 0
    for prog, table in sorted(renamecov.read_symbols(ROOT / "config").items()):
        for name in sorted(table):
            if renamecov.segment(prog, name):
                continue
            m = renamecov.PLACEHOLDER.match(name)
            if m:
                total += m.group(1) == "func"
            elif (prog, name) not in slot:
                total += 1
                named += 1
    return named, total


def function_states(states, tree):
    """(finished, matched, total) functions of the C files of psxd_floor.file_states(states, on `tree`): see the
    function-states badge. Reads psxd_floor's data only (debt_bodies with file_states' skip; scan_file stubs)."""
    skip = psxd_floor.parse_baseline(tree.read(psxd_floor.BASELINE)).skip
    bodies = psxd_floor.debt_bodies(tree.repo, skip, tree)
    fin = mat = stubs = 0
    for _, p, _ in states:
        for name, got in bodies.get(p, {}).items():
            if name != psxd_floor.SCOPE:
                mat += any(got.values())
                fin += not any(got.values())
        stubs += psxd_floor.scan_file(p, tree.read(p) or "", address_header=psxd_floor.address_header(tree))["stubs"]
    return fin, mat, fin + mat + stubs


def unit_categories():
    """{src path: category} of the C units, from gen_objdiff.collect() (run from the repo root)."""
    here = os.getcwd()
    os.chdir(ROOT)
    try:
        units, _ = load_gen_objdiff().collect()
    finally:
        os.chdir(here)
    out = {}
    for u in units:
        if u["kind"] == "c":
            cat = [c for c in CATS if c in u["cats"]]
            if len(cat) != 1:
                raise Fail("unit %s: categories %s hold not exactly one of %s" % (u["src"], u["cats"], ",".join(CATS)))
            out[u["src"]] = cat[0]
    return out


def includes(path, memo):
    """The repo-relative files that `path` includes directly (relative to its folder, then include/)."""
    if path not in memo:
        try:
            text = (ROOT / path).read_text(errors="replace")
        except OSError:
            text = ""
        got = []
        for inc in INCLUDE.findall(text):
            for cand in (os.path.normpath(os.path.join(os.path.dirname(path), inc)), os.path.normpath("include/" + inc)):
                if not cand.startswith("..") and (ROOT / cand).is_file():
                    got.append(cand)
                    break
        memo[path] = sorted(set(got))
    return memo[path]


def file_categories():
    """{path: set of categories}: each unit its own; each file a unit includes (transitively) the unit's."""
    out = {}
    memo = {}
    for src, cat in sorted(unit_categories().items()):
        seen, todo = set(), [src]
        while todo:
            p = todo.pop()
            if p in seen:
                continue
            seen.add(p)
            out.setdefault(p, set()).add(cat)
            todo.extend(includes(p, memo))
    return out


def compute():
    rows, errs = psxd_publish.load_categories(ROOT / "config/categories.tsv")
    ids = {r["id"] for r in rows or []}
    missing = [c for c in CATS if c not in ids]
    if rows is None or errs or missing:
        raise Fail("config/categories.tsv: %s" % ("; ".join(errs) or "missing %s" % ",".join(missing or ["file"])))
    tree = psxd_floor.Tree(ROOT)
    states = psxd_floor.file_states(ROOT, tree)
    cats = file_categories()
    debt = {c: dict.fromkeys(DEBT_KEYS, 0) for c in CATS}
    unmapped = []
    for _, p, got in states:
        if not cats.get(p):
            if got and not p.startswith(PROBES):
                unmapped.append(p)
            continue
        for c in sorted(cats[p]):
            for k in DEBT_KEYS:
                debt[c][k] += got.get(k, 0)
    if unmapped:
        raise Fail("debt-bearing C file(s) in no category: %s" % " ".join(sorted(unmapped)))
    named, functions = function_counts()
    finished = sum(1 for s in states if s[0] == "finished")
    out = render(named, functions, finished, len(states), debt, function_states(states, tree))
    out.update(data_badges(read_snapshot()))
    return out


def write(badges, out):
    out.mkdir(parents=True, exist_ok=True)
    for name, text in sorted(badges.items()):
        (out / (name + ".json")).write_text(text)


def stale(badges, out):
    """The names whose file in `out` is missing or differs, sorted."""
    bad = []
    for name, text in sorted(badges.items()):
        f = out / (name + ".json")
        if not f.is_file() or f.read_text() != text:
            bad.append(name)
    return bad


def check(badges, out, maps=None, snap=None):
    """`maps` (parsed build maps, or None when there are none) is compared with `snap` (the snapshot)."""
    bad = stale(badges, out)
    for name in bad:
        print("BADGES STALE %s" % name)
    progs = stale_snapshot(snap, maps) if maps else []
    for p in progs:
        print("BADGES STALE data_bytes %s" % p)
    if bad or progs:
        return 1
    print("BADGES OK %d badges" % len(badges))
    return 0


ROLE_FILE = ('INCLUDE_ASM("asm/P/nonmatchings/r", run_stub);\n\nvoid walk(void) {\n}\n\n'
             'void step(int x) {\n    if (x) goto out;\n    x++;\nout:\n    return;\n}\n')

FIXTURE_MAP = """Discarded input sections

 .data          0x00000000       0x99 build/src/P/gone.c.o

Memory Configuration

Linker script and memory map

LOAD build/src/P/a.c.o
.header         0x00000000      0x800
 .data          0x00000000      0x800 build/asm/P/header.s.o

.main           0x80010000      0x200 load address 0x00000800
 FILL mask 0x00000000
 build/src/P/a.c.o(.rodata)
 .rodata        0x80010000       0x10 build/src/P/a.c.o
                0x80010000                D_80010000
 .rodata        0x80010010       0x20 build/asm/P/data/10010.rodata.s.o
 .text          0x80010030      0x100 build/src/P/a.c.o
 *fill*         0x80010130        0x4
 build/src/P/a.c.o(.data)
 .data
                0x80010134        0x8 build/src/P/a.c.o
 .sdata         0x8001013c        0x4 build/src/P/b.c.o
 COMMON         0x80010140       0x40 build/asm/P/c.s.o
 .gnu.attributes
                0x00000000       0x10 build/src/P/a.c.o
/DISCARD/
 *(*)
 .data          0x00000000       0x77 build/src/P/a.c.o
OUTPUT(build/P.elf elf32-tradlittlemips)
"""


def selftest():
    tmp = renamecov.phase_scratch(ROOT) / "badges-selftest"
    shutil.rmtree(tmp, ignore_errors=True)
    try:
        d = {c: dict.fromkeys(DEBT_KEYS, 0) for c in CATS}
        d["rock"]["pin"] = 600
        want = render(3, 10, 0, 4, d)
        write(want, tmp)
        (tmp / "functions.json").write_text(ratio("named functions", 2, 10))
        got = stale(want, tmp)
        if got != ["functions"]:
            print("BADGES CONTROL FAIL stale %s, want functions" % (",".join(got) or "none"))
            return 1
        if json.loads(want["debt-rock"])["color"] != "orange" or json.loads(want["functions"])["color"] != "orange":
            print("BADGES CONTROL FAIL colour")
            return 1
        repo = tmp / "role"                          # a two-function role file beside a stub, in a planted git tree
        (repo / "src/P/sys").mkdir(parents=True)
        (repo / "src/P/sys/r.c").write_text(ROLE_FILE)
        for args in (["init", "--quiet"], ["add", "-A"]):
            subprocess.run(["git"] + args, cwd=repo, check=True)
        tree = psxd_floor.Tree(repo)
        states = psxd_floor.file_states(repo, tree)
        got = function_states(states, tree)
        if [s[:2] for s in states] != [("stubs", "src/P/sys/r.c")] or got != (1, 1, 3):
            print("BADGES CONTROL FAIL role file: states %s functions %s, want stubs and (1, 1, 3)" % (states, got))
            return 1
        maps = tmp / "maps"                          # fixture maps: split names, *fill*, .text, header, /DISCARD/
        maps.mkdir()
        (maps / "SLUS_013.95.map").write_text(FIXTURE_MAP)
        (maps / "rock_00.map").write_text(FIXTURE_MAP.replace("0x10 build/src/P/a.c.o", "0x30 build/src/P/a.c.o"))
        parsed = parse_maps(maps)
        if parsed != {"SLUS_013.95": (0x10 + 0x8 + 0x4, 0x10 + 0x8 + 0x4 + 0x20 + 0x40),
                      "rock_00": (0x30 + 0x8 + 0x4, 0x30 + 0x8 + 0x4 + 0x20 + 0x40)}:
            print("BADGES CONTROL FAIL map parse %s" % parsed)
            return 1
        snap = dict(parsed)
        snap["rock_00"] = (snap["rock_00"][0] - 1, snap["rock_00"][1])
        snapfile = tmp / "data_bytes.tsv"
        snapfile.write_text(snapshot_text(snap))
        if read_snapshot(snapfile) != snap or stale_snapshot(read_snapshot(snapfile), parsed) != ["rock_00"]:
            print("BADGES CONTROL FAIL stale snapshot not named")
            return 1
        data = data_badges(parsed)
        write(data, tmp)
        (tmp / "data-main.json").write_text(data_badges(snap)["data-rock"])
        if check(data, tmp, parsed, parsed) != 1 or stale(data, tmp) != ["data-main"]:
            print("BADGES CONTROL FAIL stale data badge not named")
            return 1
        if json.loads(data["data-main"])["message"] != "28/124 bytes (22.6%)":
            print("BADGES CONTROL FAIL data message %s" % json.loads(data["data-main"])["message"])
            return 1
    finally:
        shutil.rmtree(tmp, ignore_errors=True)
    print("BADGES CONTROL OK")
    return 0


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    g = ap.add_mutually_exclusive_group(required=True)
    g.add_argument("--write", action="store_true")
    g.add_argument("--check", action="store_true")
    g.add_argument("--maps", nargs="?", const="build", metavar="DIR")
    g.add_argument("--self-test", action="store_true")
    a = ap.parse_args(argv)
    if a.self_test:
        return selftest()
    try:
        if a.maps:
            d = ROOT / a.maps
            snap = parse_maps(d)
            if MAIN_PROG not in snap:
                raise Fail("%s: no %s.map (run after a build)" % (d, MAIN_PROG))
            SNAPSHOT.write_text(snapshot_text(snap))
            print("BADGES WROTE data_bytes %d progs" % len(snap))
        badges = compute()
        maps = parse_maps(ROOT / "build") if a.check else None
    except (Fail, psxd_floor.Fail) as e:
        print("BADGES FAIL %s" % e)
        return 1
    if a.check:
        return check(badges, OUT, maps, read_snapshot())
    write(badges, OUT)
    for name in sorted(badges):
        print("BADGES WROTE %s %s" % (name, json.loads(badges[name])["message"]))
    return 0


if __name__ == "__main__":
    sys.exit(main())
