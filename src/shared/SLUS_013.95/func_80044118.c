#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_80017A04();
void func_80043B90(s8* arg0, s16 arg1);

void func_80044118(s8* arg0) {
    s16 t;

    if ((*(u8**)(arg0 + 0x7C))[0x93] & 2) {
        ((void (*)(void*, s32))set_animation)(arg0, 2);
        arg0[5] = 7;
        return;
    }
    ((void (*)())func_80017A04)(arg0);
    if (arg0[0x98] != 0) {
        arg0[0x98] = 0;
        t = ++*(u16*)(arg0 + 0x8A);
        if (t >= 3) {
            ((void (*)(void*, s32))set_animation)(arg0, 5);
            *(s32*)(arg0 + 0x50) = 0;
            arg0[5]++;
            return;
        }
    }
    func_80043B90(arg0, (*(u8*)(arg0 + 0x15) == 0) << 11);
}
