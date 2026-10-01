# make-format.snippet.mk — appended to the project's Makefile by decomp-architect (install.py S9).
# `make format` rewrites every C source and header under src/ with the tracked .clang-format; `make format-check`
# is the same run in dry mode with warnings as errors (a CI-able check, no game bytes needed). Dotfiles under src/
# are excluded so a tool's live probe file is never formatted into the tree.

.PHONY: format format-check extract scratch-check ghidra-import ghidra-export ghidra-roundtrip ghidra-mcp-start ghidra-mcp-stop redux-smoke redux-loads loadmap

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

# Annotation export (read-only) to config/ghidra/<program>.jsonl, and its round trip into .run/ghidra/rebuild/.
ghidra-export:
	GHIDRA_HOME="$(GHIDRA_HOME)" bash tools/mmx6/ghidra/export.sh SLUS_013.95

ghidra-roundtrip:
	GHIDRA_HOME="$(GHIDRA_HOME)" bash tools/mmx6/ghidra/roundtrip.sh SLUS_013.95

# GhidrAssistMCP server (headless, detached) on ghidra/mmx6; stop saves, releases the lock, proves a read-only reopen.
ghidra-mcp-start:
	GHIDRA_HOME="$(GHIDRA_HOME)" bash tools/mmx6/ghidra/mcp_start.sh

ghidra-mcp-stop:
	GHIDRA_HOME="$(GHIDRA_HOME)" bash tools/mmx6/ghidra/mcp_stop.sh

# Runtime oracle (Mac-only, docs/ops/oracles.md): PCSX-Redux headless + repo Lua. REDUX_CUE is the host disc
# path (not CUE, whose default is the container's). Smoke: RAM dumps at 3 moments → .run/redux/smoke/.
REDUX ?= $(HOME)/Applications/PCSX-Redux.app/Contents/MacOS/PCSX-Redux
BIOS ?= /Users/ThinkPad/GameInputs/megaman-x6/SCPH1001.BIN
REDUX_CUE ?= /Users/ThinkPad/GameInputs/megaman-x6/Mega Man X6 (USA) (v1.1).cue

redux-smoke:
	REDUX="$(REDUX)" BIOS="$(BIOS)" REDUX_CUE="$(REDUX_CUE)" bash tools/mmx6/redux/run.sh tools/mmx6/redux/smoke.lua --timeout 240

# Overlay load captures: loads.lua once per pad schedule tools/mmx6/redux/inputs/*.lua → .run/redux/loads/<run>.jsonl.
redux-loads:
	for f in tools/mmx6/redux/inputs/*.lua; do \
	  MMX6_INPUTS="$$PWD/$$f" REDUX="$(REDUX)" BIOS="$(BIOS)" REDUX_CUE="$(REDUX_CUE)" \
	    bash tools/mmx6/redux/run.sh tools/mmx6/redux/loads.lua --timeout 600 || exit 1; \
	done

# Member -> base map (Mac-only: exe + members + captures + smoke dumps) → config/loadmap.txt; rc 1 on a failed control.
loadmap:
	$(PYTHON) tools/mmx6/loadmap.py --out config/loadmap.txt

format:
	find src -type f \( -name '*.c' -o -name '*.h' \) -not -name '.*' -print0 | xargs -0 -r clang-format -i --style=file

format-check:
	find src -type f \( -name '*.c' -o -name '*.h' \) -not -name '.*' -print0 | xargs -0 -r clang-format --dry-run --Werror --style=file
