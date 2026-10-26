"""protodiff.py -- the functions of each prototype build that retail lacks or changed (stdlib).

    protodiff.py build [--id ID]...
        -> docs/leads/proto.tsv (tracked: keys, addresses, counts and our words only) and build/leads/retail-debug.tsv
           (ignored). One line per build: `PROTODIFF <id>: absent N changed M moved X same K`, and
           `PROTODIFF <id>: skipped N stub programs: rock_NN ...` when it has any. Builds: every
           config/oracle.<id>.functions.tsv, its files in extracted/<id>/ (its executable: the non-archive
           build_file of that table). proto.tsv line 3: `# skipped (4-byte stub programs, no rows): <id>:rock_NN ...`.
    protodiff.py --self-test
        Planted programs (synthetic words): the census, the anchors, the pairing, the twins (a reloc-only pair
        accepted, a one-word near-twin, an ambiguous twin and a 4-byte stub refused). Last line `PROTODIFF CONTROL OK`.

Programs: imgadapter.programs (the executable at its header's address, each ROCK_X6.BIN member at retail's base of
its index, config/oracle.units.tsv). A proto function start: the program's first word, each jal target, each held
row's place (an anchor) and the word after its body (zeros skipped), and each word after a `jr ra` and its delay slot
(zeros skipped) that a stack prologue (`addiu sp, sp, -N` in its first 4 words), a pointer word or a lui pair reaches;
a start inside a held body is dropped. On retail against .run/oracle/functions.tsv this rule finds 8433 of 8534 starts
with 140 extra (T6.c1). Text: retail's text range of the unit, moved by the outermost chained anchors. A function runs to the next start, cut after its last `j` or `jr` and delay slot (a held one: retail's length).
A target resolves in its own program, else in the executable (imgadapter's rule; other overlays: not resolved).
Anchors: the rows of config/oracle.<id>.functions.tsv with an address (an ROCK_X6.BIN place is a file offset: the
member that holds it), in the program of their unit; psxd_img.chain keeps the longest run rising in both. Then each retail function of a gap that holds no place and
whose masked body lies once in the gap's proto words is one more anchor (same).
Between two neighbouring anchors the proto functions pair in order with the retail functions there that hold no
place (a `--` search row may pair): the most total similarity (difflib ratio of psxd_img.loose words), a pair only at
>= THRESHOLD. Paired and equal: same; paired: changed; unpaired: absent. A held row whose proto length differs from
retail's: changed (none by construction: the body matched over retail's whole length).
Moved (after pairing; C0266 trap: ~10% of absent rows are members moved to another unit): an absent body of more
than one word whose masked words (psxd_img.loose: jal targets, lui and low-half immediates cleared) equal those of
exactly one retail census function of more than one word, in any unit; retail = that function `<unit>:0xADDR`,
size_delta 0. Refused: a body of one word, two or more twins (ambiguous), any difference outside the mask. A program of
one word or less (a 4-byte stub: 09-21 rock_33..rock_40) is skipped: no rows, listed in the header.
Columns: strings = the 12-hex sha1 prefixes of docs/leads/strings.tsv rows of this build whose referencing function
lies in this function; callers = jal sites, pointer words and lui pairs that reach its start; debug_hint = our tokens:
calls-<lib> (a retail lib function of DEBUG_LIBS, named by config/ghidra/SLUS_013.95.jsonl, found in the build by its
exact words, else by its pair), fmt-string (psxd_img.FORMAT), path-string (psxd_img.PATH), ascii-strings,
sjis-strings, no-callers.
"""
import argparse
import difflib
import json
import re
import sys
from bisect import bisect_right
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import imgadapter as ia  # noqa: E402

kit, rock = ia.kit, ia.rock
ROOT = ia.ROOT
TAG = "PROTODIFF"
OUT, DEBUG = "docs/leads/proto.tsv", "build/leads/retail-debug.tsv"
IMGTAB = "extracted"  # extracted/<id>/, written by tools/mmx6/extract_protos.py
GHIDRA = "config/ghidra/SLUS_013.95.jsonl"
COLUMNS = "build\tprog\tbuild_address\tretail\tstate\twords\tsize_delta\tstrings\tcallers\tdebug_hint"
DEBUG_COLUMNS = "prog\tvram\tstrings\tdebug_hint"
DEBUG_LIBS = re.compile(r"(s?printf|puts|Fnt[A-Za-z]+|SetDumpFnt|KanjiFnt[A-Za-z]+|pollhost|PC[a-z]+)$")
THRESHOLD = 0.6  # was 0.5; T6.c1 log: same-unit non-corresponding pairs reach 0.595 at the 99th percentile
PROBE = 4        # words after a start where a prologue counts


