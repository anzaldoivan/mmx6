#include "common.h"

void func_800F777C(u8* arg0) {
    if (*(u16*)(arg0 + 0x88) & 1) {
        arg0[3] = 1;
    } else {
        arg0[3] = 0;
    }
    if (--*(s16*)(arg0 + 0x88) == 0) {
        arg0[3] = 0;
        arg0[4] = 2;
    }
}
