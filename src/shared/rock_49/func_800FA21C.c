#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
extern struct X4_BackgroundObj background_objects[3];
extern s8 D_80097424;

void func_800FA21C(struct X4_BackgroundObj* arg0) {
    if (D_80097424 == 0) {
        *(s16*)&arg0->unk4 = 0;
        background_objects[1].x_pos.u.hi = 0x120;
        background_objects[1].y_pos.u.hi = 0;
        background_objects[1].unk4C = 1;
        background_objects[1].unk3 = 1;
        background_objects[0].x_pos.u.hi = 0;
        background_objects[0].y_pos.u.hi = 0;
        background_objects[0].unk4C = 1;
        background_objects[0].unk3 = 1;
        func_80016C48(0, 1, 0);
        arg0->unk1++;
    }
}
