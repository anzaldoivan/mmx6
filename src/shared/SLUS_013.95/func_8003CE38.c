/* Adapted from sozud/mmx4 @29b62af src/main/player_common.c:player_update_flash, AGPL-3.0; proven shared with X6 by exact signature e08fdf21be18 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"

void func_8003CE38(struct X4_PlayerObj* self) {
    s8 action = self->unk5; // likely fake
    if ((self->unk5 != PLAYER_BEAM_IN) && (action != PLAYER_BEAM_OUT) &&
        (self->hurt_phase <= 0)) {
        if (self->shot_palette_timer != 0) {
            if (--self->shot_palette_timer == 0) {
                func_8003C4EC(self);
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
                    func_8003CF54(self, self->flash_palette);
                } else {
                    func_8003C4EC(self);
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
