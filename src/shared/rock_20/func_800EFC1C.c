#include "common.h"

void func_800EFC1C(u8* arg0) {
    u8 v = arg0[0x158];
    u32 i;
    if (v == 0xFF) {
        arg0[0] = 3;
    } else {
        arg0[0] = 0x13;
        arg0[0x1D] = v;
    }
    arg0[1] = 0;
    arg0[2] = 0;
    arg0[3] = 0;
    do {
        i = 0;
    } while (0);
    arg0 += 0x26;
    do {
        arg0[i] = 0;
    } while (++i < 0x10);
}
