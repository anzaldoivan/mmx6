#!/usr/bin/env python3
"""propsince.py -- incremental propagate keys: the registry keys whose inputs changed since the last green full run.

  propsince.py record        (container) after a green `th-propagate-full`: build/propagate/green.json = per registry
                             key (PROPAGATE_KEYS_CMD's set: family rows excluded) its inputs, each file with its sha1:
                             the shared paths of its registry rows; the units (build/corpus/functions.jsonl `tu`) of its
                             members (class members of build/census/classes.jsonl + registry member pvs) and each unit's
                             include closure (layout.includers, plus the headers each closure file includes: quoted
                             from its own dir then include/, <...> from include/); the shared bodies' closure; the sha1
                             of its registry rows; the sha1 of its units' lines in config/carve.<prog>.txt. Also every
                             ALL-trigger file with its sha1.
  propsince.py record --shard k --of n   (container, tools-health-shard k>=1 on green; stdin: the shard's keys)
                             build/propagate/shards/<k>.json = {n, fingerprint (sha1 of record()), keys}; when markers
                             1..n share n and fingerprint and their keys cover the current keys -> green.json. Last
                             `PROPSINCE SHARD k of n keys K fingerprint F; markers m of n cover c of C keys [-> green]`.
  propsince.py stamp         (host) binds green.json (read from /work: `mx.sh run cat`, MX6_VOLUME) to HEAD: rc 1
                             unless every recorded tracked file's sha1 equals its HEAD blob content (`git cat-file
                             --batch`); recorded files git does not sync (ignored: generated in the container) are
                             listed as dropped and never compared. Writes build/propagate/since.stamp = {commit,
                             dropped, green}. Last `PROPSINCE STAMP <commit12> files <f> keys <k> dropped <d>`.
  propsince.py select        (host) stdout: the changed keys, one per line, or `ALL`. ALL when there is no stamp, an
                             ALL-trigger file changed, was added or removed (derive_triggers: Makefile, mk/*, the
                             Dockerfile, propagate.py's import + tools/mmx6 script-literal closure, config/ files named
                             in it or Makefile/mk/sdk.mk; never the registry, carve.<prog>.txt, TRIGGER_NOT; 3.1 T23),
                             or the keys would pass 100 KB (one
                             argv element is capped at 128 KB, MAX_ARG_STRLEN). Else the keys with any input changed
                             (file content, row or carve sha1) plus the current keys absent from the stamp. stderr
                             `PROPSINCE <k> of <K> keys since <commit12>; <n> inputs changed` (ALL: `PROPSINCE ALL of
                             <K> keys since <commit12>; <reason>`).
  propsince.py --self-test   fixture tree + stamp under .run/<phase>/propsince-selftest/ (deleted at end, pass or fail; <phase> as layout.RUN): no stamp ->
                             ALL; a changed member unit -> its key only; Makefile -> ALL; an imported module or a
                             named config file -> ALL; an unreferenced tools/mmx6/new.py, methods-arm.tsv or
                             debt-baseline.txt alone -> no keys; the real tree's triggers hold propagate.py, bank.py,
                             carve.py, Makefile, lack methods-arm.tsv, debt-baseline.txt; docs only -> no keys; a
                             header in one unit's closure -> that key; registry row / carve line -> that key; a key
                             absent from the stamp -> selected; with git: stamp refused on a HEAD mismatch (read-only).
                             Ends `PROPSINCE CONTROL OK` (rc 0).
Firewall G12: paths and sha1s of our own files only.
"""
import hashlib
import json
import os
import re
import shutil
import subprocess
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import layout  # noqa: E402
import propagate  # noqa: E402

