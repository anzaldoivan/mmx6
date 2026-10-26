/* Adapted from sozud/mmx4 @807a01b src/main/enemy_reaction.c:spike_crawler_hit_flash, AGPL-3.0; proven shared with X6 by exact signature 0f5c026ba0d7 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"

void spike_crawler_hit_flash(struct X4_MainObj* self) {
    if (self->unk6 == 0) {
        self->unk6++;
        self->invincibility_timer = 0x28;
    }
    if (BLINK_CLOCK(self->invincibility_timer) & 7) {
        self->unk42 &= 0x7FFF;
    } else {
        self->unk42 |= 0x8000;
    }
    if (--self->invincibility_timer == 0) {
        self->unk5 = 1;
        self->unk6 = 0;
        self->unk42 &= 0x7FFF;
    }
}
