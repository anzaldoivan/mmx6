# Prior art — leads, their status, and their credit

Every fact this project takes from outside its own bytes is a row here (G101), with its source, license and status.
Status ladder: `lead` → `consistent-with-bytes` (checked against our dump or an oracle; cite the check) →
`proven-at-gate` (a green byte gate, or a runtime proof with three datapoints or a before/after diff). Nothing below
`proven-at-gate` is banked on, recorded as fact, or used as a name. Copying follows G102: facts only from unlicensed or
non-commercial sources; mmx4 C only for proven-shared functions, listed in `THIRD_PARTY.md`.

## Sources

| Source | License | Use allowed (G102) |
|---|---|---|
| [sozud/mmx4](https://github.com/sozud/mmx4) — matching decomp of Mega Man X4 (US + JP) | AGPL-3.0 | Facts; C adapted for proven-shared functions, with attribution |
| Kuumba123 — `MegaManX6_PS1_Modding`, `MegaManX6_Practice` | none | Facts only, never copied |
| mstan/MegaManX6Recomp — static recompilation (psxrecomp) | PolyForm Noncommercial | Facts only; generated C never an input |
| acediez — *Mega Man X6 Tweaks* (romhacking.net) | — | Facts only |
| Shinnuu — Archipelago X6 world | — | Facts only |
| TCRF — Mega Man X6 page | — | Facts only |

## Leads

| # | Lead | Source | Status | Evidence / check | Phase |
|---|---|---|---|---|---|
| L1 | Compiler: **gcc 2.7.2** cc1 (decompals old-gcc 0.9) `-O2 -G0 -msoft-float -funsigned-char -g0` → maspsx `--aspsx-version=2.56 --expand-div` → GNU as (X4's pin). **Corrects the intake's "gcc 2.6.3 + aspsx 2.63"** (see Corrections) | sozud/mmx4 | lead | P4: mmx4 `build.py` rules are named `cc1_263`/`aspsx_263` but run `./bin/cc1` from `compiler.sh`'s gcc-2.7.2 download and maspsx 2.56; X6 links newer libraries (L2), so X4's pin is a first probe, not a prediction | 1.4 |
| L2 | SDK: **PsyQ 4.7** libraries — 11 `Ps` stamps in `SLUS_013.95`, all version 4.7 (libnums 0, 1, 3, 4, 6, 7, 9, 12, 14, 16, 17; first `0x80065AB4`, last `0x8008E9F4`); the "(c) 1993-1997 Sony" string corroborates the era | own bytes, 2026-10-01 | consistent-with-bytes | P1: DetectPsyQ's masked pattern over the exe image; ghidra_psx_ldr's detection at import is the final word (1.2). Stamps date the linked libraries, not the compiler of game code | 1.2 |
| L3 | `ROCK_X6.BIN` holds 59 sector-extent code overlay members, loaded at `0x801EA000` / `0x800E9860` / `0x800FA000` | MegaManX6Recomp `docs/AOT_OVERLAYS.md` | consistent-with-bytes (structure); lead (load bases) | P3: the header holds exactly 59 `{sector, size}` descriptors before the first zero pair, all in bounds (the last ends in sector 812 of 813); all 6 cited call sites (`0x80013CDC`, `0x80013CF0`, `0x80013D54`, `0x80013E40`, `0x80013E7C`, `0x80052E94`) are `jal 0x80016858`; `0x80016780`, `0x80016858`, `0x80014D50` are function starts; the three selector tables hold halfword member indices. Load bases need live RAM (1.2) | 1.2 |
| L4 | 88 named US addresses in 5 files (+ a JP set); object/layer/GPU struct layouts | Kuumba123 | consistent-with-bytes (68 code addresses); lead (names, 20 RAM addresses, structs) | P2: 68 of 88 fall inside the exe text; 59 of those 68 land on a function start (prologue `addiu sp,sp,-N` or after a `jr ra`); of the other 9, `strcpy`/`memcpy`/`memset`/`printf` are 16-byte-spaced BIOS call stubs, and 5 are unconfirmed by the heuristic; 20 are RAM or scratchpad variables outside the exe image (runtime, 1.2). Cross-source: Kuumba's `BinSeek = 0x80016858` is the recomp's archive selector (L3). Names need our own evidence before use (G62) | 1.2+ |
| L5 | Engine struct names and idioms shared with X4 | sozud/mmx4 | lead | P4: mmx4 at `c9ef393` (2026-10-01): 475 C files, 961 `INCLUDE_ASM` bodies still open, 7,021 US symbol lines; sharing with X6 unmeasured | 1.6 |
| L6 | Parts and rank tables | acediez | lead | — | 1.8+ |
| L7 | RAM variables | Archipelago X6 world | lead | — | 1.2+ |
| L8 | A 2001-10-30 prototype and a 2002 Korean/Asian PC port exist | TCRF | lead | — | parking lot |

## Probes (T0, 2026-10-01)

Throwaway scripts under `.run/t0/` (ignored) read the files extracted from our own dump and the upstream clones in
`.run/prior-art/` (ignored); only addresses, counts and verdicts are recorded here. Upstream revisions checked:
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
  `--aspsx-version=2.56`. This supersedes the 2.6.3 wording in `PROJECT_CONTEXT.md` (Project Assumptions; Key
  Decisions "Compiler"; the Phase 1.4 roadmap; Data Sources; Libraries), which is frozen and left as written, and in
  `docs/decomp-architect-install.md` (an install record). Phase 1.4's first probe is X4's actual triple; the candidate
  ladder still includes other cc1 builds, because X6's PsyQ 4.7 libraries (L2) leave its compiler open.
