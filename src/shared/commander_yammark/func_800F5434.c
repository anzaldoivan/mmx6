#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
extern M2C_UNK D_80074BFC;
extern M2C_UNK D_800F7954;
extern s32 D_800F7DE8;

void func_800F5434(u8* arg0) {
    if (++*(s16*)(arg0 + 0x7C) == 0x5A) {
        D_800F7DE8 = 0;
        ((void (*)(void*, M2C_UNK))set_animation)(arg0, 0);
        *(void**)(arg0 + 0x50) = &D_800F7954;
        *(void**)(arg0 + 0x58) = &D_80074BFC;
        arg0[5] = 4;
        arg0[6] = 0;
    }
}
