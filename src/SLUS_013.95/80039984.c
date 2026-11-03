// prog SLUS_013.95 | system movement | range 0x80039984-0x80039BC0
#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/collision.h"
#include "mmx6/movement.h"
#include "mmx6/sound.h"
#include "mmx6/weapon.h"

#define M2C_UNK s32

#define PICK(a, v)                                                             \
    switch (v) {                                                               \
    case 0x2D:                                                                 \
        a = 0;                                                                 \
        break;                                                                 \
    case 0x25:                                                                 \
    case 0x26:                                                                 \
    case 0x27:                                                                 \
    case 0x28:                                                                 \
        a = 1;                                                                 \
        if (self->facing == 0) {                                               \
            a = 2;                                                             \
        }                                                                      \
        break;                                                                 \
    default:                                                                   \
        a = 2;                                                                 \
        if (self->facing == 0) {                                               \
            a = 1;                                                             \
        }                                                                      \
        break;                                                                 \
    }

// 0x80039984 func_80039984: UP held over overhead tile 0x2E sets action 27 centred on it; over tiles 0x25-0x2D while not rising, action 28 with the y snap; returns 1 when taken.
// basis: none
// callers: handle_jump_rise
s32 func_80039984(void* arg0) {
    struct X4_PlayerObj* self = arg0;
    s32 v;
    s32 a;

    if (self->move_lock != 0) {
        return 0;
    }
    if (self->unkE3 != 0) {
        if (--self->unkE3 != 0) {
            return 0;
        }
    }
    if (!(self->input.buttons.held & 4)) {
        return 0;
    }
    v = func_8003040C(arg0);
    if (v == 0x2E) {
        if (self->attacking != 0 && self->character == 0) {
            player_set_animation(arg0, 0x90);
        } else {
            play_sound(0, 0x26, arg0);
            self->attacking = 0;
            player_set_animation(arg0, 0xA0);
        }
        self->x_pos.i.lo = 0;
        self->y_pos.i.lo = 0;
        self->action = 0x1B;
        self->action_phase = 0;
        self->x_vel.val = 0;
        self->x_pos.u.hi = (self->x_pos.u.hi & 0xFFF0) + 8;
        player_clear_dash(arg0);
        return 1;
    } else {
        if ((u8)(v - 0x25) >= 9) {
            return 0;
        }
        if (self->y_vel.val > 0) {
            return 0;
        }
        if (self->attacking != 0 && self->character == 0) {
            PICK(a, v);
            player_set_animation(arg0, a | 0x94);
        } else {
            play_sound(0, 0x26, arg0);
            PICK(a, v);
            player_set_animation(arg0, a + 0xA3);
            self->attacking = 0;
        }
        self->action = 0x1C;
        self->action_phase = 0;
        self->y_vel.val = 0;
        snap_to_tile_slope(arg0, v);
    }
    player_clear_dash(arg0);
    return 1;
}

#undef PICK
