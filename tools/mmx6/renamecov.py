#!/usr/bin/env python3
"""renamecov.py -- rename coverage: every named symbol has a recorded basis; every `x4` basis row validates (stdlib).

  renamecov.py --all
      -> scans the real tree (config/symbols.*.txt, src/**/*.c|h, config/symbols/basis.tsv, config/x4/names.tsv,
         config/refs.toml) and prints the lines below.
  renamecov.py --self-test
      -> planted tree under .run/<phase>/renamecov-selftest/ (removed at the end): a clean tree passes; a symbols-file
         symbol with no basis, a src extern with no basis and an x4 row with a wrong name are each refused with the
         right why. Ends `RENAMECOV CONTROL OK` rc 0, or `RENAMECOV CONTROL FAIL <case>` rc 1.

Inputs
  symbols   config/symbols.<prog>.txt (prog = the filename middle): lines `name = 0xADDR; ...`; `//` lines skipped.
  src       src/**/*.c|h. prog = the path part after src/ or src/shared/ (src/probes and files directly in src/ ->
            SLUS_013.95). A src symbol = a column-0 file-scope declaration or definition with external linkage
            (brace depth 0, outside comments and preprocessor lines; not `static`, `typedef`, a bare struct/union/
            enum tag, a macro call or a body line). Its vram: the name in its prog's symbols file, else in
            SLUS_013.95's (overlays reference exe symbols, C0125), else `-` (reported under the path's prog).
  basis     config/symbols/basis.tsv: `#` header, TAB `prog vram name basis-kind basis-ref tier`.
  names     config/x4/names.tsv: no header, TAB `prog vram kind x6name alias tier scope votes basis`.
  pin       config/refs.toml, the `[[ref]]` named "mmx4": `ref`[:7].

Rules
  Exempt (neither counted nor refused): placeholders `(func|D)_<8 hex>[_tag]` (the `_tag` form is a link-only
  second name, e.g. func_800139A0_2p) and segment symbols `<prog>_<UPPER>_(START|END|SIZE|VRAM)`.
  Every other symbol (distinct prog, vram, name) counts and needs a basis row with the same prog and name (and the
  same vram for a symbols-file symbol; for a src symbol a row of its prog or SLUS_013.95 is enough): else `no basis`.
  Each `x4` basis row, against the names.tsv row at its (prog, vram) (docs/naming.md, the mirror of
  x4names.py --promote):
    no names row               no names.tsv row at (prog, vram)
    basis mismatch             the names basis minus its `x4 ` prefix is not a prefix of basis-ref
    pin <sha7> not <pin7>      basis-ref's `sozud/mmx4@<sha7>` is not the refs.toml pin (`-` when absent)
    tier <t>                   func needs gate, data needs slot, and the basis tier equals the names tier
    scope <s> without role     scope engine passes; scope object passes only with a `; role <evidence>` clause
    scope <s>                  any other scope
    name <n> not <alias>       without a role clause the name is the names alias (col 5)
    role name equals alias <a> with a role clause the name differs from the alias

Lines (sorted, stable)
  RENAMECOV REFUSE <prog> <vram> <name> <why>     one per fault
  RENAMES x4 <k> role <r> other <o>                basis rows: x4 without role, x4 with role, other kinds (not a gate)
  RENAMECOV OK <n> symbols                         rc 0
  RENAMECOV FAIL <m> refusals                      rc 1 (RENAMES still printed)
"""
import argparse
import os
import re
import shutil
import sys
import tomllib
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]


def phase_scratch(root):
    """The open phase's temp folder (as tools/run.sh: `# Phase <id>` line 1 of PHASE_PLAN.md), else .run (no plan)."""
    try:
        line = (root / "phase-ends/current/PHASE_PLAN.md").read_text().split("\n", 1)[0]
    except OSError:
        line = ""
    m = re.match(r"#\s*Phase\s+([A-Za-z0-9._-]+)", line)
    return root / ".run" if not m or m.group(1) in (".", "..") else root / ".run" / m.group(1)


