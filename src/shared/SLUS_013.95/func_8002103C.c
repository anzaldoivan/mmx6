#include "common.h"

#define S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define S16(p, o) (*(s16*)((u8*)(p) + (o)))
#define S32(p, o) (*(s32*)((u8*)(p) + (o)))

void func_8002103C(void* arg0, void* arg1) {
    void* p;

    if (S8(arg1, 0x8C) > 0) {
        S16(arg0, 0x54) = 3;
        S16(arg0, 0x56) = 8;
        S16(arg0, 0x58) = (5 - S8(arg0, 2)) * 2;
        S32(arg0, 0x8) = S32(arg1, 0x8);
        S32(arg0, 0xC) = S32(arg1, 0xC);
        S8(arg0, 4) = 1;
        S8(arg0, 5) = 0;
        return;
    }
    if (S16(arg0, 0x58) != 0) {
        p = *(void**)((u8*)arg0 + 0x50);
        S32(arg0, 0x8) = S32(p, 0x18);
        S32(arg0, 0xC) = S32(p, 0x1C);
        S16(arg0, 0x58) = S16(arg0, 0x58) - 1;
        return;
    }
    S8(arg0, 3) = 0;
    S8(arg0, 4) = 0;
    if (S8(arg0, 2) == 2) {
        S8(arg1, 0x8C) = 0;
    }
}
