#!/usr/bin/env python3
"""bank.py -- the reconcile ladder: bank one body into its real TU, rung by rung (container python3, stdlib only).

  bank.py <prog:vram> --src <file>
      -> preflight: the corpus row (build/corpus/functions.jsonl) is include_asm in a TU of config/c_units.txt
         (segment.c_units) with its INCLUDE_ASM line found (layout.find_asm), else
         `RECONCILE <func> refused: <cause>` (rc 2). Rungs:
         R1 sha1 of --src recorded; probe.probe under the Makefile default TRIPLE must MATCH.
         R2 in the file tools/mmx6/layout.py find_asm names (the unit src/<prog>/<tu>.c or a role file of its
            #include closure) the line `INCLUDE_ASM("asm/<prog>/nonmatchings/<tu>", <func>);` becomes
            `#include "<src relative to that file's dir>"`; the unit object must compile. Already placed (the unit's
            closure defines <func> from --src, layout.Tree: any file, multi-function included): re-gated, not edited.
         R3 declsync.sync over the program's C files (refusal or declsync error stops); typecheck.py --files <edited + body>; edited
            units recompile. Cross-key guard (T2.c3): an edited file that is another key's shared body (a shared path
            of config/dedup_registry.txt, or any src/shared/ file other than the body) is kept only when the objects
            of its built includers (layout.includers; build/src/<p>/<tu>.c.o, `make -B` before and after the edits)
            have the same objdump -dr and .text/.data/.rodata/.sdata contents (file names dropped), else stop
            `declsync would change another key's bytes (<paths>)`; no built includer: no linked bytes, kept. Each
            kept one counts (bank.XKEY); `RECONCILE <func> xkey <n> accepted` precedes the verdict line.
         R4 stop on a config/boundaries.txt jtbl row of the program with lo inside the function ("jtbl not carved"),
            or on unit .rodata grown vs the pre-bank object ("rodata needs placement").
         R5 clean rebuild of the program (C objects, elf, binary removed; C0034) and its sha1 check; then the body
            sha1 must equal R1's, typecheck.py --all and sig.py --rescan must pass; a body under src/shared/ gets its
            config/dedup_registry.txt row (appended, line-preserving, only if absent).
         One verdict line: `RECONCILE <func> R5 banked; body sha1 <h> unchanged since R1` (rc 0) or
         `RECONCILE <func> stopped R<k>: <cause>` (rc 1). A stop restores every edited file byte-exact and rebuilds
         the program so build/ matches the tree; it never asks for a body redraft. Logs under .run/bank/.
  --repair NAME (repeatable; shared with propagate.py and refusecause.py; all off by default, off = unchanged):
      declunify (3.1 T3): an R2 `does not compile` whose log names `conflicting types for X` or `too few arguments to
         function X` -> declunify(): each declaration of X in the member's TU closure disagreeing with the body's
         gets the body's spelling, mismatching call sites an unprototyped cast; cross-key edits pass the R3 guard; then
         the ladder once more; verdict `... unchanged since R1 via declunify`. T3.c2: a conflict whose body side is
         the looser declaration (C0434) rewrites the body's declaration lines instead; `redefinition of X` wraps X's
         definition sites in a DU_DEF_X include guard; a body edit also needs the exemplar's R1 MATCH.
      rolefeed (3.1 T4): a member (--define, the exemplar from its registry row) whose shared path is outside
         src/shared/ and that stops on a path cause (refusecause.classify: R1 compile errors of the shared path fed
         standalone, or an R1/R2 assembler `already defined`) -> rolefeed(): the exemplar's layout.locate range moves
         to layout.new_body(exemplar), its old place `#include`s it; every including unit's object keeps its bytes
         (objdump, else `rolefeed exemplar bytes changed`); then the ladder once more on the new body, verdict
         `... via rolefeed`, the key's registry rows on the old path re-pointed to it. The new body's first line
         `// rolefeed (3.1 T4): <exemplar function> of <unit>` makes R1 (switch on or off) compile that including
         unit itself (C0302) and compare the exemplar function's words with the member's retail words (probe_via).
      unitcut (3.1 T6; propagate.py / refusecause.py): a member (defines on) whose shared path is the exemplar's own
         whole unit holding other code (uc_due) -> before its gate, rolefeed()'s extraction of the exemplar, then the
         ladder on the new body only (no predecessor code shifts the member); verdict `... via unitcut`.
  bank.py <prog:vram> --src <shared body> --define OLD=NEW [--define ...]
      -> a shared body under other names (T5, tools/mmx6/propagate.py): R1 probes a scratch wrapper
         .run/bank/wrap/<prog>/<func>.c (`#define OLD NEW` lines + `#include` of the body); R2 writes that block, then
         `#undef OLD` lines, in place of the INCLUDE_ASM line; R3 syncs against the renamed definition. A unit that
         already holds the block (corpus state c) is re-gated, not re-edited. No registry row (propagate.py writes it).
  bank.py --self-test
      -> planted controls (C0054) on planted include_asm siblings: X, Y = the two lowest-vram exe members of the
         exemplar's dup class whose unit holds a define block for src/shared/entity/state_dispatch.c; each block becomes
         `INCLUDE_ASM(...)` of a generated asm/<prog>/nonmatchings/<tu>/<func>.s (`.word`s of probe.retail_words plus
         the untrimmed tail); the program must rebuild to its pre-test sha1 (else FAIL); corpus.py --all regenerates
         the corpus. Bodies generated into src/shared/_selftest/: A = X with X's own table (its block's define) and a
         planted width-compatible prototype `void X(s32);` in src/SLUS_013.95/LIBSPU_S_M_UTIL.c -> R3 syncs it,
         `R5 banked`, plus a planted shared body src/shared/_selftest/xkey.c (`void X(int);`, #included by that unit)
         synced byte-neutral -> `xkey 1 accepted`; B = Y with the exemplar's table (masked standalone MATCH, wrong
         binary) -> `stopped R5`; C = X with xkey.c holding a block-scope `int X(void*);` (sync leaves it) and a call
         `((void (*)(void*))X)(p)` that sync uncasts (the int return changes registers) -> `stopped R3: declsync would change another key's bytes (src/shared/_selftest/xkey.c)`. Never
         writes the registry; after each control the planted state is restored and rebuilt; teardown restores src/,
         the registry and build/corpus/*.jsonl byte-exact, deletes the planted .s files and rebuilds; fail-closed end
         check: src/ tree, registry and program binary sha1 equal their pre-test values.
         Second pass: the same controls with X's unit a layout.role_tree plant (thin unit over
         src/<prog>/selftest_role/<tu>.c, which includes X's role file: X's block found there unchanged, R2 edits that
         role file through the extra include level), `bank: role-tree pass on <tu> -> <role>`, lines
         `role-tree control ...`. Prints each control's verdict line, then `RECONCILE CONTROL OK` (rc 0), else
         `RECONCILE SELF-TEST FAIL` rc 1.
Firewall G12: names, addresses, counts and hashes of our own files only.
"""
import argparse
import contextlib
import glob
import hashlib
import io
import json
import os
import re
import shutil
import struct
import subprocess
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import corpus  # noqa: E402
import declsync  # noqa: E402
import layout  # noqa: E402
import probe  # noqa: E402
import segment  # noqa: E402

