#include "common.h"

s32 func_8002B2F8(s32);
extern s32 D_80090C9C;
extern s8 D_80090D56;
extern s8 D_8009742C;
extern u8 D_800C4560;
extern s8 D_800CF850;

#define F33A4(type, off) (*(type*)((u8*)self + (off)))

void func_800F33A4(void* self) {
    F33A4(u8, 0x7) = 0;
    if (--F33A4(s16, 0x7C) == 0) {
        func_8002B2F8(0);
        D_80090D56 = 0;
        D_8009742C = 0;
        D_800CF850 = 0;
        D_80090C9C = 0x10000;
        D_800C4560 |= 1;
        F33A4(s16, 0x7C) = 3;
        F33A4(u8, 0x6)++;
    }
    if (--F33A4(s16, 0x7E) == 0) {
        F33A4(s16, 0x7E) = 0x3C;
    }
}

#undef F33A4
