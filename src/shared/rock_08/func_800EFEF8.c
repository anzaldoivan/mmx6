#include "common.h"

#define FLD(p, type, off) (*(type*)((u8*)(p) + (off)))

void* func_8002BBF4();

void func_800EFEF8(void* arg0, s32 arg1) {
    u8* p;
    u8 n;

    n = arg1;
    p = func_8002BBF4();
    if (p != 0) {
        p[0] = 0x41;
        p[1] = 0x25;
        p[2] = n;
        FLD(p, u16, 0x42) = FLD(arg0, u16, 0x42) & 0x7FFF;
        FLD(p, s32, 0x30) = FLD(arg0, s32, 0x30);
        FLD(p, s32, 0x3C) = FLD(arg0, s32, 0x3C);
        FLD(p, u16, 0x40) = FLD(arg0, u16, 0x40);
        FLD(p, u8, 0x14) = FLD(arg0, u8, 0x14);
        FLD(p, u16, 0xA) = FLD(arg0, u16, 0xA);
        FLD(p, u16, 0xE) = FLD(arg0, u16, 0xE);
    }
}
