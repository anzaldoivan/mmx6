#!/usr/bin/env python3
"""cards.py -- wave packs: card writing (T2.c2) and the pack probe (container, stdlib only).

  cards.py --probe-pack <dir> [--hold S] [--no-snapshot]
      -> `PACK <pv> match <m>/<n>` | `PACK <pv> fail <m>/<n>` | `PACK <pv> nocompile`; rc 0 on any PACK line
      Compiles <dir>/draft.c as drafts/<prog>/<func>.c (its TU's flags, probe.draft_cflags) inside a fresh snapshot
      waves/.iso/<tag>/ of every input probe reads, cwd = the snapshot, so an `mx.sh sync` (which spares waves/)
      cannot pull the tree out from under a running gate; the snapshot is removed after. --hold S sleeps S seconds
      after the snapshot is built (`PACK HOLD <s>` printed first); --no-snapshot compiles in /work itself (the
      negative control of tools/docker/pack_control.sh only).

  cards.py --wave W<n> --targets <file> [--root <dir>] [--journal <path>]
      -> one pack <root>/W<n>/<prog>_<func>/ per target (root default `waves`): pack.json, target.s, scaffold.c
      (decompile.py m2c), ctx.h, card.md, seed.c (when a seed exists); never writes draft.c or verdict.json.
      Lines `CARD <pv> seed <pv|-> twins <k> levers <ids|->` | `CARD REFUSED <pv> <phantom|no-asm|<unresolved id>>`
      (no pack dir), last `CARDS W<n> <k> packs`; rc 0 iff no refusal and k >= 1, rc 3 on k = 0, else rc 1.
      G44: every L\\d{2,} / C\\d{4} token on card.md resolves (codegen_map.read_rows ids, cookbook/INDEX.md rows).
  cards.py --self-test  -> planted cases in .run/cards-selftest/, last `CARDS CONTROL OK` (rc 0), else rc 1.

Pack dir waves/W<n>/<prog>_<func>/: pack.json {pv,prog,func,tu,words}, target.s, draft.c, verdict.json
(docs/ops/campaign.md ## Packs). Snapshot: asm/ and extracted/ hardlinked (nothing writes them in place), Makefile,
mk/, include/, src/, config/, tools/, build/corpus/, build/split/ copied. Firewall G12: prints counts only; card.md,
ctx.h, seed.c and pack.json hold names, addresses, counts, ids and our C only (target.s, scaffold.c stay in the pack).
"""
import argparse
import glob
import json
import os
import re
import shutil
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
REGISTRY = "config/dedup_registry.txt"
C_UNITS = "config/c_units.txt"
COOKBOOK = "cookbook/INDEX.md"
CODEGEN_MAP = "docs/codegen-map"
SELFTEST = ".run/cards-selftest"
TWIN_CAP = 12
PV_RE = re.compile(r"([^\s:]+):0x([0-9A-Fa-f]{8})")
ID_RE = re.compile(r"\b(L\d{2,}|C\d{4})\b")
JAL_RE = re.compile(r"\bjal\s+([A-Za-z_]\w*)")
REL_RE = re.compile(r"%(?:hi|lo|gp_rel)\(([A-Za-z_]\w*)\)")
PROTO_RE = re.compile(rf"^[ \t]*(?:extern\s+)?(?:static\s+)?({declsync.TYPE})\s*\b([A-Za-z_]\w*)\s*\(([^;{{}}()]*)\)\s*;",
                      re.M)
EXTERN_RE = re.compile(r"^[ \t]*(extern\s+[^;(){}=]*?\b([A-Za-z_]\w*)\s*(?:\[[^\]]*\]\s*)*);", re.M)

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


def score(func, prog, src, t):
    """('match'|'fail', m, n) or ('nocompile', 0, n): probe.probe's comparison, with a compile failure kept apart."""
    ret = probe.retail_words(prog, func)
    obj = probe.compile_obj(src, t)
    if obj is None:
        return "nocompile", 0, len(ret)
    ours, masks = probe.elf_function(obj, func)
    m = 0
    for i in range(min(len(ret), len(ours))):
        keep = ~masks.get(i, 0) & 0xFFFFFFFF
        m += (ret[i] & keep) == (ours[i] & keep)
    return ("match" if len(ours) == len(ret) and m == len(ret) else "fail"), m, len(ret)


def probe_pack(pack, hold, iso):
    with open(os.path.join(pack, "pack.json")) as f:
        meta = json.load(f)
    with open(os.path.join(pack, "draft.c"), "rb") as f:
        draft = f.read()
    pv, prog, func = meta["pv"], meta["prog"], meta["func"]
    t = triple()
    src = f"drafts/{prog}/{func}.c"
    if not iso and os.path.exists(src):
        sys.exit(f"cards: --no-snapshot would overwrite the stored draft {src}")
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
        state, m, n = score(func, prog, src, t)
    finally:
        if snap:
            os.chdir(os.path.dirname(os.path.dirname(os.path.dirname(snap))))
            shutil.rmtree(snap, ignore_errors=True)
        elif os.path.exists(src):
            os.remove(src)
    print(f"PACK {pv} {state}" + (f" {m}/{n}" if state != "nocompile" else ""), flush=True)
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


