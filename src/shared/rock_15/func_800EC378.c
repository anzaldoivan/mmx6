/* Adapted from sozud/mmx4 @4e16dfc src/main/mains/main_51_fortress_cannon.c:fortress_cannon_lower_end, AGPL-3.0; proven shared with X6 by exact signature db765c44764d (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32
M2C_UNK animate_object();
void func_800EC378(struct X4_MainObj* self) {
    ((void (*)())animate_object)(ANIMATED_OBJECT(self));
    if (--self->unk7C == 0) {
        self->action = 2;
        self->action_phase = 0;
        self->unk7C = 0x28U;
    }
}
