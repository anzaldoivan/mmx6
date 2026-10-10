#include "common.h"

#define M2C_UNK s32

s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
extern s8 D_80097180;
extern void (*D_800F3DBC[])(s8*);

void func_800EA8E8(s8* arg0) {
    *(s32*)(arg0 + 0x18) = *(s32*)(arg0 + 8);
    *(s32*)(arg0 + 0x1C) = *(s32*)(arg0 + 0xC);
    if (D_80097180 != 2 && func_8002CBFC(arg0, 0x40, 0xF0) != 1) {
        D_800F3DBC[arg0[4]](arg0);
    }
}
