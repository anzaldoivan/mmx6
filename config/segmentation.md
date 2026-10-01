# Segmentation rules (phase 1.3 T3)
Mechanical rules turning `config/boundaries.txt` rows into splat subsegments (TUs) for every program.
DK-12: split where the build forces it and nowhere else. Input rows: grammar at config/boundaries.txt:2.
Consumer: `tools/mmx6/boundcheck.py` (every forced edge below is a subsegment edge in `config/<bin>.yaml`).

## Terms
- TU: one splat text subsegment = one future `.c`/`.s` object; its rodata/data/bss travel with it.
- forced edge: an address where a TU must start or end (only `lib` rows, after the rules below, produce one).
- text extent: exe `[0x800120A0, max(0x8006D5D0, last lib hi))` (config/SLUS_013.95.yaml asm subsegment);
  overlay `[base, base+size)` until a finer code extent is recorded.

## Rules per row kind
- lib: each non-weak `lib <lo> <hi> <LIB/OBJ>` row is its own TU `[lo, hi)`, named by the object (`LIB_OBJ`, e.g.
  `LIBSPU_SPU`); `lo` and `hi` are forced edges. Tie-break on overlap (rows sorted by `lo`): a span wholly inside
  an earlier span is dropped and the container wins (more signature bytes verified); a partial overlap (none today)
  merges both into one TU named `A+B`, an open question until resolved. Ambiguous names (header `ambiguous_name`,
  `ambiguous_plate`) never become rows (tools/mmx6/boundaries.py:19, :358-366), so they fall inside a gap and
  are no edge.
- jtbl: no edge. The table belongs to the TU that contains its dispatching function (`func` column) and is emitted
  in that TU's rodata; a TU edge never separates a function from its table. Rows with note `label-inside-scan-table`
  (hi `unknown`) are labels inside another table, not tables (C0026). A table whose `func` is `-` takes the TU of
  the table that contains it, else stays in the program's single rodata block (open question 4).
- fstart: a symbol only (`func_<ADDR>` in `config/symbols.<bin>.txt`), never a TU edge.
- weak: `LIBSND.LIB/VM_VIB.OBJ` rows (0x20 B plates; exe :54-55, overlays :656 :677 :742 :912) and any row a later
  phase marks weak are never a split point in any program, and are dropped before the overlap tie-break (so exe
  VM_VIB `[0x80054AB8, 0x80054AD8)` does not clip `2MBYTE.OBJ` at 0x80054AD0).
- optcand: none; 0 rows, and the opt level is no boundary signal (1.2 T8).
- gap: the text between two consecutive forced edges (or a text-extent end and the nearest edge) with no lib row
  in it is exactly one TU, named `<vaddr hex>`, until evidence forces more (alignment padding between functions,
  a rodata-order break, a newly verified lib signature). Exe: 1 game gap + 15 small inter-lib gaps.

## Checks run on the result (scratch .run/t3/segcount.py, T3)
- Overlaps in boundaries.txt header = 4 = 3 contained (SSCLOSE ⊃ SSSNC, SSSTART ⊃ S_IH, SSSTOP ⊃ PLAY) + 1 weak
  (VM_VIB vs 2MBYTE).
- Exe jtbl: 47 tables, 41 in game TUs, 6 in lib TUs, 0 with no func; dispatch-TU order along rodata addresses has
  0 inversions, so a rodata partition that follows text TU order exists (section_order rodata first holds).
- Last exe lib span `LIBPAD.LIB/PDRESRES.OBJ` ends at 0x8006D5D4, 4 B past the T2 yaml text end 0x8006D5D0.

## TU counts per program
Columns: TUs = lib + gap; weak = rows not split; jtbl = table rows incl. inside-table labels.

