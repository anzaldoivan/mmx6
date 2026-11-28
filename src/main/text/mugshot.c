#include "common.h"
#include "mmx6/x4.h"

extern struct X4_EngineObj g_playthrough_state;

// 0x800228AC get_player_mugshot: player mugshot selection.
// basis: community tweaks-index.tsv:374
// callers: none known
s32 get_player_mugshot(void) {
    struct X4_EngineObj* p = &g_playthrough_state;
    s32 ret;
    u8 v;

    if (*(s8*)&p->controlled_player == 0) {
        v = p->sub_tanks[2];
        if (v == 0) {
            ret = 0;
        } else if (v == 4) {
            ret = 2;
        } else if (v == 1) {
            ret = 3;
        } else if (v == 2) {
            ret = 4;
        } else {
            ret = 5;
        }
    } else {
        ret = 1;
        if (p->unk5F & 0x20) {
            ret = 6;
        }
    }
    return ret;
}
