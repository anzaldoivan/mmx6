#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32*)0x1F800020)

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002A47C(s32);
void* func_8002C458();
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern s32 D_800FAF14;
extern s32 D_80074B5C;

void func_800EEB48(void* arg0) {
    void* parent;
    void* p;
    struct X4_PlayerObj* pl;
    s32 b;

    parent = M2C_FIELD(arg0, void**, 0x80);
    M2C_FIELD(arg0, u16*, 0x40) = M2C_FIELD(parent, u16*, 0x40);
    M2C_FIELD(arg0, s32*, 0x30) = M2C_FIELD(parent, s32*, 0x30);
    M2C_FIELD(arg0, u16*, 0x42) = M2C_FIELD(parent, u16*, 0x42) & 0x7FFF;
    pl = &g_Player;
    b = M2C_FIELD(pl, u8*, 0x14);
    {
        // !FAKE: depin: dropping it breaks the match (81/89)
        register s32 t asm("$2") = 3;
        M2C_FIELD(arg0, u8*, 0x16) = t;
    }
    M2C_FIELD(arg0, void**, 0x54) = &D_800FAF14;
    M2C_FIELD(arg0, void**, 0x58) = &D_80074B5C;
    M2C_FIELD(arg0, u8*, 0x67) = 0;
    M2C_FIELD(arg0, u8*, 0x3) = 0;
    M2C_FIELD(arg0, s32*, 0x68) = 0;
    M2C_FIELD(arg0, s32*, 0x50) = 0;
    M2C_FIELD(arg0, u8*, 0x62) = 0;
    M2C_FIELD(arg0, u8*, 0x61) = 0;
    M2C_FIELD(arg0, u16*, 0xA) = 0x18E0;
    M2C_FIELD(arg0, u16*, 0xE) = 0x100;
    M2C_FIELD(arg0, u8*, 0x14) = b;
    {
        s32 k = 0x18E0;
        if (k < pl->x_pos.i.hi) {
            M2C_FIELD(arg0, u8*, 0x15) = 0x40;
        } else {
            M2C_FIELD(arg0, u8*, 0x15) = 0;
        }
    }
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, u8*, 0x5C) = 0;
    M2C_FIELD(arg0, u8*, 0x60) = 0;
    M2C_FIELD(arg0, u8*, 0x84) = 0;
    {
        s32 idx = func_8002A47C(M2C_FIELD(arg0, s8*, 1));
        s32 base = SPAD20;
        // !FAKE: depin: dropping it breaks the match (60/89)
        register s32 off asm("$6") = *(s32*)(idx * 4 + base + 4);
        M2C_FIELD(arg0, s32*, 0x3C) = base + off;
        ((void (*)(void*, s32, s32))set_animation)(arg0, 0xF, off);
    }
    play_sound(2, 9, arg0);
    p = func_8002C458();
    if (p != 0) {
        u8 o = M2C_FIELD(arg0, u8*, 0);
        M2C_FIELD(p, s8*, 1) = 1;
        M2C_FIELD(p, s8*, 2) = 5;
        M2C_FIELD(p, void**, 0x7C) = arg0;
        M2C_FIELD(p, u8*, 0) = o;
    }
    M2C_FIELD(arg0, u16*, 0x7E) = 0;
    M2C_FIELD(arg0, s8*, 5) = 0;
    M2C_FIELD(arg0, s8*, 6) = 0;
    M2C_FIELD(arg0, s8*, 4)++;
}
#undef g_Player
