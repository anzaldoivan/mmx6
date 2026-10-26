#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
extern s32 D_8007429C;
extern M2C_UNK D_8007433C;
extern struct X4_PlayerObj g_Player;
extern s16 D_80097202;
extern u8 D_800CCF38;
extern s32 D_800FCF28;
extern s32 D_800FCF2C;
extern s32 D_800FCF30;
extern s32 D_800FCF34;
extern s32 D_800FCF38;
extern s32 D_800FCF3C;

void func_800F60AC(void* arg0) {
    s32 k;
    s8 t;
    s8 sub;
    s32 ang;
    s32 c;
    s32 dx;
    s32 dy;
    void* g;

    t = M2C_FIELD(M2C_FIELD(arg0, void**, 0x7C), s8*, 4);
    if (t != 1) {
        M2C_FIELD(arg0, u8*, 4) = 3;
        M2C_FIELD(arg0, u8*, 3) = 0;
        return;
    }
    M2C_FIELD(arg0, u8*, 0x60) = 0;
    M2C_FIELD(arg0, u8*, 0x5C) = t;
    M2C_FIELD(arg0, u8*, 0x16) = 4;
    M2C_FIELD(arg0, u8*, 0x67) = t;
    M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
    M2C_FIELD(arg0, void**, 0x68) = 0;
    M2C_FIELD(arg0, void**, 0x50) = 0;
    M2C_FIELD(arg0, void**, 0x54) = 0;
    M2C_FIELD(arg0, u8*, 4) = t;
    M2C_FIELD(arg0, u8*, 5) = 0;
    M2C_FIELD(arg0, u8*, 6) = 0;
    M2C_FIELD(arg0, u8*, 7) = 0;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    k = M2C_FIELD(arg0, s8*, 2) & 0xF0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    if (k == 0) {
        func_800179A4(arg0, 3);
        M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
        M2C_FIELD(arg0, void**, 0x54) = &D_800FCF28;
        M2C_FIELD(arg0, void**, 0x50) = &D_800FCF2C;
        M2C_FIELD(arg0, u8*, 0x60) = 8;
        if (M2C_FIELD(arg0, s8*, 2) == 0) {
            M2C_FIELD(arg0, u8*, 0x16) = 4;
            M2C_FIELD(arg0, s32*, 0x24) = 0;
            if (M2C_FIELD(arg0, s16*, 0xA) >= D_80097202 + 0xA0) {
                M2C_FIELD(arg0, u8*, 0x15) = 0;
                M2C_FIELD(arg0, s32*, 0x20) = -0x20000;
            } else {
                M2C_FIELD(arg0, u8*, 0x15) = 0x40;
                M2C_FIELD(arg0, s32*, 0x20) = 0x20000;
            }
            M2C_FIELD(arg0, u8*, 5) = 1;
        } else {
            M2C_FIELD(arg0, u8*, 0x16) = 4;
            if (M2C_FIELD(arg0, s16*, 0xA) >= D_80097202 + 0xA0) {
                M2C_FIELD(arg0, u8*, 0x15) = 0;
            } else {
                M2C_FIELD(arg0, u8*, 0x15) = 0x40;
            }
            M2C_FIELD(arg0, u8*, 5) = 2;
        }
    } else if (k == 0x10) {
        func_80016C48(2, 0x58, arg0);
        func_800179A4(arg0, 0x1C);
        M2C_FIELD(arg0, u8*, 0x60) = 4;
        M2C_FIELD(arg0, void**, 0x58) = &D_8007429C;
        M2C_FIELD(arg0, void**, 0x54) = &D_800FCF30;
        M2C_FIELD(arg0, void**, 0x50) = &D_800FCF34;
        M2C_FIELD(arg0, u8*, 0x16) = 4;
        M2C_FIELD(arg0, u8*, 0x15) = 0;
        switch (M2C_FIELD(arg0, s8*, 2)) {
        case 0x10:
            M2C_FIELD(arg0, s32*, 0x20) = 0;
            M2C_FIELD(arg0, s32*, 0x24) = 0x20000;
            break;
        case 0x11:
            M2C_FIELD(arg0, s32*, 0x20) = -0x20000;
            M2C_FIELD(arg0, s32*, 0x24) = 0;
            break;
        case 0x12:
            M2C_FIELD(arg0, s32*, 0x20) = 0;
            M2C_FIELD(arg0, s32*, 0x24) = -0x20000;
            break;
        case 0x13:
            M2C_FIELD(arg0, s32*, 0x20) = 0x20000;
            M2C_FIELD(arg0, s32*, 0x24) = 0;
            break;
        }
        if (D_800CCF38 >= 2) {
            M2C_FIELD(arg0, s32*, 0x20) = M2C_FIELD(arg0, s32*, 0x20) * 3 / 2;
            M2C_FIELD(arg0, s32*, 0x24) = M2C_FIELD(arg0, s32*, 0x24) * 3 / 2;
        }
        M2C_FIELD(arg0, u8*, 5) = 3;
    } else if (k == 0x20) {
        func_800179A4(arg0, 3);
        M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
        sub = M2C_FIELD(arg0, s8*, 2);
        M2C_FIELD(arg0, void**, 0x54) = &D_800FCF28;
        M2C_FIELD(arg0, void**, 0x50) = &D_800FCF2C;
        M2C_FIELD(arg0, u8*, 0x60) = 8;
        M2C_FIELD(arg0, u8*, 0x16) = 4;
        if (sub == 0x20) {
            M2C_FIELD(arg0, u8*, 5) = 4;
        } else if (sub == 0x21) {
            M2C_FIELD(arg0, u8*, 5) = 5;
        }
    } else if (k == 0x30) {
        func_80016C48(2, 0x58, arg0);
        func_800179A4(arg0, 0x22);
        M2C_FIELD(arg0, u8*, 3) = t;
        M2C_FIELD(arg0, void**, 0x58) = &D_8007433C;
        M2C_FIELD(arg0, void**, 0x54) = 0;
        M2C_FIELD(arg0, void**, 0x50) = &D_800FCF38;
        M2C_FIELD(arg0, void**, 0x68) = &D_800FCF3C;
        M2C_FIELD(arg0, u8*, 0x60) = 8;
        M2C_FIELD(arg0, u8*, 0x16) = 4;
        g = &g_Player;
        dx = M2C_FIELD(g, s16*, 0xA);
        dy = M2C_FIELD(g, s16*, 0xE);
        ang = ratan2(M2C_FIELD(arg0, s16*, 0xE) - dy,
                     dx - M2C_FIELD(arg0, s16*, 0xA));
        M2C_FIELD(arg0, s32*, 0x20) = rcos(ang) << 5;
        c = rsin(ang);
        M2C_FIELD(arg0, s32*, 0x24) = c << 5;
        if (D_800CCF38 >= 2) {
            M2C_FIELD(arg0, s32*, 0x24) = c << 6;
            M2C_FIELD(arg0, s32*, 0x20) = M2C_FIELD(arg0, s32*, 0x20) * 2;
        }
        if (M2C_FIELD(arg0, s32*, 0x20) != 0) {
            M2C_FIELD(arg0, u8*, 0x15) = 0x40;
        } else {
            M2C_FIELD(arg0, u8*, 0x15) = 0;
        }
        M2C_FIELD(arg0, u8*, 5) = 6;
    }
}
