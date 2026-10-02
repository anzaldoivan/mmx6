#!/usr/bin/env python3
"""harvest.py -- the wave harvest gate (G45): live/inert levers, records, sweeps, widening (container, stdlib only).

  harvest.py --inert <pv> --lever <diff> [--draft <c>] [--wave W<n>]
      -> lever = a unified diff whose + side is the final draft (draft default: draft.c beside the diff). The diff is
         reverse-applied onto a copy (`patch -R` when in the image, else a stdlib hunk applier); both texts compile as
         drafts/<prog>/<func>.c (TU flags, Makefile TRIPLE) in one cards.snapshot (the tree is never written);
         elf_function words + masks compared exactly: equal -> inert, different or reverted nocompile -> live.
         `HARVEST <pv> lever <path> live|inert` rc 0; with-lever nocompile -> `HARVEST <pv> lever <path> nocompile`
         rc 1 (also `noapply`, `MISSING <input>`). --wave appends the inert record to <campaign>/harvest/W<n>.jsonl.
  harvest.py --inert-wave W<n>     every journal record of W<n> with verdict banked and lever != `-` (only banked
                                   levers are credited), one snapshot; last `HARVEST INERT W<n> levers <k> live <l> inert <i>`
  harvest.py --record W<n> <pv> (--cookbook C<nnnn> | --reason TEXT) [--sweep ID]
  harvest.py --sweep <id> --wave W<n>
      -> imports tools/mmx6/sweeps/<id>.py (LABEL, apply(text) -> (text, edits)); targets = the latest journal record
         per pv with label == LABEL and a readable draft, plus <campaign>/ledger.tsv rows with blocker plateau:<LABEL>
         and an existing best draft (the ledger's wins); edited drafts -> packs waves/sweeps/W<n>/<prog>_<func>/
         {pack.json,draft.c} (gate.py --root waves/sweeps --journal campaign/harvest/W<n>.sweeps.jsonl);
         `SWEEP <id> tried <t> edited <e>`; sweep record appended.
  harvest.py --start W<n>  -> <campaign>/harvest/W<n>.start.json {taken, denominators} (INPUTS below)
  harvest.py --widen W<n>  -> `WIDEN <scanner> <old> -> <new>` per key, widen record appended; an input not newer than
                              taken -> `HARVEST WIDEN STALE <input>` rc 1; no start -> `HARVEST WIDEN W<n> MISSING start` rc 1
  harvest.py --gate W<n>   -> (a) every credited lever has an inert record, (b) every live lever a record with a cookbook
                              id resolving in cookbook/INDEX.md (file exists) or a reason, (c) every sweep-tagged record a
                              sweep record with counts, (d) a widen record. All hold: <campaign>/harvest/W<n>.ok (gate
                              line, sha1 of W<n>.jsonl, counts), `HARVEST GATE W<n> OK` rc 0; else one
                              `HARVEST GATE W<n> MISSING <what> [<pv>]` per miss, rc 1, no stamp.
  harvest.py --check-all   -> every distinct wave of the journal has a W<n>.ok whose sha1 matches W<n>.jsonl:
                              `HARVEST GATES OK <w> of <w> waves` rc 0, else `HARVEST GATE W<n> MISSING stamp|STALE` rc 1
  harvest.py --self-test   -> planted controls (C0054) in .run/harvest-selftest/; ends `HARVEST CONTROL OK` |
                              `HARVEST CONTROL FAIL <cases>` rc 1; the tree is left byte-exact.
  --campaign <dir> (default campaign) relocates journal.jsonl, ledger.tsv and harvest/.

W<n>.jsonl (tracked, append; last record per pv/kind wins): {kind:inert,pv,lever,state,why} |
{kind:record,pv,cookbook,reason,sweep} | {kind:sweep,id,label,tried,edited} | {kind:widen,rows:[{scanner,old,new}]}.
Firewall G12: names, addresses, counts, paths, ids and our own prose only. docs/ops/campaign.md ## Harvest.
"""
import argparse
import difflib
import glob
import hashlib
import importlib.util
import json
import os
import re
import shutil
import subprocess
import sys
import time

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.dirname(os.path.dirname(HERE))
sys.path.insert(0, HERE)
import bank  # noqa: E402
import cards  # noqa: E402
import cookbook_check  # noqa: E402
import journal  # noqa: E402
import probe  # noqa: E402

