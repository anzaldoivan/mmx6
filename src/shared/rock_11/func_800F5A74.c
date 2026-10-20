#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800139F4(M2C_UNK);
extern s16 D_800970AA;
extern s32 D_80097420;
#define D_80097420 (*(s32*)&D_80097420)
extern s8 D_800CCEDF;

void func_800F5A74(void* arg0) {
    s32 temp_a0;
    s32 temp_a1;

    M2C_FIELD(arg0, u16*, 0x7C) = M2C_FIELD(arg0, u16*, 0x7C) + 1;
    temp_a1 = M2C_FIELD(arg0, u16*, 0x80) + 1;
    M2C_FIELD(arg0, u16*, 0x80) = temp_a1;
    temp_a0 = M2C_FIELD(arg0, u16*, 0x82) - 1;
    M2C_FIELD(arg0, u16*, 0x82) = temp_a0;
    if (!(D_80097420 & 1)) {
        D_800970AA = temp_a1;
    } else {
        D_800970AA = temp_a0;
    }
    if (M2C_FIELD(arg0, s16*, 0x7C) >= 0x1D) {
        func_800139F4(8);
        D_800CCEDF = M2C_FIELD(arg0, u8*, 2) | 0x40;
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
    }
}
#undef D_80097420
