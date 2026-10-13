#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK);
extern s32 D_800F7D74;

void func_800F58E8(void* arg0) {
    u8* p;
    u8 t14;

    p = M2C_FIELD(arg0, u8**, 0x7C);
    M2C_FIELD(arg0, s32*, 0x30) = M2C_FIELD(p, s32*, 0x30);
    M2C_FIELD(arg0, u16*, 0x40) = M2C_FIELD(p, u16*, 0x40);
    M2C_FIELD(arg0, s32*, 0x3C) = M2C_FIELD(p, s32*, 0x3C);
    M2C_FIELD(arg0, u16*, 0x42) = M2C_FIELD(p, u16*, 0x42) & 0x7FFF;
    t14 = M2C_FIELD(p, u8*, 0x14);
    M2C_FIELD(arg0, u8*, 0x16) = 2;
    M2C_FIELD(arg0, u8*, 0x67) = 0;
    M2C_FIELD(arg0, u8*, 0x3) = 0;
    M2C_FIELD(arg0, s32*, 0x68) = 0;
    M2C_FIELD(arg0, void**, 0x50) = &D_800F7D74;
    M2C_FIELD(arg0, s32*, 0x54) = 0;
    M2C_FIELD(arg0, s32*, 0x58) = 0;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, u8*, 0x14) = t14;
    func_800179A4(arg0, 0x14);
    M2C_FIELD(arg0, u8*, 0x5C) = 0;
    M2C_FIELD(arg0, u8*, 0x60) = 4;
    M2C_FIELD(arg0, u8*, 0x5) = 0;
    M2C_FIELD(arg0, u8*, 0x4) = M2C_FIELD(arg0, u8*, 0x4) + 1;
}
