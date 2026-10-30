#include "common.h"
#include "mmx6/x4.h"

s32 play_sound(s32, s32, void*);
void func_800139F4(s32);
extern s32 D_80097420;
extern u16 g_pad1_buttons[];

void func_8001F778(struct X4_GameInfo* arg0) {
    s8* p = (s8*)&D_80097420;
    s8* q;
    s16 max;

    if (p[4] == 0) {
        q = p + 7;
        max = arg0->unk8;
        if (g_pad1_buttons[2] & 0x1000) {
            play_sound(0, 0xC, 0);
            if (p[7] == 0) {
                p[7] = max;
            } else {
                p[7]--;
            }
        }
        if (g_pad1_buttons[2] & 0x4000) {
            play_sound(0, 0xC, 0);
            if (*q == max) {
                *q = 0;
            } else {
                (*q)++;
            }
        }
        if (g_pad1_buttons[2] & 0x40) {
            play_sound(0, 0x22, 0);
            func_800139F4(8);
            arg0->mode++;
        }
    }
}
