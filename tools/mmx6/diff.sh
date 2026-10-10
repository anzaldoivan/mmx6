#!/usr/bin/env bash
# diff.sh <func> [asm-differ args...] — asm-differ (/opt/asm-differ, pinned in the Makefile) of one function, build/
# vs expected/build/ (container, from /work; settings in /work/diff_settings.py, program from env MX6_PROG). Needs
# `make build expected` in the same container chain (sync wipes /work); never runs make itself.
# Prints asm-differ's diff (with the given args), then a last line `DIFF <func> <n> differing lines`; rc 0 only
# when n == 0, 1 when n > 0, 2 when the function or a file is missing.
# Function extent: from its map symbol to the next symbol in build/<b>.map (passed as --max-lines).
# Count: a second asm-differ run with --format json (to .run/diff/<func>.json); n = rows whose current-column line
# marker is not a space (asm-differ's plain-format markers i s r R | < >; a row missing on one side counts).
set -uo pipefail
cd "$(dirname "$0")/../.."
[[ $# -ge 1 ]] || { echo "usage: diff.sh <func> [asm-differ args...]" >&2; exit 2; }
func=$1; shift
prog=${MX6_PROG:-SLUS_013.95}
map=build/$prog.map
[[ -f $map ]] || { echo "diff.sh: no $map (run make build expected)" >&2; exit 2; }
# Symbol lines of a GNU ld map are `<addr> <name>` (fixed-width hex, so string order is address order).
read -r start next < <(awk -v f="$func" '
  NF == 2 && $1 ~ /^0x/ { a = tolower($1); if ($2 == f) s = a; else if (s != "" && a > s && (n == "" || a < n)) n = a }
  END { print s, n }' "$map")
[[ -n ${start:-} ]] || { echo "diff.sh: $func not in $map" >&2; echo "DIFF $func ? differing lines"; exit 2; }
lines=1024
[[ -n ${next:-} ]] && lines=$(( (16#${next#0x} - 16#${start#0x}) / 4 ))
python3 /opt/asm-differ/diff.py --max-lines "$lines" "$@" "$func" || { echo "DIFF $func ? differing lines"; exit 2; }
mkdir -p .run/diff
json=.run/diff/$func.json
python3 /opt/asm-differ/diff.py --max-lines "$lines" "$@" --format json "$func" > "$json" \
  || { echo "DIFF $func ? differing lines"; exit 2; }
n=$(python3 - "$json" <<'EOF'
import json, sys
# The current column starts with asm-differ's line marker: " " same, else one of i s r R | < > (differing).
rows = json.load(open(sys.argv[1]))["rows"]
print(sum(1 for r in rows if "".join(s["text"] for s in r.get("current", {}).get("text", []))[:1] != " "))
EOF
) || { echo "DIFF $func ? differing lines"; exit 2; }
echo "DIFF $func $n differing lines"
[[ $n -eq 0 ]]
