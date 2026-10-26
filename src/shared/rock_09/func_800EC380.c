/* Adapted from sozud/mmx4 @807a01b src/main/mains/main_32_bomb_bat.c:bomb_bat_hover_start, AGPL-3.0; proven shared with X6 by exact signature c21d8b683171 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32
M2C_UNK func_80017A04();
void func_800EC380(struct X4_MainObj* self) {
    ((void (*)())func_80017A04)(ANIMATED_OBJECT(self));
    self->unk7C = 0xC8;
    self->unk6++;
}
