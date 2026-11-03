#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK animate_object();
M2C_UNK apply_object_motion(void*);

void func_800EDAD4(struct X4_MainObj* self) {
    ((M2C_UNK(*)())animate_object)();
    {
        // !FAKE: depin: dropping it breaks the match (25/29)
        register s32 c asm("$2") = self->unk7C;
        if (c != 0) {
            self->unk7C--;
            return;
        }
    }
    apply_object_motion(self);
    if (self->y_speed > 0x1FFFF) {
        self->gravity = 0x1000;
    }
    if (self->y_speed == 0) {
        self->action_phase = 0;
    }
}
