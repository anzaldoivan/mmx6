# tools-health.mk — the tools-health chain (container), included by the Makefile and run by `make health` (so by
# `make fleet`). One rung per phase tool: a rung runs the tool's --self-test, then its real run; later tasks append
# their rung to TOOLS_HEALTH_RUNGS. Last line `TOOLS-HEALTH OK <k> rungs`.

TOOLS_HEALTH_RUNGS := th-corpus th-boundcheck th-optscan th-bound2 th-census th-sig th-selftests-cheap th-report th-types th-declsync th-propagate th-carve th-remap \
	th-walls th-draw th-validate th-cites th-dumps th-alloc th-repro th-map th-cookbook th-permute th-plateau th-journal th-cards \
	th-verbatim th-harvest th-scaffold th-ledger th-harness th-globtypes th-objfields th-lift th-namesqueue
# `make tools-health-full`: the same chain with the full harness (adds P3, a touch + rebuild) and every other tool's
# --self-test that is not a rung, and th-propagate with every registry key's --dry-run.
TOOLS_HEALTH_FULL_RUNGS := $(filter-out th-harness th-propagate,$(TOOLS_HEALTH_RUNGS)) th-harness-full th-propagate-full \
	th-selftests th-gate

# `make tools-health-shard SHARD=k` (2.7 T4): tools-health-full split into CI-sized jobs. Shard 0 = every full rung
# but th-propagate-full; shards 1..n = th-corpus th-census, then the propagate dry-run over thshard.py's slice k of
# $(PROPAGATE_KEYS_CMD). thshard.py's cost model (its docstring), refit 3.0 T6 on the timed shard 1: SLUS 20 s per
# (key, prog) unit, at most 101 SLUS units per shard, other programs 17 s (36 s with a refused row); shard 0 measured
# 1474 s; container nproc 8; slices close at 7650 s, budget 9000 s per shard. Shard 0 runs in parallel as
# tools-health (below). Run after a build, with no `mx.sh sync` between. Each shard ends `TOOLS-HEALTH SHARD <k> of
# <n> OK`; a missing or out-of-range SHARD is rc 2. `make tools-health-shards-check`: the shards cover the key list
# once, in order, each within budget.
TOOLS_HEALTH_SHARD0_RUNGS := $(filter-out th-propagate-full,$(TOOLS_HEALTH_FULL_RUNGS))

.PHONY: tools-health tools-health-full $(TOOLS_HEALTH_RUNGS) th-harness-full th-propagate-full th-equiv th-selftests th-gate \
	tools-health-shard tools-health-shards-check th-par th-propagate-since

# Parallel chain (3.0 T6; was serial goals with th-time-* marks, 3.0 T3, C0431): tools-health, tools-health-full and
# tools-health-shard SHARD=0 run their rungs as the goals of one sub-make, -j$(JOBS) -Otarget (each rung's output
# grouped), with the goal th-par, which turns on the ordering below; a rung made on its own (`make th-draw`) keeps
# only its data prerequisites. Each rung runs once. Data dependencies are plain prerequisites (always); shared state
# is ordered order-only (th-par only): every parallel rung first, then the serial rungs one at a time, nothing beside
# them, in TH_SERIAL order:
#   th-lift           nested make -j8 (wants the 8 cores alone) and a make of the real binary
#   th-harness-full    (full) touch + make build: rebuilds the objects other rungs read (dumps, alloc, objfields)
#   th-propagate       shared .run/propagate/tree, 8-process pool (the prerequisite of th-propagate-full)
#   th-propagate-full  (full) the same tree and pool, every registry key
#   th-selftests       (full) bank.py --self-test edits src/ and the registry, make -B
#   th-gate            (full) plants and banks in /work, restores src/, registry, corpus and exes
# and th-dumps, th-alloc, th-repro one after another (all three write build/dumps; alloc re-dumps 120A0 as dumps
# does: run beside it, a .greg read half-written was ALLOC TRUNCATED, T6.c1 fleet 1). th-harness (8 threads, the long pole) overlaps the light
# rungs: $(JOBS) jobs in all, never a nested -j8 beside them. JOBS: MX6_JOBS (mx.sh run with MX6_CPUS), else 8.
# Rung walls: each rung's recipe starts with th_t0 (stamp build/th-wall/<rung>) and ends with th_t1, which prints
# `TH-WALL <rung> <s>s`, the rung's own start-to-end seconds (one stamp file per rung: race-free under -j). Both are
# empty without th-par. The sub-make lines name $(MAKE) literally, so `make -n` descends into them.
JOBS ?= $(or $(MX6_JOBS),8)
TH_SERIAL := th-lift th-harness-full th-propagate th-propagate-full th-selftests th-gate
TH_WALLS := build/th-wall
TH_PAR := --no-print-directory -j$(JOBS) -Otarget th-par

