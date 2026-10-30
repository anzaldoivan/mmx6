#include "common.h"

extern u16 g_pad1_buttons[];
s32 play_sound(s32 a0, s32 a1, void* arg2);

void func_8001F5A0(void* arg0, s32 arg1) {
    if (g_pad1_buttons[2] & 0x1000) {
        play_sound(0, 0xC, 0);
        if (*(s8*)arg0 == 0) {
            *(s8*)arg0 = arg1;
        } else {
            *(s8*)arg0 = *(s8*)arg0 - 1;
        }
    }
    if (g_pad1_buttons[2] & 0x4000) {
        play_sound(0, 0xC, 0);
        if (*(s8*)arg0 == arg1) {
            *(s8*)arg0 = 0;
            return;
        }
        *(s8*)arg0 = *(s8*)arg0 + 1;
    }
}