LOGDIR = ".run/bank"
REGISTRY = "config/dedup_registry.txt"
REGISTRY_HEAD = ("# config/dedup_registry.txt -- shared bodies and their members (tools/mmx6/bank.py); line-preserving.\n"
                 "# <dup key> <exemplar prog:vram> <shared path> <member prog:vram> <state gated|pending|refused> "
                 "<reason>\n")
EXEMPLAR = ("SLUS_013.95", 0x8003744C, 0x80073C1C, "src/shared/entity/state_dispatch.c")  # prog, body, table vram
SELFTEST_DIR = "src/shared/_selftest"
PLANT_UNIT = "src/SLUS_013.95/LIBSPU_S_M_UTIL.c"
OBJDUMP = "mipsel-linux-gnu-objdump"
XKEY = [0]  # cross-key edits R3 accepted in this process (cumulative; bank() and propagate.run_group read deltas)
# DISABLED: declunify, rolefeed (3.1 T19 verdict, rule 7) — 2026-11-13 / 3.1
#   Original intent: declunify unifies a member's conflicting declarations (T3), rolefeed feeds a role-file member the
#   extracted exemplar body (T4). Both stay in REPAIRS (still selectable) but are off in the waves' switch set.
#   Why disabled: tie on the holdout, which goes to the before. No holdout row (n 6 declaration, 4 path) and no pilot row gated
#   through either; every repair gate was [via relocdef] and/or [via unitcut] (campaign/refusecause.holdout-all.tsv,
#   .pilot-all.tsv; docs/ops/methods-gen3.md ## Verdicts). Wave banks run `--repair relocdef --repair unitcut`.
#   Re-enable if a header-level declaration decision (T3's g_Player, move_object rows) or rolefeed's carried-declarations
#   follow-up makes either gate rows the adopted pair does not, measured by refusecause --count against
#   campaign/refusecause.after.tsv.
REPAIRS = ("declunify", "rolefeed", "relocdef", "unitcut")  # named repair switches (3.1 T3-T6), each off by default: `--repair NAME`, repeatable
REPAIR = set()  # the switches on in this process (repair_set; propagate's fork workers inherit it)
UNIFY_RE = re.compile(r"(too few arguments to function|conflicting types for) [`'‘]([A-Za-z_]\w*)['’]")
_FROM = r"\n(?:(?:In file included from|\s+from) .*\n)*"  # gcc's include-chain lines between a diagnostic pair
CONFLICT_RE = re.compile(rf"^(\S+?):(\d+): conflicting types for [`'‘](\w+)['’]{_FROM}(\S+?):(\d+): previous "
                         rf"declaration of [`'‘]\w+['’]", re.M)  # T3.c2: the two locations of a conflict
REDEF_RE = re.compile(rf"^(\S+?):(\d+): redefinition of [`'‘](\w+)['’]{_FROM}(\S+?):(\d+): [`'‘]\w+['’] "
                      rf"previously defined here", re.M)
LOOSE = {"M2C_UNK", "s32", "int", "u32", "unsigned int", "signed int"}  # an object type looser than a struct/array one
RF_RE = re.compile(r"^// rolefeed \(3\.1 T4\): (\w+) of (\S+)$")  # a rolefeed body's first line: name, including unit


def exemplar():
    """(prog, vram, function name, table name, shared path) of EXEMPLAR, its names looked up now (probe.sym_name)."""
    prog, ev, tv, esrc = EXEMPLAR
    return prog, ev, probe.sym_name(prog, ev), probe.sym_name(prog, tv, "D"), esrc


class Stop(Exception):
    def __init__(self, rung, cause):
        super().__init__(cause)
        self.rung, self.cause = rung, cause


# ---- helpers -------------------------------------------------------------------------------------------------------

def sha1(path):
    with open(path, "rb") as f:
        return hashlib.sha1(f.read()).hexdigest()


def sh(cmd, log):
    """rc of cmd (list), its output appended to .run/bank/<log>.log."""
    os.makedirs(LOGDIR, exist_ok=True)
    with open(os.path.join(LOGDIR, log + ".log"), "a") as f:
        f.write("$ " + " ".join(cmd) + "\n")
        f.flush()
        return subprocess.run(cmd, stdout=f, stderr=subprocess.STDOUT).returncode


def makefile_triple():
    with open("Makefile") as f:
        return re.search(r"^TRIPLE \?= (\S+)", f.read(), re.M).group(1)


def corpus_row(prog, vram):
    with open("build/corpus/functions.jsonl") as f:
        for line in f:
            r = json.loads(line)
            if r["prog"] == prog and int(r["vram"], 16) == vram:
                return r
    return None


def bin_out(prog):
    return f"build/rock/{prog[5:]}.bin" if prog.startswith("rock_") else f"build/{prog}"


def rodata_size(obj):
    """Total size of the .rodata* sections of an ELF32 LE object."""
    with open(obj, "rb") as f:
        b = f.read()
    shoff, = struct.unpack_from("<I", b, 0x20)
    shentsize, shnum, shstrndx = struct.unpack_from("<HHH", b, 0x2E)
    secs = [struct.unpack_from("<10I", b, shoff + i * shentsize) for i in range(shnum)]
    names = secs[shstrndx][4]
    total = 0
    for s in secs:
        if b[names + s[0]:b.index(b"\0", names + s[0])].decode().startswith(".rodata"):
            total += s[5]
    return total


def rebuild(prog, log):
    """Clean rebuild of prog (its C objects, elf and binary removed first, C0034); rc of make."""
    for p in glob.glob(f"build/src/{prog}/**/*.c.o", recursive=True) + [f"build/{prog}.elf", bin_out(prog)]:
        if os.path.exists(p):
            os.remove(p)
    return sh(["make", "-s", bin_out(prog)], log)


def put(saved, path, text):
    """Write text to path, recording the original bytes (None: absent) once."""
    if path not in saved:
        saved[path] = open(path, "rb").read() if os.path.exists(path) else None
    with open(path, "w") as f:
        f.write(text)


def restore(saved):
    for p, b in saved.items():
        if b is None:
            if os.path.exists(p):
                os.remove(p)
        else:
            with open(p, "wb") as f:
                f.write(b)


def dup_key(prog, vram):
    with open("build/census/classes.jsonl") as f:
        for line in f:
            r = json.loads(line)
            if r["kind"] == "dup" and any(m[0] == prog and int(m[1], 16) == vram for m in r["members"]):
                return r
    return None


def subst(text, defines):
    """text with each whole-word OLD of defines [(OLD, NEW)] replaced by NEW (what cpp makes of the body)."""
    for old, new in defines:
        text = re.sub(rf"\b{re.escape(old)}\b", new, text)
    return text


