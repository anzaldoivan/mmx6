#!/usr/bin/env python3
"""repro.py -- run the codegen-map reproducers: every tell compiled, checked against its own disassembly (container,
stdlib only).

  repro.py --all [--root D]
      every <D>/**/*.c (default D = repro, sorted): compiled through the product C rule (probe.compile_obj, Makefile
      default TRIPLE); the header's `expect:` regex re.search(..., re.M) over the function's disassembly (mipsel
      objdump, one `<mnemonic> <operands>` line per instruction, numeric registers, no address column, no bytes,
      `<sym+off>` annotations dropped, trimmed after the last `jr $31` + delay slot); a `dump:` fragment must be on a
      line of <base>.<pass> made by dumps.run (pass maspsx: <base>.s, cc1's asm = maspsx's input).
      -> per file `REPRO <path> OK|FAIL <why> <t>s`; last line `REPRO <ok> of <r> tells reproduced`;
         rc 1 if any FAIL or r = 0.
  repro.py --lever L<nn> [--map-dir D]
      the row `L<nn> | <group> | tell: ... | mechanism: <pass> src:... | lever: ... | proof: repro/<group>/<id> | ...`
      of <D>/*.md (default docs/codegen-map) -> pair <id>.a.c, <id>.b.c: both reproduce (as --all); masked words
      (probe.elf_function) of a and b differ; a's `diff:` holds (below); row pass == a's `pass:`.
      -> `LEVER L<nn> OK <tell>` rc 0 | `LEVER L<nn> FAIL <why>` rc 1.
  repro.py --self-test
      planted controls only, in .run/repro-selftest/ (C0054): a battery (one OK, one wrong expect, one missing
      expect -> `REPRO 1 of 3`, rc 1); a planted map row L99 over a planted $4/$5 swap pair -> OK; negatives FAIL
      (b identical to a, wrong diff: kind, dump fragment absent, row absent). Ends `REPRO CONTROL OK`, else
      `REPRO CONTROL FAIL <why>` rc 1.

Header: the `//` lines at the top of the .c:
  // tell: <text>                 required
  // pass: <dumps.SUFFIXES | maspsx>  required
  // expect: <python regex>       required
  // dump: <verbatim fragment of one line of <base>.<pass>>   optional
  // func: <name>                 optional; default the only function symbol (> 1 without func: -> FAIL)
  // diff: <kind>                 on <id>.a.c of a pair; b measured against a:
      regs $A $B   equal length; b == a with $A/$B swapped, except callee-save slot lines `sw|lw $A|$B,<n>($29)`
                   (each register keeps its own stack slot), which are compared as a multiset, unswapped
      order        same instruction-line multiset, different sequence
      branch       same multiset of non-branch lines, branch mnemonic multisets differ
      isel         mnemonic multisets differ
      length <d>   len(b) - len(a) == d
Firewall G12: our own C only; prints paths, counts and reasons, never retail bytes.
"""
import argparse
import collections
import glob
import os
import re
import shutil
import subprocess
import sys
import time

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.normpath(os.path.join(HERE, "..", ".."))
sys.path.insert(0, HERE)
import dumps  # noqa: E402
import probe  # noqa: E402

OBJDUMP = "mipsel-linux-gnu-objdump"
OUT = "build/dumps"
SELFTEST = ".run/repro-selftest"
PASSES = tuple(dumps.SUFFIXES) + ("maspsx",)
HDR = re.compile(r"//\s*(tell|pass|expect|dump|func|diff):\s?(.*?)\s*$")
INSN = re.compile(r"^\s*[0-9a-f]+:\s+(\S+)\s*(.*?)\s*$")
FUNC_SYM = re.compile(r"\sF\s+\.text\S*\s+[0-9a-f]+\s+(\S+)\s*$")
SAVE = r"^(sw|lw) \$(%s|%s),-?\d+\(\$29\)$"


def triple():
    with open("Makefile") as f:
        m = re.search(r"^TRIPLE\s*\?=\s*(\S+)", f.read(), re.M)
    if not m:
        raise RuntimeError("no `TRIPLE ?=` line in Makefile")
    return m.group(1)