th-par:
	@:

ifneq ($(filter th-par,$(MAKECMDGOALS)),)
th_t0 = mkdir -p $(TH_WALLS) && date +%s%N > $(TH_WALLS)/$@
th_t1 = now=$$(date +%s%N); awk -v r=$@ -v d=$$((now - $$(cat $(TH_WALLS)/$@))) 'BEGIN { printf "TH-WALL %s %.1fs\n", r, d / 1e9 }'
TH_GOALS := $(filter-out th-par,$(MAKECMDGOALS))
# th-propagate joins the chain when th-propagate-full is a goal (not a goal itself in the full list): as a plain
# prerequisite it would start as soon as th-corpus th-census end.
TH_SER := $(filter $(TH_GOALS) $(if $(filter th-propagate-full,$(TH_GOALS)),th-propagate),$(TH_SERIAL))
# The first serial rung waits for every parallel goal, each next one for the one before.
th_chain = $(if $(2),$(eval $(firstword $(2)): | $(1))$(call th_chain,$(firstword $(2)),$(wordlist 2,$(words $(2)),$(2))))
$(call th_chain,$(filter-out $(TH_SERIAL),$(TH_GOALS)),$(TH_SER))
th-alloc: | th-dumps
th-repro: | th-alloc
endif

tools-health:
	@$(MAKE) $(TH_PAR) $(TOOLS_HEALTH_RUNGS)
	@echo "TOOLS-HEALTH OK $(words $(TOOLS_HEALTH_RUNGS)) rungs"

tools-health-full:
	@$(MAKE) $(TH_PAR) $(TOOLS_HEALTH_FULL_RUNGS)
	@echo "TOOLS-HEALTH OK $(words $(TOOLS_HEALTH_FULL_RUNGS)) rungs"

# The shard's keys are buffered in a variable (no pipefail in sh): a thshard.py failure stops the recipe instead of
# feeding propagate.py an empty list. A green shard k>=1 writes its marker (propsince.py record --shard, 3.1 T23):
# shards 1..n green on one tree -> build/propagate/green.json, as th-propagate-full.
tools-health-shard:
	@set -e; n=$$($(PROPAGATE_KEYS_CMD) | $(PYTHON) tools/mmx6/thshard.py count); \
	case "$(SHARD)" in ''|*[!0-9]*) echo "tools-health-shard: SHARD=<0..$$n> required" >&2; exit 2;; esac; \
	if [ "$(SHARD)" -gt "$$n" ]; then echo "tools-health-shard: SHARD=$(SHARD) out of range 0..$$n" >&2; exit 2; fi; \
	if [ "$(SHARD)" -eq 0 ]; then \
		$(MAKE) $(TH_PAR) $(TOOLS_HEALTH_SHARD0_RUNGS); \
	else \
		$(MAKE) --no-print-directory th-corpus th-census; \
		keys=$$($(PROPAGATE_KEYS_CMD) | $(PYTHON) tools/mmx6/thshard.py keys $(SHARD)); \
		printf '%s\n' "$$keys" | $(PYTHON) tools/mmx6/propagate.py --dry-run --expect-registry --keys-from -; \
		printf '%s\n' "$$keys" | $(PYTHON) tools/mmx6/propsince.py record --shard $(SHARD) --of $$n; \
	fi; \
	echo "TOOLS-HEALTH SHARD $(SHARD) of $$n OK"

