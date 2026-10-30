#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
extern u16 D_800C4570;
extern u8 D_800F1CC4[];

void func_800ECFE0(struct X4_EngineObj* arg0) {
    s32 t;
    s32 v;

    v = D_800C4570;
    if (v & 4) {
        play_sound(5, 0, 0);
        D_800F1CC4[4] = 2;
        D_800F1CC4[5] = 1;
        arg0->unk8 = 0;
        arg0->unkA = 0;
        arg0->unk1 = 7;
        arg0->unk2 = 0;
        t = 1;
    } else if (v & 8) {
        D_800F1CC4[4] = 1;
        D_800F1CC4[5] = 2;
        play_sound(5, 0, 0);
        t = 1;
        arg0->unk1 = 8;
        arg0->unk2 = 0;
        arg0->unk8 = 0;
    } else {
        t = 0;
    }
    if (t == 0) {
        arg0->unk8++;
        if ((s16)arg0->unk8 >= 0x3C) {
            arg0->unk1 = 6;
            arg0->unk2 = 0;
            arg0->unk8 = 0;
        }
    }
}
