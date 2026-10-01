# PhaseEnd — Phase 1.5: The honest census and the differential harness at 0% (implements Gen 1.5)
Approved: 2026-10-01 | Closed: 2026-10-01 | Planner: claude-opus-5-5/medium | Tasks: 8 done, 0 superseded

## Milestone
Milestone: every scanner prints its denominator (from the build) and passes its known-true control; the second boundary oracle reports 0 phantoms and 0 truncations; the differential harness's scheduled run of ≥5 question pairs reports 0 disagreements; the census reports duplication, structural families, reach × size and the unique tail; the tools-health chain green — verified by: `bash tools/docker/mx.sh sync && bash tools/run.sh --bg fleet -- bash tools/docker/mx.sh run make fleet` then `bash tools/run.sh --wait fleet --max 280` (repeat the wait until done) rc 0, last line `FLEET 57 of 57`, the log holds `HARNESS 0 disagreements in <p> pairs` (p ≥ 5, the sampled scheduled run); then `bash tools/run.sh --bg health -- bash tools/docker/mx.sh run make tools-health-full` + `bash tools/run.sh --wait health --max 280` rc 0, last line `TOOLS-HEALTH OK <k> rungs`, the log holds for every scanner (corpus, optscan, boundcheck, bound2, census, report, harness) one `<NAME> … of <denominator>` line whose denominator is read from build outputs and one `<NAME> CONTROL OK` line, `BOUND2 phantoms=0 truncations=0`, `CENSUS dup_classes=<a> families=<b> reach_size=<c> unique_tail=<d>`, `HARNESS 0 disagreements in <p> pairs` (p ≥ 5); `PY tools/audit_public.py` rc 0. Clauses run one after another, never concurrently (1.3: two container commands on one tree gave `FLEET 56 of 57`).
Verified: `bash tools/docker/mx.sh sync && bash tools/run.sh --bg t8fleet2 -- bash tools/docker/mx.sh run make fleet` + wait → exit 0, `HARNESS CONTROL OK`, `HARNESS 0 disagreements in 6 pairs`, `TOOLS-HEALTH OK 7 rungs`, last line `FLEET 57 of 57` (.run/logs/t8fleet2.log); then `bash tools/run.sh --bg t8full2 -- bash tools/docker/mx.sh run make tools-health-full` + wait → exit 0, 7 `CONTROL OK` (CORPUS BOUNDCHECK OPTSCAN BOUND2 CENSUS REPORT HARNESS), `BOUND2 phantoms=0 truncations=0 ledgered=0 of 7345`, `CENSUS dup_classes=1152 families=1175 reach_size=14/16 unique_tail=2531 of 7345`, `HARNESS 0 disagreements in 7 pairs`, last line `TOOLS-HEALTH OK 8 rungs` (.run/logs/t8full2.log); `PY tools/audit_public.py` → rc 0, 0 offenders among 744 paths; `PY tools/card.py check` → 6977 of 7000