tools-health-shards-check:
	@set -e; $(PYTHON) tools/mmx6/thshard.py --self-test; \
	$(PROPAGATE_KEYS_CMD) | $(PYTHON) tools/mmx6/thshard.py check

# The function corpus and text denominator (tools/mmx6/corpus.py; needs the linked build).
th-corpus:
	@$(th_t0)
	$(PYTHON) tools/mmx6/corpus.py --self-test
	$(PYTHON) tools/mmx6/corpus.py --all
	@$(th_t1)

# Every forced lib edge is a subsegment edge of its yaml, over all config/*.yaml (tools/mmx6/boundcheck.py).
th-boundcheck:
	@$(th_t0)
	$(PYTHON) tools/mmx6/boundcheck.py --self-test
	$(PYTHON) tools/mmx6/boundcheck.py
	@$(th_t1)

# The codegen census covers every corpus asm function, per program (tools/mmx6/optscan.py; needs the corpus).
th-optscan: th-corpus
	@$(th_t0)
	$(PYTHON) tools/mmx6/optscan.py --self-test
	$(PYTHON) tools/mmx6/optscan.py --all
	@$(th_t1)

# The second boundary oracle (tools/mmx6/bound2.py; needs the corpus): controls, then `--all` (rc 0 iff no phantom
# or truncation; T5 cleared them with declared overlay boundaries, config/segmentation.md).
th-bound2: th-corpus
	@$(th_t0)
	$(PYTHON) tools/mmx6/bound2.py --self-test && $(PYTHON) tools/mmx6/bound2.py --all
	@$(th_t1)

# The census (tools/mmx6/census.py; needs the corpus): planted twin/mask/rename controls and the empty-body class,
# then `--all` (build/census/classes.jsonl; last line `CENSUS dup_classes=… of <N>`).
th-census: th-corpus
	@$(th_t0)
	$(PYTHON) tools/mmx6/census.py --self-test && $(PYTHON) tools/mmx6/census.py --all
	@$(th_t1)

# The twin band (tools/mmx6/sig.py; needs the census): planted exact/mask-off/near/out/past-RATIO/dropped-pair
# controls, then `--all` (build/sig/{sigs,twins}.jsonl; last line `TWINS exact_pairs <e> of <E> …`, rc 1 if e < E).
th-sig: th-census
	@$(th_t0)
	$(PYTHON) tools/mmx6/sig.py --self-test && $(PYTHON) tools/mmx6/sig.py --all
	@$(th_t1)

# The reports (tools/mmx6/report.py; needs the census): planted progress/difficulty/dup controls and real-corpus sums,
# then `--all` (build/reports/{progress,difficulty,dup}.{md,json}; last line `REPORT progress c … stubs <e>`).
th-report: th-census
	@$(th_t0)
	$(PYTHON) tools/mmx6/report.py --self-test && $(PYTHON) tools/mmx6/report.py --all
	@$(th_t1)

# The differential harness (tools/mmx6/harness.py; needs the corpus, bound2 and census outputs): planted
# disagreement per pair + NOT-RUN control, then the sampled pairs P1 P2 P4-P8 (build/harness/runs.log; last line
# `HARNESS <d> disagreements in <p> pairs`, rc 0 iff d = 0); one process, P2 compiled once (T19). Last rung (T19).
th-harness: th-corpus th-optscan th-bound2 th-census th-draw
	@$(th_t0)
	$(PYTHON) tools/mmx6/harness.py --self-test --sampled
	@$(th_t1)

th-harness-full: th-corpus th-optscan th-bound2 th-census th-draw
	@$(th_t0)
	$(PYTHON) tools/mmx6/harness.py --self-test --full
	@$(th_t1)

# One home for types (tools/mmx6/typecheck.py; text only, no deps): planted dup/raw-cast/outside/unkeyable controls,
# then `--all` (last line `TYPES <d> definitions <s> shapes of <f> files; duplicates <n>; raw casts <m>`, rc 0 iff none).
th-types:
	@$(th_t0)
	$(PYTHON) tools/mmx6/typecheck.py --self-test && $(PYTHON) tools/mmx6/typecheck.py --all
	@$(th_t1)

