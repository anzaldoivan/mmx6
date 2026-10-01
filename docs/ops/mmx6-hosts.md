# Hosts, paths and pins — mmx6

As known at generation (2026-10-01). Update in the same change as whatever changes a line (H7).

## Hosts
- **Mac (arm64):** Claude Code + PA3, the repository at `~/orca/mmx6`; Ghidra 12.1.x + psx_ldr + GhidrAssistMCP
  (static oracle); PCSX-Redux with Lua (runtime oracle).
- **amd64 Docker host:** Docker Desktop on the Mac (context `desktop-linux`); builds run there with the source in a
  named volume (the DC2 arrangement). One tree, driven by `tools/docker/mx.sh build|sync|pull|disc|run` (Phase 1.0, T2):
  - Agents edit the Mac clone only; volume `mmx6-work` is a disposable copy mounted at `/work`.
  - `mx.sh sync` before any run after host edits: wipes `/work` (except `/work/.run`) and copies tracked +
    untracked-non-ignored files; never `.git` or ignored paths. Container edits outside `/work/.run` are lost on the next sync.
  - `mx.sh pull <path>...` brings named relative container outputs back; refuses absolute, `..`, firewall paths (G12).
  - No bind mounts of host paths. Image `mmx6-build`. Env overrides `MX6_IMAGE`, `MX6_VOLUME`, `MX6_DISC_VOLUME`
    (override per worktree, cookbook C0004).
  - Dump loaded via `mx.sh disc /Users/ThinkPad/GameInputs/megaman-x6` (top-level `*.cue`/`*.bin` only, BIOS skipped)
    into volume `mmx6-disc`, mounted read-only at `/disc` by `mx.sh run`.

## Game inputs (never committed)
- Dump: `/Users/ThinkPad/GameInputs/megaman-x6/Mega Man X6 (USA) (v1.1).cue` (+ `.bin`, 599,985,792 bytes);
  Redump USA v1.1, SHA-1 `d4f7e08371027a87a3bf13311db5a4c56733f4ea`, verified 2026-10-01.
- BIOS for the emulator: `/Users/ThinkPad/GameInputs/megaman-x6/SCPH1001.BIN`.
- Layout: one MODE2/2352 track; `SYSTEM.CNF` boots `SLUS_013.95`; code overlays in `ROCK_X6.BIN`; XA/STR streams.

## Scratch
- Scratch under `.run/`; cap and warning threshold set in Phase 1.1 (default: cap 25 GB, warn 20 GB, as DC2).

## Pins
- Python: `/opt/homebrew/opt/python@3.14/bin/python3.14` (from `.claude/pa.json`).
- Compiler triple: TODO — pinned by evidence in Phase 1.4 (first candidate: mmx4's X4 triple — gcc 2.7.2 cc1 + maspsx 2.56 `--expand-div`, `-O2 -G0 -msoft-float -funsigned-char` — a lead, G101; docs/prior-art.md L1).
- splat, binutils, the assembler shim, the formatter: TODO — pinned by the phase that installs them.
- Build image (2026-10-01): base `ubuntu:24.04@sha256:008173c23f95b170204355c12626cb5a965d779a7e1283b09e9cffbb1bf33ca3`
  (multi-arch index); `mmx6-build` config `sha256:52d752e194b5430ce7819412a97c4f101628fe90f4e62db0580749bb9d92b4ba`
  (image id `sha256:ca8e49c0…` changes per build with the attestation manifest).
- PA3 tier: `max5` (Claude Max 5x).
