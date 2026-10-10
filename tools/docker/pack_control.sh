#!/usr/bin/env bash
# pack_control.sh — the pack-location control (host; docs/ops/campaign.md ## Packs). Plants a pack in waves/WCTL/
# from an INCLUDE_ASM target of SLUS_013.95 (draft = the m2c scaffold, decompile.py, under `#if 0`, then the
# function's INCLUDE_ASM line, so R is a compiled result that reads asm/ inside the snapshot), then checks:
#   (1) a clone edit of draft.c reaches /work by `mx.sh push` (sha1 equal), a .s push is refused
#   (2) `mx.sh pull waves/WCTL` brings pack.json/draft.c and no .s
#   (3) a quiet `cards.py --probe-pack` result R
#   (4) `--probe-pack --hold 40` with `mx.sh sync` during the hold: result R, draft sha1 unchanged, waves/WCTL kept
#   (5) negative: `--no-snapshot --hold 40` with a sync during the hold: result != R or rc != 0
# Removes the pack (clone and /work) after. Logs in .run/packctl/. Last line `PACK CONTROL OK` (rc 0) or
# `PACK CONTROL FAIL <step> <why>` (rc 1). /work is left synced and unbuilt.
set -euo pipefail
cd "$(git rev-parse --show-toplevel)"
MX=(bash tools/docker/mx.sh)
OUT=.run/packctl
W=waves/WCTL
PROG=SLUS_013.95
rm -rf "$OUT" && mkdir -p "$OUT"

cleanup() { rm -rf "$W"; "${MX[@]}" run rm -rf "/work/$W" >/dev/null 2>&1 || true; }
fail() { echo "PACK CONTROL FAIL $*"; cleanup; exit 1; }
prep() { "${MX[@]}" run bash -c "make -s extract build/split/$PROG.stamp" > "$OUT/prep$1.log" 2>&1 || fail "prep$1 rc $?"; }
csha() { "${MX[@]}" run sha1sum "/work/$1" | cut -d' ' -f1; }
# Background probe; waits for `PACK HOLD`, syncs during the hold, checks the probe outlived the sync; sets RC.
held_sync() {
  local log="$OUT/$1.out" pid t=0
  "${MX[@]}" run python3 tools/mmx6/cards.py --probe-pack "$D" --hold 40 $2 > "$log" 2>&1 & pid=$!
  until grep -q '^PACK HOLD' "$log"; do
    kill -0 "$pid" 2>/dev/null || fail "$1 probe ended before its hold: $(tail -1 "$log")"
    (( t++ < 600 )) || fail "$1 no PACK HOLD in 600 s"
    sleep 1
  done
  "${MX[@]}" sync > "$OUT/$1.sync.log" 2>&1 || fail "$1 sync rc $?"
  kill -0 "$pid" 2>/dev/null || fail "$1 sync outlasted the hold"
  "${MX[@]}" run test -d asm && fail "$1 sync did not wipe /work/asm"
  RC=0; wait "$pid" || RC=$?
}

