#!/usr/bin/env python3
"""cards.py -- wave packs: card writing (T2.c2) and the pack probe (container, stdlib only).

  cards.py --probe-pack <dir> [--hold S] [--no-snapshot] [--show] [--probes DIR]
      -> `PACK <pv> match <m>/<n>` | `PACK <pv> fail <m>/<n>` | `PACK <pv> nocompile`; rc 0 on any PACK line
      Probe cap (T8): attempt k = 1 + count of <dir>/draft.a<n>.c; cap = config/routing.txt probe cap of the band of
      pack.json words (draw.routing; no band = 0). Under fcntl.flock on waves/.probes/<dir relpath, / -> __>.log
      (held through the compile): used >= cap -> last line `PACK <pv> refused probe-cap a<k> <used>/<cap>`, rc 3,
      nothing compiled; else one line `<UTC ISO> a<k> <state>[ <m>/<n>]` is appended and `PROBE <pv> a<k> <used>/<cap>`
      precedes the PACK line (still the last line, --show aside). Each counted probe writes <dir>/probe.ours.s (our
      function, rabbitizer, relocs as %hi/%lo/%gp_rel(sym) / jal sym, branches .L<vram>) and <dir>/probe.diff.s
      (unified diff target.s -> ours, both cut to `op args` lines); .s stays off the host clone (mx.sh push/pull).
      --probes DIR: keep the counter under DIR instead of waves/.probes (self-tests' scratch probes; never for real packs).
      --show prints probe.diff.s after the PACK line; without it no asm is printed.
      Compiles <dir>/draft.c as drafts/<prog>/<func>.c (its TU's flags, probe.draft_cflags) inside a fresh snapshot
      waves/.iso/<tag>/ of every input probe reads, cwd = the snapshot, so an `mx.sh sync` (which spares waves/)
      cannot pull the tree out from under a running gate; the snapshot is removed after. --hold S sleeps S seconds
      after the snapshot is built (`PACK HOLD <s>` printed first); --no-snapshot compiles in /work itself (the
      negative control of tools/docker/pack_control.sh only).

  cards.py --wave W<n> --targets <file> [--root <dir>] [--journal <path>]
      -> one pack <root>/W<n>/<prog>_<func>/ per target (root default `waves`): pack.json, target.s, scaffold.c
      (decompile.py m2c), ctx.h, card.md, seed.c (when a seed exists); never writes draft.c or verdict.json.
      Target line `<prog>:0x<VRAM>` with optional caps ` probe=<p> attempts=<a>` (draw.py --routing): card.md line
      `caps probe <p> runs per attempt, attempts <a>` (`caps -` without), pack.json probe/attempts (null without).
      Lines `CARD <pv> seed <pv|-> twins <k> levers <ids|-> x5 <unit:0xVRAM|->` | `CARD REFUSED <pv> <phantom|no-asm|<id>>`
      (no pack dir), last `CARDS W<n> <k> packs`; rc 0 iff no refusal and k >= 1, rc 3 on k = 0, else rc 1.
      G44: every L\\d{2,} / C\\d{4} token on card.md resolves (codegen_map.read_rows ids, cookbook/INDEX.md rows).
  cards.py --wave W<n> [--targets <file>] --arm config/methods-arm.tsv [--root R]  (3.1 T10, the seeded arm)
      -> as above, plus every arm-file row not in --targets (its config/routing.txt band caps). An arm row's fresh pack
      gets pack.json arm "fresh"; a `seeded` row also gets <prog>_<func>.seeded/: the fresh pack's files plus sibling.c
      (the sibling's C, symbols mapped to X6 names), pack.json arm/sibling/mapped/unmapped, card.md `## Sibling`.
      Sibling `x4:<src>:<func>`: x4port.port() (relocation alignment); `x5:<unit>:<vram>:<name>`: <root>/<W>/.x5/
      <prog>_<VRAM>.c (from --x5-fetch) renamed by the x5-leads relocation map, then the twin join (x5-twins.tsv,
      priorart.tsv, docs/leads/x5.tsv: one X6 counterpart in the target's program, else SLUS); a symbol neither
      names keeps its X5 spelling marked `/* X5 */`, counted in unmapped. Lines `CARD <pv> seeded sibling <s> mapped
      <m> unmapped <u>` | `CARD REFUSED <pv> seeded <why>`; packs of both arms count in CARDS.
  cards.py --x5-fetch W<n> --arm <file> [--root R]  (host python: reads ../mmx5-dev at HEAD, read only)
      -> per seeded x5 row <root>/<W>/.x5/<prog>_<VRAM>.c: the function from src/slus|rockx5/<stem>.c (a dedup member
      read through its src/shared/ body, its #defines applied) with the file's top-level declarations; a file with
      INCLUDE_ASM is refused (C0426's C rule). Lines `X5FETCH <pv> <sibling> <files>` | `X5FETCH REFUSED <pv> <why>`,
      last `X5FETCH W<n> <k> siblings`; rc 1 on a refusal. Then `mx.sh push <root>/<W>`.
  cards.py --probe-count <dir>  -> `PROBES <pv> a1 <n>/<cap> [a2 <n>/<cap> ...]` from the counter (current attempt
      always listed), rc 0.
  cards.py --outside <log> [--since ISO] [--until ISO] [--match S]  (host python; mx.sh run appends
      `<UTC ISO> <volume> <argv>` to waves/.mx-run.log) -> per run `PROBE|ALLOWED|OUTSIDE <ts> <argv>` (PROBE: cards.py
      --probe-pack/--probe-count; ALLOWED: depin.py, verbatim.py, cat/ls/head/tail/grep/wc, sed -n, mx.sh push/pull),
      last `OUTSIDE <k> of <n> runs`, rc 0.
  cards.py --self-test  -> planted cases in .run/cards-selftest/, last `CARDS CONTROL OK` (rc 0), else rc 1.

Pack dir waves/W<n>/<prog>_<func>/: pack.json {pv,prog,func,tu,words,probe,attempts}, target.s, draft.c, verdict.json
(docs/ops/campaign.md ## Packs). Snapshot: asm/ and extracted/ hardlinked (nothing writes them in place), Makefile,
mk/, include/, src/, config/, tools/, build/corpus/, build/split/ copied. Firewall G12: prints counts only; card.md,
ctx.h, seed.c and pack.json hold names, addresses, counts, ids and our C only (target.s, scaffold.c stay in the pack).
"""
import argparse
import contextlib
import difflib
import fcntl
import glob
import io
import json
import os
import re
import shutil
import struct
import subprocess
import sys
import time
from collections import Counter

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(os.path.dirname(HERE))
sys.path.insert(0, HERE)
import probe  # noqa: E402  (relative paths only: retail_words, draft_cflags, compile_obj, elf_function)
import codegen_map  # noqa: E402
import cookbook_check  # noqa: E402
import declsync  # noqa: E402
import journal  # noqa: E402
import plateau  # noqa: E402

FUNCS = "build/corpus/functions.jsonl"
CLASSES = "build/census/classes.jsonl"
TWINS = "build/sig/twins.jsonl"
X5_LEADS = "campaign/x4/x5-leads.tsv"  # mmx5 tools/sig/imgtab.py x6 --leads, copied (prior-art L5c)
REGISTRY = "config/dedup_registry.txt"
C_UNITS = "config/c_units.txt"
COOKBOOK = "cookbook/INDEX.md"
CODEGEN_MAP = "docs/codegen-map"
SELFTEST = ".run/cards-selftest"
PROBES = "waves/.probes"  # probe-cap counters, one per pack (T8)
ROUTING = "config/routing.txt"
ATTEMPT_RE = re.compile(r"draft\.a\d+\.c")
TWIN_CAP = 12
PV_RE = re.compile(r"([^\s:]+):0x([0-9A-Fa-f]{8})")
CAPS_RE = re.compile(r"(?:probe=(\d+) attempts=(\d+))?")  # optional wave-line caps (draw.py --routing)
ID_RE = re.compile(r"\b(L\d{2,}|C\d{4})\b")
JAL_RE = re.compile(r"\bjal\s+([A-Za-z_]\w*)")
REL_RE = re.compile(r"%(?:hi|lo|gp_rel)\(([A-Za-z_]\w*)\)")
PROTO_RE = re.compile(rf"^[ \t]*(?:extern\s+)?(?:static\s+)?({declsync.TYPE})\s*\b([A-Za-z_]\w*)\s*\(([^;{{}}()]*)\)\s*;",
                      re.M)
EXTERN_RE = re.compile(r"^[ \t]*(extern\s+[^;(){}=]*?\b([A-Za-z_]\w*)\s*(?:\[[^\]]*\]\s*)*);", re.M)

