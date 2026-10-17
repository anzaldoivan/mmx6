#include "common.h"

void func_800EA5A0(u8* arg0) {
    if (--*(s16*)(arg0 + 0x7C) == 0) {
        arg0[5] = 4;
        arg0[6] = 0;
    }
}
