# mmx6 — Project Context & Roadmap

> **Version:** 1.0.0
> **Generated:** 2026-10-01
> **Generation:** 1 | **Tech Stack:** PlayStation (MIPS R3000A) · splat · PsyQ-era cc1 (pinned by evidence in Phase 1.4) + an assembler shim · GNU binutils (mips) · Make · Python · Ghidra + psx_ldr + GhidrAssistMCP · PCSX-Redux (Lua) · amd64 Docker build host

---

## For Humans — Quick Guide

This is your project's **permanent constitution** — the vision, decisions, architecture, and the
generation map. Written once, **never edited**. State, rules and the live plan evolve elsewhere.

**The document system (where everything lives):**

| File | What it is | Who edits it |
|---|---|---|
| **This file** | permanent vision, decisions, architecture, generation map | nobody, after generation |
| `CLAUDE.md` | ≤300 tokens: roles, pointers, the always-rules | the installer |
| `project-architect` skill | the standing rules every agent loads | a planner session |
| `HOW_WE_WORK.md` | developer profile, tools, paths, build/test, standing decisions | any task that changes one (H7) |
| `GENERATION_PLAN.md` | the live roadmap: phases, milestones, open/closed | the planner; `plan_edit.py gen-close` |
| `phase-ends/current/PHASE_PLAN.md` | the approved plan of the open phase | `tools/plan_edit.py` only |
| `phase-ends/` | PhaseEnds, GenerationEnds, task/research indexes | scripts at each close |
| `rules/` `cookbook/` `docs/ops/` | full rule texts, techniques, ops detail — one file per entry, found by grep on the INDEX | the task that earns the entry |

**To work on this project:** run `python3 tools/launch.py` in the repo (or a bare `claude`). It picks the session kind
(planner, router, review), writes the seed, and starts Claude. Governance methodology:
`docs/project-architect.md`; the decompilation methodology: `docs/decomp-architect.md` (installed by the kit).

---

## Rules & Protocols

Not in this file. A permanent-static document would freeze them.

- Standing rules for every agent: the **`project-architect`** skill (`.claude/skills/project-architect/SKILL.md`).
- Full rule texts, one file per rule: **`rules/INDEX.md`** → `rules/<id>.md`. G1–G67 are the decomp kit's
  (installed after this intake); G101 and G102 are this project's own, written at intake.
- Pointers and the always-rules: **`CLAUDE.md`**.

**Precedence:** where this file's wording ages out of step, the project-architect skill and `rules/` govern.

---

## Quick Reference Card

- **Project:** mmx6 — a matching decompilation of Mega Man X6 (Capcom, 2001; PlayStation, USA SLUS-01395, disc v1.1).
- **Goal:** every code binary on the disc rebuilt byte-identical from readable, evidenced C, with the hash check inside
  the build, reproducible by anyone with their own dump from the README alone.
- **Definition of done (the milestone gate):** the byte gate — the whole-binary hash of every onboarded binary equals
  the original's, from a clean rebuild, checked inside `make build` (G3, G61); no unmatched C in a default build (G4).
  Each phase closes only when every `verified by:` clause of its milestone runs green (`tools/phaseend_index.py verify`).
- **Stack:** see the header; the compiler triple is a `TODO` until Phase 1.4 pins it by evidence.
- **Environment:** see `HOW_WE_WORK.md` and `docs/ops/INDEX.md` (`docs/ops/mmx6-hosts.md` for hosts and paths).
- **Current generation:** 1 — the matching decompilation, from the firewall to readable N of N.

---

## Project Overview

Mega Man X6 is the last 2D Mega Man X game on the PlayStation and shares its engine lineage with X4 and X5. It has no
decompilation (GitHub, decomp.me, decomp.dev and the community lists were searched on 2026-10-01), while its
predecessor X4 has an active matching decompilation, **sozud/mmx4**, whose toolchain pin, build layout and engine
knowledge make X6 the natural next target.

This project produces C source that, compiled with the original era's toolchain and linked in the original order,
reproduces every shipped code binary of the USA v1.1 disc byte for byte — the boot executable `SLUS_013.95` and the code
overlays packed in `ROCK_X6.BIN` — verified by a hash check inside every build. It adds the first byte-identical C for
X6, names that each carry recorded evidence, and a path for X-series engine work to be shared across decompilations.

The methodology is the decomp-architect kit's (a finished PSX matching decompilation's distilled ladder): tooling and
instruments first, at 0%, then the campaign leverage-first, with readability enforced at bank time rather than after.

### Project Assumptions

- The developer's dump is the Redump USA v1.1 image (SHA-1 `d4f7e08371027a87a3bf13311db5a4c56733f4ea`, verified
  2026-10-01), one MODE2/2352 data track, no CD-DA track. Other versions are a later generation.