SELFTEST = ".run/harvest-selftest"
SWEEPS = os.path.join(HERE, "sweeps")
INPUTS = dict(progress="build/reports/progress.json", classes="build/census/classes.jsonl",
              draw="build/draw/draw.jsonl", stubs="build/census/stubs.txt")  # stubs optional (the CENSUS stubs line)
WAVE_RE = re.compile(r"W\d+|W-[a-z0-9]+")  # W-<lane>: a lane wave id
CB_RE = re.compile(r"C\d{4}")
HUNK_RE = re.compile(r"^@@ -(\d+)(?:,(\d+))? \+(\d+)(?:,(\d+))? @@")
STUBS_RE = re.compile(r"CENSUS stubs (\d+) of (\d+) asm functions \(ledgered (\d+)\)")


def hdir(camp):
    return os.path.join(camp, "harvest")


def hpath(camp, wave, ext=".jsonl"):
    return os.path.join(hdir(camp), wave + ext)


def hrecords(camp, wave):
    p = hpath(camp, wave)
    return [json.loads(x) for x in open(p, encoding="utf-8") if x.strip()] if os.path.isfile(p) else []


def hadd(camp, wave, rec):
    os.makedirs(hdir(camp), exist_ok=True)
    with open(hpath(camp, wave), "a", encoding="utf-8") as f:
        f.write(json.dumps(rec, separators=(", ", ": ")) + "\n")


def latest(recs, kind, key="pv"):
    return {r[key]: r for r in recs if r.get("kind") == kind}


def file_sha(p):
    with open(p, "rb") as f:
        return hashlib.sha1(f.read()).hexdigest()


def clean(s):
    """s when it is our prose (<= 400 chars, no register operand/.word/glabel, G12), else None."""
    return s if len(s) <= 400 and not (journal.REG_RE.search(s) or journal.ASM_RE.search(s)) else None


def split_pv(pv):
    m = cards.PV_RE.fullmatch(pv or "")
    return (m.group(1), int(m.group(2), 16)) if m else None


def corpus_rows():
    return {(r["prog"], int(r["vram"], 16)): r for r in map(json.loads, open(cards.FUNCS))} \
        if os.path.isfile(cards.FUNCS) else {}


# ---- lever: reverse apply ------------------------------------------------------------------------------------------

def reverse_stdlib(text, diff):
    """text with each hunk's + side replaced by its - side, or None when a hunk does not match."""
    a = text.split("\n")
    hunks, cur = [], None
    for line in diff.split("\n"):
        m = HUNK_RE.match(line)
        if m:
            cur = (int(m.group(3)), [], [])
            hunks.append(cur)
        elif cur is not None and line[:1] in (" ", "-", "+"):
            if line[0] != "+":
                cur[1].append(line[1:])
            if line[0] != "-":
                cur[2].append(line[1:])
        elif line.startswith(("---", "+++", "diff ", "\\")) or not line:
            continue
    if not hunks:
        return None
    off = 0
    for start, old, new in hunks:
        want = max(start - 1 + off, 0) if new else start + off
        cands = sorted(range(len(a) - len(new) + 1), key=lambda i: (abs(i - want), i))
        at = next((i for i in cands if a[i:i + len(new)] == new), None)
        if at is None:
            return None
        a[at:at + len(new)] = old
        off += len(old) - len(new)
    return "\n".join(a)


def reverse(text, diff_path, scratch):
    """The reverted text of a draft (str) and its lever diff, or None when the diff does not reverse-apply."""
    diff = open(diff_path, errors="replace").read()
    if shutil.which("patch"):
        os.makedirs(scratch, exist_ok=True)
        src, out = os.path.join(scratch, "draft.c"), os.path.join(scratch, "reverted.c")
        with open(src, "w") as f:
            f.write(text)
        r = subprocess.run(["patch", "-R", "-s", "--batch", "--no-backup-if-mismatch", "-r", "-", "-o", out, src,
                            os.path.abspath(diff_path)], capture_output=True, text=True)
        got = open(out).read() if r.returncode == 0 and os.path.isfile(out) else None
        shutil.rmtree(scratch, ignore_errors=True)
        return got
    return reverse_stdlib(text, diff)


