/* Adapted from sozud/mmx4 @29b62af src/main/afterimage.c:func_800AEA58, AGPL-3.0; proven shared with X6 by exact signature 2a177c96c5fb (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"

void func_80021254(struct X4_UnkObj* self, struct X4_PlayerObj* player) {
    self->ext.afterimage.position_timer = 3;
    self->ext.afterimage.blink_timer = 8;
    self->ext.afterimage.palette_offset = (5 - self->unk2) * 2;
    self->x_pos.val = player->x_pos.val;
    self->y_pos.val = player->y_pos.val;
    self->state = 1;
    self->unk5 = 0;
}
