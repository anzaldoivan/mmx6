# G-sched — scheduling, delay slots, assembler reorder (sched, sched2, mach, dbr, maspsx)

## Pass (cc1 2.95.2)
- sched (before reload) and sched2 (after reload, on at -O2) do list scheduling per block.
  - src:gcc-2.95.2/gcc/toplev.c:4133 "TIMEVAR (sched_time, schedule_insns (rtl_dump_file));"
  - src:gcc-2.95.2/gcc/toplev.c:4283 "TIMEVAR (sched2_time, schedule_insns (rtl_dump_file));"
  - src:gcc-2.95.2/gcc/toplev.c:4870 "flag_schedule_insns_after_reload = 1;"
- A load depends on an earlier store only if true_dependence says they may alias (the /s and scalar facts of G-expr).
  - src:gcc-2.95.2/gcc/sched.c:1393 "if (true_dependence (XEXP (pending_mem, 0), VOIDmode,"
  - src:gcc-2.95.2/gcc/alias.c:1269 "return !fixed_scalar_and_varying_struct_p (mem, x, varies);"
  - A member store gets /s: src:gcc-2.95.2/gcc/expr.c:4770 "MEM_SET_IN_STRUCT_P (to_rtx, 1);".
- The ready-list order is priority, then insn class, then original order (LUID).
  - src:gcc-2.95.2/gcc/sched.c:1837 "rank_for_schedule (x, y)"
  - src:gcc-2.95.2/gcc/sched.c:1881 "return INSN_LUID (tmp) - INSN_LUID (tmp2);"
- The dbr pass fills the delay slots from before the branch/call first, then does the eager fill from the targets.
  - src:gcc-2.95.2/gcc/toplev.c:4342 "TIMEVAR (dbr_sched_time, dbr_schedule (insns, rtl_dump_file));"
  - src:gcc-2.95.2/gcc/reorg.c:1998 "fill_simple_delay_slots (non_jumps_p)"
  - src:gcc-2.95.2/gcc/reorg.c:2892 "fill_eager_delay_slots ()"
- maspsx (pin 2.86, cookbook C0044) reorders/expands cc1's asm and inserts load-delay nops. It is not gcc source, and it has no cite.

## From BFM (gcc 2.7.2) — G67 translation
- S1 (LUID tie-break → statement order) survives (a lead, not reproduced): src:gcc-2.95.2/gcc/sched.c:1881 "return INSN_LUID (tmp) - INSN_LUID (tmp2);".
- S2 (birthing boost) changed: it is now unconditional before reload. REG_DEAD notes are gone when adjust_priority runs, so n_deaths is always 0 and every birthing insn gets max priority. The code is src:gcc-2.95.2/gcc/sched.c:1968 "/* ??? This code has no effect, because REG_DEAD notes are removed", src:gcc-2.95.2/gcc/sched.c:1990 "if (birthing_insn_p (PATTERN (prev)))". It is a lead, not reproduced.
- S3 (load chain below stores = priority, → permuter) changed. A load held below a store is first an aliasing decision (row L07: `*p=` holds it, `p->a=` frees it). The code is src:gcc-2.95.2/gcc/sched.c:1393 "if (true_dependence (XEXP (pending_mem, 0), VOIDmode,". It is priority/permuter only once the dependence is gone.
- S4 (filler between load and use = statement order) survives (a lead) through the same LUID tie (sched.c:1881 above).
- D1 (delay slot = first eligible insn backward) survives (observed: in repro/G-jump/polarity.a, `sw $31,16($29)` fills `beqz`'s slot and `li $4,1` fills `jal`'s): src:gcc-2.95.2/gcc/reorg.c:1998 "fill_simple_delay_slots (non_jumps_p)".
- D2 (slot stays nop: loads, multi-insn) survives (observed: repro/G-jump/xjump.b `jal 0` + `nop`). The slot takes only a one-insn non-dslot insn, src:gcc-2.95.2/gcc/config/mips/mips.md:125 "(define_delay (and (eq_attr ".
- D3 (eager fill by mostly_true_jump) survives as code (a lead): src:gcc-2.95.2/gcc/reorg.c:891 "mostly_true_jump (jump_insn, condition)". The lever (invert polarity) is G-jump L08.
- The maspsx nop after an unfilled branch is a lead. BFM's 2.56 delay-slot hop is not re-proven on 2.86 (C0044: 2.60-2.86 are byte-identical under -G0).

## Levers
L07 | G-sched | tell: a global load (`lw`) sits after a store through a pointer, where the target hoists it above the store (or the reverse) | mechanism: sched src:gcc-2.95.2/gcc/sched.c:1393 "if (true_dependence (XEXP (pending_mem, 0), VOIDmode," src:gcc-2.95.2/gcc/alias.c:1269 "return !fixed_scalar_and_varying_struct_p (mem, x, varies);" src:gcc-2.95.2/gcc/expr.c:4770 "MEM_SET_IN_STRUCT_P (to_rtx, 1);" | lever: the store's form. A bare `*p = v` (no /s, may alias the scalar) holds the load below it. A member store `p->a = v` (/s, in-struct) cannot alias a fixed scalar, and sched hoists the load above it. The instructions are the same. Only the order differs. | proof: repro/G-sched/ldst | retail: -
  - dump (a-side .sched): "(insn 12 19 14 (set (mem:SI (reg:SI 4 a0) 0)"
  - cookbook: C0081
