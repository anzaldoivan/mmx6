#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
s32 random_byte();

void func_800F27B0(void* arg0) {
    ((void (*)(s32, s32, void*))play_sound)(2, (random_byte() & 1) | 0x22,
                                            arg0);
    ((void (*)(void*, s32))set_animation)(arg0, 1);
    ((u8*)arg0)[6] = ((u8*)arg0)[6] + 1;
}
