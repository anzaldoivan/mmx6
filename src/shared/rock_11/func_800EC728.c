#include "common.h"

extern s8 D_8008EF48[];

s32 func_800EC728(s8* arg0) {
    s8* p;
    s32 n = 0;

    for (p = D_8008EF48; p < D_8008EF48 + 0x1D40; p += 0x9C) {
        if (p != arg0 && p[0] != 0 && p[1] == arg0[1]) {
            n++;
            if (n >= 4) {
                return 1;
            }
        }
    }
    return 0;
}
