#!/usr/bin/env python3
"""codegen_map.py -- the codegen-map checker: map rows, the triage table, the levers' byte proofs and the gcc source
citations (container, stdlib only).

  codegen_map.py [--groups G-a,G-b] [--map-dir D]     (default: all six groups, D = docs/codegen-map)
      every `L<nn> | ...` row of D/*.md (README.md excluded) is validated:
        `L<nn> | <group> | tell: <text> | mechanism: <pass> src:gcc-2.95.2/<path>:<line> "<frag>" [...] |
         lever: <text> | proof: repro/<group>/<id> | retail: <prog>:<8 hex>|-`
        group == the file's group (file stem); <pass> in that group's pass set (GROUPS); >= 1 src: cite;
        proof == repro/<group>/<id> with <id>.a.c and <id>.b.c present; ids unique across files, ascending per file.
      D/README.md: `## Pass groups` lists exactly GROUPS (`- G-x: <passes> — G-x.md`); `## Triage` rows
      `tell | group | levers | else` (4 fields; tell ends with `sym-<slug>`; levers = comma list of L ids of that
      group's file, or TODO; TODO anywhere in a row counts). Only triage rows of requested groups are checked.
      Each valid row of a requested group: repro.lever (= `repro.py --lever L<nn>`); then `gccsrc.py --check`.
      -> per defect `MAP FAIL <id|file> <why>` / `TRIAGE FAIL <row> <why>`; `LEVER ...` lines from repro;
         gccsrc's non-OK lines and its last line; then `TRIAGE OK <t> rows, 0 TODO` (else
         `TRIAGE FAIL total <t> rows, <n> TODO`); last line `MAP OK <g> of 6 pass groups; levers <l> byte-proven`
         (g = requested groups with >= 1 lever OK; else `MAP FAIL total ...`).
      rc 0 iff no FAIL, cites OK, triage 0 TODO, every requested group has >= 1 OK lever.
  codegen_map.py --self-test
      planted map dirs and one planted $4/$5 swap pair in .run/map-selftest/ (C0054; never the real rows): a good
      row -> OK; negatives FAIL: malformed row, pass not in its group, dangling proof, duplicate id, triage lever
      absent, triage TODO, requested group with 0 levers (no cite check: planted cites do not resolve).
      Ends `MAP CONTROL OK`, else `MAP CONTROL FAIL <why>` rc 1.
Firewall G12: our own C and docs only; prints ids, paths, counts and reasons, never retail bytes.
"""
import argparse
import glob
import os
import re
import shutil
import subprocess
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.normpath(os.path.join(HERE, "..", ".."))
sys.path.insert(0, HERE)
import repro  # noqa: E402

GROUPS = {
    "G-expr": ("rtl", "cse", "addressof", "gcse", "cse2"),
    "G-loop": ("loop",),
    "G-combine": ("combine", "regmove"),
    "G-alloc": ("lreg", "greg", "flow", "flow2"),
    "G-sched": ("sched", "sched2", "mach", "dbr", "maspsx"),
    "G-jump": ("jump", "jump2"),
}
SELFTEST = ".run/map-selftest"
ROW_START = re.compile(r"^\s*[-*]?\s*(L\d+)\s*\|")
ID = re.compile(r"^L\d{2,}$")
CITE = re.compile(r'src:gcc-2\.95\.2/\S+:\d+ "[^"]*"')
RETAIL = re.compile(r"^(-|\w+:[0-9a-fA-F]{8})$")
FIELDS = ("tell", "mechanism", "lever", "proof", "retail")


def parse_row(line, group, base):
    """(id, dict | None, why)."""
    cells = [c.strip() for c in line.strip().lstrip("-* ").strip("|").split("|")]
    lid = cells[0]
    if not ID.match(lid):
        return lid, None, "malformed id"
    if len(cells) != 7:
        return lid, None, f"malformed row: {len(cells)} fields, want 7"
    row = {"id": lid, "group": cells[1]}
    for want, c in zip(FIELDS, cells[2:]):
        k, sep, v = c.partition(":")
        if not sep or k.strip() != want or not v.strip():
            return lid, None, f"malformed row: field `{want}:` missing or empty"
        row[want] = v.strip()
    if row["group"] != group:
        return lid, None, f"group {row['group']} != file group {group}"
    mech = row["mechanism"].split()
    if mech[0] not in GROUPS[group]:
        return lid, None, f"pass {mech[0]} not in {group}"
    if not CITE.search(row["mechanism"]):
        return lid, None, "mechanism has no src:gcc-2.95.2 cite"
    m = re.fullmatch(r"repro/([^/]+)/([\w.-]+)", row["proof"])
    if not m or m.group(1) != group:
        return lid, None, f"proof {row['proof']} not repro/{group}/<id>"
    stem = os.path.join(base, row["proof"])
    if not (os.path.isfile(stem + ".a.c") and os.path.isfile(stem + ".b.c")):
        return lid, None, f"dangling proof: no {stem}.{{a,b}}.c"
    if not RETAIL.match(row["retail"]):
        return lid, None, f"retail {row['retail']} not - or <prog>:<8 hex>"
    return lid, row, ""


