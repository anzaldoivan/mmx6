#include "common.h"
#define M2C_UNK s32

s32 func_8003A628(void*);
M2C_UNK func_8003BA04(void*, M2C_UNK);

M2C_UNK func_8003B9AC(void* arg0) {
    s32 var_a1;

    if (func_8003A628(arg0) == 0) {
        var_a1 = 0x51;
        if (*(s32*)((u8*)arg0 + 0x8C) & 0xFFFF0000) {
            var_a1 = 0x6D;
        }
        ((void (*)(void*, s32))func_8003BA04)(arg0, var_a1);
        *((u8*)arg0 + 5) = 0x1A;
        *((u8*)arg0 + 6) = 0;
    }
}