- The game was built with a PsyQ 4.x-era toolchain: the disc carries "Library Programs (c) 1993-1997 Sony Computer
  Entertainment Inc."; the exact library version is detected in Phase 1.2 and the compiler pinned in Phase 1.4.
  mmx4's X4 pin (gcc 2.6.3 cc1 + aspsx 2.63) is the first candidate, **a lead, not a fact** (G101).
- Code lives in `SLUS_013.95` plus overlays in `ROCK_X6.BIN`; the recomp project's overlay map (59 sector-extent
  members, load bases `0x801EA000` / `0x800E9860` / `0x800FA000`) is a lead re-proven against live RAM in Phase 1.2.
  N — the number of binaries in "N of N" — is fixed by Phase 1.2's load map, not by this file.
- XA audio and STR movies are data, not code; they are extracted and hashed but never part of N.
- The X4↔X6 shared-engine hypothesis is unproven; the source projects' cross-game scans found only Sony library code
  shared. It is measured (Phase 1.6) before anything is planned around it.
- One developer, one Mac (arm64); builds run in an amd64 Docker host; Claude Max 5x.

---

## Lessons Learned / Known Risks

From the source project's failure museum (`corpus/decomp-kernels.md` part 9, kernels cited as DK-n):

- **Almost every recorded wall was one of the project's own instruments** (DK-9, DK-17) — the differential harness and
  the coverage assertions are planned at 0% (Phase 1.5), not after the first wall.
- **Integration, not idioms, is the bottleneck once cracking is systematic** (DK-7) — banking is budgeted (Phase 1.6's
  reconcile ladder).
- **A wrong compiler era or a silent assembler default produces systematic near-misses everywhere** (DK-3) — the pin is
  proven on three to five probes under exactly one triple, the assembler version passed explicitly.
- **ROM-derived bytes committed "while private" cost a full-history rewrite** (DK-1, DK-53–56) — this repository is
  public from the first commit and the firewall has no private exemption.
- **Model-drafted outward text costs goodwill** (DK-58); **names guessed by a model damage a decompilation without any
  test catching it** (G62).
- **Structural decisions get more expensive as matched work accumulates** (DK-12) — segmentation at the forced
  boundaries happens before any C exists (Phase 1.3).
- **A fresh session misreads a compressed hand-off** (DK-59) — hand-offs are replayed, never summarised (G59).

Specific to this project:

- **Leads mistaken for evidence** — Kuumba123's names, the recomp's overlay map, mmx4's pin assumed rather than proven.
  Every lead carries a status in `docs/prior-art.md` (G101).
- **License contamination** — copying from an unlicensed (Kuumba123) or non-commercial (MegaManX6Recomp) source into an
  AGPL-3.0 public repository (G102).
- **The X4↔X6 sharing hypothesis may be false** — measure before planning around it.
- **Budget.** Claude Max 5x for an eleven-phase generation: free, deterministic, local work before paid work (DK-40);
  waves sized to the budget (G39).

---

## Project Philosophy

**North Star (one sentence):** every binary on the Mega Man X6 disc rebuilds byte-identical from readable, evidenced C,
and the build itself is the proof.

- **The byte gate is the only definition of done.** A function is matched when the whole binary's hash is green from a
  clean rebuild; nothing else is a claim (G3, G61).