ARM = "config/methods-arm.tsv"  # the seeded arm's rows (3.1 T10)
ARM_COLS = ["split", "prog", "vram", "func", "arm", "sibling"]
SAMPLE = "config/methods-sample.tsv"
PARTNERS = "campaign/x4/partners.tsv"
X5_TWINS = "campaign/x4/x5-twins.tsv"
PRIORART = "campaign/priorart.tsv"
X5_DOC = "docs/leads/x5.tsv"
X5_DIR = ".x5"  # <root>/<W>/.x5/<prog>_<VRAM>.c: --x5-fetch output, outside the pack dirs
MMX5 = os.path.join(os.path.dirname(ROOT), "mmx5-dev")
X5_SYM = re.compile(r"(?:func|D)_[0-9A-F]{8}(?:_ovl\d+)?")
MAIN = "SLUS_013.95"

ISO = "waves/.iso"
LINK = ("asm", "extracted")
COPY = ("Makefile", "mk", "include", "src", "config", "tools", "build/corpus", "build/split")


def triple():
    """The Makefile's default TRIPLE (`TRIPLE ?= <name>`)."""
    with open("Makefile") as f:
        for line in f:
            m = re.match(r"TRIPLE \?= (\S+)", line)
            if m:
                return m.group(1)
    sys.exit("cards: no `TRIPLE ?=` in the Makefile")


def snapshot(tag):
    """Build waves/.iso/<tag>/ from the current tree; returns its absolute path."""
    dst = os.path.abspath(os.path.join(ISO, tag))
    shutil.rmtree(dst, ignore_errors=True)
    os.makedirs(dst)
    for p in LINK + COPY:
        if not os.path.exists(p):
            continue
        os.makedirs(os.path.dirname(os.path.join(dst, p)) or dst, exist_ok=True)
        subprocess.run(["cp", "-al" if p in LINK else "-a", p, os.path.join(dst, p)], check=True)
    return dst


def score(func, prog, src, t, objs=None):
    """('match'|'fail', m, n) or ('nocompile', 0, n): probe.probe's comparison, with a compile failure kept apart.
    objs: a list that receives the compiled object's path (probe_pack's disassembly)."""
    ret = probe.retail_words(prog, func)
    obj = probe.compile_obj(src, t)
    if obj is None:
        return "nocompile", 0, len(ret)
    if objs is not None:
        objs.append(obj)
    ours, masks = probe.elf_function(obj, func)
    m = 0
    for i in range(min(len(ret), len(ours))):
        keep = ~masks.get(i, 0) & 0xFFFFFFFF
        m += (ret[i] & keep) == (ours[i] & keep)
    return ("match" if len(ours) == len(ret) and m == len(ret) else "fail"), m, len(ret)


def utc():
    return time.strftime("%Y-%m-%dT%H:%M:%SZ", time.gmtime())


def probe_cap(words):
    """The config/routing.txt probe cap of the band holding `words`; 0 when no band holds it."""
    import draw  # lazy: draw's imports are not needed by the host-side modes
    try:
        rows = draw.routing(os.path.join(ROOT, ROUTING), "PACK")
    except draw.Refuse as e:
        sys.exit("\n".join(e.lines))
    return next((r[3] for r in rows if r[0] <= words <= r[1]), 0)


def attempt(pack):
    return 1 + sum(1 for n in os.listdir(pack) if ATTEMPT_RE.fullmatch(n))


def counter_path(pack, probes):
    return os.path.join(probes, os.path.relpath(os.path.abspath(pack), ROOT).replace("/", "__") + ".log")


def probe_slot(path, k, cap, work):
    """Under flock on the counter: (None, used) when attempt k has used >= cap probes; else run work() (lock held, so a
    concurrent probe of the pack waits and sees this one) and append `<UTC> a<k> <state>`; (state, used + 1)."""
    os.makedirs(os.path.dirname(path), exist_ok=True)
    with open(path, "a+") as f:
        fcntl.flock(f, fcntl.LOCK_EX)
        f.seek(0)
        used = sum(1 for line in f if line.split()[1:2] == [f"a{k}"])
        if used >= cap:
            return None, used
        state = "error"
        try:
            state = work()
        finally:
            f.write(f"{utc()} a{k} {state}\n")
            f.flush()
        return state, used + 1


def asm_norm(lines):
    """`op args` with single spaces, cut after the last `jr $ra` + its delay slot (probe.trim's rule)."""
    out = []
    for line in lines:
        op, _, rest = line.strip().partition(" ")
        out.append(f"{op} {' '.join(rest.split())}".strip())
    ra = [i for i, x in enumerate(out) if x == "jr $ra"]
    return out[: ra[-1] + 2] if ra else out


def target_asm_lines(path):
    """(first vram or None, normalized instruction lines) of a pack's target.s (spimdisasm rows)."""
    vram, rows = None, []
    if not os.path.exists(path):  # x4port packs carry no target.s (3.1 T11)
        return vram, rows
    with open(path) as f:
        for line in f:
            m = probe.INSN_RE.search(line)
            if m:
                vram = vram if vram is not None else int(m.group(1), 16)
                rows.append(f"{m.group(2)} {m.group(3)}")
    return vram, asm_norm(rows)


