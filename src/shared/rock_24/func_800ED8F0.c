#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
extern M2C_UNK D_800743DC;
extern u8 D_800970B4;
extern s8 D_800CCEF6;
extern s32 D_800F6B9C;
extern s32 D_800F6C88;
extern u16 D_800F6CE0[][2];
extern u8 D_800F7794;

#define F(type, off) M2C_FIELD(self, type*, off)

void func_800ED8F0(void* self) {
    s32 b;
    s32 z;

    z = 0;
    D_800F7794 = F(u8, 0x2) & 0xF;
    F(u8, 0x2) = 0;
    F(void*, 0x30) = &D_800F6C88;
    b = D_800970B4;
    {
        // !FAKE: depin: dropping it breaks the match (58/70)
        register s32 t asm("$2") = 6;
        F(u8, 0x16) = t;
    }
    {
        // !FAKE: depin: dropping it breaks the match (65/70)
        register void* a asm("$2") = &D_800F6B9C;
        F(void*, 0x68) = a;
    }
    {
        void* a = &D_800743DC;
        F(void*, 0x58) = a;
    }
    F(u8, 0x67) = 0;
    F(u8, 0x3) = 0;
    F(s32, 0x50) = 0;
    F(s32, 0x54) = 0;
    F(u8, 0x61) = 0;
    F(u8, 0x15) = 0;
    F(s32, 0x20) = 0;
    F(s32, 0x24) = 0;
    F(s32, 0x28) = 0;
    F(s32, 0x2C) = 0x40000;
    F(u8, 0x5C) = 0x20;
    F(u8, 0x60) = 0;
    F(u8, 0x14) = b;
    set_animation(self, z);
    F(u16, 0xA) = D_800F6CE0[D_800F7794][0];
    F(u16, 0xE) = D_800F6CE0[D_800F7794][1];
    D_800CCEF6 = 1;
    F(u8, 0x5) = 2;
    F(u8, 0x6) = 0;
    F(u8, 0x7) = 5;
    F(u8, 0x4) = F(u8, 0x4) + 1;
}
