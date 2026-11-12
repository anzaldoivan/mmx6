#!/bin/bash
# tools/mmx6/redux/resweep.sh OUT -- milestone re-sweep datapoints (2.6 T18; kept by T12.1). Host, repo root.
# Runs every boot schedule (inputs/{intro_stage,boot_menu,menu_options,menu_start}.lua, tag t18 as at 2.6) and every
# inputs/mv_*.lua; the movement jsonl is saved to OUT/mv-before first and each rerun cmp'd against it.
# One line per run: `BOOTRUN <s> rc= <CONTROL/require/stop lines>`, `MVRUN <s> rc= jsonl=identical|DIFFERS <CONTROL>`.
# OUT is phase scratch (.run/<phase>/<task>); outputs stay in .run/redux/{boot,movement}/.
OUT=${1:?usage: resweep.sh OUT}; TAG=${MMX6_RUN_TAG:-t18}
R=tools/mmx6/redux
mkdir -p "$OUT/mv-before"
cp .run/redux/movement/*.jsonl .run/redux/movement/*.summary.txt "$OUT/mv-before/" 2>/dev/null
for s in intro_stage boot_menu menu_options menu_start; do
  stop=""; [ $s = intro_stage ] && stop="MMX6_STOP=2773"
  env $stop MMX6_INPUTS=$R/inputs/$s.lua MMX6_RUN_TAG=$TAG $R/run.sh $R/boot.lua --timeout 240 > "$OUT/boot-$s.out" 2>&1
  echo "BOOTRUN $s rc=$? $(grep -h 'BOOT CONTROL\|^require\|^stop' .run/redux/boot/$s-$TAG.summary.txt 2>/dev/null | tr '\n' ' ')"
done
for f in $R/inputs/mv_*.lua; do
  s=$(basename $f .lua)
  MMX6_INPUTS=$f $R/run.sh $R/movement.lua --timeout 240 > "$OUT/mv-$s.out" 2>&1
  rc=$?
  if cmp -s .run/redux/movement/$s.jsonl "$OUT/mv-before/$s.jsonl"; then same=identical; else same=DIFFERS; fi
  echo "MVRUN $s rc=$rc jsonl=$same $(grep -h 'MOVEMENT CONTROL' .run/redux/movement/$s.summary.txt 2>/dev/null | head -1)"
done
