/* Adapted from sozud/mmx4 @29b62af src/main/mains/main_13_heavy_mech.c:heavy_mech_face_player, AGPL-3.0; proven shared with X6 by exact signature d7798d86256f (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern struct X4_PlayerObj D_800970A0;

void func_800F32A8(struct X4_AnimatedObj* self) {
    if (self->x_pos.val > D_800970A0.x_pos.val) {
        self->unk15 = 0;
    } else {
        self->unk15 = 0x40;
    }
}
