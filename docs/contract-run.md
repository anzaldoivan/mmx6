# Contract run

Written by `bash tools/mmx6/contract.sh` from captured output. It is never hand-edited.

- date (UTC): 2026-10-24T23:37:31Z
- commit: `233d51b2ceabc8c4f498db929767bb413ecb8409`
- triple: `gcc2.95.2-psx-aspsx2.86`
- image: `sha256:dc2e8b5512c70395c293cee7026b55b0af464dfd9499e3387923b53611077641`

## Steps (result line, wall time)

- fleet: `FLEET 57 of 57` (3018 s)
- loadmap: `CONTROLS 23/23 pass` (0 s)
- boundaries: `# totals programs=57 sites=224 switchdata=431 both=212 scan=12 ghidra=219 hi_mismatch=48 lib=239 lib_funcs=828/1815 optcand_funcs=0/1815 fstart=122 unexplained=0` (7 s)
- bound2: `BOUND2 phantoms=0 truncations=0 ledgered=4 of 8534 functions in 57 programs` (2 s)
- th-selftests: `IMGTAB CONTROL OK` (230 s)
- sdk: `SDK 255 of 255 objects substituted, 57 binaries OK` (87 s)
- ghidra-roundtrip: `ROUNDTRIP OK 57 programs` (548 s)
- redux-smoke: `run.sh: rc=0` (89 s)
- audit_public: `audit_public: OK — 0 offenders among 9919 paths` (3 s)

## Not rerun

- `make tools-health-full`: verified split at the PhaseEnd commit 2026-10-24, "phase-end: PhaseEnd 1.8.1", 0486c89d.

## Fresh clone

- projection: `f6fff21a85cf8f17c940b6c32fc39b09f26bf5c7` (`65ed5dcd08fc0ef970a1b57067b0b6c2e456950d` reduced to config/public-paths.txt)
- check-public: `PUBLIC CHECK OK (5469 file(s), 0 warn)`
- README build commands: `FRESH BUILD 57 of 57` (100 s)
