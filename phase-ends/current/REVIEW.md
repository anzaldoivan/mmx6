# REVIEW — Phase 1.5, T5

What ran: Mac host + container mmx6-build: baseline bound2 (.run/logs/t5base.log), T5.c1 (.run/logs/t5c1.log), T5.c2 per-program loop, final clean fleet + bound2 (.run/logs/t5.log)
Results at: phase-ends/current/logs/T5.md, phase-ends/current/logs/T5.c1.md, phase-ends/current/logs/T5.c2.md, config/segmentation.md:127-136
What the expert saw: Classes at T4: jtbl-label 11, carve 1, data-tail 615, ghidra-missed-start 52 (64 phantoms, 615 truncations). After the head rule (c1): jtbl-label 22, carve 0, data-tail 631, ghidra-missed-start 52 (61 phantoms, 644 truncations). After the inventory fixes: all classes 0, phantoms 0, truncations 0. Ledger: empty (config/boundary_exceptions.txt not created; no residue lacked byte evidence). Fixes: B2 side, the head rule (3 phantoms); inventory side, 52 header data symbols, 50 head functions, 581 declared starts (23 multi-return merges), 14 data symbols in 53 overlays.

Decisions needed:
- Accept T5 with an empty exception ledger — Recommended: accept; every class had byte evidence on one side.
- The 53 overlays' starts are now declared from the same byte rules bound2 uses, so bound2 checks consistency there, not independence; and merges are not flagged (1266 by a scratch count) — Recommended: accept for this phase and record a `Next task needs:` line for a merge/independence check in a later phase, no plan change now.

Plan edits proposed:
- `PY tools/plan_edit.py set-status T5 done` (router, after the developer accepts)
