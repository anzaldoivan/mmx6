// prog SLUS_013.95 | system player | range 0x8003F200-0x8003F288
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#include "mmx6/graphics.h"

// 0x8003F200 start_hover: Blade hover boots execution.
// basis: community tweaks-index.tsv:244
// callers: none known
s32 start_hover(struct X4_PlayerObj* self) {
    u8 v;

    v = self->armor;
    if (v != 4) {
        return 0;
    }
    if (!(self->pressed_input & 0x80)) {
        return 0;
    }
    self->x_vel.val = 0;
    self->x_accel = 0;
    self->y_vel.val = 0;
    self->gravity = 0;
    self->dash_momentum = 0;
    self->air_action = v;
    self->afterimage = 0;
    *(u8*)&self->is_clone = 0xB4;
    *(u8*)&self->clone_timer = 0;
    player_set_animation_shooting(self, 0x15);
    self->action = 0x21;
    self->action_phase = 0;
    return 1;
}
