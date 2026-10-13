#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80017A04();

void func_800EC66C(u8* arg0) {
    u8 t;

    t = arg0[0x80];
    if (t != 0) {
        arg0[0x80] = --t;
        if (t == 0) {
            ((void (*)(void*, s32))func_800179A4)(arg0, 1);
        }
    } else {
        ((void (*)(void*))func_80017A04)(arg0);
        if (*(s8*)(arg0 + 0x45) != 0) {
            ((void (*)(void*, s32))func_800179A4)(arg0, 0);
            arg0[6] = 0;
            arg0[0x15] = (arg0[0x15] == 0) << 6;
            *(s32*)(arg0 + 0x20) = -*(s32*)(arg0 + 0x20);
        }
    }
}
