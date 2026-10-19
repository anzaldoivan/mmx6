#include "common.h"

extern u8 D_800CCF38;

void func_800F3028(u8* arg0) {
    *(s16*)(arg0 + 0x7C) = 0xA;
    if (D_800CCF38 >= 2) {
        *(s16*)(arg0 + 0x7E) = 4;
    } else {
        *(s16*)(arg0 + 0x7E) = 2;
    }
    arg0[6]++;
}
