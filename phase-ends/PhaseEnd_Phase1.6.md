# PhaseEnd — Phase 1.6: The multipliers and the type layer (implements Gen 1.6)
Approved: 2026-10-01 | Closed: 2026-10-01 | Planner: claude-opus-5-5/medium | Tasks: 9 done, 1 superseded

## Milestone
Milestone: one hand-matched function propagates to every member across the fleet, byte-gated per member, registered fail-closed (propagation dry run reports every member gated); the twin band reproduces every known exact pair; a standalone match banks into its real unit by the reconcile ladder without a redraft; opt-level and jump-table carves build; the draw filter counts what it refused; the canonical-type check refuses a planted duplicate; the X4↔X6 sharing number recorded; the clean fleet check stays N of N — verified by: `bash tools/docker/mx.sh sync && bash tools/run.sh --bg fleet -- bash tools/docker/mx.sh run make fleet` then `bash tools/run.sh --wait fleet --max 280` (repeat the wait until done) rc 0, last line `FLEET 57 of 57`, the log holds `C MATCHED <c> of <F> functions (… banked <b>)` with b ≥ 3 + the propagated members, `HARNESS 0 disagreements in <p> pairs` (p ≥ 6); then `bash tools/run.sh --bg health -- bash tools/docker/mx.sh run make tools-health-full` + `bash tools/run.sh --wait health --max 280` rc 0, last line `TOOLS-HEALTH OK <k> rungs`, the log holds `BOUND2 merges=0` and `BOUND2 INDEPENDENT <i> of <S>`, `PROPAGATE DRY-RUN <class> gated <m> of <m> members`, `REGISTRY OK <r> rows`, `TWINS exact_pairs <e> of <e> in band`, `RECONCILE CONTROL OK`, `CARVE jtbl OK` and `CARVE opt OK`, `TYPES CONTROL OK` (planted duplicate refused), `DRAW refused <r> of <n>` with per-reason counts, `HARNESS 0 disagreements in <p> pairs`, every `<NAME> CONTROL OK`; `grep -n "X4SHARE" docs/prior-art.md` → one line with the number and its denominator; `PY tools/audit_public.py` rc 0. Clauses run one after another, never concurrently.
Verified: `mx.sh sync` + `run.sh --bg t9fleet -- mx.sh run make fleet` → exit 0, `HARNESS 0 disagreements in 7 pairs`, `C MATCHED 701 of 8534 functions (282 empty-body; banked 419)`, `FLEET 57 of 57` (.run/logs/t9fleet.log); `run.sh --bg t9health -- mx.sh run make tools-health-full` → exit 0, `TOOLS-HEALTH OK 16 rungs`, `BOUND2 merges=0`, `BOUND2 INDEPENDENT 1985 of 2031`, `PROPAGATE DRY-RUN 6d5cbe29… gated 416 of 416 members`, `REGISTRY OK 416 rows`, `TWINS exact_pairs 277792 of 277792 in band`, `RECONCILE CONTROL OK`, `CARVE jtbl OK`, `CARVE opt OK`, `TYPES CONTROL OK`, `DRAW refused 4840 of 7833 (L1 579 L2 4261 L3 0 L4 0)`, `HARNESS 0 disagreements in 8 pairs`, 17 CONTROL OK, 0 FAIL (.run/logs/t9health.log); `grep -n "X4SHARE" docs/prior-art.md` → one line (28); `PY tools/audit_public.py` → rc 0

