#include "common.h"

void* func_8002C530();

void func_800EAB3C(u8* arg0, u8 arg1) {
    u8* obj;

    obj = func_8002C530();
    if (obj != 0) {
        obj[0] = 0x41;
        obj[1] = 5;
        obj[2] = arg1;
        obj[0x15] = arg0[0x15];
        *(u16*)(obj + 0x40) = *(u16*)(arg0 + 0x40);
        *(u16*)(obj + 0x42) = *(u16*)(arg0 + 0x42) & 0x7FFF;
        *(s32*)(obj + 0x30) = *(s32*)(arg0 + 0x30);
        *(s32*)(obj + 0x3C) = *(s32*)(arg0 + 0x3C);
        obj[0x14] = arg0[0x14];
        *(u16*)(obj + 0xA) = *(u16*)(arg0 + 0xA);
        *(u16*)(obj + 0x8) = 0;
        *(u16*)(obj + 0xE) = *(u16*)(arg0 + 0xE);
        *(u16*)(obj + 0xC) = 0;
        *(u8**)(obj + 0x50) = arg0;
    }
}
