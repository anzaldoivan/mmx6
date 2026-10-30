#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define SPAD (*(u8**)0x1F80004C)

M2C_UNK set_animation(void*, M2C_UNK);
s32 random_byte();
void func_800EBC20(struct X4_MainObj* self);
extern struct X4_BackgroundObj background_objects[3];
extern s32 D_800F7180;
extern s32 D_800F7184;
extern u16 D_800F72AC[];

void func_800EB9C8(u8* arg0) {
    s32 i;

    if ((s16)-- * (u16*)(arg0 + 0x7C) == -1) {
        *(u16*)(SPAD + 0x8A) = *(u16*)(arg0 + 0xA);
        *(u16*)(SPAD + 0x8C) = *(u16*)(arg0 + 0xE);
        SPAD[0x88] = 3;
        set_animation(arg0, 4);
        i = random_byte() & 0xF;
        *(u16*)(arg0 + 0xA) =
            background_objects[0].x_pos.i.hi + D_800F72AC[i * 2];
        *(u16*)(arg0 + 0xE) =
            background_objects[0].y_pos.i.hi + D_800F72AC[(i * 2) | 1];
        func_800EBC20((struct X4_MainObj*)arg0);
        *(s32**)(arg0 + 0x54) = &D_800F7184;
        *(s32**)(arg0 + 0x50) = &D_800F7180;
        arg0[6]++;
    }
}
