#!/usr/bin/env python3
"""Per-wave metrics table (3.1 T13): sums methods-before/after records into campaign/wave-metrics.tsv.

Host tool, stdlib. `--build [FILE...]` (default campaign/methods-before.tsv campaign/methods-after.tsv,
missing files skipped) writes the table; `--check` rebuilds from the table's own source column(s) and
compares per cell (`WAVEMETRICS DRIFT <wave> <col> table <x> rebuilt <y>`, last line
`WAVEMETRICS CHECK OK <k> waves`, rc 0 or 1); `--self-test` plants faults in .run/<phase>/wavemetrics-selftest (layout._phase_run(); was .run/3.1).
Records file: methods-before.tsv form (header row + data rows) plus optional after columns route, arm,
banked, bank_wall_s; wave facts in comment lines
`# wave <name> split <pilot|holdout|all|<name>> fleet_wall_s <n|-> since_wall_s <n|->`.
A row belongs to every directive whose split equals its split column (or `all`). Production waves (W306 on,
3.2 T1) share campaign/wave-rows.tsv: directive split = its own wave name, rows' split = that name. Errors rc 2:
`WAVEMETRICS BAD <file>:<line> <why>`. Rules: docs/ops/campaign.md `## Yield`.
"""
import re, shutil, sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import layout  # noqa: E402

ROOT = Path(__file__).resolve().parents[2]
OUT = "campaign/wave-metrics.tsv"
DEFAULT = ("campaign/methods-before.tsv", "campaign/methods-after.tsv", "campaign/wave-rows.tsv")
BEFORE = ("stratum prog vram func split words a1 a2 best best_pins pinfree_match coder_runs ctx_a1 ctx_a2 "
          "wall_a1_s wall_a2_s compiles_a1 compiles_a2 dev_stops").split()
AFTER = ("route", "arm", "banked", "bank_wall_s")
INTS = ("words best_pins coder_runs ctx_a1 ctx_a2 wall_a1_s wall_a2_s compiles_a1 compiles_a2 dev_stops "
        "bank_wall_s").split()
ROUTES = ("repair", "draft", "w300")
COLS = ("wave rows attempts coder_runs context coder_wall_s compiles pinfree_matches banked_repair "
        "banked_draft banked_w300 dev_stops bank_wall_s fleet_wall_s since_wall_s source").split()
DIRECTIVE = re.compile(r"^# wave (\S+) split (pilot|holdout|all|W\d+) fleet_wall_s (\d+|-) since_wall_s (\d+|-)$")


class Bad(Exception):
    pass


def n(v):
    return 0 if v == "-" else int(v)


def parse(root, rel):
    """-> (directives [(wave, split, fleet, since, line)], rows [dict])"""
    lines = (root / rel).read_text().splitlines()
    dirs, rows, head = [], [], None
    for i, line in enumerate(lines, 1):  # directives first: one may sit after the rows it covers
        if line.startswith("# wave "):
            m = DIRECTIVE.match(line)
            if not m:
                raise Bad(f"{rel}:{i} malformed wave directive")
            if m.group(2).startswith("W") and m.group(2) != m.group(1):
                raise Bad(f"{rel}:{i} wave split {m.group(2)} is not the wave name {m.group(1)}")
            dirs.append((*m.groups(), i))
    splits = {d[1] for d in dirs}
    for i, line in enumerate(lines, 1):
        if not line or line.startswith("#"):
            continue
        cells = line.split("\t")
        if head is None:
            extra = cells[len(BEFORE):]
            if cells[:len(BEFORE)] != BEFORE or any(c not in AFTER for c in extra) or len(set(extra)) != len(extra):
                raise Bad(f"{rel}:{i} header mismatch")
            head = cells
            continue
        if len(cells) != len(head):
            raise Bad(f"{rel}:{i} {len(cells)} cells, header has {len(head)}")
        r = dict(zip(head, cells))
        for c in INTS:
            if c in r and r[c] != "-" and not r[c].isdigit():
                raise Bad(f"{rel}:{i} non-integer {c} {r[c]!r}")
        if r.get("route", "-") not in ROUTES + ("-",):
            raise Bad(f"{rel}:{i} unknown route {r['route']!r}")
        if r["split"] not in splits and "all" not in splits:
            raise Bad(f"{rel}:{i} row under no directive (split {r['split']})")
        r["_line"] = i
        rows.append(r)
    return dirs, rows


