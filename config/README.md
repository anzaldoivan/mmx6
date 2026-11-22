# `config/` — project configuration (hand-edited)

This directory holds these items.

- `firewall.txt` is the one source of the ROM firewall. It holds the purge/glob rules and the hash sources.
  `tools/audit_public.py` reads it.
- `firewall-fixture.sha1` is the planted-fixture control hash.
- `decomp-hooks.snippet.json`
- `mcp.json.template`
- `medium.sha1` is the sha1 of the dump (sha1sum format). It is a `required:` source with `manifest/us.jsonl`
  (Phase 1.1 T5).

- `versions.tsv` is the version registry (`version serial triple`). Its serial joins `discs.tsv`. `make` stops on a
  `VERSION` with no row, and on a Makefile `TRIPLE` default that differs from the row's triple.

These items belong to Phase 1.3. The address-bound ones sit in `us/` (`config/<version>/`, one directory per build
version). Only `us` exists. The shared ones stay here.

- `us/main.yaml` is the splat config of the executable. `us/rock_NN.yaml` are the overlays' configs.
- `us/symbols.<bin>.txt` holds the splat symbol names (`name = 0xADDR; // basis: <src>`).
- `us/carve.<bin>.txt` and `us/carve.<bin>.mk`, `us/dedup_registry.txt`, `us/equiv-keys.txt`,
  `us/boundary_exceptions.txt` and `us/data_bytes.tsv` are address-bound too.
- `check.<bin>.sha` is the build hash gate (`<sha1>  build/<bin>`). The Makefile maps `build/` to `build/us/`.
- `segmentation.md` holds the TU segmentation rules.
- `us/boundaries.txt` and `us/loadmap.txt` are the split evidence.
- `ghidra/` is the database text export.

These items are hand-edited: `firewall.txt`, `medium.sha1`, the snippets/templates, `us/symbols.*.txt`,
`segmentation.md`, and the `us/main.yaml` header and options. Write each hash file from the tool run that
verified it. Never type a hash file.

These items are generated. `tools/mmx6/segment.py <bin>` generates the `us/main.yaml` subsegment block between
its BEGIN/END markers. `make boundaries` generates `us/boundaries.txt`. `make loadmap` generates `us/loadmap.txt`. What
these files drive lands in the ignored `asm/`, `build/`, `expected/`, `extracted/`.

`make fleet` builds every `config/us/*.yaml` from clean and gates each on its `check.<bin>.sha`. Its last line is
`FLEET 57 of 57` (snapshot 2026-10-24, `make fleet`). The count of that line must equal `us/loadmap.txt` `N =`. `make expected` copies `build/us/` to `expected/us/`.

Firewall (G12): tracked = published. Track names, addresses, hashes and configuration only. Track no game-derived
bytes and no pasted disassembly. `tools/audit_public.py` hashes every tracked file against the sources in
`firewall.txt`.
