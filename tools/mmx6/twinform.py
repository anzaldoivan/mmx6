#!/usr/bin/env python3
"""twinform.py -- the twin-form hazard scanner (3.3 T39; docs/ops/twin-form.md, cookbook C0499; host PY or container
python3, stdlib only). Ported from docs/ops/twin-form/scan.py (marker walk, section C) and twins.py (static control).

An alias window = `#define OLD NEW` lines (blank or comment lines between them allowed), then `#include "../<dir>/*.c"`
(any dir). Per unit of config/c_units.txt (src/<prog>/<tu>.c) the unit is preprocessed (the Makefile's CPP and
CPPFLAGS, -DMMX6_OVERLAY for rock_ units as the build; no such cpp on the host -> clang/cc -E -x c) and its line
markers walked: every include/ header first entered while an alias window is open along the include chain is a first
reach, with class `foreign` (include/mmx6/rock_NN.h, rock_NN != the unit's program), `own` (rock_NN == the program)
or `neutral` (any other header), the names the windows rename and the names left under the owner's names. Every
src/**/*.c: identity pairs (OLD == NEW) and chain pairs (a pair's NEW is another pair's OLD), and windows including
another overlay's own file (src/rock_MM/** from src/rock_NN/**). Baseline config/twinform-baseline.tsv: the foreign
first reaches keyed (unit, body, header) and the chains keyed (file, body, OLD, NEW->NEXT), no line numbers;
`new` = a foreign first reach or chain not in it. Identity pairs are reported, never refused, never baselined.
3.3b T2 (M31): `neutral` = an overlay-local placeholder (func_/D_/jtbl_<8 hex>[_inl], outside main's range from
config/<ver>/main.yaml) declared by a neutral header (include/, not mmx6/rock_NN.h, reached by units of every rock_NN
program), keyed (-, name, header); `order` = a unit first entering a neutral header at or after its first alias window
opens, keyed (unit, -, header). Both are baselined and refused like a foreign first reach.

  twinform.py --all [--root DIR]
      -> build/us/twinform/{first_reach,identity,chain,xown,misses,neutral_set,neutral,order}.tsv (under DIR);
         one line `TWINFORM first <n> foreign <f> own <o> identity <i> chain <c> neutral <x> order <y> new <k>`;
         rc 0 (report-only).
  twinform.py --control <tsv> [--root DIR]
      -> the static control (twins.py): window include lines in src/**/*.c outside src/shared/ whose body directly
         includes mmx6/rock_NN.h; `TWINFORM CONTROL lines <n> files <m> tsv <t> missing <a> extra <b>` (+ one line per
         difference); rc 0 iff equal.
  twinform.py --write-baseline [--root DIR]
      -> rewrites config/twinform-baseline.tsv from the tree's foreign first reaches and chains.
  twinform.py --self-test
      -> planted tree under .run/<phase>/twinform-selftest/ (deleted after): a foreign and an own first reach, a window
         on another overlay's own file, an identity pair, a chain, a neutral and an order case; refusal() names the
         foreign reach, the chain, the neutral and the order case until they are baselined; bank.py's R2 path (window() + twin_cause()) and layout.py's apply check
         (twin_refusals()) refuse them and drop the identity pair. `TWINFORM self-test ok`, rc 0, else FAIL lines, rc 1.

Library: scan(root, units, files, cpp) and refusal(root, units, files, cpp=None, cfg=None) (bank.py, layout.py).
"""
import argparse
import glob
import os
import re
import shutil
import subprocess
import sys
from concurrent.futures import ThreadPoolExecutor
from paths import BUILD, CONFIG_V, MAIN, VERSION  # noqa: E402  (the version axis, 3.3 T37)