# ---- lever: compile both sides -------------------------------------------------------------------------------------

def compiled(prog, func, text, t):
    """(words, masks) of func compiled from text as drafts/<prog>/<func>.c (cwd = a snapshot), or None."""
    src = f"drafts/{prog}/{func}.c"
    os.makedirs(os.path.dirname(src), exist_ok=True)
    with open(src, "w") as f:
        f.write(text)
    obj = probe.compile_obj(src, t)
    if obj is None:
        return None
    try:
        words, masks = probe.elf_function(obj, func)
    except SystemExit:
        return None
    return words, masks


def inert_many(items, say):
    """items [(pv, lever, draft)] -> [(pv, lever, state, why)]; state live|inert|nocompile|noapply|missing."""
    rows, out, todo = corpus_rows(), [], []
    for pv, lever, draft in items:
        draft = draft or os.path.join(os.path.dirname(lever), "draft.c")
        key = split_pv(pv)
        miss = ("pv" if key is None else "lever" if not os.path.isfile(lever) else "draft" if not os.path.isfile(draft)
                else cards.FUNCS if key not in rows else None)
        if miss:
            out.append((pv, lever, "missing", f"MISSING {draft if miss == 'draft' else lever if miss == 'lever' else miss}"))
            continue
        text = open(draft, errors="replace").read()
        rev = reverse(text, lever, os.path.join(".run/harvest", str(os.getpid())))
        if rev is None:
            out.append((pv, lever, "noapply", "the lever does not reverse-apply to the draft"))
            continue
        todo.append((pv, lever, key[0], rows[key]["name"], text, rev))
    if todo:
        t = cards.triple()
        snap = cards.snapshot(f"harvest-{os.getpid()}")
        try:
            os.chdir(snap)
            for pv, lever, prog, func, text, rev in todo:
                w = compiled(prog, func, text, t)
                if w is None:
                    out.append((pv, lever, "nocompile", "the draft with the lever does not compile"))
                    continue
                r = compiled(prog, func, rev, t)
                if r is None:
                    out.append((pv, lever, "live", "reverted draft does not compile"))
                elif r == w:
                    out.append((pv, lever, "inert", f"reverted bytes equal ({len(w[0])} words, masks equal)"))
                else:
                    d = next((i for i in range(min(len(w[0]), len(r[0]))) if w[0][i] != r[0][i]), None)
                    out.append((pv, lever, "live", f"reverted words {len(r[0])} vs {len(w[0])}"
                                + (f", first difference at word {d}" if d is not None else ", masks differ")))
        finally:
            os.chdir(ROOT)
            shutil.rmtree(snap, ignore_errors=True)
    order = {(pv, lever): i for i, (pv, lever, _) in enumerate(items)}
    out.sort(key=lambda x: order[(x[0], x[1])])
    for pv, lever, state, why in out:
        say(f"HARVEST {pv} lever {lever} {why if state == 'missing' else state}")
    return out


def inert_cmd(camp, pv, lever, draft, wave, say):
    pv, lever, state, why = inert_many([(pv, lever, draft)], say)[0]
    if state not in ("live", "inert"):
        return 1
    if wave:
        hadd(camp, wave, dict(kind="inert", pv=pv, lever=lever, state=state, why=why))
    return 0


def inert_wave(camp, wave, say):
    credited = {}
    for r in journal.records(os.path.join(camp, "journal.jsonl")):
        if r["wave"] == wave and r["verdict"] == "banked" and r["lever"] != "-":
            credited[r["pv"]] = r["lever"]
    res = inert_many([(pv, lev, None) for pv, lev in sorted(credited.items())], say)
    rc = 0
    for pv, lever, state, why in res:
        if state in ("live", "inert"):
            hadd(camp, wave, dict(kind="inert", pv=pv, lever=lever, state=state, why=why))
        else:
            rc = 1
    n = lambda s: sum(x[2] == s for x in res)  # noqa: E731
    say(f"HARVEST INERT {wave} levers {len(res)} live {n('live')} inert {n('inert')}")
    return rc


# ---- records, sweeps -----------------------------------------------------------------------------------------------

