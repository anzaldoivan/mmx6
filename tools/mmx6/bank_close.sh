#!/usr/bin/env bash
# bank_close.sh (3.0 T1): the developer's one-liner after a bank, in the R61 order, one paste per stop.
#   1 stage    git add -- <paths>                       (R39: staged before `debt --update`)
#   2 raise    PY tools/psxd_floor.py debt --raise placeholder <n> --reason <text>   (only when given)
#   3 update   PY tools/psxd_floor.py debt --update
#   4 check    PY tools/psxd_floor.py debt              (rc 0 and a `DEBT CHECK OK` line)
#   5 badges   PY tools/mmx6/badges.py --write
#   6 bcheck   PY tools/mmx6/badges.py --check
#   7 commit   bash tools/commit_task.sh <TaskId> "<line>" <paths> config/debt-baseline.txt docs/badges
# Steps run one after another; the first nonzero rc stops it: `BANK-CLOSE FAIL <step> rc=<rc>`, exit <rc>.
# Success: last line `BANK-CLOSE OK <k> steps`. psxd_floor.py refuses `debt --raise/--update` to agent
# sessions: agents run only --dry-run and --self-test.
# Usage:
#   bash tools/mmx6/bank_close.sh [--dry-run] <TaskId> "<one line>" [placeholder <n> [--reason <text>]] <paths>
#   bash tools/mmx6/bank_close.sh --rises <paths>
#   bash tools/mmx6/bank_close.sh --self-test
# <paths> = <path>... or `--paths-from <file>` (3.1 T7: a wave's list, one path per line, blank and `#` lines skipped).
# --dry-run prints the exact commands, one per line (list paths written out), and runs nothing. --reason defaults to
# "<TaskId>: <line>".
# --rises (agent-runnable, writes nothing tracked): copies .git/index, stages <paths> into the copy (GIT_INDEX_FILE,
# R114; untracked files included), runs `debt --staged` on it, prints `RISE <kind> +<n> (<mode>)` per rising kind and
# last `BANK-RISES placeholder <n> other <kind +n,...|none>`: the wave's one `placeholder <n>` for the paste. rc 1 when
# staging or debt fails.
# Env: PY = host python (default the card's).
set -uo pipefail
ROOT="$(cd "$(dirname "$0")/../.." && pwd)" || exit 2
PY="${PY:-/opt/homebrew/opt/python@3.14/bin/python3.14}"

die() { echo "bank_close: $*" >&2; exit 2; }

scratch_root() {  # .run/<phase> from the plan's title, else .run
  local phase
  phase=$(sed -n '1s/^#[[:space:]]*Phase[[:space:]][[:space:]]*\([A-Za-z0-9._-][A-Za-z0-9._-]*\).*/\1/p' \
    "$ROOT/phase-ends/current/PHASE_PLAN.md" 2>/dev/null | head -n 1)
  case "$phase" in "" | . | ..) echo "$ROOT/.run" ;; *) echo "$ROOT/.run/$phase" ;; esac
}

