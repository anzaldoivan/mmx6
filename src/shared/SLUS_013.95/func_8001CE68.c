#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

s32 play_sound(s32 a0, s32 a1, void* arg2);
extern u16 g_pad1_buttons[];
extern s32 D_800E3130[];

void func_8001CE68(struct X4_EngineObj* arg0) {
    switch (D_800E3130[1]) {
    case 0:
    case 1:
    case 2:
        if (g_pad1_buttons[2] & 4) {
            D_800E3130[1]++;
        } else if (g_pad1_buttons[2] & 8) {
            D_800E3130[1] = 0;
        }
        break;
    case 3:
        if (g_pad1_buttons[2] & 2) {
            play_sound(0, 0x22, 0);
            D_800E3130[0] = 0;
            D_800E3130[1]++;
        } else if (g_pad1_buttons[2] & 4) {
            D_800E3130[1] = 0;
        }
        break;
    }
    if (g_pad1_buttons[2] & 0x5000) {
        D_800E3130[1] = 0;
    }
    if (arg0->unk2 != 0) {
        D_800E3130[1] = 0;
    }
}
