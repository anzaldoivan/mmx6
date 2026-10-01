# Memory map — mmx6 (SLUS-01395 v1.1)

Load addresses of the exe and the ROCK_X6.BIN members, each with its evidence. A row is `proven` only with
3 runtime datapoints (G5); everything else stays a lead. Overlay rows: T6/T7 (`config/loadmap.txt`).

- SLUS_013.95 load 0x80010000: proven (3 datapoints, PCSX-Redux build 279, no pad input: first `BinSeek` 0x80016858 hit at frame 1478, frame 4000, second `BinSeek` hit at frame 7787; both hits a0=0x12 a1=0x800E9860). Function-body words 92827/92827 equal at each of the 3 (1343 bodies from `config/ghidra/SLUS_013.95.jsonl`, each [func, next func/data row) trimmed to its last `jr ra` + delay slot); whole text 129880, 129857, 129833 of 130048 words. Negative control `--base 0x80010800` fails (rc 1). Commands: `make redux-smoke PYTHON=PY && PY tools/mmx6/exeproof.py .run/redux/smoke` (T4, 2026-10-01).

## Overlay bases (T6, 2026-10-01; per-member rows: `config/loadmap.txt`, `make loadmap`)
Proof per load: `loadmap.py` checks the BinSeek capture's dumps of [dest, dest+size): before != member, after == member
("before/after diff"); size = the TOC word, equal to the member's manifest size at every load. Captures:
`make redux-loads` run `intro_stage` (`.run/redux/loads/intro_stage.jsonl`); reruns in T6.c2 (Redux logs
`.run/redux/logs/loads-20261001-04*.log`) add BinSeek hits with the same a0/a1.
- L3 base 0x801EA000: proven (run intro_stage seq 5, frame 2773, member 0, caller 0x80013CDC (ra 0x80013CE4), before/after diff; T6.c2 rerun same load before/after diff; 4 more hits a0=0 a1=0x801EA000 in 3 T6.c2 runs (attract demo, frames 2793/4314/3493/2793); static a1 at 0x80013CDC and 0x80013CF0)
- L3 base 0x800E9860: proven (run intro_stage seqs 1, 2, 4, 6, members 18, 18, 12, 2 = three distinct members, caller 0x80013E7C (ra 0x80013E84), before/after diff each; word at 0x80010000 = 0x800E9860 at every load and static, the a1 source of 0x80013E7C)
- L3 base 0x800FA000: proven (run intro_stage seq 3, frame 2098, member 46, caller 0x80013E40 (ra 0x80013E48), before/after diff; T6.c2 rerun same load before/after diff; a third hit a0=46 a1=0x800FA000 at frame 2098 in another T6.c2 run; static a1 at 0x80013E40, 0x80013D54, 0x80052E94)
Not reached at runtime (static base only): caller 0x80013D54 (members 33..40), async 0x80052E94 (43, 44, 45),
0x80013CF0 (member 1). T6.c2 tried title menu (Game Start, Continue, Option), attract demo, stage pause, losing
all lives (game over, continue): no load from these callers.

## Code/data/empty criterion
Rule (`tools/mmx6/loadmap.py`): empty = size <= 4; code = >= 1 `addiu sp,sp,-N` and a word-aligned `jr ra` and a
static or runtime base; data = the rest. Counts (59 members): code 56, data 1 (member 13), empty 2 (members 41, 42).
CONTROLS 23/23 pass (exe bodies at 3 smoke dumps; per proven member: equal at its base, fails at base+4, vs another
member's after-dump, word-shuffled). N = 1 (exe) + code members:
N = 57

## Address ledger
Version SLUS-01395 v1.1 throughout. Status: proven runtime (observed live in our captures) | consistent-with-bytes
(decoded from the retail bytes, not observed) | lead.
- 0x80010000 exe load: exe header (formats.md); proven runtime (exe row above, T4)
- 0x80054AD8 exe entry: exe header (formats.md), Ghidra import entry; consistent-with-bytes
- 0x80016858 BinSeek (archive selector): Kuumba L4 name, prior-art L3 recomp; proven runtime (Exec bp fires at every load, a0 = member, a1 = base)
- 0x80014E60 read engine (CdlSetloc/CdlReadN): formats.md; consistent-with-bytes
- 0x800165A4 ready callback: formats.md; proven runtime (bp at 0x80016628 inside it sees remaining 0x800E01A8 = 0 when the after-dump equals the member)
- 0x80014D50 per-sector copy: formats.md, prior-art L3 recomp (function start); consistent-with-bytes
- 0x8001494C waiter: formats.md; consistent-with-bytes
- 0x800E0B58 TOC RAM table: formats.md; proven runtime (size word read at each load equals the member size, 5 members)
- call sites (prior-art L3 recomp; loadmap.py decode): 0x80013CDC proven runtime; 0x80013E40 proven runtime; 0x80013E7C proven runtime; 0x80013CF0, 0x80013D54, 0x80052E94 consistent-with-bytes (not hit)
- tables (loadmap.py decode; prior-art L3 recomp): 0x8006D9EC (site 0x80013D54, members 33..40) consistent-with-bytes; 0x8006DC50 (site 0x80013E40) and 0x8006DB78 (site 0x80013E7C) consistent-with-bytes, runtime indices 46 / 2, 12, 18 lie in them
- bases (prior-art L3 recomp): 0x801EA000, 0x800E9860, 0x800FA000 proven runtime (lines above)