def block(src, where, defines):
    """Lines that instantiate src from a file in directory where: defines, the #include, the #undefs."""
    return ([f"#define {o} {n}" for o, n in defines] + [f'#include "{os.path.relpath(src, where)}"']
            + [f"#undef {o}" for o, _ in defines])


def placed(prog, func, src, tu):
    """True when unit tu's #include closure defines func from src (layout: any file, a multi-function one included;
    a body under another member's alias block defines that member's name, not func). cwd = the tree."""
    try:
        return any(f.kind == "def" and f.name == func and f.path == os.path.relpath(src)
                   for f in layout.Tree(os.getcwd()).fns(prog, tu))
    except (layout.Refuse, OSError):
        return False


def find_asm(prog, func):
    """layout.find_asm over the tree at cwd (a gate snapshot, a dry-run copy, the repo); a closure defect -> None."""
    try:
        return layout.find_asm(prog, func, os.getcwd())
    except (layout.Refuse, OSError):
        return None


def obj_text(o):
    """objdump -dr + contents of .text/.data/.rodata/.sdata* of an object, the lines naming its file dropped."""
    run = lambda *a: subprocess.run([OBJDUMP, *a, o], capture_output=True, text=True, check=True).stdout  # noqa: E731
    secs = sorted({s for s in re.findall(r"^\s*\d+\s+(\S+)", run("-h"), re.M)
                   if re.match(r"\.(text|data|rodata|sdata|rdata)", s)})
    out = run("-dr") + "".join(run("-s", "-j", s) for s in secs)
    return "\n".join(x for x in out.splitlines() if o not in x)


def xkey_guard(src, edits, saved, log):
    """R3 cross-key guard (T2.c3): count of edited files that are another key's shared body, kept when their built
    includers' objects are unchanged by the edits; raises Stop(3) (originals written back, includers rebuilt) else."""
    shared = set()
    if os.path.isfile(REGISTRY):
        with open(REGISTRY) as f:
            shared = {x.split()[2] for x in f if not x.startswith("#") and len(x.split()) > 2}
    own = os.path.relpath(src)
    xs = sorted(p for p in edits if os.path.relpath(p) != own
                and (os.path.relpath(p) in shared or os.path.relpath(p).startswith("src/shared/")))
    if not xs:
        return 0
    inc = layout.includers(os.getcwd())
    objs = {p: [o for o in (f"build/src/{q}/{tu}.c.o" for q, tu in inc.get(os.path.relpath(p), []))
                if os.path.isfile(o)] for p in xs}
    built = sorted({o for v in objs.values() for o in v})

    def write(texts):  # every edited file (before: all originals, so the includers compile as before the sync)
        for p in edits:
            with open(p, "wb") as f:
                f.write(texts[p] if isinstance(texts[p], bytes) else texts[p].encode())

    def snap():
        for o in built:
            if sh(["make", "-s", "-B", o], log):
                raise Stop(3, f"includer {o} of {' '.join(xs)} does not compile (log {LOGDIR}/{log}.log)")
        return {o: obj_text(o) for o in built}

    def back():  # originals written back, no includer object left built from the edits
        write(saved)
        for o in built:
            sh(["make", "-s", "-B", o], log)

    if built:
        try:
            write(saved)
            before = snap()
            write(edits)
            after = snap()
        except Stop:
            back()
            raise
        changed = [p for p in xs if any(before[o] != after[o] for o in objs[p])]
        if changed:
            back()
            raise Stop(3, f"declsync would change another key's bytes ({' '.join(changed)})")
    XKEY[0] += len(xs)
    return len(xs)


def repair_arg(ap):
    """The shared `--repair NAME` option (bank.py, propagate.py, refusecause.py); repair_set(args) turns them on."""
    ap.add_argument("--repair", action="append", default=[], choices=REPAIRS, metavar="NAME",
                    help=f"turn on a named repair switch ({', '.join(REPAIRS)}); repeatable; all off by default")


def repair_set(a):
    REPAIR.update(a.repair)


def decl_at(path, line, name):
    """declsync.body_decl of the last declaration of name at or before path:line (a gcc diagnostic location: the
    R2 block, restored since, may have shifted lines after it), or None."""
    try:
        with open(path, errors="replace") as f:
            text = f.read().split("\n")
    except OSError:
        return None
    for ln in reversed(text[:line]):
        d = declsync.body_decl(ln.strip(), name) if name in ln else None
        if d is not None:
            return d
    return None


def loose(b, o):
    """True when the body's declaration b is the looser side of o (C0434): an `extern <s32-like> X;` object against
    a struct/array one or a function, an unprototyped `()` against a prototype, a `void` return against a 4-byte one."""
    if b[0] == "obj":
        return declsync.norm(b[1]) in LOOSE and (o[0] == "fn" or declsync.norm(o[1]) not in LOOSE
                                                 or bool(o[2]) > bool(b[2]))
    return o[0] == "fn" and ((not b[2] and bool(o[2])) or
                             (declsync.norm(b[1]) == "void" and declsync.width(o[1]) == 4))


def def_span(lines, i):
    """(first, last) line indices of the definition whose declarator is on lines[i] (its return-type lines above it
    included; a function to its closing brace, data to its `;`), or None."""
    s = i
    while s > 0 and lines[s - 1].strip() and not lines[s - 1].lstrip().startswith(("#", "/", "*")) \
            and not lines[s - 1].rstrip().endswith((";", "}", "{", "*/")):
        s -= 1
    depth, seen = 0, False
    for j in range(i, len(lines)):
        for c in re.sub(r"//.*|/\*.*?\*/|\"(?:\\.|[^\"\\])*\"|'(?:\\.|[^'\\])*'", "", lines[j]):
            if c == "{":
                depth, seen = depth + 1, True
            elif c == "}":
                depth -= 1
            elif c == ";" and not seen and depth == 0:
                return s, j
        if seen and depth <= 0:
            return s, j
    return None


def guard_text(path, text, sites, name):
    """(new text, [lines]): each definition of name at the 1-based lines sites of text wrapped in
    `#ifndef DU_DEF_<name>` / `#define DU_DEF_<name>` / `#endif`, so the TU defines it once (T3.c2 redefinition)."""
    lines, out, g = text.split("\n"), [], f"DU_DEF_{name}"
    for ln in sorted(set(sites), reverse=True):
        sp = def_span(lines, ln - 1)
        if sp is None or (sp[0] > 0 and lines[sp[0] - 1].strip() == f"#define {g}"):
            continue
        lines[sp[0]:sp[1] + 1] = [f"#ifndef {g}", f"#define {g}"] + lines[sp[0]:sp[1] + 1] + ["#endif"]
        out.append(f"DECLUNIFY guard {path}:{ln} {name}")
    return "\n".join(lines), out


