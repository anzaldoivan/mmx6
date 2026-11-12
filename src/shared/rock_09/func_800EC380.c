/* Adapted from sozud/mmx4 @4e16dfc src/main/mains/main_32_bomb_bat.c:bomb_bat_hover_start, AGPL-3.0; proven shared with X6 by exact signature c21d8b683171 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32
M2C_UNK animate_object();
void func_800EC380(struct X4_MainObj* self) {
    ((void (*)())animate_object)(ANIMATED_OBJECT(self));
    self->unk7C = 0xC8;
    self->action_phase++;
}
