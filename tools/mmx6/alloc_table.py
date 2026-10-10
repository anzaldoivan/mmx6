#!/usr/bin/env python3
"""alloc_table.py -- per-function register-allocation table of one C unit from cc1 2.95.2's .lreg/.greg dumps
(container, stdlib only). Formula and dump-line citations: docs/codegen-map/G-alloc.md.

  alloc_table.py --src <c> [--func f]          any repo-relative .c (dumps key = its basename without .c)
  alloc_table.py --tu <prog>/<tu> [--func f]   src/<prog>/<tu>.c (dumps key = <prog>/<tu>)
      makes the dumps through dumps.run (the C rule's own recipe), then per function of .lreg (`;; Function f`):
      one row per pseudo of .lreg's `Register N used R times across L insns[ in block B]…` lines:
        `<pseudo> refs <r> live <l> block <b|-> pref <h[,h…]|-> prio <p> hard <h|->`
        pref = .greg `;; P preferences:` hard regs; hard = .greg `;; Register dispositions:` (2.95's greg dump does
        print the final hard regs: local-alloc's and global-alloc's both, before reload);
        prio = global-alloc's priority int(((floor_log2(refs)*refs)/live)*10000*size) (double, truncated toward 0;
        size = ceil(bytes/4), default 1; live 0 -> -1; floor_log2(0) = -1); a tied pseudo (`p+t` in the order line)
        gets its allocno's: refs summed, live = max, size = max.
      then `ALLOC <key>:<func> pseudos <n> order <k>` (k = K of `;; K regs to allocate:`; local-alloc's pseudos,
      `;; Register N in H.`, are never in the order line).
      -> `ALLOC MISSING <key>:<func> <p>`       an order-line pseudo (or tied pseudo) absent from .lreg, rc 1
      -> `ALLOC TRUNCATED <key>:<func> <what>`  no .greg block / order line / dispositions header, rc 1 (no order
                                               line is order 0, not TRUNCATED, when no .lreg pseudo has live != -1:
                                               global.c dumps none when max_allocno == 0)
      --func f absent from .lreg -> `ALLOC NOFUNC <key>:<f>` rc 2.
  alloc_table.py --self-test
      plants A and B (identical but for reference counts; x, y each live across a call and a branch) in
      .run/alloc-selftest/: x, y are in the order line (not local-alloc's); A orders x before y, B y before x; each
      order line equals the table's prio-descending order (tie: lower pseudo); x, y hard regs swap 16<->17 between
      A and B; A's .greg cut before `;; Register dispositions:` -> TRUNCATED rc!=0; an order line naming a pseudo
      absent from .lreg -> MISSING rc!=0. Ends `ALLOC CONTROL OK` (rc 0), else `ALLOC CONTROL FAIL <why>` rc 1.
"""
import argparse
import math
import os
import re
import shutil
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import dumps  # noqa: E402

ROOT = dumps.ROOT
SELFTEST = ".run/alloc-selftest"
FUNC = re.compile(r";; Function (\S+)")
REG = re.compile(r"Register (\d+) used (\d+) times across (\d+) insns(?: in block (\d+))?([;.].*)$")
BYTES = re.compile(r"; (\d+) bytes")
LOCAL = re.compile(r";; Register (\d+) in (\d+)\.")
ORDER = re.compile(r";; (\d+) regs to allocate:(.*)$")
PREF = re.compile(r";; (\d+) preferences:(.*)$")
DISP = re.compile(r"(\d+) in (\d+)")
# A plant: identical but for reference counts (EXTRA_X / EXTRA_Y extra uses of x / y after the call).
PLANT = """extern int g(int);
extern int h(int, int);
int f(int a, int b)
{
    int x = a * 3;
    int y = b * 5;
    if (g(a)) { x += 1; y += 2; }
    g(0);
%s    return h(x, y);
}
"""


def floor_log2(n):
    return n.bit_length() - 1 if n > 0 else -1


def prio(refs, live, size):
    live = -1 if live == 0 else live
    return int(((floor_log2(refs) * refs) / live) * 10000 * size)


def sections(path):
    """{func: [lines]} of a dump, split at `;; Function f`; None if the file is absent."""
    if not os.path.isfile(path):
        return None
    out, cur = {}, None
    with open(path, "rb") as f:
        for ln in f.read().decode("latin-1").split("\n"):
            m = FUNC.match(ln)
            if m:
                cur = out.setdefault(m.group(1), [])
            elif cur is not None:
                cur.append(ln)
    return out


