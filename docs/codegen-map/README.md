# Codegen map — cc1 2.95.2 (pin gcc2.95.2-psx-aspsx2.86)
A row `L<nn>` names a diff tell, the cc1 pass and gcc 2.95.2 source lines that decide it, and the C lever that moves it.
Each row is byte-proven by its reproducer pair: `python3 tools/mmx6/repro.py --lever L<nn>` (both sides reproduce, bytes differ, `diff:` kind holds).
Check the map (rows, triage against cookbook/C0002.md, proofs, citations), all groups: `python3 tools/mmx6/codegen_map.py --check` (container). A levers cell `→ permuter` means no C lever: hand the function to the permuter.

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
two values' `$16`/`$17` swapped, equal ref counts and live lengths sym-sreg-swapped | G-alloc | L05 | permuter (T7)
two values' `$16`/`$17` swapped, unequal ref counts sym-sreg-swapped | G-alloc | L06 | permuter (T7)
a global `lw` held below a pointer store, or hoisted above it sym-load-below-store | G-sched | L07 | permuter (T7)
`beqz` vs `bnez` with the arms' code in the other order sym-branch-arms-swapped | G-jump | L08 | permuter (T7)
two `jal` to one callee in if/else arms vs one shared `jal` sym-cross-jump | G-jump | L09 | permuter (T7)
an index scaled `sll rI,rI,2` before the `addu` vs an unscaled byte-offset `addu` sym-shift-x4 | G-expr | L10 | permuter (T7)
two spilled values' stack slots swapped (`sw $2,52($sp)` vs `56($sp)`) sym-spill-slot | G-alloc | L11 | permuter (T7)
a pointer loaded out of a struct (`p->a`) again after each member store through it, or loaded once sym-global-reload | G-expr | L12 | permuter (T7)
a loop guarded by its own copied exit test (`sltu`+`beqz`) vs a cheaper source guard (`blez` on the count) sym-loop-reversed | G-jump | L13 | permuter (T7)
a masked `short` read as `lhu` vs `lh` sym-narrow-load | G-expr | L14 | permuter (T7)
`lhu` + `sll 16` + `sra 16` vs one `lh` (a volatile read) sym-narrow-load | G-combine | L15 | permuter (T7)
every small edit moves 20+ instructions (a register-pressure lock) sym-register-pressure | G-alloc | → permuter | permuter (T7)
