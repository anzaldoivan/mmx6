#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179D0(void*, M2C_UNK, s8);
extern struct X4_BackgroundObj background_objects[3];

#define F(type, off) M2C_FIELD(arg0, type*, off)

void func_800F1048(void* arg0) {
    struct X4_BackgroundObj* bg;
    s16 k;
    s32 x;
    s32 y;

    bg = background_objects;
    F(s8, 0x3) = 1;
    x = (s16)(F(s16, 0x8) - bg->x_pos.i.hi) - 0xA0;
    k = F(s16, 0x54);
    x *= k;
    y = ((s16)(F(s16, 0xC) - bg->y_pos.i.hi) - 0x38) * k;
    F(s16, 0xA) = x / 39 + 0xA0;
    F(s16, 0xE) = y / 39 + 0x38;
    ((void (*)(void*, s32, s16))func_800179D0)(arg0, 0x20, F(s16, 0x54) / 3);
    if (F(s16, 0x56) == 0) {
        F(u8, 0x4)++;
    } else {
        F(s16, 0x56)--;
    }
}
