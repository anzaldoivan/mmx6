// prog SLUS_013.95 | system player | range 0x8003D630-0x8003D714
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/movement.h"

// 0x8003D630 init_move_stats: base movement stats, then the deltas of equipped parts and armor 2.
// basis: code via=equipped_parts; derived.tsv:127
// callers: update_stage_entry
M2C_UNK init_move_stats(void* arg0) {
    struct X4_PlayerObj* self = arg0;

    set_base_move_stats(self);
    if (self->equipped_parts & 8) {
        self->jump_gravity -= 0x1080;
    }
    if (self->armor == 2) {
        self->slide_down_speed = 0;
    }
    if (self->equipped_parts & 0x10) {
        self->dash_speed += 0x1A000;
        self->dash_base_speed += 0x10800;
        self->unk10C += 0xC00;
        self->unk12C += 0x10800;
        self->unk130 += 0x10800;
    }
    if (self->equipped_parts & 4) {
        self->walk_start_speed += 0x4000;
        self->walk_speed += 0x10000;
    }
}
