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
| L1 | Compiler: gcc 2.6.3 cc1 + aspsx 2.63 (X4's pin) | sozud/mmx4 | lead | — | 1.4 |
| L2 | SDK era PsyQ 4.x ("Library Programs (c) 1993-1997 Sony Computer Entertainment Inc." on the disc) | own grep of the dump, 2026-10-01 | consistent-with-bytes | string present in the dump; library version not yet detected | 1.2 |
| L3 | `ROCK_X6.BIN` holds 59 sector-extent code overlay members, loaded at `0x801EA000` / `0x800E9860` / `0x800FA000` | MegaManX6Recomp `docs/AOT_OVERLAYS.md` | lead | — | 1.2 |
| L4 | ~53 named US addresses; a JP set; object/layer/GPU struct layouts | Kuumba123 | lead | — | 1.2+ |
| L5 | Engine struct names and idioms shared with X4 | sozud/mmx4 | lead | — | 1.6 |
| L6 | Parts and rank tables | acediez | lead | — | 1.8+ |
| L7 | RAM variables | Archipelago X6 world | lead | — | 1.2+ |
| L8 | A 2001-10-30 prototype and a 2002 Korean/Asian PC port exist | TCRF | lead | — | parking lot |