ROOT = os.path.dirname(os.path.dirname(os.path.dirname(os.path.abspath(__file__))))
BASELINE = "config/twinform-baseline.tsv"
OUT = f"{BUILD}/twinform"
DEF = re.compile(r"^\s*#\s*define\s+(\w+)\s+(\w+)\s*$")
INC = re.compile(r'^\s*#\s*include\s+"([^"]+)"')
SKIP = re.compile(r"^\s*(//.*|/\*.*\*/)?\s*$")
MARK = re.compile(r'^# (\d+) "([^"]+)"((?: \d)*)')
PERPROG = re.compile(r"^include/mmx6/(rock_\d\d)\.h$")
PP_INC = re.compile(r'^\s*#\s*include\s+"mmx6/rock_\d\d\.h"')
OVL = re.compile(r"^src/(rock_\d\d)/")
PLACE = re.compile(r"^(?:func|D|jtbl)_([0-9A-Fa-f]{8})(?:_inl)?$")  # a placeholder name and its address (T2.c1)
BASE_HEAD = ("# config/twinform-baseline.tsv -- tools/mmx6/twinform.py --write-baseline (3.3 T39): the foreign per-overlay\n"
             "# first reaches (first unit body header) and chains (chain file body OLD NEW->NEXT) the tree holds; no\n"
             "# line numbers. A bank or a layout apply adding a row not listed here is refused.\n"
             "# 3.3b T2: neutral (neutral - name header: a header every rock_NN program reaches declares an overlay-local\n"
             "# placeholder) and order (order unit - header: the unit first enters that neutral header at or after its\n"
             "# first alias window opens).\n")


def _phase_run():
    """The open phase's temp folder, relative (`# Phase <id>` line 1 of the live plan, as tools/run.sh), else .run."""
    try:
        with open(os.path.join(ROOT, "phase-ends/current/PHASE_PLAN.md")) as f:
            line = f.readline()
    except OSError:
        line = ""
    m = re.match(r"#\s*Phase\s+([A-Za-z0-9._-]+)", line)
    return ".run" if not m or m.group(1) in (".", "..") else os.path.join(".run", m.group(1))


def find_cpp(cfg):
    """(cmd, flags) from cfg's Makefile CPP / CPPFLAGS; no such cpp on PATH -> clang or cc `-E -x c` (host)."""
    cpp, flags = None, ["-nostdinc", "-undef", "-D__GNUC__=2", "-DPSX", f"-DVERSION=VER_{VERSION.upper()}", "-Iinclude"]
    try:
        with open(os.path.join(cfg, "Makefile")) as f:
            for line in f:
                m = re.match(r"^(CPP|CPPFLAGS)\s*:?=\s*(.*)$", line.rstrip("\n"))
                if m and m.group(1) == "CPP":
                    cpp = m.group(2).strip()
                elif m:  # $(VERSION_UC): the Makefile's uppercase VERSION (-DVERSION=VER_<UC>)
                    flags = [t.replace("$(VERSION_UC)", VERSION.upper()) for t in m.group(2).split()]
    except OSError:
        pass
    if cpp and shutil.which(cpp):
        return [cpp], flags
    for c in ("clang", "cc"):
        if shutil.which(c):
            return [c, "-E", "-x", "c"], flags
    return None, flags


def c_units(cfg):
    """[(prog, src/<prog>/<tu>.c)] of cfg's config/c_units.txt."""
    out = []
    with open(os.path.join(cfg, "config/c_units.txt")) as f:
        for line in f:
            if line.startswith("#") or not line.strip():
                continue
            p, t = line.split()[:2]
            out.append((p, f"src/{p}/{t}.c"))
    return out


def windows(root, rel):
    """[(define_line, include_line, include_target, [(old, new)])] for every alias window in root/rel."""
    try:
        with open(os.path.join(root, rel), errors="replace") as f:
            lines = f.read().split("\n")
    except OSError:
        return []
    out, defs, first = [], [], None
    for i, line in enumerate(lines, 1):
        m = DEF.match(line)
        if m:
            if not defs:
                first = i
            defs.append((m.group(1), m.group(2)))
            continue
        m = INC.match(line)
        if m and defs and m.group(1).startswith("../") and m.group(1).endswith(".c"):
            out.append((first, i, m.group(1), list(defs)))
            defs = []
            continue
        if SKIP.match(line) and defs:
            continue
        defs = []
    return out


