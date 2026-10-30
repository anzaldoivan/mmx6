#include "common.h"
#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
s32 random_byte();
void func_800F9E00(u8* arg0, u8 arg1);

void func_800F8BC0(u8* arg0) {
    s8 state = arg0[0x45];

    if (state == 1) {
        if (random_byte() & 1) {
            play_sound(2, 0x22, arg0);
        } else {
            play_sound(2, 0x23, arg0);
        }
        play_sound(2, 0x4B, arg0);
        func_800F9E00(arg0, 0x10);
        func_800F9E00(arg0, 0x11);
    } else if (state == 2) {
        arg0[6]++;
    } else if (state == 3) {
        play_sound(2, 0x4A, arg0);
    }
}
