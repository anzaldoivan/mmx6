/* Adapted from sozud/mmx4 @29b62af src/main/player_weapon.c:player_set_animation_shooting, AGPL-3.0; proven shared with X6 by exact signature b7ee5de16676 (see THIRD_PARTY.md). */
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
M2C_UNK func_8003BA04(void*, M2C_UNK);

void func_8003F4C4(struct X4_PlayerObj* self, s32 animation) {
    if (self->unk2 == 0 && self->attacking != 0) {
        animation += 0x70;
    }
    func_8003BA04(self, animation);
}
