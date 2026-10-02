# Codegen map — cc1 2.95.2 (pin gcc2.95.2-psx-aspsx2.86)
A row `L<nn>` names a diff tell, the cc1 pass and gcc 2.95.2 source lines that decide it, and the C lever that moves it.
Each row is byte-proven by its reproducer pair: `python3 tools/mmx6/repro.py --lever L<nn>` (both sides reproduce, bytes differ, `diff:` kind holds).
Check the map (rows, triage, proofs, citations): `python3 tools/mmx6/codegen_map.py --groups <G-x,...>` (container).

## Pass groups
- G-expr: rtl cse addressof gcse cse2 — G-expr.md
- G-loop: loop — G-loop.md
- G-combine: combine regmove — G-combine.md
- G-alloc: lreg greg flow flow2 — G-alloc.md
- G-sched: sched sched2 mach dbr maspsx — G-sched.md
- G-jump: jump jump2 — G-jump.md

## Triage
tell | group | levers | else
--- | --- | --- | ---
a global reloaded after a store through a pointer, or not reloaded where the target reloads sym-global-reload | G-expr | L01 | permuter (T7)
`&local` cached in a callee-saved register vs `addiu $aN,$sp,K` per call sym-phantom-callee-saved | G-expr | L02 | permuter (T7)
counted loop exit `bgez` vs `bgtz`/`bne`, count `N-1` vs `N` sym-loop-reversed | G-loop | L03 | permuter (T7)
`lw` + `andi 0xff` vs a single `lbu` sym-narrow-load | G-combine | L04 | permuter (T7)
