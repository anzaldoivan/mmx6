# tools-health.mk — the tools-health chain (container), included by the Makefile and run by `make health` (so by
# `make fleet`). One rung per phase tool: a rung runs the tool's --self-test, then its real run; later tasks append
# their rung to TOOLS_HEALTH_RUNGS. Last line `TOOLS-HEALTH OK <k> rungs`.

TOOLS_HEALTH_RUNGS := th-corpus th-boundcheck th-optscan th-bound2 th-census th-sig th-report th-harness th-types th-declsync th-propagate th-carve th-remap \
	th-walls th-draw th-validate th-cites th-dumps th-alloc th-repro th-map th-cookbook th-permute th-plateau th-journal th-cards \
	th-verbatim th-harvest th-scaffold th-ledger
# `make tools-health-full`: the same chain with the full harness (adds P3, a touch + rebuild) and every other tool's
# --self-test that is not a rung, and th-propagate with every registry key's --dry-run.
TOOLS_HEALTH_FULL_RUNGS := $(filter-out th-harness th-propagate,$(TOOLS_HEALTH_RUNGS)) th-harness-full th-propagate-full \
	th-selftests th-gate

.PHONY: tools-health tools-health-full $(TOOLS_HEALTH_RUNGS) th-harness-full th-propagate-full th-selftests th-gate

tools-health: $(TOOLS_HEALTH_RUNGS)
	@echo "TOOLS-HEALTH OK $(words $(TOOLS_HEALTH_RUNGS)) rungs"

tools-health-full: $(TOOLS_HEALTH_FULL_RUNGS)
	@echo "TOOLS-HEALTH OK $(words $(TOOLS_HEALTH_FULL_RUNGS)) rungs"

# The function corpus and text denominator (tools/mmx6/corpus.py; needs the linked build).
th-corpus:
	$(PYTHON) tools/mmx6/corpus.py --self-test
	$(PYTHON) tools/mmx6/corpus.py --all

# Every forced lib edge is a subsegment edge of its yaml, over all config/*.yaml (tools/mmx6/boundcheck.py).
th-boundcheck:
	$(PYTHON) tools/mmx6/boundcheck.py --self-test
	$(PYTHON) tools/mmx6/boundcheck.py

# The codegen census covers every corpus asm function, per program (tools/mmx6/optscan.py; needs the corpus).
th-optscan: th-corpus
	$(PYTHON) tools/mmx6/optscan.py --self-test
	$(PYTHON) tools/mmx6/optscan.py --all

# The second boundary oracle (tools/mmx6/bound2.py; needs the corpus): controls, then `--all` (rc 0 iff no phantom
# or truncation; T5 cleared them with declared overlay boundaries, config/segmentation.md).
th-bound2: th-corpus
	$(PYTHON) tools/mmx6/bound2.py --self-test && $(PYTHON) tools/mmx6/bound2.py --all

# The census (tools/mmx6/census.py; needs the corpus): planted twin/mask/rename controls and the empty-body class,
# then `--all` (build/census/classes.jsonl; last line `CENSUS dup_classes=… of <N>`).
th-census: th-corpus
	$(PYTHON) tools/mmx6/census.py --self-test && $(PYTHON) tools/mmx6/census.py --all

# The twin band (tools/mmx6/sig.py; needs the census): planted exact/mask-off/near/out/past-RATIO/dropped-pair
# controls, then `--all` (build/sig/{sigs,twins}.jsonl; last line `TWINS exact_pairs <e> of <E> …`, rc 1 if e < E).
th-sig: th-census
	$(PYTHON) tools/mmx6/sig.py --self-test && $(PYTHON) tools/mmx6/sig.py --all

# The reports (tools/mmx6/report.py; needs the census): planted progress/difficulty/dup controls and real-corpus sums,
# then `--all` (build/reports/{progress,difficulty,dup}.{md,json}; last line `REPORT progress c … stubs <e>`).
th-report: th-census
	$(PYTHON) tools/mmx6/report.py --self-test && $(PYTHON) tools/mmx6/report.py --all

# The differential harness (tools/mmx6/harness.py; needs the corpus, bound2 and census outputs): planted
# disagreement per pair + NOT-RUN control, then the sampled pairs P1 P2 P4-P8 (build/harness/runs.log; last line
# `HARNESS <d> disagreements in <p> pairs`, rc 0 iff d = 0).
th-harness: th-corpus th-optscan th-bound2 th-census th-draw
	$(PYTHON) tools/mmx6/harness.py --self-test && $(PYTHON) tools/mmx6/harness.py --sampled

th-harness-full: th-corpus th-optscan th-bound2 th-census th-draw
	$(PYTHON) tools/mmx6/harness.py --self-test && $(PYTHON) tools/mmx6/harness.py --full

# One home for types (tools/mmx6/typecheck.py; text only, no deps): planted dup/raw-cast/outside/unkeyable controls,
# then `--all` (last line `TYPES <d> definitions <s> shapes of <f> files; duplicates <n>; raw casts <m>`, rc 0 iff none).
th-types:
	$(PYTHON) tools/mmx6/typecheck.py --self-test && $(PYTHON) tools/mmx6/typecheck.py --all

