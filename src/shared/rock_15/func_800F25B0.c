#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);

void func_800F25B0(u8* arg0) {
    set_animation(arg0, 0);
    *(s32*)(arg0 + 0x24) = 0;
    *(s16*)(arg0 + 0x7C) = 0x3C;
    *(s16*)(arg0 + 0x7E) = 0;
    arg0[6]++;
}
