#!/usr/bin/env bash
# fleet.sh — the clean fleet verification (container; `make fleet`): make format-check (src/ vs .clang-format) →
# rm -rf build asm expected → make extract →
# make -j$JOBS -k split build → make health (JOBS: env JOBS, else MX6_JOBS, else 8; mk/tools-health.mk runs the rungs
# under the same -j). ok = BINS outputs present (build/<exe>, build/rock/NN.bin; .DELETE_ON_ERROR
# removes any whose hash check failed), n = config/*.yaml, k = `N = <k>` of config/loadmap.txt.
# Before it `C MATCHED <c> of <F> functions (<e> empty-body; banked <c-e>)` (F, e from build/corpus/functions.jsonl).
# Last line, always: `FLEET <ok> of <n>`; rc 0 only if ok = n, n = k, extract and health rc 0, the corpus is
# present and its c + c-empty = c.
# `fleet.sh --quick` (`make fleet-quick`): the same (format-check included), but health is cut to boundcheck.py + `make -s th-corpus th-ledger
# th-cookbook`; last line `FLEET <ok> of <n> (quick)`. Quick is never the gate (contract.sh matches `^FLEET .* of N$`).
# A failed format-check stops the fleet at once (2.7 T10, R79): no rm/extract/build/health; clang-format's own
# diagnostics, `fleet: make format-check rc <r>`, then `FLEET 0 of <n>` (quick: ` (quick)`), rc 1.
# Stage walls (3.0 T3): `FLEET-WALL <stage> <s>s` after format-check, wipe, extract, build and health, then
# `FLEET-WALL total`; the health chain adds `TH-WALL <rung> <s>s` per rung (mk/tools-health.mk). FLEET stays last.
set -u
quick=; [ "${1:-}" = "--quick" ] && quick=1
cd "$(dirname "$0")/../.."
MK=(${MAKE:-make} --no-print-directory)
JOBS=${JOBS:-${MX6_JOBS:-8}}
t_start=$(date +%s%N) t_mark=$t_start
wall() {  # FLEET-WALL <stage> <seconds since the previous mark, or since $2>
  local t; t=$(date +%s%N)
  awk -v s="$1" -v d=$((t - ${2:-$t_mark})) 'BEGIN { printf "FLEET-WALL %s %.1fs\n", s, d / 1e9 }'
  t_mark=$t
}

"${MK[@]}" -s format-check; rc_format=$?
wall format-check
if [ "$rc_format" -ne 0 ]; then
  n=$(ls config/*.yaml | grep -c .)
  echo "fleet: make format-check rc $rc_format (fix: mx.sh run make format && mx.sh pull <paths>)"
  wall total "$t_start"
  echo "FLEET 0 of $n${quick:+ (quick)}"
  exit 1
fi
rm -rf build asm expected
wall wipe
"${MK[@]}" extract; rc_extract=$?
wall extract
"${MK[@]}" -j"$JOBS" -k split build
wall build
if [ -n "$quick" ]; then
  ${PYTHON:-python3} tools/mmx6/boundcheck.py && "${MK[@]}" -s th-corpus th-ledger th-cookbook; rc_health=$?
else
  "${MK[@]}" health; rc_health=$?
fi
wall health

ok=0 n=0
for y in config/*.yaml; do
  b=$(basename "$y" .yaml)
  n=$((n + 1))
  case "$b" in rock_*) out="build/rock/${b#rock_}.bin" ;; *) out="build/$b" ;; esac
  [ -f "$out" ] && ok=$((ok + 1))
done
k=$(sed -n 's/^N = \([0-9][0-9]*\)$/\1/p' config/loadmap.txt)

rc=0
[ "$rc_extract" -eq 0 ] || { echo "fleet: make extract rc $rc_extract"; rc=1; }
[ "$rc_health" -eq 0 ] || { echo "fleet: make health rc $rc_health"; rc=1; }
[ "$n" = "$k" ] || { echo "fleet: $n config/*.yaml but config/loadmap.txt N = ${k:-?}"; rc=1; }
[ "$ok" -eq "$n" ] || { echo "fleet: $((n - ok)) binaries missing or red"; rc=1; }
# C MATCHED f: global function symbols of build/src/**/*.c.o minus INCLUDE_ASM entries of their sources (T8);
# local/jump labels and gcc2_compiled. are not global functions; alabel entries (size 0) are not counted.
# One instrument with harness.py P1: corpus.py --c-names (fleet_c_names, readelf -sW of the objects) (T8.c1).
c=$(${PYTHON:-python3} tools/mmx6/corpus.py --c-names | grep -c .)
# F = all rows of the function corpus (make health runs corpus.py --all), e = its c-empty rows; the corpus's
# c + c-empty must equal c (G28).
CORPUS=build/corpus/functions.jsonl
if [ -f "$CORPUS" ]; then
  F=$(grep -c . "$CORPUS")
  e=$(grep -c '"state": *"c-empty"' "$CORPUS")
  cc=$(grep -c '"state": *"c"' "$CORPUS")
  [ $((cc + e)) -eq "$c" ] || { echo "fleet: corpus c $cc + c-empty $e != C MATCHED $c"; rc=1; }
  echo "C MATCHED $c of $F functions ($e empty-body; banked $((c - e)))"
else
  echo "fleet: no $CORPUS (corpus.py --all)"; rc=1
  echo "C MATCHED $c"
fi
wall total "$t_start"
echo "FLEET $ok of $n${quick:+ (quick)}"
exit "$rc"
