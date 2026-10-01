# `config/` — project configuration (hand-edited)

What lives here: `firewall.txt`, the ROM firewall's one source (purge/glob rules + hash sources, read by
`tools/audit_public.py`); `firewall-fixture.sha1`, the planted-fixture control hash; `decomp-hooks.snippet.json`;
`mcp.json.template`. Later phases add the files `firewall.txt` lists as `pending:` (`medium.sha1`, `check.*.sha`) and the
splat/symbol configuration.

Hand-edited: everything here; hash files are written from the tool run that verified them, never typed.
Generated: nothing. What these files drive lands in the ignored `asm/`, `build/`, `expected/`, `extracted/`.

Firewall (G12): tracked = published. Names, addresses, hashes and configuration only; no game-derived bytes, no pasted
disassembly. `tools/audit_public.py` hashes every tracked file against the sources in `firewall.txt`.
