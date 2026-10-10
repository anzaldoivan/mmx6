/* Adapted from sozud/mmx4 @29b62af src/main/mains/main_51_fortress_cannon.c:fortress_cannon_check_fall, AGPL-3.0; proven shared with X6 by exact signature 838e32cf3933 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"

void func_800EC428(struct X4_MainObj* self) {
    if (self->air_state == 0 && !(self->collision_flags & 8)) {
        self->unk5 = 6;
        self->unk6 = 0;
        self->y_speed = 0;
        self->gravity = FIXED(0.2578125);
        self->x_speed = 0;
        self->x_accel = 0;
        self->air_state = 1;
    }
}
