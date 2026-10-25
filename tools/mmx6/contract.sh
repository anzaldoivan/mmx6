#!/usr/bin/env bash
# The contract run (1.9 T7, host): every gate of the tree in one pass from a clean committed tree, then
# docs/contract-run.md written wholly from captured values. Stops at the first failing step (`CONTRACT FAIL <step>
# rc=<rc>`, rc 1, the doc untouched); on success last line `CONTRACT OK <n> steps`.
# Each step: full output -> .run/<phase>/contract/<i>-<step>.log; result line = the step's own last verdict line (grepped).
# Usage: MX6_DUMP=<dump dir> bash tools/mmx6/contract.sh   (env: PY = host python, MX6_IMAGE = container image)
set -uo pipefail
cd "$(dirname "$0")/../.." || exit 2
PY="${PY:-/opt/homebrew/opt/python@3.14/bin/python3.14}"
MX="bash tools/docker/mx.sh"
NBIN=57  # binaries of the fleet (config/*.yaml programs)
# The open phase's temp folder (as tools/run.sh: `# Phase <id>` of PHASE_PLAN.md), else .run (no plan open).
PHASE=$(sed -n '1s/^#[[:space:]]*Phase[[:space:]][[:space:]]*\([A-Za-z0-9._-][A-Za-z0-9._-]*\).*/\1/p' \
  phase-ends/current/PHASE_PLAN.md 2>/dev/null | head -n 1)
case "$PHASE" in "" | . | ..) SCR=.run ;; *) SCR=.run/$PHASE ;; esac
LOGD=$SCR/contract
DOC=docs/contract-run.md

dirty=$(git status --porcelain -- Makefile mk src include config tools/mmx6 tools/docker)
[ -z "$dirty" ] || { echo "contract: refuse: uncommitted changes under the build inputs:"; echo "$dirty"; exit 2; }
C=$(git rev-parse HEAD)
mkdir -p "$LOGD"
STEPS=()
i=0

# step <name> <verdict ERE> <cmd...>: run, log, time; result = last line of the log matching the ERE.
step() {
  local name=$1 pat=$2; shift 2
  i=$((i + 1))
  local log="$LOGD/$i-$name.log" t0 rc
  t0=$(date +%s)
  echo "contract: [$i] $name ..."
  "$@" >"$log" 2>&1
  rc=$?
  WALL=$(($(date +%s) - t0))
  RESULT=$(grep -E "$pat" "$log" | tail -1)
  if [ $rc -ne 0 ] || [ -z "$RESULT" ]; then
    tail -5 "$log"
    echo "CONTRACT FAIL $name rc=$rc (log $log)"; exit 1
  fi
}
record() { echo "contract: [$i] $1: $2 (${WALL} s)"; STEPS+=("- $1: \`$2\` (${WALL} s)"); }
fail() { echo "CONTRACT FAIL $1 rc=1 ($2)"; exit 1; }

# fresh-clone (1.9 T8): tools/mmx6/fresh_clone.sh (HEAD reduced to config/public-paths.txt, check-public, the README's
# build block verbatim on image/volumes mmx6-fresh, mmx6-disc-fresh; build + hash only), written as `## Fresh clone`.
step fresh-clone '^FRESH BUILD [0-9]+ of [0-9]+$' bash tools/mmx6/fresh_clone.sh
[ "$RESULT" = "FRESH BUILD $NBIN of $NBIN" ] || fail fresh-clone "not FRESH BUILD $NBIN of $NBIN"
FWALL=$WALL FRESULT=$RESULT
FPROJ=$(sed -n 's/^projection //p' "$LOGD/$i-fresh-clone.log" | tail -1)
FCHECK=$(grep '^PUBLIC CHECK OK' "$LOGD/$i-fresh-clone.log" | tail -1)
echo "contract: [$i] fresh-clone: $FRESULT at $FPROJ (${FWALL} s)"

step fleet '^FLEET [0-9]+ of [0-9]+$' bash -c "$MX sync && $MX run make fleet"
[ "$RESULT" = "FLEET $NBIN of $NBIN" ] && [ "$(tail -1 "$LOGD/$i-fleet.log")" = "$RESULT" ] \
  || fail fleet "last line not FLEET $NBIN of $NBIN"
record fleet "$RESULT"

step loadmap '^CONTROLS ' bash -c "make loadmap PYTHON=$PY && git diff --exit-code config/loadmap.txt"
record loadmap "$RESULT"

step boundaries '^# totals ' bash -c "make boundaries PYTHON=$PY && git diff --exit-code config/boundaries.txt"
record boundaries "$RESULT"

step bound2 '^BOUND2 ' $MX run python3 tools/mmx6/bound2.py --all
record bound2 "$RESULT"

step th-selftests '(PASS|OK|pass)' $MX run make th-selftests
record th-selftests "$RESULT"

step sdk '^SDK [0-9]+ of [0-9]+' $MX run bash -c 'make clean && make -j8 SDK=/sdk build'
nok=$(grep -cE ': OK$' "$LOGD/$i-sdk.log")
read -r _ k _ n _ <<<"$RESULT"
[ "$nok" -eq $NBIN ] && [ "$k" = "$n" ] || fail sdk "$nok of $NBIN binaries OK; $RESULT"
record sdk "$RESULT, $nok binaries OK"

step ghidra-roundtrip '^ROUNDTRIP ' make ghidra-roundtrip
record ghidra-roundtrip "$RESULT"

step redux-smoke '^run\.sh: rc=' make redux-smoke
record redux-smoke "${RESULT%% log=*}"

step audit_public '^audit_public: (OK|FAIL)' "$PY" tools/audit_public.py
record audit_public "$RESULT"

TRIPLE=$(sed -n 's/^TRIPLE ?= *//p' Makefile)
IMG=$(docker image inspect --format '{{.Id}}' "${MX6_IMAGE:-mmx6-build}")
TH=$(git log -1 --format='%cs, "%s", %h' -- phase-ends/PhaseEnd_Phase1.8.1.md)
tmp="$LOGD/contract-run.md"
{
  echo "# Contract run"
  echo
  echo "Written by \`bash tools/mmx6/contract.sh\` from captured output. It is never hand-edited."
  echo
  echo "- date (UTC): $(date -u +%Y-%m-%dT%H:%M:%SZ)"
  echo "- commit: \`$C\`"
  echo "- triple: \`$TRIPLE\`"
  echo "- image: \`$IMG\`"
  echo
  echo "## Steps (result line, wall time)"
  echo
  printf '%s\n' "${STEPS[@]}"
  echo
  echo "## Not rerun"
  echo
  echo "- \`make tools-health-full\`: verified split at the PhaseEnd commit $TH."
  echo
  echo "## Fresh clone"
  echo
  echo "- projection: \`$FPROJ\` (\`$C\` reduced to config/public-paths.txt)"
  echo "- check-public: \`$FCHECK\`"
  echo "- README build commands: \`$FRESULT\` (${FWALL} s)"
} >"$tmp"
mv "$tmp" "$DOC"
echo "CONTRACT OK $i steps"
