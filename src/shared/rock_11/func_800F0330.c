#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179D0(void*, M2C_UNK, s8);
void func_800F40F4(u8* arg0, u8 arg1, s16 arg2, s16 arg3);
extern struct X4_BackgroundObj background_objects[3];
extern s32 D_800FCB9C;

#define F(type, off) M2C_FIELD(arg0, type*, off)

void func_800F0330(void* arg0) {
    s32 x;
    s32 y;
    s16 i;
    s16 j;

    F(u8, 0x3) = 1;
    x = ((s16)(F(u16, 0x8C) - background_objects[0].x_pos.u.hi) - 0xA0) *
            F(s16, 0x88) / 39 +
        0xA0;
    y = ((s16)(F(u16, 0x8E) - background_objects[0].y_pos.u.hi) - 0x38) *
            F(s16, 0x88) / 39 +
        0x38;
    F(s16, 0xA) = x;
    F(s16, 0xE) = y;
    ((void (*)(void*, s32, s16))func_800179D0)(arg0, 0x20, F(s16, 0x88) / 3);
    j = F(s16, 0x88);
    for (i = 0; i < 5; i++) {
        j -= 2;
        if (j >= 0) {
            func_800F40F4(arg0, 3, j, 1);
        }
    }
    if (F(s16, 0x88) == 0x27) {
        F(void*, 0x50) = &D_800FCB9C;
        F(s16, 0x88) = 0;
        F(u8, 0x14) = 0;
        F(s16, 0xA) = F(s16, 0x8C);
        F(s16, 0xE) = F(s16, 0x8E);
        F(u8, 0x6)++;
        return;
    }
    F(s16, 0x88)++;
}
