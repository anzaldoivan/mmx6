# tools/mmx6/sweeps/ — mechanical lever sweeps (harvest.py --sweep)

A sweep starts from a harvested live lever that is mechanical (a pure text rewrite). The sweep turns the lever into
a script. The script runs over every draft stuck on the same plateau label. There is one file per sweep:
`tools/mmx6/sweeps/<id>.py`, with `<id>` = `[A-Za-z0-9_-]+`.

The interface is stdlib only, has no side effects and is deterministic:
- `LABEL` (str) is the plateau label (plateau.py) that the sweep targets.
- `apply(text) -> (text, edits)` returns the rewritten C text and the number of edits made (0 = untouched).

Run `harvest.py --sweep <id> --wave W<n>` (container). The targets are the latest journal record per pv whose label
is `LABEL` and whose draft is readable. `campaign/ledger.tsv` rows with blocker `plateau:<LABEL>` and an existing
best draft are targets too.

Edited drafts become packs `waves/sweeps/W<n>/<prog>_<func>/{pack.json,draft.c}`.
`gate.py --wave W<n> --root waves/sweeps --journal campaign/harvest/W<n>.sweeps.jsonl` scores the packs. The run
gives the line `SWEEP <id> tried <t> edited <e>`. A `sweep` record goes to `campaign/harvest/W<n>.jsonl`.

The contract is docs/ops/campaign.md `## Harvest`. Firewall G12 allows our C only, never game bytes.
