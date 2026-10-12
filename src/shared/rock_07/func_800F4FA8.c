#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800179A4(void*, M2C_UNK);
s32 func_8002D2D4();

void func_800F4FA8(u8* arg0) {
    s32 a;
    s32 b;
    s32 q;

    if (*(s8*)(arg0 + 0x45) == 1) {
        func_800179A4(arg0, 4);
        a = (u8)((u32)func_8002D2D4() % 20) + 0x3C;
        b = (u8)((u32)func_8002D2D4() % 15) + 0xA;
        q = (a << 0x10) / ((b * b) >> 1);
        *(s32*)(arg0 + 0x2C) = q;
        *(s32*)(arg0 + 0x20) = 0;
        *(s32*)(arg0 + 0x28) = 0;
        arg0[6]++;
        *(s32*)(arg0 + 0x24) = q * b;
    }
}
