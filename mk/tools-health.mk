# tools-health.mk — the tools-health chain (container), included by the Makefile and run by `make health` (so by
# `make fleet`). One rung per phase tool: a rung runs the tool's --self-test, then its real run; later tasks append
# their rung to TOOLS_HEALTH_RUNGS. Last line `TOOLS-HEALTH OK <k> rungs`.

TOOLS_HEALTH_RUNGS := th-corpus th-boundcheck th-optscan th-bound2 th-census th-sig th-report th-harness
# `make tools-health-full`: the same chain with the full harness (adds P3, a touch + rebuild) and every other tool's
# --self-test that is not a rung.
TOOLS_HEALTH_FULL_RUNGS := $(filter-out th-harness,$(TOOLS_HEALTH_RUNGS)) th-harness-full th-selftests

.PHONY: tools-health tools-health-full $(TOOLS_HEALTH_RUNGS) th-harness-full th-selftests

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

# The other tools' self-tests (not rungs of their own): boundaries.py, loadmap.py, probe.py.
th-selftests:
	$(PYTHON) tools/mmx6/boundaries.py --self-test
	$(PYTHON) tools/mmx6/loadmap.py --self-test
	$(PYTHON) tools/mmx6/probe.py --self-test
