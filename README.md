# Mega Man X6 decompilation (mmx6)


## Description

**mmx6** is a matching decompilation of ***Mega Man X6*** (PlayStation, Capcom, 2001), USA release v1.1. It
reconstructs C source. Compiled with the original era's toolchain and linked in the original order, that source
rebuilds every code binary on the disc byte for byte. These binaries are the boot executable `SLUS_013.95` and the
code overlays inside `ROCK_X6.BIN`. Every build checks each binary's hash.

Readable, evidenced source is the first step towards understanding the game's engine and the code it shares with
*Mega Man X4*. It is also the first step towards tools, documentation and ports built on it. Anyone with their own
dump can rebuild the binaries from this README alone.

<!-- psxdecomp: ai-policy -->
> [!IMPORTANT]
> **AI policy:** LLMs produce negligible decompilation results without good guidance. Investigate and familiarize yourself with the console's architecture and the game you are decompiling, and always use your own judgment. Humans drive the decisions. AI reads and writes the code.

<!-- psxdecomp:disc:begin -->
| Disc | Serial | Executable | SHA-1 of the data track |
|---|---|---|---|
| USA v1.1 | SLUS-01395 | `SLUS_013.95` | `d4f7e08371027a87a3bf13311db5a4c56733f4ea` (Redump) |

The target `SLUS_013.95` has SHA-1 `667ce8f792cfaa69abe6e999a87513f798bbcac4` (`config/check.SLUS_013.95.sha`). Every build checks its rebuild against it.
<!-- psxdecomp:disc:end -->

> [!IMPORTANT]
> This repository contains **no game data**: no executable, no disc data, no disassembly listing, no memory image,
> no vendor SDK. You build from your own legally obtained dump. The `.gitignore` is the firewall. The gate is
> [`tools/audit_public.py`](tools/audit_public.py) (sources in [`config/firewall.txt`](config/firewall.txt)), and CI
> runs it on every push. See [`src/NOTICE.md`](src/NOTICE.md).

## Progress

