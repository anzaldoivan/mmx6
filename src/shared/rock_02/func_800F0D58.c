#include "common.h"
#define M2C_UNK s32
#define SPAD20_800F0D58 (*(s32*)0x1F800020)

M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002A47C(s32);

void func_800F0D58(s8* arg0) {
    s32 t;

    if (arg0[0x46] == 0) {
        *(s32*)(arg0 + 0x2C) = 0x6000;
        t = func_8002A47C(arg0[1]);
        *(s32*)(arg0 + 0x3C) =
            SPAD20_800F0D58 + *(s32*)(t * 4 + SPAD20_800F0D58 + 4);
        ((void (*)(void*, s32))set_animation)(arg0, 7);
        arg0[6]++;
    }
}
#undef SPAD20_800F0D58
