#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* func_8002C530();
M2C_UNK func_8002D2B0(s32);
M2C_UNK func_80030ECC();
void func_800F20BC(void* arg0);
s32 func_800F2100(void* arg0);
s32 func_800F2158(void* arg0);
extern u8 D_800FBFE4[][2];
extern u8 D_800FBFF4[][2];

void func_800F01DC(void* arg0) {
    void* parent;
    void* m1;
    void* m2;
    void* m3;
    void* m4;
    void* m5;
    void* m6;
    void* m7;
    void* m8;
    void* m9;
    u16 i;
    u16 t;
    s32 r;

    parent = M2C_FIELD(arg0, void**, 0x7C);
    parent = M2C_FIELD(arg0, void**, 0x7C);
    if (func_800F2158(arg0) == 0) {
        M2C_FIELD(arg0, u8*, 0x5) = 0;
        M2C_FIELD(arg0, u8*, 0x4)++;
        m7 = func_8002C530();
        if (m7 != 0) {
            do {
                M2C_FIELD(m7, u8*, 0x0) = 0x41;
                M2C_FIELD(m7, u8*, 0x1) = 7;
                M2C_FIELD(m7, u8*, 0x2) = 1;
                M2C_FIELD(m7, u8*, 0x15) = M2C_FIELD(arg0, u8*, 0x15);
                M2C_FIELD(m7, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
                M2C_FIELD(m7, u16*, 0x42) =
                    M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
                M2C_FIELD(m7, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
                M2C_FIELD(m7, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
                M2C_FIELD(m7, u8*, 0x14) = M2C_FIELD(arg0, u8*, 0x14);
            } while (0);
            t = M2C_FIELD(arg0, u16*, 0x92);
            M2C_FIELD(m7, u16*, 0x8) = 0;
            M2C_FIELD(m7, u16*, 0xA) = t;
            M2C_FIELD(m7, u16*, 0xE) = M2C_FIELD(arg0, u16*, 0x94);
            M2C_FIELD(m7, u16*, 0xC) = 0;
            M2C_FIELD(m7, void**, 0x50) = arg0;
            M2C_FIELD(m7, u8*, 0x16) = 5;
            i = M2C_FIELD(arg0, u16*, 0x84);
            M2C_FIELD(m7, u16*, 0x54) = i;
            M2C_FIELD(m7, u16*, 0x56) = M2C_FIELD(arg0, u16*, 0x96);
            M2C_FIELD(m7, u8*, 0x47) =
                D_800FBFF4[(s16)i][0] + M2C_FIELD(m7, u8*, 0x56);
            M2C_FIELD(m7, u8*, 0x15) = D_800FBFF4[(s16)i][1];
            M2C_FIELD(m7, u8*, 0x0) = 0x51;
        }
        m8 = func_8002C530();
        if (m8 != 0) {
            do {
                M2C_FIELD(m8, u8*, 0x0) = 0x41;
                M2C_FIELD(m8, u8*, 0x1) = 7;
                M2C_FIELD(m8, u8*, 0x2) = 0;
                M2C_FIELD(m8, u8*, 0x15) = M2C_FIELD(arg0, u8*, 0x15);
                M2C_FIELD(m8, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
                M2C_FIELD(m8, u16*, 0x42) =
                    M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
                M2C_FIELD(m8, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
                M2C_FIELD(m8, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
                M2C_FIELD(m8, u8*, 0x14) = M2C_FIELD(arg0, u8*, 0x14);
            } while (0);
            M2C_FIELD(m8, u16*, 0xA) = M2C_FIELD(arg0, u16*, 0x92);
            M2C_FIELD(m8, u16*, 0x8) = M2C_FIELD(arg0, u16*, 0x94);
            M2C_FIELD(m8, u16*, 0xE) = M2C_FIELD(arg0, u16*, 0xA);
            M2C_FIELD(m8, u16*, 0xC) = M2C_FIELD(arg0, u16*, 0xE);
            M2C_FIELD(m8, void**, 0x50) = arg0;
            M2C_FIELD(m8, u8*, 0x16) = 6;
            M2C_FIELD(m8, u16*, 0x54) = M2C_FIELD(arg0, u16*, 0x84);
            M2C_FIELD(m8, u16*, 0x56) = M2C_FIELD(arg0, u16*, 0x88);
            M2C_FIELD(m8, u8*, 0x0) = 0x51;
        }
        m9 = func_8002C530();
        if (m9 != 0) {
            do {
                M2C_FIELD(m9, u8*, 0x0) = 0x41;
                M2C_FIELD(m9, u8*, 0x1) = 7;
                M2C_FIELD(m9, u8*, 0x2) = 1;
                M2C_FIELD(m9, u8*, 0x15) = M2C_FIELD(arg0, u8*, 0x15);
                M2C_FIELD(m9, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
                M2C_FIELD(m9, u16*, 0x42) =
                    M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
                M2C_FIELD(m9, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
                M2C_FIELD(m9, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
                M2C_FIELD(m9, u8*, 0x14) = M2C_FIELD(arg0, u8*, 0x14);
            } while (0);
            t = M2C_FIELD(arg0, u16*, 0xA);
            M2C_FIELD(m9, u16*, 0x8) = 0;
            M2C_FIELD(m9, u16*, 0xA) = t;
            M2C_FIELD(m9, u16*, 0xE) = M2C_FIELD(arg0, u16*, 0xE);
            M2C_FIELD(m9, u16*, 0xC) = 0;
            M2C_FIELD(m9, void**, 0x50) = arg0;
            M2C_FIELD(m9, u8*, 0x16) = 4;
            i = M2C_FIELD(arg0, u16*, 0x84);
            M2C_FIELD(m9, u16*, 0x54) = i;
            M2C_FIELD(m9, u16*, 0x56) = M2C_FIELD(arg0, u16*, 0x88);
            M2C_FIELD(m9, u8*, 0x47) =
                D_800FBFE4[(s16)i][0] + M2C_FIELD(m9, u8*, 0x56);
            M2C_FIELD(m9, u8*, 0x15) = D_800FBFE4[(s16)i][1];
            M2C_FIELD(m9, u8*, 0x0) = 0x51;
        }
        return;
    }
    func_800F20BC(arg0);
    func_80030ECC(arg0);
    r = M2C_FIELD(arg0, u16*, 0x8A);
    if (M2C_FIELD(arg0, s16*, 0x8A) == 0) {
        goto main;
    }
    r--;
    M2C_FIELD(arg0, u16*, 0x8A) = r;
    if ((s16)r != 0) {
        goto main;
    }
    M2C_FIELD(parent, u8*, 0x89) = 2;
    M2C_FIELD(arg0, u8*, 0x5) = 0;
    M2C_FIELD(arg0, u8*, 0x4)++;
    m1 = func_8002C530();
    if (m1 != 0) {
        do {
            M2C_FIELD(m1, u8*, 0x0) = 0x41;
            M2C_FIELD(m1, u8*, 0x1) = 7;
            M2C_FIELD(m1, u8*, 0x2) = 1;
            M2C_FIELD(m1, u8*, 0x15) = M2C_FIELD(arg0, u8*, 0x15);
            M2C_FIELD(m1, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
            M2C_FIELD(m1, u16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
            M2C_FIELD(m1, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
            M2C_FIELD(m1, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
            M2C_FIELD(m1, u8*, 0x14) = M2C_FIELD(arg0, u8*, 0x14);
        } while (0);
        t = M2C_FIELD(arg0, u16*, 0x92);
        M2C_FIELD(m1, u16*, 0x8) = 0;
        M2C_FIELD(m1, u16*, 0xA) = t;
        M2C_FIELD(m1, u16*, 0xE) = M2C_FIELD(arg0, u16*, 0x94);
        M2C_FIELD(m1, u16*, 0xC) = 0;
        M2C_FIELD(m1, void**, 0x50) = arg0;
        M2C_FIELD(m1, u8*, 0x16) = 5;
        i = M2C_FIELD(arg0, u16*, 0x84);
        M2C_FIELD(m1, u16*, 0x54) = i;
        M2C_FIELD(m1, u16*, 0x56) = M2C_FIELD(arg0, u16*, 0x96);
        M2C_FIELD(m1, u8*, 0x47) =
            D_800FBFF4[(s16)i][0] + M2C_FIELD(m1, u8*, 0x56);
        M2C_FIELD(m1, u8*, 0x15) = D_800FBFF4[(s16)i][1];
        M2C_FIELD(m1, u8*, 0x0) = 0x51;
    }
    m2 = func_8002C530();
    if (m2 != 0) {
        do {
            M2C_FIELD(m2, u8*, 0x0) = 0x41;
            M2C_FIELD(m2, u8*, 0x1) = 7;
            M2C_FIELD(m2, u8*, 0x2) = 0;
            M2C_FIELD(m2, u8*, 0x15) = M2C_FIELD(arg0, u8*, 0x15);
            M2C_FIELD(m2, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
            M2C_FIELD(m2, u16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
            M2C_FIELD(m2, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
            M2C_FIELD(m2, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
            M2C_FIELD(m2, u8*, 0x14) = M2C_FIELD(arg0, u8*, 0x14);
        } while (0);
        M2C_FIELD(m2, u16*, 0xA) = M2C_FIELD(arg0, u16*, 0x92);
        M2C_FIELD(m2, u16*, 0x8) = M2C_FIELD(arg0, u16*, 0x94);
        M2C_FIELD(m2, u16*, 0xE) = M2C_FIELD(arg0, u16*, 0xA);
        M2C_FIELD(m2, u16*, 0xC) = M2C_FIELD(arg0, u16*, 0xE);
        M2C_FIELD(m2, void**, 0x50) = arg0;
        M2C_FIELD(m2, u8*, 0x16) = 6;
        M2C_FIELD(m2, u16*, 0x54) = M2C_FIELD(arg0, u16*, 0x84);
        M2C_FIELD(m2, u16*, 0x56) = M2C_FIELD(arg0, u16*, 0x88);
        M2C_FIELD(m2, u8*, 0x0) = 0x51;
    }
    m3 = func_8002C530();
    if (m3 != 0) {
        do {
            M2C_FIELD(m3, u8*, 0x0) = 0x41;
            M2C_FIELD(m3, u8*, 0x1) = 7;
            M2C_FIELD(m3, u8*, 0x2) = 1;
            M2C_FIELD(m3, u8*, 0x15) = M2C_FIELD(arg0, u8*, 0x15);
            M2C_FIELD(m3, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
            M2C_FIELD(m3, u16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
            M2C_FIELD(m3, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
            M2C_FIELD(m3, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
            M2C_FIELD(m3, u8*, 0x14) = M2C_FIELD(arg0, u8*, 0x14);
        } while (0);
        t = M2C_FIELD(arg0, u16*, 0xA);
        M2C_FIELD(m3, u16*, 0x8) = 0;
        M2C_FIELD(m3, u16*, 0xA) = t;
        M2C_FIELD(m3, u16*, 0xE) = M2C_FIELD(arg0, u16*, 0xE);
        M2C_FIELD(m3, u16*, 0xC) = 0;
        M2C_FIELD(m3, void**, 0x50) = arg0;
        M2C_FIELD(m3, u8*, 0x16) = 4;
        i = M2C_FIELD(arg0, u16*, 0x84);
        M2C_FIELD(m3, u16*, 0x54) = i;
        M2C_FIELD(m3, u16*, 0x56) = M2C_FIELD(arg0, u16*, 0x88);
        M2C_FIELD(m3, u8*, 0x47) =
            D_800FBFE4[(s16)i][0] + M2C_FIELD(m3, u8*, 0x56);
        M2C_FIELD(m3, u8*, 0x15) = D_800FBFE4[(s16)i][1];
        M2C_FIELD(m3, u8*, 0x0) = 0x51;
    }
    return;
main:
    if (func_800F2100(arg0) == 0 && M2C_FIELD(arg0, s16*, 0x88) == 0 &&
        M2C_FIELD(arg0, s8*, 0x98) != 2) {
        ((void (*)(void*))func_8002D2B0)(arg0);
        if (M2C_FIELD(arg0, s16*, 0xA) < 0) {
            M2C_FIELD(arg0, s16*, 0xA) = 0;
        }
        if (M2C_FIELD(arg0, s16*, 0xE) < 0) {
            M2C_FIELD(arg0, s16*, 0xE) = 0;
        }
    }
    m4 = func_8002C530();
    if (m4 != 0) {
        do {
            M2C_FIELD(m4, u8*, 0x0) = 0x41;
            M2C_FIELD(m4, u8*, 0x1) = 7;
            M2C_FIELD(m4, u8*, 0x2) = 1;
            M2C_FIELD(m4, u8*, 0x15) = M2C_FIELD(arg0, u8*, 0x15);
            M2C_FIELD(m4, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
            M2C_FIELD(m4, u16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
            M2C_FIELD(m4, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
            M2C_FIELD(m4, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
            M2C_FIELD(m4, u8*, 0x14) = M2C_FIELD(arg0, u8*, 0x14);
        } while (0);
        t = M2C_FIELD(arg0, u16*, 0x92);
        M2C_FIELD(m4, u16*, 0x8) = 0;
        M2C_FIELD(m4, u16*, 0xA) = t;
        M2C_FIELD(m4, u16*, 0xE) = M2C_FIELD(arg0, u16*, 0x94);
        M2C_FIELD(m4, u16*, 0xC) = 0;
        M2C_FIELD(m4, void**, 0x50) = arg0;
        M2C_FIELD(m4, u8*, 0x16) = 5;
        i = M2C_FIELD(arg0, u16*, 0x84);
        M2C_FIELD(m4, u16*, 0x54) = i;
        M2C_FIELD(m4, u16*, 0x56) = M2C_FIELD(arg0, u16*, 0x96);
        M2C_FIELD(m4, u8*, 0x47) =
            D_800FBFF4[(s16)i][0] + M2C_FIELD(m4, u8*, 0x56);
        M2C_FIELD(m4, u8*, 0x15) = D_800FBFF4[(s16)i][1];
    }
    m5 = func_8002C530();
    if (m5 != 0) {
        do {
            M2C_FIELD(m5, u8*, 0x0) = 0x41;
            M2C_FIELD(m5, u8*, 0x1) = 7;
            M2C_FIELD(m5, u8*, 0x2) = 0;
            M2C_FIELD(m5, u8*, 0x15) = M2C_FIELD(arg0, u8*, 0x15);
            M2C_FIELD(m5, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
            M2C_FIELD(m5, u16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
            M2C_FIELD(m5, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
            M2C_FIELD(m5, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
            M2C_FIELD(m5, u8*, 0x14) = M2C_FIELD(arg0, u8*, 0x14);
        } while (0);
        M2C_FIELD(m5, u16*, 0xA) = M2C_FIELD(arg0, u16*, 0x92);
        M2C_FIELD(m5, u16*, 0x8) = M2C_FIELD(arg0, u16*, 0x94);
        M2C_FIELD(m5, u16*, 0xE) = M2C_FIELD(arg0, u16*, 0xA);
        M2C_FIELD(m5, u16*, 0xC) = M2C_FIELD(arg0, u16*, 0xE);
        M2C_FIELD(m5, void**, 0x50) = arg0;
        M2C_FIELD(m5, u8*, 0x16) = 6;
        M2C_FIELD(m5, u16*, 0x54) = M2C_FIELD(arg0, u16*, 0x84);
        M2C_FIELD(m5, u16*, 0x56) = M2C_FIELD(arg0, u16*, 0x88);
    }
    m6 = func_8002C530();
    if (m6 != 0) {
        do {
            M2C_FIELD(m6, u8*, 0x0) = 0x41;
            M2C_FIELD(m6, u8*, 0x1) = 7;
            M2C_FIELD(m6, u8*, 0x2) = 1;
            M2C_FIELD(m6, u8*, 0x15) = M2C_FIELD(arg0, u8*, 0x15);
            M2C_FIELD(m6, u16*, 0x40) = M2C_FIELD(arg0, u16*, 0x40);
            M2C_FIELD(m6, u16*, 0x42) = M2C_FIELD(arg0, u16*, 0x42) & 0x7FFF;
            M2C_FIELD(m6, s32*, 0x30) = M2C_FIELD(arg0, s32*, 0x30);
            M2C_FIELD(m6, s32*, 0x3C) = M2C_FIELD(arg0, s32*, 0x3C);
            M2C_FIELD(m6, u8*, 0x14) = M2C_FIELD(arg0, u8*, 0x14);
        } while (0);
        t = M2C_FIELD(arg0, u16*, 0xA);
        M2C_FIELD(m6, u16*, 0x8) = 0;
        M2C_FIELD(m6, u16*, 0xA) = t;
        M2C_FIELD(m6, u16*, 0xE) = M2C_FIELD(arg0, u16*, 0xE);
        M2C_FIELD(m6, u16*, 0xC) = 0;
        M2C_FIELD(m6, void**, 0x50) = arg0;
        M2C_FIELD(m6, u8*, 0x16) = 4;
        i = M2C_FIELD(arg0, u16*, 0x84);
        M2C_FIELD(m6, u16*, 0x54) = i;
        M2C_FIELD(m6, u16*, 0x56) = M2C_FIELD(arg0, u16*, 0x88);
        M2C_FIELD(m6, u8*, 0x47) =
            D_800FBFE4[(s16)i][0] + M2C_FIELD(m6, u8*, 0x56);
        M2C_FIELD(m6, u8*, 0x15) = D_800FBFE4[(s16)i][1];
    }
    M2C_FIELD(arg0, s16*, 0x88) = (s16)(M2C_FIELD(arg0, s16*, 0x88) + 1) % 3;
    r = M2C_FIELD(arg0, u16*, 0x96) + 1;
    M2C_FIELD(arg0, u16*, 0x96) = (u16)r % 5;
}