# One type per global (tools/mmx6/globtypes.py; text only + the link maps): planted sign/width/shape/view controls,
# then `--all` in the same process (C0283; last line `GLOBTYPES <g> globals <d> declarations; conflicts <n> (view <v>)`,
# rc 0 iff the non-view count is not above config/globtypes-baseline.txt).
th-globtypes:
	@$(th_t0)
	$(PYTHON) tools/mmx6/globtypes.py --self-test --all
	@$(th_t1)

# The object family's fields (tools/mmx6/objfields.py; cc1 over include/mmx6/object.h, the corpus): planted wrong
# offset/missing row/bad note/off-start controls, then config/types/fields.tsv vs the offsetof table, DC7 notes.
th-objfields: th-corpus
	@$(th_t0)
	$(PYTHON) tools/mmx6/objfields.py --self-test
	$(PYTHON) tools/mmx6/objfields.py --check
	@$(th_t1)

# The type lifter (tools/mmx6/lift.py; make + the pinned toolchain): scratch units under .run/<phase>/lift-selftest/,
# a fixture fields table: liftable -> lifted, bytes equal; width mismatch and unkXX -> refused (unkXX lifted with
# --unk); a byte-moving lift -> reverted. Last line `LIFT CONTROL OK`. No real run: lifting edits src/.
th-lift:
	@$(th_t0)
	$(PYTHON) tools/mmx6/lift.py --self-test
	@$(th_t1)

# Declaration sync, reconcile rung R3 (tools/mmx6/declsync.py; text only, in memory): synced/refused/uncast controls.
th-declsync:
	@$(th_t0)
	$(PYTHON) tools/mmx6/declsync.py --self-test
	@$(th_t1)

# Shared-body propagation (tools/mmx6/propagate.py; needs the corpus and census): planted registry controls, then
# every config/dedup_registry.txt row's built dup key vs its row (`REGISTRY OK <r> rows`). The --dry-run per registry
# key, --expect-registry: each member's verdict vs its registry row (refused rows legitimately refuse; disagreement ->
# `PROPAGATE DRIFT ...`, rc 1; 1.9 T14.c1), takes ~260 s on 8 workers, so it runs in tools-health-full only (T5.c3).
# Keys run grouped (1.8.1 T41.1): one process reads every key on stdin (--keys-from -), worker trees made once,
# per program one R5 clean rebuild over its group units (keys with a refused row run isolated, as per-key mode);
# per-key mode took ~21 s/key (3695 keys, ~22 h); verdicts identical on 47 keys (T41.1.c2).
# Keys are streamed (1.8.1 T41): an inline list of 3695 keys (151 KB) is one sh -c argument over Linux's 128 KB
# MAX_ARG_STRLEN, so exec failed (E2BIG, make Error 127).
PROPAGATE_KEYS_CMD = awk '!/^\#/ && NF >= 5 && $$6 != "family" {print $$1}' config/dedup_registry.txt | sort -u

th-propagate: th-corpus th-census
	@$(th_t0)
	$(PYTHON) tools/mmx6/propagate.py --self-test && $(PYTHON) tools/mmx6/propagate.py --check
	@$(th_t1)

# Carves (tools/mmx6/carve.py; needs the corpus): planted refusals on a scratch copy under .run/, then --check of
# every config/carve.<prog>.txt row, its .mk and every yaml block (last line `CARVE CHECK OK <n> carves`).
th-carve: th-corpus
	@$(th_t0)
	$(PYTHON) tools/mmx6/carve.py --self-test && $(PYTHON) tools/mmx6/carve.py --check
	@$(th_t1)