def jal_target(pc, w):
    return ((pc + 4) & 0xF0000000) | ((w & 0x3FFFFFF) << 2)


def home(q, exe, x):
    return q if q.base <= x < q.end else exe if exe.base <= x < exe.end else None


def reach(code):
    """({prog: {target: count}} of jal sites, {prog: {target: count}} of pointer words and lui pairs."""
    exe, jal, ptr = code[0], {p.name: {} for p in code}, {p.name: {} for p in code}
    for q in code:
        for i, w in enumerate(q.ws):
            if w >> 26 == 3:
                h = home(q, exe, jal_target(q.base + 4 * i, w))
                if h:
                    t = jal_target(q.base + 4 * i, w)
                    jal[h.name][t] = jal[h.name].get(t, 0) + 1
            elif not w & 3:
                h = home(q, exe, w)
                if h:
                    ptr[h.name][w] = ptr[h.name].get(w, 0) + 1
        for x, luis in kit.refs(q.ws, q.base).items():
            h = home(q, exe, x)
            if h and not x & 3:
                ptr[h.name][x] = ptr[h.name].get(x, 0) + len(luis)
    return jal, ptr


def skip0(ws, s):
    while s < len(ws) and ws[s] == 0:
        s += 1
    return s


def ends(w):
    """A function's last word but its delay slot: `j`, or `jr` of any register."""
    return w >> 26 == 2 or w & 0xFC1FFFFF == 0x00000008