## Tasks
- T1 — bound2 merge check and start independence | Done: bound2 now reports merges (build/bound2/merges.txt, each inner B2 start classed multi-return with its site or over-merge) and fails `--all` on any over-merge; all 1189 over-merges were split by declared starts, fleet green at 8534 functions; start independence is measured over config/symbols.<prog>.txt. | commit: - | tasks/T1.md | logs/T1.md
- T2 — signatures and the twin band | Done: tools/mmx6/sig.py writes build/sig/sigs.jsonl (8534 rows) and build/sig/twins.jsonl (exact + near pairs) from census.read_words; exact-pair control 277792 of 277792 in band; rung th-sig runs in `make fleet` (8 rungs). | commit: - | tasks/T2.md | logs/T2.md
- T3 — canonical type file and its bank-time check | Done: `include/mmx6/types.h` holds every typedef/struct (6 primitives + `Probe800473EC`, each with `// evidence:`); `tools/mmx6/typecheck.py` keys them by shape and refuses duplicates, defs outside include/mmx6/, raw address casts in src/<prog>/; rung `th-types`; fleet green, C MATCHED 285 unchanged. | commit: - | tasks/T3.md | logs/T3.md
- T4 — reconcile ladder and the hand-matched exemplar | Done: exemplar func_8003744C (dup class 6d5cbe29…, 15 words, 416 members, payoff 6225, reach 37) hand-matched standalone and banked into exe TU 120A0 through `bank.py` as `src/shared/entity/state_dispatch.c`, body unchanged since R1; bank.py walks R1-R5 with declsync/typecheck/sig rescan; self-test controls green; C MATCHED banked 4. | commit: - | tasks/T4.md | logs/T4.md
- T5 — overlay C units, dedup propagation and the registry | Done: 36 overlays holding members of dup class 6d5cbe29… are whole-overlay `c` units; propagate.py instantiated the T4 shared body at all 416 members (416 of 416 gated, 0 refused), registry 416 rows, fail-closed check and self-test; C MATCHED banked 419. | commit: - | tasks/T5.md | logs/T5.md
- T6 — jump-table and opt-level carve tools | Done: `tools/mmx6/carve.py` carves a jump table into its dispatcher unit's rodata and splits a unit at a function start with a per-unit CFLAGS override; both applied on the exe (table 0x80011378 → unit 32208; 120A0 split at 0x80032208, pin O2 cflags), fleet byte-identical; rung th-carve. | commit: - | tasks/T6.md | logs/T6.md
- T6.1 — bank.py self-test on planted siblings | Done: `bank.py --self-test` no longer needs live include_asm siblings: it plants two (exe members of class 6d5cbe29 reverted from define block to INCLUDE_ASM over a generated retail-words .s), proves the plant byte-identical, runs controls A and B, tears down byte-exact and checks src/, registry and binary sha1 unchanged; ends `RECONCILE CONTROL OK`. | commit: - | tasks/T6.1.md | logs/T6.1.md
- T7 — family remap from a banked exemplar | Done: tools/mmx6/family_remap.py remaps a banked exemplar's shared body onto family siblings outside its dup class by positional pairing of relocation targets into a #define mapping, gates each via bank.py; real run on the exemplar's family: `REMAP 40505e804bdfbd1e8638f69e75c5e8b64881ef98 gated 0 of 258 siblings; refused 258 (preflight 39, R1 219)`; self-test controls G (gated R5) and R (refused pair), `REMAP CONTROL OK`. | commit: - | tasks/T7.md | logs/T7.md
- T8 — X4↔X6 sharing number from mmx4's own build | Done: tools/mmx6/x4share.py clones mmx4 into container `.run/mmx4/`, compiles each US C file alone with INCLUDE_ASM stubbed, signs functions with sig.py and counts X6 functions with exact/near X4 partners; L5 in docs/prior-art.md is measured. | commit: - | tasks/T8.md | logs/T8.md

