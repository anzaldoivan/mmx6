#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK);
extern s32 D_8007429C;
extern s32 D_800F3804;
extern s32 D_800F3808;

void func_800EB41C(void* arg0) {
    s32 var_a1;
    u8 temp_v1;
    s32 temp_v0;

    var_a1 = 0xFFFD8000;
    M2C_FIELD(arg0, u8*, 3) = 1;
    temp_v1 = M2C_FIELD(arg0, u8*, 0x15);
    M2C_FIELD(arg0, u8*, 4) = M2C_FIELD(arg0, u8*, 4) + 1;
    if (temp_v1 != 0) {
        var_a1 = 0x28000;
    }
    temp_v0 = M2C_FIELD(arg0, s16*, 0xA);
    M2C_FIELD(arg0, s32*, 0x20) = var_a1;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    if (temp_v1 != 0) {
        temp_v0 += 0x10;
    } else {
        temp_v0 -= 0x10;
    }
    M2C_FIELD(arg0, s16*, 0xA) = temp_v0;
    M2C_FIELD(arg0, u8*, 0x16) = 6;
    M2C_FIELD(arg0, s32**, 0x68) = &D_800F3808;
    M2C_FIELD(arg0, s32**, 0x54) = &D_800F3804;
    M2C_FIELD(arg0, s32**, 0x50) = &D_800F3804;
    M2C_FIELD(arg0, s32**, 0x58) = &D_8007429C;
    M2C_FIELD(arg0, u8*, 0x60) = 2;
    M2C_FIELD(arg0, u16*, 0xE) = M2C_FIELD(arg0, u16*, 0xE) + 3;
    func_800179A4(arg0, 8);
}
