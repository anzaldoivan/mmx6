#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK); /* extern */
extern struct X4_PlayerObj g_Player;
extern M2C_UNK D_800F77B0;
extern M2C_UNK D_800F77B4;
extern M2C_UNK D_800F77B8;
extern M2C_UNK D_800F77EC;

void func_800EE5CC(void* arg0) {
    void* temp = &g_Player;

    M2C_FIELD(arg0, u8*, 0x5C) = 0x20;
    M2C_FIELD(arg0, u8*, 0x60) = 4;
    M2C_FIELD(arg0, u8*, 0x61) = 0;
    M2C_FIELD(arg0, u8*, 0x14) = M2C_FIELD(temp, u8*, 0x14);
    M2C_FIELD(arg0, u8*, 0x67) = 0;
    M2C_FIELD(arg0, u8*, 0x70) = 0;
    M2C_FIELD(arg0, s32*, 0x18) = M2C_FIELD(arg0, s32*, 0x8);
    M2C_FIELD(arg0, s32*, 0x1C) = M2C_FIELD(arg0, s32*, 0xC);
    if (M2C_FIELD(temp, s32*, 0x8) < M2C_FIELD(arg0, s32*, 0x18)) {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
    } else {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
    }
    M2C_FIELD(arg0, void**, 0x30) = &D_800F77EC;
    M2C_FIELD(arg0, u8*, 0x16) = 6;
    M2C_FIELD(arg0, void**, 0x68) = &D_800F77B0;
    M2C_FIELD(arg0, void**, 0x54) = &D_800F77B8;
    M2C_FIELD(arg0, void**, 0x50) = &D_800F77B4;
    switch (M2C_FIELD(arg0, s8*, 0x2)) {
    case 0:
        ((void (*)(void*, s32))set_animation)(arg0, 0);
        M2C_FIELD(arg0, u8*, 0x5) = 1;
        break;
    case 1:
        ((void (*)(void*, s32))set_animation)(arg0, 0);
        M2C_FIELD(arg0, u8*, 0x5) = 1;
        break;
    case 2:
        ((void (*)(void*, s32))set_animation)(arg0, 0);
        M2C_FIELD(arg0, u8*, 0x5) = 1;
        break;
    case 3:
        M2C_FIELD(arg0, u8*, 0x3) = 0;
        M2C_FIELD(arg0, u8*, 0x5) = 4;
        break;
    case 4:
        M2C_FIELD(arg0, u8*, 0x3) = 0;
        M2C_FIELD(arg0, u8*, 0x5) = 5;
        break;
    }
    M2C_FIELD(arg0, s16*, 0x7C) = 0;
    M2C_FIELD(arg0, u8*, 0x4) = 1;
    M2C_FIELD(arg0, u8*, 0x6) = 0;
}
