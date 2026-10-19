#include "common.h"

extern s8 D_800CCEF6;

void func_800F250C(u8* arg0) {
    u8* p;

    p = *(u8**)(arg0 + 0x10);
    if (p != 0) {
        *p = 0x80;
    }
    D_800CCEF6 = 0;
    arg0[0xA8] = 0;
    arg0[0] = 0;
    arg0[2] = 0;
    arg0[3] = 0;
    arg0[4] = 0;
    arg0[5] = 0;
    arg0[6] = 0;
    arg0[7] = 0;
}
