# tools-health.mk — the tools-health chain (container), included by the Makefile and run by `make health` (so by
# `make fleet`). One rung per phase tool: a rung runs the tool's --self-test, then its real run; later tasks append
# their rung to TOOLS_HEALTH_RUNGS. Last line `TOOLS-HEALTH OK <k> rungs`.

TOOLS_HEALTH_RUNGS := th-corpus th-boundcheck th-optscan th-bound2 th-census th-sig th-report th-harness th-types th-declsync th-propagate th-carve
# `make tools-health-full`: the same chain with the full harness (adds P3, a touch + rebuild) and every other tool's
# --self-test that is not a rung, and th-propagate with every registry key's --dry-run.
TOOLS_HEALTH_FULL_RUNGS := $(filter-out th-harness th-propagate,$(TOOLS_HEALTH_RUNGS)) th-harness-full th-propagate-full \
	th-selftests

.PHONY: tools-health tools-health-full $(TOOLS_HEALTH_RUNGS) th-harness-full th-propagate-full th-selftests

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
# disagreement per pair + NOT-RUN control, then the sampled pairs P1 P2 P4 P5 P6 P7 (build/harness/runs.log; last line
# `HARNESS <d> disagreements in <p> pairs`, rc 0 iff d = 0).
th-harness: th-corpus th-optscan th-bound2 th-census
	$(PYTHON) tools/mmx6/harness.py --self-test && $(PYTHON) tools/mmx6/harness.py --sampled

th-harness-full: th-corpus th-optscan th-bound2 th-census
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
PROPAGATE_KEYS = $(shell awk '!/^\#/ && NF >= 5 {print $$1}' config/dedup_registry.txt | sort -u)

th-propagate: th-corpus th-census
	$(PYTHON) tools/mmx6/propagate.py --self-test && $(PYTHON) tools/mmx6/propagate.py --check

# Carves (tools/mmx6/carve.py; needs the corpus): planted refusals on a scratch copy under .run/, then --check of
# every config/carve.<prog>.txt row, its .mk and every yaml block (last line `CARVE CHECK OK <n> carves`).
th-carve: th-corpus
	$(PYTHON) tools/mmx6/carve.py --self-test && $(PYTHON) tools/mmx6/carve.py --check

th-propagate-full: th-propagate
	@set -e; for k in $(PROPAGATE_KEYS); do $(PYTHON) tools/mmx6/propagate.py $$k --dry-run; done

# The other tools' self-tests (not rungs of their own): boundaries.py, loadmap.py, probe.py, bank.py (the reconcile
# ladder's planted controls: clean rebuilds of the exe, tree restored after).
th-selftests:
	$(PYTHON) tools/mmx6/boundaries.py --self-test
	$(PYTHON) tools/mmx6/loadmap.py --self-test
	$(PYTHON) tools/mmx6/probe.py --self-test
	$(PYTHON) tools/mmx6/bank.py --self-test
