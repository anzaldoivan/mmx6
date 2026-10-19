#!/usr/bin/env python3
"""propagate.py -- instantiate a shared body at every member of its dup class, byte-gate each (container, stdlib).

  propagate.py <dup key> [--dry-run]
      -> the key's exemplar row of config/dedup_registry.txt names the shared body; members from
         build/census/classes.jsonl. Per member (prog, vram order): defines `<exemplar name> -> <member corpus name>`
         and `D_<exemplar table> -> D_<member table>` (table address = the lui/lw (or addiu) pair of the member's
         retail words, probe.retail_words; the exemplar needs none; only when the body names D_<exemplar table>,
         else the name define alone; an identity table define is dropped when the unit's own `#define` lines directly
         above the member's INCLUDE_ASM alias that name), then bank.ladder R1-R4 (R1 probes a scratch
         wrapper, R2 writes the define/include/undef block; a unit already holding it is re-gated, not re-edited).
         R5 (bank.rung5: clean rebuild + hash, body sha1, typecheck, sig) once per program, then an unmasked compare of
         each member's linked extent vs retail; on a program R5 failure every member is retried alone, failing
         members restored. One line per member `<prog:vram> gated|refused <reason>`, last
         `PROPAGATE <key> gated <m> of <M> members` (rc 0 iff m = M); registry rows appended/updated in place.
         A member already holding a gated row of the key (its own bank, an earlier run) is not re-gated: row kept, counted.
      --dry-run: the same gates in scratch copies of the tree (.run/propagate/tree/w<i>, one per worker process;
         programs run in parallel, output printed in program order); src/ and the registry are never
         written (their sha1 checked unchanged at the end); last `PROPAGATE DRY-RUN <key> gated <m> of <M> members`.
      --dry-run --expect-registry: the same dry run, rc 0 iff every member's verdict agrees with its registry row of the
         key (gated row -> gated, refused row -> refused, any reason; no row -> must gate, as plain --dry-run); each
         disagreement `PROPAGATE DRIFT <key> <prog:vram> <registry status> -> <dry-run verdict>` (rc 1). Members with a
         gated row are skipped (counted gated) as in every run; the exemplar is re-gated (a c/c-empty exemplar's
         preflight refusal agrees with its `gated exemplar` row).
  propagate.py --check
      -> per registry row the member's dup key recomputed from the built object (census.read_words + dup_key); refusal
         lines `REGISTRY refused drift|not in class|missing member ...` (rc 1) or `REGISTRY OK <r> rows` (rc 0).
         A row whose reason starts `family` (tools/mmx6/family_remap.py) is checked on census.family_key instead:
         drift vs its row key, not in that family class; exempt from the missing-member rule.
  propagate.py --self-test
      -> scratch registry/classes copies (.run/propagate/selftest/): every class member rowed -> OK; a row whose built
         key differs from its row key (drift), one member row dropped (missing member), a row for a function outside
         the class (not in class) -> each refused; --expect-registry on planted rows/verdicts: a refused row refused ->
         agrees, a gated row refused -> DRIFT, a c-empty exemplar refused -> agrees; a planted unit alias above a member's
         INCLUDE_ASM -> the identity define dropped. Ends `PROPAGATE CONTROL OK` (rc 0), else rc 1.
Firewall G12: names, addresses, counts and hashes of our own files only.
"""
import argparse
import hashlib
import json
import multiprocessing
import os
import shutil
import sys
import time

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import bank  # noqa: E402
import census  # noqa: E402
import probe  # noqa: E402

CLASSES = "build/census/classes.jsonl"
FUNCS = "build/corpus/functions.jsonl"
SCRATCH = ".run/propagate"
TREE = SCRATCH + "/tree"  # the dry run's worker trees TREE/w<i>
WORKERS = os.cpu_count() or 1
COPY = ("Makefile", "mk", "include", "config", "src", "tools", "asm", "build")  # the dry run's scratch tree
LINK = ("extracted",)  # read-only inputs
LOAD_OPS = (0x23, 0x09)  # lw, addiu: the %lo half of the table address
_KEYS = {}  # (prog, vram) -> built dup key (or None), shared by --check calls
_FAMS = {}  # (prog, vram) -> built family key (or None), filled with _KEYS


def pv(m):
    return f"{m[0]}:0x{m[1]:08X}"


