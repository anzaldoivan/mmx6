# NOTICE — the sources under `src/`

The C files under `src/` are a **reimplementation of the executable code of *Mega Man X6*** (Sony PlayStation (MIPS R3000A),
USA SLUS-01395 (disc v1.1)). They are written so that the game's own compiler turns them back into the original machine
code byte for byte. They exist for **study, interoperability and preservation**. They exist to document how the game
works and to make its code readable. They also exist to keep it buildable after the original tools and media are gone.

*Mega Man X6* and its code are **© TODO(publisher, year)**. The original work is theirs. This project is not
affiliated with, sponsored by or endorsed by the rights holder.

**No license is asserted over the contents of `src/`.** They are derived from the copyrighted program. They are published
as a reimplementation for the purposes above, in the manner of other matching decompilations of commercial games.

Nothing here grants anyone more rights in the original work than they already have. Nothing here should be read as a
license to distribute the game or its compiled code. The compiled output of these sources is, by design, identical to
the original binaries. Distributing that output is distributing the game's code. Do not distribute that output.

What this repository does **not** contain: the game's executable, its disc or cartridge data, any disassembly listing,
any memory image, or the vendor's SDK. Building requires your own copy of the game (see the top-level `README.md`).

The rest of the repository — the tooling under `tools/`, the build system and the documentation under `docs/` — is the
project's own work. It is licensed under AGPL-3.0 for the project's own tools and documents (`LICENSE`). No rights are
claimed over Capcom's game or the decompiled source (`LICENSE`). Adapted mmx4 files keep their attribution and license,
listed in THIRD_PARTY.md (`LICENSE`). Third-party components are listed with their licenses in `THIRD_PARTY.md`.
