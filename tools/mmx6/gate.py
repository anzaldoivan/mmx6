"""gate.py -- the wave gate: score every pack directory, bank per binary in isolated snapshots (container, stdlib only).

  gate.py --wave W<n> [--root waves] [--journal campaign/journal.jsonl] [-j 1..3] [--no-propagate]
      -> every pack dir <root>/W<n>/<prog>_<func>/ is scored (its draft.c; verdict.json's status is never read).
         Inputs (ignored/generated; a missing one is `GATE <pv> MISSING <input>`, never a verdict): pack.json, draft.c,
         the build/corpus row, build/census/classes.jsonl, the retail binary (config/<prog>.yaml target), the asm .s
         holding the glabel. Drafts are grouped by program; <= j programs at once (default 3), each in its own snapshot
         waves/.iso/gate-<prog>.<pid>/ (cards.snapshot + all of build/, .clang-format, docs/codegen-map; src/ copied,
         never hardlinked) holding the per-program lock .run/gate/locks/<prog>.lock (busy: `GATE LOCKED <prog>`, rc 1);
         drafts of one program serially. Per draft, cwd = the snapshot: the draft is clang-formatted (repo
         .clang-format, C0063) as src/shared/<prog>/<func>.c; the standalone masked probe (cards.score) compiles it as
         drafts/<prog>/<func>.c (TU flags; `#define <draft name> <func>` first when the draft defines another name);
         verbatim.check; bank.bank on the body copy; on a bank stop R1-R4 the recovery ladder (`define`, `declsync`, `cast`,
         `tudecl`; R2 `tusync` when a first-stop/attempt log names the body's own func (`conflicting types for|
         redefinition of|previous declaration of 'func'`, `'func' redeclared as different kind of symbol`): every other
         file of the TU (unit .c + its #include closure) declaring func gets the definition's spelling (declsync force),
         tried with tudecl's start text then its variants A, B; a failed attempt restores those files byte-exact +
         rebuild; R4 `rodata needs placement (+N bytes)` -> `rodata`: `carve.py rodata <prog> <vram> --bytes N`, re-split
         (the snapshot's asm/<prog> hardlinks broken first) + rebuild, bank; a carve refusal is no bank attempt; a bank
         stop restores the carve-touched files byte-exact, re-split, rebuild; unrecovered, the STOPPED cause adds
         `; rodata CARVE REFUSE <code>|bank stop R<k>`);
         on a probe fail the plateau label (plateau.classify). Lines per draft:
         `GATE <pv> match <m>/<n>|fail <m>/<n>|nocompile|verbatim|MISSING <input>`, then `BANKED <pv> <words>` |
         `RECOVERED <pv> R<k> via <step>` (+ BANKED) | `STOPPED <pv> R<k>: <cause>; error <key>` |
         `REFUSED <pv> <cause>`; each ladder attempt prints `LADDER <pv> <step>` before its bank's RECONCILE line.
         After each program worker: apply-back to the tree under .run/gate/locks/apply.lock (changed src/ files and
         carve-touched config files; new registry rows appended); a tree file changed since the snapshot -> `GATE APPLY CONFLICT <path>`, nothing of that
         program applied, rc 1; the program is re-split and rebuilt in the tree. Then: each banked exemplar's dup class propagated
         (propagate.propagate; `PROPAGATE <key> gated <m> of <M> members`) when it has open members, else
         `PROPAGATE <key> skipped: no open members`; one
         `sig.py --rescan`; one journal record per draft (journal.append; lever = <pack>/<f> when verdict.json's
         `lever` names a file in the pack, else `-`). Last two lines
         `GATE W<n> drafts <d> = banked <a> + failed <b> + no-verdict <c>` (asserted; rc 1 if it breaks) and
         `WAVE W<n> banked <k> (<i> instructions) of <d> drafts; recovered <r>`. Every snapshot is removed (finally;
         stale gate-* of a dead pid at start). rc 0 = the gate completed, 1 = assertion/apply conflict/lock, 2 usage.
  gate.py --self-test
      -> planted controls (C0054) in .run/gate-selftest/ (wave W0); /work restored byte-exact after; last line
         `GATE CONTROL OK` (rc 0), else `GATE CONTROL FAIL <case>` (rc 1). docs/ops/campaign.md ## Gate, ## Recovery.
Firewall G12: names, addresses, counts, labels and our own C only.
"""
import argparse
import contextlib
import fcntl
import glob
import hashlib
import io
import json
import multiprocessing
import os
import re
import shutil
import struct
import subprocess
import sys
import time

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(os.path.dirname(HERE))
sys.path.insert(0, HERE)
import bank  # noqa: E402
import cards  # noqa: E402
import carve  # noqa: E402
import declsync  # noqa: E402
import journal  # noqa: E402
import plateau  # noqa: E402
import probe  # noqa: E402
import propagate  # noqa: E402
import verbatim  # noqa: E402

LOCKS = ".run/gate/locks"
EXTRA = (".clang-format", "docs/codegen-map")  # copied into the snapshot after cards.snapshot (plus all of build/)
SELFTEST = ".run/gate-selftest"
TUDECL_F = ("rock_35", 0x800FE298, "D_800970AA")  # self-test case F: a banked body, `extern s16 <sym>` read signed
# was ("rock_35", 0x800FDD90, "D_800FE9A8") (T48): T36.c1 aliased propagated rock_05 members' D_800F4480 onto D_800FE9A8
# in rock_35's unit, so the planted TU `extern u16` collided with them and the plant rebuild went red
RODATA_I = ("rock_04", 0x800E9B30)  # self-test case I: a body banked via rodata, its carve and bank undone
# was 0x800EA2A8 (T4.c2): later waves carved E9864..E98F4 around its row E9894; undoing a mid-run row splits the unit's
# .rodata (carve refuses non-contiguous; splat then drops jtbl_800E987C of asm func_800E9DFC), so I and M are the
# unit's first and last rodata rows (T21.c2)
RODATA_M = ("rock_04", 0x800ED3A4)  # case M: a second table in I's unit (T44.c1: merged carve, +4 pad), undone as I
STOP_RE = re.compile(r" stopped R(\d): (.*)$")
RODATA_RE = re.compile(r"^rodata needs placement \(\+(\d+) bytes\)")
QUOTED_RE = re.compile(r"[`'‘]([A-Za-z_]\w*)['’]")
CONFLICT_RE = re.compile(r"(too (?:few|many) arguments to function|conflicting types for) [`'‘]([A-Za-z_]\w*)['’]")
TUDECL_RE = re.compile(r"^(\S+?):(\d+):.*?(conflicting types for|redefinition of|previous declaration of) "
                       r"[`'‘]([A-Za-z_]\w*)['’]")
DIAG_RE = re.compile(r"^\S+?:\d+:\s*(.*)$")


def sha1b(b):
    return hashlib.sha1(b).hexdigest()


def file_sha(p):
    return bank.sha1(p) if os.path.isfile(p) else None


def lock(prog):
    """An open fd holding the non-blocking per-program flock, or None when another holder has it."""
    os.makedirs(os.path.join(ROOT, LOCKS), exist_ok=True)
    fd = os.open(os.path.join(ROOT, LOCKS, prog + ".lock"), os.O_RDWR | os.O_CREAT, 0o644)
    try:
        fcntl.flock(fd, fcntl.LOCK_EX | fcntl.LOCK_NB)
    except OSError:
        os.close(fd)
        return None
    return fd


def reap():
    """Remove waves/.iso/gate-* snapshots whose pid is dead."""
    for d in glob.glob(os.path.join(ROOT, cards.ISO, "gate-*")):
        try:
            pid = int(d.rsplit(".", 1)[1])
            os.kill(pid, 0)
            continue
        except (ValueError, IndexError, ProcessLookupError):
            pass
        except PermissionError:
            continue
        shutil.rmtree(d, ignore_errors=True)


def snapshot(prog):
    dst = cards.snapshot(f"gate-{prog}.{os.getpid()}")
    for p in EXTRA + tuple(os.path.join("build", e) for e in sorted(os.listdir("build"))):
        if os.path.exists(p) and not os.path.exists(os.path.join(dst, p)):
            os.makedirs(os.path.dirname(os.path.join(dst, p)), exist_ok=True)
            subprocess.run(["cp", "-a", p, os.path.join(dst, p)], check=True)
    return dst


