# Phase 1.8 planner inputs: census, carries, 1.7 audit
task: gather census numbers, open carries, 1.7 audit data for the 1.8 PHASE_PLAN
agent: retriever-digest
tags: phase-1.8, census, carries, twins, x4share, draw, audit

## Answer
Fleet: 8534 functions (57 programs: exe SLUS_013.95 + 56 overlays), 701 C-matched (282 empty-body stubs + 419 banked), 7833 open. Draw 2993 of 7833. Details below.

## Findings
(a) Census
- Inventory 8534 (asm 8249 at 1.6 T1) after bound2 split 1189 over-merges (was 7345); phase-1.6/tasks/T1.md:20. Per-program totals NOT in any PhaseEnd; read build/reports/progress.md.
- C MATCHED 701 of 8534 (282 empty-body; banked 419): 4 hand/bank (T4 exemplar func_8003744C + 3) + propagated 416 members of dup class 6d5cbe29 (15 words, payoff 6225, reach 37, exe 6 + 36 overlays), all 416 gated 15/15 under pin gcc2.95.2-psx-aspsx2.86. PhaseEnd_Phase1.6.md:6,12,13; phase-1.6/tasks/T5.md:30.
- Stubs vs C: 8534-701 = 7833 INCLUDE_ASM stubs (draw input).
- 1.5 baseline at 7345 (stale for payoffs): game 6858, lib 487 (PsyQ lib funcs, reach always 1, exe only; lib matched 0; 20 dup classes/52 members, tail 334); 1152 dup classes/4482 members; 1175 families/4814; unique tail 2531 (808064 B, 34%); game tail 2198/715696 B. phase-1.5/tasks/T6.md:19-23. Empty-body class 412 = 282 c-empty + 130 asm jr ra stubs.
- Fresh at 8534: dup_classes=1445 families=1448 unique_tail=2551 (phase-1.6/tasks/T2.md:20). Twins: exact pairs 277792, near 174556, 4341 distinct exact keys, twins.jsonl 452348 rows; near RATIO 0.3, base rate 1.25%.
- Reach x size: 2 classes <=8 words reach 11+ hold 719 funcs; 9 classes of 9-32 words reach 11+ hold 655 (1.5 T6 findings). Next dup candidates: aad97fb234fe (15w, 171 members, payoff 2550, reach 34), 092b78e20e4a (19w, 49, 912, reach 25) (phase-1.6/logs/T4.md:8). 1.5 dup payoff 536040 of 1717444 text bytes (1152 classes, 4482 members).
- X4SHARE (under X6 pin): exact 2042, near 916 of 8534; X4 side 4289 funcs/402 of 402 C files; 1547 exact >=8 words; 251 distinct exact keys (overlay dups inflate); largest 114 words; control gcc 2.7.2 gives 47 >=8w. docs/prior-art.md:28. Constraint: G102 (proven-shared only, THIRD_PARTY.md credit, AGPL), G12 (no X4 bytes/object/per-function list tracked), G107.
- Family 40505e80: 258 siblings, differ by one offset immediate; remap gated 0 of 258 (preflight 39, R1 219); needs parameterised body, not remap. PhaseEnd_Phase1.6.md:16,57.
- Draw: refused 4840 of 7833 (L1 579, L2 4261, L3 0, L4 0), drawn 2993; 3408 open twin clusters, largest 455 (one survivor per cluster, G46). L1 579 wait on lib-unit triple proofs + overlay jtbl carves (overlay yamls have no rodata block). walls.txt and draw_exclude.txt: headers only, empty (phase-1.6/tasks/T9.md:26).

