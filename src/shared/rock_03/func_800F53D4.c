#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
extern M2C_UNK D_8007433C;

void func_800F53D4(u8* arg0) {
    *(s32*)(arg0 + 0x20) = 0;
    *(s32*)(arg0 + 0x24) = 0;
    set_animation(arg0, 8);
    play_sound(2, 0x21, arg0);
    *(s32*)(arg0 + 0x50) = 0;
    *(s32**)(arg0 + 0x58) = &D_8007433C;
    *(s16*)(arg0 + 0x7C) = 0;
    arg0[6]++;
}
