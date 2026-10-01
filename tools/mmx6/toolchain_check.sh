#!/bin/sh
# toolchain_check.sh SPLAT_PIN BINUTILS_PIN CPP_PIN CC1_SET MASPSX_PIN — print each tool's version, compare to its pin
# (version string only, not the banner); rc 1 on any mismatch, a missing tool counts as a mismatch. Each cc1 of CC1_SET
# (/opt/cc/<name>/cc1) must report version <name> minus its suffix and pass a cpp|cc1|maspsx|as smoke compile; maspsx
# (/opt/maspsx) must be at MASPSX_PIN. Called by `make toolchain-check`.
splat_pin=$1 binutils_pin=$2 cpp_pin=$3 cc1_set=$4 maspsx_pin=$5
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
exit $rc
