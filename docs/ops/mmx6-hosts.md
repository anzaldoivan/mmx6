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
- Extraction: `make extract` (Mac: `PYTHON=<PY> CUE=<dump cue>`; container: `mx.sh sync && mx.sh run make extract`) writes
  ignored `extracted/retail/` and tracked `manifest/retail.jsonl` (68 records, sha1 `262452fe…b0`, identical Mac py3.14 /
  container py3.12, Phase 1.1 T5); firewall `required:` sources: `manifest/retail.jsonl`, `config/medium.sha1`.
- Layout: one MODE2/2352 track; `SYSTEM.CNF` boots `SLUS_013.95`; code overlays in `ROCK_X6.BIN`; XA/STR streams.

## Scratch
- Scratch under `.run/`; cap and warning threshold set in Phase 1.1 (default: cap 25 GB, warn 20 GB, as DC2). See `.run/README.md`.

## Pins
- Python: `/opt/homebrew/opt/python@3.14/bin/python3.14` (from `.claude/pa.json`).
- Compiler candidates (Phase 1.4 T1, 2026-10-01, R1.4-001): cc1 only, from decompals/old-gcc release tag `0.17`
  (`gcc-<name>.tar.gz`: 2.7.2-psx 2.7.2-cdk 2.6.3-psx 2.8.0-psx 2.8.1-psx 2.91.66-psx 2.95.2-psx) + tag `0.9`
  (`gcc-2.7.2.tar.gz`, name `2.7.2`), each sha256-asserted in the Dockerfile, at `/opt/cc/<name>/cc1` (static i386 ELF).
  Makefile `OLDGCC_PIN`/`CC1_SET`. Pinned triple (Phase 1.4 T7): `gcc2.95.2-psx-aspsx2.86`
  (docs/ops/compiler-pin.md); the other cc1 stay installed as the ladder's negative rungs.
- cc1 2.95.2-psx source (Phase 1.7 T1, 2026-10-01): GNU `gcc-2.95.2.tar.gz` sha256
  `064e1cb06ea5d2f4a07ec46c1c64d771f74d04f404b6a6766bca2477f7d72482` + old-gcc @`b74211c9d959e9724802f3177c8229cd67202c87`
  (tag 0.17) psx edits, built in stage `gccsrc` from `ubuntu:focal@sha256:8feb4d8ca5354def3d8fce243717141ce31e2c428701f6682bd2fafe15388214`;
  staged at `/opt/gcc-2.95.2-src`, tree digest `8d8a1a5be69d98ae9921359eb356de36d7689f37c854bef29c6f77737e59781e`.
  Makefile `GCCSRC_SHA`/`GCCSRC_TREE`/`GCCSRC_PATCHES`; `make toolchain-check` line `GCCSRC …` (docs/ops/compiler-pin.md ## Source).
- splat / binutils / cpp (Phase 1.3 T1, 2026-10-01): `splat64[mips]==0.50.0` + `spimdisasm==1.42.4` + `rabbitizer==1.16.2`
  (PyPI; `pip index versions splat64` checked 2026-10-01: newest 0.50.0; deps from the first build's `pip freeze`) in venv
  `/opt/splat-venv` on PATH; `binutils-mipsel-linux-gnu` 2.42 (as/ld/objcopy) and `cpp-mipsel-linux-gnu` 12.4.0 from
  Ubuntu 24.04 apt via the pinned base. Makefile `SPLAT_PIN`/`BINUTILS_PIN`/`CPP_PIN`; `mx.sh run make toolchain-check`.
- Assembler shim: maspsx (mkst) commit `7686f845a181700534c83c0419183e38aeb3e49c` (2026-10-01, R1.4-001) at `/opt/maspsx`,
  wrapper `/usr/local/bin/maspsx`; python3 stdlib only. Makefile `MASPSX_PIN`; `make toolchain-check` smokes each cc1 through it.
- Decompile scaffold / differ (Phase 1.4 T4, 2026-10-01, upstream HEAD): m2c (matt-kempster) commit
  `708d2d2cb2698f091a92492b328f73b24209f72d` at `/opt/m2c`; asm-differ (simonlindholm) commit
  `0dd09af8f8008f1f880327cf0aca3b26d2562ea2` at `/opt/asm-differ`; runtime deps in `/opt/splat-venv` at their poetry.lock
  versions (graphviz 0.20.3, colorama 0.4.6, watchdog 6.0.0, levenshtein 0.27.1, rapidfuzz 3.13.0, cxxfilt 0.3.0).
  Makefile `M2C_PIN`/`ASMDIFFER_PIN`; `make toolchain-check` checks both commits.
- Formatter (2026-10-01): `Ubuntu clang-format version 18.1.3 (1ubuntu1)` from the pinned image's apt (≥ 15, so `.clang-format` InsertBraces applies); runs only in the container: `mx.sh sync && mx.sh run make format && mx.sh pull <paths>`.
- Build image (2026-10-01): base `ubuntu:24.04@sha256:008173c23f95b170204355c12626cb5a965d779a7e1283b09e9cffbb1bf33ca3`
  (multi-arch index); `mmx6-build` config `sha256:5d1d605eab919468afd3208988ee429d1a211a2b382176ab4b5c8a91239c9b7b`
  (Phase 1.4 T1, was `sha256:c3628cd3…` at 1.3 T1, `sha256:ed5326e0…` at 1.1 T4; image id `sha256:c68c8868…` informational, changes per build with the attestation manifest).
- mkpsxiso / dumpsxiso (T4, 2026-10-01): commit `54fb1644ed8741223583e2dcda358b75a205e214` (v2.30), built in the image
  (`cmake` from apt), `dumpsxiso` at `/usr/local/bin`; reference extractor for `make extract`.
- Ghidra (2026-10-01): 12.1.3 at `~/ghidra_12.1.3_PUBLIC`, run headless by `make ghidra-import` (docs/ops/oracles.md);
  Java `openjdk version "21.0.4" 2024-07-16 LTS` (Temurin-21.0.4+7), the `java` on PATH.
- Ghidra extensions (2026-10-01): `ghidra_psx_ldr` (DrMefistO) and `GhidrAssistMCP` (jtang613 per README), both
  `extension.properties version=12.1.3`; no release/commit id in Module.manifest, README or jar manifests
  (empty `MANIFEST.MF`); psx_ldr `-src.zip` entries dated 2026-09-03.
- PCSX-Redux (2026-10-01): dev channel build 279, changeset `f7b388cc1e6555e2caf3ad78ed431126a546214a` (timestamp
  1790813560), from the bundle's `Contents/Resources/share/pcsx-redux/version.json` (Info.plist has no version);
  `~/Applications/PCSX-Redux.app`, macOS arm64; LuaJIT 2.1.1785598229 (startup banner). Runtime oracle, docs/ops/oracles.md.
- PA3 tier: `max5` (Claude Max 5x).
