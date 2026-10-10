#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD4C (*(u8**)0x1F80004C)

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80017A04();

void func_800F7818(void* arg0) {
    s32 t;

    ((M2C_UNK(*)())func_80017A04)();
    if (M2C_FIELD(arg0, s16*, 0x7C) == 0xA) {
        func_80016C48(2, 0x1D, arg0);
        func_80012D9C(7);
    }
    t = M2C_FIELD(arg0, u16*, 0x7C);
    M2C_FIELD(arg0, u16*, 0x7C) = t + 1;
    if ((s16)t >= 0x79) {
        func_800179A4(arg0, 8);
        {
            register s32 b asm("$2");
            b = M2C_FIELD(arg0, u8*, 6) + 1;
            M2C_FIELD(arg0, u8*, 6) = b;
        }
        return;
    }
    if (M2C_FIELD(SPAD4C, u8*, 0x8A) != 0x11) {
        func_800179A4(arg0, 2);
        func_80016C48(2, 0x3D, arg0);
        M2C_FIELD(arg0, u8*, 6) = 5;
    }
}
