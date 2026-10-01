#!/usr/bin/env bash
# tools/mmx6/ghidra/roundtrip.sh [PROG ...] [--jsonl F]
#
# Proves config/ghidra/<PROG>.jsonl regenerates the annotations: for each program (default SLUS_013.95),
# a fresh import (auto-analysis, manifest-sha1-checked) into the scratch project .run/ghidra/rebuild/,
# ImportAnnotations.java of the committed file (or --jsonl F), re-export to .run/ghidra/rebuild/<PROG>.jsonl,
# cmp against the input. Prints `ROUNDTRIP OK <k> programs` and rc 0, else the first differing line per
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
[ ${#PROGS[@]} -gt 0 ] || PROGS=(SLUS_013.95)
if [ -n "$JSONL" ]; then
  case "$JSONL" in /*) ;; *) JSONL="$PWD/$JSONL" ;; esac
  [ ${#PROGS[@]} -eq 1 ] || { echo "roundtrip: --jsonl takes exactly one program" >&2; exit 2; }
fi

mkdir -p "$RB" "$REPO/ghidra"
ln -sfn ../.run/ghidra/rebuild "$RBP"
ok=0; bad=0
for p in "${PROGS[@]}"; do
  in="${JSONL:-$REPO/config/ghidra/$p.jsonl}"
  out="$RB/$p.jsonl"
  [ -f "$in" ] || { echo "roundtrip: $p: ERROR input missing: $in"; bad=$((bad + 1)); continue; }
  rm -f "$out"
  t0=$SECONDS
  bash "$HERE/import.sh" --program "$p" --project "$RBP" >"$RB/$p.import.log" 2>&1 \
    || { echo "roundtrip: $p: ERROR import failed (log $RB/$p.import.log)"; bad=$((bad + 1)); continue; }
  t1=$SECONDS
  "$GHIDRA/support/analyzeHeadless" "$RBP" mmx6 -process "$p" -noanalysis \
    -scriptPath "$HERE/scripts" -postScript ImportAnnotations.java "$in" >"$RB/$p.apply.log" 2>&1
  rc=$?
  grep -E 'MMX6ANN' "$RB/$p.apply.log"
  if [ $rc -ne 0 ] || grep -q 'MMX6ANN ERROR' "$RB/$p.apply.log"; then
    echo "roundtrip: $p: ERROR apply failed (log $RB/$p.apply.log)"; bad=$((bad + 1)); continue
  fi
  t2=$SECONDS
  bash "$HERE/export.sh" "$p" --project "$RBP" --out "$out" >"$RB/$p.export.log" 2>&1 \
    || { echo "roundtrip: $p: ERROR export failed (log $RB/$p.export.log)"; bad=$((bad + 1)); continue; }
  echo "roundtrip: $p: import $((t1 - t0)) s, apply $((t2 - t1)) s, export $((SECONDS - t2)) s"
  if cmp -s "$in" "$out"; then
    ok=$((ok + 1))
  else
    n="$(cmp "$in" "$out" 2>&1 | sed -nE 's/.* line ([0-9]+).*/\1/p')"
    echo "roundtrip: $p: DIFF at line ${n:-?} ($(wc -l <"$in" | tr -d ' ') vs $(wc -l <"$out" | tr -d ' ') lines)"
    [ -n "$n" ] && { echo "  want: $(sed -n "${n}p" "$in" | cut -c1-400)"; echo "  got:  $(sed -n "${n}p" "$out" | cut -c1-400)"; }
    bad=$((bad + 1))
  fi
done
if [ $bad -eq 0 ]; then echo "ROUNDTRIP OK $ok programs"; exit 0; fi
echo "ROUNDTRIP FAIL $bad of ${#PROGS[@]} programs"; exit 1
