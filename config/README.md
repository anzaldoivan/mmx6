# `config/` — project configuration (hand-edited)

What lives here: `firewall.txt`, the ROM firewall's one source (purge/glob rules + hash sources, read by
`tools/audit_public.py`); `firewall-fixture.sha1`, the planted-fixture control hash; `decomp-hooks.snippet.json`;
`mcp.json.template`; `medium.sha1`, the dump's sha1 (sha1sum format), a `required:` source with `manifest/retail.jsonl`
(Phase 1.1 T5). Phase 1.3: `SLUS_013.95.yaml`, the splat config of the executable; `symbols.<bin>.txt`, splat symbol
names (`name = 0xADDR; // basis: <src>`); `check.<bin>.sha`, the build hash gate (`<sha1>  build/<bin>`);
`segmentation.md`, the TU segmentation rules; `boundaries.txt` and `loadmap.txt`, the split evidence; `ghidra/`, the
database text export.

Hand-edited: `firewall.txt`, `medium.sha1`, the snippets/templates, `symbols.*.txt`, `segmentation.md`, and the
`SLUS_013.95.yaml` header and options; hash files are written from the tool run that verified them, never typed.
Generated: the `SLUS_013.95.yaml` subsegment block between its BEGIN/END markers (`tools/mmx6/segment.py <bin>`);
`boundaries.txt` (`make boundaries`) and `loadmap.txt` (`make loadmap`). What these files drive lands in the ignored
`asm/`, `build/`, `expected/`, `extracted/`.
`make fleet` builds every `config/*.yaml` from clean and gates each on its `check.<bin>.sha` (last line `FLEET 57 of 57`; its count must equal `loadmap.txt` `N =`); `make expected` copies `build/` to `expected/build/`.

Firewall (G12): tracked = published. Names, addresses, hashes and configuration only; no game-derived bytes, no pasted
disassembly. `tools/audit_public.py` hashes every tracked file against the sources in `firewall.txt`.
