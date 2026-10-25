#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32**)0x1F800020)

M2C_UNK func_800179A4(void*, M2C_UNK);
s32 func_8002A47C(s32);
M2C_UNK func_8002C9B0();
s32 func_8002D2D4();
extern u32* D_80095098;
extern u8 D_800970B4;
extern struct X4_BackgroundObj background_objects[3];
extern s8 D_800CD30A;
extern s32 D_800F78E8;

void func_800EF304(void* arg0) {
    s32 r;
    u8 t;

    if (D_800CD30A != 6) {
        func_8002C9B0(arg0);
        return;
    }
    M2C_FIELD(arg0, u8*, 3) = 0;
    M2C_FIELD(arg0, s16*, 0x7C) = 0;
    M2C_FIELD(arg0, u8*, 0x5C) = 0;
    M2C_FIELD(arg0, u8*, 0x61) = 0;
    t = D_800970B4;
    M2C_FIELD(arg0, void**, 0x30) = &D_800F78E8;
    M2C_FIELD(arg0, u8*, 0x16) = 0;
    M2C_FIELD(arg0, void**, 0x68) = NULL;
    M2C_FIELD(arg0, void**, 0x54) = NULL;
    M2C_FIELD(arg0, void**, 0x50) = NULL;
    M2C_FIELD(arg0, u8*, 0x67) = 0;
    M2C_FIELD(arg0, s16*, 0x7C) = 5;
    M2C_FIELD(arg0, u8*, 0x60) = 0;
    M2C_FIELD(arg0, u8*, 0x14) = t;
    ((void (*)(void*, s32))func_800179A4)(arg0, 0);
    M2C_FIELD(arg0, u8*, 0x15) = 0;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    if (M2C_FIELD(arg0, s8*, 2) == 0) {
        M2C_FIELD(arg0, s16*, 0x40) =
            D_80095098[func_8002A47C(M2C_FIELD(arg0, s8*, 1))] >> 7;
        M2C_FIELD(arg0, s16*, 0x42) =
            ((func_8002A47C(M2C_FIELD(arg0, s8*, 1)) * 4 + 0x20) % 16) |
            (((func_8002A47C(M2C_FIELD(arg0, s8*, 1)) + 8) / 4 + 0x1E0) << 6);
        M2C_FIELD(arg0, s32*, 0x3C) =
            (s32)SPAD20 + SPAD20[func_8002A47C(M2C_FIELD(arg0, s8*, 1))];
        M2C_FIELD(arg0, u8*, 5) = 0;
    } else {
        r = func_8002D2D4();
        M2C_FIELD(arg0, s16*, 0xA) =
            background_objects[0].x_pos.i.hi + r * 2 + (func_8002D2D4() & 0x1F);
        M2C_FIELD(arg0, s16*, 0xE) = background_objects[0].y_pos.i.hi - 0x10;
        M2C_FIELD(arg0, s32*, 0x20) = -0x70000;
        M2C_FIELD(arg0, s32*, 0x24) = -0x70000;
        M2C_FIELD(arg0, u8*, 5) = 1;
    }
    M2C_FIELD(arg0, u8*, 4) = 1;
    M2C_FIELD(arg0, u8*, 6) = 0;
    M2C_FIELD(arg0, s32*, 0x18) = M2C_FIELD(arg0, s32*, 8);
    M2C_FIELD(arg0, s32*, 0x1C) = M2C_FIELD(arg0, s32*, 0xC);
}
