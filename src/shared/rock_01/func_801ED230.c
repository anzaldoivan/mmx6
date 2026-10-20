#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8003BA04(void*, M2C_UNK);

void func_801ED230(u8* arg0) {
    s32 t;

    t = arg0[0xE1] + 1;
    arg0[0xE1] = t;
    if ((u32)(t & 0xFF) >= 0x47U) {
        ((void (*)(void*, s32))func_8003BA04)(arg0, 0x6F);
        arg0[6] = arg0[6] + 1;
    }
}
