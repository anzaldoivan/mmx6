#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80017A04();
s32 func_8002D2D4();
void func_800FA140(void* arg0);
extern s16 D_800970AE;
extern s32 D_800FC954;
extern u8 D_800FD59C;

void func_800F6594(void* arg0) {
    void* s0;
    s16 r;
    s16 v;

    r = func_8002D2D4() & 3;
    s0 = M2C_FIELD(arg0, void**, 0x88);
    func_80017A04(arg0);
    func_800FA140(arg0);
    v = M2C_FIELD(s0, s16*, 0x7C);
    if (v == 0) {
        if (r == 0) {
            if (M2C_FIELD(arg0, s8*, 2) == 3) {
                M2C_FIELD(arg0, s16*, 0x7E) = 1;
                M2C_FIELD(arg0, u8*, 0x93) = 3;
            } else {
                M2C_FIELD(arg0, s16*, 0x7E) = 3;
                M2C_FIELD(arg0, u8*, 0x93) = D_800FD59C;
            }
        } else if (r == 1) {
            if (M2C_FIELD(arg0, s8*, 2) == 3) {
                M2C_FIELD(arg0, s16*, 0x7E) = 2;
                M2C_FIELD(arg0, u8*, 0x93) = 0;
            } else {
                M2C_FIELD(arg0, s16*, 0x7E) = 3;
                M2C_FIELD(arg0, u8*, 0x93) = D_800FD59C;
            }
        } else if (r == 2) {
            M2C_FIELD(arg0, s16*, 0x7E) = 1;
            M2C_FIELD(arg0, u8*, 0x93) = 3;
        } else if (r == 3) {
            M2C_FIELD(arg0, s16*, 0x7E) = 3;
            M2C_FIELD(arg0, u8*, 0x93) = D_800FD59C;
        }
        M2C_FIELD(arg0, s16*, 0x7C) = 0x90;
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = -0x8000;
        func_800179A4(arg0, 0xF);
    } else if (v == 1) {
        if (r < 2) {
            if (M2C_FIELD(arg0, s8*, 2) == 3) {
                M2C_FIELD(arg0, s16*, 0x7E) = 0;
                M2C_FIELD(arg0, u8*, 0x93) = 0;
            } else {
                M2C_FIELD(arg0, s16*, 0x7E) = 3;
                M2C_FIELD(arg0, u8*, 0x93) = D_800FD59C;
            }
        } else {
            M2C_FIELD(arg0, s16*, 0x7E) = 3;
            M2C_FIELD(arg0, u8*, 0x93) = D_800FD59C;
        }
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, s32*, 0x24) = 0x8000;
        M2C_FIELD(arg0, s16*, 0x7C) = 0x90;
        func_800179A4(arg0, 0xE);
    } else if (v == 2) {
        if (r < 2) {
            if (M2C_FIELD(arg0, s8*, 2) == 3) {
                M2C_FIELD(arg0, s16*, 0x7E) = 2;
                M2C_FIELD(arg0, u8*, 0x93) = 0;
                func_800179A4(arg0, 0xF);
            } else {
                M2C_FIELD(arg0, s16*, 0x7E) = 3;
                M2C_FIELD(arg0, u8*, 0x93) = D_800FD59C;
                func_800179A4(arg0, 0xC);
            }
        } else {
            M2C_FIELD(arg0, s16*, 0x7E) = 3;
            M2C_FIELD(arg0, u8*, 0x93) = D_800FD59C;
            func_800179A4(arg0, 0xC);
        }
        M2C_FIELD(arg0, s32*, 0x20) = 0x8000;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s16*, 0x7C) = 0xB0;
    } else if (v == 3) {
        if (r < 2) {
            if (M2C_FIELD(arg0, s8*, 2) == 3) {
                M2C_FIELD(arg0, s16*, 0x7E) = 2;
                M2C_FIELD(arg0, u8*, 0x93) = 0;
                func_800179A4(arg0, 0xF);
            } else {
                M2C_FIELD(arg0, s16*, 0x7E) = 3;
                M2C_FIELD(arg0, u8*, 0x93) = D_800FD59C;
                func_800179A4(arg0, 0xD);
            }
        } else {
            M2C_FIELD(arg0, s16*, 0x7E) = 3;
            M2C_FIELD(arg0, u8*, 0x93) = D_800FD59C;
            func_800179A4(arg0, 0xD);
        }
        M2C_FIELD(arg0, s32*, 0x20) = -0x8000;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s16*, 0x7C) = 0xB0;
    } else if (v == 4) {
        if (D_800970AE > 0xD0) {
            if (M2C_FIELD(arg0, s8*, 0x8F) == 2) {
                M2C_FIELD(arg0, s16*, 0x7E) = 3;
                M2C_FIELD(arg0, u8*, 0x93) = D_800FD59C;
                M2C_FIELD(arg0, s32*, 0x20) = 0x8000;
                M2C_FIELD(arg0, s32*, 0x24) = 0;
                M2C_FIELD(arg0, s16*, 0x7C) = 0xB0;
                func_800179A4(arg0, 0xC);
            } else {
                M2C_FIELD(arg0, s16*, 0x7E) = 1;
                M2C_FIELD(arg0, u8*, 0x93) = 3;
                M2C_FIELD(arg0, s32*, 0x20) = 0;
                M2C_FIELD(arg0, s32*, 0x24) = -0x8000;
                M2C_FIELD(arg0, s16*, 0x7C) = 0x90;
                func_800179A4(arg0, 0xF);
            }
        } else if (M2C_FIELD(arg0, s8*, 0x8F) == 2) {
            M2C_FIELD(arg0, s16*, 0x7E) = 0;
            M2C_FIELD(arg0, u8*, 0x93) = 0;
            M2C_FIELD(arg0, s32*, 0x20) = 0;
            M2C_FIELD(arg0, s32*, 0x24) = 0x8000;
            M2C_FIELD(arg0, s16*, 0x7C) = 0x90;
            func_800179A4(arg0, 0xE);
        } else {
            M2C_FIELD(arg0, s16*, 0x7E) = 3;
            M2C_FIELD(arg0, u8*, 0x93) = D_800FD59C;
            M2C_FIELD(arg0, s32*, 0x20) = -0x8000;
            M2C_FIELD(arg0, s32*, 0x24) = 0;
            M2C_FIELD(arg0, s16*, 0x7C) = 0xB0;
            func_800179A4(arg0, 0xD);
        }
    } else if (v == 5) {
        if (D_800970AE > 0xD0) {
            if (M2C_FIELD(arg0, s8*, 0x8F) == 3) {
                M2C_FIELD(arg0, s16*, 0x7E) = 3;
                M2C_FIELD(arg0, u8*, 0x93) = D_800FD59C;
                M2C_FIELD(arg0, s32*, 0x20) = -0x8000;
                M2C_FIELD(arg0, s32*, 0x24) = 0;
                M2C_FIELD(arg0, s16*, 0x7C) = 0xB0;
                func_800179A4(arg0, 0xD);
            } else {
                M2C_FIELD(arg0, s16*, 0x7E) = 1;
                M2C_FIELD(arg0, u8*, 0x93) = 3;
                M2C_FIELD(arg0, s32*, 0x20) = 0;
                M2C_FIELD(arg0, s32*, 0x24) = -0x8000;
                M2C_FIELD(arg0, s16*, 0x7C) = 0x90;
                func_800179A4(arg0, 0xF);
            }
        } else if (M2C_FIELD(arg0, s8*, 0x8F) == 3) {
            M2C_FIELD(arg0, s16*, 0x7E) = 0;
            M2C_FIELD(arg0, u8*, 0x93) = 0;
            M2C_FIELD(arg0, s32*, 0x20) = 0;
            M2C_FIELD(arg0, s32*, 0x24) = 0x8000;
            M2C_FIELD(arg0, s16*, 0x7C) = 0x90;
            func_800179A4(arg0, 0xE);
        } else {
            M2C_FIELD(arg0, s16*, 0x7E) = 3;
            M2C_FIELD(arg0, u8*, 0x93) = D_800FD59C;
            M2C_FIELD(arg0, s32*, 0x20) = 0x8000;
            M2C_FIELD(arg0, s32*, 0x24) = 0;
            M2C_FIELD(arg0, s16*, 0x7C) = 0xB0;
            func_800179A4(arg0, 0xC);
        }
    }
    func_80016C48(2, 0x6B, arg0);
    M2C_FIELD(arg0, void**, 0x54) = &D_800FC954;
    M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
}
