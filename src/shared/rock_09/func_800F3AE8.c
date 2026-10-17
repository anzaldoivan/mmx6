#include "common.h"

extern s16 D_800970AA;

#define F(T, p, o) (*(T*)((u8*)(p) + (o)))

void func_800F3AE8(void* arg0) {
    s32 g;
    s32 x;
    s32 v;

    if (F(s16, arg0, 0x7E) == 2) {
        F(u8, arg0, 6) = 9;
        return;
    }
    g = D_800970AA;
    x = F(s16, arg0, 0xA);
    F(s32, arg0, 0x24) = 0x58000;
    F(s32, arg0, 0x2C) = 0x2C00;
    v = (g - x) << 10;
    F(s32, arg0, 0x20) = v;
    if (v < 0) {
        F(u8, arg0, 0x15) = 0;
    } else {
        F(u8, arg0, 0x15) = 0x40;
    }
    F(u8, arg0, 6) = 0xD;
}