EXE = "SLUS_013.95"
SELFTEST = phase_scratch(ROOT) / "renamecov-selftest"
PLACEHOLDER = re.compile(r"^(func|D)_[0-9A-Fa-f]{8}(_\w+)?$")
SYMLINE = re.compile(r"^\s*([A-Za-z_]\w*)\s*=\s*0x([0-9A-Fa-f]+)\s*;")
# a column-0 declaration or definition: type words, then the name (or `(*name)`), then ( [ = ; or ,
DECL = re.compile(r"^(?:extern\s+)?(?:const\s+|volatile\s+|signed\s+|unsigned\s+)*[A-Za-z_]\w*(?:[\w \*]*?)"
                  r"[\s\*]\(?\s*\*?\s*([A-Za-z_]\w*)\s*\)?\s*(\(|\[|=|;|,)")
NOT_DECL = re.compile(r"^(static|typedef|return|if|else|for|while|do|switch|case|goto|break|continue|default)\b"
                      r"|^(struct|union|enum)\s+\w*\s*(\{|;|$)")
ROLE = re.compile(r";\s*role\s+\S")
PIN = re.compile(r"sozud/mmx4@([0-9A-Fa-f]+)")


def segment(prog, name):
    return re.match(rf"^{re.escape(prog)}_[A-Z]+_(START|END|SIZE|VRAM)$", name) is not None


def exempt(prog, name):
    return PLACEHOLDER.match(name) is not None or segment(prog, name)


def read_tsv(path):
    """Rows of a TAB file, `#` lines skipped; [] when absent."""
    if not os.path.isfile(path):
        return []
    return [x.split("\t") for x in Path(path).read_text().splitlines() if x and not x.startswith("#")]


def read_symbols(symdir):
    """{prog: {name: vram}} from <symdir>/symbols.<prog>.txt."""
    out = {}
    for p in sorted(Path(symdir).glob("symbols.*.txt")):
        prog = p.name[len("symbols."):-len(".txt")]
        table = out.setdefault(prog, {})
        for line in p.read_text(errors="replace").splitlines():
            if line.lstrip().startswith("//"):
                continue
            m = SYMLINE.match(line)
            if m:
                table.setdefault(m.group(1), f"0x{int(m.group(2), 16):08X}")
    return out


def src_prog(rel):
    parts = rel.parts
    if parts and parts[0] == "shared":
        parts = parts[1:]
    if len(parts) < 2 or parts[0] == "probes":
        return EXE
    return parts[0]


def scrub(line, in_comment):
    """The line with comments, strings and char literals blanked; returns (text, still-in-block-comment)."""
    out, i, n = [], 0, len(line)
    while i < n:
        if in_comment:
            j = line.find("*/", i)
            if j < 0:
                return "".join(out), True
            out.append(" " * (j + 2 - i))
            i, in_comment = j + 2, False
        elif line.startswith("/*", i):
            in_comment = True
        elif line.startswith("//", i):
            break
        elif line[i] in "\"'":
            q, j = line[i], i + 1
            while j < n and line[j] != q:
                j += 2 if line[j] == "\\" else 1
            out.append(" " * (min(j + 1, n) - i))
            i = j + 1
        else:
            out.append(line[i])
            i += 1
    return "".join(out), in_comment


def src_names(text):
    """The external-linkage names declared or defined at file scope, column 0, in one C file's text."""
    names, depth, in_comment, cont = [], 0, False, False
    for raw in text.splitlines():
        if cont:  # a preprocessor continuation line
            cont = raw.rstrip().endswith("\\")
            continue
        col0 = depth == 0 and not in_comment and raw[:1] not in ("", " ", "\t", "}", "#", "/")
        if depth == 0 and not in_comment and raw.startswith("#"):
            cont = raw.rstrip().endswith("\\")
            continue
        line, in_comment = scrub(raw, in_comment)
        if col0 and not NOT_DECL.match(line):
            m = DECL.match(line)
            if m:
                names.append(m.group(1))
        depth = max(0, depth + line.count("{") - line.count("}"))
    return names