# ---- inputs (in the tree) ------------------------------------------------------------------------------------------

def inputs(pack, rows):
    """(draft dict, None) or (pv or dir name, missing input)."""
    pj = os.path.join(pack, "pack.json")
    if not os.path.isfile(pj):
        return os.path.basename(pack), "pack.json"
    with open(pj) as f:
        meta = json.load(f)
    pv, prog, func = meta["pv"], meta["prog"], meta["func"]
    if not os.path.isfile(os.path.join(pack, "draft.c")):
        return pv, "draft.c"
    row = rows.get((prog, int(pv.rpartition(":")[2], 16)))
    if row is None:
        return pv, "build/corpus row"
    if not os.path.isfile(cards.CLASSES):
        return pv, cards.CLASSES
    target = probe.yaml_layout(prog)[0] if os.path.isfile(f"config/{prog}.yaml") else f"config/{prog}.yaml"
    if not target or not os.path.isfile(target):
        return pv, target or f"config/{prog}.yaml target"
    if row["state"] in ("asm", "include_asm") and cards.target_asm(prog, row) is None:
        return pv, (f"asm/{prog}/nonmatchings/{row['tu']}/{func}.s" if row["state"] == "include_asm"
                    else f"asm/{prog}/{row['tu']}.s")
    with open(os.path.join(pack, "draft.c"), errors="replace") as f:
        text = f.read()
    return dict(pv=pv, prog=prog, func=func, row=row, text=text, pack=pack), None


# ---- one program in its snapshot -----------------------------------------------------------------------------------

def fmt(text, body):
    r = subprocess.run(["clang-format", "--style=file", f"--assume-filename={body}"], input=text,
                       capture_output=True, text=True)
    if r.returncode:
        raise RuntimeError(f"clang-format rc {r.returncode}")
    return r.stdout


def write(path, text):
    os.makedirs(os.path.dirname(path), exist_ok=True)
    with open(path, "w") as f:
        f.write(text)


def decls(text):
    """{name: (match span, normalised text)} of top-level prototypes and externs."""
    out = {}
    for rx in (cards.PROTO_RE, cards.EXTERN_RE):
        for m in rx.finditer(text):
            out.setdefault(m.group(2), (m.span(), " ".join(m.group(0).split())))
    return out


def declsync_fix(prog, body, cause, func):
    """New body text with declsync's own edit of the body and the named declarations at the program's prevailing
    spelling, or None when nothing changes."""
    with open(body) as f:
        text = f.read()
    new = text
    try:
        edits, _, _, _ = declsync.sync(prog, body, files=[body])
        new = edits.get(body, new)
    except SystemExit:
        pass
    names = set(re.findall(r"\b([A-Za-z_]\w*)\b", cause))
    log = os.path.join(bank.LOGDIR, f"{prog}.{func}.log")
    if os.path.isfile(log):
        with open(log, errors="replace") as f:
            names |= set(QUOTED_RE.findall(f.read()))
    spell = {}
    for p in declsync.unit_files(prog):
        if os.path.abspath(p) == os.path.abspath(body):
            continue
        with open(p, errors="replace") as f:
            for n, (_, s) in decls(f.read()).items():
                spell.setdefault(n, {}).setdefault(s, 0)
                spell[n][s] += 1
    for n, (span, s) in sorted(decls(new).items(), key=lambda x: -x[1][0][0]):  # bottom-up: spans stay valid
        if n in names and n in spell:
            best = sorted(spell[n].items(), key=lambda x: (-x[1], x[0]))[0][0]
            if best != s:
                new = new[:span[0]] + best + new[span[1]:]
    if re.search(r"\bM2C_UNK\b", new) and not re.search(r"^#define M2C_UNK\b", new, re.M):  # the scaffold prelude's
        new = re.sub(r'^(#include "common.h"\n)', r"\1#define M2C_UNK s32\n", new, count=1, flags=re.M)  # spelling
    return new if new != text else None


def cast_fix(prog, body, cause, func):
    """New body text for a call/declaration conflict named in cause (the stop cause + the first-stop bank log's conflict
    lines), or None. `too few|many arguments to function 'X'` / `conflicting types for 'X'` on this body's lines (or in
    the stop cause): every call of X after the draft's own prototype of X made through an unprototyped cast
    `((<draft's return type> (*)())X)(`; the prototype dropped for `conflicting types` only (an arity conflict keeps it,
    the bank's standalone probe needs X declared). `too few|many arguments` on another body's lines: the draft's own
    prototype of X loses its parameter list (`<ret> X();`), its calls unchanged."""
    with open(body) as f:
        text = f.read()
    own, other = set(), set()
    for ln in cause.splitlines():
        for h in CONFLICT_RE.findall(ln):
            (other if ".c:" in ln and f"/{func}.c:" not in ln else own).add(h)
    new = text
    for kind, n in sorted(own):
        mo = next((m for m in cards.PROTO_RE.finditer(new) if m.group(2) == n), None)
        if n == func or mo is None:
            continue
        ret = " ".join(mo.group(1).split())
        head, end = new[:mo.end()], mo.end()
        if kind == "conflicting types for":
            tail = re.match(r"[ \t]*(?:/\*[^\n]*?\*/)?[ \t]*\n", new[end:])  # the prototype's line with its `/* extern */`
            head, end = new[:mo.start()], end + (tail.end() if tail else 0)
        new = head + re.sub(rf"(?<![\w.>]){re.escape(n)}(?=\s*\()", f"(({ret} (*)()){n})", new[end:])
    for kind, n in sorted(other):
        mo = next((m for m in cards.PROTO_RE.finditer(new) if m.group(2) == n), None)
        if kind != "conflicting types for" and n not in {func} | {x for _, x in own} and mo and mo.group(3).strip():
            new = new[:mo.start(3)] + new[mo.end(3):]
    return new if new != text else None


def view(m, n):
    """The view macro body of the body's own declaration match m (cards.PROTO_RE or EXTERN_RE) of n, or None."""
    if m.re is cards.PROTO_RE:
        return f"(({' '.join(m.group(1).split())} (*)({' '.join(m.group(3).split())})){n})"
    d = re.sub(r"^\s*extern\s+", "", m.group(1))
    at = re.search(rf"\b{re.escape(n)}\b", d)
    typ = " ".join(d[:at.start()].split())
    dims = "".join(d[at.end():].split())
    # an array views as an lvalue of the body's array type: `&X`, `X[i]` and decay all work whatever the TU's type (T3.c3)
    return f"(*({typ} (*){dims})&{n})" if "[" in dims else f"(*({typ} *)&{n})"


