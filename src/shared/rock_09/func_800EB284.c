/* Adapted from sozud/mmx4 @29b62af src/main/mains/main_65_magma_dragoon.c:magma_dragoon_face_player, AGPL-3.0; proven shared with X6 by exact signature 3d82c3af21bb (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern s32 g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)

void func_800EB284(struct X4_MainObj* self) {
    if (g_Player.x_pos.i.hi > self->x_pos.i.hi) {
        self->unk15 = 0x40;
    } else {
        self->unk15 = 0;
    }
}
#undef g_Player
