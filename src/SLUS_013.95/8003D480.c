#include "common.h"

s8* func_8002BEC4(s8* p, s32 dir);
extern u8 D_800970B4;

void* func_8003D480(s8 arg0, s8 arg1, s8 arg2, s32 arg3) {
    u8* p;

    p = (u8*)func_8002BEC4((s8*)arg3, 0);
    if (p != 0) {
        p[0] = arg0;
        p[1] = arg1;
        p[2] = arg2;
        p[0x14] = D_800970B4;
        if (arg3 != 0) {
            *(s32*)(p + 0x7C) = arg3;
        }
        return p;
    }
    return 0;
}
