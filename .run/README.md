# `.run/` — scratch (the project's system temp)

Scratch for everything a rerun can reproduce: build/extract logs (`.run/logs/` via `tools/run.sh`), dumps, probes,
per-session work dirs. Never the system temp: no project data lives outside the repository. Generated; never committed.
`make clean` never touches it; pruning is a hand decision. Size cap and warning threshold are set in Phase 1.1.

Ignored by contents (`/.run/*`, not `/.run/`) so an irreplaceable artifact can be tracked by a dated exception block in
`.gitignore` (`# P<N> <task> (<session>, <date>): why` then `!/.run/P<N>/` … `!/.run/P<N>/verify/*.log`). Commit only what
a rerun cannot reproduce (hand analysis, a verdict's harness, a ledger, the recorded contract run).

Per session: `.run/<session>/`; each agent cleans only its own `work/<binary>-<address>/`; deliverables in `drafts/`,
`verdicts/`, `reports/`.

Firewall (G12, G18): a tracked `.run/` file is published and audited like any other: no target listings. Never
`git clean -x`/`-fdx` here: game-derived data is ignored-but-present on disk.
