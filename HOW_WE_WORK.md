# How we work — mmx6

<!-- The card: standing facts. Never appended to; cap card.max_chars (.claude/pa.json).
     Read via `tools/card.py slice <role>`. Edited in the task that changes a fact (H7). -->

## Project <!-- roles: expert coder router planner review critic discuss auditor curator -->
mmx6 — a matching decompilation of Mega Man X6 (PlayStation, USA SLUS-01395 v1.1): byte-identical C, hash-checked in the build.

## Developer <!-- roles: router planner review discuss auditor curator -->
Who: anzaldoivan, solo. Experience: advanced; shipped BFM-decomp (PSX) to 100% byte-identical; runs
dino-crisis-2-decomp on PA3 with the decomp kit. Domain: PSX matching decompilation (MIPS, PsyQ).
Budget: Claude Max 5x; free, local, deterministic work before paid work. Models: Opus 5.5 for experts and
coders, never Fable; the deepest judgments via `/discuss max`. Breadth fan-out welcome when the plan names it.
Preferences: recommendations, not questions. Plain-English recaps at phase end. A notification
whenever anything waits on them. Autonomy: full inside an approved plan; stop only at the two gates. Notification channel: toast.
The developer pushes; agents never do. They ratify rules at the next planner session.

## Rhythm <!-- roles: router planner review discuss auditor curator -->
autonomous  <!-- autonomous: router runs the phase, stops only at the gates; review: `review: yes` tasks wait on REVIEW.md -->
Gates: plan approval (planner session) and the milestone (verified by the closer expert).

## Tools <!-- roles: expert coder router planner review critic discuss auditor curator -->
PY = /opt/homebrew/opt/python@3.14/bin/python3.14

| Name | Command | Purpose |
|---|---|---|
| launch | `PY tools/launch.py --seed-only` | state detector → `.run/seed.md` |
| plan_edit | `PY tools/plan_edit.py` | the only writer of `PHASE_PLAN.md` (status, Changes, add/reopen) |
| status | `PY tools/status.py` | statusline `.run/status.json`; INBOX; waiting flags |
| task_log | `PY tools/task_log.py` | lint and finish a task summary (`Verified:` required) |
| research_add | `PY tools/research_add.py` | allocate a report id, write the index line |
| rules_add | `PY tools/rules_add.py` | add, supersede, promote, retire a rule |
| skill_add | `PY tools/skill_add.py` | turn a `workflow:` gotcha into `.claude/skills/<name>/SKILL.md` |
| cookbook_add | `bash tools/cookbook_add.sh` | add a cookbook entry and its index line |
| phaseend_index | `PY tools/phaseend_index.py` | assemble, lint and archive a PhaseEnd |
| genend_index | `PY tools/genend_index.py` | assemble and lint a GenerationEnd |
| commit_task | `bash tools/commit_task.sh` | the only commit path; explicit paths, no trailers, never pushes |
| run | `bash tools/run.sh` | any command that may print >40 lines; `--bg` / `--wait` for long compute |
| extract | `mx.sh run make extract` | dump → `extracted/retail/` + `manifest/retail.jsonl` |
| mx.sh | `bash tools/docker/mx.sh build\|sync\|pull <path>\|disc <dir>\|run <cmd>` | amd64 container `mmx6-build`; tree at /work, dump at /disc:ro |
| probe | `mx.sh run make probe-ladder`; `probe.py <func> --prog p --src c --triple t` | masked compare to retail; `PIN …` |
| decompile | `mx.sh run python3 tools/mmx6/decompile.py <func> [--prog p]` | m2c scaffold |
| diff | `mx.sh run bash tools/mmx6/diff.sh <func>` (after `make expected`) | asm-differ; `DIFF <func> <n>`, rc 0 iff n=0 |
| scanners | `mx.sh run python3 tools/mmx6/<t>.py --all\|--self-test`, t = corpus optscan bound2 census report sig walls draw (after `make extract build`) | → build/; tools-health rungs |
| bank path | `mx.sh run python3 tools/mmx6/<t>.py`, t = bank propagate family_remap carve typecheck declsync x4share | usage: docs/ops/decomp-environment.md |
| codegen | same, t = gccsrc dumps alloc_table repro codegen_map cookbook_check permute plateau | as bank path; map docs/codegen-map/README.md |
| harness | `mx.sh run python3 tools/mmx6/harness.py --sampled\|--full\|--self-test` | pairs P1-P8 → build/harness/runs.log |
| toolchain-check | `mx.sh run make toolchain-check` | versions + cc1/maspsx smoke; rc≠0 drift |

