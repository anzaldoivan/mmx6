# Oracles: static (Ghidra + psx_ldr) and runtime (PCSX-Redux Lua) commands

Mac-only, native (never the container). Runtime oracle (PCSX-Redux Lua): `## Runtime` below (T4.c1).

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

## MCP server
GhidrAssistMCP (extension in `$GHIDRA_HOME/Ghidra/Extensions/GhidrAssistMCP`), headless on `ghidra/mmx6`, program `SLUS_013.95`.
- Start: `make ghidra-mcp-start` (tools/mmx6/ghidra/mcp_start.sh) → detached `analyzeHeadless … -process SLUS_013.95
  -noanalysis -postScript GAMCPStartServerScript.java host=localhost port=8080 wait=true completion_file=.run/ghidra/mcp.complete`;
  pid `.run/ghidra/mcp.pid`, log `.run/ghidra/mcp.log`; rc 0 once `GET /sse` → 200 (≤ 120 s), else stopped and rc 1;
  rc 2 if already running or any Ghidra JVM is alive.
- Endpoints: SSE `http://localhost:8080/sse` (+ `POST /message`), streamable HTTP `/mcp`. Health:
  `curl --max-time 3 -s -o /dev/null -w '%{http_code}' http://localhost:8080/sse` → `200` (curl rc 28 is normal: SSE stays open).
- Stop: `make ghidra-mcp-stop` (mcp_stop.sh) → creates the completion file (server closes, Ghidra saves, exits); fallback
  SIGTERM then SIGKILL to the pid's process group (reported, rc 1); then a read-only reopen (DumpProgramInfo →
  `.run/ghidra/mcp-reopen.txt`) must succeed, else rc 1. Nothing running → message, rc 0.
- Saves happen only on a clean stop (log line `Save succeeded for processed file`); a SIGKILL loses unsaved work.
- The project lock is exclusive: `make ghidra-import` and any export/headless script need the server stopped first.
- Client: tracked `.mcp.json` (from config/mcp.json.template) `"disassembler"` SSE. A restarted server leaves the client
  stale: the developer runs `/mcp` (or it connects at the next session start); verify with one cheap call (G2,
  docs/ops/disassembler-mcp.md).

## Annotation export and round trip
- Export: `make ghidra-export PYTHON=<py>` → `tools/mmx6/ghidra/export.sh SLUS_013.95` (`[PROG] [--project DIR] [--out F]`):
  `analyzeHeadless ghidra mmx6 -process <PROG> -readOnly -noanalysis -postScript ExportAnnotations.java <out>`; default
  out `config/ghidra/<PROG>.jsonl` (tracked); log `.run/ghidra/export-<PROG>.log`; ~10 s. Never writes the project.
- Format: one JSON object per line, fixed key order, no whitespace, addresses `"0x%08x"`, rows sorted per kind; byte-stable
  (two exports `cmp`-equal). Kinds `k`: program (lang, cspec, image_base, format), block, archive, type (local
  types, namespace `/mmx6/`), func (name, ret, cc, flags, params, locals, comment), data (addr, type path, len; no values),
  comment (eol/pre/post/plate/repeat), bookmark, equate, label (non-default). No instruction words or bytes (G12).
- Round trip: `make ghidra-roundtrip PYTHON=<py>` → `tools/mmx6/ghidra/roundtrip.sh SLUS_013.95` (`[PROG…] [--jsonl F]`):
  fresh `import.sh` into scratch project `.run/ghidra/rebuild/` (opened via symlink `ghidra/rebuild`, since Ghidra rejects
  `.`-leading path elements), `ImportAnnotations.java` of the committed file (or `--jsonl F`), re-export to
  `.run/ghidra/rebuild/<PROG>.jsonl`, `cmp`. rc 0 + `ROUNDTRIP OK <k> programs`, else first differing line, rc 1.
  ~146 s (import 140 s, apply 3 s, export 3 s). Logs `.run/ghidra/rebuild/<PROG>.{import,apply,export}.log`.
- ImportAnnotations refuses (prints `MMX6ANN ERROR`, applies nothing) on a language/image-base mismatch or an unknown `k`.
- Negative control: rename one func in a copy (`.run/ghidra/neg.jsonl`), `roundtrip.sh SLUS_013.95 --jsonl .run/ghidra/neg.jsonl`
  → rc 1 with the differing line (the unchanged label row renames the function back).
- Precondition: MCP server stopped (exclusive project lock).

