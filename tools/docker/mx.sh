#!/usr/bin/env bash
# mx.sh — the Mac clone <-> amd64 build container arrangement (docs/ops/mmx6-hosts.md).
# The Mac clone is the only tree agents edit; the volume is a disposable copy at /work.
#   build [args]   build the image (linux/amd64)
#   sync           replace /work with the clone's tracked + untracked-non-ignored files (/work/.run, /work/waves kept)
#   push <path>... copy named waves/ paths from the clone to /work (same relpath, no wipe; firewall paths refused)
#   pull <path>... copy named relative paths from /work back into the clone (firewall paths refused; no *.s under
#                  waves/: game asm never reaches the clone, G12)
#   disc <dir>     load <dir>'s top-level *.cue/*.bin into the disc volume at /disc
#   run <cmd...>   run a command in /work with /disc mounted read-only
# Env overrides (per worktree, cookbook C0004): MX6_IMAGE, MX6_VOLUME, MX6_DISC_VOLUME.
# Never --privileged, never --pid=host, never a bind mount of a host path.
set -euo pipefail

cd "$(git rev-parse --show-toplevel)"
IMAGE="${MX6_IMAGE:-mmx6-build}"
VOL="${MX6_VOLUME:-mmx6-work}"
DISC="${MX6_DISC_VOLUME:-mmx6-disc}"
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

cmd="${1:-}"; [[ $# -gt 0 ]] && shift
case "$cmd" in
  build)
    exec docker build "${PLAT[@]}" -t "$IMAGE" -f tools/docker/Dockerfile "$@" tools/docker ;;
  sync)
    git ls-files -co --exclude-standard -z \
      | while IFS= read -r -d '' f; do if [[ -e "$f" ]]; then printf '%s\0' "$f"; fi; done \
      | COPYFILE_DISABLE=1 tar --no-xattrs --no-mac-metadata --null -T - -cf - \
      | docker run -i --rm "${PLAT[@]}" -v "$VOL:/work" -w /work "$IMAGE" \
          sh -c 'find /work -mindepth 1 -maxdepth 1 ! -name .run ! -name waves -exec rm -rf {} + && tar -xf - -C /work' ;;
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
  run)
    [[ $# -gt 0 ]] || die "usage: mx.sh run <cmd...>"
    exec docker run --rm "${PLAT[@]}" -v "$VOL:/work" -v "$DISC:/disc:ro" -w /work "$IMAGE" "$@" ;;
  *)
    die "usage: mx.sh build|sync|push|pull|disc|run ..." ;;
esac
