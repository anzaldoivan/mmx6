#include "common.h"

void func_800E9D04(u8* arg0) {
    s32 t;

    t = *(u16*)(arg0 + 4) - 1;
    *(u16*)(arg0 + 4) = t;
    if ((t << 16) == 0) {
        arg0[1]++;
    }
}
