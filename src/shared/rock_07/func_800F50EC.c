#include "common.h"

#define M2C_UNK s32

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
s32 random_byte();
void func_800F6A1C(void* arg0, s32 arg1);

void func_800F50EC(void* arg0) {
    s8 mode = ((s8*)arg0)[0x45];
    u8 r;

    if (mode == 1) {
        r = (u32)random_byte() % 3;
        if (r != mode) {
            switch (r) {
            case 0:
                play_sound(2, 0x22, arg0);
                break;
            case 1:
                break;
            case 2:
                goto two;
            }
        } else {
            play_sound(2, 0x23, arg0);
            if (0) {
            two:
                play_sound(2, 0x24, arg0);
            }
        }
        play_sound(2, 0x5D, arg0);
        func_800F6A1C(arg0, 0);
    } else if (mode == 2) {
        ((void (*)(void*, s32))set_animation)(arg0, 6);
        ((u8*)arg0)[6]++;
    }
}
