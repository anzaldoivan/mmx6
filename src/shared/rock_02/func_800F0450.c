#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32*)0x1F800020)

M2C_UNK func_800179A4(void*, M2C_UNK);
s32 func_8002A47C(s32);
extern s16 D_800970AA;

void func_800F0450(void* arg0) {
    s32 v;

    if (D_800970AA > M2C_FIELD(arg0, s16*, 0xA)) {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
    } else {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
    }
    v = M2C_FIELD(arg0, u8*, 0x15);
    if (v == 0) {
        v = 0xFFFF0000;
    } else {
        v = 0x10000;
    }
    M2C_FIELD(arg0, s32*, 0x20) = v;
    do {
    } while (0);
    M2C_FIELD(arg0, s32*, 0x3C) =
        SPAD20 + *(s32*)(func_8002A47C(M2C_FIELD(arg0, s8*, 1)) * 4 + SPAD20);
    ((void (*)(void*, s32))func_800179A4)(arg0, 1);
    M2C_FIELD(arg0, s16*, 0x7C) = 0;
    M2C_FIELD(arg0, u8*, 0x6) = M2C_FIELD(arg0, u8*, 0x6) + 1;
}
