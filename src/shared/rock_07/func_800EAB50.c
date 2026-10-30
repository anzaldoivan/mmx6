#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define B(p, o) M2C_FIELD(p, u8*, o)
#define SB(p, o) M2C_FIELD(p, s8*, o)
#define H(p, o) M2C_FIELD(p, s16*, o)
#define W(p, o) M2C_FIELD(p, s32*, o)
#define P(p, o) M2C_FIELD(p, void**, o)

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK move_object();
extern s32 D_800741FC[];
extern struct X4_PlayerObj g_Player;
extern M2C_UNK D_800F8840;
extern M2C_UNK D_800F8844;
extern M2C_UNK D_800F884C;
extern M2C_UNK D_800F8850;
extern M2C_UNK D_800F8854;
extern M2C_UNK D_800F8858;

void func_800EAB50(void* arg0) {
    void* parent;
    s32 ang;
    s32 t;
    s32 dx;
    s32 dy;
    void* g;
    s32 sel;
    s32 a;
    s32 b;
    s32 v;

    parent = P(arg0, 0x7C);
    B(arg0, 0x60) = 0;
    B(arg0, 0x5C) = 1;
    B(arg0, 0x16) = 0x20;
    B(arg0, 0x67) = 1;
    P(arg0, 0x58) = D_800741FC;
    P(arg0, 0x68) = 0;
    P(arg0, 0x50) = 0;
    P(arg0, 0x54) = 0;
    B(arg0, 0x4) = 1;
    B(arg0, 0x5) = 0;
    B(arg0, 0x6) = 0;
    B(arg0, 0x7) = 0;
    W(arg0, 0x20) = 0;
    W(arg0, 0x24) = 0;
    W(arg0, 0x28) = 0;
    W(arg0, 0x2C) = 0;
    B(arg0, 0x91) = 0;
    B(arg0, 0x90) = 0;
    B(arg0, 0x92) = 0;
    sel = SB(arg0, 0x2) & 0xF0;
    if (sel == 0) {
        set_animation(arg0, 8);
        B(arg0, 0x60) = 2;
        P(arg0, 0x68) = &D_800F8840;
        P(arg0, 0x50) = &D_800F8844;
        W(arg0, 0x20) = 0;
        W(arg0, 0x24) = 0xFFFE0000;
        W(arg0, 0x2C) = 0x1800;
        move_object(arg0);
        B(arg0, 0x6) = 0;
        goto recheck;
    } else if (sel == 0x10) {
        play_sound(2, 0x4A, arg0);
        set_animation(arg0, 0xA);
        B(arg0, 0x60) = 4;
        P(arg0, 0x68) = &D_800F884C;
        P(arg0, 0x50) = &D_800F8850;
        g = &g_Player;
        dx = H(g, 0xA);
        dy = H(g, 0xE);
        ang = ratan2(H(arg0, 0xE) - dy, dx - H(arg0, 0xA));
        a = rcos(ang) << 4;
        W(arg0, 0x20) = (a << 2) + a;
        b = rsin(ang) << 4;
        W(arg0, 0x24) = (b << 2) + b;
        if (W(arg0, 0x20) != 0) {
            B(arg0, 0x15) = 0x40;
        } else {
            B(arg0, 0x15) = 0;
        }
        move_object(arg0);
        v = 1;
    } else if (sel == 0x20) {
        play_sound(2, 0x4B, arg0);
        set_animation(arg0, 9);
        {
            // !FAKE: depin: dropping it breaks the match (206/208)
            register s32 c4 asm("$2") = 4;
            // !FAKE: depin: dropping it breaks the match (205/208)
            register s32 c2 asm("$3") = 2;
            B(arg0, 0x60) = c4;
            B(arg0, 0x5C) = c2;
            P(arg0, 0x50) = &D_800F8854;
            P(arg0, 0x54) = &D_800F8858;
            B(arg0, 0x90) = 1;
            H(arg0, 0x88) = 0x3C;
        }
        if ((B(arg0, 0x2) & 0xF) == 1) {
            W(arg0, 0x20) = 0xFFFE8000;
            B(arg0, 0x15) = 0;
            H(arg0, 0xA) = H(arg0, 0xA) - 0x2C;
        } else {
            W(arg0, 0x20) = 0x18000;
            B(arg0, 0x15) = 0x40;
            H(arg0, 0xA) = H(arg0, 0xA) + 0x2C;
        }
        move_object(arg0);
        v = 2;
    } else if (sel == 0x30) {
        play_sound(2, 0x4C, arg0);
        set_animation(arg0, 0xB);
        {
            // !FAKE: depin: dropping it breaks the match (198/208)
            register s32 c6 asm("$2") = 6;
            // !FAKE: depin: dropping it breaks the match (194/208)
            register s32 cm asm("$3") = -0xC;
            B(arg0, 0x60) = c6;
            B(arg0, 0x8F) = 0x18;
            SB(arg0, 0x8D) = cm;
            P(arg0, 0x50) = (u8*)arg0 + 0x8C;
            t = SB(arg0, 0x45) << 4;
            B(arg0, 0x8C) = 0x7F - t;
            B(arg0, 0x8E) = t;
        }
        if (B(arg0, 0x15) == 0) {
            H(arg0, 0xA) = H(parent, 0xA) - 0xA4;
        } else {
            H(arg0, 0xA) = H(parent, 0xA) + 0xA4;
        }
        v = 3;
    } else {
        goto check;
    }
    B(arg0, 0x6) = v;
recheck:
    if ((SB(arg0, 0x2) & 0xF0) == 0x30) {
        return;
    }
check:
    if (func_8002CBFC(arg0, 0x20, 0x20) == 0) {
        func_8002CCB0(arg0, 0x10, 0x10);
        v = B(arg0, 0x92);
        if (v != 0) {
            B(arg0, 0x3) = 0;
        }
    } else {
        B(arg0, 0x4) = 2;
    }
}
