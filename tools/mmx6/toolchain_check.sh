#!/bin/sh
# toolchain_check.sh SPLAT_PIN BINUTILS_PIN CPP_PIN — print each tool's version, compare to its pin (version string
# only, not the banner); rc 1 on any mismatch, a missing tool counts as a mismatch. Called by `make toolchain-check`.
splat_pin=$1 binutils_pin=$2 cpp_pin=$3
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
exit $rc
