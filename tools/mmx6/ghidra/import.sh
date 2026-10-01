#!/usr/bin/env bash
# tools/mmx6/ghidra/import.sh [--program SLUS_013.95 | --member NN --base 0xADDR] [--project DIR]
#
# Headless import of a retail input into the Ghidra project `mmx6` (default dir: <repo>/ghidra, ignored+purged).
# --program: extracted/retail/iso/<name> via psx_ldr's "PSX Executables Loader", -overwrite (idempotent),
#   full auto-analysis (incl. psx_ldr "PsyQ Signatures", which applies psyq/<ver>/ sigs + GDT on its own),
#   then postScript DumpProgramInfo.java -> .run/ghidra/info/<program>.txt (format: docs/ops/oracles.md).
# --member: not yet (T4).
# Input currency (G22): the file's sha1 must equal its manifest/retail.jsonl record, else rc 2.
# PRECONDITION: no other Ghidra (GUI with the MCP server, or another headless run) holds the project lock.
# Adapted from the decomp-architect kit P2 ghidra_import.sh (bfm names replaced; no ImportPsyqGdt step).
set -uo pipefail
REPO="$(cd "$(dirname "${BASH_SOURCE[0]}")/../../.." && pwd)"
GHIDRA="${GHIDRA_HOME:-$HOME/ghidra_12.1.3_PUBLIC}"
PROJ_DIR="$REPO/ghidra"
PROJ="mmx6"
SCRIPTS="$REPO/tools/mmx6/ghidra/scripts"
MANIFEST="$REPO/manifest/retail.jsonl"
PROGRAM="SLUS_013.95"
MEMBER=""

while [ $# -gt 0 ]; do
  case "$1" in
    --program) PROGRAM="${2:?--program needs a name}"; shift 2 ;;
    --member) MEMBER="${2:?--member needs NN}"; shift 2 ;;
    --base) shift 2 ;;
    --project) PROJ_DIR="${2:?--project needs a dir}"; shift 2 ;;
    *) echo "import: usage: import.sh [--program SLUS_013.95 | --member NN --base 0xADDR] [--project DIR]" >&2; exit 2 ;;
  esac
done

if [ -n "$MEMBER" ]; then
  echo "import: --member: not yet (T4)" >&2; exit 2
fi

REL="iso/$PROGRAM"
EXE="$REPO/extracted/retail/$REL"
[ -x "$GHIDRA/support/analyzeHeadless" ] || { echo "import: ERROR analyzeHeadless not found under $GHIDRA" >&2; exit 2; }
[ -f "$EXE" ] || { echo "import: ERROR input missing: $EXE (run make extract)" >&2; exit 2; }

want="$(grep -F "\"path\": \"$REL\"" "$MANIFEST" | sed -E 's/.*"sha1": "([0-9a-f]{40})".*/\1/')"
have="$(shasum -a 1 "$EXE" | cut -d' ' -f1)"
if [ -z "$want" ] || [ "$want" != "$have" ]; then
  echo "import: ERROR sha1 mismatch for $REL: manifest='$want' file='$have'" >&2; exit 2
fi

# The project lock is exclusive: refuse while any Ghidra JVM is alive (GUI/MCP server or headless).
if pgrep -f 'ghidra.Ghidra' >/dev/null 2>&1; then
  echo "import: ERROR a Ghidra process is running (stop the GUI/MCP server first)" >&2; exit 2
fi
rm -f "$PROJ_DIR/$PROJ.lock" "$PROJ_DIR/$PROJ.lock~" 2>/dev/null || true

mkdir -p "$PROJ_DIR" "$REPO/.run/ghidra/info"
INFO="$REPO/.run/ghidra/info/$PROGRAM.txt"
rm -f "$INFO"
echo "import: $REL sha1=$have -> $PROJ_DIR/$PROJ"
"$GHIDRA/support/analyzeHeadless" "$PROJ_DIR" "$PROJ" \
  -import "$EXE" -overwrite \
  -loader PsxLoader \
  -scriptPath "$SCRIPTS" \
  -postScript DumpProgramInfo.java "$INFO" "$have"
rc=$?
echo "import: analyzeHeadless exit=$rc"
[ $rc -eq 0 ] || exit $rc
[ -s "$INFO" ] || { echo "import: ERROR info file not written: $INFO" >&2; exit 1; }
cat "$INFO"