# Declaration sync, reconcile rung R3 (tools/mmx6/declsync.py; text only, in memory): synced/refused/uncast controls.
th-declsync:
	$(PYTHON) tools/mmx6/declsync.py --self-test

# Shared-body propagation (tools/mmx6/propagate.py; needs the corpus and census): planted registry controls, then
# every config/dedup_registry.txt row's built dup key vs its row (`REGISTRY OK <r> rows`). The --dry-run per registry
# key (`PROPAGATE DRY-RUN <key> gated <m> of <M> members`, rc 1 if m < M) takes ~260 s on 8 workers, so it runs in
# tools-health-full only (T5.c3).
PROPAGATE_KEYS = $(shell awk '!/^\#/ && NF >= 5 && $$6 != "family" {print $$1}' config/dedup_registry.txt | sort -u)

th-propagate: th-corpus th-census
	$(PYTHON) tools/mmx6/propagate.py --self-test && $(PYTHON) tools/mmx6/propagate.py --check

# Carves (tools/mmx6/carve.py; needs the corpus): planted refusals on a scratch copy under .run/, then --check of
# every config/carve.<prog>.txt row, its .mk and every yaml block (last line `CARVE CHECK OK <n> carves`).
th-carve: th-corpus
	$(PYTHON) tools/mmx6/carve.py --self-test && $(PYTHON) tools/mmx6/carve.py --check

# Family remap (tools/mmx6/family_remap.py; needs the corpus and census): planted controls G (a jal-target-only
# sibling, gated through bank R5, its family row passes propagate.py --check) and R (reordered call pair, refused at
# pair); tree, registry, corpus and exe restored byte-exact. ~19 s, so a fast rung (T7.c1).
th-remap: th-corpus th-census
	$(PYTHON) tools/mmx6/family_remap.py --self-test

# The wall oracle (tools/mmx6/walls.py; needs the corpus): planted valid/unknown-pass/no-ref/C-function rows in
# .run/walls-selftest/, then --check of config/walls.txt (last line `WALLS CHECK OK <r> rows`).
th-walls: th-corpus
	$(PYTHON) tools/mmx6/walls.py --self-test && $(PYTHON) tools/mmx6/walls.py --check

# The draw filter (tools/mmx6/draw.py; needs the reports, twins and walls): planted L1-L4, exclude-audit, leverage,
# --band and harvest-stamp controls in .run/draw-selftest/, then the exclude audit (`EXCLUDE AUDIT <r> rows, <s> stale`,
# rc 2 if s > 0) and the real draw (build/draw/draw.jsonl; last line `DRAW refused <r> of <n> (…); drawn <k>`).
th-draw: th-report th-sig th-walls
	$(PYTHON) tools/mmx6/draw.py --self-test && $(PYTHON) tools/mmx6/draw.py --audit && $(PYTHON) tools/mmx6/draw.py

# The target validator (tools/mmx6/validate.py; needs the draw): planted out-of-range/phantom/banked/no-asm/lib controls
# in .run/validate-selftest/, then every `draw` row of build/draw/draw.jsonl (INVALID lines only; last
# `VALIDATE <ok> of <n>`, rc 1 if any invalid: the draw filter never passes an invalid target).
th-validate: th-draw
	$(PYTHON) tools/mmx6/validate.py --self-test && $(PYTHON) tools/mmx6/validate.py --drawn

# The citation auditor (tools/mmx6/gccsrc.py; needs /opt/gcc-2.95.2-src only when a citation exists): planted good,
# drifted, missing and wrong-fragment cites in .run/gccsrc-selftest/, then --check of docs/codegen-map/*.md and
# cookbook/C*.md (last line `CITES OK <c> of <c> citations`).
th-cites:
	$(PYTHON) tools/mmx6/gccsrc.py --self-test && $(PYTHON) tools/mmx6/gccsrc.py --check

# Per-pass cc1 dumps (tools/mmx6/dumps.py; needs the built C objects): planted function's every -da suffix and an
# empty .c refused CPP-EMPTY in .run/dumps-selftest/, then 120A0's dumps with its .text equal to the built object
# (last line `DUMPS TEXT SLUS_013.95/120A0 words <a> built <b> identical`).
th-dumps:
	$(PYTHON) tools/mmx6/dumps.py --self-test && $(PYTHON) tools/mmx6/dumps.py --tu SLUS_013.95/120A0

# The allocation table (tools/mmx6/alloc_table.py; needs the built C objects' asm): planted A/B pair whose reference
# counts swap global-alloc's order and hard regs 16<->17, a truncated .greg and a missing order pseudo, in
# .run/alloc-selftest/; then 120A0's table (an `ALLOC SLUS_013.95/120A0:<f> pseudos <n> order <k>` line per function).
th-alloc:
	$(PYTHON) tools/mmx6/alloc_table.py --self-test && $(PYTHON) tools/mmx6/alloc_table.py --tu SLUS_013.95/120A0