GREEN = "build/propagate/green.json"
STAMP = "build/propagate/since.stamp"
SELFTEST = os.path.join(layout._phase_run(), "propsince-selftest")  # .run/<phase>/, else .run/
SHARDS = "build/propagate/shards"
# ALL-trigger set, derived (3.1 T23; was TRIGGER_DIRS mk/ tools/mmx6/ tools/docker/ config/): Makefile, mk/*, the
# Dockerfile, propagate.py's local import + tools/mmx6/<x>.(py|sh) literal closure, the config/ files named in it or in
# Makefile/mk/sdk.mk (literal; %s * {..} $(..) parts glob). Registry and carve.<prog>.txt are keyed inputs.
TRIGGER_FIXED = ("Makefile", "tools/docker/Dockerfile")
TRIGGER_ROOT = "tools/mmx6/propagate.py"
TRIGGER_TEXTS = ("Makefile", "mk/sdk.mk")  # scanned for tools/mmx6 and config/ literals too
TRIGGER_EXTRA = ()  # files a propagate run opens that the derivation misses (audit-hook check, 3.1 T23.c1)
# Named by a closure module's other CLI only, never opened by a propagate run (audit hook, 3.1 T23.c1; R159):
# cards.py --arm (imported by gate.py), psxd_floor.py debt (propagate uses its marker counts).
TRIGGER_NOT = ("config/methods-arm.tsv", "config/debt-baseline.txt")
IMPORT_RE = re.compile(r"^\s*(?:from\s+([\w.]+)\s+import\b|import\s+([\w., ]+?)\s*(?:#|$))", re.M)
SCRIPT_RE = re.compile(r"tools/mmx6/[\w/]+\.(?:py|sh)\b")
CONFIG_RE = re.compile(r"config/(?:[\w.\-%*/]|\$\([^)\s]*\)|\{[^}\s]*\}|\$[*@<])+")
CARVE_RE = re.compile(r"^config/carve\.[^/]+\.txt$")
HDR_RE = re.compile(r'^\s*#\s*include\s*([<"])([^">]+)[">]')
MAX_KEY_BYTES = 100000  # selected keys' bytes above which select prints ALL (argv element cap 128 KB)


def sha1_file(path):
    try:
        with open(path, "rb") as f:
            return hashlib.sha1(f.read()).hexdigest()
    except OSError:
        return None


def sha1_text(s):
    return hashlib.sha1(s.encode()).hexdigest()


def read_text(root, rel):
    try:
        with open(os.path.join(root, rel), errors="replace") as f:
            return f.read()
    except OSError:
        return ""


def walk_files(root, d):
    out = []
    for dp, dns, fns in os.walk(os.path.join(root, d)):
        dns[:] = sorted(x for x in dns if x != "__pycache__")
        out += [os.path.relpath(os.path.join(dp, fn), root).replace(os.sep, "/")
                for fn in fns if not fn.endswith(".pyc")]
    return sorted(out)


def config_pattern(lit):
    """regex of one config/ literal: %s, %d, *, {..}, $(..), $* parts match [^/]*; a trailing `/` is the whole dir."""
    lit = lit.rstrip(".-")
    if lit == "config/" or not lit.startswith("config/"):
        return None
    parts = re.split(r"(\$\([^)]*\)|\{[^}]*\}|\$[*@<]|%[sd]?|\*)", lit)
    rx = "".join("[^/]*" if i % 2 else re.escape(p) for i, p in enumerate(parts))
    return re.compile(rx + (".*" if lit.endswith("/") else "") + "$")


def module_file(root, name):
    """tools/mmx6/<name>.py, else tools/<name>.py (propagate adds tools/ for psxd_floor), else None."""
    for d in ("tools/mmx6/", "tools/"):
        rel = d + name.replace(".", "/") + ".py"
        if os.path.isfile(os.path.join(root, rel)):
            return rel
    return None


def derive_triggers(root="."):
    """The ALL-trigger paths of the tree at root (see TRIGGER_FIXED above), sorted."""
    closure, todo, texts = set(), [TRIGGER_ROOT], {r: read_text(root, r) for r in TRIGGER_TEXTS}
    for t in texts.values():
        todo += SCRIPT_RE.findall(t)
    while todo:
        r = todo.pop()
        if r in closure or not os.path.isfile(os.path.join(root, r)):
            continue
        closure.add(r)
        t = texts[r] = read_text(root, r)
        todo += SCRIPT_RE.findall(t)
        if r.endswith(".py"):
            for frm, imp in IMPORT_RE.findall(t):
                for name in ([frm] if frm else [x.split()[0] for x in imp.split(",") if x.strip()]):
                    m = module_file(root, name)
                    if m:
                        todo.append(m)
    pats = {p for t in texts.values() for p in map(config_pattern, CONFIG_RE.findall(t)) if p}
    conf = [p for p in walk_files(root, "config") if any(x.match(p) for x in pats)]
    out = set(closure) | set(conf) | set(walk_files(root, "mk")) | set(TRIGGER_EXTRA)
    out |= {p for p in TRIGGER_FIXED if os.path.isfile(os.path.join(root, p))}
    return sorted(p for p in out if p != propagate.bank.REGISTRY and not CARVE_RE.match(p) and p not in TRIGGER_NOT
                  and os.path.isfile(os.path.join(root, p)))


