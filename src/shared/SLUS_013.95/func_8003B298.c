#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8003BA04(void*, M2C_UNK);
M2C_UNK func_8003CDBC();

M2C_UNK func_8003B298(void* arg0) {
    u8* p = arg0;
    s8 v;
    s32 t;
    s32 u;

    func_8003BA04(arg0, 0x12);
    u = *(s32*)(p + 0x10C);
    t = *(s32*)(p + 0xEC) & 0x10;
    *(s32*)(p + 0x24) = 0;
    *(s32*)(p + 0x2C) = 0;
    *(s8*)(p + 0x84) = -1;
    *(s32*)(p + 0x28) = u;
    do {
    } while (0);
    v = 0x12;
    if (t) {
        v = 0xA;
    }
    *(s8*)(p + 0x85) = v;
    do {
    } while (0);
    {
        // !FAKE: pin the call argument so the join store issues first
        register u8* a asm("$4") = p;
        *(s8*)(p + 0x86) = 3;
        ((void (*)())func_8003CDBC)(a);
    }
    *(s8*)(p + 5) = 0xD;
    *(s8*)(p + 6) = 0;
}
