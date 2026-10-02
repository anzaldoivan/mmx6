# PhaseEnd — Phase 1.7: The codegen map and the permuter (implements Gen 1.7)
Approved: 2026-10-01 | Closed: 2026-10-02 | Planner: claude-opus-5-5/medium | Tasks: 8 done, 0 superseded

## Milestone
Milestone: ≥1 byte-proven lever per pass group with a symptom-keyed triage table; the compiler source staged at the pinned version, citations audited; the permuter's stored-draft run proves it iterated; the plateau classifier labels its planted plateau; the cookbook index check asserts every entry indexed and every row resolving — verified by: `bash tools/docker/mx.sh build && bash tools/docker/mx.sh sync && bash tools/docker/mx.sh run make toolchain-check` rc 0 with a `GCCSRC 2.95.2 <sha256>` line; then `bash tools/run.sh --bg fleet -- bash tools/docker/mx.sh run make fleet` + `bash tools/run.sh --wait fleet --max 280` (repeat the wait until done) rc 0, last line `FLEET 57 of 57`, the log holds `HARNESS 0 disagreements in <p> pairs`; then `bash tools/run.sh --bg health -- bash tools/docker/mx.sh run make tools-health-full` + `bash tools/run.sh --wait health --max 280` rc 0, last line `TOOLS-HEALTH OK <k> rungs` (k ≥ 22), the log holds `CITES OK <c> of <c> citations` (c ≥ 6), `CITES CONTROL OK`, `DUMPS CONTROL OK`, `ALLOC CONTROL OK`, `REPRO <r> of <r> tells reproduced`, `MAP OK 6 of 6 pass groups; levers <l> byte-proven` (l ≥ 6), `TRIAGE OK <t> rows, 0 TODO`, `COOKBOOK OK <e> entries, <e> rows, 0 orphans, 0 dangling`, `COOKBOOK CONTROL OK`, `PERMUTE CONTROL OK`, `PLATEAU CONTROL OK` (planted plateaus labelled `regalloc` and `sched`), every `<NAME> CONTROL OK`, 0 FAIL; then `bash tools/run.sh --bg perm -- bash tools/docker/mx.sh run python3 tools/mmx6/permute.py --draft drafts/<prog>/<func>.c --iterations 300 --seed 1` + `bash tools/run.sh --wait perm --max 280` rc 0, line `PERMUTE <func> iterations <n> distinct <d> base <b> best <s>` with n ≥ 300, d ≥ 2, s ≤ b, then `bash tools/docker/mx.sh run python3 tools/mmx6/plateau.py --draft drafts/<prog>/<func>.c` → one `PLATEAU <func> <label> …` line; `PY tools/audit_public.py` rc 0. Clauses run one after another, never concurrently.
Verified: milestone clauses in order — m1 `mx.sh build && sync && make toolchain-check` exit 0, `GCCSRC 2.95.2 064e1cb0… patches 3` (.run/logs/m1.log); fleet exit 0, `FLEET 57 of 57`, `HARNESS 0 disagreements in 7 pairs` (.run/logs/fleet.log); tools-health-full exit 0, `TOOLS-HEALTH OK 24 rungs`, `CITES OK 164 of 164 citations`, `CITES CONTROL OK`, `DUMPS CONTROL OK`, `ALLOC CONTROL OK`, `REPRO 30 of 30 tells reproduced`, `MAP OK 6 of 6 pass groups; levers 15 byte-proven`, `TRIAGE OK 16 rows, 0 TODO`, `COOKBOOK OK 89 entries, 89 rows, 0 orphans, 0 dangling`, `COOKBOOK CONTROL OK`, `PERMUTE CONTROL OK`, `PLATEAU CONTROL OK` (.run/logs/health.log); perm exit 0, `PERMUTE func_80042F20 iterations 300 distinct 301 base 9 best 9` (.run/logs/perm.log); plateau rc 0, `PLATEAU func_80042F20 regalloc residual 9/12 rows L05,L06,L11,permuter src draft`; `PY tools/audit_public.py` rc 0

