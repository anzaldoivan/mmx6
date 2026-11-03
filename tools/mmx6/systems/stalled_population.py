"""stalled_population.py -- population of stalled plumbing drafts (2.6 T4.c1; replaces the lost 2.4 popa.py).

Member: latest campaign/journal.jsonl row per pv has verdict plumbing* + pv open in campaign/ledger.tsv + draft on disk.
Run from the repo root (host):  PY tools/mmx6/systems/stalled_population.py .run/<phase>/stalled/pop.tsv
Out: pv label wave draft func (tab-separated); counts on stderr. Next: stalled_compile.sh <pop.tsv>.
"""
import json, os, sys
from collections import Counter

ROOT = "."
latest = {}
for line in open(os.path.join(ROOT, "campaign/journal.jsonl")):
    line = line.strip()
    if not line:
        continue
    r = json.loads(line)
    latest[r["pv"]] = r
open_pv = set()
for line in open(os.path.join(ROOT, "campaign/ledger.tsv")):
    f = line.rstrip("\n").split("\t")
    if len(f) >= 2:
        open_pv.add(f"{f[0]}:{f[1]}")
plumb = {pv: r for pv, r in latest.items() if r["verdict"].startswith("plumbing")}
closed = [pv for pv in plumb if pv not in open_pv]
missing = [pv for pv in plumb if pv in open_pv and not os.path.isfile(os.path.join(ROOT, plumb[pv]["draft"]))]
pop = sorted(pv for pv in plumb if pv in open_pv and pv not in missing)
print(f"latest-plumbing {len(plumb)} closed {len(closed)} missing-draft {len(missing)} population {len(pop)}", file=sys.stderr)
print("labels", Counter(plumb[pv]["label"] for pv in pop), file=sys.stderr)
print("drafts-not-under-waves", sum(1 for pv in pop if not plumb[pv]["draft"].startswith("waves/")), file=sys.stderr)
with open(sys.argv[1], "w") as o:
    for pv in pop:
        r = plumb[pv]
        o.write(f"{pv}\t{r['label']}\t{r['wave']}\t{r['draft']}\t{r['func']}\n")
