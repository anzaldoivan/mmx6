# G-jump — jump optimizer (jump, jump2)

## Pass (cc1 2.95.2)
- The expand pass sets the branch polarity: `if (c) A; else B;` jumps on !c to B, and A falls through. The jump pass keeps it except for `if (foo) bar; else break;` (arm swap) and jump-around-jump.
  - src:gcc-2.95.2/gcc/stmt.c:1916 "do_jump (cond, thiscond->data.cond.next_label, NULL_RTX);"
  - `!c` swaps the labels: src:gcc-2.95.2/gcc/expr.c:10667 "do_jump (TREE_OPERAND (exp, 0), if_true_label, if_false_label);".
  - src:gcc-2.95.2/gcc/jump.c:1796 "/* Look for   if (foo) bar; else break;  */"
- Cross-jump: only jump2 (after reload) merges identical insn tails before a jump and before its label.
  - src:gcc-2.95.2/gcc/toplev.c:4307 "TIMEVAR (jump_time, jump_optimize (insns, JUMP_CROSS_JUMP,"
  - The minimum is 1 insn at a simple jump and 2 between two jumps to one label. The code is src:gcc-2.95.2/gcc/jump.c:1974 "find_cross_jump (insn, JUMP_LABEL (insn), 1,", src:gcc-2.95.2/gcc/jump.c:1989 "find_cross_jump (insn, target, 2,".
  - The walk stops at the first insn-code mismatch: src:gcc-2.95.2/gcc/jump.c:2871 "GET_CODE (i1) != GET_CODE (i2))".
  - flow puts a `(use (const_int 0))` after a call that ends a block: src:gcc-2.95.2/gcc/flow.c:603 "if (GET_CODE (end) == CALL_INSN)", src:gcc-2.95.2/gcc/flow.c:605 "rtx nop = gen_rtx_USE (VOIDmode, const0_rtx);".

## From BFM (gcc 2.7.2) — G67 translation
- Polarity ("invert the source condition") survives. The arm order is the polarity from expand (src:gcc-2.95.2/gcc/stmt.c:1916 "do_jump (cond, thiscond->data.cond.next_label, NULL_RTX);"). The jump pass keeps it (.rtl and .jump hold the same `if_then_else`, observed). The row is L08.
- Cross-jump ("CALL veto is a COUNT law") changed in form. In 2.95, the veto is flow's nop. A fall-through arm ending in a call ends with `(use (const_int 0))`, and the jump-side arm ends in the call. The codes differ at the first step and nothing merges (src:gcc-2.95.2/gcc/jump.c:2871 "GET_CODE (i1) != GET_CODE (i2))"). The count part survives: src:gcc-2.95.2/gcc/jump.c:3010 "if (minimum <= 0 && last1 != 0 && last1 != e1)". The row is L09.
- D5 (merged vs separate exits, reorg.c) is a lead, not tried in this task.
- Exit-test duplication is in G-loop (jump.c:341), with no lever.

## Levers
L08 | G-jump | tell: the branch is `beqz` where the target has `bnez` (or the reverse) and the two arms' code is in the other order | mechanism: jump src:gcc-2.95.2/gcc/stmt.c:1916 "do_jump (cond, thiscond->data.cond.next_label, NULL_RTX);" src:gcc-2.95.2/gcc/expr.c:10667 "do_jump (TREE_OPERAND (exp, 0), if_true_label, if_false_label);" | lever: invert the source condition and swap the arms. The `if` arm is always the fall-through. `if (a) A; else B;` gives `beqz` to B, and `if (!a) B; else A;` gives `bnez` to A. | proof: repro/G-jump/polarity | retail: -
  - dump (a-side .jump): "(if_then_else (eq:SI (reg/v:SI 81)"
  - cookbook: C0082
L09 | G-jump | tell: an if/else has two `jal` to the same callee. The target shares one `jal` with the differing argument set before the jump (or the reverse). | mechanism: jump2 src:gcc-2.95.2/gcc/jump.c:1974 "find_cross_jump (insn, JUMP_LABEL (insn), 1," src:gcc-2.95.2/gcc/jump.c:2871 "GET_CODE (i1) != GET_CODE (i2))" src:gcc-2.95.2/gcc/flow.c:605 "rtx nop = gen_rtx_USE (VOIDmode, const0_rtx);" | lever: write the shared tail after the `if` or in both arms. After the `if`, the else-arm ends in the call, flow's nop vetoes cross-jump, and the result is two `jal`. In both arms (`g(1); G = 3;` / `g(2); G = 3;`), jump2 merges the store and the call, and the result is one `jal`. | proof: repro/G-jump/xjump | retail: -
  - dump (a-side .jump2): "(use (const_int 0 [0x0]))"
  - cookbook: C0083
L13 | G-jump | tell: a loop entry guard is the loop's own exit test (`sltu` + `beqz`). The target guards with a different, cheaper compare (`blez` on the count), or the reverse. | mechanism: jump src:gcc-2.95.2/gcc/jump.c:341 "if (duplicate_loop_exit_test (insn))" src:gcc-2.95.2/gcc/jump.c:2766 "emit_note_before (NOTE_INSN_LOOP_VTOP, exitcode);" | lever: `while (p < e)` lets jump copy the exit test as the guard. `if (n > 0) do {...} while (p < e);` puts the source's guard there. The a-side has 12 insns and the b-side has 10. | proof: repro/G-jump/guard | retail: -
  - dump (a-side .jump): "NOTE_INSN_LOOP_VTOP"
  - cookbook: C0087
