#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK set_animation(void*, M2C_UNK);
extern u8 D_800970B4;
extern u8 D_800F4BF0[];

void func_800EBD74(void* arg0) {
    void* p;
    // !FAKE: depin: dropping it breaks the match (12/59)
    register s32 b asm("$5");
    // !FAKE: depin: dropping it breaks the match (12/59)
    register s32 h asm("$2");

    p = M2C_FIELD(arg0, void**, 0x80);
    M2C_FIELD(arg0, u16*, 0x40) = M2C_FIELD(p, u16*, 0x40);
    M2C_FIELD(arg0, s32*, 0x30) = M2C_FIELD(p, s32*, 0x30);
    M2C_FIELD(arg0, s32*, 0x3C) = M2C_FIELD(p, s32*, 0x3C);
    M2C_FIELD(arg0, u16*, 0x42) = M2C_FIELD(p, u16*, 0x42);
    b = D_800970B4;
    h = (s32)(D_800F4BF0 + 0x10D0);
    M2C_FIELD(arg0, void**, 0x50) = (void*)h;
    {
        // !FAKE: depin: dropping it breaks the match (56/59)
        register s32 five asm("$3") = 5;
        M2C_FIELD(arg0, u8*, 0x16) = five;
    }
    M2C_FIELD(arg0, u8*, 0x67) = 0;
    M2C_FIELD(arg0, u8*, 0x3) = 0;
    M2C_FIELD(arg0, s32*, 0x68) = 0;
    M2C_FIELD(arg0, s32*, 0x54) = 0;
    M2C_FIELD(arg0, s32*, 0x58) = 0;
    M2C_FIELD(arg0, u8*, 0x61) = 0;
    M2C_FIELD(arg0, u8*, 0x15) = 0;
    M2C_FIELD(arg0, u8*, 0x14) = b;
    M2C_FIELD(arg0, u16*, 0xA) += M2C_FIELD(p, u16*, 0xA);
    M2C_FIELD(arg0, u16*, 0xE) += M2C_FIELD(p, u16*, 0xE);
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, u8*, 0x5C) = 0;
    M2C_FIELD(arg0, u8*, 0x60) = 0;
    ((void (*)(void*, s32))set_animation)(arg0, 5);
    M2C_FIELD(arg0, u8*, 0x5) = 0;
    M2C_FIELD(arg0, u8*, 0x6) = 0;
    M2C_FIELD(arg0, u8*, 0x4) += 1;
}