def decl_names(root, hdr):
    """Identifiers a header declares (extern objects, prototypes, typedef-free top-level names)."""
    names = set()
    try:
        with open(os.path.join(root, hdr), errors="replace") as f:
            txt = re.sub(r"/\*.*?\*/", "", f.read(), flags=re.S)
    except OSError:
        return names
    depth = 0
    for line in txt.split("\n"):
        s = re.sub(r"//.*", "", line).strip()
        if s.startswith("#") or not s:
            continue
        if depth == 0 and s.endswith(";") and not s.startswith(("typedef", "}")):
            m = re.match(r"^[\w\s\*]*?\b(\w+)\s*(\(|\[|;|=)", s)
            if m and m.group(1) not in ("void", "int", "s32", "u32", "u8", "s8", "u16", "s16", "struct", "extern"):
                names.add(m.group(1))
        depth += s.count("{") - s.count("}")
    return names


def hclass(prog, header):
    m = PERPROG.match(header)
    return "neutral" if not m else "own" if m.group(1) == prog else "foreign"


def run_cpp(root, prog, unit, cpp, flags):
    """(preprocessed text, error or '') of unit, as the build preprocesses it."""
    a = cpp + flags + (["-DMMX6_OVERLAY"] if prog.startswith("rock_") else []) + [unit]
    r = subprocess.run(a, cwd=root, stdout=subprocess.PIPE, stderr=subprocess.PIPE, universal_newlines=True)
    if r.returncode:
        return "", "cpp failed: " + (r.stderr.strip().split("\n") or [""])[0][:200]
    return r.stdout, ""


def main_range(root):
    """[lo, hi) of the main program's addresses (config/<ver>/main.yaml: vram to the file end plus bss_size; root's,
    else the repo's)."""
    for base in (root, ROOT):
        try:
            with open(os.path.join(base, CONFIG_V, f"{MAIN}.yaml")) as f:
                txt = f.read()
        except OSError:
            continue
        lo = int(re.search(r"^\s+vram:\s*(0x[0-9A-Fa-f]+)", txt, re.M).group(1), 16)
        st = int(re.search(r"^\s+start:\s*(0x[0-9A-Fa-f]+)", txt, re.M).group(1), 16)
        bss = int(re.search(r"^\s+bss_size:\s*(0x[0-9A-Fa-f]+)", txt, re.M).group(1), 16)
        end = int(re.findall(r"^\s*- \[(0x[0-9A-Fa-f]+)\]\s*$", txt, re.M)[-1], 16)
        return lo, lo + end - st + bss
    raise SystemExit(f"twinform: no {CONFIG_V}/{MAIN}.yaml")


