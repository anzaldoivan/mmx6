#include "common.h"

extern u8 D_800E9860[];

// 0x800E9E2C tick_boss_intro: boss intro sound step.
// basis: community tweaks-index.tsv:329
// callers: none known
void tick_boss_intro(u8* arg0) {
    u8 buf[8];

    __builtin_memcpy(buf, D_800E9860 + 4, 8);
    if (--*(s16*)(arg0 + 4) == 0) {
        *(s16*)(arg0 + 4) = 0xB4;
        arg0[1]++;
    }
}