def tudecl_fix(body, text, log, func, orig=None):
    """[variant A, variant B] body texts (each differing from text) reconciling the body's top-level declarations of
    the symbols named by `conflicting types for|redefinition of|previous declaration of 'X'` in log with the TU's
    prevailing spelling (the diagnostic location not in the body; a prototype, extern or definition header there): A =
    each body declaration -> the TU's spelling,
    `redefinition` -> the body's own definition dropped; B = A plus `#define X <view of the body type>` after the
    declaration and `#undef X` at the body's end, per symbol whose body type differs from the TU's. Both: a symbol
    declared in orig (the body before cast) but not in text (cast dropped its prototype) gets the TU's spelling before
    the body's first definition (the standalone probe needs it declared); a variant using M2C_UNK without defining it
    gets the scaffold prelude's `#define M2C_UNK s32` before its first use (T3.c3)."""
    tu, redef = {}, set()
    me = os.path.abspath(body)
    for ln in log.splitlines():
        mo = TUDECL_RE.match(ln)
        if not mo or mo.group(4) == func:
            continue
        path, line, kind, n = os.path.normpath(mo.group(1)), int(mo.group(2)), mo.group(3), mo.group(4)
        if kind == "redefinition of":
            redef.add(n)
        if os.path.abspath(path) == me or n in tu or not os.path.isfile(path):
            continue
        src = open(path, errors="replace").read()
        off = sum(len(x) + 1 for x in src.split("\n")[:line - 1])
        cand = [(span, s) for rx in (cards.PROTO_RE, cards.EXTERN_RE) for mm in rx.finditer(src) if mm.group(2) == n
                for span, s in [(mm.span(), " ".join(mm.group(0).split()))]]
        cand += [(mm.span(), " ".join(mm.group(0)[:-1].split()) + ";") for mm in declsync.DEF_RE.finditer(src)
                 if mm.group(2) == n]  # a definition's header is the TU's spelling too (T3.c3)
        here = [c for c in cand if c[0][0] <= off + len(src[off:].split("\n", 1)[0]) and c[0][1] >= off]
        if here or cand:
            tu[n] = (here or cand)[0][1]
    own = sorted(((mm.start(), mm.end(), mm) for rx in (cards.PROTO_RE, cards.EXTERN_RE) for mm in rx.finditer(text)
                  if mm.group(2) in tu), key=lambda x: -x[0])
    a, b, seen = text, text, set()
    undef = []
    for s, e, mm in own:  # bottom-up: spans stay valid
        n = mm.group(2)
        if n in seen:
            continue
        seen.add(n)
        mine = " ".join(mm.group(0).split())
        a = a[:s] + tu[n] + a[e:]
        nl = b.find("\n", e)
        nl = len(b) if nl < 0 else nl
        differs = re.sub(r"\b(extern|static)\s+", "", mine) != re.sub(r"\b(extern|static)\s+", "", tu[n])
        macro = f"\n#define {n} {view(mm, n)}" if differs and view(mm, n) else ""
        b = b[:s] + tu[n] + b[e:nl] + macro + b[nl:]
        if macro:
            undef.append(n)
    for n in sorted(redef - {func}):
        for x in ("a", "b"):
            t_ = a if x == "a" else b
            dm = next((m for m in declsync.DEF_RE.finditer(t_) if m.group(2) == n), None)
            if dm:  # a function definition: through its matching brace
                i, depth = dm.end() - 1, 0
                while i < len(t_):
                    depth += {"{": 1, "}": -1}.get(t_[i], 0)
                    i += 1
                    if depth == 0:
                        break
                span = (dm.start(), i)
            else:
                vm = re.search(rf"^(?!extern\b)(?:static\s+)?[A-Za-z_][\w \t\*]*?\b{re.escape(n)}\s*(?:\[[^\]]*\]\s*)*"
                               r"(?:=[^;]*)?;[ \t]*\n?", t_, re.M)
                span = vm.span() if vm else None
            if span:
                t_ = t_[:span[0]] + t_[span[1]:]
            a, b = (t_, b) if x == "a" else (a, t_)
    if undef:
        b = b.rstrip("\n") + "\n" + "".join(f"#undef {n}\n" for n in sorted(undef))
    gone = sorted(n for n in tu if n not in decls(text) and orig is not None and n in decls(orig))
    vs = []
    for v in (a, b):
        dm = declsync.DEF_RE.search(v)
        if gone and dm:
            v = v[:dm.start()] + "".join(tu[n] + "\n" for n in gone) + v[dm.start():]
        um = re.search(r"^.*\bM2C_UNK\b", v, re.M)
        if um and not re.search(r"^#define M2C_UNK\b", v, re.M):
            v = v[:um.start()] + "#define M2C_UNK s32\n" + v[um.start():]
        vs.append(v)
    out = []
    for v in vs:
        if v != text and v not in out:
            out.append(v)
    return out


def tusync_step(pv, prog, func, dname, tu, body, texts, defs, say):
    """(rc, out) of the `tusync` step: per body text (first that banks wins) the other files of the TU declaring func
    (prototype, extern object, call-site cast) get the text's definition spelling (declsync.sync_text force), bank;
    a stop restores those files byte-exact and rebuilds prog."""
    files = [p for p in declsync.unit_files(prog, [f"src/{prog}/{tu}.c"])
             if os.path.abspath(p) != os.path.abspath(body)]
    saved = {p: open(p, "rb").read() for p in files}
    orig = open(body).read()
    rc, out, tried = 1, "", []
    for t in texts:
        t = fmt(t, body)
        sd = [(func, r, ps) for n, r, ps in declsync.definitions(t) if n in (func, dname)][:1]
        if t in tried or not sd:
            continue
        tried.append(t)
        edits = {}
        for p in files:
            src = open(p, errors="replace").read()
            new, _, _ = declsync.sync_text(p, src, sd, force=True)
            if new != src:
                edits[p] = new
        if not edits:
            continue
        for p, x in edits.items():
            write(p, x)
        write(body, t)
        say(f"LADDER {pv} tusync")
        rc, out = bank.bank(pv, body, defines=defs)
        if rc == 0:
            return rc, out
        bank.restore(saved)
        write(body, orig)
        bank.rebuild(prog, f"gate-tusync.{prog}")
    return rc, out


def err_key(log):
    """The first non-warning compiler diagnostic of log, its `file:line:` and quoted names stripped; `-` when none."""
    for ln in log.splitlines():
        mo = DIAG_RE.match(ln)
        if mo and not mo.group(1).startswith("warning:"):
            return " ".join(re.sub(r"[`'‘][^`'’\n]*['’]", "", mo.group(1)).split()).rstrip(":") or "-"
    return "-"


def carve_files(prog):
    """The files `carve.py rodata <prog>` may write (record, .mk, yaml, symbols, the overlay unit's D_ line)."""
    return [f"config/carve.{prog}.txt", f"config/carve.{prog}.mk", f"config/{prog}.yaml",
            f"config/symbols.{prog}.txt"] + sorted(glob.glob(f"src/{prog}/*.c"))


def resplit(prog, log):
    """Re-split and rebuild prog in the snapshot; rc. Its asm/ is hardlinked to the tree (cards.LINK) and splat rewrites
    files in place: the links are broken first (a copy)."""
    a = f"asm/{prog}"
    if os.path.isdir(a) and not os.path.exists(a + ".copied"):
        os.rename(a, a + ".lnk")
        subprocess.run(["cp", "-a", a + ".lnk", a], check=True)
        shutil.rmtree(a + ".lnk")
        open(a + ".copied", "w").close()
    return bank.sh(["make", "-s", f"build/split/{prog}.stamp"], log) or bank.rebuild(prog, log)


def rodata_step(pv, prog, vram, body, defs, n, say):
    """(rc, out, note) of the `rodata` step: carve.py rodata, re-split + rebuild, bank.bank; on a refusal no bank
    attempt; on a red rebuild or a bank stop every carve-touched file is restored byte-exact, re-split and rebuilt.
    note = `CARVE REFUSE <code>` | `rebuild red` | `bank stop R<k>` | `bank refused` (+ `, restore red`)."""
    log = f"gate-rodata.{prog}"
    saved = {p: (open(p, "rb").read() if os.path.isfile(p) else None) for p in carve_files(prog)}
    r = subprocess.run([sys.executable, "tools/mmx6/carve.py", "rodata", prog, f"0x{vram:08X}", "--bytes", str(n)],
                       capture_output=True, text=True)
    for x in (r.stdout + r.stderr).split("\n"):
        if x.startswith("CARVE "):
            say(x)
    saved.update({p: None for p in carve_files(prog) if p not in saved})
    changed = any((open(p, "rb").read() if os.path.isfile(p) else None) != b for p, b in saved.items())
    if r.returncode:
        mo = re.search(r"CARVE REFUSE (\S+)", r.stdout + r.stderr)
        note = f"CARVE REFUSE {mo.group(1)}" if mo else f"carve rc {r.returncode}"
        if changed:
            bank.restore(saved)
            note += ", restore red" if resplit(prog, log) else ""
        return 1, "", note
    if resplit(prog, log):
        rc, out, note = 1, "", "rebuild red"
    else:
        say(f"LADDER {pv} rodata")
        rc, out = bank.bank(pv, body, defines=defs)
        if rc == 0:
            return 0, out, ""
        mo = STOP_RE.search(out)
        note = f"bank stop R{mo.group(1)}" if mo else "bank refused"
    bank.restore(saved)
    if resplit(prog, log):
        note += ", restore red"
    return rc, out, note


