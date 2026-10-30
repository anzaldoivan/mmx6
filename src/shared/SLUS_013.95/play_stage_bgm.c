#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_bgm_xa_track(M2C_UNK, M2C_UNK);
extern u8 g_stage_bgm_tracks[];
extern struct X4_EngineObj g_playthrough_state;

// 0x8001854C play_stage_bgm: plays the XA music track for the current stage, substage and player.
// basis: code src/shared/SLUS_013.95/play_stage_bgm.c:17 via=g_stage_bgm_tracks
// callers: func_8001E78C, func_80051B74
void play_stage_bgm(void) {
    struct X4_EngineObj* e = &g_playthrough_state;

    if (*(u16*)&e->stage != 0x10F) {
        ((void (*)(M2C_UNK, M2C_UNK, void*))play_bgm_xa_track)(
            g_stage_bgm_tracks[(e->stage * 8 + e->substage * 4) +
                       *(s8*)&e->controlled_player * 2],
            0x63, e);
    }
}