## Tasks
- T1 — compiler source staged and the citation auditor | Done: image holds `/opt/gcc-2.95.2-src` (GNU gcc-2.95.2 + old-gcc @0.17 psx edits), proven to be the pin's source (rebuilt cc1 byte-identical to the installed pin cc1; fleet 57/57 with `CC1=<rebuilt>`); `toolchain-check` prints `GCCSRC`; `gccsrc.py` audits citations, rung `th-cites`. | commit: - | tasks/T1.md | logs/T1.md
- T2 — dump scripts and the pass list reconciled | Done: `dumps.py` writes per-pass cc1 2.95.2 `-da` dumps for a standalone C file or a real TU, spliced from the C rule's own recipe; 120A0's dump-run object is byte-identical to the built one; walls.PASSES = observed suffixes + maspsx (`peephole2`, `stack` gone); rung `th-dumps`. | commit: - | tasks/T2.md | logs/T2.md
- T3 — allocation-table reader and the reproducer runner | Done: `alloc_table.py` prints the per-pseudo allocation table from cc1 2.95.2 `.lreg`/`.greg` with the cited priority formula; `repro.py` runs the reproducer battery and checks lever pairs; two G-alloc a/b pairs; rungs `th-alloc`, `th-repro` (19 rungs). | commit: - | tasks/T3.md | logs/T3.md
- T4 — codegen map, front-end groups (expr, loop, combine) | Done: G-expr, G-loop, G-combine mapped on cc1 2.95.2 with cited pass functions, BFM G67 translation and 4 byte-proven levers (L01-L04, cookbook C0075-C0078); `codegen_map.py` checks rows, levers, cites and triage; rung `th-map`. | commit: - | tasks/T4.md | logs/T4.md
- T5 — codegen map, back-end groups (alloc, sched, jump) and the triage table | Done: G-alloc, G-sched, G-jump mapped on cc1 2.95.2 with BFM G67 translation and 7 new byte-proven levers (L05-L11, C0079-C0085); README triage covers every C0002 tell (12 rows, 0 TODO); C0002 Entries filled; codegen_map.py checks README against C0002; th-map checks all six groups. | commit: - | tasks/T5.md | logs/T5.md
- T6 — cookbook seeded by symptom and the index check | Done: BFM's symptom index mapped onto our 11 tells in `docs/codegen-map/inherited.md` (78 rows, 18 re-proven, 60 lead); 4 BFM leads re-proven as L12-L15 / C0086-C0089; `cookbook_check.py` checks the index; rung `th-cookbook`. | commit: - | tasks/T6.md | logs/T6.md
- T7 — permuter, masked scorer and the stored draft | Done: decomp-permuter pinned in the image and named by toolchain-check; `permute.py` builds the permuter dir, binds the masked scorer by a shim (upstream unedited), enforces DK-15 guards, self-test `PERMUTE CONTROL OK`; stored draft `drafts/SLUS_013.95/func_80042F20.c` (non-matching); real 300-iteration run green; rung th-permute. | commit: - | tasks/T7.md | logs/T7.md

