#include "common.h"
#define M2C_UNK s32

M2C_UNK set_animation(void*, M2C_UNK);
M2C_UNK func_800F1A90(void* self, u8 arg1);

void func_800F3A60(u8* arg0) {
    if (--*(s16*)(arg0 + 0x7C) == 0) {
        ((void (*)(void*, u8))func_800F1A90)(arg0, 0x30);
        ((void (*)(void*, s32))set_animation)(arg0, 0x3B);
        *(u16*)(arg0 + 0x7C) = 0x28;
        arg0[6] = arg0[6] + 1;
    }
}
