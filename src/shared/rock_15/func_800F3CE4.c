/* Adapted from sozud/mmx4 @29b62af src/main/mains/main_49_train_soldier.c:train_soldier_jump_crouch, AGPL-3.0; proven shared with X6 by exact signature 7d7e8abd4964 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32
M2C_UNK func_80017A04();
void func_800F3CE4(struct X4_MainObj* self) {
    ((void (*)())func_80017A04)((struct X4_AnimatedObj*)self);
    if (self->animation_step.fields.event != 0) {
        self->unk6++;
    }
}
