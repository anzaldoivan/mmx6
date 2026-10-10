#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK);
void func_800ECC44(void*, s32);
void func_800ECCD8(void*, s32);
extern M2C_UNK D_8007433C;
extern M2C_UNK D_800743DC;
extern u8 D_800970B4;
extern u8 D_800F79D0[];

void func_800E9E08(void* arg0) {
    void* p = arg0;
    s32 kind;
    s32 t;
    s32 v;

    t = M2C_FIELD(p, s8*, 0x2);
    if (t == 0) {
        M2C_FIELD(p, u8*, 0x60) = 8;
        M2C_FIELD(p, u8*, 0x5C) = 0;
        M2C_FIELD(p, u8*, 0x61) = 0;
        M2C_FIELD(p, void**, 0x30) = D_800F79D0 + 0xC68;
        M2C_FIELD(p, u8*, 0x14) = D_800970B4;
        M2C_FIELD(p, u8*, 0x15) = 0;
        M2C_FIELD(p, u8*, 0x16) = 0x22;
        M2C_FIELD(p, u8*, 0x67) = 0;
        M2C_FIELD(p, void**, 0x58) = &D_800743DC;
        M2C_FIELD(p, s32*, 0x20) = 0;
        M2C_FIELD(p, s32*, 0x24) = 0;
        M2C_FIELD(p, s32*, 0x28) = 0;
        M2C_FIELD(p, s32*, 0x2C) = 0;
        M2C_FIELD(p, s16*, 0x82) = 0xA0;
        M2C_FIELD(p, s16*, 0x86) = -0x40;
        M2C_FIELD(p, u8*, 0x3) = 0;
        M2C_FIELD(p, u8*, 0x8F) = 0;
        M2C_FIELD(p, u8*, 0x90) = 0;
        M2C_FIELD(p, u8*, 0x91) = 0;
        M2C_FIELD(p, u8*, 0x92) = 0;
        M2C_FIELD(p, s32*, 0x68) = 0;
        M2C_FIELD(p, s32*, 0x50) = 0;
        M2C_FIELD(p, s32*, 0x54) = 0;
        func_800179A4(arg0, 0);
        M2C_FIELD(p, u8*, 0x8C) = 0;
        M2C_FIELD(p, u8*, 0x8D) = 0;
        M2C_FIELD(p, u8*, 0x8E) = 0;
        func_800ECC44(p, 0x10);
        func_800ECC44(p, 0x11);
        func_800ECC44(p, 0x12);
        func_800ECC44(p, 0x20);
        func_800ECC44(p, 0x21);
        func_800ECC44(p, 0x22);
        func_800ECCD8(p, 0);
        func_800ECCD8(p, 1);
        func_800ECCD8(p, 0x10);
        func_800ECCD8(p, 0x11);
        func_800ECCD8(p, 0x20);
        M2C_FIELD(p, u8*, 0x4) = 1;
        M2C_FIELD(p, u8*, 0x5) = 2;
        M2C_FIELD(p, u8*, 0x6) = 0;
        return;
    } else {
        u8 b;
        M2C_FIELD(p, u8*, 0x60) = 0;
        M2C_FIELD(p, u8*, 0x5C) = 0x10;
        M2C_FIELD(p, void**, 0x30) = D_800F79D0 + 0xC68;
        b = D_800970B4;
        kind = t & 0xF0;
        M2C_FIELD(p, u8*, 0x16) = 0x21;
        M2C_FIELD(p, s16*, 0x84) = 0;
        M2C_FIELD(p, u8*, 0x67) = 0;
        M2C_FIELD(p, u8*, 0x14) = b;
        if (kind == 0x10) {
            ((void (*)(void*, s32))func_800179A4)(p, 5);
            M2C_FIELD(p, void**, 0x58) = &D_800743DC;
            switch (M2C_FIELD(p, s8*, 0x2)) {
            case 0x11:
                M2C_FIELD(p, u8*, 0x15) = 0x40;
                break;
            case 0x10:
            case 0x12:
                M2C_FIELD(p, u8*, 0x15) = 0;
                break;
            default:
                M2C_FIELD(p, u8*, 0x5) = 3;
                goto end;
            }
            v = 3;
        } else {
            ((void (*)(void*, s32))func_800179A4)(p, 1);
            M2C_FIELD(p, void**, 0x58) = &D_8007433C;
            switch (M2C_FIELD(p, s8*, 0x2)) {
            case 0x21:
                M2C_FIELD(p, u8*, 0x15) = 0;
                break;
            case 0x20:
            case 0x22:
                M2C_FIELD(p, u8*, 0x15) = 0x40;
                break;
            default:
                M2C_FIELD(p, u8*, 0x5) = 2;
                goto end;
            }
            v = 2;
        }
        M2C_FIELD(p, u8*, 0x5) = v;
    end:
        M2C_FIELD(p, s32*, 0x20) = 0;
        M2C_FIELD(p, s32*, 0x24) = 0;
        M2C_FIELD(p, s32*, 0x28) = 0;
        M2C_FIELD(p, s32*, 0x2C) = 0;
        M2C_FIELD(p, u8*, 0x3) = 0;
        M2C_FIELD(p, s32*, 0x68) = 0;
        M2C_FIELD(p, s32*, 0x50) = 0;
        M2C_FIELD(p, void**, 0x54) = D_800F79D0 + 0xB5C;
        M2C_FIELD(p, u8*, 0x4) = 3;
    }
    M2C_FIELD(p, u8*, 0x6) = 0;
}
