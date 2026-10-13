#include "common.h"

extern u8 D_800964A0[];

s8* func_8002C590(void) {
    s8* p;
    s8* end;
    s8* d;
    s32 k;

    p = (s8*)D_800964A0;
    end = p + 0xC00;
    for (; p < end; p += 0x60) {
        if (*p == 0) {
            d = p;
            for (k = 0x5F; k != -1; k--) {
                *d++ = 0;
            }
            return p;
        }
    }
    return 0;
}
