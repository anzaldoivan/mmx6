# G-alloc — local-alloc, global-alloc, reload (lreg, greg, flow, flow2)

## Allocation priority (what `tools/mmx6/alloc_table.py` computes; phase 1.7 T3)
- global order: `prio = (int)(((double)(floor_log2(refs) * refs) / live) * 10000 * size)`, descending; tie → lower allocno (≈ lower pseudo) first
  - src:gcc-2.95.2/gcc/global.c:603 "(floor_log2 (allocno_n_refs[v1]) * allocno_n_refs[v1])"
  - src:gcc-2.95.2/gcc/global.c:604 "/ allocno_live_length[v1])"
  - src:gcc-2.95.2/gcc/global.c:605 "* 10000 * allocno_size[v1]);"
  - tie: src:gcc-2.95.2/gcc/global.c:615 "return v1 - v2;"
  - refs summed, live = max over tied pseudos: src:gcc-2.95.2/gcc/global.c:429 "allocno_n_refs[allocno] += REG_N_REFS (i);"
  - live 0 → -1: src:gcc-2.95.2/gcc/global.c:542 "allocno_live_length[i] = -1;"
- local (block-local pseudos, one block): same shape over the quantity's birth..death span, not REG_LIVE_LENGTH
  - src:gcc-2.95.2/gcc/local-alloc.c:1512 "(floor_log2 (qty_n_refs[q]) * qty_n_refs[q] * qty_size[q])"
  - src:gcc-2.95.2/gcc/local-alloc.c:1513 "/ (qty_death[q] - qty_birth[q])) * 10000))"
- dump lines read: `.lreg` `Register N used R times across L insns [in block B]…` src:gcc-2.95.2/gcc/flow.c:4243 "Register %d used %d times across %d insns"
  - local result `;; Register N in H.` src:gcc-2.95.2/gcc/local-alloc.c:2266 ";; Register %d in %d.\n"
  - `.greg` order `;; K regs to allocate: p…` (only pseudos local-alloc left) src:gcc-2.95.2/gcc/global.c:1781 ";; %d regs to allocate:"
  - `.greg` final hard regs `;; Register dispositions:` then `P in H` src:gcc-2.95.2/gcc/global.c:1831 ";; Register dispositions:\n"

## Pass (cc1 2.95.2)
- lreg (local-alloc): block-local pseudos, quantities sorted by the local priority; tied copies merged by combine_regs
  - src:gcc-2.95.2/gcc/local-alloc.c:1523 "qty_compare_1 (q1p, q2p)"
  - src:gcc-2.95.2/gcc/local-alloc.c:1609 "combine_regs (usedreg, setreg, may_save_copy, insn_number, insn, already_dead)"
- greg (global-alloc): the rest, in allocno_compare order (section above); each takes the first free hard reg find_reg allows
  - src:gcc-2.95.2/gcc/global.c:593 "allocno_compare (v1p, v2p)"
  - src:gcc-2.95.2/gcc/global.c:925 "find_reg (allocno, losers, alt_regs_p, accept_call_clobbered, retrying)"
- reload: spill slots per pseudo (alter_reg); caller-saves on at -O2 (call-clobbered reg saved around a call instead of a $s reg)
  - src:gcc-2.95.2/gcc/reload1.c:2379 "alter_reg (i, from_reg)"
  - src:gcc-2.95.2/gcc/toplev.c:4866 "flag_caller_saves = 1;"
  - src:gcc-2.95.2/gcc/caller-save.c:332 "save_call_clobbered_regs ()"

## From BFM (gcc 2.7.2) — G67 translation
- K1 decl order = pseudo order = tie-break: survives. Equal prio (8888 both, tie pair) → lower pseudo first: src:gcc-2.95.2/gcc/global.c:615 "return v1 - v2;". Row L05.
- K2 density floor_log2(refs)*refs/live decides $s order: survives, same formula: src:gcc-2.95.2/gcc/global.c:603 "(floor_log2 (allocno_n_refs[v1]) * allocno_n_refs[v1])". Row L06.
- K4 caller-save `sw/lw` hugging jal: survives as code (lead, not reproduced this task): -O2 sets it, src:gcc-2.95.2/gcc/toplev.c:4866 "flag_caller_saves = 1;".
- K7 spill-slot offsets by regno: survives as code (lead, not reproduced): a slot per spilled pseudo in alter_reg, src:gcc-2.95.2/gcc/reload1.c:2379 "alter_reg (i, from_reg)".
- RC-6 20+ insn explosion = register-pressure lock: survives as triage, no lever: C0002 `sym-register-pressure` → permuter (T7).

## Levers
L05 | G-alloc | tell: two values live across calls get `$16`/`$17` swapped against the target, with equal ref counts and live lengths | mechanism: greg src:gcc-2.95.2/gcc/global.c:615 "return v1 - v2;" | lever: declaration order: the first-declared value is the lower pseudo and wins the tie (`int x, y;` → x `$16`; `int y, x;` → y `$16`); a: 83 prio 8888, 84 prio 8888; b: same prios, 83 is y | proof: repro/G-alloc/tie | retail: -
  - dump (a-side .greg): "83 in 16  84 in 17"
  - cookbook: C0079
L06 | G-alloc | tell: two values live across calls get `$16`/`$17` swapped against the target, ref counts unequal | mechanism: greg src:gcc-2.95.2/gcc/global.c:603 "(floor_log2 (allocno_n_refs[v1]) * allocno_n_refs[v1])" src:gcc-2.95.2/gcc/global.c:604 "/ allocno_live_length[v1])" | lever: move references: the value with the higher floor_log2(refs)*refs/live gets `$16`; a: x=83 refs 6 live 13 prio 9230, y=87 refs 4 live 12 prio 6666 → x `$16`; b (extra uses moved to y): x=83 refs 4 live 13 prio 6153, y=87 refs 6 live 12 prio 10000 → y `$16` | proof: repro/G-alloc/refs | retail: -
  - dump (a-side .greg): ";; 2 regs to allocate: 83 87"
  - cookbook: C0080
