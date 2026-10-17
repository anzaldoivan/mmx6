#include "common.h"

extern s16 D_800970AA;

void func_800F2B4C(u8* e) {
    s16 x = *(s16*)(e + 0xA);

    if (D_800970AA < x) {
        e[0x15] = 0;
    } else {
        e[0x15] = 0x40;
    }
}
