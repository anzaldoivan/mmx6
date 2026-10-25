#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define B(p, o) M2C_FIELD(p, u8*, o)
#define SB(p, o) M2C_FIELD(p, s8*, o)
#define H(p, o) M2C_FIELD(p, s16*, o)
#define W(p, o) M2C_FIELD(p, s32*, o)

M2C_UNK func_800179A4(void*, M2C_UNK);
extern s32 D_80075B9C;
extern s32 D_800F88A4;
extern s32 D_800F88A8;
extern s32 D_800F88AC;
extern s32 D_800F88B4;
extern s32 D_800F88B8;
extern s32 D_800F88BC;

void func_800EB114(void* arg0) {
    s32 kind;
    s32 x;
    s32 y;
    s8 sub;

    B(arg0, 0x75) = 1;
    B(arg0, 0xA2) = 1;
    B(arg0, 0x76) = 0;
    kind = SB(arg0, 0x2) & 0xF0;
    B(arg0, 0x67) = 0;
    if (kind == 0) {
        B(arg0, 0x16) = 0x23;
        B(arg0, 0x60) = 8;
        W(arg0, 0x58) = (s32)&D_80075B9C;
        W(arg0, 0x50) = (s32)&D_800F88A4;
        B(arg0, 0x5C) = 0;
        B(arg0, 0x61) = 0;
        B(arg0, 0x65) = 0;
        W(arg0, 0x54) = (s32)&D_800F88A8;
        W(arg0, 0x68) = (s32)&D_800F88AC;
        func_800179A4(arg0, 0x10);
        sub = SB(arg0, 0x2);
        B(arg0, 0x3) = 0;
        B(arg0, 0x5) = 0;
        if (sub == 0) {
            x = 0x10;
            y = -0x40;
            goto right;
        } else if (sub == 1) {
            x = 0x130;
            y = -0x40;
            goto left;
        }
    } else if (kind == 0x10) {
        void* a = arg0;
        B(arg0, 0x60) = 0x7F;
        B(arg0, 0x5C) = 0;
        W(arg0, 0x58) = (s32)&D_80075B9C;
        B(arg0, 0x61) = 0;
        B(arg0, 0x65) = 0;
        W(arg0, 0x50) = 0;
        W(arg0, 0x54) = (s32)&D_800F88B4;
        W(arg0, 0x68) = (s32)&D_800F88B8;
        func_800179A4(a, 0x10);
        sub = SB(arg0, 0x2);
        B(arg0, 0x3) = 0;
        B(arg0, 0x5) = 1;
        if (sub == 0x10) {
            x = 0x50;
            y = -0x50;
        left:
            H(arg0, 0x82) = x;
            H(arg0, 0x86) = y;
            B(arg0, 0x15) = 0;
        } else if (sub == 0x11) {
            x = 0xF0;
            y = -0x50;
        right:
            H(arg0, 0x82) = x;
            H(arg0, 0x86) = y;
            B(arg0, 0x15) = 0x40;
        }
    } else if (kind == 0x20) {
        void* a = arg0;
        B(arg0, 0x60) = 8;
        B(arg0, 0x5C) = 0;
        W(arg0, 0x58) = (s32)&D_80075B9C;
        B(arg0, 0x61) = 0;
        B(arg0, 0x65) = 0;
        W(arg0, 0x50) = 0;
        W(arg0, 0x54) = 0;
        W(arg0, 0x68) = (s32)&D_800F88BC;
        func_800179A4(a, 0x10);
        B(arg0, 0x3) = 0;
        B(arg0, 0x5) = 2;
    }
    B(arg0, 0x6) = 0;
    B(arg0, 0x4)++;
}