def header(src):
    h = {}
    with open(src) as f:
        for line in f:
            if not line.startswith("//"):
                break
            m = HDR.match(line)
            if m:
                h[m.group(1)] = m.group(2)
    return h


def run(argv):
    p = subprocess.run(argv, capture_output=True, text=True)
    if p.returncode != 0:
        raise RuntimeError(f"{argv[0]} rc {p.returncode}: {p.stderr.strip()[-200:]}")
    return p.stdout


def functions(obj):
    return [m.group(1) for m in map(FUNC_SYM.search, run([OBJDUMP, "-t", obj]).splitlines()) if m]


def disasm(obj, func):
    """`<mnemonic> <operands>` per instruction of func, trimmed after the last `jr $31` + delay slot (C0021)."""
    out = run([OBJDUMP, "-d", "--no-show-raw-insn", "-M", "gpr-names=numeric", f"--disassemble={func}", obj])
    lines = []
    for x in out.splitlines():
        m = INSN.match(x)
        if m:
            ops = re.sub(r"\s*<[^>]*>", "", m.group(2))
            lines.append(f"{m.group(1)} {ops}".strip())
    for i in range(len(lines) - 1, -1, -1):
        if lines[i] == "jr $31":
            return lines[: i + 2]
    return lines


def check(src, tri):
    """(ok, why, header, obj, func, disasm lines) of one reproducer."""
    h = header(src)
    for k in ("tell", "pass", "expect"):
        if not h.get(k):
            return False, f"no {k}:", h, None, None, None
    if h["pass"] not in PASSES:
        return False, f"pass {h['pass']} not a dumps suffix or maspsx", h, None, None, None
    obj = probe.compile_obj(src, tri)
    if obj is None:
        return False, "compile failed", h, None, None, None
    fs = functions(obj)
    func = h.get("func") or (fs[0] if len(fs) == 1 else None)
    if func is None:
        return False, f"{len(fs)} function symbols, no func:", h, obj, None, None
    if func not in fs:
        return False, f"func {func} not in object", h, obj, None, None
    lines = disasm(obj, func)
    try:
        if not re.search(h["expect"], "\n".join(lines), re.M):
            return False, "expect not in disassembly", h, obj, func, lines
    except re.error as e:
        return False, f"expect regex: {e}", h, obj, func, lines
    if h.get("dump"):
        key = os.path.splitext(src)[0]
        outdir = os.path.join(OUT, key)
        rc, _ = dumps.run(src, key, outdir, out=lambda s: None)
        base = os.path.basename(key)
        dump = os.path.join(outdir, f"{base}.{'s' if h['pass'] == 'maspsx' else h['pass']}")
        if rc or not os.path.isfile(dump):
            return False, f"no dump {dump}", h, obj, func, lines
        with open(dump, errors="replace") as f:
            if not any(h["dump"] in x for x in f):
                return False, f"dump fragment not in {dump}", h, obj, func, lines
    return True, "", h, obj, func, lines


def run_all(root, out=print):
    tri = triple()
    srcs = sorted(glob.glob(os.path.join(root, "**", "*.c"), recursive=True))
    ok = 0
    for s in srcs:
        t = time.monotonic()
        try:
            good, why = check(s, tri)[:2]
        except RuntimeError as e:
            good, why = False, str(e)
        ok += good
        out(f"REPRO {s} {'OK' if good else 'FAIL ' + why} {time.monotonic() - t:.2f}s")
    out(f"REPRO {ok} of {len(srcs)} tells reproduced")
    return 0 if srcs and ok == len(srcs) else 1


def find_row(lnn, map_dir):
    for md in sorted(glob.glob(os.path.join(map_dir, "*.md"))):
        with open(md) as f:
            for line in f:
                cells = [c.strip() for c in line.strip().strip("|").split("|")]
                if cells and cells[0].lstrip("-* ") == lnn:
                    return {c.split(":", 1)[0]: c.split(":", 1)[1].strip() for c in cells[2:] if ":" in c}
    return None