def parse_pv(s):
    p, _, v = s.rpartition(":")
    return p, int(v, 16)


def load_classes(path=CLASSES, kind="dup"):
    """{<kind> key: [(prog, vram)]}."""
    out = {}
    with open(path) as f:
        for line in f:
            c = json.loads(line)
            if c["kind"] == kind:
                out[c["key"]] = sorted((p, int(v, 16)) for p, v in c["members"])
    return out


def corpus_rows():
    with open(FUNCS) as f:
        return {(r["prog"], int(r["vram"], 16)): r for r in map(json.loads, f)}


def registry_rows(path=bank.REGISTRY):
    """[(line index, [key, exemplar, shared path, member, state, reason])] of the registry's data lines."""
    out = []
    if os.path.exists(path):
        with open(path) as f:
            for i, line in enumerate(f.read().split("\n")):
                t = line.split(None, 5)
                if line.strip() and not line.startswith("#") and len(t) >= 5:
                    out.append((i, t + [""] * (6 - len(t))))
    return out


def table_addr(words):
    """Address of the first lui + following lw/addiu pair in words, or None."""
    hi = None
    for w in words:
        if hi is None and w >> 26 == 0x0F:
            hi = (w & 0xFFFF) << 16
        elif hi is not None and w >> 26 in LOAD_OPS:
            lo = w & 0xFFFF
            return (hi + (lo - 0x10000 if lo & 0x8000 else lo)) & 0xFFFFFFFF
    return None


def extent_same(prog, row):
    """Linked bytes of the member's extent == retail bytes (unmasked)."""
    target, seg_start, seg_vram = probe.yaml_layout(prog)
    vram = int(row["vram"], 16)
    off, n = seg_start + vram - seg_vram, int(row["end"], 16) - vram
    with open(target, "rb") as f:
        f.seek(off)
        want = f.read(n)
    with open(bank.bin_out(prog), "rb") as f:
        f.seek(off)
        got = f.read(n)
    return len(want) == n and got == want


def unit_aliases(prog, tu, func, name, root="src"):
    """True when the `#define` lines directly above func's INCLUDE_ASM line in <root>/<prog>/<tu>.c define name (T40.c1)."""
    try:
        with open(f"{root}/{prog}/{tu}.c") as f:
            lines = f.read().split("\n")
    except OSError:
        return False
    at = f'INCLUDE_ASM("asm/{prog}/nonmatchings/{tu}", {func});'
    for i, line in enumerate(lines):
        if line == at:
            j = i - 1
            while j >= 0 and lines[j].startswith("#define "):
                if lines[j].split()[1] == name:
                    return True
                j -= 1
    return False


def tree_sha(paths):
    h = hashlib.sha1()
    for top in paths:
        for d, dirs, files in sorted(os.walk(top)) if os.path.isdir(top) else [("", [], [top])]:
            dirs.sort()
            for name in sorted(files):
                p = os.path.join(d, name)
                h.update(p.encode() + b"\0")
                with open(p, "rb") as f:
                    h.update(f.read())
    return h.hexdigest()


# ---- propagate -----------------------------------------------------------------------------------------------------

def gate(prog, vram, src, defines, log):
    """(member record or None, reason); R1-R4 of one member, its edits kept on success, restored on a stop."""
    r, func, cause = bank.preflight(prog, vram, src, defines)
    if cause:
        return None, f"refused preflight: {cause}"
    saved = {}
    try:
        h1 = bank.ladder(prog, vram, src, func, r["tu"], saved, log, defines, r5=False)
    except (bank.Stop, SystemExit) as e:
        rung, why = (e.rung, e.cause) if isinstance(e, bank.Stop) else (1, f"probe error: {e}")
        bank.restore(saved)
        bank.sh(["make", "-s", "-B", f"build/src/{prog}/{r['tu']}.c.o"], log)  # the next member's pre-bank object
        return None, f"refused R{rung}: {why}"
    return dict(prog=prog, vram=vram, row=r, defines=defines, saved=saved, h1=h1), ""


def program_r5(prog, src, gated, log):
    """Raise bank.Stop unless the program is green from a clean rebuild and every gated extent equals retail."""
    bank.rung5(prog, src, gated[0]["h1"], log)
    bad = [pv((g["prog"], g["vram"])) for g in gated if not extent_same(prog, g["row"])]
    if bad:
        raise bank.Stop(5, f"linked extent differs from retail ({' '.join(bad)})")


