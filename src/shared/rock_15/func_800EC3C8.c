/* Adapted from sozud/mmx4 @4e16dfc src/main/mains/main_06_bulldozer.c:bulldozer_fall, AGPL-3.0; proven shared with X6 by exact signature 6c63f20ba27c (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32
M2C_UNK apply_object_motion(void*);

M2C_UNK animate_object();
void func_800EC3C8(struct X4_MainObj* self) {
    ((void (*)())animate_object)(ANIMATED_OBJECT(self));
    if (self->collision_flags & 8) {
        self->action = 2;
        self->action_phase = 0;
        self->y_speed = 0;
        self->gravity = 0;
        self->x_speed = 0;
        self->x_accel = 0;
        self->air_state = 0;
        return;
    }
    ((void (*)())apply_object_motion)(ANIMATED_OBJECT(self));
}