def gate_draft(d, t, say):
    """Result dict of one draft (cwd = the snapshot)."""
    pv, prog, func, row = d["pv"], d["prog"], d["func"], d["row"]
    res = dict(pv=pv, verdict=None, score="-", label="-", note="", draft=os.path.join(d["pack"], "draft.c"),
               banked=False, recovered=None)
    body = f"src/shared/{prog}/{func}.c"
    try:
        text = fmt(d["text"], body)
        names = [x[0] for x in declsync.definitions(text)]
        dname = func if func in names or not names else names[-1]
        psrc = f"drafts/{prog}/{func}.c"
        write(psrc, (f"#define {dname} {func}\n" if dname != func else "") + text)
        state, m, n = cards.score(func, prog, psrc, t)
    except (Exception, SystemExit) as e:
        say(f"GATE {pv} nocompile")
        return dict(res, verdict="nocompile", note=f"gate probe error {type(e).__name__}")
    ok, why, _ = verbatim.check(text)
    if not ok:
        say(f"GATE {pv} verbatim")
        return dict(res, verdict="verbatim", note=f"verbatim refused {why}")
    if state == "nocompile":
        say(f"GATE {pv} nocompile")
        return dict(res, verdict="nocompile")
    res["score"] = f"{m}/{n}"
    if state == "fail":
        say(f"GATE {pv} fail {m}/{n}")
        try:
            target = probe.retail_words(prog, func)
            w, diffs, internal, mm = plateau.residual_retail(plateau.compile_o(psrc), func, target, int(row["vram"], 16))
            label = plateau.classify(w, target, diffs, internal, mm)
            plateau.line(func, label, mm, len(target), "draft")  # printed into the worker's lines
        except (Exception, SystemExit):
            label = "-"
        return dict(res, verdict="fail", label=label)
    say(f"GATE {pv} match {m}/{n}")
    if os.path.exists(body):
        with open(body) as f:
            if f.read() != text:
                say(f"REFUSED {pv} a different body exists at {body}")
                return dict(res, verdict="plumbing", label="refused", note="a different body exists at the shared path")
        created = False
    else:
        write(body, text)
        created = True
    rc, out = bank.bank(pv, body)
    first, steps, log0, cast_text, cast_log = None, [], "", None, ""
    log = os.path.join(bank.LOGDIR, f"{prog}.{func}.log")
    if rc == 1:
        mo = STOP_RE.search(out)
        first = (int(mo.group(1)), mo.group(2)) if mo else (0, out)
        k, cause = first
        # the first stop's log of this body: a later step's bank run rewrites the log
        log0 = open(log, errors="replace").read() if os.path.isfile(log) else ""
        defs = [(dname, func)] if dname != func else []
        if k <= 3 and defs:
            steps.append(("define", None, defs))
        if k in (2, 3) and (cause.startswith("declaration ") or "declsync would edit the body" in cause
                            or "does not compile" in cause):
            steps.append(("declsync", cause, defs))
        if k in (2, 3):
            lines = log0.splitlines()
            steps.append(("cast", "\n".join([cause] + [ln for ln in lines if CONFLICT_RE.search(ln)]), defs))
        if k == 2:
            steps.append(("tudecl", None, defs))
            steps.append(("tusync", None, defs))
        if k == 4 and RODATA_RE.match(cause):
            steps.append(("rodata", cause, defs))
    ro_note, alog, tud = "", log0, []  # alog: the first stop's + every attempt's log (tusync's trigger)
    own = re.compile(rf"(?:conflicting types for|redefinition of|previous declaration of) [`'‘]{re.escape(func)}['’]"
                     rf"|[`'‘]{re.escape(func)}['’] redeclared as different kind of symbol")
    for step, cause, defs in steps:
        orig = open(body).read()
        if step == "rodata":  # a carve, not a body edit: its own attempt and restore (rodata_step)
            rc, out, ro_note = rodata_step(pv, prog, int(row["vram"], 16), body, defs,
                                           int(RODATA_RE.match(cause).group(1)), say)
            if rc == 0:
                res["recovered"] = (first[0], step)
                break
            continue
        if step == "tusync":  # a TU edit, not a body edit: tudecl's start text, then its variants A, B
            if not own.search(alog):
                continue
            rc, out = tusync_step(pv, prog, func, dname, row["tu"], body, tud or [cast_text or orig], defs, say)
            if rc == 0:
                res["recovered"] = (first[0], step)
                break
            continue
        if step in ("declsync", "cast"):
            new = (declsync_fix if step == "declsync" else cast_fix)(prog, body, cause, func)
            if new is None:
                continue
            cands = [new]
        elif step == "tudecl":  # from cast's edited body when cast changed it; its attempt log joins the first stop's
            start = cast_text or orig
            cands = [v for v in tudecl_fix(body, start, log0 + "\n" + cast_log, func, orig) if fmt(v, body) != start]
            tud = [start] + cands
        else:
            cands = [None]
        for new in cands:  # tudecl: variant A, then B; the first that banks wins
            if new is not None:
                write(body, fmt(new, body))  # declsync's spelling is whitespace-normalised: re-format (format-check)
            say(f"LADDER {pv} {step}")  # diagnostics: the step of the bank attempt whose RECONCILE line follows
            rc, out = bank.bank(pv, body, defines=defs)
            alog += "\n" + (open(log, errors="replace").read() if os.path.isfile(log) else "")
            if step == "cast":
                cast_text = open(body).read()
                cast_log = open(log, errors="replace").read() if os.path.isfile(log) else ""
            if rc == 0:
                break
            write(body, orig)
        if rc == 0:
            res["recovered"] = (first[0], step)
            break
    if rc == 0:
        if res["recovered"]:
            say(f"RECOVERED {pv} R{res['recovered'][0]} via {res['recovered'][1]}")
        say(f"BANKED {pv} {row['words']}")
        return dict(res, verdict="banked", banked=True, draft=body)
    if created and os.path.exists(body):
        os.remove(body)
    if first is None:
        cause = out.split(" refused: ", 1)[-1]
        say(f"REFUSED {pv} {cause}")
        return dict(res, verdict="plumbing", label="refused", note=f"bank refused {cause}")
    k, cause = first
    if ro_note:
        cause += f"; rodata {ro_note}"
    key = err_key(log0)
    say(f"STOPPED {pv} R{k}: {cause}; error {key}")
    if k == 5:
        return dict(res, verdict="fail", label="hash", note=f"bank stopped R5 {cause}; error {key}")
    return dict(res, verdict="plumbing", label=f"R{k}", note=f"bank stopped R{k} {cause}; error {key}")


def src_sums():
    return {p: bank.sha1(p) for p in sorted(glob.glob("src/**/*", recursive=True)) if os.path.isfile(p)}


def cfg_sums(prog):
    """The carve-touched config files of prog (carve_files), applied back under src/'s conflict rule."""
    return {p: bank.sha1(p) for p in carve_files(prog) if p.startswith("config/") and os.path.isfile(p)}


def worker(prog, drafts, t):
    """One program: lock, snapshot, drafts serially; returns lines, results and the changes to apply."""
    out = dict(prog=prog, lines=[], results=[], changes={}, start={}, reg_rows=[], t0=time.time(), t1=0.0,
               locked=False, error="")
    fd = lock(prog)
    if fd is None:
        out.update(locked=True, t1=time.time())
        return out
    here, snap = os.getcwd(), None
    buf = io.StringIO()
    try:
        snap = snapshot(prog)
        os.chdir(snap)
        start = dict(src_sums(), **cfg_sums(prog))
        reg0 = open(bank.REGISTRY).read().split("\n") if os.path.isfile(bank.REGISTRY) else []
        with contextlib.redirect_stdout(buf):
            for d in drafts:
                out["results"].append(gate_draft(d, t, lambda s: print(s, flush=True)))
        end = dict(src_sums(), **cfg_sums(prog))
        for p in sorted(set(start) | set(end)):
            if start.get(p) != end.get(p):
                out["start"][p] = start.get(p)
                out["changes"][p] = open(p, "rb").read() if p in end else None
        reg1 = open(bank.REGISTRY).read().split("\n") if os.path.isfile(bank.REGISTRY) else []
        out["reg_rows"] = [x for x in reg1 if x and x not in set(reg0)]
    except (Exception, SystemExit) as e:
        out["error"] = f"{type(e).__name__}: {e}"
    finally:
        os.chdir(here)
        if snap:
            shutil.rmtree(snap, ignore_errors=True)
        os.close(fd)
        out["lines"] = [x for x in buf.getvalue().split("\n") if x]
        out["t1"] = time.time()
    return out


