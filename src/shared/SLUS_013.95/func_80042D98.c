#include "common.h"

extern s32 D_800C1220[];

void func_80042D98(s8* arg0) {
    s8* p;
    s32 dx;
    s32 dy;
    s32 d;
    s32 best;

    *(s8**)(arg0 + 0x80) = 0;
    best = 1000000;
    for (p = (s8*)D_800C1220; p < (s8*)D_800C1220 + 0x3340; p += 0xA4) {
        if (p[0] != 0 && p[1] == 4 && p[3] != 0 && p[7] == 1) {
            dx = *(s16*)(arg0 + 0xA) - *(s16*)(p + 0xA);
            dy = *(s16*)(arg0 + 0xE) - *(s16*)(p + 0xE);
            d = dx * dx + dy * dy;
            if (d < best) {
                best = d;
                *(s8**)(arg0 + 0x80) = p;
            }
        }
    }
}