def propagate(key, dry):
    """(gated count, member count, [(member pv, state, reason)])."""
    reg = registry_rows()
    ex_rows = [t for _, t in reg if t[0] == key and t[1] == t[3]]
    cls = load_classes().get(key)
    if not ex_rows or cls is None:
        sys.exit(f"propagate: {'no exemplar row in ' + bank.REGISTRY if not ex_rows else 'no dup class'} for {key}")
    ex, src = parse_pv(ex_rows[0][1]), ex_rows[0][2]
    rows = corpus_rows()
    ex_name = rows[ex]["name"]
    ex_tab = table_addr(probe.retail_words(ex[0], ex_name))
    with open(src) as f:
        body = f.read()
    if ex_name not in body:
        sys.exit(f"propagate: exemplar name {ex_name} not in {src} (contract)")
    if ex_tab is not None and f"D_{ex_tab:08X}" not in body:
        ex_tab = None  # no table in the body (the lui/lw pair is some other global): the name define only
    done = {t[3] for _, t in reg if t[0] == key and t[4] == "gated"}  # own banks / earlier runs: rows kept as they are
    skip = [m for m in cls if m != ex and pv(m) in done]
    by_prog = {}
    for m in cls:
        if m not in skip:
            by_prog.setdefault(m[0], []).append(m)
    ctx = (ex, ex_name, ex_tab, src, rows)
    results = []
    if not dry:
        for prog in sorted(by_prog):
            results += run_prog(prog, by_prog[prog], ctx, lambda s: print(s, flush=True))
    else:  # one scratch tree per worker; programs in parallel, output in program order
        n = min(WORKERS, len(by_prog))
        trees = [f"{TREE}/w{i}" for i in range(n)]
        for t in trees:
            make_tree(t)
        mp = multiprocessing.get_context("fork")
        q = mp.Queue()
        for t in trees:
            q.put(t)
        order = sorted(by_prog, key=lambda p: (-len(by_prog[p]), p))  # longest first
        with mp.Pool(n, initializer=_worker_init, initargs=(q,)) as pool:
            jobs = {p: pool.apply_async(_worker_prog, (p, by_prog[p], ctx)) for p in order}
            for prog in sorted(by_prog):
                res, lines = jobs[prog].get()
                print("\n".join(lines), flush=True)
                results += res
    if not dry:
        write_registry(key, pv(ex), src, results)
    return sum(s == "gated" for _, s, _ in results) + len(skip), len(cls), results


def run_prog(prog, ms, ctx, out):
    """[(member pv, state, reason)] of one program: R1-R4 per member, then R5 (isolating members on a red R5)."""
    ex, ex_name, ex_tab, src, rows = ctx
    log, results, gated = f"propagate-{prog}", [], []
    for m in ms:
        r = rows.get(m)
        if r is None:
            results.append((pv(m), "refused", "preflight: no corpus row"))
            out(f"{pv(m)} refused preflight: no corpus row")
            continue
        if m == ex:
            defines = []
        elif ex_tab is None:
            defines = [(ex_name, r["name"])]
        else:
            t = table_addr(probe.retail_words(prog, r["name"]))
            if t is None:
                results.append((pv(m), "refused", "R1: no lui/lw table pair in retail words"))
                out(f"{pv(m)} refused R1: no lui/lw table pair in retail words")
                continue
            defines = [(ex_name, r["name"]), (f"D_{ex_tab:08X}", f"D_{t:08X}")]
            if t == ex_tab and unit_aliases(prog, r["tu"], r["name"], f"D_{t:08X}"):
                defines = defines[:1]  # an identity define would override the unit's own alias of the name (T40.c1)
        g, why = gate(prog, m[1], src, defines, log)
        if g is None:
            results.append((pv(m), "refused", why[len("refused "):]))
            out(f"{pv(m)} {why}")
        else:
            gated.append(g)
    if gated:
        try:
            program_r5(prog, src, gated, log)
        except bank.Stop as e:  # isolate per member: undo all, retry each alone
            out(f"propagate: {prog} R5 {e.cause}; isolating {len(gated)} members")
            for g in reversed(gated):
                bank.restore(g["saved"])
            bank.rebuild(prog, log)
            kept = []
            for g0 in gated:
                g, why = gate(prog, g0["vram"], src, g0["defines"], log)
                if g is not None:
                    try:
                        program_r5(prog, src, kept + [g], log)
                        kept.append(g)
                        continue
                    except bank.Stop as e2:
                        bank.restore(g["saved"])
                        bank.rebuild(prog, log)
                        why = f"refused R5: {e2.cause}"
                results.append((pv((prog, g0["vram"])), "refused", why[len("refused "):]))
                out(f"{pv((prog, g0['vram']))} {why}")
            gated = kept
    for g in gated:
        d = g["defines"]
        reason = "exemplar" if not d else "define " + " ".join(f"{o}={n}" for o, n in d)
        results.append((pv((prog, g["vram"])), "gated", reason))
        out(f"{pv((prog, g['vram']))} gated {reason}")
    return results


