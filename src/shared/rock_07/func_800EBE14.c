#include "common.h"

s32 func_8002D2D4();

void func_800EBE14(u8* arg0) {
    s32 r;

    r = func_8002D2D4();
    arg0[6]++;
    *(s16*)(arg0 + 0x7C) = r % 40 + 50;
}
