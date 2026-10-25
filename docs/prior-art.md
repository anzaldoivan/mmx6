# Prior art — leads, their status, and their credit

Every fact that this project takes from outside its own bytes is a row here (G101), with its source, license and
status.

The status ladder is `lead` → `consistent-with-bytes` → `proven-at-gate`. `consistent-with-bytes` means checked
against our dump or an oracle. Cite the check. `proven-at-gate` means a green byte gate, or a runtime proof with three
datapoints or a before/after diff. Nothing below `proven-at-gate` is banked on, recorded as fact, or used as a name.

Copying follows G102. From unlicensed or non-commercial sources, take facts only. Take mmx4 C only for proven-shared
functions, listed in `THIRD_PARTY.md`.

## Sources

| Source | License | Use allowed (G102) |
|---|---|---|
| [sozud/mmx4](https://github.com/sozud/mmx4) — matching decomp of Mega Man X4 (US + JP) | AGPL-3.0 | Facts. C adapted for proven-shared functions, with attribution |
| PsyQ runtime-library API (Sony), as copied in mmx4's `include/psy-q-4.0/` (LIBCD.H, LIBGPU.H, SYS/TYPES.H) | not licensed by mmx4's AGPL | Facts only (member order, types, sizes, constant values), re-expressed in our own `include/mmx6/psyq_api.h`. The byte gate verified them (T7.c4) |
| Kuumba123 — `MegaManX6_PS1_Modding`, `MegaManX6_Practice` | none | Facts only, never copied |
| mstan/MegaManX6Recomp — static recompilation (psxrecomp) | PolyForm Noncommercial | Facts only. Generated C is never an input |
| acediez — *Mega Man X6 Tweaks* (romhacking.net) | — | Facts only |
| Shinnuu — Archipelago X6 world | — | Facts only |
| TCRF — Mega Man X6 page | — | Facts only |

## Leads

| # | Lead | Source | Status | Evidence / check | Phase |
|---|---|---|---|---|---|
| L1 | Compiler: **gcc 2.7.2** cc1 (decompals old-gcc 0.9) `-O2 -G0 -msoft-float -funsigned-char -g0` → maspsx `--aspsx-version=2.56 --expand-div` → GNU as (X4's pin). **Corrects the intake's "gcc 2.6.3 + aspsx 2.63"** (see Corrections) | sozud/mmx4 | refuted for X6 (1.4 T6/T7) | 1.4 ladder (docs/ops/compiler-pin.md): every gcc 2.7.2 build (0.9, -psx, -cdk) fails all 3 probes. X6's pin is gcc **2.95.2-psx** + aspsx 2.86 (2.56-2.86 one -G0 class), proven by the probe gate. P4: mmx4 `build.py` rules are named `cc1_263`/`aspsx_263`, but they run `./bin/cc1` from `compiler.sh`'s gcc-2.7.2 download and maspsx 2.56. X6 links newer libraries (L2), so X4's pin is a first probe, not a prediction | 1.4 |
| L2 | SDK: **PsyQ 4.7** libraries — 11 `Ps` stamps in `SLUS_013.95`, all version 4.7. The libnums are 0, 1, 3, 4, 6, 7, 9, 12, 14, 16, 17. The first stamp is at `0x80065AB4`, the last at `0x8008E9F4`. The "(c) 1993-1997 Sony" string corroborates the era | own bytes, 2026-10-01 | proven-at-gate | P1: DetectPsyQ's masked pattern over the exe image. At import, ghidra_psx_ldr's detection is the final word (1.2). 1.2 T1: `make ghidra-import` → `.run/ghidra/info/SLUS_013.95.txt` `psyq_version: 4.7.0`, `sig_functions: 811` of `functions: 1520` (method: docs/ops/oracles.md). Stamps date the linked libraries, not the compiler of game code | 1.2 |
| L3 | `ROCK_X6.BIN` holds 59 sector-extent code overlay members, loaded at `0x801EA000` / `0x800E9860` / `0x800FA000` | MegaManX6Recomp `docs/AOT_OVERLAYS.md` | consistent-with-bytes (structure). Proven runtime for all 3 load bases (docs/memory-map.md, T6): `0x801EA000` member 0, `0x800E9860` members 2/12/18, `0x800FA000` member 46 | P3: the header holds exactly 59 `{sector, size}` descriptors before the first zero pair, all in bounds (the last ends in sector 812 of 813). All 6 cited call sites (`0x80013CDC`, `0x80013CF0`, `0x80013D54`, `0x80013E40`, `0x80013E7C`, `0x80052E94`) are `jal 0x80016858`. `0x80016780`, `0x80016858`, `0x80014D50` are function starts. The three selector tables hold halfword member indices. Load bases need live RAM (1.2) | 1.2 (T6) |
| L4 | 88 named US addresses in 5 files (+ a JP set). Object/layer/GPU struct layouts | Kuumba123 | consistent-with-bytes (68 code addresses), and lead (names, 20 RAM addresses, structs) | P2: 68 of 88 fall inside the exe text, and 59 of those 68 land on a function start (prologue `addiu sp,sp,-N` or after a `jr ra`). Of the other 9, `strcpy`/`memcpy`/`memset`/`printf` are 16-byte-spaced BIOS call stubs, and 5 are unconfirmed by the heuristic. 20 are RAM or scratchpad variables outside the exe image (runtime, 1.2). Cross-source: Kuumba's `BinSeek = 0x80016858` is the recomp's archive selector (L3). Names need our own evidence before use (G62). The T7 result is in the notes below the table | 1.2 (T7) |
| L5 | Engine struct names and idioms shared with X4 | sozud/mmx4 | measured (function bodies, under X6's pin). The names/structs are still lead | P4: mmx4 at `c9ef393` (2026-10-01): 475 C files, 961 `INCLUDE_ASM` bodies still open, 7,021 US symbol lines. 1.6 T8 (`tools/mmx6/x4share.py`, mmx4 `29b62af`, 2026-10-01): each US C file compiled alone, INCLUDE_ASM stubbed, signatures by `sig.py`, vs X6 `build/sig/sigs.jsonl`. The plan's triple cc1 2.6.3 + maspsx `--aspsx-version=2.63` compiles 0 of 402 files (cc1 2.6.3 rejects `__attribute__((packed))` in mmx4's common header). That result is not representative. Under X6's pin gcc 2.95.2-psx + aspsx 2.86: `X4SHARE exact 2042 near 916 of 8534 X6 functions; X4 side 4289 functions from 402 of 402 C files; lib 27 game 2931` (1547 exact ≥ 8 words, 251 distinct exact keys). Control: mmx4's own gcc 2.7.2 gives exact 534, 47 ≥ 8 words, so the matches follow X6's compiler, not the mask | 1.6 |
| L5a | X4 function names as aliases for X6 addresses | sozud/mmx4 | per tier: `gate` = proven-at-gate, `bytes` = consistent-with-bytes | `tools/mmx6/x4names.py --build` (2026-10-24, T47, pin mmx4 `6a6b455` in `config/refs.toml`): `campaign/x4/partners.tsv` rows with a real X4 name, exactly one X4 partner, ≥ 8 words → `config/x4/names.tsv`, map in `docs/x4-names.md`. `--widen` (container) adds partner classes that share one name and relocation-slot votes: `X4NAMES 246 rows; gate 201 bytes 19 slot 26; engine 85 object 160; func 239 data 7` (partners: `X4SHARE exact 2059 near 937 of 8534 X6 functions; X4 side 4429 functions from 405 of 405 C files`). `gate`: the X6 function is banked in C (state `c` or an attributed `src/shared` file). `bytes`: exact signature, body still assembly. `slot`: a lead only (≥ 2 aliased functions reference the address where their mmx4 twin references that symbol, none disagrees), functions and globals. More evidence is in the notes below the table | 1.10 |
| L5b | X5 and X6 share functions. One table joins both games on the mmx4 function. One table lists the functions that are equal in both games under the relocation mask | mmx5 decompilation (AGPL-3.0, the developer's) and sozud/mmx4 | `xref.tsv`: lead. `x5-twins.tsv`: consistent-with-bytes | The tools of the mmx5 repository write both tables (2026-10-13, mmx4 `34f37a4`): `tools/sig/x4adapter.py --xref` and `tools/sig/imgtab.py x6`. `campaign/x4/xref.tsv` and `campaign/x4/x5-twins.tsv` have the same bytes as `docs/oracle/x4-xref.tsv` and `docs/oracle/x6-twins.tsv` of mmx5. They are copied, never edited here. Counts: `X4NAMES xref 405 single rows of 525405; 192 mmx4 functions` and `IMGTAB x6 629 classes; X5 2168, X6 2170; donors X6 c -> X5 asm 1348, X5 c -> X6 asm 100`. `x5-twins.tsv` has one row for each class member: key, words, game, unit, address, name, state (the state of 2026-10-13). A twin is a lead for the C, and the gate proves it: the two games have different compiler flags | campaign |
| L5c | The C of an X5 twin is a seed for its X6 function | mmx5 decompilation (AGPL-3.0, the developer's), public pin `ebdd888` | lead | 2026-10-14: `campaign/x4/x5-leads.tsv` has the same bytes as mmx5 `docs/oracle/x5-leads.tsv` (`imgtab.py x6 --leads`). It holds `X5 c -> X6 asm 97 rows, 48 classes`. A row names the X6 function, the mmx5 function, its C path and the map X5 name -> X6 name. `cards.py` shows it as `## X5 twin`. The pin holds all 48 donor files. The gate proves each draft | campaign |
| L6 | Parts and rank tables | acediez | lead | — | 1.8+ |
| L7 | RAM variables | Archipelago X6 world | lead | — | 1.2+ |
| L8 | A 2001-10-30 prototype and a 2002 Korean/Asian PC port exist | TCRF | lead | — | parking lot |
| L13 | The 2001-10-30 prototype has retail's code but for a few places | Hidden Palace (the developer's copy, id `proto-2001-10-30`) | consistent-with-bytes for the map, lead for the function rows | `tools/mmx6/imgadapter.py proto --id proto-2001-10-30` (2026-10-14) writes `config/oracle.proto-2001-10-30.{map,strings,functions}.tsv`: `IMGTAB proto proto-2001-10-30: exe 130030 of 130048 words in 4 runs (99%); overlays 401274 of 401281 words in 60 runs (99%); functions 7499 of 7500 held: 7499 in a run, 0 by search (0 at one place); strings 27: 0 with a reference, 0 with a retail twin, 0 more with retail code within 32 words`. The map's rows stop at the places that differ: three in the executable (`0x80016954`, `0x80016A3C`, `0x8006D5D8`), one each in `rock_11`, `rock_22`, `rock_24` and `rock_35`. After them the executable's words lie 8, then 12 bytes higher in the build. The build lacks `func_80016950` in retail's form. The 27 strings have no reference: most are 6 bytes of code or data that changed with the addresses. Since 2026-10-14: `tools/psxd_img.py proto --id proto-2001-10-30 --build .run/imgtab/proto-2001-10-30 --exe SLUS_013.95` regenerates the three tables with byte-equal data rows | campaign |
| L14 | The 2001-09-21 prototype holds 5609 of the 7500 game functions in retail's form | Hidden Palace (the developer's copy, id `proto-2001-09-21`) | lead | `tools/mmx6/imgadapter.py proto --id proto-2001-09-21` (2026-10-14) writes `config/oracle.proto-2001-09-21.{map,strings,functions}.tsv`: `IMGTAB proto proto-2001-09-21: exe 111587 of 130048 words in 398 runs (85%); overlays 266035 of 401281 words in 2036 runs (66%); functions 5609 of 7500 held: 4663 in a run, 946 by search (384 at one place); strings 22: 3 with a reference, 2 with a retail twin, 0 more with retail code within 32 words`. A function row gives the build's file and address when one place holds the body: 562 `search` rows have more places and no address. The other 1891 functions (executable 213, overlays 1678) have no body of this form in the build. The mask clears each jump target and each lui or low-half immediate. The strings are a lead to code that retail lacks: the table holds a key, and the text is local (`.run/imgtab/proto-2001-09-21/strings.txt`, ignored). Since 2026-10-14: `tools/psxd_img.py proto --id proto-2001-09-21 --build .run/imgtab/proto-2001-09-21 --exe SLPM_869.59` regenerates the three tables with byte-equal data rows | campaign |

### Notes on the leads

These notes continue the evidence of the rows L4 and L5a.

- **L4 — T7 vs Ghidra function starts** (docs/memory-map.md ledger). Of the 68: 61 Ghidra starts, 3 byte-level starts
  Ghidra missed, 2 after `jr ra` without prologue, 1 unconfirmed, 1 zero word (data).
- **L5a — object-scoped names.** Object-scoped names (mmx4 source under
  `mains items effects layers misc weapons visuals quads`) are aliases only until a role basis exists: identical bytes
  do not prove identical role. No alias is a symbol yet.
- **L5a — content lane** (the X4 disc image): measured 2026-10-11 and dropped. The lane used named, sized mmx4 data
  symbols of ≥ 16 bytes, not constant fill, no address-looking word. It searched for them by content in the X6
  executable and every overlay. Result: `X4NAMES data-probe 6 unique of 76`, below the 20-hit bar, so no `content`
  tier exists. `x4names.py --x4-exe`, `--data-probe` reproduce it.
- **L5a — wider voter set for the slot votes:** measured 2026-10-11 and not adopted. Every exact X4/X6 pair of ≥ 8
  words votes. A multi-partner class votes as one voter at the slots all its partners agree on. Result:
  `X4NAMES voters single 197 class 41 below-floor 13; votes 836 on 338 addresses, admitted 40, new 12`, below the
  20-new bar.
- **L5a — not done, with the reason:** matching retail X4 functions that mmx4 has not decompiled. The two games use
  different compilers. The measured control under mmx4's own compiler (1.6 T8, 2026-10-01, `tools/mmx6/x4share.py`)
  gave 47 exact matches of ≥ 8 words across 4289 functions. So the 961 open bodies would yield about ten.
- **L5a — naming grant (sozud/mmx4).** sozud allows this project to share mmx4's function names and naming
  conventions and to keep both repositories' names in sync. The two comments are quoted verbatim. The mmx6 author wrote:
  `Once it's at 100% I will focus on naming and matching things with the X4 repo if you don't mind, I really like your naming conventions`.
  sozud replied: `Thanks, sure I think having the repos synchronized makes sense`. The scope is the naming conventions
  and the synchronisation of names between the repositories. Date and link: not recorded. The grant stands on
  the quoted exchange.
- **L5a — what the grant does not change.** The grant permits shared names, but it is not evidence. Each alias still
  needs its recorded basis (G62, G101). mmx4 C is used only for proven-shared functions, with attribution (G102).

## Probes (T0, 2026-10-01)

Throwaway scripts under `.run/t0/` (ignored) read the files extracted from our own dump and the upstream clones in
`.run/prior-art/` (ignored). This file records only addresses, counts and verdicts. Upstream revisions checked:
sozud/mmx4 `c9ef393` · Kuumba123/MegaManX6_PS1_Modding `b3a1bf4` · Kuumba123/MegaManX6_Practice `59e5ae7` ·
mstan/MegaManX6Recomp `e42f1c7` · Shinnuu/Archipelago `mmx6-apworld` `f5b9979`.

- **P0 — the medium.** The data track holds 9 files: `SLUS_013.95` (522,240 B), `ROCK_X6.BIN` (1,665,024 B),
  `ROCK_X6.DAT` (50,913,280 B), `SYSTEM.CNF`, `STR/CAPLOGO.STR`, `STR/X6OP.STR`, `XA/BGM.XA`, `XA/DEMO.XA`,
  `ZNULL.DAT`. The exe header gives entry `0x80054AD8`, load `0x80010000` and text size `0x7F000`, matching
  MegaManX6Recomp's `DISC.md`.
- **P1 — SDK stamps** → L2. **P2 — Kuumba123 US symbols vs function starts** → L4. **P3 — the recomp's loader
  claims** → L3. **P4 — mmx4's build and progress, read from its tree** → L1, L5.

## Corrections

- **2026-10-01 — the compiler lead (L1).** The intake recorded mmx4's pin as "gcc 2.6.3 cc1 + aspsx 2.63", read from
  the rule names in mmx4's `build.py`. P4 shows those rules run gcc **2.7.2**'s cc1 and maspsx with
  `--aspsx-version=2.56`.

  This supersedes the 2.6.3 wording in `PROJECT_CONTEXT.md` and in `docs/decomp-architect-install.md` (an install
  record). In `PROJECT_CONTEXT.md` that wording is in Project Assumptions, Key Decisions "Compiler", the Phase 1.4
  roadmap, Data Sources and Libraries. `PROJECT_CONTEXT.md` is frozen and left as written. Phase 1.4's first probe is
  X4's actual triple. The candidate ladder still includes other cc1 builds, because X6's PsyQ 4.7 libraries (L2) leave
  its compiler open.
- **2026-10-01 — X6's compiler (L1, phase 1.4 T7).** The candidate ladder pinned gcc 2.95.2-psx (old-gcc 0.17),
  not X4's 2.7.2: a variable-divisor probe matches only under 2.95.2-psx (compiler zero trap, no `break 6`).
  The pin, its evidence and residual doubts are in `docs/ops/compiler-pin.md`.
