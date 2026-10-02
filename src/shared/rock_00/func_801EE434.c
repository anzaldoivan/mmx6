#include "common.h"

extern s32 D_8009718C;

s32 func_801EE434(void) {
    s32 var_v1;

    var_v1 = 0x7802;
    if (D_8009718C & 0x180) {
        var_v1 = 0x7844;
    }
    return var_v1;
}
