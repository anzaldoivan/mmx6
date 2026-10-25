#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK); /* extern */
extern M2C_UNK D_8007479C;
extern struct X4_PlayerObj g_Player;
extern M2C_UNK D_800F7448;
extern M2C_UNK D_800F744C;
extern M2C_UNK D_800F7650;

void func_800ED760(void* arg0) {
    void* temp = &g_Player;
    u8 b;
    s32 x;

    M2C_FIELD(arg0, u8*, 0x5C) = 0x20;
    M2C_FIELD(arg0, u8*, 0x60) = 8;
    M2C_FIELD(arg0, u8*, 0x61) = 0;
    b = M2C_FIELD(temp, u8*, 0x14);
    x = M2C_FIELD(arg0, s32*, 0x8);
    M2C_FIELD(arg0, void**, 0x58) = &D_8007479C;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, u8*, 0x70) = 0;
    M2C_FIELD(arg0, u8*, 0x14) = b;
    if (M2C_FIELD(temp, s32*, 0x8) < x) {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
    } else {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
    }
    M2C_FIELD(arg0, void**, 0x30) = &D_800F7650;
    M2C_FIELD(arg0, u8*, 0x16) = 5;
    M2C_FIELD(arg0, s32*, 0x68) = 0;
    M2C_FIELD(arg0, void**, 0x54) = &D_800F744C;
    M2C_FIELD(arg0, void**, 0x50) = &D_800F7448;
    ((void (*)(void*, s32))func_800179A4)(arg0, 0);
    M2C_FIELD(arg0, s16*, 0x7C) = 0;
    M2C_FIELD(arg0, u8*, 0x4) = 1;
    M2C_FIELD(arg0, u8*, 0x5) = 1;
    M2C_FIELD(arg0, u8*, 0x7) = 0;
}