def git_lines(*args):
    """git output split on NUL, or None without git / outside a work tree."""
    if not shutil.which("git"):
        return None
    r = subprocess.run(["git", *args], capture_output=True)
    if r.returncode:
        return None
    return [x for x in r.stdout.decode().split("\0") if x]


def keys_now(reg):
    """PROPAGATE_KEYS_CMD's set: registry keys of rows whose reason's first word is not `family`."""
    return sorted({t[0] for _, t in reg if (t[5].split() or [""])[0] != "family"})


def rows_sha(reg, key):
    return sha1_text("\n".join(" ".join(t) for _, t in reg if t[0] == key))


def carve_lines(prog, root="."):
    p = os.path.join(root, "config", f"carve.{prog}.txt")
    if not os.path.isfile(p):
        return []
    with open(p) as f:
        return [l.rstrip("\n") for l in f if l.strip() and not l.startswith("#")]


def carve_sha(units, root=".", cache=None):
    """sha1 of the carve lines naming one of units (jtbl: col 3; rodata/data: col 4; opt: col 2 or 4)."""
    cache = {} if cache is None else cache
    out = []
    for prog, tu in sorted(units):
        if prog not in cache:
            cache[prog] = carve_lines(prog, root)
        for l in cache[prog]:
            w = l.split()
            tus = {"jtbl": w[2:3], "rodata": w[3:4], "data": w[3:4], "opt": w[1:2] + w[3:4]}.get(w[0], [])
            if tu in tus:
                out.append(f"{prog} {l}")
    return sha1_text("\n".join(out))


class Deps:
    """Per-file direct includes (the .c includes as layout.includers resolves them, plus headers)."""

    def __init__(self, root="."):
        self.root, self.memo = root, {}

    def exists(self, rel):
        return os.path.isfile(os.path.join(self.root, rel))

    def direct(self, rel):
        if rel not in self.memo:
            out = []
            try:
                with open(os.path.join(self.root, rel), errors="replace") as f:
                    lines = f.read().split("\n")
            except OSError:
                lines = []
            for l in lines:
                m = HDR_RE.match(l)
                if not m:
                    continue
                q, t = m.groups()
                if t.endswith(".c"):
                    cands = [t if t.startswith("src/") else layout.norm(rel, t)]
                elif q == '"':
                    cands = [layout.norm(rel, t), "include/" + t]
                else:
                    cands = ["include/" + t]
                for c in cands:
                    if self.exists(c):
                        out.append(c)
                        break
            self.memo[rel] = out
        return self.memo[rel]

    def closure(self, starts):
        seen, todo = set(), list(starts)
        while todo:
            r = todo.pop()
            if r in seen or not self.exists(r):
                continue
            seen.add(r)
            todo.extend(self.direct(r))
        return seen


def record(root="."):
    """green.json's content for the tree at root (cwd-relative build/ inputs)."""
    reg = propagate.registry_rows(os.path.join(root, propagate.bank.REGISTRY))
    classes = propagate.load_classes(os.path.join(root, propagate.CLASSES))
    with open(os.path.join(root, propagate.FUNCS)) as f:
        rows = {(r["prog"], int(r["vram"], 16)): r for r in map(json.loads, f)}
    unit_files = {}
    for path, us in layout.includers(root).items():
        for u in us:
            unit_files.setdefault(tuple(u), set()).add(path)
    deps, files, keys, carves = Deps(root), {}, {}, {}
    unit_clos = {}
    for key in keys_now(reg):
        krows = [t for _, t in reg if t[0] == key]
        members = set(classes.get(key, [])) | {propagate.parse_pv(t[3]) for t in krows}
        units = sorted({(m[0], rows[m]["tu"]) for m in members if m in rows})
        kf = deps.closure({t[2] for t in krows})
        for u in units:
            if u not in unit_clos:
                unit_clos[u] = deps.closure(unit_files.get(u, ()))
            kf |= unit_clos[u]
        keys[key] = {"files": sorted(kf), "rows": rows_sha(reg, key), "carve": carve_sha(units, root, carves),
                     "units": [list(u) for u in units]}
        for p in kf:
            files.setdefault(p, None)
    triggers = derive_triggers(root)
    for p in list(files) + triggers:
        files[p] = sha1_file(os.path.join(root, p))
    return {"version": 1, "files": dict(sorted(files.items())), "triggers": triggers, "keys": keys}


