#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8003BA04(void*, M2C_UNK);
s32 func_801EA34C(void* arg0);
void func_801EB5F8(void*);
s32 func_801ECCD4(void*);

#define F_S8(p, o) (*(s8*)((u8*)(p) + (o)))

s32 func_801EC028(void* arg0) {
    s8 v;

    if (F_S8(arg0, 2) == 0) {
        return 0;
    }
    if (F_S8(arg0, 0xD3) != 0) {
        return 0;
    }
    if (func_801EA34C(arg0) != 0) {
        return 1;
    }
    if (func_801ECCD4(arg0) == 0) {
        return 0;
    }
    v = F_S8(arg0, 0x86);
    if (v == 6) {
        func_8003BA04(arg0, 0x60);
        func_80016C48(1, 7, arg0);
        v = 0x36;
    } else {
        func_8003BA04(arg0, 0x5B);
        func_80016C48(1, 8, arg0);
        v = 0x32;
    }
    F_S8(arg0, 5) = v;
    F_S8(arg0, 6) = 0;
    do {
        func_801EB5F8(arg0);
    } while (0);
    return 1;
}
