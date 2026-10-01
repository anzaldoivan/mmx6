#!/usr/bin/env bash
# tools/mmx6/ghidra/import.sh [--program SLUS_013.95 | --member NN[,NN...]|all [--base 0xADDR] | --list] [--project DIR]
#
# Headless import of a retail input into the Ghidra project `mmx6` (default dir: <repo>/ghidra, ignored+purged).
# --program: extracted/retail/iso/<name> via psx_ldr's "PSX Executables Loader", -overwrite (idempotent),
#   full auto-analysis (incl. psx_ldr "PsyQ Signatures", which applies psyq/<ver>/ sigs + GDT on its own),
#   then postScript DumpProgramInfo.java -> .run/ghidra/info/<program>.txt (format: docs/ops/oracles.md).
# --member NN[,NN...]|all [--base 0xADDR]: extracted/retail/rock/NN.bin as raw program rock_NN (BinaryLoader,
#   language PSX:LE:32:default, base = the config/loadmap.txt row for NN; rc 2 if the row is not `code` or
#   --base differs). Raw import at 0, then preScript PrepareOverlay.java moves it to the base (image base = block
#   start) and pins "PsyQ Version" to the exe's detected $PSYQ_VER so the "PsyQ Signatures" analyzer runs at
#   that version (it accepts raw programs by language). One JVM per base
#   group (`all` = every code member); the input is a hard link .run/ghidra/stage/rock_NN (program name).
# --list: print `rock_NN 0xBASE` for every code member of config/loadmap.txt (export/roundtrip/Makefile).
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
LOADMAP="$REPO/config/loadmap.txt"
PROGRAM="SLUS_013.95"
MEMBER=""
BASE=""
PSYQ_VER="4.7.0"   # psx_ldr-detected version of SLUS_013.95 (.run/ghidra/info/SLUS_013.95.txt)

# code members of the loadmap: `rock_NN 0xBASE`, index order
list_code() { awk '$1 ~ /^[0-9]+$/ && $3 == "code" { printf "rock_%02d %s\n", $1, $2 }' "$LOADMAP"; }

while [ $# -gt 0 ]; do
  case "$1" in
    --program) PROGRAM="${2:?--program needs a name}"; shift 2 ;;
    --member) MEMBER="${2:?--member needs NN}"; shift 2 ;;
    --base) BASE="${2:?--base needs 0xADDR}"; shift 2 ;;
    --project) PROJ_DIR="${2:?--project needs a dir}"; shift 2 ;;
    --list) list_code; exit 0 ;;
    *) echo "import: usage: import.sh [--program SLUS_013.95 | --member NN[,NN...]|all [--base 0xADDR] | --list] [--project DIR]" >&2; exit 2 ;;
  esac
done

[ -x "$GHIDRA/support/analyzeHeadless" ] || { echo "import: ERROR analyzeHeadless not found under $GHIDRA" >&2; exit 2; }

# sha1 of manifest record <rel> must equal the file's, else rc 2; prints the sha1
check_sha1() {
  local rel="$1" f="$REPO/extracted/retail/$1" want have
  [ -f "$f" ] || { echo "import: ERROR input missing: $f (run make extract)" >&2; return 2; }
  want="$(grep -F "\"path\": \"$rel\"" "$MANIFEST" | sed -E 's/.*"sha1": "([0-9a-f]{40})".*/\1/')"
  have="$(shasum -a 1 "$f" | cut -d' ' -f1)"
  if [ -z "$want" ] || [ "$want" != "$have" ]; then
    echo "import: ERROR sha1 mismatch for $rel: manifest='$want' file='$have'" >&2; return 2
  fi
  echo "$have"
}

# The project lock is exclusive: refuse while any Ghidra JVM is alive (GUI/MCP server or headless).
lock_check() {
  if pgrep -f 'ghidra.Ghidra' >/dev/null 2>&1; then
    echo "import: ERROR a Ghidra process is running (stop the GUI/MCP server first)" >&2; exit 2
  fi
  rm -f "$PROJ_DIR/$PROJ.lock" "$PROJ_DIR/$PROJ.lock~" 2>/dev/null || true
}

if [ -n "$MEMBER" ]; then
  [ "$PROGRAM" = "SLUS_013.95" ] || { echo "import: --program and --member are exclusive" >&2; exit 2; }
  # resolve the member list against the loadmap: NN -> base, refusing non-code rows and a differing --base
  if [ "$MEMBER" = "all" ]; then
    [ -z "$BASE" ] || { echo "import: --base needs a single --member list, not all" >&2; exit 2; }
    WANT="$(list_code)"
  else
    WANT=""
    for n in ${MEMBER//,/ }; do
      [[ "$n" =~ ^[0-9]+$ ]] || { echo "import: ERROR bad member '$n'" >&2; exit 2; }
      i=$((10#$n))
      row="$(awk -v i="$i" '$1 == i { print $2, $3 }' "$LOADMAP")"
      set -- $row
      [ "${2:-}" = "code" ] || { echo "import: ERROR member $i: loadmap row is '${row:-missing}', not code" >&2; exit 2; }
      if [ -n "$BASE" ] && [ $((BASE)) -ne $(($1)) ]; then
        echo "import: ERROR member $i: --base $BASE differs from loadmap base $1" >&2; exit 2
      fi
      WANT+="$(printf 'rock_%02d %s' "$i" "$1")"$'\n'
    done
  fi
  lock_check
  STAGE="$REPO/.run/ghidra/stage"
  INFODIR="$REPO/.run/ghidra/info"
  mkdir -p "$PROJ_DIR" "$INFODIR" "$STAGE"
  rc_all=0
  for b in $(printf '%s' "$WANT" | awk 'NF { print $2 }' | sort -u); do
    files=(); : >"$STAGE/sha1-$b.txt"
    for p in $(printf '%s' "$WANT" | awk -v b="$b" '$2 == b { print $1 }'); do
      rel="rock/${p#rock_}.bin"
      sha="$(check_sha1 "$rel")" || exit 2
      ln -f "$REPO/extracted/retail/$rel" "$STAGE/$p"
      echo "$p $sha" >>"$STAGE/sha1-$b.txt"
      rm -f "$INFODIR/$p.txt"
      files+=("$STAGE/$p")
    done
    echo "import: ${#files[@]} member(s) at $b -> $PROJ_DIR/$PROJ"
    "$GHIDRA/support/analyzeHeadless" "$PROJ_DIR" "$PROJ" \
      -import "${files[@]}" -overwrite \
      -loader BinaryLoader -loader-baseAddr 0x0 \
      -processor PSX:LE:32:default -cspec default \
      -scriptPath "$SCRIPTS" \
      -preScript PrepareOverlay.java "$PSYQ_VER" "$b" \
      -postScript DumpProgramInfo.java "$INFODIR" "$STAGE/sha1-$b.txt"
    rc=$?
    echo "import: analyzeHeadless exit=$rc ($b)"
    [ $rc -eq 0 ] || rc_all=$rc
    for f in "${files[@]}"; do
      p="$(basename "$f")"
      [ -s "$INFODIR/$p.txt" ] || { echo "import: ERROR info file not written: $INFODIR/$p.txt" >&2; rc_all=1; continue; }
      echo "import: $p $(tr '\n' ' ' <"$INFODIR/$p.txt")"
    done
  done
  exit $rc_all
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