def first_reaches(root, prog, unit, cpp, flags, cache):
    """([row], error or ''): row = (unit, window file:d0-il, body, header, class, renamed, n_left, left);
    cache["reach"][unit] = (prog, {header: entry index}, entry index of the first window opened or None) (T2.c1)."""
    out, err = cache["cpp"].pop(unit, None) or run_cpp(root, prog, unit, cpp, flags)
    if err:
        return [], err
    stack, first, at, wopen, n = [], {}, {}, None, 0
    for line in out.split("\n"):
        m = MARK.match(line)
        if not m:
            if stack:
                stack[-1][1] += 1
            continue
        ln, f, fl = int(m.group(1)), os.path.normpath(m.group(2)), m.group(3).split()
        if "1" in fl:
            n += 1
            if f.startswith("include/") and f not in first:
                first[f] = [tuple(x) for x in stack] + [(f, 0)]
                at[f] = n
            if wopen is None and f.startswith("src/") and stack and stack[-1][0].startswith("src/"):
                par = stack[-1][0]
                if par not in cache["win"]:
                    cache["win"][par] = windows(root, par)
                if any(os.path.normpath(os.path.join(os.path.dirname(par), w[2])) == f for w in cache["win"][par]):
                    wopen = n
            stack.append([f, ln])
        elif "2" in fl or any(s[0] == f for s in stack):
            while stack and stack[-1][0] != f:
                stack.pop()
            if stack:
                stack[-1][1] = ln
            else:
                stack = [[f, ln]]
        else:
            stack.append([f, ln])
    cache["reach"][unit] = (prog, at, wopen)
    rows = []
    for h, chain in sorted(first.items()):
        act = []  # windows open along the chain, outermost first: (file, window)
        for i in range(1, len(chain)):
            par, pl = chain[i - 1]
            if not chain[i][0].startswith("src/") or not par.startswith("src/"):
                continue
            if par not in cache["win"]:
                cache["win"][par] = windows(root, par)
            ws = [w for w in cache["win"][par] if os.path.normpath(os.path.join(os.path.dirname(par), w[2])) == chain[i][0]]
            if ws:
                act.append((par, min(ws, key=lambda w: abs(w[1] - pl))))
        if not act:
            continue
        wf, (d0, il, tgt, _) = act[-1]
        defs = [d for _, w in act for d in w[3]]
        if h not in cache["decl"]:
            cache["decl"][h] = decl_names(root, h)
        olds = {o for o, _ in defs}
        dn = cache["decl"][h]
        ren, left = sorted(dn & olds), sorted(dn - olds)
        body = os.path.normpath(os.path.join(os.path.dirname(wf), tgt))
        rows.append((unit, f"{wf}:{d0}-{il}", body, h, hclass(prog, h), ",".join(ren) or "-", str(len(left)),
                     ",".join(left) or "-"))
    return rows, ""


def pairs(root, files):
    """(identity rows, chain rows, xown rows) of the windows in files (root-relative)."""
    ident, chains, xown = [], [], []
    for f in files:
        mf = OVL.match(f)
        for d0, il, tgt, defs in windows(root, f):
            body = os.path.normpath(os.path.join(os.path.dirname(f), tgt))
            olds = dict(defs)
            for o, n in defs:
                if o == n:
                    ident.append((f, f"{d0}-{il}", body, o, n))
                elif n in olds:
                    chains.append((f, f"{d0}-{il}", body, o, n + "->" + olds[n]))
            mb = OVL.match(body)
            if mf and mb and mb.group(1) != mf.group(1):
                xown.append((f, f"{d0}-{il}", body))
    return ident, chains, xown


def src_files(root):
    return sorted(os.path.relpath(p, root) for p in glob.glob(os.path.join(root, "src/**/*.c"), recursive=True))


