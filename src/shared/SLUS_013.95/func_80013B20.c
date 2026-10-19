#include "common.h"

void func_80013B20(s32* src, s32* dst, s32 n) {
    do {
        *dst++ = *src++;
    } while (--n);
}