def build(root, files):
    out, seen = [], {}
    for rel in files:
        dirs, rows = parse(root, rel)
        for wave, split, fleet, since, line in dirs:
            if wave in seen:
                raise Bad(f"{rel}:{line} duplicate wave {wave} (first {seen[wave]})")
            seen[wave] = f"{rel}:{line}"
            sel = [r for r in rows if split in (r["split"], "all")]
            banked = {k: sum(1 for r in sel if r.get("banked") == "yes" and r.get("route") == k) for k in ROUTES}
            out.append([wave, len(sel),
                        sum((r["a1"] != "-") + (r["a2"] != "-") for r in sel),
                        sum(n(r["coder_runs"]) for r in sel),
                        sum(n(r["ctx_a1"]) + n(r["ctx_a2"]) for r in sel),
                        sum(n(r["wall_a1_s"]) + n(r["wall_a2_s"]) for r in sel),
                        sum(n(r["compiles_a1"]) + n(r["compiles_a2"]) for r in sel),
                        sum(1 for r in sel if r["pinfree_match"] == "yes" and r.get("route") != "w300"),
                        banked["repair"], banked["draft"], banked["w300"],
                        sum(n(r["dev_stops"]) for r in sel),
                        sum(n(r.get("bank_wall_s", "-")) for r in sel),
                        fleet, since, rel])
    out.sort(key=lambda r: (r[-1], r[0]))
    head = [f"# {OUT} -- generated by tools/mmx6/wavemetrics.py --build; one row per `# wave` directive",
            "# sums over the directive's split rows; '-' counts 0; context = ctx_a1+ctx_a2; "
            "pinfree_matches excludes route w300; banked_<route> = banked yes by route",
            "# " + "\t".join(COLS)]
    return "\n".join(head + ["\t".join(map(str, r)) for r in out]) + "\n"


def table(text):
    return {c[0]: c for c in (l.split("\t") for l in text.splitlines() if l and not l.startswith("#"))}


def check(root, out):
    cur = table((root / out).read_text())
    srcs = sorted({r[-1] for r in cur.values()})
    new = table(build(root, srcs))
    drift = []
    for w in sorted(set(cur) | set(new)):
        a, b = cur.get(w), new.get(w)
        for j, c in enumerate(COLS[1:], 1):
            x = a[j] if a and j < len(a) else "-absent-"
            y = b[j] if b else "-absent-"
            if x != y:
                drift.append(f"WAVEMETRICS DRIFT {w} {c} table {x} rebuilt {y}")
    return drift, len(cur)