def record_cmd(camp, wave, pv, cookbook, reason, sweep, say):
    if split_pv(pv) is None:
        say(f"HARVEST RECORD REFUSED pv not <prog>:0x<vram>: {pv}")
        return 1
    if cookbook and not CB_RE.fullmatch(cookbook):
        say(f"HARVEST RECORD REFUSED cookbook not C<nnnn>: {cookbook}")
        return 1
    if reason is not None and (not reason.strip() or clean(reason) is None):
        say("HARVEST RECORD REFUSED reason empty, over 400 chars or holding asm text (G12)")
        return 1
    if sweep and not re.fullmatch(r"[A-Za-z0-9_-]+", sweep):
        say(f"HARVEST RECORD REFUSED sweep id {sweep}")
        return 1
    hadd(camp, wave, dict(kind="record", pv=pv, cookbook=cookbook or "-", reason=reason or "-", sweep=sweep or "-"))
    say(f"HARVEST RECORD {wave} {pv} {cookbook or 'reason'}" + (f" sweep {sweep}" if sweep else ""))
    return 0


def ledger_rows(camp):
    p = os.path.join(camp, "ledger.tsv")
    if not os.path.isfile(p):
        return []
    out = []
    for line in open(p, encoding="utf-8"):
        f = line.rstrip("\n").split("\t") if "\t" in line else line.split()
        if len(f) >= 7 and not line.startswith("#"):
            out.append(f)
    return out


def sweep_cmd(camp, sid, wave, say, root="waves/sweeps"):
    if not re.fullmatch(r"[A-Za-z0-9_-]+", sid) or not os.path.isfile(os.path.join(SWEEPS, sid + ".py")):
        say(f"HARVEST SWEEP {sid} MISSING tools/mmx6/sweeps/{sid}.py")
        return 1
    spec = importlib.util.spec_from_file_location(f"sweep_{sid}", os.path.join(SWEEPS, sid + ".py"))
    mod = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(mod)
    targets = {}
    for r in journal.records(os.path.join(camp, "journal.jsonl")):
        targets[r["pv"]] = r
    targets = {pv: r["draft"] for pv, r in targets.items() if r["label"] == mod.LABEL and os.path.isfile(r["draft"])}
    for f in ledger_rows(camp):
        if f[6] == f"plateau:{mod.LABEL}" and f[5] != "m2c" and os.path.isfile(f[5]):
            try:
                targets[f"{f[0]}:0x{int(f[1], 16):08X}"] = f[5]
            except ValueError:
                continue
    rows, tried, edited = corpus_rows(), 0, 0
    for pv, draft in sorted(targets.items()):
        tried += 1
        text = open(draft, errors="replace").read()
        new, edits = mod.apply(text)
        if not edits or new == text:
            continue
        prog, vram = split_pv(pv)
        row = rows.get((prog, vram), {})
        func = row.get("name") or os.path.basename(draft)[:-2]
        pack = os.path.join(root, wave, f"{prog}_{func}")
        os.makedirs(pack, exist_ok=True)
        with open(os.path.join(pack, "pack.json"), "w") as f:
            json.dump(dict(pv=pv, prog=prog, func=func, tu=row.get("tu"), words=row.get("words")), f)
        with open(os.path.join(pack, "draft.c"), "w") as f:
            f.write(new)
        edited += 1
    say(f"SWEEP {sid} tried {tried} edited {edited}")
    hadd(camp, wave, dict(kind="sweep", id=sid, label=mod.LABEL, tried=tried, edited=edited))
    return 0


# ---- widening ------------------------------------------------------------------------------------------------------

def denominators(inp):
    """({scanner key: number}, [inputs read]); raises FileNotFoundError on a missing required input."""
    d, used = {}, []
    with open(inp["progress"]) as f:
        p = json.load(f)
    used.append(inp["progress"])
    for scope, t in [("fleet", p["fleet"])] + sorted(p.get("lanes", {}).items()):
        for k, v in sorted(t.items()):
            if isinstance(v, int) and not isinstance(v, bool):
                d[f"progress.{scope}.{k}"] = v
    with open(inp["classes"]) as f:
        cls = [json.loads(x) for x in f if x.strip()]
    used.append(inp["classes"])
    for kind in sorted({c["kind"] for c in cls}):
        multi = [c for c in cls if c["kind"] == kind and len(c["members"]) > 1]
        d[f"census.{kind}.classes"] = len(multi)
        d[f"census.{kind}.members"] = sum(len(c["members"]) for c in multi)
    if os.path.isfile(inp["stubs"]):
        m = STUBS_RE.search(open(inp["stubs"]).read())
        if m:
            used.append(inp["stubs"])
            d["census.stubs"], d["census.stubs.asm"], d["census.stubs.ledgered"] = map(int, m.groups())
    with open(inp["draw"]) as f:
        rows = [json.loads(x) for x in f if x.strip()]
    used.append(inp["draw"])
    for v in ("draw", "eligible", "refused"):
        d[f"draw.{v}"] = sum(r["verdict"] == v for r in rows)
    for r in rows:
        if r["verdict"] == "refused":
            k = f"draw.refused.{r['layer']}"
            d[k] = d.get(k, 0) + 1
    return dict(sorted(d.items())), used


