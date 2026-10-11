#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32*)0x1F800020)

M2C_UNK func_800179A4(void*, M2C_UNK);
s32 func_8002A47C(s32);
s32 func_80065944(s32);
s32 func_80065A14(s32);
s32 func_80065B74(s32, s32);
extern s32 D_8007429C;
extern M2C_UNK D_800970A0;
extern s32 D_800FB294;
extern s32 D_800FB298;
extern s32 D_800FB29C;
extern void* D_800FBC78;

void func_800EFA5C(void* arg0) {
    register void* p asm("$5");
    s32 ang;
    s32 t;
    register u8 dir asm("$6");

    p = M2C_FIELD(arg0, void**, 0x7C);
    M2C_FIELD(arg0, u16*, 0x40) = M2C_FIELD(p, u16*, 0x40);
    M2C_FIELD(arg0, s32*, 0x30) = M2C_FIELD(p, s32*, 0x30);
    t = M2C_FIELD(p, u16*, 0x42);
    M2C_FIELD(arg0, u8*, 0x16) = 2;
    M2C_FIELD(arg0, u8*, 0x14) = 0;
    M2C_FIELD(arg0, u16*, 0x42) = t & 0x7FFF;
    dir = M2C_FIELD(p, u8*, 0x15);
    M2C_FIELD(arg0, void**, 0x68) = &D_800FB294;
    M2C_FIELD(arg0, void**, 0x50) = &D_800FB298;
    M2C_FIELD(arg0, void**, 0x54) = &D_800FB29C;
    M2C_FIELD(arg0, u8*, 0x67) = 0;
    M2C_FIELD(arg0, u8*, 0x3) = 0;
    M2C_FIELD(arg0, u8*, 0x15) = dir;
    {
        void* a58 = &D_8007429C;
        void* q = D_800FBC78;
        s32 idx;
        s32 base;
        register s32 off asm("$6");
        M2C_FIELD(arg0, void**, 0x58) = a58;
        idx = func_8002A47C(M2C_FIELD(q, s8*, 1));
        base = SPAD20;
        off = *(s32*)(idx * 4 + base + 4);
        M2C_FIELD(arg0, s32*, 0x3C) = base + off;
        ((void (*)(void*, s32, s32))func_800179A4)(arg0, 0xE, off);
    }
    if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
        M2C_FIELD(arg0, s16*, 0xA) =
            M2C_FIELD(M2C_FIELD(arg0, void**, 0x7C), s16*, 0xA) - 0xA;
    } else {
        M2C_FIELD(arg0, s16*, 0xA) =
            M2C_FIELD(M2C_FIELD(arg0, void**, 0x7C), s16*, 0xA) + 0xA;
    }
    M2C_FIELD(arg0, s16*, 0xE) =
        M2C_FIELD(M2C_FIELD(arg0, void**, 0x7C), s16*, 0xE);
    {
        u8* g = (u8*)&D_800970A0;
        ang = (s16)func_80065B74(
            M2C_FIELD(g, s16*, 0xE) - M2C_FIELD(arg0, s16*, 0xE),
            M2C_FIELD(g, s16*, 0xA) - M2C_FIELD(arg0, s16*, 0xA));
    }
    M2C_FIELD(arg0, s32*, 0x20) = func_80065A14(ang) << 5;
    M2C_FIELD(arg0, s32*, 0x24) = -func_80065944(ang) << 5;
    M2C_FIELD(arg0, u8*, 0x5C) = 1;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, u8*, 0x60) = 4;
    M2C_FIELD(arg0, u8*, 0x5) = 0;
    M2C_FIELD(arg0, u8*, 0x4)++;
}
