#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
extern s32 D_800741FC[];
extern M2C_UNK D_8007433C;
extern u8 D_800CCF38;
extern M2C_UNK D_800FAB68;
extern M2C_UNK D_800FAB6C;

void func_800EB23C(void* arg0) {
    s32 vx;
    u8 dir;
    s32 x;

    vx = 0xFFFE0000;
    dir = M2C_FIELD(arg0, u8*, 0x15);
    M2C_FIELD(arg0, u8*, 3) = 1;
    if (dir != 0) {
        vx = 0x20000;
    }
    x = M2C_FIELD(arg0, s16*, 0xA);
    M2C_FIELD(arg0, s32*, 0x20) = vx;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    if (dir != 0) {
        x += 0x10;
    } else {
        x -= 0x10;
    }
    M2C_FIELD(arg0, s16*, 0xA) = x;
    M2C_FIELD(arg0, u8*, 0x16) = 4;
    M2C_FIELD(arg0, void**, 0x68) = &D_800FAB6C;
    M2C_FIELD(arg0, void**, 0x54) = &D_800FAB68;
    M2C_FIELD(arg0, void**, 0x50) = &D_800FAB68;
    {
        // !FAKE: depin: dropping it breaks the match (57/65)
        register s32 one asm("$4") = 1;
        M2C_FIELD(arg0, u8*, 0x5C) = one;
        M2C_FIELD(arg0, u8*, 0x60) = one;
    }
    M2C_FIELD(arg0, u8*, 0x61) = 0;
    M2C_FIELD(arg0, s16*, 0xE) -= 0xC;
    M2C_FIELD(arg0, s16*, 0x42) &= 0x7FFF;
    if (D_800CCF38 >= 2) {
        M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
        set_animation(arg0, 7);
    } else {
        M2C_FIELD(arg0, void**, 0x58) = D_800741FC;
        set_animation(arg0, 6);
    }
    M2C_FIELD(arg0, u8*, 4) += 1;
}
