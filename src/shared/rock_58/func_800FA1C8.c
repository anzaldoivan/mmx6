#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
extern s8 D_80097424;

void func_800FA1C8(u8* arg0) {
    if (D_80097424 == 0) {
        *(s16*)(arg0 + 8) = 0x20C;
        *(s16*)(arg0 + 0xA) = 0xB;
        play_sound(0, 7, 0);
        arg0[1] += 1;
    }
}
