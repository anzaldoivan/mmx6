#include "common.h"

void func_80042F7C(s8 arg0, s8* arg1, s8* arg2) {
    s32 temp_a0;

    temp_a0 = arg0 - 1;
    *arg1 = (temp_a0 / 2) + 0x13;
    *arg2 = temp_a0 & 1;
}