- **Instruments before campaigns.** The oracles, the census, the differential harness, the multipliers and the codegen
  map are built and proven at 0%, because the campaign banks at the rate they allow (Part B's order).
- **Evidence over leads.** Prior art orders the work; only our own bytes and oracles establish facts (G101). Unnamed
  beats wrong (G62).
- **Readability at bank time.** Pins recorded at draft time, shared bodies as C files per system, canonical types and
  no raw address cast from the first bank, names with recorded evidence, formatting with the first C file, layout by
  the game's systems at the forced boundaries.
- **The repository ships no byte of the game** — from commit one, public or not (G12).
- **Free work before paid work** (DK-40); the record over memory; every change justifiable by a person from the record
  (G65).

---

## Key Decisions

| Decision | Choice | Rejected alternative | Why |
|---|---|---|---|
| Approach | Decomp-first: matching C, the memory map from the loader's own code and the runtime oracle | Recompilation-first (or using MegaManX6Recomp's output) | A matching decompilation needs no recompiler and a recompiler's output feeds no matching work (failure museum, first exhibit) |
| Target version | USA v1.1 (SLUS-01395), Redump-verified | JP release, v1.0, the 2001-10-30 prototype | The developer's legally owned dump; Kuumba123's US symbol leads; other versions become extra split configs in a later generation |
| Definition of done | Whole-binary hash inside `make build`, from a clean rebuild | Per-function diff scores; percentage of functions "decompiled" | Only the byte gate cannot be fooled (G3, G61) |
| Compiler | A PsyQ-era cc1 candidate ladder, gcc 2.6.3 + aspsx 2.63 first, then gcc 2.7.2 builds; pinned by probes under exactly one triple | Adopting mmx4's X4 pin as given | A wrong era produces systematic near-misses everywhere (DK-3); mmx4's pin is a lead (G101) |
| Splitter | splat with per-binary configs and a curated symbol file | A bespoke splitter | The community's tool; mmx4 uses it; the kit's pipeline assumes it |
| Segmentation | Translation-unit boundaries at the forced boundaries (jump-table spans, opt levels, library objects) found in Phase 1.2, before any C | Carving boundaries as functions are matched; archaeology of the original file layout | Structural changes grow expensive as matched work accumulates (DK-12) |
| Compressed payloads | Verified on the decompressed payload; a rebuilt disc verifies by booting | Hash-matching recompressed data | Recompression is rarely byte-stable |
| License | AGPL-3.0 for the project's tools and documents; no rights claimed over Capcom's game; adapted mmx4 files keep attribution and license, listed in `THIRD_PARTY.md` | MIT / CC0 | Same license as sozud/mmx4, so proven-shared functions can be adapted with attribution |
| Visibility | Public from the first commit | Private, then a flip | Nothing to hide; the firewall applies either way, so there is no "while private" exemption to regret (DK-1) |
| Prior art | Facts and leads with a status ladder (G101); copying only under a permitting license (G102) | Trusting community names and maps; copying unlicensed tables | Leads mistaken for evidence and license contamination are this project's named risks |
| X4 engine reuse | Measured by a signature scan before any plan depends on it (Phase 1.6) | Planning the campaign around assumed sharing | Prior cross-game scans (DC2, BFM) found only Sony library code shared |
| Build host | amd64 Docker host (Docker Desktop on the Mac), source in a named volume; oracles native on the Mac | Native arm64 builds | The era's compiler binaries and the community toolchains are x86 builds; the developer's DC2 setup is proven |
| Readability | Enforced at draft and bank time (the six inversions) | A readability generation after 100% | The source project paid for a whole generation of after-the-fact readability |
| AI use | Disclosed: "This project is developed with substantial AI assistance; every change is justifiable from recorded evidence, a person reviews each phase gate, names come only from evidence, outward text is written by a person, and contributors disclose AI-generated submissions." | Undisclosed | Community trust; the AI-conduct rules G61–G65 |
| Models and budget | Claude Max 5x; Opus 5.5 for experts and coders, never Fable; the deepest judgments (the compiler pin, every load-address derivation, the segmentation decision, every wall verdict) go to `/discuss max` or are split until routine | One model and effort for everything | The developer's budget and preference; the kit's *Models and effort* list |

---

## Core Logic / Strategy

The pipeline every binary goes through, built in the order of the Generation Map:

1. **Extract** — the project's own deterministic disc/archive extractor (ISO9660 MODE2, `ROCK_X6.BIN` members with
   game-semantics decompression and a length cross-check) writes the extraction tree and a committed **manifest of
   hashes**; a second run reproduces it; sampled payloads are cross-checked against a reference extractor where one
   exists. The manifest — hashes only, never bytes — becomes a `required:` source of the firewall.
