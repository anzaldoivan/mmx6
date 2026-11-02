#include "common.h"

extern s16 D_800970AA;

void func_800EB644(u8* arg0) {
    s32 a;
    s32 b;

    if (--*(s16*)(arg0 + 0x7C) == 0) {
        arg0[6]++;
    }
    a = D_800970AA;
    b = *(s16*)(arg0 + 0xA);
    if (((a - b) >= 0 ? (a - b) : (b - a)) < 0x30) {
        arg0[6]++;
    }
}