def self_test():
    tmp = ROOT / layout._phase_run() / "wavemetrics-selftest"  # was .run/3.1
    shutil.rmtree(tmp, ignore_errors=True)
    (tmp / "campaign").mkdir(parents=True)
    rec = "campaign/fx.tsv"
    hdr = "\t".join(BEFORE + list(AFTER))
    base = ["s\tP\t0x1\tf1\tpilot\t10\tmatch 10/10\t-\t10/10\t0\tyes\t1\t100\t-\t60\t-\t2\t-\t1\trepair\tA\tyes\t30",
            "s\tP\t0x2\tf2\tholdout\t10\tfail 5/10\tmatch 10/10\t10/10\t0\tyes\t2\t100\t200\t60\t90\t3\t4\t0\tw300\tB\tyes\t40",
            "s\tP\t0x3\tf3\tholdout\t10\tmatch 10/10\t-\t10/10\t0\tyes\t1\t50\t-\t10\t-\t1\t-\t1\tdraft\tA\tno\t-"]
    dirs = ["# wave FX-pilot split pilot fleet_wall_s 500 since_wall_s -",
            "# wave FX-holdout split holdout fleet_wall_s - since_wall_s 7"]

    def write(rows, ds=dirs):
        (tmp / rec).write_text("\n".join(["# fixture"] + ds + [hdr] + rows) + "\n")

    def bad(rows, ds=dirs):
        write(rows, ds)
        try:
            build(tmp, [rec])
        except Bad as e:
            return str(e)
        return None

    plants = 0
    try:
        write(base)
        (tmp / OUT).write_text(build(tmp, [rec]))
        d, k = check(tmp, OUT)
        assert not d and k == 2, (d, k)
        t = table((tmp / OUT).read_text())
        h = dict(zip(COLS, t["FX-holdout"]))
        # plant: w300 match not counted, banked by route, sums
        assert (h["rows"], h["attempts"], h["context"], h["compiles"], h["pinfree_matches"],
                h["banked_w300"], h["banked_draft"], h["bank_wall_s"], h["since_wall_s"]) == \
            ("2", "3", "350", "8", "1", "1", "0", "40", "7"), h
        plants += 1
        # plant: one table cell edited -> drift naming it
        lines = (tmp / OUT).read_text().splitlines()
        j = next(i for i, l in enumerate(lines) if l.startswith("FX-pilot\t"))
        c = lines[j].split("\t")
        c[COLS.index("coder_runs")] = "9"
        lines[j] = "\t".join(c)
        (tmp / OUT).write_text("\n".join(lines) + "\n")
        d, _ = check(tmp, OUT)
        assert d == ["WAVEMETRICS DRIFT FX-pilot coder_runs table 9 rebuilt 1"], d
        plants += 1
        # plant: row with no directive
        e = bad(base, dirs[:1])
        assert e and "no directive" in e, e
        plants += 1
        # plant: unknown route
        e = bad([base[0].replace("\trepair\t", "\tsweep\t")] + base[1:])
        assert e and "unknown route" in e, e
        plants += 1
        # plant: production waves share one file, each directive takes only its own rows (3.2 T1)
        prod = [r.replace("\tpilot\t", "\tW1\t").replace("\tholdout\t", "\tW2\t") for r in base]
        pds = ["# wave W1 split W1 fleet_wall_s 5 since_wall_s -", "# wave W2 split W2 fleet_wall_s - since_wall_s -"]
        write(prod, pds)
        t = table(build(tmp, [rec]))
        assert (t["W1"][1], t["W2"][1]) == ("1", "2"), t
        e = bad(prod, ["# wave W1 split W2 fleet_wall_s - since_wall_s -"] + pds[1:])
        assert e and "not the wave name" in e, e
        plants += 1
    finally:
        shutil.rmtree(tmp, ignore_errors=True)
    print(f"WAVEMETRICS SELF-TEST OK {plants} plants")


def main():
    a = sys.argv[1:]
    try:
        if a[:1] == ["--build"]:
            files = [f for f in (a[1:] or DEFAULT) if (ROOT / f).exists()]
            text = build(ROOT, files)
            (ROOT / OUT).write_text(text)
            print(f"WAVEMETRICS BUILD OK {len(table(text))} waves -> {OUT}")
        elif a == ["--check"]:
            d, k = check(ROOT, OUT)
            for l in d:
                print(l)
            if d:
                sys.exit(1)
            print(f"WAVEMETRICS CHECK OK {k} waves")
        elif a == ["--self-test"]:
            self_test()
        else:
            sys.exit("usage: wavemetrics.py --build [FILE...] | --check | --self-test")
    except Bad as e:
        print(f"WAVEMETRICS BAD {e}")
        sys.exit(2)


if __name__ == "__main__":
    main()
