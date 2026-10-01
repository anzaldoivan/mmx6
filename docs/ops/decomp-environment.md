# Decomp environment

*Installed by decomp-architect on 2026-10-01. The environment, build and oracle facts of a matching decompilation;
the rules behind them are the G group in `rules/`.*

## Version pins (decomp)

| Component | Version | Notes / why pinned |
|---|---|---|
| The pinned toolchain triple (compiler → assembler shim → binutils, with flags) | candidates in image (Phase 1.4 T1): cc1 set `/opt/cc/<name>/cc1` (old-gcc 0.17 + 0.9), maspsx @7686f84 `/usr/local/bin/maspsx`, binutils 2.42; pinned (Phase 1.4 T7): `gcc2.95.2-psx-aspsx2.86` = 2.95.2-psx cc1 `-O2 -G0 -msoft-float -funsigned-char` → maspsx `--aspsx-version=2.86` → as; evidence and residual doubts `docs/ops/compiler-pin.md` | pinned by fingerprint evidence down the candidate ladder; the assembler's compatibility version is always passed explicitly — a shim's default is not "latest" |
| Candidate compiler family (from the SDK evidence) | PsyQ-era GCC cc1 + aspsx: mmx4's X4 triple first (gcc 2.7.2 cc1 + maspsx --aspsx-version=2.56 --expand-div, a lead; docs/prior-art.md L1), then the other PsyQ-era cc1 builds (X6 links PsyQ 4.7 libraries, L2); pinned by probes in Phase 1.4 (result: gcc 2.95.2-psx; X4's 2.7.2 refuted, L1); installed set + smoke: `make toolchain-check` (docs/ops/mmx6-hosts.md Pins) | the candidate set the pin phase runs down; never a sibling project's triple |
| Decompile scaffold and differ | m2c @708d2d2 (`/opt/m2c`), asm-differ @0dd09af (`/opt/asm-differ`), deps in /opt/splat-venv (docs/ops/mmx6-hosts.md Pins) | Makefile `M2C_PIN`/`ASMDIFFER_PIN`; make toolchain-check |
| The splitter / disassembler and its config | `splat64 0.50.0` (+ spimdisasm 1.42.4, rabbitizer 1.16.2) | venv /opt/splat-venv in image; make toolchain-check |
| The build host | x86-64 Linux, Ubuntu 24.04, ext4 | On another host, use the container `tools/docker/Dockerfile` (`--platform linux/amd64`). Keep the tree in a named volume. The vintage 32-bit compiler runs under the container's emulation. |
| The disassembler database and its agent server | Ghidra 12.1.3 + ghidra_psx_ldr (project `ghidra/mmx6`, ignored); GhidrAssistMCP headless (`make ghidra-mcp-start`/`-stop`, docs/ops/oracles.md); text export `config/ghidra/<program>.jsonl` | the static oracle; the database is tracked as a TEXT export with a rebuild script |
| The emulator and its scripting bridge | TODO(phase-2) | the runtime oracle |

## The game and the medium

- **Title / platform / serial:** Mega Man X6 · Sony PlayStation (MIPS R3000A) · USA SLUS-01395 (disc v1.1)
- **The main executable on the medium:** `SLUS_013.95` (its hash is the first per-binary contract, Phase 3)
- **Container layout:** One MODE2/2352 ISO9660 track; SYSTEM.CNF boots SLUS_013.95; code overlays (and compressed payloads) packed as sector-extent members of the ROCK_X6.BIN archive; XA/STR streams alongside
- **SDK / compiler-era evidence:** The disc carries "Library Programs (c) 1993-1997 Sony Computer Entertainment Inc." (PsyQ 4.x era); exact library version to be detected in Phase 1.2
- **The dump (machine-local, never committed):** `/Users/ThinkPad/GameInputs/megaman-x6/Mega Man X6 (USA) (v1.1).cue` — copied once onto a fast local filesystem under `disks/`
  (ignored); the extractor reads it, nothing builds against it.