class Ctx:
    """Fleet-wide inputs read once: corpus, dup classes, registry, c_units, src/ declaration index, id sets."""

    def __init__(self):
        self.funcs = {(r["prog"], int(r["vram"], 16)): r for r in jl(FUNCS)}
        self.names = {r["name"] for r in self.funcs.values()}
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


def card(ctx, pv, row, asm, twins, jpath):
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
    globs = sorted({s for s in REL_RE.findall(asm or "") if s not in ctx.names and not s.startswith("func_")})
    recs = [r for r in journal.records(jpath) if r["pv"] == pvs(*pv)]
    label = recs[-1]["label"] if recs and recs[-1]["label"] != "-" else "none"
    trows = plateau.rows(label) if label in plateau.GROUPS else "-"
    levers = sorted(set(re.findall(r"\bL\d{2,}\b", trows)))
    L = [f"# card {pvs(*pv)} {row['name']}", "",
         f"target {pvs(*pv)} {row['name']} tu {row['tu']} words {row['words']} state {row['state']} lane {row['lane']}",
         "", "## Seed"]
    if seed:
        L.append(f"{pvs(*seed[0])} {ctx.funcs.get(seed[0], {}).get('name', '-')} body {seed[1]}" +
                 (f" reason {seed[2]}" if seed[2] else "") + " (copied to seed.c)")
    else:
        L.append("-")
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


def write_cards(wave, targets_path, root, jpath, allow_banked=False, say=print):
    ctx = Ctx()
    targets, bad = [], []
    with open(targets_path) as f:
        for line in f:
            s = line.strip()
            if s and not s.startswith("#"):
                m = PV_RE.fullmatch(s)
                if m:
                    targets.append((m.group(1), int(m.group(2), 16)))
                else:
                    bad.append(s)
    for s in bad:
        say(f"CARD REFUSED {s} malformed")
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
        md, hdr, seed, opens, levers = card(ctx, pv, row, asm, tw[pv], jpath)
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
        files = {"pack.json": json.dumps(dict(pv=pvs(*pv), prog=pv[0], func=row["name"], tu=row["tu"],
                                              words=row["words"])) + "\n",
                 "card.md": md, "ctx.h": hdr}
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
        say(f"CARD {pvs(*pv)} seed {pvs(*seed[0]) if seed else '-'} twins {len(opens)} levers {','.join(levers) or '-'}")
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

    def run(wave, pv, jp):
        tp = os.path.join(SELFTEST, f"{wave}.txt")
        with open(tp, "w") as f:
            f.write(pvs(*pv) + "\n")
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
            rc, said = run(wave, tgt, jp)
            pack = os.path.join(SELFTEST, wave, f"{tgt[0]}_{row['name']}")
            if want is None:
                md = open(os.path.join(pack, "card.md")).read() if os.path.isdir(pack) else ""
                check(rc == 0 and rec["notes"] in md,
                      f"(b) {pvs(*tgt)} card carries the journal record: {said[0]}")
            else:
                check(said[0] == f"CARD REFUSED {pvs(*tgt)} {want}" and not os.path.exists(pack) and rc != 0,
                      f"({'c' if want[0] == 'C' else 'd'}) {pvs(*tgt)} {want} refused, no pack: {said[0]}")
    shutil.rmtree(SELFTEST, ignore_errors=True)
    print("CARDS CONTROL OK" if ok else "CARDS CONTROL FAIL")
    return 0 if ok else 1


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n", 1)[0])
    g = ap.add_mutually_exclusive_group(required=True)
    g.add_argument("--probe-pack", metavar="DIR")
    g.add_argument("--wave", metavar="W<n>")
    g.add_argument("--self-test", action="store_true")
    ap.add_argument("--hold", type=float, default=0)
    ap.add_argument("--no-snapshot", action="store_true")
    ap.add_argument("--targets", metavar="FILE")
    ap.add_argument("--root", default="waves")
    ap.add_argument("--journal", default=journal.JOURNAL)
    a = ap.parse_args()
    if a.probe_pack:
        return probe_pack(a.probe_pack, a.hold, not a.no_snapshot)
    tp = os.path.abspath(a.targets) if a.targets else None
    root, jp = os.path.abspath(a.root), os.path.abspath(a.journal)
    os.chdir(ROOT)
    if a.self_test:
        return self_test()
    if not re.fullmatch(r"W\d+|W-[a-z0-9]+", a.wave) or not tp:
        ap.error("--wave W<n> needs --targets <file>")
    return write_cards(a.wave, tp, root, jp)


if __name__ == "__main__":
    sys.exit(main())
