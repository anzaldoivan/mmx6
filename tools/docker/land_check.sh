#!/usr/bin/env bash
# land_check.sh <tree>: the byte check of an exported tree. psxd_publish.py land runs it ([public].land_check) on the
# import chain's tree before dev moves. A throwaway container from the build image; the game inputs are copied from
# the work volume, mounted read-only (the live /work is never written). Exit 0 only when every check.*.sha line holds.
set -euo pipefail
tree=${1:?usage: land_check.sh <tree>}
image="${MX6_IMAGE:-mmx6-build}"
vol="${MX6_VOLUME:-mmx6-work}"
cn="mmx6-land-check-$$"
docker run -d --platform linux/amd64 --name "$cn" -v "$vol":/src:ro "$image" sleep 7200 >/dev/null
trap 'docker rm -f -v "$cn" >/dev/null 2>&1' EXIT
docker exec "$cn" bash -c 'rm -rf /work/* /work/.[!.]* 2>/dev/null; mkdir -p /work && cp -a /src/extracted /work/'
COPYFILE_DISABLE=1 tar -C "$tree" --exclude=.git --exclude=./extracted --no-xattrs -cf - . |
  docker exec -i "$cn" tar -xf - -C /work
docker exec "$cn" bash -c 'cd /work && { make -j8 split build >/tmp/b.log 2>&1 || { tail -5 /tmp/b.log; exit 1; }; }
  cat config/check.*.sha | sort -u >/tmp/all.sha
  n=$(cd /work && sha1sum -c /tmp/all.sha 2>/dev/null | grep -c ": OK$" || true); t=$(wc -l </tmp/all.sha)
  echo "LAND-CHECK $n of $t"; [ "$n" = "$t" ]'
