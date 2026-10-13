#include "common.h"

#define S8(p, o) (*(s8*)((u8*)(p) + (o)))
#define U8(p, o) (*(u8*)((u8*)(p) + (o)))
#define S16(p, o) (*(s16*)((u8*)(p) + (o)))
#define S32(p, o) (*(s32*)((u8*)(p) + (o)))
#define PTR(p, o) (*(u8**)((u8*)(p) + (o)))

void func_80020F8C(u8* arg0, u8* arg1) {
    u8* t;

    if (S8(arg1, 0x8C) > 0) {
        S16(arg0, 0x54) = 3;
        S16(arg0, 0x56) = 8;
        S16(arg0, 0x58) = (5 - S8(arg0, 2)) * 2;
        S32(arg0, 8) = S32(arg1, 8);
        {
            s32 c = S32(arg1, 0xC);
            U8(arg0, 4) = 1;
            U8(arg0, 5) = 0;
            S32(arg0, 0xC) = c;
        }
        return;
    }
    if (S16(arg0, 0x56) != 0) {
        S16(arg0, 0x56)--;
        if (S16(arg0, 0x56) & 1) {
            t = PTR(arg0, 0x50);
            S32(arg0, 8) = S32(t, 0x18);
            S32(arg0, 0xC) = S32(t, 0x1C);
        }
    } else {
        U8(arg0, 5)++;
    }
}