def diff_holds(kind, a, b):
    k = kind.split()
    if not k:
        return "empty diff:"
    if k[0] == "regs" and len(k) == 3:
        ra, rb = k[1], k[2]
        if len(a) != len(b):
            return "regs: lengths differ"
        sw = {ra: rb, rb: ra}
        save = re.compile(SAVE % (re.escape(ra[1:]), re.escape(rb[1:])))
        keep_a = [x for x in a if not save.match(x)]
        keep_b = [x for x in b if not save.match(x)]
        if collections.Counter(a) - collections.Counter(keep_a) != collections.Counter(b) - collections.Counter(keep_b):
            return "regs: callee-save slot lines differ"
        swapped = [re.sub(r"\$\d+\b", lambda m: sw.get(m.group(0), m.group(0)), x) for x in keep_a]
        return "" if swapped == keep_b else f"regs: b is not a with {ra}/{rb} swapped"
    if k[0] == "order" and len(k) == 1:
        if collections.Counter(a) != collections.Counter(b) or a == b:
            return "order: not the same lines in a different sequence"
        return ""
    if k[0] == "branch" and len(k) == 1:
        isb = re.compile(r"^b(?!reak)")
        nb = [collections.Counter(x for x in s if not isb.match(x)) for s in (a, b)]
        bm = [collections.Counter(x.split()[0] for x in s if isb.match(x)) for s in (a, b)]
        return "" if nb[0] == nb[1] and bm[0] != bm[1] else "branch: non-branch lines differ or branches equal"
    if k[0] == "isel" and len(k) == 1:
        ma, mb = (collections.Counter(x.split()[0] for x in s) for s in (a, b))
        return "" if ma != mb else "isel: mnemonic multisets equal"
    if k[0] == "length" and len(k) == 2 and re.fullmatch(r"-?\d+", k[1]):
        return "" if len(b) - len(a) == int(k[1]) else f"length: b-a = {len(b) - len(a)}, not {k[1]}"
    return f"unknown diff: {kind}"


def lever(lnn, map_dir, base="."):
    """(rc, line)."""
    def fail(why):
        return 1, f"LEVER {lnn} FAIL {why}"
    row = find_row(lnn, map_dir)
    if row is None:
        return fail(f"row absent in {map_dir}")
    proof, mech = row.get("proof", ""), row.get("mechanism", "").split()
    if not proof.startswith("repro/") or not mech:
        return fail("row lacks proof: repro/... or mechanism: <pass>")
    stem = os.path.join(base, proof)
    a, b = stem + ".a.c", stem + ".b.c"
    if not (os.path.isfile(a) and os.path.isfile(b)):
        return fail(f"no pair {stem}.{{a,b}}.c")
    if not header(a).get("diff"):
        return fail(f"no diff: in {a}")
    tri = triple()
    ra = check(a, tri)
    if not ra[0]:
        return fail(f"{a}: {ra[1]}")
    wa = probe.elf_function(ra[3], ra[4])
    rb = check(b, tri)  # compiles b; a's object copy is read above, before b's compile
    if not rb[0]:
        return fail(f"{b}: {rb[1]}")
    wb = probe.elf_function(rb[3], rb[4])

    def masked(wm):
        return [w & ~wm[1].get(i, 0) & 0xFFFFFFFF for i, w in enumerate(wm[0])]
    if masked(wa) == masked(wb):
        return fail("a and b identical (masked words)")
    why = diff_holds(ra[2]["diff"], ra[5], rb[5])
    if why:
        return fail(why)
    if mech[0] != ra[2]["pass"]:
        return fail(f"row pass {mech[0]} != a's pass: {ra[2]['pass']}")
    return 0, f"LEVER {lnn} OK {row.get('tell', '')}"


SUB = "extern int g(int);\nint f(int a, int b)\n{\n    return %s;\n}\n"