def start_cmd(camp, wave, say, inp=None):
    inp = inp or INPUTS
    for k in ("progress", "classes", "draw"):
        if not os.path.isfile(inp[k]):
            say(f"HARVEST START {wave} MISSING {inp[k]}")
            return 1
    taken = time.time()
    d, _ = denominators(inp)
    os.makedirs(hdir(camp), exist_ok=True)
    with open(hpath(camp, wave, ".start.json"), "w") as f:
        json.dump(dict(taken=taken, denominators=d), f, indent=1, sort_keys=True)
        f.write("\n")
    say(f"HARVEST START {wave} {len(d)} denominators")
    return 0


def widen_cmd(camp, wave, say, inp=None):
    inp = inp or INPUTS
    sp = hpath(camp, wave, ".start.json")
    if not os.path.isfile(sp):
        say(f"HARVEST WIDEN {wave} MISSING start")
        return 1
    with open(sp) as f:
        st = json.load(f)
    need = ["progress", "classes", "draw"] + (["stubs"] if "census.stubs" in st["denominators"] else [])
    rc = 0
    for k in need:
        if not os.path.isfile(inp[k]):
            say(f"HARVEST WIDEN {wave} MISSING {inp[k]}")
            rc = 1
        elif os.path.getmtime(inp[k]) <= st["taken"]:
            say(f"HARVEST WIDEN STALE {inp[k]}")
            rc = 1
    if rc:
        return 1
    new, _ = denominators(inp)
    old, rows = st["denominators"], []
    for k in sorted(set(old) | set(new)):
        o, n = old.get(k, "-"), new.get(k, "-")
        say(f"WIDEN {k} {o} -> {n}")
        rows.append(dict(scanner=k, old=o, new=n))
    hadd(camp, wave, dict(kind="widen", rows=rows))
    return 0


# ---- the gate ------------------------------------------------------------------------------------------------------

def cookbook_ids(cb="cookbook"):
    ids = set()
    if os.path.isfile(os.path.join(cb, "INDEX.md")):
        for line in open(os.path.join(cb, "INDEX.md"), encoding="utf-8"):
            m = cookbook_check.ROW_RE.match(line)
            if m and not line.startswith("<!--") and os.path.isfile(os.path.join(cb, m.group(1) + ".md")):
                ids.add(m.group(1))
    return ids


def gate_cmd(camp, wave, say):
    credited = {}
    for r in journal.records(os.path.join(camp, "journal.jsonl")):
        if r["wave"] == wave and r["verdict"] == "banked" and r["lever"] != "-":
            credited[r["pv"]] = r["lever"]
    hr = hrecords(camp, wave)
    inert, recs, sweeps = latest(hr, "inert"), latest(hr, "record"), latest(hr, "sweep", "id")
    widen = [r for r in hr if r.get("kind") == "widen"]
    ids, miss = cookbook_ids(), []
    for pv, lev in sorted(credited.items()):
        x = inert.get(pv)
        if x is None or x.get("lever") != lev or x.get("state") not in ("live", "inert"):
            miss.append(f"inert {pv}")
    live = sorted(pv for pv, x in inert.items() if x.get("state") == "live")
    for pv in live:
        r = recs.get(pv)
        if r is None:
            miss.append(f"record {pv}")
        elif r.get("cookbook", "-") != "-":
            if r["cookbook"] not in ids:
                miss.append(f"cookbook {r['cookbook']} {pv}")
        elif not (r.get("reason") or "-").strip() or r.get("reason") == "-":
            miss.append(f"reason {pv}")
    for pv, r in sorted(recs.items()):
        if r.get("sweep", "-") != "-":
            s = sweeps.get(r["sweep"])
            if s is None or not all(isinstance(s.get(k), int) for k in ("tried", "edited")):
                miss.append(f"sweep {r['sweep']} {pv}")
    if not widen:
        miss.append("widen")
    for m in miss:
        say(f"HARVEST GATE {wave} MISSING {m}")
    if miss:
        return 1
    line = f"HARVEST GATE {wave} OK"
    with open(hpath(camp, wave, ".ok"), "w") as f:
        f.write(f"{line}\nsha1 {file_sha(hpath(camp, wave))}\ncredited {len(credited)} live {len(live)} "
                f"inert {sum(x.get('state') == 'inert' for x in inert.values())} records {len(recs)} "
                f"sweeps {len(sweeps)} widen {len(widen)}\n")
    say(line)
    return 0


