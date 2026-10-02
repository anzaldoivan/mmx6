MILESTONE: green

## Recap
Phase 1.6 built the tools that let one matched function count many times. A "dup class" is a group of functions whose machine code is identical once addresses are masked out; "banking" a function means putting its C source into the real build so that the whole game binary still rebuilds byte-for-byte; the "fleet" is the 57 game programs (the main executable plus 56 overlays) rebuilt and hash-checked together. The phase first fixed the function-boundary checker, which found 1,189 places where the disassembler had fused several real functions into one; splitting them raised the function count from 7,345 to 8,534 with the fleet still identical. It then added a duplicate finder, one shared header for data types, a five-step ladder that moves a matched function into its real source file and re-checks the whole binary, and tools that cut source files at jump tables and at function boundaries; one 15-instruction function, matched by hand, was placed at all 416 of its copies, raising matched functions from 285 to 701 of 8,534 (282 of them empty stubs). Finally, a filter now picks what to decompile next and counts why it set the rest aside (4,840 of 7,833 set aside), and compiling Mega Man X4's published source under X6's compiler showed 2,042 X6 functions with an identical X4 counterpart, a large source for later phases.

Milestone re-verified clause by clause in this session: fleet exit 0, `FLEET 57 of 57`, `C MATCHED 701 of 8534 functions (282 empty-body; banked 419)`, `HARNESS 0 disagreements in 7 pairs`; tools-health-full exit 0, `TOOLS-HEALTH OK 16 rungs` with every named line present (merges=0, INDEPENDENT 1985 of 2031, DRY-RUN gated 416 of 416, REGISTRY OK 416, TWINS 277792 of 277792, RECONCILE/TYPES CONTROL OK, CARVE jtbl and opt OK, DRAW refused 4840 of 7833 by layer, HARNESS 0 in 8 pairs, 17 CONTROL OK); one X4SHARE line in docs/prior-art.md:28; audit rc 0.

Deviation (harness): `phaseend_index.py verify` reported GREEN 4/4 after only launching the background fleet and health runs, and started both at once; the health run beside the fleet failed. Its verdict was discarded and the clauses were rerun one after another (logs/PHASE-END.md).

H7 check: every summary that names tools, pins or build commands also lists docs/ops/ or HOW_WE_WORK.md; no miss.

## Decisions that still bind
- norm: types live in include/mmx6/types.h with evidence, keyed by shape, fleet-gated → rule G105 (T3).
- norm: a shared body is one src/shared file included per member, members differ only by name/address #defines, registry fail-closed → rule G106 (T4, T5, T7).
- norm: sibling-game C is measured and adopted under X6's pin, counts only in git → rule G107 (T8).
- contract: bound2 merge classes, independence basis, over-merge fix by sized starts → docs/ops/oracles.md + th-bound2 self-test (T1).
- contract: twin band (exact/near, RATIO 0.3, base-rate seed) → docs/ops/decomp-environment.md sig row + th-sig (T2).
- contract: bank.py R1-R5 verdicts, body sha1 invariant, planted-sibling self-test → docs/ops/decomp-environment.md bank row + th-selftests (T4, T6.1).
- contract: registry check and per-member gating; overlay c units need `auto_decompile_empty_functions: false` → docs/ops/decomp-environment.md + th-propagate(-full) (T5).
- contract: carve record per binary, `CFLAGS_<tu>`, `.rodata` subsegment type → docs/ops/decomp-environment.md "Carves" + th-carve (T6; G43).
- contract: family remap rungs and family registry rows → docs/ops/decomp-environment.md + th-remap (T7).
- contract: walls.txt row format, verdict layers L1-L4, draw_exclude staleness audit, P8 agreement → docs/ops/decomp-environment.md + th-walls, th-draw, harness P8 (T9; G52).
- Next task needs: mmx4's 2,042 exact partners as a bank source for leverage-first waves (critic-deferred to 1.7/1.8; G102, G107).
- Next task needs: 579 L1 refusals wait on lib-unit triple proofs and overlay jtbl carves (overlay yamls have no rodata block); walls.txt and draw_exclude.txt are still empty.
- Next task needs: family 40505e80's 258 siblings differ by one offset immediate; they need a parameterised body, not a remap (T7).
- Next task needs: harness fix for `phaseend_index.py verify` on bg/wait clauses (judge the `--wait` result, run clauses sequentially).
