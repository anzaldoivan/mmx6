# Segmentation rules (phase 1.3 T3)
These mechanical rules turn `config/boundaries.txt` rows into splat subsegments (TUs) for every program.
DK-12: split where the build forces it and nowhere else. The grammar of the input rows is at config/boundaries.txt:2.
The consumer is `tools/mmx6/boundcheck.py`. Every forced edge below is a subsegment edge in `config/<bin>.yaml`.

## Terms
- TU: A TU is one splat text subsegment, which is one future `.c`/`.s` object. Its rodata/data/bss travel with it.
- forced edge: A forced edge is an address where a TU must start or end. Only `lib` rows, after the rules below,
  produce one.
- text extent: The exe text extent is `[0x800120A0, max(0x8006D5D0, last lib hi))` (config/SLUS_013.95.yaml asm
  subsegment). The overlay text extent is `[base, base+size)` until a finer code extent is recorded.

## Rules per row kind
- lib: Each non-weak `lib <lo> <hi> <LIB/OBJ>` row is its own TU `[lo, hi)`, named by the object (`LIB_OBJ`, for
  example `LIBSPU_SPU`). `lo` and `hi` are forced edges. For the tie-break on overlap, the rows are sorted by `lo`.
  The tie-break drops a span that is wholly inside an earlier span, and the container wins (more signature bytes
  verified). A partial overlap (none today) merges both into one TU named `A+B`, which is an open question until
  resolved. Ambiguous names (header `ambiguous_name`, `ambiguous_plate`) never become rows
  (tools/mmx6/boundaries.py:19, :358-366), so they fall inside a gap and are no edge.
- jtbl: A jtbl row is no edge. The table belongs to the TU that contains its dispatching function (`func` column)
  and is emitted in that TU's rodata. A TU edge never separates a function from its table. Rows with note
  `label-inside-scan-table` (hi `unknown`) are labels inside another table, not tables (C0026). A table whose `func`
  is `-` takes the TU of the table that contains it. If no table contains it, it stays in the program's single
  rodata block (open question 4).
- fstart: An fstart row is a symbol only (`func_<ADDR>` in `config/symbols.<bin>.txt`). It is never a TU edge.
- weak: The weak rows are the `LIBSND.LIB/VM_VIB.OBJ` rows and any row that a later phase marks weak. The VM_VIB
  rows are 0x20 B plates (exe :54-55, overlays :656 :677 :742 :912). The weak rows are never a split point in any
  program. They are dropped before the overlap tie-break, so exe VM_VIB `[0x80054AB8, 0x80054AD8)` does not clip
  `2MBYTE.OBJ` at 0x80054AD0.
- optcand: none. There are 0 rows, and the opt level is no boundary signal (1.2 T8).
- gap: A gap is the text with no lib row between two consecutive forced edges, or between a text-extent end and
  the nearest edge. A gap is exactly one TU, named `<vaddr hex>`, until evidence forces more (alignment padding
  between functions, a rodata-order break, a newly verified lib signature). The exe has 1 game gap + 15 small
  inter-lib gaps.