def check_all(camp, say):
    waves = sorted({r["wave"] for r in journal.records(os.path.join(camp, "journal.jsonl"))}, key=lambda w: (0, int(w[1:]), "") if w[1:].isdigit() else (1, 0, w))
    ok = 0
    for w in waves:
        stamp = hpath(camp, w, ".ok")
        if not os.path.isfile(stamp):
            say(f"HARVEST GATE {w} MISSING stamp")
            continue
        m = re.search(r"^sha1 ([0-9a-f]{40})$", open(stamp).read(), re.M)
        cur = file_sha(hpath(camp, w)) if os.path.isfile(hpath(camp, w)) else None
        if not m or m.group(1) != cur:
            say(f"HARVEST GATE {w} STALE")
            continue
        ok += 1
    if ok != len(waves):
        return 1
    say(f"HARVEST GATES OK {ok} of {len(waves)} waves")
    return 0


# ---- self-test -----------------------------------------------------------------------------------------------------

def tree_sums():
    out = {}
    for d in ("src", "config", "campaign", "cookbook", "drafts"):
        for p in glob.glob(f"{d}/**/*", recursive=True):
            if os.path.isfile(p):
                out[p] = file_sha(p)
    return out


def self_test():
    pre, fails = tree_sums(), []
    st = os.path.abspath(SELFTEST)
    camp = os.path.join(SELFTEST, "campaign")

    def fail(case, why=""):
        print(f"harvest: control {case} failed {why}".rstrip())
        fails.append(case)

    def run(fn, *a, **kw):
        lines = []
        rc = fn(*a, say=lambda s: (print(s, flush=True), lines.append(s)), **kw)
        return rc, lines

    try:
        shutil.rmtree(st, ignore_errors=True)
        os.makedirs(camp)
        exe, ev, ename, _, esrc = bank.EXEMPLAR
        rows = corpus_rows()
        other = next(m for m in sorted((m[0], int(m[1], 16)) for m in bank.dup_key(exe, ev)["members"])
                     if m[0] == exe and m != (exe, ev) and m in rows)
        body = open(esrc).read()
        if "arg0[6]" not in body:
            raise RuntimeError("no `arg0[6]` in the exemplar body")
        packs = {}
        for case, (prog, v), name, final in (
                ("live", (exe, ev), ename, body.replace("arg0[6]", "arg0[7]", 1)),
                ("inert", other, rows[other]["name"], None)):
            text = body.replace(ename, name)
            if final is None:
                ls = text.split("\n")
                i = next(k for k, x in enumerate(ls) if x.startswith("{") or x.rstrip().endswith("{")) + 1
                final = "\n".join(ls[:i] + ["    int harvest_rider; /* inert: an unused local, compiled */"] + ls[i:])
            else:
                final = final.replace(ename, name)
            pack = os.path.join(SELFTEST, "packs", f"{prog}_{name}")
            os.makedirs(pack)
            with open(os.path.join(pack, "draft.c"), "w") as f:
                f.write(final)
            diff = "".join(difflib.unified_diff(text.splitlines(True), final.splitlines(True), "a/draft.c", "b/draft.c"))
            with open(os.path.join(pack, "lever.diff"), "w") as f:
                f.write(diff)
            if reverse_stdlib(final, diff) != text:
                fail(f"stdlib-reverse-{case}")
            packs[case] = (f"{prog}:0x{v:08X}", os.path.join(pack, "lever.diff"), rows[(prog, v)]["words"])
        (pa, la, wa), (pb, lb, wb) = packs["live"], packs["inert"]
        # live / inert, one lever each (W1 gets the live inert-record)
        rc, ls = run(inert_cmd, camp, pa, la, None, "W1")
        if rc or f"HARVEST {pa} lever {la} live" not in ls:
            fail("live")
        rc, ls = run(inert_cmd, camp, pb, lb, None, None)
        if rc or f"HARVEST {pb} lever {lb} inert" not in ls:
            fail("inert")
        jp = os.path.join(camp, "journal.jsonl")

        def jrec(wave, pv, lever, words):
            r = dict(wave=wave, pv=pv, func="f", words=words, band=journal.band(words), runs=1, verdict="banked",
                     score=f"{words}/{words}", label="-", draft=os.path.join(os.path.dirname(lever), "draft.c"),
                     lever=lever, notes="harvest control")
            if journal.append(jp, json.dumps(r), lambda s: None):
                raise RuntimeError(f"journal plant {wave} {pv} refused")

        live_rec = hrecords(camp, "W1")[-1]
        # W1: a live lever with no cookbook entry or reason -> refused, no stamp
        jrec("W1", pa, la, wa)
        rc, ls = run(gate_cmd, camp, "W1")
        if rc != 1 or f"HARVEST GATE W1 MISSING record {pa}" not in ls or os.path.exists(hpath(camp, "W1", ".ok")):
            fail("no-record")
        # W2: a sweep-tagged record without a sweep record -> refused, no stamp
        jrec("W2", pa, la, wa)
        hadd(camp, "W2", live_rec)
        run(record_cmd, camp, "W2", pa, None, "the edit is specific to this function", "S1")
        rc, ls = run(gate_cmd, camp, "W2")
        if rc != 1 or f"HARVEST GATE W2 MISSING sweep S1 {pa}" not in ls or os.path.exists(hpath(camp, "W2", ".ok")):
            fail("no-sweep")
        # W3: complete (inert-wave over both levers, real cookbook id, sweep record, widen on fresh planted inputs)
        jrec("W3", pa, la, wa)
        jrec("W3", pb, lb, wb)
        rc, ls = run(inert_wave, camp, "W3")
        if rc or "HARVEST INERT W3 levers 2 live 1 inert 1" not in ls:
            fail("inert-wave")
        cid = sorted(cookbook_ids())[0]
        if run(record_cmd, camp, "W3", pa, cid, None, "S1")[0]:
            fail("record")
        hadd(camp, "W3", dict(kind="sweep", id="S1", label="planted", tried=1, edited=1))
        inp = {k: os.path.join(SELFTEST, "inputs", os.path.basename(v)) for k, v in INPUTS.items()}
        os.makedirs(os.path.dirname(inp["progress"]))

        def plant(n):
            with open(inp["progress"], "w") as f:
                json.dump(dict(fleet=dict(n=10, mf=n), lanes=dict(game=dict(n=8, mf=n))), f)
            with open(inp["classes"], "w") as f:
                f.write(json.dumps(dict(kind="dup", key="k", size=4, members=[["P", "0x1"], ["P", "0x2"]])) + "\n")
            with open(inp["draw"], "w") as f:
                f.write(json.dumps(dict(prog="P", vram="0x1", verdict="refused", layer="L2", reason="r")) + "\n")
                f.write(json.dumps(dict(prog="P", vram="0x2", verdict="draw", layer=None, reason=None)) + "\n")

        plant(3)
        if run(start_cmd, camp, "W3", inp=inp)[0]:
            fail("start")
        rc, ls = run(widen_cmd, camp, "W3", inp=inp)
        if rc != 1 or f"HARVEST WIDEN STALE {inp['progress']}" not in ls:
            fail("widen-stale")
        taken = json.load(open(hpath(camp, "W3", ".start.json")))["taken"]
        plant(5)
        for p in (inp["progress"], inp["classes"], inp["draw"]):
            os.utime(p, (taken + 5, taken + 5))
        rc, ls = run(widen_cmd, camp, "W3", inp=inp)
        if rc or "WIDEN progress.fleet.mf 3 -> 5" not in ls:
            fail("widen")
        rc, ls = run(gate_cmd, camp, "W3")
        if rc or ls != ["HARVEST GATE W3 OK"] or not os.path.isfile(hpath(camp, "W3", ".ok")):
            fail("complete")
        # check-all over the planted dir: W1, W2 unstamped; a clean copy of W3 alone passes; a later append is stale
        rc, ls = run(check_all, camp)
        if rc != 1 or ls != ["HARVEST GATE W1 MISSING stamp", "HARVEST GATE W2 MISSING stamp"]:
            fail("check-all-missing")
        camp2 = os.path.join(SELFTEST, "campaign2")
        os.makedirs(hdir(camp2))
        for x in open(jp):  # re-appended: the prev chain is rebuilt
            if json.loads(x)["wave"] == "W3":
                journal.append(os.path.join(camp2, "journal.jsonl"), x, lambda s: None)
        for ext in (".jsonl", ".ok"):
            shutil.copy(hpath(camp, "W3", ext), hpath(camp2, "W3", ext))
        rc, ls = run(check_all, camp2)
        if rc or ls != ["HARVEST GATES OK 1 of 1 waves"]:
            fail("check-all-ok")
        hadd(camp2, "W3", dict(kind="widen", rows=[]))
        rc, ls = run(check_all, camp2)
        if rc != 1 or ls != ["HARVEST GATE W3 STALE"]:
            fail("check-all-stale")
    except (Exception, SystemExit) as e:
        os.chdir(ROOT)
        print(f"harvest: self-test {type(e).__name__}: {e}")
        fails.append("setup")
    if tree_sums() != pre:
        fails.append("teardown-tree")
    if glob.glob(os.path.join(cards.ISO, "harvest-*")):
        fails.append("teardown-iso")
    if fails:
        print(f"HARVEST CONTROL FAIL {','.join(fails)}")
        return 1
    print("HARVEST CONTROL OK")
    return 0