def scan(root, units, files, cpp, flags, every=None):
    """dict first, identity, chain, xown, misses, nset, neutral, order over units [(prog, unit)] and files
    (root-relative). nset: the neutral headers (include/, not mmx6/rock_NN.h, reached by units of every rock_NN program
    of every, default units); neutral: (name, header) for each overlay-local placeholder a neutral header declares;
    order: (unit, header) for each neutral header a unit first enters at or after its first alias window opens."""
    every = units if every is None else every
    cache = {"win": {}, "decl": {}, "cpp": {}, "reach": {}}
    todo = [(p, u) for p, u in dict.fromkeys(list(units) + list(every)) if os.path.isfile(os.path.join(root, u))]
    with ThreadPoolExecutor(max_workers=min(8, os.cpu_count() or 1)) as ex:  # the cpp runs, in parallel
        for (p, u), out in zip(todo, ex.map(lambda t: run_cpp(root, t[0], t[1], cpp, flags), todo)):
            cache["cpp"][u] = out
    first, misses = [], []
    for prog, u in units:
        if not os.path.isfile(os.path.join(root, u)):
            misses.append((u, "no file"))
            continue
        rows, err = first_reaches(root, prog, u, cpp, flags, cache)
        first += rows
        if err:
            misses.append((u, err))
    for prog, u in every:
        if u not in cache["reach"] and os.path.isfile(os.path.join(root, u)):
            first_reaches(root, prog, u, cpp, flags, cache)
    progs = {}
    for prog, u in every:
        if prog.startswith("rock_"):
            progs.setdefault(prog, set()).update(cache["reach"].get(u, (0, {}, 0))[1])
    nset = sorted(set.intersection(*progs.values()) if progs else set())
    nset = [h for h in nset if h.startswith("include/") and not PERPROG.match(h)]
    lo, hi = main_range(root)
    neutral = []
    for h in nset:
        if h not in cache["decl"]:
            cache["decl"][h] = decl_names(root, h)
        for name in sorted(cache["decl"][h]):
            m = PLACE.match(name)
            if m and not lo <= int(m.group(1), 16) < hi:
                neutral.append((name, h))
    order = []
    for _, u in units:
        _, at, wopen = cache["reach"].get(u, (0, {}, None))
        order += [(u, h) for h in nset if wopen is not None and h in at and at[h] >= wopen]
    ident, chains, xown = pairs(root, files)
    return dict(first=first, identity=ident, chain=chains, xown=xown, misses=misses, nset=nset, neutral=neutral,
                order=order)


def keys(res):
    """Baseline keys of a scan: ("first", unit, body, header) of foreign rows, ("chain", file, body, old, new),
    ("neutral", "-", name, header), ("order", unit, "-", header)."""
    k = [("first", r[0], r[2], r[3]) for r in res["first"] if r[4] == "foreign"]
    k += [("chain", c[0], c[2], c[3], c[4]) for c in res["chain"]]
    return k + [("neutral", "-", n, h) for n, h in res["neutral"]] + [("order", u, "-", h) for u, h in res["order"]]


def load_baseline(cfg):
    try:
        with open(os.path.join(cfg, BASELINE)) as f:
            return {tuple(line.rstrip("\n").split("\t")) for line in f if line.strip() and not line.startswith("#")}
    except OSError:
        return set()


def cause_of(k):
    if k[0] == "first":
        return f"twinform: foreign first reach {k[3]} under {k[2]} in {k[1]} not in {BASELINE}"
    if k[0] == "neutral":
        return f"twinform: neutral header {k[3]} declares overlay-local {k[2]} not in {BASELINE}"
    if k[0] == "order":
        return f"twinform: order {k[1]} first enters neutral header {k[3]} after its first alias window not in {BASELINE}"
    return f"twinform: chain {k[3]}->{k[4]} in {k[1]} (body {k[2]}) not in {BASELINE}"


def refusal(root, units, files, cpp=None, flags=None, cfg=None):
    """[cause] for every foreign first reach and order case of units, chain of files and neutral case of the tree not
    in cfg's baseline (cfg default root; the neutral set over cfg's config/c_units.txt); a unit cpp cannot preprocess
    is skipped (the build reports it). Identity pairs are never a cause."""
    cfg = cfg or root
    if cpp is None:
        cpp, flags = find_cpp(cfg)
    if cpp is None:
        return ["twinform: no preprocessor"]
    base = load_baseline(cfg)
    res = scan(root, units, files, cpp, flags, every=c_units(cfg))
    return [cause_of(k) for k in keys(res) if k not in base]


def write_tsv(path, head, rows):
    with open(path, "w") as f:
        f.write("\t".join(head) + "\n")
        for r in rows:
            f.write("\t".join(map(str, r)) + "\n")


