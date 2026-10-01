# Oracles: static (Ghidra + psx_ldr) and runtime (PCSX-Redux Lua) commands

Mac-only, native (never the container). Runtime oracle (PCSX-Redux Lua): `## Runtime` below (T4.c1).

## Import
- `make ghidra-import PYTHON=<py>` (`GHIDRA_HOME ?= $(HOME)/ghidra_12.1.3_PUBLIC`) runs
  `tools/mmx6/ghidra/import.sh --program SLUS_013.95`. ~2.5 min (PsyQ Signatures analyzer ~2 min).
- `make ghidra-import-overlays PYTHON=<py>` runs `import.sh --member all`: every `code` row of `config/loadmap.txt`
  (56) as program `rock_NN`, one JVM per base group (0x800E9860 ×30, 0x800FA000 ×24, 0x801EA000 ×2); ~6 min total.
- `import.sh [--program SLUS_013.95 | --member NN[,NN…]|all [--base 0xADDR] | --list] [--project DIR]`:
  - `--program <name>`: input `extracted/retail/iso/<name>`; program name = basename. Default `SLUS_013.95`.
  - `--member`: input `extracted/retail/rock/NN.bin` (manifest path `rock/NN.bin`, sha1-checked), hard-linked as
    `.run/ghidra/stage/rock_NN` (the program name). Base = the loadmap row for NN; rc 2 if the row is not `code`
    (e.g. `--member 13` data, 41 empty) or `--base` differs (`--member 0 --base 0x801EA004`). Raw import
    `-loader BinaryLoader -loader-baseAddr 0x0 -processor PSX:LE:32:default -cspec default`, then
    `-preScript PrepareOverlay.java 4.7.0 <base>`: `setImageBase(base)` moves the block to the base (BinaryLoader at
    the base itself leaves image base 0) and sets Program Information "PsyQ Version" = 4.7.0 (the exe's detected
    version). Full auto-analysis; psx_ldr "PsyQ Signatures" accepts raw programs by language (`canAnalyze`:
    language `PSX:LE:32:default`) and reads `psyq/470/`. Overlays are separate raw programs (no headless OverlayManager).
  - `--list`: prints `rock_NN 0xBASE` per code member (used by export.sh `--all`, roundtrip.sh, Makefile).
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
One `key: value` per line, hex lowercase 8 digits (rock_NN: `entry: none`, `image_base` = loadmap base,
`psyq_version` set by PrepareOverlay; batch mode `DumpProgramInfo.java <info-dir> <sha1-map>`):
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
- Overlays (rock_NN, T7.c1, 2026-10-01): `sig_functions: 0` for all 56 (no PsyQ library code matched); proof the
  analyzer ran per program: each export has `archive psyq470` and block `GTEMAC` (both made by PsxAnalyzer.added after
  signature application). Positive control: the exe through the same raw path (base 0x8000F800, PrepareOverlay)
  → `sig_functions: 484` (313 USER_DEFINED + 171 IMPORTED), PsyQ Signatures 151 s.

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
- Export: `make ghidra-export PYTHON=<py>` → `tools/mmx6/ghidra/export.sh --all` (`[PROG… | --all] [--project DIR]
  [--out F|DIR]`; `--all` = SLUS_013.95 + `import.sh --list`): one program → `analyzeHeadless ghidra mmx6 -process <PROG>
  -readOnly -noanalysis -postScript ExportAnnotations.java <out>`, log `.run/ghidra/export-<PROG>.log`; several → one JVM
  `-process` (every program) into `.run/ghidra/export/`, requested files moved to `config/ghidra/` (or `--out DIR`),
  log `.run/ghidra/export-batch.log`. Default out `config/ghidra/<PROG>.jsonl` (tracked). Never writes the project.
  Batch output = one-by-one output (rock_03 import+export batch vs single `cmp`-equal, 2026-10-01).
- Format: one JSON object per line, fixed key order, no whitespace, addresses `"0x%08x"`, rows sorted per kind; byte-stable
  (two exports `cmp`-equal). Kinds `k`: program (lang, cspec, image_base, format), block, archive, type (local
  types, namespace `/mmx6/`), func (name, ret, cc, flags, params, locals, comment), data (addr, type path, len; no values),
  comment (eol/pre/post/plate/repeat), bookmark, equate, label (non-default). No instruction words or bytes (G12).