## Decisions that still bind
- T1 — merge = inventory function F holding a B2 start s strictly inside; `multi-return` iff a crossing edge exists (branch/j inside F across g, fallthrough into s, or a jtbl of F with targets across g; g = word after the preceding jr ra delay slot for post-ret s, else s), else `over-merge`; `merges=` counts over-merges and gates rc; multi-return never gates.
- T1 — independence basis per declared `type:func` start: ghidra (Ghidra k=func) > pointer (start value stored as an aligned word in the program's own image) > none; a measure, not a gate.
- T1 — an over-merge is fixed by declaring both F's start and each inner start sized (last jr ra + 8 before the next new start) in config/symbols.<prog>.txt; multi-return inner starts are not boundaries.
- T2 — twin band — exact = equal census dup key; near = not exact, length min/max >= 0.75, skel-histogram L1 <= 2*RATIO*max_len, Levenshtein over relocation-masked words / max_len <= RATIO, RATIO = 0.3; near impossible below 4 words.
- T2 — E = sum C(n,2) over kind=dup classes in build/census/classes.jsonl; sig rc 1 when e<E or the census member set != corpus set.
- T2 — base rate = 100000 uniform distinct random pairs, seed 0x516, same band predicate.
- T3 — every typedef/struct lives in include/mmx6/types.h with a `// evidence:` line, probe sources included; a new type in src/ fails th-types, so fleet.
- T4 — a shared body is banked by replacing the member's INCLUDE_ASM line with `#include "../shared/<system>/<name>.c"`; the body file includes common.h itself and is the probe source at R1, so its sha1 is the R1-R5 invariant.
- T4 — bank.py verdicts `RECONCILE <func> R5 banked; body sha1 <h> unchanged since R1` | `RECONCILE <func> stopped R<k>: <cause>` (rc 1) | preflight `refused` (rc 2); every stop restores edited files and rebuilds.
- T5 — a non-exemplar member instantiates a shared body as `#define <exemplar fn> <member name>` + `#define <exemplar table> D_<absolute addr>` (addr from the member's retail hi/lo pair), `#include "../shared/…c"`, `#undef` both; the registry reason column names the defines. An absent `D_<addr>` resolves through the Makefile PROVIDE rule.
- T5 — registry check = per row recompute the member's dup key from the built object; refuse on drift, on a class member with no row (missing member), on a row whose member is not in the class; `REGISTRY OK <r> rows`.
- T5 — propagate gates R1-R4 per member via bank.py, R5 once per program plus a per-member unmasked compare of the linked extent; a program R5 failure isolates per member.
- T5 — an overlay c unit needs `auto_decompile_empty_functions: false` (else splat writes `jr ra` stubs as empty C, c-empty +160).
- T6 — carve state lives per binary in `config/carve.<prog>.txt` (written only by carve.py) and its generated `config/carve.<prog>.mk`; segment.py applies the record, so the yaml block stays generated and survives regeneration (G43, T4 binding).
- T6 — per-unit cc1 flags are a target-specific `CFLAGS_<tu>` on `build/src/<prog>/<tu>.c.o` (no cross-binary collision; overlays share tu names).
- T6 — a jtbl carve emits `[off, .rodata, <tu>]` (dot type; plain `rodata` with a c sibling is a splat error) and requires the dispatcher's unit to be c and its rodata contiguous; the opt carve's new unit inherits the parent kind.
- T7 — family remap rungs in order preflight, pair, R1..R5; R1 is pre-screened with bank.wrapper + probe.probe so an R1 refusal never triggers bank's per-stop program rebuild; bank.bank(registry=False, defines) only for R1 matches.
- T7 — exemplar targets = relocations of the shared body compiled standalone; sibling targets = relocations in the built object holding it (c.o for C units, else s.o), HI16/LO16 named `D_<ADDR>` from the retail hi/lo pair at each site, R_MIPS_26 by symbol; section-symbol target refuses pair.
- T7 — pair refuses count/type mismatch, inconsistent mapping, and reorder/chain (x -> y, y != x, y also an exemplar target); this keeps the #define mapping cpp-safe.
- T7 — family registry row `<family key> <ex prog:vram> <body> <member prog:vram> gated family define A=B …`; propagate --check recomputes the member's census.family_key and refuses drift or absence from the family class; family rows are exempt from the missing-member rule.
- T8 — the X4 sharing number is taken under X6's pin (gcc2.95.2-psx-aspsx2.86); the plan's 2.6.3 triple compiles nothing and mmx4's own 2.7.2 is not X6's compiler.
- T9 — walls.txt row = `<prog> <vram> <pass> <dumpfile>:<line> <quoted dump line>` (G52); pass from a fixed gcc 2.95 cc1 dump-pass list + `maspsx`; a wall on a c/c-empty function is stale and fails `--check`.
- T9 — verdict layers, a function counted at the first that refuses: L1 lib OBJ not in compiler-pin `## Proven lib units`, boundaries jtbl row of the function with no carve row, optscan opt vs unit cflags; L2 any registry row, an exact twin already C (propagate, not draft), one survivor per open twin cluster (connected component of twins.jsonl exact+near over the difficulty list; G46); L3 walls.bankable no; L4 non-stale exclude row with layer L4.
- T9 — draw_exclude.txt is audited before any verdict: a row is stale if its function left the difficulty list or (layer L1-L3) that layer no longer refuses it; any stale row → `DRAW STALE …`, rc 2, no draw.jsonl (G38). L1-L3 rows are mirrors; only L4 rows add refusals.
- T9 — P8 bankable? agrees iff draw.jsonl keys = difficulty keys, no function walls/registry call unbankable is draw|eligible, every L3 row is walls-unbankable.
- norm: types live in include/mmx6/types.h with evidence, keyed by shape, fleet-gated → rule G105 (T3).
- norm: a shared body is one src/shared file included per member, members differ only by name/address #defines, registry fail-closed → rule G106 (T4, T5, T7).
- norm: sibling-game C is measured and adopted under X6's pin, counts only in git → rule G107 (T8).
- contract: bound2 merge classes, independence basis, over-merge fix by sized starts → docs/ops/oracles.md + th-bound2 self-test (T1).
- contract: twin band (exact/near, RATIO 0.3, base-rate seed) → docs/ops/decomp-environment.md sig row + th-sig (T2).
- contract: bank.py R1-R5 verdicts, body sha1 invariant, planted-sibling self-test → docs/ops/decomp-environment.md bank row + th-selftests (T4, T6.1).
- contract: registry check and per-member gating; overlay c units need `auto_decompile_empty_functions: false` → docs/ops/decomp-environment.md + th-propagate(-full) (T5).
- contract: carve record per binary, `CFLAGS_<tu>`, `.rodata` subsegment type → docs/ops/decomp-environment.md "Carves" + th-carve (T6; G43).
- contract: family remap rungs and family registry rows → docs/ops/decomp-environment.md + th-remap (T7).
- contract: walls.txt row format, verdict layers L1-L4, draw_exclude staleness audit, P8 agreement → docs/ops/decomp-environment.md + th-walls, th-draw, harness P8 (T9; G52).
- Next task needs: mmx4's 2,042 exact partners as a bank source for leverage-first waves (critic-deferred to 1.7/1.8; G102, G107).
- Next task needs: 579 L1 refusals wait on lib-unit triple proofs and overlay jtbl carves (overlay yamls have no rodata block); walls.txt and draw_exclude.txt are still empty.
- Next task needs: family 40505e80's 258 siblings differ by one offset immediate; they need a parameterised body, not a remap (T7).
- Next task needs: harness fix for `phaseend_index.py verify` on bg/wait clauses (judge the `--wait` result, run clauses sequentially).

## Rules proposed
- (none)

## Cookbook entries added
C0058 | Splat can fuse dozens of real functions into one; check B2 starts strictly inside each function | boundaries,splat,spimdisasm,merge,bound2 | 2026-10-01 | 1.6/T1 | mmx6 T1
C0059 | Code after an interior jr ra reached by no edge is its own function; splitting is byte-neutral | boundaries,mips,multi-return,merge | 2026-10-01 | 1.6/T1 | mmx6 T1
C0060 | Near-duplicate band: lossless prefilter by length and opcode-histogram bounds | twins,near-dup,edit-distance,census | 2026-10-01 | 1.6/T2 | mmx6 T2
C0061 | Moving a type to a shared header: remove its copies from probe sources too | types,header,probe,common.h | 2026-10-01 | 1.6/T3 | mmx6 T3
C0062 | A masked standalone match can name the wrong symbol; only the whole-binary hash catches it | probe,masking,relocation,bank | 2026-10-01 | 1.6/T4 | mmx6 T4
C0063 | Format a body before the first probe; clang-format changes its sha1 afterwards | clang-format,bank,sha1 | 2026-10-01 | 1.6/T4 | mmx6 T4
C0064 | Verify c-unit conversions from a clean sync; splat skips .s for functions only named D_<addr> | splat,c-unit,nonmatchings,overlay | 2026-10-01 | 1.6/T5 | mmx6 T5
C0065 | Parameterise a shared body per member with name #defines; gate with an unmasked linked compare | dedup,propagate,define,relocation | 2026-10-01 | 1.6/T5 | mmx6 T5
C0066 | Plant a self-test precondition that real progress consumed; prove the plant by the binary hash | self-test,control,plant | 2026-10-01 | 1.6/T6.1 | mmx6 T6.1
C0067 | A corpus regeneration rewrites several outputs together; scratch runs save and restore all of them | corpus,scratch,self-test | 2026-10-01 | 1.6/T6.1 | mmx6 T6.1
C0068 | A planted .word .s must span the corpus extent to its end, or the link shifts | plant,probe,extent,link | 2026-10-01 | 1.6/T6.1 | mmx6 T6.1
C0069 | splat pairs rodata with a c unit only as type .rodata; derive the dispatcher from %hi | splat,rodata,jtbl,carve | 2026-10-01 | 1.6/T6 | mmx6 T6
C0070 | Splitting a c unit must rewrite the moved INCLUDE_ASM folders to the new unit | splat,carve,include_asm,nonmatchings | 2026-10-01 | 1.6/T6 | mmx6 T6
C0071 | Family-only siblings differ in a non-relocated field; relocation remap gates few | family,remap,dedup,relocation | 2026-10-01 | 1.6/T7 | mmx6 T7
C0072 | #define A B with #define B A collapses under cpp rescanning; refuse such mappings | cpp,define,remap | 2026-10-01 | 1.6/T7 | mmx6 T7
C0073 | Test sibling-game sharing under the target's compiler pin; vary only the compiler as the control | prior-art,sibling-game,pin,control | 2026-10-01 | 1.6/T8 | mmx6 T8
C0074 | Draw filter over a twin graph: at most one member per connected component per wave | draw,twins,wave,routing | 2026-10-01 | 1.6/T9 | mmx6 T9

## Research
R1.6-001 | define each multiplier instrument for a task planner (done-when, controls, incidents) | Phase 1.6 multiplier instruments, as defined in the inherited record | phase-1.6, multipliers, twin, dedup, family, carve, reconcile, G7, G10, G38, G43, G46, G50, G62 | retriever-digest | 2026-10-01 | 30 lines
R1.6-002 | extract planner facts for 1.6 (banking, opt-level, jtbl, bound2 independence, census) | Phase 1.6 planner facts from 1.2-1.5 summaries | phase-1.6, banking, census, bound2, segmentation, compiler-pin | retriever-digest | 2026-10-01 | 64 lines
R1.6-003 | can sozud/mmx4 compile matched C to objects without X4 disc | mmx4 build without disc | mmx4, psx, decomp, toolchain | retriever-web | 2026-10-01 | 32 lines

## Audit
- seed: median 15k, max 15k, n=11 (phase 1.6)
- previous phase 1.5: median 14k, growth 3.5%
- CLAUDE.md: 1242 bytes (unchanged)
- .claude/skills/ci-wait-after-push/SKILL.md: 799 bytes (unchanged)
- .claude/skills/container-scratch-not-synced/SKILL.md: 1125 bytes (unchanged)
- .claude/skills/docker-vm-no-privileged/SKILL.md: 774 bytes (unchanged)
- .claude/skills/project-architect/SKILL.md: 13448 bytes (unchanged)
- .claude/skills/typecheck-fnptr-keyer-first/SKILL.md: 1093 bytes (new)
- .claude-state/memory/MEMORY.md: 214 bytes (unchanged)
- HOW_WE_WORK.md: 7031 bytes
- cookbook/INDEX.md: 11715 bytes
- rules/INDEX.md: 10984 bytes
### Carry audit — phase 1.6 (2026-10-01T19:20:33Z → open UTC, 2 sessions, 1191 requests)
- beside 1.6: session 40c95448 $5.19 (83 turns), not attributed
- beside 1.6: session 848488e2 $10.41 (298 turns), not attributed
- beside 1.6: session 66464fd8 $7.09 (98 turns), not attributed
- beside 1.6: session 6ea0c3e5 $7.21 (119 turns), not attributed

| file (read) | chars | n |
|---|---|---|
| bank.py | 102.8k | 10 |
| PHASE_PLAN.md | 71.4k | 5 |
| bound2.py | 56.9k | 6 |
| propagate.py | 35.9k | 3 |
| probe.py | 33.3k | 5 |
| census.py | 26.8k | 2 |
| harness.py | 24.3k | 2 |
| T5.md | 18.4k | 3 |
| decomp-environment.md | 14.7k | 5 |
| corpus.py | 14.5k | 4 |
| file (write) | chars | n |
|---|---|---|
| refs.toml | 31.9k | 3 |
| bank.py | 26.4k | 13 |
| install.py | 25.3k | 1 |
| carve.py | 19.8k | 4 |
| family_remap.py | 19.4k | 1 |
| propagate.py | 17.8k | 4 |
| draw.py | 17.6k | 1 |
| fetch_refs.py | 16.5k | 1 |
| result kind | chars | n |
|---|---|---|
| bash other | 894.3k | 547 |
| Read | 593.9k | 108 |
| tools/card.py | 236.1k | 27 |
| run.sh | 120.6k | 143 |
| tools/plan_edit.py | 117.9k | 24 |
| tools/task_log.py | 32.3k | 15 |
| tools/outline.py | 30.6k | 8 |
| Agent | 27.5k | 26 |
| tools/status.py | 21.0k | 13 |
| Grep | 20.5k | 10 |
- whole reads over 20.0k: 1
- seed floor: retriever-code 5,376 (n 1, prev 5,436) · retriever-digest 5,273 (n 2, prev 5,241) · retriever-web 3,702 (n 1, prev —)
- outline credit: 10 outlines · 7 followed by a ranged read · 56.2k chars credited
- warm pings: 44 pings over 10 runs, 13 warmed waits over the TTL, rewrites across warmed waits 0, waits past the cap 0, pings cost $0.6124 vs rewrites replaced $4.2850, cheaper than one rewrite: yes
- toasts by cause (waiting): question 0, review 0, replan 0, permission 0, input 0, discussion 0, crash 0, idle 0, stop 0, subagent-stop 0, model 0, other 0
- router turns by cause: loop 14, relay 44, re-arm 12, other 5, relay cost $1.2994
- retriever re-asks: 0 of 0 retriever briefs repeat a lookup of the same run
- router: pa-session a0525f51 · requests 163 · ctx at end 110.3k · growth T1 +1.4k, T2 +3.4k, T3 +1.0k, T4 +2.2k, T5 +13.1k, T6 +5.3k, T6.1 +3.0k, T7 +5.2k, T8 +2.0k, T9 +2.7k · top: tools/status.py 21.0k/13, Agent 13.8k/13, tools/plan_edit.py 11.7k/12, other 11.3k/58, bash other 681/1
- noise: 102 lines 8.5k chars — No such file or directory: 63 lines/6.0k, usage: : 38 lines/2.4k, warning: in the working copy of: 1 lines/91
- price: read $0.20/Mtok · 1h write $7.58/Mtok · output $18.95/Mtok (phase model mix)
- median requests after a read: 3
- carry/request: 1814 chars, 1191 requests (prev 1515 chars, 605 requests, growth 19.7%)
- flag: 45 tool-source reads by coder-opus55, critic, expert-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/report.py  2.5k chars  expert-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/harness.py  7.7k chars  expert-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/bank.py  18.8k chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/probe.py  2.3k chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/corpus.py  1.8k chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/corpus.py  1.1k chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/bank.py  3.6k chars  expert-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/bank.py  3.4k chars  expert-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/bound2.py  20.9k chars  expert-opus55
  /Users/ThinkPad/orca/mmx6/tools/plan_edit.py  1.8k chars  critic
  /Users/ThinkPad/orca/mmx6/tools/plan_edit.py  2.0k chars  critic
  /Users/ThinkPad/orca/mmx6/tools/mmx6/bank.py  23.9k chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/propagate.py  19.4k chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/census.py  10.9k chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/probe.py  5.9k chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/bank.py  15.4k chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/probe.py  13.9k chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/declsync.py  3.6k chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/bank.py  18.8k chars  expert-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/bank.py  6.0k chars  expert-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/corpus.py  10.0k chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/probe.py  1.3k chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/probe.py  9.9k chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/bound2.py  964 chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/bank.py  2.0k chars  expert-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/bank.py  1.5k chars  expert-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/census.py  15.9k chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/harness.py  16.6k chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/propagate.py  10.5k chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/propagate.py  6.0k chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/bank.py  9.5k chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/corpus.py  1.6k chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/bound2.py  20.9k chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/boundaries.py  671 chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/boundaries.py  581 chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/boundaries.py  246 chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/bound2.py  3.3k chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/segment.py  10.6k chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/boundcheck.py  624 chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/.claude/skills/container-scratch-not-synced/SKILL.md  1.2k chars  expert-opus55
  /Users/ThinkPad/orca/mmx6/.claude/skills/typecheck-fnptr-keyer-first/SKILL.md  434 chars  expert-opus55
  /Users/ThinkPad/orca/mmx6/.claude/skills/container-scratch-not-synced/SKILL.md  1.2k chars  expert-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/bound2.py  4.1k chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/bound2.py  6.7k chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/tools/docker/mx.sh  2.6k chars  coder-opus55
- flag: 1 whole reads over 20.0k by coder-opus55
  file: /Users/ThinkPad/orca/mmx6/tools/mmx6/bank.py  role: coder-opus55  chars: 22.1k

## Agent runs
- T1 | expert-opus55 | expert | claude-opus-5-5 | high | ctx 80k | $0.695 | saved $1.81 | completed | parent a0525f51
- T1 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 57k | $0.740 | saved $1.37 | completed | parent a2789770
- T1 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 59k | $0.545 | saved $1.71 | completed | parent a2789770
- T2 | expert-opus55 | expert | claude-opus-5-5 | high | ctx 55k | $0.369 | saved $0.84 | completed | parent a0525f51
- T2 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 61k | $0.653 | saved $1.67 | completed | parent a59372dc
- T3 | expert-opus55 | expert | claude-opus-5-5 | high | ctx 53k | $0.383 | saved $0.75 | completed | parent a0525f51
- T3 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 51k | $0.613 | saved $2.41 | completed | parent a5c28ae0
- T4 | expert-opus55 | expert | claude-opus-5-5 | high | ctx 83k | $0.884 | saved $1.45 | completed | parent a0525f51
- T4 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 102k | $1.378 | saved $4.43 | completed | parent adb6e9ed
- T5 | expert-opus55 | expert | claude-opus-5-5 | high | ctx 86k | $1.189 | saved $0.71 | completed | parent a0525f51
- T1 | expert-opus55 | expert | claude-opus-5-5 | high | ctx 53k | $0.644 | saved - | completed | parent f11d66e5
- T1 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 68k | $0.719 | saved - | completed | parent ac1ab443
- T5 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 65k | $0.632 | saved $1.34 | completed | parent a8321060
- T5 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 145k | $2.682 | saved $2.24 | completed | parent a8321060
- T1 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 25k | $0.160 | saved - | completed | parent ac1ab443
- T2 | expert-opus55 | expert | claude-opus-5-5 | high | ctx 46k | $0.440 | saved - | completed | parent f11d66e5
- T2 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 40k | $0.406 | saved - | completed | parent ab537db8
- T3 | expert-opus55 | expert | claude-opus-5-5 | high | ctx 45k | $0.410 | saved - | completed | parent f11d66e5
- T3 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 71k | $0.727 | saved - | completed | parent a17e0608
- T5 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 135k | $2.165 | saved $3.24 | completed | parent a8321060
- T4 | expert-opus55 | expert | claude-opus-5-5 | high | ctx 47k | $0.446 | saved - | completed | parent f11d66e5
- T4 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 96k | $1.468 | saved - | completed | parent a9084d30
- T5 | expert-opus55 | expert | claude-opus-5-5 | high | ctx 99k | $2.057 | saved - | completed | parent f11d66e5
- T5 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 33k | $0.416 | saved - | completed | parent a560023a
- T5 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 82k | $0.967 | saved - | completed | parent a560023a
- T6 | expert-opus55 | expert | claude-opus-5-5 | high | ctx 83k | $0.789 | saved $0.19 | completed | parent a0525f51
- T6 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 120k | $1.611 | saved $0.96 | completed | parent a858a4b8
- T5 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 25k | $0.272 | saved - | completed | parent a560023a
- T6 | critic | critic | claude-opus-5-5 | medium | ctx 37k | $0.257 | saved - | completed | parent a0525f51
- T6.1 | expert-opus55 | expert | claude-opus-5-5 | high | ctx 66k | $0.435 | saved $0.21 | completed | parent a0525f51
- T6 | expert-opus55 | expert | claude-opus-5-5 | high | ctx 59k | $0.695 | saved - | completed | parent f11d66e5
- T6 | retriever-digest | retriever | claude-sonnet-5-5 | medium | ctx 14k | $0.066 | saved - | completed | parent a7959bec
- T6.1 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 61k | $0.502 | saved $0.87 | completed | parent a50e62ac
- T6 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 58k | $0.551 | saved - | completed | parent a7959bec
- T7 | expert-opus55 | expert | claude-opus-5-5 | high | ctx 62k | $0.519 | saved $0.08 | completed | parent f11d66e5
- T7 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 32k | $0.271 | saved - | completed | parent aa3f5b8a
- T7 | expert-opus55 | expert | claude-opus-5-5 | high | ctx 92k | $0.873 | saved $0.06 | completed | parent a0525f51
- T7 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 101k | $1.260 | saved $0.24 | completed | parent a1b1f7d4
- T7 | expert-opus55 | expert | claude-opus-5-5 | high | ctx 58k | $0.504 | saved - | completed | parent f11d66e5
- … 13 more: PY ~/.claude/pa3/pa_ledger.py report

## Discussions
- (none)

## Deferred
- T6 | superseded — jump-table and opt-level carve tools
- from T9: walls.txt and draw_exclude.txt are empty; the first real wall needs pass + dump line or walls.py refuses it; 579 L1 refusals wait on lib triple proofs and jtbl carves (overlays have no rodata block). (unconsumed)

## Changes
- 2026-10-01 router: T1 next -> done
- 2026-10-01 router: T2 next -> done
- 2026-10-01 router: T3 next -> done
- 2026-10-01 router: T4 next -> done
- 2026-10-01 router: T5 next -> done
- 2026-10-01 router: T6 next -> done
- 2026-10-01 router: reopened T6 as T6.1 — bank.py self-test on planted siblings
- 2026-10-01 router: critic: T6.1 makes the bank.py self-test independent of the corpus. It has been red since T5, and tools-health-full in the T9 milestone runs it.
- 2026-10-01 router: T6.1 next -> done
- 2026-10-01 router: T7 next -> done
- 2026-10-01 router: T8 next -> done
- 2026-10-01 critic: critic: T8 deviation accepted. The plan's cc1 2.6.3 triple compiled 0 of 402 files (recorded). The number was measured under X6's pin gcc2.95.2-psx-aspsx2.86 (prior-art L1 already supersedes 2.6.3). The milestone clause is unchanged and T9 consumes it as is.
- 2026-10-01 critic: critic: deferred, not in 1.6 scope: banking from mmx4's 2042 exact X4 partners. It goes to the 1.7/1.8 planner as a bank source for leverage-first waves, under the standing G102 rule (proven-shared functions only, THIRD_PARTY.md credit). No X4 byte, object or per-function list is tracked (G12).
- 2026-10-01 router: T9 next -> done

## Plain-English Recap
Phase 1.6 built the tools that let one matched function count many times. A "dup class" is a group of functions whose machine code is identical once addresses are masked out; "banking" a function means putting its C source into the real build so that the whole game binary still rebuilds byte-for-byte; the "fleet" is the 57 game programs (the main executable plus 56 overlays) rebuilt and hash-checked together. The phase first fixed the function-boundary checker, which found 1,189 places where the disassembler had fused several real functions into one; splitting them raised the function count from 7,345 to 8,534 with the fleet still identical. It then added a duplicate finder, one shared header for data types, a five-step ladder that moves a matched function into its real source file and re-checks the whole binary, and tools that cut source files at jump tables and at function boundaries; one 15-instruction function, matched by hand, was placed at all 416 of its copies, raising matched functions from 285 to 701 of 8,534 (282 of them empty stubs). Finally, a filter now picks what to decompile next and counts why it set the rest aside (4,840 of 7,833 set aside), and compiling Mega Man X4's published source under X6's compiler showed 2,042 X6 functions with an identical X4 counterpart, a large source for later phases.

Milestone re-verified clause by clause in this session: fleet exit 0, `FLEET 57 of 57`, `C MATCHED 701 of 8534 functions (282 empty-body; banked 419)`, `HARNESS 0 disagreements in 7 pairs`; tools-health-full exit 0, `TOOLS-HEALTH OK 16 rungs` with every named line present (merges=0, INDEPENDENT 1985 of 2031, DRY-RUN gated 416 of 416, REGISTRY OK 416, TWINS 277792 of 277792, RECONCILE/TYPES CONTROL OK, CARVE jtbl and opt OK, DRAW refused 4840 of 7833 by layer, HARNESS 0 in 8 pairs, 17 CONTROL OK); one X4SHARE line in docs/prior-art.md:28; audit rc 0.

Deviation (harness): `phaseend_index.py verify` reported GREEN 4/4 after only launching the background fleet and health runs, and started both at once; the health run beside the fleet failed. Its verdict was discarded and the clauses were rerun one after another (logs/PHASE-END.md).

H7 check: every summary that names tools, pins or build commands also lists docs/ops/ or HOW_WE_WORK.md; no miss.
