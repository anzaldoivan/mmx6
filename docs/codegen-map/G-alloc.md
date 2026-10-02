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