def main():
    os.chdir(ROOT)
    ap = argparse.ArgumentParser(description=__doc__.split("\n", 1)[0])
    g = ap.add_mutually_exclusive_group()
    g.add_argument("--inert", metavar="PV")
    g.add_argument("--inert-wave", metavar="W")
    g.add_argument("--record", nargs=2, metavar=("W", "PV"))
    g.add_argument("--start", metavar="W")
    g.add_argument("--widen", metavar="W")
    g.add_argument("--gate", metavar="W")
    g.add_argument("--check-all", action="store_true")
    g.add_argument("--self-test", action="store_true")
    ap.add_argument("--sweep", metavar="ID", help="sweep mode with --wave, or the sweep tag of --record")
    ap.add_argument("--lever")
    ap.add_argument("--draft")
    ap.add_argument("--wave")
    ap.add_argument("--cookbook")
    ap.add_argument("--reason")
    ap.add_argument("--campaign", default="campaign")
    a = ap.parse_args()
    for w in (a.inert_wave, a.start, a.widen, a.gate, a.wave, a.record and a.record[0]):
        if w and not WAVE_RE.fullmatch(w):
            ap.error(f"not W<n>: {w}")
    c = a.campaign
    if a.self_test:
        return self_test()
    if a.inert:
        if not a.lever:
            ap.error("--inert needs --lever <diff>")
        return inert_cmd(c, a.inert, a.lever, a.draft, a.wave, print)
    if a.inert_wave:
        return inert_wave(c, a.inert_wave, print)
    if a.record:
        if bool(a.cookbook) == (a.reason is not None):
            ap.error("--record needs exactly one of --cookbook C<nnnn> | --reason TEXT")
        return record_cmd(c, a.record[0], a.record[1], a.cookbook, a.reason, a.sweep, print)
    if a.start:
        return start_cmd(c, a.start, print)
    if a.widen:
        return widen_cmd(c, a.widen, print)
    if a.gate:
        return gate_cmd(c, a.gate, print)
    if a.check_all:
        return check_all(c, print)
    if a.sweep:
        if not a.wave:
            ap.error("--sweep <id> needs --wave W<n>")
        return sweep_cmd(c, a.sweep, a.wave, print)
    ap.error("need a mode (see --help)")


if __name__ == "__main__":
    sys.exit(main())
