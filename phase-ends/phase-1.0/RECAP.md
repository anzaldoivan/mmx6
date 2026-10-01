MILESTONE: green

## Recap
Phase 1.0 set up the ground the decompilation will stand on, before any game code is touched. It closed two gaps in the firewall that keeps game data out of the public repository (the disc folder and the console BIOS file), and checked that every commit before the first push was clean. It decided how the Mac and the build container share work: agents edit only the Mac copy, a script copies that tree into a disposable Docker volume, builds run there, and results come back only through an explicit pull. It pinned the container image and the code formatter version, proved that `make format` reformats a planted C file inside the container, and filled in the layout READMEs and the project card. The developer pushed, and the public CI job that audits for game data passed.

## Verification (phaseend_index verify, 2026-10-01)
- Clause 1 `audit_public.py` exit 0: GREEN (.run/logs/verify1.log).
- Clause 2 planted fixture: tool reported RED, judged GREEN. The clause requires exit 1 naming `OFFENDER .run/firewall-control/planted.bin`; verify2.log and a direct re-run both show rc=1 and that exact OFFENDER line. The verifier treats any nonzero exit as RED, so it cannot express an expected failure. Planted file removed after the run.
- Clause 3 rules 67 + G101/G102: GREEN. Clause 4 T3 format proof: GREEN. Clause 5 no-rom CI `success`: GREEN.
- harness: `phaseend_index.py verify` marks a clause whose expected result is a nonzero exit as RED; milestone clauses of the form "exit 1 naming X" need manual confirmation until the verifier honours expected exit codes.

## H7 check
- T2 (Dockerfile pin, new mx.sh) lists docs/ops/mmx6-hosts.md; T3 (formatter pin) lists docs/ops; T4 lists HOW_WE_WORK.md. T1 changed only firewall config (.gitignore, config/firewall.txt), which is not a tool, hook, setting, pin or build command. No misses.

## Promoted
- generalizable: C0009 (fnmatch `**/X` root miss, T1), C0010 (docker pin by config digest, T2).
- workflow: skill `ci-wait-after-push` (T5).

## Decisions that still bind
- Agents edit the Mac clone only; `mmx6-work` is disposable; `mx.sh sync` before any run after host edits; outputs return only via `mx.sh pull`; no bind mounts (environment fact: card Conventions, docs/ops/mmx6-hosts.md:9-17).
- `mx.sh pull` refuses absolute paths, `..` and firewall paths (environment fact: docs/ops/mmx6-hosts.md:13).
- Formatting runs only in the container: `mx.sh sync && mx.sh run make format && mx.sh pull <paths>` (environment fact: card Modes, docs/ops/mmx6-hosts.md:32).
- Next task needs: `phaseend_index.py verify` support for expected nonzero exits (harness, out of project scope; for the auditor/planner).
