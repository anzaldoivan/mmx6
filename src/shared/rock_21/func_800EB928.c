#include "common.h"

extern s8 D_800971FB;

static inline s32 func_800EB928_tick(u8* p) {
    if ((*(s16*)(p + 4))++ >= 0x186) {
        *(s16*)(p + 4) = 0;
        return 1;
    }
    return 0;
}

void func_800EB928(u8* arg0) {
    if (func_800EB928_tick(arg0)) {
        D_800971FB = 0;
        arg0[1] += 1;
    }
}
