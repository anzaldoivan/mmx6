#!/usr/bin/env bash
# tools/mmx6/ghidra/roundtrip.sh [PROG ...] [--jsonl F]
#
# Proves config/ghidra/<PROG>.jsonl regenerates the annotations: for each program (default SLUS_013.95 + every
# code member of config/loadmap.txt), a fresh import (auto-analysis, manifest-sha1-checked) into the scratch
# project .run/ghidra/rebuild/ (recreated each run), ImportAnnotations.java of the committed file (or --jsonl F),
# re-export to .run/ghidra/rebuild/out/<PROG>.jsonl, cmp against the input. Batched: import.sh groups members
# by base (one JVM per group), one JVM applies all, one exports all. Prints `ROUNDTRIP OK <k> programs` and rc 0, else the first differing line per
# program and rc 1. Never touches ghidra/mmx6.
# Ghidra rejects project paths with a '.'-leading element, so the scratch project is opened through the
# symlink ghidra/rebuild -> ../.run/ghidra/rebuild (ghidra/ is ignored and purged; the data stays in .run/).
set -uo pipefail
REPO="$(cd "$(dirname "${BASH_SOURCE[0]}")/../../.." && pwd)"
GHIDRA="${GHIDRA_HOME:-$HOME/ghidra_12.1.3_PUBLIC}"
HERE="$REPO/tools/mmx6/ghidra"
RB="$REPO/.run/ghidra/rebuild"
RBP="$REPO/ghidra/rebuild"
PROGS=()
JSONL=""

while [ $# -gt 0 ]; do
  case "$1" in
    --jsonl) JSONL="${2:?--jsonl needs a file}"; shift 2 ;;
    -*) echo "roundtrip: usage: roundtrip.sh [PROG ...] [--jsonl F]" >&2; exit 2 ;;
    *) PROGS+=("$1"); shift ;;
  esac
done
[ ${#PROGS[@]} -gt 0 ] || PROGS=(SLUS_013.95 $(bash "$HERE/import.sh" --list | awk '{ print $1 }'))
if [ -n "$JSONL" ]; then
  case "$JSONL" in /*) ;; *) JSONL="$PWD/$JSONL" ;; esac
  [ ${#PROGS[@]} -eq 1 ] || { echo "roundtrip: --jsonl takes exactly one program" >&2; exit 2; }
fi

mkdir -p "$RB" "$REPO/ghidra"
ln -sfn ../.run/ghidra/rebuild "$RBP"
# fresh scratch project: no stale programs from an earlier round trip
rm -rf "$RB/mmx6.rep" "$RB/mmx6.gpr" "$RB/in" "$RB/out"
mkdir -p "$RB/in" "$RB/out"
ok=0; bad=0; members=""; exe=()
for p in "${PROGS[@]}"; do
  in="${JSONL:-$REPO/config/ghidra/$p.jsonl}"
  [ -f "$in" ] || { echo "roundtrip: $p: ERROR input missing: $in"; bad=$((bad + 1)); continue; }
  cp "$in" "$RB/in/$p.jsonl"
  case "$p" in rock_*) members="$members,${p#rock_}" ;; *) exe+=("$p") ;; esac
done
[ $bad -eq 0 ] || { echo "ROUNDTRIP FAIL $bad of ${#PROGS[@]} programs"; exit 1; }

t0=$SECONDS
for p in "${exe[@]}"; do
  bash "$HERE/import.sh" --program "$p" --project "$RBP" >"$RB/$p.import.log" 2>&1 \
    || { echo "roundtrip: $p: ERROR import failed (log $RB/$p.import.log)"; exit 1; }
done
if [ -n "$members" ]; then
  bash "$HERE/import.sh" --member "${members#,}" --project "$RBP" >"$RB/members.import.log" 2>&1 \
    || { echo "roundtrip: ERROR member import failed (log $RB/members.import.log)"; exit 1; }
fi
t1=$SECONDS
# one JVM applies every program's <in>/<program>.jsonl
"$GHIDRA/support/analyzeHeadless" "$RBP" mmx6 -process -noanalysis \
  -scriptPath "$HERE/scripts" -postScript ImportAnnotations.java "$RB/in" >"$RB/apply.log" 2>&1
rc=$?
grep -E 'MMX6ANN' "$RB/apply.log"
napp="$(grep -c 'MMX6ANN' "$RB/apply.log")"
if [ $rc -ne 0 ] || grep -q 'MMX6ANN ERROR' "$RB/apply.log" || [ "$napp" -ne ${#PROGS[@]} ]; then
  echo "roundtrip: ERROR apply failed ($napp of ${#PROGS[@]} applied; log $RB/apply.log)"; exit 1
fi
t2=$SECONDS
if [ ${#PROGS[@]} -eq 1 ]; then eo="$RB/out/${PROGS[0]}.jsonl"; else eo="$RB/out"; fi
bash "$HERE/export.sh" "${PROGS[@]}" --project "$RBP" --out "$eo" >"$RB/export.log" 2>&1 \
  || { echo "roundtrip: ERROR export failed (log $RB/export.log)"; exit 1; }
echo "roundtrip: ${#PROGS[@]} programs: import $((t1 - t0)) s, apply $((t2 - t1)) s, export $((SECONDS - t2)) s"
for p in "${PROGS[@]}"; do
  in="$RB/in/$p.jsonl"; out="$RB/out/$p.jsonl"
  if cmp -s "$in" "$out"; then
    ok=$((ok + 1))
  else
    n="$(cmp "$in" "$out" 2>&1 | sed -nE 's/.* line ([0-9]+).*/\1/p')"
    echo "roundtrip: $p: DIFF at line ${n:-?} ($(wc -l <"$in" | tr -d ' ') vs $(wc -l <"$out" 2>/dev/null | tr -d ' ') lines)"
    [ -n "$n" ] && { echo "  want: $(sed -n "${n}p" "$in" | cut -c1-400)"; echo "  got:  $(sed -n "${n}p" "$out" | cut -c1-400)"; }
    bad=$((bad + 1))
  fi
done
if [ $bad -eq 0 ]; then echo "ROUNDTRIP OK $ok programs"; exit 0; fi
echo "ROUNDTRIP FAIL $bad of ${#PROGS[@]} programs"; exit 1
