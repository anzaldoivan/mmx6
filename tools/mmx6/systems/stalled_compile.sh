#!/bin/bash
# stalled_compile.sh -- compile-only each stalled draft in the container via the product C rule (2.6 T4.c1).
# Run from the repo root after mx.sh sync:  bash tools/mmx6/systems/stalled_compile.sh .run/<phase>/stalled/pop.tsv > .run/<phase>/logs/stalled-compile.log
# Out: per draft `@@FILE <draft> rc=<n>` + its first error lines; the TRIPLE is the compiler pin (Makefile TRIPLE).
POP=${1:?usage: stalled_compile.sh <pop.tsv>}
bash tools/docker/mx.sh run bash -c '
for d in "$@"; do
  out=$(make -s -B TRIPLE=gcc2.95.2-psx-aspsx2.86 "build/$d.o" 2>&1); rc=$?
  echo "@@FILE $d rc=$rc"
  printf "%s\n" "$out" | grep -E "error|warning: .*(conflict|implicit)|parse|undeclared|incomplete|has no member" | head -8
done' x $(cut -f4 "$POP")
