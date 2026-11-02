#include "common.h"
#include "psyq/libspu.h"

extern u8* D_80097780;

s32 func_800175F0(u8 arg0) {
    u8* p = D_80097780 + arg0 * 4;
    return SpuGetKeyStatus(1 << (p[3] & 0x1F)) == 0;
}

// clang-format off
INCLUDE_ASM("asm/SLUS_013.95/nonmatchings/120A0", func_80017630);
// clang-format on
