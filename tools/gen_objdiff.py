#!/usr/bin/env python3
"""gen_objdiff.py (mmx6 prototype, stdlib only; modelled on sozud/mmx4 tools/gen_objdiff.py).

Writes objdiff.json for the byte-matching build in the current directory (run after `make split build`).
Reads only tracked records (config/*.yaml, config/boundaries.txt, config/loadmap.txt) plus build/ objects.

Unit  = one code subsegment (`c` or `asm`) of config/<prog>.yaml -> one object file:
          c   -> build/src/<prog>/<name>.c.o
          asm -> build/asm/<prog>/<name>.s.o
target_path = that object (the build is byte-identical to the disc, so it IS the expected object).
base_path   = c unit: the same object (include/macro.inc `nonmatching` emits <func>.NON_MATCHING, so objdiff's MIPS
              reader drops those functions on the base side: INCLUDE_ASM bodies count as not matched);
              asm unit: build/empty.o (nothing decompiled).
build_base/build_target are false: objdiff-cli never runs make.

  gen_objdiff.py [--out objdiff.json] [--categories-out config/categories.tsv]
"""
import argparse, glob, json, os, re, subprocess, sys

EXE = "SLUS_013.95"
WEAK = ("LIBSND.LIB/VM_VIB.OBJ",)
SUB = re.compile(r"^\s*- \[(0x[0-9A-Fa-f]+),\s*([.\w]+),\s*(\w+)\]")
BSS = re.compile(r"^\s*- \{\s*start:\s*(0x[0-9A-Fa-f]+)")
END = re.compile(r"^\s*- \[(0x[0-9A-Fa-f]+)\]\s*$")
VRAM = re.compile(r"^\s*vram:\s*(0x[0-9A-Fa-f]+)")
START = re.compile(r"^\s*start:\s*(0x[0-9A-Fa-f]+)")


def units_of(path):
    vram = start = None
    subs, end, inside = [], None, False
    for line in open(path):
        if "BEGIN generated" in line:
            inside = True
            continue
        if "END generated" in line:
            inside = False
            continue
        if inside:
            m = SUB.match(line) or BSS.match(line)
            if m:
                subs.append((int(m.group(1), 16), m.group(2) if m.lastindex > 1 else "bss",
                             m.group(3) if m.lastindex > 2 else ""))
            continue
        if vram is None and VRAM.match(line):
            vram = int(VRAM.match(line).group(1), 16)
        if start is None and START.match(line):
            start = int(START.match(line).group(1), 16)
        if END.match(line):
            end = int(END.match(line).group(1), 16)
    out = []
    for i, (off, kind, name) in enumerate(subs):
        if kind in ("c", "asm"):
            nxt = subs[i + 1][0] if i + 1 < len(subs) else end
            out.append((name, kind, off - start + vram, nxt - start + vram))
    return out


def exe_sdk_span():
    lo = hi = cur = None
    for line in open("config/boundaries.txt"):
        t = line.split()
        if line.startswith("# program "):
            cur = t[2]
        elif t and t[0] == "lib" and cur == EXE and t[3] not in WEAK:
            a, b = int(t[1], 16), int(t[2], 16)
            lo = a if lo is None else min(lo, a)
            hi = b if hi is None else max(hi, b)
    return lo, hi


def loadmap():
    rows = {}
    for line in open("config/loadmap.txt"):
        t = line.split()
        if len(t) >= 3 and t[0].isdigit():
            rows[int(t[0])] = (t[1], t[2])
    return rows


def collect():
    sdk_lo, sdk_hi = exe_sdk_span()
    lm = loadmap()
    units, rock = [], []
    for y in sorted(glob.glob("config/*.yaml")):
        prog = os.path.basename(y)[:-5]
        if prog == EXE:
            seg = "main"
        else:
            if lm.get(int(prog.split("_")[1]), ("", ""))[1] != "code":
                continue
            seg = prog
            rock.append(prog)
        for name, kind, lo, hi in units_of(y):
            if prog == EXE:
                cats = ["sdk"] if sdk_lo <= lo < sdk_hi else ["game", "main"]
            else:
                cats = ["game", "rock", "rock." + prog]
            if kind == "c":
                src, obj = f"src/{prog}/{name}.c", f"build/src/{prog}/{name}.c.o"
            else:
                src, obj = f"asm/{prog}/{name}.s", f"build/asm/{prog}/{name}.s.o"
            units.append(dict(name=f"{seg}/{name}", kind=kind, src=src, obj=obj, cats=cats))
    return units, sorted(rock)


def categories_tsv(rock):
    rows = ["# config/categories.tsv -- DRAFT from gen_objdiff.py (mmx6). id parent name status",
            "id\tparent\tname\tstatus",
            "game\t\tGame code\tactive", "sdk\t\tPsyQ SDK libraries\tactive",
            f"main\t\t{EXE} (boot executable)\tactive", "rock\t\tROCK_X6.BIN overlays\tactive"]
    rows += [f"rock.{r}\trock\tRock {r.split('_')[1]}\tactive" for r in rock]
    return rows


def ensure_empty():
    p = "build/empty.o"
    if not os.path.exists(p):
        subprocess.run(["mipsel-linux-gnu-as", "-EL", "-march=r3000", "-o", p, os.devnull], check=True)
    return p


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--out", default="objdiff.json")
    ap.add_argument("--categories-out", default=None)
    a = ap.parse_args()
    units, rock = collect()
    empty = ensure_empty()
    tsv = categories_tsv(rock)
    if a.categories_out:
        open(a.categories_out, "w").write("\n".join(tsv) + "\n")
    cats = [r.split("\t") for r in tsv if not r.startswith(("#", "id\t"))]
    out, missing = [], []
    for u in sorted(units, key=lambda u: u["name"]):
        if not os.path.exists(u["obj"]):
            missing.append(u["obj"])
            continue
        out.append({"name": u["name"], "target_path": u["obj"],
                    "base_path": u["obj"] if u["kind"] == "c" else empty,
                    "metadata": {"source_path": u["src"], "progress_categories": u["cats"]}})
    if missing:
        sys.exit("missing objects (did the build run?): %d, e.g. %s" % (len(missing), missing[:3]))
    cfg = {"build_base": False, "build_target": False, "units": out,
           "progress_categories": [{"id": c[0], "name": c[2]} for c in cats]}
    with open(a.out, "w") as f:
        json.dump(cfg, f, indent=2)
        f.write("\n")
    nasm = sum(1 for u in units if u["kind"] == "asm")
    print(f"{a.out}: {len(out)} units ({nasm} asm-only, {len(out)-nasm} C)")


main()
