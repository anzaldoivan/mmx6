MILESTONE: green

## Recap
Phase 1.4 set out to find the exact compiler setup Capcom used to build Mega Man X6, because a matching decompilation
can only reproduce the game's bytes from C if it compiles that C the same way. A "probe" is one game function rewritten
in C and compiled on its own; the phase installed eight candidate compilers and an assembler shim (maspsx, which mimics
Sony's assembler), wrote three probes, and compiled each under every candidate. Only one setup reproduced all three
probes byte for byte, GCC 2.95.2 (PSX build) with maspsx at its 2.86 setting, while every other candidate failed at least
one; that setup is now the "pin", the single compiler configuration the build uses for all 57 programs on the disc. The
three functions were then placed in the game's real source file and a full clean rebuild still reproduces the retail
executable and all 56 overlays exactly, so they count as the project's first decompiled ("banked") functions.

## Milestone check
- ladder: `mx.sh sync && run.sh --bg ladder -- mx.sh run make extract probe-ladder` + `run.sh --wait ladder` → exit 0, last line `PIN gcc2.95.2-psx-aspsx2.86 3 of 3`; each of the 7 other triples shows FAIL on ≥ 1 probe (gcc2.91.66-psx fails only func_8002B410, 8/79) (.run/logs/ladder.log) — GREEN
- `grep -cE '^- (Triple|Assembler version|Fingerprint evidence|Per-module variation):' docs/ops/compiler-pin.md` → 4 — GREEN
- fleet: `mx.sh sync && run.sh --bg fleet -- mx.sh run make fleet` + `run.sh --wait fleet` → exit 0, `C MATCHED 285` (f ≥ 3), last line `FLEET 57 of 57`, `BOUNDARIES OK 57 programs` (.run/logs/fleet.log) — GREEN
- `PY tools/audit_public.py` → rc 0, 0 offenders among 686 paths (.run/logs/audit.log) — GREEN
- Clauses run one after another, by hand (see Deviations).

## Deviations
- `phaseend_index.py verify` (.run/logs/phaseend-verify.log) reported `RED (3/5)`, not a milestone failure: it split the Milestone line at `;`, launched the ladder and the fleet as concurrent `--bg` jobs without their `--wait` halves (the race the Milestone forbids), judged clause 3 GREEN from the launcher's two lines, and ran the prose clause "clauses run one after another…" as a command (exit 127). Verdict above comes from the sequential manual reruns. harness: phaseend_index verify mis-parses `--bg … then --wait` clauses and prose clauses; it needs a wait-aware, sequential clause runner.
- H7 check: every summary naming tools, pins or build settings (T1 T2 T3 T4 T5 T6.1 T7 T8) also lists `HOW_WE_WORK.md` or `docs/ops/`; no miss.
- harness: `skill_add.py` appends a Skills line to the card without a `card.py check`; the card went 7000 → 7132. Trimmed back to 7000/7000 here (skill line shortened in step with its SKILL.md description; `Python:` line uses PY; three Tools purpose cells and the Build line shortened).
- T6 superseded by T6.1 (aspsx tie, critic decision); T7 ratified at review.

## Decisions that still bind
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

## Promoted
- Rules: G103, G104 (rules/INDEX.md).
- Cookbook: C0035–C0047 (13 `generalizable:` gotchas from T1 T2 T3 T4 T5 T6 T6.1 T8).
- Skill: container-scratch-not-synced (T3 `workflow:` gotcha), card Skills line.