def _worker_init(q):
    os.chdir(q.get())


def _worker_prog(prog, ms, ctx):
    lines = []
    return run_prog(prog, ms, ctx, lines.append), lines


def write_registry(key, ex, src, results):
    """Rows updated in place (same key + member) or appended; comments, order and the exemplar row kept."""
    with open(bank.REGISTRY) as f:
        lines = f.read().split("\n")
    at = {(t[0], t[3]): i for i, t in registry_rows()}
    for m, state, reason in sorted(results):
        if m == ex:
            continue  # the exemplar row stays (a refused re-gate, e.g. a c-empty exemplar, never overwrites it)
        row = f"{key} {ex} {src} {m} {state} {reason}"
        if (key, m) in at:
            lines[at[(key, m)]] = row
        else:
            lines.insert(len(lines) - 1 if lines and lines[-1] == "" else len(lines), row)
    with open(bank.REGISTRY, "w") as f:
        f.write("\n".join(lines))


def make_tree(tree):
    os.makedirs(tree)
    for p in COPY:  # copy2/copytree keep mtimes, so make sees the copied build/ as up to date
        if os.path.isdir(p):
            shutil.copytree(p, os.path.join(tree, p), symlinks=True)
        else:
            shutil.copy2(p, os.path.join(tree, p))
    for p in LINK:
        os.symlink(os.path.abspath(p), os.path.join(tree, p))


def expect_drift(key, results, reg=bank.REGISTRY, states=None):
    """(DRIFT lines, unrowed refusals): each dry-run verdict vs the member's registry row of key (refused row ->
    refused, any other row -> gated); a member without a row must gate (counted, no DRIFT line). The run's exemplar
    on a `gated` row whose corpus state is c or c-empty agrees refused too (write_registry keeps that row).
    states: {member pv: corpus state} (default: build/corpus)."""
    rows = [t for _, t in registry_rows(reg) if t[0] == key]
    st = {t[3]: t[4] for t in rows}
    exs = {t[3] for t in rows if t[1] == t[3] and t[4] == "gated"}
    if exs and states is None:
        states = {pv(m): r["state"] for m, r in corpus_rows().items()}
    drift, unrowed = [], 0
    for m, state, _ in sorted(results):
        want = "refused" if st.get(m) == "refused" else "gated"
        if state == "refused" and m in exs and states.get(m) in ("c", "c-empty"):
            continue  # a c/c-empty exemplar's re-gate is refused at preflight; its gated row stands
        if state != want:
            if m in st:
                drift.append(f"PROPAGATE DRIFT {key} {m} {st[m]} -> {state}")
            else:
                unrowed += 1
    return drift, unrowed


# ---- registry check ------------------------------------------------------------------------------------------------

def member_keys(ms, rows):
    """{(prog, vram): built dup key or None} (cached)."""
    todo = [m for m in ms if m not in _KEYS]
    have = [m for m in todo if m in rows]
    for m in todo:
        _KEYS.setdefault(m, None)
        _FAMS.setdefault(m, None)
    try:
        for m, (w, k) in zip(have, census.read_words([rows[m] for m in have])):
            _KEYS[m], _FAMS[m] = census.dup_key(w, k), census.family_key(w)
    except census.Refuse:  # some rows unreadable: one at a time
        for m in have:
            try:
                (w, k), = census.read_words([rows[m]])
                _KEYS[m], _FAMS[m] = census.dup_key(w, k), census.family_key(w)
            except census.Refuse:
                pass
    return {m: _KEYS[m] for m in ms}


