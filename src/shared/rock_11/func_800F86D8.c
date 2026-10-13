#include "common.h"
#define M2C_UNK s32

M2C_UNK func_800179A4(void*, M2C_UNK);
s32 func_8002D2D4();
extern s16 D_8009721E;

void func_800F86D8(u8* arg0) {
    u32 r;

    ((void (*)(void*, s32))func_800179A4)(arg0, 0);
    if (*(s16*)(arg0 + 0xA) < D_8009721E + 0xA8) {
        arg0[0x15] = 0x40;
        *(s32*)(arg0 + 0x20) = 0x20000;
    } else {
        arg0[0x15] = 0;
        *(s32*)(arg0 + 0x20) = 0xFFFE0000;
    }
    *(s32*)(arg0 + 0x24) = 0;
    *(s16*)(arg0 + 0x7C) = 0x3C;
    r = func_8002D2D4();
    arg0[6]++;
    arg0[7] = r % 3;
}
