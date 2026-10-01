# PhaseEnd — Phase 1.0: Governance and the firewall (implements Gen 1.0)
Approved: 2026-10-01 | Closed: 2026-10-01 | Planner: claude-opus-5-5/medium | Tasks: 5 done, 0 superseded

## Milestone
Milestone: the ROM audit passes on the tree and fails on the planted fixture; rules/INDEX.md holds 67 decomp-architect rows plus G101, G102; the Mac↔Docker arrangement is recorded in `docs/ops/mmx6-hosts.md` and proven by `make format` run inside the amd64 container on a planted C file from the tree the agents edit; no-rom CI green after the developer's push — verified by: `PY tools/audit_public.py` exit 0; `mkdir -p .run/firewall-control && printf 'DECOMP-FIXTURE!!' > .run/firewall-control/planted.bin && PY tools/audit_public.py --paths .run/firewall-control/planted.bin` exit 1 naming `OFFENDER .run/firewall-control/planted.bin`; `grep -c '| decomp-architect$' rules/INDEX.md` = 67 and `grep -cE '^G10[12] ' rules/INDEX.md` = 2; T3's recorded format proof (`bash tools/docker/mx.sh sync && bash tools/docker/mx.sh run make format` then `mx.sh pull` changed the planted file, `make format-check` exit 0 in the container); `gh run list --workflow no-rom.yml -L 1` conclusion `success`
Verified: gh run list --workflow no-rom.yml -L 1 --json conclusion,headSha → conclusion success, headSha 75531132167d76cd930d093ebcfdd619f0e53113 (pushed HEAD)

## Tasks
- T1 — firewall verify, history audit, purge gaps | Done: Firewall re-verified (tree, fixture, purge-path controls); full git history (all 11 commits incl. the 8 unpushed) audited clean; `disc/` and BIOS `SCPH*.BIN` now forbidden in both .gitignore and config/firewall.txt. | commit: - | tasks/T1.md | logs/T1.md
- T2 — pinned image and the Mac↔volume arrangement | Done: Build image pinned by digest; `tools/docker/mx.sh build|sync|pull|disc|run` drives one tree (Mac clone → volume `mmx6-work`); arrangement recorded in docs/ops/mmx6-hosts.md; round trip and disc sha1 proven. | commit: - | tasks/T2.md | logs/T2.md
- T3 — make format proven in the container | Done: `make format` / `make format-check` proven end to end through mx.sh (sync → format → pull); formatter pinned in docs/ops/mmx6-hosts.md. | commit: - | tasks/T3.md | logs/T3.md
- T4 — layout READMEs and the card's TODOs | Done: config/, src/, include/ READMEs added and .run/README.md condensed (each ≤ 15 lines: contents, generated vs hand-edited, firewall rule); card TODOs filled: mx.sh in Tools, Paths, Build (TODO(phase n) markers), Conventions, Pins, Harness gotchas. | commit: - | tasks/T4.md | logs/T4.md

## Decisions that still bind
- T2 — agents edit the Mac clone only; `mmx6-work` at /work is disposable; `mx.sh sync` before any run after host edits; container outputs return only via `mx.sh pull <relpath>`; no bind mounts of host paths.
- T2 — `mx.sh pull` refuses absolute paths, `..`, and any firewall purge/glob path (G12).
- T3 — formatting runs only in the container: `mx.sh sync && mx.sh run make format && mx.sh pull <paths>`; the Mac has no clang-format.
- Agents edit the Mac clone only; `mmx6-work` is disposable; `mx.sh sync` before any run after host edits; outputs return only via `mx.sh pull`; no bind mounts (environment fact: card Conventions, docs/ops/mmx6-hosts.md:9-17).
- `mx.sh pull` refuses absolute paths, `..` and firewall paths (environment fact: docs/ops/mmx6-hosts.md:13).
- Formatting runs only in the container: `mx.sh sync && mx.sh run make format && mx.sh pull <paths>` (environment fact: card Modes, docs/ops/mmx6-hosts.md:32).
- Next task needs: `phaseend_index.py verify` support for expected nonzero exits (harness, out of project scope; for the auditor/planner).

## Rules proposed
- (none)

## Cookbook entries added
C0009 | fnmatch **/X misses root-level X; add a sibling root glob | firewall,glob,fnmatch,audit | 2026-10-01 | 1.0/T1 | mmx6 T1
C0010 | Pin docker images by config digest, not image Id, under buildx | docker,pin,buildx,reproducibility | 2026-10-01 | 1.0/T2 | mmx6 T2

## Research
- (none)

## Audit
- seed: median 14k, max 14k, n=7 (phase 1.0)
- CLAUDE.md: 1242 bytes
- .claude/skills/ci-wait-after-push/SKILL.md: 799 bytes
- .claude/skills/docker-vm-no-privileged/SKILL.md: 774 bytes
- .claude/skills/project-architect/SKILL.md: 13448 bytes
- .claude-state/memory/MEMORY.md: 214 bytes
- HOW_WE_WORK.md: 6502 bytes
- cookbook/INDEX.md: 2000 bytes
- rules/INDEX.md: 10300 bytes
### Carry audit — phase 1.0 (2026-10-01T04:03:32Z → open UTC, 1 sessions, 127 requests)

