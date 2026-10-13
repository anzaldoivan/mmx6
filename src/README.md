# `src/` — the decompiled C (hand-edited)

What lives here: C that the game's own compiler turns back into the original code byte for byte. Once segmentation
lands (Phase 1.3), there is one file per translation unit. Legal status and what this tree does not contain: `NOTICE.md`.

A C unit is `src/<bin>/<tu>.c`, one per TU listed in `config/c_units.txt`. First, splat writes it once (names and
`INCLUDE_ASM` lines only). Then functions are decompiled in place. The Makefile C rule builds it
(`build/%.c.o: %.c`, compiler triple `TRIPLE` from `config/triples.txt`). See docs/ops/decomp-environment.md.

Hand-edited: every `.c`/`.h` here. Formatted only in the container:
`mx.sh sync && mx.sh run make format && mx.sh pull <paths>` (the Mac has no clang-format).
Generated: nothing. Disassembly stays in the ignored `asm/`. Never paste it here.

Firewall (G12): tracked = published. C only: no listings of target instructions, no blobs copied from the disc.
`tools/audit_public.py` hashes every tracked file.
