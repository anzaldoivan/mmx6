#!/usr/bin/env python3
"""callgraph.py -- system membership from the SLUS_013.95 call graph (C0285, C0346; from 2.6 T3.c1).

Run from the repo root (host):  PY tools/mmx6/systems/callgraph.py WORK [--diag | --who <hexvram>...]
WORK: a .run/<phase>/<T>/ dir holding functions.jsonl (container build/corpus/functions.jsonl, copied and pulled)
and debt.txt (psxd_floor.py debt --files). Also reads extracted/retail/iso/SLUS_013.95, src/,
docs/ops/layout-test.untested.tsv. Output: WORK/movement.md (the ## Members sections of docs/systems/movement.md).
The constants below (FOLDERS, OUT_FILES, TABLES, page title) are the movement system's; a new system edits them.
"""
import glob, json, os, re, struct, sys
from collections import defaultdict

PROG = "SLUS_013.95"
T = sys.argv[1].rstrip("/")
FOLDERS = ["player", "dash", "ladder", "cling"]
OUT_FILES = ("src/SLUS_013.95/collision/", "src/SLUS_013.95/8002E47C.c", "src/SLUS_013.95/damage/")
TABLES = [("D_80073ACC", 0x80073ACC, "src/SLUS_013.95/player/player.c:50"),
          ("D_800762C0", 0x800762C0, "src/SLUS_013.95/cling/player_to_ceiling.c:4")]


fns = {}
for ln in open(f"{T}/functions.jsonl"):
    r = json.loads(ln)
    if r["prog"] == PROG:
        fns[int(r["vram"], 16)] = r
starts = set(fns)

exe = open("extracted/retail/iso/SLUS_013.95", "rb").read()
t_addr = struct.unpack_from("<I", exe, 0x18)[0]
def word(a):
    return struct.unpack_from("<I", exe, 0x800 + a - t_addr)[0]

# file of each function: the src file holding its C body or its INCLUDE_ASM line
srcfile, asm = {}, set()
pat_def = re.compile(r"^[A-Za-z_][\w \*]*?\b(\w+)\s*\([^;]*$")
pat_asm = re.compile(r"INCLUDE_ASM\(\s*\"[^\"]*\"\s*,\s*(\w+)\s*\)")
byname = {r["name"]: v for v, r in fns.items()}
for path in sorted(glob.glob(f"src/{PROG}/**/*.c", recursive=True)):
    for line in open(path, errors="replace"):
        m = pat_asm.search(line)
        if m and m.group(1) in byname:
            v = byname[m.group(1)]; srcfile.setdefault(v, path); asm.add(v); continue
        if line[:1].isspace() or line.startswith(("#", "//", "static inline")):
            continue
        m = pat_def.match(line)
        if m and m.group(1) in byname and not line.rstrip().endswith(";"):
            srcfile.setdefault(byname[m.group(1)], path)

# shared bodies (src/shared/) pulled in by #include or a #define alias: attribute to the including SLUS file
for path in sorted(glob.glob(f"src/{PROG}/**/*.c", recursive=True)):
    t = open(path, errors="replace").read()
    for n in re.findall(r"#define\s+\w+\s+(\w+)\s*$", t, re.M) + re.findall(r"#include\s+\"[^\"]*/(\w+)\.c\"", t):
        if n in byname: srcfile.setdefault(byname[n], path)
    for inc in re.findall(r"#include\s+\"([^\"]*shared/[^\"]*\.c)\"", t):
        for line in open(os.path.normpath(os.path.join(os.path.dirname(path), inc)), errors="replace"):
            m = pat_def.match(line)
            if m and m.group(1) in byname and not line.rstrip().endswith(";"):
                srcfile.setdefault(byname[m.group(1)], path)

# edges
jal, ref = defaultdict(set), defaultdict(set)   # caller -> callees
for v, r in fns.items():
    end = int(r["end"], 16)
    lui = {}
    for pc in range(v, end, 4):
        w = word(pc); op = w >> 26
        if op == 3:
            t = (pc & 0xF0000000) | ((w & 0x3FFFFFF) << 2)
            if t in starts: jal[v].add(t)
        elif op == 15:
            lui[(w >> 16) & 31] = (w & 0xFFFF) << 16
        elif op in (9, 13):
            rs, imm = (w >> 21) & 31, w & 0xFFFF
            if rs in lui:
                a = (lui[rs] + (imm - 0x10000 if imm & 0x8000 else imm)) & 0xFFFFFFFF if op == 9 else lui[rs] | imm
                if a in starts and a != v: ref[v].add(a)