def collect(symdir, srcdir):
    """{(prog, vram, name)} of the counted (non-exempt) symbols, and the symbols table."""
    syms = read_symbols(symdir)
    found = set()
    for prog, table in syms.items():
        for name, vram in table.items():
            if not exempt(prog, name):
                found.add((prog, vram, name, "sym"))
    srcdir = Path(srcdir)
    for p in sorted(srcdir.rglob("*")):
        if p.suffix not in (".c", ".h") or not p.is_file():
            continue
        prog = src_prog(p.relative_to(srcdir))
        for name in src_names(p.read_text(errors="replace")):
            if exempt(prog, name):
                continue
            if name in syms.get(prog, {}):
                found.add((prog, syms[prog][name], name, "src"))
            elif name in syms.get(EXE, {}):
                found.add((EXE, syms[EXE][name], name, "src"))
            else:
                found.add((prog, "-", name, "src"))
    return found


def read_pin(refs):
    with open(refs, "rb") as f:
        rows = [r for r in tomllib.load(f).get("ref", []) if r.get("name") == "mmx4"]
    return rows[0]["ref"][:7] if rows else "-"


def check_x4(row, names, pin7):
    """The faults of one x4 basis row (list of why strings)."""
    prog, vram, name, _, ref, tier = (row + [""] * 6)[:6]
    nr = names.get((prog, vram))
    if nr is None:
        return ["no names row"]
    _, _, kind, _, alias, ntier, scope, _, nbasis = (nr + [""] * 9)[:9]
    why = []
    role = ROLE.search(ref) is not None
    if not nbasis.startswith("x4 ") or not ref.startswith(nbasis[3:]):
        why.append("basis mismatch")
    m = PIN.search(ref)
    sha7 = m.group(1)[:7] if m else "-"
    if sha7 != pin7:
        why.append(f"pin {sha7} not {pin7}")
    need = "slot" if kind == "data" else "gate"
    if tier != need or tier != ntier:
        why.append(f"tier {tier if tier != need else ntier}")
    if scope == "object" and not role:
        why.append(f"scope {scope} without role")
    elif scope not in ("engine", "object"):
        why.append(f"scope {scope}")
    if not role and name != alias:
        why.append(f"name {name} not {alias}")
    elif role and name == alias:
        why.append(f"role name equals alias {alias}")
    return why


def scan(symdir, srcdir, basis_path, names_path, refs_path):
    """Run every check; returns (refuse lines, renames line, n symbols)."""
    basis = read_tsv(basis_path)
    names = {(r[0], r[1]): r for r in read_tsv(names_path) if len(r) >= 2}
    pin7 = read_pin(refs_path)
    have = {(r[0], r[2]) for r in basis if len(r) >= 3}
    have_at = {(r[0], r[1], r[2]) for r in basis if len(r) >= 3}
    found = collect(symdir, srcdir)
    refuse = set()
    for prog, vram, name, origin in found:
        if origin == "sym":
            ok = (prog, vram, name) in have_at
        else:
            ok = (prog, name) in have or (EXE, name) in have
        if not ok:
            refuse.add(f"RENAMECOV REFUSE {prog} {vram} {name} no basis")
    k = r = o = 0
    for row in basis:
        if len(row) < 4 or row[3] != "x4":
            o += 1
            continue
        if ROLE.search(row[4] if len(row) > 4 else ""):
            r += 1
        else:
            k += 1
        for why in check_x4(row, names, pin7):
            refuse.add(f"RENAMECOV REFUSE {row[0]} {row[1]} {row[2]} {why}")
    n = len({(p, v, nm) for p, v, nm, _ in found})
    return sorted(refuse), f"RENAMES x4 {k} role {r} other {o}", n


def report(refuse, renames, n):
    for line in refuse:
        print(line)
    print(renames)
    if refuse:
        print(f"RENAMECOV FAIL {len(refuse)} refusals")
        return 1
    print(f"RENAMECOV OK {n} symbols")
    return 0


def real():
    return scan(ROOT / "config", ROOT / "src", ROOT / "config/symbols/basis.tsv", ROOT / "config/x4/names.tsv",
                ROOT / "config/refs.toml")


