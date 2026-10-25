#!/usr/bin/env bash
# tools/mmx6/ghidra/mirror.sh
#
# The symbol mirror (phase 1.10 T10): applies the renamed symbols (config/symbols.<prog>.txt, with their basis as
# plate comment) and the names.tsv alias plate comments to the Ghidra database ghidra/mmx6, then re-exports all
# programs to config/ghidra/. Steps: refuse if a Ghidra process runs; back up ghidra/mmx6.gpr + mmx6.rep to
# .run/<phase>/ghidra-backup/ (once; an existing backup is never overwritten); x4adapter.py --mirror --out
# .run/<phase>/mirror/ (the delta files); one JVM ImportAnnotations.java of that dir; gate: one MMX6ANN line per
# program, no `MMX6ANN ERROR`, failed=0 on every line (exit 0 alone proves nothing, C0017); export.sh --all.
# Idempotent: a rerun applies the same records, Ghidra counts them unchanged, the re-export is cmp-equal.
# On a bad apply: restore ghidra/mmx6.{gpr,rep} from the backup (never delete ghidra/).
set -uo pipefail
REPO="$(cd "$(dirname "${BASH_SOURCE[0]}")/../../.." && pwd)"
GHIDRA="${GHIDRA_HOME:-$HOME/ghidra_12.1.3_PUBLIC}"
PY="${PYTHON:-/opt/homebrew/opt/python@3.14/bin/python3.14}"
HERE="$REPO/tools/mmx6/ghidra"
# The open phase's temp folder (as tools/run.sh: `# Phase <id>` of PHASE_PLAN.md), else .run (no plan open).
PHASE=$(sed -n '1s/^#[[:space:]]*Phase[[:space:]][[:space:]]*\([A-Za-z0-9._-][A-Za-z0-9._-]*\).*/\1/p' \
  "$REPO/phase-ends/current/PHASE_PLAN.md" 2>/dev/null | head -n 1)
case "$PHASE" in "" | . | ..) SCR="$REPO/.run" ;; *) SCR="$REPO/.run/$PHASE" ;; esac
BK="$SCR/ghidra-backup"
MD="$SCR/mirror"
LOG="$SCR/mirror-apply.log"

[ -x "$GHIDRA/support/analyzeHeadless" ] || { echo "mirror: ERROR analyzeHeadless not found under $GHIDRA" >&2; exit 2; }
[ -f "$REPO/ghidra/mmx6.gpr" ] && [ -d "$REPO/ghidra/mmx6.rep" ] || { echo "mirror: ERROR no project at $REPO/ghidra/mmx6.gpr" >&2; exit 2; }
if pgrep -f 'ghidra.Ghidra' >/dev/null 2>&1; then
  echo "mirror: ERROR a Ghidra process is running (stop the GUI/MCP server first)" >&2; exit 2
fi

if [ -e "$BK" ]; then
  echo "mirror: backup kept: $BK"
else
  mkdir -p "$BK.tmp" && cp -Rp "$REPO/ghidra/mmx6.gpr" "$REPO/ghidra/mmx6.rep" "$BK.tmp/" && mv "$BK.tmp" "$BK" \
    || { echo "mirror: ERROR backup failed" >&2; exit 1; }
  echo "mirror: backup written: $BK"
fi

rm -rf "$MD"; mkdir -p "$MD"
"$PY" "$HERE/../x4adapter.py" --mirror --out "$MD" || { echo "mirror: ERROR x4adapter --mirror failed" >&2; exit 1; }
n="$(ls "$MD"/*.jsonl | wc -l | tr -d ' ')"

"$GHIDRA/support/analyzeHeadless" "$REPO/ghidra" mmx6 -process -noanalysis \
  -scriptPath "$HERE/scripts" -postScript ImportAnnotations.java "$MD" >"$LOG" 2>&1
rc=$?
grep -E 'MMX6ANN|  fail ' "$LOG"
napp="$(grep -c 'MMX6ANN' "$LOG")"
nok="$(grep -c 'MMX6ANN .* failed=0 ' "$LOG")"
if [ $rc -ne 0 ] || grep -q 'MMX6ANN ERROR' "$LOG" || [ "$napp" -ne "$n" ] || [ "$nok" -ne "$n" ]; then
  echo "mirror: ERROR apply failed (exit $rc, $napp MMX6ANN lines, $nok with failed=0, of $n; log $LOG)"
  echo "mirror: restore ghidra/mmx6.{gpr,rep} from $BK before anything else"
  exit 1
fi
echo "mirror: applied $n programs (log $LOG)"
bash "$HERE/export.sh" --all || { echo "mirror: ERROR export failed" >&2; exit 1; }
echo "MIRROR OK $n programs"
