#include "common.h"
#define M2C_UNK s32

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
s32 func_8002D2D4();
s32 func_8002FE30(void*);
s32 func_8003A814(void*, s32);
M2C_UNK func_8003AF1C(void*);
M2C_UNK func_8003BA04(void*, M2C_UNK);
M2C_UNK func_8003CD9C();
M2C_UNK func_8003CFE0(void*, M2C_UNK);
s32 func_801ECCD4();

s32 func_801EA124(void* arg0) {
    u8* p = arg0;
    s32 v;

    if (func_801ECCD4() == 0) {
        return 0;
    }
    func_8003BA04(p, func_8003A814(p, func_8002FE30(p) & 0xFF) + 0x6B);
    func_80016C48(1, 8, p);
    if (func_8002D2D4() & 4) {
        func_8003CFE0(p, 8);
    }
    ((void (*)(void*))func_8003CD9C)(p);
    {
        s32 t = 1;
        p[5] = 0x3D;
        p[6] = t;
    }
    if (*(u16*)(p + 0x80) & 2) {
        p[0x15] = 0;
    }
    if (*(u16*)(p + 0x80) & 1) {
        p[0x15] = 0x40;
    }
    if (*(s8*)(p + 0xD3) == 0) {
        p[0x8E] = 0;
        if (*(u16*)(p + 0x80) & 0x80) {
            func_8003AF1C(p);
            return 1;
        }
        p[0x8E] = 1;
    }
    if (*(s8*)(p + 0x46) == 0) {
        p[0x8E] = 0;
        v = func_8002FE30(p);
        if (v == 0x2E) {
            v = 0x1B;
        } else {
            v = 0x1C;
        }
        p[5] = v;
        p[6] = 1;
    }
    return 1;
}