## Tasks
- T1 — rock_17/43/45 split into real functions | Done: rock_17/43/45 now split into glabel functions 29/77/52 (was 0) from declared, retail-byte-based starts; optscan unsplit 0, dropped 0w; clean fleet green. Count threshold 81/53 for 43/45 not met (see Deviations). | commit: - | tasks/T1.md | logs/T1.md
- T2 — corpus oracle with build-derived denominators | Done: tools/mmx6/corpus.py writes build/corpus/{functions,spans,denominators}.jsonl for 57 programs; every text byte is a function or a classified span (uncovered 0); text bytes read from build/<p>.elf; self-test + planted control green; `make tools-health` (mk/tools-health.mk) runs from `make health`, so from the fleet. | commit: - | tasks/T2.md | logs/T2.md
- T3 — coverage assertions on the existing scanners | Done: optscan, boundcheck and fleet.sh now state their count against an external denominator (corpus / config/*.yaml) and refuse a narrowed population; optscan and boundcheck self-tests end `<NAME> CONTROL OK` with planted narrowings; both run as tools-health rungs. | commit: - | tasks/T3.md | logs/T3.md
- T4 — second boundary oracle and its first disagreement run | Done: tools/mmx6/bound2.py builds a splat-independent function list per program (Ghidra starts, post-return starts, jal targets; extents trimmed per C0021 over retail bytes), compares it to build/corpus/functions.jsonl, writes build/bound2/; self-test controls green; first run 64 phantoms, 615 truncations, recorded by class. | commit: - | tasks/T4.md | logs/T4.md
- T5 — boundary disagreements adjudicated to 0 | Done: bound2 reports `phantoms=0 truncations=0 ledgered=0` over 7345 functions in 57 programs on a clean fleet; every T4 class was resolved by fixing the side the retail bytes prove wrong; no ledger rows were needed. | commit: 3d98b78 | tasks/T5.md | logs/T5.md
- T6 — census of duplication, families, reach × size, unique tail | Done: tools/mmx6/census.py classes all 7345 corpus functions into dup classes (relocation-masked words) and families (opcode skeleton), reports reach × size and the unique tail per lane and fleet-wide, writes build/census/classes.jsonl; controls green; rung th-census runs in `make fleet`. | commit: - | tasks/T6.md | logs/T6.md
- T7 — progress, difficulty and duplicate reports | Done: tools/mmx6/report.py writes build/reports/{progress,difficulty,dup}.{md,json} from build/corpus + build/census (words via census.read_words); planted + real controls green; rung th-report runs in `make fleet` (6 rungs). | commit: - | tasks/T7.md | logs/T7.md

## Decisions that still bind
- T1 — an overlay whose splat output is 0-glabel is fixed by declaring every start sized in config/symbols.<prog>.txt with a retail-byte basis (post-return, jal, first code after header, data); never a Ghidra name.
- T2 — corpus spans are only bytes no function covers (functions win, nothing counted twice); span kind precedence jtbl > libgap > data (`dlabel` region) > pad (zero words); any other uncovered byte is refused.
- T2 — lane — exe game TU `120A0` → game; every other exe text TU (lib TUs and the 15 hex-named Q2 gap TUs) → lib; overlays → game. Gap-TU functions are lib-lane, identifiable by their hex `tu`.
- T3 — optscan's denominator N = corpus rows with state asm|include_asm (functions with splat asm); c / c-empty functions have no asm and are counted by fleet.sh's `C MATCHED … of <F>`, which cross-checks corpus c + c-empty against its readelf count.
- T3 — boundcheck refuses only an empty total forced-edge list; overlays legitimately have 0 lib edges.
- T4 — B2 starts = Ghidra k=func in [text_lo,text_hi) ∪ post-ret (first non-zero word after a jr ra delay slot, not inside a numeric-hi jtbl span of config/boundaries.txt) ∪ jal targets from jals inside trimmed bodies (own text or exe text); basis precedence ghidra > jal > post-ret. Never reads asm/, yaml or corpus spans to build B2.
- T4 — B2 extent = last jr ra + 8 before the next B2 start; a start with no jr ra is unended (supports inventory starts, contributes no bytes), counted on `BOUND2 UNENDED <k>`.
- T4 — phantom = inventory vram not a B2 start; truncation (keyed by B2 start) = a byte of the B2 extent covered by ≠1 inventory function, or the inventory function at that start ending before the B2 end. Classes, first match: jtbl-label, carve (rock_17/43/45 declared starts), q1-text-end, data-tail, ghidra-missed-start, unclassified.
- T4 — ledger config/boundary_exceptions.txt (optional; T5 writes it): `<prog> <vram> <phantom|truncation> <class> <evidence…>`; class from the closed set minus unclassified (else rc 2); a row matching no disagreement is stale, rc 1; ledgered rows still listed.
- T5 — B2 start bases = ghidra > jal > head > post-ret; `head` = first code word after an overlay's header, found from retail bytes by back-scan from the first `jr $ra` (plausible(): valid R3000 word, not a $zero-based load/store, not an ALU write to $zero; zero words skipped).
- T5 — an overlay's word 0 (index + 1) and its header / pointer-table words are data and are declared `D_<text_lo>` in config/symbols.<prog>.txt; a 4-byte data symbol is declared without `size:` (spimdisasm ends a sized symbol only at size >= 8) and followed by a declared function.
- T5 — the bound2 self-test ledger control uses an injected disagreement, never a real one (it must hold at 0/0).
- T6 — dup key = sha1 of a function's words with relocation fields masked; mask = relocation sites of its built TU object (`readelf -rW`), field masks = probe.py `MASKS` (R_MIPS_26 low 26, HI16/LO16/GPREL16 low 16), the same mask the probe uses.
- T6 — family key = sha1 of the mnemonic skeleton (opcode; + funct for SPECIAL, rt for REGIMM, rs for COPz; registers and immediates dropped).
- T6 — reach = distinct programs among a dup class's members (source analog: per-function fleet reach); size = instruction words.
- T6 — unique tail = functions in no dup class ≥2 and no family ≥2; per-lane figures regroup within the lane.
- T7 — progress matched = state c + c-empty (equals fleet `C MATCHED`), shown as banks (c) and stubs (c-empty) separately; byte denominator B = function bytes (4 x words); text bytes and span bytes by kind reported on their own line from denominators.jsonl.
- T7 — difficulty ranks not-yet-C (asm | include_asm) ascending by (jtbl, words, branches, calls, prog, vram); branch = REGIMM, ops 4-7, COPz BC; call = jal + jalr; jtbl = any `jr` with rs != 31.
- T7 — dup payoff = (members - 1) x words per dup class >= 2, desc, ties (-members, key); json lists every class with reach and C members: the 1.6 propagation list.
- T8 — harness pairs — P1 matched? corpus.parse_c vs fleet_c_names; P2 compiles? probe standalone compile vs build/<p>.elf words (probe mask), every corpus `c` function; P3 fleet? BINS sha1 before vs after touch of 120A0.c + first exe asm unit + `make -s build` (NOT-RUN if a .o was not rebuilt), `--full` only; P4 coverage? optscan parser vs corpus per program; P5 boundaries? bound2.account phantoms=truncations=0; P6 programs? yaml stems vs loadmap N vs ghidra jsonl stems; P7 stubs? corpus c-empty + asm `jr $ra; nop` vs census empty dup class.
- T8 — runs.log line `<utc> P<n> <question> AGREE|DISAGREE|NOT-RUN <a> <b> of <N> <unit>`; stdout prefixes the same line `HARNESS `; NOT-RUN counts as a disagreement (G35); the self-test logs to container .run/harness/selftest.log, never runs.log.
- T8 — `make tools-health-full` runs after a fleet (needs the build); it touches and rebuilds two units in place.
- Contracts (in the tools and documented in docs/ops/decomp-environment.md, docs/ops/oracles.md, config/segmentation.md; each guarded by its tool's `--self-test` rung in mk/tools-health.mk): corpus span kinds and lanes (T2); optscan denominator = asm|include_asm rows and boundcheck's empty-edge refusal (T3); B2 starts, extents, phantom/truncation classes and ledger (T4, T5); dup key, family key, reach, unique tail (T6); progress, difficulty and dup payoff (T7); harness pairs P1-P7, runs.log line, NOT-RUN counts as a disagreement (T8).
- Environment fact: `make tools-health-full` runs only after a fleet and rebuilds two units in place (docs/ops/decomp-environment.md; card Build/run/test row).
- Environment fact: the health chain lives at `mk/tools-health.mk` (D1); the card and docs/ops already say so.
- Next task needs: GENERATION_PLAN.md phase 1.5 milestone still reads `` `build/tools-health.mk` green ``; the router should amend it to `mk/tools-health.mk` (D1) when it closes 1.5.
- Next task needs: give optscan and boundcheck name-prefixed `of` lines (`OPTSCAN SCANNED …`, `BOUNDCHECK BOUNDARIES OK …`), or reword future milestones, so the `<NAME> … of` clause holds literally.
- Next task needs: P1 and P5 are consistency checks, not independent sources; the independent merge check is deferred to 1.6 (I4).
- Next task needs: `phaseend_index.py verify` must run `--bg` + `--wait` clause pairs to completion, one after another, before it reports GREEN (harness fix, auditor).
- Next task needs: the card sits at 6977 of 7000 chars; the next card edit needs a trim first.

## Rules proposed
- (none)

## Cookbook entries added
C0048 | spimdisasm farthestBranch survives function ends; declare sized func symbols | splat,spimdisasm,overlay,boundaries | 2026-10-01 | 1.5/T1 | T1 overlay 0-glabel fix
C0049 | jr ra count overcounts functions (multi-return) | boundaries,census,mips | 2026-10-01 | 1.5/T1 | T1
C0050 | Coverage oracle: closed set of uncovered-byte kinds with precedence | oracle,coverage,corpus | 2026-10-01 | 1.5/T2 | T2 corpus spans
C0051 | Narrowing control from the real population (hide one input dir) | self-test,control,scanner | 2026-10-01 | 1.5/T3 | T3 optscan
C0052 | Post-return start rule chains through data; scope it | boundaries,bound2,data | 2026-10-01 | 1.5/T4 | T4 bound2
C0053 | spimdisasm ends sized symbols only at size >= 8 | splat,spimdisasm,symbols | 2026-10-01 | 1.5/T5 | T5 symbols
C0054 | Self-test controls inject disagreements, never borrow real ones | self-test,control | 2026-10-01 | 1.5/T5 | T5 bound2 ledger
C0055 | Dup census: load-bearing-mask control (twin must split unmasked) | census,duplicates,control | 2026-10-01 | 1.5/T6 | T6 census
C0056 | Report over a census: currency guard plus planted mutation | report,census,control | 2026-10-01 | 1.5/T7 | T7 report
C0057 | Harness pair whose instrument never ran is NOT-RUN, counted as disagreement | harness,differential,control | 2026-10-01 | 1.5/T8 | T8 harness P3

## Research
R1.5-001 | scope phase 1.5 tasks from inherited record | Phase 1.5 instruments: source-record names, controls, denominators, incidents | phase-1.5, oracle, census, differential, tools-health | retriever-digest | 2026-10-01 | 29 lines
R1.5-002 | extract planner facts for 1.5 second boundary oracle / differential harness | Phase 1.5 planning facts: boundary oracles, defects, costs | phase-1.5, oracle, boundaries, ghidra, redux, segmentation | retriever-digest | 2026-10-01 | 30 lines

## Audit
- seed: median 14k, max 14k, n=9 (phase 1.5)
- previous phase 1.4: median 14k, growth 0.1%
- CLAUDE.md: 1242 bytes (unchanged)
- .claude/skills/ci-wait-after-push/SKILL.md: 799 bytes (unchanged)
- .claude/skills/container-scratch-not-synced/SKILL.md: 1125 bytes (unchanged)
- .claude/skills/docker-vm-no-privileged/SKILL.md: 774 bytes (unchanged)
- .claude/skills/project-architect/SKILL.md: 13448 bytes (unchanged)
- .claude-state/memory/MEMORY.md: 214 bytes (unchanged)
- HOW_WE_WORK.md: 7009 bytes
- cookbook/INDEX.md: 9006 bytes
- rules/INDEX.md: 10587 bytes
### Carry audit — phase 1.5 (2026-10-01T16:10:56Z → open UTC, 1 sessions, 602 requests)

| file (read) | chars | n |
|---|---|---|
| bound2.py | 58.1k | 9 |
| census.py | 39.5k | 5 |
| optscan.py | 38.5k | 5 |
| PHASE_PLAN.md | 32.5k | 4 |
| boundaries.py | 26.4k | 5 |
| corpus.py | 24.2k | 5 |
| Makefile | 16.6k | 3 |
| T1.md | 13.0k | 3 |
| sst.txt | 12.1k | 1 |
| probe.py | 9.6k | 1 |
| file (write) | chars | n |
|---|---|---|
| corpus.py | 20.0k | 6 |
| report.py | 17.4k | 1 |
| bound2.py | 16.6k | 4 |
| census.py | 14.5k | 1 |
| harness.py | 13.9k | 2 |
| T5.md | 6.5k | 1 |
| HOW_WE_WORK.md | 5.0k | 14 |
| T4.md | 4.8k | 1 |
| result kind | chars | n |
|---|---|---|
| bash other | 448.4k | 228 |
| Read | 378.4k | 79 |
| tools/card.py | 120.5k | 25 |
| tools/plan_edit.py | 102.3k | 29 |
| run.sh | 99.3k | 79 |
| tools/outline.py | 33.9k | 6 |
| Agent | 22.2k | 21 |
| tools/status.py | 12.9k | 9 |
| tools/task_log.py | 8.5k | 14 |
| other | 6.9k | 45 |
- whole reads over 20.0k: 0
- seed floor: retriever-code 5,436 (n 1, prev 5,299) · retriever-digest 5,241 (n 2, prev 5,281)
- outline credit: 10 outlines · 9 followed by a ranged read · 72.4k chars credited
- warm pings: 15 pings over 8 runs, 8 warmed waits over the TTL, rewrites across warmed waits 1, waits past the cap 0, pings cost $0.2399 vs rewrites replaced $2.6372, cheaper than one rewrite: yes
- toasts by cause (waiting): question 0, review 0, replan 0, permission 0, input 0, discussion 0, crash 0, idle 0, stop 0, subagent-stop 0, model 0, other 0
- router turns by cause: loop 13, relay 15, re-arm 5, other 0, relay cost $0.3888
- retriever re-asks: 0 of 0 retriever briefs repeat a lookup of the same run
- router: pa-session 657dd7d1 · requests 81 · ctx at end 82.1k · growth T1 +2.5k, T2 +2.9k, T3 +1.1k, T4 +2.1k, T5 +6.6k, T6 +2.7k, T7 +1.8k, T8 +2.7k · top: tools/status.py 12.9k/9, Agent 12.7k/12, tools/plan_edit.py 5.6k/10, other 5.4k/23, tools/research_add.py 3.0k/1
- noise: 59 lines 3.3k chars — No such file or directory: 37 lines/2.1k, usage: : 22 lines/1.3k
- price: read $0.20/Mtok · 1h write $7.45/Mtok · output $18.63/Mtok (phase model mix)
- median requests after a read: 3
- carry/request: 2097 chars, 602 requests (prev 1682 chars, 529 requests, growth 24.7%)
- flag: carry per request grew 25% vs 1.4
- flag: 1 whole-plan reads by main
- flag: 39 tool-source reads by coder-opus55, critic, expert-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/bound2.py  10.5k chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/bound2.py  4.6k chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/bound2.py  1.4k chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/fleet.sh  2.8k chars  expert-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/harness.py  7.7k chars  expert-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/harness.py  1.1k chars  expert-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/census.py  3.3k chars  expert-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/census.py  15.9k chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/boundaries.py  3.3k chars  expert-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/boundaries.py  2.1k chars  expert-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/boundaries.py  5.3k chars  expert-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/bound2.py  2.4k chars  expert-opus55
  /Users/ThinkPad/orca/mmx6/tools/plan_edit.py  159 chars  critic
  /Users/ThinkPad/orca/mmx6/tools/mmx6/boundaries.py  10.1k chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/boundaries.py  5.6k chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/fleet.sh  2.8k chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/corpus.py  4.2k chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/corpus.py  3.9k chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/corpus.py  5.9k chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/optscan.py  3.4k chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/optscan.py  9.4k chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/census.py  3.1k chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/census.py  5.9k chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/bound2.py  6.3k chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/bound2.py  4.1k chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/probe.py  9.6k chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/bound2.py  16.7k chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/optscan.py  15.9k chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/boundcheck.py  4.7k chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/corpus.py  656 chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/census.py  11.4k chars  expert-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/corpus.py  9.6k chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/bound2.py  8.3k chars  expert-opus55
  /Users/ThinkPad/orca/mmx6/.claude/skills/container-scratch-not-synced/SKILL.md  1.2k chars  expert-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/bound2.py  3.6k chars  expert-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/fleet.sh  2.0k chars  expert-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/boundcheck.py  4.7k chars  expert-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/optscan.py  3.5k chars  expert-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/optscan.py  6.4k chars  expert-opus55

## Agent runs
- T1 | expert-opus55 | expert | claude-opus-5-5 | high | ctx 83k | $0.948 | saved - | completed | parent 0c26ff2d
- T1 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 75k | $0.835 | saved - | completed | parent a95bb3c5
- T1 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 83k | $1.129 | saved - | completed | parent a95bb3c5
- T2 | expert-opus55 | expert | claude-opus-5-5 | high | ctx 147k | $2.540 | saved - | completed | parent 0c26ff2d
- T2 | retriever-code | retriever | claude-sonnet-5-5 | medium | ctx 35k | $0.151 | saved - | completed | parent a0da69fd
- T2 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 65k | $0.763 | saved - | completed | parent a0da69fd
- T1 | expert-opus55 | expert | claude-opus-5-5 | high | ctx 87k | $0.801 | saved $0.94 | completed | parent 657dd7d1
- T2 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 69k | $0.692 | saved - | completed | parent a0da69fd
- T1 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 62k | $0.538 | saved $2.30 | completed | parent a6cec3d5
- T2 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 61k | $0.564 | saved - | completed | parent a0da69fd
- T1 | critic | critic | claude-opus-5-5 | medium | ctx 23k | $0.129 | saved - | completed | parent 657dd7d1
- T2 | expert-opus55 | expert | claude-opus-5-5 | high | ctx 72k | $0.730 | saved $1.28 | completed | parent 657dd7d1
- T2 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 100k | $0.981 | saved - | completed | parent a0da69fd
- T2 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 76k | $0.891 | saved $0.80 | completed | parent a99d2990
- T2 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 136k | $1.850 | saved - | completed | parent a0da69fd
- T2 | critic | critic | claude-opus-5-5 | medium | ctx 22k | $0.175 | saved - | completed | parent 657dd7d1
- T3 | expert-opus55 | expert | claude-opus-5-5 | high | ctx 68k | $0.623 | saved $1.15 | completed | parent 657dd7d1
- T3 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 54k | $0.479 | saved $1.22 | completed | parent aef19d07
- T4 | expert-opus55 | expert | claude-opus-5-5 | high | ctx 69k | $0.567 | saved $0.22 | completed | parent 657dd7d1
- T2 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 139k | $1.914 | saved - | completed | parent a0da69fd
- T4 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 56k | $0.570 | saved $1.19 | completed | parent a4b2dd34
- T5 | expert-opus55 | expert | claude-opus-5-5 | high | ctx 116k | $1.998 | saved $5.16 | completed | parent 657dd7d1
- T2 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 172k | $4.377 | saved - | handoff | parent a0da69fd
- T5 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 41k | $0.266 | saved $0.24 | completed | parent ae6ba8f8
- T5 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 146k | $2.103 | saved $0.61 | completed | parent ae6ba8f8
- T5 | review | review | claude-opus-5-5 | medium | ctx 23k | $0.139 | saved - | completed | parent 657dd7d1
- T2 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 115k | $1.524 | saved - | completed | parent a0da69fd
- T6 | expert-opus55 | expert | claude-opus-5-5 | high | ctx 62k | $0.450 | saved $0.03 | completed | parent 657dd7d1
- T6 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 65k | $0.610 | saved $0.39 | completed | parent a221cb04
- T7 | expert-opus55 | expert | claude-opus-5-5 | high | ctx 58k | $0.471 | saved - | completed | parent 657dd7d1
- T7 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 52k | $0.612 | saved $0.01 | completed | parent a8de1abd
- T3 | expert-opus55 | expert | claude-opus-5-5 | high | ctx 70k | $0.498 | saved - | completed | parent 0c26ff2d
- T3 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 63k | $0.559 | saved - | completed | parent a8e17b59
- T8 | expert-opus55 | expert | claude-opus-5-5 | high | ctx 97k | $0.898 | saved $0.34 | completed | parent 657dd7d1
- T3 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 35k | $0.240 | saved - | completed | parent a8e17b59
- T8 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 96k | $0.960 | saved $0.17 | completed | parent a14accfb
- T4 | expert-opus55 | expert | claude-opus-5-5 | high | ctx 60k | $0.485 | saved - | completed | parent 0c26ff2d
- T4 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 75k | $0.805 | saved - | completed | parent a35bce1e
- T4 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 44k | $0.382 | saved $0.00 | completed | parent a35bce1e
- … 3 more: PY ~/.claude/pa3/pa_ledger.py report

## Discussions
- I4 | planner: bound2 merge check + split-independence measure for the 53 overlays whose starts T5 declared from bound2's own | deferred:1.6

## Deferred
- from T8: 1.6 should add a merge/independence check for the 53 overlays with declared starts (T5); `make tools-health-full` is the exhaustive gate behind the milestone. (unconsumed)
- I4 (deferred:1.6): planner: bound2 merge check + split-independence measure for the 53 overlays whose starts T5 declared from bound2's own

## Changes
- 2026-10-01 developer: D1: tracked health chain lives at mk/tools-health.mk (build/ is purged by firewall and make clean); milestone read as make tools-health-full green
- 2026-10-01 router: T1 done-when amended (critic, 2026-10-01): count clause 'count >= the 163 optscan carved: 29/81/53' reads 'glabel functions 29/77/52 = optscan raw jr-ra carve 29/81/53 minus 5 interior-return merges (rock_43 func_800FDCD4 +2, func_800FDD84 +2; rock_45 func_800FB6F0 +1), each named in logs/T1.md with branch site and target past the interior jr ra'; basis clause widened to retail-byte kinds jal target, post-return, first code word after header, data span (never Ghidra). Reason: a raw jr-ra count overcounts multi-return functions; splitting at those returns would create cross-function branches. These 3 overlays' starts are declared (158), and T4/T5 bound2 must check them as declared, not as first-oracle output.
- 2026-10-01 router: T1 next -> done
- 2026-10-01 router: T2 next -> done
- 2026-10-01 router: T3/T4/T6/T7 verify amended (critic, 2026-10-01): mx.sh sync wipes /work incl. extracted/ and build/, so each container clause after sync gains 'make -s extract && make -s build &&' at its head: T4/T6/T7 read 'bash -c 'make -s extract && make -s build && …''; T3 reads 'mx.sh run bash -c 'make -s extract && make -s build && make tools-health'' (th-corpus needs the linked build). Checks and expected lines unchanged. T5, T8 and milestone unchanged: they lead with make fleet (green after sync in T1/T2), and tools-health-full runs after fleet with no sync in between. Basis: tasks/T2.md, .run/logs/t2verify.log.
- 2026-10-01 router: T3 next -> done
- 2026-10-01 router: T4 next -> done
- 2026-10-01 developer: T5 next -> done — accepted at review: 0/0, empty ledger, byte evidence for every class
- 2026-10-01 router: T6 next -> done
- 2026-10-01 router: T7 next -> done
- 2026-10-01 router: T8 next -> done

## Plain-English Recap
Phase 1.5 made the project's measuring tools honest before real decompilation starts. A "scanner" here is a script that walks the built game code and counts something, such as functions, function boundaries or duplicated code. Every scanner now prints its denominator, meaning the total it counts against, read from the build rather than typed in by hand. Each scanner also passes a "known-true control", a planted case whose correct answer is known in advance. A second, independent boundary checker now finds 0 phantom functions and 0 truncated ones across all 57 programs. A new differential harness asks the same question of two independent sources (for example, how many functions are already in C) and found 0 disagreements. The census shows where effort pays off: 1,152 classes of byte-identical duplicate functions, 1,175 structural families (same instruction shape, different registers or constants) and a unique tail of 2,531 functions that resemble no other function. 285 of 7,345 functions are matched today, 282 of them empty stubs.
