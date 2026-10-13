#include "common.h"

void* func_8002BBF4();

void func_800F67D0(void* arg0, s32 arg1) {
    u8* src = arg0;
    u8* obj;
    u8 b = arg1;

    obj = func_8002BBF4();
    if (obj != 0) {
        obj[0] = 0x41;
        obj[1] = 0x38;
        obj[0x15] = src[0x15];
        *(void**)(obj + 0x80) = src;
        obj[2] = b;
        *(u16*)(obj + 0xA) = *(u16*)(src + 0xA);
        *(s16*)(obj + 8) = 0;
        *(u16*)(obj + 0xE) = *(u16*)(src + 0xE);
        *(s16*)(obj + 0xC) = 0;
        *(u16*)(obj + 0x42) = *(u16*)(src + 0x42) & 0x7FFF;
        *(s32*)(obj + 0x30) = *(s32*)(src + 0x30);
        *(s32*)(obj + 0x3C) = *(s32*)(src + 0x3C);
        *(u16*)(obj + 0x40) = *(u16*)(src + 0x40);
        obj[0x14] = src[0x14];
    }
}
