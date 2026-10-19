#include "common.h"

extern s16 D_800970AA;

void func_800F08E8(u8* arg0) {
    s32 g = D_800970AA;

    if (*(s16*)(arg0 + 0xA) < g) {
        arg0[0x15] = 0x40;
    } else {
        arg0[0x15] = 0;
    }
    if (*(s8*)(arg0 + 7) != 0) {
        arg0[5] = 5;
        arg0[6] = 0;
    }
}
