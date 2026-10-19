#include "common.h"

void func_800ECDB0(u8* arg0) {
    if (arg0[0x89] == 2) {
        arg0[0x89] = 0;
    }
    if (--*(s16*)(arg0 + 0x7C) == 0) {
        arg0[6] = 0;
    }
}
