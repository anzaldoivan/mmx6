# make-format.snippet.mk — appended to the project's Makefile by decomp-architect (install.py S9).
# `make format` rewrites every C source and header under src/ with the tracked .clang-format; `make format-check`
# is the same run in dry mode with warnings as errors (a CI-able check, no game bytes needed). Dotfiles under src/
# are excluded so a tool's live probe file is never formatted into the tree.

.PHONY: format format-check split build build-bins clean extract scratch-check ghidra-import ghidra-import-overlays ghidra-export ghidra-roundtrip ghidra-mcp-start ghidra-mcp-stop redux-smoke redux-loads loadmap boundaries toolchain-check

# Extractor (tools/mmx6/, stdlib only). CUE defaults to the container's disc volume; on the Mac pass CUE=<path>.
PYTHON ?= python3
CUE ?= /disc/Mega Man X6 (USA) (v1.1).cue
SCRATCH_CAP_GB ?= 25
SCRATCH_WARN_GB ?= 20
# Toolchain pins (container; docs/ops/mmx6-hosts.md Pins): `make toolchain-check` fails on drift.
SPLAT_PIN ?= 0.50.0
BINUTILS_PIN ?= 2.42
CPP_PIN ?= 12.4.0

extract:
	$(PYTHON) tools/mmx6/extract.py --cue "$(CUE)" --out extracted/retail --manifest manifest/retail.jsonl --medium config/medium.sha1

# All-asm build (container): `make split build` → splat config/<bin>.yaml → asm/<bin>/, assemble every .s, link with
# the splat ld script, objcopy → build/<bin>, then the hash gate config/check.<bin>.sha. `clean` never touches extracted/.
BINS ?= SLUS_013.95
AS_SHIM ?=
AS := $(AS_SHIM) mipsel-linux-gnu-as
LD := mipsel-linux-gnu-ld
OBJCOPY := mipsel-linux-gnu-objcopy
ASFLAGS := -EL -march=r3000 -mtune=r3000 -mabi=32 -no-pad-sections -G0 -Iinclude
# No C compiler is pinned before phase 1.4; any .c reaching the rule below fails loudly.
CC1 ?=

split:
	for b in $(BINS); do splat split config/$$b.yaml || exit 1; done

# A failed hash check deletes build/<bin>, so a rerun cannot pass on a stale red output.
.DELETE_ON_ERROR:

# Sub-make so the .s list is read after `split` has written it.
build:
	$(MAKE) build-bins

build-bins: $(foreach b,$(BINS),build/$(b))

S_FILES = $(shell find asm/$(1) -name '*.s' 2>/dev/null)

define BIN_RULES
build/$(1).elf: $(patsubst %.s,build/%.s.o,$(call S_FILES,$(1))) build/$(1).ld
	$$(LD) -o $$@ -Map build/$(1).map -T build/$(1).ld \
	  -T build/undefined_syms_auto.$(1).txt -T build/undefined_funcs_auto.$(1).txt --no-check-sections
build/$(1): build/$(1).elf
	$$(OBJCOPY) -O binary $$< $$@
	sha1sum -c config/check.$(1).sha
endef
$(foreach b,$(BINS),$(eval $(call BIN_RULES,$(b))))

build/%.s.o: %.s include/macro.inc
	@mkdir -p $(dir $@)
	$(AS) $(ASFLAGS) -o $@ $<

%.s: %.c
	@if [ -z "$(CC1)" ]; then echo "CC1 unset: no C compiler pinned until phase 1.4: $<" >&2; exit 1; fi
	$(CC1) $< -o $@

clean:
	rm -rf asm build

toolchain-check:
	sh tools/mmx6/toolchain_check.sh "$(SPLAT_PIN)" "$(BINUTILS_PIN)" "$(CPP_PIN)"

scratch-check:
	$(PYTHON) tools/mmx6/scratch.py --root .run --cap-gb $(SCRATCH_CAP_GB) --warn-gb $(SCRATCH_WARN_GB)

# Static oracle (Mac-only, docs/ops/oracles.md): headless Ghidra + psx_ldr import of the exe into ghidra/mmx6.
GHIDRA_HOME ?= $(HOME)/ghidra_12.1.3_PUBLIC

ghidra-import:
	GHIDRA_HOME="$(GHIDRA_HOME)" bash tools/mmx6/ghidra/import.sh --program SLUS_013.95

# Every `code` member of config/loadmap.txt as raw program rock_NN at its loadmap base (one JVM per base group).
ghidra-import-overlays:
	GHIDRA_HOME="$(GHIDRA_HOME)" bash tools/mmx6/ghidra/import.sh --member all

# Annotation export (read-only) to config/ghidra/<program>.jsonl, and its round trip into .run/ghidra/rebuild/;
# both cover SLUS_013.95 + every code member of config/loadmap.txt.
ghidra-export:
	GHIDRA_HOME="$(GHIDRA_HOME)" bash tools/mmx6/ghidra/export.sh --all

ghidra-roundtrip:
	GHIDRA_HOME="$(GHIDRA_HOME)" bash tools/mmx6/ghidra/roundtrip.sh

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

# Forced boundaries (jump tables, PsyQ objects, -O0 candidates, missed func starts) per program → config/boundaries.txt.
boundaries:
	$(PYTHON) tools/mmx6/boundaries.py --out config/boundaries.txt --psyq-dir "$(GHIDRA_HOME)/Ghidra/Extensions/ghidra_psx_ldr/data/psyq"

format:
	find src -type f \( -name '*.c' -o -name '*.h' \) -not -name '.*' -print0 | xargs -0 -r clang-format -i --style=file

format-check:
	find src -type f \( -name '*.c' -o -name '*.h' \) -not -name '.*' -print0 | xargs -0 -r clang-format --dry-run --Werror --style=file
