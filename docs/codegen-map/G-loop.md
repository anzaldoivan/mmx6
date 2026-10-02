# G-loop — loop optimizer (loop)

## Pass (cc1 2.95.2)
- loop reversal (dbra): an up-count biv whose only uses are the increment and the exit test is rewritten as a count-down to `bgez`
  - src:gcc-2.95.2/gcc/loop.c:7654 "check_dbra_loop (loop_end, insn_count, loop_start, loop_info)"
  - dump text: src:gcc-2.95.2/gcc/loop.c:7885 "Can reverse loop", src:gcc-2.95.2/gcc/loop.c:8162 "Reversed loop"
- invariant loads: a MEM is invariant only if RTX_UNCHANGING_P or no call/unknown store in the loop
  - src:gcc-2.95.2/gcc/loop.c:3254 "if (RTX_UNCHANGING_P (x))"
  - a non-const call sets it: src:gcc-2.95.2/gcc/loop.c:2452 "unknown_address_altered = 1;"
- induction variables: src:gcc-2.95.2/gcc/loop.c:5928 "basic_induction_var (x, mode, dest_reg, p, inc_val, mult_val, location)", src:gcc-2.95.2/gcc/loop.c:6931 "combine_givs (bl)", src:gcc-2.95.2/gcc/loop.c:8333 "maybe_eliminate_biv_1 (x, insn, bl, eliminate_p, where)"

## From BFM (gcc 2.7.2) — G67 translation
- P1 const-pointer hoist: gone. `const int *p` and `int *p` give identical code (no hoist past `f(i)`, observed this task, scratch): expand never sets RTX_UNCHANGING_P from pointer-to-const, src:gcc-2.95.2/gcc/expr.c:6284 "RTX_UNCHANGING_P (temp) = TREE_READONLY (exp) & TREE_STATIC (exp);", so the invariant_p arm src:gcc-2.95.2/gcc/loop.c:3254 "if (RTX_UNCHANGING_P (x))" is not reached and the call wins (src:gcc-2.95.2/gcc/loop.c:2452 "unknown_address_altered = 1;").
- P2 loop reversal: changed. 2.95.2 normalises like 2.8.1: start 0 and start 1 (`i=1;i<11`) both reverse to `li 9 ... bgez`; a loop with a call in it (`g()`) is also reversed (observed, scratch). An index use `A[i]=0` is still reversed (pointer walked down). Lever: write the down-count yourself. Row L03.
- P3 index-biv elimination: changed (lead). maybe_eliminate_biv_1 keeps the 2.8.1 `&& 0` disables: src:gcc-2.95.2/gcc/loop.c:8385 "&& 0)". Not reproduced this task.
- P4 IV count: survives (lead). src:gcc-2.95.2/gcc/loop.c:6931 "combine_givs (bl)". Not reproduced.
- P5 increment position: survives as code (lead, unproven as in BFM): src:gcc-2.95.2/gcc/loop.c:3862 "not_every_iteration = 1;".
- P6 giv-init fence: survives (lead; asm fence). Not reproduced.
- exit-test duplication: still jump.c, no lever: src:gcc-2.95.2/gcc/jump.c:341 "if (duplicate_loop_exit_test (insn))".

## Levers
L03 | G-loop | tell: counted loop as `li N-1` ... `addu -1` + `bgez`, where the target has `li N` + `bgtz`/`bne` (or the reverse) | mechanism: loop src:gcc-2.95.2/gcc/loop.c:7654 "check_dbra_loop (loop_end, insn_count, loop_start, loop_info)" src:gcc-2.95.2/gcc/loop.c:8162 "Reversed loop" | lever: `for (i = 0; i < N; i++)` with the counter otherwise unused is reversed to `bgez`; write `for (i = N; i > 0; i--)` for `bgtz`, `i != 0` for `bne` | proof: repro/G-loop/dbra | retail: -
  - dump (a-side .loop): "Reversed loop and added reg_nonneg"
  - cookbook: C0077
