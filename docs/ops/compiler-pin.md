# Compiler pin — mmx6

The triple ladder and its verdict live here. Evidence is counts, addresses and idiom names only (G12).

## Pin (phase 1.4 T7, 2026-10-01)

- Triple: `gcc2.95.2-psx-aspsx2.86` = cc1 `/opt/cc/2.95.2-psx/cc1` (decompals old-gcc 0.17 `gcc-2.95.2-psx`)
  `-O2 -G0 -msoft-float -funsigned-char -quiet` → maspsx @7686f84 `--aspsx-version=2.86 --expand-div` → GNU as 2.42
  (Makefile `ASFLAGS`). Row of `config/triples.txt`; the Makefile default `TRIPLE`, used by every C unit.
- Assembler version: 2.86 (passed explicitly; 2.56-2.86 byte-equivalent under -G0, representative)
- Fingerprint evidence: 3 probes, exe game TU 120A0, ladder of 8 cc1 rungs (`### After-run (T6.1)` below):
  func_8001E78C (0x8001E78C, 13 words, `sltiu` range check + frame + `jal`) and func_800473EC (0x800473EC, 29 words,
  `lb` of an s8 global, `sltiu`, halfword decrement) each eliminate 2.7.2, 2.7.2-psx, 2.7.2-cdk, 2.6.3-psx, 2.8.0-psx,
  2.8.1-psx (best 11/13, 25/29); func_8002B410 (0x8002B410, 79 words, `divu` by a variable, compiler zero trap
  `bne b,$0; break 7` with `mflo` scheduled before it, 5th arg on stack) eliminates all seven others, incl. 2.91.66-psx
  (8/79). Only 2.95.2-psx matches all three (`PIN gcc2.95.2-psx-aspsx2.86 3 of 3`, rc 0). Corroboration: game TU 120A0
  has 45 div/divu, 45 `break 7`, 0 `break 6`; every `--expand-div` rung adds `break 6` to a signed div macro (T6).
- Per-module variation: none found. O0 0, fp-only 0, gprel 0 of 6784 functions; one O2 run per program (57 of 57)
  (`## Per-module variation` below). One triple for all 57 programs; no per-unit override in the Makefile.
- Banked (T8): func_8001E78C, func_800473EC, func_8002B410 are C in their real TU `src/SLUS_013.95/120A0.c` under
  the pin; whole-binary hash green (`make fleet`). The TU's 282 splat-emitted empty `void f(void) {}` also build.

Residual doubts:
- aspsx class: 2.56/2.67/2.79/2.86 are byte-equivalent under `-G0` with gprel 0 (`### aspsx equivalence class`);
  2.86 is an arbitrary representative, accepted at T7's review. A function with `sltu rd,rs,<negative imm>` (2.56 alone
  emits `li $at` + `sltu`) or any `$gp` access would split it; the split corpus has neither.
- One idiom class decides 2.95.2 over 2.91.66 (division); the two sltiu probes do not separate them.
- All probes come from the exe game TU 120A0. Overlays (same O2/-G0 census) and the PsyQ 4.7 library TUs are unprobed;
  library objects were built by Sony and may need their own triple when a lib TU becomes a C unit.
- First overlay C (phase 1.6 T5.c3): 410 overlay members of dup class 6d5cbe29… (36 overlays, names in
  phase-ends/current/logs/T5.c3.md) gated byte-identical under the pin, no per-unit override (I3); one 15-word body only.