## Decisions that still bind
- T1 — gcc source for citations = `/opt/gcc-2.95.2-src` in the image, pinned by Makefile `GCCSRC_SHA` (tarball 064e1cb0…) and `GCCSRC_TREE` (8d8a1a5b…); a Dockerfile change to the stage and the pins change together; never in git.
- T1 — citation format `src:gcc-2.95.2/<path>:<line> "<fragment ≤80 chars, no \">"`, line 1-based, fragment a verbatim substring of that line (latin-1 decode); audited by `gccsrc.py --check` over docs/codegen-map/*.md + cookbook/C*.md.
- T2 — dumps never re-type flags: dumps.py takes the `cpp | cc1 | maspsx | as` line of `make -s -n -B build/<c>.o` and runs each stage (rc checked), cc1 + `-da -dumpbase <base>` in `build/dumps/<key>/`; target-specific `CFLAGS_<tu>` and overlay `-DMMX6_OVERLAY` ride along (proven: CFLAGS=-XPROBE override reaches 120A0, not 32208).
- T2 — `dumps.SUFFIXES` is the single cc1 pass-name list; `walls.PASSES` imports it (+ maspsx). A wall's pass must be one of: rtl jump cse addressof gcse loop cse2 bp flow combine regmove sched lreg greg flow2 sched2 jump2 mach dbr maspsx.
- T3 — alloc row `<pseudo> refs <r> live <l> block <b|-> pref <h[,h]|-> prio <p> hard <h|->`; pref = greg `;; P preferences:` hard regs; hard = greg `;; Register dispositions:`; per function `ALLOC <key>:<func> pseudos <n> order <k>` (key gains `:<func>`, a dump holds many functions).
- T3 — prio = global.c's `int(((floor_log2(refs)*refs)/live)*10000*size)`, tie → lower allocno; local-alloc uses the same shape over birth..death (local-alloc.c:1512), not printed in any dump.
- T3 — reproducer header `// tell:`, `// pass:`, `// expect:` (re.M over the object's disassembly, one `<mnem> <ops>` line per insn, numeric regs), optional `// dump:` (verbatim fragment in `<base>.<pass>`; maspsx → `<base>.s`), `// func:`; pair `.a.c` carries `// diff: regs $A $B | order | branch | isel | length <d>`.
- T4 — pass groups (codegen_map.py GROUPS) G-expr rtl cse addressof gcse cse2 · G-loop loop · G-combine combine regmove · G-alloc lreg greg flow flow2 · G-sched sched sched2 mach dbr maspsx · G-jump jump jump2; bp none.
- T4 — symptom vocabulary = a bare `sym-<slug>` ending each C0002 tell cell and each README triage tell; a lever's cookbook tag uses the same slug. Slugs so far: spill-slot, register-pressure, load-below-store, phantom-callee-saved, shift-x4, branch-arms-swapped, cross-jump, global-reload, loop-reversed, narrow-load.
- T4 — lever ids global across docs/codegen-map/*.md, next free L05; a row with a failing `repro.py --lever` is not entered.
- T5 — a triage row's levers cell is L ids of its group or exactly `→ permuter` (intrinsic); C0002 Entries is C ids resolving to cookbook files or `→ permuter`; every C0002 `sym-<slug>` needs ≥1 README triage row (codegen_map.py enforces).
- T6 — cookbook_check.py rules: one INDEX row per `cookbook/C*.md`, same id and title; every row resolves; an entry tagged `idiom` (row or file tags) carries ≥1 `sym-<slug>` from C0002's tell column; C0002 has no `TODO`. Tokens `COOKBOOK ORPHAN|DANGLING|DUP|TITLE|NOSYMPTOM|TODO <id>` rc 1.
- T6 — inherited.md status = `re-proven C<nnnn>` only for an exact match of a byte-proven lever; an "adjacent" match stays `lead`.
- T7 — masked score = mismatches of `probe.elf_function` words vs `probe.retail_words` under probe's MASKS + R_MIPS_PC16 low 16, + |length diff|; R_MIPS_26 to the function's own section compared relative to function start. Score 0 iff probe's compare MATCH; never a bank (C0062): printed `PERMUTE CANDIDATE … (not banked)`.
- T7 — scorer bound by monkeypatch (`src.scorer.Scorer` before `import src.main`, `src.main.Scorer` after); `git -C /opt/decomp-permuter status --porcelain` asserted empty.
- T7 — iterations = upstream `iteration N` lines (\b/\r-written), child killed by pid at N ≥ requested; distinct = unique sha256 in `<permdir>/sources.log` (base included); `--seed 0` refused (upstream treats 0 as unseeded); -j1.
- T7 — pins hidden by wrapping in `PERM_IGNORE(...)`, restored byte-exact (asserted); K&R seed → `PERMUTE REFUSED K&R <func>` rc≠0; refused or zero-iteration cycle rc≠0.
- T8 — plateau label rules, first that holds: none (m=0) · length · isel (multiset of opcode keys, conditional-branch polarity folded, differs) · sched (sequence differs, no polarity flip) · regalloc (same sequence, residual words differ only in register fields, or $sp load/store offset = spill slot) · branch (a polarity flip, or residual confined to conditional branches / internal j) · else isel.
- T8 — residual m = masked_scorer score (mismatches + |length diff|), n = retail words; line `PLATEAU <func> <label> residual <m>/<n> rows <ids> src <draft|permuted|plant-…>`.
- T8 — label → groups: length → G-expr G-combine G-loop G-jump; isel → G-expr G-combine; sched → G-sched; regalloc → G-alloc; branch → G-jump; rows = README `## Triage` levers cells of those groups in table order (`→ permuter` printed `permuter`).
- norm: a codegen claim cites the staged pin source in the audited format and carries a byte-proven a/b pair; inherited idioms are leads until both hold → rule G108 (T1, T3-T6).
- environment: gcc source `/opt/gcc-2.95.2-src` pinned by Makefile `GCCSRC_SHA`/`GCCSRC_TREE`, Dockerfile stage and pins change together → docs/ops/compiler-pin.md `## Source`, docs/ops/mmx6-hosts.md (T1).
- environment: decomp-permuter @059609d, upstream unedited, scorer bound by shim → docs/ops/mmx6-hosts.md, docs/ops/decomp-environment.md (T7).
- contract: citation format and audit (`gccsrc.py --check` over docs/codegen-map/ and cookbook/) → docs/ops/decomp-environment.md + th-cites (T1).
- contract: dumps splice `make -s -n -B` recipe; `dumps.SUFFIXES` is the one pass list, `walls.PASSES` imports it → docs/ops/decomp-environment.md + th-dumps (T2).
- contract: alloc row format and global.c priority formula; reproducer header (`tell/pass/expect/dump/func/diff`) → docs/ops/decomp-environment.md, docs/codegen-map/G-alloc.md + th-alloc, th-repro (T3).
- contract: six pass groups, `sym-<slug>` vocabulary, global lever ids (next free L16), triage levers cell = L ids or `→ permuter` → docs/codegen-map/README.md, cookbook/C0002.md + th-map (T4, T5).
- contract: cookbook index rules (one row per file, idiom entries carry a slug, C0002 no TODO); inherited.md `re-proven` only on exact lever match → docs/ops/decomp-environment.md, docs/codegen-map/inherited.md + th-cookbook (T6).
- contract: masked score, iteration/distinct counting, pin hide/restore, K&R refusal, seed 0 refused → docs/ops/decomp-environment.md + th-permute (T7).
- contract: plateau label order and label-to-group routing, `PLATEAU` line shape → docs/ops/decomp-environment.md + th-plateau (T8).
- scope: Next task needs: func_80042F20 plateau `regalloc` → try G-alloc L05/L06/L11 before more permuter time; BFM leads untried (S1, S2, D5, K3, K4, K7, §346) stay leads for 1.8.
- scope: Next task needs: carried from 1.6, mmx4's 2042 exact X4 partners as a bank source and family 40505e80 → 1.8 campaign.
- scope: Next task needs: `phaseend_index.py verify` must run clauses sequentially and wait for background clauses before a verdict (harness fix for the auditor).

## Rules proposed
- (none)

## Cookbook entries added
C0075 | Global reloaded after *p= but kept after p[k]=/p->f= (cse /s aliasing) | idiom,sym-global-reload,G-expr,cse,aliasing,reload | 2026-10-01 | 1.7/T4 | mmx6 repro
C0076 | &local cached in $s0 via a named pointer vs per-site addiu (call args) | idiom,sym-phantom-callee-saved,G-expr,rtl,callee-saved,address | 2026-10-01 | 1.7/T4 | mmx6 repro
C0077 | Up-count loop reversed to bgez; write the down-count for bgtz/bne | idiom,sym-loop-reversed,G-loop,loop,dbra,branch | 2026-10-01 | 1.7/T4 | mmx6 repro
C0078 | lw+andi 0xff vs lbu: combine merges the mask only if the word dies | idiom,sym-narrow-load,G-combine,combine,lbu,mask | 2026-10-01 | 1.7/T4 | mmx6 repro
C0079 | $16/$17 swapped at equal priority: declaration order breaks the global-alloc tie | idiom,sym-sreg-swapped,G-alloc,greg,regalloc,decl-order | 2026-10-02 | 1.7/T5 | mmx6 repro
C0080 | $16/$17 swapped by ref count: global-alloc density floor_log2(refs)*refs/live | idiom,sym-sreg-swapped,G-alloc,greg,regalloc,refs | 2026-10-02 | 1.7/T5 | mmx6 repro
C0081 | Load held below *p= but hoisted above p->f= (sched /s aliasing) | idiom,sym-load-below-store,G-sched,sched,aliasing,order | 2026-10-02 | 1.7/T5 | mmx6 repro
C0082 | beqz vs bnez: the if arm falls through; invert the condition and swap arms | idiom,sym-branch-arms-swapped,G-jump,jump,polarity,branch | 2026-10-02 | 1.7/T5 | mmx6 repro
C0083 | Cross-jump: a fall-through arm ending in a call never merges; a store tail merges the call | idiom,sym-cross-jump,G-jump,jump2,cross-jump,call | 2026-10-02 | 1.7/T5 | mmx6 repro
C0084 | Index sll 2 vs none: p[i] on int * scales, a char * byte offset does not | idiom,sym-shift-x4,G-expr,rtl,pointer,shift | 2026-10-02 | 1.7/T5 | mmx6 repro
C0085 | Spill slots swapped: reload assigns slots in pseudo (declaration) order | idiom,sym-spill-slot,G-alloc,greg,spill,decl-order | 2026-10-02 | 1.7/T5 | mmx6 repro
C0086 | Struct base reloaded per member store: name the pointer-derived base in a local | idiom,sym-global-reload,G-expr,cse,alias,struct | 2026-10-02 | 1.7/T6 | BFM §193-H re-proven
C0087 | Loop guard: while copies its exit test as the guard; a written guard + do-while keeps yours | idiom,sym-loop-reversed,G-jump,jump,loop,guard | 2026-10-02 | 1.7/T6 | BFM §279 re-proven
C0088 | lhu vs lh on a masked short: & in the expression is shortened; an int temp keeps lh | idiom,sym-narrow-load,G-expr,rtl,shorten,short | 2026-10-02 | 1.7/T6 | BFM §329 re-proven
C0089 | Volatile short read: lhu + sll/sra instead of lh (combine skips volatile) | idiom,sym-narrow-load,G-combine,combine,volatile,short | 2026-10-02 | 1.7/T6 | BFM §345 re-proven
C0090 | A release archive's sha256 is not its binary's; prove a binary by the extracted file | pin,hash,toolchain,provenance | 2026-10-02 | 1.7/T1 | mmx6 T1
C0091 | decompals/old-gcc releases rebuild bit-identical from the tag's Dockerfile on a pinned focal base | toolchain,provenance,gcc,docker,pin | 2026-10-02 | 1.7/T1 | mmx6 T1
C0092 | Target-specific make vars are invisible to other targets: splice make -n -B's recipe line | make,toolchain,flags,dumps | 2026-10-02 | 1.7/T2 | mmx6 T2
C0093 | Prove an instrumented compile matches the build by diffing .text bytes, not RTL insn counts | toolchain,dumps,control,gcc | 2026-10-02 | 1.7/T2 | mmx6 T2
C0094 | Line-numbered citations into C sources: split on \n only, never str.splitlines() | python,citations,gcc,self-test | 2026-10-02 | 1.7/T3 | mmx6 T3
C0095 | Allocation-order reproducers must keep values live across a block boundary | gcc,greg,regalloc,reproducer | 2026-10-02 | 1.7/T3 | mmx6 T3
C0096 | Pipe-delimited rows break on citation fragments containing a pipe | docs,format,citations | 2026-10-02 | 1.7/T4 | mmx6 T4
C0097 | The same C idiom can move pass between gcc versions: re-prove, never port the citation | gcc,G67,citations,porting | 2026-10-02 | 1.7/T4 | mmx6 T4
C0098 | A spill-slot swap lever cannot be a pure order diff: declare a length 0 diff | reproducer,spill,G-alloc,diff | 2026-10-02 | 1.7/T5 | mmx6 T5
C0099 | Inherited gcc 2.7.2 idioms often go byte-identical under 2.95.2: reproduce before entering | gcc,porting,BFM,reproducer | 2026-10-02 | 1.7/T6 | mmx6 T6
C0100 | decomp-permuter --seed random-walks one candidate; seed 0 means unseeded | permuter,seed,random | 2026-10-02 | 1.7/T7 | mmx6 T7
C0101 | decomp-permuter writes its iteration status with \b/\r: split on \r and \n to count | permuter,parsing,iterations | 2026-10-02 | 1.7/T7 | mmx6 T7
C0102 | Stock permuter objdump scorer never reaches 0 on a relocated function: mask relocations both sides | permuter,relocation,scorer,masking | 2026-10-02 | 1.7/T7 | mmx6 T7

## Research
R1.7-001 | what the inherited record says about building each Phase 1.7 piece | Phase 1.7 inherited record: codegen map, dumps, alloc table, battery, masked permuter, plateau classifier, cookbook index | phase-1.7, codegen-map, permuter, plateau, cookbook-index, dumps, G67 | retriever-digest | 2026-10-01 | 85 lines
R1.7-002 | Phase 1.7 plan, mmx6 gcc2.95.2-psx + aspsx via maspsx | gcc 2.95.2 source, PSX patches, decomp-permuter CLI, plateau notion | gcc-2.95.2, psx, permuter, old-gcc | retriever-web | 2026-10-01 | 37 lines
R1.7-003 | list BFM levers (tell/mechanism/C lever/proof/version) from cse_expr.md and loop.md for T4 G-expr, G-loop, G-combine rows | BFM gcc-2.7.2 map levers: expr/cse, loop, combine | bfm, gcc-2.7.2, cse, loop, combine, codegen-map, T4 | retriever-digest | 2026-10-01 | 50 lines
R1.7-004 | T5 | BFM gcc-2.7.2 regalloc/sched/dbr levers for T5 G-alloc, G-sched, G-jump rows | bfm,gcc-2.7.2,regalloc,sched,dbr,jump,codegen-map,T5 | retriever-digest | 2026-10-02 | 18 lines
R1.7-005 | T6 inherited.md; map BFM symptom index to 11 slugs, candidate new idioms, DC2/mmx4 absence | BFM cookbook symptom index mapped onto mmx6 triage tells | bfm, cookbook-index, triage, inherited, gcc-2.7.2, codegen-map | retriever-digest | 2026-10-02 | 125 lines

## Audit
- seed: median 14k, max 14k, n=9 (phase 1.7)
- previous phase 1.6: median 15k, growth -3.3%
- CLAUDE.md: 1242 bytes (unchanged)
- .claude/skills/ci-wait-after-push/SKILL.md: 799 bytes (unchanged)
- .claude/skills/container-scratch-not-synced/SKILL.md: 1586 bytes (+461)
- .claude/skills/docker-vm-no-privileged/SKILL.md: 774 bytes (unchanged)
- .claude/skills/project-architect/SKILL.md: 13448 bytes (unchanged)
- .claude/skills/typecheck-fnptr-keyer-first/SKILL.md: 1093 bytes (unchanged)
- .claude-state/memory/MEMORY.md: 214 bytes (unchanged)
- HOW_WE_WORK.md: 7005 bytes
- cookbook/INDEX.md: 16360 bytes
- rules/INDEX.md: 11147 bytes
### Carry audit — phase 1.7 (2026-10-02T01:50:45Z → open UTC, 1 sessions, 780 requests)

| file (read) | chars | n |
|---|---|---|
| cookbook-index.md | 83.1k | 7 |
| regalloc.md | 50.0k | 1 |
| sched.md | 34.5k | 1 |
| cse_expr.md | 30.5k | 2 |
| permute.py | 28.3k | 3 |
| loop.md | 26.3k | 2 |
| repro.py | 21.1k | 4 |
| decomp-environment.md | 19.4k | 2 |
| codegen_map.py | 17.0k | 2 |
| dumps.py | 16.0k | 2 |
| file (write) | chars | n |
|---|---|---|
| repro.py | 14.7k | 1 |
| retriever-digest-t6-bfm-symptom-map.md | 13.9k | 1 |
| permute.py | 13.7k | 3 |
| bfm-rows.md | 11.9k | 1 |
| alloc_table.py | 11.5k | 1 |
| plateau.py | 11.2k | 2 |
| codegen_map.py | 9.7k | 1 |
| dumps.py | 9.0k | 4 |
| result kind | chars | n |
|---|---|---|
| bash other | 735.5k | 331 |
| Read | 522.9k | 79 |
| tools/card.py | 152.4k | 14 |
| tools/plan_edit.py | 136.7k | 32 |
| run.sh | 133.6k | 87 |
| tools/cookbook_add.sh | 34.0k | 12 |
| Agent | 27.5k | 26 |
| tools/task_log.py | 15.7k | 11 |
| tools/status.py | 14.7k | 10 |
| tools/audit_public.py | 13.1k | 23 |
- whole reads over 20.0k: 2
- seed floor: retriever-code 5,622 (n 1, prev 5,376) · retriever-digest 5,621 (n 4, prev 5,273) · retriever-web 3,816 (n 1, prev 3,702)
- outline credit: 2 outlines · 1 followed by a ranged read · 0 chars credited
- warm pings: 17 pings over 8 runs, 11 warmed waits over the TTL, rewrites across warmed waits 0, waits past the cap 0, pings cost $0.2234 vs rewrites replaced $3.7198, cheaper than one rewrite: yes
- toasts by cause (waiting): question 0, review 0, replan 0, permission 0, input 0, discussion 0, crash 0, idle 0, stop 0, subagent-stop 0, model 0, other 0
- router turns by cause: loop 9, relay 17, re-arm 8, other 0, relay cost $0.4528
- retriever re-asks: 0 of 3 retriever briefs repeat a lookup of the same run
- router: pa-session 832f9bc5 · requests 86 · ctx at end 73.8k · growth T1 +2.8k, T2 +2.9k, T3 +1.5k, T4 +1.6k, T5 +2.5k, T6 +1.8k, T7 +5.8k, T8 +1.6k · top: tools/status.py 14.7k/10, Agent 9.5k/9, tools/plan_edit.py 7.7k/10, other 5.4k/26
- noise: 144 lines 10.1k chars — usage: : 87 lines/6.4k, No such file or directory: 57 lines/3.7k
- price: read $0.20/Mtok · 1h write $7.51/Mtok · output $18.77/Mtok (phase model mix)
- median requests after a read: 3
- carry/request: 2368 chars, 780 requests (prev 1346 chars, 1194 requests, growth 75.9%)
- flag: carry per request grew 76% vs 1.6
- flag: 1 whole-plan reads by expert-opus55
- flag: 24 tool-source reads by coder-opus55, expert-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/permute.py  14.2k chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/permuter/compile.sh  1.4k chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/probe.py  570 chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/repro.py  3.1k chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/repro.py  2.0k chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/permuter/masked_scorer.py  4.8k chars  expert-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/gccsrc.py  549 chars  expert-opus55
  /Users/ThinkPad/orca/mmx6/tools/docker/Dockerfile  4.5k chars  expert-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/toolchain_check.sh  2.9k chars  expert-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/probe.py  2.9k chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/probe.py  4.6k chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/dumps.py  8.0k chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/alloc_table.py  393 chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/repro.py  13.2k chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/codegen_map.py  2.3k chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/walls.py  3.1k chars  expert-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/dumps.py  8.0k chars  expert-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/walls.py  391 chars  expert-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/codegen_map.py  14.7k chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/repro.py  2.9k chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/.claude/skills/container-sync-wipes-build/SKILL.md  442 chars  expert-opus55
  /Users/ThinkPad/orca/mmx6/.claude/skills/container-scratch-not-synced/SKILL.md  1.2k chars  expert-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/permute.py  13.1k chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/permute.py  955 chars  expert-opus55
- flag: 2 whole reads over 20.0k by retriever-digest
  file: /Users/ThinkPad/orca/BFM-decomp/decomp-architect/corpus/cookbook/gcc-2.7.2-map/regalloc.md  role: retriever-digest  chars: 49.0k
  file: /Users/ThinkPad/orca/BFM-decomp/decomp-architect/corpus/cookbook/gcc-2.7.2-map/sched.md  role: retriever-digest  chars: 33.5k

## Agent runs
- T1 | expert-opus55 | expert | claude-opus-5-5 | high | ctx 83k | $0.664 | saved $0.63 | completed | parent 832f9bc5
- T1 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 56k | $0.569 | saved $1.60 | completed | parent a584978a
- T1 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 39k | $0.328 | saved - | completed | parent a584978a
- T1 | expert-opus55 | expert | claude-opus-5-5 | high | ctx 54k | $0.520 | saved - | completed | parent 4218494a
- T1 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 61k | $0.873 | saved - | completed | parent ae8de235
- T2 | expert-opus55 | expert | claude-opus-5-5 | high | ctx 75k | $0.643 | saved $0.52 | completed | parent 832f9bc5
- T2 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 60k | $0.645 | saved $0.44 | completed | parent a6478909
- T3 | expert-opus55 | expert | claude-opus-5-5 | high | ctx 81k | $0.798 | saved - | completed | parent 832f9bc5
- T3 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 69k | $0.702 | saved $0.59 | completed | parent a562a3c3
- T2 | expert-opus55 | expert | claude-opus-5-5 | high | ctx 56k | $0.413 | saved - | completed | parent 4218494a
- T2 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 54k | $0.499 | saved - | completed | parent a86024ab
- T3 | expert-opus55 | expert | claude-opus-5-5 | high | ctx 80k | $0.811 | saved $0.15 | completed | parent 4218494a
- T3 | retriever-code | retriever | claude-sonnet-5-5 | medium | ctx 56k | $0.289 | saved - | completed | parent a51efb79
- T3 | retriever-digest | retriever | claude-sonnet-5-5 | medium | ctx 41k | $0.188 | saved - | completed | parent a51efb79
- T3 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 72k | $0.702 | saved $0.39 | completed | parent a562a3c3
- T3 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 115k | $1.394 | saved - | completed | parent a51efb79
- T3 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 70k | $0.675 | saved $0.12 | completed | parent a51efb79
- T4 | expert-opus55 | expert | claude-opus-5-5 | high | ctx 86k | $0.837 | saved $0.06 | completed | parent 832f9bc5
- T4 | retriever-digest | retriever | claude-sonnet-5-5 | medium | ctx 43k | $0.173 | saved - | completed | parent a49d5592
- T4 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 49k | $0.427 | saved - | completed | parent a49d5592
- T4 | expert-opus55 | expert | claude-opus-5-5 | high | ctx 79k | $0.823 | saved $0.04 | completed | parent 4218494a
- T4 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 90k | $1.029 | saved - | completed | parent a49d5592
- T4 | retriever-digest | retriever | claude-sonnet-5-5 | medium | ctx 15k | $0.047 | saved - | completed | parent ab6dfd15
- T4 | retriever-digest | retriever | claude-sonnet-5-5 | medium | ctx 45k | $0.241 | saved - | completed | parent ab6dfd15
- T4 | retriever-code | retriever | claude-sonnet-5-5 | medium | ctx 44k | $0.255 | saved - | completed | parent ab6dfd15
- T4 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 125k | $1.700 | saved - | completed | parent ab6dfd15
- T4 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 81k | $0.887 | saved - | completed | parent ab6dfd15
- T4 | retriever-code | retriever | claude-sonnet-5-5 | medium | ctx 11k | $0.027 | saved - | completed | parent ac0be351
- T5 | expert-opus55 | expert | claude-opus-5-5 | high | ctx 82k | $0.720 | saved - | completed | parent 832f9bc5
- T5 | retriever-digest | retriever | claude-sonnet-5-5 | medium | ctx 46k | $0.135 | saved - | completed | parent a21c0774
- T5 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 111k | $1.147 | saved - | completed | parent a21c0774
- T5 | expert-opus55 | expert | claude-opus-5-5 | high | ctx 88k | $0.965 | saved - | completed | parent 4218494a
- T5 | retriever-digest | retriever | claude-sonnet-5-5 | medium | ctx 54k | $0.261 | saved - | completed | parent a1d05181
- T5 | retriever-digest | retriever | claude-sonnet-5-5 | medium | ctx 47k | $0.280 | saved - | completed | parent a1d05181
- T5 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 88k | $1.046 | saved - | completed | parent a1d05181
- T5 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 110k | $1.412 | saved - | completed | parent a1d05181
- T5 | retriever-code | retriever | claude-sonnet-5-5 | medium | ctx 13k | $0.048 | saved - | completed | parent a1946ad0
- T5 | retriever-code | retriever | claude-sonnet-5-5 | medium | ctx 11k | $0.025 | saved - | completed | parent ad008491
- T5 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 75k | $0.727 | saved - | completed | parent a21c0774
- … 24 more: PY ~/.claude/pa3/pa_ledger.py report

## Discussions
- (none)

## Deferred
- from T8: plateau rows for func_80042F20 → G-alloc L05/L06/L11 or the permuter; tools-health fleet 23 rungs, full 24. (unconsumed)

## Changes
- 2026-10-01 router: T1 next -> done
- 2026-10-01 router: T2 next -> done
- 2026-10-01 router: T3 next -> done
- 2026-10-02 router: T4 next -> done
- 2026-10-02 router: T5 next -> done
- 2026-10-02 router: T6 next -> done
- 2026-10-02 router: T7 next -> done
- 2026-10-02 router: T8 next -> done

## Plain-English Recap
Phase 1.7 built the workbench for the hard part of matching: understanding why the pinned compiler (cc1 from gcc 2.95.2 with Sony's PlayStation patches) produces the exact code it does, and what C change steers it. The phase staged that compiler's real source inside the build image, proved it is the source of our compiler by rebuilding a byte-identical cc1, and added an auditor that checks every source citation ("file:line plus quoted fragment") against it; 164 citations now pass. It added tools that dump the compiler's internal stages ("passes") for any file, print the register-allocation table the allocator used, and run small paired C files ("reproducers": an a/b pair whose machine code differs exactly as a written claim says). With these it wrote a "codegen map" of six pass groups (expression, loop, combine, allocation, scheduling, jump), each with byte-proven "levers" (a C change that reliably moves the output, proven by its reproducer pair): 15 levers in all, a triage table of 16 rows that goes from a visible symptom to the levers to try, and a cookbook check that every technique entry is indexed and findable. Finally it pinned the open-source decomp-permuter (a tool that tries random C rewrites and scores each against the original bytes), proved it really iterates (300 iterations on a stored non-matching draft), and added a classifier that labels a stuck draft's leftover difference ("plateau") as register allocation, scheduling, branch, instruction choice or length and names the triage rows to try.

Milestone re-verified clause by clause, one after another, in this session: toolchain-check exit 0 with `GCCSRC 2.95.2 064e1cb0… patches 3` and `PERMUTER 059609d4…` (.run/logs/pe-m1.log); fleet exit 0, last line `FLEET 57 of 57`, `HARNESS 0 disagreements in 7 pairs` (.run/logs/pe-fleet.log); tools-health-full exit 0, last line `TOOLS-HEALTH OK 24 rungs`, with `CITES OK 164 of 164 citations`, `CITES CONTROL OK`, `DUMPS CONTROL OK`, `ALLOC CONTROL OK`, `REPRO 30 of 30 tells reproduced`, `MAP OK 6 of 6 pass groups; levers 15 byte-proven`, `TRIAGE OK 16 rows, 0 TODO`, `COOKBOOK OK 89 entries, 89 rows, 0 orphans, 0 dangling`, `COOKBOOK CONTROL OK`, `PERMUTE CONTROL OK`, `PLATEAU CONTROL OK` and 25 distinct `<NAME> CONTROL OK` lines (.run/logs/pe-health.log); permuter exit 0, `PERMUTE func_80042F20 iterations 300 distinct 301 base 9 best 9` (.run/logs/pe-perm.log); plateau rc 0, one line `PLATEAU func_80042F20 regalloc residual 9/12 rows L05,L06,L11,permuter src draft` (.run/logs/pe-plateau.log); `audit_public.py` rc 0 (.run/logs/pe-audit.log). After the closer's cookbook promotion the index check reads `COOKBOOK OK 102 entries, 102 rows, 0 orphans, 0 dangling`.

On "0 FAIL": the health log holds 58 lines containing `FAIL`; each was read and every one is planted-control output inside a `--self-test` (boundcheck, repro, map, probe-ladder mutation, alloc, dumps, cookbook, plateau) whose `CONTROL OK` follows; no rung failed (every rung rc 0, make exit 0). Same reading as T8.

Deviation (harness): `phaseend_index.py verify` was not run; in 1.6 it launched the background clauses concurrently and reported green before they finished, and this milestone requires clauses one after another. Each clause was run through `run.sh` by hand with `--wait --max 250` (280 overruns the tool-call cap, T8 gotcha).

H7 check: every summary that names tools, pins, Dockerfile, Makefile or mk/ rungs (T1-T8) also lists docs/ops/ or HOW_WE_WORK.md; no miss.