def ex_of(prog, vram, src):
    """(exemplar prog, function) of the member's registry row for body src, or None (declunify then skips the
    exemplar R1 check)."""
    if not os.path.isfile(REGISTRY):
        return None
    with open(REGISTRY) as f:
        rows = [x.split() for x in f if not x.startswith("#") and len(x.split()) > 3]
    t = next((t for t in rows if t[2] == src and t[3] == f"{prog}:0x{vram:08X}"), None)
    if t is None:
        return None
    p, _, v = t[1].rpartition(":")
    return p, corpus_row(p, int(v, 16))["name"]


def declunify(unit, src, defines, tail, saved, log, ex=None):
    """Repair switch `declunify` (3.1 T3) after an R2 `does not compile`: per X of tail's `conflicting types for X` /
    `too few arguments to function X` with a declaration in the body (defines applied; declsync.body_decl), every file
    of the member's TU closure (declsync.unit_files from its unit .c; never the body) gets declsync.unify_text.
    T3.c2: a `conflicting types` pair whose body-side declaration is the looser one (loose, C0434) and whose name the
    defines leave alone rewrites the body's declarations of X to the other location's instead (unify_text on the body:
    calls whose return differs cast to the old one); a `redefinition of X` pair wraps each definition site
    in a DU_DEF_X include guard (guard_text). (files edited, note): 0 -> nothing edited. Edits pass xkey_guard (every
    shared body, the body itself included: includer objects keep their bytes) and, when the body is edited and ex =
    (exemplar prog, function) is given, the exemplar's R1 probe on the edited body, else Stop(2, `declunify <cause>`),
    nothing kept; then recorded in saved (put)."""
    names = list(dict.fromkeys(m.group(2) for m in UNIFY_RE.finditer(tail)))
    redefs = {}
    for m in REDEF_RE.finditer(tail):
        for p, ln in ((m.group(1), m.group(2)), (m.group(4), m.group(5))):
            redefs.setdefault(m.group(3), set()).add((os.path.normpath(p), int(ln)))
    if not names and not redefs:
        return 0, "n/a"
    with open(src, errors="replace") as f:
        raw = f.read()
    body = subst(raw, defines)
    decls = {n: d for n in names for d in [declsync.body_decl(body, n)] if d}
    if not decls and not redefs:
        return 0, f"no body declaration of {' '.join(names)}"
    own = os.path.abspath(src)
    renamed = {x for d in defines for x in d}
    bside = {}
    for m in CONFLICT_RE.finditer(tail):
        n, locs = m.group(3), ((m.group(1), int(m.group(2))), (m.group(4), int(m.group(5))))
        other = [(p, ln) for p, ln in locs if os.path.abspath(p) != own]
        if n in decls and n not in renamed and len(other) == 1:
            o = decl_at(other[0][0], other[0][1], n)
            if o is not None and loose(decls[n], o):
                bside[n] = o
    files = [p for p in declsync.unit_files(None, [unit]) if os.path.abspath(p) != own]
    texts = {}
    for p in files:
        with open(p, errors="replace") as f:
            texts[p] = f.read()
    new, lines = dict(texts), []
    for n in sorted(set(decls) - set(bside)):
        olds = [o for p in files for o in declsync.unify_text(p, new[p], n, decls[n])[2]]
        for p in files:
            new[p], ls, _ = declsync.unify_text(p, new[p], n, decls[n], olds[0] if olds else None)
            lines += ls
    texts[src] = new[src] = raw
    for n in sorted(bside):
        new[src], ls, _ = declsync.unify_text(src, new[src], n, bside[n])
        lines += ls
    for n in sorted(redefs):
        by = {}
        for p, ln in redefs[n]:
            by.setdefault(next((q for q in new if os.path.abspath(q) == os.path.abspath(p)), p), []).append(ln)
        for p, lns in sorted(by.items()):
            if p not in new:
                with open(p, errors="replace") as f:
                    texts[p] = new[p] = f.read()
            new[p], ls = guard_text(p, new[p], lns, n)
            lines += ls
    edits = {p: t for p, t in new.items() if t != texts[p]}
    with open(os.path.join(LOGDIR, log + ".log"), "a") as f:
        f.write("".join(x + "\n" for x in lines))
    if not edits:
        return 0, f"no edit ({' '.join(sorted(set(decls) | set(redefs)))})"
    orig = {p: open(p, "rb").read() for p in edits}
    try:
        x = xkey_guard(unit, edits, orig, log)
        if src in edits and ex is not None:
            with open(src, "w") as f:
                f.write(edits[src])
            try:
                ok, mw, nw = probe.probe(ex[1], ex[0], src, makefile_triple())
            except SystemExit as e:
                ok, mw, nw = False, 0, f"? ({e})"
            if not ok:
                raise Stop(2, f"exemplar {ex[0]}:{ex[1]} R1 FAIL {mw}/{nw} words on the edited body")
    except Stop as e:
        for p in edits:
            with open(p, "wb") as f:
                f.write(orig[p])
        raise Stop(2, f"declunify {e.cause}")
    for p, t in sorted(edits.items()):  # the originals read above: xkey_guard may have left the edits on disk already
        saved.setdefault(p, orig[p])
        put(saved, p, t)
    return len(edits), f"{len(edits)} files xkey {x}" + (" body" if src in edits else "")


def rf_unit(src):
    """(function, including unit) of a rolefeed body's first line (RF_RE), else None."""
    try:
        with open(src, errors="replace") as f:
            m = RF_RE.match(f.readline().rstrip("\n"))
    except OSError:
        return None
    return m.groups() if m else None


def probe_via(func, prog, name, unit, triple, log):
    """R1 of a rolefeed body (3.1 T4): the including unit compiled as itself (probe.compile_obj, its own CFLAGS,
    C0302), the words of name against func's retail words, reloc fields masked; prints probe's result line. A compile
    failure appends probe's compile log to the bank log (refusecause reads it)."""
    ret = probe.retail_words(prog, func)
    obj = probe.compile_obj(unit, triple)
    ours, masks = probe.elf_function(obj, name) if obj else ([], {})
    if obj is None:
        d = os.path.dirname(unit).replace("/", "_").lstrip(".") or "_"
        p = os.path.join(".run/probe", triple, d, os.path.basename(unit) + ".log")
        with open(os.path.join(LOGDIR, log + ".log"), "a") as f, open(p, errors="replace") as g:
            f.write(g.read())
    keep = [~masks.get(i, 0) & 0xFFFFFFFF for i in range(min(len(ret), len(ours)))]
    matched = sum((ret[i] & k) == (ours[i] & k) for i, k in enumerate(keep))
    ok = obj is not None and len(ours) == len(ret) and matched == len(ret)
    print(f"{func} {triple} {'MATCH' if ok else 'FAIL'} {matched}/{len(ret)} words (via {unit})", flush=True)
    return ok, matched, len(ret)


def r1_log(prog, vram, src, defines):
    """Text of the member's R1 probe compile log (probe.compile_obj's path of src or its define wrapper), else ''."""
    r = corpus_row(prog, vram) if os.path.isfile("build/corpus/functions.jsonl") else None
    if r is None:
        return ""
    p = os.path.join(LOGDIR, "wrap", prog, r["name"] + ".c") if defines else src
    d = os.path.dirname(p).replace("/", "_").lstrip(".") or "_"
    try:
        with open(os.path.join(".run/probe", makefile_triple(), d, os.path.basename(p) + ".log"), errors="replace") as f:
            return f.read()
    except OSError:
        return ""


