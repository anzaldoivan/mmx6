/* Adapted from sozud/mmx4 @807a01b src/main/enemy_reaction.c:spike_crawler_hit_flash, AGPL-3.0; proven shared with X6 by exact signature 0f5c026ba0d7 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"

void spike_crawler_hit_flash(struct X4_MainObj* self) {
    if (self->action_phase == 0) {
        self->action_phase++;
        self->invincibility_timer = 0x28;
    }
    if (BLINK_CLOCK(self->invincibility_timer) & 7) {
        self->unk42 &= 0x7FFF;
    } else {
        self->unk42 |= 0x8000;
    }
    if (--self->invincibility_timer == 0) {
        self->action = 1;
        self->action_phase = 0;
        self->unk42 &= 0x7FFF;
    }
}
