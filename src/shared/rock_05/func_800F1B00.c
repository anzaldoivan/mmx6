#include "common.h"

extern u8 D_800CCF5F;

void func_800F1B00(u8* arg0) {
    u8 v = D_800CCF5F;

    if (v == 0) {
        *(s16*)(arg0 + 0x7E) = 0;
    } else if (v == 1) {
        *(s16*)(arg0 + 0x7E) = v;
    } else {
        *(s16*)(arg0 + 0x7E) = 2;
    }
    arg0[6] = arg0[6] + 1;
}