def rf_due(prog, vram, src, defines, why, tail):
    """Repair switch rolefeed's trigger (3.1 T4): on, src outside src/shared/, and the refusal why (`refused R<k>: ...`)
    an R1 stop with any compile error (refusecause.DIAG_RE, no warning/note) in the probe compile log or tail (the
    gate's bank log; a parse error cascades into `undeclared` lines), or an R1/R2 stop refusecause.classify calls path
    (gas `already defined`)."""
    mo = re.match(r"refused R([12]): (.*)", why)
    if "rolefeed" not in REPAIR or not mo or os.path.relpath(src).startswith("src/shared/"):
        return False
    import refusecause  # lazy: refusecause imports this module
    text = tail + (r1_log(prog, vram, src, defines) if mo.group(1) == "1" else "")
    if mo.group(1) == "1" and any(refusecause.DIAG_RE.match(ln) and "warning:" not in ln and "note:" not in ln
                                  for ln in text.splitlines()):
        return True
    return refusecause.classify(dict(stop=(int(mo.group(1)), mo.group(2)), log=text))[0] == "path"


def rf_where(ex, src):
    """(file, first line, last line, including units (exemplar's prog/tu first, C0302), new body path) of exemplar
    ex = (prog, function) in the tree at cwd (layout.locate, layout.includers, layout.new_body), or None. src: the
    key's shared path (the self-test stubs this)."""
    loc = layout.locate(ex[0], ex[1], os.getcwd())
    if loc is None:
        return None
    path, first, last, tu = loc
    inc = layout.includers(os.getcwd()).get(path, [])
    units = [f"src/{p}/{t}.c" for p, t in sorted(inc, key=lambda x: x != (ex[0], tu))]
    return path, first, last, units, layout.new_body(*ex)


def uc_due(ex, src):
    """Repair switch unitcut's trigger (3.1 T6): on, src outside src/shared/ and no rolefeed body, the exemplar ex =
    (prog, function) defined in src itself (rf_where; src a unit or a split unit its unit #includes), and src
    holding code other than the exemplar (layout.parse: an INCLUDE_ASM, another definition or an #include entry
    outside the exemplar's lines), which a member fed the whole unit gets linked with (C0425)."""
    rel = os.path.relpath(src)
    if "unitcut" not in REPAIR or rel.startswith("src/shared/") or rf_unit(src):
        return False
    w = rf_where(ex, src)
    if w is not None and w[0] != rel and rf_unit(w[0]):  # cut already (an earlier member): rolefeed() reuses it
        return rf_unit(w[0])[1] == rel
    if w is None or w[0] != rel:
        return False
    with open(src, errors="replace") as f:
        lines = f.read().split("\n")
    return any(not w[1] - 1 <= e.first <= w[2] - 1 for e in layout.parse(lines))


def rolefeed(ex, src, saved, log, preamble=False):
    """Repair switch `rolefeed` (3.1 T4): exemplar ex = (prog, function) moved out of src (a role file or a whole unit)
    into its own body at rf_where's new path (first line the RF_RE marker), its range in src replaced by an #include
    of it; every including unit's object (make -B, before and after) keeps its objdump -dr and section contents, else
    the two files restored, the objects rebuilt, Stop `rolefeed exemplar bytes changed`. Edits recorded in saved (put).
    Returns (new body, note, includer objects); an exemplar already in a rolefeed body (an earlier member): reused.
    preamble (unitcut, 3.1 T6): the body also carries copies of src's lines above its first layout.parse entry and of
    those between the entry above the exemplar and it (a split unit's per-function includes, macros, declarations
    the exemplar compiles under), as src/shared bodies do; src keeps them for its other code."""
    w = rf_where(ex, src)
    if w is None:
        raise Stop(1, f"exemplar {ex[1]} not located")
    path, first, last, units, new = w
    if not units:
        raise Stop(1, f"no including unit of {path}")
    if path == os.path.relpath(new) and rf_unit(new):
        return new, f"reused {new}", []
    if path != os.path.relpath(src):
        raise Stop(1, f"exemplar {ex[1]} in {path}, not {src}")
    if os.path.exists(new):
        raise Stop(1, f"body {new} exists")
    with open(path) as f:
        lines = f.read().split("\n")
    ents = layout.parse(lines) if preamble else []
    prev = max((e.last for e in ents if e.last < first - 1), default=None)  # the entry above the exemplar
    head = ([] if not preamble else lines[:first - 1] if prev is None
            else lines[:min(e.first for e in ents)] + lines[prev + 1:first - 1])
    body = "\n".join([f"// rolefeed (3.1 T4): {ex[1]} of {units[0]}"] + head + lines[first - 1:last]) + "\n"
    text = "\n".join(lines[:first - 1] + [f'#include "{os.path.relpath(new, os.path.dirname(path))}"'] + lines[last:])
    objs = [f"build/{u}.o" for u in units]

    def snap():
        for o in objs:
            if sh(["make", "-s", "-B", o], log):
                raise Stop(1, f"includer {o} does not compile")
        return {o: obj_text(o) for o in objs}

    mine = {}
    try:
        before = snap()
        os.makedirs(os.path.dirname(new) or ".", exist_ok=True)
        put(mine, new, body)
        put(mine, path, text)
        after = snap()
    except Stop:
        restore(mine)
        for o in objs:
            sh(["make", "-s", "-B", o], log)
        raise
    changed = [o for o in objs if before[o] != after[o]]
    if changed:
        restore(mine)
        for o in objs:
            sh(["make", "-s", "-B", o], log)
        raise Stop(1, f"exemplar bytes changed ({' '.join(changed)})")
    with open(os.path.join(LOGDIR, log + ".log"), "a") as f:
        f.write(f"ROLEFEED {path}:{first}-{last} -> {new} units {len(units)}\n")
    for p, b in mine.items():
        saved.setdefault(p, b)
    return new, f"fed {new}", objs


def repoint(lines, key, old, new):
    """Registry lines with each row of key whose shared path is old re-pointed to new (rolefeed, 3.1 T4)."""
    out = []
    for x in lines:
        t = x.split(" ", 5)
        out.append(" ".join(t[:2] + [new] + t[3:]) if not x.startswith("#") and len(t) > 3 and t[0] == key
                   and t[2] == old else x)
    return out


def wrapper(src, func, defines, prog=""):
    """Scratch C file instantiating src as func (R1 under defines); under wrap/<prog>/ (names repeat across programs)."""
    d = os.path.join(LOGDIR, "wrap", prog)
    os.makedirs(d, exist_ok=True)
    p = os.path.join(d, func + ".c")
    with open(p, "w") as f:
        f.write("\n".join(block(src, d, defines)) + "\n")
    return p


# ---- the ladder ----------------------------------------------------------------------------------------------------

