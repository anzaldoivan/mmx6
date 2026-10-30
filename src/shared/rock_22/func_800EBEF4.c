#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
extern s8 D_800970A5;
extern struct X4_BackgroundObj background_objects[3];

void func_800EBEF4(struct X4_MainObj* arg0) {
    if ((D_800970A5 == 0x14) &&
        (background_objects[0].unk26 == background_objects[0].unk1E)) {
        background_objects[1].unk3 = 1;
        arg0->unk7C = 0;
        arg0->unk7E = 0xA;
        arg0->unk6++;
        play_sound(5, 1, arg0);
        ((void (*)(s32))func_80012D9C)(4);
    }
}
