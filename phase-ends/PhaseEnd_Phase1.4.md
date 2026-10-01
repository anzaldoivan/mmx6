# PhaseEnd — Phase 1.4: The compiler pinned by evidence (implements Gen 1.4)
Approved: 2026-10-01 | Closed: 2026-10-01 | Planner: claude-opus-5-5/medium | Tasks: 8 done, 1 superseded

## Milestone
Milestone: the probe harness reports 3–5 probe functions byte-identical under exactly one candidate triple, every other tried triple failing; the triple, its fingerprint evidence and the explicit assembler version recorded in `docs/ops/`; per-module variation detected and recorded; the first matched functions survive the clean fleet check (N of N) — verified by: `bash tools/docker/mx.sh sync && bash tools/run.sh --bg ladder -- bash tools/docker/mx.sh run make extract probe-ladder` then `bash tools/run.sh --wait ladder --max 280` (repeat the wait until done) rc 0, the log's last line is `PIN <triple> <k> of <k>` with 3 ≤ k ≤ 5 and the log shows `FAIL` for every other triple it tried; `grep -cE '^- (Triple|Assembler version|Fingerprint evidence|Per-module variation):' docs/ops/compiler-pin.md` = 4; `bash tools/docker/mx.sh sync && bash tools/run.sh --bg fleet -- bash tools/docker/mx.sh run make fleet` then `bash tools/run.sh --wait fleet --max 280` rc 0, the log holds `C MATCHED <f>` with f ≥ 3 and its last line is `FLEET 57 of 57`; `PY tools/audit_public.py` rc 0. Commands over 285 s run as `bash tools/run.sh --bg <name> -- <cmd>` then `bash tools/run.sh --wait <name> --max 280`; clauses run one after another, never concurrently (1.3 phase-end race: two container commands on one tree gave `FLEET 56 of 57`).
Verified: `bash tools/docker/mx.sh sync && bash tools/run.sh --bg t8fleet -- bash tools/docker/mx.sh run make fleet` + `bash tools/run.sh --wait t8fleet --max 280` → exit=0, `C MATCHED 285` (f ≥ 3), last line `FLEET 57 of 57`, `build/SLUS_013.95: OK` (.run/logs/t8fleet.log); `PY tools/audit_public.py` → rc 0; `mx.sh run make format-check` → rc 0; coder: `make probe-ladder` → `PIN gcc2.95.2-psx-aspsx2.86 3 of 3`

