#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);

void func_800F5D00(u8* arg0) {
    set_animation(arg0, 6);
    play_sound(2, 0x22, arg0);
    arg0[6]++;
}
