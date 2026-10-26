# Contract run

Written by `bash tools/mmx6/contract.sh` from captured output. It is never hand-edited.

- date (UTC): 2026-10-26T18:58:07Z
- commit: `69bc3714f471a013dd1a15600906e0d181e1362a`
- triple: `gcc2.95.2-psx-aspsx2.86`
- image: `sha256:dc2e8b5512c70395c293cee7026b55b0af464dfd9499e3387923b53611077641`

## Steps (result line, wall time)

- fleet: `FLEET 57 of 57` (2254 s)
- loadmap: `CONTROLS 23/23 pass` (0 s)
- boundaries: `# totals programs=57 sites=224 switchdata=431 both=212 scan=12 ghidra=219 hi_mismatch=48 lib=238 lib_funcs=832/1837 optcand_funcs=0/1837 fstart=118 unexplained=0` (6 s)
- bound2: `BOUND2 phantoms=0 truncations=0 ledgered=4 of 8537 functions in 57 programs` (1 s)
- th-selftests: `BADGES CONTROL OK` (146 s)
- sdk: `SDK 255 of 255 objects substituted, 57 binaries OK` (44 s)
- ghidra-roundtrip: `ROUNDTRIP OK 57 programs` (523 s)
- redux-smoke: `run.sh: rc=0` (51 s)
- audit_public: `audit_public: OK — 0 offenders among 12148 paths` (3 s)
- gamestr: `GAMESTR OK 4855 files, 9 verbatim, 16 key` (1 s)

## Not rerun

- `make tools-health-full`: verified split at the PhaseEnd commit 2026-10-24, "phase-end: PhaseEnd 1.8.1", 0486c89d.

## Fresh clone

- projection: `8b5540c8d0317682a292f16479bedefc1b324e67` (`69bc3714f471a013dd1a15600906e0d181e1362a` reduced to config/public-paths.txt)
- check-public: `PUBLIC CHECK OK (5550 file(s), 0 warn)`
- README build commands: `FRESH BUILD 57 of 57` (75 s)
