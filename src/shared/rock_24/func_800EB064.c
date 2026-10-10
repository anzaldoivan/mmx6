#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_800179A4(void*, M2C_UNK);
s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
s32 func_80065944(s32);
s32 func_80065A14(s32);
s32 func_80065B74(s32, s32);
extern s32 D_8007429C;
extern M2C_UNK D_800970A0;
extern s32 D_800F679C;
extern s32 D_800F67A0;

void func_800EB064(void* arg0) {
    s32 angle;
    s32 t;
    s32 v;
    s32 px;
    s32 py;

    M2C_FIELD(arg0, u8*, 0x60) = 4;
    M2C_FIELD(arg0, u8*, 0x5C) = 1;
    M2C_FIELD(arg0, s32**, 0x58) = &D_8007429C;
    M2C_FIELD(arg0, u8*, 0x16) = 5;
    M2C_FIELD(arg0, u8*, 0x67) = 1;
    func_800179A4(arg0, 3);
    M2C_FIELD(arg0, s32*, 0x68) = 0;
    M2C_FIELD(arg0, s32**, 0x50) = &D_800F679C;
    M2C_FIELD(arg0, s32**, 0x54) = &D_800F67A0;
    M2C_FIELD(arg0, u8*, 4) = 1;
    M2C_FIELD(arg0, u8*, 5) = 0;
    M2C_FIELD(arg0, u8*, 6) = 0;
    M2C_FIELD(arg0, u8*, 7) = 0;
    px = ((struct X4_PlayerObj*)&D_800970A0)->x_pos.i.hi;
    py = ((struct X4_PlayerObj*)&D_800970A0)->y_pos.i.hi;
    angle = func_80065B74(M2C_FIELD(arg0, s16*, 0xE) - py,
                          px - M2C_FIELD(arg0, s16*, 0xA));
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    t = func_80065A14(angle);
    v = t * 16;
    M2C_FIELD(arg0, s32*, 0x20) = (t * 64 + v) >> 1;
    t = func_80065944(angle);
    v = t * 16;
    M2C_FIELD(arg0, s32*, 0x24) = (t * 64 + v) >> 1;
    func_80016C48(2, 0x3B, arg0);
    if (func_8002CBFC(arg0, 0x20, 0x20) == 0) {
        func_8002CCB0(arg0, 0x10, 0x10);
    } else {
        M2C_FIELD(arg0, u8*, 4)++;
    }
}
