# `include/` — headers shared by `src/` (hand-edited)

What lives here: the project's own headers (types, structs, globals, macros) included by `src/`; first files arrive with
segmentation (Phase 1.3).

Hand-edited: every header here; formatted only in the container (`make format` covers `src/`; see `Makefile`).
Generated: nothing.

Firewall (G12): tracked = published. Never copy vendor SDK headers here: the SDK is user-supplied and ignored
(`tools/psyq/`, purge class 6); declare what the code needs in our own words. `tools/audit_public.py` hashes every tracked file.
