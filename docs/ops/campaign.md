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

## Packs

Location: `waves/W<n>/<prog>_<func>/` at the repo root of both trees (Mac clone and `/work`); `.gitignore` `/waves/`,
firewall `glob: waves/**/*.s`. Files: `pack.json` `{pv,prog,func,tu,words}`, `target.s` (game asm, container only),
`draft.c` (the drafter writes first, rewrites on every improvement), `verdict.json` (the drafter's, last).

- Transport: `mx.sh sync` spares top-level `/work/waves` (as `/work/.run`), so a sync never wipes packs or a running
  gate's snapshot. Coders edit `draft.c` in the clone, then `mx.sh push <waves/…>` (clone → `/work`, same relpath, no
  wipe; only `waves/` paths; a `.s` is refused by the firewall glob and excluded from the tar). `mx.sh pull <waves/…>`
  excludes `*.s` under `waves/`: game asm never reaches the clone.
- Snapshot: `cards.py --probe-pack <dir> [--hold S] [--no-snapshot]` (container) builds `waves/.iso/<prog>_<func>.<pid>/`
  (asm/ and extracted/ hardlinked `cp -al`: nothing writes them in place; Makefile mk include src config tools
  build/corpus build/split copied), chdirs there, writes draft.c as `drafts/<prog>/<func>.c` (the TU's CFLAGS via
  probe.draft_cflags), compiles under the Makefile `TRIPLE`, removes the snapshot. Line `PACK <pv> match <m>/<n>` |
  `fail <m>/<n>` | `nocompile`, rc 0 on any PACK line. probe.py/dumps.py use repo-relative paths only (checked T2.c1).
  `--no-snapshot` (compile in `/work`, refuses to overwrite a stored draft) is the negative control only.
- Cards (G44): `cards.py --wave W<n> --targets <file> [--root <dir>] [--journal <path>]` (container; root default
  `waves`) writes per target `<root>/W<n>/<prog>_<func>/`: `pack.json`, `target.s` (include_asm: its nonmatchings .s;
  asm: its glabel span of the whole-TU .s), `scaffold.c` (decompile.py m2c stdout, else `/* decompile.py rc <k> */`),
  `ctx.h` (destination's `#include` lines + its declarations), `card.md`, `seed.c` (the seed's C body, when a seed exists);
  never writes `draft.c`/`verdict.json`. card.md sections in order: Seed (`<pv> <name> body <path> [reason <define …>]`:
  a banked twin over the whole fleet, same dup class or exact twin, banked = corpus c|c-empty or a gated registry row;
  registry exemplar first, then lowest (prog, vram); body = registry shared path, else the C file defining it), Open
  twins (asm|include_asm, not gated; exact then near by dist, cap 12, `<pv> <tier> <dist> <name>`), Destination
  (`src/<prog>/<tu>.c c_unit yes|no`), File declarations (top-level `;` prototypes/externs), Callee declaration
  consensus (`jal` callees: most common prototype/definition signature across src/ with count, else `-`),
  Shared-global declarations (`%hi/%lo/%gp_rel` data symbols: most common `extern` across src/ with count, else `-`),
  Journal history (the pv's journal records, notes verbatim), Plateau (latest record's label ≠ `-` else `none`;
  `plateau.rows(label)`; lever ids). Every `L\d{2,}`/`C\d{4}` token must resolve (codegen_map.read_rows ids,
  cookbook/INDEX.md rows) or `CARD REFUSED <pv> <id>` and the pack dir is removed (only the card files when a draft.c or
  verdict.json is there); no corpus row / no asm → `CARD REFUSED <pv> phantom|no-asm`. Lines
  `CARD <pv> seed <pv|-> twins <k> levers <ids|->`, last `CARDS W<n> <k> packs`; rc 0 iff no refusal and k ≥ 1,
  rc 3 on k = 0, else rc 1. `--self-test` (`.run/cards-selftest/`, planted journals there) → `CARDS CONTROL OK`; rung
  `th-cards` (deps th-sig th-journal).
- Control `bash tools/docker/pack_control.sh` (host; logs `.run/packctl/`), last `PACK CONTROL OK`. Plants a
  pack in `waves/WCTL/` (first SLUS_013.95 INCLUDE_ASM function of 8-40 words without a stored draft; draft = m2c
  scaffold under `#if 0` + the INCLUDE_ASM line, so R is compiled), removes it after. Result at T2.c1
  (func_80012FA0, 17 words): (1) push sha1 equal clone/`/work`, `.s` push refused; (2) pull: pack.json + draft.c, 0 `.s`;
  (3) R = `match 17/17`; (4) `--hold 40` + sync during the hold (sync wiped `/work/asm`): `match 17/17`, draft sha1
  unchanged, `/work/waves/WCTL` kept, `waves/.iso` empty after; (5) `--no-snapshot --hold 40` + sync: rc 1, no PACK line
  (probe's `make build/split/SLUS_013.95.stamp` fails: the tree was wiped).

## Journal

`campaign/journal.jsonl` (tracked, append-only), `tools/mmx6/journal.py` (container, stdlib). One JSON object per line,
keys exactly `{wave, pv, func, words, band, runs, verdict, score, label, draft, lever, notes, prev}`.

- `band` from words: `le16|17-40|41-80|81-160|gt160` (must agree); `verdict` ∈ `banked|fail|nocompile|verbatim|missing|plumbing`;
  `score` `m/n` or `-`; `label`/`draft`/`lever` a token (path, plateau label) or `-`; `notes` ≤ 400 chars of our prose,
  refused if it holds a MIPS register operand (`$a0`, `$sp`, `$4`…), `.word` or `glabel` (G12); `prev` = sha1 of the
  previous line's text (40 zeros first): the append-only check (the container has no .git).
- `--append <json>`: validates, sets prev (any given prev is replaced), appends; `JOURNAL REFUSED <why>` rc 1, file untouched.
  `--for <pv>`: that pv's lines, last `JOURNAL FOR <pv> <k> records`. `--rate [--wave W<n>]`: all five bins
  `RATE <bin> drafted <d> banked <b> instructions <i>` (d distinct pv with a record, b distinct pv banked, i sum of their
  words). `--check`: `JOURNAL OK <r> records` rc 0 | `JOURNAL BAD <line> <why>` rc 1. `--journal <path>` overrides the file.
- `--self-test` (`.run/journal-selftest/`): good append, 14 refusals (each schema rule) leave the file byte-identical,
  rate bins on planted records (with `--wave`), `--for`, an edited earlier line caught by `--check`; ends
  `JOURNAL CONTROL OK`. Rung `th-journal` (`--self-test && --check`).
