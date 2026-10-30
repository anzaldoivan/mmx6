#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
void func_800EAB3C(u8* arg0, u8 arg1);

void func_800EA66C(u8* arg0) {
    s8 t;

    if (--*(s16*)(arg0 + 0x7C) == 0) {
        play_sound(2, 7, arg0);
        t = arg0[2];
        if (t == 0) {
            func_800EAB3C(arg0, 2);
        } else if (t == 1) {
            func_800EAB3C(arg0, 3);
        }
        *(u16*)(arg0 + 0x7C) = 0x14;
        arg0[6]++;
    }
}
