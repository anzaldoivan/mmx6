MILESTONE: green

## Recap
Phase 1.5 made the project's measuring tools honest before real decompilation starts. A "scanner" here is a script that walks the built game code and counts something, such as functions, function boundaries or duplicated code. Every scanner now prints its denominator, meaning the total it counts against, read from the build rather than typed in by hand. Each scanner also passes a "known-true control", a planted case whose correct answer is known in advance. A second, independent boundary checker now finds 0 phantom functions and 0 truncated ones across all 57 programs. A new differential harness asks the same question of two independent sources (for example, how many functions are already in C) and found 0 disagreements. The census shows where effort pays off: 1,152 classes of byte-identical duplicate functions, 1,175 structural families (same instruction shape, different registers or constants) and a unique tail of 2,531 functions that resemble no other function. 285 of 7,345 functions are matched today, 282 of them empty stubs.

## Milestone evidence (closer run 2026-10-01, sequential, clean)
- fleet: `.run/logs/pe15fleet.log` exit=0, last line `FLEET 57 of 57`, `HARNESS 0 disagreements in 6 pairs`, `TOOLS-HEALTH OK 7 rungs`
- tools-health-full: `.run/logs/pe15health.log` exit=0, last line `TOOLS-HEALTH OK 8 rungs`; CONTROL OK for CORPUS, OPTSCAN, BOUNDCHECK, BOUND2, CENSUS, REPORT, HARNESS; `BOUND2 phantoms=0 truncations=0 ledgered=0 of 7345 functions in 57 programs`; `CENSUS dup_classes=1152 families=1175 reach_size=14/16 unique_tail=2531 of 7345`; `HARNESS 0 disagreements in 7 pairs`
- `of <denominator>` lines: CORPUS `… of 1979192 text bytes in 57 programs`, optscan `SCANNED 7060 of 7060 functions in 57 of 57 programs`, boundcheck `BOUNDARIES OK 57 of 57 programs`, BOUND2/CENSUS/REPORT/HARNESS `… of <N>`
- audit: `PY tools/audit_public.py` rc 0 (`.run/logs/pe15audit.log`, 0 offenders among 746 paths)

## Deviations
- `phaseend_index.py verify` printed `VERIFY: GREEN (3/3)` falsely. It ran the `run.sh --bg` launches without the `--wait` clauses, so fleet and tools-health-full ran concurrently on one tree. The health log of that run shows `th-corpus` Error 1 (missing build/rock_*.elf), kept at `.run/logs/pe15-health-concurrent-false.log`. The verdict above comes from clauses re-run by hand one after another, never from the verifier's GREEN.
- optscan and boundcheck name their `of` lines `SCANNED …` and `BOUNDARIES OK …`, not `OPTSCAN …`/`BOUNDCHECK …`. These are the formats the approved plan's T3 done-when sets, so the clause is read through the plan's own interface, and their `<NAME> CONTROL OK` lines are literal. The literal `<NAME> … of` wording is not met for these two tools; see Next task needs.
- H7: every summary whose Files name tools, mk or fleet.sh also lists HOW_WE_WORK.md or docs/ops/; no miss.

## Decisions that still bind
- Contracts (in the tools and documented in docs/ops/decomp-environment.md, docs/ops/oracles.md, config/segmentation.md; each guarded by its tool's `--self-test` rung in mk/tools-health.mk): corpus span kinds and lanes (T2); optscan denominator = asm|include_asm rows and boundcheck's empty-edge refusal (T3); B2 starts, extents, phantom/truncation classes and ledger (T4, T5); dup key, family key, reach, unique tail (T6); progress, difficulty and dup payoff (T7); harness pairs P1-P7, runs.log line, NOT-RUN counts as a disagreement (T8).
- Environment fact: `make tools-health-full` runs only after a fleet and rebuilds two units in place (docs/ops/decomp-environment.md; card Build/run/test row).
- Environment fact: the health chain lives at `mk/tools-health.mk` (D1); the card and docs/ops already say so.
- Next task needs: GENERATION_PLAN.md phase 1.5 milestone still reads `` `build/tools-health.mk` green ``; the router should amend it to `mk/tools-health.mk` (D1) when it closes 1.5.
- Next task needs: give optscan and boundcheck name-prefixed `of` lines (`OPTSCAN SCANNED …`, `BOUNDCHECK BOUNDARIES OK …`), or reword future milestones, so the `<NAME> … of` clause holds literally.
- Next task needs: P1 and P5 are consistency checks, not independent sources; the independent merge check is deferred to 1.6 (I4).
- Next task needs: `phaseend_index.py verify` must run `--bg` + `--wait` clause pairs to completion, one after another, before it reports GREEN (harness fix, auditor).
- Next task needs: the card sits at 6977 of 7000 chars; the next card edit needs a trim first.
