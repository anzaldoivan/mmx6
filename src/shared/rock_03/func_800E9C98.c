#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
extern u8 D_800CCF38;
extern u8 D_800F6CBC[];
extern u8 D_800F6CC0[];
extern u8 D_800F70C4[];
#define SPAD4C (*(u8**)0x1F80004C)

void func_800E9C98(u8* arg0) {
    s8 t = arg0[2];

    if (t == 0) {
        SPAD4C[0x81] = 0x1A - D_800F70C4[(s8)arg0[0x45] - 1];
        SPAD4C[0x83] = D_800F70C4[(s8)arg0[0x45] - 1];
    } else if (t == 1) {
        ((s8*)SPAD4C)[0x81] = -0x1E;
        SPAD4C[0x83] = D_800F70C4[(s8)arg0[0x45] - 1];
    }
    if ((s8)arg0[0x45] == 0x1C) {
        s8 s = arg0[2];
        *(u8**)(arg0 + 0x50) = D_800F6CBC;
        *(u8**)(arg0 + 0x54) = D_800F6CC0;
        if (s == 0) {
            ((void (*)(void*, s32))set_animation)(arg0, 4);
        } else if (s == 1) {
            ((void (*)(void*, s32))set_animation)(arg0, 0x12);
        }
        if (D_800CCF38 >= 2) {
            *(s16*)(arg0 + 0x7C) = 0xF;
        } else {
            *(s16*)(arg0 + 0x7C) = 0x1E;
        }
        arg0[6]++;
    }
}

#undef SPAD4C
