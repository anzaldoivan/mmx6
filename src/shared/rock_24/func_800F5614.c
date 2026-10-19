#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern void* D_800F7800;

void func_800F5614(void* arg0) {
    void* p;
    u8 t;

    p = D_800F7800;
    M2C_FIELD(arg0, s32*, 0x30) = M2C_FIELD(p, s32*, 0x30);
    t = M2C_FIELD(p, u8*, 0x14);
    M2C_FIELD(arg0, u8*, 0x16) = 2;
    M2C_FIELD(arg0, u8*, 0x67) = 0;
    M2C_FIELD(arg0, u8*, 0x3) = 0;
    M2C_FIELD(arg0, s32*, 0x68) = 0;
    M2C_FIELD(arg0, s32*, 0x50) = 0;
    M2C_FIELD(arg0, s32*, 0x54) = 0;
    M2C_FIELD(arg0, s32*, 0x58) = 0;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, u8*, 0x5C) = 0;
    M2C_FIELD(arg0, u8*, 0x60) = 0;
    M2C_FIELD(arg0, s32*, 0x8C) = 0;
    M2C_FIELD(arg0, u8*, 0x5) = 0;
    M2C_FIELD(arg0, u8*, 0x4) = M2C_FIELD(arg0, u8*, 0x4) + 1;
    M2C_FIELD(arg0, u8*, 0x14) = t;
}
