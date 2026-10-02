# G-expr — expand, cse, addressof, gcse, cse2 (rtl cse addressof gcse cse2)

## Pass (cc1 2.95.2)
- store invalidation: every MEM store runs `invalidate`, which drops a table entry only on `true_dependence` (no blanket flush on a plain store)
  - src:gcc-2.95.2/gcc/cse.c:1832 "|| true_dependence (x, full_mode, p->exp, cse_rtx_varies_p)))"
  - src:gcc-2.95.2/gcc/cse.c:7533 "invalidate (XEXP (dest, 0), GET_MODE (dest));"
- the aliasing fact: a scalar at a fixed address (a global, `mem/f`) never aliases a struct-flagged MEM (`mem/s`) at a varying address
  - src:gcc-2.95.2/gcc/alias.c:1182 "if (MEM_SCALAR_P (mem1) && MEM_IN_STRUCT_P (mem2)"
  - src:gcc-2.95.2/gcc/alias.c:1269 "return !fixed_scalar_and_varying_struct_p (mem, x, varies);"
  - QImode stores and AND addresses alias everything: src:gcc-2.95.2/gcc/alias.c:1261 "if (mem_mode == QImode || GET_CODE (mem_addr) == AND)"
- who gets /s: expand flags `*(p+k)` (indexed, pointer PLUS) and aggregates; a bare `*p` stays unflagged
  - src:gcc-2.95.2/gcc/expr.c:6267 "if (TREE_CODE (exp1) == PLUS_EXPR"
  - member store: src:gcc-2.95.2/gcc/expr.c:4770 "MEM_SET_IN_STRUCT_P (to_rtx, 1);"
  - pointer-to-const gives no RTX_UNCHANGING_P: src:gcc-2.95.2/gcc/expr.c:6284 "RTX_UNCHANGING_P (temp) = TREE_READONLY (exp) & TREE_STATIC (exp);"
- calls: memory flushed, call-clobbered hard regs dropped; pseudo values (callee-saved candidates) survive
  - src:gcc-2.95.2/gcc/cse.c:7665 "invalidate_memory ();"
  - src:gcc-2.95.2/gcc/cse.c:1962 "if (TEST_HARD_REG_BIT (regs_invalidated_by_call, regno))"
- call arguments: a register argument goes through a pseudo only if costly (rtx_cost > 2) and small-register-classes or in a loop; else expanded straight into `$aN` per site
  - src:gcc-2.95.2/gcc/calls.c:662 "&& rtx_cost (args[i].value, SET) > 2"
  - src:gcc-2.95.2/gcc/calls.c:664 "|| preserve_subexpressions_p ()))"
- block boundaries and jump equivalences
  - src:gcc-2.95.2/gcc/cse.c:893 "new_basic_block ()"
  - src:gcc-2.95.2/gcc/cse.c:6125 "record_jump_equiv (insn, taken)"

## From BFM (gcc 2.7.2) — G67 translation
- X1 cross-call value CSE: survives. `h(x&0xffff); g(); h(x&0xffff)` keeps `andi $16,$4,0xffff` across the call; identity asm `__asm__("":"=r"(x):"0"(x))` before the 2nd use gives `move $16,$4` + `andi` per site (observed this task, scratch). Calls drop only hard regs: src:gcc-2.95.2/gcc/cse.c:1962 "if (TEST_HARD_REG_BIT (regs_invalidated_by_call, regno))". Lead (asm fence; not a row).
- X2 cross-call address caching: changed. 2.95.2 expands `h(buf)` per site (`addiu $4,$29,16` each call, no $s0): cheap args skip the pseudo, src:gcc-2.95.2/gcc/calls.c:662 "&& rtx_cost (args[i].value, SET) > 2". Caching now comes from a named pointer (`void *q = buf; h(q); h(q);`), no asm needed. Row L02.
- X3 /s MEM_IN_STRUCT_P aliasing: survives. `G=1; return *p + p[1];` keeps the `*p` load under the store; struct members `p->f + p->g` float above it (observed, scratch; decided in sched, G-sched). Decider: src:gcc-2.95.2/gcc/alias.c:1182 "if (MEM_SCALAR_P (mem1) && MEM_IN_STRUCT_P (mem2)". Lead.
- X4 cse store-flush: changed mechanism, same lever. 2.95.2 no longer flushes on a plain store (note_mem_written only handles stack pushes); the reload after `*p=` comes from `true_dependence` because the bare deref lacks /s: src:gcc-2.95.2/gcc/cse.c:1832 "|| true_dependence (x, full_mode, p->exp, cse_rtx_varies_p)))". u8 stores still flush (QImode aliases all; `char *p` reload observed): src:gcc-2.95.2/gcc/alias.c:1261 "if (mem_mode == QImode || GET_CODE (mem_addr) == AND)". Row L01.
- X5 if/else diamond fence: survives (not reproduced this task). A block start resets the table: src:gcc-2.95.2/gcc/cse.c:893 "new_basic_block ()". Lead.
- X6 dead-branch retention: survives (not reproduced this task). src:gcc-2.95.2/gcc/cse.c:6125 "record_jump_equiv (insn, taken)". Lead; the 2.8.1 1000-insn flush not checked.

