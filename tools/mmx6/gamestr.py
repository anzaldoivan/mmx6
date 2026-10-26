#!/usr/bin/env python3
"""gamestr.py -- the M16 game-string gate: short game strings in glossed comments, dialogue in an ignored sidecar.

  gamestr.py check [paths]
      -> scans the git-tracked text files under src/, include/ and docs/ (or the given files and folders) and prints
         `GAMESTR FAIL <path>:<line>: <reason>` per refusal, then `GAMESTR OK <n> files, <v> verbatim, <k> key` rc 0
         or `GAMESTR FAIL <n> refusals` rc 1.
  gamestr.py sidecar [--prog P]
      -> refs/leads/strings/<prog>.tsv (ignored) for each retail program, every string, through the one writer
         (tools/mmx6/imgadapter.py strings, which also writes a proto's <build>.<prog>.tsv). Columns `vram sha1 bytes
         class text`; class short | dialogue | story | table. check and render read the retail sidecars only.
  gamestr.py render <src>...
      -> build/strings/<same relpath> (ignored), each key comment expanded to the verbatim form from the sidecar.
  gamestr.py --self-test
      -> planted tree under .run/<phase>/gamestr-selftest/ (removed at the end): one file per refusal plus a passing
         tree. Ends `GAMESTR CONTROL OK` rc 0, or `GAMESTR CONTROL FAIL <case>` rc 1.

Forms (one line each; `//` or a `/* ... */` closed on the same line)
  verbatim  // str 0x<8 HEX> "<game text>" = "<English gloss>"     text: \\" and \\\\ escapes, <= 64 bytes of UTF-8
  key       // str 0x<8 HEX> sha1=<40 hex> = "<English gloss>"     sha1 of the original Shift-JIS bytes
Refusals: text over 64 bytes; a text quote not closed on its line; a missing, empty or non-ASCII gloss; verbatim
comments on consecutive lines (a dialogue block); a verbatim address of sidecar class dialogue, story or table (only
when a sidecar exists); in src/ and include/ any non-ASCII byte outside a verbatim text, in docs/ any Japanese script.
Allowlist: src/NOTICE.md and src/README.md are skipped; in docs/glossary.md the cells of a table column headed
`Japanese` may hold Japanese text (each <= 64 bytes). docs/strings.md is the public description.
"""
import argparse
import re
import shutil
import subprocess
import sys
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


SELFTEST = phase_scratch(ROOT) / "gamestr-selftest"
SIDECAR = "refs/leads/strings"
STRNAMES = "config/oracle.strnames.tsv"
RENDER = "build/strings"
SCOPE = ("src", "include", "docs")
SKIP = {"src/NOTICE.md", "src/README.md"}
GLOSSARY = "docs/glossary.md"
LIMIT = 64
BLOCKED = {"dialogue", "story", "table"}
HEADER = "vram\tsha1\tbytes\tclass\ttext"

ANY = re.compile(r"(?://|/\*)\s*str\s+0x")
VERBATIM = re.compile(r'(//|/\*)\s*str 0x([0-9A-F]{8}) "((?:[^"\\]|\\.)*)" = "([^"]*)"\s*(\*/)?')
KEY = re.compile(r'(//|/\*)\s*str 0x([0-9A-F]{8}) sha1=([0-9a-f]{40}) = "([^"]*)"\s*(\*/)?')
HEAD = re.compile(r'(?://|/\*)\s*str 0x[0-9A-F]{8} (?:"((?:[^"\\]|\\.)*)("?)|sha1=[0-9a-f]{40})(.*)')
PROTO = re.compile(r"proto-[a-z0-9-]+\.")   # a proto sidecar: <build>.<prog>.tsv
JAPANESE = re.compile("[　-〿぀-ヿ㐀-䶿一-鿿豈-﫿＀-￯]")


def unescape(t):
    return re.sub(r'\\(["\\])', r"\1", t)


def gloss_ok(g):
    return bool(g.strip()) and all(0x20 <= ord(c) <= 0x7E for c in g)


def retail_sidecars(root):
    """The retail sidecars: refs/leads/strings/<prog>.tsv, not a proto's <build>.<prog>.tsv (imgadapter.py strings)."""
    return [p for p in sorted((root / SIDECAR).glob("*.tsv")) if not PROTO.match(p.name)]


