#!/usr/bin/env python3
"""family_remap.py -- remap a banked exemplar's shared body onto its structural family (container python3, stdlib).

  family_remap.py <family key> [--dry-run]
      -> the exemplar = the config/dedup_registry.txt row `gated exemplar` whose member lies in the family class of
         build/census/classes.jsonl (none, or no such family: rc 2). Siblings = family members outside the exemplar's
         dup class, (prog, vram) order. Per sibling, rungs:
         preflight bank.preflight (corpus row include_asm in a config/c_units.txt TU).
         pair     relocation targets (`readelf -rW`, offset order, (type, symbol)) of the body compiled standalone
                  (probe.compile_obj, Makefile TRIPLE) inside the exemplar function vs those of the built object holding
                  the sibling (census.obj_of) inside its extent; a sibling HI16/LO16 target is named D_<ADDR>, ADDR from
                  its retail hi/lo words (T5 rule); refused on a count or type-sequence difference, a section-symbol
                  target, an inconsistent mapping (one -> two, two -> one) or a reorder/chain (x -> y, y != x, y also an
                  exemplar target). Mapping + `<exemplar func> -> <sibling name>`, identities dropped = the defines.
         R1       bank.wrapper + probe.probe MATCH (before bank, so an R1 refusal costs no program rebuild).
         R2-R5    bank.bank(<sibling>, body, registry=False, defines) (R1 again, then R2..R5).
         One line per sibling `<prog:vram> <func> gated|refused <rung>: <cause>`; a gated sibling appends the registry
         row `<family key> <exemplar prog:vram> <body> <sibling prog:vram> gated family define A=B ...` (line-preserving).
         Last line `REMAP <key> gated <g> of <s> siblings; refused <r> (<rung> <n>, ...)`, rc 0 (g = 0 is no failure).
      --dry-run: preflight + pair + R1 only, no tree edits; last line ends ` (dry-run: R1 only)`.
  family_remap.py --self-test
      -> C0054 planted controls. G: SLUS_013.95:0x8001E78C (C in src/SLUS_013.95/120A0.c): its targets read from
         120A0.c.o first; its definition becomes INCLUDE_ASM of a bank.plant_words .s, the exe must rebuild to its
         pre-test sha1, corpus.py --all regenerates; exemplar src/shared/_selftest/remap_ex.c = its body as `remap_ex`
         calling `remap_callee` -> must be gated (R5), then its family row is written and `propagate.py --check` must
         pass. R: `remap_a(1); remap_b(2);` vs the reverse, compiled standalone in .run/remap/ -> must be refused at pair.
         Teardown restores src/, the registry and build/corpus/{functions,spans,denominators}.jsonl byte-exact, deletes
         the plants, rebuilds; fail-closed check of src/, registry, exe sha1. Ends `REMAP CONTROL OK` (rc 0), else
         `REMAP SELF-TEST FAIL <n>` (rc 1). Logs under .run/remap/.
Firewall G12: names, addresses, counts and hashes of our own files only.
"""
import argparse
import contextlib
import json
import os
import re
import shutil
import subprocess
import sys
import time

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import bank  # noqa: E402
import census  # noqa: E402
import probe  # noqa: E402
import propagate  # noqa: E402

SCRATCH = ".run/remap"
RUNGS = ("preflight", "pair", "R1", "R2", "R3", "R4", "R5")
HILO = ("R_MIPS_HI16", "R_MIPS_LO16")
REL_ROW = re.compile(r"^([0-9a-f]{8})\s+[0-9a-f]{8}\s+(R_MIPS_\w+)(?:\s+[0-9a-f]{8}\s+(\S+))?")
G_SIB = ("SLUS_013.95", 0x8001E78C)
G_UNIT = "src/SLUS_013.95/120A0.c"
G_SRC = "src/shared/_selftest/remap_ex.c"


class Refuse(Exception):
    pass


# ---- relocation targets ---------------------------------------------------------------------------------------------

