#include "common.h"

void func_80013B40(s32* src, s32* dst, s32 n) {
    do {
        s32 a = src[0];
        s32 b = src[1];
        // !FAKE: target keeps the third word in t0
        register s32 c asm("$8") = src[2];
        // !FAKE: target keeps the fourth word in t1
        register s32 d asm("$9") = src[3];
        dst[0] = a;
        dst[1] = b;
        dst[2] = c;
        dst[3] = d;
        do {
            src += 4;
        } while (0);
        n--;
        dst += 4;
    } while (n != 0);
}
