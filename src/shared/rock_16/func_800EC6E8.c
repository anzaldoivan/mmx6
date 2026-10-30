#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
extern u16 g_pad1_buttons[];
extern s8 D_800CCEFB;
extern u8 D_800F1CC4[];
extern s8 D_800F1CCA[];

void func_800EC6E8(struct X4_EngineObj* arg0) {
    // !FAKE: depin: dropping it breaks the match (89/92)
    register s32 v asm("$3");

    if (g_pad1_buttons[2] & 0x5000) {
        play_sound(5, 0, 0);
        D_800F1CC4[2] = 1;
        D_800F1CC4[3] = 1;
        if (g_pad1_buttons[2] & 0x1000) {
            D_800F1CCA[0] = 2;
            D_800F1CCA[1] = 1;
            arg0->unk3 = D_800CCEFB;
            if (arg0->unk3 == 0) {
                arg0->unk3 = 7;
            } else {
                arg0->unk3 = arg0->unk3 - 1;
            }
        } else {
            D_800F1CCA[0] = 1;
            D_800F1CCA[1] = 2;
            arg0->unk3 = D_800CCEFB;
            if (arg0->unk3 >= 7) {
                arg0->unk3 = 0;
            } else {
                arg0->unk3 = arg0->unk3 + 1;
            }
        }
        arg0->unk8 = 0;
        arg0->unk2++;
        return;
    }
    if (g_pad1_buttons[2] & 4) {
        D_800F1CC4[2] = 2;
        D_800F1CC4[3] = 1;
        play_sound(5, 0, 0);
        v = 8;
    } else if (g_pad1_buttons[2] & 8) {
        D_800F1CC4[2] = 1;
        D_800F1CC4[3] = 2;
        play_sound(5, 0, 0);
        v = 5;
    } else {
        return;
    }
    arg0->unk1 = v;
    arg0->unk2 = 0;
    arg0->unk8 = 0;
}
