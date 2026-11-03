// prog SLUS_013.95 | system movement | range 0x8003D718-0x8003D7A8
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/effect.h"
#include "mmx6/engine_state.h"
#include "mmx6/weapon.h"

// 0x8003D718 load_armor_and_parts: player init: copies armor, parts and beaten stages from the playthrough state.
// basis: code via=equipped_parts; derived.tsv:128
// callers: update_stage_entry
M2C_UNK load_armor_and_parts(void* arg0) {
    struct X4_PlayerObj* self = arg0;
    u8 m = g_playthrough_state.sub_tanks[2];

    self->armor = m;
    self->equipped_parts =
        *(s32*)((u8*)&g_playthrough_state + 0x74 + self->character * 4);
    if (m == 2) {
        self->beaten_stages = 0;
        player_spawn_visual(1, 0x1B, 5, 0);
        load_buffered_palette(2, 0x19, 1);
        load_buffered_palette(2, 0x18, 1);
        return;
    }
    self->beaten_stages = g_playthrough_state.unk60;
}
