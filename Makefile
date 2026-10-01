# make-format.snippet.mk — appended to the project's Makefile by decomp-architect (install.py S9).
# `make format` rewrites every C source and header under src/ with the tracked .clang-format; `make format-check`
# is the same run in dry mode with warnings as errors (a CI-able check, no game bytes needed). Dotfiles under src/
# are excluded so a tool's live probe file is never formatted into the tree.

.PHONY: format format-check split build build-bins clean extract scratch-check ghidra-import ghidra-import-overlays ghidra-export ghidra-roundtrip ghidra-mcp-start ghidra-mcp-stop redux-smoke redux-loads loadmap boundaries toolchain-check health fleet expected probe-ladder

# Extractor (tools/mmx6/, stdlib only). CUE defaults to the container's disc volume; on the Mac pass CUE=<path>.
PYTHON ?= python3
CUE ?= /disc/Mega Man X6 (USA) (v1.1).cue
SCRATCH_CAP_GB ?= 25
SCRATCH_WARN_GB ?= 20
# Toolchain pins (container; docs/ops/mmx6-hosts.md Pins): `make toolchain-check` fails on drift.
SPLAT_PIN ?= 0.50.0
BINUTILS_PIN ?= 2.42
CPP_PIN ?= 12.4.0
# Candidate cc1 set (decompals/old-gcc 0.17 + 0.9 for plain 2.7.2) at /opt/cc/<name>/cc1; maspsx pinned by commit.
OLDGCC_PIN ?= 0.17
CC1_SET ?= 2.7.2 2.7.2-psx 2.7.2-cdk 2.6.3-psx 2.8.0-psx 2.8.1-psx 2.91.66-psx 2.95.2-psx
MASPSX_PIN ?= 7686f845a181700534c83c0419183e38aeb3e49c

extract:
	$(PYTHON) tools/mmx6/extract.py --cue "$(CUE)" --out extracted/retail --manifest manifest/retail.jsonl --medium config/medium.sha1

