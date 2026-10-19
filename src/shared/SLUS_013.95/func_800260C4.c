#include "common.h"

u32 func_800260C4(s32 arg0, s32 arg1, s32 arg2) {
    s32 r, g, b;
    u32 v;

    r = arg0 * 0x4D;
    g = arg1 * 0x97;
    b = arg2 * 0x1C;
    v = r + g + b;
    if (v > 0xFFFF) {
        v = 0xFFFF;
    }
    v >>= 8;
    return v & 0xFFFF;
}
