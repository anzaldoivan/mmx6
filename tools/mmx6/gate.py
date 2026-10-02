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
         verbatim.check; bank.bank on the body copy; on a bank stop R1-R4 the recovery ladder (`define`, `declsync`);
         on a probe fail the plateau label (plateau.classify). Lines per draft:
         `GATE <pv> match <m>/<n>|fail <m>/<n>|nocompile|verbatim|MISSING <input>`, then `BANKED <pv> <words>` |
         `RECOVERED <pv> R<k> via <step>` (+ BANKED) | `STOPPED <pv> R<k>: <cause>` | `REFUSED <pv> <cause>`.
         After each program worker: apply-back to the tree under .run/gate/locks/apply.lock (changed src/ files; new
         registry rows appended); a tree file changed since the snapshot -> `GATE APPLY CONFLICT <path>`, nothing of that
         program applied, rc 1; the program is rebuilt in the tree. Then: each banked exemplar's dup class propagated
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
import declsync  # noqa: E402
import journal  # noqa: E402
import plateau  # noqa: E402
import probe  # noqa: E402
import propagate  # noqa: E402
import verbatim  # noqa: E402

LOCKS = ".run/gate/locks"
EXTRA = (".clang-format", "docs/codegen-map")  # copied into the snapshot after cards.snapshot (plus all of build/)
SELFTEST = ".run/gate-selftest"
STOP_RE = re.compile(r" stopped R(\d): (.*)$")
QUOTED_RE = re.compile(r"[`'‘]([A-Za-z_]\w*)['’]")


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
    return new if new != text else None


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
    first, steps = None, []
    if rc == 1:
        mo = STOP_RE.search(out)
        first = (int(mo.group(1)), mo.group(2)) if mo else (0, out)
        k, cause = first
        defs = [(dname, func)] if dname != func else []
        if k <= 3 and defs:
            steps.append(("define", None, defs))
        if k in (2, 3) and (cause.startswith("declaration ") or "declsync would edit the body" in cause
                            or "does not compile" in cause):
            steps.append(("declsync", cause, defs))
    for step, cause, defs in steps:
        orig = open(body).read()
        if step == "declsync":
            new = declsync_fix(prog, body, cause, func)
            if new is None:
                continue
            write(body, fmt(new, body))  # declsync's spelling is whitespace-normalised: re-format (format-check)
        rc, out = bank.bank(pv, body, defines=defs)
        if rc == 0:
            res["recovered"] = (first[0], step)
            break
        write(body, orig)
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
    say(f"STOPPED {pv} R{k}: {cause}")
    if k == 5:
        return dict(res, verdict="fail", label="hash", note=f"bank stopped R5 {cause}")
    return dict(res, verdict="plumbing", label=f"R{k}", note=f"bank stopped R{k} {cause}")


def src_sums():
    return {p: bank.sha1(p) for p in sorted(glob.glob("src/**/*", recursive=True)) if os.path.isfile(p)}


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
        start = src_sums()
        reg0 = open(bank.REGISTRY).read().split("\n") if os.path.isfile(bank.REGISTRY) else []
        with contextlib.redirect_stdout(buf):
            for d in drafts:
                out["results"].append(gate_draft(d, t, lambda s: print(s, flush=True)))
        end = src_sums()
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
    for prog in sorted(applied):
        if bank.rebuild(prog, "gate-apply"):
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


def plant_unit(saved, unit_c, prog, members):
    """Rewrite unit_c from its original text with each member's define block (line index i) -> INCLUDE_ASM."""
    if unit_c in saved and saved[unit_c] is not None:
        lines = saved[unit_c].decode().split("\n")
    else:
        lines = open(unit_c).read().split("\n")
    tu = os.path.basename(unit_c)[:-2]
    for i, func in sorted(members, reverse=True):
        lines = lines[:i] + [f'INCLUDE_ASM("asm/{prog}/nonmatchings/{tu}", {func});'] + lines[i + 5:]
    bank.put(saved, unit_c, "\n".join(lines))