th-repro:
	$(PYTHON) tools/mmx6/repro.py --self-test && $(PYTHON) tools/mmx6/repro.py --all

# T5 widens --groups to all six.
th-map:
	$(PYTHON) tools/mmx6/codegen_map.py --self-test && $(PYTHON) tools/mmx6/codegen_map.py

th-cookbook:
	$(PYTHON) tools/mmx6/cookbook_check.py --self-test && $(PYTHON) tools/mmx6/cookbook_check.py --check

th-propagate-full: th-propagate
	@set -e; for k in $(PROPAGATE_KEYS); do $(PYTHON) tools/mmx6/propagate.py $$k --dry-run; done

# The other tools' self-tests (not rungs of their own): boundaries.py, loadmap.py, probe.py, bank.py (the reconcile
# ladder's planted controls: clean rebuilds of the exe, tree restored after), x4share.py (its real run needs network).
th-selftests:
	$(PYTHON) tools/mmx6/boundaries.py --self-test
	$(PYTHON) tools/mmx6/loadmap.py --self-test
	$(PYTHON) tools/mmx6/probe.py --self-test
	$(PYTHON) tools/mmx6/bank.py --self-test
	$(PYTHON) tools/mmx6/x4share.py --self-test

# The permuter wrapper (tools/mmx6/permute.py; decomp-permuter pinned in the image): planted controls only in
# .run/permute/ (xor operand swap reaches masked 0 with the stock-scorer contrast, register pin hidden and restored,
# K&R refused, upstream clean); ~15 s. No real run here: the stored draft (T7.c2) runs on its own.
th-permute:
	$(PYTHON) tools/mmx6/permute.py --self-test

# The plateau classifier (tools/mmx6/plateau.py): planted regalloc/sched/branch/identical pairs in
# .run/plateau-selftest/, then the stored draft's residual label and triage rows (`PLATEAU <func> <label> …`).
th-plateau:
	$(PYTHON) tools/mmx6/plateau.py --self-test && $(PYTHON) tools/mmx6/plateau.py --draft drafts/SLUS_013.95/func_80042F20.c

# The campaign journal (tools/mmx6/journal.py): planted append/refusals/edit/rate in .run/journal-selftest/, then
# the real campaign/journal.jsonl's append-only check (`JOURNAL OK <r> records`).
th-journal:
	$(PYTHON) tools/mmx6/journal.py --self-test && $(PYTHON) tools/mmx6/journal.py --check

# The wave cards (tools/mmx6/cards.py): planted cases in .run/cards-selftest/ (a dup-class member seeded by a banked
# twin, a planted journal record on the next card, unresolved C/L ids refused with no pack dir); `CARDS CONTROL OK`.
th-cards: th-sig th-journal
	$(PYTHON) tools/mmx6/cards.py --self-test

# The verbatim check (tools/mmx6/verbatim.py, DK-29): planted bodies in .run/verbatim-selftest/ (inline asm,
# directive, INCLUDE_ASM refused; a pin counted, a commented pin not), then every src/shared and drafts .c file.
th-verbatim:
	$(PYTHON) tools/mmx6/verbatim.py --self-test && $(PYTHON) tools/mmx6/verbatim.py --all

# The harvest gate (tools/mmx6/harvest.py, G45): planted live/inert levers (the exemplar body, compiled both ways in
# a snapshot), refused waves (live lever without record, sweep tag without sweep record), a stamped complete wave and
# check-all in .run/harvest-selftest/; then every journal wave has a current stamp (`HARVEST GATES OK <w> of <w> waves`).
th-harvest:
	$(PYTHON) tools/mmx6/harvest.py --self-test && $(PYTHON) tools/mmx6/harvest.py --check-all

# The scaffold lane (tools/mmx6/scaffold.py): planted c-empty functions in build/scaffold/selftest/ (a trivial m2c
# scaffold scores 0, a one-word mutation > 0, a planted syntax error nocompile, a re-run adds no rows, the match's gate
# pack). No real run here: `scaffold.py --all` is the detached lane run (docs/ops/campaign.md ## Scaffold lane).
th-scaffold: th-corpus
	$(PYTHON) tools/mmx6/scaffold.py --self-test

# The ledger (tools/mmx6/ledger.py): planted inputs in .run/ledger-selftest/ (every class/blocker rule; a missing
# function, a C function's row, an unknown blocker, an INCLUDE_ASM best draft each refused), then campaign/ledger.tsv
# against the corpus (one well-formed row per asm function). Rebuilt by `ledger.py --build` (docs/ops/campaign.md ## Ledger).
th-ledger: th-corpus
	$(PYTHON) tools/mmx6/ledger.py --self-test
	$(PYTHON) tools/mmx6/ledger.py --check

# The wave gate (tools/mmx6/gate.py; full chain only: it plants and banks in /work like bank.py's self-test): planted
# exe + overlay members in .run/gate-selftest/ (bank, define recovery, plateau-labelled fail, MISSING asm, two
# programs concurrently, lock refused); /work restored byte-exact and both binaries rebuilt to their sha1 after.
th-gate:
	$(PYTHON) tools/mmx6/gate.py --self-test
