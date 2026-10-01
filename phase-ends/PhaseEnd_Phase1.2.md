# PhaseEnd — Phase 1.2: The oracles and the load map (implements Gen 1.2)
Approved: 2026-10-01 | Closed: 2026-10-01 | Planner: claude-opus-5-5/medium | Tasks: 8 done, 0 superseded

## Milestone
Milestone: Ghidra database imported with psx_ldr and the era's signatures, the detected PsyQ version recorded (prior-art L2 → proven or refuted); text export → rebuild → re-export round trip byte-equal; PCSX-Redux scripted from the repo; load address of `SLUS_013.95` and of ≥1 `ROCK_X6.BIN` overlay per load base each cite three datapoints or a before/after diff in `docs/memory-map.md` (L3's three bases proven or refuted); the load-map tool's control rows pass; jump-table spans and forced boundaries recorded; N fixed and written in `docs/memory-map.md` — verified by: `make ghidra-import PYTHON=PY && grep -E '^psyq_version: ' .run/ghidra/info/SLUS_013.95.txt && grep -nE '^\| L2 .*\| (proven-at-gate|refuted) \|' docs/prior-art.md` rc 0; `make ghidra-roundtrip PYTHON=PY` rc 0 (prints `ROUNDTRIP OK <k> programs`, k = 1 + imported overlay programs); `make redux-smoke PYTHON=PY` rc 0; `make loadmap PYTHON=PY` rc 0 (prints `CONTROLS <p>/<p> pass` and `N = <n>`) and `git diff --exit-code config/loadmap.txt`; `grep -cE '^- L3 base 0x(801EA000|800E9860|800FA000): (proven|refuted)' docs/memory-map.md` = 3 and `grep -E '^N = [0-9]+$' docs/memory-map.md`; `make boundaries PYTHON=PY` rc 0 and `git diff --exit-code config/boundaries.txt`; `PY tools/audit_public.py` rc 0. Commands over 285 s run as `bash tools/run.sh --bg <name> -- <cmd>` then `bash tools/run.sh --wait <name> --max 280`.
Verified: make boundaries PYTHON=PY && git diff --exit-code config/boundaries.txt && boundaries.py --self-test && audit_public.py → VERIFY_RC=0, SELF-TEST PASS 7, audit OK 0 offenders / 399 paths (.run/logs/t8-verify.log)

## Tasks
- T1 — Ghidra import with psx_ldr and PsyQ detection | Done: `make ghidra-import PYTHON=PY` imports SLUS_013.95 (manifest sha1 checked) into `ghidra/mmx6` via psx_ldr with auto-analysis; info file shows PsyQ 4.7.0 and 811 signature functions; L2 proven-at-gate. | commit: - | tasks/T1.md | logs/T1.md
- T2 — GhidrAssistMCP served headless and wired | Done: `make ghidra-mcp-start` serves SLUS_013.95 via GhidrAssistMCP headless on localhost:8080 (SSE /sse → 200); `make ghidra-mcp-stop` saves cleanly, releases the lock, read-only reopen passes; `.mcp.json` wired. | commit: - | tasks/T2.md | logs/T2.md
- T3 — Annotation text export and rebuild round trip | Done: `make ghidra-export` writes `config/ghidra/SLUS_013.95.jsonl` (9943 rows) read-only from `ghidra/mmx6`; `make ghidra-roundtrip` rebuilds from extracted bytes + JSONL in a scratch project, re-exports, cmp equal, `ROUNDTRIP OK 1 programs`; two runs agree; negative control rc 1. | commit: - | tasks/T3.md | logs/T3.md
- T4 — PCSX-Redux bridge and the exe load proof | Done: `make redux-smoke` boots the cue headless with the BIOS, dumps RAM at first BinSeek hit (frame 1478), frame 4000 and second BinSeek hit (frame 7787), rc 0 in ~52 s; `exeproof.py` finds all 92827 function-body words equal at the 3 dumps; exe row proven in docs/memory-map.md. | commit: - | tasks/T4.md | logs/T4.md
- T5 — overlay load capture across the three bases | Done: `make redux-loads` boots headless, drives title → Game Start → opening stage by pad schedule, and logs every BinSeek load with before/after RAM dumps to `.run/redux/loads/*.jsonl`; `loadmap.py --summary` counts loads per base and caller. | commit: - | tasks/T5.md | logs/T5.md
- T6 — load-map tool, control rows, memory map and N | Done: `make loadmap` builds config/loadmap.txt (exe row + 59 member rows) from the exe bytes, ROCK members and captures; `CONTROLS 23/23 pass`; `N = 57`; all three L3 bases proven in docs/memory-map.md. | commit: - | tasks/T6.md | logs/T6.md
- T7 — overlay programs in Ghidra and L4 address check | Done: the 56 `code` members of config/loadmap.txt are imported by manifest path (sha1 checked) as `rock_NN` at their load-map bases with psx_ldr PsyQ 4.7.0 analysis; exports committed; `ROUNDTRIP OK 57 programs`; L4's 68 exe addresses checked against SLUS_013.95 function starts, counts in the memory-map ledger and prior-art L4. | commit: - | tasks/T7.md | logs/T7.md

