#include "common.h"

#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);

void func_800F2998(s8* arg0) {
    if (arg0[7] == 0) {
        set_animation(arg0, 5);
        play_sound(2, 0x14, arg0);
        ((u8*)arg0)[6] = ((u8*)arg0)[6] + 1;
    }
}
