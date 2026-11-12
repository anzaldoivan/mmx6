/* Adapted from sozud/mmx4 @4e16dfc src/main/player.c:player_hurt, AGPL-3.0; proven shared with X6 by exact signature 94a81587fc1f (see THIRD_PARTY.md). */
// prog SLUS_013.95 | system player | range 0x80037838-0x8003787C
// Shared file: included by src/SLUS_013.95/32208.c, between player_ladder_let_go and update_hurt_knockback.
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
// D_80073C30: the hurt handlers, one per hurt type, used by player_hurt (index X4_PlayerObj.hurt_type).
extern void (*D_80073C30[])(struct X4_PlayerObj*);
M2C_UNK animate_object();

// 0x80037838 player_hurt: runs the hurt handler that the player's hurt type selects.
// basis: x4 94a81587fc1f
// callers: none known
// reads: X4_PlayerObj.hurt_type (+0x63, s8), the index into D_80073C30.
// uses: animate_object on the player as an X4_AnimatedObj, before the handler runs.
void player_hurt(struct X4_PlayerObj* self) {
    animate_object(ANIMATED_OBJECT(self));
    D_80073C30[self->hurt_type](self);
}
