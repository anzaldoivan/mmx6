# PhaseEnd — Phase 1.1: Deterministic extraction with a committed manifest (implements Gen 1.1)
Approved: 2026-10-01 | Closed: 2026-10-01 | Planner: claude-opus-5-5/medium | Tasks: 5 done, 0 superseded

## Milestone
Milestone: one command extracts the whole disc (9 ISO9660 files, the 59 `ROCK_X6.BIN` members with game-semantics decompression and a length cross-check, XA/STR streams); two runs yield the same manifest hash; sampled payloads match a reference extractor with 0 differences where one exists; `config/medium.sha1` and the committed manifest `manifest/retail.jsonl` (replaces `extracted/retail/manifest.jsonl`; developer decision at approval) promoted from `pending:` to `required:` in `config/firewall.txt` and the audit exits 0; `git status` shows nothing ROM-derived — verified by: `make extract` run twice on the Mac (output dir recreated each run) plus once in the container gives one `shasum manifest/retail.jsonl` value; `wc -l < manifest/retail.jsonl` equals the count of files under `extracted/retail/` (9 ISO + member files); T4's recorded reference comparison reports 0 differing sectors over the 9 ISO files; `grep -cE '^required: (config/medium.sha1|manifest/retail.jsonl)$' config/firewall.txt` = 2 and `PY tools/audit_public.py` exit 0; `git status --porcelain --ignored=no` lists nothing under `extracted/`, `disc/`, `.run/`
Verified: PY tools/audit_public.py && test $(grep -cE '^required: (config/medium.sha1|manifest/retail.jsonl)$' config/firewall.txt) -eq 2 && test -z "$(git status --porcelain -- extracted disc .run)" → rc 0 (.run/logs/t5-verify.log; audit OK 0 offenders / 281 paths, 70 hashes)

## Tasks
- T1 — ISO9660 extractor, manifest, scratch cap | Done: `make extract` extracts the 9 ISO files of the verified medium to `extracted/retail/iso/` and writes a deterministic 9-line `manifest/retail.jsonl`; `make scratch-check` enforces the `.run/` cap (25 GB, warn 20 GB). | commit: - | tasks/T1.md | logs/T1.md
- T2 — ROCK_X6.BIN container and compression probe | Done: `docs/formats.md` documents the medium, ISO9660, the ROCK_X6.BIN TOC and loader path, compression (none), length cross-check, ROCK_X6.DAT (unknown), XA/STR and the manifest schema, from our own bytes with address evidence. | commit: - | tasks/T2.md | logs/T2.md
- T3 — ROCK_X6.BIN members with decompression and length cross-check | Done: `make extract` writes `extracted/retail/rock/00.bin`..`58.bin`, cross-checked against docs/formats.md; manifest is 9 `iso` + 59 `rock` = 68 lines, equal to the file count under `extracted/retail/`. | commit: - | tasks/T3.md | logs/T3.md
- T4 — dumpsxiso reference comparison of the 9 ISO files | Done: the build image builds `dumpsxiso` from mkpsxiso commit 54fb1644ed8741223583e2dcda358b75a205e214 (v2.30); our extractor and dumpsxiso agree on all 9 ISO files: `9 files, 254921 sectors, 0 differing`. | commit: - | tasks/T4.md | logs/T4.md

## Decisions that still bind
- T1 — Form-2 detection = ISO dir-record XA attribute (big-endian bits 0x1000 Form 2, 0x2000 interleaved) cross-checked against sector subheader submode bit 5; docs/formats.md should state it.
- T2 — no ROCK_X6.BIN member is compressed; T3's `decompress` is the identity: member k = `bin[sector*2048 : sector*2048+size]`, manifest `compressed: false`, `stored_size = size`, no `.stored` files.
- T2 — TOC = 59 `{u32 sector, u32 size}` LE at offset 0, sector relative to file start (2048 B), size in bytes; zero pair at 59; header = sectors 0–1, all zero after the pair. The game reads a fixed 59 (0x80016818), not the terminator.
- T3 — `decompress` is the identity; it refuses `len(stored) != size` naming the member. No `rock-stored` records on this medium.
- T4 — dumpsxiso pin = mkpsxiso commit 54fb164 (tag v2.30^{}), resolved by `git ls-remote`, not by release page.
- T5 — `manifest/retail.jsonl` and `config/medium.sha1` are `required:` firewall sources; a missing one fails the audit and CI; regenerate the manifest only via `make extract`.
- Form-2 detection via big-endian dir-record XA attribute cross-checked with subheader submode bit 5 → contract, already in docs/formats.md:19-24 (cookbook C0011).
- ROCK_X6.BIN = 59 `{u32 sector, u32 size}` LE TOC, no member compressed, `decompress` is identity with a length check → contract, docs/formats.md (ROCK_X6.BIN, Member table) and `tools/mmx6/rock.py`.
- dumpsxiso pinned to mkpsxiso commit 54fb164 (v2.30) → environment fact, docs/ops/mmx6-hosts.md:34-37 and Dockerfile.
- `manifest/retail.jsonl` and `config/medium.sha1` are `required:` firewall sources, regenerated only by `make extract` → contract, config/firewall.txt:38-39 checked by `audit_public.py` and CI.
- Next task needs: phase 1.2 imports `extracted/retail/SLUS_013.95` and the 59 ROCK_X6.BIN members (stable index = manifest `rock` records) into Ghidra; load bases 0x801EA000 / 0x800E9860 / 0x800FA000 are leads from docs/prior-art.md, unverified.
- Next task needs: write Milestone `verified by` clauses as full runnable commands (Mac `make extract` with `PYTHON=` and `CUE=`), so `phaseend_index.py verify` can judge them unaided.

