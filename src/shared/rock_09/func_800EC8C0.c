/* Adapted from sozud/mmx4 @807a01b src/main/mains/main_32_bomb_bat.c:bomb_bat_dive_fall, AGPL-3.0; proven shared with X6 by exact signature 551fe75c1ef0 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32
M2C_UNK animate_object();
M2C_UNK move_object(s32);
void func_800EC8C0(struct X4_MainObj* self) {
    ((void (*)())animate_object)(ANIMATED_OBJECT(self));
    ((void (*)())move_object)(MOVING_OBJECT(self));
    self->y_speed += 0x100;
}
