#!/usr/bin/env bash
# compile.sh <in.c> -o <out.o> — the permuter's compile command (container). tools/mmx6/permute.py copies it into
# .run/permute/<func>/ (<permdir>); decomp-permuter runs it as `bash <permdir>/compile.sh <tmp.c> -o <tmp.o>`.
# Appends the input's sha256 to <permdir>/sources.log, then compiles through the product C rule from the repo root
# (`make -s -B build/<permdir>/cc/cand.c.o`, as tools/mmx6/probe.py compile_obj does) and copies the object to
# <out.o>; make output in <permdir>/cc/make.log (to stderr on failure). Serial use only (permuter -j1).
# <permdir>/cflags (written by permute.py when the draft's TU carries a CFLAGS_<tu> override) becomes CFLAGS_cand.
set -euo pipefail
[[ $# -eq 3 && $2 == -o ]] || { echo "usage: compile.sh <in.c> -o <out.o>" >&2; exit 2; }
in=$(cd "$(dirname "$1")" && pwd)/$(basename "$1")
out=$(cd "$(dirname "$3")" && pwd)/$(basename "$3")
permdir=$(cd "$(dirname "$0")" && pwd)
root=$permdir
while [[ ! -f $root/Makefile || ! -d $root/tools/mmx6 ]]; do
    [[ $root != / ]] || { echo "compile.sh: no repo root above $permdir" >&2; exit 2; }
    root=$(dirname "$root")
done
rel=${permdir#"$root"/}
sha256sum "$in" | cut -d' ' -f1 >> "$permdir/sources.log"
mkdir -p "$permdir/cc"
cp "$in" "$permdir/cc/cand.c"
cd "$root"
over=()
[[ ! -f $permdir/cflags ]] || over=("CFLAGS_cand=$(<"$permdir/cflags")")
make -s -B "build/$rel/cc/cand.c.o" ${over[@]+"${over[@]}"} >"$permdir/cc/make.log" 2>&1 || { cat "$permdir/cc/make.log" >&2; exit 1; }
cp "build/$rel/cc/cand.c.o" "$out"