[![no-rom](https://github.com/anzaldoivan/mmx6/actions/workflows/no-rom.yml/badge.svg)](https://github.com/anzaldoivan/mmx6/actions/workflows/no-rom.yml)

<!-- psxdecomp:progress:begin -->
[![Code][psxd-code]][psxd-progress] [![Functions][psxd-functions]][psxd-progress]

| Category | Name | Status |
|---|---|---|
| `main` | SLUS_013.95 (boot executable) | [![Code](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Code&measure=code&category=main)](https://decomp.dev/anzaldoivan/mmx6?category=main) [![Functions](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Functions&measure=functions&category=main)](https://decomp.dev/anzaldoivan/mmx6?category=main) |
| `rock` | ROCK_X6.BIN overlays | [![Code](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Code&measure=code&category=rock)](https://decomp.dev/anzaldoivan/mmx6?category=rock) [![Functions](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Functions&measure=functions&category=rock)](https://decomp.dev/anzaldoivan/mmx6?category=rock) |
| `sdk` | PsyQ SDK libraries | [![Code](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Code&measure=code&category=sdk)](https://decomp.dev/anzaldoivan/mmx6?category=sdk) [![Functions](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Functions&measure=functions&category=sdk)](https://decomp.dev/anzaldoivan/mmx6?category=sdk) |

<details><summary><code>rock</code>: 56 overlays</summary>

| Category | Name | Status |
|---|---|---|
| `rock.rock_00` | Rock 00 | [![Code](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Code&measure=code&category=rock.rock_00)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_00) [![Functions](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Functions&measure=functions&category=rock.rock_00)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_00) |
| `rock.rock_01` | Rock 01 | [![Code](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Code&measure=code&category=rock.rock_01)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_01) [![Functions](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Functions&measure=functions&category=rock.rock_01)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_01) |
| `rock.rock_02` | Rock 02 | [![Code](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Code&measure=code&category=rock.rock_02)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_02) [![Functions](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Functions&measure=functions&category=rock.rock_02)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_02) |
| `rock.rock_03` | Rock 03 | [![Code](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Code&measure=code&category=rock.rock_03)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_03) [![Functions](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Functions&measure=functions&category=rock.rock_03)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_03) |
| `rock.rock_04` | Rock 04 | [![Code](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Code&measure=code&category=rock.rock_04)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_04) [![Functions](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Functions&measure=functions&category=rock.rock_04)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_04) |
| `rock.rock_05` | Rock 05 | [![Code](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Code&measure=code&category=rock.rock_05)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_05) [![Functions](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Functions&measure=functions&category=rock.rock_05)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_05) |
| `rock.rock_06` | Rock 06 | [![Code](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Code&measure=code&category=rock.rock_06)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_06) [![Functions](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Functions&measure=functions&category=rock.rock_06)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_06) |
| `rock.rock_07` | Rock 07 | [![Code](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Code&measure=code&category=rock.rock_07)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_07) [![Functions](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Functions&measure=functions&category=rock.rock_07)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_07) |
| `rock.rock_08` | Rock 08 | [![Code](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Code&measure=code&category=rock.rock_08)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_08) [![Functions](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Functions&measure=functions&category=rock.rock_08)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_08) |
| `rock.rock_09` | Rock 09 | [![Code](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Code&measure=code&category=rock.rock_09)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_09) [![Functions](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Functions&measure=functions&category=rock.rock_09)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_09) |
| `rock.rock_10` | Rock 10 | [![Code](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Code&measure=code&category=rock.rock_10)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_10) [![Functions](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Functions&measure=functions&category=rock.rock_10)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_10) |
| `rock.rock_11` | Rock 11 | [![Code](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Code&measure=code&category=rock.rock_11)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_11) [![Functions](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Functions&measure=functions&category=rock.rock_11)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_11) |
| `rock.rock_12` | Rock 12 | [![Code](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Code&measure=code&category=rock.rock_12)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_12) [![Functions](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Functions&measure=functions&category=rock.rock_12)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_12) |
| `rock.rock_14` | Rock 14 | [![Code](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Code&measure=code&category=rock.rock_14)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_14) [![Functions](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Functions&measure=functions&category=rock.rock_14)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_14) |
| `rock.rock_15` | Rock 15 | [![Code](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Code&measure=code&category=rock.rock_15)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_15) [![Functions](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Functions&measure=functions&category=rock.rock_15)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_15) |
| `rock.rock_16` | Rock 16 | [![Code](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Code&measure=code&category=rock.rock_16)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_16) [![Functions](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Functions&measure=functions&category=rock.rock_16)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_16) |
| `rock.rock_17` | Rock 17 | [![Code](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Code&measure=code&category=rock.rock_17)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_17) [![Functions](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Functions&measure=functions&category=rock.rock_17)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_17) |
| `rock.rock_18` | Rock 18 | [![Code](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Code&measure=code&category=rock.rock_18)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_18) [![Functions](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Functions&measure=functions&category=rock.rock_18)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_18) |
| `rock.rock_19` | Rock 19 | [![Code](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Code&measure=code&category=rock.rock_19)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_19) [![Functions](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Functions&measure=functions&category=rock.rock_19)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_19) |
| `rock.rock_20` | Rock 20 | [![Code](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Code&measure=code&category=rock.rock_20)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_20) [![Functions](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Functions&measure=functions&category=rock.rock_20)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_20) |
| `rock.rock_21` | Rock 21 | [![Code](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Code&measure=code&category=rock.rock_21)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_21) [![Functions](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Functions&measure=functions&category=rock.rock_21)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_21) |
| `rock.rock_22` | Rock 22 | [![Code](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Code&measure=code&category=rock.rock_22)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_22) [![Functions](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Functions&measure=functions&category=rock.rock_22)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_22) |
| `rock.rock_23` | Rock 23 | [![Code](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Code&measure=code&category=rock.rock_23)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_23) [![Functions](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Functions&measure=functions&category=rock.rock_23)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_23) |
| `rock.rock_24` | Rock 24 | [![Code](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Code&measure=code&category=rock.rock_24)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_24) [![Functions](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Functions&measure=functions&category=rock.rock_24)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_24) |
| `rock.rock_25` | Rock 25 | [![Code](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Code&measure=code&category=rock.rock_25)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_25) [![Functions](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Functions&measure=functions&category=rock.rock_25)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_25) |
| `rock.rock_26` | Rock 26 | [![Code](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Code&measure=code&category=rock.rock_26)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_26) [![Functions](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Functions&measure=functions&category=rock.rock_26)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_26) |
| `rock.rock_27` | Rock 27 | [![Code](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Code&measure=code&category=rock.rock_27)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_27) [![Functions](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Functions&measure=functions&category=rock.rock_27)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_27) |
| `rock.rock_28` | Rock 28 | [![Code](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Code&measure=code&category=rock.rock_28)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_28) [![Functions](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Functions&measure=functions&category=rock.rock_28)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_28) |
| `rock.rock_29` | Rock 29 | [![Code](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Code&measure=code&category=rock.rock_29)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_29) [![Functions](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Functions&measure=functions&category=rock.rock_29)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_29) |
| `rock.rock_30` | Rock 30 | [![Code](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Code&measure=code&category=rock.rock_30)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_30) [![Functions](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Functions&measure=functions&category=rock.rock_30)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_30) |
| `rock.rock_31` | Rock 31 | [![Code](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Code&measure=code&category=rock.rock_31)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_31) [![Functions](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Functions&measure=functions&category=rock.rock_31)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_31) |
| `rock.rock_32` | Rock 32 | [![Code](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Code&measure=code&category=rock.rock_32)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_32) [![Functions](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Functions&measure=functions&category=rock.rock_32)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_32) |
| `rock.rock_33` | Rock 33 | [![Code](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Code&measure=code&category=rock.rock_33)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_33) [![Functions](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Functions&measure=functions&category=rock.rock_33)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_33) |
| `rock.rock_34` | Rock 34 | [![Code](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Code&measure=code&category=rock.rock_34)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_34) [![Functions](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Functions&measure=functions&category=rock.rock_34)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_34) |
| `rock.rock_35` | Rock 35 | [![Code](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Code&measure=code&category=rock.rock_35)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_35) [![Functions](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Functions&measure=functions&category=rock.rock_35)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_35) |
| `rock.rock_36` | Rock 36 | [![Code](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Code&measure=code&category=rock.rock_36)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_36) [![Functions](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Functions&measure=functions&category=rock.rock_36)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_36) |
| `rock.rock_37` | Rock 37 | [![Code](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Code&measure=code&category=rock.rock_37)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_37) [![Functions](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Functions&measure=functions&category=rock.rock_37)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_37) |
| `rock.rock_38` | Rock 38 | [![Code](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Code&measure=code&category=rock.rock_38)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_38) [![Functions](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Functions&measure=functions&category=rock.rock_38)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_38) |
| `rock.rock_39` | Rock 39 | [![Code](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Code&measure=code&category=rock.rock_39)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_39) [![Functions](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Functions&measure=functions&category=rock.rock_39)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_39) |
| `rock.rock_40` | Rock 40 | [![Code](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Code&measure=code&category=rock.rock_40)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_40) [![Functions](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Functions&measure=functions&category=rock.rock_40)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_40) |
| `rock.rock_43` | Rock 43 | [![Code](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Code&measure=code&category=rock.rock_43)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_43) [![Functions](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Functions&measure=functions&category=rock.rock_43)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_43) |
| `rock.rock_44` | Rock 44 | [![Code](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Code&measure=code&category=rock.rock_44)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_44) [![Functions](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Functions&measure=functions&category=rock.rock_44)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_44) |
| `rock.rock_45` | Rock 45 | [![Code](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Code&measure=code&category=rock.rock_45)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_45) [![Functions](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Functions&measure=functions&category=rock.rock_45)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_45) |
| `rock.rock_46` | Rock 46 | [![Code](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Code&measure=code&category=rock.rock_46)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_46) [![Functions](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Functions&measure=functions&category=rock.rock_46)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_46) |
| `rock.rock_47` | Rock 47 | [![Code](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Code&measure=code&category=rock.rock_47)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_47) [![Functions](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Functions&measure=functions&category=rock.rock_47)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_47) |
| `rock.rock_48` | Rock 48 | [![Code](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Code&measure=code&category=rock.rock_48)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_48) [![Functions](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Functions&measure=functions&category=rock.rock_48)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_48) |
| `rock.rock_49` | Rock 49 | [![Code](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Code&measure=code&category=rock.rock_49)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_49) [![Functions](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Functions&measure=functions&category=rock.rock_49)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_49) |
| `rock.rock_50` | Rock 50 | [![Code](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Code&measure=code&category=rock.rock_50)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_50) [![Functions](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Functions&measure=functions&category=rock.rock_50)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_50) |
| `rock.rock_51` | Rock 51 | [![Code](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Code&measure=code&category=rock.rock_51)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_51) [![Functions](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Functions&measure=functions&category=rock.rock_51)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_51) |
| `rock.rock_52` | Rock 52 | [![Code](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Code&measure=code&category=rock.rock_52)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_52) [![Functions](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Functions&measure=functions&category=rock.rock_52)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_52) |
| `rock.rock_53` | Rock 53 | [![Code](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Code&measure=code&category=rock.rock_53)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_53) [![Functions](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Functions&measure=functions&category=rock.rock_53)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_53) |
| `rock.rock_54` | Rock 54 | [![Code](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Code&measure=code&category=rock.rock_54)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_54) [![Functions](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Functions&measure=functions&category=rock.rock_54)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_54) |
| `rock.rock_55` | Rock 55 | [![Code](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Code&measure=code&category=rock.rock_55)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_55) [![Functions](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Functions&measure=functions&category=rock.rock_55)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_55) |
| `rock.rock_56` | Rock 56 | [![Code](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Code&measure=code&category=rock.rock_56)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_56) [![Functions](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Functions&measure=functions&category=rock.rock_56)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_56) |
| `rock.rock_57` | Rock 57 | [![Code](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Code&measure=code&category=rock.rock_57)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_57) [![Functions](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Functions&measure=functions&category=rock.rock_57)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_57) |
| `rock.rock_58` | Rock 58 | [![Code](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Code&measure=code&category=rock.rock_58)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_58) [![Functions](https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Functions&measure=functions&category=rock.rock_58)](https://decomp.dev/anzaldoivan/mmx6?category=rock.rock_58) |

</details>

The published number is the matched code of the `game` category, in bytes. The `sdk` row counts the SDK libraries apart. A complete unit is a C file whose code and data all match. It is not a finished file (`rules/FIN1.md`).

Progress bars powered by [decomp.dev][psxd-progress].

[psxd-code]: https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Code&measure=code&category=game
[psxd-functions]: https://decomp.dev/anzaldoivan/mmx6.svg?mode=shield&label=Functions&measure=functions&category=game
[psxd-progress]: https://decomp.dev/anzaldoivan/mmx6
<!-- psxdecomp:progress:end -->

Like many late PlayStation games, *Mega Man X6* keeps much of its code in *overlays*. Overlays are binaries that the
executable loads at a fixed address when it needs them. Because of this, only part of the game's code occupies
memory at once.

X6 packs the overlays as numbered entries of one archive, `ROCK_X6.BIN`. Of its 59 entries, 56 are code, one is
data and two are empty (snapshot 2026-10-24: the `class` column of [`config/loadmap.txt`](config/loadmap.txt), written
by `make loadmap`). Once progress is published, each code entry
gets its own category (`rock.rock_NN`) on decomp.dev. The category has the name "Rock NN" until evidence identifies
the stage or system that the entry serves.

What does the percentage mean? A function counts as matched only when the whole binary still hashes identically
with it compiled from C. 100% is not the end. Names and types come only from evidence, never from guesses (an
address-named placeholder is honest). The record behind them (the phase syntheses, the decision log, the
[cookbook](cookbook/INDEX.md) of byte-proven idioms) is what makes the work auditable.

## Building the decompilation

You need Git, Bash and Docker. The build runs in a `linux/amd64` container. On Apple silicon, it runs under
emulation. You also need your own dump of *Mega Man X6 (USA) (v1.1)* as Redump `.cue` + `.bin`, with the Redump
file names. The dump never enters the repository. The command `mx.sh disc` copies it into a Docker volume mounted
read-only.

`bash tools/bootstrap.sh /path/to/dump` runs the first three steps below and the toolchain preflight in one go.

```sh
git clone https://github.com/anzaldoivan/mmx6.git && cd mmx6
bash tools/docker/mx.sh build                  # build the toolchain image (once)
bash tools/docker/mx.sh disc /path/to/dump     # the folder holding the .cue and .bin
bash tools/docker/mx.sh sync                   # copy the tree into the build volume
bash tools/docker/mx.sh run make extract       # verify the dump against config/medium.sha1, extract the binaries
bash tools/docker/mx.sh run make -j8 build     # split, assemble/compile, link, hash-check every binary
```

A successful build prints one `OK` line per binary: `build/SLUS_013.95: OK` and `build/rock/NN.bin: OK` for each code
overlay, 57 in all. A clone of this repository printed all 57 on 2026-10-24 (docs/contract-run.md, `## Fresh clone`).
The tool self-test ladder (`make fleet`) needs development-side inputs that are not published. It runs in the private
contract run.

## Repository layout

| Path | Contents |
|---|---|
| `src/` | Decompiled C, one directory per binary (`src/SLUS_013.95/`, `src/rock_NN/`) |
| `include/` | Headers and assembler macros |
| `config/` | splat configurations, symbol files, hash checks, load map, segment boundaries |
| `manifest/` | Hashes of every extracted file (no game bytes) |
| `tools/` | Extraction, build, matching and analysis tools (`tools/mmx6/`), the build container (`tools/docker/`) |
| `Makefile`, `mk/` | The build and its checks |
| `docs/` | Formats, memory map, codegen map and prior art |
| `cookbook/` | Byte-proven C idioms for this compiler |
| `disks/` | Your dump, if you keep it in the tree (git-ignored) |

## Getting started

### Setting up

The build runs in a Linux container: `tools/docker/Dockerfile` defines it and `tools/docker/mx.sh` drives it.

### Contributing

Before your first pull request, read [CONTRIBUTING.md](CONTRIBUTING.md). Bring your own copy of the game. Never
commit anything derived from it. Follow the AI-use conduct section.

### Reference

Are you new to this compiler or stuck on a function? The [cookbook](cookbook/INDEX.md) and the
[codegen map](docs/codegen-map/README.md) document the code patterns proven so far.

## Acknowledgements

No decompilation of Mega Man X6 existed when this project started (searched 2026-10-01). This project stands on the
work of others. Every fact taken from them is tracked with its status in [`docs/prior-art.md`](docs/prior-art.md).
A fact from another project stays a lead until this project's own bytes prove it.

- **[sozud](https://github.com/sozud)** — [**mmx4**](https://github.com/sozud/mmx4), the matching decompilation of
  *Mega Man X4* (US + JP, AGPL-3.0). Its toolchain, layout and engine knowledge are the starting point for X6. This
  project shares its license so that code proven shared between the two games can be adapted with attribution
  (listed in [`THIRD_PARTY.md`](THIRD_PARTY.md)).
  Its author allows this project to share mmx4's function names and naming conventions and to keep both
  repositories' names in sync. Each name is still proven here before it becomes a symbol. Row L5a of
  [`docs/prior-art.md`](docs/prior-art.md) records the grant and the evidence.
- **[Kuumba123](https://github.com/Kuumba123)** — [MegaManX6_PS1_Modding](https://github.com/Kuumba123/MegaManX6_PS1_Modding)
  and [MegaManX6_Practice](https://github.com/Kuumba123/MegaManX6_Practice): X6 symbol research (US + JP) and
  struct layouts, plus the wider Mega Man PS1 modding tools. Their repositories carry no license, so nothing is
  copied from them. Their findings are used as leads, re-proven here, and credited.
- **[mstan](https://github.com/mstan)** — [MegaManX6Recomp](https://github.com/mstan/MegaManX6Recomp) (PolyForm
  Noncommercial). Its documentation of the overlay loader is a lead for the load map. Its generated code is not used.
- **acediez** — [*Mega Man X6 Tweaks*](https://www.romhacking.net/hacks/4035/) and its documentation of the game's tables.
- **Shinnuu** — the [Archipelago Mega Man X6 world](https://github.com/Shinnuu/Archipelago) and its RAM research.
- **[The Cutting Room Floor](https://tcrf.net/Mega_Man_X6)** — the prototype and version history.

The governance and method come from ProjectArchitect 3 and the decomp-architect kit distilled from a finished
matching decompilation (Brave Fencer Musashi).

## License

The project's own work — the tooling, the build system, the documentation — is licensed under AGPL-3.0
([`LICENSE`](LICENSE)). No rights are claimed over Capcom's game or the decompiled source. Adapted mmx4 files keep
their attribution and license, listed in [`THIRD_PARTY.md`](THIRD_PARTY.md). **No license is asserted over the
reimplemented sources under `src/`** ([`src/NOTICE.md`](src/NOTICE.md)). Third-party components keep their own
licenses. *Mega Man X6* is the property of its rights holder.
