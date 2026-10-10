# tools/mmx6/sweeps/ — mechanical lever sweeps (harvest.py --sweep)

A sweep turns a harvested live lever that is mechanical (a pure text rewrite) into a script run over every draft
stuck on the same plateau label. One file per sweep: `tools/mmx6/sweeps/<id>.py`, `<id>` = `[A-Za-z0-9_-]+`.

Interface (stdlib only, no side effects, deterministic):
- `LABEL` (str): the plateau label (plateau.py) the sweep targets.
- `apply(text) -> (text, edits)`: the rewritten C text and the number of edits made (0 = untouched).

Run: `harvest.py --sweep <id> --wave W<n>` (container). Targets: the latest journal record per pv whose label is
`LABEL` and whose draft is readable, plus `campaign/ledger.tsv` rows with blocker `plateau:<LABEL>` and an existing
best draft. Edited drafts become packs `waves/sweeps/W<n>/<prog>_<func>/{pack.json,draft.c}`, scored by
`gate.py --wave W<n> --root waves/sweeps --journal campaign/harvest/W<n>.sweeps.jsonl`. Line
`SWEEP <id> tried <t> edited <e>`; a `sweep` record goes to `campaign/harvest/W<n>.jsonl`. Contract:
docs/ops/campaign.md `## Harvest`. Firewall G12: our C only, never game bytes.