callers = defaultdict(set)
for a, bs in jal.items():
    for b in bs: callers[b].add(a)
rcallers = defaultdict(set)
for a, bs in ref.items():
    for b in bs: rcallers[b].add(a)

tables = {}
for nm, base, where in TABLES:
    ts, a = [], base
    while word(a) in starts:
        ts.append(word(a)); a += 4
    tables[nm] = ts

def fpath(v): return srcfile.get(v, "asm/ (no src)" if fns[v]["state"] == "asm" else "?")
def is_out(v): return fpath(v).startswith(OUT_FILES)
def label(v): return f"{fns[v]['name']} 0x{v:08X} {fpath(v)}"

folder = lambda p: any(p.startswith(f"src/{PROG}/{f}/") for f in FOLDERS)
entries = {v for v in fns if folder(fpath(v))} | {t for ts in tables.values() for t in ts}
entries -= {v for v in entries if is_out(v)}
reached, stack, boundary = set(entries), list(entries), defaultdict(set)
while stack:
    a = stack.pop()
    for b in jal[a]:
        if is_out(b): boundary[b].add(a); continue
        if b not in reached: reached.add(b); stack.append(b)
members = set(reached)
while True:
    drop = {v for v in members - entries if not callers[v] <= members}
    if not drop: break
    members -= drop
shared = reached - members
boundary = {b: cs & members for b, cs in boundary.items() if cs & members}

byfile = defaultdict(set)
for v in fns: byfile[fpath(v)].add(v)
folder_files = sorted(p for p in glob.glob(f"src/{PROG}/*/*.c") if folder(p))
mfiles = set(folder_files) | {p for p, vs in byfile.items() if p not in ("?", "asm/ (no src)") and len(vs & members) * 2 > len(vs)}

untested = {}
for i, ln in enumerate(open("docs/ops/layout-test.untested.tsv"), 1):
    c = ln.rstrip("\n").split("\t")
    if c[0].startswith(PROG + ":"): untested[int(c[0].split(":")[1], 16)] = (i, c)
debt = {}
for ln in open(f"{T}/debt.txt"):
    m = re.match(r"DEBT FILE (\w+)\s+(\S+?)(?::\s*(.*))?$", ln.rstrip())
    if m: debt[m.group(2)] = (m.group(1), m.group(3) or "no debt kinds")

HEAD = os.popen("git rev-parse --short HEAD").read().strip()
named = lambda v: not fns[v]["name"].startswith("func_")
stat = (f"COUNTS fns {len(fns)} jal {sum(map(len, jal.values()))} ref {sum(map(len, ref.values()))} entries {len(entries)} "
        f"folder-fns {sum(1 for v in fns if folder(fpath(v)))} " + " ".join(f"{n} {len(t)}" for n, t in tables.items())
        + f" reached {len(reached)} members {len(members)} member-files {len(mfiles)} shared {len(shared)} "
        f"shared-named {sum(map(named, shared))} boundary {len(boundary)} asm-members {len(members & asm)}")
o = []
P = o.append
P("# Movement (player) — SLUS_013.95")
P("")
P("## Members")
P("")
P(f"Method (C0285): bounds from `build/corpus/functions.jsonl`, `jal` decoded in the retail image, plus the two entry tables; "
  f"entries = every function in `src/SLUS_013.95/{{player,dash,ladder,cling}}/` + table targets ({len(entries)}); reach down over jal+table "
  f"edges, stopping at `collision/`, `8002E47C.c`, `damage/`; a reached non-entry stays only if every jal caller is a member "
  f"(fixpoint). `lui`+`addiu/ori` refs decoded, not used for reach ({sum(map(len, ref.values()))} refs; none from outside into members). "
  f"Counts: {len(reached)} reached, {len(members)} members, {len(mfiles)} member files, {len(shared)} shared helpers, "
  f"{len(boundary)} boundary callees.")
