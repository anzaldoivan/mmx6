# decomp-architect install record

*Written by the kit's installer on 2026-10-01 against ProjectArchitect 3.14.2 (tested 3.14.2). The kit's pieces and their PA3 homes: the kit's `templates/pa3-contract.md`.*

## The game interview

- **GAME_TITLE:** Mega Man X6
- **PLATFORM:** Sony PlayStation (MIPS R3000A)
- **GAME_SERIAL:** USA SLUS-01395 (disc v1.1)
- **TARGET_BINARY:** SLUS_013.95
- **DUMP_PATH:** given (machine-local; not recorded)
- **CONTAINER_LAYOUT:** One MODE2/2352 ISO9660 track; SYSTEM.CNF boots SLUS_013.95; code overlays (and compressed payloads) packed as sector-extent members of the ROCK_X6.BIN archive; XA/STR streams alongside
- **SDK_EVIDENCE:** The disc carries "Library Programs (c) 1993-1997 Sony Computer Entertainment Inc." (PsyQ 4.x era); exact library version to be detected in Phase 1.2
- **COMPILER_FAMILY:** PsyQ-era GCC cc1 + aspsx: gcc 2.6.3 + aspsx 2.63 first (mmx4's X4 pin, a lead), then gcc 2.7.2 builds; pinned by probes in Phase 1.4
- **COMMUNITY_WORK:** No X6 decompilation found on 2026-10-01; leads: sozud/mmx4 (X4 matching decomp, AGPL-3.0), Kuumba123 MegaManX6_PS1_Modding/Practice (unlicensed, facts only), mstan/MegaManX6Recomp (PolyForm Noncommercial, facts only), acediez X6 Tweaks, Shinnuu Archipelago X6 world, TCRF
- **PROJECT_GOALS:** Every code binary on the USA v1.1 disc (SLUS_013.95 and the ROCK_X6.BIN overlays) rebuilt byte-identical from readable, evidenced C, with the hash check inside the build, reproducible by anyone with their own dump from the README alone.
- **LICENSE_CHOICE:** AGPL-3.0 for the project's own tools and documents; no rights are claimed over Capcom's game or the decompiled source; adapted mmx4 files keep their attribution and license, listed in THIRD_PARTY.md
- **AI_DISCLOSURE:** This project is developed with substantial AI assistance; every change is justifiable from recorded evidence, a person reviews each phase gate, names come only from evidence, outward text is written by a person, and contributors disclose AI-generated submissions.
- **PUBLIC_OR_PRIVATE:** public

## Deviations

- none

## Warnings

- none

## What was written

- created `.clang-format`
- changed `.claude/skills/project-architect/SKILL.md`
- created `.github/workflows/no-rom.yml`
- changed `.gitignore`
- created `.run/README.md`
- changed `CLAUDE.md`
- created `CONTRIBUTING.md`
- changed `HOW_WE_WORK.md`
- created `Makefile`
- created `README.md`
- created `config/decomp-hooks.snippet.json`
- created `config/firewall-fixture.sha1`
- created `config/firewall.txt`
- created `config/mcp.json.template`
- created `cookbook/C0001.md`
- created `cookbook/C0002.md`
- created `cookbook/C0003.md`
- created `cookbook/C0004.md`
- created `cookbook/C0005.md`
- created `cookbook/C0006.md`
- changed `cookbook/INDEX.md`
- created `docs/README.md`
- created `docs/decomp-architect-install.md`
- created `docs/decomp-architect.md`
- created `docs/decomp-kernels.md`
- created `docs/inherited-record.md`
- created `docs/knowledge-corpus.md`
- changed `docs/ops/INDEX.md`
- created `docs/ops/decomp-environment.md`
- created `docs/ops/disassembler-mcp.md`
- created `docs/tools-manifest.md`
- created `docs/wave-playbook.md`
- created `rules/G1.md`
- created `rules/G10.md`
- created `rules/G11.md`
- created `rules/G12.md`
- created `rules/G13.md`
- created `rules/G14.md`
- created `rules/G15.md`
- created `rules/G16.md`
- created `rules/G17.md`
- created `rules/G18.md`
- created `rules/G19.md`
- created `rules/G2.md`
- created `rules/G20.md`
- created `rules/G21.md`
- created `rules/G22.md`
- created `rules/G23.md`
- created `rules/G24.md`
- created `rules/G25.md`
- created `rules/G26.md`
- created `rules/G27.md`
- created `rules/G28.md`
- created `rules/G29.md`
- created `rules/G3.md`
- created `rules/G30.md`
- created `rules/G31.md`
- created `rules/G32.md`
- created `rules/G33.md`
- created `rules/G34.md`
- created `rules/G35.md`
- created `rules/G36.md`
- created `rules/G37.md`
- created `rules/G38.md`
- created `rules/G39.md`
- created `rules/G4.md`
- created `rules/G40.md`
- created `rules/G41.md`
- created `rules/G42.md`
- created `rules/G43.md`
- created `rules/G44.md`
- created `rules/G45.md`
- created `rules/G46.md`
- created `rules/G47.md`
- created `rules/G48.md`
- created `rules/G49.md`
- created `rules/G5.md`
- created `rules/G50.md`
- created `rules/G51.md`
- created `rules/G52.md`
- created `rules/G53.md`
- created `rules/G54.md`
- created `rules/G55.md`
- created `rules/G56.md`
- created `rules/G57.md`
- created `rules/G58.md`
- created `rules/G59.md`
- created `rules/G6.md`
- created `rules/G60.md`
- created `rules/G61.md`
- created `rules/G62.md`
- created `rules/G63.md`
- created `rules/G64.md`
- created `rules/G65.md`
- created `rules/G66.md`
- created `rules/G67.md`
- created `rules/G7.md`
- created `rules/G8.md`
- created `rules/G9.md`
- changed `rules/INDEX.md`
- created `src/NOTICE.md`
- created `tools/audit_public.py`
- created `tools/bootstrap.sh`
- created `tools/docker/Dockerfile`
- routed `memory-seed/offline-tooling-first.md` → cookbook
- routed `memory-seed/a-slow-gate-is-a-bug.md` → cookbook
- routed `memory-seed/breadth-is-isolated-agents.md` → cookbook
- routed `memory-seed/route-by-measured-difficulty.md` → cookbook
- routed `memory-seed/mcp-reconnect-after-restart.md` → ops:docs/ops/disassembler-mcp.md
- routed `memory-seed/answer-before-grinding-in-live-coop.md` → rule:G2
- routed `memory-seed/tool-change-ships-with-its-consumers-and-docs.md` → rule:G33
- routed `memory-seed/checkpoint-means-everything-is-already-in-a-file.md` → rule:G59
- routed `memory-seed/keep-an-accelerator-ledger.md` → rule:G59
- routed `memory-seed/phaseend-carries-the-narrative-axis.md` → rule:G59
- routed `memory-seed/the-byte-gate-is-the-only-claim.md` → drop
- routed `memory-seed/the-matching-flywheel.md` → drop
- routed `memory-seed/one-runbook-is-the-procedure.md` → drop
- routed `memory-seed/consult-the-tool-dictionary-first.md` → drop
- routed `memory-seed/translate-the-source-idiom-through-the-pass.md` → drop
- routed `memory-seed/no-sleep-polling-background-tasks.md` → drop
- routed `memory-seed/long-checks-run-in-the-foreground.md` → drop
- routed `memory-seed/resume-means-resume-the-run.md` → drop

## Next

A bare `claude` in this repository: PA3's generation planner drafts `GENERATION_PLAN.md` from the ladder; the ladder's Phase-0 milestone (the CI workflow green on the first push) is verified by PA3's own gates.