def head_mismatch(files, tracked):
    """[path] of recorded tracked files whose sha1 differs from the HEAD blob (one `git cat-file --batch`)."""
    paths = sorted(p for p in files if p in tracked)
    if not paths:
        return []
    r = subprocess.run(["git", "cat-file", "--batch"], input="".join(f"HEAD:{p}\n" for p in paths).encode(),
                       capture_output=True, check=True)
    out, buf, i = [], r.stdout, 0
    for p in paths:
        j = buf.index(b"\n", i)
        hdr = buf[i:j].split()
        if hdr[-1] == b"missing":
            out.append(p)
            i = j + 1
            continue
        n = int(hdr[2])
        if hashlib.sha1(buf[j + 1:j + 1 + n]).hexdigest() != files[p]:
            out.append(p)
        i = j + 1 + n + 1
    return out


def stamp():
    r = subprocess.run(["bash", "tools/docker/mx.sh", "run", "cat", GREEN], capture_output=True)
    if r.returncode != 0:
        print(f"PROPSINCE stamp refused: no {GREEN} in /work (mx.sh run cat rc {r.returncode})")
        return 1
    green = json.loads(r.stdout)
    synced = git_lines("ls-files", "-co", "--exclude-standard", "-z")
    tracked = git_lines("ls-files", "-z")
    head = git_lines("rev-parse", "HEAD")
    if synced is None or tracked is None or not head:
        print("PROPSINCE stamp refused: needs git (host)")
        return 1
    synced, tracked, commit = set(synced), set(tracked), head[0].strip()
    dropped = sorted(p for p in green["files"] if p not in synced)
    bad = head_mismatch(green["files"], tracked)
    for p in bad[:10]:
        print(f"PROPSINCE stamp refused {p}: recorded sha1 != HEAD")
    if bad:
        print(f"PROPSINCE stamp refused: {len(bad)} recorded files differ from HEAD {commit[:12]}")
        return 1
    os.makedirs(os.path.dirname(STAMP), exist_ok=True)
    with open(STAMP, "w") as f:
        json.dump({"commit": commit, "dropped": dropped, "green": green}, f)
    print(f"PROPSINCE STAMP {commit[:12]} files {len(green['files'])} keys {len(green['keys'])} dropped {len(dropped)}")
    return 0


def select(st, root=".", triggers_now=None):
    """(['ALL'] | [keys], stderr line). st: the stamp dict or None; triggers_now: the current ALL-trigger paths."""
    reg = propagate.registry_rows(os.path.join(root, propagate.bank.REGISTRY))
    now = keys_now(reg)
    if st is None:
        return ["ALL"], f"PROPSINCE ALL of {len(now)} keys since no stamp; no stamp"
    green, dropped, since = st["green"], set(st["dropped"]), st["commit"][:12]
    files = {p: s for p, s in green["files"].items() if p not in dropped}
    trig_then = {p for p in green["triggers"] if p not in dropped}
    trig_now = set(derive_triggers(root) if triggers_now is None else triggers_now)

    def all_(why):
        return ["ALL"], f"PROPSINCE ALL of {len(now)} keys since {since}; {why}"

    if trig_then != trig_now:
        d = sorted(trig_then ^ trig_now)
        return all_(f"trigger {'added' if d[0] in trig_now else 'removed'} {d[0]}")
    for p in sorted(trig_then):
        if sha1_file(os.path.join(root, p)) != files[p]:
            return all_(f"trigger changed {p}")
    changed = {p for p, s in files.items() if p not in trig_then and sha1_file(os.path.join(root, p)) != s}
    sel, carves, nrow = [], {}, 0
    for key in now:
        k = green["keys"].get(key)
        if k is None:
            sel.append(key)
            continue
        hit = any(p in changed for p in k["files"])
        if rows_sha(reg, key) != k["rows"] or carve_sha([tuple(u) for u in k["units"]], root, carves) != k["carve"]:
            hit, nrow = True, nrow + 1
        if hit:
            sel.append(key)
    if sum(len(k) + 1 for k in sel) > MAX_KEY_BYTES:
        return all_(f"{len(sel)} keys pass {MAX_KEY_BYTES} bytes")
    return sel, f"PROPSINCE {len(sel)} of {len(now)} keys since {since}; {len(changed) + nrow} inputs changed"


def cmd_select():
    st = None
    if os.path.isfile(STAMP):
        with open(STAMP) as f:
            st = json.load(f)
    synced = git_lines("ls-files", "-co", "--exclude-standard", "-z")
    trig = [p for p in derive_triggers(".") if p in set(synced)] if synced is not None else None
    out, line = select(st, ".", trig)
    print("\n".join(out))
    print(line, file=sys.stderr)
    return 0