P(f"HEAD {HEAD}, 2026-11-02 (2.6 T3.c1); script `tools/mmx6/systems/callgraph.py`; rerun: `mx.sh sync && mx.sh run bash -c "
  f"\"make extract && make build && python3 tools/mmx6/corpus.py --prog SLUS_013.95 && mkdir -p {T} && cp build/corpus/functions.jsonl {T}/\"`; "
  f"`mx.sh pull {T}/functions.jsonl`; `PY tools/psxd_floor.py debt --files > {T}/debt.txt`; `PY tools/mmx6/systems/callgraph.py {T}`.")
P("")
P("### Entry tables")
P("")
for nm, base, where in TABLES:
    ts = tables[nm]
    P(f"- `{nm}` ({where}): {len(ts)} words, all function starts, {len(set(ts))} distinct; stops at 0x{base + 4 * len(ts):08X}")
    for t in ts:
        if is_out(t): P(f"  - {label(t)}: outside, not an entry")
P("")
P("### Member files")
P("")
P(f"State and kinds from `PY tools/psxd_floor.py debt --files` at HEAD {HEAD}.")
P("")
for p in sorted(mfiles):
    st, kinds = debt.get(p, ("?", "no DEBT FILE line"))
    n = len(byfile[p] & members)
    P(f"- {p}: {st}; {kinds}" + ("" if folder(p) else f" ({n} of {len(byfile[p])} fns members)"))
P("")
P("### Member functions")
for p in sorted({fpath(v) for v in members}):
    P("")
    P(f"#### {p}")
    P("")
    for v in sorted(byfile[p] & members):
        tags = (["asm"] if v in asm else []) + ([f"untested row {untested[v][0]}"] if v in untested else []) \
            + ([] if p in mfiles else ["file out"])
        P(f"- {fns[v]['name']} 0x{v:08X} {p}" + (" " + " ".join(tags) if tags else ""))
P("")
P("### Asm members")
P("")
for v in sorted(members & asm): P(f"- {label(v)}")
P("")
P("### Stalled drafts")
P("")
P("SLUS rows of `docs/ops/layout-test.untested.tsv` (all `plumbing:*`) in reach:")
P("")
for v, (i, c) in sorted(untested.items(), key=lambda x: x[1][0]):
    where = "member" if v in members else "shared helper" if v in shared else "boundary callee" if v in boundary else None
    if where: P(f"- row {i} {fns[v]['name']} 0x{v:08X} {fpath(v)}: {where}; {c[3]} {c[5]}")
P("")
P(f"### Shared helpers")
P("")
P(f"{len(shared)} reached functions dropped by the fixpoint (a caller outside); {sum(map(named, shared))} named, listed; "
  f"placeholders omitted. Count = outside jal callers.")
P("")
for v in sorted(shared):
    if named(v): P(f"- {label(v)}: {len(callers[v] - members)} outside callers")
P("")
P("### Boundary callees (T7)")
P("")
P("No member calls into `collision/` or `damage/`; `player_hurt` is reached only through `D_80073ACC`.")
P("")
for v in sorted(boundary): P(f"- {label(v)}: {len(boundary[v])} member callers")
P("")
P("### Outside callers of entries")
P("")
for v in sorted(entries):
    for c in sorted(callers[v] - members): P(f"- {label(c)} -> {fns[v]['name']}")
    for c in sorted(rcallers[v] - members): P(f"- {label(c)} -> {fns[v]['name']} (ref)")
open(f"{T}/movement.md", "w").write("\n".join(o) + "\n")
print(stat)
print(f"CHECK folder fns all members: {all(v in members for v in fns if folder(fpath(v)))}")
for v, (i, c) in sorted(untested.items(), key=lambda x: x[1][0]):
    print(f"UNTESTED row {i} 0x{v:08X} " + ("member" if v in members else "shared" if v in shared else
          "boundary" if v in boundary else "not reached"))
if len(sys.argv) > 2 and sys.argv[2] == "--diag":
    import collections
    un = [v for v in fns if v not in srcfile]
    print(collections.Counter(fns[v]["state"] for v in un))
    print([fns[v]["name"] for v in un if fns[v]["state"] != "asm"][:12])
if len(sys.argv) > 2 and sys.argv[2] == "--who":
    for a in sys.argv[3:]:
        v = int(a, 16)
        print(label(v), "callers:", " ".join(f"{fns[c]['name']}[{'M' if c in members else 'S' if c in shared else '-'}]" for c in sorted(callers[v]))[:600])
