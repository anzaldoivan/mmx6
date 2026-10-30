#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80017A04();
extern s32 D_80076108;

void func_80044294(s8* arg0) {
    ((void (*)())func_80017A04)();
    if (arg0[0x46] == 0) {
        *(s32**)(arg0 + 0x50) = &D_80076108;
        arg0[0x98] = 0;
        *(s16*)(arg0 + 0x8A) = 0;
        arg0[0x64] = 1;
        if (!(*(*(u8**)(arg0 + 0x7C) + 0x93) & 2)) {
            ((void (*)(void*, s32))set_animation)(arg0, 1);
            arg0[5] = (u8)arg0[5] - 3;
        } else {
            ((void (*)(void*, s32))set_animation)(arg0, 2);
            arg0[5] = 7;
        }
    }
}