# ---- self-test ------------------------------------------------------------------------------------------------------

FIX = {
    "Makefile": "all:\n",
    "mk/a.mk": "# a\n",
    "tools/mmx6/t.py": "# t\n",
    "tools/mmx6/propagate.py": ("import os\nimport t  # noqa\nUNITS = 'config/c_units.txt'\n"
                                "ARM = 'config/methods-arm.tsv'\n"),
    "config/c_units.txt": "# units\nP A\nP B\nP C\n",
    "config/methods-arm.tsv": "# arm\n",
    "config/debt-baseline.txt": "# debt\n",
    "config/carve.P.txt": "# carves\nrodata 0x80001000 0x80001010 A\nrodata 0x80002000 0x80002010 B\n",
    "config/dedup_registry.txt": ("# registry\n"
                                  "ka P:0x80000100 src/shared/s.c P:0x80000100 gated exemplar\n"
                                  "ka P:0x80000100 src/shared/s.c P:0x80000200 gated define\n"
                                  "kb P:0x80000300 src/shared/t.c P:0x80000300 gated exemplar\n"
                                  "kf P:0x80000100 src/shared/s.c P:0x80000400 gated family remap\n"),
    "src/P/A.c": '#include "common.h"\n#include "../shared/s.c"\nvoid a(void) {}\n',
    "src/P/B.c": '#include "common.h"\n#include "h.h"\n#include "../shared/t.c"\n',
    "src/P/C.c": '#include "common.h"\nvoid c(void) {}\n',
    "src/shared/s.c": "void s(void) {}\n",
    "src/shared/t.c": "void t(void) {}\n",
    "include/common.h": "/* common */\n",
    "src/P/h.h": "/* h */\n",
    "docs/d.md": "doc\n",
}
FIX_FUNCS = [("0x80000100", "A"), ("0x80000200", "A"), ("0x80000300", "B"), ("0x80000400", "C"), ("0x80000500", "C")]


def self_test():
    base = os.path.abspath(SELFTEST)
    shutil.rmtree(base, ignore_errors=True)
    fails = []

    def put(rel, text):
        p = os.path.join(base, rel)
        os.makedirs(os.path.dirname(p), exist_ok=True)
        with open(p, "w") as f:
            f.write(text)

    def check(name, st, want, edits=()):
        for rel, text in edits:
            put(rel, text)
        got, line = select(st, base)
        for rel, _ in edits:
            if rel in FIX:
                put(rel, FIX[rel])
            else:
                os.remove(os.path.join(base, rel))
        ok = got == want
        print(f"PROPSINCE control {name}: {' '.join(got) or '(none)'} {'ok' if ok else 'FAIL want ' + ' '.join(want)}")
        if not ok:
            fails.append(name)

    try:
        for rel, text in FIX.items():
            put(rel, text)
        put(propagate.FUNCS, "".join(json.dumps({"prog": "P", "vram": v, "name": "f" + v, "tu": tu}) + "\n"
                                     for v, tu in FIX_FUNCS))
        put(propagate.CLASSES, json.dumps({"kind": "dup", "key": "ka", "members": [["P", "0x80000100"],
                                                                                 ["P", "0x80000200"]]}) + "\n")
        green = record(base)
        st = {"commit": "f" * 40, "dropped": [], "green": green}
        check("no stamp", None, ["ALL"])
        check("unchanged", st, [])
        check("member unit A", st, ["ka"], [("src/P/A.c", FIX["src/P/A.c"] + "/* c */\n")])
        check("Makefile", st, ["ALL"], [("Makefile", "all:\n\t@true\n")])
        check("unreferenced tools/mmx6/new.py", st, [], [("tools/mmx6/new.py", "# n\n")])
        check("imported module t", st, ["ALL"], [("tools/mmx6/t.py", "# t2\n")])
        check("named config c_units", st, ["ALL"], [("config/c_units.txt", FIX["config/c_units.txt"] + "# x\n")])
        check("methods-arm only", st, [], [("config/methods-arm.tsv", "# arm 2\n")])
        check("debt-baseline only", st, [], [("config/debt-baseline.txt", "# debt 2\n")])
        check("docs only", st, [], [("docs/d.md", "doc 2\n")])
        check("header in B closure", st, ["kb"], [("src/P/h.h", "/* h2 */\n")])
        check("shared body s", st, ["ka"], [("src/shared/s.c", "void s(void) { }\n")])
        check("carve line of A", st, ["ka"], [("config/carve.P.txt", FIX["config/carve.P.txt"].replace("1010", "1014"))])
        check("registry row kb", st, ["kb"], [("config/dedup_registry.txt",
                                                 FIX["config/dedup_registry.txt"].replace("exemplar\nkf", "x\nkf"))])
        check("key absent from stamp", st, ["kc"], [("config/dedup_registry.txt", FIX["config/dedup_registry.txt"]
                                                     + "kc P:0x80000500 src/shared/s.c P:0x80000500 gated exemplar\n")])
        if "kf" in green["keys"]:
            fails.append("family key recorded")
        real = set(derive_triggers(os.path.dirname(os.path.dirname(HERE))))
        need = {"tools/mmx6/propagate.py", "tools/mmx6/bank.py", "tools/mmx6/carve.py", "Makefile"}
        ok = need <= real and not real & {"config/methods-arm.tsv", "config/debt-baseline.txt"}
        print(f"PROPSINCE control real-tree triggers {len(real)}: {'ok' if ok else 'FAIL'}")
        if not ok:
            fails.append("real-tree triggers")
        tracked = git_lines("ls-files", "-z")
        if tracked is not None and "Makefile" in tracked:
            bad = head_mismatch({"Makefile": "0" * 40}, set(tracked))
            r = subprocess.run(["git", "cat-file", "blob", "HEAD:Makefile"], capture_output=True, check=True)
            good = head_mismatch({"Makefile": hashlib.sha1(r.stdout).hexdigest()}, set(tracked))
            ok = bad == ["Makefile"] and good == []
            print(f"PROPSINCE control stamp HEAD mismatch: refused {bad} / clean {good} {'ok' if ok else 'FAIL'}")
            if not ok:
                fails.append("stamp")
        else:
            print("PROPSINCE control stamp HEAD mismatch: skipped (no git)")
    finally:
        shutil.rmtree(base, ignore_errors=True)
    if fails:
        print(f"PROPSINCE CONTROL FAILED {', '.join(fails)}")
        return 1
    print("PROPSINCE CONTROL OK")
    return 0


