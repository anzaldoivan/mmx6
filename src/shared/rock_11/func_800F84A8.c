#include "common.h"

s32 func_800FA4F8(void* arg0, s16 arg1, s32 arg2);
extern u16 D_80097222;
#define CALL func_800FA4F8

void func_800F84A8(void* arg0, s32 arg1) {
    register s32 b asm("$2") = *((u8*)arg0 + 2);
    register s32 kind asm("$4") = b & 0xF;
    register s32 one asm("$3") = 1;
#define ONE one
    if (kind == ONE) {
        goto c1;
    }
    if (kind < 2) {
        if (kind == 0) {
            goto c0;
        }
        goto end;
    }
    if (kind == 2) {
        goto c2;
    }
    goto end;
c0:
    arg1 = CALL((u8*)arg0 + 0xC, D_80097222 + 0xF2, 0x50000);
    goto end;
c1:
    arg1 = CALL((u8*)arg0 + 0xC, D_80097222 + 0xC2, 0x50000);
    goto end;
c2:
    arg1 = CALL((u8*)arg0 + 0xC, D_80097222 + 0x92, 0x50000);
end:
    if (arg1 != 0) {
        *(s16*)((u8*)arg0 + 0x7C) = 0xE10;
        *((u8*)arg0 + 5) += 1;
    }
}