## Tasks
- T1 — candidate compilers and maspsx in the image | Done: image `mmx6-build` installs 8 cc1 under `/opt/cc/<name>/cc1` (2.7.2 from old-gcc tag 0.9 = mmx4's build; 2.7.2-psx, 2.7.2-cdk, 2.6.3-psx, 2.8.0-psx, 2.8.1-psx, 2.91.66-psx, 2.95.2-psx from tag 0.17), each archive sha256-asserted in the Dockerfile; maspsx at commit 7686f845 in /opt/maspsx with `/usr/local/bin/maspsx` wrapper; `make toolchain-check` checks every cc1 version, runs a division smoke (cpp → cc1 → maspsx `--aspsx-version=2.56 --expand-div` → as, `nm` must show `T f`) per cc1, and the maspsx commit. | commit: 8b104ae | tasks/T1.md | logs/T1.md
- T2 — C build path and an all-stub C unit | Done: exe TU LIBSPU_S_M_UTIL (0x80055A04, 2 funcs) is a splat `c` unit, src/SLUS_013.95/LIBSPU_S_M_UTIL.c of INCLUDE_ASM lines, compiled cpp → cc1 → maspsx → as under the TRIPLE-selected triple and linked; exe hash green, fleet 57 of 57. | commit: 87a49ff | tasks/T2.md | logs/T2.md
- T3 — probe harness and ladder runner with controls | Done: `tools/mmx6/probe.py` compiles one C file standalone under a named triple via the product C rule (`make -s -B TRIPLE=<t> build/<src>.o`), takes the function's words from the .o, masks relocation fields (R_MIPS_26 low 26; HI16/LO16/GPREL16 low 16) on both sides and compares to the retail function read from `extracted/retail/`; `--ladder` prints one line per probe×triple then `PIN <t> <k> of <k>` | `PIN NONE` | `PIN AMBIGUOUS …`, rc 0 only on a unique PIN; `--self-test` = known-true INCLUDE_ASM control MATCH and a runtime-planted one-word mutation FAIL under all 32 triples. | commit: 1ce8172 | tasks/T3.md | logs/T3.md
- T4 — decompile scaffold and differ invocation | Done: image carries m2c and asm-differ at pinned commits (toolchain-check checks both); `decompile.py <func>` prints an m2c scaffold; `diff.sh <func>` runs asm-differ against expected/build/ using the ld map and ends `DIFF <func> <n> differing lines` (rc 0 only n=0); 0 lines for func_80055A04. | commit: 60fb176 | tasks/T4.md | logs/T4.md
- T5 — per-module codegen census | Done: tools/mmx6/optscan.py classifies all 6784 functions of the 57 programs (O0 tell, nop-after-load, gprel, div expand/bare) with per-program summaries and runs; docs/ops/compiler-pin.md `Per-module variation` records the result. | commit: - | tasks/T5.md | logs/T5.md
- T6 — probes drafted and the ladder run | Done: 3 game-TU probes match byte-for-byte under gcc 2.95.2-psx; the 32-rung ladder resolves the cc1 axis (2.95.2-psx unique) but ends `PIN AMBIGUOUS` across its 4 aspsx rungs, which no game function can split under `-G0`. | commit: - | tasks/T6.md | logs/T6.md
- T6.1 — aspsx -G0 equivalence class collapsed; ladder pins one triple | Done: config/triples.txt has one rung per cc1 (`--aspsx-version=2.86 --expand-div`, 8 rungs); `make probe-ladder` ends `PIN gcc2.95.2-psx-aspsx2.86 3 of 3`, rc 0. | commit: - | tasks/T6.1.md | logs/T6.1.md
- T7 — the pin recorded and ratified | Done: docs/ops/compiler-pin.md records the pin `gcc2.95.2-psx-aspsx2.86` with evidence, per-module variation and residual doubts; Makefile default `TRIPLE` is the pin, fleet green under it; L1 refuted in prior-art; card carries the pin under cap. | commit: - | tasks/T7.md | logs/T7.md

## Decisions that still bind
- T1 — the cc1 candidate set is `CC1_SET` in the Makefile, archives pinned by sha256 in the Dockerfile (a cc1 does not report its release tag); maspsx pinned by commit `MASPSX_PIN`; Dockerfile and Makefile change together.
- T2 — C units are listed in config/c_units.txt and become `c` only through segment.py; triples live in config/triples.txt, selected by `TRIPLE` (default L1 `gcc2.7.2-aspsx2.56` until T7).
- T2 — the C rule runs under bash pipefail; a dead stage fails the rule (negative control rc 2).
- T3 — probes compile through the Makefile C rule (one pipeline; a pin is the product build's pin), never a copied flag set.
- T3 — the mutation control is generated in `.run/probe/mut/` at runtime; no target bytes in tracked files.
- T4 — m2c pinned 708d2d2c…, asm-differ 0dd09af8…, by commit in Makefile + Dockerfile, checked by toolchain-check.
- T4 — diff.sh's verdict is its last line `DIFF <func> <n> differing lines`; rc 0 only when n=0.
- T5 — no -O0 module and no `$gp`-relative access in any of the 57 programs: the ladder needs one opt level (-O2 class) and `-G0`; do not add -O0 or `-G8` rungs without new evidence.
- T6 — the game's cc1 is gcc 2.95.2-psx (decompals old-gcc): only it emits the retail division shape `div $0,a,b; mflo; bne b,$0; nop; break 7` (zero trap, no overflow check); func_8002B410 matches only there.
- T6.1 — aspsx 2.56/2.67/2.79/2.86 are one equivalence class under `-G0` with gprel 0; the ladder lists one representative (2.86, arbitrary) per cc1; a new aspsx rung needs a probe that exercises `sltu rd,rs,<negative imm>` or `$gp` access.
- T7 — X6's compiler pin is `gcc2.95.2-psx-aspsx2.86` (old-gcc 0.17 2.95.2-psx cc1 `-O2 -G0 -msoft-float -funsigned-char` → maspsx @7686f84 `--aspsx-version=2.86 --expand-div` → as 2.42), one triple for all 57 programs, no per-unit override until a probe outside exe game TU 120A0 fails under it.
- T7 — aspsx 2.86 is the representative of the 2.56-2.86 `-G0` class, passed explicitly; pending developer acceptance at this review.
- T8 — a function is banked when it is C in its real TU (listed in config/c_units.txt) and the clean fleet's whole-binary hash is green; the standalone probe match alone is not a bank (G10).
- Pin `gcc2.95.2-psx-aspsx2.86` (old-gcc 0.17 2.95.2-psx cc1 `-O2 -G0 -msoft-float -funsigned-char` → maspsx @7686f84 `--aspsx-version=2.86 --expand-div` → as 2.42) for all 57 programs; no per-unit override until a probe outside TU 120A0 fails → environment fact: card `Compiler pin:` line, docs/ops/compiler-pin.md `## Pin`; test `make probe-ladder`.
- aspsx 2.56–2.86 are one `-G0` equivalence class, 2.86 its named representative; collapse indistinguishable rungs before claiming a pin → rule G104 (added); mechanism in docs/ops/compiler-pin.md `### aspsx equivalence class`.
- Probes compile through the Makefile C rule, never a copied flag set → rule G103 (added).
- A function is banked when it is C in its real TU and the clean fleet hash is green → existing rule G10 (no new rule); `C MATCHED` in tools/mmx6/fleet.sh, documented docs/ops/decomp-environment.md.
- No -O0 module and no `$gp`-relative access in any program: one -O2 class, `-G0`; no -O0/-G8 rungs without new evidence → environment fact: docs/ops/compiler-pin.md `Per-module variation`.
- C units only via config/c_units.txt through segment.py; the C rule runs under bash pipefail → contract: docs/ops/decomp-environment.md; tested by the fleet (T2 negative control rc 2).
- Toolchain pins (CC1_SET sha256, maspsx/m2c/asm-differ commits) live in Makefile + Dockerfile and change together → environment fact: card `Pins:` line, docs/ops/mmx6-hosts.md; test `make toolchain-check`.
- diff.sh's verdict is its last line `DIFF <func> <n> differing lines`, rc 0 iff n=0; the probe mutation control is generated at runtime in the container's `.run/` → contracts: docs/ops/decomp-environment.md; tests `diff.sh func_80055A04`, `probe.py --self-test`.
- Next task needs: split fix for rock_17/43/45 (`dlabel` + `.word`, 0 glabel; 163 functions, 1044 words dropped by optscan) before any C unit there — deferred to 1.5.
- Next task needs: I3 — the first lib or overlay C unit confirms the pin at the byte gate (the pin's first test outside TU 120A0; LIBSPU_S_M_UTIL holds 0 C functions); a FAIL there is a per-unit triple ladder, not a re-pin — deferred to 1.5.
- Next task needs: I2 — the 15 exe inter-lib gaps — deferred to 1.5.
- Next task needs: `C MATCHED` counts splat's 282 empty-body (`jr ra; nop`) functions; stub-only baseline 282, banked 285 (3 probes); progress is measured as the delta, or the count is refined to exclude empty bodies.

## Rules proposed
- (none)

## Cookbook entries added
C0036 | Ubuntu make recipes run under dash (no pipefail); set SHELL bash + .SHELLFLAGS per target | make,pipefail,dash,ubuntu | 2026-10-01 | 1.4/T2 | mmx6 T2
C0037 | cpp 12 -nostdinc drops the stdc-predef.h pre-include that old gcc 2.x cc1 warns on | cpp,old-gcc,cc1,psx | 2026-10-01 | 1.4/T2 | mmx6 T2
C0038 | An INCLUDE_ASM probe control is triple-independent; pair it with a planted one-word mutation | probe,control,compare,masking | 2026-10-01 | 1.4/T3 | mmx6 T3
C0039 | asm-differ arch mips is big-endian; PSX needs mipsel (m2c target mipsel-gcc-c) | asm-differ,m2c,mips,endianness,psx | 2026-10-01 | 1.4/T4 | mmx6 T4
C0040 | make -j extract build races; run extract as its own make call first | make,parallel,extract,race | 2026-10-01 | 1.4/T4 | mmx6 T4
C0041 | splat's instruction comment word is in file byte order; decode as little-endian before field extraction | splat,mips,decode,endianness | 2026-10-01 | 1.4/T5 | mmx6 T5
C0042 | A splat asm subsegment can come out as dlabel + .word with 0 glabel; per-function tools must detect it | splat,spimdisasm,census,functions | 2026-10-01 | 1.4/T5 | mmx6 T5
C0043 | A break 7 near a div is not an expanded-div test; classify by break 6 presence and mflo position | mips,division,maspsx,expand-div,fingerprint | 2026-10-01 | 1.4/T6 | mmx6 T6
C0044 | maspsx aspsx-version rungs >= 2.60 are byte-identical under -G0 with no $gp access | maspsx,aspsx,pin,ladder,psx | 2026-10-01 | 1.4/T6 | mmx6 T6
C0045 | A trailing # comment on a make VAR ?= value line keeps the space before # in the value | make,variables,comments | 2026-10-01 | 1.4/T6.1 | mmx6 T6.1
C0046 | splat 0.50 c-mode writes a jr ra; nop function as empty C; measure the stub-only baseline before banking | splat,c-mode,count,baseline | 2026-10-01 | 1.4/T8 | mmx6 T8
C0047 | Once a function is C, splat writes no nonmatchings .s for it; extent tools must fall back to symbol order | splat,nonmatchings,extent,probe | 2026-10-01 | 1.4/T8 | mmx6 T8

## Research
R1.4-001 | Candidate compiler ladder for MMX6 PSX (phase 1.4) | PSX compiler ladder: old-gcc, maspsx, PsyQ versions | psx, old-gcc, maspsx, aspsx, gcc-2.7.2, decomp | retriever-web | 2026-10-01 | 44 lines

## Audit
- seed: median 14k, max 14k, n=10 (phase 1.4)
- previous phase 1.3: median 15k, growth -1.9%
- CLAUDE.md: 1242 bytes (unchanged)
- .claude/skills/ci-wait-after-push/SKILL.md: 799 bytes (unchanged)
- .claude/skills/container-scratch-not-synced/SKILL.md: 1125 bytes (new)
- .claude/skills/docker-vm-no-privileged/SKILL.md: 774 bytes (unchanged)
- .claude/skills/project-architect/SKILL.md: 13448 bytes (unchanged)
- .claude-state/memory/MEMORY.md: 214 bytes (unchanged)
- HOW_WE_WORK.md: 7050 bytes
- cookbook/INDEX.md: 7667 bytes
- rules/INDEX.md: 10587 bytes
### Carry audit — phase 1.4 (2026-10-01T14:11:36Z → open UTC, 1 sessions, 525 requests)

| file (read) | chars | n |
|---|---|---|
| PHASE_PLAN.md | 60.5k | 5 |
| Makefile | 31.4k | 5 |
| segment.py | 16.7k | 2 |
| compiler-pin.md | 15.6k | 4 |
| diff.py | 15.6k | 7 |
| HOW_WE_WORK.md | 15.4k | 4 |
| optscan.py | 11.6k | 1 |
| probe.py | 10.8k | 3 |
| decomp-environment.md | 9.4k | 3 |
| T6.md | 7.9k | 2 |
| file (write) | chars | n |
|---|---|---|
| optscan.py | 20.7k | 13 |
| probe.py | 13.4k | 4 |
| compiler-pin.md | 7.5k | 5 |
| add_cookbook.sh | 6.0k | 1 |
| RECAP.md | 5.6k | 1 |
| T7.md | 4.3k | 1 |
| T6.md | 4.1k | 1 |
| T6.md | 3.9k | 1 |
| result kind | chars | n |
|---|---|---|
| bash other | 362.2k | 215 |
| Read | 244.1k | 57 |
| tools/card.py | 224.0k | 26 |
| run.sh | 82.2k | 66 |
| Agent | 23.3k | 22 |
| tools/plan_edit.py | 21.1k | 17 |
| tools/task_log.py | 15.3k | 11 |
| tools/outline.py | 12.4k | 3 |
| tools/status.py | 11.6k | 14 |
| tools/audit_public.py | 7.5k | 15 |
- whole reads over 20.0k: 1
- seed floor: retriever-code 5,299 (n 1, prev 5,428) · retriever-digest 5,281 (n 1, prev 5,381) · retriever-web 3,907 (n 1, prev 3,839)
- outline credit: 3 outlines · 1 followed by a ranged read · 22.6k chars credited
- warm pings: 6 pings over 6 runs, 1 warmed waits over the TTL, rewrites across warmed waits 0, waits past the cap 0, pings cost $0.0322 vs rewrites replaced $0.2452, cheaper than one rewrite: yes
- toasts by cause (waiting): question 0, review 0, replan 0, permission 0, input 0, discussion 0, crash 0, idle 0, stop 0, subagent-stop 0, model 0, other 0
- router turns by cause: loop 13, relay 0, re-arm 0, other 1, relay cost $0.0000
- retriever re-asks: 0 of 0 retriever briefs repeat a lookup of the same run
- router: pa-session 2424e7a8 · requests 47 · ctx at end 73.8k · growth T1 +1.4k, T2 +505, T3 +484, T4 +483, T5 +1.5k, T6 +1.7k, T6.1 +1.6k, T7 +2.6k, T8 +1.7k · top: Agent 13.8k/13, tools/status.py 11.6k/14, tools/plan_edit.py 3.7k/10, other 1.5k/2, tools/managed.py 1.5k/1
- noise: 60 lines 3.6k chars — usage: : 33 lines/1.9k, No such file or directory: 27 lines/1.6k
- price: read $0.20/Mtok · 1h write $7.60/Mtok · output $18.99/Mtok (phase model mix)
- median requests after a read: 4
- carry/request: 1970 chars, 525 requests (prev 1974 chars, 298 requests, growth -0.2%)
- flag: 1 whole-plan reads by critic
- flag: 14 tool-source reads by coder-opus55, expert-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/segment.py  6.9k chars  expert-opus55
  /Users/ThinkPad/orca/mmx6/.claude/skills/ci-wait-after-push/SKILL.md  215 chars  expert-opus55
  /Users/ThinkPad/orca/mmx6/.claude/skills/container-scratch-not-synced/SKILL.md  212 chars  expert-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/segment.py  9.8k chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/tools/docker/Dockerfile  3.8k chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/toolchain_check.sh  2.5k chars  coder-opus55
  /Users/Shared/kits/decomp-architect/corpus/tools/P4/decompile.py  2.6k chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/tools/docker/mx.sh  3.5k chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/probe.py  1.4k chars  expert-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/probe.py  6.0k chars  expert-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/optscan.py  11.6k chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/probe.py  3.4k chars  coder-opus55
  /Users/ThinkPad/orca/mmx6/tools/docker/Dockerfile  2.0k chars  expert-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/toolchain_check.sh  976 chars  expert-opus55
- flag: 1 whole reads over 20.0k by critic
  file: /Users/ThinkPad/orca/mmx6/phase-ends/current/PHASE_PLAN.md  role: critic  chars: 28.2k

## Agent runs
- - | auditor | other | claude-opus-5-5 | medium | ctx 25k | $0.143 | saved - | completed | parent 167d8b13
- T1 | expert-opus55 | expert | claude-opus-5-5 | medium | ctx 52k | $0.370 | saved $0.06 | completed | parent 167d8b13
- T1 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 55k | $0.500 | saved $0.02 | completed | parent a1b375e5
- T2 | expert-opus55 | expert | claude-opus-5-5 | medium | ctx 36k | $0.183 | saved $0.34 | completed | parent 167d8b13
- T2 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 63k | $0.534 | saved $0.28 | completed | parent a95cc7fc
- T3 | expert-opus55 | expert | claude-opus-5-5 | medium | ctx 49k | $0.368 | saved - | completed | parent 167d8b13
- T3 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 58k | $0.520 | saved - | completed | parent a15d1c0d
- T4 | expert-opus55 | expert | claude-opus-5-5 | medium | ctx 50k | $0.417 | saved - | completed | parent 167d8b13
- T4 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 102k | $1.312 | saved $0.56 | completed | parent aa2dc2af
- T4 | review | review | claude-opus-5-5 | medium | ctx 23k | $0.127 | saved - | completed | parent 167d8b13
- T4 | expert-opus55 | expert | claude-opus-5-5 | medium | ctx 43k | $0.240 | saved - | completed | parent 167d8b13
- T4 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 33k | $0.230 | saved $0.56 | completed | parent aea5f244
- T5 | expert-opus55 | expert | claude-opus-5-5 | medium | ctx 49k | $0.277 | saved - | completed | parent 167d8b13
- T5 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 44k | $0.325 | saved - | completed | parent a660ec3f
- T6 | expert-opus55 | expert | claude-opus-5-5 | medium | ctx 46k | $0.299 | saved - | completed | parent 167d8b13
- T6 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 67k | $0.728 | saved $0.03 | completed | parent a7d25393
- T7 | expert-opus55 | expert | claude-opus-5-5 | medium | ctx 37k | $0.246 | saved - | completed | parent 167d8b13
- T7 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 32k | $0.180 | saved - | completed | parent a56778dc
- T8 | expert-opus55 | expert | claude-opus-5-5 | medium | ctx 47k | $0.336 | saved - | completed | parent 167d8b13
- T8 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 40k | $0.287 | saved - | completed | parent a445615d
- PHASE-END | expert-opus55 | expert | claude-opus-5-5 | high | ctx 45k | $0.414 | saved - | completed | parent 167d8b13
- T1 | expert-opus55 | expert | claude-opus-5-5 | medium | ctx 45k | $0.261 | saved $0.06 | completed | parent 2424e7a8
- T1 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 46k | $0.367 | saved - | completed | parent af01685e
- T2 | expert-opus55 | expert | claude-opus-5-5 | medium | ctx 63k | $0.492 | saved $0.33 | completed | parent 2424e7a8
- T2 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 67k | $0.660 | saved $0.25 | completed | parent a2101a61
- T3 | expert-opus55 | expert | claude-opus-5-5 | medium | ctx 53k | $0.379 | saved - | completed | parent 2424e7a8
- T3 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 55k | $0.646 | saved $0.26 | completed | parent a7a6ad75
- T4 | expert-opus55 | expert | claude-opus-5-5 | medium | ctx 48k | $0.448 | saved $0.22 | completed | parent 2424e7a8
- T4 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 85k | $1.195 | saved $0.79 | completed | parent a06de12b
- T5 | expert-opus55 | expert | claude-opus-5-5 | high | ctx 60k | $0.671 | saved $0.11 | completed | parent 2424e7a8
- T5 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 37k | $0.406 | saved $1.23 | completed | parent a857480c
- T5 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 37k | $0.430 | saved $0.79 | completed | parent a857480c
- PHASE-END | critic | critic | claude-opus-5-5 | medium | ctx 19k | $0.167 | saved - | completed | parent 167d8b13
- T9 | expert-opus55 | expert | claude-opus-5-5 | high | ctx 52k | $0.399 | saved - | completed | parent 167d8b13
- T9 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 36k | $0.292 | saved - | completed | parent af2e4197
- T10 | expert-opus55 | expert | claude-opus-5-5 | high | ctx 50k | $0.327 | saved $0.17 | completed | parent 167d8b13
- T5 | critic | critic | claude-opus-5-5 | medium | ctx 23k | $0.134 | saved - | completed | parent 2424e7a8
- T6 | expert-opus55 | expert | claude-opus-5-5 | high | ctx 81k | $1.072 | saved - | completed | parent 2424e7a8
- T10 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 31k | $0.292 | saved - | completed | parent ac4d026b
- … 10 more: PY ~/.claude/pa3/pa_ledger.py report

## Discussions
- I3 | first lib/overlay C unit: confirm the pin at the byte gate; on mismatch, open the triple ladder for that unit | deferred:1.5

## Deferred
- T6 | superseded — probes drafted and the ladder run
- from T8: banking more 120A0 functions = replace one INCLUDE_ASM line in src/SLUS_013.95/120A0.c with C, fleet-gated; `C MATCHED` baseline is 285. The first C function in a lib TU or overlay is the pin's first test outside 120A0 (on mismatch: a per-unit triple ladder, per the developer's note). (unconsumed)
- I3 (deferred:1.5): first lib/overlay C unit: confirm the pin at the byte gate; on mismatch, open the triple ladder for that unit

## Changes
- 2026-10-01 router: T1 next -> done
- 2026-10-01 router: T2 next -> done
- 2026-10-01 router: T3 next -> done
- 2026-10-01 router: T4 next -> done
- 2026-10-01 router: T5 next -> done
- 2026-10-01 critic: reopened T6 as T6.1 — aspsx -G0 equivalence class collapsed; ladder pins one triple
- 2026-10-01 critic: critic: T6 aspsx tie is a structural -G0 equivalence class (maspsx.py:40-47, corpus 0 sltu_at/0 gprel); T6.1 collapses it to representative aspsx 2.86. T7 must write '- Assembler version: 2.86 (passed explicitly; 2.56-2.86 byte-equivalent under -G0, representative)' and list the class under residual doubts; the developer accepts the representative at T7's review (Risks line 4).
- 2026-10-01 router: T6.1 next -> done
- 2026-10-01 developer: T7 next -> done
- 2026-10-01 router: T8 next -> done

## Plain-English Recap
Phase 1.4 set out to find the exact compiler setup Capcom used to build Mega Man X6, because a matching decompilation
can only reproduce the game's bytes from C if it compiles that C the same way. A "probe" is one game function rewritten
in C and compiled on its own; the phase installed eight candidate compilers and an assembler shim (maspsx, which mimics
Sony's assembler), wrote three probes, and compiled each under every candidate. Only one setup reproduced all three
probes byte for byte, GCC 2.95.2 (PSX build) with maspsx at its 2.86 setting, while every other candidate failed at least
one; that setup is now the "pin", the single compiler configuration the build uses for all 57 programs on the disc. The
three functions were then placed in the game's real source file and a full clean rebuild still reproduces the retail
executable and all 56 overlays exactly, so they count as the project's first decompiled ("banked") functions.