def self_test():
    exe, ev, ename, etable, esrc = bank.EXEMPLAR
    corpus_out = [f"build/corpus/{n}.jsonl" for n in ("functions", "spans", "denominators")]
    real_j = "campaign/journal.jsonl"
    pre_src = {p: open(p, "rb").read() for p in glob.glob("src/**/*", recursive=True) if os.path.isfile(p)}
    pre_reg = open(bank.REGISTRY, "rb").read()
    pre_corpus = {p: open(p, "rb").read() for p in corpus_out}
    pre_j = open(real_j, "rb").read() if os.path.isfile(real_j) else None
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
        if len(mem.get(exe, [])) < 4 or ov is None:
            raise RuntimeError("need 4 exe and 1 overlay c-unit members of the exemplar class with a define block")
        A, B, C, D = mem[exe][:4]
        E = mem[ov][0]
        progs = [exe, ov]
        pre_bin = {p: bank.sha1(bank.bin_out(p)) for p in progs}
        # plant (C0054): define blocks -> INCLUDE_ASM of generated .s files; proven by the binaries' sha1
        for prog, ms in ((exe, [A, B, C, D]), (ov, [E])):
            units = {}
            for v, r, (unit_c, i, _) in ms:
                plant_s(saved, prog, r["tu"], r["name"], v, int(r["end"], 16))
                units.setdefault(unit_c, []).append((i, r["name"]))
            for unit_c, lst in units.items():
                plant_unit(saved, unit_c, prog, lst)
        for p in progs:
            if bank.rebuild(p, "gate-selftest") or bank.sha1(bank.bin_out(p)) != pre_bin[p]:
                raise RuntimeError(f"plant rebuild of {p} red")
        if bank.sh([sys.executable, "tools/mmx6/corpus.py", "--all"], "gate-selftest"):
            raise RuntimeError("corpus.py --all rc != 0 on the planted tree")
        rows = {(r["prog"], int(r["vram"], 16)): r for r in map(json.loads, open(corpus_out[0]))}
        if any(rows[(p, m[0])]["state"] != "include_asm" for p, m in ((exe, A), (exe, B), (exe, C), (exe, D), (ov, E))):
            raise RuntimeError("planted members not include_asm in the regenerated corpus")
        # D: its unit block back, its .s gone; the corpus still names it include_asm -> MISSING asm
        for unit_c in sorted({m[2][0] for m in (A, B, C, D)}):
            plant_unit(saved, unit_c, exe, [(m[2][1], m[1]["name"]) for m in (A, B, C) if m[2][0] == unit_c])
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
                ("D", exe, D, None, None), ("E", ov, E, None, None)):
            func = r["name"]
            text = body.replace(ename, func + (name or "")).replace(etable, table)
            if mut:
                if mut[0] not in text:
                    raise RuntimeError(f"case C: no `{mut[0]}` in the body")
                text = text.replace(mut[0], mut[1], 1)
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
        lines = []
        rc, info = run("W0", root, jp, 3, True, lambda s: (print(s, flush=True), lines.append(s)))
        words = sum(cases[k][1] for k in "ABE")
        want = {"A": [f"BANKED {cases['A'][0]} {cases['A'][1]}"],
                "B": [f"RECOVERED {cases['B'][0]} R1 via define", f"BANKED {cases['B'][0]} {cases['B'][1]}"],
                "D": [f"GATE {cases['D'][0]} MISSING asm/{exe}/nonmatchings/{D[1]['tu']}/{D[1]['name']}.s"],
                "E": [f"BANKED {cases['E'][0]} {cases['E'][1]}"],
                "coverage": ["GATE W0 drafts 5 = banked 3 + failed 1 + no-verdict 1"],
                "wave": [f"WAVE W0 banked 3 ({words} instructions) of 5 drafts; recovered 1"]}
        for case, ls in want.items():
            if any(x not in lines for x in ls):
                fail(case)
        recs = {r["pv"]: r for r in journal.records(jp)} if os.path.isfile(jp) else {}
        rc_c = recs.get(cases["C"][0], {})
        if not any(x.startswith(f"GATE {cases['C'][0]} fail ") for x in lines) or rc_c.get("verdict") != "fail" \
                or rc_c.get("label") in (None, "-", "none"):
            fail("C")
        if len(recs) != 5 or journal.check(jp, lambda s: None):
            fail("journal")
        iv = info["intervals"]
        if len(iv) != 2 or max(a for a, _ in iv.values()) >= min(b for _, b in iv.values()):
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
            if bank.rebuild(p, "gate-selftest-teardown"):
                fails.append(f"teardown-rebuild-{p}")
        bank.sh([sys.executable, "tools/mmx6/sig.py", "--rescan"], "gate-selftest-teardown")
    # fail-closed: the tree is what it was
    if {p: sha1b(b) for p, b in pre_src.items()} != src_sums():
        fails.append("teardown-src")
    if open(bank.REGISTRY, "rb").read() != pre_reg:
        fails.append("teardown-registry")
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
    if not (a.wave and re.fullmatch(r"W\d+", a.wave)):
        ap.error("need --wave W<n>, or --self-test")
    return run(a.wave, a.root, a.journal, a.j, not a.no_propagate)[0]


if __name__ == "__main__":
    sys.exit(main())
