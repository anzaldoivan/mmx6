#include "common.h"

void* func_8002C458();

void func_800F41D0(void* arg0, u8 arg1, s16 arg2, s16 arg3) {
    u8* p;

    p = func_8002C458();
    if (p != 0) {
        p[0] = 0x41;
        p[1] = 0x1C;
        *(void**)(p + 0x7C) = arg0;
        p[2] = arg1;
        *(s16*)(p + 0xA) = arg2;
        *(s16*)(p + 0x8) = 0;
        *(s16*)(p + 0xE) = arg3;
        *(s16*)(p + 0xC) = 0;
        p[0x14] = 0;
    }
}
