#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);

void func_800F9D88(u8* arg0) {
    if (((s8*)arg0)[0x45] == 1) {
        set_animation(arg0, 2);
        play_sound(2, 0x66, arg0);
        arg0[5]++;
    }
}
