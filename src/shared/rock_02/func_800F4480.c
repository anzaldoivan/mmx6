#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04(); /* extern */

void func_800F4480(void* arg0) {
    void* temp_s0;
    s32 temp_a1;

    ((M2C_UNK(*)())func_80017A04)();
    temp_s0 = M2C_FIELD(arg0, void**, 0x7C);
    ((M2C_UNK(*)())func_80017A04)(arg0);
    if (M2C_FIELD(arg0, s8*, 2) == 9) {
        if (M2C_FIELD(temp_s0, u8*, 0x15) != 0) {
            M2C_FIELD(arg0, u8*, 0x15) = 0x40;
            M2C_FIELD(arg0, u16*, 0xA) = M2C_FIELD(temp_s0, u16*, 0xA) - 0x30;
        } else {
            M2C_FIELD(arg0, u8*, 0x15) = 0;
            M2C_FIELD(arg0, u16*, 0xA) = M2C_FIELD(temp_s0, u16*, 0xA) + 0x30;
        }
    } else {
        if (M2C_FIELD(temp_s0, u8*, 0x15) == 0) {
            M2C_FIELD(arg0, u8*, 0x15) = 0x40;
            M2C_FIELD(arg0, u16*, 0xA) = M2C_FIELD(temp_s0, u16*, 0xA) - 0x30;
        } else {
            M2C_FIELD(arg0, u8*, 0x15) = 0;
            M2C_FIELD(arg0, u16*, 0xA) = M2C_FIELD(temp_s0, u16*, 0xA) + 0x30;
        }
    }
    M2C_FIELD(arg0, u16*, 0xE) = M2C_FIELD(temp_s0, u16*, 0xE);
    temp_a1 = M2C_FIELD(temp_s0, s32*, 4) & 0xFFFF00;
    if (temp_a1 == 0x30F00 || temp_a1 == 0x31000) {
        if (M2C_FIELD(arg0, s8*, 2) == 9) {
            if (M2C_FIELD(temp_s0, u8*, 0x15) != 0) {
                M2C_FIELD(arg0, s32*, 0x20) = -0x80000;
            } else {
                M2C_FIELD(arg0, s32*, 0x20) = 0x80000;
            }
        } else {
            if (M2C_FIELD(temp_s0, u8*, 0x15) == 0) {
                M2C_FIELD(arg0, s32*, 0x20) = -0x80000;
            } else {
                M2C_FIELD(arg0, s32*, 0x20) = 0x80000;
            }
        }
        M2C_FIELD(arg0, u8*, 0x8D) = 0x78;
        M2C_FIELD(arg0, u8*, 6)++;
    } else if (temp_a1 == 0x11100) {
        if (M2C_FIELD(temp_s0, s16*, 0x7C) >= 0x1E) {
            if (M2C_FIELD(arg0, s8*, 2) == 9) {
                if (M2C_FIELD(temp_s0, u8*, 0x15) != 0) {
                    M2C_FIELD(arg0, s32*, 0x20) = 0x8000;
                } else {
                    M2C_FIELD(arg0, s32*, 0x20) = -0x8000;
                }
            } else {
                if (M2C_FIELD(temp_s0, u8*, 0x15) == 0) {
                    M2C_FIELD(arg0, s32*, 0x20) = 0x8000;
                } else {
                    M2C_FIELD(arg0, s32*, 0x20) = -0x8000;
                }
            }
            M2C_FIELD(arg0, u8*, 0x8D) = 0x30;
            M2C_FIELD(arg0, u8*, 6)++;
        }
    }
}
