# Memory map — mmx6 (SLUS-01395 v1.1)

Load addresses of the exe and the ROCK_X6.BIN members, each with its evidence. A row is `proven` only with
3 runtime datapoints (G5); everything else stays a lead. Overlay rows: T6/T7 (`config/loadmap.txt`).

- SLUS_013.95 load 0x80010000: proven (3 datapoints, PCSX-Redux build 279, no pad input: first `BinSeek` 0x80016858 hit at frame 1478, frame 4000, second `BinSeek` hit at frame 7787; both hits a0=0x12 a1=0x800E9860). Function-body words 92827/92827 equal at each of the 3 (1343 bodies from `config/ghidra/SLUS_013.95.jsonl`, each [func, next func/data row) trimmed to its last `jr ra` + delay slot); whole text 129880, 129857, 129833 of 130048 words. Negative control `--base 0x80010800` fails (rc 1). Commands: `make redux-smoke PYTHON=PY && PY tools/mmx6/exeproof.py .run/redux/smoke` (T4, 2026-10-01).
