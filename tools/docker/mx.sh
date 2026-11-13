#!/usr/bin/env bash
# mx.sh — the Mac clone <-> amd64 build container arrangement (docs/ops/mmx6-hosts.md).
# The Mac clone is the only tree agents edit; the volume is a disposable copy at /work.
#   build [args]   build the image (linux/amd64)
#   sync [--clean] replace /work with the clone's tracked + untracked-non-ignored files (/work/.run, /work/waves kept;
#                  top-level asm build expected extracted kept too unless --clean: a later make is incremental)
#   push <path>... copy named waves/ paths from the clone to /work (same relpath, no wipe; firewall paths refused)
#   pull <path>... copy named relative paths from /work back into the clone (firewall paths refused; no *.s under
#                  waves/: game asm never reaches the clone, G12)
#   disc <dir>     load <dir>'s top-level *.cue/*.bin into the disc volume at /disc
#   sdk <dir>      load <dir>'s whole tree (the PsyQ SDK, tools/psyq) into the sdk volume at /sdk (vendor bytes
#                  stay in the volume, never in git or the image)
#   run <cmd...>   run a command in /work with /disc and /sdk mounted read-only (--init, named mx6-run-<pid>-<epoch>,
#                  labels mx6.run=1 mx6.client=<pid>; killed when mx.sh exits; rc and stdout are the command's)
#   stale          list running mx6.run containers whose client pid is gone (stderr warning on every `run`)
# Env overrides (per worktree, cookbook C0004): MX6_IMAGE, MX6_VOLUME, MX6_DISC_VOLUME, MX6_SDK_VOLUME.
# MX6_CPUS=<n> (optional): `run` adds `--cpus <n> -e MX6_JOBS=<n>`, so make's -j (fleet build, tools-health) is n;
# for k coders sharing the 8-core VM, 8/k each (docs/ops/decomp-environment.md ## Per-coder volumes).
# Never --privileged, never --pid=host, never a bind mount of a host path.
set -euo pipefail

cd "$(git rev-parse --show-toplevel)"
IMAGE="${MX6_IMAGE:-mmx6-build}"
VOL="${MX6_VOLUME:-mmx6-work}"
DISC="${MX6_DISC_VOLUME:-mmx6-disc}"
SDKV="${MX6_SDK_VOLUME:-mmx6-sdk}"
PLAT=(--platform linux/amd64)

die() { echo "mx.sh: $*" >&2; exit 2; }

