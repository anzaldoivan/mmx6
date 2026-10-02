# Campaign manual (phase 1.8)

Purpose: the 1.8 decomp campaign's working manual: the lanes a target can take, the wave procedure, the routing set
(`config/routing.txt`) and the ledger vocabulary (`campaign/ledger.tsv`). Sections are added by the tasks that build
them; this file holds procedure and tool contracts only, never game bytes (G12).

## Lanes

Stub: filled by 1.8 T4 (lanes and the wave procedure) and T5 (scaffold lane).

## Validator

`tools/mmx6/validate.py` (container, stdlib) is the target validator (G49): run on every wave's target list before
cards are written, so no card drafts a phantom, banked or undrawable function.

- Checks, in order, first failing reported: `out-of-range` (prog without a `config/boundaries.txt`
  `# program <P> base <B> size <S>` header, or vram outside [B, B+S)) → `phantom` (no `build/corpus/functions.jsonl`
  row starts at that exact vram) → `banked` (corpus state `c|c-empty`, or a `config/dedup_registry.txt` row naming it
  with state `gated`) → `no-asm` (include_asm: `asm/<prog>/nonmatchings/<tu>/<name>.s`; asm: the whole-TU
  `asm/<prog>/**/<tu>.s`; absent or without `glabel <name>`) → `lib-unproven` (lane lib, its boundaries `lib` OBJ not
  under `docs/ops/compiler-pin.md` `## Proven lib units`).
- `validate.py --targets <file>`: one `<prog>:0x<VRAM>` per line (`#`, blank ignored; malformed line rc 1). Lines
  `VALID <pv>` | `INVALID <pv> <reason>` in file order, last `VALIDATE <ok> of <n>`; rc 0 if ok ≥ 1, rc 3 if ok = 0
  (an empty tier ends the wave, it is not drafted).
- `validate.py --drawn`: the `draw` rows of `build/draw/draw.jsonl`; INVALID lines only + the VALIDATE line; rc 1 on
  any invalid (the draw filter must never pass one), rc 3 on no draw rows. Rung `th-validate` (after `th-draw`).
- `validate.py --self-test`: planted roots in `.run/validate-selftest/`, one target per reason + one valid
  (`VALIDATE 1 of 6`), an all-invalid file rc 3, the no-asm target VALID once its `.s` is planted; `VALIDATE CONTROL OK`.

Exclude audit: `draw.py --audit` checks every `config/draw_exclude.txt` row against the universe U = corpus
`asm|include_asm` rows: stale if not in U, an L1/L3 row whose static check no longer refuses it, an L2 row with no
registry/banked-twin refusal and no twin-component peer in U (L4 rows never stale while in U). Lines
`DRAW STALE <prog> <vram> <layer> <why>`, last `EXCLUDE AUDIT <r> rows, <s> stale`, rc 2 if s > 0. Every draw runs it
first and refuses (rc 2, nothing written) on a stale row.

Leverage draw: `draw.py --rank leverage|difficulty --wave W<n> [--band <lo>-<hi>] [--n K]` writes
`build/draw/W<n>.txt` (one pv per line, first K survivors of the L1-L4 verdicts, one per twin component, C0074).
leverage = payoff `words × (1 + m)` desc, m = other asm functions sharing the census dup class, family or an exact
twin; ties by scaffold closeness (`build/scaffold/scaffold.jsonl` score ascending, none last), then (prog, vram).
difficulty = `build/reports/difficulty.json` order. `--band` keeps lo ≤ words ≤ hi before the verdicts.

Harvest-stamp refusal: for W<n> with n ≥ 1 the draw refuses `DRAW HARVEST-MISSING W<n-1>` (rc 2, checked before any
input is read, no W<n>.txt) unless `campaign/harvest/W<n-1>.ok` exists (written by the harvest gate, G45); W0 needs no
stamp.
