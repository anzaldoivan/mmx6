# Campaign manual (phase 1.8)

Purpose: the 1.8 decomp campaign's working manual: the lanes a target can take, the wave procedure, the routing set
(`config/routing.txt`) and the ledger vocabulary (`campaign/ledger.tsv`). Sections are added by the tasks that build
them; this file holds procedure and tool contracts only, never game bytes (G12).

## Lanes

Every lane has a cadence and a cap (G39).
- drafting (paid clock): waves of 16 cards, ≤ 4 coders concurrent (a harvest workflow included), one run per card + ≤ 1
  retry inside the band cap of `config/routing.txt` (T9); never stopped to ship a tool change: changes land between
  waves (G48).
- scaffold (free; T5): detached, resumable.
- propagate/remap (free): after every banked exemplar, run by the gate.
- x4 (free; T7): proven-shared only (G102).
- permuter (free): plateau fails only, iterations capped per band.
- lib (free; T8): vendor ledger rows.
- gate: every wave, serial per binary, ≤ 3 binaries at once.
- harvest: every wave; it closes the wave.
- lane waves (T6): id `W-<lane>` beside `W<n>` (gate, cards, journal, harvest; draw stays `W<n>`; `journal.py --rate`
  without `--wave` counts `W<n>` only); W-fam = the family 40505e80 lane.

## Wave procedure

