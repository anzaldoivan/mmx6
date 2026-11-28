// rolefeed (3.1 T4): func_800ED704 of src/rock_24/E9860.c
#undef func_80030ECC

#include "common.h"
#include "mmx6/globals.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
extern s32 D_800F6BA4;
extern s32 D_800F6BA8;
extern u16 D_800F6CFC[][4][2];
extern u8 D_800F7794;

#define F(type, off) M2C_FIELD(self, type*, off)

void func_800ED704(void* self) {
    void* parent;
    u16 t;
    u8 b;

    parent = F(void*, 0x80);
    F(u16, 0x40) = M2C_FIELD(parent, u16*, 0x40);
    F(s32, 0x30) = M2C_FIELD(parent, s32*, 0x30);
    F(s32, 0x3C) = M2C_FIELD(parent, s32*, 0x3C);
    F(u16, 0x42) = M2C_FIELD(parent, u16*, 0x42);
    b = D_800970B4;
    F(u8, 0x16) = 6;
    F(u8, 0x67) = 0;
    F(u8, 0x3) = 0;
    F(s32, 0x68) = 0;
    F(void*, 0x50) = &D_800F6BA4;
    F(void*, 0x54) = &D_800F6BA8;
    F(void*, 0x58) = &D_800743DC;
    F(u8, 0x61) = 0;
    F(u8, 0x15) = 0;
    F(u8, 0x14) = b;
    F(u16, 0xA) = D_800F6CFC[D_800F7794][F(s8, 0x2) - 1][0];
    t = D_800F6CFC[D_800F7794][F(s8, 0x2) - 1][1];
    F(s32, 0x20) = 0;
    F(s32, 0x24) = 0;
    F(s32, 0x28) = 0;
    F(s32, 0x2C) = 0;
    F(u8, 0x5C) = 0x10;
    F(u8, 0x60) = 4;
    F(u16, 0xE) = t;
    set_animation(self, 9);
    F(u8, 0x5) = 2;
    F(u8, 0x6) = 0;
    F(u8, 0x4) = F(u8, 0x4) + 1;
}