def read_rows(map_dir, base, fail):
    """{group: [row]} of valid rows; defects through fail."""
    rows, seen = {g: [] for g in GROUPS}, {}
    for md in sorted(glob.glob(os.path.join(map_dir, "*.md"))):
        name = os.path.basename(md)
        if name == "README.md":
            continue
        group, last = name[:-3], -1
        with open(md, encoding="utf-8") as f:
            lines = [x for x in f if ROW_START.match(x)]
        if lines and group not in GROUPS:
            fail(name, f"rows in a file of no group ({len(lines)})")
            continue
        for x in lines:
            lid, row, why = parse_row(x, group, base)
            if lid in seen:
                fail(lid, f"duplicate id ({seen[lid]}, {name})")
                continue
            seen[lid] = name
            if ID.match(lid):
                if int(lid[1:]) <= last:
                    fail(lid, f"out of order in {name}")
                last = max(last, int(lid[1:]))
            if row is None:
                fail(lid, why)
            else:
                rows[group].append(row)
    return rows, seen


def read_readme(map_dir, groups, seen, fail, tfail):
    """(triage rows of requested groups, TODO count)."""
    path = os.path.join(map_dir, "README.md")
    if not os.path.isfile(path):
        fail("README.md", "absent")
        return 0, 0
    sec, listed, t, todo = None, {}, 0, 0
    with open(path, encoding="utf-8") as f:
        for x in f:
            x = x.rstrip("\n")
            if x.startswith("## "):
                sec = x[3:].strip()
                continue
            if sec == "Pass groups" and x.startswith("- "):
                m = re.fullmatch(r"- (G-[\w-]+): ([\w ]+?) — (\S+)", x.strip())
                if not m:
                    fail("README.md", f"malformed group line: {x[:60]}")
                    continue
                listed[m.group(1)] = (tuple(m.group(2).split()), m.group(3))
            elif sec == "Triage" and "|" in x:
                cells = [c.strip() for c in x.strip().strip("|").split("|")]
                if cells[:2] == ["tell", "group"] or all(set(c) <= set("-: ") for c in cells):
                    continue
                if len(cells) != 4:
                    tfail(x[:60], f"{len(cells)} fields, want 4")
                    continue
                tell, g, levers, _ = cells
                if g not in GROUPS:
                    tfail(tell[:60], f"group {g} unknown")
                    continue
                if g not in groups:
                    continue
                t += 1
                if "TODO" in x:
                    todo += 1
                    tfail(tell[:60], "TODO")
                    continue
                if not re.search(r"sym-[\w-]+$", tell):
                    tfail(tell[:60], "tell does not end with sym-<slug>")
                for lid in (s.strip() for s in levers.split(",")):
                    if seen.get(lid) != f"{g}.md":
                        tfail(tell[:60], f"lever {lid} absent from {g}.md")
    want = {g: (p, f"{g}.md") for g, p in GROUPS.items()}
    if listed != want:
        fail("README.md", "## Pass groups differs from GROUPS")
    return t, todo


def check(groups, map_dir, base=".", cites=True, out=print, memo=None):
    """rc; memo caches repro.lever results by (id, proof, pass, base) across calls (the self-test reuses one pair)."""
    memo = {} if memo is None else memo
    fails, tfails = [], []

    def fail(what, why):
        fails.append(what)
        out(f"MAP FAIL {what} {why}")

    def tfail(what, why):
        tfails.append(what)
        out(f"TRIAGE FAIL {what} {why}")

    rows, seen = read_rows(map_dir, base, fail)
    t, todo = read_readme(map_dir, groups, seen, fail, tfail)
    g_ok, levers = 0, 0
    for g in groups:
        ok = 0
        for row in rows[g]:
            key = (row["id"], row["proof"], row["mechanism"].split()[0], os.path.abspath(base))
            if key not in memo:
                try:
                    memo[key] = repro.lever(row["id"], map_dir, base)
                except RuntimeError as e:
                    memo[key] = (1, f"LEVER {row['id']} FAIL {e}")
            rc, line = memo[key]
            out(line)
            if rc:
                fails.append(row["id"])
            ok += rc == 0
        levers += ok
        if ok:
            g_ok += 1
        else:
            fail(g, "no byte-proven lever")
    cites_ok = True
    if cites:
        p = subprocess.run([sys.executable, os.path.join(HERE, "gccsrc.py"), "--check"],
                           capture_output=True, text=True, cwd=ROOT)
        lines = p.stdout.strip().splitlines()
        for x in lines:
            out(x)
        if not lines:
            out(f"CITES no output rc {p.returncode}")
        cites_ok = p.returncode == 0
    out(f"TRIAGE OK {t} rows, 0 TODO" if not tfails else f"TRIAGE FAIL total {t} rows, {todo} TODO")
    good = not fails and not tfails and cites_ok and g_ok == len(groups)
    out(f"MAP {'OK' if good else 'FAIL total'} {g_ok} of {len(GROUPS)} pass groups; levers {levers} byte-proven")
    return 0 if good else 1


