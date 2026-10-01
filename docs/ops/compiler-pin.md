# Compiler pin — mmx6

The triple ladder and its verdict live here (T7 writes the pin). Evidence is counts, addresses and idiom names only (G12).

## Per-module variation

Census: `mx.sh run python3 tools/mmx6/optscan.py --all` (phase 1.4 T5, after `make extract split`), last line
`SCANNED 6784 functions in 57 programs`, rc 0; log `.run/logs/optscan.log` (container asm, not tracked).

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

Run (phase 1.4 T6.1): `bash tools/docker/mx.sh run make TRIPLE=gcc2.7.2-aspsx2.86 extract probe-ladder` (8 rungs, one per
cc1, `-aspsx2.86` only, x 3 probes); 24 result lines, make rc 0; log `.run/logs/t61c1.log`.

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
