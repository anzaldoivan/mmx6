#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80017A04();
void func_80043B90(s8* arg0, s16 arg1);
extern s32 D_80076108;

void func_8004431C(s8* arg0) {
    u8* t;
    s32 v;

    ((void (*)())func_80017A04)(arg0);
    t = *(u8**)(arg0 + 0x7C);
    if (!(t[0x93] & 2)) {
        ((void (*)(void*, s32))set_animation)(arg0, 1);
        *(s32**)(arg0 + 0x50) = &D_80076108;
        arg0[0x98] = 0;
        arg0[0x64] = 1;
        arg0[5] = 3;
    }
    v = (arg0[2] - 1) * 0x555 + 0xE00;
    func_80043B90(arg0, (*(u16*)(t + 0x94) + v) & 0xFFF);
}
