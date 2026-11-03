/* Adapted from sozud/mmx4 @807a01b src/main/player_common.c:player_update_flash, AGPL-3.0; proven shared with X6 by exact signature e08fdf21be18 (see THIRD_PARTY.md). */
// prog SLUS_013.95 | system player | range 0x8003CE38-0x8003CF20
#include "common.h"
#include "mmx6/x4.h"

// 0x8003CE38 player_update_flash: steps the shot and hurt palette flashes.
// basis: x4 exact e08fdf21be18
// callers: update_player
void player_update_flash(struct X4_PlayerObj* self) {
    s8 action = self->action; // likely fake
    if ((self->action != PLAYER_BEAM_IN) && (action != PLAYER_BEAM_OUT) &&
        (self->hurt_phase <= 0)) {
        if (self->shot_palette_timer != 0) {
            if (--self->shot_palette_timer == 0) {
                player_load_weapon_palette(self);
            }
        }
        if (self->hurt_phase < 0) {
            self->flash_palette = 0x23;
        }
        if (self->flash_palette != 0) {
            if (self->flash_delay != 0) {
                self->flash_delay--;
            } else {
                if (self->flash_phase == 0) {
                    load_player_palette(self, self->flash_palette);
                } else {
                    player_load_weapon_palette(self);
                }
                self->flash_delay = 1;
                if (FLICKER_ENABLED) {
                    self->flash_phase ^= 1;
                }
            }
            self->flash_palette = 0;
        }
    }
}
