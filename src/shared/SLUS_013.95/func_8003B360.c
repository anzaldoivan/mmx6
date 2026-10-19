#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8003BA04(void*, M2C_UNK);

void func_8003B360(void* arg0) {
    u8* p = arg0;

    ((void (*)(void*, s32))func_8003BA04)(arg0, 0x84);
    *(s8*)(p + 0x67) = -1;
    *(s32*)(p + 0x20) = 0;
    *(s32*)(p + 0x28) = 0;
    *(s32*)(p + 0x24) = 0;
    *(u8*)(p + 0x84) = 0;
    *(u8*)(p + 0x8C) = 0;
    *(u8*)(p + 0x5) = 7;
    *(u8*)(p + 0x6) = 0;
    *(s32*)(p + 0x2C) = *(s32*)(p + 0x100);
}