def self_test():
    lines, fails = [], []

    def ok(cond, what):
        lines.append(f"REPRO CONTROL {'ok' if cond else 'FAIL'} {what}")
        if not cond:
            fails.append(what)

    shutil.rmtree(SELFTEST, ignore_errors=True)

    def plant(rel, hdr, body):
        p = os.path.join(SELFTEST, rel)
        os.makedirs(os.path.dirname(p), exist_ok=True)
        with open(p, "w") as f:
            f.write("".join(f"// {k}: {v}\n" for k, v in hdr) + body)

    sub = SUB % "a - b"
    hdr = [("tell", "a - b subtracts $5 from $4"), ("pass", "rtl")]
    plant("battery/ok.c", hdr + [("expect", r"^subu \$2,\$4,\$5$")], sub)
    plant("battery/wrong.c", hdr + [("expect", r"^subu \$2,\$5,\$4$")], sub)
    plant("battery/noexpect.c", hdr, sub)
    got = []
    rc = run_all(os.path.join(SELFTEST, "battery"), got.append)
    lines.extend(got)
    st = {x.split()[1]: x.split()[2] for x in got[:-1]}
    ok(st.get(os.path.join(SELFTEST, "battery/ok.c")) == "OK", "planted ok.c OK")
    ok(st.get(os.path.join(SELFTEST, "battery/wrong.c")) == "FAIL", "wrong expect FAIL")
    ok(st.get(os.path.join(SELFTEST, "battery/noexpect.c")) == "FAIL", "missing expect FAIL")
    ok(got[-1:] == ["REPRO 1 of 3 tells reproduced"] and rc == 1, "battery counts `REPRO 1 of 3`, rc 1")

    exp_a, exp_b = r"^subu \$2,\$4,\$5$", r"^subu \$2,\$5,\$4$"
    frag = "(minus:SI"
    pairs = {  # id: (a's diff:, a's dump:, b's body)
        "swap": ("regs $4 $5", frag, SUB % "b - a"),
        "same": ("regs $4 $5", frag, sub),
        "kind": ("order", frag, SUB % "b - a"),
        "nodump": ("regs $4 $5", "(no-such-fragment", SUB % "b - a"),
    }
    rows = []
    for n, (pid, (kind, dump, bbody)) in zip((99, 98, 97, 96), pairs.items()):
        plant(f"repro/G-test/{pid}.a.c", hdr + [("expect", exp_a), ("dump", dump), ("diff", kind)], sub)
        plant(f"repro/G-test/{pid}.b.c", hdr + [("expect", exp_b if bbody != sub else exp_a)], bbody)
        rows.append(f"L{n} | G-test | tell: planted {pid} | mechanism: rtl src:gcc-2.95.2/gcc/expr.c:1 \"x\" | "
                    f"lever: operand order | proof: repro/G-test/{pid} | retail: -\n")
    os.makedirs(os.path.join(SELFTEST, "map"), exist_ok=True)
    with open(os.path.join(SELFTEST, "map", "G-test.md"), "w") as f:
        f.write("# G-test (planted by repro.py --self-test)\n" + "".join(rows))
    mapd = os.path.join(SELFTEST, "map")
    for lnn, want, what in (("L99", "OK", "planted regs-swap pair OK"),
                            ("L98", "FAIL a and b identical", "b identical to a FAIL"),
                            ("L97", "FAIL order:", "wrong diff: kind FAIL"),
                            ("L96", "FAIL " + os.path.join(SELFTEST, "repro/G-test/nodump.a.c") + ": dump fragment",
                             "dump fragment absent FAIL"),
                            ("L95", "FAIL row absent", "row absent FAIL")):
        rc, line = lever(lnn, mapd, SELFTEST)
        lines.append(line)
        ok(line.startswith(f"LEVER {lnn} {want}") and rc == (0 if want == "OK" else 1), what)
    lines.append("REPRO CONTROL OK" if not fails else f"REPRO CONTROL FAIL {'; '.join(fails)}")
    for x in lines:
        print(x)
    return 1 if fails else 0


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    g = ap.add_mutually_exclusive_group(required=True)
    g.add_argument("--all", action="store_true")
    g.add_argument("--lever", metavar="L<nn>")
    g.add_argument("--self-test", action="store_true")
    ap.add_argument("--root", default="repro")
    ap.add_argument("--map-dir", default="docs/codegen-map")
    a = ap.parse_args()
    root = os.path.relpath(os.path.abspath(a.root), ROOT)
    map_dir = os.path.abspath(a.map_dir)
    os.chdir(ROOT)
    try:
        if a.self_test:
            return self_test()
        if a.all:
            return run_all(root)
        rc, line = lever(a.lever, map_dir)
        print(line)
        return rc
    except RuntimeError as e:
        print(f"repro: {e}")
        return 1


if __name__ == "__main__":
    sys.exit(main())
