# G-loop — loop optimizer (loop)

## Pass (cc1 2.95.2)
- Loop reversal (dbra): the pass rewrites an up-count biv whose only uses are the increment and the exit test as a count-down to `bgez`.
  - src:gcc-2.95.2/gcc/loop.c:7654 "check_dbra_loop (loop_end, insn_count, loop_start, loop_info)"
  - The dump text is src:gcc-2.95.2/gcc/loop.c:7885 "Can reverse loop", src:gcc-2.95.2/gcc/loop.c:8162 "Reversed loop".
- Invariant loads: a MEM is invariant only if it is RTX_UNCHANGING_P or the loop has no call/unknown store.
  - src:gcc-2.95.2/gcc/loop.c:3254 "if (RTX_UNCHANGING_P (x))"
  - A non-const call sets it: src:gcc-2.95.2/gcc/loop.c:2452 "unknown_address_altered = 1;".
- Induction variables: src:gcc-2.95.2/gcc/loop.c:5928 "basic_induction_var (x, mode, dest_reg, p, inc_val, mult_val, location)", src:gcc-2.95.2/gcc/loop.c:6931 "combine_givs (bl)", src:gcc-2.95.2/gcc/loop.c:8333 "maybe_eliminate_biv_1 (x, insn, bl, eliminate_p, where)"

## From BFM (gcc 2.7.2) — G67 translation
- P1 (const-pointer hoist) is gone. `const int *p` and `int *p` give identical code (no hoist past `f(i)`, observed in this task, scratch). The cause is that expand never sets RTX_UNCHANGING_P from pointer-to-const: src:gcc-2.95.2/gcc/expr.c:6284 "RTX_UNCHANGING_P (temp) = TREE_READONLY (exp) & TREE_STATIC (exp);". So the code does not reach the invariant_p arm src:gcc-2.95.2/gcc/loop.c:3254 "if (RTX_UNCHANGING_P (x))", and the call wins (src:gcc-2.95.2/gcc/loop.c:2452 "unknown_address_altered = 1;").
- P2 (loop reversal) changed. 2.95.2 normalises like 2.8.1. Start 0 and start 1 (`i=1;i<11`) both reverse to `li 9 ... bgez`, and a loop with a call in it (`g()`) is also reversed (observed, scratch). An index use `A[i]=0` is still reversed (the pointer is walked down). The lever is to write the down-count yourself. The row is L03.
- P3 (index-biv elimination) changed (a lead). maybe_eliminate_biv_1 keeps the 2.8.1 `&& 0` disables: src:gcc-2.95.2/gcc/loop.c:8385 "&& 0)". It is not reproduced in this task.
- P4 (IV count) survives (a lead). The code is src:gcc-2.95.2/gcc/loop.c:6931 "combine_givs (bl)". It is not reproduced.
- P5 (increment position) survives as code (a lead, unproven as in BFM): src:gcc-2.95.2/gcc/loop.c:3862 "not_every_iteration = 1;".
- P6 (giv-init fence) survives (a lead, an asm fence). It is not reproduced.
- Exit-test duplication is still in jump.c and has no lever: src:gcc-2.95.2/gcc/jump.c:341 "if (duplicate_loop_exit_test (insn))".

## Levers
L03 | G-loop | tell: a counted loop is `li N-1` ... `addu -1` + `bgez`, where the target has `li N` + `bgtz`/`bne` (or the reverse) | mechanism: loop src:gcc-2.95.2/gcc/loop.c:7654 "check_dbra_loop (loop_end, insn_count, loop_start, loop_info)" src:gcc-2.95.2/gcc/loop.c:8162 "Reversed loop" | lever: the pass reverses `for (i = 0; i < N; i++)` with the counter otherwise unused to `bgez`. Write `for (i = N; i > 0; i--)` for `bgtz`, and `i != 0` for `bne`. | proof: repro/G-loop/dbra | retail: -
  - dump (a-side .loop): "Reversed loop and added reg_nonneg"
  - cookbook: C0077
