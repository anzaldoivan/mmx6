#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8003BA04(void*, M2C_UNK);
s32 func_8003EB0C(void* arg0, s32 arg1);
void func_8003F740(void*, s32);
void func_801ECAF0(u8* arg0);
s32 func_801ECCD4(void*);

s32 func_801ECA50(u8* p) {
    if (func_8003EB0C(p, 1) <= *(s16*)(p + 0xAA)) {
        if (func_801ECCD4(p) != 0) {
            func_8003BA04(p, 0x64);
            func_80016C48(1, 0x14, p);
            p[0x84] = 0;
            p[0x86] = 0;
            p[0x93] = 1;
            func_8003F740(p, 1);
            p[5] = 0x3F;
            p[6] = 0;
            func_801ECAF0(p);
            return 1;
        }
        return 0;
    }
    return 0;
}