# Family remap (tools/mmx6/family_remap.py; needs the corpus and census): planted controls G (a jal-target-only
# sibling, gated through bank R5, its family row passes propagate.py --check) and R (reordered call pair, refused at
# pair); tree, registry, corpus and exe restored byte-exact. Runs in a scratch copy .run/remap/tree (3.1 T11), the real
# tree sha1-guarded, so it runs beside the other rungs (was serial, 160/161 s at the 3.0 T6 fleets); beside th-harness 408 s (3.1 T11 fleet).
# Prerequisites: every build/ output it copies and reads (3.0 T6): corpus, census, sig (bank R5's sig.py --rescan).
th-remap: th-corpus th-census th-sig
	@$(th_t0)
	$(PYTHON) tools/mmx6/family_remap.py --self-test
	@$(th_t1)

# The wall oracle (tools/mmx6/walls.py; needs the corpus): planted valid/unknown-pass/no-ref/C-function rows in
# .run/walls-selftest/, then --check of config/walls.txt (last line `WALLS CHECK OK <r> rows`).
th-walls: th-corpus
	@$(th_t0)
	$(PYTHON) tools/mmx6/walls.py --self-test && $(PYTHON) tools/mmx6/walls.py --check
	@$(th_t1)

# The draw filter (tools/mmx6/draw.py; needs the reports, twins and walls): planted L1-L4, exclude-audit, leverage,
# --band and harvest-stamp controls in .run/draw-selftest/, then the exclude audit (`EXCLUDE AUDIT <r> rows, <s> stale`,
# rc 2 if s > 0) and the real draw (build/draw/draw.jsonl; last line `DRAW refused <r> of <n> (…); drawn <k>`).
th-draw: th-report th-sig th-walls
	@$(th_t0)
	$(PYTHON) tools/mmx6/draw.py --self-test && $(PYTHON) tools/mmx6/draw.py --audit && $(PYTHON) tools/mmx6/draw.py
	@$(th_t1)

# The target validator (tools/mmx6/validate.py; needs the draw): planted out-of-range/phantom/banked/no-asm/lib controls
# in .run/validate-selftest/, then every `draw` row of build/draw/draw.jsonl (INVALID lines only; last
# `VALIDATE <ok> of <n>`, rc 1 if any invalid: the draw filter never passes an invalid target).
th-validate: th-draw
	@$(th_t0)
	$(PYTHON) tools/mmx6/validate.py --self-test && $(PYTHON) tools/mmx6/validate.py --drawn
	@$(th_t1)

# The citation auditor (tools/mmx6/gccsrc.py; needs /opt/gcc-2.95.2-src only when a citation exists): planted good,
# drifted, missing and wrong-fragment cites in .run/gccsrc-selftest/, then --check of docs/codegen-map/*.md and
# cookbook/C*.md (last line `CITES OK <c> of <c> citations`).
th-cites:
	@$(th_t0)
	$(PYTHON) tools/mmx6/gccsrc.py --self-test && $(PYTHON) tools/mmx6/gccsrc.py --check
	@$(th_t1)

# Per-pass cc1 dumps (tools/mmx6/dumps.py; needs the built C objects): planted function's every -da suffix and an
# empty .c refused CPP-EMPTY in .run/dumps-selftest/, then 120A0's dumps with its .text equal to the built object
# (last line `DUMPS TEXT SLUS_013.95/120A0 words <a> built <b> identical`).
th-dumps:
	@$(th_t0)
	$(PYTHON) tools/mmx6/dumps.py --self-test && $(PYTHON) tools/mmx6/dumps.py --tu SLUS_013.95/120A0
	@$(th_t1)

# The allocation table (tools/mmx6/alloc_table.py; needs the built C objects' asm): planted A/B pair whose reference
# counts swap global-alloc's order and hard regs 16<->17, a truncated .greg and a missing order pseudo, in
# .run/alloc-selftest/; then 120A0's table (an `ALLOC SLUS_013.95/120A0:<f> pseudos <n> order <k>` line per function).
th-alloc:
	@$(th_t0)
	$(PYTHON) tools/mmx6/alloc_table.py --self-test && $(PYTHON) tools/mmx6/alloc_table.py --tu SLUS_013.95/120A0
	@$(th_t1)

