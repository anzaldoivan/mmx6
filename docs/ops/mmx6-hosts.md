# Hosts, paths and pins — mmx6

As known at generation (2026-10-01). Update in the same change as whatever changes a line (H7).

## Hosts
- **Mac (arm64):** Claude Code + PA3, the repository at `~/orca/mmx6`; Ghidra 12.1.x + psx_ldr + GhidrAssistMCP
  (static oracle); PCSX-Redux with Lua (runtime oracle).
- **amd64 Docker host:** Docker Desktop on the Mac (context `desktop-linux`); builds run there with the source in a
  named volume (the DC2 arrangement). How the Mac clone and the volume stay one tree: **decided in Phase 1.0** — record
  it here.

## Game inputs (never committed)
- Dump: `/Users/ThinkPad/GameInputs/megaman-x6/Mega Man X6 (USA) (v1.1).cue` (+ `.bin`, 599,985,792 bytes);
  Redump USA v1.1, SHA-1 `d4f7e08371027a87a3bf13311db5a4c56733f4ea`, verified 2026-10-01.
- BIOS for the emulator: `/Users/ThinkPad/GameInputs/megaman-x6/SCPH1001.BIN`.
- Layout: one MODE2/2352 track; `SYSTEM.CNF` boots `SLUS_013.95`; code overlays in `ROCK_X6.BIN`; XA/STR streams.

## Scratch
- Scratch under `.run/`; cap and warning threshold set in Phase 1.1 (default: cap 25 GB, warn 20 GB, as DC2).

## Pins
- Python: `/opt/homebrew/opt/python@3.14/bin/python3.14` (from `.claude/pa.json`).
- Compiler triple: TODO — pinned by evidence in Phase 1.4 (first candidate: gcc 2.6.3 cc1 + aspsx 2.63, a lead, G101).
- splat, binutils, the assembler shim, the formatter: TODO — pinned by the phase that installs them.
- PA3 tier: `max5` (Claude Max 5x).
