#include "common.h"

void func_800EA980(u8* arg0) {
    if (--*(s16*)(arg0 + 0x7C) == 0) {
        *(s16*)(arg0 + 0x7C) = 0xA;
        arg0[6]++;
    }
}