th-repro:
	@$(th_t0)
	$(PYTHON) tools/mmx6/repro.py --self-test && $(PYTHON) tools/mmx6/repro.py --all
	@$(th_t1)

# T5 widens --groups to all six.
th-map:
	@$(th_t0)
	$(PYTHON) tools/mmx6/codegen_map.py --self-test && $(PYTHON) tools/mmx6/codegen_map.py
	@$(th_t1)

th-cookbook:
	@$(th_t0)
	$(PYTHON) tools/mmx6/cookbook_check.py --self-test && $(PYTHON) tools/mmx6/cookbook_check.py --check
	@$(th_t1)

# On rc 0 th-propagate-full also records every key's inputs (propsince.py record -> build/propagate/green.json, 3.0 T5).
th-propagate-full: th-propagate
	@$(th_t0)
	@set -e; $(PROPAGATE_KEYS_CMD) | $(PYTHON) tools/mmx6/propagate.py --dry-run --expect-registry --keys-from -; \
	$(PYTHON) tools/mmx6/propsince.py record
	@$(th_t1)

# Incremental propagate keys (3.0 T5; docs/ops/methods-gen3.md `## Incremental propagate keys`): the grouped dry run
# of only the keys whose inputs changed since the last green full run, `KEYS="$$(PY tools/mmx6/propsince.py select)"`
# (host; needs a stamp: full green -> mx.sh pull build/propagate/green.json -> propsince.py stamp). KEYS undefined or
# ALL -> $(PROPAGATE_KEYS_CMD), then propsince.py record on rc 0 (a full run, 3.1 T23); KEYS="" given (no key
# changed) -> `PROPAGATE-SINCE no keys`, rc 0, no run. The words
# go to a file via $$(file) (no shell argument; one argv element is capped at 128 KB, select prints ALL past 100 KB).
# Not a fleet rung. Run after a build, with no `mx.sh sync` between, as th-propagate-full.
SINCE_KEYS := build/propagate/since-keys.txt
th-propagate-since: th-corpus th-census
ifeq ($(origin KEYS),undefined)
	@set -e; $(PROPAGATE_KEYS_CMD) | $(PYTHON) tools/mmx6/propagate.py --dry-run --expect-registry --keys-from -; \
	$(PYTHON) tools/mmx6/propsince.py record
else ifeq ($(strip $(KEYS)),ALL)
	@set -e; $(PROPAGATE_KEYS_CMD) | $(PYTHON) tools/mmx6/propagate.py --dry-run --expect-registry --keys-from -; \
	$(PYTHON) tools/mmx6/propsince.py record
else ifeq ($(strip $(KEYS)),)
	@echo "PROPAGATE-SINCE no keys"
else
	@: $(shell mkdir -p $(dir $(SINCE_KEYS)))  # at expansion: make expands every recipe line before the first runs
	$(file >$(SINCE_KEYS),$(strip $(KEYS)))
	@set -e; tr -s ' ' '\n' < $(SINCE_KEYS) | grep . | $(PYTHON) tools/mmx6/propagate.py --dry-run --expect-registry --keys-from -
endif

# Per-key vs grouped dry-run equivalence (3.0 T3.c1): config/equiv-keys.txt (propagate.py --equiv-pick: 24 registry
# keys, 6 per stratum of SLUS member? x refused row?, pools limited to keys with gated non-exemplar / refused member
# rows, 3.0 T3.c2) run per key, serially, then grouped; every (key, member)
# verdict (state, reason code) and every `gated m of n` must agree: `EQUIV identical <k> keys <m> members`, rc 0;
# `EQUIV mix gated g refused r` first, and g or r = 0 gives `EQUIV EMPTY`, rc 1 (a vacuous sample never passes).
# The comparator's planted controls first (--equiv-self-test). Not a fleet rung. Wall 1088 s (per-key 754 s,
# grouped 315 s; 3.0 T3.c2; was 940 s with 0 gated members compared, 3.0 T3.c1).
th-equiv: th-corpus th-census
	$(PYTHON) tools/mmx6/propagate.py --equiv-self-test && $(PYTHON) tools/mmx6/propagate.py --equiv config/equiv-keys.txt

