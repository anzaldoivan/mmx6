#include "common.h"
#include "mmx6/x4.h"

extern struct X4_EngineObj g_playthrough_state;

// 0x8003D014 check_low_health: low health voice site.
// basis: community tweaks-index.tsv:328
// callers: func_80035BDC, func_80037880, func_80037920
void check_low_health(void* arg0) {
    s8* p = arg0;
    // !FAKE: base register
    register s8* b asm("$2");

    if (p[0x8D] == 0) {
        b = (s8*)&g_playthrough_state;
        {
            s32 i = p[2];
            b -= -i;
        }
        if (p[0x5C] < (s8)(b[0x5B] / 3)) {
            p[0x8D] = 0x78;
        }
    }
}
