/* Adapted from sozud/mmx4 @29b62af src/main/player.c:player_hurt, AGPL-3.0; proven shared with X6 by exact signature 94a81587fc1f (see THIRD_PARTY.md). */
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
extern void (*D_80073C30[])(struct X4_PlayerObj*);
M2C_UNK func_80017A04();

void func_80037838(struct X4_PlayerObj* self) {
    func_80017A04(ANIMATED_OBJECT(self));
    D_80073C30[self->hurt_type](self);
}
