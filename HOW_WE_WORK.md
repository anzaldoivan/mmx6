# How we work — mmx6

<!-- The card: standing facts for every agent. Never appended to; the cap is
     card.max_chars in .claude/pa.json (default 7000), enforced by the archive.
     Each role prints its slice with `tools/card.py slice <role>`.
     Written at install (interview) and edited in the same task as whatever changed it (H7). -->

## Project <!-- roles: expert coder router planner review critic discuss auditor curator -->
mmx6 — a matching decompilation of Mega Man X6 (PlayStation, USA SLUS-01395 v1.1): byte-identical C, the hash check inside the build. Constitution `PROJECT_CONTEXT.md`; roadmap `GENERATION_PLAN.md`;
rules `rules/INDEX.md`; techniques `cookbook/INDEX.md`; ops detail `docs/ops/INDEX.md`.

## Developer <!-- roles: router planner review discuss auditor curator -->
Who: anzaldoivan, solo. Experience: advanced; shipped BFM-decomp (PSX) to 100% byte-identical; runs
dino-crisis-2-decomp on PA3 with the decomp kit. Domain: PSX matching decompilation (MIPS, PsyQ).
Budget: Claude Max 5x; free, local, deterministic work before paid work. Models: Opus 5.5 for experts and
coders, never Fable; the deepest judgments via `/discuss max`. Breadth fan-out welcome when the plan names it.
Preferences: recommendations, not questions. Plain-English recaps at phase end. A notification
whenever anything waits on them. Autonomy: full inside an approved plan; stop only at the two gates. Notification channel: toast.
The developer pushes; agents never do. They ratify rules at the next planner session.

## Rhythm <!-- roles: router planner review discuss auditor curator -->
autonomous  <!-- autonomous: the router runs the phase end to end, stopping only at the two gates.
                  review: tasks marked `review: yes` end the turn with REVIEW.md and wait. -->
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
| <!-- TODO PROJECT_TOOL: no source found --> | `<!-- TODO PROJECT_TOOL_COMMAND: no source found -->` | <!-- TODO PROJECT_TOOL_PURPOSE: no source found --> |

## Skills <!-- roles: expert planner -->
<!-- one line per captured workflow; the SKILL.md is the canonical text -->
- <!-- TODO SKILL_NAME: no source found --> — <what it automates, when to invoke it>
- docker-vm-no-privileged — Never probe the Docker VM with --privileged or --pid=host; the classifier treats it as containment escape

## Paths <!-- roles: expert coder router planner review critic discuss auditor curator -->
- Oracles (the ground truth X3 names): <!-- TODO ORACLES: no source found -->
- Data: <!-- TODO DATA_PATHS: no source found -->
- Generated (never hand-edited, H1): <!-- TODO GENERATED_PATHS: no source found -->
- Hand-edited: <!-- TODO HAND_EDITED_PATHS: no source found -->
- Scratch: `.run/` (gitignored; never the system temp)

## Build / run / test <!-- roles: expert coder router planner review critic discuss auditor curator -->
- Build: `<!-- TODO BUILD_COMMAND: no source found -->`
- Run: `<!-- TODO RUN_COMMAND: no source found -->`
- Test / the gate: `<!-- TODO TEST_COMMAND: no source found -->` — green means <!-- TODO GREEN_MEANS: no source found -->
- Modes: <!-- TODO TEST_MODES: no source found -->
Long gates go through `tools/run.sh` with a raised timeout, never a poll loop.

## Conventions & house style <!-- roles: expert coder router planner review critic discuss auditor curator -->
- <!-- TODO PROJECT_CONVENTION: no source found -->
<!-- project-specific only; the general house style is in the project-architect skill -->

## Environment <!-- roles: expert coder router planner review critic discuss auditor curator -->
- OS / shells: Darwin / bash, zsh
- Python: /opt/homebrew/opt/python@3.14/bin/python3.14 (3.14.7)
- Pins: <!-- TODO PINS_SUMMARY: no source found --> — detail in `docs/ops/INDEX.md`
- Harness gotchas that bite here: <!-- TODO HARNESS_GOTCHAS: no source found -->

## Docs map <!-- roles: expert coder router planner review critic discuss auditor curator -->
- `docs/ops/INDEX.md` — setup, env, pins, per-topic ops notes
- `cookbook/INDEX.md` — techniques, grep by tag
- `rules/INDEX.md` — full rule texts
- `phase-ends/TASK_INDEX.md`, `phase-ends/RESEARCH_INDEX.md` — what was done and what was learned
- `docs/research-archive/` — migrated legacy reports
- `docs/retired/` — everything moved out of the load order
- `docs/decomp-architect.md` — the decomp method; `docs/README.md` maps the decomp docs (kernels, tools manifest, wave playbook, corpus front pages); `docs/ops/decomp-environment.md`
