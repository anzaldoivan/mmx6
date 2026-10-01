# Oracles: static (Ghidra + psx_ldr) commands

Mac-only, native (never the container). Runtime oracle (PCSX-Redux Lua): TODO(T5).

## Import
- `make ghidra-import PYTHON=<py>` (`GHIDRA_HOME ?= $(HOME)/ghidra_12.1.3_PUBLIC`) runs
  `tools/mmx6/ghidra/import.sh --program SLUS_013.95`. ~2.5 min (PsyQ Signatures analyzer ~2 min).
- `import.sh [--program SLUS_013.95 | --member NN --base 0xADDR] [--project DIR]`:
  - `--program <name>`: input `extracted/retail/iso/<name>`; program name = basename. Default `SLUS_013.95`.
  - `--member`: not yet (T4); exits 2.
  - `--project DIR`: project dir (default `<repo>/ghidra`, project name `mmx6`; ignored + purged, never tracked).
    Ghidra rejects any path element starting with `.` (so not under `.run/`).
  - Refuses (rc 2) when the file's sha1 != its `manifest/retail.jsonl` record (G22); missing input → `make extract`.
  - `analyzeHeadless <dir> mmx6 -import <exe> -overwrite -loader PsxLoader -postScript DumpProgramInfo.java <info> <sha1>`:
    loader "PSX Executables Loader" with default options (RAM base/size, PsyQ version auto-detected; no `-loader-*`
    flags passed); default auto-analysis incl. psx_ldr "PsyQ Signatures" (applies its own `psyq/<ver>/` sigs + GDT,
    so no ImportPsyqGdt step). `-overwrite` makes a re-run idempotent (same info file twice, 2026-10-01).
- Lock: the project lock is exclusive. Stop the Ghidra GUI / GhidrAssistMCP server first; import.sh refuses (rc 2)
  while any `ghidra.Ghidra` JVM is alive, then clears a stale `mmx6.lock`. After a restart, reconnect the MCP client
  (docs/ops/disassembler-mcp.md, G2).

## Info file `.run/ghidra/info/<program>.txt`
One `key: value` per line, hex lowercase 8 digits:
`language: <languageID>:<compilerSpec>` · `image_base: 0x…` · `entry: 0x…` (first external entry point in an
initialized non-GTEMAC block) · `psyq_version: <v|none>` (Program Information property "PsyQ Version", set by the
loader's DetectPsyQ) · `sig_functions: <n>` · `functions: <n>` (all functions) · `input_sha1: <sha1>` (verified
against the manifest by import.sh).

## sig_functions method
psx_ldr `SigApplier` names each signature match with `FlatProgramAPI.createFunction(addr, name)` (USER_DEFINED) or
`createLabel(..., IMPORTED)`; Ghidra's own analyzers name with DEFAULT/ANALYSIS. So sig_functions = functions whose
primary symbol source is USER_DEFINED or IMPORTED, in an initialized block other than `GTEMAC` (the loader's IMPORTED
GTE macro stubs), excluding the entry point (`start`) and `main` (loader-named). DumpProgramInfo also logs the
USER_DEFINED/IMPORTED split.
- Negative control (2026-10-01): same import with `-noanalysis` → `sig_functions: 0`, `functions: 1`.
- Not a valid control: disabling the analyzer by preScript `setAnalysisOption(.., "PsyQ Signatures", "false")` —
  the analyzer still ran (35 s, 402 counted); do not rely on that option headlessly.
- Values (SLUS_013.95, 2026-10-01): `psyq_version: 4.7.0`, `sig_functions: 811` (543−2 USER_DEFINED + 270 IMPORTED),
  `functions: 1520`, `entry: 0x80054ad8`, `image_base: 0x80000000`, `language: PSX:LE:32:default:default`.