## Decisions that still bind
- T1 — `sig_functions` = functions whose primary symbol source is USER_DEFINED or IMPORTED (psx_ldr's PsyQ Signatures naming); Ghidra's own analyzers use DEFAULT/ANALYSIS (docs/ops/oracles.md).
- T2 — the MCP server is stopped via GhidrAssistMCP's `completion_file=` option (the only path that saves); never pkill; import/export need it stopped (project lock).
- T3 — round trip = fresh import with auto-analysis + ImportAnnotations + re-export, cmp vs committed JSONL (no delta scheme; analysis proved deterministic).
- T4 — a function body for exeproof = [func addr, next func/data row) in CODE, trimmed to the last `jr ra` + delay slot (JSONL func rows carry no extent); denominator printed (1343 bodies, 92827 words).
- T4 — Redux runs need `-interpreter -debugger -portable` (see gotchas); `REDUX_CUE` is separate from `CUE` (container default).
- T5 — "read complete" = ready callback 0x800165A4 at pc 0x80016628 with remaining word 0x800E01A8 = 0, for every caller (one rule covers sync and async paths).
- T6 — N = 1 + members classed `code` (holds an `addiu sp,sp,-N` prologue and a `jr ra`, and has a static or runtime base); empty = size ≤ 4; data = rest. Today code 56, data 1 (member 13), empty 2 (41, 42), N = 57.
- T6 — runtime proof of a member's base = before-dump differs and after-dump[:size] == member bytes; static base from the call-site table otherwise (`static:<caller>`).
- T7 — overlay program = raw import at base 0 then image base set to the loadmap base by PrepareOverlay.java; base comes only from config/loadmap.txt (import refuses data/empty members and a differing `--base`).
- T8 — jump-table extent = the dispatch's `sltiu` bound (fallback: consecutive code-pointer words); Ghidra's `Address table[n]` count is advisory (`ghidra_hi=` note), it overruns into the next table.
- T8 — lib rows only where the PsyQ signature verifies at the address and the name is unique; twin spans (LIBCD/LIBDS) and multi-candidate plates counted ambiguous, not emitted.
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

## Rules proposed
- (none)

## Cookbook entries added
C0014 | Ghidra headless: preScript setAnalysisOption does not disable a psx_ldr analyzer; use -noanalysis as control | ghidra,psx_ldr,headless,analysis,negative-control | 2026-10-01 | 1.2/T1 | mmx6 T1
C0015 | GhidrAssistMCP headless: stop via completion_file so the project saves; killing the JVM skips the save | ghidra,mcp,ghidrassistmcp,headless,save | 2026-10-01 | 1.2/T2 | mmx6 T2
C0016 | Ghidra headless refuses project paths with a dot-leading element; reach .run/ scratch via a symlink | ghidra,headless,project,path | 2026-10-01 | 1.2/T3 | mmx6 T3
C0017 | analyzeHeadless exits 0 when a script prints an error and returns; grep the script's error marker | ghidra,headless,exit-code,wrapper | 2026-10-01 | 1.2/T3 | mmx6 T3
C0018 | PCSX-Redux on macOS arm64 crashes under the dynarec headless; run with -interpreter | pcsx-redux,macos,arm64,headless,interpreter | 2026-10-01 | 1.2/T4 | mmx6 T4
C0019 | PCSX-Redux Lua Exec breakpoints never fire without -debugger | pcsx-redux,lua,breakpoint,debugger | 2026-10-01 | 1.2/T4 | mmx6 T4
C0020 | PCSX-Redux -portable keeps config in the run dir; spu.Speed = 0 runs unthrottled | pcsx-redux,portable,speed,headless | 2026-10-01 | 1.2/T4 | mmx6 T4
C0021 | Ghidra function starts without extents over-include data tails; trim to last jr ra + delay slot | ghidra,export,function-extent,mips,compare | 2026-10-01 | 1.2/T4 | mmx6 T4
C0022 | PCSX-Redux Lua pad input: SIO0.slots[1].pads[1].setOverride/clearOverride | pcsx-redux,lua,pad,input | 2026-10-01 | 1.2/T5 | mmx6 T5
C0023 | macOS host has no MIPS objdump; disassemble in the build container or decode words in the tool | macos,mips,objdump,disassembly,container | 2026-10-01 | 1.2/T6 | mmx6 T6
C0024 | Ghidra BinaryLoader headless -loader-baseAddr can leave image_base 0; import at 0 and setImageBase in a preScript | ghidra,binaryloader,image-base,headless,overlay | 2026-10-01 | 1.2/T7 | mmx6 T7
C0025 | Ghidra multi-import JVM: per-program analysis summary missing from log; check per-program artifacts | ghidra,headless,batch,log,verification | 2026-10-01 | 1.2/T7 | mmx6 T7
C0026 | Ghidra may emit switchdataD_ labels every 8 B inside one switch table; merge labels within a bounded table | ghidra,switch,jump-table,labels,boundaries | 2026-10-01 | 1.2/T8 | mmx6 T8

## Research
R1.2-001 | scriptable Ghidra + PCSX-Redux oracles on macOS arm64 | PSX oracles: ghidra_psx_ldr, GhidrAssistMCP, PCSX-Redux headless | ghidra, psx, pcsx-redux, mcp, headless | retriever-web | 2026-10-01 | 41 lines

## Audit
- seed: median 14k, max 14k, n=9 (phase 1.2)
- previous phase 1.1: median 14k, growth 0.7%
- CLAUDE.md: 1242 bytes (unchanged)
- .claude/skills/ci-wait-after-push/SKILL.md: 799 bytes (unchanged)
- .claude/skills/docker-vm-no-privileged/SKILL.md: 774 bytes (unchanged)
- .claude/skills/project-architect/SKILL.md: 13448 bytes (unchanged)
- .claude-state/memory/MEMORY.md: 214 bytes (unchanged)
- HOW_WE_WORK.md: 6905 bytes
- cookbook/INDEX.md: 4751 bytes
- rules/INDEX.md: 10300 bytes
### Carry audit — phase 1.2 (2026-10-01T05:44:07Z → open UTC, 1 sessions, 609 requests)

| file (read) | chars | n |
|---|---|---|
| ImportAnnotations.java | 22.5k | 1 |
| ExportAnnotations.java | 18.3k | 1 |
| strings.txt | 14.9k | 4 |
| oracles.md | 8.7k | 2 |
| exeproof.py | 7.0k | 2 |
| loadmap.py | 6.2k | 1 |
| formats.md | 5.8k | 2 |
| loadmap.txt | 4.8k | 1 |
| boundaries.py | 4.7k | 2 |
| prior-art.md | 3.5k | 1 |
| file (write) | chars | n |
|---|---|---|
| boundaries.py | 25.3k | 5 |
| loadmap.py | 16.7k | 2 |
| import.sh | 8.6k | 3 |
| lib.lua | 5.3k | 5 |
| DumpProgramInfo.java | 5.3k | 6 |
| cookbook.sh | 5.2k | 1 |
| exeproof.py | 5.1k | 2 |
| oracles.md | 4.9k | 2 |
| result kind | chars | n |
|---|---|---|
| bash other | 369.1k | 234 |
| tools/card.py | 147.1k | 12 |
| Read | 117.6k | 38 |
| run.sh | 92.1k | 94 |
| tools/plan_edit.py | 65.1k | 20 |
| Agent | 20.1k | 19 |
| tools/status.py | 15.0k | 11 |
| Grep | 11.2k | 7 |
| tools/task_log.py | 9.6k | 8 |
| tools/outline.py | 9.2k | 2 |
- whole reads over 20.0k: 1
- seed floor: retriever-code 5,222 (n 1, prev 5,198) · retriever-digest 5,089 (n 1, prev 5,488) · retriever-web 3,887 (n 1, prev 3,607)
- outline credit: 2 outlines · 2 followed by a ranged read · 8.5k chars credited
- warm pings: 26 pings over 8 runs, 9 warmed waits over the TTL, rewrites across warmed waits 0, waits past the cap 0, pings cost $0.2397 vs rewrites replaced $1.9803, cheaper than one rewrite: yes
- toasts by cause (waiting): question 0, review 0, replan 0, permission 0, input 0, discussion 0, crash 0, idle 0, stop 0, subagent-stop 0, model 0, other 0
- router turns by cause: loop 14, relay 26, re-arm 5, other 0, relay cost $0.6385
- retriever re-asks: 0 of 1 retriever briefs repeat a lookup of the same run
- router: pa-session bd6dc39e · requests 98 · ctx at end 76.8k · growth T1 +1.5k, T2 +547, T3 +2.0k, T4 +3.9k, T5 +1.4k, T6 +4.1k, T7 +6.7k, T8 +1.4k · top: tools/status.py 15.0k/11, Agent 9.5k/9, other 6.6k/34, tools/plan_edit.py 2.8k/9
- noise: 29 lines 2.3k chars — usage: : 23 lines/2.0k, No such file or directory: 6 lines/302
- price: read $0.20/Mtok · 1h write $7.26/Mtok · output $18.14/Mtok (phase model mix)
- median requests after a read: 6
- carry/request: 1462 chars, 609 requests (prev 2509 chars, 154 requests, growth -41.8%)
- flag: 1 whole-plan reads by expert-opus55
- flag: 12 tool-source reads by coder-opus55, expert-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/exeproof.py  4.7k chars  expert-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/ghidra/import.sh  3.2k chars  expert-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/ghidra/roundtrip.sh  3.4k chars  expert-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/redux/lib.lua  3.0k chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/redux/smoke.lua  2.6k chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/redux/run.sh  3.0k chars  coder-opus55
  /Users/Shared/kits/decomp-architect/corpus/tools/P2/ghidra_scripts/ExportAnnotations.java  18.3k chars  coder-opus55
  /Users/Shared/kits/decomp-architect/corpus/tools/P2/ghidra_scripts/ImportAnnotations.java  22.5k chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/loadmap.py  6.2k chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/exeproof.py  2.3k chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/boundaries.py  544 chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/boundaries.py  4.1k chars  coder-opus55
- flag: 1 whole reads over 20.0k by coder-opus55
  file: /Users/Shared/kits/decomp-architect/corpus/tools/P2/ghidra_scripts/ImportAnnotations.java  role: coder-opus55  chars: 21.1k

## Agent runs
- T1 | expert-opus55 | expert | claude-opus-5-5 | medium | ctx 59k | $0.536 | saved - | completed | parent 8f380e71
- T1 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 89k | $1.088 | saved $1.01 | completed | parent ac7f1a77
- T2 | expert-opus55 | expert | claude-opus-5-5 | medium | ctx 52k | $0.326 | saved - | completed | parent 8f380e71
- T2 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 80k | $0.703 | saved - | completed | parent a9c670df
- T2 | retriever-web | retriever | claude-sonnet-5-5 | medium | ctx 11k | $0.038 | saved - | completed | parent a9c670df
- T2 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 53k | $0.477 | saved - | completed | parent a9c670df
- T3 | expert-opus55 | expert | claude-opus-5-5 | medium | ctx 46k | $0.373 | saved - | completed | parent 8f380e71
- T3 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 72k | $0.835 | saved - | completed | parent a9882fbd
- T3 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 34k | $0.230 | saved - | completed | parent a9882fbd
- T3 | critic | critic | claude-opus-5-5 | medium | ctx 26k | $0.188 | saved - | completed | parent 8f380e71
- T3.1 | expert-opus55 | expert | claude-opus-5-5 | medium | ctx 39k | $0.215 | saved - | completed | parent 8f380e71
- T3.1 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 31k | $0.220 | saved - | completed | parent a2441483
- T4 | expert-opus55 | expert | claude-opus-5-5 | medium | ctx 130k | $1.956 | saved - | completed | parent 8f380e71
- T4 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 76k | $1.006 | saved $0.30 | completed | parent ae39b750
- T5 | expert-opus55 | expert | claude-opus-5-5 | medium | ctx 60k | $0.773 | saved - | completed | parent 8f380e71
- T5 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 53k | $0.526 | saved - | completed | parent a201d9ed
- T5 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 89k | $1.041 | saved - | completed | parent a201d9ed
- T6 | expert-opus55 | expert | claude-opus-5-5 | medium | ctx 43k | $0.239 | saved - | completed | parent 8f380e71
- T6 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 38k | $0.320 | saved - | completed | parent aa2d6cf2
- T7 | expert-opus55 | expert | claude-opus-5-5 | medium | ctx 51k | $0.372 | saved - | completed | parent 8f380e71
- T7 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 91k | $1.176 | saved - | completed | parent af7709ba
- T7 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 54k | $0.416 | saved - | completed | parent af7709ba
- PHASE-END | expert-opus55 | expert | claude-opus-5-5 | medium | ctx 48k | $0.521 | saved - | completed | parent 8f380e71
- T1 | expert-opus55 | expert | claude-opus-5-5 | medium | ctx 45k | $0.335 | saved $0.49 | completed | parent bd6dc39e
- T1 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 60k | $0.650 | saved $2.53 | completed | parent a8ddc76f
- T2 | expert-opus55 | expert | claude-opus-5-5 | medium | ctx 41k | $0.229 | saved - | completed | parent bd6dc39e
- T2 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 39k | $0.322 | saved - | completed | parent ae25ee99
- T3 | expert-opus55 | expert | claude-opus-5-5 | medium | ctx 40k | $0.293 | saved - | completed | parent bd6dc39e
- T3 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 68k | $0.675 | saved - | completed | parent ada8f1bd
- T4 | expert-opus55 | expert | claude-opus-5-5 | medium | ctx 52k | $0.377 | saved - | completed | parent bd6dc39e
- T4 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 90k | $1.279 | saved - | completed | parent a01edbc3
- T5 | expert-opus55 | expert | claude-opus-5-5 | medium | ctx 36k | $0.198 | saved - | completed | parent bd6dc39e
- T5 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 69k | $0.957 | saved - | completed | parent a5935859
- T6 | expert-opus55 | expert | claude-opus-5-5 | medium | ctx 53k | $0.350 | saved - | completed | parent bd6dc39e
- T6 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 67k | $0.690 | saved - | completed | parent a8e00dc2
- T6 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 69k | $0.766 | saved - | completed | parent a8e00dc2
- T7 | expert-opus55 | expert | claude-opus-5-5 | medium | ctx 65k | $0.637 | saved - | completed | parent bd6dc39e
- T7 | retriever-digest | retriever | claude-sonnet-5-5 | medium | ctx 22k | $0.092 | saved - | completed | parent a6d5be5e
- T7 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 95k | $1.148 | saved $0.45 | completed | parent a6d5be5e
- … 3 more: PY ~/.claude/pa3/pa_ledger.py report

## Discussions
- (none)

## Deferred
- from T8: segmentation (1.3) splits at jtbl spans and lib spans in config/boundaries.txt; overlay VM_VIB rows are weak evidence. (unconsumed)

## Changes
- 2026-10-01 router: T1 next -> done
- 2026-10-01 router: T2 next -> done
- 2026-10-01 router: T3 next -> done
- 2026-10-01 router: T4 next -> done
- 2026-10-01 router: T5 next -> done
- 2026-10-01 router: T6 next -> done
- 2026-10-01 router: T7 next -> done
- 2026-10-01 router: T8 next -> done

## Plain-English Recap
This phase set up the two independent "oracles" a matching decompilation checks itself against: Ghidra, a static disassembler that reads the game's code from the disc files, and PCSX-Redux, a PlayStation emulator we drive with scripts to watch the game while it runs. Ghidra now imports the main program and all 56 code overlays (code files the game loads into memory on demand) with the PsyQ 4.7 library signatures, and its annotations survive a text export, a fresh rebuild and a re-export unchanged. The emulator boots the game unattended, plays from the title screen into the first stage, and records every overlay load with memory snapshots before and after. From that we built the load map: the memory address of the main program and of every overlay, each proven at runtime or from the loader's own tables, with the three load addresses an earlier report guessed all confirmed, and the number of programs to decompile fixed at N = 57. Finally each program got its forced boundaries (jump tables, library objects, function starts), which the next phase needs to split the binary into source files.
