#include "common.h"

extern s16 D_800970AA;

void func_800F3450(u8* arg0) {
    s32 t = D_800970AA;

    if (*(s16*)(arg0 + 0xA) < t) {
        arg0[0x15] = 0x40;
    } else {
        arg0[0x15] = 0;
    }
    *(s16*)(arg0 + 0x7C) = 0;
    *(s16*)(arg0 + 0x7E) = 0;
    arg0[7] = 0;
    arg0[6] += 2;
}