def cmd_all(root):
    cpp, flags = find_cpp(root)
    if cpp is None:
        print("TWINFORM refused: no preprocessor")
        return 1
    res = scan(root, c_units(root), src_files(root), cpp, flags)
    base = load_baseline(root)
    new = [k for k in keys(res) if k not in base]
    out = os.path.join(root, OUT)
    os.makedirs(out, exist_ok=True)
    write_tsv(f"{out}/first_reach.tsv", ["unit", "window", "body", "header", "class", "renamed", "n_left", "left"],
              res["first"])
    write_tsv(f"{out}/identity.tsv", ["file", "window", "body", "old", "new"], res["identity"])
    write_tsv(f"{out}/chain.tsv", ["file", "window", "body", "old", "new"], res["chain"])
    write_tsv(f"{out}/xown.tsv", ["file", "window", "body"], res["xown"])
    write_tsv(f"{out}/misses.tsv", ["unit", "why"], res["misses"])
    write_tsv(f"{out}/neutral_set.tsv", ["header"], [(h,) for h in res["nset"]])
    write_tsv(f"{out}/neutral.tsv", ["name", "header"], res["neutral"])
    write_tsv(f"{out}/order.tsv", ["unit", "header"], res["order"])
    write_tsv(f"{out}/new.tsv", ["cause"], [(cause_of(k),) for k in new])
    n = len(res["first"])
    f_ = sum(r[4] == "foreign" for r in res["first"])
    o = sum(r[4] == "own" for r in res["first"])
    print(f"TWINFORM first {n} foreign {f_} own {o} identity {len(res['identity'])} chain {len(res['chain'])} "
          f"neutral {len(res['neutral'])} order {len(res['order'])} new {len(new)}")
    return 0


def cmd_write_baseline(root):
    cpp, flags = find_cpp(root)
    if cpp is None:
        print("TWINFORM refused: no preprocessor")
        return 1
    res = scan(root, c_units(root), src_files(root), cpp, flags)
    if res["misses"]:
        print("TWINFORM refused: %d unit(s) not scanned (%s)" % (len(res["misses"]), res["misses"][0][0]))
        return 1
    ks = sorted(set(keys(res)))
    with open(os.path.join(root, BASELINE), "w") as f:
        f.write(BASE_HEAD)
        for k in ks:
            f.write("\t".join(k) + "\n")
    print(f"TWINFORM baseline {len(ks)} rows ({sum(k[0] == 'first' for k in ks)} first, "
          f"{sum(k[0] == 'chain' for k in ks)} chain, {sum(k[0] == 'neutral' for k in ks)} neutral, "
          f"{sum(k[0] == 'order' for k in ks)} order)")
    return 0


def static_control(root):
    """{(file, include line)}: window include lines in src/**/*.c outside src/shared/ whose body directly includes a
    per-overlay header (twins.py)."""
    out = set()
    for p in src_files(root):
        if p.startswith("src/shared"):
            continue
        for _, il, tgt, _ in windows(root, p):
            b = os.path.join(root, os.path.normpath(os.path.join(os.path.dirname(p), tgt)))
            if os.path.isfile(b):
                with open(b, errors="replace") as f:
                    if any(PP_INC.match(x) for x in f):
                        out.add((p, il))
    return out


def cmd_control(root, tsv):
    mine = static_control(root)
    with open(tsv) as f:
        theirs = {(c[0], int(c[1])) for c in (line.split("\t") for line in f if line.strip()) if len(c) >= 2}
    miss, extra = sorted(theirs - mine), sorted(mine - theirs)
    for p, il in miss:
        print(f"TWINFORM control missing {p}:{il}")
    for p, il in extra:
        print(f"TWINFORM control extra {p}:{il}")
    print(f"TWINFORM CONTROL lines {len(mine)} files {len({p for p, _ in mine})} tsv {len(theirs)} "
          f"missing {len(miss)} extra {len(extra)}")
    return int(bool(miss or extra))


# ---- self-test -----------------------------------------------------------------------------------------------------