## Rules proposed
- (none)

## Cookbook entries added
C0011 | ISO9660 dir-record XA attribute is big-endian; Form 2 = 0x1000, cross-check submode bit 5 | psx,iso9660,xa,form2,extract | 2026-10-01 | 1.1/T1 | mmx6 T1
C0012 | objdump a PS-X EXE as raw binary with --adjust-vma=load-0x800; keep listing in .run | psx,mips,objdump,exe,disassembly | 2026-10-01 | 1.1/T2 | mmx6 T2
C0013 | dumpsxiso also writes an XML project into its cwd; move it out before diffing | psx,dumpsxiso,extract,diff,reference | 2026-10-01 | 1.1/T4 | mmx6 T4

## Research
R1.1-001 | disc layout, ROCK_X6.BIN container, compression, extractors/tools (SLUS-01395) | MMX6 disc layout, ROCK_X6 archive, tools | mmx6, psx, disc, archive, extractor, licenses | retriever-web | 2026-10-01 | 35 lines

## Audit
- seed: median 14k, max 14k, n=6 (phase 1.1)
- previous phase 1.0: median 14k, growth 1.2%
- CLAUDE.md: 1242 bytes (unchanged)
- .claude/skills/ci-wait-after-push/SKILL.md: 799 bytes (unchanged)
- .claude/skills/docker-vm-no-privileged/SKILL.md: 774 bytes (unchanged)
- .claude/skills/project-architect/SKILL.md: 13448 bytes (unchanged)
- .claude-state/memory/MEMORY.md: 214 bytes (unchanged)
- HOW_WE_WORK.md: 6781 bytes
- cookbook/INDEX.md: 2477 bytes
- rules/INDEX.md: 10300 bytes
### Carry audit — phase 1.1 (2026-10-01T04:51:51Z → open UTC, 1 sessions, 151 requests)

| file (read) | chars | n |
|---|---|---|
| all.txt | 11.6k | 6 |
| formats.md | 11.6k | 2 |
| f14d50.txt | 3.4k | 1 |
| T1.md | 3.1k | 1 |
| mmx6-hosts.md | 3.0k | 1 |
| rock.py | 2.7k | 1 |
| T3.md | 2.3k | 1 |
| Dockerfile | 2.2k | 2 |
| THIRD_PARTY.md | 1.8k | 2 |
| mx.sh | 1.6k | 1 |
| file (write) | chars | n |
|---|---|---|
| formats.md | 8.6k | 4 |
| extract.py | 4.5k | 2 |
| iso9660.py | 4.1k | 1 |
| RECAP.md | 3.6k | 1 |
| T2.md | 3.1k | 1 |
| T2.md | 3.1k | 1 |
| T1.md | 3.0k | 1 |
| T1.c1.md | 2.8k | 1 |
| result kind | chars | n |
|---|---|---|
| tools/card.py | 89.5k | 6 |
| bash other | 88.0k | 52 |
| Read | 44.0k | 19 |
| run.sh | 28.0k | 21 |
| tools/plan_edit.py | 13.7k | 8 |
| Agent | 9.5k | 9 |
| tools/phaseend_index.py | 4.1k | 2 |
| Write | 3.1k | 21 |
| tools/status.py | 2.4k | 7 |
| tools/task_log.py | 2.3k | 5 |
- whole reads over 20.0k: 0
- seed floor: retriever-code 5,198 (n 1, prev 5,279) · retriever-digest 5,488 (n 1, prev —) · retriever-web 3,607 (n 1, prev —)
- outline credit: 2 outlines · 2 followed by a ranged read · 104.2k chars credited
- warm pings: 1 pings over 1 runs, 0 warmed waits over the TTL, rewrites across warmed waits 0, waits past the cap 0, pings cost $0.0142 vs rewrites replaced $0.0000, cheaper than one rewrite: n/a
- toasts by cause (waiting): question 0, review 0, replan 0, permission 0, input 0, discussion 0, crash 0, idle 0, stop 0, subagent-stop 0, model 0, other 0
- router turns by cause: loop 6, relay 0, re-arm 0, other 0, relay cost $0.0000
- retriever re-asks: 0 of 0 retriever briefs repeat a lookup of the same run
- router: pa-session 58f58af6 · requests 20 · ctx at end 46.9k · growth T1 +675, T2 +568, T3 +513, T4 +556, T5 +566 · top: Agent 6.3k/6, tools/status.py 2.4k/7, tools/plan_edit.py 2.4k/6, other 196/1
- noise: 21 lines 1.2k chars — usage: : 16 lines/950, No such file or directory: 5 lines/274
- price: read $0.20/Mtok · 1h write $7.40/Mtok · output $18.51/Mtok (phase model mix)
- median requests after a read: 2
- carry/request: 1944 chars, 151 requests (prev 2964 chars, 131 requests, growth -34.4%)
- flag: 4 tool-source reads by coder-opus55, expert-opus55
  /Users/ThinkPad/orca/mmx6/tools/mmx6/rock.py  2.7k chars  expert-opus55
  /Users/ThinkPad/orca/mmx6/tools/docker/mx.sh  1.6k chars  expert-opus55
  /Users/ThinkPad/orca/mmx6/tools/docker/Dockerfile  1.1k chars  expert-opus55
  /Users/ThinkPad/orca/mmx6/tools/docker/Dockerfile  1.1k chars  coder-opus55