2. **Map** — the static oracle (Ghidra + psx_ldr with the era's signatures, served to agents over GhidrAssistMCP) and
   the runtime oracle (PCSX-Redux scripted in Lua) establish every load address from three datapoints or a before/after
   diff (M3); the load map is regenerated from the bytes with control rows; jump-table spans and other forced boundaries
   are recorded.
3. **Split and rebuild at 100% assembly** — splat configs per binary, the Makefile pipeline (preprocessor → vintage
   cc1 → assembler shim → binutils → objcopy → hash check), translation units at the forced boundaries.
4. **Pin the compiler** — probe functions byte-identical under exactly one triple; per-module variation recorded.
5. **Count honestly** — the census and the differential harness, each scanner asserting its coverage, a second oracle
   with 0 phantoms and 0 truncations.
6. **Multiply** — signatures, the twin band, dedup propagation, families, the reconcile ladder, the carve chain, the
   draw filter, and the canonical type layer from the first bank. The X4↔X6 sharing measurement happens here.
7. **Understand the compiler** — the codegen map with a lever per pass group, the permuter, the plateau classifier,
   the cookbook indexed by symptom.
8. **Campaign** — cards, lanes and waves, leverage-first, every wave closed by the harvest gate, every remaining function
   on a named ledger, until 0 stubs.
9. **Publish** — the contract run, the fresh-clone proof, generated numbers, outreach written by a person.
10. **Read** — names with evidence, pins forced-or-gone, no raw casts, one definition per shape, formatting clean, N of N.

### Component Inventory

| Component | Phase built | What it is |
|---|---|---|
| ROM audit + firewall config + planted fixture | 1.0 | Fails the build/CI on any game-derived byte; negative control proves it bites |
| No-ROM CI workflow (`no-rom.yml`) | 1.0 | ROM audit + compile of every translation unit without the game |
| Extractor + manifest + format notes | 1.1 | Deterministic, hash-manifested extraction of the whole disc |
| MCP server wiring, text export + rebuild script | 1.2 | The static oracle, regenerable from tracked text |
| Emulator bridge | 1.2 | The scripted runtime oracle |
| Load-map tool, span/boundary indicator | 1.2 | Load addresses with control rows; forced boundaries for segmentation |
| Makefile pipeline, split configs, per-binary contracts, assembler shim | 1.3 | The byte-identical all-assembly baseline, hash check inside `make build` |
| Decompile scaffold, differ invocation, probe harness, stub headers | 1.4 | The compiler pin and the end-to-end match workflow |
| Corpus oracle, coverage assertions, second boundary oracle, differential harness, census, reports, `build/tools-health.mk` | 1.5 | Honest counting at 0% |
| Signatures + twin band, dedup registry, family remap, declaration sync, canonical type file, carve tools, wall oracle, draw filter | 1.6 | The multipliers and the type layer |
| Codegen map, dump scripts, allocation-table reader, reproducer battery, permuter + masked scorer, plateau classifier, cookbook index tool | 1.7 | Compiler understanding |
| Cards and packs, lanes, wave procedure, journal, target validator, exclude-list audit, worktree gates, recovery ladder, harvest tools, verbatim check | 1.8 | The campaign machinery |
| Contract script, bootstrap script, progress publisher, badges | 1.9 | Publication |
| Allocation-order reader, type lifter, symbol mirror, rename-coverage scanner | 1.10 | Readability |

---

## Safety / Guardrails / Error Handling

- **The ROM firewall from commit one** (G12–G18, DK-1): no byte of the game, the BIOS (`SCPH1001.BIN`) or any
  extraction is ever committed; the audit runs in CI and locally, and its negative control (the planted fixture) must
  fail it. Never `git clean -x` (it deletes the untracked dump-derived tree). The dump lives outside the repository.
- **The byte gate is the only claim** (G3, G61): no report of progress that the hash check did not confirm; no unmatched
  C in a default build (G4).
- **AI conduct** (G61–G65): names only with evidence; outward text (issues, PRs to other projects, releases, community
  posts) written by a person; no automated traffic against community infrastructure (decomp.me, Discord, other repos);
  every change justifiable by a person from the record.
- **Prior art** (G101, G102): leads carry a status and are never banked on below `proven-at-gate`; nothing is copied
  from Kuumba123's repositories or MegaManX6Recomp; mmx4 C only for proven-shared functions, with attribution.
- **Git**: agents commit per task through `tools/commit_task.sh`; the developer pushes; no AI trailers.
- **Scratch** under `.run/` (gitignored), never system temp (H4); a scratch cap with a warning threshold (set in
  Phase 1.1); `make clean` never touches it; pruning is a hand decision.
- **Errors**: a red gate stops the task and is reported as red with its output (P9); a wall is classified by the wall
  oracle, never worked around by loosening a check.

---

## Architecture

### Project Structure

The expected shape (splat convention); Phase 1.3 pins the exact layout and Phase 1.0 the gitignore that keeps every
ROM-derived path out of git.

```
mmx6/
├── PROJECT_CONTEXT.md  GENERATION_PLAN.md  HOW_WE_WORK.md  CLAUDE.md  README.md  LICENSE  THIRD_PARTY.md
├── Makefile                      # build → hash check inside; expected; format; health
├── config/                       # splat configs per binary, symbol files, the firewall config
├── src/                          # matched C, laid out by the game's systems (main exe + overlays)
├── include/                      # the canonical type layer, headers, stub/non-matching headers
├── asm/                          # generated by the splitter (gitignored, ROM-derived)
├── assets/ · disc/               # the extraction tree (gitignored, ROM-derived)
├── expected/                     # `make expected` baseline (gitignored)
├── build/                        # objects, linked binaries (gitignored); build/tools-health.mk is tracked
├── manifest/                     # committed hash manifest of the extraction (hashes only)
├── tools/                        # PA3 tools + the project's extractor, oracles bridges, campaign tools
├── docs/                         # methodology, prior-art.md, memory-map.md, format notes, ops/
├── rules/ · cookbook/ · phase-ends/ · templates/
└── .run/                         # scratch (gitignored, capped)
```

### Services / Dependency Wiring

- **Mac (arm64), native:** Claude Code + PA3; Ghidra 12.1.x + psx_ldr + GhidrAssistMCP (the static oracle, an MCP
  server agents query); PCSX-Redux with its Lua/web interface (the runtime oracle); the dump at
  `/Users/ThinkPad/GameInputs/megaman-x6/`.
- **amd64 Docker host (Docker Desktop on the Mac):** the build — splat, the vintage cc1, the assembler shim, binutils,
  Make — with the source in a named volume for filesystem speed. How the clone on the Mac and the volume stay one tree
  (and which one agents edit) is decided in Phase 1.0 and recorded in `docs/ops/mmx6-hosts.md`.
- **GitHub:** the public repository and the no-ROM CI; the developer pushes.

### Config / Settings

- `config/*.yaml` — one splat config per binary; `config/symbols*.txt` — curated symbols (each name with a basis, G62).
- The firewall config (the audit's `required:` sources, from Phase 1.1 the manifest).
- `.claude/pa.json` — PA3 settings (tier `max5`, rhythm `autonomous`, toast on waiting).
- The scratch cap and warning threshold (Phase 1.1), budgets per lane (G39, Phase 1.8).
- The pinned toolchain triple — a `TODO` until Phase 1.4; recorded in `docs/ops/`.

---

## Testing & Validation Strategy

- **The byte gate:** whole-binary hash per binary inside `make build`; the clean fleet check (`clean → extract → build`
  over every onboarded binary) prints N of N.
- **Negative controls everywhere:** the planted ROM fixture fails the audit; the canonical-type check refuses a planted
  duplicate; the plateau classifier labels a planted plateau; every scanner passes a known-true control.
- **Coverage assertions:** every scanner prints its denominator; denominators come from the build, never typed in.
- **Differential harness:** two independent oracles answer the same questions on a schedule; 0 disagreements, 0 phantoms,
  0 truncations.
- **Runtime proofs (M3):** every load address carries three datapoints or a before/after diff.
- **CI without the game:** the ROM audit and a compile of every translation unit with the pinned toolchain.
- **Validation is phases, not afterthoughts:** Phase 1.5 (the honest census and the harness) and Phase 1.9 (the
  contract run) are validation phases in their own right.

**Pass criteria:** a phase closes only when every `verified by:` clause of its milestone runs green
(`tools/phaseend_index.py verify`); the generation closes at N of N byte-identical from C, published, readable.

---

## Generation Map

*The permanent sketch: what each generation is for, and the milestone-shaped phases it is expected
to need. Milestones only — no task checklists. The live phase list (names, scope, dependencies,
open/closed, PhaseEnd links) is `GENERATION_PLAN.md`, and the tasks of the open phase are
`phase-ends/current/PHASE_PLAN.md`. Where the two disagree, the live plan governs.*

### Generation 1 — The matching decompilation
Scope: the decomp-architect ladder, phases 0–10, numbered 1.0–1.10, on the USA v1.1 disc.
Done when: every code binary on the disc — N of N, N fixed by Phase 1.2's load map — rebuilds byte-identical from C
from a clean rebuild with the check inside the build; every game-code function is C (what is not — the vendor's linked
objects, genuine hand-written assembly — is stated, censused and published); a stranger with their own dump extracts,
builds and verifies from the README alone; the published numbers are generated; readability holds (Phase 1.10).

The Build Roadmap (the kit's canonical ladder, adapted: an advanced developer, so the phases stay fine-grained and the
planner may split Phase 1.8 into waves). Each phase ends at its milestone; `verified by:` is the command the closer
runs; the phase's plan pins exact spellings of commands the phase itself builds.

- **Phase 1.0 Governance and the firewall** — milestone: the ROM audit FAILS on the planted fixture and PASSES on the
  tree; the no-ROM CI workflow is green on the first push (the developer pushes); the constitution carries this
  ladder; `rules/` holds G1–G67 (and this project's G101–G102). Also decides the Mac↔Docker tree arrangement.
  *Verified by:* `python3 tools/audit_public.py` exits 0 on the tree and 1 on the planted fixture;
  `grep -c '| decomp-architect$' rules/INDEX.md` = 67; `gh run list --workflow no-rom.yml -L 1` is green.
  *Tools:* the audit with its config, the fixture, CI, the layout READMEs, `make format`. *Rules from here:* G12–G18,
  G58, G61–G65, G101, G102. *Earned by:* DK-1, DK-53–DK-58.
- **Phase 1.1 Deterministic extraction with a committed manifest** — milestone: one command
  extracts the whole disc (ISO9660 files, `ROCK_X6.BIN` members, XA/STR streams); a second run reproduces the manifest
  identically; sampled payloads agree byte-for-byte with a reference extractor where one exists; `git status` shows
  nothing ROM-derived staged; the audit reads the manifest as a required hash source.
  *Verified by:* the extract command run twice yields the same manifest hash; the reference comparison over the sampled
  payloads reports 0 differences; `python3 tools/audit_public.py` exits 0 with the manifest as a `required:` source.
  *Tools:* the extractor (game-semantics decompression with a length cross-check), the manifest, the format notes.
  *Rules:* G13 (manifest `required:`). *Earned by:* DK-2.
- **Phase 1.2 The oracles and the load map** — milestone: the Ghidra database imported with the era's signatures and the
  detected PsyQ library version recorded; the database's annotations exported as text and the rebuild round-trip
  proven; PCSX-Redux scripted; the load address of `SLUS_013.95` and of at least one `ROCK_X6.BIN` overlay byte-proven
  against a live memory image (the recomp's 59-member / three-base map re-proven or refuted, G101); the load map
  regenerated from the bytes with control rows; jump-table spans and other forced boundaries recorded; N fixed.
  *Verified by:* the text export → rebuild → re-export round trip is byte-equal; the load-map tool's control rows pass;
  each load address cites three datapoints or a before/after diff in `docs/memory-map.md`.
  *Tools:* MCP wiring, text export + rebuild, emulator bridge, load-map tool, span/boundary indicator. *Rules:* G1, G2,
  G5, G6. *Earned by:* DK-13, DK-12, DK-18.
- **Phase 1.3 The all-assembly byte-identical baseline** — milestone: `make build` produces every onboarded binary with a
  hash equal to the original at 100% assembly, the check inside the build; translation-unit boundaries at Phase 1.2's
  forced boundaries; `make expected` baseline set.
  *Verified by:* the clean fleet check prints N of N and exits 0.
  *Tools:* the Makefile pipeline, per-binary contracts, split configs, the boundary check in the health target.
  *Rules:* G9. *Earned by:* DK-2, DK-12.
- **Phase 1.4 The compiler pinned by evidence** — milestone: three to five probe functions byte-identical under exactly
  one candidate triple (gcc 2.6.3 + aspsx 2.63 tried first, as a lead); the triple recorded with its fingerprint
  evidence and the assembler version passed explicitly; per-module variation detected and recorded; the first functions
  matched end to end through the whole workflow.
  *Verified by:* the probe harness reports every probe byte-identical under exactly one triple; the first matched
  functions survive the clean fleet check.
  *Tools:* the decompile scaffold wrapper, the differ invocation, the standalone probe, stub/non-matching headers.
  *Rules:* G8, G10. *Earned by:* DK-3.
- **Phase 1.5 The honest census and the differential harness — at 0%** — milestone: every scanner asserts its coverage;
  a second oracle disagrees with the first on nothing (0 phantoms, 0 truncations); the harness runs at least five
  question pairs on a schedule with 0 disagreements; the census reports duplication, structural families, reach × size
  and the unique tail, each checked against a known-true case; the progress report derives its denominators from the
  build.
  *Verified by:* every scanner prints its denominator and passes its known-true control; the second oracle reports 0
  phantoms and 0 truncations; the harness's scheduled run reports 0 disagreements.
  *Tools:* the corpus oracle, coverage assertions, the second boundary oracle, the differential harness, the census,
  progress/difficulty/duplicate reports, `build/tools-health.mk`. *Rules:* G19–G36. *Earned by:* DK-8, DK-9, DK-17,
  DK-19, DK-30, DK-61.
- **Phase 1.6 The multipliers: propagation, families, twins, the reconcile ladder, the carve chain, the draw filter** —
  milestone: one hand-matched function propagates to every member across the fleet, byte-gated per member, registered
  fail-closed; the twin band reproduces every exact pair and finds more; a standalone match banks into its real
  translation unit by the ladder without a redraft; the opt-level and jump-table carves build; the draw filter refuses
  what cannot bank and counts what it filtered; all four verdict layers consumed; the canonical type layer exists from
  the first bank. The X4↔X6 sharing measurement (signatures against mmx4) is recorded here, with its number.
  *Verified by:* the propagation dry run reports every member byte-gated; the twin band reproduces the known exact
  pairs; the canonical-type check refuses a planted duplicate definition; the clean fleet check stays N of N.
  *Tools:* signatures + band, dedup propagation and registry, family remap, declaration sync / callee casts / canonical
  signatures, the canonical type file with its bank-time checks, carve tools, wall oracle, draw filter, twin rescan.
  *Rules:* G7, G37, G40–G43, G46, G62 (bank-time clause). *Earned by:* DK-5, DK-7, DK-10, DK-11, DK-24, DK-36, DK-65.
- **Phase 1.7 The codegen map and the permuter** — milestone: the map holds at least one byte-proven lever per pass group
  with a symptom-keyed triage table; the compiler's source staged at the pinned version with citations audited; the
  permuter runs on a stored draft and proves it iterated; the plateau classifier labels a plateau; the cookbook seeded
  from the source and sibling projects (mmx4, DC2, BFM), indexed by symptom with its own coverage assertion.
  *Verified by:* the permuter's stored-draft run proves it iterated; the cookbook index check asserts every entry indexed
  and every index row resolving; the plateau classifier labels its planted plateau.
  *Tools:* the map, dump scripts, allocation-table reader, reproducer battery, permuter with a masked scorer, plateau
  classifier, cookbook index tool. *Rules:* G51, G52, G55, G57, G60, G66, G67. *Earned by:* DK-6, DK-14, DK-15, DK-52.
- **Phase 1.8 First cracks, the manual wave, the routing cliff — then the campaign, leverage-first** — milestone: bank
  rate by instruction count measured on a small manual wave and the routing set from it; every wave closes with the
  harvest gate; the fleet green from a clean rebuild after every banked batch; every remaining function on a named
  ledger with a class, a closeness, a best draft and a named blocker; the census reads 0 stubs. (The planner may split
  this phase into waves.)
  *Verified by:* the census reads 0 stubs; every remaining function is on the named ledger; the clean fleet check is
  N of N.
  *Tools:* cards and packs, lanes, the wave procedure, the journal read side, target validator, exclude-list audit,
  gates in worktrees, the recovery ladder, harvest tools, the verbatim check. *Rules:* G38, G39, G44, G45, G47–G50,
  G53, G54, G56. *Earned by:* DK-16, DK-31–DK-35, DK-39–DK-51.
- **Phase 1.9 Publish** — milestone: the contract run recorded (clean rebuild, with and without the vendor SDK, every
  oracle green, N of N); a fresh clone rebuilds from the developer's own dump by the README alone; every published
  number generated with a freshness check; the no-ROM CI green; releases and outreach written by a person.
  *Verified by:* the recorded contract run (both SDK legs, every oracle green, N of N); the fresh-clone proof; the
  progress publisher's freshness check.
  *Tools:* the contract script, the bootstrap script, the progress publisher, badges, release write-ups. *Rules:* G17,
  G58, G63, G64. *Earned by:* DK-56, DK-57, DK-58.
- **Phase 1.10 Readability** (short if the bank-time inversions held: names, pins and formatting) — milestone: 0
  register pins, or each marked as forced with its reason; 0 shared bodies as macros; 0 raw address casts; one
  definition per structure; every renamed symbol with a recorded basis; formatting clean; and, unchanged, N of N.
  *Verified by:* the census reads 0 unmarked pins, 0 macro bodies and 0 raw address casts; `make format-check` passes;
  the clean fleet check is N of N.
  *Tools:* the allocation-order reader, the type lifter, the symbol mirror into the database, the rename-coverage
  scanner. *Rules:* G11, G62. *Earned by:* DK-64, DK-65, DK-47, DK-12; the six inversions.

**Two notes on the order.** Phases 1.5–1.7 look like planning-only phases and are not: each ends in a running tool with
a verifiable output, and each is the reason the campaign banks at the rate it does — the source project built them
reactively, phases later. Tooling-first does not remove the hard tail: novel unique functions and compiler-internal
residuals still need genuine reasoning; it makes the cheap half nearly free and stops the waste (DK-43).

**Readability at day one — the six inversions** (held at draft and bank time from Phase 1.4 on):
1. Pins are recorded at draft time: a draft carrying a register pin is a near-miss with its allocation-order reading;
   a body that cannot be shaped banks with a `// !FAKE:` line; the count is a published metric from the first bank
   (G55, DK-47).
2. Shared bodies live as C files per system from the first propagation, never macro bodies (G7, DK-5).
3. Types are canonical at bank time; no raw address cast is banked; one definition per shape (G62).
4. Names carry evidence, recorded per name — a printed string, a cross-reference chain, a debug menu, a live-memory
   datapoint, a community label with provenance (G62, G101). Unnamed beats wrong.
5. Formatting is installed with the first C file; a bank is formatted before it is committed.
6. File layout follows the game's systems, unit boundaries decided at segmentation from the forced boundaries (DK-12).

Each phase produces something runnable and testable and ends at an observable, machine-checkable
milestone (the gate P9/M1 hold it to). Validation is a phase of its own; enhancement layers are
toggleable and added one at a time.

---

## Enhancement Backlog

- A public preset for decomp.me's matching tool — requested from its maintainers by a person (G63, G64).
- The codegen map, the signature tooling and the drafter pipeline released as standalone tools.
- Additional versions (JP release, v1.0 if one exists) as extra split configs.
- A text-export policy that makes the reverse-engineering database fully regenerable from tracked text.

---

## Future Generations

- **Generation 2 — more versions and a shiftable build.** The JP release (Kuumba123's JP symbol leads; mmx4 already
  carries JP for X4) and the 2001-10-30 prototype as extra split configs; a shiftable build. Requires Generation 1's
  N of N and the type layer.
- **Generation 3 — beyond matching.** Asset export and repacking, native recompilation or a port, randomizer-grade
  tooling, possibly shared X-series engine work with the X4/X5 decompilations. Every one depends on symbolic, legible
  source.

---

## What Success Looks Like

Every code binary on the Mega Man X6 USA v1.1 disc — **N of N** — rebuilds byte-identical from C from a clean rebuild,
with the check inside the build. Every game-code function is C; what is not C (the Sony libraries linked as objects,
genuine hand-written assembly) is stated, censused and published, never hidden. A stranger with their own dump extracts,
builds and verifies from the README alone. Every published number is generated, with a freshness check. The source
reads: names with recorded evidence, canonical types, no raw casts, no unexplained pins, formatted.

---

## Feature & Architecture Inventory

| Feature | Tier | Phase / status |
|---|---|---|
| Deterministic extraction + manifest | core | 1.1 |
| Oracles + load map | core | 1.2 |
| All-assembly byte-identical baseline | core | 1.3 |
| Compiler pinned by evidence | core | 1.4 |
| Honest census + differential harness | core | 1.5 |
| Propagation, families, reconcile ladder, type layer | core | 1.6 |
| Codegen map + permuter | core | 1.7 |
| The campaign to every game-code function | core | 1.8 |
| Publication with the contract run | core | 1.9 |
| Readability to the community's standard | core | 1.10 |
| decomp.me preset; standalone tools; extra versions; text-export policy | stretch | Enhancement Backlog |
| Shiftable build; assets; port/recomp; randomizer; matching model | dream | Parking Lot / later generations |

---

## Data Sources / External Dependencies

| Source | What | License | Treatment |
|---|---|---|---|
| The developer's dump | Redump *Mega Man X6 (USA) (v1.1)*, `.bin`/`.cue` at `/Users/ThinkPad/GameInputs/megaman-x6/`, SHA-1 `d4f7e083…f4ea` | Capcom's; legally owned | Never committed; the ground truth |
| `SCPH1001.BIN` | PlayStation BIOS for the runtime oracle, beside the dump | Sony's | Never committed |
| sozud/mmx4 | Matching decomp of X4 (US + JP): gcc 2.6.3 cc1 + aspsx 2.63, splat, engine structs | AGPL-3.0 | Leads (G101); C adapted only for proven-shared functions with attribution (G102) |
| Kuumba123 `MegaManX6_PS1_Modding`, `MegaManX6_Practice` | ~53 named US addresses, a JP set, object/layer/GPU struct research | none | Facts and leads only; never copied (G102) |
| mstan/MegaManX6Recomp | Static recompilation; `docs/AOT_OVERLAYS.md` overlay-loader map | PolyForm Noncommercial | Overlay-map facts as leads for Phase 1.2; its generated C never an input |
| acediez, *Mega Man X6 Tweaks* (romhacking.net) | Parts/rank table documentation | — | Data-symbol leads |
| Shinnuu's Archipelago X6 world | RAM variables | — | RAM leads |
| TCRF | The 2001-10-30 prototype; the 2002 Korean PC port | — | Parking lot |

Every row is credited in `docs/prior-art.md`, each lead with its status (G101).

---

## Libraries / Dependencies

Pinned as known at generation; exact versions are recorded in `docs/ops/` by the phase that pins them.

- **splat** (splitter) — Phase 1.3.
- **The vintage compiler** — PsyQ-era cc1 candidates (gcc 2.6.3, gcc 2.7.2 builds) + **aspsx 2.63** or the community
  assembler shim reproducing it — Phase 1.4.
- **GNU binutils** (mips) for assemble/link/objcopy; a modern preprocessor — Phase 1.3.
- **Ghidra 12.1.x + psx_ldr + GhidrAssistMCP** — Phase 1.2.
- **PCSX-Redux** (Lua scripting) — Phase 1.2.
- **Docker Desktop** (amd64 build image) — Phase 1.0/1.3.
- **Python 3.14** (`/opt/homebrew/opt/python@3.14/bin/python3.14`, per `.claude/pa.json`) — tools.
- **The community formatter configuration** — installed with the first C file (Phase 1.0's `make format`).
- **A permuter** (decomp-permuter or equivalent) — Phase 1.7.

---

## Parking Lot

- A shiftable build.
- Asset export and repacking.
- Native recompilation or a port.
- Randomizer-grade tooling.
- A community-trained matching model.
- The JP release as a second split config.
- The 2001-10-30 prototype.
- The 2002 Korean/Asian PC port (Multi-Enterprise) as a cross-check of function structure.
- A full X4↔X6 shared-engine scan against the developer's own X4 dump.

---

## Notes for Future Phases

- **Phase 1.0:** decide and record how the Mac clone (where PA3 and the agents work) and the Docker named volume (where
  the build runs) stay one tree — the intake records the DC2 arrangement as the model, not a decision. Seed
  `THIRD_PARTY.md` empty with its format; `docs/prior-art.md` is seeded at intake.
- **Phase 1.1:** set the scratch cap.
- **Phase 1.2:** the recomp's overlay map (59 members, three bases) and Kuumba123's addresses are leads to re-prove,
  not inputs. The load-address derivations are `/discuss max` judgments.
- **Phase 1.4:** try mmx4's pin first; it is the cheapest probe, not a conclusion. The pin is a `/discuss max` judgment.
- **Phase 1.6:** the X4↔X6 measurement may not need an X4 dump: mmx4's matched C compiled with its own toolchain yields
  X4 bytes for its matched functions, a signature source on its own. A lead to evaluate, not a decision.
- **Phase 1.8:** size waves to the Max 5x budget; free local work first. The planner may split this phase.
- Every wall verdict and the segmentation decision go to `/discuss max` or are split until routine (the kit's
  *Models and effort* list in `docs/ops/decomp-environment.md`).
