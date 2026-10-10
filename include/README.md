# `include/` — headers shared by `src/` (hand-edited)

What lives here: the project's own headers (types, structs, globals, macros) included by `src/`; first files arrive with
segmentation (Phase 1.3).

`common.h` (Phase 1.4 T2) is included first by every C unit: `INCLUDE_ASM(FOLDER, NAME)` assembles a not-yet-decompiled
function's splat `.s` from the ignored `asm/<bin>/nonmatchings/` in place; fixed-width typedefs `u8 s8 u16 s16 u32 s32` (via `mmx6/types.h`);
`NON_MATCHING` drafts sit under `#ifdef NON_MATCHING`, which the default build never defines. `macro.inc` holds the label
macros for splat's asm.

`mmx6/types.h` (Phase 1.6 T3) is the one home of types: every typedef and struct is defined there, once, each with an
`// evidence:` line; `common.h` includes it; `tools/mmx6/typecheck.py` (rung `th-types`) refuses any other home.

Hand-edited: every header here; formatted only in the container (`make format` covers `src/`; see `Makefile`).
Generated: nothing.

Firewall (G12): tracked = published. Never copy vendor SDK headers here: the SDK is user-supplied and ignored
(`tools/psyq/`, purge class 6); declare what the code needs in our own words. `tools/audit_public.py` hashes every tracked file.
