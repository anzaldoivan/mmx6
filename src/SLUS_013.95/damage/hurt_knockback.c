// prog SLUS_013.95 | system damage | range 0x80037880-0x8003791C
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void move_x_backward(void* arg0);
void end_dash(s32 arg0);
void player_load_weapon_palette(struct X4_PlayerObj* self);
void load_player_palette(struct X4_PlayerObj*, s32);
void check_low_health(void* arg0);

// 0x80037880 update_hurt_knockback: hurt handler for hurt types 0, 1 and 4: x motion through move_x_backward; when invincibility_timer reaches 0x3C runs end_dash, then check_low_health unless locked.
// basis: oracle derived.tsv:86; oracle:docs/systems/movement.md mv_wall-0021 mv_wall-0023 mv_wall-0024 mv_lowhp-0044
// callers: player_hurt
// dispatch: D_80073C30[0], [1], [4] in player_hurt (hurt_type)
void update_hurt_knockback(void* arg0) {
    struct X4_PlayerObj* self = arg0;

    move_x_backward(self);
    if (self->character == 0) {
        if (self->animation_step.fields.frame_index == 0xD0) {
            load_player_palette(self, 0x52);
        } else {
            player_load_weapon_palette(self);
        }
    }
    if (self->invincibility_timer == 0x3C) {
        ((void (*)(s32))end_dash)((s32)self);
        if (self->move_lock != 0) {
            self->hurt_phase = 0;
            self->invincibility_timer = 0;
            return;
        }
        check_low_health(self);
        self->hurt_phase = -1;
    }
}