def blocked_vrams(root):
    """{vram: class} of the retail sidecar rows whose class is dialogue, story or table; {} when no sidecar exists."""
    out = {}
    for p in retail_sidecars(root):
        for line in p.read_text(encoding="utf-8").splitlines()[1:]:
            c = line.split("\t")
            if len(c) >= 4 and c[3] in BLOCKED and c[0].startswith("0x"):
                out[int(c[0], 16)] = c[3]
    return out


def str_comment(line):
    """(kind, match, reasons): kind verbatim | key | None (no `str 0x` comment) | bad."""
    if not ANY.search(line):
        return None, None, []
    m = VERBATIM.search(line)
    kind = "verbatim"
    if not m:
        m, kind = KEY.search(line), "key"
    if m and (m.group(1) == "//" or m.group(5)):
        why = []
        if kind == "verbatim" and len(unescape(m.group(3)).encode("utf-8")) > LIMIT:
            why.append(f"verbatim text over {LIMIT} bytes")
        if not gloss_ok(m.group(4)):
            why.append("non-ASCII gloss" if m.group(4).strip() else "empty gloss")
        return kind, m, why
    h = HEAD.search(line)
    if not h:
        return "bad", None, ["malformed str comment"]
    if h.group(1) is not None and not h.group(2):
        return "bad", None, ["text quote not closed on its line (spans lines)"]
    rest = h.group(3)
    if '= "' not in rest:
        return "bad", None, ["missing gloss"]
    if m and m.group(1) == "/*":
        return "bad", None, ["/* comment not closed on its line"]
    return "bad", None, ["malformed str comment"]


def glossary_cells(lines):
    """{line index: [(start, end) of the Japanese column's cell]} of the markdown tables of lines."""
    out, col, i = {}, None, 0
    while i < len(lines):
        s = lines[i].strip()
        if not s.startswith("|"):
            col = None
            i += 1
            continue
        if col is None:
            cells = [c.strip() for c in s.strip("|").split("|")]
            col = cells.index("Japanese") if "Japanese" in cells else -1
            i += 2  # the header and its separator
            continue
        if col >= 0:
            bars = [k for k, ch in enumerate(lines[i]) if ch == "|"]
            if len(bars) > col + 1:
                out[i] = (bars[col] + 1, bars[col + 1])
        i += 1
    return out


def scan_file(rel, text, blocked):
    """([(line, reason)], verbatim count, key count) of one text file."""
    docs = rel.startswith("docs/")
    lines = text.split("\n")
    cells = glossary_cells(lines) if rel == GLOSSARY else {}
    fails, nv, nk, prev = [], 0, 0, False
    for i, line in enumerate(lines):
        n = i + 1
        kind, m, why = str_comment(line)
        fails += [(n, w) for w in why]
        masked = line
        if kind == "verbatim":
            nv += 1
            if prev:
                fails.append((n, "verbatim comments on consecutive lines (dialogue block)"))
            v = int(m.group(2), 16)
            if v in blocked:
                fails.append((n, f"0x{v:08X} is sidecar class {blocked[v]}"))
            masked = line[:m.start(3)] + line[m.end(3):]
        elif kind == "key":
            nk += 1
        prev = kind == "verbatim"
        if i in cells:
            a, b = cells[i]
            if len(line[a:b].strip().encode("utf-8")) > LIMIT:
                fails.append((n, f"glossary Japanese cell over {LIMIT} bytes"))
            masked = masked[:a] + masked[b:] if kind != "verbatim" else masked
        bad = JAPANESE.search(masked) if docs else re.search(r"[^\x00-\x7f]", masked)
        if bad:
            fails.append((n, f"{'Japanese script' if docs else 'non-ASCII'} U+{ord(bad.group()):04X} outside a form"))
    return fails, nv, nk


def tracked(root):
    out = subprocess.run(["git", "-C", str(root), "ls-files", "-z", "--", *SCOPE], capture_output=True, check=True)
    return [root / p for p in out.stdout.decode().split("\0") if p]


def expand(paths):
    out = []
    for p in paths:
        p = Path(p).resolve()
        out += sorted(f for f in p.rglob("*") if f.is_file()) if p.is_dir() else [p]
    return out


def relpath(f, root):
    try:
        return f.resolve().relative_to(root.resolve()).as_posix()
    except ValueError:
        return f.as_posix()


