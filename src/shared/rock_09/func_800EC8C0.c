/* Adapted from sozud/mmx4 @29b62af src/main/mains/main_32_bomb_bat.c:bomb_bat_dive_fall, AGPL-3.0; proven shared with X6 by exact signature 551fe75c1ef0 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32
M2C_UNK func_80017A04();
M2C_UNK move_object(s32);
void func_800EC8C0(struct X4_MainObj* self) {
    ((void (*)())func_80017A04)(ANIMATED_OBJECT(self));
    ((void (*)())move_object)(MOVING_OBJECT(self));
    self->y_speed += 0x100;
}
