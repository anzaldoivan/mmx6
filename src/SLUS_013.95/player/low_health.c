// prog SLUS_013.95 | system player | range 0x8003D014-0x8003D078
#include "common.h"
#include "mmx6/x4.h"

#include "mmx6/pilot_globals.h"

// 0x8003D014 check_low_health: low health voice site.
// basis: community tweaks-index.tsv:328
// callers: update_hurt_knockback
// unnamed callers: func_80035BDC, func_80037920
void check_low_health(void* arg0) {
    struct X4_EngineObj* e;
    struct X4_PlayerObj* p = arg0;
    s8* b;

    if (*(s8*)&p->low_health_timer == 0) {
        e = &g_playthrough_state;
        b = (s8*)e;
        {
            s32 i = p->character;
            b -= -i;
        }
        if (p->hp < (s8)(b[0x5B] / 3)) {
            p->low_health_timer = 0x78;
        }
    }
}
