#include "common.h"

extern s8 D_800CCEF6;

void func_800EED04(u8* arg0) {
    if ((u32)((u8)D_800CCEF6 - 1) < 8U) {
        arg0[1] = 2;
    } else {
        arg0[1] = 3;
    }
    arg0[2] = 0;
}