def check(root, files):
    """(refusal lines, summary line, rc) of files (absolute paths) under root."""
    blocked = blocked_vrams(root)
    out, n, nv, nk = [], 0, 0, 0
    for f in files:
        rel = relpath(f, root)
        if rel in SKIP or not f.is_file():
            continue
        b = f.read_bytes()
        try:
            text = b.decode("utf-8")
        except UnicodeDecodeError:
            continue
        if "\0" in text:
            continue
        n += 1
        fails, v, k = scan_file(rel, text, blocked)
        nv, nk = nv + v, nk + k
        out += [f"GAMESTR FAIL {rel}:{ln}: {why}" for ln, why in fails]
    if out:
        return out, f"GAMESTR FAIL {len(out)} refusals", 1
    return out, f"GAMESTR OK {n} files, {nv} verbatim, {nk} key", 0


def sidecar(prog):
    """Write refs/leads/strings/<prog>.tsv through imgadapter.py's one writer; print the counts and the oracle key
    check (each retail row of config/oracle.strnames.tsv has a string of its unit or the executable with that key)."""
    sys.path.insert(0, str(ROOT / "tools" / "mmx6"))
    import imgadapter
    ss = imgadapter.retail_strings(ROOT)[0]
    rows = [ln.split("\t") for ln in (ROOT / STRNAMES).read_text().splitlines() if ln and not ln.startswith("#")]
    rows = [r for r in rows if r[8] == "retail" and (prog is None or r[0] == prog)]
    keys = {}
    for s in ss:
        keys.setdefault(s["prog"], set()).add(s["sha1"][:12])
    exe = ss[0]["prog"] if ss else None
    miss = [(r[0], int(r[3], 16), r[4]) for r in rows if r[4] not in keys.get(r[0], set()) | keys.get(exe, set())]
    got = imgadapter.write_sidecars(ss, prog=prog, root=ROOT)
    for u, n in got.items():
        print(f"GAMESTR SIDECAR {u} {n} rows")
    for u, c, k in sorted(set(miss)):
        print(f"GAMESTR KEY MISMATCH {u} 0x{c:08X} {k}: no string of that code has sha1 prefix {k}")
    print(f"GAMESTR SIDECAR OK {sum(got.values())} rows, {len(rows)} oracle rows, key = sha1[:12] on "
          f"{len(rows) - len(miss)}/{len(rows)}")
    return 1 if miss else 0


def render(srcs):
    files = retail_sidecars(ROOT)
    if not files:
        print("GAMESTR FAIL no sidecar (run gamestr.py sidecar)")
        return 1
    text = {}
    for p in files:
        for line in p.read_text(encoding="utf-8").splitlines()[1:]:
            c = line.split("\t", 4)
            text[(c[0], c[1])] = c[4]
    rc, nk = 0, 0
    for f in expand(srcs):
        rel = relpath(f, ROOT)
        lines, bad = f.read_text(encoding="utf-8").split("\n"), False
        for i, line in enumerate(lines):
            m = KEY.search(line)
            if not m:
                continue
            t = text.get((f"0x{m.group(2)}", m.group(3)))
            if t is None:
                print(f"GAMESTR FAIL {rel}:{i + 1}: unknown key 0x{m.group(2)} sha1={m.group(3)}")
                rc, bad = 1, True
                continue
            q = t.replace("\\", "\\\\").replace('"', '\\"')
            lines[i] = line[:m.start(3) - 5] + f'"{q}"' + line[m.end(3):]
            nk += 1
        if not bad:
            out = ROOT / RENDER / rel
            out.parent.mkdir(parents=True, exist_ok=True)
            out.write_text("\n".join(lines), encoding="utf-8")
    print(f"GAMESTR RENDER {'OK' if rc == 0 else 'FAIL'} {nk} keys")
    return rc


KANA = "テスト"  # invented fixture text, no game string
SHA = "0" * 40


def plant(base, files):
    if base.exists():
        shutil.rmtree(base)
    for rel, body in files.items():
        (base / rel).parent.mkdir(parents=True, exist_ok=True)
        (base / rel).write_text(body, encoding="utf-8")


