# tools/mmx6/systems/ — scripts behind the per-system pages

Scripts that fix a system's membership and size for `docs/systems/<system>.md` (convention: `docs/systems/README.md`).
Run them from the repo root on the host. Inputs and outputs go under `.run/<phase>/` and are never tracked.
They have no self-tests. Each was checked by reproducing its 2.6 scratch output byte for byte (2.6 T12).

- `callgraph.py WORK [--diag | --who <hexvram>...]`: membership from the SLUS_013.95 call graph (C0285, C0346).
  The constants at the top (FOLDERS, OUT_FILES, TABLES, title) are the movement system's. A new system edits them.
  WORK holds `functions.jsonl` (container `build/corpus/functions.jsonl`, copied to WORK and pulled, C0319).
  It also holds `debt.txt` (`PY tools/psxd_floor.py debt --files`).
  The script writes `WORK/movement.md`, and the page holds the exact rerun (docs/systems/movement.md `## Members`).
- `sizes.py DEBT_FILES [prefix...]`: per-system files, states, asm, debt kinds, untested drafts (2.6 planning, R2.6-002).
  `DEBT_FILES` = `PY tools/psxd_floor.py debt --files` output.
- `stalled_population.py OUT.tsv`: the stalled plumbing-draft population (2.6 T4).
  A member has latest journal verdict `plumbing*`, an open ledger row and a draft on disk.
  The count was 91 at 2.6 T4 and 84 after T9 banked its targets.
- `stalled_compile.sh POP.tsv`: compile-only each draft of the population in the container (`mx.sh sync` first).
  Its log fed `docs/ops/stalled-drafts.tsv` (2.6 T4.c1). The join script of that step was one-off and is not kept.
- `props_check.py PROPS.tsv TOKENS.tsv`: checks a naming-proposal TSV (10 columns) against its token list (C0368, 2.6 T14).
  One row per token, a basis on every admit, anchors whole words on the cited line, names snake_case, unique, unused in
  src/include. Prints `PROPS OK n` (rc 0) or `PROPS FAIL` lines (rc 1). Kept by 2.6 T12.1, cmp-equal to the scratch copy.
