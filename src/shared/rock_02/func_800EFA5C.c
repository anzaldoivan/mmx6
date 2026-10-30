#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32*)0x1F800020)

M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002A47C(s32);
extern s32 D_8007429C;
extern M2C_UNK g_Player;
extern s32 D_800FB294;
extern s32 D_800FB298;
extern s32 D_800FB29C;
extern void* D_800FBC78;

void func_800EFA5C(void* arg0) {
    void* p;
    s32 ang;
    s32 t;
    // !FAKE: depin: dropping it breaks the match (13/104)
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
        // !FAKE: depin: dropping it breaks the match (47/104)
        register s32 off asm("$6");
        M2C_FIELD(arg0, void**, 0x58) = a58;
        idx = func_8002A47C(M2C_FIELD(q, s8*, 1));
        base = SPAD20;
        off = *(s32*)(idx * 4 + base + 4);
        M2C_FIELD(arg0, s32*, 0x3C) = base + off;
        ((void (*)(void*, s32, s32))set_animation)(arg0, 0xE, off);
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
        u8* g = (u8*)&g_Player;
        ang = (s16)ratan2(M2C_FIELD(g, s16*, 0xE) - M2C_FIELD(arg0, s16*, 0xE),
                          M2C_FIELD(g, s16*, 0xA) - M2C_FIELD(arg0, s16*, 0xA));
    }
    M2C_FIELD(arg0, s32*, 0x20) = rcos(ang) << 5;
    M2C_FIELD(arg0, s32*, 0x24) = -rsin(ang) << 5;
    M2C_FIELD(arg0, u8*, 0x5C) = 1;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, u8*, 0x60) = 4;
    M2C_FIELD(arg0, u8*, 0x5) = 0;
    M2C_FIELD(arg0, u8*, 0x4)++;
}