def selftest():
    good = {
        "src/a/ok.c": f'int x; // str 0x80010000 "{KANA}" = "test"\nint y;\n'
                      f'/* str 0x80010004 sha1={SHA} = "a key" */\nint z; /* str 0x80010008 "A\\"B" = "ab" */\n',
        "src/README.md": f"{KANA} is allowed here\n",
        "docs/ok.md": "An em-dash — and an arrow → stay legal.\n",
        "docs/glossary.md": f"| English | Japanese |\n|---|---|\n| test | {KANA} |\n",
    }
    cases = [
        ("pass", {}, []),
        ("over-64", {"src/b.c": f'// str 0x80010000 "{KANA * 8}" = "long"\n'},
         ["src/b.c:1: verbatim text over 64 bytes"]),
        ("spans-lines", {"src/b.c": '// str 0x80010000 "ABC\n'},
         ["src/b.c:1: text quote not closed on its line (spans lines)"]),
        ("no-gloss", {"src/b.c": '// str 0x80010000 "ABC"\n'}, ["src/b.c:1: missing gloss"]),
        ("empty-gloss", {"src/b.c": f'// str 0x80010000 sha1={SHA} = ""\n'}, ["src/b.c:1: empty gloss"]),
        ("ascii-gloss", {"src/b.c": f'// str 0x80010000 "A" = "{KANA}"\n'},
         ["src/b.c:1: non-ASCII gloss", "src/b.c:1: non-ASCII U+30C6 outside a form"]),
        ("dialogue", {"src/b.c": '// str 0x80010000 "A" = "a"\n// str 0x80010004 "B" = "b"\n'},
         ["src/b.c:2: verbatim comments on consecutive lines (dialogue block)"]),
        ("sidecar-class", {"src/b.c": '// str 0x80010000 "A" = "a"\n',
                           f"{SIDECAR}/u.tsv": f"{HEADER}\n0x80010000\t{SHA}\t1\tdialogue\tA\n"},
         ["src/b.c:1: 0x80010000 is sidecar class dialogue"]),
        ("src-non-ascii", {"include/b.h": "int x; // —\n"}, ["include/b.h:1: non-ASCII U+2014 outside a form"]),
        ("docs-japanese", {"docs/b.md": f"Say {KANA}.\n"}, ["docs/b.md:1: Japanese script U+30C6 outside a form"]),
        ("glossary-cell", {"docs/glossary.md": f"| English | Japanese |\n|---|---|\n| t | {KANA * 8} |\n"},
         ["docs/glossary.md:3: glossary Japanese cell over 64 bytes"]),
        ("glossary-column", {"docs/glossary.md": f"| English | Japanese |\n|---|---|\n| {KANA} | t |\n"},
         ["docs/glossary.md:3: Japanese script U+30C6 outside a form"]),
    ]
    rc = 0
    try:
        for case, extra, want in cases:
            files = extra if want else good
            plant(SELFTEST, files)
            fails, summary, code = check(SELFTEST, expand([SELFTEST]))
            got = [f[len("GAMESTR FAIL "):] for f in fails]
            ok = got == want and code == (1 if want else 0)
            if case == "pass":
                ok = ok and summary == "GAMESTR OK 3 files, 2 verbatim, 1 key"
            if not ok:
                print(f"GAMESTR CONTROL FAIL {case}")
                for line in fails + [summary]:
                    print(f"  {line}")
                rc = 1
    finally:
        shutil.rmtree(SELFTEST, ignore_errors=True)
    if rc == 0:
        print("GAMESTR CONTROL OK")
    return rc


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__.split("\n", 1)[0])
    ap.add_argument("--self-test", action="store_true", help="planted controls; ends GAMESTR CONTROL OK")
    sub = ap.add_subparsers(dest="cmd")
    c = sub.add_parser("check", help="scan the tracked text files (or the given paths)")
    c.add_argument("paths", nargs="*")
    s = sub.add_parser("sidecar", help="write refs/leads/strings/<prog>.tsv (imgadapter.py's writer)")
    s.add_argument("--prog", help="one unit of config/oracle.strnames.tsv")
    r = sub.add_parser("render", help="expand key comments into build/strings/<path>")
    r.add_argument("src", nargs="+")
    a = ap.parse_args(argv)
    if a.self_test:
        return selftest()
    if a.cmd == "check":
        fails, summary, rc = check(ROOT, expand(a.paths) if a.paths else tracked(ROOT))
        for line in fails + [summary]:
            print(line)
        return rc
    if a.cmd == "sidecar":
        return sidecar(a.prog)
    if a.cmd == "render":
        return render(a.src)
    ap.print_help()
    return 2


if __name__ == "__main__":
    sys.exit(main())
