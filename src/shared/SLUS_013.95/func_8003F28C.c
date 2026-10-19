#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
s32 func_80039EB0(struct X4_PlayerObj*);
M2C_UNK func_8003B298(void*);
M2C_UNK func_8003BA04(void*, M2C_UNK);
void* func_8003D3F8(s8 arg0, s8 arg1, s8 arg2, s32 arg3);
M2C_UNK func_8003D510(M2C_UNK arg0, M2C_UNK arg1, M2C_UNK arg2, M2C_UNK arg3);

s32 func_8003F28C(void* arg0) {
    s8* p = arg0;
    s32 r;

    if (!(*(u16*)(p + 0x80) & 0x80) && ((s32(*)())func_80039EB0)() == 0) {
        r = 0;
    } else {
        func_8003B298(p);
        *(s32*)(p + 0x24) = 0;
        func_80016C48(1, 5, p);
        p[5] = 0x23;
        func_8003BA04(p, 0xA9);
        func_8003D3F8(1, 0x17, 0, p);
        func_8003D510(1, 0x12, 0, 0);
        r = 1;
    }
    return r;
}
