#include "common.h"
#define M2C_UNK s32

s32 func_800ECD7C(s32 arg0, M2C_UNK arg1, M2C_UNK arg2) {
    s16* p = (s16*)arg0;
    s16 tgt = arg1;
    s16 step = arg2;
    s32 d;

    d = *p - tgt;
    if (d >= 0 ? (d <= step) : (tgt - *p <= step)) {
        *p = tgt;
        return 1;
    }
    if (tgt < *p) {
        *p -= step;
    } else if (*p < tgt) {
        *p += step;
    }
    return 0;
}