(b) Open carries
- I2 (DISCUSSION_INDEX.md:4, deferred:1.8): 15 exe inter-lib gaps 0x10-0x120 B, each one TU by rule (config/segmentation.md:114 Q2); likely unrecognised/ambiguous PsyQ objects (9 ambiguous_name, 374 ambiguous_plate exe-wide); needs exact PsyQ version pin. Exe TUs 246 = 230 lib + 16 gap (1 game gap 0x800120A0-0x80054AD0 plus 15). Q1/Q3 also open (segmentation.md:112-117). 1.4 PhaseEnd only had R1.4-001 ladder research; no PsyQ pin found in scope.
- P1.7-1: func_80042F20 plateau `regalloc residual 9/12 rows L05,L06,L11,permuter` (base 9 best 9 after 300 its, distinct 301); try G-alloc L05/L06/L11 before more permuter time. Stored draft drafts/SLUS_013.95/func_80042F20.c (non-matching). PhaseEnd_Phase1.7.md:6,48,230.
- BFM leads untried: S1, S2, D5, K3, K4, K7, section 346 (1.7.md:48). inherited.md: 78 rows, 18 re-proven, 60 leads; 15 byte-proven levers (L01-L15, next L16); 89 cookbook entries.
- phaseend_index.py verify harness: must run clauses sequentially and wait for bg clauses before verdict (1.6 and 1.7 carry). 1.6 deviation: reported GREEN 4/4 after only launching bg runs, started fleet+health together and health failed.
- Binding banking rules: bank.py R1-R5 ladder (preflight, pair, R1..R5; body sha1 unchanged since R1; stops restore files and rebuild); shared body = one src/shared file included per member, members differ only by name/address #defines (G106); propagate registry fail-closed, rows incl. family rows, `propagate --check` refuses drift; typecheck: types in include/mmx6/types.h keyed by shape, fleet-gated (G105), planted duplicate refused; declsync + sig rescan inside bank.py; overlay c units need `auto_decompile_empty_functions: false`, whole-overlay c units; overlay corpus names repeat so key (prog,name); `type:func` symbol rows turn data into functions, use name-only; permuter result never a bank (C0062); lever claim needs pin source cite + byte-proven a/b pair (G108); mx.sh sync wipes /work/build, so run extract/build/corpus/census/sig chain first.
- bank.py --self-test fixed in 1.6 T6.1 by planting siblings. Lib TUs still unprobed; jtbl carve refuses on overlays; opt carve unproven on overlays.
- Wall/exclude data: none (empty files); walls row format `<prog> <vram> <pass> <dumpfile>:<line> <quoted line>`, pass from dumps.SUFFIXES + maspsx; draw_exclude staleness audit fails with DRAW STALE rc 2.

(c) 1.7 carry audit (PhaseEnd_Phase1.7.md:105-225)
- Session: 1 session, 780 requests (1.6: 1194); carry/request 2368 chars vs 1346 (+76%, flagged); median 14k seed, ctx at end 73.8k, 86 router requests.
- Flags: 1 whole-plan read (expert-opus55); 24 tool-source reads by coder/expert (permute.py x4, repro.py x5, probe.py x3, codegen_map.py, dumps.py...); 2 whole BFM reads >20k by retriever-digest (regalloc.md 49k, sched.md 33.5k). cookbook-index.md read 7x (83k chars). No retriever re-asks. Tool candidates: a ranged/outline reader for the cookbook index and tool sources; smaller BFM map shards; tools/card.py 152k and tools/plan_edit.py 137k (32 calls) and run.sh 134k (87) dominate result chars.
- Cost per task (agent runs, partial list 36 of 60): expert opus high $0.41-0.97/run, ctx 54-88k; coder opus medium $0.33-1.70/run (typical $0.4-1.4, ctx 39-125k; largest T4 $1.70, T3 $1.39, T5 $1.41); retriever sonnet $0.03-0.29 (ctx 11-56k). Per task roughly 3-8 runs, about $2-6 per task (T3 ~ $5.6, T4 ~ $6.1, T5 ~ $5.8 visible). Prices: read $0.20/Mtok, 1h write $7.51, output $18.77. Warm pings cost $0.22 vs $3.72 rewrites saved. Full ledger: ~/.claude/pa3/pa_ledger.py report (24 more rows).
- Wall clock: fleet ~ minutes+ (36 C units +2 min); tools-health-full ~24 min (1.6 T9); real propagation 12m22s; 1.7 health: 24 rungs. 8 tasks in 1.7; 1.6 had 9 tasks (T6.1 extra).

## Dead ends
- No per-program function table in PhaseEnds; no PsyQ version pin found; docs/segmentation.md is at config/segmentation.md; decomp-environment.md lines 135-138 hold long rows not read.

sources: phase-ends/PhaseEnd_Phase1.6.md, PhaseEnd_Phase1.7.md, phase-ends/phase-1.5/tasks/T6.md, phase-1.6/tasks/T1,T2,T5,T6,T8,T9.md, phase-1.6/logs/T4.md, phase-1.5/logs/T7.c1.md, config/segmentation.md, docs/prior-art.md:28, phase-ends/DISCUSSION_INDEX.md