## Levers
L01 | G-expr | tell: a global reloaded (`lw` again) after a store through a bare `*p` | mechanism: cse src:gcc-2.95.2/gcc/cse.c:1832 "true_dependence (x, full_mode, p->exp, cse_rtx_varies_p)" src:gcc-2.95.2/gcc/alias.c:1182 "if (MEM_SCALAR_P (mem1) && MEM_IN_STRUCT_P (mem2)" src:gcc-2.95.2/gcc/expr.c:6267 "if (TREE_CODE (exp1) == PLUS_EXPR" | lever: store through an indexed or member form (`p[k]=`, `p->f=`, /s) to keep the global; a bare `*p=` (or any u8 store) to force the reload | proof: repro/G-expr/storeflush | retail: -
  - dump (a-side .cse): "(set (mem:SI (reg/v:SI 81) 0)"
  - cookbook: C0075
L02 | G-expr | tell: `&local` in a callee-saved `$s0` and `move $aN,$s0` per call, vs `addiu $aN,$sp,K` at each call | mechanism: rtl src:gcc-2.95.2/gcc/calls.c:662 "&& rtx_cost (args[i].value, SET) > 2" src:gcc-2.95.2/gcc/calls.c:664 "preserve_subexpressions_p ()" | lever: pass a named pointer variable (`void *q = buf; h(q);`) to cache the address; pass `buf` directly for per-site `addiu` | proof: repro/G-expr/addrcache | retail: -
  - dump (a-side .rtl): "(reg/v:SI 81)) -1 (nil)"
  - cookbook: C0076
L10 | G-expr | tell: an `sll rI,rI,2` scaling an index before the `addu`, where the target adds a byte offset directly (or the reverse) | mechanism: rtl src:gcc-2.95.2/gcc/c-typeck.c:2680 "size_exp = c_size_in_bytes (TREE_TYPE (result_type));" src:gcc-2.95.2/gcc/c-typeck.c:2726 "build_binary_op (MULT_EXPR, intop," src:gcc-2.95.2/gcc/expmed.c:2352 "synth_mult (&alg, val, mult_cost);" | lever: `p[i]` on `int *p` scales i by 4 (`sll 2`); `*(int *)((char *)p + i)` adds i unscaled (the scaffold's byte offset) | proof: repro/G-expr/shiftx4 | retail: -
  - dump (a-side .rtl): "(ashift:SI (reg:SI 84)"
  - cookbook: C0084
L12 | G-expr | tell: a pointer loaded out of a struct (`lw $5,0($4)` for `p->a`) again after each member store through it, where the target loads it once (or the reverse) | mechanism: cse src:gcc-2.95.2/gcc/cse.c:1832 "true_dependence (x, full_mode, p->exp, cse_rtx_varies_p)" src:gcc-2.95.2/gcc/alias.c:1269 "return !fixed_scalar_and_varying_struct_p (mem, x, varies);" | lever: name the base in a local (`struct S2 *q = p->a; q->x = ...`) to load it once; repeat `p->a->` to reload per store (both MEMs are varying /s: the store may alias the base, cse drops it); a 10 insns, b 8 | proof: repro/G-expr/baseload | retail: -
  - dump (a-side .cse): "(set (mem/s:SI (plus:SI (reg:SI 84)"
  - cookbook: C0086
L14 | G-expr | tell: a `short` read and masked loads with `lhu` where the target has `lh` (or the reverse), mask kept | mechanism: rtl src:gcc-2.95.2/gcc/c-typeck.c:2072 "shorten = -1;" src:gcc-2.95.2/gcc/c-typeck.c:2387 "tree arg0 = get_narrower (op0, &unsigned0);" src:gcc-2.95.2/gcc/c-typeck.c:2411 "if (shorten == -1)" | lever: mask the narrow read in the expression (`(*p) & 0xFFF`): the front end shortens the & onto the HImode value, lhu; read it into an `int` temp first (`int t = *p; t & 0xFFF`): no visible conversion to narrow, lh | proof: repro/G-expr/shorten | retail: -
  - dump (a-side .rtl): "(and:SI (subreg:SI (reg:HI 83) 0)"
  - cookbook: C0088