## Build / extract / verify (decomp)

```
# extract the medium and verify against the committed manifest
bash tools/docker/mx.sh sync && bash tools/docker/mx.sh run make extract
# the clean fleet verification — every binary from clean → extract → split → build → health, exit code read;
# last line `FLEET 57 of 57` (tools/mmx6/fleet.sh; gate config/check.<bin>.sha per binary), preceded by
# `C MATCHED <c> of <F> functions (<e> empty-body; banked <c-e>)`: c = C-defined functions in build/src/**/*.c.o,
# F = build/corpus/functions.jsonl rows, e = its c-empty rows; rc 1 if the corpus is absent or its c + c-empty != c
# (`C MATCHED 285 of 6779 functions (282 empty-body; banked 3)` at 1.5 T3)
bash tools/docker/mx.sh sync && bash tools/docker/mx.sh run make fleet
# asm-differ baseline after a green build: build/ copied to expected/build/ (container only; mx.sh pull refuses it)
bash tools/docker/mx.sh run make expected
```

- **The gate:** a binary is green only when its hash check inside `make build` passes; a match is verified from a CLEAN
  rebuild, never incremental; the executable is gated only by a clean rebuild; a build is verified by its exit code. The
  clean fleet verification is the natural `verified by:` clause of every matching phase's milestone.
- **C units (Phase 1.4 T2):** a TU named in `config/c_units.txt` (`<prog> <tu_name>`) is emitted `c` by
  `tools/mmx6/segment.py` (rerun it; never hand-edit the yaml block); splat writes `src/<prog>/<tu>.c` (INCLUDE_ASM
  lines, `include/common.h`) once, then it is hand-edited. Rule `build/%.c.o: %.c` =
  `mipsel-linux-gnu-cpp -nostdinc -undef -D__GNUC__=2 -DPSX -Iinclude | $(CC1) $(CFLAGS) | maspsx $(MASPSX_FLAGS) | as`
  (exe ASFLAGS), under bash `-o pipefail`; `-nostdinc` keeps cpp 12's stdc-predef.h line markers away from old cc1.
  `TRIPLE ?= gcc2.95.2-psx-aspsx2.86` (the pin) picks the row of `config/triples.txt`
  (`<name> | cc1: /opt/cc/<ver>/cc1 | cflags: <...> | maspsx: <...>`) that sets CC1/CFLAGS/MASPSX_FLAGS; an unknown
  name stops make. `asm/<bin>/nonmatchings/` is included by C units, never assembled on its own.
  Overlays may be c units (Phase 2 T5.c1: 36 whole-overlay TUs): `build/src/rock_%.c.o` gets the overlay ASFLAGS
  (`-march=r4000 -mno-fix-loongson3-llsc`) and `-DMMX6_OVERLAY` (common.h purges the GTE `ll` macro); their yamls set
  `auto_decompile_empty_functions: false`, so every overlay function stays include_asm.
- **Probes (Phase 1.4 T3):** `tools/mmx6/probe.py <func> --prog <p> --src <c> --triple <t>` (container) compiles via
  `make -B TRIPLE=<t> build/<c>.o` and prints `<func> <t> MATCH|FAIL <m>/<n> words` (relocated fields masked, extent
  trimmed to last `jr $ra` + delay slot, C0021). `make probe-ladder` runs `config/probes.txt` × `config/triples.txt`;
  rc 0 only on a unique `PIN <t> <k> of <k>`. `--self-test`: control `src/probes/selftest_func_80055A04.c` must MATCH
  and a planted one-instruction mutation (`.run/probe/mut/`) must FAIL `n-1/n` under every triple.