take_paths() {  # "$@" = <path>... or --paths-from <file> -> PATHS
  PATHS=()
  if [ "${1:-}" = --paths-from ]; then
    [ $# -eq 2 ] || die "--paths-from takes one list file and no other paths"
    [ -f "$2" ] || die "no list file: '$2'"
    local l
    while IFS= read -r l || [ -n "$l" ]; do
      l="${l#"${l%%[![:space:]]*}"}"; l="${l%"${l##*[![:space:]]}"}"
      case "$l" in "" | "#"*) continue ;; esac
      PATHS+=("$l")
    done < "$2"
  else
    PATHS=("$@")
  fi
  [ ${#PATHS[@]} -ge 1 ] || die "no bank paths"
  local p
  for p in "${PATHS[@]}"; do case "$p" in -*) die "unexpected option or path starting with '-': '$p'" ;; esac; done
}

rises() {  # PATHS staged into a copy of .git/index; debt --staged on it
  local scr out rc kind tot row n mode down P=0 other=""
  cd "$ROOT" || return 1
  scr="$(scratch_root)/bank_close-rises.$$"; rm -rf "$scr"; mkdir -p "$scr" || return 1
  cp "$(git rev-parse --git-dir)/index" "$scr/index" || { rm -rf "$scr"; return 1; }
  if ! out=$(GIT_INDEX_FILE="$scr/index" git add -A -- "${PATHS[@]}" 2>&1); then
    printf '%s\n' "$out"; rm -rf "$scr"; echo "BANK-RISES FAIL stage"; return 1
  fi
  out=$(GIT_INDEX_FILE="$scr/index" "$PY" tools/psxd_floor.py debt --staged 2>&1); rc=$?
  rm -rf "$scr"
  if ! grep -q '^DEBT CHECK ' <<< "$out"; then
    printf '%s\n' "$out" | tail -n 5; echo "BANK-RISES FAIL debt rc=$rc"; return 1
  fi
  down=$(grep '^DEBT CHECK ' <<< "$out" | sed -n 's/.*down: \([^;)]*\).*/\1/p' | tr -d ' ')
  while read -r kind tot row; do
    [ -n "$kind" ] || continue
    n=$((tot - row)); mode=count
    case ",$down," in *",$kind,"*) mode=down ;; esac
    echo "RISE $kind +$n ($mode)"
    if [ "$kind" = placeholder ]; then P=$n; else other="${other:+$other,}$kind +$n"; fi
  done < <(sed -n 's/^DEBT FAIL rise \([A-Za-z-]*\): \([0-9]*\), its row is \([0-9]*\).*/\1 \2 \3/p' <<< "$out")
  echo "BANK-RISES placeholder $P other ${other:-none}"
}

self_test() {
  local scr t out exp rc fails=0 here="$ROOT/tools/mmx6/bank_close.sh"
  scr="$(scratch_root)/bank_close-selftest"
  rm -rf "$scr"; mkdir -p "$scr/tree/tools/mmx6" "$scr/bin"
  t="$scr/tree/tools/mmx6/bank_close.sh"
  cp "$here" "$t"
  # Stubs: each logs its argv and exits with $STUB_RC_<name> (default 0); `git` is shadowed on PATH.
  for s in tools/psxd_floor.py tools/mmx6/badges.py tools/commit_task.sh bin/git; do
    case $s in bin/*) f="$scr/$s" ;; *) f="$scr/tree/$s" ;; esac
    cat > "$f" <<'EOF'
#!/usr/bin/env bash
n=$(basename "$0"); n=${n%%.*}; [ "$n" = psxd_floor ] && [ "${1:-}" = debt ] && n=debt_${2:-check}; n=${n#debt_--}
echo "$n $*" >> "$STUB_LOG"
v="STUB_RC_$n"; [ "$n" = debt_check ] && [ -z "${STUB_NO_OK:-}" ] && echo "DEBT CHECK OK"
exit "${!v:-0}"
EOF
    chmod +x "$f"
  done
  local before_head before_base before_stat before_index
  before_head=$(git -C "$ROOT" rev-parse HEAD); before_base=$(cksum < "$ROOT/config/debt-baseline.txt")
  before_index=$(cksum < "$(git -C "$ROOT" rev-parse --absolute-git-dir)/index")
  before_stat=$(git -C "$ROOT" status --porcelain)
  ck() { if [ "$2" = "$3" ]; then echo "  ok   $1"; else echo "  FAIL $1"; echo "    want: $2"; echo "    got:  $3"; fails=$((fails + 1)); fi; }
  run() { PY=bash PATH="$scr/bin:$PATH" STUB_LOG="$scr/log" bash "$t" "$@" 2>&1; }

  # 1 dry-run order, with a raise
  out=$(run --dry-run T9 "bank func_X pin-free" placeholder 3 src/a.c "config/b c.txt"); rc=$?
  exp=$(printf '%s\n' \
    "git add -- src/a.c config/b\\ c.txt" \
    "bash tools/psxd_floor.py debt --raise placeholder 3 --reason T9:\\ bank\\ func_X\\ pin-free" \
    "bash tools/psxd_floor.py debt --update" \
    "bash tools/psxd_floor.py debt" \
    "bash tools/mmx6/badges.py --write" \
    "bash tools/mmx6/badges.py --check" \
    "bash tools/commit_task.sh T9 bank\\ func_X\\ pin-free src/a.c config/b\\ c.txt config/debt-baseline.txt docs/badges")
  ck "dry-run order with raise" "0|$exp" "$rc|$out"
  # 2 dry-run without a raise: 6 lines, no --raise; explicit --reason ignored without a raise is refused
  out=$(run --dry-run T9 "x" src/a.c); rc=$?
  ck "dry-run no raise: 6 commands, none --raise" "0|6|0" "$rc|$(echo "$out" | wc -l | tr -d ' ')|$(echo "$out" | grep -c -- '--raise')"
  out=$(run --dry-run T9 "x" placeholder 2 --reason "names paid later" src/a.c | sed -n 2p)
  ck "explicit --reason" "bash tools/psxd_floor.py debt --raise placeholder 2 --reason names\\ paid\\ later" "$out"
  # 3 argument errors: rc 2, nothing run
  : > "$scr/log"
  local bad
  for bad in "" "T9" "T9|x" "T9|x|placeholder" "T9|x|placeholder|0|a.c" "T9|x|placeholder|n|a.c" \
             "T9||a.c" "T 9|x|a.c" "T9|x|--reason|r|a.c" "--bogus|T9|x|a.c"; do
    local -a av=(); IFS='|' read -r -a av <<< "$bad"
    run ${av[@]+"${av[@]}"} > /dev/null; rc=$?
    ck "reject [${bad}]" 2 "$rc"
  done
  run T9 "$(printf 'a%.0s' $(seq 101))" a.c > /dev/null; ck "reject line > 100 chars" 2 "$?"
  run T9 "$(printf 'a\nb')" a.c > /dev/null; ck "reject multi-line" 2 "$?"
  ck "argument errors ran nothing" "" "$(cat "$scr/log")"
  # 4 live mode on stubs: full order, then a stop at each failing step
  : > "$scr/log"; out=$(run T9 "x" placeholder 3 src/a.c); rc=$?
  ck "live: rc 0, OK line" "0|BANK-CLOSE OK 7 steps" "$rc|$(echo "$out" | tail -n 1)"
  ck "live: call order" "git add -- src/a.c|raise placeholder 3 --reason T9: x|update|debt_check debt|badges --write|badges --check|commit_task T9 x src/a.c config/debt-baseline.txt docs/badges" \
    "$(sed -e 's/^raise debt --raise/raise/' -e 's/^update debt --update/update/' "$scr/log" | paste -sd'|' -)"
  local step var
  for step in stage:git update:update check:debt_check badges:badges commit:commit_task; do
    var=${step#*:}; : > "$scr/log"
    out=$(env "STUB_RC_$var=3" bash -c 'PY=bash PATH="$1/bin:$PATH" STUB_LOG="$1/log" bash "$2" T9 x src/a.c 2>&1' _ "$scr" "$t"); rc=$?
    ck "live: stop at ${step%%:*}" "3|BANK-CLOSE FAIL ${step%%:*} rc=3" "$rc|$(echo "$out" | tail -n 1)"
  done
  : > "$scr/log"; out=$(export STUB_NO_OK=1; run T9 x src/a.c); rc=$?
  ck "live: debt rc 0 without DEBT CHECK OK stops" "1|BANK-CLOSE FAIL check rc=1|3" "$rc|$(echo "$out" | tail -n 1)|$(wc -l < "$scr/log" | tr -d ' ')"
  # 5 --paths-from: a list file gives the same commands as argv; bad lists rejected, nothing run
  printf '# wave W9 bank list\n\nsrc/a.c\n  config/b c.txt  \n# end\n' > "$scr/list.txt"
  ck "list file = argv (dry-run)" \
    "$(run --dry-run T9 "bank func_X pin-free" placeholder 3 src/a.c "config/b c.txt")" \
    "$(run --dry-run T9 "bank func_X pin-free" placeholder 3 --paths-from "$scr/list.txt")"
  : > "$scr/log"; out=$(run T9 x --paths-from "$scr/list.txt"); rc=$?
  ck "list file live: stage carries the list" "0|git add -- src/a.c config/b c.txt" "$rc|$(head -n 1 "$scr/log")"
  printf '# only comments\n\n' > "$scr/empty.txt"; printf 'src/a.c\n-x\n' > "$scr/dash.txt"; : > "$scr/log"
  run T9 x --paths-from "$scr/empty.txt" > /dev/null; ck "reject empty list" 2 "$?"
  run T9 x --paths-from "$scr/dash.txt" > /dev/null; ck "reject list line starting with -" 2 "$?"
  run T9 x --paths-from "$scr/nope.txt" > /dev/null; ck "reject missing list" 2 "$?"
  run T9 x --paths-from "$scr/list.txt" src/c.c > /dev/null; ck "reject list plus argv paths" 2 "$?"
  run --rises > /dev/null; ck "reject --rises without paths" 2 "$?"
  ck "list errors ran nothing" "" "$(cat "$scr/log")"
  # 6 --rises, real floor on the real tree: a planted wave of three new func_ bodies (untracked) rises placeholder 3
  local plant="$ROOT/src/zz_bank_close_selftest" w
  if [ -e "$plant" ]; then echo "  FAIL plant dir exists: $plant"; fails=$((fails + 1)); else
    trap 'rm -rf "$plant"' EXIT
    mkdir -p "$plant"
    for w in A B C; do printf 'void func_DEADBE%s0(void) {\n}\n' "$w" > "$plant/w_$w.c"; done
    printf '# planted wave\nsrc/zz_bank_close_selftest/w_A.c\nsrc/zz_bank_close_selftest/w_B.c\nsrc/zz_bank_close_selftest/w_C.c\n' \
      > "$scr/wave.txt"
    out=$(bash "$here" --rises --paths-from "$scr/wave.txt" 2>&1); rc=$?
    ck "rises: planted wave of 3 untracked func_ bodies" "0|RISE placeholder +3 (down)|BANK-RISES placeholder 3 other none" \
      "$rc|$(grep '^RISE ' <<< "$out" | paste -sd'|' -)|$(echo "$out" | tail -n 1)"
    out=$(bash "$here" --rises src/zz_bank_close_selftest/w_A.c 2>&1); rc=$?
    ck "rises: argv path, one body" "0|BANK-RISES placeholder 1 other none" "$rc|$(echo "$out" | tail -n 1)"
    rm -rf "$plant"; trap - EXIT
  fi
  out=$(bash "$here" --rises HOW_WE_WORK.md 2>&1); rc=$?
  ck "rises: unchanged path rises nothing" "0|BANK-RISES placeholder 0 other none" "$rc|$(echo "$out" | tail -n 1)"
  out=$(bash "$here" --rises src/zz_bank_close_selftest/none.c 2>&1); rc=$?
  ck "rises: unknown path fails at stage" "1|BANK-RISES FAIL stage" "$rc|$(echo "$out" | tail -n 1)"
  # 7 the real tree untouched
  ck "git HEAD, status, index and baseline untouched" "$before_head|$before_base|$before_index|$before_stat" \
    "$(git -C "$ROOT" rev-parse HEAD)|$(cksum < "$ROOT/config/debt-baseline.txt")|$(cksum < "$(git -C "$ROOT" rev-parse --absolute-git-dir)/index")|$(git -C "$ROOT" status --porcelain)"
  rm -rf "$scr"
  if [ "$fails" -eq 0 ]; then echo "BANK-CLOSE SELF-TEST OK"; return 0; fi
  echo "BANK-CLOSE SELF-TEST FAIL $fails"; return 1
}

[ "${1:-}" = --self-test ] && { [ $# -eq 1 ] || die "--self-test takes no arguments"; self_test; exit $?; }
if [ "${1:-}" = --rises ]; then
  shift; [ $# -ge 1 ] || die "usage: bank_close.sh --rises (<path>... | --paths-from <file>)"
  take_paths "$@"; rises; exit $?
fi

DRY=0
[ "${1:-}" = --dry-run ] && { DRY=1; shift; }
[ $# -ge 3 ] || die "usage: bank_close.sh [--dry-run] <TaskId> \"<line>\" [placeholder <n> [--reason <text>]] (<path>... | --paths-from <file>)"
TASK=$1 LINE=$2; shift 2
[[ "$TASK" =~ ^[A-Za-z0-9][A-Za-z0-9._-]*$ ]] || die "bad TaskId: '$TASK'"
[ -n "$LINE" ] || die "empty commit line"
[[ "$LINE" == *$'\n'* ]] && die "commit line must be one line"
[ ${#LINE} -le 100 ] || die "commit line over 100 chars (${#LINE})"
RAISE="" REASON=""
if [ "${1:-}" = placeholder ]; then
  [ $# -ge 2 ] && [[ "$2" =~ ^[1-9][0-9]*$ ]] || die "placeholder needs a positive count"
  RAISE=$2; shift 2
  if [ "${1:-}" = --reason ]; then [ $# -ge 2 ] && [ -n "$2" ] || die "--reason needs text"; REASON=$2; shift 2; fi
  [ -n "$REASON" ] || REASON="$TASK: $LINE"
fi
[ $# -ge 1 ] || die "no bank paths"
take_paths "$@"

NAMES=() CMDS=()
add() { local name=$1 q; shift; printf -v q '%q ' "$@"; NAMES+=("$name"); CMDS+=("${q% }"); }
add stage git add -- "${PATHS[@]}"
[ -n "$RAISE" ] && add raise "$PY" tools/psxd_floor.py debt --raise placeholder "$RAISE" --reason "$REASON"
add update "$PY" tools/psxd_floor.py debt --update
add check "$PY" tools/psxd_floor.py debt
add badges "$PY" tools/mmx6/badges.py --write
add bcheck "$PY" tools/mmx6/badges.py --check
add commit bash tools/commit_task.sh "$TASK" "$LINE" "${PATHS[@]}" config/debt-baseline.txt docs/badges

if [ "$DRY" -eq 1 ]; then printf '%s\n' "${CMDS[@]}"; exit 0; fi

cd "$ROOT" || exit 2
n=${#CMDS[@]}
for ((i = 0; i < n; i++)); do
  echo "BANK-CLOSE $((i + 1))/$n ${NAMES[$i]}: ${CMDS[$i]}"
  out=$(eval "${CMDS[$i]}" 2>&1); rc=$?
  [ -n "$out" ] && printf '%s\n' "$out"
  if [ "$rc" -eq 0 ] && [ "${NAMES[$i]}" = check ] && ! grep -q 'DEBT CHECK OK' <<< "$out"; then
    echo "bank_close: debt rc 0 but no 'DEBT CHECK OK' line"; rc=1
  fi
  [ "$rc" -eq 0 ] || { echo "BANK-CLOSE FAIL ${NAMES[$i]} rc=$rc"; exit "$rc"; }
done
echo "BANK-CLOSE OK $n steps"
