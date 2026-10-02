/* Adapted from sozud/mmx4 @29b62af src/main/mains/main_65_magma_dragoon.c:magma_dragoon_face_player, AGPL-3.0; proven shared with X6 by exact signature 3d82c3af21bb (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern struct X4_PlayerObj D_800970A0;

void func_80042C18(struct X4_MainObj* self) {
    if (D_800970A0.x_pos.i.hi > self->x_pos.i.hi) {
        self->unk15 = 0x40;
    } else {
        self->unk15 = 0;
    }
}
