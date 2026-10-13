#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32*)0x1F800020)

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_800179A4(void*, M2C_UNK);
s32 func_8002A47C(s32);
s32 func_8002D2D4();
extern s16 D_800970AA;

void func_800F0654(void* arg0) {
    s32 a;
    s32 b;

    if (D_800970AA > M2C_FIELD(arg0, s16*, 0xA)) {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
    } else {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
    }
    if (func_8002D2D4() & 1) {
        func_80016C48(2, 0x25, arg0);
    } else {
        func_80016C48(2, 0x26, arg0);
    }
    M2C_FIELD(arg0, u16*, 0x40) = 0x140;
    a = func_8002A47C(M2C_FIELD(arg0, s8*, 1));
    b = func_8002A47C(M2C_FIELD(arg0, s8*, 1));
    M2C_FIELD(arg0, u16*, 0x42) =
        ((a * 4 + 0x20) % 16) | (((b + 8) / 4 + 0x1E0) << 6);
    M2C_FIELD(arg0, s32*, 0x3C) =
        SPAD20 + *(s32*)(func_8002A47C(M2C_FIELD(arg0, s8*, 1)) * 4 + SPAD20);
    ((void (*)(void*, s32))func_800179A4)(arg0, 4);
    M2C_FIELD(arg0, s16*, 0x7C) = 0;
    M2C_FIELD(arg0, u8*, 6)++;
}