- Flags `-msoft-float -funsigned-char` were never varied by a rung (X4's set, kept); no probe exercises float code or
  plain `char` signedness. The kit's extra cc1 flags (`-mips1 -mcpu=3000 -mgas -fgnu-linker`) were not compared.
- `--expand-div` in the pin row is inert for 2.95.2 (cc1 emits the `div $0,a,b` form itself); kept for row parity.
- func_8004BB5C (signed div) dropped at 52/219 words: residue is register allocation, unexplained, not counter-evidence.
- old-gcc 2.95.2-psx is a rebuild; which cc1 Sony shipped with PsyQ 4.7 is unknown (R1.4-001). Matching bytes, not
  provenance, is the claim.
- rock_17/43/45 are `.word`-only (unsplit); their 163 carved functions entered the census by carving only.

## Source (phase 1.7 T1, 2026-10-01)

- Tarball: `https://ftp.gnu.org/gnu/gcc/gcc-2.95.2.tar.gz` (upstream's URL; the `gcc-2.95.2/` subdir has only split
  tarballs), sha256 `064e1cb06ea5d2f4a07ec46c1c64d771f74d04f404b6a6766bca2477f7d72482`, same bytes from
  mirrors.kernel.org/gnu. Makefile `GCCSRC_SHA`.
- Recipe: decompals/old-gcc commit `b74211c9d959e9724802f3177c8229cd67202c87` = tag `0.17` (the release our cc1 comes
  from; its `.github/workflows/build.yml` builds release assets at the tag via `make` = `docker build -f
  gcc-<v>.Dockerfile --target export`), file `gcc-2.95.2-psx.Dockerfile`, base `ubuntu:focal` (pinned by digest).
- The 4 edits, verbatim, in stage `gccsrc` of tools/docker/Dockerfile: `sed` varargs.h → stdarg.h over `**/*.c`
  (dash: one level), `obstack-2.95.2.h.patch` (include/obstack.h), `mips.patch` (gcc/config/mips/mips.h),
  `psx-2.91.patch` (-p1 tree); patches fetched at the commit, each sha256-asserted. Makefile `GCCSRC_PATCHES ?= 3`.
- Staged: `/opt/gcc-2.95.2-src` in the image (pre-configure, no build outputs) + stamp `.mmx6-gccsrc` (tarball sha,
  old-gcc commit, 3 patch names). Tree digest (sorted `find -type f` minus stamp → sha256sum → sha256)
  `8d8a1a5be69d98ae9921359eb356de36d7689f37c854bef29c6f77737e59781e`, 2777 files; Makefile `GCCSRC_TREE`.
  `make toolchain-check` prints `GCCSRC 2.95.2 <tarball sha> patches 3` or `DRIFT gccsrc …` (rc 1).
- Proof A held: stage `cc1-rebuild` (upstream configure/make, full target list) gives cc1 sha256
  `2aa85925dfa10855107c78e29ec36965b953976a45b1a47fb68beb5a74096079` = sha256 of the installed
  `/opt/cc/2.95.2-psx/cc1` (byte-identical, `cmp` clean, 3504368 bytes). `932ed366…` (Dockerfile cc1 set) is the
  sha256 of the release tarball `gcc-2.95.2-psx.tar.gz`, not of cc1.
- Proof B also held: clean `make fleet CC1=/work/.run/t1/cc1-rebuild/cc1` → `FLEET 57 of 57`; all 39 make-driven cc1
  invocations in the log used the override, 0 used `/opt/cc/2.95.2-psx/cc1`.
- Re-prove: `docker build --platform linux/amd64 --target cc1-export --output type=local,dest=.run/t1/cc1-rebuild
  -f tools/docker/Dockerfile tools/docker`, then sha256 `.run/t1/cc1-rebuild/cc1` == the installed cc1's sha256.

## Per-module variation

Census: `mx.sh run python3 tools/mmx6/optscan.py --all` (phase 1.4 T5; since 1.5 T3 after `make extract build` and
`corpus.py --all`, rung `th-optscan` of `make tools-health`), last line `SCANNED 6494 of 6494 functions in 57 of 57
programs` (N per program = corpus rows state asm|include_asm; any n != N printed and rc 1; was `SCANNED 6784
functions in 57 programs` at 1.4 T5); `--self-test` ends `OPTSCAN CONTROL OK` (planted narrowing refused).

Classes (decoded instruction words, per function = splat glabel extent):
- `O0`: prologue `addu|or $fp,$sp,$zero` in the first 8 insns and nop-after-load density >= 0.5 (or < 2 loads).
  `O2`: no -O0 tell (includes hand-written asm and lib objects). `fp-only`: the fp move without the nop density.
- `gprel`: >= 1 load/store/addiu based on `$gp` (rs = 28).
- `div-expand`: div/divu followed within 4 insns by `break 7` (maspsx `--expand-div` / assembler macro form);
  `div-bare`: div/divu without it.
- `unsplit`: program whose asm subsegment splat emitted as `dlabel` + `.word` only; functions carved per C0021
  (`jr $ra` + delay slot), named `anon_<vram>`; words after the last `jr $ra` counted as `dropped`.

Findings (denominator: 6784 functions, 57 programs):
- O0: 0 of 6784 in every program. fp-only: 0. No -O0 module exists, so the pin is a single opt level (-O2 class).
- gprel: 0 of 6784, including the exe (1920 functions) despite gp = 0x8008EAA4 in the exe: `-G0` everywhere.
- div-expand: 41 functions (exe 23: 13 in game TU 120A0 = 0x800120A0..0x80054AD0, 10 in PsyQ lib TUs;
  overlays rock_03/04/07/08/15/16/22/33/34/36/37 hold the other 18). Expanded division is the norm.
- div-bare: 16 functions: exe 2, both game TU (func_8002B410, func_8004BB5C); overlays rock_04, 07, 09, 11, 15,
  25, 26, 34, 36, 40. A bare div beside expanded ones is a probe target for T6 (raw `div $zero` form or asm).
- Contiguous runs: one run per program (57 RUN lines, all `O2`); no per-module class change by address.
- unsplit: rock_17 (29 carved, 513 words dropped), rock_43 (81, 283), rock_45 (53, 248) — 163 carved functions;
  their split config yields no glabel (scope: a split fix, not this census).

## Lib provenance

PsyQ version linked into the exe: **4.7 (psx_ldr `psyq/470`)**, by G56 scoring (phase 1.8 T8, 2026-10-02).
Method: every psx_ldr signature set (16 versions, `$GHIDRA_HOME/Ghidra/Extensions/ghidra_psx_ldr/data/psyq/<ver>/`)
scored against the exe lib band [0x80054AD0, 0x8006D5D4) with boundaries.py `load_sigs`/`sig_ok` (masked bytes,
`??` skipped); scratch `.run/t8/psyqscore.py`, log `.run/logs/t8score.log`; planted control (one byte of row
0x80054AD0 mutated → 470 agree 233 → 232) `SCORE CONTROL OK`.
agree = non-weak boundaries `lib` rows (233) whose bytes match that version's same-named object; exclusive = agree rows
matching in that version only; placed/unique = objects matching at ≥ 1 / exactly 1 aligned offset in the band.
- 260: agree 33, placed 56, unique 52, exclusive 0 (474 objects with a sig)
- 300: agree 48, placed 58, unique 53, exclusive 0 (526)
- 330: agree 50, placed 64, unique 56, exclusive 0 (761)
- 340: agree 50, placed 62, unique 57, exclusive 0 (781)
- 350: agree 52, placed 68, unique 58, exclusive 0 (846)
- 3610, 3611: agree 52, placed 71, unique 57, exclusive 0 (1021 each)
- 370: agree 56, placed 84, unique 68, exclusive 0 (1098)
- 400: agree 57, placed 87, unique 70, exclusive 0 (1238)
- 410: agree 169, placed 189, unique 169, exclusive 0 (1339)
- 420: agree 171, placed 190, unique 171, exclusive 0 (1471)
- 430: agree 180, placed 199, unique 180, exclusive 0 (1672)
- 440: agree 197, placed 216, unique 197, exclusive 0 (1766)
- 450: agree 200, placed 218, unique 199, exclusive 0 (1771)
- 460: agree 228, placed 282, unique 234, exclusive 0 (2187)
- 470: agree 233 of 233, placed 285, unique 239, exclusive 5 (2190) — the only version placing every row; linked
Next evidence (archive link, G56): the PsyQ 4.7 LIB archives, objects linked as-is; not fetched (lib lane stays `vendor`).

Inter-lib gap objects (machine-read by `tools/mmx6/ledger.py`: rows `- gap <0xVRAM> <LIB.LIB/OBJ.OBJ> <evidence>`;
a lib-lane function at `<VRAM>` gets class `vendor:<LIB.LIB>/<LIB>_<OBJ>`). All 15 exe inter-lib gaps are 470
objects: each gap's span is tiled exactly by 470 signatures; none is padding (zero words ≤ 12 of 36, every gap holds
called code), none a game TU. Each span matches ≥ 2 byte-identical objects; the name is chosen by this rule, in order:
(1) candidates = 470 objects whose sig spans exactly the function (inner shorter matches dropped, T3 containment);
(2) drop objects already placed by a boundaries row or an earlier slot (an object links once); (3) prefer the LIB of
the prev/next lib row (skipped when it empties the set); (4) prefer a name between prev and next in member order;
(5) Ghidra plate hint, then lowest name by ascending address. Alternatives are byte-identical: the choice names, it
does not change bytes.
- gap 0x80055F34 LIBSPU.LIB/S_I.OBJ alt UT_ROFF (taken by 0x8005BA04); caller SSINIT_C (SsInit → SpuInit)
- gap 0x80057974 LIBSND.LIB/DE_15.OBJ alt DE_17/18/19; between DE_14 and DE_16
- gap 0x800579D4 LIBSND.LIB/DE_17.OBJ alt DE_15/18/19; between DE_16 and MIDIBEND, 3 slots DE_17..19
- gap 0x80057A04 LIBSND.LIB/DE_18.OBJ same slot run
- gap 0x80057A34 LIBSND.LIB/DE_19.OBJ same slot run
- gap 0x80058574 LIBSND.LIB/SSQUIT.OBJ alt 11 generic 0x20 stubs; after SSPLAY_2 (member order); caller game shutdown
- gap 0x8005BA04 LIBSND.LIB/UT_ROFF.OBJ alt LIBSPU S_I; between UT_RFB and UT_SVA
- gap 0x8005BA24 LIBSND.LIB/UT_RON.OBJ alt LIBSPU S_IH (placed at 0x80058DF4); between UT_ROFF and UT_SVA
- gap 0x800617A4 LIBCD.LIB/SYS.OBJ alt LIBDS D3_006; between EVENT and ISO9660; hint CdPosToInt
- gap 0x800646E4 LIBCD.LIB/S_002.OBJ alt LIBDS D3_005; between BIOS_1 and S_007; hint CdIntToPos
- gap 0x800647F4 LIBCD.LIB/S_003.OBJ alt S_004/S_005 (3 slots: 0x800647F4, 0x800657A4, 0x800657B4)
- gap 0x80064874 LIBCD.LIB/S_008.OBJ alt S_012/S_013/S_024 + 8 non-LIBCD stubs; between S_007 and S_016
- gap 0x80064894 LIBCD.LIB/S_012.OBJ same stub set
- gap 0x800648B4 LIBCD.LIB/S_009.OBJ alt CDR_2/CDR_3/S_014/S_015, LIBDS D3_007; between S_007 and S_016
- gap 0x80064C94 LIBCD.LIB/S_020.OBJ alt LIBDS DSSYS_3; after S_016; hint CdMix
- gap 0x80064DD4 LIBCD.LIB/S_023.OBJ alt LIBDS DSCB_4; between BIOS_2 and CDR_1; caller CDR_1 x8
- gap 0x800657A4 LIBCD.LIB/S_004.OBJ alt S_005; before S_006
- gap 0x800657B4 LIBCD.LIB/S_005.OBJ last of S_003..S_005
- gap 0x800657D4 LIBCD.LIB/S_013.OBJ alt S_024; after S_006
- gap 0x800657F4 LIBCD.LIB/S_014.OBJ alt CDR_2/CDR_3/S_015; after S_006
- gap 0x80065814 LIBCD.LIB/S_021.OBJ alt S_022, LIBDS D3_003 (D3_002 placed at 0x80064CB4)
- gap 0x80065924 LIBCD.LIB/S_024.OBJ last LIBCD stub; after BIOS_3
- gap 0x800698C4 LIBCARD.LIB/C112.OBJ alt LIBAPI C112; before C171
- gap 0x8006A784 LIBDS.LIB/DSCB_1.OBJ alt DSCB_2/DSCB_3; neighbours LIBAPI/LIBPAD (rule 3 empty)
- gap 0x8006A7A4 LIBDS.LIB/DSCB_4.OBJ alt LIBCD S_023 (taken by 0x80064DD4)

