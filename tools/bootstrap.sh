#!/usr/bin/env bash
# tools/bootstrap.sh — fresh-clone setup: bash tools/bootstrap.sh <dump-dir>
# Idempotent; never sudo, never installs. The toolchain (Python tools, assembler, vintage compiler, splat) lives in the
# container image (tools/docker/Dockerfile; pins: docs/ops/mmx6-hosts.md, docs/ops/compiler-pin.md), so the host needs
# only git, bash and docker. Steps:
#   1. host tools  — git, bash, docker + a running daemon; if any is missing, print ONE install line and exit 1.
#   2. image       — tools/docker/mx.sh build
#   3. disc        — tools/docker/mx.sh disc <dump-dir> (its top-level *.cue/*.bin into the disc volume)
#   4. work tree   — tools/docker/mx.sh sync
#   5. preflight   — tools/docker/mx.sh run make toolchain-check; its exit status is this script's.
# MX6_IMAGE, MX6_VOLUME, MX6_DISC_VOLUME pass through to mx.sh (per-worktree names, cookbook C0004).
set -euo pipefail
say() { printf 'bootstrap: %s\n' "$*"; }

if [[ $# -ne 1 || ! -d "$1" ]]; then
    echo "usage: bash tools/bootstrap.sh <dump-dir>   (a directory holding the disc's *.cue/*.bin)" >&2
    exit 2
fi
DUMP="$(cd "$1" && pwd)"
REPO="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cd "$REPO"

# 1) host tools — presence only; print the install line, never run it.
missing=()
for t in git bash docker; do command -v "$t" >/dev/null 2>&1 || missing+=("$t"); done
if ((${#missing[@]} == 0)) && ! docker info >/dev/null 2>&1; then missing+=("docker-daemon"); fi
if ((${#missing[@]})); then
    say "MISSING: ${missing[*]} — install, start Docker, then re-run bootstrap:"
    if [[ "$(uname -s)" == Darwin ]]; then
        echo "  brew install git bash && brew install --cask docker"
    else
        echo "  sudo apt-get install -y git bash docker.io && sudo systemctl start docker"
    fi
    exit 1
fi
say "host tools: git, bash, docker (daemon up)"

MX=(bash tools/docker/mx.sh)
say "2/5 image";     "${MX[@]}" build
say "3/5 disc";      "${MX[@]}" disc "$DUMP"
say "4/5 sync";      "${MX[@]}" sync
say "5/5 preflight: make toolchain-check"
rc=0; "${MX[@]}" run make toolchain-check || rc=$?
say "preflight rc=$rc"
exit "$rc"
