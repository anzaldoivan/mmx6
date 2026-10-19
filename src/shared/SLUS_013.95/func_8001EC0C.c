#include "common.h"
#define M2C_UNK s32

s32 func_8001EC0C(void* arg0) {
    s8* p = arg0;
    s8 temp_a0;

    if (p[0xC] != 0xC) {
        return 0;
    }
    temp_a0 = p[0x1D];
    if (temp_a0 < 2) {
        return 0;
    }
    return temp_a0 < 0xA;
}