def ladder(prog, vram, src, func, tu, saved, log, defines=(), r5=True):
    """Walk R1-R4 (and R5 when r5); raises Stop; returns the R1 sha1."""
    h1 = sha1(src)
    via = rf_unit(src)  # a rolefeed body (3.1 T4): R1 through its including unit
    try:
        if via:
            ok, m, n = probe_via(func, prog, via[0], via[1], makefile_triple(), log)
        else:
            ok, m, n = probe.probe(func, prog, wrapper(src, func, defines, prog) if defines else src,
                                   makefile_triple())
    except SystemExit as e:
        raise Stop(1, f"probe error: {e}")
    if not ok:
        raise Stop(1, f"standalone probe FAIL {m}/{n} words")
    unit_c, unit_o = f"src/{prog}/{tu}.c", f"build/src/{prog}/{tu}.c.o"
    if not os.path.isfile(unit_o) and sh(["make", "-s", unit_o], log):
        raise Stop(2, f"pre-bank {unit_o} does not build")
    pre_ro = rodata_size(unit_o)
    # R2 (a unit already holding the block is re-gated: compiled, not edited); the INCLUDE_ASM line is edited in the
    # file layout finds it in (the unit or a role file), the #include relative to that file
    line, fa, at = layout.asm_line(prog, tu, func), find_asm(prog, func), placed(prog, func, src, tu)
    where = fa[0] if fa else unit_c
    with open(where) as f:
        lines = f.read().split("\n")
    if fa and fa[2] == tu and lines[fa[1] - 1] == line and lines.count(line) == 1 and not at:
        i = fa[1] - 1
        put(saved, where, "\n".join(lines[:i] + block(src, os.path.dirname(where), defines) + lines[i + 1:]))
    elif fa or not at:
        raise Stop(2, f"{lines.count(line)} lines `{line}`, {int(at)} placed blocks in {where}")
    if sh(["make", "-s", "-B", unit_o], log):
        raise Stop(2, f"{unit_o} does not compile (log {LOGDIR}/{log}.log)")
    # R3
    with open(src, errors="replace") as f:
        body = f.read()
    try:
        edits, dl, refused, _ = declsync.sync(prog, src, texts={src: subst(body, defines)})
    except SystemExit as e:  # e.g. a definition DEF_RE cannot read (function-pointer parameter): a stop, not a crash
        raise Stop(3, f"declsync error: {e}")
    with open(os.path.join(LOGDIR, log + ".log"), "a") as f:
        f.write("\n".join(dl) + "\n")
    if refused:
        raise Stop(3, "declaration " + next(l for l in dl if " refused " in l)[len("DECLSYNC "):])
    if os.path.abspath(src) in {os.path.abspath(p) for p in edits}:
        raise Stop(3, f"declsync would edit the body {src}")
    for p, t in sorted(edits.items()):
        put(saved, p, t)
    if sh([sys.executable, "tools/mmx6/typecheck.py", "--files"] + sorted(edits) + [src], log):
        raise Stop(3, f"typecheck.py --files rc != 0 (log {LOGDIR}/{log}.log)")
    units = {p for p in edits if os.path.dirname(p) == f"src/{prog}" and p.endswith(".c")
             and os.path.basename(p)[:-2] in segment.c_units(prog)} | ({unit_c} if edits else set())  # role files: no .o
    for p in sorted(units):
        if sh(["make", "-s", "-B", f"build/{p}.o"], log):
            raise Stop(3, f"edited unit {p} does not recompile")
    xkey_guard(src, edits, saved, log)
    # R4
    lo, hi = vram, int(corpus_row(prog, vram)["end"], 16)
    for a, _ in corpus.jtbl_rows(prog):
        if lo <= a < hi:
            raise Stop(4, f"jtbl not carved (0x{a:08X})")
    post_ro = rodata_size(unit_o)
    if post_ro > pre_ro:
        raise Stop(4, f"rodata needs placement (+{post_ro - pre_ro} bytes)")
    if r5:
        rung5(prog, src, h1, log)
    return h1


def rung5(prog, src, h1, log):
    """R5 over the whole program (once per program when propagating); raises Stop."""
    if rebuild(prog, log):
        raise Stop(5, f"{bin_out(prog)} whole-binary hash red from a clean rebuild (log {LOGDIR}/{log}.log)")
    if sha1(src) != h1:
        raise Stop(5, f"body sha1 changed since R1 ({src})")
    if sh([sys.executable, "tools/mmx6/typecheck.py", "--all"], log):
        raise Stop(5, "typecheck.py --all rc != 0")
    if sh([sys.executable, "tools/mmx6/sig.py", "--rescan"], log):
        raise Stop(5, "sig.py --rescan rc != 0")


def preflight(prog, vram, src, defines=()):
    """(corpus row or None, func, refusal cause or ''); a c row passes only when its unit holds src's block."""
    r = corpus_row(prog, vram) if os.path.isfile("build/corpus/functions.jsonl") else None
    func = r["name"] if r else f"{prog}:0x{vram:08X}"
    regate = r is not None and r["state"] == "c" and os.path.isfile(src) and placed(prog, func, src, r["tu"])
    cause = ("no corpus row" if r is None
             else f"state {r['state']}, not include_asm" if r["state"] != "include_asm" and not regate
             else f"TU {r['tu']} not in config/c_units.txt" if r["tu"] not in segment.c_units(prog)
             else f"no file {src}" if not os.path.isfile(src)
             else f"no `{layout.asm_line(prog, r['tu'], func)}` in {prog}'s units" if not regate
             and find_asm(prog, func) is None else "")
    return r, func, cause


