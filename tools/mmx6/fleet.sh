#!/usr/bin/env bash
# fleet.sh — the clean fleet verification (container; `make fleet`): rm -rf build asm expected → make extract →
# make -j8 -k split build → make health. ok = BINS outputs present (build/<exe>, build/rock/NN.bin; .DELETE_ON_ERROR
# removes any whose hash check failed), n = config/*.yaml, k = `N = <k>` of config/loadmap.txt.
# Last line, always: `FLEET <ok> of <n>`; rc 0 only if ok = n, n = k, extract and health rc 0.
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
echo "FLEET $ok of $n"
exit "$rc"
