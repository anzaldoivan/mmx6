#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern struct X4_BackgroundObj background_objects[3];

void func_800FA4AC(u8* arg0) {
    if (*(s16*)(arg0 + 4) >= 0x78) {
        background_objects[0].unk3 = 1;
        background_objects[0].x_pos.u.hi = 0;
        background_objects[0].y_pos.u.hi = 0x100;
        background_objects[0].unk4C = 1;
        arg0[1]++;
        return;
    }
    (*(s16*)(arg0 + 4))++;
}