# All-asm build (container): `make split build` → splat config/<bin>.yaml → asm/<bin>/, assemble every .s, link with
# the splat ld script, objcopy → build/<bin> (exe) or build/rock/NN.bin (bin rock_NN), then the hash gate
# config/check.<bin>.sha. BINS = every config/*.yaml. `clean` never touches extracted/.
BINS ?= $(patsubst config/%.yaml,%,$(wildcard config/*.yaml))
EXE_BINS := $(filter-out rock_%,$(BINS))
ROCK_BINS := $(filter rock_%,$(BINS))
BIN_OUTS := $(addprefix build/,$(EXE_BINS)) $(patsubst rock_%,build/rock/%.bin,$(ROCK_BINS))
AS_SHIM ?=
AS := $(AS_SHIM) mipsel-linux-gnu-as
LD := mipsel-linux-gnu-ld
OBJCOPY := mipsel-linux-gnu-objcopy
NM := mipsel-linux-gnu-nm
ASFLAGS := -EL -march=r3000 -mtune=r3000 -mabi=32 -no-pad-sections -G0 -Iinclude
# Overlays are one asm TU each, so their data words reach gas as instructions; rabbitizer's R3000GTE category
# decodes some as MIPS II/III ops (dsll32, tge, ll, sync, sdc1 ...) that -march=r3000 rejects. r4000 only widens
# the accepted set: same encodings under `.set noreorder`, and the sha1 gate checks every overlay byte (T5.c1).
# -mno-fix-loongson3-llsc: this binutils build otherwise inserts a `sync` before every `ll` (rock_03 +0xE488).
build/asm/rock_%.o: ASFLAGS := $(subst -march=r3000,-march=r4000,$(ASFLAGS)) -mno-fix-loongson3-llsc
# C compiler triple: one row of config/triples.txt (`<name> | cc1: ... | cflags: ... | maspsx: ...`) sets CC1,
# CFLAGS, MASPSX_FLAGS; an unknown TRIPLE stops make before any rule runs.
TRIPLE ?= gcc2.7.2-aspsx2.56
TRIPLE_FIELD = $(strip $(shell awk -F'|' -v t='$(TRIPLE)' -v k='$(1): ' '{ n = $$1; gsub(/^ +| +$$/, "", n) } \
  n == t { for (i = 2; i <= NF; i++) { f = $$i; gsub(/^ +| +$$/, "", f); if (index(f, k) == 1) print substr(f, length(k) + 1) } }' \
  config/triples.txt))
CC1 := $(call TRIPLE_FIELD,cc1)
CFLAGS := $(call TRIPLE_FIELD,cflags)
MASPSX_FLAGS := $(call TRIPLE_FIELD,maspsx)
ifeq ($(CC1),)
$(error TRIPLE '$(TRIPLE)' has no row in config/triples.txt)
endif
CPP := mipsel-linux-gnu-cpp
# -nostdinc: cpp 12 otherwise injects stdc-predef.h, whose line markers old cc1 warns on ("unrecognized text").
CPPFLAGS := -nostdinc -undef -D__GNUC__=2 -DPSX -Iinclude
MASPSX := maspsx

# One stamp per binary, so `make -jN split` runs the splat processes in parallel.
split: $(foreach b,$(BINS),build/split/$(b).stamp)

build/split/%.stamp: config/%.yaml config/symbols.%.txt
	splat split config/$*.yaml
	@mkdir -p $(dir $@) && touch $@

# A failed hash check deletes build/<bin>, so a rerun cannot pass on a stale red output.
.DELETE_ON_ERROR:
# Objects reached only through pattern rules stay on disk (no intermediate cleanup), so reruns are incremental.
.SECONDARY:

# Sub-make after split, so the .s list is read once `split` has written it (also when both are goals under -j).
build: split
	$(MAKE) build-bins

build-bins: $(BIN_OUTS)

# Objects of one binary: every .s and every bin subsegment (asset .bin) splat wrote under asm/<bin>/, except
# asm/<bin>/nonmatchings/ (INCLUDE_ASM pulls those into their C unit), and every C unit under src/<bin>/.
O_FILES = $(patsubst %,build/%.o,$(shell find asm/$(1) -path asm/$(1)/nonmatchings -prune -o \
  \( -name '*.s' -o -name '*.bin' \) -print 2>/dev/null) $(shell find src/$(1) -name '*.c' 2>/dev/null))

# An overlay's data words reach gas as code, so they reference D_<addr>/func_<addr> names splat counts as defined
# (inside the segment) but never labels, or j/jal targets outside RAM it never lists: build/<bin>.provide.ld
# PROVIDEs every still-undefined such name at the address its name spells (exact; the sha1 gate checks the bytes).
.SECONDEXPANSION:
build/%.elf: $$(call O_FILES,$$*) build/%.ld
	{ echo '/* generated by make: PROVIDE(<name> = <addr in name>) for undefined D_/func_ refs */'; \
	  $(NM) -u $(filter %.o,$^) | sed -n 's/^ *U \(\(D\|func\)_\([0-9A-F]\{8\}\)\)$$/PROVIDE(\1 = 0x\3);/p' | sort -u; \
	} > build/$*.provide.ld
	$(LD) -o $@ -Map build/$*.map -T build/$*.ld \
	  -T build/undefined_syms_auto.$*.txt -T build/undefined_funcs_auto.$*.txt -T build/$*.provide.ld \
	  --no-check-sections

$(addprefix build/,$(EXE_BINS)): build/%: build/%.elf
	$(OBJCOPY) -O binary $< $@
	sha1sum -c config/check.$*.sha

build/rock/%.bin: build/rock_%.elf
	@mkdir -p $(dir $@)
	$(OBJCOPY) -O binary $< $@
	sha1sum -c config/check.rock_$*.sha

build/%.s.o: %.s include/macro.inc
	@mkdir -p $(dir $@)
	$(AS) $(ASFLAGS) -o $@ $<

# An overlay data word decodes as MIPS `ll`, which splat's GTE `ll` macro (include/gte_macros.inc, written by
# splat split) shadows: overlay sources get macro.inc first, then that macro is purged (assembler lines are +2).
build/asm/rock_%.s.o: asm/rock_%.s include/macro.inc
	@mkdir -p $(dir $@)
	{ printf '.include "macro.inc"\n.purgem ll\n'; cat $<; } | $(AS) $(ASFLAGS) -o $@ --

# A bin subsegment (an overlay's 1-3 byte tail) as raw .data bytes.
build/%.bin.o: %.bin
	@mkdir -p $(dir $@)
	printf '.section .data\n.incbin "%s"\n' $< | $(AS) $(ASFLAGS) -o $@ --

# A C unit: cpp | cc1 | maspsx | as (exe ASFLAGS). bash with pipefail, so a failing stage fails the rule (sh is dash).
build/%.c.o: SHELL := /bin/bash
build/%.c.o: .SHELLFLAGS := -o pipefail -c
build/%.c.o: %.c include/common.h include/macro.inc
	@mkdir -p $(dir $@)
	$(CPP) $(CPPFLAGS) $< | $(CC1) $(CFLAGS) | $(MASPSX) $(MASPSX_FLAGS) | $(AS) $(ASFLAGS) -o $@ --

clean:
	rm -rf asm build

# Every forced lib edge of config/boundaries.txt is a subsegment edge of its config/<bin>.yaml (container).
health:
	$(PYTHON) tools/mmx6/boundcheck.py

# The clean fleet verification (container): last line `FLEET <ok> of <n>`, rc 0 only when every binary is green.
fleet:
	@MAKE="$(MAKE)" bash tools/mmx6/fleet.sh

# asm-differ baseline: expected/<repo-relative path> of every build output.
expected: build
	rm -rf expected && mkdir -p expected && cp -R build expected/build

# The triple ladder (container): every config/probes.txt row under every config/triples.txt row; rc 0 only on a
# unique `PIN <triple> <k> of <k>`.
probe-ladder:
	$(PYTHON) tools/mmx6/probe.py --ladder

toolchain-check:
	sh tools/mmx6/toolchain_check.sh "$(SPLAT_PIN)" "$(BINUTILS_PIN)" "$(CPP_PIN)" "$(CC1_SET)" "$(MASPSX_PIN)"

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
