# G-expr — expand, cse, addressof, gcse, cse2 (rtl cse addressof gcse cse2)

## Pass (cc1 2.95.2)
- Store invalidation: every MEM store runs `invalidate`, which drops a table entry only on `true_dependence`. A plain store causes no blanket flush.
  - src:gcc-2.95.2/gcc/cse.c:1832 "|| true_dependence (x, full_mode, p->exp, cse_rtx_varies_p)))"
  - src:gcc-2.95.2/gcc/cse.c:7533 "invalidate (XEXP (dest, 0), GET_MODE (dest));"
- The aliasing fact: a scalar at a fixed address (a global, `mem/f`) never aliases a struct-flagged MEM (`mem/s`) at a varying address.
  - src:gcc-2.95.2/gcc/alias.c:1182 "if (MEM_SCALAR_P (mem1) && MEM_IN_STRUCT_P (mem2)"
  - src:gcc-2.95.2/gcc/alias.c:1269 "return !fixed_scalar_and_varying_struct_p (mem, x, varies);"
  - QImode stores and AND addresses alias everything: src:gcc-2.95.2/gcc/alias.c:1261 "if (mem_mode == QImode || GET_CODE (mem_addr) == AND)".
- Who gets /s: expand flags `*(p+k)` (indexed, pointer PLUS) and aggregates. A bare `*p` stays unflagged.
  - src:gcc-2.95.2/gcc/expr.c:6267 "if (TREE_CODE (exp1) == PLUS_EXPR"
  - The member store code is src:gcc-2.95.2/gcc/expr.c:4770 "MEM_SET_IN_STRUCT_P (to_rtx, 1);".
  - A pointer-to-const gives no RTX_UNCHANGING_P: src:gcc-2.95.2/gcc/expr.c:6284 "RTX_UNCHANGING_P (temp) = TREE_READONLY (exp) & TREE_STATIC (exp);".
- Calls: a call flushes memory and drops the call-clobbered hard regs. Pseudo values (callee-saved candidates) survive.
  - src:gcc-2.95.2/gcc/cse.c:7665 "invalidate_memory ();"
  - src:gcc-2.95.2/gcc/cse.c:1962 "if (TEST_HARD_REG_BIT (regs_invalidated_by_call, regno))"
- Call arguments: a register argument goes through a pseudo only if costly (rtx_cost > 2) and small-register-classes or in a loop. Otherwise, the compiler expands it straight into `$aN` per site.
  - src:gcc-2.95.2/gcc/calls.c:662 "&& rtx_cost (args[i].value, SET) > 2"
  - src:gcc-2.95.2/gcc/calls.c:664 "|| preserve_subexpressions_p ()))"
- Block boundaries and jump equivalences:
  - src:gcc-2.95.2/gcc/cse.c:893 "new_basic_block ()"
  - src:gcc-2.95.2/gcc/cse.c:6125 "record_jump_equiv (insn, taken)"

## From BFM (gcc 2.7.2) — G67 translation
- X1 (cross-call value CSE) survives. `h(x&0xffff); g(); h(x&0xffff)` keeps `andi $16,$4,0xffff` across the call. An identity asm `__asm__("":"=r"(x):"0"(x))` before the 2nd use gives `move $16,$4` + `andi` per site (observed in this task, scratch). Calls drop only hard regs: src:gcc-2.95.2/gcc/cse.c:1962 "if (TEST_HARD_REG_BIT (regs_invalidated_by_call, regno))". It is a lead (an asm fence, not a row).
- X2 (cross-call address caching) changed. 2.95.2 expands `h(buf)` per site (`addiu $4,$29,16` each call, no $s0): cheap args skip the pseudo, src:gcc-2.95.2/gcc/calls.c:662 "&& rtx_cost (args[i].value, SET) > 2". Caching now comes from a named pointer (`void *q = buf; h(q); h(q);`), with no asm needed. The row is L02.
- X3 (/s MEM_IN_STRUCT_P aliasing) survives. `G=1; return *p + p[1];` keeps the `*p` load under the store. The struct members `p->f + p->g` float above it (observed, scratch). The sched pass decides this (G-sched). The decider is src:gcc-2.95.2/gcc/alias.c:1182 "if (MEM_SCALAR_P (mem1) && MEM_IN_STRUCT_P (mem2)". It is a lead.
- X4 (cse store-flush) has a changed mechanism and the same lever. 2.95.2 no longer flushes on a plain store (note_mem_written only handles stack pushes). The reload after `*p=` comes from `true_dependence` because the bare deref lacks /s: src:gcc-2.95.2/gcc/cse.c:1832 "|| true_dependence (x, full_mode, p->exp, cse_rtx_varies_p)))". The u8 stores still flush (QImode aliases all, `char *p` reload observed): src:gcc-2.95.2/gcc/alias.c:1261 "if (mem_mode == QImode || GET_CODE (mem_addr) == AND)". The row is L01.
- X5 (if/else diamond fence) survives (not reproduced in this task). A block start resets the table: src:gcc-2.95.2/gcc/cse.c:893 "new_basic_block ()". It is a lead.
- X6 (dead-branch retention) survives (not reproduced in this task). The code is src:gcc-2.95.2/gcc/cse.c:6125 "record_jump_equiv (insn, taken)". It is a lead. The 2.8.1 1000-insn flush is not checked.

