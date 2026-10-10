#!/usr/bin/env bash
# tools/mmx6/ghidra/export.sh [PROG ... | --all] [--project DIR] [--out F]
#
# Read-only export of one program's annotations (types, signatures, data, comments, bookmarks, equates,
# labels) to byte-stable JSON-Lines via scripts/ExportAnnotations.java. PROG default SLUS_013.95;
# project default <repo>/ghidra (name mmx6); out default config/ghidra/<PROG>.jsonl.
# --all = SLUS_013.95 + every code member of config/loadmap.txt (import.sh --list). More than one PROG: one JVM
# (-process, every program of the project) into .run/ghidra/export/, then the requested files are moved to
# config/ghidra/ (or the --out dir; the per-program output is the same script on the same program as a one-by-one run).
# PRECONDITION: no other Ghidra (GUI/MCP server, headless run) holds the project lock. Never writes the
# project (-readOnly -noanalysis).
# Adapted from the decomp-architect kit P2 ghidra_export_annotations.sh (no splat symbol files, one program).
set -uo pipefail
REPO="$(cd "$(dirname "${BASH_SOURCE[0]}")/../../.." && pwd)"
GHIDRA="${GHIDRA_HOME:-$HOME/ghidra_12.1.3_PUBLIC}"
PROJ_DIR="$REPO/ghidra"
PROJ="mmx6"
SCRIPTS="$REPO/tools/mmx6/ghidra/scripts"
PROGS=()
OUT=""

while [ $# -gt 0 ]; do
  case "$1" in
    --project) PROJ_DIR="${2:?--project needs a dir}"; shift 2 ;;
    --out) OUT="${2:?--out needs a file}"; shift 2 ;;
    --all) PROGS+=(SLUS_013.95 $(bash "$REPO/tools/mmx6/ghidra/import.sh" --list | awk '{ print $1 }')); shift ;;
    -*) echo "export: usage: export.sh [PROG ... | --all] [--project DIR] [--out F]" >&2; exit 2 ;;
    *) PROGS+=("$1"); shift ;;
  esac
done
[ ${#PROGS[@]} -gt 0 ] || PROGS=(SLUS_013.95)
PROGRAM="${PROGS[0]}"
[ -n "$OUT" ] || OUT="$REPO/config/ghidra/$PROGRAM.jsonl"
case "$OUT" in /*) ;; *) OUT="$PWD/$OUT" ;; esac

[ -x "$GHIDRA/support/analyzeHeadless" ] || { echo "export: ERROR analyzeHeadless not found under $GHIDRA" >&2; exit 2; }
[ -f "$PROJ_DIR/$PROJ.gpr" ] || { echo "export: ERROR no project at $PROJ_DIR/$PROJ.gpr" >&2; exit 2; }
if pgrep -f 'ghidra.Ghidra' >/dev/null 2>&1; then
  echo "export: ERROR a Ghidra process is running (stop the GUI/MCP server first)" >&2; exit 2
fi

if [ ${#PROGS[@]} -gt 1 ]; then
  # batch: --out names a directory (default config/ghidra/)
  if [ "$OUT" = "$REPO/config/ghidra/$PROGRAM.jsonl" ]; then OD="$REPO/config/ghidra"; else OD="$OUT"; fi
  ST="$REPO/.run/ghidra/export"
  LOG="$REPO/.run/ghidra/export-batch.log"
  rm -rf "$ST"; mkdir -p "$ST" "$OD"
  "$GHIDRA/support/analyzeHeadless" "$PROJ_DIR" "$PROJ" -process -readOnly -noanalysis \
    -scriptPath "$SCRIPTS" -postScript ExportAnnotations.java "$ST" >"$LOG" 2>&1
  rc=$?
  grep -E 'ERROR|Exception' "$LOG"
  echo "export: analyzeHeadless exit=$rc, $(grep -c MMX6EXPORT "$LOG") program(s) (log $LOG)"
  [ $rc -eq 0 ] || exit $rc
  bad=0
  for p in "${PROGS[@]}"; do
    if [ -s "$ST/$p.jsonl" ]; then mv -f "$ST/$p.jsonl" "$OD/$p.jsonl"
    else echo "export: ERROR $p not exported (not in $PROJ_DIR/$PROJ?)" >&2; bad=$((bad + 1)); fi
  done
  echo "export: ${#PROGS[@]} requested, $bad missing -> $OD/"
  [ $bad -eq 0 ] || exit 1
  exit 0
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