def bank(pv, src, registry=True, defines=()):
    """(rc, verdict line); prints the verdict line."""
    prog, _, v = pv.rpartition(":")
    vram = int(v, 16)
    r, func, cause = preflight(prog, vram, src, defines)
    if cause:
        out = f"RECONCILE {func} refused: {cause}"
        print(out, flush=True)
        return 2, out
    log = f"{prog}.{func}"  # per program: overlays share function names
    if os.path.exists(os.path.join(LOGDIR, log + ".log")):
        os.remove(os.path.join(LOGDIR, log + ".log"))
    saved, x0, via, orig = {}, XKEY[0], "", os.path.relpath(src)
    try:
        try:
            h1 = ladder(prog, vram, src, func, r["tu"], saved, log, defines)
        except Stop as e:  # repair switch declunify: unify the TU's declarations, then the ladder once more
            with open(os.path.join(LOGDIR, log + ".log"), errors="replace") as f:
                tail = f.read()
            rf = ex_of(prog, vram, src) if defines and "rolefeed" in REPAIR else None  # rolefeed (3.1 T4)
            rf = rf if rf and rf_due(prog, vram, src, defines, f"refused R{e.rung}: {e.cause}", tail) else None
            if not (rf or "declunify" in REPAIR and e.rung == 2 and " does not compile " in e.cause):
                raise
            restore(saved)
            sh(["make", "-s", "-B", f"build/src/{prog}/{r['tu']}.c.o"], log)
            if rf:  # the exemplar fed from its own body, then the ladder once more on it
                try:
                    src = rolefeed(rf, src, saved, log)[0]
                except Stop as e2:
                    raise Stop(e.rung, f"{e.cause}; rolefeed {e2.cause}")
                h1, via = ladder(prog, vram, src, func, r["tu"], saved, log, defines), " via rolefeed"
            else:
                with open(os.path.join(LOGDIR, log + ".log"), errors="replace") as f:
                    tail = f.read()
                ex = (prog, func) if not defines else ex_of(prog, vram, src)
                k, note = declunify(f"src/{prog}/{r['tu']}.c", src, defines, tail, saved, log, ex)
                if not k:
                    raise Stop(2, f"{e.cause}; declunify {note}")
                h1 = ladder(prog, vram, src, func, r["tu"], saved, log, defines)
                via = " via declunify"
    except Stop as e:
        restore(saved)
        rc = rebuild(prog, log)
        out = f"RECONCILE {func} stopped R{e.rung}: {e.cause}" + (f" (restore rebuild rc {rc})" if rc else "")
        print(f"RECONCILE {func} xkey {XKEY[0] - x0} accepted", flush=True)
        print(out, flush=True)
        return 1, out
    print(f"RECONCILE {func} xkey {XKEY[0] - x0} accepted", flush=True)
    if via == " via rolefeed" and os.path.isfile(REGISTRY):  # the key's rows on the old path follow the new body
        text = open(REGISTRY).read()
        keys = {x.split()[0] for x in text.split("\n") if not x.startswith("#") and len(x.split()) > 3
                and x.split()[2] == orig and x.split()[3] == f"{prog}:0x{vram:08X}"}
        lines = text.split("\n")
        for k in sorted(keys):
            lines = repoint(lines, k, orig, src)
        with open(REGISTRY, "w") as f:
            f.write("\n".join(lines))
    if registry and not defines and os.path.abspath(src).startswith(os.path.abspath("src/shared") + os.sep):
        cls = dup_key(prog, vram)
        if cls is not None:
            ex = f"{prog}:0x{vram:08X}"
            row = f"{cls['key']} {ex} {os.path.relpath(src)} {ex} gated exemplar"
            text = open(REGISTRY).read() if os.path.exists(REGISTRY) else REGISTRY_HEAD
            lines = text.split("\n")
            stale = [i for i, x in enumerate(lines) if x.split(None, 5)[:4:3] == [cls["key"], ex] and x != row
                     and not x.startswith("#") and x.split(None, 5)[4:5] != ["gated"]]
            if stale:  # a refused/open row of this member (an earlier propagate) becomes its gated row, in place
                lines[stale[0]] = row
                with open(REGISTRY, "w") as f:
                    f.write("\n".join(lines))
            elif row not in lines:
                with open(REGISTRY, "w") as f:
                    f.write(text + ("" if text.endswith("\n") else "\n") + row + "\n")
    out = f"RECONCILE {func} R5 banked; body sha1 {h1} unchanged since R1{via}"
    print(out, flush=True)
    return 0, out


# ---- self-test -----------------------------------------------------------------------------------------------------

def member_block(prog, func):
    """(file, line index, the member's table) of func's define block for the exemplar body, or None; file = a unit
    or a role file (any .c under src/<prog>/)."""
    _, _, ename, etable, esrc = exemplar()
    for unit_c in sorted(glob.glob(f"src/{prog}/**/*.c", recursive=True)):
        with open(unit_c) as f:
            lines = f.read().split("\n")
        for i in range(len(lines) - 1):
            m = re.fullmatch(rf"#define {etable} (\w+)", lines[i + 1])
            if lines[i] == f"#define {ename} {func}" and m:
                blk = block(esrc, os.path.dirname(unit_c), [(ename, func), (etable, m.group(1))])
                if lines[i:i + len(blk)] == blk:
                    return unit_c, i, m.group(1)
    return None


def plant_words(prog, func, vram, end):
    """Retail words of [vram, end): probe.retail_words (trimmed, C0021) plus the untrimmed tail words."""
    n = (end - vram) // 4
    words = probe.retail_words(prog, func)[:n]  # T40.8.1: never past the corpus extent
    if len(words) < n:
        target, seg_start, seg_vram = probe.yaml_layout(prog)
        with open(target, "rb") as f:
            f.seek(seg_start + vram - seg_vram + 4 * len(words))
            words += list(struct.unpack(f"<{n - len(words)}I", f.read(4 * (n - len(words)))))
    return words


def tree_sums(root):
    return {p: sha1(p) for p in sorted(glob.glob(f"{root}/**/*", recursive=True)) if os.path.isfile(p)}


def self_test():
    prog, ev = EXEMPLAR[:2]
    if not probe.plant_lookup("bank", prog, ev):
        return 1
    corpus_out = [f"build/corpus/{n}.jsonl" for n in ("functions", "spans", "denominators")]
    pre_src, pre_reg, pre_bin = tree_sums("src"), sha1(REGISTRY), sha1(bin_out(prog))
    pre_corpus = {p: open(p, "rb").read() for p in corpus_out}
    fails = controls(corpus_out, pre_bin, pre_corpus, role=False)
    fails += controls(corpus_out, pre_bin, pre_corpus, role=True)
    # fail-closed: the tree, the registry and the binary are what they were before the test
    for what, ok in (("src/", tree_sums("src") == pre_src), (REGISTRY, sha1(REGISTRY) == pre_reg),
                     (bin_out(prog), os.path.exists(bin_out(prog)) and sha1(bin_out(prog)) == pre_bin)):
        if not ok:
            print(f"bank: {what} sha1 differs from the pre-test value")
            fails += 1
    if fails:
        print(f"RECONCILE SELF-TEST FAIL {fails}")
        return 1
    print("RECONCILE CONTROL OK")
    return 0


