#include "common.h"

void* func_8002C530();

void func_800ED58C(u8 arg0, s8 arg1, s16 arg2, s16 arg3, u8 arg4) {
    u8* obj;

    obj = func_8002C530();
    if (obj != 0) {
        obj[0] = 1;
        obj[1] = 0x2E;
        obj[2] = arg0;
        obj[0x54] = arg1;
        obj[0x57] = arg4 + 1;
        *(s16*)(obj + 0xA) = arg2;
        *(s16*)(obj + 0xE) = arg3;
    }
}
