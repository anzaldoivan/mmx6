"""priorart.py -- prior art per residue function: X5 twin, mmx4 partner, prototype, PC port (stdlib; 3.0 T11).

    priorart.py --build   -> campaign/priorart.tsv (private; names, addresses, hashes, paths only, G12)
    priorart.py --check   rc 0 iff a rebuild equals the tracked campaign/priorart.tsv
    priorart.py --count   markdown table: per blocker class, rows with each source and with any source

Rows: every campaign/ledger.tsv game row (col7 != `vendor`), sorted (prog, vram). Columns
`prog vram func blocker x5 x4 proto pc`, `-` when none; `#` header lines name each input and its commit.
- x5: `<c|asm>:<X5 unit>:<vram>:<name>`, `;`-joined, c first then (unit, vram). Sources: the X6 row's body-hash group
  in mmx5-dev docs/oracle/x6-twins.tsv at HEAD, campaign/x4/x5-leads.tsv (sig leads), docs/leads/x5.tsv code rows.
  C at mmx5-dev HEAD (READ ONLY, `git show`/`ls-tree HEAD`; working tree ignored; the twins state column is stale):
  (unit, vram) is c iff a tracked src/slus/<stem>.c or src/rockx5/<stem>.c exists (one file per c segment of
  config/splat.<image>.yaml) with stem func_<VRAM> (slus) or func_|D_<VRAM>_<ovlNN>, or a config/names.tsv function
  new_name whose old_name is func_<VRAM> (slus renames), and the file has no INCLUDE_ASM line. Name: names.tsv rename.
- x4: `<c|asm>:<mmx4 path>:<function>` from campaign/x4/partners.tsv; c iff at the config/refs.toml mmx4 pin the file
  defines the function as C (a top-level definition line, no INCLUDE_ASM of it). Clone: .run/mmx4 (`mx.sh pull`);
  refused when it lacks the pin. No fetch.
- proto: `<build>:<state>` `,`-joined sorted unique, docs/leads/proto.tsv rows whose retail = `<prog>:0x<vram>`.
- pc: `0x<x86>` `,`-joined, docs/leads/pc-port.md `## Function pairing` bullets (`` `name` = x86 0xA ``) and its
  "Callee twins found on the way" lists (`name 0xA`), all SLUS_013.95; name -> vram by the ledger func column,
  `func_XXXXXXXX` or a bare 0x8... address.
"""
import argparse
import re
import subprocess
import sys
import tomllib
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
MMX5 = ROOT.parent / "mmx5-dev"
MMX4 = ROOT / ".run" / "mmx4"
OUT = ROOT / "campaign" / "priorart.tsv"
LEDGER = "campaign/ledger.tsv"
X5_LEADS = "campaign/x4/x5-leads.tsv"
PARTNERS = "campaign/x4/partners.tsv"
X5_TSV = "docs/leads/x5.tsv"
PROTO = "docs/leads/proto.tsv"
PCPORT = "docs/leads/pc-port.md"
TWINS = "docs/oracle/x6-twins.tsv"  # in mmx5-dev
EXE = "SLUS_013.95"


def git(repo, *args):
    r = subprocess.run(["git", "-C", str(repo), *args], capture_output=True, text=True)
    if r.returncode:
        sys.exit(f"PRIORART: git -C {repo} {' '.join(args)} failed: {r.stderr.strip()}")
    return r.stdout


def rows_tsv(path):
    return [ln.split("\t") for ln in (ROOT / path).read_text().splitlines() if ln and not ln.startswith("#")]


def key(prog, vram):
    return prog, int(vram, 16)


def ledger_rows():
    out = []
    for c in rows_tsv(LEDGER):
        if c[6] != "vendor":
            out.append((c[0], int(c[1], 16), c[2], c[6]))
    out.sort(key=lambda r: (r[0], r[1]))
    return out