| program | TUs | lib | gap | weak | jtbl |
|---|---|---|---|---|---|
| SLUS_013.95 | 246 | 230 | 16 | 2 | 47 |
| rock_00 | 1 | 0 | 1 | 0 | 2 |
| rock_01 | 1 | 0 | 1 | 0 | 0 |
| rock_02 | 1 | 0 | 1 | 0 | 82 |
| rock_03 | 1 | 0 | 1 | 0 | 10 |
| rock_04 | 1 | 0 | 1 | 0 | 11 |
| rock_05 | 1 | 0 | 1 | 0 | 1 |
| rock_06 | 1 | 0 | 1 | 0 | 1 |
| rock_07 | 1 | 0 | 1 | 0 | 7 |
| rock_08 | 1 | 0 | 1 | 0 | 5 |
| rock_09 | 1 | 0 | 1 | 0 | 6 |
| rock_10 | 1 | 0 | 1 | 1 | 93 |
| rock_11 | 1 | 0 | 1 | 0 | 11 |
| rock_12 | 1 | 0 | 1 | 1 | 1 |
| rock_14 | 1 | 0 | 1 | 0 | 3 |
| rock_15 | 1 | 0 | 1 | 0 | 0 |
| rock_16 | 1 | 0 | 1 | 0 | 2 |
| rock_17 | 1 | 0 | 1 | 0 | 0 |
| rock_18 | 1 | 0 | 1 | 0 | 2 |
| rock_19 | 1 | 0 | 1 | 0 | 0 |
| rock_20 | 1 | 0 | 1 | 0 | 2 |
| rock_21 | 1 | 0 | 1 | 0 | 0 |
| rock_22 | 1 | 0 | 1 | 1 | 17 |
| rock_23 | 1 | 0 | 1 | 0 | 5 |
| rock_24 | 1 | 0 | 1 | 0 | 11 |
| rock_25 | 1 | 0 | 1 | 0 | 2 |
| rock_26 | 1 | 0 | 1 | 0 | 9 |
| rock_27 | 1 | 0 | 1 | 0 | 0 |
| rock_28 | 1 | 0 | 1 | 0 | 0 |
| rock_29 | 1 | 0 | 1 | 0 | 1 |
| rock_30 | 1 | 0 | 1 | 0 | 2 |
| rock_31 | 1 | 0 | 1 | 1 | 88 |
| rock_32 | 1 | 0 | 1 | 0 | 1 |
| rock_33 | 1 | 0 | 1 | 0 | 7 |
| rock_34 | 1 | 0 | 1 | 0 | 0 |
| rock_35 | 1 | 0 | 1 | 0 | 0 |
| rock_36 | 1 | 0 | 1 | 0 | 4 |
| rock_37 | 1 | 0 | 1 | 0 | 0 |
| rock_38 | 1 | 0 | 1 | 0 | 3 |
| rock_39 | 1 | 0 | 1 | 0 | 2 |
| rock_40 | 1 | 0 | 1 | 0 | 2 |
| rock_43 | 1 | 0 | 1 | 0 | 2 |
| rock_44 | 1 | 0 | 1 | 0 | 0 |
| rock_45 | 1 | 0 | 1 | 0 | 1 |
| rock_46 | 1 | 0 | 1 | 0 | 0 |
| rock_47 | 1 | 0 | 1 | 0 | 0 |
| rock_48 | 1 | 0 | 1 | 0 | 0 |
| rock_49 | 1 | 0 | 1 | 0 | 0 |
| rock_50 | 1 | 0 | 1 | 0 | 0 |
| rock_51 | 1 | 0 | 1 | 0 | 0 |
| rock_52 | 1 | 0 | 1 | 0 | 0 |
| rock_53 | 1 | 0 | 1 | 0 | 0 |
| rock_54 | 1 | 0 | 1 | 0 | 0 |
| rock_55 | 1 | 0 | 1 | 0 | 0 |
| rock_56 | 1 | 0 | 1 | 0 | 0 |
| rock_57 | 1 | 0 | 1 | 0 | 0 |
| rock_58 | 1 | 0 | 1 | 0 | 0 |
| total (57 programs) | 302 | 230 | 72 | 6 | 443 |

## Open questions (not settled by T3)
1. Exe text end: the yaml text subsegment must reach 0x8006D5D4 (PDRESRES signature end) for the lib edge to exist;
   is 0x8006D5D0..D5D4 code tail or a signature that overruns into data?
2. The 15 small exe inter-lib gaps (0x10-0x120 B) are each one TU by rule; likely unrecognised or ambiguous PsyQ
   objects (9 ambiguous_name, 374 ambiguous_plate exe-wide) or padding; resolving them needs the exact PsyQ version.
3. Contained lib spans (SSSNC, S_IH, PLAY): a real object cannot sit inside another; are these short-signature
   false matches, or is the container's signature too long?
4. Overlay jtbl rows with func `-`: 219 are inside-table labels; 40 have no recorded dispatcher. Irrelevant while
   each overlay is one TU; must be owned before any overlay is split.
5. The exe game gap [0x800120A0, 0x80054AD0) (0x42A30 B) is one TU; splitting it needs evidence (padding, rodata
   order, file-boundary heuristics) that this phase does not gather.
6. Overlay text extent: overlays count their whole image as one TU; code vs rodata/data inside each image is not
   yet recorded.
