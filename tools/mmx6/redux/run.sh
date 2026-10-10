#!/usr/bin/env bash
# tools/mmx6/redux/run.sh <lua> [--timeout S] [--state .run/redux/states/<name>]
#
# Runs PCSX-Redux headless (runtime oracle, docs/ops/oracles.md) on the retail disc with a repo Lua script:
#   -no-ui -testmode -stdout -lua_stdout -portable -interpreter -debugger -bios $BIOS -iso $REDUX_CUE -run -dofile <lua>
# (-interpreter: the arm64 dynarec of this build dies with SIGBUS/SIGILL within ~1 s headless; -debugger: Exec
# breakpoints fire only with it; -portable: config + memory cards in the cwd, never ~/.config/pcsx-redux. T4.c1)
# Log: .run/redux/logs/<lua-stem>-<stamp>.log. rc = the Lua's PCSX.quit(code); 124 on timeout (killed by pid).
# Env: REDUX (binary), BIOS, REDUX_CUE (defaults as in the Makefile). Exported to the Lua: MMX6_ROOT (repo),
# MMX6_REDUX_STATE (absolute save-state path, empty if none; lib.lua loadState() consumes it).
# Redux runs with cwd .run/redux/work so its own config/cache files never land in the repo.
set -uo pipefail
REPO="$(cd "$(dirname "${BASH_SOURCE[0]}")/../../.." && pwd)"
REDUX="${REDUX:-$HOME/Applications/PCSX-Redux.app/Contents/MacOS/PCSX-Redux}"
BIOS="${BIOS:-/Users/ThinkPad/GameInputs/megaman-x6/SCPH1001.BIN}"
REDUX_CUE="${REDUX_CUE:-/Users/ThinkPad/GameInputs/megaman-x6/Mega Man X6 (USA) (v1.1).cue}"
TIMEOUT=600
STATE=""
LUA=""

while [ $# -gt 0 ]; do
  case "$1" in
    --timeout) TIMEOUT="${2:?--timeout needs seconds}"; shift 2;;
    --state) STATE="${2:?--state needs a path}"; shift 2;;
    -h|--help) sed -n '2,9p' "$0" | sed 's/^# \{0,1\}//'; exit 0;;
    *) [ -z "$LUA" ] || { echo "run.sh: extra argument $1" >&2; exit 2; }; LUA="$1"; shift;;
  esac
done
[ -n "$LUA" ] || { echo "run.sh: missing <lua>" >&2; exit 2; }
for f in "$LUA" "$REDUX" "$BIOS" "$REDUX_CUE"; do
  [ -f "$f" ] || { echo "run.sh: missing file: $f" >&2; exit 2; }
done
LUA="$(cd "$(dirname "$LUA")" && pwd)/$(basename "$LUA")"
if [ -n "$STATE" ]; then
  [ -f "$STATE" ] || { echo "run.sh: missing state: $STATE" >&2; exit 2; }
  STATE="$(cd "$(dirname "$STATE")" && pwd)/$(basename "$STATE")"
fi

mkdir -p "$REPO/.run/redux/logs" "$REPO/.run/redux/work"
LOG="$REPO/.run/redux/logs/$(basename "$LUA" .lua)-$(date +%Y%m%d-%H%M%S).log"
export MMX6_ROOT="$REPO" MMX6_REDUX_STATE="$STATE"

cd "$REPO/.run/redux/work" || exit 2
"$REDUX" -no-ui -testmode -stdout -lua_stdout -portable -interpreter -debugger -bios "$BIOS" -iso "$REDUX_CUE" -run -dofile "$LUA" \
  >"$LOG" 2>&1 &
PID=$!
waited=0
while kill -0 "$PID" 2>/dev/null; do
  if [ "$waited" -ge "$TIMEOUT" ]; then
    kill "$PID" 2>/dev/null; sleep 2; kill -9 "$PID" 2>/dev/null
    wait "$PID" 2>/dev/null
    echo "run.sh: timeout after ${TIMEOUT}s (pid $PID killed); log $LOG" >&2
    exit 124
  fi
  sleep 1; waited=$((waited + 1))
done
wait "$PID"; rc=$?
echo "run.sh: rc=$rc log=$LOG"
exit "$rc"