PLANT = {
    "config/c_units.txt": "# prog tu\nrock_01 U\nrock_02 V\nrock_05 W\n",
    "include/mmx6/rock_02.h": "#ifndef ROCK_02_H\n#define ROCK_02_H\nextern int D_A;\nextern int D_B;\n#endif\n",
    "include/mmx6/x4.h": "#ifndef X4_H\n#define X4_H\nextern int g_N;\n#endif\n",
    "include/mmx6/n.h": "#ifndef N_H\n#define N_H\nextern int D_80100000;\nextern int D_80020000;\n#endif\n",
    "src/shared/rock_02/body.c": '#include "mmx6/rock_02.h"\nint body(void) { return D_A + D_B; }\n',
    "src/rock_02/own.c": '#include "mmx6/n.h"\n#include "mmx6/x4.h"\nint own(void) { return g_N; }\n',
    "src/rock_01/U.c": ('#include "mmx6/n.h"\n#define body body_01\n#define D_A D_A01\n#include "../shared/rock_02/body.c"\n'
                        "#undef body\n#undef D_A\n"),
    "src/rock_02/V.c": ('#include "mmx6/n.h"\n#define body body_02\n#include "../shared/rock_02/body.c"\n#undef body\n'),
    "src/rock_05/W.c": ('#define own own_05\n#define g_N g_N\n#include "../rock_02/own.c"\n#undef own\n#undef g_N\n'),
    "src/rock_05/chain.c": ('#define body D_A\n#define D_A D_B\n#include "../shared/rock_02/body.c"\n'
                            "#undef body\n#undef D_A\n"),
}