# The other tools' self-tests (not rungs of their own): boundaries.py, loadmap.py, probe.py, bank.py (the reconcile
# ladder's planted controls: clean rebuilds of the exe, tree restored after), x4share.py (its real run needs network),
# x4port.py (planted control: our own banked C as the fake mmx4 source), x4names.py (planted table, votes and data
# probe; the real pairing on our own object), x4core.py (the core shared with mmx5: synthetic ELF objects),
# tools/psxd_img.py (psxdecomp's map core: synthetic words), imgadapter.py (its contract files: a planted archive)
# renamecov.py (rename coverage: a planted symbols/src/basis/names tree), gamestr.py (the M16 game-string gate:
# one planted file per refusal plus a passing tree), docconv.py (the DC1-DC8 documentation check: one planted file
# per rule plus a passing file; then its real check of config/docconv.txt) and badges.py (README badges: a planted
# stale and fresh badge).
th-selftests: th-selftests-cheap
	@$(th_t0)
	$(PYTHON) tools/mmx6/bank.py --self-test
	@$(th_t1)

# The 16 cheap self-tests (~18 s; propsince.py 3.0 T5; docs/ops/selftest-cost.md, rule M24): a fleet rung after th-sig, whose census and
# sig outputs x4share/x4port read (C0314). bank (above) and gate (th-gate) stay full-chain only.
th-selftests-cheap: th-sig
	@$(th_t0)
	$(PYTHON) tools/mmx6/boundaries.py --self-test
	$(PYTHON) tools/mmx6/loadmap.py --self-test
	$(PYTHON) tools/mmx6/probe.py --self-test
	$(PYTHON) tools/mmx6/x4share.py --self-test
	$(PYTHON) tools/mmx6/x4port.py --self-test
	$(PYTHON) tools/mmx6/x4names.py --self-test
	$(PYTHON) tools/mmx6/x4core.py --selftest
	$(PYTHON) tools/psxd_img.py --self-test
	$(PYTHON) tools/mmx6/imgadapter.py --self-test
	$(PYTHON) tools/mmx6/readcensus.py --self-test
	$(PYTHON) tools/mmx6/renamecov.py --self-test
	$(PYTHON) tools/mmx6/gamestr.py --self-test
	$(PYTHON) tools/mmx6/docconv.py --self-test
	$(PYTHON) tools/mmx6/docconv.py check
	$(PYTHON) tools/mmx6/badges.py --self-test
	$(PYTHON) tools/mmx6/propsince.py --self-test
	$(PYTHON) tools/mmx6/refusecause.py --self-test
	@$(th_t1)

# The permuter wrapper (tools/mmx6/permute.py; decomp-permuter pinned in the image): planted controls only in
# .run/permute/ (xor operand swap reaches masked 0 with the stock-scorer contrast, register pin hidden and restored,
# K&R refused, upstream clean); ~15 s. No real run here: the stored draft (T7.c2) runs on its own.
th-permute:
	@$(th_t0)
	$(PYTHON) tools/mmx6/permute.py --self-test
	@$(th_t1)

# The names queue and every `code:` basis ref (tools/mmx6/namesqueue.py; text + git ls-files, rule M23): planted
# controls, then `check` (rc 0 iff judged = queue rows and no `NAMESQUEUE REFUSE`, e.g. a stale ref after a line shift).
th-namesqueue:
	@$(th_t0)
	$(PYTHON) tools/mmx6/namesqueue.py --self-test
	$(PYTHON) tools/mmx6/namesqueue.py check
	@$(th_t1)

# The plateau classifier (tools/mmx6/plateau.py): planted regalloc/sched/branch/identical pairs in
# .run/plateau-selftest/, then a tracked non-matching draft's residual label and triage rows (`PLATEAU <func> <label> …`).
# Draft = drafts/rock_05/func_800EA5C8.c (W0, sched 86/98); was drafts/SLUS_013.95/func_80042F20.c until it banked (1.8/T9).
th-plateau:
	@$(th_t0)
	$(PYTHON) tools/mmx6/plateau.py --self-test && $(PYTHON) tools/mmx6/plateau.py --draft drafts/rock_05/func_800EA5C8.c
	@$(th_t1)

