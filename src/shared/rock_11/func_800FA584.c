#include "common.h"

extern s32 D_80097420;

s32 func_800FA584(s16* arg0, s16 arg1, s16 arg2, s16 arg3) {
    u32 rem;
    s32 d;

    rem = (u32)D_80097420 % (u32)arg3;
    if (rem != 0) {
        return rem;
    }
    d = *arg0 - arg1;
    if (d >= 0 ? (d <= arg2) : (arg1 - *arg0 <= arg2)) {
        *arg0 = arg1;
        return 1;
    }
    if (arg1 < *arg0) {
        *arg0 -= arg2;
    } else if (*arg0 < arg1) {
        *arg0 += arg2;
    }
    return 0;
}
