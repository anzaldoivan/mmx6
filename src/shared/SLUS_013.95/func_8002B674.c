#include "common.h"

extern s32 D_80090C90[][16];

void func_8002B674(s32 arg0, s32 arg1) {
    s32 b = (s32)D_80090C90;
    s32* p = (s32*)(((arg1 >> 5) << 2) + (arg0 << 6) + b);
    *p &= ~(0x80000000U >> (arg1 & 0x1F));
}