# The campaign journal (tools/mmx6/journal.py): planted append/refusals/edit/rate in .run/journal-selftest/, then
# the real campaign/journal.jsonl's append-only check (`JOURNAL OK <r> records`).
th-journal:
	@$(th_t0)
	$(PYTHON) tools/mmx6/journal.py --self-test && $(PYTHON) tools/mmx6/journal.py --check
	@$(th_t1)

# The wave cards (tools/mmx6/cards.py): planted cases in .run/cards-selftest/ (a dup-class member seeded by a banked
# twin, a planted journal record on the next card, unresolved C/L ids refused with no pack dir); `CARDS CONTROL OK`.
th-cards: th-sig th-journal
	@$(th_t0)
	$(PYTHON) tools/mmx6/cards.py --self-test
	@$(th_t1)

# The verbatim check (tools/mmx6/verbatim.py, DK-29): planted bodies in .run/verbatim-selftest/ (inline asm,
# directive, INCLUDE_ASM refused; a pin counted, a commented pin not), then every src/shared and drafts .c file.
th-verbatim:
	@$(th_t0)
	$(PYTHON) tools/mmx6/verbatim.py --self-test && $(PYTHON) tools/mmx6/verbatim.py --all
	@$(th_t1)

# The harvest gate (tools/mmx6/harvest.py, G45): planted live/inert levers (the exemplar body, compiled both ways in
# a snapshot), refused waves (live lever without record, sweep tag without sweep record), a stamped complete wave and
# check-all in .run/harvest-selftest/; then every journal wave has a current stamp (`HARVEST GATES OK <w> of <w> waves`).
# Needs the draw: the self-test copies build/census, build/reports and build/draw inputs (T6.c1).
th-harvest: th-draw
	@$(th_t0)
	$(PYTHON) tools/mmx6/harvest.py --self-test && $(PYTHON) tools/mmx6/harvest.py --check-all
	@$(th_t1)

# The scaffold lane (tools/mmx6/scaffold.py): planted c-empty functions in build/scaffold/selftest/ (a trivial m2c
# scaffold scores 0, a one-word mutation > 0, a planted syntax error nocompile, a re-run adds no rows, the match's gate
# pack). No real run here: `scaffold.py --all` is the detached lane run (docs/ops/campaign.md ## Scaffold lane).
th-scaffold: th-corpus
	@$(th_t0)
	$(PYTHON) tools/mmx6/scaffold.py --self-test
	@$(th_t1)

# The ledger (tools/mmx6/ledger.py): planted inputs in .run/ledger-selftest/ (every class/blocker rule; a missing
# function, a C function's row, an unknown blocker, an INCLUDE_ASM best draft, a malformed pins column each refused; a
# pinned score loses to a pin-free one), then campaign/ledger.tsv against the corpus (one well-formed 8-column row per
# asm function). Rebuilt by `ledger.py --build` (docs/ops/campaign.md ## Ledger).
# Needs the draw: --check reads build/{census,sig,draw} (T6.c1). --reconcile: src INCLUDE_ASM lines vs game rows (T9.c1).
th-ledger: th-corpus th-draw
	@$(th_t0)
	$(PYTHON) tools/mmx6/ledger.py --self-test
	$(PYTHON) tools/mmx6/ledger.py --check
	$(PYTHON) tools/mmx6/ledger.py --reconcile
	@$(th_t1)

# The wave gate (tools/mmx6/gate.py; full chain only: it plants and banks in /work like bank.py's self-test): planted
# exe + overlay members in .run/gate-selftest/ (bank, define recovery, plateau-labelled fail, MISSING asm, two
# programs concurrently, lock refused); /work restored byte-exact and both binaries rebuilt to their sha1 after.
th-gate:
	@$(th_t0)
	$(PYTHON) tools/mmx6/gate.py --self-test
	@$(th_t1)
