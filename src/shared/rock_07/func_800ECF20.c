#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_8002D230(void*);
M2C_UNK func_8002EE10(void*);

void func_800ECF20(struct X4_PlayerObj* self) {
    ((void (*)(void*))func_8002D230)(self);
    if (self->unk70 != 0 || (func_8002EE10(self), self->unk70 != 0)) {
        ((void (*)(s32, s32, void*))func_80016C48)(2, 0x4D, self);
        self->x_vel.val = -0x10000;
        M2C_FIELD(self, u8*, 0x91) = 1;
        self->y_vel.val = 0;
        M2C_FIELD(self, s16*, 0x88) = 0x3C;
        self->unk7++;
    }
}
