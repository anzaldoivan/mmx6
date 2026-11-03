#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK apply_object_motion(void*);

void func_800F4DFC(u8* arg0) {
    ((void (*)(void*))apply_object_motion)(arg0);
    if (arg0[0x70] & 8) {
        ((void (*)(void*, s32))set_animation)(arg0, 0x26);
        arg0[6] = arg0[6] + 1;
    }
}
