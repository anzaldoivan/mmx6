#include "common.h"

s32 random_byte();

void func_800EBE14(u8* arg0) {
    s32 r;

    r = random_byte();
    arg0[6]++;
    *(s16*)(arg0 + 0x7C) = r % 40 + 50;
}
