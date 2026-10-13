#include "common.h"

s8* func_8002C5F0(s8* p, s32 back);

void func_800F02F4(void* arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s8* p;
    u8 a1 = arg1;
    s8 a2 = arg2;
    s16 a3 = arg3;
    s16 a4 = arg4;

    p = func_8002C5F0(arg0, 0);
    if (p != 0) {
        p[0] = 1;
        p[1] = 0x2E;
        p[2] = a1;
        p[0x54] = a2;
        p[0x57] = ((u8*)arg0)[0x57];
        *(void**)(p + 0x50) = arg0;
        *(s16*)(p + 0xA) = a3;
        *(s16*)(p + 0xE) = a4;
    }
}