def check(reg=bank.REGISTRY, cls_path=CLASSES, quiet=False):
    """(rc, refusal lines); prints them and the verdict line unless quiet."""
    rows = [t for _, t in registry_rows(reg)]
    cls, fams, cr = load_classes(cls_path), load_classes(cls_path, "family"), corpus_rows()
    mems = [parse_pv(t[3]) for t in rows]
    got = member_keys(mems, cr)
    bad = []
    for t, m in zip(rows, mems):
        if t[5].startswith("family"):  # family_remap.py rows: the family key, no missing-member rule
            k = _FAMS[m]
            if k != t[0]:
                bad.append(f"REGISTRY refused drift {t[3]}: built family key {k or 'none'} != row key {t[0]}")
            if m not in fams.get(t[0], ()):
                bad.append(f"REGISTRY refused not in class {t[3]} family {t[0]}")
            continue
        k = got[m]
        if k != t[0]:
            bad.append(f"REGISTRY refused drift {t[3]}: built key {k or 'none'} != row key {t[0]}")
        if m not in cls.get(t[0], ()):
            bad.append(f"REGISTRY refused not in class {t[3]} key {t[0]}")
    have = set(zip((t[0] for t in rows), mems))
    for key in sorted({t[0] for t in rows if not t[5].startswith("family")}):
        for m in cls.get(key, ()):
            if (key, m) not in have:
                bad.append(f"REGISTRY refused missing member {pv(m)} key {key}")
    out = bad + ([f"REGISTRY REFUSED {len(bad)} of {len(rows)} rows"] if bad else [f"REGISTRY OK {len(rows)} rows"])
    if not quiet:
        print("\n".join(out))
    return (1 if bad else 0), bad