## Runtime
- `make redux-smoke` (`REDUX ?= ~/Applications/PCSX-Redux.app/Contents/MacOS/PCSX-Redux`, `BIOS ?=` SCPH1001.BIN,
  `REDUX_CUE ?=` the host .cue; not `CUE`, the container path) → `tools/mmx6/redux/run.sh tools/mmx6/redux/smoke.lua
  --timeout 240`. ~52 s wall; rc 0; `.run/redux/smoke/{binseek1,frame4000,binseek2}.{bin,json}` (2 MiB RAM at 0x80000000).
- `run.sh <lua> [--timeout S] [--state F]`: `-no-ui -testmode -stdout -lua_stdout -portable -interpreter -debugger
  -bios -iso -run -dofile <lua>`, cwd `.run/redux/work` (portable config + memcards there), log
  `.run/redux/logs/<stem>-<stamp>.log`; rc = `PCSX.quit(code)`; timeout → kill by pid, rc 124. Env to Lua:
  `MMX6_ROOT`, `MMX6_REDUX_STATE`.
- Flags found necessary (2026-10-01, build f7b388cc): without `-interpreter` the arm64 dynarec dies (SIGBUS/SIGILL)
  ~1 s into emulation; Exec breakpoints fire only with `-debugger`; a missing `-dofile` file does not exit (hangs).
- `tools/mmx6/redux/lib.lua`: `breakpoint(addr,label,fn(regs))`, `onVsync(fn(frame))` (frame = `GPU::Vsync` count),
  `dumpRange/dumpRAM/writeText/dumpScreen`, `word(addr)`, pad `press/release/mash/padSchedule`, `loadState()`, `quit`. Sets `PCSX.settings.spu.Speed = 0` (unthrottled, ~150 fps).
  Anchors listeners/breakpoints in global `MMX6_LIB`: anything only reachable from chunk locals is GC'd after the
  chunk returns and the next callback crashes Redux.
- Determinism (no input; frames 1478/7787 in 3 runs, 8862 in 2, 8886 in 1): BinSeek 0x80016858 hits at frames 1478 (a0 0x12, a1 0x800E9860, ra 0x80013E84),
  7787 (same), 8862 (a0 0, a1 0x801EA000, ra 0x80013CE4), 8886 (a0 2, a1 0x800E9860).
- `make redux-loads` (T5.c1; same vars) → `MMX6_INPUTS=<f> run.sh tools/mmx6/redux/loads.lua --timeout 600` for every
  `tools/mmx6/redux/inputs/*.lua`; ~45 s per schedule; stops at the first rc ≠ 0. `loads.lua`: Exec bp BinSeek
  0x80016858 → record (caller = ra, index = a0, dest = a1, size = TOC word 0x800E0B58+8·index+4) and dump
  `[dest,dest+size)` before; "after" dump at 0x80016628 in ready callback 0x800165A4 on the first hit with remaining
  (word 0x800E01A8) = 0 (all callers). Out `.run/redux/loads/<run>.jsonl` (`seq frame caller index dest size before
  after w10000`; `w10000` = word at 0x80010000 = the 0x80013E7C base), `<run>-<seq>-{before,after}.bin`,
  `<run>.summary.txt`. Optional `MMX6_SCREEN_EVERY=N` → `.run/redux/screens/<run>/f<frame>-<w>x<h>-<bpp>.bin`
  (`PCSX.GPU.takeScreenShot`, raw pixels; bpp 0 = BGR555, 1 = RGB24) for finding pad timings.
- Pad schedules `inputs/<name>.lua` return `{name, steps = {{frame,'BUTTON',hold},…}, stop}` (frames = Vsync count
  from power-on; `MMX6_LIB.mash(btn, from, to, every, hold)` builds taps). Pad API (in the Redux binary's pad.cc Lua
  binding): `PCSX.SIO0.slots[1].pads[1].setOverride(PCSX.CONSTS.PAD.BUTTON.START)` holds a button,
  `clearOverride(b)` releases; lib `press/release(name)`, `padSchedule(steps)`. `intro_stage`: START taps skip the
  intro story and pick Game Start (stage load ~2773), CROSS advances the dialog (START does not), RIGHT walks;
  gameplay by ~3500. Deterministic: same jsonl in 2 runs.
- `PY tools/mmx6/loadmap.py --captures .run/redux/loads --summary`: counts per dest and caller; rc 0 iff ≥ 1 load to
  0x801EA000, 0x800FA000 and from 0x80013E7C (observed base 0x800E9860 = w10000).
- Exe load proof: `PY tools/mmx6/exeproof.py .run/redux/smoke [--base 0x80010000]` (body words + whole-image fraction
  per dump). Proof row for `docs/memory-map.md` pending: 4 body words differ (T4.c1 log).
