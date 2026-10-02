#!/bin/sh
# toolchain_check.sh SPLAT_PIN BINUTILS_PIN CPP_PIN CC1_SET MASPSX_PIN M2C_PIN ASMDIFFER_PIN GCCSRC_SHA GCCSRC_TREE
#   GCCSRC_PATCHES PERMUTER_PIN — print each tool's version,
# compare to its pin (version string only, not the banner); rc 1 on any mismatch, a missing tool counts as a mismatch.
# Each cc1 of CC1_SET (/opt/cc/<name>/cc1) must report version <name> minus its suffix and pass a cpp|cc1|maspsx|as
# smoke compile; maspsx (/opt/maspsx), m2c (/opt/m2c) and asm-differ (/opt/asm-differ) must be at their commit pins;
# decomp-permuter (/opt/decomp-permuter) at PERMUTER_PIN, printed `PERMUTER <sha>`.
# /opt/gcc-2.95.2-src (cc1 2.95.2-psx source) must carry a stamp naming the tarball pin and GCCSRC_PATCHES patches, and
# hash to GCCSRC_TREE (sorted `find -type f` minus the stamp → sha256sum → sha256); missing tree = drift.
# Called by `make toolchain-check`.
splat_pin=$1 binutils_pin=$2 cpp_pin=$3 cc1_set=$4 maspsx_pin=$5 m2c_pin=$6 asmdiffer_pin=$7
gccsrc_sha=$8 gccsrc_tree=$9 gccsrc_patches=${10} permuter_pin=${11}
rc=0
# ver <cmd...>: first dotted version number in the `--version` output (banner text skipped).
ver() { "$@" --version 2>/dev/null | grep -oE '[0-9]+(\.[0-9]+)+' | head -n1; }
check() {
    name=$1 pin=$2; shift 2
    v=$(ver "$@")
    if [ "$v" = "$pin" ]; then echo "ok    $name $v"; else echo "DRIFT $name ${v:-missing} (pin $pin)"; rc=1; fi
}
check splat "$splat_pin" splat
check mipsel-linux-gnu-as "$binutils_pin" mipsel-linux-gnu-as
check mipsel-linux-gnu-ld "$binutils_pin" mipsel-linux-gnu-ld
check mipsel-linux-gnu-objcopy "$binutils_pin" mipsel-linux-gnu-objcopy
check mipsel-linux-gnu-cpp "$cpp_pin" mipsel-linux-gnu-cpp
# cc1 set: `cc1 -version` on empty stdin, then a smoke compile of a division (exercises maspsx --expand-div).
scratch=/work/.run/toolchain-check.$$
mkdir -p "$scratch" && echo 'int f(int a,int b){return a/b;}' > "$scratch/t.c"
for name in $cc1_set; do
    cc1=/opt/cc/$name/cc1 want=${name%%-*}
    v=$("$cc1" -version </dev/null 2>&1 | grep -m1 'GNU C version' | grep -oE '[0-9]+(\.[0-9]+)+' | head -n1)
    rm -f "$scratch/t.o"
    mipsel-linux-gnu-cpp -undef -D__GNUC__=2 -DPSX "$scratch/t.c" 2>/dev/null \
        | "$cc1" -quiet -O2 -G0 -funsigned-char -msoft-float 2>/dev/null \
        | maspsx --aspsx-version=2.56 --expand-div \
        | mipsel-linux-gnu-as -EL -march=r3000 -mabi=32 -G0 -o "$scratch/t.o" 2>/dev/null
    smoke=$?
    if [ "$v" = "$want" ] && [ $smoke -eq 0 ] && [ -s "$scratch/t.o" ] \
        && mipsel-linux-gnu-nm "$scratch/t.o" | grep -q ' T f$'; then echo "ok    cc1 $name $v smoke"
    else echo "DRIFT cc1 $name ${v:-missing} (want $want; smoke rc $smoke)"; rc=1; fi
done
rm -rf "$scratch"
m=$(git -C /opt/maspsx rev-parse HEAD 2>/dev/null)
if [ -n "$m" ] && [ "$m" = "$maspsx_pin" ]; then echo "ok    maspsx $m"; else echo "DRIFT maspsx ${m:-missing} (pin $maspsx_pin)"; rc=1; fi
# commit <name> <dir> <pin>: the clone at <dir> must be checked out at <pin>.
commit() {
    c=$(git -C "$2" rev-parse HEAD 2>/dev/null)
    if [ -n "$c" ] && [ "$c" = "$3" ]; then echo "ok    $1 $c"; else echo "DRIFT $1 ${c:-missing} (pin $3)"; rc=1; fi
}
commit m2c /opt/m2c "$m2c_pin"
commit asm-differ /opt/asm-differ "$asmdiffer_pin"
p=$(git -C /opt/decomp-permuter rev-parse HEAD 2>/dev/null)
if [ -n "$p" ] && [ "$p" = "$permuter_pin" ]; then echo "PERMUTER $p"; else echo "DRIFT permuter ${p:-missing} (pin $permuter_pin)"; rc=1; fi
src=/opt/gcc-2.95.2-src stamp=/opt/gcc-2.95.2-src/.mmx6-gccsrc
if [ -f "$stamp" ]; then
    t=$(sed -n 's/^tarball //p' "$stamp"); k=$(grep -c '^patch ' "$stamp")
    d=$(cd "$src" && find . -type f ! -path ./.mmx6-gccsrc -print0 | LC_ALL=C sort -z | xargs -0 sha256sum | sha256sum)
    d=${d%% *}
else t=missing k=0 d=missing; fi
if [ "$t" = "$gccsrc_sha" ] && [ "$k" = "$gccsrc_patches" ] && [ "$d" = "$gccsrc_tree" ]; then
    echo "GCCSRC 2.95.2 $t patches $k"
else echo "DRIFT gccsrc tarball $t patches $k tree $d (pin $gccsrc_sha patches $gccsrc_patches tree $gccsrc_tree)"; rc=1; fi
exit $rc
