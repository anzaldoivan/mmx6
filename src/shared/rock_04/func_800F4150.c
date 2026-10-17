#include "common.h"

void func_800F4150(u8* arg0) {
    if (--*(s16*)(arg0 + 0x7C) == 0) {
        arg0[6] -= 2;
    }
}