# ---- self-test: planted tree, never the real files (C0054) ----------------------------------------------------------

PIN_FULL = "abcdef0123456789abcdef0123456789abcdef01"
NB = "x4 exact 0123456789ab sozud/mmx4@abcdef0 src/main/a.c:do_thing"


def plant(base, extra_sym="", extra_src="", alias="do_thing"):
    if base.exists():
        shutil.rmtree(base)
    (base / "config/symbols").mkdir(parents=True)
    (base / "src/shared/rock_01").mkdir(parents=True)
    (base / "config/symbols.SLUS_013.95.txt").write_text(
        "// header\n// basis: hand\n__start = 0x80054AD8;\nfunc_80010000 = 0x80010000; // type:func\n"
        "do_thing = 0x80010010;\n" + extra_sym)
    (base / "config/symbols.rock_01.txt").write_text("D_801E0000_r = 0x801E0000;\n")
    (base / "src/shared/rock_01/func_801E0004.c").write_text(
        "/* extern int not_me; */\n#define M(x) \\\n    int nor_me;\n"
        "extern u8 rock_01_RODATA_START[];\nextern s32 D_801E0000_r[];\nstatic int hidden;\n"
        "typedef struct Foo { int a; } Foo;\nstruct Bar;\nvoid do_thing(void);\n" + extra_src +
        "void func_801E0004(void) {\nint inner;\n}\n")
    head = "# prog\tvram\tname\tbasis-kind\tbasis-ref\ttier\n"
    (base / "config/symbols/basis.tsv").write_text(
        head + f"SLUS_013.95\t0x80010010\tdo_thing\tx4\t{NB[3:]}; corroborator hand community\tgate\n"
        "SLUS_013.95\t0x80054AD8\t__start\tcommunity\tcrt0\t-\n")
    (base / "names.tsv").write_text(f"SLUS_013.95\t0x80010010\tfunc\tfunc_80010010\t{alias}\tgate\tengine\t-\t{NB}\n")
    (base / "refs.toml").write_text(f'[[ref]]\nname = "other"\nref = "1111111"\n\n[[ref]]\nname = "mmx4"\n'
                                    f'ref = "{PIN_FULL}"\n')


def selftest():
    cases = [
        ("clean", {}, None),
        ("sym-no-basis", {"extra_sym": "g_Planted = 0x80020000;\n"},
         "RENAMECOV REFUSE SLUS_013.95 0x80020000 g_Planted no basis"),
        ("src-no-basis", {"extra_src": "extern s32 planted_extern;\n"},
         "RENAMECOV REFUSE rock_01 - planted_extern no basis"),
        ("x4-wrong-name", {"alias": "other_thing"},
         "RENAMECOV REFUSE SLUS_013.95 0x80010010 do_thing name do_thing not other_thing"),
    ]
    rc = 0
    try:
        for case, kw, want in cases:
            plant(SELFTEST, **kw)
            refuse, renames, n = scan(SELFTEST / "config", SELFTEST / "src", SELFTEST / "config/symbols/basis.tsv",
                                      SELFTEST / "names.tsv", SELFTEST / "refs.toml")
            ok = renames == "RENAMES x4 1 role 0 other 1"
            ok = ok and (refuse == [] and n == 2 if want is None else refuse == [want])
            if not ok:
                print(f"RENAMECOV CONTROL FAIL {case}")
                for line in refuse + [renames, f"n {n}"]:
                    print(f"  {line}")
                rc = 1
    finally:
        shutil.rmtree(SELFTEST, ignore_errors=True)
    if rc == 0:
        print("RENAMECOV CONTROL OK")
    return rc


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    g = ap.add_mutually_exclusive_group(required=True)
    g.add_argument("--all", action="store_true", help="scan the real tree")
    g.add_argument("--self-test", action="store_true", help="planted controls")
    a = ap.parse_args()
    return selftest() if a.self_test else report(*real())


if __name__ == "__main__":
    sys.exit(main())