## Agent runs
- T1 | expert-opus55 | expert | claude-opus-5-5 | medium | ctx 43k | $0.373 | saved - | completed | parent 6dd5ff3c
- T1 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 36k | $0.255 | saved $0.40 | completed | parent a412568b
- T1 | expert-opus55 | expert | claude-opus-5-5 | medium | ctx 31k | $0.187 | saved - | interrupted | parent a2d6fe63
- T2 | expert-opus55 | expert | claude-opus-5-5 | medium | ctx 39k | $0.214 | saved - | completed | parent 6dd5ff3c
- T2 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 44k | $0.437 | saved $0.01 | completed | parent ac99fdfe
- T3 | expert-opus55 | expert | claude-opus-5-5 | medium | ctx 32k | $0.160 | saved - | completed | parent 6dd5ff3c
- T3 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 33k | $0.224 | saved - | completed | parent ab3ea00a
- T3 | expert-opus55 | expert | claude-opus-5-5 | medium | ctx 29k | $0.174 | saved - | completed | parent 6dd5ff3c
- T3 | critic | critic | claude-opus-5-5 | medium | ctx 24k | $0.161 | saved - | completed | parent 6dd5ff3c
- T3 | expert-opus55 | expert | claude-opus-5-5 | medium | ctx 31k | $0.196 | saved - | completed | parent 6dd5ff3c
- T1 | expert-opus55 | expert | claude-opus-5-5 | medium | ctx 38k | $0.199 | saved - | completed | parent 58f58af6
- T1 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 37k | $0.384 | saved - | completed | parent ac8f68ae
- T2 | expert-opus55 | expert | claude-opus-5-5 | medium | ctx 74k | $0.838 | saved $0.50 | completed | parent 58f58af6
- T3 | expert-opus55 | expert | claude-opus-5-5 | medium | ctx 40k | $0.268 | saved - | completed | parent 58f58af6
- T3 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 32k | $0.232 | saved - | completed | parent a2d6ab50
- T4 | expert-opus55 | expert | claude-opus-5-5 | medium | ctx 47k | $0.326 | saved - | completed | parent 58f58af6
- T4 | coder-opus55 | coder | claude-opus-5-5 | medium | ctx 34k | $0.252 | saved - | completed | parent ab48ea79
- T5 | expert-opus55 | expert | claude-opus-5-5 | medium | ctx 42k | $0.324 | saved - | completed | parent 58f58af6
- T5 | expert-opus55 | expert | claude-opus-5-5 | medium | ctx 37k | $0.257 | saved - | completed | parent 58f58af6

## Discussions
- (none)

## Deferred
- from T5: 1.2 imports `extracted/retail/rock/NN.bin` and `iso/SLUS_013.95` by the manifest's paths; `pending: config/check.*.sha` stays for 1.3. (unconsumed)

## Changes
- 2026-10-01 router: T1 next -> done
- 2026-10-01 router: T2 next -> done
- 2026-10-01 router: T3 next -> done
- 2026-10-01 router: T4 next -> done
- 2026-10-01 router: T5 next -> done

## Plain-English Recap
Phase 1.1 built the project's disc extractor: one command (`make extract`) reads our own copy of the Mega Man X6 disc image and unpacks its nine files plus the 59 sub-files packed inside `ROCK_X6.BIN`. It also writes a manifest, a text list of each file's name, size and fingerprint (a SHA-1 hash, never the bytes themselves), which is the only extraction output committed to git. Reading the game's own loading code showed that the packed sub-files are stored uncompressed, so "decompression" is a length check rather than a real decoder. Two runs on the Mac and one in the Linux build container all produced the same manifest, and an independent open-source tool (dumpsxiso) extracted all nine disc files identically. The manifest and the disc fingerprint are now mandatory inputs to the public-safety audit, which passes.
