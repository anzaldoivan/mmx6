# tools-health.mk — the tools-health chain (container), included by the Makefile and run by `make health` (so by
# `make fleet`). One rung per phase tool: a rung runs the tool's --self-test, then its real run; later tasks append
# their rung to TOOLS_HEALTH_RUNGS. Last line `TOOLS-HEALTH OK <k> rungs`.

TOOLS_HEALTH_RUNGS := th-corpus th-boundcheck th-optscan th-bound2 th-census

.PHONY: tools-health $(TOOLS_HEALTH_RUNGS)

tools-health: $(TOOLS_HEALTH_RUNGS)
	@echo "TOOLS-HEALTH OK $(words $(TOOLS_HEALTH_RUNGS)) rungs"

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