def _worker(args):
    return worker(*args)


# ---- the tree side -------------------------------------------------------------------------------------------------

def apply_back(w, say):
    """True when every change of worker w was applied (none when any tree file changed since its snapshot)."""
    os.makedirs(LOCKS, exist_ok=True)
    with open(os.path.join(LOCKS, "apply.lock"), "w") as lf:
        fcntl.flock(lf, fcntl.LOCK_EX)
        bad = [p for p in w["changes"] if file_sha(p) != w["start"][p]]
        for p in bad:
            say(f"GATE APPLY CONFLICT {p}")
        if bad:
            return False
        for p, b in sorted(w["changes"].items()):
            if b is None:
                os.remove(p)
            else:
                os.makedirs(os.path.dirname(p), exist_ok=True)
                with open(p, "wb") as f:
                    f.write(b)
        if w["reg_rows"]:
            text = open(bank.REGISTRY).read() if os.path.isfile(bank.REGISTRY) else bank.REGISTRY_HEAD
            have = set(text.split("\n"))
            add = [x for x in w["reg_rows"] if x not in have]
            if add:
                with open(bank.REGISTRY, "w") as f:
                    f.write(text + ("" if text.endswith("\n") else "\n") + "\n".join(add) + "\n")
    return True


def open_members(key, rows):
    cls = propagate.load_classes().get(key) or []
    gated = {t[3] for _, t in propagate.registry_rows() if t[0] == key and t[4] == "gated"}
    return [m for m in cls if rows.get(m, {}).get("state") in ("asm", "include_asm") and propagate.pv(m) not in gated]


def note_ok(s):
    s = s[:400]
    return s if not (journal.REG_RE.search(s) or journal.ASM_RE.search(s)) else ""


def lever_of(pack):
    """The journal `lever`: <pack>/<f> when verdict.json's `lever` names an existing file in the pack, else `-` (its
    status is never read, G50)."""
    try:
        with open(os.path.join(pack, "verdict.json")) as f:
            f_ = json.load(f).get("lever")
    except (OSError, ValueError, AttributeError):
        return "-"
    if not isinstance(f_, str) or not f_ or os.path.isabs(f_) or ".." in f_.split("/") or any(c.isspace() for c in f_):
        return "-"
    return os.path.join(pack, f_) if os.path.isfile(os.path.join(pack, f_)) else "-"


def run(wave, root, jpath, j, prop, say=print):
    """(rc, info) of one gate run (cwd = the repo root)."""
    reap()
    rows = {(r["prog"], int(r["vram"], 16)): r for r in map(json.loads, open(cards.FUNCS))} \
        if os.path.isfile(cards.FUNCS) else {}
    packs = sorted(p for p in glob.glob(os.path.join(root, wave, "*")) if os.path.isdir(p))
    rc, results, metas, by_prog = 0, {}, {}, {}
    for pack in packs:
        d, miss = inputs(pack, rows)
        if miss:
            say(f"GATE {d} MISSING {miss}")
            results[pack] = dict(pv=d, verdict="missing", score="-", label="-", note=f"missing {miss}",
                                 draft=os.path.join(pack, "draft.c"), banked=False, recovered=None)
            pj = os.path.join(pack, "pack.json")
            metas[pack] = json.load(open(pj)) if os.path.isfile(pj) else None
            continue
        metas[pack] = dict(pv=d["pv"], func=d["func"], words=d["row"]["words"])
        by_prog.setdefault(d["prog"], []).append(d)
    info = dict(intervals={}, results=results)
    t = cards.triple()
    applied, banked_pvs = set(), []
    order = sorted(by_prog, key=lambda p: (-len(by_prog[p]), p))
    if order:
        with multiprocessing.get_context("fork").Pool(min(j, len(order))) as pool:
            for w in pool.imap_unordered(_worker, [(p, by_prog[p], t) for p in order]):
                prog = w["prog"]
                info["intervals"][prog] = (w["t0"], w["t1"])
                for x in w["lines"]:
                    say(x)
                packs_of = [d["pack"] for d in by_prog[prog]]
                if w["locked"] or w["error"]:
                    say(f"GATE LOCKED {prog}" if w["locked"] else f"GATE WORKER {prog} error {w['error']}")
                    rc = 1
                    continue  # its drafts stay no-verdict
                ok = apply_back(w, say)
                for pack, r in zip(packs_of, w["results"]):
                    if r["banked"] and not ok:
                        r = dict(r, verdict="plumbing", banked=False, label="conflict", note="apply-back conflict")
                    results[pack] = r
                if not ok:
                    rc = 1
                    continue
                if w["changes"]:
                    applied.add(prog)
                banked_pvs += [r["pv"] for r in w["results"] if r["banked"]]
    for prog in sorted(applied):  # re-split first: a rodata carve changed the yaml/symbols (a no-op otherwise)
        if bank.sh(["make", "-s", f"build/split/{prog}.stamp"], "gate-apply") or bank.rebuild(prog, "gate-apply"):
            say(f"GATE REBUILD {prog} red (log {bank.LOGDIR}/gate-apply.log)")
            rc = 1
    if banked_pvs and prop:
        rows = {(r["prog"], int(r["vram"], 16)): r for r in map(json.loads, open(cards.FUNCS))}
        keys = sorted({t[0] for _, t in propagate.registry_rows() if t[1] == t[3] and t[1] in banked_pvs})
        for key in keys:
            if not open_members(key, rows):
                say(f"PROPAGATE {key} skipped: no open members")
                continue
            try:
                g, n, _ = propagate.propagate(key, False)
                say(f"PROPAGATE {key} gated {g} of {n} members")
            except SystemExit as e:
                say(f"PROPAGATE {key} refused: {e}")
    if banked_pvs:
        r = subprocess.run([sys.executable, "tools/mmx6/sig.py", "--rescan"], capture_output=True, text=True)
        say((r.stdout.strip().split("\n") or [""])[-1] if r.returncode == 0 else f"GATE RESCAN rc {r.returncode}")
    a = b = c = words = rec = 0
    for pack in packs:
        r, meta = results.get(pack), metas.get(pack)
        if r is None or r["verdict"] == "missing":
            c += 1
        elif r["banked"]:
            a += 1
            words += meta["words"]
            rec += bool(r["recovered"])
        else:
            b += 1
        if r is None or not meta or not meta.get("pv") or not meta.get("words"):
            continue
        record = dict(wave=wave, pv=meta["pv"], func=meta["func"], words=meta["words"], band=journal.band(meta["words"]),
                      runs=1, verdict=r["verdict"], score=r["score"], label=r["label"], draft=r["draft"],
                      lever=lever_of(pack),
                      notes=note_ok(r["note"] or f"gate {r['verdict']}") or f"gate {r['verdict']}")
        if journal.append(jpath, json.dumps(record), say):
            rc = 1
    say(f"GATE {wave} drafts {len(packs)} = banked {a} + failed {b} + no-verdict {c}")
    if a + b + c != len(packs):
        rc = 1
    say(f"WAVE {wave} banked {a} ({words} instructions) of {len(packs)} drafts; recovered {rec}")
    return rc, info


# ---- self-test -----------------------------------------------------------------------------------------------------

def plant_s(saved, prog, tu, func, vram, end):
    words = bank.plant_words(prog, func, vram, end)
    _, seg_start, seg_vram = probe.yaml_layout(prog)
    off = seg_start + vram - seg_vram
    bank.put(saved, f"asm/{prog}/nonmatchings/{tu}/{func}.s",
             ".set noat      /* allow manual use of $at */\n.set noreorder /* don't insert nops after branches */\n\n"
             f"nonmatching {func}, 0x{4 * len(words):X}\n\nglabel {func}\n"
             + "".join(f"    /* {off + 4 * k:X} {vram + 4 * k:08X} {struct.pack('<I', w).hex().upper()} */  .word 0x{w:08X}\n"
                       for k, w in enumerate(words)) + f"endlabel {func}\n")