## Skills <!-- roles: expert planner -->
<!-- one line per workflow; SKILL.md is canonical -->
- docker-vm-no-privileged — never probe the Docker VM with --privileged/--pid=host (containment escape)
- ci-wait-after-push — after a push: run.sh --bg gh run watch, then --wait < 285 s
- container-scratch-not-synced — Mac .run/ never syncs, sync wipes build/: make and read in one run
- typecheck-fnptr-keyer-first — extend typecheck.py's keyer before the first fn-pointer typedef

## Paths <!-- roles: expert coder router planner review critic discuss auditor curator -->
- Oracles (native Mac): Ghidra 12.1.3 + psx_ldr (docs/ops/oracles.md)
- Data: dump `/Users/ThinkPad/GameInputs/megaman-x6/` (never under the repo) → volume `mmx6-disc` at /disc:ro (`mx.sh disc`)
- Generated (never hand-edited, H1; ignored): `asm/`, `build/`, `expected/`, `extracted/`
- Manifest: `manifest/retail.jsonl` (tracked; hashes only; firewall `required:`)
- Hand-edited: `src/`, `include/`, `config/`
- Scratch: `.run/` (gitignored; never the system temp)

## Build / run / test <!-- roles: expert coder router planner review critic discuss auditor curator -->
- Build: `mx.sh sync && mx.sh run make fleet` (sync wipes /work)
- Run: `make redux-smoke`, `tools/mmx6/redux/run.sh <lua>` (PCSX-Redux headless; docs/ops/oracles.md)
- Test / the gate: `make fleet` (health runs `make tools-health`, harness `--sampled`) → rc 0 + last line `FLEET 57 of 57`, then `PY tools/audit_public.py` → rc 0
- Exhaustive: after fleet, `mx.sh run make tools-health-full` (every self-test, harness `--full`) → `TOOLS-HEALTH OK <k> rungs`
- Format: `mx.sh run make format-check` (rc 0); fix: `mx.sh run make format && mx.sh pull <paths>`

## Conventions & house style <!-- roles: expert coder router planner review critic discuss auditor curator -->
- Agents edit the Mac tree only; `mx.sh sync` before any `mx.sh run` after host edits; outputs return only via `mx.sh pull <relpath>`; no bind mounts
<!-- project-specific only; general style: project-architect skill -->

## Environment <!-- roles: expert coder router planner review critic discuss auditor curator -->
- OS / shells: Darwin / bash, zsh
- Python: PY (3.14.7)
- Pins (image and every tool): docs/ops/mmx6-hosts.md
- Compiler pin: `gcc2.95.2-psx-aspsx2.86` = Makefile `TRIPLE`, all programs (docs/ops/compiler-pin.md)
- Harness gotchas: `tools/audit_public.py --help` runs the full audit; a hook denies `cat` of product files (use Read)

## Docs map <!-- roles: expert coder router planner review critic discuss auditor curator -->
- `docs/ops/INDEX.md` ops notes; `cookbook/INDEX.md` techniques; `rules/INDEX.md` rule texts
- `phase-ends/TASK_INDEX.md`, `phase-ends/RESEARCH_INDEX.md` — tasks, research
- `docs/research-archive/` legacy reports; `docs/retired/` out of load order; `docs/README.md` decomp docs map