## Proven lib units

Machine-read by `tools/mmx6/draw.py` (L1: a lib-lane function whose `config/boundaries.txt` `lib` OBJ is not listed
here is refused `lib triple unproven <OBJ>`). Rows: `- <LIB/OBJ> <evidence>` (evidence = the probe/bank that matched a
function of that OBJ under the pin).

none

## Ladder

### Before-run (T6): 32 rungs

Run (phase 1.4 T6): `bash tools/docker/mx.sh run make extract probe-ladder` (32 rungs of `config/triples.txt` x 3 probes of
`config/probes.txt`, all game TU 120A0); 96 result lines, make rc 2 (ladder rc 1: no unique pin); log `.run/logs/t6c1.log`.

`PIN AMBIGUOUS gcc2.95.2-psx-aspsx2.56,gcc2.95.2-psx-aspsx2.67,gcc2.95.2-psx-aspsx2.79,gcc2.95.2-psx-aspsx2.86`

Probes: func_8001E78C `sltiu-range` (sltiu range check, frame + jal); func_800473EC `lb-s8-sltiu-halfword`;
func_8002B410 `divu-var-mflo-hazard` (bare `divu` by a variable, `mflo` before the `break 7` check, 5th arg on stack).
func_8004BB5C (signed div by a value equal to 10) dropped: best draft 52/219 under gcc2.95.2-psx-aspsx2.86; an inline
helper with the divisor as a parameter reproduces its div/check form, the residue is register allocation.
Only cc1 2.95.2-psx matches the div probe; 2.91.66-psx matches both sltiu probes and fails the div probe (8/79).
The four aspsx rungs tie on every probe (maspsx flags inert under `-G0`).

