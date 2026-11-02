#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
extern s16 D_800F7E0C;
extern s16 D_800F7E0E;

void func_800F52F4(void* arg0) {
    if (D_800F7E0C == 0) {
        ((void (*)(void*, s32))set_animation)(arg0, 2);
        play_sound(2, 0x27, arg0);
        D_800F7E0E = 6;
        *(s16*)((u8*)arg0 + 0x8E) = 0;
        *(s16*)((u8*)arg0 + 0x7C) = 0;
        *((u8*)arg0 + 6) += 1;
    }
}
