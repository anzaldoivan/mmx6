/* Adapted from sozud/mmx4 @807a01b src/main/mains/main_06_bulldozer.c:bulldozer_fall, AGPL-3.0; proven shared with X6 by exact signature 6c63f20ba27c (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32
M2C_UNK func_8002D230(void*);

M2C_UNK func_80017A04();
void func_800EC3C8(struct X4_MainObj* self) {
    ((void (*)())func_80017A04)(ANIMATED_OBJECT(self));
    if (self->collision_flags & 8) {
        self->unk5 = 2;
        self->unk6 = 0;
        self->y_speed = 0;
        self->gravity = 0;
        self->x_speed = 0;
        self->x_accel = 0;
        self->air_state = 0;
        return;
    }
    ((void (*)())func_8002D230)(ANIMATED_OBJECT(self));
}