# ---- X5 (mmx5-dev HEAD) ----
def x5_state(head):
    files = git(MMX5, "ls-tree", "-r", "--name-only", head, "src/slus", "src/rockx5").split()
    names = {}
    for ln in git(MMX5, "show", f"{head}:config/names.tsv").splitlines()[1:]:
        c = ln.split("\t")
        if len(c) >= 5 and c[0] == "function" and c[1] == "slus":
            names[c[3]] = c[4]
    renamed = {v: k for k, v in names.items()}
    asm_files = set(git(MMX5, "grep", "-l", "INCLUDE_ASM", head, "--", "src/slus", "src/rockx5").split())
    asm_files = {f.split(":", 1)[1] for f in asm_files}
    cset = set()
    for f in files:
        if not f.endswith(".c") or f in asm_files:
            continue
        stem = Path(f).stem
        stem = renamed.get(stem, stem)
        m = re.fullmatch(r"(?:func|D)_([0-9A-F]{8})(?:_(ovl\d+))?", stem)
        if not m:
            continue
        if f.startswith("src/slus/") and not m.group(2):
            cset.add(("slus", int(m.group(1), 16)))
        elif f.startswith("src/rockx5/") and m.group(2):
            cset.add((m.group(2), int(m.group(1), 16)))
    return cset, names


def x5_name(unit, vram, name, names):
    if name in ("", "-"):
        name = f"func_{vram:08X}" if unit == "slus" else f"func_{vram:08X}_{unit}"
    return names.get(name, name)


def x5_map(head, cset, names):
    """(prog, vram) -> {(unit, vram): name}; twins: (prog, vram) -> same."""
    twins = {}
    groups = {}
    for ln in git(MMX5, "show", f"{head}:{TWINS}").splitlines():
        c = ln.split("\t")
        if len(c) < 7:
            continue
        groups.setdefault(c[0], []).append(c)
    for rows in groups.values():
        x5 = [(r[3], int(r[4], 16), r[5]) for r in rows if r[2] == "X5"]
        for r in rows:
            if r[2] == "X6":
                d = twins.setdefault(key(r[3], r[4]), {})
                for u, v, n in x5:
                    d[(u, v)] = x5_name(u, v, n, names)
    allm = {k: dict(v) for k, v in twins.items()}
    for c in rows_tsv(X5_LEADS):
        u, v = c[4], int(c[5], 16)
        allm.setdefault(key(c[0], c[1]), {})[(u, v)] = x5_name(u, v, c[6], names)
    for c in rows_tsv(X5_TSV)[1:]:
        if len(c) < 4 or not c[3].startswith("code"):
            continue
        a = re.fullmatch(r"(?:(\S+) )?0x([0-9A-F]{8})", c[1])
        b = re.match(r"X5 (?:(slus|ovl\d+) )?(?:0x([0-9A-F]{8})|func_([0-9A-F]{8})(?:_(ovl\d+))?)", c[2])
        if not a or not b:
            continue
        u = b.group(1) or b.group(4) or "slus"
        v = int(b.group(2) or b.group(3), 16)
        allm.setdefault(key(a.group(1) or EXE, a.group(2)), {})[(u, v)] = x5_name(u, v, "", names)
    return allm, twins


def x5_value(d, cset):
    if not d:
        return "-"
    items = sorted(d.items(), key=lambda kv: (kv[0] not in cset, kv[0]))
    return ";".join(f"{'c' if k in cset else 'asm'}:{k[0]}:0x{k[1]:08X}:{n}" for k, n in items)


# ---- X4 (mmx4 pin) ----
def x4_pin():
    refs = tomllib.loads((ROOT / "config/refs.toml").read_text())
    pin = next(r["ref"] for r in refs["ref"] if r["name"] == "mmx4")
    r = subprocess.run(["git", "-C", str(MMX4), "cat-file", "-e", f"{pin}^{{commit}}"], capture_output=True)
    if r.returncode:
        sys.exit(f"PRIORART: {MMX4} lacks the mmx4 pin {pin} (bash tools/docker/mx.sh pull .run/mmx4); refused")
    return pin


def x4_map(pin):
    src = {}
    out = {}
    for c in rows_tsv(PARTNERS):
        path, fn = c[5], c[6]
        if path not in src:
            src[path] = git(MMX4, "show", f"{pin}:{path}")
        text = src[path]
        f = re.escape(fn)
        is_asm = re.search(rf"^\s*INCLUDE_ASM\([^)]*\b{f}\s*\)", text, re.M)
        is_def = re.search(rf"^[A-Za-z_][^;=\n]*\b{f}\s*\([^;]*$", text, re.M)
        out[key(c[0], c[1])] = f"{'c' if is_def and not is_asm else 'asm'}:{path}:{fn}"
    return out


# ---- proto, pc ----
def proto_map():
    out = {}
    for c in rows_tsv(PROTO):
        if c[3] != "-":
            p, v = c[3].split(":")
            out.setdefault(key(p, v), set()).add(f"{c[0]}:{c[4]}")
    return {k: ",".join(sorted(v)) for k, v in out.items()}