# Refuse a pull path that is absolute, has a `..` component, or matches a firewall purge:/glob: line (G12).
check_path() {
  local p="$1" kind pat rest
  [[ -n "$p" ]] || die "empty path"
  [[ "$p" != /* ]] || die "absolute path refused: $p"
  case "/$p/" in */../*) die "'..' component refused: $p" ;; esac
  while read -r kind pat rest; do
    case "$kind" in
      purge:)
        local bare="${pat%/}"
        if [[ "$p" == "$bare" || "$p" == "$bare"/* || "$p" == "$pat"* ]]; then
          die "firewall path refused ($kind $pat): $p"
        fi ;;
      glob:)
        # shellcheck disable=SC2053
        if [[ "$p" == $pat || "$p" == $pat/* ]]; then die "firewall path refused ($kind $pat): $p"; fi ;;
    esac
  done < config/firewall.txt
}

# Running mx6.run containers whose client pid (mx6.client, a host pid) is gone: `MX-STALE <name> client <pid> up
# <status>` lines, last `MX-STALE <n> orphans`.
stale() {
  local n=0 name pid status
  while IFS=$'\t' read -r name pid status; do
    [[ -n "$name" ]] || continue
    if [[ -z "$pid" ]] || ! ps -p "$pid" >/dev/null 2>&1; then
      echo "MX-STALE $name client ${pid:-?} up $status"; n=$((n + 1))
    fi
  done < <(docker ps --filter label=mx6.run=1 --format '{{.Names}}\t{{.Label "mx6.client"}}\t{{.Status}}')
  echo "MX-STALE $n orphans"
}

cmd="${1:-}"; [[ $# -gt 0 ]] && shift
case "$cmd" in
  build)
    exec docker build "${PLAT[@]}" -t "$IMAGE" -f tools/docker/Dockerfile "$@" tools/docker ;;
  sync)
    keep='! -name asm ! -name build ! -name expected ! -name extracted'
    if [[ "${1:-}" == --clean ]]; then keep=''; shift; fi
    [[ $# -eq 0 ]] || die "usage: mx.sh sync [--clean]"
    git ls-files -co --exclude-standard -z \
      | while IFS= read -r -d '' f; do if [[ -e "$f" ]]; then printf '%s\0' "$f"; fi; done \
      | COPYFILE_DISABLE=1 tar --no-xattrs --no-mac-metadata --null -T - -cf - \
      | docker run -i --rm "${PLAT[@]}" -v "$VOL:/work" -w /work "$IMAGE" \
          sh -c "find /work -mindepth 1 -maxdepth 1 ! -name .run ! -name waves $keep -exec rm -rf {} + && tar -xf - -C /work" ;;
  push)
    [[ $# -gt 0 ]] || die "usage: mx.sh push <waves/relative-path>..."
    for p in "$@"; do
      check_path "$p"
      case "$p" in waves/?*) ;; *) die "push is for waves/ paths only: $p" ;; esac
      [[ -e "$p" ]] || die "no such path: $p"
    done
    COPYFILE_DISABLE=1 tar --no-xattrs --no-mac-metadata --exclude='*.s' -cf - "$@" \
      | docker run -i --rm "${PLAT[@]}" -v "$VOL:/work" "$IMAGE" tar -xf - -C /work ;;
  pull)
    [[ $# -gt 0 ]] || die "usage: mx.sh pull <relative-path>..."
    for p in "$@"; do check_path "$p"; done
    docker run --rm "${PLAT[@]}" -v "$VOL:/work" "$IMAGE" tar -cf - -C /work --exclude='waves/*.s' "$@" | tar -xf - ;;
  disc)
    [[ $# -eq 1 && -d "$1" ]] || die "usage: mx.sh disc <dir>"
    files=()
    for f in "$1"/*.cue "$1"/*.bin; do [[ -f "$f" ]] && files+=("$(basename "$f")"); done
    [[ ${#files[@]} -gt 0 ]] || die "no *.cue/*.bin in $1"
    COPYFILE_DISABLE=1 tar --no-xattrs --no-mac-metadata -cf - -C "$1" "${files[@]}" \
      | docker run -i --rm "${PLAT[@]}" -v "$DISC:/disc" "$IMAGE" \
          sh -c 'find /disc -mindepth 1 -maxdepth 1 -exec rm -rf {} + && tar -xf - -C /disc && ls -l /disc' ;;
  sdk)
    [[ $# -eq 1 && -d "$1" ]] || die "usage: mx.sh sdk <dir>"
    COPYFILE_DISABLE=1 tar --no-xattrs --no-mac-metadata --exclude=.DS_Store -cf - -C "$1" . \
      | docker run -i --rm "${PLAT[@]}" -v "$SDKV:/sdk" "$IMAGE" \
          sh -c 'find /sdk -mindepth 1 -maxdepth 1 -exec rm -rf {} + && tar -xf - -C /sdk && ls /sdk' ;;
  run)
    [[ $# -gt 0 ]] || die "usage: mx.sh run <cmd...>"
    cpus=(); [[ -n "${MX6_CPUS:-}" ]] && cpus=(--cpus "$MX6_CPUS" -e "MX6_JOBS=$MX6_CPUS")
    # run log (host, waves/ is gitignored): `cards.py --outside waves/.mx-run.log` sorts runs into probes and the rest
    argv="$*"; argv="${argv//$'\n'/ }"
    mkdir -p waves && printf '%s %s %s\n' "$(date -u +%Y-%m-%dT%H:%M:%SZ)" "$VOL" "$argv" >> waves/.mx-run.log
    # Named, labelled, killed on exit (3.1 T23): a dead client otherwise left the container running (`mx.sh stale`).
    n_stale=$(stale | tail -n 1 | awk '{print $2}')
    [[ "${n_stale:-0}" == 0 ]] || echo "mx.sh: warning: $n_stale orphaned mx6 run containers (mx.sh stale)" >&2
    name="mx6-run-$$-$(date +%s)"
    docker run --rm --init --name "$name" --label mx6.run=1 --label "mx6.client=$$" "${PLAT[@]}" \
      ${cpus[@]+"${cpus[@]}"} -v "$VOL:/work" -v "$DISC:/disc:ro" -v "$SDKV:/sdk:ro" -w /work "$IMAGE" "$@" &
    dpid=$!
    trap 'docker kill "$name" >/dev/null 2>&1 || true' EXIT
    trap 'exit 130' INT; trap 'exit 143' TERM; trap 'exit 129' HUP
    rc=0; wait "$dpid" || rc=$?
    trap - EXIT
    exit "$rc" ;;
  stale)
    [[ $# -eq 0 ]] || die "usage: mx.sh stale"
    stale ;;
  *)
    die "usage: mx.sh build|sync [--clean]|push|pull|disc|sdk|run|stale ..." ;;
esac