def record_shard(k, n, keys):
    """Marker SHARDS/<k>.json {n, fingerprint (sha1 of record()), keys: the shard's keys, stdin}; when markers 1..n
    share n and fingerprint and their keys cover keys_now, green.json = that record."""
    green = record(".")
    fp = sha1_text(json.dumps(green, sort_keys=True))
    os.makedirs(SHARDS, exist_ok=True)
    with open(os.path.join(SHARDS, f"{k}.json"), "w") as f:
        json.dump({"n": n, "fingerprint": fp, "keys": keys}, f)
    have, cover = 0, set()
    for i in range(1, n + 1):
        try:
            with open(os.path.join(SHARDS, f"{i}.json")) as f:
                m = json.load(f)
        except (OSError, ValueError):
            continue
        if m.get("n") == n and m.get("fingerprint") == fp:
            have, cover = have + 1, cover | set(m.get("keys", []))
    now = set(green["keys"])
    done = have == n and now <= cover
    if done:
        with open(GREEN, "w") as f:
            json.dump(green, f)
    print(f"PROPSINCE SHARD {k} of {n} keys {len(keys)} fingerprint {fp[:12]}; markers {have} of {n} cover "
          f"{len(now & cover)} of {len(now)} keys" + (f" -> {GREEN}" if done else ""))
    return 0


def main():
    a = sys.argv[1:]
    if a == ["--self-test"]:
        return self_test()
    if a == ["record"]:
        green = record(".")
        os.makedirs(os.path.dirname(GREEN), exist_ok=True)
        with open(GREEN, "w") as f:
            json.dump(green, f)
        print(f"PROPSINCE RECORD keys {len(green['keys'])} files {len(green['files'])} -> {GREEN}")
        return 0
    if len(a) == 5 and a[:2] == ["record", "--shard"] and a[3] == "--of" and a[2].isdigit() and a[4].isdigit():
        return record_shard(int(a[2]), int(a[4]), sorted({l.strip() for l in sys.stdin if l.strip()}))
    if a == ["stamp"]:
        return stamp()
    if a == ["select"]:
        return cmd_select()
    print("usage: propsince.py record [--shard k --of n] | stamp | select | --self-test", file=sys.stderr)
    return 2


if __name__ == "__main__":
    sys.exit(main())