def parse_order(rest):
    """`p1 p2+t (s) …` -> [[p1], [p2, t], …]."""
    out = []
    for tok in rest.split():
        if tok.startswith("("):
            continue
        out.append([int(x) for x in tok.split("+")])
    return out


def table(key, func, lreg, greg):
    """-> (rc, lines, order [[p…]], rows {p: row dict}) for one function."""
    regs, local = {}, {}
    for ln in lreg:
        m = REG.match(ln)
        if m and int(m.group(1)) not in regs:
            b = BYTES.search(m.group(5))
            regs[int(m.group(1))] = dict(refs=int(m.group(2)), live=int(m.group(3)), block=m.group(4),
                                         size=max(1, -(-int(b.group(1)) // 4)) if b else 1)
        m = LOCAL.match(ln)
        if m:
            local[int(m.group(1))] = int(m.group(2))
    tag = f"{key}:{func}"
    if greg is None:
        return 1, [f"ALLOC TRUNCATED {tag} no .greg block"], [], {}
    order, k, prefs, hard, disp = None, 0, {}, {}, False
    for ln in greg:
        m = ORDER.match(ln)
        if m and order is None:
            k, order = int(m.group(1)), parse_order(m.group(2))
            continue
        m = PREF.match(ln)
        if m:
            prefs[int(m.group(1))] = m.group(2).split()
            continue
        if ln.startswith(";; Register dispositions:"):
            disp = True
            continue
        if disp:
            if ln.startswith(";;"):
                disp = None
            else:
                for p, r in DISP.findall(ln):
                    hard[int(p)] = int(r)
    if order is None:  # global.c:498 dumps no order line when max_allocno == 0: no pseudo with live != -1
        if any(r["live"] != -1 for r in regs.values()):
            return 1, [f"ALLOC TRUNCATED {tag} no order line"], [], {}
        order = []
    if disp is False:
        return 1, [f"ALLOC TRUNCATED {tag} no dispositions header"], order, {}
    miss = [p for grp in order for p in grp if p not in regs]
    if miss:
        return 1, [f"ALLOC MISSING {tag} {p}" for p in miss], order, {}
    group = {p: grp for grp in order for p in grp}
    rows, out = {}, []
    for p in sorted(regs):
        grp = group.get(p, [p])
        r = regs[p]
        pr = prio(sum(regs[q]["refs"] for q in grp), max(regs[q]["live"] for q in grp),
                  max(regs[q]["size"] for q in grp))
        rows[p] = dict(r, prio=pr, hard=hard.get(p))
        pref = ",".join(prefs.get(grp[0], [])) or "-"
        out.append(f"{p} refs {r['refs']} live {r['live']} block {r['block'] or '-'} pref {pref} prio {pr} "
                   f"hard {hard.get(p, '-')}")
    out.append(f"ALLOC {tag} pseudos {len(regs)} order {k}")
    return 0, out, order, rows


def unit(key, base_path, func=None, out=print):
    """Table of every function (or func) of base_path.lreg/.greg; -> rc."""
    lreg, greg = sections(base_path + ".lreg"), sections(base_path + ".greg")
    if lreg is None:
        out(f"ALLOC TRUNCATED {key}:- no .lreg")
        return 1
    if func is not None and func not in lreg:
        out(f"ALLOC NOFUNC {key}:{func}")
        return 2
    rc = 0
    for f in ([func] if func else lreg):
        r, lines, _, _ = table(key, f, lreg[f], None if greg is None else greg.get(f))
        for x in lines:
            out(x)
        rc = rc or r
    return rc


def self_test():
    lines, fails = [], []

    def ok(cond, what):
        lines.append(f"ALLOC CONTROL {'ok' if cond else 'FAIL'} {what}")
        if not cond:
            fails.append(what)

    shutil.rmtree(SELFTEST, ignore_errors=True)
    os.makedirs(SELFTEST)
    more = {"a": "    x = h(x, x) + x * x;\n", "b": "    y = h(y, y) + y * y;\n"}
    got = {}
    for name, extra in more.items():
        c = os.path.join(SELFTEST, name + ".c")
        with open(c, "w") as f:
            f.write(PLANT % extra)
        d = os.path.join(SELFTEST, "out-" + name)
        rc, _ = dumps.run(c, "selftest-" + name, d, lines.append)
        base = os.path.join(d, name)
        lreg, greg = sections(base + ".lreg"), sections(base + ".greg")
        good = rc == 0 and lreg is not None and greg is not None and "f" in lreg and "f" in greg
        ok(good, f"plant {name} compiles with -da, f in .lreg and .greg")
        if not good:
            continue
        rc, tl, order, rows = table("selftest-" + name, "f", lreg["f"], greg["f"])
        lines.extend(tl)
        ok(rc == 0, f"plant {name} table rc 0")
        local = {int(m.group(1)) for m in map(LOCAL.match, lreg["f"]) if m}
        flat = [grp[0] for grp in order]
        want = sorted(flat, key=lambda p: (-rows[p]["prio"], p)) if rc == 0 else None
        ok(flat == want, f"plant {name} order line {flat} == prio-descending {want}")
        got[name] = (flat, rows, local)
    if len(got) == 2:
        (fa, ra, la), (fb, rb, lb) = got["a"], got["b"]
        xy = sorted(set(fa) & set(fb))
        ok(len(xy) == 2 and not (set(xy) & (la | lb)), f"x, y = {xy} in both order lines, not local-alloc's")
        if len(xy) == 2:
            x, y = xy
            ok(fa.index(x) < fa.index(y), f"A orders x {x} before y {y}: {fa}")
            ok(fb.index(y) < fb.index(x), f"B orders y {y} before x {x}: {fb}")
            ha, hb = (ra[x]["hard"], ra[y]["hard"]), (rb[x]["hard"], rb[y]["hard"])
            ok(ha == (16, 17) and hb == (17, 16), f"x, y hard regs A {ha} B {hb} swap 16<->17")
        # negative controls on planted copies of A's .greg (never a real unit)
        d = os.path.join(SELFTEST, "out-a")
        greg = open(os.path.join(d, "a.greg"), encoding="latin-1").read()
        cut = os.path.join(SELFTEST, "trunc")
        os.makedirs(cut)
        shutil.copy(os.path.join(d, "a.lreg"), os.path.join(cut, "a.lreg"))
        with open(os.path.join(cut, "a.greg"), "w", encoding="latin-1") as f:
            f.write(greg[:greg.index(";; Register dispositions:")])
        tl = []
        rc = unit("selftest-trunc", os.path.join(cut, "a"), "f", tl.append)
        lines.extend(tl)
        ok(rc != 0 and any(t.startswith("ALLOC TRUNCATED selftest-trunc:f") for t in tl), "truncated .greg TRUNCATED")
        mis = os.path.join(SELFTEST, "missing")
        os.makedirs(mis)
        shutil.copy(os.path.join(d, "a.lreg"), os.path.join(mis, "a.lreg"))
        with open(os.path.join(mis, "a.greg"), "w", encoding="latin-1") as f:
            f.write(re.sub(r"(;; \d+ regs to allocate:)", r"\1 9999", greg, count=1))
        tl = []
        rc = unit("selftest-missing", os.path.join(mis, "a"), "f", tl.append)
        lines.extend(tl)
        ok(rc != 0 and "ALLOC MISSING selftest-missing:f 9999" in tl, "order pseudo absent from .lreg MISSING")
    for x in lines:
        print(x)
    print("ALLOC CONTROL OK" if not fails else f"ALLOC CONTROL FAIL {'; '.join(fails)}")
    return 1 if fails else 0


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    g = ap.add_mutually_exclusive_group(required=True)
    g.add_argument("--src", metavar="C")
    g.add_argument("--tu", metavar="PROG/TU")
    g.add_argument("--self-test", action="store_true")
    ap.add_argument("--func", metavar="F")
    a = ap.parse_args()
    src = a.src and os.path.relpath(os.path.abspath(a.src), ROOT)
    os.chdir(ROOT)
    try:
        if a.self_test:
            return self_test()
        if a.tu:
            prog, name = a.tu.split("/", 1)
            c, key, d = f"src/{prog}/{name}.c", a.tu, os.path.join(dumps.OUT, prog, name)
        else:
            name = os.path.splitext(os.path.basename(src))[0]
            c, key, d = src, name, os.path.join(dumps.OUT, name)
        rc, _ = dumps.run(c, key, d)
        if rc:
            return rc
        return unit(key, os.path.join(d, name), a.func)
    except RuntimeError as e:
        print(f"alloc_table: {e}")
        return 1


if __name__ == "__main__":
    sys.exit(main())