def controls(corpus_out, pre_bin, pre_corpus, role):
    """Failures of controls A, B; role: on a layout.role_tree plant of X's unit (X's block reached through it)."""
    prog, ev, ename, etable, esrc = exemplar()
    saved, fails, stack = {}, 0, contextlib.ExitStack()
    tag = "role-tree " if role else ""
    try:
        cls = dup_key(prog, ev)
        rows = {int(r["vram"], 16): r for r in map(json.loads, open(corpus_out[0])) if r["prog"] == prog}
        sibs = [(v, member_block(prog, rows[v]["name"])) for v in sorted(int(m[1], 16) for m in (cls["members"] if cls else [])
                                                                         if m[0] == prog and int(m[1], 16) != ev)
                if v in rows]
        sibs = [(v, b) for v, b in sibs if b][:2]
        if len(sibs) < 2:
            raise Stop(0, f"{len(sibs)} c-unit siblings of {ename}'s dup class with a define block; need 2")
        if role:  # second pass: X's unit as a thin wrapper over one role file; the blocks found again through it
            pre = sibs[0][1]  # L-B: X's block already lives in a role file; the plant adds one include level above it
            rp = stack.enter_context(layout.role_tree(prog, rows[sibs[0][0]]["tu"], os.getcwd()))
            sibs = [(v, member_block(prog, rows[v]["name"])) for v, _ in sibs]
            if sibs[0][1] != pre or pre[0] not in declsync.unit_files(prog, [rp]):
                raise Stop(0, f"role-tree: X's block {pre} not found again through {rp} ({sibs[0][1]})")
            print(f"bank: role-tree pass on {rows[sibs[0][0]]['tu']} -> {rp}")
        # plant (C0054): each member's define block -> INCLUDE_ASM of a generated .s of its retail words
        for v, (unit_c, i, _) in sorted(sibs, key=lambda s: (s[1][0], -s[1][1])):  # bottom-up within a unit
            func, tu = rows[v]["name"], rows[v]["tu"]
            words = plant_words(prog, func, v, int(rows[v]["end"], 16))
            _, seg_start, seg_vram = probe.yaml_layout(prog)
            off = seg_start + v - seg_vram
            with open(unit_c) as f:
                lines = f.read().split("\n")
            put(saved, unit_c, "\n".join(lines[:i] + [layout.asm_line(prog, tu, func)] + lines[i + 5:]))
            put(saved, f"asm/{prog}/nonmatchings/{tu}/{func}.s",
                ".set noat      /* allow manual use of $at */\n.set noreorder /* don't insert nops after branches */\n\n"
                f"nonmatching {func}, 0x{4 * len(words):X}\n\nglabel {func}\n"
                + "".join(f"    /* {off + 4 * k:X} {v + 4 * k:08X} {struct.pack('<I', w).hex().upper()} */  .word 0x{w:08X}\n"
                          for k, w in enumerate(words)) + f"endlabel {func}\n")  # neighbour row comment (corpus ROW_RE)
        if rebuild(prog, "selftest-plant") or sha1(bin_out(prog)) != pre_bin:
            raise Stop(0, f"plant rebuild of {prog} red (log {LOGDIR}/selftest-plant.log)")
        if sh([sys.executable, "tools/mmx6/corpus.py", "--all"], "selftest-plant"):
            raise Stop(0, "corpus.py --all rc != 0 on the planted tree")
        rows = {int(r["vram"], 16): r for r in map(json.loads, open(corpus_out[0])) if r["prog"] == prog}
        (vx, (ux, _, tx)), (vy, (uy, _, _)) = sibs
        if any(rows[v]["state"] != "include_asm" for v in (vx, vy)):
            raise Stop(0, "planted siblings not include_asm in the regenerated corpus")
        with open(esrc) as f:
            body = f.read()
        x, y = rows[vx]["name"], rows[vy]["name"]
        xk = os.path.join(SELFTEST_DIR, "xkey.c")  # another key's shared body (T2.c3), #included by PLANT_UNIT
        cases = [  # (name, func, vram, table, plant prototype, xkey.c text, expect)
            ("A", x, vx, tx, True, f"void {x}(int);\n", " R5 banked; "),
            ("B", y, vy, etable, False, None, " stopped R5: "),
            ("C", x, vx, tx, False, "void xkey_h();\nvoid xkey_call(void* p, s16* q) {\n"
             f"    int {x}(void*);\n    ((void (*)(void*)){x})(p);\n    if (--*q == 0) {{\n        xkey_h(q);\n"
             "        return;\n    }\n    *q = 3;\n}\n",  # block-scope int prototype: uncast changes registers
             f" stopped R3: declsync would change another key's bytes ({xk})"),
        ]
        snap = sorted({ux, uy}) + [PLANT_UNIT, REGISTRY]
        for name, func, vram, table, plant, xtext, expect in cases:
            orig = {p: (open(p, "rb").read() if os.path.exists(p) else None) for p in snap}
            try:
                os.makedirs(SELFTEST_DIR, exist_ok=True)
                src = os.path.join(SELFTEST_DIR, func + ".c")
                with open(src, "w") as f:
                    f.write(body.replace(ename, func).replace(etable, table))
                h0 = sha1(src)
                if plant:
                    with open(PLANT_UNIT, "a") as f:
                        f.write(f"\nvoid {func}(s32);\n")
                if xtext:
                    with open(xk, "w") as f:
                        f.write(xtext)
                    with open(PLANT_UNIT, "a") as f:
                        f.write(f'#include "{os.path.relpath(xk, os.path.dirname(PLANT_UNIT))}"\n')
                with contextlib.redirect_stdout(io.StringIO()) as cap:
                    rc, out = bank(f"{prog}:0x{vram:08X}", src, registry=False)
                print(cap.getvalue(), end="")
                good = expect in out and (rc == 0) == (name == "A")
                if name == "A":
                    synced = f"void {func}(s8* arg0);" in open(PLANT_UNIT).read()
                    good &= synced and f"body sha1 {h0} unchanged" in out
                    good &= f"void {func}(s8* arg0);" in open(xk).read()
                    good &= f"RECONCILE {func} xkey 1 accepted\n" in cap.getvalue()
                print(f"{tag}control {name} {func} {'ok' if good else 'FAIL'}: want {expect.strip(' :;')}")
                fails += not good
            finally:
                restore(orig)
                shutil.rmtree(SELFTEST_DIR, ignore_errors=True)
                shutil.rmtree(f"build/{SELFTEST_DIR}", ignore_errors=True)
                if rebuild(prog, "selftest-restore"):
                    print(f"control {name}: restore rebuild of {prog} red")
                    fails += 1
    except (Exception, SystemExit) as e:
        print(f"bank: self-test {e}")
        fails += 1
    finally:
        restore(saved)
        try:
            stack.close()  # the role-tree plant's unit restored, its sums checked
        except layout.Refuse as e:
            print(f"bank: {e}")
            fails += 1
        shutil.rmtree(SELFTEST_DIR, ignore_errors=True)
        shutil.rmtree(f"build/{SELFTEST_DIR}", ignore_errors=True)
        for p, b in pre_corpus.items():
            with open(p, "wb") as f:
                f.write(b)
        if rebuild(prog, "selftest-teardown"):
            print(f"bank: teardown rebuild of {prog} red")
            fails += 1
    return fails


def main():
    os.chdir(os.path.join(HERE, "..", ".."))
    ap = argparse.ArgumentParser(description=__doc__.split("\n", 1)[0])
    ap.add_argument("pv", nargs="?", metavar="prog:vram")
    ap.add_argument("--src")
    ap.add_argument("--define", action="append", default=[], metavar="OLD=NEW")
    ap.add_argument("--self-test", action="store_true")
    repair_arg(ap)
    a = ap.parse_args()
    repair_set(a)
    if a.self_test:
        return self_test()
    if not (a.pv and a.src) or any(d.count("=") != 1 for d in a.define):
        ap.error("need <prog:vram> --src <file> [--define OLD=NEW ...], or --self-test")
    return bank(a.pv, a.src, defines=[tuple(d.split("=")) for d in a.define])[0]


if __name__ == "__main__":
    sys.exit(main())
