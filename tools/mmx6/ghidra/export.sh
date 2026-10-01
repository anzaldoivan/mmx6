#!/usr/bin/env bash
# tools/mmx6/ghidra/export.sh [PROG] [--project DIR] [--out F]
#
# Read-only export of one program's annotations (types, signatures, data, comments, bookmarks, equates,
# labels) to byte-stable JSON-Lines via scripts/ExportAnnotations.java. PROG default SLUS_013.95;
# project default <repo>/ghidra (name mmx6); out default config/ghidra/<PROG>.jsonl.
# PRECONDITION: no other Ghidra (GUI/MCP server, headless run) holds the project lock. Never writes the
# project (-readOnly -noanalysis).
# Adapted from the decomp-architect kit P2 ghidra_export_annotations.sh (no splat symbol files, one program).
set -uo pipefail
REPO="$(cd "$(dirname "${BASH_SOURCE[0]}")/../../.." && pwd)"
GHIDRA="${GHIDRA_HOME:-$HOME/ghidra_12.1.3_PUBLIC}"
PROJ_DIR="$REPO/ghidra"
PROJ="mmx6"
SCRIPTS="$REPO/tools/mmx6/ghidra/scripts"
PROGRAM="SLUS_013.95"
OUT=""

while [ $# -gt 0 ]; do
  case "$1" in
    --project) PROJ_DIR="${2:?--project needs a dir}"; shift 2 ;;
    --out) OUT="${2:?--out needs a file}"; shift 2 ;;
    -*) echo "export: usage: export.sh [PROG] [--project DIR] [--out F]" >&2; exit 2 ;;
    *) PROGRAM="$1"; shift ;;
  esac
done
[ -n "$OUT" ] || OUT="$REPO/config/ghidra/$PROGRAM.jsonl"
case "$OUT" in /*) ;; *) OUT="$PWD/$OUT" ;; esac

[ -x "$GHIDRA/support/analyzeHeadless" ] || { echo "export: ERROR analyzeHeadless not found under $GHIDRA" >&2; exit 2; }
[ -f "$PROJ_DIR/$PROJ.gpr" ] || { echo "export: ERROR no project at $PROJ_DIR/$PROJ.gpr" >&2; exit 2; }
if pgrep -f 'ghidra.Ghidra' >/dev/null 2>&1; then
  echo "export: ERROR a Ghidra process is running (stop the GUI/MCP server first)" >&2; exit 2
fi

mkdir -p "$(dirname "$OUT")"
rm -f "$OUT"
LOG="$REPO/.run/ghidra/export-$PROGRAM.log"
mkdir -p "$REPO/.run/ghidra"
"$GHIDRA/support/analyzeHeadless" "$PROJ_DIR" "$PROJ" -process "$PROGRAM" -readOnly -noanalysis \
  -scriptPath "$SCRIPTS" -postScript ExportAnnotations.java "$OUT" >"$LOG" 2>&1
rc=$?
grep -E 'MMX6EXPORT|ERROR|Exception' "$LOG"
echo "export: analyzeHeadless exit=$rc -> $OUT (log $LOG)"
[ $rc -eq 0 ] || exit $rc
[ -s "$OUT" ] || { echo "export: ERROR output not written: $OUT" >&2; exit 1; }
