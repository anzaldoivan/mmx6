#!/usr/bin/env bash
# The fresh-clone proof (1.9 T8, host): HEAD reduced to config/public-paths.txt in .run/<phase>/fresh (the files
# check-public rejects removed in one commit), check-public, then the README's `## Building the decompilation` block
# run verbatim from it (its clone line replaced by the projection, /path/to/dump by $MX6_DUMP), on image/volumes
# mmx6-fresh, mmx6-disc-fresh, removed on exit with the clone. Proves build + hash only: the health ladder
# (make fleet) needs dev-side inputs and stays in the private contract run. Last line `FRESH BUILD <k> of 57` (distinct
# `build/...: OK` lines); rc 0 iff k = 57.
# Usage: MX6_DUMP=<dump dir> bash tools/mmx6/fresh_clone.sh [DOC]
#   DOC given: on success its `## Fresh clone` section (the last) is replaced. contract.sh runs it as step 1 without.
set -uo pipefail
cd "$(dirname "$0")/../.." || exit 2
PY="${PY:-/opt/homebrew/opt/python@3.14/bin/python3.14}"
NBIN=57  # binaries of the fleet (config/*.yaml programs)
# The open phase's temp folder (as tools/run.sh: `# Phase <id>` of PHASE_PLAN.md), else .run (no plan open).
PHASE=$(sed -n '1s/^#[[:space:]]*Phase[[:space:]][[:space:]]*\([A-Za-z0-9._-][A-Za-z0-9._-]*\).*/\1/p' \
  phase-ends/current/PHASE_PLAN.md 2>/dev/null | head -n 1)
case "$PHASE" in "" | . | ..) SCR=.run ;; *) SCR=.run/$PHASE ;; esac
FRESH=$SCR/fresh
LOGD=$PWD/$SCR/contract
dump=${MX6_DUMP:?"MX6_DUMP (the folder of the .cue and .bin) is required"}
doc=${1:-}
C=$(git rev-parse HEAD)
mkdir -p "$LOGD"
drop=$LOGD/fresh-drop.txt cmds=$LOGD/fresh-cmds.txt out=$LOGD/fresh-build.out
export MX6_IMAGE=mmx6-fresh MX6_VOLUME=mmx6-fresh MX6_DISC_VOLUME=mmx6-disc-fresh
trap 'rm -rf "$FRESH"; docker volume rm -f mmx6-fresh mmx6-disc-fresh >/dev/null 2>&1; docker image rm mmx6-fresh >/dev/null 2>&1' EXIT
t0=$(date +%s)

rm -rf "$FRESH" && git clone -q --no-local . "$FRESH" || exit 1
"$PY" tools/psxd_publish.py check-public "$FRESH" \
  | sed -nE 's/^PUBLIC FAIL +(.*): (tracked but|never public).*/\1/p' >"$drop"
GIT_LITERAL_PATHSPECS=1 git -C "$FRESH" rm -q --pathspec-from-file="$drop" || exit 1
git -C "$FRESH" -c user.name=contract -c user.email=contract@localhost commit -q -m "projection of $C" || exit 1
check=$("$PY" tools/psxd_publish.py check-public "$FRESH" | tail -1)
echo "$check"
"$PY" tools/psxd_publish.py check-public "$FRESH" >/dev/null || exit 1
proj=$(git -C "$FRESH" rev-parse HEAD)

(
  cd "$FRESH" || exit 1
  awk '/^## Building the decompilation/{s=1} s&&/^```sh/{b=1;next} b&&/^```/{exit} b' README.md >"$cmds"
  while IFS= read -r line; do
    cmd=${line%%#*}; cmd=${cmd%"${cmd##*[![:space:]]}"}
    case "$cmd" in '' | 'git clone '*) continue ;; esac
    cmd=${cmd//\/path\/to\/dump/$dump}
    echo "fresh\$ $cmd"
    bash -c "$cmd" </dev/null || { echo "fresh: FAIL: $cmd"; exit 1; }
  done <"$cmds"
) 2>&1 | tee "$out"
rc=${PIPESTATUS[0]}
k=$(grep -E '^build/[^ ]+: OK$' "$out" | sort -u | wc -l | tr -d ' ')
result="FRESH BUILD $k of $NBIN"
wall=$(($(date +%s) - t0))
echo "projection $proj"
echo "$result"
[ "$rc" -eq 0 ] && [ "$k" -eq $NBIN ] || exit 1

if [ -n "$doc" ]; then
  tmp=$LOGD/fresh-doc.md
  awk '/^## Fresh clone$/{exit} {print}' "$doc" >"$tmp"
  [ -z "$(tail -c1 "$tmp")" ] && [ -n "$(tail -1 "$tmp")" ] && echo >>"$tmp"
  {
    echo "## Fresh clone"
    echo
    echo "- projection: \`$proj\` (\`$C\` reduced to config/public-paths.txt)"
    echo "- check-public: \`$check\`"
    echo "- README build commands: \`$result\` (${wall} s)"
  } >>"$tmp"
  mv "$tmp" "$doc"
fi