def self_test():
    d = os.path.join(ROOT, _phase_run(), "twinform-selftest")
    fails = []

    def want(ok, what):
        print(f"control {what} {'ok' if ok else 'FAIL'}")
        if not ok:
            fails.append(what)

    cpp, flags = find_cpp(ROOT)
    if cpp is None:
        print("TWINFORM self-test FAIL: no preprocessor")
        return 1
    shutil.rmtree(d, ignore_errors=True)
    try:
        for rel, text in PLANT.items():
            os.makedirs(os.path.dirname(os.path.join(d, rel)), exist_ok=True)
            with open(os.path.join(d, rel), "w") as f:
                f.write(text)
        units = c_units(d)
        res = scan(d, units, src_files(d), cpp, flags)
        fr = {(r[0], r[3]): r for r in res["first"]}
        u = fr.get(("src/rock_01/U.c", "include/mmx6/rock_02.h"))
        want(u is not None and u[4] == "foreign" and u[2] == "src/shared/rock_02/body.c" and u[5] == "D_A"
             and u[7] == "D_B", "first-reach foreign (U: rock_02.h under body.c, D_A renamed, D_B left)")
        v = fr.get(("src/rock_02/V.c", "include/mmx6/rock_02.h"))
        want(v is not None and v[4] == "own", "first-reach own (V)")
        w = fr.get(("src/rock_05/W.c", "include/mmx6/x4.h"))
        want(w is not None and w[4] == "neutral" and w[2] == "src/rock_02/own.c", "first-reach neutral (W)")
        want(res["xown"] == [("src/rock_05/W.c", "1-3", "src/rock_02/own.c")], "other-overlay-own-file window (W)")
        want([r[0] for r in res["identity"]] == ["src/rock_05/W.c"], "identity pair (W g_N)")
        want(res["chain"] == [("src/rock_05/chain.c", "1-3", "src/shared/rock_02/body.c", "body", "D_A->D_B")],
             "chain (body->D_A->D_B)")
        want(not res["misses"], "every planted unit preprocessed")
        want(res["nset"] == ["include/mmx6/n.h"] and res["neutral"] == [("D_80100000", "include/mmx6/n.h")],
             "neutral (n.h every program reaches: D_80100000 overlay-local, D_80020000 main's)")
        want(res["order"] == [("src/rock_05/W.c", "include/mmx6/n.h")], "order (W enters n.h inside its window)")
        allf = src_files(d)
        c0 = refusal(d, units, allf, cpp, flags)
        want(len(c0) == 4 and any("foreign first reach include/mmx6/rock_02.h" in c for c in c0)
             and any("chain body->D_A" in c for c in c0) and any("overlay-local D_80100000" in c for c in c0)
             and any("order src/rock_05/W.c" in c for c in c0),
             "refusal: new foreign reach + chain + neutral + order, no own/identity")
        with open(os.path.join(d, BASELINE), "w") as f:
            f.write(BASE_HEAD + "".join("\t".join(k) + "\n" for k in keys(res)))
        want(refusal(d, units, allf, cpp, flags) == [], "refusal: baselined rows pass")
        # bank.py's R2 path: the window it writes (identity dropped), then twin_cause on the edited unit
        sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
        import bank  # noqa: E402 (lazy: bank imports the corpus/probe stack)
        import layout  # noqa: E402
        blk = bank.window("src/shared/rock_02/body.c", "src/rock_05", [("body", "body_05"), ("D_B", "D_B")])
        want(blk == ["#define body body_05", '#include "../shared/rock_02/body.c"', "#undef body"],
             "bank window drops identity pair D_B=D_B")
        with open(os.path.join(d, "src/rock_05/W.c"), "a") as f:
            f.write("\n".join(blk) + "\n")
        c1 = bank.twin_cause("rock_05", "W", "src/rock_05/W.c", [("body", "body_05")], root=d)
        want(c1.startswith("twinform: foreign first reach include/mmx6/rock_02.h"), "bank refuses a new foreign reach")
        with open(os.path.join(d, "src/rock_05/W.c"), "w") as f:
            f.write(PLANT["src/rock_05/W.c"])
        c2 = bank.twin_cause("rock_05", "W", "src/rock_05/chain.c", [("body", "D_A"), ("D_A", "D_B")], root=d)
        os.remove(os.path.join(d, BASELINE))
        c3 = bank.twin_cause("rock_05", "W", "src/rock_05/chain.c", [("body", "D_A"), ("D_A", "D_B")], root=d)
        want(c2 == "" and "chain body->D_A" in c3, "bank refuses a new chain (baselined passes)")
        want("overlay-local D_80100000" in c3 and "order src/rock_05/W.c" in c3,
             "bank refuses a new neutral + order case (baselined passes)")
        # layout.py apply's check on a staged tree: the same tree as the stage, the units and written files
        r4 = layout.twin_refusals(d, d, units, ["src/rock_05/chain.c", "src/rock_05/W.c"])
        want(len(r4) == 4 and "chain body->D_A" in " ".join(r4) and "rock_01/U.c" in " ".join(r4)
             and "overlay-local D_80100000" in " ".join(r4) and "order src/rock_05/W.c" in " ".join(r4),
             "layout refuses a new foreign reach + chain + neutral + order, not the identity pair")
    finally:
        shutil.rmtree(d, ignore_errors=True)
    print("TWINFORM self-test " + ("ok" if not fails else f"FAIL ({len(fails)})"))
    return int(bool(fails))


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    g = ap.add_mutually_exclusive_group(required=True)
    g.add_argument("--all", action="store_true")
    g.add_argument("--control", metavar="TSV")
    g.add_argument("--write-baseline", action="store_true")
    g.add_argument("--self-test", action="store_true")
    ap.add_argument("--root", default=ROOT, help="tree to scan (default: the repo)")
    a = ap.parse_args()
    root = os.path.abspath(a.root)
    if a.self_test:
        return self_test()
    if a.control:
        return cmd_control(root, a.control)
    if a.write_baseline:
        return cmd_write_baseline(root)
    return cmd_all(root)


if __name__ == "__main__":
    sys.exit(main())
