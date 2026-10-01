# How we work — mmx6

<!-- The card: standing facts. Never appended to; cap card.max_chars (.claude/pa.json).
     Read via `tools/card.py slice <role>`. Edited in the task that changes a fact (H7). -->

## Project <!-- roles: expert coder router planner review critic discuss auditor curator -->
mmx6 — a matching decompilation of Mega Man X6 (PlayStation, USA SLUS-01395 v1.1): byte-identical C, hash-checked in the build. Constitution `PROJECT_CONTEXT.md`; roadmap `GENERATION_PLAN.md`.

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
| launch | `PY tools/launch.py --seed-only` | the pa-session's state detector; writes `.run/seed.md`; never typed by the developer |
| plan_edit | `PY tools/plan_edit.py` | the only writer of `PHASE_PLAN.md` (status, Changes, add/reopen) |
| status | `PY tools/status.py` | `.run/status.json` for the statusline; INBOX consume; waiting flags |
| task_log | `PY tools/task_log.py` | lint and finish a task summary (`Verified:` required) |
| research_add | `PY tools/research_add.py` | allocate a report id, write the index line |
| rules_add | `PY tools/rules_add.py` | add, supersede, promote, retire a rule |
| skill_add | `PY tools/skill_add.py` | turn a `workflow:` gotcha into `.claude/skills/<name>/SKILL.md` |
| cookbook_add | `bash tools/cookbook_add.sh` | add a cookbook entry and its index line |
| phaseend_index | `PY tools/phaseend_index.py` | assemble, lint and archive a PhaseEnd |
| genend_index | `PY tools/genend_index.py` | assemble and lint a GenerationEnd |
| commit_task | `bash tools/commit_task.sh` | the only commit path; explicit paths, no trailers, never pushes |
| run | `bash tools/run.sh` | any command that may print >40 lines; `--bg` / `--wait` for long compute |
| extract | `mx.sh run make extract` (host: `make extract PYTHON=PY CUE=<cue>`) | dump → ignored `extracted/retail/` + `manifest/retail.jsonl` |
| mx.sh | `bash tools/docker/mx.sh build\|sync\|pull <path>\|disc <dir>\|run <cmd>` | amd64 container `mmx6-build`; tree volume at /work, dump at /disc:ro |
| probe | `mx.sh run make probe-ladder`; `tools/mmx6/probe.py <func> --prog p --src c --triple t` | masked compare to retail; `PIN …`, rc 0 iff unique |
| decompile | `mx.sh run python3 tools/mmx6/decompile.py <func> [--prog p]` | m2c scaffold on stdout |
| diff | `mx.sh run bash tools/mmx6/diff.sh <func>` (after `make extract build expected`) | asm-differ; ends `DIFF <func> <n> …`, rc 0 iff n=0 |
| optscan | `mx.sh run python3 tools/mmx6/optscan.py --all\|--prog p` (after `make extract split`) | codegen census; docs/ops/compiler-pin.md |
| toolchain-check | `mx.sh run make toolchain-check` | versions + cc1/maspsx smoke; rc ≠ 0 on pin drift |

## Skills <!-- roles: expert planner -->
<!-- one line per captured workflow; the SKILL.md is the canonical text -->
- docker-vm-no-privileged — Never probe the Docker VM with --privileged or --pid=host; the classifier treats it as containment escape
- ci-wait-after-push — Wait for GitHub CI after a push: run.sh --bg gh run watch, then run.sh --wait under 285 s

## Paths <!-- roles: expert coder router planner review critic discuss auditor curator -->
- Oracles (native Mac): static Ghidra 12.1.3 + psx_ldr, `make ghidra-import PYTHON=PY` (docs/ops/oracles.md)
- Data: dump `/Users/ThinkPad/GameInputs/megaman-x6/` (never under the repo) → volume `mmx6-disc` at /disc:ro (`mx.sh disc`)
- Generated (never hand-edited, H1; ignored): `asm/`, `build/`, `expected/`, `extracted/`
- Manifest: `manifest/retail.jsonl` (tracked; hashes only; firewall `required:`)
- Hand-edited: `src/`, `include/`, `config/`
- Scratch: `.run/` (gitignored; never the system temp)

## Build / run / test <!-- roles: expert coder router planner review critic discuss auditor curator -->
- Build: `mx.sh sync && mx.sh run make fleet` (clean → extract → split → build → health; sync wipes /work; image `mx.sh build`); `mx.sh run make expected` → asm-differ baseline
- Run: `make redux-smoke` / `bash tools/mmx6/redux/run.sh <lua> [--timeout S]` (PCSX-Redux headless; docs/ops/oracles.md)
- Test / the gate: `make fleet` (as Build) → rc 0 + last line `FLEET 57 of 57`, then `PY tools/audit_public.py` → rc 0
- Modes: format `mx.sh sync && mx.sh run make format-check` (rc 0); fix: `mx.sh run make format && mx.sh pull <paths>`

## Conventions & house style <!-- roles: expert coder router planner review critic discuss auditor curator -->
- Agents edit the Mac tree only; `mx.sh sync` before any `mx.sh run` after host edits; outputs return only via `mx.sh pull <relpath>`; no bind mounts
<!-- project-specific only; general style: project-architect skill -->

## Environment <!-- roles: expert coder router planner review critic discuss auditor curator -->
- OS / shells: Darwin / bash, zsh
- Python: /opt/homebrew/opt/python@3.14/bin/python3.14 (3.14.7)
- Pins: image `ubuntu:24.04@sha256:008173c2…`, clang-format 18.1.3, splat64 0.50.0, binutils 2.42, cpp 12.4.0, cc1 set /opt/cc (old-gcc 0.17 + 0.9), maspsx @7686f84, m2c @708d2d2, asm-differ @0dd09af (docs/ops/mmx6-hosts.md)
- Compiler pin: `gcc2.95.2-psx-aspsx2.86` = Makefile `TRIPLE`, all programs (docs/ops/compiler-pin.md)
- Harness gotchas that bite here: `tools/audit_public.py --help` runs the full audit; a hook denies `cat` of product files (use Read)

## Docs map <!-- roles: expert coder router planner review critic discuss auditor curator -->
- `docs/ops/INDEX.md` — setup, env, pins, per-topic ops notes
- `cookbook/INDEX.md` — techniques, grep by tag
- `rules/INDEX.md` — full rule texts
- `phase-ends/TASK_INDEX.md`, `phase-ends/RESEARCH_INDEX.md` — tasks, research
- `docs/research-archive/` — legacy reports; `docs/retired/` — out of the load order
- `docs/README.md` — map of the decomp docs (method: `docs/decomp-architect.md`)