def pc_map(ledger):
    text = (ROOT / PCPORT).read_text()
    sec = text.split("\n## Function pairing", 1)[1].split("\n## ", 1)[0]
    byname = {f: v for p, v, f, _ in ledger if p == EXE}
    pairs = re.findall(r"`(\w+)` = x86 (0x[0-9A-F]+)", sec)
    for m in re.finditer(r"Callee twins found on the way:(.*?)(?=\n\s*- |\Z)", sec, re.S):
        body = m.group(1).split(". Log:")[0]
        pairs += re.findall(r"(\w+)\s+(0x[0-9A-F]+)", body)
    out = {}
    for name, x86 in pairs:
        if name in byname:
            v = byname[name]
        elif re.fullmatch(r"func_[0-9A-F]{8}", name):
            v = int(name[5:], 16)
        elif re.fullmatch(r"0x8[0-9A-F]{7}", name):
            v = int(name, 16)
        else:
            continue
        out.setdefault((EXE, v), set()).add(x86)
    return {k: ",".join(sorted(s, key=lambda a: int(a, 16))) for k, s in out.items()}


def blob(path):
    return git(ROOT, "hash-object", path).strip()[:7]


def build():
    ledger = ledger_rows()
    head = git(MMX5, "rev-parse", "HEAD").strip()
    pin = x4_pin()
    cset, names = x5_state(head)
    x5m, twins = x5_map(head, cset, names)
    x4m, pm, pcm = x4_map(pin), proto_map(), pc_map(ledger)
    lines = [
        "# campaign/priorart.tsv -- generated by tools/mmx6/priorart.py --build; do not edit (names, addresses, paths only)",
        f"# x5: mmx5-dev {TWINS} + C state at mmx5-dev HEAD {head}",
        f"# x4: mmx4 pin {pin} via {PARTNERS} blob {blob(PARTNERS)}",
        "# inputs (blob ids): " + " ".join(f"{p}@{blob(p)}" for p in (LEDGER, X5_LEADS, X5_TSV, PROTO, PCPORT)),
        "# prog\tvram\tfunc\tblocker\tx5\tx4\tproto\tpc",
    ]
    rows = []
    for p, v, f, b in ledger:
        k = (p, v)
        r = [p, f"0x{v:08X}", f, b, x5_value(x5m.get(k, {}), cset), x4m.get(k, "-"), pm.get(k, "-"), pcm.get(k, "-")]
        rows.append(r)
        lines.append("\t".join(r))
    return "\n".join(lines) + "\n", rows, head, twins, cset


def bclass(b):
    return "member-of" if b.startswith("member-of:") else b


def count(rows):
    cols = ["n", "x5 twin", "x5 C", "x4 partner", "x4 C", "proto", "pc", "any"]
    tab = {}
    for r in rows:
        x5, x4, pr, pc = r[4], r[5], r[6], r[7]
        x5c = any(e.startswith("c:") for e in x5.split(";"))
        x4c = x4.startswith("c:")
        v = [1, x5 != "-", x5c, x4 != "-", x4c, pr != "-", pc != "-", x5c or x4c or pr != "-" or pc != "-"]
        for cl in (bclass(r[3]), "total"):
            t = tab.setdefault(cl, [0] * len(cols))
            for i, x in enumerate(v):
                t[i] += int(x)
    out = ["| blocker | " + " | ".join(cols) + " |", "|---" * (len(cols) + 1) + "|"]
    for cl in sorted(k for k in tab if k != "total") + ["total"]:
        out.append(f"| {cl} | " + " | ".join(str(x) for x in tab[cl]) + " |")
    return "\n".join(out)


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    g = ap.add_mutually_exclusive_group(required=True)
    g.add_argument("--build", action="store_true")
    g.add_argument("--check", action="store_true")
    g.add_argument("--count", action="store_true")
    a = ap.parse_args()
    if a.count:
        rows = [ln.split("\t") for ln in OUT.read_text().splitlines() if ln and not ln.startswith("#")]
        print(count(rows))
        return 0
    text, rows, *_ = build()
    if a.build:
        OUT.write_text(text)
        print(f"PRIORART: {len(rows)} rows -> {OUT.relative_to(ROOT)}")
        return 0
    ok = OUT.exists() and OUT.read_text() == text
    print(f"PRIORART CHECK {'OK' if ok else 'STALE'} {len(rows)} rows")
    return 0 if ok else 1


if __name__ == "__main__":
    sys.exit(main())
