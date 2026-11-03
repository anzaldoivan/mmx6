#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK animate_object();

void func_800EC66C(u8* arg0) {
    u8 t;

    t = arg0[0x80];
    if (t != 0) {
        arg0[0x80] = --t;
        if (t == 0) {
            ((void (*)(void*, s32))set_animation)(arg0, 1);
        }
    } else {
        ((void (*)(void*))animate_object)(arg0);
        if (*(s8*)(arg0 + 0x45) != 0) {
            ((void (*)(void*, s32))set_animation)(arg0, 0);
            arg0[6] = 0;
            arg0[0x15] = (arg0[0x15] == 0) << 6;
            *(s32*)(arg0 + 0x20) = -*(s32*)(arg0 + 0x20);
        }
    }
}
