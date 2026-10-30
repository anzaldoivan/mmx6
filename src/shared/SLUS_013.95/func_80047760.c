#include "common.h"

s32 play_sound(s32 a0, s32 a1, void* arg2);
extern u8 D_800CCF38;

void func_80047760(u8* arg0) {
    if (--*(s16*)(arg0 + 0x14) == 0) {
        if (D_800CCF38 >= 2) {
            *(s32*)(arg0 + 0x18) = 0xFFFEC000;
        } else {
            *(s32*)(arg0 + 0x18) = 0xFFFF0000;
        }
        arg0[5] = 3;
        play_sound(2, 0x22, arg0);
        *(s32*)(arg0 + 0x1C) = *(s32*)(arg0 + 0x20);
    }
}