README = ("# Codegen map (planted by codegen_map.py --self-test)\n## Pass groups\n"
          + "".join(f"- {g}: {' '.join(p)} — {g}.md\n" for g, p in GROUPS.items())
          + "## Triage\ntell | group | levers | else\n--- | --- | --- | ---\n")
GOOD = ('L01 | G-expr | tell: planted swap | mechanism: rtl src:gcc-2.95.2/gcc/expr.c:1 "x" | '
        'lever: operand order | proof: repro/G-expr/swap | retail: -\n')
TRIAGE = "planted subtract sym-planted | G-expr | L01 | permuter (T7)\n"


def self_test():
    lines, fails, memo = [], [], {}

    def ok(cond, what):
        lines.append(f"MAP CONTROL {'ok' if cond else 'FAIL'} {what}")
        if not cond:
            fails.append(what)

    shutil.rmtree(SELFTEST, ignore_errors=True)
    hdr = "// tell: a - b subtracts $5 from $4\n// pass: rtl\n"
    for side, expr, exp, extra in (("a", "a - b", r"^subu \$2,\$4,\$5$", "// diff: regs $4 $5\n"),
                                   ("b", "b - a", r"^subu \$2,\$5,\$4$", "")):
        p = os.path.join(SELFTEST, "repro", "G-expr", f"swap.{side}.c")
        os.makedirs(os.path.dirname(p), exist_ok=True)
        with open(p, "w") as f:
            f.write(hdr + f"// expect: {exp}\n" + extra + repro.SUB % expr)

    def case(name, files, groups, want, why):
        d = os.path.join(SELFTEST, name)
        os.makedirs(d, exist_ok=True)
        for fn, body in files.items():
            with open(os.path.join(d, fn), "w") as f:
                f.write(body)
        got = []
        rc = check(groups, d, SELFTEST, cites=False, out=got.append, memo=memo)
        lines.extend(f"  {name}: {x}" for x in got)
        hit = want == "OK" or any(x.startswith(want) and why in x for x in got)
        ok(hit and rc == (0 if want == "OK" else 1) and got[-1].startswith(f"MAP {want if want == 'OK' else 'FAIL'}"),
           f"{name} {want}")

    good = {"README.md": README + TRIAGE, "G-expr.md": "# G-expr\n" + GOOD}
    case("good", good, ["G-expr"], "OK", "")
    case("malformed", dict(good, **{"G-expr.md": "# G-expr\n" + GOOD + "L02 | G-expr | tell: x\n"}),
         ["G-expr"], "MAP FAIL L02", "malformed row")
    case("badpass", dict(good, **{"G-expr.md": "# G-expr\n" + GOOD + GOOD.replace("L01", "L02").replace(
        "mechanism: rtl", "mechanism: loop")}), ["G-expr"], "MAP FAIL L02", "not in G-expr")
    case("dangling", dict(good, **{"G-expr.md": "# G-expr\n" + GOOD + GOOD.replace("L01", "L02").replace(
        "G-expr/swap", "G-expr/nope")}), ["G-expr"], "MAP FAIL L02", "dangling proof")
    case("duplicate", dict(good, **{"G-loop.md": "# G-loop\n" + GOOD.replace("G-expr", "G-loop").replace(
        "mechanism: rtl", "mechanism: loop")}), ["G-expr"], "MAP FAIL L01", "duplicate id")
    case("trilever", dict(good, **{"README.md": README + TRIAGE.replace("L01", "L01,L07")}),
         ["G-expr"], "TRIAGE FAIL", "lever L07 absent")
    case("tritodo", dict(good, **{"README.md": README + TRIAGE.replace("L01", "TODO")}),
         ["G-expr"], "TRIAGE FAIL", "TODO")
    case("nolevers", good, ["G-expr", "G-loop"], "MAP FAIL G-loop", "no byte-proven lever")
    lines.append("MAP CONTROL OK" if not fails else f"MAP CONTROL FAIL {'; '.join(fails)}")
    for x in lines:
        print(x)
    return 1 if fails else 0


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--groups", default=",".join(GROUPS))
    ap.add_argument("--map-dir", default="docs/codegen-map")
    ap.add_argument("--self-test", action="store_true")
    a = ap.parse_args()
    map_dir = os.path.abspath(a.map_dir)
    os.chdir(ROOT)
    if a.self_test:
        return self_test()
    groups = [g.strip() for g in a.groups.split(",") if g.strip()]
    bad = [g for g in groups if g not in GROUPS]
    if bad or not groups:
        print(f"MAP FAIL --groups unknown {','.join(bad) or '(none)'}")
        return 2
    return check(groups, map_dir)


if __name__ == "__main__":
    sys.exit(main())
