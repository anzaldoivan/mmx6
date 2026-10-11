#include "common.h"

void* func_8002C530();

void func_800EA470(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    u8 id = arg0;
    s8 b = arg1;
    s16 x = arg2;
    s16 y = arg3;
    u8 n = arg4;
    u8* obj;

    obj = func_8002C530();
    if (obj != 0) {
        obj[0] = 1;
        obj[1] = 0x2F;
        obj[2] = id;
        obj[0x54] = b;
        obj[0x57] = n + 1;
        *(s16*)(obj + 0xA) = x;
        *(s16*)(obj + 0xE) = y;
    }
}
