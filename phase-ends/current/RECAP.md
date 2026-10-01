MILESTONE: green

# PhaseEnd 1.2 — The oracles and the load map

## Recap
This phase set up the two independent "oracles" a matching decompilation checks itself against: Ghidra, a static disassembler that reads the game's code from the disc files, and PCSX-Redux, a PlayStation emulator we drive with scripts to watch the game while it runs. Ghidra now imports the main program and all 56 code overlays (code files the game loads into memory on demand) with the PsyQ 4.7 library signatures, and its annotations survive a text export, a fresh rebuild and a re-export unchanged. The emulator boots the game unattended, plays from the title screen into the first stage, and records every overlay load with memory snapshots before and after. From that we built the load map: the memory address of the main program and of every overlay, each proven at runtime or from the loader's own tables, with the three load addresses an earlier report guessed all confirmed, and the number of programs to decompile fixed at N = 57. Finally each program got its forced boundaries (jump tables, library objects, function starts), which the next phase needs to split the binary into source files.

## Milestone verification
`PY tools/phaseend_index.py verify --verbose` (.run/logs/pe-verify.log; per clause .run/logs/verify1..7.log): 5/7 GREEN as scored.
- 1 import + `psyq_version` + L2 row: GREEN.
- 2 `make ghidra-roundtrip`: scored RED only because the verifier searched for the literal placeholder `ROUNDTRIP OK <k> programs`; output `ROUNDTRIP OK 57 programs` (k = 1 + 56 imported overlays). Re-run with rc captured: `RC=0` (.run/logs/pe-roundtrip.log). Satisfied.
- 3 `make redux-smoke`: GREEN.
- 4 `make loadmap` + `git diff --exit-code config/loadmap.txt`: scored RED for the literal `CONTROLS <p>/<p> pass`; output `CONTROLS 23/23 pass`, `N = 57`. Re-run rc 0, no diff (.run/logs/pe-loadmap.log). Satisfied.
- 5 L3 base lines = 3 and `N = 57` line: GREEN.
- 6 `make boundaries` + no diff: GREEN.
- 7 `PY tools/audit_public.py` rc 0: GREEN.

## Decisions that still bind
All are contracts already written in the product docs by the task that made them:
- `sig_functions` = USER_DEFINED/IMPORTED symbol source (T1) — docs/ops/oracles.md `## sig_functions method`.
- MCP server stops only via GhidrAssistMCP `completion_file=`; import/export need it stopped (T2) — docs/ops/oracles.md `## MCP server`.
- Round trip = fresh import + ImportAnnotations + re-export, cmp vs committed JSONL (T3) — docs/ops/oracles.md.
- Exe body extent = [start, next row) trimmed to last `jr ra` + delay slot (T4) — docs/memory-map.md.
- Redux runs use `-interpreter -debugger -portable`; `REDUX_CUE` separate from `CUE` (T4) — docs/ops/oracles.md `## Runtime`.
- Read complete = callback 0x800165A4 at pc 0x80016628 with remaining 0x800E01A8 = 0 (T5) — docs/ops/oracles.md, docs/memory-map.md.
- N = 1 + `code` members; runtime base proof = before differs and after[:size] == member bytes, else static call-site base (T6) — docs/memory-map.md.
- Overlay program base comes only from config/loadmap.txt; raw import at 0 then setImageBase (T7) — docs/ops/oracles.md.
- Jump-table extent from the dispatch `sltiu`; lib rows only for verified unique signatures (T8) — docs/memory-map.md `## Forced boundaries (T8)`.
- No new project rules proposed.

## Deviations
- H7: T6 (`make loadmap`) and T8 (`make boundaries`) added build targets without touching HOW_WE_WORK.md or docs/ops/. Fixed at phase end: docs/ops/oracles.md `## Load map and boundaries`.

## Promoted
- Cookbook C0014–C0026 (13 `generalizable:` gotchas, T1–T8). No `workflow:` gotchas.

## Harness gotchas for the next plan
- harness: `phaseend_index.py verify` matches `<k>`-style placeholders in "prints `…`" literally, so a clause with a placeholder always scores RED; planners should write concrete patterns (regex) or the verifier should treat `<x>` as a wildcard.
- harness: `plan_edit.py show --section milestone` refused (no `## milestone` section; use `grep -n '^Milestone:'`); reported T5–T8 and again here.
- harness: hooks deny the expert reading kit reference sources and tools/mmx6 sources (T1, T5, T8).
- harness: R1.2-001's "missing -dofile file → exit 1" is wrong; Redux hangs (T4).
- harness: a stale PCSX-Redux process (pid 81707, parent 1, ~9.7 h old at phase end) was left running by an earlier task; not killed here.

## Next task needs
- Phase 1.3 (build and byte gate) inherits config/loadmap.txt (N = 57) and config/boundaries.txt as the split inputs.