def relocs(obj, func, nwords=None):
    """[(word index, type, symbol)] of obj's relocations inside func (nwords words; None: to its section's end)."""
    data, syms = census.elf_load(obj)
    if func not in syms:
        raise Refuse(f"no symbol {func} in {obj}")
    sec, off = syms[func]
    end = off + 4 * nwords if nwords else len(data.get(sec, b""))
    out, cur = [], None
    for line in subprocess.run([census.READELF, "-rW", obj], capture_output=True, text=True, check=True).stdout.splitlines():
        m = census.REL_HDR.match(line)
        if m:
            cur = m.group(1)[4:] if m.group(1).startswith(".rel.") else m.group(1)[5:]
            continue
        m = REL_ROW.match(line)
        if m and cur == sec and off <= int(m.group(1), 16) < end:
            out.append(((int(m.group(1), 16) - off) // 4, m.group(2), m.group(3) or ""))
    return sorted(out, key=lambda t: t[0])


def targets(rel, words=None):
    """[(type, name)] of rel; HI16/LO16 named D_<ADDR> from words (the retail words) when given."""
    if any(not s or s.startswith(".") for _, _, s in rel):
        raise Refuse("section-symbol target")
    if words is None or not any(t in HILO for _, t, _ in rel):
        return [(t, s) for _, t, s in rel]
    names, pend, last = {}, {}, {}
    for i, (k, t, s) in enumerate(rel):
        if t == "R_MIPS_HI16":
            pend.setdefault(s, []).append(i)
            last[s] = (words[k] & 0xFFFF) << 16
        elif t == "R_MIPS_LO16":
            if s not in last:
                raise Refuse(f"LO16 of {s} without a HI16")
            lo = words[k] & 0xFFFF
            name = f"D_{(last[s] + (lo - 0x10000 if lo & 0x8000 else lo)) & 0xFFFFFFFF:08X}"
            for j in pend.pop(s, []) + [i]:
                names[j] = name
    if any(t == "R_MIPS_HI16" and i not in names for i, (_, t, _) in enumerate(rel)):
        raise Refuse("HI16 without a LO16")
    return [(t, names.get(i, s)) for i, (_, t, s) in enumerate(rel)]


def sibling_targets(r, idx):
    obj = census.obj_of(r, idx)
    if obj is None or not os.path.isfile(obj):
        raise Refuse(f"no object for {r['name']} ({obj})")
    rel = relocs(obj, r["name"], r["words"])
    words = probe.retail_words(r["prog"], r["name"]) if any(t in HILO for _, t, _ in rel) else None
    return targets(rel, words)


def pair(ex_t, sib_t, ex_func, sib_func):
    """(defines [(OLD, NEW)] or None, refusal cause)."""
    if len(ex_t) != len(sib_t):
        return None, f"{len(ex_t)} exemplar vs {len(sib_t)} sibling relocations"
    if [t for t, _ in ex_t] != [t for t, _ in sib_t]:
        return None, "relocation type sequence differs"
    fwd, back = {}, {}
    for x, y in [(x, y) for (_, x), (_, y) in zip(ex_t, sib_t)] + [(ex_func, sib_func)]:
        if fwd.setdefault(x, y) != y:
            return None, f"inconsistent mapping {x} -> {fwd[x]} and {y}"
        if back.setdefault(y, x) != x:
            return None, f"inconsistent mapping {back[y]} and {x} -> {y}"
    for x, y in fwd.items():
        if y != x and y in fwd:
            return None, f"reorder/chain {x} -> {y} ({y} is an exemplar target)"
    return [(ex_func, sib_func)] + [(x, y) for x, y in fwd.items() if x != y and x != ex_func], ""


# ---- remap -----------------------------------------------------------------------------------------------------------

def remap_one(r, ex_func, ex_t, body, dry, idx, sib_t=None):
    """(state, rung, cause, defines) of one sibling corpus row (sib_t: its targets, read earlier; the self-test)."""
    prog, vram = r["prog"], int(r["vram"], 16)
    pv, func = f"{prog}:0x{vram:08X}", r["name"]
    _, _, cause = bank.preflight(prog, vram, body)
    if cause and not cause.startswith("state c,"):
        return "refused", "preflight", cause, None
    try:
        sib_t = sib_t if sib_t is not None else sibling_targets(r, idx)
    except (Refuse, SystemExit) as e:
        return "refused", "pair", str(e), None
    defines, why = pair(ex_t, sib_t, ex_func, func)
    if defines is None:
        return "refused", "pair", why, None
    if cause:  # a c row: only a unit already holding this block is re-gated
        _, _, cause = bank.preflight(prog, vram, body, defines)
        if cause:
            return "refused", "preflight", cause, None
    os.makedirs(SCRATCH, exist_ok=True)
    with open(os.path.join(SCRATCH, "remap.log"), "a") as lf, contextlib.redirect_stdout(lf):
        try:
            ok, m, n = probe.probe(func, prog, bank.wrapper(body, func, defines), bank.makefile_triple())
        except SystemExit as e:
            return "refused", "R1", f"probe error: {e}", None
        if not ok:
            return "refused", "R1", f"standalone probe FAIL {m}/{n} words", None
        if dry:
            return "gated", "R1", "probe MATCH (dry-run)", defines
        rc, out = bank.bank(pv, body, registry=False, defines=defines)
    if rc == 0:
        return "gated", "R5", out.split(" R5 ", 1)[1], defines
    m = re.search(r" stopped (R\d): (.*)$", out)
    return ("refused", m.group(1), m.group(2), None) if m else ("refused", "preflight", out.split(": ", 1)[-1], None)


def family_row(key, ex_pv, body, pv, defines):
    """Append (or update in place) the sibling's family row of the registry, line-preserving."""
    row = f"{key} {ex_pv} {body} {pv} gated family define " + " ".join(f"{o}={n}" for o, n in defines)
    with open(bank.REGISTRY) as f:
        lines = f.read().split("\n")
    at = [i for i, t in propagate.registry_rows() if t[0] == key and t[3] == pv]
    if at:
        lines[at[0]] = row
    else:
        lines.insert(len(lines) - 1 if lines and lines[-1] == "" else len(lines), row)
    with open(bank.REGISTRY, "w") as f:
        f.write("\n".join(lines))


def summary(key, rs, dry):
    g = sum(s == "gated" for s, _ in rs)
    by = [f"{k} {n}" for k in RUNGS for n in [sum(s == "refused" and g_ == k for s, g_ in rs)] if n]
    return (f"REMAP {key} gated {g} of {len(rs)} siblings; refused {len(rs) - g}" + (f" ({', '.join(by)})" if by else "")
            + (" (dry-run: R1 only)" if dry else ""))


def run(key, dry):
    with open(propagate.CLASSES) as f:
        fam = next((c for c in map(json.loads, f) if c["kind"] == "family" and c["key"] == key), None)
    if fam is None:
        print(f"REMAP {key} refused: no family class in {propagate.CLASSES}")
        return 2
    members = {(p, int(v, 16)) for p, v in fam["members"]}
    ex = next((t for _, t in propagate.registry_rows() if t[4] == "gated" and t[5] == "exemplar"
               and propagate.parse_pv(t[3]) in members), None)
    if ex is None:
        print(f"REMAP {key} refused: no gated exemplar row of the family in {bank.REGISTRY}")
        return 2
    exm, body = propagate.parse_pv(ex[3]), ex[2]
    cls = bank.dup_key(*exm)
    dup = {(p, int(v, 16)) for p, v in (cls["members"] if cls else [])}
    rows = propagate.corpus_rows()
    obj = probe.compile_obj(body, bank.makefile_triple())
    if obj is None:
        print(f"REMAP {key} refused: {body} does not compile standalone")
        return 2
    ex_func = rows[exm]["name"]
    try:
        ex_t = targets(relocs(obj, ex_func, rows[exm]["words"]))
    except Refuse as e:
        print(f"REMAP {key} refused: exemplar targets: {e}")
        return 2
    idx = census.asm_index()
    rs = []
    for m in sorted(members - dup):
        pv = propagate.pv(m)
        r = rows.get(m)
        if r is None:
            state, rung, cause, defines = "refused", "preflight", "no corpus row", None
        else:
            state, rung, cause, defines = remap_one(r, ex_func, ex_t, body, dry, idx)
        print(f"{pv} {r['name'] if r else '?'} {state} {rung}: {cause}", flush=True)
        if state == "gated" and not dry:
            family_row(key, ex[3], body, pv, defines)
        rs.append((state, rung))
    print(summary(key, rs, dry))
    return 0


# ---- self-test --------------------------------------------------------------------------------------------------------

def src_bytes():
    return {p: open(p, "rb").read() for p in sorted(bank.tree_sums("src"))}


def put_tree(snap):
    """src/ back to snap byte-exact (changed files rewritten, new files and empty new dirs removed)."""
    for p in bank.tree_sums("src"):
        if p not in snap:
            os.remove(p)
    for p, b in snap.items():
        if not os.path.exists(p) or open(p, "rb").read() != b:
            with open(p, "wb") as f:
                f.write(b)
    for d, _, _ in sorted(os.walk("src"), reverse=True):
        if d != "src" and not os.listdir(d):
            os.rmdir(d)


def control_g():
    """(ok, line) of control G; leaves the planted tree for the teardown."""
    prog, gv = G_SIB
    rows = propagate.corpus_rows()
    r = rows[G_SIB]
    func, tu = r["name"], r["tu"]
    with open(propagate.CLASSES) as f:
        fam = next(c["key"] for c in map(json.loads, f)
                   if c["kind"] == "family" and [prog, f"0x{gv:08X}"] in c["members"])
    unit_o = f"build/src/{prog}/{tu}.c.o"
    if not os.path.isfile(unit_o) and bank.sh(["make", "-s", unit_o], "remap-selftest"):
        raise bank.Stop(0, f"{unit_o} does not build")
    sib_t = sibling_targets(r, census.asm_index())  # read before planting
    callees = sorted({s for t, s in sib_t if t == "R_MIPS_26"})
    if len(callees) != 1:
        raise bank.Stop(0, f"{func}: {len(callees)} jal targets, want 1")
    with open(G_UNIT) as f:
        lines = f.read().split("\n")
    i = next(k for k, l in enumerate(lines) if re.match(rf"^\w[^;(]*\b{func}\(.*\{{$", l))
    j = next(k for k in range(i, len(lines)) if lines[k] == "}")
    fn = "\n".join(lines[i:j + 1])
    decls = []
    for l in lines[:i]:
        m = re.match(r"^(?:extern\s+)?\w[\w\s*]*?\b(\w+)\s*[(\[;]", l)
        if m and l.endswith(";") and m.group(1) != func and re.search(rf"\b{m.group(1)}\b", fn) and l not in decls:
            decls.append(l)
    os.makedirs(os.path.dirname(G_SRC), exist_ok=True)
    with open(G_SRC, "w") as f:
        f.write(bank.subst('/* family_remap.py --self-test exemplar (planted, deleted at teardown). */\n#include "common.h"\n\n'
                           + "\n".join(decls) + "\n\n" + fn + "\n", [(func, "remap_ex"), (callees[0], "remap_callee")]))
    # plant (C0054): the C definition -> INCLUDE_ASM of a generated .s of its retail words
    saved = {}
    words = bank.plant_words(prog, func, gv, int(r["end"], 16))
    _, seg_start, seg_vram = probe.yaml_layout(prog)
    off = seg_start + gv - seg_vram
    bank.put(saved, G_UNIT, "\n".join(lines[:i] + [f'INCLUDE_ASM("asm/{prog}/nonmatchings/{tu}", {func});']
                                      + lines[j + 1:]))
    bank.put(saved, f"asm/{prog}/nonmatchings/{tu}/{func}.s",
             ".set noat      /* allow manual use of $at */\n.set noreorder /* don't insert nops after branches */\n\n"
             f"nonmatching {func}, 0x{4 * len(words):X}\n\nglabel {func}\n"
             + "".join(f"    /* {off + 4 * k:X} {gv + 4 * k:08X} {w.to_bytes(4, 'little').hex().upper()} */  .word 0x{w:08X}\n"
                       for k, w in enumerate(words)) + f"endlabel {func}\n")
    return saved, fam, func, sib_t


def self_test():
    t0 = time.time()
    prog = G_SIB[0]
    corpus_out = [f"build/corpus/{n}.jsonl" for n in ("functions", "spans", "denominators")]
    pre_src, pre_reg, pre_bin = src_bytes(), open(bank.REGISTRY, "rb").read(), bank.sha1(bank.bin_out(prog))
    pre_corpus = {p: open(p, "rb").read() for p in corpus_out}
    saved, fails = {}, 0
    os.makedirs(SCRATCH, exist_ok=True)
    try:
        saved, fam, func, sib_t = control_g()
        if bank.rebuild(prog, "remap-selftest") or bank.sha1(bank.bin_out(prog)) != pre_bin:
            raise bank.Stop(0, f"plant rebuild of {prog} red (log {bank.LOGDIR}/remap-selftest.log)")
        if bank.sh([sys.executable, "tools/mmx6/corpus.py", "--all"], "remap-selftest"):
            raise bank.Stop(0, "corpus.py --all rc != 0 on the planted tree")
        r = propagate.corpus_rows()[G_SIB]
        if r["state"] != "include_asm":
            raise bank.Stop(0, f"planted {func} is {r['state']}, not include_asm, in the regenerated corpus")
        obj = probe.compile_obj(G_SRC, bank.makefile_triple())
        if obj is None:
            raise bank.Stop(0, f"{G_SRC} does not compile")
        ex_t = targets(relocs(obj, "remap_ex"))
        state, rung, cause, defines = remap_one(r, "remap_ex", ex_t, G_SRC, False, census.asm_index(), sib_t)
        good = state == "gated" and rung == "R5"
        print(f"control G {propagate.pv(G_SIB)} {func} {state} {rung}: {cause}")
        if good:
            family_row(fam, "_selftest:0x00000000", G_SRC, propagate.pv(G_SIB), defines)
            p = subprocess.run([sys.executable, "tools/mmx6/propagate.py", "--check"], capture_output=True, text=True)
            last = (p.stdout.strip().split("\n") or [""])[-1]
            print(f"control G propagate.py --check rc {p.returncode}: {last}")
            good = p.returncode == 0 and last.startswith("REGISTRY OK")
        fails += not good
        # control R: a reordered call pair must be refused at pair
        for name, calls in (("remap_ra", ("remap_a(1)", "remap_b(2)")), ("remap_rb", ("remap_b(2)", "remap_a(1)"))):
            with open(f"{SCRATCH}/{name}.c", "w") as f:
                f.write('#include "common.h"\n\nvoid remap_a(s32);\nvoid remap_b(s32);\n\n'
                        f"void {name}(void) {{\n" + "".join(f"    {c};\n" for c in calls) + "}\n")
        oa, ob = (probe.compile_obj(f"{SCRATCH}/{n}.c", bank.makefile_triple()) for n in ("remap_ra", "remap_rb"))
        if oa is None or ob is None:
            raise bank.Stop(0, "control R bodies do not compile")
        defines, why = pair(targets(relocs(oa, "remap_ra")), targets(relocs(ob, "remap_rb")), "remap_ra", "remap_rb")
        good = defines is None and why.startswith("reorder")
        print(f"control R remap_rb {'refused pair: ' + why if defines is None else 'gated pair'}")
        fails += not good
    except (Exception, SystemExit) as e:
        print(f"family_remap: self-test {type(e).__name__}: {e}")
        fails += 1
    finally:
        bank.restore(saved)
        put_tree(pre_src)
        shutil.rmtree(f"build/{os.path.dirname(G_SRC)}", ignore_errors=True)
        with open(bank.REGISTRY, "wb") as f:
            f.write(pre_reg)
        for p, b in pre_corpus.items():
            with open(p, "wb") as f:
                f.write(b)
        if bank.rebuild(prog, "remap-selftest-teardown"):
            print(f"family_remap: teardown rebuild of {prog} red")
            fails += 1
    for what, ok in (("src/", src_bytes() == pre_src), (bank.REGISTRY, open(bank.REGISTRY, "rb").read() == pre_reg),
                     (bank.bin_out(prog), os.path.exists(bank.bin_out(prog))
                      and bank.sha1(bank.bin_out(prog)) == pre_bin)):
        if not ok:
            print(f"family_remap: {what} differs from the pre-test value")
            fails += 1
    print(f"family_remap: self-test wall {time.time() - t0:.0f}s")
    if fails:
        print(f"REMAP SELF-TEST FAIL {fails}")
        return 1
    print("REMAP CONTROL OK")
    return 0


def main():
    os.chdir(os.path.join(HERE, "..", ".."))
    ap = argparse.ArgumentParser(description=__doc__.split("\n", 1)[0])
    ap.add_argument("key", nargs="?", metavar="family key")
    ap.add_argument("--dry-run", action="store_true")
    ap.add_argument("--self-test", action="store_true")
    a = ap.parse_args()
    if a.self_test:
        return self_test()
    if not a.key:
        ap.error("need <family key> [--dry-run], or --self-test")
    return run(a.key, a.dry_run)


if __name__ == "__main__":
    sys.exit(main())
