#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s32 D_800FDE30;

void func_800FDB64(void* a) {
    void* p = M2C_FIELD(a, void**, 0x50);

    M2C_FIELD(a, u8*, 0x47) = M2C_FIELD(p, u8*, 0x47);
    M2C_FIELD(a, u8*, 0x15) = M2C_FIELD(p, u8*, 0x15);
    M2C_FIELD(a, s32*, 0x38) = M2C_FIELD(p, s32*, 0x38);
    M2C_FIELD(a, s32*, 0x3C) = M2C_FIELD(p, s32*, 0x3C);
    M2C_FIELD(a, s32*, 0x18) = M2C_FIELD(a, s32*, 0x8);
    M2C_FIELD(a, s32*, 0x1C) = M2C_FIELD(a, s32*, 0xC);
    if (M2C_FIELD(a, s8*, 0x4) == 0) {
        if (M2C_FIELD(p, s8*, 0x9A) != 0) {
            if (M2C_FIELD(p, s8*, 0x9A) > 0) {
                M2C_FIELD(a, u8*, 0x3) = 1;
                M2C_FIELD(a, s16*, 0x54) = 3;
                M2C_FIELD(a, s16*, 0x56) = 8;
                M2C_FIELD(a, s16*, 0x58) = (5 - M2C_FIELD(a, s8*, 0x2)) * 2;
                M2C_FIELD(a, s32*, 0x8) = M2C_FIELD(p, s32*, 0x8);
                M2C_FIELD(a, s32*, 0xC) = M2C_FIELD(p, s32*, 0xC);
                M2C_FIELD(a, s8*, 0x4) = 1;
                M2C_FIELD(a, s8*, 0x5) = 0;
            } else {
                M2C_FIELD(p, s8*, 0x9A) = 0;
            }
        }
    } else if (M2C_FIELD(p, s8*, 0x9A) == 0) {
        M2C_FIELD(a, u8*, 0x3) = 0;
        M2C_FIELD(a, s8*, 0x4) = 0;
    } else {
        ((void (**)(void*, void*))((u8*)&D_800FDE30 +
                                   0x448))[M2C_FIELD(a, s8*, 0x5)](a, p);
    }
}
