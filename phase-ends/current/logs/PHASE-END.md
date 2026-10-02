# Phase 1.7 — phase-end log

Closer: expert-opus55 (PHASE-END brief), 2026-10-02. Inputs: plan Milestone + Context (plan_edit.py show), tasks/T1-T8.md, `task_log.py gotchas` (43 lines in 8 summaries).

## Milestone clauses (sequential, each through run.sh)
1. `run.sh --bg pe-m1 -- bash -c 'mx.sh build && mx.sh sync && mx.sh run make toolchain-check'`; `--wait pe-m1 --max 250` → exit 0; `PERMUTER 059609d4…`, `GCCSRC 2.95.2 064e1cb06ea5…d72482 patches 3`. GREEN (.run/logs/pe-m1.log)
2. `run.sh --bg pe-fleet -- mx.sh run make fleet`; two waits → exit 0; last line `FLEET 57 of 57`; `HARNESS 0 disagreements in 7 pairs`; `C MATCHED 701 of 8534 functions (282 empty-body; banked 419)`; `TOOLS-HEALTH OK 23 rungs`. GREEN (.run/logs/pe-fleet.log)
3. `run.sh --bg pe-health -- mx.sh run make tools-health-full`; two waits → exit 0; last line `TOOLS-HEALTH OK 24 rungs` (k ≥ 22); `CITES OK 164 of 164` (c ≥ 6), `CITES CONTROL OK`, `DUMPS CONTROL OK`, `ALLOC CONTROL OK`, `REPRO 30 of 30 tells reproduced`, `MAP OK 6 of 6 pass groups; levers 15 byte-proven` (l ≥ 6), `TRIAGE OK 16 rows, 0 TODO`, `COOKBOOK OK 89 entries, 89 rows, 0 orphans, 0 dangling`, `COOKBOOK CONTROL OK`, `PERMUTE CONTROL OK`, `PLATEAU CONTROL OK` (plants: regalloc 9/22, sched 2/5, branch 3/13, none 0/6); 25 distinct `<NAME> CONTROL OK`, 0 `CONTROL FAIL`; `HARNESS 0 disagreements in 8 pairs` (full). GREEN (.run/logs/pe-health.log)
   - 0 FAIL: 58 lines contain `FAIL`; grep-classified: indented plant lines, `CONTROL ok …`, `.run/repro-selftest`, `LEVER L95-L98` planted, boundcheck self-test (`BOUNDARIES FAIL` ×3, each followed by `refused`, then `BOUNDCHECK CONTROL OK`), probe.py self-test mutation (8× `func_80055A04 … FAIL 31/32`, then `SELF-TEST OK`). No rung failure.
4. `run.sh --bg pe-perm -- mx.sh run python3 tools/mmx6/permute.py --draft drafts/SLUS_013.95/func_80042F20.c --iterations 300 --seed 1`; wait → exit 0; `PERMUTE func_80042F20 iterations 300 distinct 301 base 9 best 9` (n ≥ 300, d ≥ 2, s ≤ b). GREEN (.run/logs/pe-perm.log)
5. `mx.sh run python3 tools/mmx6/plateau.py --draft drafts/SLUS_013.95/func_80042F20.c` → rc 0, one line `PLATEAU func_80042F20 regalloc residual 9/12 rows L05,L06,L11,permuter src draft`. GREEN (.run/logs/pe-plateau.log)
6. `PY tools/audit_public.py` → rc 0, `0 offenders among 986 paths`. GREEN (.run/logs/pe-audit.log)

## Deviations
- `phaseend_index.py verify` not run: plan Context records it launched bg clauses concurrently (1.6) and the milestone says never concurrently; clauses run by hand in order.
- `--wait --max 250`, not 280 (T8 harness gotcha: 280 overruns the tool-call cap); waits repeated until done, as the clause allows.

## H7
T1-T8 Files: each summary naming tools/Dockerfile/Makefile/mk lists docs/ops/ (T8 also HOW_WE_WORK.md). No miss.

## Promotions
- generalizable (13) → cookbook C0090-C0102 via `cookbook_add.sh` (body script .run/pe17/promote.sh). C0096 title first held a literal `|` (broke its own INDEX row); retitled "containing a pipe" in C0096.md + INDEX row by hand. `cookbook_check.py --check` → `COOKBOOK OK 102 entries, 102 rows, 0 orphans, 0 dangling`.
- workflow (1, T4:30) → folded into existing skill `container-scratch-not-synced` (steps + description + card line). `skill_add.py container-sync-wipes-build` was run first; it appends a card line, pushing the card to 7134 > 7000; reverted (git checkout HOW_WE_WORK.md, scaffold removed) and merged instead. Card after: 6971 of 7000 (`card.py check`).
- binding (24 lines) → all already in product docs (grep: docs/ops/decomp-environment.md, compiler-pin.md, mmx6-hosts.md, docs/codegen-map/*.md, cookbook/C0002.md) with tool self-tests; one norm → rule G108 (`rules_add.py add`).
- harness (9): plan hash naming (T1:32); sed -n hook on tools/ (T2:29, T8:25); retriever-digest report path (T5:27, T6:28); zsh one-argv loop (T6:29); sync wipes extracted/ in verify chains (T7:32); commit_task.sh needs explicit HOW_WE_WORK.md (T8:23); `--max 280` overrun (T8:24). Left for the auditor; recurring retriever report path (twice) worth a fix.
- harness (this closer): `skill_add.py` appends to `HOW_WE_WORK.md ## Skills` without checking `card.max_chars`; `--help` does not say it writes the card. A `cat` of a SKILL.md in a compound Bash call was denied by the learn-from-help hook.

## Commits
- see `git log --oneline -3` after `commit_task.sh PHASE-END`.
