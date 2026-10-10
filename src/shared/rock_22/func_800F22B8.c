#include "common.h"

extern s8 D_8008EF48[];

void func_800F22B8(s16* arg0) {
    s8* p;
    s16 v;

    for (p = D_8008EF48; p < D_8008EF48 + 0x1D40; p += 0x9C) {
        if (p[0] != 0 && p[1] == 0xD) {
            v = *(s16*)(p + 0xA);
            if (v >= arg0[0] && arg0[2] >= v) {
                v = *(s16*)(p + 0xE);
                if (v >= arg0[1] && arg0[3] >= v) {
                    *(s16*)(p + 0x7E) = 2;
                    p[4] = 4;
                }
            }
        }
    }
}
