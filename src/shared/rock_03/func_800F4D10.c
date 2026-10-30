#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
extern s16 D_800F7E0C;
extern s16 D_800F7E0E;

void func_800F4D10(u8* arg0) {
    if (D_800F7E0C == 0) {
        set_animation(arg0, 0);
        play_sound(2, 0x27, arg0);
        D_800F7E0E = 2;
        *(s16*)(arg0 + 0x7C) = 0;
        arg0[6]++;
    }
}
