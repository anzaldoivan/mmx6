# Phase 1.3 planning inputs: gate definitions, rules, 1.2 findings
task: extract definitions, rules, and 1.2/1.1 findings bearing on the all-assembly byte-identical baseline
agent: retriever-digest
tags: phase-1.3, splat, fleet-check, segmentation, boundaries

## Answer
See findings. Key gap: several named terms have no standalone definition in the files named (see Dead ends).

## Findings
(a) PROJECT_CONTEXT.md
- :176-177 pipeline: "splat configs per binary, the Makefile pipeline (preprocessor -> vintage cc1 -> assembler shim -> binutils -> objcopy -> hash check), translation units at the forced boundaries."
- :200 1.3 row: "Makefile pipeline, split configs, per-binary contracts, assembler shim | 1.3 | The byte-identical all-assembly baseline, hash check inside `make build`".
- :278-279 clean fleet check: "whole-binary hash per binary inside `make build`; the clean fleet check (`clean -> extract -> build` over every onboarded binary) prints N of N."
- :241 Makefile: "build -> hash check inside; expected; format; health". :247 `expected/` = "`make expected` baseline (gitignored)". :248 build/ gitignored, build/tools-health.mk tracked (built 1.5, :202).
- :235-236 "Phase 1.3 pins the exact layout"; :268 config/*.yaml one splat config per binary, config/symbols*.txt each name with basis (G62). :261-262 build runs on amd64 Docker (splat, vintage cc1, assembler shim, binutils, Make); source in named volume. :272 toolchain triple TODO until 1.4.
- :216 G3,G61 byte gate only claim; G4 no unmatched C in default build. :213 asm/ generated, gitignored (:245).
- :536-537 segmentation decision goes to /discuss max (or split until routine).
- :532 recomp's "59 members, three bases" is a lead, not input.
- decomp-architect.md s2 :82-86 "hash check lives inside every build, so there is no third state between identical and failed"; :95 whole-binary rebuild is blind to "a stale output file; an incremental linker script"; :97-100 G9, G42. s6 :210-213 file placement incl. "a boundary the split drew wrongly", jump-table carves; :222-224 "a newly discovered binary is not real until every consumer knows it (G7)", carve state per binary (G43).
- docs/ops/decomp-environment.md:31-32 fleet command is TODO(phase-3) (fill it in 1.3); :35-37 "binary green only when its hash check inside `make build` passes; verified from a CLEAN rebuild; executable gated only by clean rebuild; build verified by exit code". :10 toolchain triple TODO; assembler compat version always passed explicitly. docs/ops/mmx6-hosts.md:34 splat/binutils/shim install TODO (this phase pins).
- docs/ops/decomp-environment.md:59 segmentation decision is `/discuss max`.
- Not defined anywhere in the named files: "per-binary contracts", "assembler shim" (beyond :200/:261), "cc1 slot", "health target" semantic, "boundary check" in health. 1.3 must define them.

Rules
- G9 (rules/G9.md): byte-match verified from clean rebuild (clean->extract->build); reverted config needs re-extract; build verified by exit code, not output file.
- G42: whole fleet rebuilt clean on a schedule and after every propagating gate; baseline checked first.
- G62: names/types evidence-based; symbols files need a basis; no raw address casts at bank time.
- G3/G4/G61: whole-binary hash is the claim; no unmatched C in default build.
- DK-12 (docs/decomp-kernels.md:165-173): set unit boundaries at forced boundaries (jump-table spans, per-file opt levels, interleaved library objects) at segmentation time; "split where the BUILD forces it and nowhere else"; cost grows monotonically (:176-178).
- G43 carve state per binary; G7 new binary known to every consumer; G12 firewall (asm/, expected/ never tracked). No G-rule on "contracts" beyond these; Phase 1.9 owns the "contract script".

(b) docs: wave-playbook.md:10,20 only say "last clean fleet run green"/"clean rebuild of everything, read exit code". tools-manifest.md (kit tools, reference only, not mmx6 scripts): split_indicator.py:43, gen_lib_subsegs.py:62 (multi-block vendor lib subsegs), psyq_integrate.py:73 (real lib objects replacing stub subsegments), mk_write.py:74 (safe writer of generated binary-registry makefile), jr_isolate_all.py:145 (multi-cut resegment isolating switch functions), interleave_check.py:127, r22_verify.sh:291 (exclusive clean-tree fleet verify), compile_only.py:303. No kit doc specifies check.*.sha format or Makefile shape; no fleet-check script name for mmx6 (decomp-environment.md:32 TODO). docs/README.md has nothing on these.
- A hook denies reading kit tool sources (T8 gotcha) though plan Context says consult them.

(c) 1.2/1.1
- Members: 59 in ROCK_X6.BIN (T2: TOC of 59 {sector,size}); none compressed, extract is identity (T3); stored total 1,606,492 B; sizes >=4; 8 sizes not %4 (RAM gets <=3 zero pad bytes past size); 41,42 are 4 B (id word only). Extract path extracted/retail/rock/NN.bin; manifest/retail.jsonl 68 lines (9 iso + 59 rock); manifest sha1 262452fe....
- Classes (T6): code 56, data 1 (member 13), empty 2 (41,42); N = 1 + 56 = 57 (exe SLUS_013.95 + 56 code overlays). Binding: code = `addiu sp,sp,-N` prologue + `jr ra` + a base; empty = size<=4.
- Bases (T6, config/loadmap.txt): 0x801EA000 -> members 0,1 (2); 0x800E9860 (word at 0x80010000) -> 2..32 (31 members, 30 code + data 13); 0x800FA000 -> 33..40, 43..45, 46..58 (24). So up to 31 overlays share one base; they cannot coexist, so each needs its own splat vram/segment name and own link. No member has two bases. Static-only bases (no runtime proof): 1, 33..40, 43..45.
- Overlays: raw, no headers, load at base; leading u32 is an id-like word (index+2 for 2-12, index+1 for 14-58). T7: sig_functions=0 for all 56 overlays (no PsyQ code matched); Ghidra overlay programs are image base set via PrepareOverlay.java.
- Boundaries (T8): config/boundaries.txt 804 rows (jtbl/lib/optcand/fstart). 57 programs: 224 jtbl dispatch sites, 212 both, scan-only 12, ghidra-only 219 (label-inside-scan-table; rock_02/10/31 73 each); 48 hi mismatches; extent = sltiu bound, 222 of 224 (2 by consecutive code pointer words). exe: jtbl 41 both/6 scan of 47, lib 235 objects covering 828/1343 funcs (4 overlapping spans), fstart 90, optcand 0/1343. Overlays: only 4 lib rows, all weak `VM_VIB.OBJ` (32-byte sig) = weak evidence, do not split on them. optcand 0/1815: opt level is not a forced-boundary signal. Twin libs (LIBCD/LIBDS) ambiguous, not emitted. fstart rows: jal targets with no Ghidra start; 0x80017e98, 0x80027aa8, 0x80027ba0 (jal only from overlays) candidate starts.
- Data-in-code: jump tables live in .rodata-like islands inside the text; per DK-12 group contiguous spans per function. rock_02/10 have 82/93 switchdata labels (one big table); treat labels inside a byte-bounded table as one table. exe .data/.rodata/.bss layout and gp are NOT covered in T6-T8 or memory-map greps (no gp/.bss hits): 1.3 must derive them (PS-X EXE header fields).
- Gotchas: `plan_edit.py show --section milestone` refused (T5-T8, none exist); Mac has no MIPS objdump (use container; raw objdump with --adjust-vma=load-0x800 for PS-X EXE, keep listing under .run/); `mx.sh sync` wipes /work except .run (including container-side extracted/, so extract+use in one `mx.sh run`); .run scripts not synced (pass inline); hook blocks `sed -n` of tools/mmx6/*.py (use Read); Ghidra BinaryLoader -loader-baseAddr leaves base 0; Ghidra batch log table missing per-program (check exports); import of 57 programs 504 s.

(d) rules: see (a) Rules; no G-rule file mentions "segment"/"fleet check script"; rules/INDEX.md only G9, G42 match for gate/fleet.

## Dead ends
- No definitions of "cc1 slot", "per-binary contracts", "health target", "boundary check in health", "check.*.sha" in named files. Grep of docs/ for Makefile|splat|shim|check.*sha found nothing more specific. Did not read GENERATION_PLAN.md or PHASE_PLAN.md (out of scope).

sources: PROJECT_CONTEXT.md:164-300,520-537; docs/decomp-architect.md:80-143,208-241; docs/decomp-kernels.md:165-180; docs/ops/decomp-environment.md:10,24-39; docs/tools-manifest.md; rules/G9.md G42.md G62.md; phase-ends/phase-1.2/tasks/T6-T8.md; phase-ends/phase-1.1/tasks/T2-T3.md; docs/memory-map.md:8-61; config/boundaries.txt
