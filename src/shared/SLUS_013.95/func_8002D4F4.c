#include "common.h"

extern u16 D_80097120;

s32 func_8002D4F4(void) {
    s32 var_v0;

    var_v0 = (D_80097120 & 0xF) != 0;
    if (D_80097120 & 0x1B0) {
        var_v0 += 1;
    }
    return var_v0;
}
