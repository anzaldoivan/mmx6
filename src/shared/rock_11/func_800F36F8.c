#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation_frame(void*, M2C_UNK, s8);
s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
extern s32 D_80097420;

#define F(type, off) M2C_FIELD(arg0, type*, off)

void func_800F36F8(void* arg0) {
    switch (F(u8, 0x2) & 0xF) {
    case 1:
        ((void (*)(void*, s32, s32))set_animation_frame)(arg0, 0x25, D_80097420 & 1);
        F(s16, 0xA) += 6;
        break;
    case 2:
        ((void (*)(void*, s32, s32))set_animation_frame)(arg0, 0x21, D_80097420 & 1);
        F(s16, 0xE) -= 6;
        break;
    case 3:
        ((void (*)(void*, s32, s32))set_animation_frame)(arg0, 0x22, D_80097420 & 1);
        F(s16, 0xA) -= 6;
        F(s16, 0xE) += 6;
        break;
    }
    if (func_8002CBFC(arg0, 0x20, 0x20) == 1) {
        F(u8, 0x4) = 3;
    }
}
