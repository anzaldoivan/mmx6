// prog SLUS_013.95 | system dash | range 0x80039F78-0x80039FF8
#include "common.h"
#include "mmx6/x4.h"

// 0x80039F78 update_double_tap_dash: double-tap detection: an L/R press opens a 12-frame window; the same side again sets double_tap_dash.
// basis: code via=double_tap_dash; derived.tsv:98
// callers: update_player
void update_double_tap_dash(void* arg0) {
    struct X4_PlayerObj* self = arg0;
    s8 temp_v0;
    u16 temp_v0_2;

    self->double_tap_dash = 0;
    if ((self->move_lock == 0) && (temp_v0 = self->action, (temp_v0 != 0)) &&
        (temp_v0 != 1)) {
        if (self->double_tap_timer == 0) {
            temp_v0_2 = self->pressed_input & 3;
            self->double_tap_direction = temp_v0_2;
            if (temp_v0_2 != 0) {
                self->double_tap_timer = 0xC;
            }
        } else {
            self->double_tap_timer = (u8)self->double_tap_timer - 1;
            if (self->pressed_input & self->double_tap_direction) {
                self->double_tap_dash = 1;
                self->double_tap_timer = 0;
            }
        }
    }
}