1. `harvest.py --start W<n>` (denominators before the wave).
2. Draw: `draw.py --rank leverage|difficulty --wave W<n> …` (refused without `campaign/harvest/W<n-1>.ok`).
3. Audit: `draw.py --audit` (run first by every draw).
4. Validate: `validate.py --targets build/draw/W<n>.txt`.
5. Cards: `cards.py --wave W<n> --targets build/draw/W<n>.txt`.
6. Fan-out: one coder per card; drafts pushed as packs (`mx.sh push waves/W<n>/…`).
7. Gate the directory: `gate.py --wave W<n>`.
8. Recover: the gate's ladder (## Recovery); plumbing stops re-gated, never redrafted.
9. Ledger: `ledger.py --build` (after the gate's banks; needs corpus, census, sig and a default `draw.py` run), pull
   `campaign/ledger.tsv` (## Ledger).
10. One `make fleet` from a clean rebuild.
11. Journal: pull `src/`, the registry, `campaign/journal.jsonl` and `campaign/harvest/` before any sync.
12. Harvest gate: `--inert-wave W<n>`, `--record` per live lever, `--sweep` per mechanical idiom, `--widen W<n>`,
    `--gate W<n>` (stamps `campaign/harvest/W<n>.ok`, which the next draw needs).

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

## Verbatim

`tools/mmx6/verbatim.py` (DK-29, stdlib, container or host): a banked or ledgered body must be C. After C comments are
stripped it refuses `include-asm` (INCLUDE_ASM/INCLUDE_RODATA anywhere), `directive <d>` (assembler directive text) and
`inline-asm` (any asm statement or expression other than a register pin); register pins are allowed and counted (1.10).
- `<file>…` → `VERBATIM <file> ok pins <p>` | `VERBATIM <file> refused <why>`; `--all` (src/shared and tracked drafts .c)
  last `VERBATIM ALL <k> files; refused <r>; pins <p>`. rc 0 iff none refused, 1 otherwise, 2 usage/unreadable.
- `--self-test` (`.run/verbatim-selftest/`) ends `VERBATIM CONTROL OK` | `VERBATIM CONTROL FAIL <case>` rc 1; rung `th-verbatim`.

## Gate

`tools/mmx6/gate.py --wave W<n> [--root waves] [--journal campaign/journal.jsonl] [-j 1..3] [--no-propagate]`
(container, stdlib; T3.c2). Scores every pack dir `<root>/W<n>/<prog>_<func>/` (its `draft.c`; never verdict.json's status, G50).
- Inputs (ignored/generated; a missing one is `GATE <pv> MISSING <input>`, never a verdict): pack.json, draft.c, the
  build/corpus row, build/census/classes.jsonl, the retail binary (config/<prog>.yaml target), the asm .s holding the glabel.
- Isolation (C0004): drafts grouped by program; ≤ j programs at once (default 3), each in its own snapshot
  `waves/.iso/gate-<prog>.<pid>/` (cards.snapshot + all of build/, .clang-format, docs/codegen-map; src/ copied, never
  hardlinked) holding `.run/gate/locks/<prog>.lock` (fcntl.flock non-blocking; busy → `GATE LOCKED <prog>`, rc 1);
  drafts of one program serially. Snapshots removed in `finally`; stale `gate-*` of a dead pid reaped at start.
- Per draft (cwd = snapshot): clang-format (repo .clang-format, C0063) as `src/shared/<prog>/<func>.c` (a different body
  already there → `REFUSED`); standalone masked probe (cards.score) of that text as `drafts/<prog>/<func>.c` (TU flags;
  `#define <draft name> <func>` first when the draft defines another name); verbatim.check; bank.bank on the body copy
  (registry exemplar row when a dup class exists); probe fail → plateau label (plateau.classify, `PLATEAU …` line).
  Lines `GATE <pv> match <m>/<n>|fail <m>/<n>|nocompile|verbatim|MISSING <input>`, then `BANKED <pv> <words>` |
  `RECOVERED <pv> R<k> via <step>` (+ BANKED) | `STOPPED <pv> R<k>: <cause>` | `REFUSED <pv> <cause>`.
- Apply-back after each program worker, under `.run/gate/locks/apply.lock`: snapshot src/ files whose sha1 changed since the
  snapshot start are copied to the tree, new registry rows appended; a tree file changed meanwhile → `GATE APPLY CONFLICT
  <path>`, nothing of that program applied (its banks journaled `plumbing`, label `conflict`), rc 1. The program is then
  rebuilt in the tree (`GATE REBUILD <prog> red` rc 1).
- Then in the tree: each banked exemplar's dup class propagated (propagate.propagate) when it has asm|include_asm members
  with no gated registry row, else `PROPAGATE <key> skipped: no open members`; one `sig.py --rescan` (G46); one journal
  record per draft (lever per ## Harvest; verdict banked|fail|nocompile|verbatim|missing|plumbing; label = plateau label, `R<k>`, `hash`,
  `refused` or `-`). Last lines `GATE W<n> drafts <d> = banked <a> + failed <b> + no-verdict <c>` (asserted, rc 1 if it
  breaks) and `WAVE W<n> banked <k> (<i> instructions) of <d> drafts; recovered <r>`. rc 0 = completed, 1 = assertion,
  conflict, lock or worker error, 2 usage.
- `--self-test` (`.run/gate-selftest/`, wave W0; C0054 planted): four exe and one overlay c-unit member of the
  state_dispatch class reverted to INCLUDE_ASM of generated .s files (proven by both binaries' sha1); drafts = the shared
  body with each member's name/table: A byte-identical → BANKED; B renamed `<func>_w` → RECOVERED R1 via define; C
  `arg0[6]`→`arg0[7]` → `fail 14/15`, label isel, journal fail; D block restored and its .s removed (corpus still
  include_asm) → MISSING asm; E overlay → BANKED; the two workers' intervals overlap; a second non-blocking lock refused;
  coverage and WAVE lines exact. Teardown restores src/, registry, corpus jsonl trio byte-exact, real journal untouched,
  both binaries rebuilt to their sha1, no `waves/.iso/gate-*`; ends `GATE CONTROL OK` | `GATE CONTROL FAIL <cases>` rc 1.
  Rung `th-gate` in `make tools-health-full` only (mutates /work like bank's self-test).

## Recovery

Plumbing (G50) = probe match but a bank stop R1-R4: no redraft; the ladder re-runs bank.bank on the gate's body copy, first
success wins (`RECOVERED <pv> R<k> via <step>`, k = the rung of the first stop):
1. `define` (first stop R1-R3, the draft's defined function name ≠ the target func): `bank --define <draftname>=<func>`.
2. `declsync` (first stop R2 compile error, `declaration …` or `declsync would edit the body`): the body copy gets
   declsync.sync's own edit of the body, and its top-level prototypes/externs named by the stop cause or by quoted names
   in `.run/bank/<prog>.<func>.log` rewritten to the program's prevailing spelling (most common across declsync.unit_files);
   skipped when nothing changes; carries the define of step 1 when the names differ.
3. `cast` (first stop R2/R3; a call/declaration conflict in the stop cause or the first-stop bank log): on the body's own
   lines, `too few|many arguments to function 'X'` / `conflicting types for 'X'` → every call of X after the draft's own
   prototype becomes `((<its return type> (*)())X)(…)`; the prototype is dropped for `conflicting types` only (the bank's
   standalone probe needs X declared); on another body's lines, `too few|many arguments … 'X'` → the draft's own
   prototype of X loses its parameter list. Re-formatted; skipped when nothing changes; carries step 1's define.
R4 (jtbl not carved, rodata needs placement) is not recoverable. Unrecovered → `STOPPED <pv> R<k>: <cause>`, journal
`plumbing`, label `R<k>`. An R5 stop (hash) → failed, journal `fail`, label `hash`. A bank preflight refusal →
`REFUSED <pv> <cause>`, journal `plumbing`, label `refused`.

## Harvest

`tools/mmx6/harvest.py` (container, stdlib; G45): closes a wave. `--campaign <dir>` (default `campaign`) relocates
`journal.jsonl`, `ledger.tsv` and `harvest/`.
- Lever = a unified diff in the pack (its relative path in verdict.json `lever`) whose + side is the final draft.c. The
  gate journals `lever` = `waves/W<n>/<prog>_<func>/<f>` when that file exists in the pack, else `-` (status never read, G50).
- `--inert <pv> --lever <diff> [--draft <c>] [--wave W<n>]` (draft default: draft.c beside the diff): reverse-apply onto
  a copy (`patch -R` when in the image, else a stdlib hunk applier); both texts compiled as `drafts/<prog>/<func>.c` in
  one cards.snapshot (TU flags, Makefile TRIPLE; the tree is never written); elf_function words + masks compared
  exactly: equal → `inert`, different or reverted nocompile → `live`. Line `HARVEST <pv> lever <path> live|inert`;
  with-lever nocompile → `HARVEST <pv> lever <path> nocompile` rc 1 (`noapply` when the diff does not reverse-apply,
  `MISSING <input>`). `--wave` appends the inert record.
- `--inert-wave W<n>`: every journal record of W<n> with verdict banked and lever ≠ `-` (only banked levers are
  credited), one snapshot; last `HARVEST INERT W<n> levers <k> live <l> inert <i>`.
- `campaign/harvest/W<n>.jsonl` (tracked, append; last record per pv/kind wins; our names, numbers, prose only, G12):
  `inert {pv,lever,state,why}`; `record {pv,cookbook:C<nnnn>|-,reason:<≤ 400 chars>|-,sweep:<id>|-}` from
  `--record W<n> <pv> (--cookbook C<nnnn> | --reason TEXT) [--sweep ID]` (a reason with asm text refused);
  `sweep {id,label,tried,edited}`; `widen {rows}`. Every record carries `kind`.
- `--sweep <id> --wave W<n>`: imports `tools/mmx6/sweeps/<id>.py` (`LABEL`, `apply(text) -> (text, edits)`; README
  there); targets = the latest journal record per pv with label == LABEL and a readable draft, plus `ledger.tsv` rows
  with blocker `plateau:<LABEL>` and an existing tracked best draft (the ledger's draft wins); edited drafts written as
  packs `waves/sweeps/W<n>/<prog>_<func>/{pack.json,draft.c}` (gate them with `gate.py --wave W<n> --root waves/sweeps
  --journal campaign/harvest/W<n>.sweeps.jsonl`); line `SWEEP <id> tried <t> edited <e>`; sweep record appended.
- `--start W<n>` writes `campaign/harvest/W<n>.start.json` `{taken, denominators}`: `progress.<fleet|game|lib>.<k>`
  (build/reports/progress.json), `census.<dup|family>.<classes|members>` (classes of ≥ 2 members,
  build/census/classes.jsonl), `census.stubs[.asm|.ledgered]` when `build/census/stubs.txt` holds the
  `CENSUS stubs` line, `draw.<draw|eligible|refused>` and `draw.refused.<L1-L4>` (build/draw/draw.jsonl). `--widen W<n>`
  recomputes: `WIDEN <scanner> <old> -> <new>` per key, the widen record appended; an input not newer than `taken` →
  `HARVEST WIDEN STALE <input>` rc 1; no start → `HARVEST WIDEN W<n> MISSING start` rc 1.
- `--gate W<n>`: (a) every credited lever has an inert record (same lever path), (b) every live lever has a record with
  a cookbook id resolving in cookbook/INDEX.md (a row, file exists) or a non-empty reason, (c) every sweep-tagged
  record has a sweep record with counts, (d) a widen record exists. All hold → `campaign/harvest/W<n>.ok` (gate line,
  `sha1 <W<n>.jsonl>`, counts), `HARVEST GATE W<n> OK` rc 0; else `HARVEST GATE W<n> MISSING inert|record|reason|
  cookbook <id>|sweep <id>|widen [<pv>]` per miss, rc 1, no stamp. draw.py refuses W<n+1> without the stamp.
- `--check-all`: every distinct wave of journal.jsonl has an .ok whose sha1 still matches its W<n>.jsonl →
  `HARVEST GATES OK <w> of <w> waves` rc 0, else `HARVEST GATE W<n> MISSING stamp` | `HARVEST GATE W<n> STALE` rc 1.
- `--self-test` (`.run/harvest-selftest/`, C0054 planted, the exemplar body src/shared/entity/state_dispatch.c as the
  draft): live lever (`arg0[6]`→`arg0[7]`) → live; inert lever (a one-line comment rider) → inert; W1 live lever
  without record → refused, no stamp; W2 sweep-tagged record without sweep record → refused; W3 complete (inert-wave,
  real cookbook id, sweep record, stale then fresh planted widen inputs) → stamped; check-all: unstamped W1/W2 MISSING,
  a W3-only copy OK, an append after the stamp STALE; src/ config/ campaign/ cookbook/ drafts/ unchanged, no
  `waves/.iso/harvest-*`. Ends `HARVEST CONTROL OK` | `HARVEST CONTROL FAIL <cases>` rc 1. Rung `th-harvest`
  (`--self-test && --check-all`).

## Scaffold lane

`tools/mmx6/scaffold.py` (container, stdlib; T5.c1): the free first crack at every asm function. Detached:
`bash tools/run.sh --bg scaffold -- bash tools/docker/mx.sh run python3 tools/mmx6/scaffold.py --all -j 8`.
- Per `build/corpus/functions.jsonl` row with state asm|include_asm, sorted (prog, vram): m2c (decompile.py's command:
  the nonmatchings .s + the TU's data .s, `-t mipsel-gcc-c`, plus `--valid-syntax` so untyped field access is
  `M2C_FIELD`) → one fixed normalisation pass (`#include "common.h"`, a prelude of `#define`s for NULL/s64/u64/f32/f64
  and `M2C_UNK*`/`M2C_FIELD`/`M2C_BITWISE`, each only when used and never a typedef (bank R3 typecheck), `?` → s32, top-level initialised data → `extern`; never a
  per-function fix; `M2C_ERROR` and the other placeholders stay undefined) → `make build/<src>.o` with the TU's cc1 flags
  as `CFLAGS_<func>` (the C rule's recipe for `src/<prog>/<tu>.c`, as probe.draft_cflags) → masked compare vs the
  retail words of the corpus extent (probe.trim, relocation masks as probe.probe). Whole-TU `asm` rows have no
  nonmatchings .s: nocompile.
- Record (one per function, appended; resumable: a pv already in the file is skipped):
  `build/scaffold/scaffold.jsonl` `{pv,func,words,score,n,state}`, state `match|compile|nocompile`, score = masked
  mismatches `max(retail, ours) - matched` (0 iff probe MATCH), null when nocompile; n = trimmed retail words. Scaffold C
  kept at `build/scaffold/src/<prog>/<func>.c` (game-derived, ignored, G12). `--jsonl PATH` relocates both (scratch
  runs). `--limit K` = deterministic stride sample of the (prog, vram) order; `--prog P`; `-j N` (default nproc).
  Last lines `SCAFFOLD RATE <k> functions in <s> s (<r>/s)`, `SCAFFOLD <done> of <a>: match <m> compile <c> nocompile <x>`.
- Pack → gate: `scaffold.py --packs <dir>` (alone or with `--all`) writes every match row as a pack
  `<dir>/W0/<prog>_<func>/` (pack.json `{pv,prog,func,tu,words}`, draft.c = the scaffold C, verdict.json
  `{"pv","status":"match","score":0,"lever":"-","notes":"m2c scaffold"}`); line `SCAFFOLD PACKS <k> in <dir>/W0`. Then
  `gate.py --wave W0 --root <dir>` (## Gate) banks them: the scaffold tool never calls bank.py (G61: only the
  whole-binary hash banks), and the gate's own probe, not the jsonl, decides.
- `--self-test` (`build/scaffold/selftest/`): three SLUS_013.95 c-empty functions (banked C: they never lose their
  retail words, and no lane banks them again) get planted generic `.s` (`jr $ra` + delay slot, m2c run on it):
  trivial → match score 0 (retail extent equal to probe.retail_words), delay slot `addiu $v0, $zero, 1` → compile
  score > 0, a planted syntax error → nocompile (score null), a re-run adds no rows, `--packs` writes exactly the match's
  pack. Ends `SCAFFOLD CONTROL OK` | `SCAFFOLD CONTROL FAIL <cases>` rc 1. Rung `th-scaffold`.

## Ledger

`tools/mmx6/ledger.py --build | --check | --self-test [--ledger P]` (container, stdlib; T5.c4) →
`campaign/ledger.tsv` (tracked; names, addresses, numbers, keys, our draft paths only, G12). One row per corpus
asm|include_asm function, sorted (prog, vram), tab-separated `<prog> <vram 0x%08X> <func> <class> <closeness> <best draft>
<blocker>`. Run `ledger.py --build` after every gate's banks, before `make fleet`; inputs `build/corpus/functions.jsonl`,
`build/census/classes.jsonl`, `build/sig/twins.jsonl`, `build/draw/draw.jsonl` (a default `draw.py` run, after
`report.py --all`), `config/boundaries.txt`, `config/walls.txt`, `config/dedup_registry.txt`, the scaffold rows
(`build/scaffold/scaffold.jsonl`, else `campaign/scaffold/scaffold.jsonl`), the journals
(`campaign/scaffold/journal.jsonl`, then `campaign/journal.jsonl`) and tracked `drafts/<prog>/<func>.c`.
- class, first that holds: lane lib → `vendor:<LIB>/<tu>` (LIB from the `config/boundaries.txt` lib row holding the
  vram, else `unproven`); census dup class ≥ 2 → `dup:<key>`; census family ≥ 2 → `family:<key>`; exact sig twin →
  `twin:<pv>` (lowest other member of its exact-twin component); `x4` (mmx4 exact partner; in the vocabulary, never
  assigned yet: x4share.py prints counts only); else `unique`.
- closeness: `m/n` (m matched words) of the best (m/n, then m) of the scaffold row (m = max(0, n − score)), journal
  scores, the tracked draft compiled and masked-scored; `nocompile` if none compiled.
- best draft: the tracked `drafts/<prog>/<func>.c`, else `m2c` (regenerable by the pinned scaffold, never tracked).
- blocker, first that holds: `vendor` (lane lib, G56); `jtbl-uncarved` | `opt-mismatch` (draw L1); `wall:<pass>`
  (walls.txt row); the latest journal record: body fail → `plateau:<label>` (plateau.py: none, length, isel, sched,
  regalloc, branch), plumbing → `plumbing:R<k>` (probe matched, bank stopped at R<k>; a fail `hash` = R5) or
  `plumbing:refused` (bank refused, a different shared body, apply-back conflict); the tracked draft's plateau label →
  `plateau:<label>`; draw L2 → `member-of:<pv>` (registry exemplar, banked twin or cluster head); else `undrawn`
  (never drafted; closeness from the scaffold lane).
- `--check` → `LEDGER BAD <pv> <why>` per missing asm function, C or non-corpus row, row outside the grammar, best
  draft absent or refused by verbatim.check; `LEDGER classes <head> <k> …`, `LEDGER blockers <head> <k> …`; last
  `LEDGER OK <r> rows; 0 missing, 0 malformed` rc 0 | `LEDGER FAIL …` rc 1. `--self-test` (`.run/ledger-selftest/`,
  fictional program) ends `LEDGER CONTROL OK`. Rung `th-ledger`.
- census.py prints `CENSUS stubs <s> of <a> asm functions (ledgered <l>)` (stub = asm|include_asm with no ledger row)
  before its last line, also in `build/census/stubs.txt` (harvest.py's denominator).