- Round trip: `make ghidra-roundtrip PYTHON=<py>` → `tools/mmx6/ghidra/roundtrip.sh` (`[PROG…] [--jsonl F]`; default
  SLUS_013.95 + every loadmap code member): scratch project `.run/ghidra/rebuild/` recreated (opened via symlink
  `ghidra/rebuild`, since Ghidra rejects `.`-leading path elements), fresh `import.sh` (exe; members batched per base),
  one JVM `ImportAnnotations.java .run/ghidra/rebuild/in` (copies of the committed files, or `--jsonl F`; dir mode reads
  `<dir>/<program>.jsonl`), one batch export to `.run/ghidra/rebuild/out/`, `cmp` each. rc 0 + `ROUNDTRIP OK <k>
  programs`, else first differing line per program, rc 1. 57 programs (T7.c1, 2026-10-01): import 505 s
  (exe ~140 s + 56 members in 3 JVMs), apply 13 s, export 4 s.
  Logs `.run/ghidra/rebuild/{<exe>.import,members.import,apply,export}.log`.
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

## Load map and boundaries (T6, T8; added at PhaseEnd 1.2)
- `make loadmap PYTHON=<py>` → `tools/mmx6/loadmap.py --out config/loadmap.txt` (exe row + 59 member rows; static
  decode of the BinSeek call sites + `.run/redux/loads` captures); prints `N = <n>` and `CONTROLS <p>/<p> pass`;
  `--self-test`. Gate: rc 0 and `git diff --exit-code config/loadmap.txt`. Criteria: docs/memory-map.md.
- `make boundaries PYTHON=<py>` → `tools/mmx6/boundaries.py` writes `config/boundaries.txt` (jtbl/lib/optcand/fstart
  rows per load-map program; PsyQ objs from `$(GHIDRA_HOME)/Ghidra/Extensions/ghidra_psx_ldr/data/psyq`; needs the
  `config/ghidra/*.jsonl` exports); `--self-test`. Gate: rc 0 and `git diff --exit-code config/boundaries.txt`.

## Second boundary oracle (bound2, 1.5 T4)
- `tools/mmx6/bound2.py --all | --prog <p> | --self-test` (container, stdlib; needs extract + build + `corpus.py --all`).
- Inputs (B2 is built without asm/, config/*.yaml, splat output or corpus spans): retail bytes via
  `boundaries.programs()` (sha1-checked), text = `build/corpus/denominators.jsonl` [text_lo, text_hi),
  `config/ghidra/<p>.jsonl` funcs, `config/boundaries.txt` `jtbl` rows. Compared to `build/corpus/functions.jsonl`.
- Starts (basis ghidra > jal > head > post-ret): Ghidra func addrs in text; post-ret = first non-zero word at/after a+8
  of each `jr $ra` at a, unless inside a numeric-hi jtbl span; jal targets of jals inside the trimmed bodies of the
  other sets, target in the program's text or (overlay only) the exe text.
- head (overlays only, 1.5 T5): from the first `jr $ra` at/after text_lo scan back while `plausible(w)` (stop at
  text_lo), then skip zero words forward. `plausible(w)`: w = 0, or a valid R3000 word that is not a load/store with
  base $zero, a SPECIAL with rd $zero (except jr/jalr/syscall/break/mfhi/mthi/mflo/mtlo/mult/div), or an I-type ALU
  with rt $zero. Self-test: rock_17/43/45/46 head starts; in-memory ledger rows (ledgered; stale -> rc 1).
- Extent (C0021): end = last `jr $ra` in [start, next start or text_hi) + 8; none -> unended (start kept, no bytes).
- phantom = inventory vram not a B2 start; truncation = a B2 function [s, end) with a word covered by != 1 inventory
  function, or the inventory function at s ends before end.
- Classes (first match): `jtbl-label` (key word or problem run in/abutting a jtbl span; unknown-hi row = its lo
  word), `carve` (rock_17/43/45, starts declared in config/symbols.<p>.txt), `q1-text-end` (exe 0x8006D5D0..D4),
  `data-tail` (truncation whose uncovered words all lie in corpus data|pad spans), `ghidra-missed-start` (other
  phantoms), `unclassified`.
- Ledger `config/boundary_exceptions.txt` (optional; T5): `<prog> <vram> <phantom|truncation> <class> <evidence...>`,
  `#` comments; class not in the set minus unclassified -> rc 2; a matched disagreement is `ledgered`; a row matching
  nothing is stale (`BOUND2 STALE <row>`, rc 1).
- Outputs: `build/bound2/<p>.jsonl` {"prog","vram","end"|null,"basis"}; `build/bound2/disagreements.txt` (`## <class>`
  groups incl. `## ledgered`, lines `<kind> <prog> <vram> <detail>`); stdout `BOUND2 UNENDED <k>`,
  `BOUND2 CLASSES ...`, `BOUND2 phantoms=<p> truncations=<t> ledgered=<x> of <N> functions in <P> programs`.
  rc 0 iff p = t = 0 and no stale row; 1 otherwise; 2 bad input.
- `--self-test`: the 3 banked probes + func_80055A04 agree; in-memory split -> phantom, end cut by 8 -> truncation;
  ends `BOUND2 CONTROL OK`. Rung `th-bound2` (mk/tools-health.mk) runs the self-test only.
