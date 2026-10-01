---
name: ci-wait-after-push
description: Wait for GitHub CI after a push: run.sh --bg gh run watch, then run.sh --wait under 285 s
---

# CI wait after push

Captured 2026-10-01 from .run/pe/sk1.md.

## When to use
after the developer pushes and a milestone needs a CI conclusion

## Steps
# Wait for CI after a push
1. Find the run: `gh run list --workflow <wf>.yml -L 1` (note its id and headSha; confirm headSha is the pushed commit).
2. Start the watch detached: `bash tools/run.sh --bg <name> -- gh run watch <id> --exit-status`.
3. Wait in one bounded call: `bash tools/run.sh --wait <name> --max 270` (repeat if still running; each call < 285 s).
4. Green = exit 0 and `gh run list --workflow <wf>.yml -L 1` conclusion `success`.
- Never a sleep-poll loop; GNU `timeout` is absent on macOS.
