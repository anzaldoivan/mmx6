#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_80016C48(s32 a0, s32 a1, void* arg2);
M2C_UNK func_800179A4(void*, M2C_UNK);
void func_8004FFF8(void*, s32);
extern s32 D_800970A8;
extern s8 D_80097174;

void func_8004F144(void* arg0) {
    s8 state = M2C_FIELD(arg0, s8*, 0x45);

    if (state == 1) {
        if (D_80097174 == 0) {
            func_80016C48(2, 0x2E, arg0);
            if (M2C_FIELD(arg0, u8*, 0x84) == 0) {
                func_8004FFF8(arg0, 0);
                func_8004FFF8(arg0, 1);
            } else {
                func_8004FFF8(arg0, 0x10);
            }
        }
    } else if (state == 2) {
        if (M2C_FIELD(arg0, u8*, 0x82) == 0) {
            if (M2C_FIELD(arg0, s32*, 8) > D_800970A8) {
                M2C_FIELD(arg0, u8*, 0x82) = 0;
            } else {
                M2C_FIELD(arg0, u8*, 0x82) = 0x40;
            }
        } else {
            if (M2C_FIELD(arg0, s32*, 8) > D_800970A8) {
                M2C_FIELD(arg0, u8*, 0x82) = 0;
            } else {
                M2C_FIELD(arg0, u8*, 0x82) = 0x40;
            }
        }
        if (M2C_FIELD(arg0, u8*, 0x84) == 0) {
            if (M2C_FIELD(arg0, u8*, 0x7E) == 0) {
                if (M2C_FIELD(arg0, u8*, 0x82) == 0) {
                    func_800179A4(arg0, 0x13);
                } else {
                    func_800179A4(arg0, 0x14);
                }
            } else if (M2C_FIELD(arg0, u8*, 0x82) == 0) {
                func_800179A4(arg0, 0x15);
            } else {
                func_800179A4(arg0, 0x16);
            }
            M2C_FIELD(arg0, u8*, 0x81) = 0x3C;
        } else {
            if (M2C_FIELD(arg0, u8*, 0x82) == 0) {
                func_800179A4(arg0, 0x1C);
            } else {
                func_800179A4(arg0, 0x23);
            }
            M2C_FIELD(arg0, u8*, 0x81) = 0x14;
        }
        M2C_FIELD(arg0, u8*, 5) -= 1;
    }
}