def self_test():
    d = os.path.join(SCRATCH, "selftest")
    os.makedirs(d, exist_ok=True)
    ex_rows = [t for _, t in registry_rows() if t[1] == t[3]]
    if not ex_rows:
        print(f"propagate: no exemplar row in {bank.REGISTRY}\nPROPAGATE SELF-TEST FAIL")
        return 1
    key, ex, src = ex_rows[0][:3]
    cls = load_classes()
    members = cls[key]
    rows = corpus_rows()
    outsider = next(m for m in sorted(rows) if m not in members and rows[m]["state"] == "c")
    other = next(k for k in sorted(cls) if k != key)
    exrow = " ".join(ex_rows[0][:5] + [ex_rows[0][5]]).rstrip()
    full = [exrow] + [f"{key} {ex} {src} {pv(m)} gated control" for m in members if pv(m) != ex]
    out_row = f"{key} {ex} {src} {pv(outsider)} gated control"
    with open(CLASSES) as f:  # drift: the outsider counted in the class, its built key is not the class key
        planted = [json.loads(line) for line in f]
    for c in planted:
        if c["kind"] == "dup" and c["key"] == key:
            c["members"] = sorted(c["members"] + [[outsider[0], f"0x{outsider[1]:08X}"]])
    pcls = os.path.join(d, "classes.jsonl")
    with open(pcls, "w") as f:
        f.write("".join(json.dumps(c) + "\n" for c in planted))
    controls = [  # (name, registry rows, classes, expect refusal kind or None, only that kind)
        ("clean", full, CLASSES, None),
        ("drift", full + [out_row], pcls, "drift"),
        ("missing member", full[:-1], CLASSES, "missing member"),
        ("not in class", full + [out_row], CLASSES, "not in class"),
        ("foreign key", [exrow.replace(key, other, 1)] + full[1:], CLASSES, "drift"),
    ]
    fails = 0
    for name, lines, cpath, want in controls:
        reg = os.path.join(d, "registry.txt")
        with open(reg, "w") as f:
            f.write(bank.REGISTRY_HEAD + "\n".join(lines) + "\n")
        rc, bad = check(reg, cpath, quiet=True)
        kinds = {b.split(" refused ", 1)[1].split(" ")[0] for b in bad}
        good = rc == 0 and not bad if want is None else rc != 0 and any(f" refused {want} " in b for b in bad)
        if name in ("drift", "missing member"):
            good &= kinds == {want.split()[0]}
        print(f"control {name} {'ok' if good else 'FAIL'}: rc {rc}, {len(bad)} refusals"
              + (f", first: {next((b for b in bad if want in b), bad[0])}" if bad else ""))
        fails += not good
    ms = [pv(m) for m in members if pv(m) != ex][:2]  # --expect-registry controls on planted rows and verdicts
    if len(ms) < 2:
        print(f"control expect FAIL: class {key} has < 2 non-exemplar members")
        fails += 1
    else:
        reg = os.path.join(d, "registry.txt")
        with open(reg, "w") as f:
            f.write(bank.REGISTRY_HEAD + "\n".join([exrow, f"{key} {ex} {src} {ms[0]} refused R5: control",
                                                    f"{key} {ex} {src} {ms[1]} gated control"]) + "\n")
        pre = "preflight: state c-empty, not include_asm"
        for name, res, want, sts in (
                ("expect agree", [(ex, "gated", ""), (ms[0], "refused", "R5: x")], 0, {}),
                ("expect drift", [(ex, "gated", ""), (ms[1], "refused", "R5: x")], 1, {}),
                ("expect c-empty exemplar", [(ex, "refused", pre), (ms[0], "refused", "R5: x")], 0,
                 {ex: "c-empty"})):
            drift, unrowed = expect_drift(key, res, reg, sts)
            rc = 1 if drift or unrowed else 0
            want_drift = [] if want == 0 else [f"PROPAGATE DRIFT {key} {ms[1]} gated -> refused"]
            good = rc == want and drift == want_drift
            print(f"control {name} {'ok' if good else 'FAIL'}: rc {rc}, {len(drift)} drift"
                  + (f", {drift[0]}" if drift else ""))
            fails += not good
    ud = os.path.join(d, "src", "p")  # plant: the unit's own alias above the INCLUDE_ASM suppresses the identity define
    os.makedirs(ud, exist_ok=True)
    with open(os.path.join(ud, "u.c"), "w") as f:
        f.write('#define D_1 D_1_x4\nINCLUDE_ASM("asm/p/nonmatchings/u", f);\n\nINCLUDE_ASM("asm/p/nonmatchings/u", g);\n')
    got = [unit_aliases("p", "u", fn, nm, os.path.join(d, "src")) for fn, nm in (("f", "D_1"), ("f", "D_2"), ("g", "D_1"))]
    good = got == [True, False, False]
    print(f"control unit alias {'ok' if good else 'FAIL'}: {got}")
    fails += not good
    if fails:
        print(f"PROPAGATE SELF-TEST FAIL {fails}")
        return 1
    print("PROPAGATE CONTROL OK")
    return 0


def main():
    root = os.path.abspath(os.path.join(HERE, "..", ".."))
    os.chdir(root)
    ap = argparse.ArgumentParser(description=__doc__.split("\n", 1)[0])
    ap.add_argument("key", nargs="?")
    ap.add_argument("--dry-run", action="store_true")
    ap.add_argument("--expect-registry", action="store_true")
    ap.add_argument("--check", action="store_true")
    ap.add_argument("--self-test", action="store_true")
    a = ap.parse_args()
    if a.self_test:
        return self_test()
    if a.check:
        return check()[0]
    if a.expect_registry and not a.dry_run:
        ap.error("--expect-registry needs --dry-run")
    if not a.key:
        ap.error("need <dup key> [--dry-run], --check or --self-test")
    t0 = time.time()
    if not a.dry_run:
        m, n, _ = propagate(a.key, False)
        print(f"PROPAGATE {a.key} gated {m} of {n} members")
        return 0 if m == n else 1
    watch = ["src", bank.REGISTRY]
    before = tree_sha(watch)
    shutil.rmtree(TREE, ignore_errors=True)
    m, n, results = propagate(a.key, True)
    after = tree_sha(watch)
    print(f"propagate: dry run wall {time.time() - t0:.0f}s; src/ + registry sha1 {after[:12]} "
          f"{'unchanged' if after == before else 'CHANGED from ' + before[:12]}")
    print(f"PROPAGATE DRY-RUN {a.key} gated {m} of {n} members")
    if a.expect_registry:
        drift, unrowed = expect_drift(a.key, results)
        if drift:
            print("\n".join(drift))
        return 0 if not drift and not unrowed and after == before else 1
    return 0 if m == n and after == before else 1


if __name__ == "__main__":
    sys.exit(main())
