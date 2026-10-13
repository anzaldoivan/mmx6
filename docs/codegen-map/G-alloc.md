# G-alloc — local-alloc, global-alloc, reload (lreg, greg, flow, flow2)

## Allocation priority (what `tools/mmx6/alloc_table.py` computes, phase 1.7 T3)
- The global order is `prio = (int)(((double)(floor_log2(refs) * refs) / live) * 10000 * size)`, descending. On a tie, the lower allocno (≈ lower pseudo) goes first.
  - src:gcc-2.95.2/gcc/global.c:603 "(floor_log2 (allocno_n_refs[v1]) * allocno_n_refs[v1])"
  - src:gcc-2.95.2/gcc/global.c:604 "/ allocno_live_length[v1])"
  - src:gcc-2.95.2/gcc/global.c:605 "* 10000 * allocno_size[v1]);"
  - The tie code is src:gcc-2.95.2/gcc/global.c:615 "return v1 - v2;".
  - Over tied pseudos, the code sums refs and takes the maximum live: src:gcc-2.95.2/gcc/global.c:429 "allocno_n_refs[allocno] += REG_N_REFS (i);".
  - A live of 0 becomes -1: src:gcc-2.95.2/gcc/global.c:542 "allocno_live_length[i] = -1;".
- The local order (block-local pseudos, one block) has the same shape over the quantity's birth..death span, not REG_LIVE_LENGTH.
  - src:gcc-2.95.2/gcc/local-alloc.c:1512 "(floor_log2 (qty_n_refs[q]) * qty_n_refs[q] * qty_size[q])"
  - src:gcc-2.95.2/gcc/local-alloc.c:1513 "/ (qty_death[q] - qty_birth[q])) * 10000))"
- The tool reads these dump lines. The `.lreg` line is `Register N used R times across L insns [in block B]…` src:gcc-2.95.2/gcc/flow.c:4243 "Register %d used %d times across %d insns"
  - The local result is `;; Register N in H.` src:gcc-2.95.2/gcc/local-alloc.c:2266 ";; Register %d in %d.\n"
  - The `.greg` order is `;; K regs to allocate: p…` (only the pseudos that local-alloc left) src:gcc-2.95.2/gcc/global.c:1781 ";; %d regs to allocate:"
  - The `.greg` final hard regs are `;; Register dispositions:`, then `P in H` src:gcc-2.95.2/gcc/global.c:1831 ";; Register dispositions:\n"

## Pass (cc1 2.95.2)
- lreg (local-alloc) handles the block-local pseudos. It sorts the quantities by the local priority, and combine_regs merges tied copies.
  - src:gcc-2.95.2/gcc/local-alloc.c:1523 "qty_compare_1 (q1p, q2p)"
  - src:gcc-2.95.2/gcc/local-alloc.c:1609 "combine_regs (usedreg, setreg, may_save_copy, insn_number, insn, already_dead)"
- greg (global-alloc) handles the rest in allocno_compare order (section above). Each one takes the first free hard reg that find_reg allows.
  - src:gcc-2.95.2/gcc/global.c:593 "allocno_compare (v1p, v2p)"
  - src:gcc-2.95.2/gcc/global.c:925 "find_reg (allocno, losers, alt_regs_p, accept_call_clobbered, retrying)"
- reload gives spill slots per pseudo (alter_reg). Caller-saves is on at -O2 (a call-clobbered reg saved around a call instead of a $s reg).
  - src:gcc-2.95.2/gcc/reload1.c:2379 "alter_reg (i, from_reg)"
  - src:gcc-2.95.2/gcc/toplev.c:4866 "flag_caller_saves = 1;"
  - src:gcc-2.95.2/gcc/caller-save.c:332 "save_call_clobbered_regs ()"

## From BFM (gcc 2.7.2) — G67 translation
- K1 (decl order = pseudo order = tie-break) survives. With equal prio (8888 both, tie pair), the lower pseudo goes first: src:gcc-2.95.2/gcc/global.c:615 "return v1 - v2;". The row is L05.
- K2 (density floor_log2(refs)*refs/live decides $s order) survives with the same formula: src:gcc-2.95.2/gcc/global.c:603 "(floor_log2 (allocno_n_refs[v1]) * allocno_n_refs[v1])". The row is L06.
- K4 (caller-save `sw/lw` hugging jal) survives as code (a lead, not reproduced in this task). The option -O2 sets it: src:gcc-2.95.2/gcc/toplev.c:4866 "flag_caller_saves = 1;".
- K7 (spill-slot offsets by regno) survives. reload walks the pseudos in regno order. It gives each spilled pseudo the next slot (decl order → pseudo order → offset): src:gcc-2.95.2/gcc/reload1.c:797 "alter_reg (i, -1);". The row is L11.
- RC-6 (20+ insn explosion = register-pressure lock) survives as triage with no lever: C0002 `sym-register-pressure` → permuter (T7).

## Levers
L05 | G-alloc | tell: two values live across calls get `$16`/`$17` swapped against the target, with equal ref counts and live lengths | mechanism: greg src:gcc-2.95.2/gcc/global.c:615 "return v1 - v2;" | lever: by declaration order, the first-declared value is the lower pseudo and wins the tie. With `int x, y;`, x gets `$16`. With `int y, x;`, y gets `$16`. On the a-side, 83 has prio 8888 and 84 has prio 8888. On the b-side, the prios are the same and 83 is y. | proof: repro/G-alloc/tie | retail: -
  - dump (a-side .greg): "83 in 16  84 in 17"
  - cookbook: C0079
L06 | G-alloc | tell: two values live across calls get `$16`/`$17` swapped against the target, with unequal ref counts | mechanism: greg src:gcc-2.95.2/gcc/global.c:603 "(floor_log2 (allocno_n_refs[v1]) * allocno_n_refs[v1])" src:gcc-2.95.2/gcc/global.c:604 "/ allocno_live_length[v1])" | lever: move references. The value with the higher floor_log2(refs)*refs/live gets `$16`. On the a-side, x=83 has refs 6, live 13, prio 9230 and y=87 has refs 4, live 12, prio 6666. The result is that x gets `$16`. On the b-side (extra uses moved to y), x=83 has refs 4, live 13, prio 6153 and y=87 has refs 6, live 12, prio 10000. The result is that y gets `$16`. | proof: repro/G-alloc/refs | retail: -
  - dump (a-side .greg): `";; 2 regs to allocate: 83 87"`
  - cookbook: C0080
L11 | G-alloc | tell: the stack slots of two spilled values are swapped against the target (`sw $2,52($sp)` vs `56($sp)`), with equal length | mechanism: greg src:gcc-2.95.2/gcc/reload1.c:797 "alter_reg (i, -1);" src:gcc-2.95.2/gcc/reload1.c:2422 "x = assign_stack_local (GET_MODE (regno_reg_rtx[i]), total_size," | lever: by declaration order, spilled pseudos get slots in pseudo order, and the first-declared spilled value gets the lower offset. With `int v2, v3;`, v2 gets 52 and v3 gets 56. With `int v3, v2;`, v3 gets 52 and v2 gets 56. On the a-side, 82 84 85 are spilled at 48 52 56. | proof: repro/G-alloc/slot | retail: -
  - dump (a-side .greg): "(const_int 52 [0x34])) 0)"
  - cookbook: C0085