| file (read) | chars | n |
|---|---|---|
| HOW_WE_WORK.md | 6.1k | 1 |
| spec.md | 5.8k | 1 |
| mmx6-hosts.md | 5.6k | 4 |
| README.md | 2.5k | 1 |
| firewall.txt | 2.2k | 1 |
| Dockerfile | 938 | 1 |
| REVIEW.template.md | 847 | 1 |
| INDEX.md | 266 | 1 |
| file (write) | chars | n |
|---|---|---|
| spec.md | 5.6k | 1 |
| mx.sh | 3.3k | 2 |
| RECAP.md | 2.7k | 1 |
| HOW_WE_WORK.md | 2.5k | 13 |
| T2.md | 2.5k | 1 |
| T1.md | 2.5k | 1 |
| T1.md | 2.4k | 1 |
| T2.c1.md | 2.3k | 1 |
| result kind | chars | n |
|---|---|---|
| tools/card.py | 91.1k | 7 |
| bash other | 36.4k | 26 |
| run.sh | 30.4k | 21 |
| Read | 24.2k | 11 |
| Agent | 10.6k | 10 |
| tools/plan_edit.py | 8.8k | 9 |
| tools/task_log.py | 8.8k | 5 |
| tools/audit_public.py | 3.4k | 7 |
| Edit | 2.7k | 19 |
| Write | 2.5k | 17 |
- spilled: 1 results, 40.5k chars on disk, 0 read whole
- whole reads over 20.0k: 0
- seed floor: retriever-code 5,279 (n 1, prev —)
- outline credit: 0 outlines · 0 followed by a ranged read · 0 chars credited
- warm pings: 0 pings over 0 runs, 0 warmed waits over the TTL, rewrites across warmed waits 0, waits past the cap 0, pings cost $0.0000 vs rewrites replaced $0.0000, cheaper than one rewrite: n/a
- toasts by cause (waiting): question 0, review 0, replan 0, permission 0, input 0, discussion 0, crash 0, idle 0, stop 0, subagent-stop 0, model 0, other 0
- router turns by cause: loop 8, relay 0, re-arm 0, other 1, relay cost $0.0000
- retriever re-asks: 0 of 0 retriever briefs repeat a lookup of the same run
- router: pa-session e4e46fb8 · requests 29 · ctx at end 55.7k · growth T1 +534, T2 +571, T3 +461, T4 +474, T5 +728, T5 +517 · top: Agent 8.5k/8, tools/plan_edit.py 2.5k/6, tools/status.py 2.3k/8, tools/managed.py 1.6k/1, other 699/2
- noise: 11 lines 593 chars — usage: : 6 lines/345, No such file or directory: 5 lines/248
- price: read $0.20/Mtok · 1h write $6.67/Mtok · output $16.68/Mtok (phase model mix)
- median requests after a read: 1
- carry/request: 1786 chars, 127 requests
- flag: 1 tool-source reads by coder-opus55
  /Users/ThinkPad/orca/mmx6/tools/docker/Dockerfile  938 chars  coder-opus55

## Agent runs
- T1 | expert-opus55 | expert | claude-opus-5-5 | medium | ctx 33k | $0.241 | saved - | completed | parent d585a8a6
- T2 | expert-opus55 | expert | claude-opus-5-5 | medium | ctx 33k | $0.170 | saved - | completed | parent d585a8a6
- T2 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 30k | $0.201 | saved - | completed | parent a23a4a66
- T2 | expert-opus55 | expert | claude-opus-5-5 | medium | ctx 34k | $0.187 | saved - | completed | parent d585a8a6
- T2 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 27k | $0.236 | saved - | completed | parent afdd60fb
- T2 | expert-opus55 | expert | claude-opus-5-5 | medium | ctx 29k | $0.175 | saved - | completed | parent d585a8a6
- T1 | expert-opus55 | expert | claude-opus-5-5 | medium | ctx 39k | $0.323 | saved - | completed | parent e4e46fb8
- T2 | expert-opus55 | expert | claude-opus-5-5 | medium | ctx 35k | $0.177 | saved - | completed | parent e4e46fb8
- T2 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 36k | $0.325 | saved - | completed | parent a0e70dd8
- T3 | expert-opus55 | expert | claude-opus-5-5 | medium | ctx 31k | $0.166 | saved - | completed | parent e4e46fb8
- T4 | expert-opus55 | expert | claude-opus-5-5 | medium | ctx 47k | $0.313 | saved - | completed | parent e4e46fb8
- T4 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 31k | $0.280 | saved - | completed | parent a85ab367
- T5 | expert-opus55 | expert | claude-opus-5-5 | medium | ctx 33k | $0.214 | saved - | completed | parent e4e46fb8
- T5 | review | review | claude-opus-5-5 | medium | ctx 19k | $0.107 | saved - | completed | parent e4e46fb8
- T5 | expert-opus55 | expert | claude-opus-5-5 | medium | ctx 22k | $0.134 | saved - | completed | parent e4e46fb8
- T5 | expert-opus55 | expert | claude-opus-5-5 | medium | ctx 33k | $0.178 | saved - | completed | parent e4e46fb8

## Discussions
- I1 | T5 pushed main at 7553113; respawn T5 to record the no-rom CI result | dropped

## Deferred
- from T5: CI is live on push; every later push must keep audit_public green. (unconsumed)

## Changes
- 2026-10-01 router: T1 next -> done
- 2026-10-01 router: T2 next -> done
- 2026-10-01 router: T3 next -> done
- 2026-10-01 router: T4 next -> done
- 2026-10-01 router: T5 next -> done

## Plain-English Recap
Phase 1.0 set up the ground the decompilation will stand on, before any game code is touched. It closed two gaps in the firewall that keeps game data out of the public repository (the disc folder and the console BIOS file), and checked that every commit before the first push was clean. It decided how the Mac and the build container share work: agents edit only the Mac copy, a script copies that tree into a disposable Docker volume, builds run there, and results come back only through an explicit pull. It pinned the container image and the code formatter version, proved that `make format` reformats a planted C file inside the container, and filled in the layout READMEs and the project card. The developer pushed, and the public CI job that audits for game data passed.
