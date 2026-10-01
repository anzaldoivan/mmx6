# make-format.snippet.mk — appended to the project's Makefile by decomp-architect (install.py S9).
# `make format` rewrites every C source and header under src/ with the tracked .clang-format; `make format-check`
# is the same run in dry mode with warnings as errors (a CI-able check, no game bytes needed). Dotfiles under src/
# are excluded so a tool's live probe file is never formatted into the tree.

.PHONY: format format-check extract scratch-check ghidra-import

# Extractor (tools/mmx6/, stdlib only). CUE defaults to the container's disc volume; on the Mac pass CUE=<path>.
PYTHON ?= python3
CUE ?= /disc/Mega Man X6 (USA) (v1.1).cue
SCRATCH_CAP_GB ?= 25
SCRATCH_WARN_GB ?= 20

extract:
	$(PYTHON) tools/mmx6/extract.py --cue "$(CUE)" --out extracted/retail --manifest manifest/retail.jsonl --medium config/medium.sha1

scratch-check:
	$(PYTHON) tools/mmx6/scratch.py --root .run --cap-gb $(SCRATCH_CAP_GB) --warn-gb $(SCRATCH_WARN_GB)

# Static oracle (Mac-only, docs/ops/oracles.md): headless Ghidra + psx_ldr import of the exe into ghidra/mmx6.
GHIDRA_HOME ?= $(HOME)/ghidra_12.1.3_PUBLIC

ghidra-import:
	GHIDRA_HOME="$(GHIDRA_HOME)" bash tools/mmx6/ghidra/import.sh --program SLUS_013.95

format:
	find src -type f \( -name '*.c' -o -name '*.h' \) -not -name '.*' -print0 | xargs -0 -r clang-format -i --style=file

format-check:
	find src -type f \( -name '*.c' -o -name '*.h' \) -not -name '.*' -print0 | xargs -0 -r clang-format --dry-run --Werror --style=file
