#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800FA140(void* arg0);
extern s32 D_800FD5A0;

void func_800F7630(void* arg0) {
    void* s0;
    u8 t;
    s8 v;

    t = M2C_FIELD(arg0, u8*, 0x8E);
    s0 = M2C_FIELD(arg0, void**, 0x84);
    if (t != 0) {
        M2C_FIELD(arg0, u8*, 0x8E) = t - 1;
        return;
    }
    func_800FA140(arg0);
    if (M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        M2C_FIELD(s0, u8*, 7)++;
        M2C_FIELD(arg0, s8*, 5) = 5;
        M2C_FIELD(arg0, u8*, 6) = 0;
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        M2C_FIELD(arg0, s16*, 0x7E) = 0;
        ((u8*)s0 + 0x8F)[M2C_FIELD(arg0, s8*, 2)] = M2C_FIELD(arg0, u8*, 0x8F);
        return;
    }
    v = M2C_FIELD(arg0, s8*, 0x8F);
    if (v == 0) {
        if (M2C_FIELD(s0, u8*, 0x15) != 0) {
            s32 d = D_800FD5A0;
            M2C_FIELD(arg0, s32*, 0x20) = 0;
            M2C_FIELD(arg0, s32*, 0x24) = -d;
            if (M2C_FIELD(s0, s16*, 0x7C) == 1) {
                M2C_FIELD(arg0, s16*, 0x7E) = 0xB0 / (d >> 4);
            }
        } else {
            s32 d = D_800FD5A0;
            M2C_FIELD(arg0, s32*, 0x24) = 0;
            M2C_FIELD(arg0, s32*, 0x20) = d;
            if (M2C_FIELD(s0, s16*, 0x7C) == 1) {
                M2C_FIELD(arg0, s16*, 0x7E) = 0x140 / (d >> 4);
            }
        }
    } else if (v == 1) {
        if (M2C_FIELD(s0, u8*, 0x15) == 0) {
            s32 d = D_800FD5A0;
            M2C_FIELD(arg0, s32*, 0x20) = 0;
            M2C_FIELD(arg0, s32*, 0x24) = -d;
            if (M2C_FIELD(s0, s16*, 0x7C) == 1) {
                M2C_FIELD(arg0, s16*, 0x7E) = 0xB0 / (d >> 4);
            }
        } else {
            s32 d = D_800FD5A0;
            M2C_FIELD(arg0, s32*, 0x24) = 0;
            M2C_FIELD(arg0, s32*, 0x20) = -d;
            if (M2C_FIELD(s0, s16*, 0x7C) == 1) {
                M2C_FIELD(arg0, s16*, 0x7E) = 0x140 / (d >> 4);
            }
        }
    } else if (v == 2) {
        if (M2C_FIELD(s0, u8*, 0x15) != 0) {
            s32 d = D_800FD5A0;
            M2C_FIELD(arg0, s32*, 0x24) = 0;
            M2C_FIELD(arg0, s32*, 0x20) = d;
            if (M2C_FIELD(s0, s16*, 0x7C) == 1) {
                M2C_FIELD(arg0, s16*, 0x7E) = 0x140 / (d >> 4);
            }
        } else {
            s32 d = D_800FD5A0;
            M2C_FIELD(arg0, s32*, 0x20) = 0;
            M2C_FIELD(arg0, s32*, 0x24) = d;
            if (M2C_FIELD(s0, s16*, 0x7C) == 1) {
                M2C_FIELD(arg0, s16*, 0x7E) = 0xB0 / (d >> 4);
            }
        }
    } else if (v == 3) {
        if (M2C_FIELD(s0, u8*, 0x15) != 0) {
            s32 d = D_800FD5A0;
            M2C_FIELD(arg0, s32*, 0x20) = 0;
            M2C_FIELD(arg0, s32*, 0x24) = d;
            if (M2C_FIELD(s0, s16*, 0x7C) == 1) {
                M2C_FIELD(arg0, s16*, 0x7E) = 0xB0 / (d >> 4);
            }
        } else {
            s32 d = D_800FD5A0;
            M2C_FIELD(arg0, s32*, 0x24) = 0;
            M2C_FIELD(arg0, s32*, 0x20) = -d;
            if (M2C_FIELD(s0, s16*, 0x7C) == 1) {
                M2C_FIELD(arg0, s16*, 0x7E) = 0x140 / (d >> 4);
            }
        }
    }
    M2C_FIELD(arg0, u8*, 6)++;
}