## Levers
L01 | G-expr | tell: the code reloads a global (`lw` again) after a store through a bare `*p` | mechanism: cse src:gcc-2.95.2/gcc/cse.c:1832 "true_dependence (x, full_mode, p->exp, cse_rtx_varies_p)" src:gcc-2.95.2/gcc/alias.c:1182 "if (MEM_SCALAR_P (mem1) && MEM_IN_STRUCT_P (mem2)" src:gcc-2.95.2/gcc/expr.c:6267 "if (TREE_CODE (exp1) == PLUS_EXPR" | lever: store through an indexed or member form (`p[k]=`, `p->f=`, /s) to keep the global. Use a bare `*p=` (or any u8 store) to force the reload. | proof: repro/G-expr/storeflush | retail: -
  - dump (a-side .cse): "(set (mem:SI (reg/v:SI 81) 0)"
  - cookbook: C0075
L02 | G-expr | tell: the code has `&local` in a callee-saved `$s0` and `move $aN,$s0` per call, vs `addiu $aN,$sp,K` at each call | mechanism: rtl src:gcc-2.95.2/gcc/calls.c:662 "&& rtx_cost (args[i].value, SET) > 2" src:gcc-2.95.2/gcc/calls.c:664 "preserve_subexpressions_p ()" | lever: pass a named pointer variable (`void *q = buf; h(q);`) to cache the address. Pass `buf` directly for per-site `addiu`. | proof: repro/G-expr/addrcache | retail: -
  - dump (a-side .rtl): "(reg/v:SI 81)) -1 (nil)"
  - cookbook: C0076
L10 | G-expr | tell: an `sll rI,rI,2` scales an index before the `addu`, where the target adds a byte offset directly (or the reverse) | mechanism: rtl src:gcc-2.95.2/gcc/c-typeck.c:2680 "size_exp = c_size_in_bytes (TREE_TYPE (result_type));" src:gcc-2.95.2/gcc/c-typeck.c:2726 "build_binary_op (MULT_EXPR, intop," src:gcc-2.95.2/gcc/expmed.c:2352 "synth_mult (&alg, val, mult_cost);" | lever: `p[i]` on `int *p` scales i by 4 (`sll 2`). `*(int *)((char *)p + i)` adds i unscaled (the scaffold's byte offset). | proof: repro/G-expr/shiftx4 | retail: -
  - dump (a-side .rtl): "(ashift:SI (reg:SI 84)"
  - cookbook: C0084
L12 | G-expr | tell: the code loads a pointer out of a struct (`lw $5,0($4)` for `p->a`) again after each member store through it. The target loads it once (or the reverse). | mechanism: cse src:gcc-2.95.2/gcc/cse.c:1832 "true_dependence (x, full_mode, p->exp, cse_rtx_varies_p)" src:gcc-2.95.2/gcc/alias.c:1269 "return !fixed_scalar_and_varying_struct_p (mem, x, varies);" | lever: name the base in a local (`struct S2 *q = p->a; q->x = ...`) to load it once. Repeat `p->a->` to reload per store. Both MEMs are varying /s: the store may alias the base, and cse drops it. The a-side has 10 insns and the b-side has 8. | proof: repro/G-expr/baseload | retail: -
  - dump (a-side .cse): "(set (mem/s:SI (plus:SI (reg:SI 84)"
  - cookbook: C0086
L14 | G-expr | tell: a `short` that is read and masked loads with `lhu` where the target has `lh` (or the reverse), with the mask kept | mechanism: rtl src:gcc-2.95.2/gcc/c-typeck.c:2072 "shorten = -1;" src:gcc-2.95.2/gcc/c-typeck.c:2387 "tree arg0 = get_narrower (op0, &unsigned0);" src:gcc-2.95.2/gcc/c-typeck.c:2411 "if (shorten == -1)" | lever: mask the narrow read in the expression (`(*p) & 0xFFF`). The front end then shortens the & onto the HImode value, and the result is lhu. Read it into an `int` temp first (`int t = *p; t & 0xFFF`). Then there is no visible conversion to narrow, and the result is lh. | proof: repro/G-expr/shorten | retail: -
  - dump (a-side .rtl): "(and:SI (subreg:SI (reg:HI 83) 0)"
  - cookbook: C0088
