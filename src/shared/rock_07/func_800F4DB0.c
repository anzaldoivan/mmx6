#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK apply_object_motion(void*);

void func_800F4DB0(u8* arg0) {
    ((void (*)(void*))apply_object_motion)(arg0);
    if (*(s32*)(arg0 + 0x24) <= 0) {
        ((void (*)(void*, s32))set_animation)(arg0, 0xE);
        arg0[6] = arg0[6] + 1;
    }
}
