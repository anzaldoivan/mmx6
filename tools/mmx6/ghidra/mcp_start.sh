#!/usr/bin/env bash
# tools/mmx6/ghidra/mcp_start.sh
#
# Starts the GhidrAssistMCP server headless on ghidra/mmx6 (program SLUS_013.95, no re-import, no analysis):
#   analyzeHeadless … -process SLUS_013.95 -noanalysis -postScript GAMCPStartServerScript.java wait=true
#   completion_file=.run/ghidra/mcp.complete (mcp_stop.sh creates it: server closes, Ghidra saves and exits).
# Detached (nohup, own session); pid -> .run/ghidra/mcp.pid, log -> .run/ghidra/mcp.log.
# Waits <= 120 s for the health check (GET /sse -> 200), else stops the JVM and rc 1.
# rc: 0 up; 1 failed to come up; 2 precondition (already running, Ghidra JVM alive, tool missing).
# Client: .mcp.json "disassembler" (SSE http://localhost:8080/sse). Lifecycle: docs/ops/oracles.md "## MCP server".
set -uo pipefail
REPO="$(cd "$(dirname "${BASH_SOURCE[0]}")/../../.." && pwd)"
GHIDRA="${GHIDRA_HOME:-$HOME/ghidra_12.1.3_PUBLIC}"
PROJ_DIR="$REPO/ghidra"
PROJ="mmx6"
PROGRAM="SLUS_013.95"
HOST="localhost"
PORT="8080"
RUN="$REPO/.run/ghidra"
PIDF="$RUN/mcp.pid"
LOG="$RUN/mcp.log"
DONEF="$RUN/mcp.complete"
EXT_SCRIPTS="$GHIDRA/Ghidra/Extensions/GhidrAssistMCP/ghidra_scripts"
URL="http://$HOST:$PORT/sse"

[ -x "$GHIDRA/support/analyzeHeadless" ] || { echo "mcp-start: ERROR analyzeHeadless not found under $GHIDRA" >&2; exit 2; }
[ -f "$EXT_SCRIPTS/GAMCPStartServerScript.java" ] || { echo "mcp-start: ERROR GhidrAssistMCP not installed under $GHIDRA" >&2; exit 2; }
[ -d "$PROJ_DIR/$PROJ.rep" ] || { echo "mcp-start: ERROR no project $PROJ_DIR/$PROJ (run make ghidra-import)" >&2; exit 2; }

if [ -f "$PIDF" ] && kill -0 "$(cat "$PIDF")" 2>/dev/null; then
  echo "mcp-start: ERROR already running (pid $(cat "$PIDF")); make ghidra-mcp-stop first" >&2; exit 2
fi
# The project lock is exclusive: refuse while any Ghidra JVM is alive (GUI or headless).
if pgrep -f 'ghidra.Ghidra' >/dev/null 2>&1; then
  echo "mcp-start: ERROR a Ghidra process is running (stop the GUI/headless run first)" >&2; exit 2
fi
rm -f "$PIDF" "$DONEF" "$PROJ_DIR/$PROJ.lock" "$PROJ_DIR/$PROJ.lock~" 2>/dev/null || true
mkdir -p "$RUN"

# nohup + own session: the JVM outlives the caller's shell and is not one of its job-control jobs.
nohup /usr/bin/env perl -e 'use POSIX; POSIX::setsid(); exec @ARGV' \
  "$GHIDRA/support/analyzeHeadless" "$PROJ_DIR" "$PROJ" \
  -process "$PROGRAM" -noanalysis \
  -scriptPath "$EXT_SCRIPTS" \
  -postScript GAMCPStartServerScript.java "host=$HOST" "port=$PORT" "wait=true" "completion_file=$DONEF" \
  >"$LOG" 2>&1 </dev/null &
pid=$!
echo "$pid" >"$PIDF"
echo "mcp-start: pid $pid, log $LOG; waiting for $URL"

deadline=$((SECONDS + 120))
while [ $SECONDS -lt $deadline ]; do
  # SSE keeps the stream open: curl exits 28 after the headers; the http_code is what counts.
  code="$(curl --max-time 3 -s -o /dev/null -w '%{http_code}' "$URL" 2>/dev/null)"
  if [ "$code" = "200" ]; then
    echo "mcp-start: up ($URL -> 200)"; exit 0
  fi
  if ! kill -0 "$pid" 2>/dev/null; then
    echo "mcp-start: ERROR analyzeHeadless exited before the server came up; tail of $LOG:" >&2
    tail -n 15 "$LOG" >&2; rm -f "$PIDF"; exit 1
  fi
  sleep 2
done
echo "mcp-start: ERROR no 200 from $URL within 120 s; stopping" >&2
bash "$REPO/tools/mmx6/ghidra/mcp_stop.sh" --no-verify >&2
exit 1
