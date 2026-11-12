#include "common.h"

void* func_8002C458();

void func_8004FFF8(void* arg0, s32 arg1) {
    u8 t;
    u8* p;

    t = arg1;
    p = func_8002C458();
    if (p != 0) {
        p[0] = 0x41;
        p[1] = 0x18;
        p[2] = t;
        *(s16*)(p + 0x88) = (s8)((u8*)arg0)[2];
        *(u16*)(p + 0x42) = *(u16*)((u8*)arg0 + 0x42) & 0x7FFF;
        *(s32*)(p + 0x30) = *(s32*)((u8*)arg0 + 0x30);
        *(s32*)(p + 0x3C) = *(s32*)((u8*)arg0 + 0x3C);
        *(u16*)(p + 0x40) = *(u16*)((u8*)arg0 + 0x40);
        p[0x15] = ((u8*)arg0)[0x82];
        p[0x14] = ((u8*)arg0)[0x14];
        {
            s32 a = *(u16*)((u8*)arg0 + 0xA);
            *(u16*)(p + 8) = 0;
            *(u16*)(p + 0xA) = a;
            {
                s32 b = *(u16*)((u8*)arg0 + 0xE);
                *(u16*)(p + 0xC) = 0;
                *(void**)(p + 0x7C) = arg0;
                *(u16*)(p + 0xE) = b;
            }
        }
    }
}
