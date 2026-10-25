#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD28 (*(s32*)0x1F800028)

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
s32 func_8002A47C(s32);
M2C_UNK func_8002B3D4(M2C_UNK, M2C_UNK*, M2C_UNK);
s32 func_80065944(s32);
s32 func_80065A14(s32);
s32 func_80065B74(s32, s32);
extern s32 D_8007429C;
extern M2C_UNK D_8007433C;
extern s32 D_8007541C;
extern s32 D_800754BC;
extern s32 D_80075B9C;
extern M2C_UNK g_Player;
extern s32 D_800FB300;
extern M2C_UNK D_800FB304;
extern s32 D_800FB308;
extern s32 D_800FB30C;
extern s32 D_800FB314;
extern s32 D_800FB318;

void func_800F38F4(void* arg0) {
    void* s2;
    s8 t;
    s32 ang;
    s32 v;
    s32 c;
    s32 d;
    void* g;
    s32 a;
    s32 b;

    s2 = M2C_FIELD(arg0, void**, 0x7C);
    g = &g_Player;
    M2C_FIELD(arg0, u8*, 4) = 1;
    M2C_FIELD(arg0, u8*, 6) = 0;
    M2C_FIELD(arg0, void**, 0x54) = 0;
    M2C_FIELD(arg0, void**, 0x50) = 0;
    M2C_FIELD(arg0, void**, 0x68) = 0;
    M2C_FIELD(arg0, u8*, 0x14) = M2C_FIELD(g, u8*, 0x14);
    t = M2C_FIELD(arg0, s8*, 2);
    M2C_FIELD(arg0, u8*, 0x16) = 4;
    M2C_FIELD(arg0, u8*, 0x15) = M2C_FIELD(s2, u8*, 0x15);
    if (t == 0) {
        M2C_FIELD(arg0, u8*, 0x60) = 6;
        M2C_FIELD(arg0, u8*, 0x5C) = 1;
        M2C_FIELD(arg0, void**, 0x58) = &D_8007429C;
        M2C_FIELD(arg0, void**, 0x54) = &D_800FB300;
        M2C_FIELD(arg0, void**, 0x50) = &D_800FB30C;
        M2C_FIELD(arg0, void**, 0x68) = &D_800FB318;
        ang =
            func_80065B74(M2C_FIELD(g, s16*, 0xE) - M2C_FIELD(arg0, s16*, 0xE),
                          M2C_FIELD(g, s16*, 0xA) - M2C_FIELD(arg0, s16*, 0xA));
        if (M2C_FIELD(s2, s8*, 2) == 0) {
            M2C_FIELD(arg0, s32*, 0x20) = func_80065A14(ang) * 32;
            M2C_FIELD(arg0, s32*, 0x24) = -func_80065944(ang) * 32;
        } else {
            c = func_80065A14(ang);
            v = c * 16;
            M2C_FIELD(arg0, s32*, 0x20) = c * 64 + v;
            d = -func_80065944(ang);
            v = d << 4;
            M2C_FIELD(arg0, s32*, 0x24) = (d << 6) + v;
        }
        ((void (*)(void*, M2C_UNK))func_800179A4)(arg0, 0xA);
        M2C_FIELD(arg0, u8*, 5) = 0;
        M2C_FIELD(arg0, u8*, 0x8D) = 8;
    } else if (t == 1) {
        M2C_FIELD(arg0, u8*, 0x60) = 0xC;
        M2C_FIELD(arg0, u8*, 0x5C) = 8;
        M2C_FIELD(arg0, void**, 0x58) = &D_800754BC;
        ((void (*)(void*, M2C_UNK))func_800179A4)(arg0, 0xC);
        M2C_FIELD(arg0, u8*, 5) = 1;
        M2C_FIELD(arg0, u8*, 0x8E) = 0;
        M2C_FIELD(arg0, s16*, 0x90) = 0;
        func_80016C48(2, 0x1F, arg0);
        if (M2C_FIELD(s2, s8*, 2) == 0) {
            M2C_FIELD(arg0, s16*, 0x42) =
                (((func_8002A47C(M2C_FIELD(s2, s8*, 1)) + 1) * 4 + 0x20) % 16) |
                (((func_8002A47C(M2C_FIELD(s2, s8*, 1)) + 9) / 4 + 0x1E0) << 6);
            a = func_8002A47C(M2C_FIELD(s2, s8*, 1)) * 4 + 0x20;
            func_8002B3D4(func_8002A47C(M2C_FIELD(s2, s8*, 1)) * 4 + 0x24,
                          (M2C_UNK*)(SPAD28 + a * 32), 4);
        } else {
            M2C_FIELD(arg0, s16*, 0x42) = 0x794C;
            func_8002B3D4(0x5C, (M2C_UNK*)(SPAD28 + 0xB00), 4);
        }
    } else if (t == 2) {
        M2C_FIELD(arg0, u8*, 0x60) = 0xC;
        M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
        M2C_FIELD(arg0, void**, 0x54) = &D_800FB300;
        M2C_FIELD(arg0, void**, 0x50) = &D_800FB30C;
        ((void (*)(void*, M2C_UNK))func_800179A4)(arg0, 0xD);
        M2C_FIELD(arg0, u8*, 0x8D) = 0x14;
        M2C_FIELD(arg0, u8*, 5) = 2;
    } else if (t == 3) {
        ((void (*)(void*, M2C_UNK))func_800179A4)(arg0, 0xE);
        M2C_FIELD(arg0, u8*, 5) = 4;
        M2C_FIELD(arg0, s16*, 0xA) += 8;
        func_80016C48(2, 0x1A, arg0);
    } else if (t == 4) {
        ((void (*)(void*, M2C_UNK))func_800179A4)(arg0, 0xF);
        M2C_FIELD(arg0, u8*, 5) = 5;
        M2C_FIELD(arg0, u8*, 0x16) = 6;
    } else if (t == 5) {
        ((void (*)(void*, M2C_UNK))func_800179A4)(arg0, 0x10);
        M2C_FIELD(arg0, u8*, 5) = 5;
    } else if (t == 6) {
        M2C_FIELD(arg0, u8*, 0x60) = 0xC;
        func_80016C48(2, 0x1F, arg0);
        M2C_FIELD(arg0, void**, 0x50) = &D_800FB30C;
        ((void (*)(void*, M2C_UNK))func_800179A4)(arg0, 0x14);
        M2C_FIELD(arg0, s16*, 0xA) = M2C_FIELD(s2, s16*, 0xA);
        M2C_FIELD(arg0, s16*, 0xE) = M2C_FIELD(s2, s16*, 0xE) - 0x18;
        M2C_FIELD(arg0, u8*, 0x16) = 6;
        M2C_FIELD(arg0, u8*, 5) = 6;
        M2C_FIELD(arg0, u8*, 0x8D) = 0;
        M2C_FIELD(arg0, u8*, 3) = 1;
        func_80016C48(2, 0x1F, arg0);
        M2C_FIELD(arg0, s16*, 0x42) = 0x794C;
        func_8002B3D4(0x5C, (M2C_UNK*)(SPAD28 + 0xB00), 4);
    } else if (t == 7) {
        M2C_FIELD(arg0, u8*, 0x60) = 0xC;
        func_80016C48(2, 0x1F, arg0);
        ((void (*)(void*, M2C_UNK))func_800179A4)(arg0, 0xC);
        M2C_FIELD(arg0, void**, 0x58) = &D_80075B9C;
        M2C_FIELD(arg0, void**, 0x54) = &D_800FB304;
        M2C_FIELD(arg0, u8*, 5) = 7;
        M2C_FIELD(arg0, u8*, 0x8D) = 0;
        M2C_FIELD(arg0, u8*, 3) = 1;
        M2C_FIELD(arg0, s16*, 0x42) = 0x794C;
        func_8002B3D4(0x5C, (M2C_UNK*)(SPAD28 + 0xB00), 4);
    } else if (t == 8) {
        M2C_FIELD(arg0, u8*, 0x60) = 0xC;
        M2C_FIELD(arg0, void**, 0x54) = &D_800FB300;
        M2C_FIELD(arg0, void**, 0x50) = &D_800FB30C;
        M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
        ((void (*)(void*, M2C_UNK))func_800179A4)(arg0, 0xD);
        M2C_FIELD(arg0, u8*, 0x8D) = 0x18;
        M2C_FIELD(arg0, u8*, 5) = 7;
        M2C_FIELD(arg0, u8*, 6) = 2;
    } else if (t == 9) {
        M2C_FIELD(arg0, u8*, 0x60) = 0xC;
        M2C_FIELD(arg0, u8*, 0x5C) = 0x20;
        M2C_FIELD(arg0, void**, 0x58) = &D_8007541C;
        M2C_FIELD(arg0, void**, 0x54) = &D_800FB308;
        M2C_FIELD(arg0, void**, 0x50) = &D_800FB314;
        if (M2C_FIELD(s2, u8*, 0x15) != 0) {
            M2C_FIELD(arg0, u8*, 0x15) = 0x40;
            M2C_FIELD(arg0, s16*, 0xA) = M2C_FIELD(s2, s16*, 0xA) - 0x30;
        } else {
            M2C_FIELD(arg0, u8*, 0x15) = 0;
            M2C_FIELD(arg0, s16*, 0xA) = M2C_FIELD(s2, s16*, 0xA) + 0x30;
        }
        M2C_FIELD(arg0, s16*, 0xE) = M2C_FIELD(s2, s16*, 0xE);
        ((void (*)(void*, M2C_UNK))func_800179A4)(arg0, 0x11);
        M2C_FIELD(arg0, u8*, 3) = 1;
        M2C_FIELD(arg0, u8*, 5) = 8;
    } else if (M2C_FIELD(arg0, s8*, 2) == 10) {
        M2C_FIELD(arg0, u8*, 0x60) = 0xC;
        M2C_FIELD(arg0, u8*, 0x5C) = 0x20;
        M2C_FIELD(arg0, void**, 0x58) = &D_8007541C;
        M2C_FIELD(arg0, void**, 0x54) = &D_800FB308;
        M2C_FIELD(arg0, void**, 0x50) = &D_800FB314;
        if (M2C_FIELD(s2, u8*, 0x15) == 0) {
            M2C_FIELD(arg0, u8*, 0x15) = 0x40;
            M2C_FIELD(arg0, s16*, 0xA) = M2C_FIELD(s2, s16*, 0xA) - 0x30;
        } else {
            M2C_FIELD(arg0, u8*, 0x15) = 0;
            M2C_FIELD(arg0, s16*, 0xA) = M2C_FIELD(s2, s16*, 0xA) + 0x30;
        }
        M2C_FIELD(arg0, s16*, 0xE) = M2C_FIELD(s2, s16*, 0xE);
        ((void (*)(void*, M2C_UNK))func_800179A4)(arg0, 0x11);
        M2C_FIELD(arg0, u8*, 3) = 1;
        M2C_FIELD(arg0, u8*, 5) = 8;
    } else if (M2C_FIELD(arg0, s8*, 2) == 11) {
        M2C_FIELD(arg0, u8*, 0x60) = 0xC;
        M2C_FIELD(arg0, u8*, 0x5C) = 2;
        func_80016C48(2, 0x1F, arg0);
        ((void (*)(void*, M2C_UNK))func_800179A4)(arg0, 0xC);
        M2C_FIELD(arg0, u8*, 5) = 9;
        M2C_FIELD(arg0, u8*, 0x8D) = 0;
        M2C_FIELD(arg0, u8*, 3) = 1;
        M2C_FIELD(arg0, void**, 0x58) = &D_80075B9C;
        M2C_FIELD(arg0, s16*, 0x42) = 0x794C;
        func_8002B3D4(0x5C, (M2C_UNK*)(SPAD28 + 0xB00), 4);
    }
}
