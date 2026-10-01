MILESTONE: green

## Recap
Phase 1.1 built the project's disc extractor: one command (`make extract`) reads our own copy of the Mega Man X6 disc image and unpacks its nine files plus the 59 sub-files packed inside `ROCK_X6.BIN`. It also writes a manifest, a text list of each file's name, size and fingerprint (a SHA-1 hash, never the bytes themselves), which is the only extraction output committed to git. Reading the game's own loading code showed that the packed sub-files are stored uncompressed, so "decompression" is a length check rather than a real decoder. Two runs on the Mac and one in the Linux build container all produced the same manifest, and an independent open-source tool (dumpsxiso) extracted all nine disc files identically. The manifest and the disc fingerprint are now mandatory inputs to the public-safety audit, which passes.

## Verification (closing expert, this session)
- `phaseend_index.py verify` → RED 3/5 (.run/logs/pe-verify.log); both REDs are verifier-mechanism artifacts, each clause re-run by hand GREEN:
- clause 1: tool ran `make extract` on the Mac without `CUE=` (Makefile default is the container path `/disc/...`) → FileNotFoundError. Re-run `.run/pe/c1.sh` (.run/logs/pe-c1.log): committed, mac1, mac2 (`extracted/retail` removed before each) and container all `262452fe80c9b49e810def67b2380f94dc50e5b0` → GREEN.
- clause 2: 68 manifest lines = 68 files under `extracted/retail/` on Mac (×2) and container (pe-c1.log) → GREEN.
- clause 3: prose clause ("T4's") fed to bash, unbalanced quote → rc 2. Checked by hand: `.run/t4/result.txt` line 1 `9 files, 254921 sectors, 0 differing` → GREEN.
- clause 4: grep count 2; `audit_public.py` rc 0, 0 offenders / 284 paths (.run/logs/pe-audit.log) → GREEN.
- clause 5: porcelain lists only `phase-ends/DISCUSSION_INDEX.md`; 0 entries under extracted/, disc/, .run/ → GREEN.

## Deviations
- H7: T1 (tools/mmx6/ package, Makefile `extract`/`scratch-check` targets) and T3 (tools/mmx6/rock.py) list neither HOW_WE_WORK.md nor docs/ops/ in `Files:`; the card row `extract` and docs/ops/mmx6-hosts.md:23-25 arrived only in T5. Gap closed by T5, recorded here as a miss.
- harness: `phaseend_index.py verify` runs every backticked span or prose clause as a shell command: Mac-side commands lose required vars (`CUE=`), and prose clauses with apostrophes fail to parse. Milestone `verified by` clauses should be written as complete runnable commands.

## Decisions that still bind
- Form-2 detection via big-endian dir-record XA attribute cross-checked with subheader submode bit 5 → contract, already in docs/formats.md:19-24 (cookbook C0011).
- ROCK_X6.BIN = 59 `{u32 sector, u32 size}` LE TOC, no member compressed, `decompress` is identity with a length check → contract, docs/formats.md (ROCK_X6.BIN, Member table) and `tools/mmx6/rock.py`.
- dumpsxiso pinned to mkpsxiso commit 54fb164 (v2.30) → environment fact, docs/ops/mmx6-hosts.md:34-37 and Dockerfile.
- `manifest/retail.jsonl` and `config/medium.sha1` are `required:` firewall sources, regenerated only by `make extract` → contract, config/firewall.txt:38-39 checked by `audit_public.py` and CI.
- Next task needs: phase 1.2 imports `extracted/retail/SLUS_013.95` and the 59 ROCK_X6.BIN members (stable index = manifest `rock` records) into Ghidra; load bases 0x801EA000 / 0x800E9860 / 0x800FA000 are leads from docs/prior-art.md, unverified.
- Next task needs: write Milestone `verified by` clauses as full runnable commands (Mac `make extract` with `PYTHON=` and `CUE=`), so `phaseend_index.py verify` can judge them unaided.
