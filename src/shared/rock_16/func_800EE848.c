#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define S8(o) M2C_FIELD(arg0, s8*, o)
#define U8(o) M2C_FIELD(arg0, u8*, o)
#define U16(o) M2C_FIELD(arg0, u16*, o)
#define S16(o) M2C_FIELD(arg0, s16*, o)
#define PTR(o) M2C_FIELD(arg0, void**, o)
#define SCRATCH_PTR (*(u8**)0x1F800020)

M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_800179D0(void*, M2C_UNK, s8);
M2C_UNK func_8002C9B0();
s32 func_800EC1FC(s32);
extern struct X4_EngineObj D_800CCED0;
extern s8 D_800CCEF9;
extern s8 D_800CCEFA;
extern u16 D_800F12A8[][2];
extern u16 D_800F1328[][2];
extern u16 D_800F1520[][2];
extern u8 D_800F1538[];
extern s8 D_800F1CD0[][5];
extern s8 D_800F1CE0[][5];

#define ENG_29 (D_800CCED0.character_state.bytes[3])
#define ENG_2A (D_800CCED0.character_state.bytes[4])

void func_800EE848(void* arg0) {
    u8* p;
    s8 v;
    s8 i;
    s8 t;
    s8 j;

    S16(0x40) = 0x1800;
    p = SCRATCH_PTR;
    v = S8(2);
    PTR(0x3C) = p + *(s32*)(p + 4);
    PTR(0x30) = D_800F1538;
    if (v < 0x20) {
        if (v >= 0x18) {
            ((void (*)(void*, s32, s8))func_800179D0)(arg0, 0, v);
        } else if (func_800EC1FC(v) != 0) {
            ((void (*)(void*, s32, s8))func_800179D0)(arg0, 1, S8(2));
        } else {
            ((void (*)(void*, s32, s8))func_800179D0)(arg0, 0, S8(2));
        }
        U16(0xA) = D_800F12A8[S8(2)][0];
        U16(0xE) = D_800F12A8[S8(2)][1];
        U8(0x16) = 3;
        U8(0x5) = 0;
    } else if (v == 0x20 || v == 0x23) {
        if (!(D_800CCED0.unk5F & 0x10) || D_800CCED0.unk1 == 6) {
            ((void (*)(void*, s32, s8))func_800179D0)(arg0, 2, 1);
        } else if (D_800CCED0.unk1 == 5) {
            ((void (*)(void*, s32, s8))func_800179D0)(arg0, 2, 0);
        }
        if (S8(2) == 0x20) {
            U16(0xA) = 0x2D6;
        } else {
            U16(0xA) = 0x8D6;
        }
        U16(0xE) = 0x88;
        U8(0x16) = 3;
        U8(0x5) = 1;
    } else if (v == 0x21 || v == 0x24) {
        PTR(0x3C) = SCRATCH_PTR + *(s32*)(SCRATCH_PTR + 0xC);
        ((void (*)(void*, s32, s8))func_800179D0)(arg0, 3, D_800CCEFA);
        if (S8(2) == 0x21) {
            U16(0xA) = 0x2D0;
        } else {
            U16(0xA) = 0x8D0;
        }
        U16(0xE) = 0x98;
        U8(0x16) = 3;
        U8(0x5) = 2;
    } else if (v == 0x22 || v == 0x25) {
        func_8002C9B0(arg0);
        return;
    } else if ((u8)(U8(2) - 0x26) < 2) {
        ((void (*)(void*, s32))func_800179A4)(arg0, 5);
        if (S8(2) == 0x26) {
            U16(0xA) = D_800F12A8[ENG_2A][0];
        } else {
            U16(0xA) = D_800F12A8[ENG_2A][0] + 0x600;
        }
        U16(0xE) = D_800F12A8[ENG_2A][1];
        U8(0x16) = 1;
        U8(0x5) = 4;
    } else if (v < 0x2D) {
        S8(2) -= 0x28;
        ((void (*)(void*, s32, s8))func_800179D0)(
            arg0, 6, D_800F1CE0[D_800CCEF9][S8(2)]);
        U16(0xA) = D_800F1328[S8(2)][0];
        U16(0xE) = D_800F1328[S8(2)][1];
        U8(0x16) = 3;
        U8(0x5) = 5;
    } else if (v < 0x32) {
        S8(2) -= 0x2D;
        ((void (*)(void*, s32))func_800179A4)(arg0, 7);
        i = S8(2);
        if (D_800F1CD0[ENG_29][i] != -1) {
            U16(0xA) = D_800F12A8[D_800F1CD0[ENG_29][i]][0];
            U16(0xE) = D_800F12A8[D_800F1CD0[ENG_29][i]][1];
        } else {
            U8(0x3) = 0;
        }
        U8(0x16) = 2;
        U8(0x5) = 6;
    } else if (S8(2) < 0x37) {
        S8(2) -= 0x32;
        t = D_800F1CD0[D_800CCEF9][S8(2)];
        if (t != -1) {
            ((void (*)(void*, s32, s8))func_800179D0)(arg0, 0, t);
        }
        U16(0xA) = D_800F1328[S8(2)][0];
        U16(0xE) = D_800F1328[S8(2)][1];
        U8(0x16) = 2;
        U8(0x5) = 7;
    } else if (S8(2) < 0x3D) {
        S8(2) -= 0x37;
        ((void (*)(void*, s32, s8))func_800179D0)(arg0, 8, S8(2));
        j = S8(2);
        U16(0xA) = D_800F1520[j][0];
        U16(0xE) = D_800F1520[j][1];
        if (j == 1) {
            U8(0x16) = 7;
        } else {
            U8(0x16) = 1;
        }
        U8(0x5) = 8;
    } else if (S8(2) == 0x3D) {
        ((void (*)(void*, s32))func_800179A4)(arg0, 9);
        U16(0xA) = D_800F12A8[ENG_2A][0];
        U16(0xE) = D_800F12A8[ENG_2A][1];
        U8(0x16) = 1;
        U8(0x5) = 9;
    }
    U8(0x14) = 1;
    U8(0x4)++;
}
