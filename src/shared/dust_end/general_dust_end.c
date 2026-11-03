/* Adapted from sozud/mmx4 @807a01b src/main/shots/shot_55_general_shot.c:general_dust_end, AGPL-3.0; proven shared with X6 by exact signature 76d90a83ca68 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32
M2C_UNK animate_object(void*);
void general_dust_end(struct X4_ShotObj* self) {
    ((void (*)())animate_object)(self);
    if (self->animation_step.fields.relative_step == 0) {
        self->state++;
    }
}
