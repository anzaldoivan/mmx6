#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);

void func_801ED150(u8* arg0) {
    if (arg0[0x45] & 0x40) {
        arg0[0xE1] = 0;
        arg0[6]++;
        play_sound(1, 0x1C, arg0);
    }
}