"${MX[@]}" sync > "$OUT/sync0.log" 2>&1 || fail "sync0 rc $?"
"${MX[@]}" run rm -rf "/work/$W"
prep 0
"${MX[@]}" run bash -c '
set -e; P='"$PROG"'; W='"$W"'
for s in $(ls asm/$P/nonmatchings/*/func_*.s | sort); do
  f=$(basename "$s" .s); tu=$(basename "$(dirname "$s")")
  [ -f "src/$P/$tu.c" ] && grep -q "INCLUDE_ASM(\"asm/$P/nonmatchings/$tu\", $f);" "src/$P/$tu.c" || continue
  [ -f "drafts/$P/$f.c" ] && continue
  n=$(grep -c "^ */\* [0-9A-F]* [0-9A-F]\{8\} [0-9A-F]\{8\} \*/" "$s" || true)
  [ "$n" -ge 8 ] && [ "$n" -le 40 ] || continue
  d=$W/${P}_$f; mkdir -p "$d"; cp "$s" "$d/target.s"
  { echo "#include \"common.h\""; echo "#if 0 /* m2c scaffold (rarely compiles raw); the INCLUDE_ASM below gives a compiled R */"
    python3 tools/mmx6/decompile.py "$f" --prog "$P" || true
    echo "#endif"; echo "INCLUDE_ASM(\"asm/$P/nonmatchings/$tu\", $f);"; } > "$d/draft.c"
  printf "{\"pv\": \"%s:0x%s\", \"prog\": \"%s\", \"func\": \"%s\", \"tu\": \"%s\", \"words\": %d}\n" \
    "$P" "${f#func_}" "$P" "$f" "$tu" "$n" > "$d/pack.json"
  echo "PLANT $d words $n"; exit 0
done
echo "no INCLUDE_ASM target"; exit 1' > "$OUT/plant.log" 2>&1 || fail "plant: $(tail -1 "$OUT/plant.log")"
D=$(sed -n 's/^PLANT \([^ ]*\) .*/\1/p' "$OUT/plant.log")
echo "$(tail -1 "$OUT/plant.log")"

# (2) pull: pack.json + draft.c, no .s; the container keeps target.s
rm -rf "$W"
"${MX[@]}" pull "$W"
[[ -f "$D/pack.json" && -f "$D/draft.c" ]] || fail "2 pull lacks pack.json/draft.c"
[[ -z "$(find "$W" -name '*.s')" ]] || fail "2 pull brought a .s"
"${MX[@]}" run test -f "$D/target.s" || fail "2 container lost target.s"
echo "STEP 2 pull: pack.json draft.c, 0 .s in the clone, target.s kept in /work"

# (1) clone edit -> push -> same sha1 in /work; a .s push is refused
echo "/* pack control edit $(date +%s) */" >> "$D/draft.c"
MAC=$(shasum "$D/draft.c" | cut -d' ' -f1)
"${MX[@]}" push "$D/draft.c"
[[ "$(csha "$D/draft.c")" == "$MAC" ]] || fail "1 push sha1 differs"
: > "$OUT/fake.s"; mkdir -p "$D" && cp "$OUT/fake.s" "$D/fake.s"
if "${MX[@]}" push "$D/fake.s" > "$OUT/push_s.log" 2>&1; then fail "1 .s push accepted"; fi
rm -f "$D/fake.s"
echo "STEP 1 push: sha1 $MAC equal in clone and /work; .s push refused ($(tail -1 "$OUT/push_s.log"))"

# (3) quiet probe
"${MX[@]}" run python3 tools/mmx6/cards.py --probe-pack "$D" > "$OUT/s3.out" 2>&1 || fail "3 rc $?: $(tail -1 "$OUT/s3.out")"
R=$(grep '^PACK ' "$OUT/s3.out" | tail -1)
[[ -n "$R" ]] || fail "3 no PACK line"
echo "STEP 3 quiet: $R"

# (4) snapshot probe held across a sync
held_sync s4 ""
R4=$(grep '^PACK [^H]' "$OUT/s4.out" | tail -1 || true)
[[ $RC -eq 0 && "$R4" == "$R" ]] || fail "4 rc $RC result '$R4' != '$R'"
[[ "$(csha "$D/draft.c")" == "$MAC" ]] || fail "4 draft sha1 changed"
"${MX[@]}" run test -d "/work/$W" || fail "4 /work/$W gone"
"${MX[@]}" run sh -c 'test -z "$(ls -A /work/waves/.iso 2>/dev/null)"' || fail "4 snapshot not removed"
echo "STEP 4 snapshot+sync: $R4 (= R), draft sha1 unchanged, /work/$W present, waves/.iso empty"

# (5) negative control: no snapshot, same sync
prep 5
held_sync s5 --no-snapshot
R5=$(grep '^PACK [^H]' "$OUT/s5.out" | tail -1 || true)
[[ $RC -ne 0 || "$R5" != "$R" ]] || fail "5 no-snapshot result equals R under a sync"
echo "STEP 5 no-snapshot+sync: rc $RC result '${R5:-none}' ($(grep -v '^PACK HOLD' "$OUT/s5.out" | tail -1))"

cleanup
"${MX[@]}" run test ! -e "/work/$W" || fail "cleanup left /work/$W"
echo "PACK CONTROL OK"
