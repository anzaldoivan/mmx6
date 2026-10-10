#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_80031474(void*);
extern void (*D_800FBA70[])(void*);

void func_800F4AB8(void* arg0) {
    void* parent;
    s32 r;
    s8 k;

    parent = M2C_FIELD(arg0, void**, 0x7C);
    r = func_80031474(arg0);
    if (M2C_FIELD(parent, s8*, 6) == 5) {
        k = M2C_FIELD(parent, s8*, 5);
        if (k != 0xD && M2C_FIELD(arg0, s8*, 6) < 7) {
            if (k == 0x10) {
                M2C_FIELD(arg0, s8*, 6) = 8;
            } else {
                if (M2C_FIELD(arg0, s8*, 2) == 9) {
                    M2C_FIELD(parent, u8*, 0x8A) &= 0xF0;
                } else {
                    M2C_FIELD(parent, u8*, 0x8A) &= 0xF;
                }
                M2C_FIELD(arg0, s32*, 0x54) = 0;
                M2C_FIELD(arg0, s32*, 0x50) = 0;
                M2C_FIELD(arg0, u8*, 0x8D) = 0x5A;
                M2C_FIELD(arg0, s8*, 6) = 7;
            }
        }
    }
    if (r < 0 || M2C_FIELD(parent, s8*, 5) == 0xC) {
        if (M2C_FIELD(arg0, s8*, 6) != 7) {
            if (M2C_FIELD(arg0, s8*, 2) == 9) {
                M2C_FIELD(parent, u8*, 0x8A) &= 0xF0;
                M2C_FIELD(parent, u8*, 0x8D)--;
            } else {
                M2C_FIELD(parent, u8*, 0x8A) &= 0xF;
                M2C_FIELD(parent, u8*, 0x8E)--;
            }
            M2C_FIELD(arg0, s32*, 0x54) = 0;
            M2C_FIELD(arg0, s32*, 0x50) = 0;
            M2C_FIELD(arg0, u8*, 0x8D) = 0x5A;
            M2C_FIELD(arg0, s8*, 6) = 7;
        }
    }
    D_800FBA70[M2C_FIELD(arg0, s8*, 6)](arg0);
    if (M2C_FIELD(parent, s8*, 5) == 0xB) {
        M2C_FIELD(arg0, s32*, 8) = M2C_FIELD(arg0, s32*, 0x18);
        M2C_FIELD(arg0, s32*, 0xC) = M2C_FIELD(arg0, s32*, 0x1C);
    }
}
