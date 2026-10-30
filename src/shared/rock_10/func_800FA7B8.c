#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);

void func_800FA7B8(u8* arg0) {
    s8 temp_v1;
    u8* temp_s0;

    temp_v1 = *(s8*)(arg0 + 0x45);
    temp_s0 = *(u8**)(arg0 + 0x50);
    if (temp_v1 == 2) {
        play_sound(2, 0x4F, arg0);
        temp_s0[7] = 1;
    } else if (temp_v1 == 1) {
        arg0[3] = 0;
        arg0[4] = arg0[4] + 1;
    }
}
