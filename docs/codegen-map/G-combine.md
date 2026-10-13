# G-combine — instruction combiner, register move (combine regmove)

## Pass (cc1 2.95.2)
- try_combine merges a producer (i2) into its consumer (i3). If i2's result is still live after i3, it must also keep i2's set (a PARALLEL), which usually fails to match.
  - src:gcc-2.95.2/gcc/combine.c:1329 "try_combine (i3, i2, i1)"
  - src:gcc-2.95.2/gcc/combine.c:1600 "added_sets_2 = ! dead_or_set_p (i3, i2dest);"
- An AND with a 2^n-1 mask becomes a zero-extending extraction. When the operand is a MEM, that is a narrow load (`lbu`/`lhu`).
  - src:gcc-2.95.2/gcc/combine.c:5909 "make_compound_operation (x, in_code)"
  - src:gcc-2.95.2/gcc/combine.c:6037 "else if ((i = exact_log2 (INTVAL (XEXP (x, 1)) + 1)) >= 0)"
  - src:gcc-2.95.2/gcc/combine.c:7310 "simplify_and_const_int (x, mode, varop, constop)"
- In regmove, the copy shape decides if regmove keeps or removes a `move`.
  - src:gcc-2.95.2/gcc/regmove.c:376 "optimize_reg_copy_1 (insn, dest, src)"
  - src:gcc-2.95.2/gcc/regmove.c:1650 "fixup_match_1 (insn, set, src, src_subreg, dst, backward, operand_number,"

## From BFM (gcc 2.7.2) — G67 translation
- BFM has no combine/regmove lever. This file has its own candidates (G67 n/a):
- K1 (single-use rule) is not reproduced. `t=b+1; if (t==5) g(0);` and `... g(t);` both give `addu $4,$4,1; li $2,5; bne`. There is no fold to compare with 4, even when t dies (observed, scratch). It is recorded, not forced.
- K2 (extension merge) reproduces. The row is L04. The decider is src:gcc-2.95.2/gcc/combine.c:1600 "added_sets_2 = ! dead_or_set_p (i3, i2dest);".
- K3 (regmove) is not tried in this task (a lead).

## Levers
L04 | G-combine | tell: `lw` + `andi rX,rY,0xff` where the target has a single `lbu` (or the reverse) | mechanism: combine src:gcc-2.95.2/gcc/combine.c:6037 "else if ((i = exact_log2 (INTVAL (XEXP (x, 1)) + 1)) >= 0)" src:gcc-2.95.2/gcc/combine.c:1600 "added_sets_2 = ! dead_or_set_p (i3, i2dest);" | lever: a masked word whose only use is the mask folds into `lbu`. A second use of the full word keeps `lw` + `andi`. Another read of `*p` is such a use, even after cse merges it. | proof: repro/G-combine/extmerge | retail: -
  - dump (a-side .combine): "(zero_extend:SI (mem:QI (reg:SI 4 a0) 0)))"
  - cookbook: C0078
L15 | G-combine | tell: `lhu` + `sll 16` + `sra 16` where the target has one `lh` (or the reverse) | mechanism: combine src:gcc-2.95.2/gcc/combine.c:1047 "volatile_refs_p (src))" | lever: a `volatile` read keeps the HImode load apart from its sign extend (combine refuses to move a volatile MEM). Drop `volatile` for one `lh`. The a-side has 6 insns and the b-side has 3. | proof: repro/G-combine/volatile | retail: -
  - dump (a-side .combine): "(mem/v:HI (reg/v:SI 81) 0)) 256 {movhi_internal2}"
  - cookbook: C0089