- **Shared bodies (Phase 1.6 T4):** a dup-class body lives once in `src/shared/<system>/<name>.c`; each member TU has
  `#include "../shared/<system>/<name>.c"` in place of its INCLUDE_ASM line (relative to the unit; `tools/mmx6/bank.py`
  writes it; corpus.py parse_c follows it), registered in `config/dedup_registry.txt`.
- **Decompile / diff (Phase 1.4 T4, container):** `python3 tools/mmx6/decompile.py <func> [--prog p]` runs m2c
  (`-t mipsel-gcc-c`) on `asm/<p>/nonmatchings/**/<func>.s` (+ the TU's split data asm if any) and prints the C scaffold
  (needs `make split`; m2c stderr in `.run/decompile/`; rc 2 if not found). `bash tools/mmx6/diff.sh <func> [asm-differ
  args]` runs `/opt/asm-differ/diff.py` (binary mode, never `-m`), extent = map symbol to next map symbol, then prints
  `DIFF <func> <n> differing lines` (n from a `--format json` rerun: rows whose current-column marker is not a space);
  rc 0 only when n == 0. `diff_settings.py` (repo root): arch mipsel, baseimg `expected/build/<bin>`, myimg
  `build/<bin>`, map `build/<b>.map` (ld `-Map`), objdump `mipsel-linux-gnu-objdump`; program from env `MX6_PROG`
  (default SLUS_013.95; `rock_NN` → `build/rock/NN.bin` + `build/rock_NN.map`). `expected/` is container-only: it is
  never pulled (mx.sh pull refuses it, P1.3-1), and `mx.sh sync` wipes it, so run
  `mx.sh sync && mx.sh run make extract && mx.sh run make build expected` before diffing. m2c output is game-derived:
  never committed (G12).

## The oracles (decomp)

- **Disassembler MCP:** GhidrAssistMCP `disassembler` (SSE `http://localhost:8080/sse`, `.mcp.json`), started/stopped by
  `make ghidra-mcp-start` / `make ghidra-mcp-stop` (docs/ops/oracles.md `## MCP server`) — verify with one cheap call before any reverse-engineering task; after a
  restart or a program switch, pause and ask the developer to reconnect the client (rule G2). Every configured MCP server
  adds its instructions to every session, so the entry is enabled only once the server exists (Phase 2).
- **Emulator bridge:** TODO(phase-2) — a live-memory finding is verified only with three or more consistent datapoints
  or a controlled before/after diff.

## Models and effort (decomp, on PA3)

PA3 pins model and effort per agent; no agent changes either. The judgments whose silent error would poison everything
downstream get the deepest reasoning through PA3's own practices, in this order: **split** the task until each piece is
routine (on the max5 and pro tiers the planner must — no plan task may carry `effort: high`); take the judgment to a
**`/discuss max`** session, whose record folds into the PhaseEnd; or **override a rung** in `.claude/pa.json` `"ladder"`.
Breadth — the same analysis over many independent items — is fan-out, not depth.

| Phase | The judgments for `/discuss max` | Breadth (fan-out) |
|---|---|---|
| 1 extraction + manifest | the container/compression semantics when they are ambiguous | a fleet-wide format audit |
| 2 oracles + load map | every load-address derivation; the segmentation decision (the forced boundaries) | a survey of every payload's loader route |
| 3 the all-assembly baseline | the linker-script/layout diagnosis when the first link is red | — |
| 4 the compiler pinned | **the fingerprint verdict** (the triple, the flags, per-module variation) | the candidate ladder run as parallel probes |
| 5 census + harness | the census's shape reading (what the strategy will be built on) | the fleet-wide census; the differential harness's pairs |
| 6 the multipliers | the reconcile ladder's design; any "class is dead" verdict | mass propagation and remaps |
| 7 the map + the permuter | **reading the compiler's source into the map**; the plateau classifier's classes | probes across many constructs |
| 8 the campaign | the routing cliff; **every wall verdict**; the harvest distillation's vocabulary | bulk drafting; the harvest over a wave's reports |
| 9 publish | the contract run's design; any irreversible repository operation (rehearsed) | the fresh-clone proof on a second machine |
| 10 readability | struct unification decisions; every name that asserts meaning | family-batched pin removal, gated |

## Git posture (decomp)

- **Visibility at day one:** public — the ROM firewall applies either way (`config/firewall.txt`,
  `tools/audit_public.py`, the CI workflow). If ever private, a later flip is gated on the host's object store, never on
  a clean tree.
- Never `git clean -x` in this tree (the game-derived data is ignored-but-present); the backup of the reverse-engineering
  work is the text export + the checksum files + a private archive repository, not the ignored directories.

## Tooling inventory (decomp)

| Tool | Location | Purpose |
|---|---|---|
| `tools/audit_public.py` | `tools/` | the ROM audit (purge paths, the derived hash set, the size cap, the pasted-disassembly check); the first-push gate and the CI job; its sources are `config/firewall.txt` |
| `tools/mmx6/segment.py <bin> [--print]` / `make health` | `tools/mmx6/`, `Makefile` | segment.py regenerates the subsegment block of `config/<bin>.yaml` from `config/boundaries.txt` per `config/segmentation.md`; `make health` (container, boundcheck.py, `--self-test`) fails unless every forced lib edge is a subsegment edge; last line `BOUNDARIES OK <k> of <N> programs` only when k = N = config/*.yaml count, an empty forced-edge list refused; `--self-test` (dropped edge, hidden yaml, empty edge list) ends `BOUNDCHECK CONTROL OK`; rung `th-boundcheck` |
| `tools/mmx6/segment.py rock_NN --init` | `tools/mmx6/`, `Makefile` | writes `config/rock_NN.yaml`, `config/symbols.rock_NN.txt`, `config/check.rock_NN.sha` (sha1 from the manifest), generated, never hand-edited; Makefile `BINS` is a wildcard over `config/*.yaml`; overlays assemble with `-march=r4000 -mno-fix-loongson3-llsc` (phase 1.3 T5) |
| `make fleet` / `make expected` | `Makefile`, `tools/mmx6/fleet.sh` | the clean fleet verification (`FLEET <n> of <n>`); `expected/build/` asm-differ baseline from hash-green outputs |
| `tools/mmx6/corpus.py --all \| --prog P \| --self-test` / `make tools-health` | `tools/mmx6/`, `mk/tools-health.mk` | the function corpus over the linked build (container): `build/corpus/{functions,spans,denominators}.jsonl` (text = `<seg>_TEXT_START/_END` of `build/<p>.elf`; uncovered text words classed jtbl > libgap > data > pad, else refused); last line `CORPUS <n> functions <b> bytes of <T> text bytes in <m> programs; game <g> lib <l>; c <c> c-empty <e> asm <a>; uncovered 0` (6779 at 1.5 T2); `--self-test` ends `CORPUS CONTROL OK`. The tools-health chain: `mk/tools-health.mk` (`TOOLS_HEALTH_RUNGS` = th-corpus th-boundcheck th-optscan since 1.5 T3, … th-harness since 1.5 T8, one rung per tool: --self-test then the real run; last line `TOOLS-HEALTH OK <k> rungs`, 7 at 1.5 T8) is called from `make health`, so from `make fleet`; `make tools-health-full` = the same rungs with th-harness-full (`--full`) for th-harness, plus th-selftests (boundaries.py, loadmap.py, probe.py --self-test), `TOOLS-HEALTH OK 8 rungs` at 1.5 T8. `corpus.py --c-names` prints `fleet_c_names()` (fleet.sh `C MATCHED` and harness P1 share it) |
| `tools/mmx6/census.py --all \| --self-test` | `tools/mmx6/`, `mk/tools-health.mk` | the census over `build/corpus/functions.jsonl` (container): words from each function's TU object (LE, C0041), mask = its relocation sites (`readelf -rW`, `probe.MASKS`); dup class = functions with equal sha1 of masked words; family = equal sha1 of the opcode skeleton (op bits 31-26, + funct/SPECIAL, rt/REGIMM, rs/COPz; registers and immediates dropped); reach = distinct programs in a function's dup class; reach × size = reach 1, 2-3, 4-10, 11+ × words ≤8, 9-32, 33-128, 129+ (cell = classes/functions); unique tail = functions in no dup class ≥2 and no family ≥2. Per lane (game, lib) and fleet, every line `… of <N> functions`; writes `build/census/classes.jsonl` (every class, sorted kind, key); last line `CENSUS dup_classes=<a> families=<b> reach_size=<cells>/16 unique_tail=<d> of <N>` (1152 / 1175 / 14 / 2531 of 7345 at 1.5 T6); `--self-test` (planted jal twin, mask-off split, register rename; empty-body class == c-empty + asm `jr $ra; nop`) ends `CENSUS CONTROL OK`; rung `th-census` |
| `tools/mmx6/report.py --progress \| --difficulty \| --dup \| --all \| --self-test` | `tools/mmx6/`, `mk/tools-health.mk` | the reports over `build/corpus/*.jsonl` and `build/census/classes.jsonl` (container), written to `build/reports/{progress,difficulty,dup}.{md,json}` (names/addresses there only; stdout counts, every line `… of <N> functions` / `of <B> bytes` / `of <T> text bytes`): progress = matched (c banks + c-empty stubs, separate columns) of functions and bytes (4 × words) per program, lane and fleet, with remainder, plus text bytes split into function and span bytes by kind; difficulty = not-yet-C (asm, include_asm) ranked ascending by (jtbl, words, branches, calls, prog, vram), branch = REGIMM, ops 4-7, COPz BC (ops 16-19, rs=8), call = jal + jalr, jtbl = any `jr` with rs ≠ 31 (words via `census.read_words`), md = size bucket × jtbl histogram + top 50; dup = dup classes ≥2 by payoff (members−1) × words, desc, with reach and members already C (the propagation list). Refused (rc 1) on a missing input or a dup-member set ≠ the corpus set. Last line `REPORT progress c <x> of <N> functions, <y> of <B> bytes; game …; lib …; banks <c> stubs <e>`; `--self-test` (planted corpus with exact progress line, difficulty and dup order; c→asm flip; stale census; real-corpus sums) ends `REPORT CONTROL OK`; rung `th-report` |
| `tools/mmx6/sig.py --all \| --rescan \| --for <prog:vram> \| --self-test` | `tools/mmx6/`, `mk/tools-health.mk` | the twin band over `build/corpus/functions.jsonl` (container; words + masks only via `census.read_words`): per function `build/sig/sigs.jsonl` `{prog,vram,words,exact,norm,hist}` (exact = `census.dup_key`; norm = masked words `w & ~mask`, hex; hist = `census.skel` histogram of norm); exact = equal exact key (dist 0); near = not exact, max_len ≥ 4, len min/max ≥ 0.75, skel-hist L1 ≤ 2·RATIO·max_len (lossless), Levenshtein(norm)/max_len ≤ RATIO (Myers bit-vector, cutoff), RATIO = 0.3, dist = that ratio; near scanned over one representative per exact key (lossless rarest-first prefix filter) and expanded to members; `build/sig/twins.jsonl` `{a,b,tier,dist}` a<b, every exact pair + every near pair, sorted (tier,a,b). Base rate = q = 100000 random distinct pairs (`Random(0x516)`) through the same band. Last line `TWINS exact_pairs <e> of <E> in band; near <n>; base_rate <r>% of <q> random pairs; of <N> functions` (E = Σ C(n,2) over `kind=dup` classes of `build/census/classes.jsonl`; 277792 of 277792, near 174556, 1.25% of 8534 at 1.6 T2, ~12 s); rc 1 if e < E, a stale census (class member set ≠ corpus set) or a read_words refusal. `--rescan` reuses rows whose TU object is not newer than sigs.jsonl (`SIG RESCAN recomputed <k> of <N> functions`); `--for` prints `TWIN <p:v> <tier> <dist> <name>` and `FOR <p:v> exact <x> near <y> of <N> functions` (rc 1 if unknown); stdout names addresses only under `--for`. `--self-test` (in memory: jal/%hi/%lo twin exact, masks off not exact, one-instruction edit near, unrelated out, 4 of 10 edits out, dropped class pair e < E) ends `SIG CONTROL OK`; rung `th-sig` |
| `tools/mmx6/typecheck.py --all \| --files <paths> \| --self-test` | `tools/mmx6/`, `mk/tools-health.mk` | one home for types (stdlib, text only, no build): keys every typedef/struct in `include/**/*.h` and `src/**/*.{c,h}` by shape (scalar = (width, signed); struct = (size, ((offset, width) per member)), PSX natural alignment, pointer 4, arrays elem×count); refuses `dup` (shape or name seen), `outside` (def not in `include/mmx6/`), `raw-cast` (`*(T *)0x…` in `src/<prog>/`), `unkeyable` (with reason, never skipped) as `TYPES REFUSE <kind> <path>:<line> <name/text>`; last line `TYPES <d> definitions <s> shapes of <f> files; duplicates <n>; raw casts <m>` (7/7, 0, 0 at 1.6 T3), rc 0 iff no refusal. `--files` = those files + `include/mmx6/*.h`. `--self-test` (in memory: real set passes; planted dup/raw-cast/outside/unkeyable each alone refused) ends `TYPES CONTROL OK`; rung `th-types` |
| `tools/mmx6/harness.py --sampled \| --full \| --self-test` | `tools/mmx6/`, `mk/tools-health.mk` | the differential harness (container): each pair asks one question of two existing instruments (imported, never re-implemented, G33): P1 matched? (corpus.parse_c C definitions vs fleet_c_names object FUNC names), P2 compiles? (corpus `c` functions: probe.compile_obj of the probes.txt `banked` src under Makefile TRIPLE vs build/<p>.elf words at the corpus extent, probe's relocation mask), P3 fleet? (`--full` only: sha1 of every BINS output vs after `touch` of src/SLUS_013.95/120A0.c + the first asm/SLUS_013.95/*.s and `make -s build`; NOT-RUN if either .o was not rebuilt), P4 coverage? (optscan parser vs optscan.corpus_counts, per program), P5 boundaries? (corpus vs build/bound2/*.jsonl through bound2.account; AGREE iff phantoms=0 truncations=0), P6 programs? (config/*.yaml stems vs loadmap `N` vs config/ghidra/*.jsonl stems), P7 stubs? (corpus c-empty + asm `jr $ra; nop` by the optscan parser vs the census `jr $ra; nop` dup class members). `--sampled` = P1 P2 P4 P5 P6 P7. Appends `<utc> P<n> <question> AGREE\|DISAGREE\|NOT-RUN <a> <b> of <N> <unit>` per pair to `build/harness/runs.log` (stdout: the same line prefixed `HARNESS `), then `HARNESS <d> disagreements in <p> pairs` (d counts DISAGREE + NOT-RUN; rc≠0 iff d>0; `0 … in 6` sampled, `0 … in 7` full at 1.5 T8). `--self-test` plants one disagreement per pair in memory (P3: on the current hashes, no rebuild) + a NOT-RUN control, logs `.run/harness/selftest.log`, ends `HARNESS CONTROL OK`; rungs `th-harness` (tools-health) / `th-harness-full` (tools-health-full) |
| `tools/mmx6/bank.py <prog:vram> --src <file> \| --self-test` | `tools/mmx6/`, `mk/tools-health.mk` | the reconcile ladder (container): preflight (corpus row include_asm in a `config/c_units.txt` TU, else `RECONCILE <func> refused: <cause>` rc 2); R1 sha1 of --src + `probe.probe` MATCH under the Makefile TRIPLE; R2 the unit's `INCLUDE_ASM(…, <func>);` line → `#include "<src relative to src/<prog>/>"`, unit compiles; R3 `declsync.sync` + `typecheck.py --files`, edited units recompile; R4 stop on a jtbl row inside the extent ("jtbl not carved") or unit `.rodata` grown ("rodata needs placement"); R5 clean rebuild of the program (C objects, elf, binary removed, C0034) + sha1 check, body sha1 = R1's, `typecheck.py --all`, `sig.py --rescan`; a src/shared/ body appends its `config/dedup_registry.txt` row (line-preserving, if absent). Last line `RECONCILE <func> R5 banked; body sha1 <h> unchanged since R1` (rc 0) or `RECONCILE <func> stopped R<k>: <cause>` (rc 1; every edited file restored byte-exact, program rebuilt). Logs `.run/bank/<func>.log`. `--self-test` (planted on two include_asm 120A0 siblings of the exemplar's dup class, bodies in `src/shared/_selftest/`: A own table + planted `void X(s32);` → synced, banked; B exemplar's table → stopped R5; tree restored and exe rebuilt after each) ends `RECONCILE CONTROL OK`; in th-selftests (tools-health-full) |
| `tools/mmx6/declsync.py --prog <p> --def <body.c> [--dry-run] \| --self-test` | `tools/mmx6/`, `mk/tools-health.mk` | declaration sync, rung R3 (stdlib, text only): over `src/<p>/*.c` + the src/ files they `#include`, each prototype `<ret> <func>(<params>);` and call-site cast `((<ret> (*)(<params>))<func>)` differing from the body's definition is moved to the definition's signature (cast removed) when width-compatible (return width, param count, each param width; pointer/s32/u32/int 4), else refused; lines `DECLSYNC synced\|uncast\|refused <path>:<line> <func> [<why>]`, last `DECLSYNC <funcs> synced <s> uncast <c> refused <r> files <k>`, rc 0 iff r = 0; nothing written on a refusal or `--dry-run`. `--self-test` (in memory: compatible synced, `s16` param refused, cast removed) ends `DECLSYNC CONTROL OK`; rung `th-declsync` |
| `make format` | `Makefile` | clang-format over `src/` with the tracked `.clang-format` (the community style) |
| TODO(phase-1): the extractor, the manifest | `tools/` | — |

## The three dictionaries (the kit master copy — consulted, never copied into this repository)

| Corpus | Where | How to use it |
|---|---|---|
| The tool dictionary — the source project's tools, verbatim, by ladder phase, keyed by the need each answers | `<kit master copy>/corpus/tools/INDEX.md` (installed summary: `docs/tools-manifest.md`) | before designing or debugging a tool, grep the index by the need; the matching file is the jumping-off point, its Adapt column the list of what differs here |
| The inherited knowledge base — the cookbook, its symptom index and the codegen map, verbatim | `<kit master copy>/corpus/cookbook/` (installed front page: `docs/knowledge-corpus.md`) | same compiler family: look the symptom up, apply, re-prove on your bytes; another compiler: read the same pass in your compiler's source and find your own lever |
| The inherited record — the source project's distilled records (the how-to, the decision log, the accelerators, the retrospective, the story, the playbook, the effort doctrine, the readability charter) and every phase-end, verbatim | `<kit master copy>/corpus/record/` (installed front page: `docs/inherited-record.md`) | when a rule or kernel cites a source, open it here; the digest first, a phase-end on demand, the how-to in order |
| Kit master copy location (machine-local) | `/Users/Shared/kits/decomp-architect` — where the kit was installed from; the dictionaries above live under it | — |