def plant_unit(saved, unit_c, prog, members, wrap=None):
    """Rewrite unit_c from its original text with each member's define block (line index i) -> INCLUDE_ASM (between
    wrap[func]'s (before, after) lines when given)."""
    if unit_c in saved and saved[unit_c] is not None:
        lines = saved[unit_c].decode().split("\n")
    else:
        lines = open(unit_c).read().split("\n")
    tu = os.path.basename(unit_c)[:-2]
    for i, func in sorted(members, reverse=True):
        pre, post = (wrap or {}).get(func, ([], []))
        lines = lines[:i] + pre + [f'INCLUDE_ASM("asm/{prog}/nonmatchings/{tu}", {func});'] + post + lines[i + 5:]
    bank.put(saved, unit_c, "\n".join(lines))


def self_test():
    exe, ev, ename, etable, esrc = bank.EXEMPLAR
    corpus_out = [f"build/corpus/{n}.jsonl" for n in ("functions", "spans", "denominators")]
    real_j = "campaign/journal.jsonl"
    pre_src = {p: open(p, "rb").read() for p in glob.glob("src/**/*", recursive=True) if os.path.isfile(p)}
    pre_reg = open(bank.REGISTRY, "rb").read()
    pre_corpus = {p: open(p, "rb").read() for p in corpus_out}
    pre_j = open(real_j, "rb").read() if os.path.isfile(real_j) else None
    pre_cfg = {p: open(p, "rb").read() for p in carve_files(RODATA_I[0]) + carve_files(RODATA_M[0]) if p.startswith("config/") and os.path.isfile(p)}
    saved, fails, progs, pre_bin = {}, [], [], {}

    def fail(case):
        print(f"gate: control {case} failed")
        fails.append(case)

    try:
        cls = bank.dup_key(exe, ev)
        rows = {(r["prog"], int(r["vram"], 16)): r for r in map(json.loads, open(corpus_out[0]))}
        cu = {}
        for x in open(cards.C_UNITS):
            t = x.split()
            if len(t) >= 2:
                cu.setdefault(t[0], set()).add(t[1])
        mem = {}
        for m in sorted((m[0], int(m[1], 16)) for m in cls["members"]):
            r = rows.get(m)
            if r is None or m == (exe, ev) or not (m[0] == exe or m[0].startswith("rock_")):
                continue
            blk = bank.member_block(m[0], r["name"])
            if blk and os.path.basename(blk[0])[:-2] in cu.get(m[0], ()):
                mem.setdefault(m[0], []).append((m[1], r, blk))
        ov = next((p for p in sorted(mem) if p.startswith("rock_")), None)
        fp, fv, fsym = TUDECL_F
        if len(mem.get(exe, [])) < 5 or ov is None or not mem.get(fp):
            raise RuntimeError(f"need 5 exe, 1 overlay, 1 {fp} c-unit members of the exemplar class with a define block")
        A, B, C, D, H = mem[exe][:5]
        G = mem[fp][0]
        Y = D  # case H: Y's define block (unplanted before the gate) precedes H's in their unit
        if Y[2][0] != H[2][0] or Y[2][1] > H[2][1]:
            raise RuntimeError("case H needs D's define block before H's in one unit")
        E = mem[ov][0]
        # cases J, K (tusync): overlay members whose unit gets a planted conflicting prototype of their own func (inert:
        # nothing calls it); K's unit also an indented copy of that prototype, which tusync (column-0 declarations only)
        # leaves: its edit makes the TU disagree and the unit stops compiling (typecheck refuses typedef/array plants)
        pool = [(p, m) for p in dict.fromkeys([ov, fp] + sorted(mem)) if p != exe for m in mem.get(p, [])
                if m not in (E, G)]
        J = pool[0] if pool else None
        busy = {E[2][0], G[2][0]} | ({J[1][2][0]} if J else set())
        K = next((x for x in pool if x[1][2][0] not in busy), None)
        if K is None:
            raise RuntimeError("cases J, K need two overlay members of the exemplar class in units apart from E's, G's")
        # case L (tusync, hash): J's plant; its draft reads the table at +1 (a relocated addend: the masked probe
        # matches) -> tusync's edit compiles, the bank attempt stops R5 hash red, restored; K's unit only when no other
        L = next((x for x in pool if x not in (J, K) and x[1][2][0] not in busy | {K[1][2][0]}), None) \
            or next((x for x in pool if x not in (J, K) and x[1][2][0] not in busy), None)
        if L is None:
            raise RuntimeError("case L needs a third overlay member of the exemplar class in a unit apart from E's, G's, J's")
        # case F (tudecl): a banked body whose `extern s16 <sym>` (read signed) meets a planted TU `extern u16 <sym>`
        fr = rows.get((fp, fv))
        fb = f"src/shared/{fp}/{fr['name']}.c" if fr else ""
        finc = f'#include "../shared/{fp}/{fr["name"]}.c"' if fr else ""
        fu = f"src/{fp}/{fr['tu']}.c" if fr else ""
        fincs = [os.path.normpath(os.path.join(os.path.dirname(fu), x))
                 for x in re.findall(r'^#include "(\.\./[^"]+)"', open(fu).read() if fr else "", re.M)]
        if not fr or fr["state"] != "c" or not os.path.isfile(fb) or f"extern s16 {fsym};" not in open(fb).read() \
                or open(fu).read().split("\n").count(finc) != 1 or fsym in open(fu).read() \
                or any(fsym in open(x).read() for x in fincs if x != os.path.normpath(fb) and os.path.isfile(x)):
            raise RuntimeError(f"case F needs {fp}:0x{fv:08X} banked as {fb} with `extern s16 {fsym};`, one include, "
                               f"no other mention of {fsym} in {fu} or its other includes")
        gwrap = {G[1]["name"]: (["#define arg0 1"], ["#undef arg0"])}  # case G: a TU macro eats the body's parameter
        # case I (rodata): a body banked via rodata; its carve undone (carve.uncarve_rodata) and its bank undone
        # case M (rodata, T44): RODATA_M, a second table merged after I's in one unit (+4 pad), undone the same way;
        # I re-gates first (pv order), M's carve then merges again with its pad
        rod = {}
        for case, (ip, iva) in (("I", RODATA_I), ("M", RODATA_M)):
            ir = rows.get((ip, iva))
            ib = f"src/shared/{ip}/{ir['name']}.c" if ir else ""
            iinc = f'#include "../shared/{ip}/{ir["name"]}.c"' if ir else ""
            iu = f"src/{ip}/{ir['tu']}.c" if ir else ""
            if not ir or ir["state"] != "c" or not os.path.isfile(ib) or open(iu).read().split("\n").count(iinc) != 1:
                raise RuntimeError(f"case {case} needs {ip}:0x{iva:08X} banked as {ib}, one include")
            rod[case] = (ip, iva, ir, ib, iinc, iu)
        ip, iva, ir, ib, iinc, iu = rod["I"]
        mp, mva, mr, mb, minc, mu = rod["M"]
        progs = list(dict.fromkeys([exe, ov, fp, ip, mp, J[0], K[0], L[0]]))
        if K[1][2][0] in (fu, iu, mu) or L[1][2][0] in (fu, iu, mu) or J[1][2][0] in (iu, mu):
            raise RuntimeError("case K's or L's unit is F's, I's or M's, or J's is I's or M's")
        pre_bin = {p: bank.sha1(bank.bin_out(p)) for p in progs}
        for p in carve_files(ip) + carve_files(mp):
            saved.setdefault(p, open(p, "rb").read() if os.path.isfile(p) else None)
        carve.use_root(carve.ROOT)
        rtext = {}
        for case, (p, v, r, b, inc, u) in rod.items():
            carve.uncarve_rodata(carve.ROOT, p, v)
            rtext[case] = open(b).read()
            ul = open(u).read().split("\n")
            i = ul.index(inc)
            bank.put(saved, u, "\n".join(ul[:i] + [f'INCLUDE_ASM("asm/{p}/nonmatchings/{r["tu"]}", {r["name"]});']
                                          + ul[i + 1:]))
            saved.setdefault(b, open(b, "rb").read())
            os.remove(b)
        for p in dict.fromkeys([ip, mp]):
            if bank.sh(["make", "-s", f"build/split/{p}.stamp"], "gate-selftest"):
                raise RuntimeError(f"case I/M re-split of {p} red")
        # no plant_s: the uncarved table stays in the rodata piece and names the function's jlabels, which only splat's
        # own .s of the function (written by this re-split) defines
        # plant (C0054): define blocks -> INCLUDE_ASM of generated .s files; proven by the binaries' sha1
        groups = {exe: [A, B, C, D, H], ov: [E]}
        for prog, m in ((fp, G), J, K, L):
            groups.setdefault(prog, []).append(m)
        for prog, ms in groups.items():
            units = {}
            for v, r, (unit_c, i, _) in ms:
                plant_s(saved, prog, r["tu"], r["name"], v, int(r["end"], 16))
                units.setdefault(unit_c, []).append((i, r["name"]))
            for unit_c, lst in units.items():
                plant_unit(saved, unit_c, prog, lst, gwrap)
        ftext = open(fb).read()
        plant_s(saved, fp, fr["tu"], fr["name"], fv, int(fr["end"], 16))
        ul = open(fu).read().split("\n")
        i = ul.index(finc)
        bank.put(saved, fu, "\n".join(ul[:i] + [f"extern u16 {fsym};",
                                                f'INCLUDE_ASM("asm/{fp}/nonmatchings/{fr["tu"]}", {fr["name"]});']
                                       + ul[i + 1:]))
        saved.setdefault(fb, open(fb, "rb").read())
        os.remove(fb)
        edef = next(d for d in declsync.definitions(open(esrc).read()) if d[0] == ename)
        pret = "u8" if declsync.norm(edef[1]) == "s32" else "s32"
        for (prog, (v, r, (unit_c, _, _))), extra in ((J, []), (K, [
                f"    {pret} {K[1][1]['name']}({edef[2]});"]), (L, [])):
            ul = open(unit_c).read().split("\n")
            i = ul.index(f'INCLUDE_ASM("asm/{prog}/nonmatchings/{r["tu"]}", {r["name"]});')
            bank.put(saved, unit_c, "\n".join(ul[:i] + [f"{pret} {r['name']}({edef[2]});"] + extra + ul[i:]))
        ktu = declsync.unit_files(K[0], [K[1][2][0]])
        ltu = declsync.unit_files(L[0], [L[1][2][0]])
        for p in progs:
            if bank.rebuild(p, "gate-selftest") or bank.sha1(bank.bin_out(p)) != pre_bin[p]:
                raise RuntimeError(f"plant rebuild of {p} red")
        if bank.sh([sys.executable, "tools/mmx6/corpus.py", "--all"], "gate-selftest"):
            raise RuntimeError("corpus.py --all rc != 0 on the planted tree")
        rows = {(r["prog"], int(r["vram"], 16)): r for r in map(json.loads, open(corpus_out[0]))}
        if any(rows[(p, m[0])]["state"] != "include_asm" for p, m in ((exe, A), (exe, B), (exe, C), (exe, D), (exe, H),
                                                               (fp, G), (ov, E), (fp, (fv,)), (ip, (iva,)), (mp, (mva,)),
                                                               J, K, L)):
            raise RuntimeError("planted members not include_asm in the regenerated corpus")
        # D: its unit block back, its .s gone; the corpus still names it include_asm -> MISSING asm
        for unit_c in sorted({m[2][0] for m in (A, B, C, D, H)}):
            plant_unit(saved, unit_c, exe, [(m[2][1], m[1]["name"]) for m in (A, B, C, H) if m[2][0] == unit_c])
        os.remove(f"asm/{exe}/nonmatchings/{D[1]['tu']}/{D[1]['name']}.s")
        if bank.rebuild(exe, "gate-selftest") or bank.sha1(bank.bin_out(exe)) != pre_bin[exe]:
            raise RuntimeError(f"D unplant rebuild of {exe} red")
        # packs
        shutil.rmtree(SELFTEST, ignore_errors=True)
        body = open(esrc).read()
        root, jp = os.path.join(SELFTEST, "waves"), os.path.join(SELFTEST, "journal.jsonl")
        cases = {}
        for case, prog, (v, r, (_, _, table)), name, mut in (
                ("A", exe, A, None, None), ("B", exe, B, "_w", None), ("C", exe, C, None, ("arg0[6]", "arg0[7]")),
                ("D", exe, D, None, None), ("E", ov, E, None, None), ("H", exe, H, None, None),
                ("G", fp, G, None, None), ("F", fp, (fv, fr, (None, None, None)), None, None),
                ("I", ip, (iva, ir, (None, None, None)), None, None), ("J", J[0], J[1], None, None),
                ("K", K[0], K[1], None, None), ("L", L[0], L[1], None, (f"{L[1][2][2]}[", f"({L[1][2][2]} + 1)[")),
                ("M", mp, (mva, mr, (None, None, None)), None, None)):
            func = r["name"]
            text = ftext if case == "F" else rtext[case] if case in rtext else \
                body.replace(ename, func + (name or "")).replace(etable, table)
            if case == "H":  # arity conflict: a 2-parameter prototype of Y, defined earlier in the unit with 1 -> cast drops it
                text = text.replace(f"void {func}(", f"void {Y[1]['name']}(s8* arg0, s32 arg1);\n\nvoid {func}(", 1)
            if mut:
                if mut[0] not in text:
                    raise RuntimeError(f"case {case}: no `{mut[0]}` in the body")
                text = text.replace(mut[0], mut[1], 1) if case == "C" else \
                    "\n".join(x.replace(mut[0], mut[1]) if not x.startswith("extern") else x for x in text.split("\n"))
            pack = os.path.join(root, "W0", f"{prog}_{func}")
            os.makedirs(pack)
            pv = f"{prog}:0x{v:08X}"
            with open(os.path.join(pack, "pack.json"), "w") as f:
                json.dump(dict(pv=pv, prog=prog, func=func, tu=r["tu"], words=r["words"]), f)
            write(os.path.join(pack, "draft.c"), text)
            cases[case] = (pv, r["words"])
        # lock: a second non-blocking acquire on a held program is refused
        fd = lock(exe)
        fd2 = lock(exe)
        if fd is None or fd2 is not None:
            fail("lock")
        for x in (fd, fd2):
            if x is not None:
                os.close(x)
        ksum = {p: file_sha(p) for p in ktu}
        lsum = {p: file_sha(p) for p in ltu}
        lines = []
        rc, info = run("W0", root, jp, 3, True, lambda s: (print(s, flush=True), lines.append(s)))
        words = sum(cases[k][1] for k in "ABEFHIJM")
        want = {"A": [f"BANKED {cases['A'][0]} {cases['A'][1]}"],
                "B": [f"RECOVERED {cases['B'][0]} R1 via define", f"BANKED {cases['B'][0]} {cases['B'][1]}"],
                "D": [f"GATE {cases['D'][0]} MISSING asm/{exe}/nonmatchings/{D[1]['tu']}/{D[1]['name']}.s"],
                "E": [f"BANKED {cases['E'][0]} {cases['E'][1]}"],
                "F": [f"RECOVERED {cases['F'][0]} R2 via tudecl", f"BANKED {cases['F'][0]} {cases['F'][1]}"],
                "H": [f"BANKED {cases['H'][0]} {cases['H'][1]}"],
                "I": [f"RECOVERED {cases['I'][0]} R4 via rodata", f"BANKED {cases['I'][0]} {cases['I'][1]}"],
                "J": [f"LADDER {cases['J'][0]} tusync", f"RECOVERED {cases['J'][0]} R2 via tusync",
                      f"BANKED {cases['J'][0]} {cases['J'][1]}"],
                "K": [f"LADDER {cases['K'][0]} tusync"],
                "M": [f"RECOVERED {cases['M'][0]} R4 via rodata", f"BANKED {cases['M'][0]} {cases['M'][1]}"],
                "coverage": ["GATE W0 drafts 13 = banked 8 + failed 4 + no-verdict 1"],
                "wave": [f"WAVE W0 banked 8 ({words} instructions) of 13 drafts; recovered 6"]}
        for case, ls in want.items():
            if any(x not in lines for x in ls):
                fail(case)
        if not any(re.fullmatch(rf"RECOVERED {re.escape(cases['H'][0])} R[23] via cast", x) for x in lines):
            fail("H")
        # J: the tusync edit of its unit carried to the tree (apply-back); K: stopped R2, its TU files byte-exact
        if f"{declsync.norm(edef[1])} {J[1][1]['name']}({edef[2]});" not in open(J[1][2][0]).read().split("\n"):
            fail("J-apply")
        rc_k = {r["pv"]: r for r in journal.records(jp)}.get(cases["K"][0], {}) if os.path.isfile(jp) else {}
        if not any(x.startswith(f"STOPPED {cases['K'][0]} R2: ") for x in lines) or rc_k.get("label") != "R2" \
                or {p: file_sha(p) for p in ktu} != ksum or os.path.exists(f"src/shared/{K[0]}/{K[1][1]['name']}.c"):
            fail("K")
        # L: its tusync attempt compiled and stopped R5 hash red (not a compile stop), then STOPPED R2, TU byte-exact
        lpv, lfn = cases["L"][0], L[1][1]["name"]
        li = lines.index(f"LADDER {lpv} tusync") if f"LADDER {lpv} tusync" in lines else len(lines)
        lr = next((x for x in lines[li:] if x.startswith(f"RECONCILE {lfn} ")), "")
        rc_l = {r["pv"]: r for r in journal.records(jp)}.get(lpv, {}) if os.path.isfile(jp) else {}
        if not re.match(rf"RECONCILE {lfn} stopped R5: .*whole-binary hash red", lr) \
                or not any(x.startswith(f"STOPPED {lpv} R2: ") for x in lines[li:]) or rc_l.get("label") != "R2" \
                or {p: file_sha(p) for p in ltu} != lsum or os.path.exists(f"src/shared/{L[0]}/{lfn}.c"):
            fail("L")
        # the call path of cast_fix on a planted text: an arity conflict on the draft's own call
        write(os.path.join(SELFTEST, "cast.c"), "M2C_UNK func_A();  /* extern */\nvoid f(void) { func_A(); }\n")
        if cast_fix(exe, os.path.join(SELFTEST, "cast.c"), "x/f.c:1: too few arguments to function `func_A'", "f") != \
                "M2C_UNK func_A();  /* extern */\nvoid f(void) { ((M2C_UNK (*)())func_A)(); }\n":
            fail("cast-call")
        # tudecl_fix on planted texts (T3.c3): a definition header as the TU spelling, a cast-dropped prototype
        # re-declared, the M2C_UNK prelude, the array view macro
        tb, to = os.path.join(SELFTEST, "b.c"), os.path.join(SELFTEST, "other.c")
        write(to, "#define M2C_UNK s32\nM2C_UNK func_C(void*);\nextern s8 D_Y;\nvoid func_B(s32 a) {\n}\n")
        tcall = "void f(void) { func_B(1); ((void (*)())func_C)(0); D_Y[1] = 0; }\n"
        tlog = "".join(f"{tb}:{i}: conflicting types for `{n}'\n{to}:{j}: previous declaration of `{n}'\n"
                       for i, j, n in ((1, 4, "func_B"), (2, 2, "func_C"), (2, 3, "D_Y")))
        tv = tudecl_fix(tb, "void func_B(s16 a);\nextern u8 D_Y[];\n" + tcall, tlog, "f",
                        "void func_B(s16 a);\nvoid func_C(s8* p);\nextern u8 D_Y[];\n" + tcall)
        tre = "#define M2C_UNK s32\nM2C_UNK func_C(void*);\n"
        if tv != ["void func_B(s32 a);\nextern s8 D_Y;\n" + tre + tcall,
                  "void func_B(s32 a);\n#define func_B ((void (*)(s16 a))func_B)\nextern s8 D_Y;\n"
                  "#define D_Y (*(u8 (*)[])&D_Y)\n" + tre + tcall + "#undef D_Y\n#undef func_B\n"]:
            fail("tudecl-call")
        recs ={r["pv"]: r for r in journal.records(jp)} if os.path.isfile(jp) else {}
        rc_c = recs.get(cases["C"][0], {})
        if not any(x.startswith(f"GATE {cases['C'][0]} fail ") for x in lines) or rc_c.get("verdict") != "fail" \
                or rc_c.get("label") in (None, "-", "none"):
            fail("C")
        gk = [mo.group(1) for x in lines
              for mo in [re.fullmatch(rf"STOPPED {re.escape(cases['G'][0])} R2: .*; error (.+)", x)] if mo]
        rc_g = recs.get(cases["G"][0], {})
        if len(gk) != 1 or gk[0] == "-" or rc_g.get("verdict") != "plumbing" or rc_g.get("label") != "R2" \
                or not rc_g.get("notes", "").endswith(f"; error {gk[0]}"):
            fail("G")
        if len(recs) != 13 or journal.check(jp, lambda s: None):
            fail("journal")
        iv = info["intervals"]
        s3 = sorted(iv.values())[:3]  # -j 3: the first three programs ran at once
        if len(iv) != len(progs) or max(a for a, _ in s3) >= min(b for _, b in s3):
            fail("overlap")
        if rc != 0:
            fail("rc")
    except (Exception, SystemExit) as e:
        print(f"gate: self-test {type(e).__name__}: {e}")
        fails.append("setup")
    finally:
        bank.restore(saved)
        for p in glob.glob("src/**/*", recursive=True):
            if os.path.isfile(p) and p not in pre_src:
                os.remove(p)
        for p, b in pre_src.items():
            if not os.path.isfile(p) or open(p, "rb").read() != b:
                with open(p, "wb") as f:
                    f.write(b)
        for d in sorted(glob.glob("src/**/", recursive=True), reverse=True):
            if not os.listdir(d):
                os.rmdir(d)
        with open(bank.REGISTRY, "wb") as f:
            f.write(pre_reg)
        for p, b in pre_corpus.items():
            with open(p, "wb") as f:
                f.write(b)
        for p in progs:
            if bank.sh(["make", "-s", f"build/split/{p}.stamp"], "gate-selftest-teardown") \
                    or bank.rebuild(p, "gate-selftest-teardown"):
                fails.append(f"teardown-rebuild-{p}")
        bank.sh([sys.executable, "tools/mmx6/sig.py", "--rescan"], "gate-selftest-teardown")
    # fail-closed: the tree is what it was
    if {p: sha1b(b) for p, b in pre_src.items()} != src_sums():
        fails.append("teardown-src")
    if open(bank.REGISTRY, "rb").read() != pre_reg:
        fails.append("teardown-registry")
    if any((open(p, "rb").read() if os.path.isfile(p) else None) != b for p, b in pre_cfg.items()):
        fails.append("teardown-config")
    if any(open(p, "rb").read() != b for p, b in pre_corpus.items()):
        fails.append("teardown-corpus")
    if (open(real_j, "rb").read() if os.path.isfile(real_j) else None) != pre_j:
        fails.append("teardown-journal")
    if any(not os.path.isfile(bank.bin_out(p)) or bank.sha1(bank.bin_out(p)) != h for p, h in pre_bin.items()):
        fails.append("teardown-binary")
    if glob.glob(os.path.join(cards.ISO, "gate-*")):
        fails.append("teardown-iso")
    if fails:
        print(f"GATE CONTROL FAIL {','.join(fails)}")
        return 1
    print("GATE CONTROL OK")
    return 0


def main():
    os.chdir(ROOT)
    ap = argparse.ArgumentParser(description=__doc__.split("\n", 1)[0])
    ap.add_argument("--wave")
    ap.add_argument("--root", default="waves")
    ap.add_argument("--journal", default="campaign/journal.jsonl")
    ap.add_argument("-j", type=int, default=3, choices=(1, 2, 3))
    ap.add_argument("--no-propagate", action="store_true")
    ap.add_argument("--self-test", action="store_true")
    a = ap.parse_args()
    if a.self_test:
        return self_test()
    if not (a.wave and re.fullmatch(r"W\d+|W-[a-z0-9]+", a.wave)):
        ap.error("need --wave W<n>, or --self-test")
    return run(a.wave, a.root, a.journal, a.j, not a.no_propagate)[0]


if __name__ == "__main__":
    sys.exit(main())