def census(q, jal, ptr, held=(), lo=0, hi=None):
    """[(start, words)] of program q in its words [lo, hi). held: [(start, words)] of its anchors."""
    ws, scan = q.ws, set()
    hi = len(ws) if hi is None else min(hi, len(ws))
    n_of = {(a - q.base) // 4: n for a, n in held}
    for i, w in enumerate(ws):
        if w == kit.JR_RA and skip0(ws, i + 2) < len(ws):
            scan.add(skip0(ws, i + 2))
    pro = {s for s in scan if any(ws[k] >> 16 == 0x27BD and ws[k] & 0x8000 for k in range(s, min(s + PROBE, len(ws))))}
    want = {(t - q.base) // 4 for t in ptr if not (t - q.base) % 4}
    st = {lo} | {(t - q.base) // 4 for t in jal if not (t - q.base) % 4} | (scan & (pro | want))
    for a, n in held:
        i = (a - q.base) // 4
        st = {s for s in st if not i < s < i + n} | {i}
        if skip0(ws, i + n) < len(ws):
            st.add(skip0(ws, i + n))
    st = sorted(s for s in st if lo <= s < hi)
    out = []
    for k, s in enumerate(st):
        e = st[k + 1] if k + 1 < len(st) else hi
        last = max((i for i in range(s, e - 1) if ends(ws[i])), default=None)
        out.append((q.base + 4 * s, n_of.get(s) or ((last + 2 - s) if last is not None else e - s)))
    return out


def sim(a, b):
    if not a or not b or 2 * min(len(a), len(b)) / (len(a) + len(b)) < THRESHOLD:
        return 0.0
    m = difflib.SequenceMatcher(None, a, b, autojunk=False)
    return m.ratio() if m.real_quick_ratio() >= THRESHOLD and m.quick_ratio() >= THRESHOLD else 0.0


def align(ps, rs):
    """[(i, j, ratio)]: the pairs in order of ps, rs (masked bodies) of the most total ratio, each >= THRESHOLD."""
    n, m = len(ps), len(rs)
    best = [[0.0] * (m + 1) for _ in range(n + 1)]
    score = {}
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            s = sim(ps[i - 1], rs[j - 1])
            if s >= THRESHOLD:
                score[i, j] = s
            best[i][j] = max(best[i - 1][j], best[i][j - 1], best[i - 1][j - 1] + s if s >= THRESHOLD else 0.0)
    out, i, j = [], n, m
    while i and j:
        if (i, j) in score and best[i][j] == best[i - 1][j - 1] + score[i, j]:
            out.append((i - 1, j - 1, score[i, j]))
            i, j = i - 1, j - 1
        elif best[i][j] == best[i - 1][j]:
            i -= 1
        else:
            j -= 1
    return out[::-1]


def diff_prog(q, r_ws, r_base, rfs, anchors, others, jal, ptr):
    """{proto start: (state, words, retail vram or None, retail words or None)} of program q.
    rfs: [(vram, words)] of its retail unit, sorted; anchors: [(proto start, retail vram, words)] in this program;
    others: the retail vrams held at a place (not pairable). r_ws, r_base: the retail unit's program."""
    ch = kit.chain(sorted((a, v) for a, v, _ in anchors))
    r_lo, r_hi = rfs[0][0], max(v + 4 * w for v, w in rfs)
    p_lo, p_hi = (ch[0][0] - (ch[0][1] - r_lo), ch[-1][0] + (r_hi - ch[-1][1])) if ch else (r_lo, r_hi)
    lo, hi = max(0, (p_lo - q.base) // 4), min(len(q.ws), (p_hi - q.base) // 4)
    rn = dict(rfs)
    body = lambda ws, base, v, n: kit.loose(ws[(v - base) // 4:(v - base) // 4 + n])  # noqa: E731
    # A retail function of a gap whose masked body lies once in the gap's proto words: one more anchor.
    lw, pos, ns = kit.loose(q.ws), {}, {a: n for a, _, n in anchors}
    for i in range(lo, hi):
        pos.setdefault(lw[i], []).append(i)
    bounds = [(p_lo - 4, r_lo - 4)] + ch + [(p_hi, r_hi)]
    extra = []
    for (a0, v0), (a1, v1) in zip(bounds, bounds[1:]):
        g0, g1 = (a0 - q.base) // 4 + ns.get(a0, 1), (a1 - q.base) // 4
        for v, w in rfs:
            if v0 < v < v1 and v not in others and w:
                b = body(r_ws, r_base, v, w)
                hits = [i for i in pos.get(b[0], ()) if g0 <= i and i + w <= g1 and lw[i:i + w] == b]
                if len(hits) == 1:
                    extra.append((q.base + 4 * hits[0], v, w))
    anchors = anchors + extra
    others = others | {v for _, v, _ in extra}
    ch = kit.chain(sorted((a, v) for a, v, _ in anchors))
    fs = census(q, jal, ptr, [(a, n) for a, _, n in anchors], lo, hi)
    out = {}
    for a, v, n in anchors:
        w = dict(fs)[a]
        out[a] = ("same" if w == n else "changed", w, v, n)
    bounds = [(-1, -1)] + ch + [(1 << 33, 1 << 33)]
    for (a0, v0), (a1, v1) in zip(bounds, bounds[1:]):
        pg = [(s, w) for s, w in fs if a0 < s < a1 and s not in out]
        rg = [(v, w) for v, w in rfs if v0 < v < v1 and v not in others]
        pairs = align([body(q.ws, q.base, s, w) for s, w in pg], [body(r_ws, r_base, v, w) for v, w in rg])
        got = {i: (j, x) for i, j, x in pairs}
        for i, (s, w) in enumerate(pg):
            if i in got:
                v, rw = rg[got[i][0]]
                eq = got[i][1] == 1.0 and body(q.ws, q.base, s, w) == body(r_ws, r_base, v, rw)
                out[s] = ("same" if eq else "changed", w, v, rn[v])
            else:
                out[s] = ("absent", w, None, None)
    return out


def held_rows(bid, toc, vrams):
    """[(retail unit, retail vram, words, proto prog, proto address)] of the rows with an address."""
    out = []
    for unit, vram, _, n, _, bfile, addr, *_ in kit.read_tsv(ROOT / f"config/oracle.{bid}.functions.tsv"):
        if addr.startswith("-"):
            continue
        a = int(addr, 16)
        if bfile == ia.OVL:
            m = next(m for m in toc if m.sector * rock.SECTOR <= a < m.sector * rock.SECTOR + m.size)
            if m.index in vrams:
                out.append((unit, int(vram, 16), int(n), f"rock_{m.index:02d}",
                            vrams[m.index] + a - m.sector * rock.SECTOR))
        else:
            out.append((unit, int(vram, 16), int(n), bfile, a))
    return out


def lib_names(root=ROOT):
    """{retail vram: name} of the executable's functions whose Ghidra name is one of DEBUG_LIBS."""
    out = {}
    for line in (root / GHIDRA).read_text().splitlines():
        if '"k":"func"' in line:
            d = json.loads(line)
            if DEBUG_LIBS.match(d["name"]):
                out[int(d["addr"], 16)] = d["name"]
    return out


def string_hints(rows, progs, build):
    """{(prog, referencing start): [(key, hint tokens)]} of the docs/leads/strings.tsv rows of build."""
    by = {p.name: p for p in progs}
    out = {}
    for prog, vram, sha1, n, _, enc, who, b in rows:
        if b != build or who == "unreferenced" or prog not in by or by[prog].base is None:
            continue
        p, x = by[prog], int(vram, 16)
        t = p.data[x - p.base:x - p.base + int(n)]
        hint = ["fmt-string"] if kit.FORMAT.search(t) else []
        hint += ["path-string"] if kit.PATH.search(t) else []
        hint.append(f"{enc}-strings")
        for ref in who.split(","):
            u, a = ref.split(":")
            out.setdefault((u, int(a, 16)), []).append((sha1[:12], hint))
    return out


def owner_of(starts, x):
    k = bisect_right(starts, x) - 1
    return starts[k] if k >= 0 else None


def tokens(hs):
    order = ["fmt-string", "path-string", "ascii-strings", "sjis-strings"]
    have = {t for h in hs for t in h}
    return [t for t in order if t in have]


def calls_in(ws, base, start, n, libs):
    return sorted({f"calls-{libs[jal_target(base + 4 * i, ws[i])]}" for i in range((start - base) // 4,
                   (start - base) // 4 + n) if ws[i] >> 26 == 3 and jal_target(base + 4 * i, ws[i]) in libs})


def find_exact(q, ws):
    hits = [i for i in range(len(q.ws) - len(ws) + 1) if q.ws[i] == ws[0] and q.ws[i:i + len(ws)] == ws]
    return q.base + 4 * hits[0] if len(hits) == 1 else None


def twin_index(retail, rcen):
    """{masked body: [(retail unit, vram, words)]} of every retail census function of more than one word."""
    out = {}
    for p in retail:
        for v, n in rcen.get(p.name, ()):
            b = kit.loose(p.ws[(v - p.base) // 4:(v - p.base) // 4 + n]) if n > 1 else ()
            if len(b) == n > 1:
                out.setdefault(b, []).append((p.name, v, n))
    return out


def twin_of(body, index):
    """(retail unit, vram, words) of the one retail function whose masked body equals body; None: a body of one word
    or less, no twin, or more than one."""
    hits = index.get(body, []) if len(body) > 1 else []
    return hits[0] if len(hits) == 1 else None


def run_build(bid, retail, rcen, srows, libs):
    folder = ROOT / IMGTAB / bid
    ovl = (folder / ia.OVL).read_bytes()
    rows = kit.read_tsv(ROOT / f"config/oracle.{bid}.functions.tsv")
    exe_name = next(r[5] for r in rows if r[5] not in (ia.OVL, "-"))
    _, vrams = ia.retail_vrams()
    progs = ia.programs((folder / exe_name).read_bytes(), exe_name, ovl, vrams)
    code = [p for p in progs if p.base is not None]
    held = held_rows(bid, rock.read_toc(ovl), vrams)
    unit_of = {p.name: (ia.EXE if p is code[0] else p.name) for p in code}
    others = {}
    for unit, v, *_ in held:
        others.setdefault(unit, set()).add(v)
    jal, ptr = reach(code)
    rprog = {p.name: p for p in retail}
    res, skipped = {}, []
    for q in code:
        u = unit_of[q.name]
        if len(q.ws) <= 1:  # a 4-byte stub program (09-21 rock_33..rock_40): no rows, listed in the header
            skipped.append(q.name)
            continue
        if u not in rprog or u not in rcen:
            continue
        anchors = [(a, v, n) for unit, v, n, pp, a in held if pp == q.name and unit == u]
        res[q.name] = diff_prog(q, rprog[u].ws, rprog[u].base, rcen[u], anchors, others.get(u, set()),
                                jal[q.name], ptr[q.name])
    index, runit = twin_index(retail, rcen), {}
    by = {p.name: p for p in code}
    for prog, fs in res.items():
        q = by[prog]
        for s, (state, w, v, rw) in list(fs.items()):
            t = twin_of(kit.loose(q.ws[(s - q.base) // 4:(s - q.base) // 4 + w]), index) if state == "absent" else None
            if t:
                fs[s], runit[prog, s] = ("moved", w, t[1], t[2]), t[0]
    if skipped:
        print(f"{TAG} {bid}: skipped {len(skipped)} stub programs: {' '.join(skipped)}")
    plibs = {}
    for v, name in libs.items():
        n = dict(rcen[ia.EXE]).get(v)
        if n is None:
            continue
        a = find_exact(code[0], rprog[ia.EXE].ws[(v - rprog[ia.EXE].base) // 4:][:n])
        a = a or next((s for s, (_, _, rv, _) in res.get(code[0].name, {}).items() if rv == v), None)
        if a is not None:
            plibs[a] = name
            print(f"{TAG} {bid}: lib {name} at 0x{a:08X}")
    sh = string_hints(srows, progs, bid)
    keyed = {}
    for (u, a), ks in sh.items():
        if u in res:
            keyed.setdefault((u, owner_of(sorted(res[u]), a)), []).extend(ks)
    out, counts = [], {"absent": 0, "changed": 0, "moved": 0, "same": 0}
    for prog, fs in res.items():
        q = by[prog]
        for s, (state, w, v, rw) in fs.items():
            counts[state] += 1
            if state == "same":
                continue
            ks = keyed.get((prog, s), [])
            c = jal[prog].get(s, 0) + ptr[prog].get(s, 0)
            hint = calls_in(q.ws, q.base, s, w, plibs) + tokens(h for _, h in ks) + ([] if c else ["no-callers"])
            ru = runit.get((prog, s), unit_of[prog])
            out.append((bid, prog, s, f"{ru}:0x{v:08X}" if v is not None else "-", state, str(w),
                        str(w - rw) if rw is not None else "-", ",".join(sorted({k for k, _ in ks})) or "-", str(c),
                        ",".join(hint) or "-"))
    print(f"{TAG} {bid}: absent {counts['absent']} changed {counts['changed']} moved {counts['moved']} "
          f"same {counts['same']}")
    return out, skipped


def retail_debug(retail, rcen, srows, libs):
    """Rows of build/leads/retail-debug.tsv: retail functions that call a DEBUG_LIBS function or load a format string."""
    sh = string_hints(srows, retail, ia.RETAIL)
    out = []
    for p in retail:
        if p.name not in rcen:
            continue
        starts = [v for v, _ in rcen[p.name]]
        keyed = {}
        for (u, a), ks in sh.items():
            if u == p.name:
                keyed.setdefault(owner_of(starts, a), []).extend(ks)
        for v, n in rcen[p.name]:
            ks = keyed.get(v, [])
            hint = calls_in(p.ws, p.base, v, n, libs) + [t for t in tokens(h for _, h in ks) if t == "fmt-string"]
            if hint:
                out.append((p.name, f"0x{v:08X}", ",".join(sorted({k for k, _ in ks})) or "-", ",".join(hint)))
    return out


def cmd_build(a):
    (unit, file), vrams = ia.retail_vrams()
    iso = kit.retail_dir(ROOT, None)
    retail = [p for p in ia.programs((iso / file).read_bytes(), unit, (iso / ia.OVL).read_bytes(), vrams)
              if p.base is not None]
    rcen = ia.census()
    if rcen is None:
        sys.exit(f"protodiff: {ia.FUNCTIONS} missing (imgadapter.py functions)")
    srows = kit.read_tsv(ROOT / ia.STRINGS)
    libs = lib_names()
    ids = a.id or sorted(p.name[len("oracle."):-len(".functions.tsv")]
                         for p in (ROOT / "config").glob("oracle.proto-*.functions.tsv"))
    rows, skip = [], []
    for bid in ids:
        r, s = run_build(bid, retail, rcen, srows, libs)
        rows += r
        skip += [f"{bid}:{p}" for p in s]
    rows.sort(key=lambda r: (r[0], r[1], r[2]))
    text = (f"# {OUT} -- generated by tools/mmx6/protodiff.py build; do not edit (keys, addresses, counts only)\n"
            f"# {COLUMNS}\n# skipped (4-byte stub programs, no rows): {' '.join(skip) or '-'}\n" + "".join("\t".join(r[:2] + (f"0x{r[2]:08X}",) + r[3:]) + "\n" for r in rows))
    (ROOT / OUT).write_text(text, newline="\n")
    dr = retail_debug(retail, rcen, srows, libs)
    (ROOT / DEBUG).parent.mkdir(parents=True, exist_ok=True)
    (ROOT / DEBUG).write_text(f"# {DEBUG} -- generated by tools/mmx6/protodiff.py build; do not edit\n# {DEBUG_COLUMNS}\n"
                              + "".join("\t".join(r) + "\n" for r in dr), newline="\n")
    print(f"{TAG}: {OUT} {len(rows)} rows; {DEBUG} {len(dr)} rows")
    return 0


def self_test():
    import struct
    bad = []

    def case(name, ok):
        print(f"{TAG} self-test {name}: {'ok' if ok else 'FAIL'}")
        if not ok:
            bad.append(name)

    base = 0x80010000
    pro, nop = 0x27BDFFE8, 0

    def fn(seed, n, call=None):
        body = [pro] + [0x00851021 + ((seed * 7919 + k * 104729) % 0x1F) * 0x800 + k for k in range(n - 3)]
        if call is not None:
            body[1] = 0x0C000000 | ((call >> 2) & 0x3FFFFFF)
        return body + [kit.JR_RA, nop]

    class P:
        def __init__(self, name, ws):
            self.name, self.base, self.ws = name, base, tuple(ws)
            self.end, self.data = base + 4 * len(ws), struct.pack(f"<{len(ws)}I", *ws)

    a, b, c, d = fn(1, 20), fn(2, 30), fn(3, 25), fn(4, 16)
    c2 = list(c)
    c2[5:8] = [0x00000025, 0x00000026, 0x00000027, 0x00000028]
    r = P("R", a + b + c + d)
    x = fn(9, 18)
    p = P("R", a + b + x + c2 + d)
    starts = lambda fs: [s for s, _ in fs]  # noqa: E731
    jal, ptr = reach([p])
    fs = census(p, jal[p.name], ptr[p.name])
    want = [base, base + 80, base + 200, base + 272, base + 4 * (20 + 30 + 18 + 26)]
    case("census", starts(fs) == want and [w for _, w in fs] == [20, 30, 18, 26, 16])
    rfs = [(base, 20), (base + 80, 30), (base + 200, 25), (base + 300, 16)]
    anchors = [(base, base, 20), (want[4], base + 300, 16)]
    out = diff_prog(p, r.ws, r.base, rfs, anchors, {base, base + 300}, jal[p.name], ptr[p.name])
    st = {s: v[0] for s, v in out.items()}
    case("pairing", st == {want[0]: "same", want[1]: "same", want[2]: "absent", want[3]: "changed",
                           want[4]: "same"} and out[want[3]][2] == base + 200)
    case("align", align([(1, 2, 3), (9, 9, 9, 9)], [(1, 2, 3)]) == [(0, 0, 1.0)])
    q = P("Q", fn(5, 12, call=base + 4 * 12) + fn(6, 10))
    jal, ptr = reach([q])
    case("callers", jal["Q"].get(base + 48) == 1)
    case("libs", calls_in(q.ws, q.base, base, 12, {base + 48: "printf"}) == ["calls-printf"])
    # Cross-unit twins: retail S holds t (a jal, a lui/addiu pair), d and a 4-byte stub; R holds a, b, c, d.
    t = fn(11, 14, call=base + 8)
    t[3:5] = [0x3C048001, 0x24841234]  # lui a0, 0x8001; addiu a0, a0, 0x1234
    s = P("S", t + d + [kit.JR_RA])
    s.base, s.end = 0x80100000, 0x80100000 + 4 * len(s.ws)
    index = twin_index([r, s], {"R": rfs, "S": [(s.base, 14), (s.base + 56, 16), (s.base + 120, 1)]})
    pt = list(t)
    pt[1], pt[3], pt[4] = 0x0C000000 | ((base + 400) >> 2 & 0x3FFFFFF), 0x3C048002, 0x24845678  # relocs only
    case("twin-true", twin_of(kit.loose(pt), index) == ("S", s.base, 14) and tuple(pt) != tuple(t))
    near = list(pt)
    near[6] ^= 0x800  # one register field: a non-reloc word
    case("twin-near-refused", twin_of(kit.loose(near), index) is None
         and twin_of(kit.loose(d), index) is None)  # d lies in R and S: ambiguous, refused
    case("twin-stub-refused", twin_of(kit.loose([kit.JR_RA]), index) is None)
    print(f"{TAG} CONTROL {'OK' if not bad else 'FAIL ' + ' '.join(bad)}")
    return 1 if bad else 0


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--self-test", action="store_true")
    sub = ap.add_subparsers(dest="cmd")
    b = sub.add_parser("build", help="write docs/leads/proto.tsv and build/leads/retail-debug.tsv")
    b.add_argument("--id", action="append", help="a build id (default: every config/oracle.proto-*.functions.tsv)")
    a = ap.parse_args(argv)
    if a.self_test:
        return self_test()
    if a.cmd == "build":
        return cmd_build(a)
    ap.print_help()
    return 2


if __name__ == "__main__":
    sys.exit(main())
