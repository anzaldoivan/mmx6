#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32**)0x1F800020)
#define SPAD28 (*(u8**)0x1F800028)

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
s32 func_800179A4(void*, s32);
s32 func_8002A47C(s32);
M2C_UNK func_8002B3D4(M2C_UNK, M2C_UNK*, M2C_UNK);
s32 func_8002D2D4();
extern struct X4_PlayerObj g_Player;
extern s32 D_800FC970;
extern s32 D_800FC97C;
extern s32 D_800FC980;
extern s32 D_800FC984;
extern s32 D_800FC988;
extern s32 D_800FC98C;
extern s32 D_800FC990;
extern s32 D_800FCE98;
extern s32 D_800FCF50;
extern s32 D_800FD4F4[];
extern s32 D_800FD514[];

void func_800F7EE8(void* arg0) {
    s32 a;
    s32 b;
    s32 ang;
    s8 kind;

    kind = M2C_FIELD(arg0, s8*, 2);
    M2C_FIELD(arg0, s8*, 4) = 1;
    M2C_FIELD(arg0, s8*, 6) = 0;
    M2C_FIELD(arg0, s16*, 0x88) = 0;
    M2C_FIELD(arg0, s8*, 0x16) = 3;
    if (kind == 0) {
        M2C_FIELD(arg0, s8*, 0x60) = 4;
        M2C_FIELD(arg0, s32*, 0x2C) = 0x5000;
        M2C_FIELD(arg0, s32*, 0x20) = D_800FD4F4[func_8002D2D4() & 7];
        M2C_FIELD(arg0, s32*, 0x24) = D_800FD514[func_8002D2D4() & 7];
        M2C_FIELD(arg0, s32*, 0x54) = 0;
        M2C_FIELD(arg0, void**, 0x50) = &D_800FC980;
        M2C_FIELD(arg0, void**, 0x68) = NULL;
        M2C_FIELD(arg0, s8*, 5) = 2;
        M2C_FIELD(arg0, s8*, 6) = 0;
        ((void (*)(void*, s32))func_800179A4)(arg0, 0x24);
    } else if (kind == 1) {
        M2C_FIELD(arg0, s8*, 0x60) = 4;
        M2C_FIELD(arg0, s32*, 0x54) = 0;
        M2C_FIELD(arg0, void**, 0x50) = &D_800FC980;
        M2C_FIELD(arg0, void**, 0x68) = &D_800FC970;
        M2C_FIELD(arg0, s8*, 5) = 3;
        M2C_FIELD(arg0, s8*, 6) = 0;
        M2C_FIELD(arg0, s16*, 0x8C) = 0x32;
        ((void (*)(void*, s32))func_800179A4)(arg0, 0x19);
        func_80016C48(2, 0x6C, arg0);
    } else if (kind == 2) {
        func_80016C48(2, 0x6F, arg0);
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = -0x20000;
        M2C_FIELD(arg0, void**, 0x68) = &D_800FC97C;
        M2C_FIELD(arg0, s32*, 0x54) = 0;
        M2C_FIELD(arg0, void**, 0x50) = NULL;
        M2C_FIELD(arg0, s8*, 5) = 1;
        M2C_FIELD(arg0, s8*, 6) = 0;
        ((void (*)(void*, s32))func_800179A4)(arg0, 0x24);
        M2C_FIELD(arg0, s16*, 0x8C) = 0x12C;
    } else if (kind == 3) {
        ang = ratan2(g_Player.y_pos.i.hi - M2C_FIELD(arg0, s16*, 0xE),
                     g_Player.x_pos.i.hi - M2C_FIELD(arg0, s16*, 0xA));
        {
            s32 t;
            s32 w;
            s32 u;
            s32 x;
            t = rcos(ang);
            w = t << 4;
            M2C_FIELD(arg0, s32*, 0x20) = ((t << 6) + w) >> 1;
            u = -rsin(ang);
            x = u << 4;
            M2C_FIELD(arg0, s32*, 0x24) = ((u << 6) + x) >> 1;
        }
        M2C_FIELD(arg0, void**, 0x30) = &D_800FCE98;
        M2C_FIELD(arg0, s8*, 0x60) = 6;
        M2C_FIELD(arg0, s32*, 0x54) = 0;
        M2C_FIELD(arg0, void**, 0x50) = &D_800FC98C;
        M2C_FIELD(arg0, void**, 0x68) = &D_800FC97C;
        M2C_FIELD(arg0, s8*, 5) = 0;
        ((void (*)(void*, s32))func_800179A4)(arg0, 0x1E);
        M2C_FIELD(arg0, s8*, 0x16) = 2;
        func_80016C48(2, 0x6C, arg0);
    } else if (kind == 4) {
        M2C_FIELD(arg0, s8*, 0x16) = 1;
        ((void (*)(void*, s32))func_800179A4)(arg0, 0x1F);
        M2C_FIELD(arg0, s8*, 5) = 5;
    } else if (kind == 5) {
        func_80016C48(2, 0x70, arg0);
        M2C_FIELD(arg0, u16*, 0x40) = 0x4A0;
        M2C_FIELD(arg0, u16*, 0x42) =
            (((func_8002A47C(0x3C) - 1) * 4 + 0x20) % 16) |
            (((func_8002A47C(0x3C) + 7) / 4 + 0x1E0) << 6);
        M2C_FIELD(arg0, void**, 0x3C) =
            (u8*)SPAD20 + SPAD20[func_8002A47C(0x3C) + 1];
        M2C_FIELD(arg0, void**, 0x30) = &D_800FCF50;
        M2C_FIELD(arg0, void**, 0x50) = &D_800FC988;
        M2C_FIELD(arg0, void**, 0x68) = NULL;
        M2C_FIELD(arg0, s32*, 0x54) = 0;
        M2C_FIELD(arg0, s8*, 5) = 1;
        M2C_FIELD(arg0, s8*, 6) = 1;
        M2C_FIELD(arg0, s8*, 0x60) = 8;
        ((void (*)(void*, s32))func_800179A4)(arg0, 0);
        M2C_FIELD(arg0, s16*, 0x8C) = 0x12C;
        M2C_FIELD(arg0, s8*, 0x15) = 0;
        a = func_8002A47C(0x3C) * 4;
        a += 0x24;
        func_8002B3D4(func_8002A47C(0x3C) * 4 + 0x1C, (s32*)((a << 5) + SPAD28),
                      4);
    } else if (kind == 6) {
        M2C_FIELD(arg0, u16*, 0x40) = 0x4A0;
        M2C_FIELD(arg0, u16*, 0x42) =
            (((func_8002A47C(0x3C) - 1) * 4 + 0x20) % 16) |
            (((func_8002A47C(0x3C) + 7) / 4 + 0x1E0) << 6);
        M2C_FIELD(arg0, void**, 0x3C) =
            (u8*)SPAD20 + SPAD20[func_8002A47C(0x3C) + 1];
        M2C_FIELD(arg0, void**, 0x30) = &D_800FCF50;
        M2C_FIELD(arg0, void**, 0x50) = &D_800FC984;
        M2C_FIELD(arg0, void**, 0x68) = NULL;
        M2C_FIELD(arg0, s32*, 0x54) = 0;
        M2C_FIELD(arg0, s8*, 5) = 1;
        M2C_FIELD(arg0, s8*, 6) = 1;
        M2C_FIELD(arg0, s8*, 0x60) = 8;
        ((void (*)(void*, s32))func_800179A4)(arg0, 1);
        M2C_FIELD(arg0, s16*, 0x8C) = 0x12C;
        M2C_FIELD(arg0, s8*, 0x15) = 0;
    } else if (kind == 7) {
        M2C_FIELD(arg0, s8*, 0x16) = 2;
        ((void (*)(void*, s32))func_800179A4)(arg0, 0x17);
        M2C_FIELD(arg0, s8*, 5) = 5;
    } else if (kind == 8) {
        M2C_FIELD(arg0, s8*, 0x16) = 2;
        ((void (*)(void*, s32))func_800179A4)(arg0, 0x18);
        M2C_FIELD(arg0, s8*, 5) = 5;
    } else if (kind == 9) {
        M2C_FIELD(arg0, s8*, 0x60) = 8;
        func_80016C48(2, 0x6D, arg0);
        M2C_FIELD(arg0, void**, 0x50) = &D_800FC990;
        M2C_FIELD(arg0, s8*, 0x16) = 2;
        M2C_FIELD(arg0, void**, 0x68) = NULL;
        M2C_FIELD(arg0, s32*, 0x54) = 0;
        M2C_FIELD(arg0, s16*, 0x8C) = 0x28;
        ((void (*)(void*, s32))func_800179A4)(arg0, 0x1C);
        M2C_FIELD(arg0, s8*, 5) = 4;
    } else if (M2C_FIELD(arg0, s8*, 2) == 10) {
        func_80016C48(2, 0x6C, arg0);
        ang = ratan2(g_Player.y_pos.i.hi - M2C_FIELD(arg0, s16*, 0xE),
                     g_Player.x_pos.i.hi - M2C_FIELD(arg0, s16*, 0xA));
        {
            s32 t;
            s32 w;
            s32 u;
            s32 x;
            t = rcos(ang);
            w = t << 4;
            M2C_FIELD(arg0, s32*, 0x20) = ((t << 5) + w) >> 1;
            u = -rsin(ang);
            x = u << 4;
            M2C_FIELD(arg0, s32*, 0x24) = ((u << 5) + x) >> 1;
        }
        M2C_FIELD(arg0, void**, 0x30) = &D_800FCE98;
        M2C_FIELD(arg0, s8*, 0x60) = 6;
        M2C_FIELD(arg0, s32*, 0x54) = 0;
        M2C_FIELD(arg0, void**, 0x50) = &D_800FC98C;
        M2C_FIELD(arg0, void**, 0x68) = &D_800FC97C;
        M2C_FIELD(arg0, s8*, 5) = 6;
        ((void (*)(void*, s32))func_800179A4)(arg0, 0x1D);
        M2C_FIELD(arg0, s8*, 0x16) = 2;
    } else {
        if (M2C_FIELD(arg0, s8*, 2) == 20) {
            ((void (*)(void*, s32))func_800179A4)(arg0, 0x29);
            M2C_FIELD(arg0, s16*, 0x8C) = 0x78;
            M2C_FIELD(arg0, s8*, 5) = 6;
        } else if (M2C_FIELD(arg0, s8*, 2) == 21) {
            ((void (*)(void*, s32))func_800179A4)(arg0, 0x29);
            M2C_FIELD(arg0, s16*, 0x8C) = 0x3C;
            M2C_FIELD(arg0, s8*, 5) = 7;
        } else {
            func_80016C48(2, 0x6A, arg0);
            ((void (*)(void*, s32))func_800179A4)(
                arg0, M2C_FIELD(arg0, s8*, 2) - 0xB);
            M2C_FIELD(arg0, s16*, 0xA) =
                M2C_FIELD(arg0, s16*, 0xA) +
                ((s8)((u32)func_8002D2D4() % 7) * 16 - 0x30);
            M2C_FIELD(arg0, s16*, 0xE) =
                M2C_FIELD(arg0, s16*, 0xE) +
                ((s8)((u32)func_8002D2D4() % 7) * 16 - 0x30);
            M2C_FIELD(arg0, s8*, 0x15) = func_8002D2D4() & 0x40;
            M2C_FIELD(arg0, s8*, 5) = 5;
        }
        M2C_FIELD(arg0, s8*, 0x16) = 2;
    }
}
