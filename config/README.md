# `config/` — project configuration (hand-edited)

This directory holds these items.

- `firewall.txt` is the one source of the ROM firewall. It holds the purge/glob rules and the hash sources.
  `tools/audit_public.py` reads it.
- `firewall-fixture.sha1` is the planted-fixture control hash.
- `decomp-hooks.snippet.json`
- `mcp.json.template`
- `medium.sha1` is the sha1 of the dump (sha1sum format). It is a `required:` source with `manifest/retail.jsonl`
  (Phase 1.1 T5).

These items belong to Phase 1.3.

- `SLUS_013.95.yaml` is the splat config of the executable.
- `symbols.<bin>.txt` holds the splat symbol names (`name = 0xADDR; // basis: <src>`).
- `check.<bin>.sha` is the build hash gate (`<sha1>  build/<bin>`).
- `segmentation.md` holds the TU segmentation rules.
- `boundaries.txt` and `loadmap.txt` are the split evidence.
- `ghidra/` is the database text export.

These items are hand-edited: `firewall.txt`, `medium.sha1`, the snippets/templates, `symbols.*.txt`,
`segmentation.md`, and the `SLUS_013.95.yaml` header and options. Write each hash file from the tool run that
verified it. Never type a hash file.

These items are generated. `tools/mmx6/segment.py <bin>` generates the `SLUS_013.95.yaml` subsegment block between
its BEGIN/END markers. `make boundaries` generates `boundaries.txt`. `make loadmap` generates `loadmap.txt`. What
these files drive lands in the ignored `asm/`, `build/`, `expected/`, `extracted/`.

`make fleet` builds every `config/*.yaml` from clean and gates each on its `check.<bin>.sha`. Its last line is
`FLEET 57 of 57` (snapshot 2026-10-24, `make fleet`). The count of that line must equal `loadmap.txt` `N =`. `make expected` copies `build/` to `expected/build/`.

Firewall (G12): tracked = published. Track names, addresses, hashes and configuration only. Track no game-derived
bytes and no pasted disassembly. `tools/audit_public.py` hashes every tracked file against the sources in
`firewall.txt`.