- carve (phase 1.6 T6): Carves are deliberate edges, one record per binary (G43). They are in
  `config/carve.<prog>.txt`, which only `tools/mmx6/carve.py` writes.

  `opt <tu> <vram> <newtu> [cflags]`: This record is a text edge at a corpus function start inside `<tu>`. The new
  TU is `<newtu>` (vram hex, kind of the parent). The per-unit cc1 flags come through `config/carve.<prog>.mk`.

  `jtbl <lo> <tu>`: The boundaries.txt jtbl row `[lo, hi)` becomes `[off, .rodata, <tu>]`. `<tu>` is the c unit of
  its dispatcher, so splat migrates the table into the dispatcher's INCLUDE_ASM .s. The rest of the rodata block
  stays `rodata` pieces named by vram hex.

  `rodata <lo> <hi> <tu>` (phase 1.8.1 T4, `carve.py rodata <prog> <func>
  [--bytes N]`): This record is the same cut over a content-derived range.
  The range is a maximal run (>= 2 words) of retail words in the rodata block whose values all lie in
  `[func, func end)`. `--bytes N` = tables T + pad P, with 0 <= P < the unit object's .rodata alignment. A second
  table of a unit merges the unit's rows into one contiguous range in TU function order. There is one row per
  table, the trailing zero pad < alignment is included, and other bytes refuse `foreign-rodata` (T44.c1).

  The exe rodata block is `[0x80010000, 0x800120A0)`. The overlay rodata block is `[base, first text function)`
  when its first TU is a c unit holding `INCLUDE_ASM(..., D_<base>)`. An overlay's first carve drops that line. It
  strips the `D_<base>` attributes in `config/symbols.<prog>.txt` (a sized symbol hides the block's jump tables
  from spimdisasm, so nothing migrates). It records `block <hi>`. Then segment.py emits rodata pieces over
  `[base, hi)` (the piece at base named `<unit>_rodata`, never the unit's name) and starts the unit at hi.

  These cases are refused: no jtbl row / func `-` / label-inside-scan-table, no rodata block, no table run
  (`no-table`), a `--bytes` mismatch. These cases are refused too: a range straddling two rodata pieces or
  overlapping a carve, a TU's rodata made non-contiguous, an asm dispatcher TU. An opt at a non-start or the TU
  start is refused too. The exe today has these carves: jtbl 0x80011378 → 32208, opt 120A0 at 0x80032208
  (TU 32208, game lane).

## Checks run on the result (scratch .run/t3/segcount.py, T3)
- The overlaps in the boundaries.txt header = 4 = 3 contained (SSCLOSE ⊃ SSSNC, SSSTART ⊃ S_IH, SSSTOP ⊃ PLAY) + 1
  weak (VM_VIB vs 2MBYTE).
- The exe has 47 jtbl tables: 41 in game TUs, 6 in lib TUs, 0 with no func. The dispatch-TU order along rodata
  addresses has 0 inversions, so a rodata partition that follows text TU order exists (section_order rodata first
  holds).
- The last exe lib span `LIBPAD.LIB/PDRESRES.OBJ` ends at 0x8006D5D4, 4 B past the T2 yaml text end 0x8006D5D0.

## TU counts per program
The TUs column is lib + gap. The weak column counts the rows not split. The jtbl column counts the table rows,
including inside-table labels.

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
1. Exe text end: the yaml text subsegment must reach 0x8006D5D4 (PDRESRES signature end) for the lib edge to exist.
   Is 0x8006D5D0..D5D4 code tail or a signature that overruns into data?
2. CLOSED (phase 1.8 T8): the 15 small exe inter-lib gaps (0x10-0x120 B) are all PsyQ 4.7 vendor objects. They
   hold 25 functions, 0 padding, 0 game TUs. `psyq/470` signatures tile every gap span exactly, and each matches
   ≥ 2 byte-identical objects (why boundaries.py left them unnamed). For the per-function object names, the naming
   rule and the version table, see docs/ops/compiler-pin.md `## Lib provenance`. Seven gaps hold 2-3 objects (579D4,
   5BA04, 646E4, 64874, 657A4, 657D4, 6A784). Per the gap rule, they stay one TU each until a lib-lane build needs
   object TUs.
3. Contained lib spans (SSSNC, S_IH, PLAY): a real object cannot sit inside another. Are these short-signature
   false matches, or is the container's signature too long?
4. Overlay jtbl rows with func `-`: 219 are inside-table labels. 40 have no recorded dispatcher. They are
   irrelevant while each overlay is one TU. They must be owned before any overlay is split.
5. The exe game gap [0x800120A0, 0x80054AD0) (0x42A30 B) is one TU. Splitting it needs evidence (padding, rodata
   order, file-boundary heuristics) that this phase does not gather.
6. Overlay text extent: overlays count their whole image as one TU. Code vs rodata/data inside each image is not
   yet recorded (partly answered for rock_17/43/45 below).

## Declared overlay function starts (phase 1.5 T1)
- rock_17/43/45 split as `dlabel` + `.word` (0 glabel). Their header words decode as far forward branches/jumps
  (spimdisasm `_findFunctions` farthestBranch never returns to 0). As a result, no `jr $ra` ends a function, and
  the one giant function, holding invalid words, is printed as data.
- Fix: config/symbols.rock_{17,43,45}.txt declare every start `type:func size:` (to its last `jr $ra` + delay
  slot). They declare header / ptr table / trailing data as sized `type:s32`. Each declaration has a `// basis:`
  line from retail bytes (post-return, jal, first code after header), never from Ghidra. The glabel counts are
  29/77/52. 5 multi-return functions (a branch targets past an earlier `jr $ra`) are one function each: rock_43
  func_800FDCD4 and func_800FDD84, and rock_45 func_800FB6F0.
- These starts are ours, not spimdisasm's. A boundary oracle that compares against splat must treat them as
  declared.

## Declared overlay boundaries (phase 1.5 T5)
- Cause: B2 (tools/mmx6/bound2.py) found phantoms/truncations in 53 overlays. They are header words inside the
  first splat function, code printed as data (header-side and tail-side data spans), data words cut into functions.
- Kind A (header) has 52 `D_<text_lo>` header symbols (word 0, plus header / jump-table words) and 50 head functions.
- Kind B (code printed as data) has 581 more declared `type:func size:` starts (post-return / jal target), 23 of
  them multi-return merges. In the rock_03 isolation, header + first function + trailing data gives B2 0/0, but
  splat merged 33 B2 functions into one. As a result, the runs are declared start by start.
- Kind C (data cut into functions) has 14 `type:s32`.
- spimdisasm ends a sized symbol only at size >= 8: a 4-byte header word is declared without size, followed by a
  declared function at +4. The result is `BOUND2 phantoms=0 truncations=0`. th-bound2 runs `--all`
  (mk/tools-health.mk).
