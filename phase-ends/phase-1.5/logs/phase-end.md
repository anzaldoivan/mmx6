# Phase 1.5 close — closer log (2026-10-01)

## Timeline
- `plan_edit.py show --section milestone` refused (section is `Milestone`, 7th time); `show` printed the header Milestone line.
- `run.sh --bg pe15verify -- PY tools/phaseend_index.py verify --verbose` → `VERIFY: GREEN (3/3)` in ~1 s. verify1/verify2.log hold only the `bg=` launch lines: verify ran the `--bg` launches, skipped the `--wait`s, and left fleet (pid 64782) and tools-health-full (pid 64822) running concurrently on one tree. health.log: `REFUSE rock_5x missing build output`, `make: *** [mk/tools-health.mk:20: th-corpus] Error 1`. Copied to `.run/logs/pe15-health-concurrent-false.log`. Verdict rejected as a false green.
- Waited for the stray fleet (exit=0, FLEET 57 of 57). Discarded it because it shared the tree with the failed health run.
- Clause 1, alone: `mx.sh sync` rc 0; `run.sh --bg pe15fleet -- mx.sh run make fleet` + `--wait` → exit=0, `HARNESS 0 disagreements in 6 pairs`, `TOOLS-HEALTH OK 7 rungs`, `FLEET 57 of 57` (`.run/logs/pe15fleet.log`).
- Clause 2, after clause 1: `run.sh --bg pe15health -- mx.sh run make tools-health-full` + `--wait` → exit=0, last line `TOOLS-HEALTH OK 8 rungs` (`.run/logs/pe15health.log`). Grepped CONTROL OK x7, `of` lines, `BOUND2 phantoms=0 truncations=0`, `CENSUS dup_classes=1152 families=1175 reach_size=14/16 unique_tail=2531 of 7345`, `HARNESS 0 disagreements in 7 pairs`.
- Clause 3, after clause 2: `PY tools/audit_public.py` rc 0 (`.run/logs/pe15audit.log`).
- `PY tools/task_log.py gotchas` → 49 lines, 8 summaries (`.run/logs/pe15gotchas.log`). 10 `generalizable:` lines promoted to C0048-C0057. No `workflow:` lines. `binding:` lines checked by grep against docs/ops and config/segmentation.md; all present.
- H7: Files blocks of T2-T8 name HOW_WE_WORK.md or docs/ops/; T1 touches config only. No miss.
- `card.py check` chars=6977 cap=7000 rc 0.

## Judgement
- optscan/boundcheck `of` lines named SCANNED/BOUNDARIES per the approved T3 done-when; read as satisfying the milestone's `<NAME> … of <denominator>` through the plan's own interface; literal-name gap recorded for 1.6.

## Gotchas
- harness: `phaseend_index.py verify` treats `run.sh --bg …` clauses as complete without running their `--wait`, runs later clauses concurrently, and prints GREEN; on 1.5 that green was false (concurrent health run failed). Re-run clauses by hand.
- harness: `plan_edit.py show --section milestone` refuses (section `Milestone`); the PHASE-END brief also names it lower-case.