def elf_relocs(path, func):
    """{word index: (reloc type, symbol name or its section's name)} of func's REL entries in an ELF32 LE object."""
    with open(path, "rb") as f:
        elf = f.read()
    shoff, = struct.unpack_from("<I", elf, 0x20)
    shentsize, shnum, shstrndx = struct.unpack_from("<HHH", elf, 0x2E)
    secs = [struct.unpack_from("<10I", elf, shoff + i * shentsize) for i in range(shnum)]

    def cstr(base, off):
        return elf[base + off : elf.index(b"\0", base + off)].decode()

    st = next(s for s in secs if s[1] == 2)
    strs, shstr = secs[st[6]][4], secs[shstrndx][4]
    syms = [struct.unpack_from("<IIIBBH", elf, st[4] + 16 * k) for k in range(st[5] // 16)]
    _, value, _, _, _, shndx = next(s for s in syms if cstr(strs, s[0]) == func and 0 < s[5] < 0xFF00)
    out = {}
    for s in secs:
        if s[1] == 9 and s[7] == shndx:
            for k in range(s[5] // 8):
                off, info = struct.unpack_from("<II", elf, s[4] + 8 * k)
                sym = syms[info >> 8]
                name = cstr(strs, sym[0]) or (cstr(shstr, secs[sym[5]][0]) if sym[5] < len(secs) else "?")
                if off >= value:
                    out[(off - value) // 4] = (info & 0xFF, name)
    return out


def obj_asm_lines(obj, func, vram):
    """Our function's normalized instruction lines (rabbitizer, the engine of spimdisasm that wrote target.s)."""
    import rabbitizer  # lazy: in the image only
    words, _ = probe.elf_function(obj, func)
    rel = elf_relocs(obj, func)
    rows = []
    for i, w in enumerate(words):
        ins = rabbitizer.Instruction(w, vram + 4 * i)
        imm = None
        if i in rel:
            t, name = rel[i]
            lo = (w & 0xFFFF) - (0x10000 if w & 0x8000 else 0)
            add = (w & 0x03FFFFFF) << 2 if t == 4 else (lo if t in (6, 7) else 0)
            sym = name + (f"{add:+#x}" if add else "")
            imm = {4: sym, 5: f"%hi({name})", 6: f"%lo({sym})", 7: f"%gp_rel({sym})"}.get(t)
        elif ins.isBranch():
            imm = f".L{ins.getBranchVramGeneric():08X}"
        rows.append(ins.disassemble(immOverride=imm))
    return asm_norm(rows)


def write_probe_asm(pack, pv, func, obj):
    """<pack>/probe.ours.s and <pack>/probe.diff.s (unified diff target.s -> ours) for one counted probe."""
    vram, tgt = target_asm_lines(os.path.join(pack, "target.s"))
    if vram is None:
        vram = int(PV_RE.match(pv).group(2), 16)
    ours = obj_asm_lines(obj, func, vram) if obj else ["# nocompile"]
    with open(os.path.join(pack, "probe.ours.s"), "w") as f:
        f.write("\n".join(ours) + "\n")
    diff = list(difflib.unified_diff(tgt, ours, "target.s", "probe.ours.s", lineterm=""))
    with open(os.path.join(pack, "probe.diff.s"), "w") as f:
        f.write("\n".join(diff) + "\n" if diff else "# no difference\n")


def probe_pack(pack, hold, iso, probes=None, show=False):
    pack = os.path.abspath(pack)
    probes = os.path.abspath(probes or os.path.join(ROOT, PROBES))
    with open(os.path.join(pack, "pack.json")) as f:
        meta = json.load(f)
    with open(os.path.join(pack, "draft.c"), "rb") as f:
        draft = f.read()
    pv, prog, func = meta["pv"], meta["prog"], meta["func"]
    t = triple()
    src = f"drafts/{prog}/{func}.c"
    if not iso and os.path.exists(src):
        sys.exit(f"cards: --no-snapshot would overwrite the stored draft {src}")
    k, cap = attempt(pack), probe_cap(meta["words"])
    got = {}

    def work():
        snap = snapshot(f"{prog}_{func}.{os.getpid()}") if iso else None
        try:
            if snap:
                os.chdir(snap)
            os.makedirs(os.path.dirname(src), exist_ok=True)
            with open(src, "wb") as f:
                f.write(draft)
            if hold:
                print(f"PACK HOLD {hold}", flush=True)
                time.sleep(hold)
            objs = []
            state, m, n = score(func, prog, src, t, objs)
            write_probe_asm(pack, pv, func, objs[0] if objs else None)
        finally:
            if snap:
                os.chdir(os.path.dirname(os.path.dirname(os.path.dirname(snap))))
                shutil.rmtree(snap, ignore_errors=True)
            elif os.path.exists(src):
                os.remove(src)
        got["line"] = f"PACK {pv} {state}" + (f" {m}/{n}" if state != "nocompile" else "")
        return state + (f" {m}/{n}" if state != "nocompile" else "")

    state, used = probe_slot(counter_path(pack, probes), k, cap, work)
    if state is None:
        print(f"PACK {pv} refused probe-cap a{k} {used}/{cap}", flush=True)
        return 3
    print(f"PROBE {pv} a{k} {used}/{cap}", flush=True)
    print(got["line"], flush=True)
    if show:
        with open(os.path.join(pack, "probe.diff.s")) as f:
            print(f.read(), end="", flush=True)
    return 0


def probe_count(pack, probes=None):
    pack = os.path.abspath(pack)
    with open(os.path.join(pack, "pack.json")) as f:
        meta = json.load(f)
    cap, path = probe_cap(meta["words"]), counter_path(pack, os.path.abspath(probes or os.path.join(ROOT, PROBES)))
    c = Counter()
    if os.path.exists(path):
        with open(path) as f:
            c.update(line.split()[1] for line in f if len(line.split()) > 1)
    ks = sorted({int(a[1:]) for a in c if re.fullmatch(r"a\d+", a)} | {attempt(pack)})
    print(f"PROBES {meta['pv']} " + " ".join(f"a{j} {c[f'a{j}']}/{cap}" for j in ks))
    return 0


INTERP_RE = re.compile(r"python[\d.]*|bash|sh")
READ_ONLY = ("cat", "ls", "head", "tail", "grep", "wc")


def run_kind(argv):
    """PROBE | ALLOWED | OUTSIDE of one logged `mx.sh run` argv (interpreters skipped, their flags are not)."""
    toks = argv.split()
    while toks and INTERP_RE.fullmatch(os.path.basename(toks[0])):
        toks = toks[1:]
    cmd = os.path.basename(toks[0]) if toks else ""
    if cmd == "cards.py" and ("--probe-pack" in toks or "--probe-count" in toks):
        return "PROBE"
    if (cmd in ("depin.py", "verbatim.py") or cmd in READ_ONLY or (cmd == "sed" and "-n" in toks)
            or (cmd == "mx.sh" and toks[1:2] in (["push"], ["pull"]))):
        return "ALLOWED"
    return "OUTSIDE"


def outside(log, since=None, until=None, match=None):
    k = n = 0
    with open(log) as f:
        for line in f:
            parts = line.rstrip("\n").split(" ", 2)
            if (len(parts) < 3 or (since and parts[0] < since) or (until and parts[0] > until)
                    or (match and match not in line)):
                continue
            kind = run_kind(parts[2])
            n += 1
            k += kind == "OUTSIDE"
            print(f"{kind} {parts[0]} {parts[2]}")
    print(f"OUTSIDE {k} of {n} runs")
    return 0


def pvs(prog, vram):
    return f"{prog}:0x{vram:08X}"


def jl(path):
    with open(path) as f:
        return [json.loads(x) for x in f if x.strip()]


def strip_comments(text):
    return re.sub(r"/\*.*?\*/|//[^\n]*", lambda m: re.sub(r"[^\n]", " ", m.group(0)), text, flags=re.S)


def top_decls(text):
    """Top-level `;`-terminated prototypes and externs of a C file (preprocessor lines and INCLUDE_ASM skipped)."""
    lines, skip = [], False
    for x in strip_comments(text).split("\n"):
        if skip or x.lstrip().startswith("#"):
            skip = x.rstrip().endswith("\\")
            lines.append("")
            continue
        lines.append(x)
    out, buf, depth, fdef, drop = [], "", 0, False, False
    for ch in "\n".join(lines):
        if ch == "{":
            if depth == 0:
                fdef = buf.strip().endswith(")")
            depth += 1
        elif ch == "}":
            depth -= 1
            if depth == 0:
                if fdef:
                    buf, fdef = "", False
                else:
                    drop = True
                continue
        if depth:
            continue
        if ch == ";":
            s = " ".join(buf.split())
            if not drop and s and not s.startswith("INCLUDE_ASM") and \
                    (s.startswith("extern ") or ("(" in s and "=" not in s)):
                out.append(s + ";")
            buf, drop = "", False
        else:
            buf += ch
    return out


def body_of(text, name):
    """The definition of name in text (signature through its closing brace), or None."""
    for m in declsync.DEF_RE.finditer(text):
        if m.group(2) != name:
            continue
        depth, i = 0, m.end() - 1
        while i < len(text):
            depth += {"{": 1, "}": -1}.get(text[i], 0)
            if depth == 0:
                return text[m.start():i + 1] + "\n"
            i += 1
    return None


def best(counter):
    """(text, count) of the most common entry (ties: lowest text), or None."""
    if not counter:
        return None
    return min(counter.items(), key=lambda kv: (-kv[1], kv[0]))


def known_functions(names, root="."):
    """Corpus function names plus the `type:func` names of every config/symbols.<prog>.txt."""
    progs = [os.path.basename(p)[len("symbols."):-len(".txt")] for p in glob.glob(os.path.join(root, "config/symbols.*.txt"))]
    return set(names) | {n for p in progs for n, _, t in probe.symbols(p, root) if t == "func"}


def card_globs(asm, known):
    """The asm's %hi/%lo/%gp_rel targets that name no known function: the shared globals a card declares.
    The `func_` test is spimdisasm's type tag, never an address: 12 text symbols labelled dlabel/alabel (e.g. rock_16
    func_800F0DDC) are typed function by it alone, in no corpus row or symbols file (T5.c1, card output unchanged)."""
    return sorted({s for s in REL_RE.findall(asm or "") if s not in known and not s.startswith("func_")})


class Ctx:
    """Fleet-wide inputs read once: corpus, dup classes, registry, c_units, src/ declaration index, id sets."""

    def __init__(self):
        self.funcs = {(r["prog"], int(r["vram"], 16)): r for r in jl(FUNCS)}
        self.names = {r["name"] for r in self.funcs.values()}
        self.known = known_functions(self.names)  # a function is known by name, never by its `func_` spelling
        self.cls_of, self.members = {}, {}
        for c in jl(CLASSES):
            if c["kind"] != "dup":
                continue
            mem = [(p, int(v, 16)) for p, v in c["members"]]
            self.members[c["key"]] = mem
            for m in mem:
                self.cls_of[m] = c["key"]
        self.reg, self.exemplars = {}, set()
        if os.path.exists(REGISTRY):
            with open(REGISTRY) as f:
                for line in f:
                    t = line.split(None, 5)
                    if not line.strip() or line.startswith("#") or len(t) < 5 or t[4] != "gated":
                        continue
                    m, e = PV_RE.fullmatch(t[3]), PV_RE.fullmatch(t[1])
                    if not (m and e):
                        continue
                    self.reg[(m.group(1), int(m.group(2), 16))] = (t[0], t[2], (t[5] if len(t) > 5 else "").strip())
                    self.exemplars.add((e.group(1), int(e.group(2), 16)))
        self.units = set()
        with open(C_UNITS) as f:
            for line in f:
                t = line.split()
                if len(t) >= 2 and not line.startswith("#"):
                    self.units.add((t[0], t[1]))
        self.protos, self.externs, self.texts = {}, {}, {}
        for p in sorted(glob.glob("src/**/*.[ch]", recursive=True)):
            with open(p, errors="replace") as f:
                text = f.read()
            self.texts[p] = text
            clean = strip_comments(text)
            for m in PROTO_RE.finditer(clean):
                if m.group(1).split()[0] in ("return", "else", "goto", "case", "do"):
                    continue  # a call statement, not a prototype
                self.protos.setdefault(m.group(2), Counter())[" ".join(f"{m.group(1)} {m.group(2)}({m.group(3)})"
                                                                       .split())] += 1
            for name, ret, ps in declsync.definitions(clean):
                self.protos.setdefault(name, Counter())[" ".join(f"{ret} {name}({ps})".split())] += 1
            for m in EXTERN_RE.finditer(clean):
                self.externs.setdefault(m.group(2), Counter())[" ".join(m.group(1).split()) + ";"] += 1
        self.x5 = {}
        if os.path.exists(X5_LEADS):
            with open(X5_LEADS) as f:
                for line in f:
                    t = line.rstrip("\n").split("\t")
                    if len(t) == 9:
                        self.x5[(t[0], int(t[1], 16))] = dict(unit=t[4], vram=t[5], name=t[6], path=t[7],
                                                             map=[x.split("=", 1) for x in t[8].split(";") if x])
        rows, seen = codegen_map.read_rows(CODEGEN_MAP, ".", lambda *a: None)
        self.levers = {r["id"] for g in rows.values() for r in g}
        self.cookbook = set()
        with open(COOKBOOK, encoding="utf-8") as f:
            for line in f:
                m = cookbook_check.ROW_RE.match(line)
                if m:
                    self.cookbook.add(m.group(1))

    def banked(self, pv):
        r = self.funcs.get(pv)
        return pv in self.reg or (r is not None and r["state"] in ("c", "c-empty"))

    def twins(self, targets):
        """{target: [(other, tier, dist)]} from build/sig/twins.jsonl."""
        want, out = set(targets), {t: [] for t in targets}
        hexes = {f"{v:08X}" for _, v in targets}
        with open(TWINS) as f:
            for line in f:
                u = line.upper()
                if not any(h in u for h in hexes):
                    continue
                r = json.loads(line)
                a, b = (r["a"][0], int(r["a"][1], 16)), (r["b"][0], int(r["b"][1], 16))
                if a in want:
                    out[a].append((b, r["tier"], r["dist"]))
                if b in want:
                    out[b].append((a, r["tier"], r["dist"]))
        return out

    def seed(self, pv, twins):
        """(seed pv, body path, reason, C body) of the banked twin, or None."""
        cand = set(self.members.get(self.cls_of.get(pv), ())) | {o for o, t, _ in twins if t == "exact"}
        cand = sorted((c for c in cand if c != pv and self.banked(c)), key=lambda c: (c not in self.exemplars, c))
        for c in cand:
            if c in self.reg:
                _, path, reason = self.reg[c]
                if path in self.texts:
                    return c, path, reason, self.texts[path]
            r = self.funcs.get(c)
            if r is None:
                continue
            for path in declsync.unit_files(c[0]):
                text = self.texts.get(path)
                body = body_of(text, r["name"]) if text else None
                if body:
                    return c, path, "", body
        return None


def target_asm(prog, row):
    """The target's asm text (include_asm: its nonmatchings .s; asm: its glabel span of the whole-TU .s), or None."""
    name = row["name"]
    if row["state"] == "include_asm":
        p = os.path.join("asm", prog, "nonmatchings", row["tu"], name + ".s")
        if os.path.isfile(p):
            with open(p, errors="replace") as f:
                return f.read()
        return None
    for d, dirs, files in os.walk(os.path.join("asm", prog)):
        dirs[:] = sorted(x for x in dirs if x != "nonmatchings")
        if row["tu"] + ".s" not in files:
            continue
        with open(os.path.join(d, row["tu"] + ".s"), errors="replace") as f:
            lines = f.read().split("\n")
        out = None
        for x in lines:
            m = re.match(r"\s*(glabel|endlabel)\s+(\S+)", x)
            if out is None:
                if m and m.group(1) == "glabel" and m.group(2) == name:
                    out = [x]
                continue
            if m and (m.group(1) == "glabel" or m.group(2) == name):
                if m.group(1) == "endlabel":
                    out.append(x)
                break
            out.append(x)
        if out:
            return "\n".join(out) + "\n"
    return None


def x5_twin(lead):
    """The card's `## X5 twin` lines: mmx5's C with this target's bytes and the names to change, else `-`."""
    if not lead:
        return ["-"]
    return [f"mmx5 {lead['unit']} {lead['name']} ({lead['vram']}) has this target's bytes under the relocation mask "
            f"({X5_LEADS}). Its C: `refs/mmx5/{lead['path']}` (`fetch_refs.py --with mmx5`; AGPL-3.0, THIRD_PARTY.md).",
            "- Seed the draft from that function's C, then rename by this map (X5 name -> X6 name):"] + \
        [f"  - `{a}` -> `{b}`" for a, b in lead["map"]] + [
            "- Keep X6's own types and declarations (include/, ctx.h), not X5's.",
            "- X5's cc1 has no `-funsigned-char` (its `-D__CHAR_UNSIGNED__` is cpp only): a plain `char` there is signed;"
            " spell it `s8` here.",
            "- A name the map lacks keeps its X6 spelling from target.s. The lead is not a match: the gate proves it."]


# ---- the seeded arm (3.1 T10) ----------------------------------------------------------------------------------------

def read_arm(path):
    """[(split, prog, vram, func, arm, sibling)] of a methods-arm file (tab-separated, `#` comments, one header row)."""
    rows = []
    with open(path) as f:
        for line in f:
            t = line.rstrip("\n").split("\t")
            if line.startswith("#") or not line.strip() or t == ARM_COLS:
                continue
            if len(t) != 6 or t[4] not in ("fresh", "seeded") or not re.fullmatch(r"0x[0-9A-F]{8}", t[2]):
                sys.exit(f"cards: {path} malformed row: {line.strip()}")
            rows.append((t[0], t[1], int(t[2], 16), t[3], t[4], t[5]))
    return rows


def partners_of(prog, vram):
    """[(src, func, exact key)] of the target's campaign/x4/partners.tsv rows (exact mmx4 partners), sorted."""
    v = f"0x{vram:08X}"
    with open(PARTNERS) as f:
        return sorted((t[5], t[6], t[4]) for t in (x.rstrip("\n").split("\t") for x in f) if t[:2] == [prog, v])


def sibling_of(prog, vram):
    """`x4:<src>:<func>` (the first exact mmx4 partner), else `x5:<unit>:<vram>:<name>` (the docs/leads/x5.tsv col3 twin
    when campaign/priorart.tsv lists it as C, else priorart's first x5 `c:` entry), else None (no sibling C)."""
    x4 = partners_of(prog, vram)
    if x4:
        return f"x4:{x4[0][0]}:{x4[0][1]}"
    v, cs, named = f"0x{vram:08X}", [], None
    with open(PRIORART) as f:
        for x in f:
            t = x.rstrip("\n").split("\t")
            if not x.startswith("#") and t[:2] == [prog, v] and len(t) > 4:
                cs = [e.split(":")[1:] for e in t[4].split(";") if e.startswith("c:")]
    with open(X5_DOC) as f:
        for x in f:
            t = x.rstrip("\n").split("\t")
            if len(t) > 3 and t[1] == f"{prog} {v}" and t[3] == "code" and t[2].startswith("X5 "):
                named = t[2].split()[1:]
    if not cs:
        return None
    pick = next((c for c in cs if named and [c[0], c[2]] == named), cs[0])
    return f"x5:{pick[0]}:{pick[1]}:{pick[2]}"


def decl_name(d):
    """The name a top-level declaration declares (`(*name...)` of a function pointer, else the identifier before its
    first `(`, `[`, `;` or `=`), or None."""
    m = re.match(r"[^(]*\(\s*\*\s*(\w+)", d) or re.search(r"(\w+)\s*[\[(;=]", d)
    return m.group(1) if m else None


def x5_extract(show, unit, vram, name):
    """(text, files) of X5 function name: the file's top-level declarations and the definition, or (None, reason).
    show(path) -> the file's text at mmx5-dev HEAD, or None. Stem `func_<VRAM>` (slus, src/slus/) or
    `func_<VRAM>_<ovl>` (src/rockx5/); a dedup member is read through its `#include "../shared/<x>.c"` with its own
    `#define A B` lines applied; INCLUDE_ASM in any file read refuses it (C0426)."""
    v = vram[2:].upper()
    path = f"src/slus/func_{v}.c" if unit == "slus" else f"src/rockx5/func_{v}_{unit}.c"
    text, files = show(path), [path]
    if text is None:
        return None, f"no-file {path}"
    m = re.search(r'^#include\s+"\.\./shared/([\w.]+)"', text, re.M)
    if m and "INCLUDE_ASM" not in text:
        defs = dict(re.findall(r"^#define\s+(\w+)\s+(\w+)\s*$", text, re.M))
        files.append(f"src/shared/{m.group(1)}")
        shared = show(files[-1])
        if shared is None:
            return None, f"no-file {files[-1]}"
        text = re.sub(r"\b\w+\b", lambda t: defs.get(t.group(0), t.group(0)), shared)
    if "INCLUDE_ASM" in text:
        return None, f"include-asm {files[-1]}"
    body = body_of(text, name)
    if body is None:
        return None, f"no-definition {name} in {files[-1]}"
    decls = [d for d in top_decls(text) if decl_name(d) != name]
    return "\n".join(decls) + ("\n\n" if decls else "") + body, files


def x5_fetch(wave, root, arm, say=print):
    """Host: <root>/<wave>/.x5/<prog>_<VRAM>.c of every seeded x5 arm row, from mmx5-dev at HEAD (read only)."""
    head = subprocess.run(["git", "-C", MMX5, "rev-parse", "--short", "HEAD"], capture_output=True, text=True)
    if head.returncode:
        sys.exit(f"cards: {MMX5} is not a git clone")

    def show(p):
        r = subprocess.run(["git", "-C", MMX5, "show", f"HEAD:{p}"], capture_output=True, text=True)
        return r.stdout if r.returncode == 0 else None
    k, bad = 0, 0
    for _, prog, vram, _, a, sib in read_arm(arm):
        if a != "seeded" or not sib.startswith("x5:"):
            continue
        _, unit, v, name = sib.split(":")
        text, files = x5_extract(show, unit, v, name)
        if text is None:
            say(f"X5FETCH REFUSED {pvs(prog, vram)} {files}")
            bad += 1
            continue
        out = os.path.join(root, wave, X5_DIR, f"{prog}_{vram:08X}.c")
        os.makedirs(os.path.dirname(out), exist_ok=True)
        with open(out, "w") as f:
            f.write(f"/* Adapted from mmx5-dev @{head.stdout.strip()} {' via '.join(files)}:{name}, AGPL-3.0"
                    f" (see THIRD_PARTY.md); X5 names (cards.py --x5-fetch) */\n" + text)
        say(f"X5FETCH {pvs(prog, vram)} {sib} {','.join(files)}")
        k += 1
    say(f"X5FETCH {wave} {k} siblings")
    return 1 if bad else 0


def x6_current(ctx, prog, name):
    """The current X6 name of a `func_|D_<ADDR>` spelling (corpus, then config/symbols, target's program then SLUS)."""
    m = re.fullmatch(r"(?:func|D)_([0-9A-F]{8})", name)
    if not m:
        return name
    a = int(m.group(1), 16)
    if not hasattr(ctx, "symaddr"):
        ctx.symaddr = {}
    for p in (prog, MAIN):
        if (p, a) in ctx.funcs:
            return ctx.funcs[(p, a)]["name"]
        if p not in ctx.symaddr:
            ctx.symaddr[p] = {v: n for n, v, _ in probe.symbols(p)}
        if a in ctx.symaddr[p]:
            return ctx.symaddr[p][a]
    return name


def x5_join(ctx):
    """{X5 function name: {X6 corpus pv}}: x5-twins.tsv key groups, priorart.tsv x5 entries, docs/leads/x5.tsv code rows."""
    if hasattr(ctx, "x5join"):
        return ctx.x5join
    out, groups = {}, {}
    with open(X5_TWINS) as f:
        for t in (x.rstrip("\n").split("\t") for x in f):
            if len(t) == 7:
                groups.setdefault(t[0], ([], []))[t[2] == "X6"].append(t[5] if t[2] == "X5" else (t[3], int(t[4], 16)))
    for x5s, x6s in groups.values():
        for a in x5s:
            out.setdefault(a, set()).update(x6s)
    with open(PRIORART) as f:
        for t in (x.rstrip("\n").split("\t") for x in f if not x.startswith("#")):
            if len(t) > 4 and t[4] != "-":
                for e in t[4].split(";"):
                    out.setdefault(e.split(":")[-1], set()).add((t[0], int(t[1], 16)))
    with open(X5_DOC) as f:
        for t in (x.rstrip("\n").split("\t") for x in f):
            if len(t) > 3 and t[3] == "code" and t[2].startswith("X5 ") and PV_RE.fullmatch(t[1].replace(" ", ":")):
                p, v = t[1].split()
                out.setdefault(t[2].split()[-1], set()).add((p, int(v, 16)))
    ctx.x5join = {a: {pv for pv in s if pv in ctx.funcs} for a, s in out.items()}
    return ctx.x5join


def x5_names(ctx, pv, name):
    """{X5 name: X6 name}: the twin itself; the x5-leads relocation map when its X5 function is this twin; the twin join
    for an X5 function with exactly one X6 counterpart in the target's program (else, none there, in SLUS)."""
    names, lead = {name: ctx.funcs[pv]["name"]}, ctx.x5.get(pv)
    if lead and lead["name"] == name:
        for a, b in lead["map"]:
            names.setdefault(a, x6_current(ctx, pv[0], b))
    for a, cands in sorted(x5_join(ctx).items()):
        for p in (pv[0], MAIN):
            c = sorted(x for x in cands if x[0] == p)
            if c:
                if len(c) == 1:
                    names.setdefault(a, ctx.funcs[c[0]]["name"])
                break
    return names


def x5_rename(text, names, syms):
    """(text, mapped, unmapped): each X5 symbol renamed by names; one names lacks (a declared name in syms or a
    func_/D_ spelling) keeps its spelling marked `/* X5 */`. Counts are distinct symbols; members (. ->) untouched."""
    mapped, unmapped = set(), set()

    def one(m):
        w, pre = m.group(0), text[max(0, m.start() - 2):m.start()]
        if pre.endswith(".") or pre == "->":
            return w
        if w in names:
            mapped.add(w)
            return names[w]
        if w in syms or X5_SYM.fullmatch(w):
            unmapped.add(w)
            return w + "/* X5 */"
        return w
    return re.sub(r"\b[A-Za-z_]\w*\b", one, text), len(mapped), len(unmapped)


_X4CTX = []


def sibling_c(ctx, pv, row, sib, root, wave):
    """(sibling.c text, mapped, unmapped) of a seeded row, or (None, reason, 0)."""
    if sib.startswith("x4:"):
        import x4port  # lazy: container only
        _, src, fn = sib.split(":")
        key = next((k for s, f, k in partners_of(*pv) if (s, f) == (src, fn)), None)
        if key is None:
            return None, f"no-partner {src}:{fn}", 0
        if not _X4CTX:
            _X4CTX.append(x4port.mmx4_ctx())
        seen = []
        try:
            draft, notes, hb = x4port.port(_X4CTX[0], pv[0], row, key, src, fn, tamper=lambda r: seen.append(r) or r)
        except x4port.Skip as e:
            return None, f"port {e}", 0
        if hb:
            inc = '#include "mmx6/x4.h"\n'
            draft = draft.replace(inc, inc + "\n".join(t for _, t, _ in hb) + "\n", 1)
        unm = sum(1 for n in notes.split("; ") if n.split(" ", 1)[0] in ("unaligned", "unresolved", "conflict"))
        return draft, max(1, 1 + len({r[1] for r in (seen[0] if seen else {}).values()}) - unm), unm
    _, unit, v, name = sib.split(":")
    p = os.path.join(root, wave, X5_DIR, f"{pv[0]}_{pv[1]:08X}.c")
    if not os.path.isfile(p):
        return None, f"no-x5-extract {os.path.relpath(p, root)} (host --x5-fetch, then mx.sh push)", 0
    with open(p) as f:
        head, code = f.read().split("\n", 1)
    syms = {decl_name(d) for d in top_decls(code)} | {name}
    text, m, u = x5_rename(code, x5_names(ctx, pv, name), syms - {None})
    return head + '\n#include "common.h"\n\n' + text, m, u


def card(ctx, pv, row, asm, twins, jpath, caps=(None, None)):
    """(card.md text, ctx.h text, seed tuple or None, open twins, lever ids)."""
    prog, _ = pv
    seed = ctx.seed(pv, twins)
    opens = [(o, t, d) for o, t, d in twins if ctx.funcs.get(o, {}).get("state") in ("asm", "include_asm")
             and o not in ctx.reg]
    opens = sorted(opens, key=lambda x: (x[1] != "exact", x[2], x[0]))[:TWIN_CAP]
    dest = f"src/{prog}/{row['tu']}.c"
    dtext = ctx.texts.get(dest, "")
    decls = top_decls(dtext)
    incl = [x for x in dtext.split("\n") if x.startswith("#include")]
    callees = sorted(set(JAL_RE.findall(asm or "")))
    globs = card_globs(asm, ctx.known)
    recs = [r for r in journal.records(jpath) if r["pv"] == pvs(*pv)]
    label = recs[-1]["label"] if recs and recs[-1]["label"] != "-" else "none"
    trows = plateau.rows(label) if label in plateau.GROUPS else "-"
    levers = sorted(set(re.findall(r"\bL\d{2,}\b", trows)))
    L = [f"# card {pvs(*pv)} {row['name']}", "",
         f"target {pvs(*pv)} {row['name']} tu {row['tu']} words {row['words']} state {row['state']} lane {row['lane']}",
         "caps " + (f"probe {caps[0]} runs per attempt, attempts {caps[1]}" if caps[0] is not None else "-"),
         "", "## Seed"]
    if seed:
        L.append(f"{pvs(*seed[0])} {ctx.funcs.get(seed[0], {}).get('name', '-')} body {seed[1]}" +
                 (f" reason {seed[2]}" if seed[2] else "") + " (copied to seed.c)")
    else:
        L.append("-")
    L += ["", "## X5 twin"] + x5_twin(ctx.x5.get(pv))
    L += ["", "## Open twins"] + [f"- {pvs(*o)} {t} {d} {ctx.funcs[o]['name']}" for o, t, d in opens] + \
         ([] if opens else ["-"])
    L += ["", "## Destination", f"{dest} c_unit {'yes' if (prog, row['tu']) in ctx.units else 'no'}"
          + ("" if dtext else " (file absent)")]
    L += ["", "## File declarations"] + [f"- `{x}`" for x in decls] + ([] if decls else ["-"])
    L += ["", "## Callee declaration consensus"]
    for c in callees:
        b = best(ctx.protos.get(c))
        L.append(f"- {c} " + (f"{b[1]} `{b[0]};`" if b else "-"))
    L += [] if callees else ["-"]
    L += ["", "## Shared-global declarations"]
    for s in globs:
        b = best(ctx.externs.get(s))
        L.append(f"- {s} " + (f"{b[1]} `{b[0]}`" if b else "-"))
    L += [] if globs else ["-"]
    L += ["", "## Journal history"]
    for r in recs:
        L.append(f"- {r['wave']} {r['verdict']} {r['score']} label {r['label']} lever {r['lever']} draft {r['draft']}"
                 f" runs {r['runs']}: {r['notes']}")
    L += [] if recs else ["-"]
    L += ["", "## Plateau", f"label {label}", f"triage rows {trows}", f"levers {','.join(levers) or '-'}", ""]
    hdr = "\n".join([f"/* ctx.h -- {dest}: includes and top-level declarations (cards.py) */"] + incl + decls) + "\n"
    return "\n".join(L), hdr, seed, opens, levers


def write_cards(wave, targets_path, root, jpath, allow_banked=False, say=print, arm=None):
    ctx = Ctx()
    targets, bad, caps = [], [], {}
    with open(targets_path) if targets_path else contextlib.nullcontext([]) as f:
        for line in f:
            s = line.strip()
            if s and not s.startswith("#"):
                m = PV_RE.fullmatch(s.split()[0])
                c = CAPS_RE.fullmatch(s[len(s.split()[0]):].strip())
                if m and c:
                    targets.append((m.group(1), int(m.group(2), 16)))
                    caps[targets[-1]] = (int(c.group(1)), int(c.group(2))) if c.group(1) else (None, None)
                else:
                    bad.append(s)
    for s in bad:
        say(f"CARD REFUSED {s} malformed")
    arms, seeded = set(), {}
    if arm:
        import draw  # lazy, as probe_cap
        bands = draw.routing(ROUTING, "CARD")
        for _, prog, vram, _, a, sib in read_arm(arm):
            arms.add((prog, vram))
            if a == "seeded":
                seeded[(prog, vram)] = sib
            if (prog, vram) not in caps:
                targets.append((prog, vram))
                w = ctx.funcs.get((prog, vram), {}).get("words", -1)
                caps[(prog, vram)] = next(((r[3], r[4]) for r in bands if r[0] <= w <= r[1]), (None, None))
    tw = ctx.twins(targets)
    k, refused = 0, len(bad)
    for pv in targets:
        row = ctx.funcs.get(pv)
        if row is None:
            say(f"CARD REFUSED {pvs(*pv)} phantom")
            refused += 1
            continue
        asm = target_asm(pv[0], row)
        if asm is None and not (allow_banked and ctx.banked(pv)):
            say(f"CARD REFUSED {pvs(*pv)} no-asm")
            refused += 1
            continue
        md, hdr, seed, opens, levers = card(ctx, pv, row, asm, tw[pv], jpath, caps[pv])
        pack = os.path.join(root, wave, f"{pv[0]}_{row['name']}")
        miss = next((i for i in ID_RE.findall(md) if i not in (ctx.levers if i[0] == "L" else ctx.cookbook)), None)
        if miss:
            say(f"CARD REFUSED {pvs(*pv)} {miss}")
            refused += 1
            if os.path.isdir(pack):
                if any(os.path.exists(os.path.join(pack, x)) for x in ("draft.c", "verdict.json")):
                    for x in ("pack.json", "target.s", "scaffold.c", "ctx.h", "card.md", "seed.c"):
                        if os.path.exists(os.path.join(pack, x)):
                            os.remove(os.path.join(pack, x))
                else:
                    shutil.rmtree(pack)
            continue
        os.makedirs(pack, exist_ok=True)
        meta = dict(pv=pvs(*pv), prog=pv[0], func=row["name"], tu=row["tu"], words=row["words"], probe=caps[pv][0],
                    attempts=caps[pv][1])
        if pv in arms:
            meta["arm"] = "fresh"
        files = {"pack.json": json.dumps(meta) + "\n", "card.md": md, "ctx.h": hdr}
        if asm is not None:
            files["target.s"] = asm
            r = subprocess.run([sys.executable, os.path.join(HERE, "decompile.py"), row["name"], "--prog", pv[0]],
                               stdout=subprocess.PIPE, stderr=subprocess.DEVNULL, text=True)
            files["scaffold.c"] = r.stdout if r.returncode == 0 else f"/* decompile.py rc {r.returncode} */\n"
        else:
            files["scaffold.c"] = "/* no target asm (banked target, self-test) */\n"
        if seed:
            files["seed.c"] = f"/* seed {pvs(*seed[0])} from {seed[1]} {seed[2]} */\n" + seed[3]
        for name, text in files.items():
            with open(os.path.join(pack, name), "w") as f:
                f.write(text)
        k += 1
        x5 = ctx.x5.get(pv)
        say(f"CARD {pvs(*pv)} seed {pvs(*seed[0]) if seed else '-'} twins {len(opens)} levers {','.join(levers) or '-'}"
            f" x5 {x5['unit'] + ':' + x5['vram'] if x5 else '-'}")
        if pv in seeded:
            sib = seeded[pv]
            text, m, u = sibling_c(ctx, pv, row, sib, root, wave)
            if text is None:
                say(f"CARD REFUSED {pvs(*pv)} seeded {m}")
                refused += 1
                continue
            spack = pack + ".seeded"
            os.makedirs(spack, exist_ok=True)
            meta.update(arm="seeded", sibling=sib, mapped=m, unmapped=u)
            files["pack.json"] = json.dumps(meta) + "\n"
            files["card.md"] = md.replace("\n## X5 twin\n", "\n## Sibling\n" + (
                f"sibling.c: {sib} C body as the starting draft, its symbols mapped to X6 names ({m} mapped, {u}"
                " unmapped" + (" kept with a `/* X5 */` marker" if sib.startswith("x5:") else " relocation notes") +
                "). Copy it to draft.c and adapt; keep X6's own types and declarations (ctx.h, include/)."
                " The gate proves it.\n") + "\n## X5 twin\n", 1)
            files["sibling.c"] = text
            for name, t in files.items():
                with open(os.path.join(spack, name), "w") as f:
                    f.write(t)
            k += 1
            say(f"CARD {pvs(*pv)} seeded sibling {sib} mapped {m} unmapped {u}")
    say(f"CARDS {wave} {k} packs")
    return 3 if k == 0 else (1 if refused else 0)


def self_test():
    shutil.rmtree(SELFTEST, ignore_errors=True)
    os.makedirs(SELFTEST)
    ok, ctx = True, Ctx()

    def check(cond, msg):
        nonlocal ok
        if not cond:
            ok = False
            print(f"SELFTEST FAIL {msg}")

    # planted: a function named without its address is known from a symbols file's `type:func`, not its spelling
    os.makedirs(os.path.join(SELFTEST, "config"))
    with open(os.path.join(SELFTEST, "config/symbols.P.txt"), "w") as f:
        f.write("// basis: planted\nalpha_helper = 0x80001000; // type:func size:0x8\n"
                "// basis: planted\nbeta_table = 0x80002000; // type:data\n")
    known = known_functions({"gamma_func"}, SELFTEST)
    got = card_globs("lui $a0, %hi(alpha_helper)\naddiu $a0, $a0, %lo(alpha_helper)\nlw $v0, %lo(beta_table)($at)\n"
                     "lw $v1, %gp_rel(gamma_func)($gp)\n", known)
    check(got == ["beta_table"], f"planted non-address names: globs {got}, want ['beta_table']")

    def run(wave, pv, jp, caps=""):
        tp = os.path.join(SELFTEST, f"{wave}.txt")
        with open(tp, "w") as f:
            f.write(pvs(*pv) + caps + "\n")
        said = []
        rc = write_cards(wave, tp, SELFTEST, jp, allow_banked=True, say=said.append)
        for s in said:
            print(f"  {s}")
        return rc, said

    # (a) a non-exemplar member of dup class 6d5cbe29 -> a banked twin (not itself) seeds it, shared body path.
    key = next((k for k in ctx.members if k.startswith("6d5cbe29")), None)
    check(key is not None, "dup class 6d5cbe29 absent from the census")
    mem = sorted(m for m in ctx.members.get(key, ()) if m not in ctx.exemplars)
    if mem:
        pv = mem[0]
        rc, said = run("W1", pv, os.path.join(SELFTEST, "empty.jsonl"))
        seed = re.match(r"CARD \S+ seed (\S+) ", said[0])
        check(rc == 0 and seed and seed.group(1) not in ("-", pvs(*pv)), f"(a) {pvs(*pv)} seed: {said[0]}")
        pack = os.path.join(SELFTEST, "W1", f"{pv[0]}_{ctx.funcs[pv]['name']}")
        md = open(os.path.join(pack, "card.md")).read() if os.path.isfile(os.path.join(pack, "card.md")) else ""
        check("body src/shared/entity/state_dispatch.c" in md and os.path.isfile(os.path.join(pack, "seed.c")),
              "(a) card names src/shared/entity/state_dispatch.c and writes seed.c")
        pj = os.path.join(pack, "pack.json")
        pk = json.load(open(pj)) if os.path.isfile(pj) else {}
        check("\ncaps -\n" in md and pk.get("probe", 0) is None and pk.get("attempts", 0) is None,
              "(a) no caps on the target line -> card.md `caps -`, pack.json probe/attempts null")
    else:
        check(False, "(a) no non-exemplar member")
    # (b)-(d) planted journal records for an asm target with asm on disk.
    tgt = next((p for p in sorted(ctx.funcs) if ctx.funcs[p]["state"] == "include_asm" and ctx.funcs[p]["lane"] ==
                "game" and target_asm(p[0], ctx.funcs[p]) is not None), None)
    check(tgt is not None, "no include_asm target with asm on disk")
    if tgt:
        row = ctx.funcs[tgt]
        for wave, ids, want in (("W2", "L05 and C0075", None), ("W3", "C9999", "C9999"), ("W4", "L99", "L99")):
            jp = os.path.join(SELFTEST, f"{wave}.jsonl")
            rec = dict(wave="W0", pv=pvs(*tgt), func=row["name"], words=row["words"], band=journal.band(row["words"]),
                       runs=1, verdict="fail", score=f"1/{row['words']}", label="regalloc", draft="-", lever="-",
                       notes=f"planted by cards.py --self-test: tried {ids}")
            check(journal.append(jp, json.dumps(rec), lambda s: None) == 0, f"{wave} journal plant refused")
            rc, said = run(wave, tgt, jp, " probe=18 attempts=2" if want is None else "")
            pack = os.path.join(SELFTEST, wave, f"{tgt[0]}_{row['name']}")
            if want is None:
                md = open(os.path.join(pack, "card.md")).read() if os.path.isdir(pack) else ""
                check(rc == 0 and rec["notes"] in md,
                      f"(b) {pvs(*tgt)} card carries the journal record: {said[0]}")
                pk = json.load(open(os.path.join(pack, "pack.json"))) if os.path.isdir(pack) else {}
                check("\ncaps probe 18 runs per attempt, attempts 2\n" in md and pk.get("probe") == 18
                      and pk.get("attempts") == 2, "(e) wave-line caps reach card.md and pack.json")
            else:
                check(said[0] == f"CARD REFUSED {pvs(*tgt)} {want}" and not os.path.exists(pack) and rc != 0,
                      f"({'c' if want[0] == 'C' else 'd'}) {pvs(*tgt)} {want} refused, no pack: {said[0]}")
        probe_plants(check, os.path.join(SELFTEST, "W2", f"{tgt[0]}_{row['name']}"), pvs(*tgt), row)
    outside_plant(check)
    # (f) an X5 twin: the card of a campaign/x4/x5-leads.tsv target carries `## X5 twin`; no lead row puts a G44 id on a card.
    check(len(ctx.x5) > 0, f"(f) {X5_LEADS} absent or empty")
    bad = [pvs(*k) for k, v in ctx.x5.items() if ID_RE.search("\n".join(x5_twin(v)))]
    check(not bad, f"(f) X5 twin lines with an L/C id token: {bad[:3]}")
    lead = next((p for p in sorted(ctx.x5) if p in ctx.funcs and target_asm(p[0], ctx.funcs[p]) is not None), None)
    check(lead is not None, "(f) no X5 lead target with asm on disk")
    if lead:
        rc, said = run("W5", lead, os.path.join(SELFTEST, "empty.jsonl"))
        pack = os.path.join(SELFTEST, "W5", f"{lead[0]}_{ctx.funcs[lead]['name']}")
        md = open(os.path.join(pack, "card.md")).read() if os.path.isdir(pack) else ""
        x5 = ctx.x5[lead]
        check(rc == 0 and said[0].endswith(f" x5 {x5['unit']}:{x5['vram']}") and
              f"\n## X5 twin\nmmx5 {x5['unit']} {x5['name']} " in md and f"`refs/mmx5/{x5['path']}`" in md and
              md.index("## X5 twin") < md.index("## Open twins"), f"(f) {pvs(*lead)} card carries its X5 twin: {said}")
    arm_plants(check, ctx)
    shutil.rmtree(SELFTEST, ignore_errors=True)
    print("CARDS CONTROL OK" if ok else "CARDS CONTROL FAIL")
    return 0 if ok else 1


def quiet(fn, *a, **kw):
    """(rc, stdout lines) of fn, its stdout captured (the self-test prints no probe output: G12)."""
    buf = io.StringIO()
    with contextlib.redirect_stdout(buf):
        rc = fn(*a, **kw)
    return rc, buf.getvalue().splitlines()


def slot_racer(path, q):
    q.put(probe_slot(path, 1, 1, lambda: (time.sleep(1), "planted")[1])[0])


def probe_plants(check, pack, pv, row):
    """(g) over-cap refused, nothing compiled; (h) one probe of a stub counts 1, writes both .s; (i) a slot race."""
    global snapshot, score
    probes = os.path.join(SELFTEST, "probes")
    cap, counter = probe_cap(row["words"]), counter_path(pack, os.path.abspath(probes))
    check(os.path.isfile(os.path.join(pack, "pack.json")) and cap > 0, f"(g) no pack or cap 0 for {pv}")
    os.makedirs(probes, exist_ok=True)
    with open(counter, "w") as f:
        f.write("".join(f"2000-01-01T00:00:00Z a1 planted\n" for _ in range(cap)))
    with open(os.path.join(pack, "draft.c"), "w") as f:
        f.write(f"void {row['name']}(void) {{}}\n")
    calls, real = [], (snapshot, score)
    snapshot = score = lambda *a, **kw: calls.append(a) or sys.exit("cards self-test: compiled over the cap")
    try:
        rc, out = quiet(probe_pack, pack, 0, True, probes)
    finally:
        snapshot, score = real
    check(rc == 3 and out[-1:] == [f"PACK {pv} refused probe-cap a1 {cap}/{cap}"] and not calls,
          f"(g) over-cap probe: rc {rc} {out[-1:]} compiles {len(calls)}")
    os.remove(counter)
    rc, out = quiet(probe_pack, pack, 0, True, probes)
    with open(counter) as f:
        lines = f.read().splitlines()
    files = [os.path.join(pack, n) for n in ("probe.ours.s", "probe.diff.s")]
    check(rc == 0 and out[-2:-1] == [f"PROBE {pv} a1 1/{cap}"] and out[-1].startswith(f"PACK {pv} ") and
          len(lines) == 1 and all(os.path.isfile(x) and os.path.getsize(x) for x in files),
          f"(h) one stub probe: rc {rc}, {len(lines)} counter lines, last {out[-1:]}")
    rc, out = quiet(probe_count, pack, probes)
    check(out == [f"PROBES {pv} a1 1/{cap}"], f"(h) --probe-count: {out}")
    import multiprocessing
    race = os.path.join(SELFTEST, "probes", "race.log")
    q = multiprocessing.Queue()
    ps = [multiprocessing.Process(target=slot_racer, args=(race, q)) for _ in range(2)]
    for x in ps:
        x.start()
    for x in ps:
        x.join()
    got = [q.get(timeout=5) for _ in ps]
    with open(race) as f:
        n = len(f.read().splitlines())
    check(got.count("planted") == 1 and got.count(None) == 1 and n == 1, f"(i) slot race under cap 1: {got}, {n} lines")


def arm_plants(check, ctx):
    """(k) an X5 snippet: a known callee renamed, a planted unknown marked; (l) INCLUDE_ASM refused, a dedup member read
    through its shared body; (m) an mmx4 row through x4port.port(), its seeded pack = the fresh files + sibling.c;
    (n) a proto-only row gets no seeded pack; (o) the tracked arm file = the sample rows whose prior-art lead is C."""
    pv, twin = ("rock_18", 0x800ED760), "func_8001F314"
    names = x5_names(ctx, pv, twin)
    snip = ("extern void func_800223E4(void);\nextern void func_8009FFF0(void);\n\nvoid func_8001F314(void) {\n"
            "    func_800223E4();\n    func_8009FFF0();\n}\n")  # synthetic, not X5's text
    out, m, u = x5_rename(snip, names, {decl_name(d) for d in top_decls(snip)} | {twin})
    callee = names.get("func_800223E4")
    check(callee and callee != "func_800223E4" and f"    {callee}();" in out and "    func_8009FFF0/* X5 */();" in out
          and f"void {ctx.funcs[pv]['name']}(void)" in out and (m, u) == (2, 1), f"(k) X5 rename: {m} {u}\n{out}")
    files = {"src/slus/func_80099900.c": '#include "types.h"\n\nINCLUDE_ASM("asm/nonmatchings/x", func_80099900);\n',
             "src/rockx5/func_800F0000_ovl02.c": '#include "types.h"\n\n#define DEDUP_NAME func_800F0000_ovl02\n'
             '#define DEDUP_CALLEE func_800F0100_ovl02\n\n#include "../shared/func_800F0000_ovl03.c"\n',
             "src/shared/func_800F0000_ovl03.c": '#include "types.h"\n\nextern void DEDUP_CALLEE(void);\n\n'
             'void DEDUP_NAME(void) {\n    DEDUP_CALLEE();\n}\n'}
    text, why = x5_extract(files.get, "slus", "0x80099900", "func_80099900")
    check(text is None and why.startswith("include-asm"), f"(l) INCLUDE_ASM X5 file not refused: {why}")
    text, why = x5_extract(files.get, "ovl02", "0x800F0000", "func_800F0000_ovl02")
    check(text is not None and "extern void func_800F0100_ovl02(void);" in text and
          "void func_800F0000_ovl02(void) {" in text and len(why) == 2, f"(l) dedup member: {why}")
    # (m)/(n): the x4 row's seeded pack through a planted x4port.port; the proto-only row is fresh only.
    import x4port
    x4, proto = (MAIN, 0x8001FB3C), ("rock_23", 0x800F25FC)
    want = partners_of(*x4)
    calls, real = [], (x4port.port, x4port.mmx4_ctx)
    x4port.mmx4_ctx = lambda: "planted"
    x4port.port = lambda c, p, row, key, src, xf, tamper=None: (calls.append((p, row["name"], key, src, xf)), (
        "/* planted port */\nvoid f(void) {}\n", "x4 port planted", []))[1]
    ap, tp = os.path.join(SELFTEST, "arm.tsv"), os.path.join(SELFTEST, "W6.txt")
    with open(ap, "w") as f:
        f.write("\t".join(ARM_COLS) + "\n" + "".join(f"holdout\t{x4[0]}\t0x{x4[1]:08X}\t-\t{a}\t{s}\n"
                                                      for a, s in (("fresh", "-"), ("seeded", sibling_of(*x4)))))
    with open(tp, "w") as f:
        f.write(pvs(*proto) + "\n")
    _X4CTX.clear()
    try:
        said = []
        rc = write_cards("W6", tp, SELFTEST, os.path.join(SELFTEST, "empty.jsonl"), True, said.append, ap)
    finally:
        x4port.port, x4port.mmx4_ctx = real
        _X4CTX.clear()
    for s in said:
        print(f"  {s}")
    base = os.path.join(SELFTEST, "W6", f"{x4[0]}_{ctx.funcs[x4]['name']}")
    ls = {d: sorted(os.listdir(d)) if os.path.isdir(d) else [] for d in (base, base + ".seeded")}
    rd = lambda d, n: open(os.path.join(d, n)).read() if os.path.isfile(os.path.join(d, n)) else ""  # noqa: E731
    pk = json.loads(rd(base + ".seeded", "pack.json") or "{}")
    check(rc == 0 and want and calls == [(x4[0], ctx.funcs[x4]["name"], want[0][2], want[0][0], want[0][1])] and
          pk.get("arm") == "seeded" and pk.get("sibling") == f"x4:{want[0][0]}:{want[0][1]}" and
          rd(base + ".seeded", "sibling.c").startswith("/* planted port */") and
          json.loads(rd(base, "pack.json") or "{}").get("arm") == "fresh", f"(m) x4 row through port(): {calls} {pk}")
    check(ls[base + ".seeded"] == sorted(ls[base] + ["sibling.c"]) and
          rd(base, "seed.c") == rd(base + ".seeded", "seed.c") and "## Sibling" not in rd(base, "card.md") and
          "\n## Sibling\nsibling.c: x4:" in rd(base + ".seeded", "card.md"), f"(m) seeded = fresh + sibling.c: {ls}")
    pp = os.path.join(SELFTEST, "W6", f"{proto[0]}_{ctx.funcs[proto]['name']}")
    check(sibling_of(*proto) is None and os.path.isdir(pp) and not os.path.exists(pp + ".seeded") and
          "arm" not in json.loads(rd(pp, "pack.json") or "{}"), "(n) proto-only row: fresh pack only")
    # (o) the tracked arm file
    want, n = [], Counter()
    with open(SAMPLE) as f:
        for t in (x.rstrip("\n").split("\t") for x in f if not x.startswith("#")):
            if "c" in (t[8], t[9]):
                n[t[13]] += 1
                n["other"] += (t[10], t[11]) != ("-", "-")
                for a in ("fresh", "seeded"):
                    want.append((t[13], t[1], int(t[2], 16), t[3], a, sibling_of(t[1], int(t[2], 16)) if a == "seeded"
                                 else "-"))
    check(read_arm(ARM) == want and n == Counter(pilot=2, holdout=7) and None not in [w[5] for w in want],
          f"(o) {ARM} differs from the sample's prior-art C rows: {n}")


def outside_plant(check):
    """(j) a planted mx-run log: probe-pack and depin allowed, probe.py / make / bash x.sh OUTSIDE."""
    log = os.path.join(SELFTEST, "mx-run.log")
    runs = ["python3 tools/mmx6/cards.py --probe-pack waves/W9/P_f", "python3 tools/mmx6/depin.py --help",
            "python3 tools/mmx6/probe.py --func f", "make build", "bash x.sh"]
    with open(log, "w") as f:
        f.write("".join(f"2026-01-01T00:00:0{i}Z mmx6-work {r}\n" for i, r in enumerate(runs)))
    rc, out = quiet(outside, log)
    flagged = [x.split(" ", 2)[2] for x in out[:-1] if x.startswith("OUTSIDE ")]
    check(rc == 0 and flagged == runs[2:] and out[-1] == "OUTSIDE 3 of 5 runs", f"(j) outside: {flagged} {out[-1:]}")


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n", 1)[0])
    g = ap.add_mutually_exclusive_group(required=True)
    g.add_argument("--probe-pack", metavar="DIR")
    g.add_argument("--wave", metavar="W<n>")
    g.add_argument("--self-test", action="store_true")
    g.add_argument("--probe-count", metavar="DIR")
    g.add_argument("--outside", metavar="LOG")
    g.add_argument("--x5-fetch", metavar="W<n>", help="host: seeded x5 rows of --arm from mmx5-dev HEAD -> <root>/W/.x5/")
    ap.add_argument("--arm", metavar="FILE", help="seeded-arm rows (config/methods-arm.tsv): fresh + .seeded packs")
    ap.add_argument("--show", action="store_true")
    ap.add_argument("--since", metavar="ISO")
    ap.add_argument("--until", metavar="ISO")
    ap.add_argument("--match", metavar="S")
    ap.add_argument("--hold", type=float, default=0)
    ap.add_argument("--no-snapshot", action="store_true")
    ap.add_argument("--probes", metavar="DIR", help="probe-cap counter dir (default waves/.probes); self-test scratch only")
    ap.add_argument("--targets", metavar="FILE")
    ap.add_argument("--root", default="waves")
    ap.add_argument("--journal", default=journal.JOURNAL)
    a = ap.parse_args()
    if a.probe_pack:
        return probe_pack(a.probe_pack, a.hold, not a.no_snapshot, a.probes, show=a.show)
    if a.probe_count:
        return probe_count(a.probe_count)
    if a.outside:
        return outside(a.outside, a.since, a.until, a.match)
    tp = os.path.abspath(a.targets) if a.targets else None
    root, jp = os.path.abspath(a.root), os.path.abspath(a.journal)
    arm = os.path.abspath(a.arm) if a.arm else None
    os.chdir(ROOT)
    if a.self_test:
        return self_test()
    if a.x5_fetch:
        if not arm or not re.fullmatch(r"W\d+|W-[a-z0-9]+", a.x5_fetch):
            ap.error("--x5-fetch W<n> needs --arm <file>")
        return x5_fetch(a.x5_fetch, root, arm)
    if not re.fullmatch(r"W\d+|W-[a-z0-9]+", a.wave) or not (tp or arm):
        ap.error("--wave W<n> needs --targets <file> or --arm <file>")
    return write_cards(a.wave, tp, root, jp, arm=arm)


if __name__ == "__main__":
    sys.exit(main())
