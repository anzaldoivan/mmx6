# TASK_PROGRESS — T8 attempt 1

Handoff cause: harness demanded hand-back while coder T8.c2 was still running (not a context threshold).

## Done so far
- PsyQ version scored (c1, commit 6d34ced, log logs/T8.c1.md, scratch `.run/t8/psyqscore.py`, `.run/logs/t8score.log`): 16 versions; 470 agree 233/233 exclusive 5; next best 460 agree 228; `SCORE CONTROL OK`. Version named: PsyQ 4.7 (`psyq/470`).
- 15 inter-lib gaps classified: all vendor objects (25 functions), 0 padding, 0 game TU; each span tiled exactly by 470 sigs, ≥ 2 byte-identical candidates each. Per-function names + rule + version table written to `.run/t8/provenance.md`; Q2 closure text `.run/t8/q2.md`.
- Ledger before: 488 vendor rows, 25 `vendor:unproven/<gap tu>` (campaign/ledger.tsv).

## In flight
- coder T8.c2 (background, opus55): inserts `.run/t8/provenance.md` into docs/ops/compiler-pin.md before `## Proven lib units`; replaces segmentation.md Q2 (:114-115) with `.run/t8/q2.md`; ledger.py lib class from `- gap <0xVRAM> <LIB/OBJ>` rows → `vendor:<LIB.LIB>/<LIB>_<OBJ>`; `--check` fails on `vendor:unproven`; self-test control; ledger --build + pull; draw L1 lib set == ledger vendor set check. Log logs/T8.c2.md, commit T8.c2 when green. Run name `t8c2`.

## Hypotheses rejected
- Gaps are padding — zero words ≤ 12/36, every gap holds called functions.
- Gaps are game TUs — every span tiled exactly by 470 signatures.

## Current hypothesis
- c2 lands green; then only verify + log + summary remain.

## Next 5 steps
1. `git log --oneline -3`: confirm T8.c2 commit; read logs/T8.c2.md VERIFIED lines only (grep). If c2 absent/failed: new coder brief naming c1 commit 6d34ced and logs/T8.c2.md.
2. Run task verify: `bash tools/docker/mx.sh sync && bash tools/run.sh --bg t8 -- bash tools/docker/mx.sh run bash -c 'make extract build && python3 tools/mmx6/corpus.py --all && python3 tools/mmx6/census.py --all && python3 tools/mmx6/ledger.py --check'` + `bash tools/run.sh --wait t8 --max 250` → rc 0, LEDGER OK, LEDGER blockers vendor 488.
3. `grep -c vendor:unproven campaign/ledger.tsv` = 0.
4. Write logs/T8.md and tasks/T8.md (template), `PY tools/task_log.py finish T8`.
5. `bash tools/commit_task.sh T8 "lib lane: PsyQ 4.7 named, 15 inter-lib gaps vendor, 488 ledgered vendor"`.

## Gotchas
- harness: hook denies reading tools/mmx6/*.py source for the expert; learn via retriever-code.
- generalizable: boundaries.py lib rows are Ghidra-seeded (named/plate-hinted funcs only) and drop multi-candidate spans; a full sig scan tiles the residual gaps with byte-identical alternatives; an object links once, so placed objects prune candidates.
- psx_ldr sig data is Mac-only (not in the container).

## State to carry verbatim
- Retriever (code) answered sig sources: no report written.
- D1 = A (campaign scope; not T8-relevant). Task closes Triage I2 / segmentation Q2.
- Rationale section not read (expert definition excludes it).

## Coder runs so far
- c1 opus55 — done — logs/T8.c1.md (6d34ced)
- c2 opus55 — running at handoff — logs/T8.c2.md

## Reports commissioned
- none (retriever-code: REPORT no)