| triple | func_8001E78C | func_800473EC | func_8002B410 |
|---|---|---|---|
| gcc2.7.2-aspsx2.56 | FAIL 9/13 | FAIL 25/29 | FAIL 9/79 |
| gcc2.7.2-aspsx2.67 | FAIL 9/13 | FAIL 25/29 | FAIL 9/79 |
| gcc2.7.2-aspsx2.79 | FAIL 9/13 | FAIL 25/29 | FAIL 9/79 |
| gcc2.7.2-aspsx2.86 | FAIL 9/13 | FAIL 25/29 | FAIL 9/79 |
| gcc2.7.2-psx-aspsx2.56 | FAIL 9/13 | FAIL 25/29 | FAIL 9/79 |
| gcc2.7.2-psx-aspsx2.67 | FAIL 9/13 | FAIL 25/29 | FAIL 9/79 |
| gcc2.7.2-psx-aspsx2.79 | FAIL 9/13 | FAIL 25/29 | FAIL 9/79 |
| gcc2.7.2-psx-aspsx2.86 | FAIL 9/13 | FAIL 25/29 | FAIL 9/79 |
| gcc2.7.2-cdk-aspsx2.56 | FAIL 9/13 | FAIL 25/29 | FAIL 3/79 |
| gcc2.7.2-cdk-aspsx2.67 | FAIL 9/13 | FAIL 25/29 | FAIL 3/79 |
| gcc2.7.2-cdk-aspsx2.79 | FAIL 9/13 | FAIL 25/29 | FAIL 3/79 |
| gcc2.7.2-cdk-aspsx2.86 | FAIL 9/13 | FAIL 25/29 | FAIL 3/79 |
| gcc2.6.3-psx-aspsx2.56 | FAIL 9/13 | FAIL 25/29 | FAIL 8/79 |
| gcc2.6.3-psx-aspsx2.67 | FAIL 9/13 | FAIL 25/29 | FAIL 8/79 |
| gcc2.6.3-psx-aspsx2.79 | FAIL 9/13 | FAIL 25/29 | FAIL 8/79 |
| gcc2.6.3-psx-aspsx2.86 | FAIL 9/13 | FAIL 25/29 | FAIL 8/79 |
| gcc2.8.0-psx-aspsx2.56 | FAIL 11/13 | FAIL 25/29 | FAIL 3/79 |
| gcc2.8.0-psx-aspsx2.67 | FAIL 11/13 | FAIL 25/29 | FAIL 3/79 |
| gcc2.8.0-psx-aspsx2.79 | FAIL 11/13 | FAIL 25/29 | FAIL 3/79 |
| gcc2.8.0-psx-aspsx2.86 | FAIL 11/13 | FAIL 25/29 | FAIL 3/79 |
| gcc2.8.1-psx-aspsx2.56 | FAIL 11/13 | FAIL 25/29 | FAIL 3/79 |
| gcc2.8.1-psx-aspsx2.67 | FAIL 11/13 | FAIL 25/29 | FAIL 3/79 |
| gcc2.8.1-psx-aspsx2.79 | FAIL 11/13 | FAIL 25/29 | FAIL 3/79 |
| gcc2.8.1-psx-aspsx2.86 | FAIL 11/13 | FAIL 25/29 | FAIL 3/79 |
| gcc2.91.66-psx-aspsx2.56 | MATCH 13/13 | MATCH 29/29 | FAIL 8/79 |
| gcc2.91.66-psx-aspsx2.67 | MATCH 13/13 | MATCH 29/29 | FAIL 8/79 |
| gcc2.91.66-psx-aspsx2.79 | MATCH 13/13 | MATCH 29/29 | FAIL 8/79 |
| gcc2.91.66-psx-aspsx2.86 | MATCH 13/13 | MATCH 29/29 | FAIL 8/79 |
| gcc2.95.2-psx-aspsx2.56 | MATCH 13/13 | MATCH 29/29 | MATCH 79/79 |
| gcc2.95.2-psx-aspsx2.67 | MATCH 13/13 | MATCH 29/29 | MATCH 79/79 |
| gcc2.95.2-psx-aspsx2.79 | MATCH 13/13 | MATCH 29/29 | MATCH 79/79 |
| gcc2.95.2-psx-aspsx2.86 | MATCH 13/13 | MATCH 29/29 | MATCH 79/79 |

