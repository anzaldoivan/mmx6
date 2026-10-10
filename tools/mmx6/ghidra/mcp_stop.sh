#!/usr/bin/env bash
# tools/mmx6/ghidra/mcp_stop.sh [--no-verify]
#
# Stops the GhidrAssistMCP server started by mcp_start.sh, by pid (never pkill -f):
#   1. creates the completion file .run/ghidra/mcp.complete (server closes, Ghidra saves, exits) and waits <= 90 s;
#   2. else SIGTERM to the process group (setsid'd by mcp_start.sh), wait <= 20 s; 3. else SIGKILL (reported; unsaved).
# Then removes the pid file and proves the project lock is released: a read-only reopen of SLUS_013.95
# (DumpProgramInfo.java -> .run/ghidra/mcp-reopen.txt) must succeed. --no-verify skips the reopen.
# rc: 0 stopped (or nothing running) and reopen ok; 1 reopen failed or a forced kill was needed.
set -uo pipefail
REPO="$(cd "$(dirname "${BASH_SOURCE[0]}")/../../.." && pwd)"
GHIDRA="${GHIDRA_HOME:-$HOME/ghidra_12.1.3_PUBLIC}"
PROJ_DIR="$REPO/ghidra"
PROJ="mmx6"
PROGRAM="SLUS_013.95"
RUN="$REPO/.run/ghidra"
PIDF="$RUN/mcp.pid"
DONEF="$RUN/mcp.complete"
SCRIPTS="$REPO/tools/mmx6/ghidra/scripts"
VERIFY=1
[ "${1:-}" = "--no-verify" ] && VERIFY=0

wait_gone() {  # <pid> <seconds>
  local end=$((SECONDS + $2))
  while kill -0 "$1" 2>/dev/null && [ $SECONDS -lt $end ]; do sleep 1; done
  ! kill -0 "$1" 2>/dev/null
}

rc=0
if [ ! -f "$PIDF" ]; then
  echo "mcp-stop: no MCP server running (no $PIDF)"
  VERIFY=0
else
  pid="$(cat "$PIDF")"
  if ! kill -0 "$pid" 2>/dev/null; then
    echo "mcp-stop: stale pid file (pid $pid not alive); removing"
  else
    touch "$DONEF"
    if wait_gone "$pid" 90; then
      echo "mcp-stop: pid $pid exited cleanly (completion file)"
    else
      echo "mcp-stop: WARNING completion file ignored; SIGTERM to group $pid" >&2
      kill -TERM -- "-$pid" 2>/dev/null || kill -TERM "$pid" 2>/dev/null
      if ! wait_gone "$pid" 20; then
        echo "mcp-stop: WARNING SIGKILL to group $pid (database changes since last save are lost)" >&2
        kill -KILL -- "-$pid" 2>/dev/null || kill -KILL "$pid" 2>/dev/null
        wait_gone "$pid" 5
      fi
      rc=1
    fi
  fi
  rm -f "$PIDF" "$DONEF"
fi

[ $VERIFY -eq 1 ] || exit $rc
if pgrep -f 'ghidra.Ghidra' >/dev/null 2>&1; then
  echo "mcp-stop: ERROR a Ghidra JVM is still alive; lock not released" >&2; exit 1
fi
if [ -e "$PROJ_DIR/$PROJ.lock" ]; then
  echo "mcp-stop: ERROR $PROJ_DIR/$PROJ.lock still present after stop" >&2; exit 1
fi
OUT="$RUN/mcp-reopen.txt"
rm -f "$OUT"
"$GHIDRA/support/analyzeHeadless" "$PROJ_DIR" "$PROJ" \
  -process "$PROGRAM" -readOnly -noanalysis \
  -scriptPath "$SCRIPTS" \
  -postScript DumpProgramInfo.java "$OUT" "reopen" >"$RUN/mcp-reopen.log" 2>&1
r=$?
if [ $r -ne 0 ] || [ ! -s "$OUT" ]; then
  echo "mcp-stop: ERROR read-only reopen failed (exit $r); see $RUN/mcp-reopen.log" >&2; exit 1
fi
echo "mcp-stop: read-only reopen ok ($OUT)"
exit $rc
