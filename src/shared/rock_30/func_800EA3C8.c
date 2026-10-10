#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK);
s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
s32 func_80065B74(s32, s32);
extern s32 D_8007429C;
extern s32 D_800970A0;
extern s32 D_800EF998;
extern s32 D_800EF99C;
extern s32 D_800EF9A0;

void func_800EA3C8(void* arg0) {
    M2C_FIELD(arg0, u8*, 0x60) = 4;
    M2C_FIELD(arg0, u8*, 0x5C) = 1;
    M2C_FIELD(arg0, s32**, 0x58) = &D_8007429C;
    M2C_FIELD(arg0, u8*, 0x16) = 5;
    M2C_FIELD(arg0, u8*, 0x67) = 1;
    func_800179A4(arg0, 2);
    {
        register s32* a asm("$2") = &D_800EF998;
        register s32* b asm("$3") = &D_800EF99C;
        M2C_FIELD(arg0, s32**, 0x68) = a;
        M2C_FIELD(arg0, s32**, 0x50) = b;
    }
    M2C_FIELD(arg0, s32**, 0x54) = &D_800EF9A0;
    M2C_FIELD(arg0, u8*, 4) = 1;
    M2C_FIELD(arg0, u8*, 5) = 0;
    M2C_FIELD(arg0, u8*, 6) = 0;
    M2C_FIELD(arg0, u8*, 7) = 0;
    if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
        M2C_FIELD(arg0, s16*, 0xA) += 6;
        M2C_FIELD(arg0, s16*, 0xE) -= 0x14;
    } else {
        M2C_FIELD(arg0, s16*, 0xA) -= 6;
        M2C_FIELD(arg0, s16*, 0xE) -= 0x14;
    }
    {
        struct X4_PlayerObj* p = &D_800970A0;
        s32 px = p->x_pos.i.hi;
        s32 py = p->y_pos.i.hi;
        func_80065B74(M2C_FIELD(arg0, s16*, 0xE) - py,
                      px - M2C_FIELD(arg0, s16*, 0xA));
    }
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0x40000;
    if (func_8002CBFC(arg0, 0x20, 0x20) == 0) {
        func_8002CCB0(arg0, 0x10, 0x10);
        return;
    }
    M2C_FIELD(arg0, u8*, 4) += 1;
}
