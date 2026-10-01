#!/usr/bin/env bash
# fleet.sh — the clean fleet verification (container; `make fleet`): rm -rf build asm expected → make extract →
# make -j8 -k split build → make health. ok = BINS outputs present (build/<exe>, build/rock/NN.bin; .DELETE_ON_ERROR
# removes any whose hash check failed), n = config/*.yaml, k = `N = <k>` of config/loadmap.txt.
# Before it `C MATCHED <c> of <F> functions (<e> empty-body; banked <c-e>)` (F, e from build/corpus/functions.jsonl).
# Last line, always: `FLEET <ok> of <n>`; rc 0 only if ok = n, n = k, extract and health rc 0, the corpus is
# present and its c + c-empty = c.
set -u
cd "$(dirname "$0")/../.."
MK=(${MAKE:-make} --no-print-directory)

rm -rf build asm expected
"${MK[@]}" extract; rc_extract=$?
"${MK[@]}" -j8 -k split build
"${MK[@]}" health; rc_health=$?

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
defd=$(find build/src -name '*.c.o' -exec mipsel-linux-gnu-readelf -sW {} + 2>/dev/null |
  awk '$4 == "FUNC" && $5 == "GLOBAL" && $7 != "UND" && $3 != 0 {print $8}' | sort -u)
inc=$(find src -name '*.c' -exec sed -n 's/^INCLUDE_ASM("[^"]*", *\([A-Za-z0-9_]*\));.*/\1/p' {} + | sort -u)
c=$(comm -23 <(printf '%s\n' "$defd" | sed '/^$/d') <(printf '%s\n' "$inc" | sed '/^$/d') | wc -l | tr -d ' ')
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
echo "FLEET $ok of $n"
exit "$rc"
