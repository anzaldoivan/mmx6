#include "common.h"

void func_8001DD74(u8* arg0) {
    s32 v;

    v = *(u16*)(arg0 + 4) + 1;
    *(u16*)(arg0 + 4) = v;
    if ((s16)v >= 3) {
        arg0[1]++;
    }
}
