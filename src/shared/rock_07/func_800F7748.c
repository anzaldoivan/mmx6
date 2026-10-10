#include "common.h"

void func_800F7748(u8* arg0) {
    s32 t;

    t = *(u16*)(arg0 + 0x88) - 1;
    *(u16*)(arg0 + 0x88) = t;
    if ((t << 16) == 0) {
        *(u16*)(arg0 + 0x88) = 0x1E;
        arg0[6]++;
    }
}