### aspsx equivalence class

- aspsx 2.56/2.67/2.79/2.86 are byte-identical on all 3 probes under every cc1 (table above).
- Mechanism, container `/opt/maspsx/maspsx.py:42-47` (version gates; `:40-41` `expand_li` off at >= 2.50, all four):
  `sltu_at` only below 2.60 (2.56); `gp_allow_offset` >= 2.70, `gp_allow_la` >= 2.80, inert under `-G0`.
- Corpus (phase 1.4 T6.1; `asm/SLUS_013.95/120A0.s` + 56 `asm/rock_*/` files, 1121 `sltiu`, 287 `sltu`):
  negative-immediate `sltiu` 0, `sltu ..,$at` 0. gprel 0 of 6784 functions (T5). Unsplit rock_17/43/45 are
  `.word`-only and not in the mnemonic counts.
- No probe within 5 can split the class; 2.86 is an arbitrary representative within it.

### After-run (T6.1): 8 rungs

Run (phase 1.4 T6.1): `bash tools/docker/mx.sh run make extract probe-ladder` (8 rungs, one per
cc1, `-aspsx2.86` only, x 3 probes); 24 result lines, make rc 0; log `.run/logs/t6.log` (default `TRIPLE` now `gcc2.7.2-aspsx2.86`, Makefile:49).

`PIN gcc2.95.2-psx-aspsx2.86 3 of 3`

| triple | func_8001E78C | func_800473EC | func_8002B410 |
|---|---|---|---|
| gcc2.7.2-aspsx2.86 | FAIL 9/13 | FAIL 25/29 | FAIL 9/79 |
| gcc2.7.2-psx-aspsx2.86 | FAIL 9/13 | FAIL 25/29 | FAIL 9/79 |
| gcc2.7.2-cdk-aspsx2.86 | FAIL 9/13 | FAIL 25/29 | FAIL 3/79 |
| gcc2.6.3-psx-aspsx2.86 | FAIL 9/13 | FAIL 25/29 | FAIL 8/79 |
| gcc2.8.0-psx-aspsx2.86 | FAIL 11/13 | FAIL 25/29 | FAIL 3/79 |
| gcc2.8.1-psx-aspsx2.86 | FAIL 11/13 | FAIL 25/29 | FAIL 3/79 |
| gcc2.91.66-psx-aspsx2.86 | MATCH 13/13 | MATCH 29/29 | FAIL 8/79 |
| gcc2.95.2-psx-aspsx2.86 | MATCH 13/13 | MATCH 29/29 | MATCH 79/79 |
