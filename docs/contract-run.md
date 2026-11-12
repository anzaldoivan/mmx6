# Contract run

Written by `bash tools/mmx6/contract.sh` from captured output. It is never hand-edited.

- date (UTC): 2026-11-08T20:04:43Z
- commit: `3680e4bc8fe021cb0e194a8f123a7c54bf24dc43`
- triple: `gcc2.95.2-psx-aspsx2.86`
- image: `sha256:dc2e8b5512c70395c293cee7026b55b0af464dfd9499e3387923b53611077641`

## Steps (result line, wall time)

- fleet: `FLEET 57 of 57` (888 s)
- loadmap: `CONTROLS 23/23 pass` (1 s)
- boundaries: `# totals programs=57 sites=224 switchdata=431 both=212 scan=12 ghidra=219 hi_mismatch=48 lib=238 lib_funcs=832/1899 optcand_funcs=0/1899 fstart=108 unexplained=0` (5 s)
- bound2: `BOUND2 phantoms=0 truncations=0 ledgered=5 of 8538 functions in 57 programs` (1 s)
- th-selftests: `RECONCILE CONTROL OK` (348 s)
- sdk: `SDK 255 of 255 objects substituted, 57 binaries OK` (46 s)
- ghidra-roundtrip: `ROUNDTRIP OK 57 programs` (513 s)
- redux-smoke: `run.sh: rc=0` (53 s)
- audit_public: `audit_public: OK — 0 offenders among 7197 paths` (2 s)
- gamestr: `GAMESTR OK 1381 files, 15 verbatim, 16 key` (0 s)

## Not rerun

- `make tools-health-full`: verified split at the PhaseEnd commit 2026-10-24, "phase-end: PhaseEnd 1.8.1", 0486c89d.

## Fresh clone

- projection: `759135500228b20f41a1d0d955a83ce8a2934ea4` (`3680e4bc8fe021cb0e194a8f123a7c54bf24dc43` reduced to config/public-paths.txt)
- check-public: `PUBLIC CHECK OK (2230 file(s), 0 warn)`
- README build commands: `FRESH BUILD 57 of 57` (63 s)
