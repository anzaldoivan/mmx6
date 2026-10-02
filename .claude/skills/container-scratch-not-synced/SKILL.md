---
name: container-scratch-not-synced
description: Mac .run/ never syncs; sync wipes build/ and extracted/; make container scratch and outputs in one mx.sh run
---

# Container scratch lives in the container

Captured 2026-10-01 from .run/phaseend14/skill.md.

## When to use
a container command needs a scratch file

## Steps
# Container scratch lives in the container
`mx.sh sync` ships tracked and untracked-non-ignored files to the container volume and wipes `/work` except `/work/.run`;
the Mac `.run/` is gitignored, so scratch made there never reaches the container, and the container's `.run/` never
reaches the Mac.
- Scratch a container command needs (generated probe sources, mutation controls, temp C files): create it inside the
  container, in the container's `.run/`, in the same `mx.sh run` chain that uses it.
- Scratch the Mac needs back: write it under a tracked-or-pullable path and `mx.sh pull <relpath>`; never a bind mount.
- Inputs a container command reads from the Mac tree must be non-ignored files, then `mx.sh sync` before `mx.sh run`.
- Generated outputs (`build/`, `build/dumps/`, `extracted/`) are wiped by every `mx.sh sync`: produce and read them
  (make dumps, then grep them) in the same `mx.sh run`; a chain that syncs first re-runs `make extract` / `make build`.
- Never run two agents' container loops concurrently: one's sync wipes the other's `/work`.
Source: phase 1.4 T3 (probe.py mutation control generated in the container's `.run/probe/mut/`); phase 1.7 T4, T7
(dumps wiped between runs; permute.py extracts when `extracted/` is missing).
