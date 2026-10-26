#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
extern s32 D_80075AFC;
extern struct X4_PlayerObj g_Player;
extern s32 D_800FCA84;
extern s32 D_800FCE24;
extern s32 D_800FCE28;

#define PARENT (*(u8**)((s32) & D_800FCA84 + 0x3DC))

void func_800FA984(void* arg0) {
    s32 ang;
    // !FAKE: depin: dropping it breaks the match (136/143)
    register u8* r asm("$3");
    // !FAKE: depin: dropping it breaks the match (136/143)
    register u8* p asm("$5");
    // !FAKE: depin: dropping it breaks the match (116/143)
    register u8* q asm("$6");
    u16 y;
    s32 t3c;
    u8 t15;

    p = PARENT;
    M2C_FIELD(arg0, u16*, 0x40) = M2C_FIELD(p, u16*, 0x40);
    M2C_FIELD(arg0, u16*, 0x42) = M2C_FIELD(p, u16*, 0x42) & 0x7FFF;
    M2C_FIELD(arg0, s32*, 0x30) = M2C_FIELD(p, s32*, 0x30);
    t3c = M2C_FIELD(p, s32*, 0x3C);
    M2C_FIELD(arg0, u8*, 0x16) = 1;
    M2C_FIELD(arg0, u8*, 0x14) = 0;
    r = PARENT;
    M2C_FIELD(arg0, s32*, 0x3C) = t3c;
    t15 = M2C_FIELD(r, u8*, 0x15);
    M2C_FIELD(arg0, u8*, 0x67) = 0;
    M2C_FIELD(arg0, u8*, 0x3) = 0;
    M2C_FIELD(arg0, s32*, 0x68) = 0;
    M2C_FIELD(arg0, void**, 0x50) = &D_800FCE24;
    M2C_FIELD(arg0, void**, 0x54) = &D_800FCE28;
    M2C_FIELD(arg0, void**, 0x58) = &D_80075AFC;
    M2C_FIELD(arg0, u8*, 0x15) = t15;
    ((void (*)(void*, s32, s32, s32))func_800179A4)(arg0, 0xD, t3c, t15);
    if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
        M2C_FIELD(arg0, s16*, 0xA) = M2C_FIELD(PARENT, s16*, 0xA) - 0x10;
    } else {
        M2C_FIELD(arg0, s16*, 0xA) = M2C_FIELD(PARENT, s16*, 0xA) + 0x10;
    }
    y = M2C_FIELD(PARENT, u16*, 0xE);
    M2C_FIELD(arg0, u16*, 0xE) = y;
    if (M2C_FIELD(arg0, s8*, 0x2) >= 2) {
        M2C_FIELD(arg0, u16*, 0xE) = y - 8;
    }
    if (M2C_FIELD(arg0, s8*, 0x2) == 0) {
        if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
            M2C_FIELD(arg0, s32*, 0x20) = -0x30000;
        } else {
            M2C_FIELD(arg0, s32*, 0x20) = 0x30000;
        }
        M2C_FIELD(arg0, s32*, 0x24) = 0;
    } else {
        ang = (s16)ratan2(g_Player.y_pos.i.hi - M2C_FIELD(arg0, s16*, 0xE),
                          g_Player.x_pos.i.hi - M2C_FIELD(arg0, s16*, 0xA));
        M2C_FIELD(arg0, s32*, 0x20) = rcos(ang) * 0x30;
        M2C_FIELD(arg0, s32*, 0x24) = -rsin(ang) * 0x30;
        if (M2C_FIELD(arg0, s32*, 0x20) < 0) {
            M2C_FIELD(arg0, u8*, 0x15) = 0;
        } else if (M2C_FIELD(arg0, s32*, 0x20) > 0) {
            M2C_FIELD(arg0, u8*, 0x15) = 0x40;
        }
    }
    {
        // !FAKE: depin: dropping it breaks the match (126/143)
        register s32 vx asm("$5") = M2C_FIELD(arg0, s32*, 0x20);
        M2C_FIELD(arg0, u8*, 0x5C) = 0x64;
        M2C_FIELD(arg0, u8*, 0x60) = 6;
        q = PARENT;
        M2C_FIELD(arg0, s32*, 0x28) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = 0;
        {
            s32 t = vx * 3;
            M2C_FIELD(arg0, s32*, 0x20) = t / 2;
        }
    }
    {
        // !FAKE: depin: dropping it breaks the match (128/143)
        register s32 vy asm("$5") = M2C_FIELD(arg0, s32*, 0x24);
        // !FAKE: depin: dropping it breaks the match (131/143)
        register s32 u asm("$3") = vy * 3;
        M2C_FIELD(arg0, s32*, 0x24) = u / 2;
    }
    {
        u8 c = M2C_FIELD(q, u8*, 0x7) + 1;
        M2C_FIELD(q, u8*, 0x7) = c;
    }
    func_80016C48(2, 0x43, arg0);
    M2C_FIELD(arg0, u8*, 0x6) = 0;
    M2C_FIELD(arg0, u8*, 0x4)++;
    M2C_FIELD(arg0, u8*, 0x5) = M2C_FIELD(arg0, u8*, 0x2);
}
