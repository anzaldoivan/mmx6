#!/usr/bin/env python3
"""badges.py -- the README's shields.io endpoint badges: docs/badges/*.json from the tree (stdlib, no network).

  badges.py --write       regenerate docs/badges/*.json.
  badges.py --check       regenerate in memory; `BADGES STALE <name>` per differing or missing file (rc 1),
                          else `BADGES OK 5 badges` (rc 0).
  badges.py --self-test   planted dir under .run/<phase>/badges-selftest/ (removed at the end): one stale and one
                          fresh badge; check names only the stale one. Ends `BADGES CONTROL OK` rc 0.

Badges (each `{"schemaVersion": 1, "label", "message", "color"}` + newline)
  functions        named function symbols over all function symbols of config/symbols.*.txt (renamecov's parser).
                   A function symbol: a `func_<8 hex>[_tag]` placeholder, or a named symbol whose basis tier is not
                   slot (data). Data: `D_` placeholders and slot-tier names.
                   Segment symbols are skipped. Named: not a placeholder.
  finished         finished C files over all C files (psxd_floor file_states, the `debt --files` line).
  debt-<cat>       cat in main, rock, sdk: pin, barrier, goto and placeholder counts summed over the cat's C files.
                   A unit file takes its category from gen_objdiff.collect(). Any other C file takes the categories
                   of the units that include it, transitively, once per category. A debt-bearing file with none fails.
                   src/probes/ (planted probe copies, no unit) stays out of the debt badges, in the finished total.
Colours: percent >= 100 brightgreen, >= 90 green, >= 60 yellow, >= 30 orange, else red.
         debt by pins + barriers: 0 brightgreen, < 500 yellow, < 1500 orange, else red.
"""
import argparse
import ast
import json
import os
import re
import shutil
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


def render(named, functions, finished, files, debt):
    """{name: text} of the five badges; `debt`: {cat: {key: count}}."""
    out = {"functions": ratio("named functions", named, functions), "finished": ratio("finished files", finished, files)}
    for c in CATS:
        d = debt[c]
        msg = "%d pins / %d barriers / %d gotos / %d placeholders" % tuple(d[k] for k in DEBT_KEYS)
        out["debt-" + c] = badge("debt: " + c, msg, debt_colour(d["pin"] + d["barrier"]))
    return out


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
    states = psxd_floor.file_states(ROOT, psxd_floor.Tree(ROOT))
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
    return render(named, functions, finished, len(states), debt)


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


def check(badges, out):
    bad = stale(badges, out)
    for name in bad:
        print("BADGES STALE %s" % name)
    if bad:
        return 1
    print("BADGES OK %d badges" % len(badges))
    return 0


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
    finally:
        shutil.rmtree(tmp, ignore_errors=True)
    print("BADGES CONTROL OK")
    return 0


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    g = ap.add_mutually_exclusive_group(required=True)
    g.add_argument("--write", action="store_true")
    g.add_argument("--check", action="store_true")
    g.add_argument("--self-test", action="store_true")
    a = ap.parse_args(argv)
    if a.self_test:
        return selftest()
    try:
        badges = compute()
    except (Fail, psxd_floor.Fail) as e:
        print("BADGES FAIL %s" % e)
        return 1
    if a.check:
        return check(badges, OUT)
    write(badges, OUT)
    for name in sorted(badges):
        print("BADGES WROTE %s %s" % (name, json.loads(badges[name])["message"]))
    return 0


if __name__ == "__main__":
    sys.exit(main())
