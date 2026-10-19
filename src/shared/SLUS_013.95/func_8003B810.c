#include "common.h"
#define M2C_UNK s32

M2C_UNK func_8003CD9C();

M2C_UNK func_8003B810(void* arg0) {
    u8* p = (u8*)arg0;

    *(s16*)(p + 0x8) = 0;
    *(s16*)(p + 0xC) = 0;
    *(s32*)(p + 0x20) = 0;
    *(s32*)(p + 0x28) = 0;
    *(s32*)(p + 0x2C) = 0;
    *(u16*)(p + 0xA) = (*(u16*)(p + 0xA) & 0xFFF0) + 8;
    *(s32*)(p + 0x24) = -*(s32*)(p + 0x11C);
    ((void (*)())func_8003CD9C)(p);
    p[5] = 0x10;
    p[6] = 0;
}
