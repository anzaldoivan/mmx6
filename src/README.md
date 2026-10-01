# `src/` — the decompiled C (hand-edited)

What lives here: C that the game's own compiler turns back into the original code byte for byte, one file per translation
unit once segmentation lands (Phase 1.3). Legal status and what this tree does not contain: `NOTICE.md`.

Hand-edited: every `.c`/`.h` here. Formatted only in the container:
`mx.sh sync && mx.sh run make format && mx.sh pull <paths>` (the Mac has no clang-format).
Generated: nothing. Disassembly stays in the ignored `asm/`; never paste it here.

Firewall (G12): tracked = published. C only: no listings of target instructions, no blobs copied from the disc;
`tools/audit_public.py` hashes every tracked file.
