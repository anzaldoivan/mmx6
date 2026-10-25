/* Adapted from sozud/mmx4 @29b62af src/main/mains/main_13_heavy_mech.c:heavy_mech_face_player, AGPL-3.0; proven shared with X6 by exact signature d7798d86256f (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
extern s32 g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)

void func_800EC5B8(struct X4_AnimatedObj* self) {
    if (self->x_pos.val > g_Player.x_pos.val) {
        self->unk15 = 0;
    } else {
        self->unk15 = 0x40;
    }
}
#undef g_Player
