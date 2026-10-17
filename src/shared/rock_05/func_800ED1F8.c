#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern s16 D_800970AA;
M2C_UNK func_8002D230(void*);

void func_800ED1F8(struct X4_MainObj* self) {
    if (self->unk7C != 0) {
        self->unk7C--;
        return;
    }
    if (self->x_speed > 0x1FFFF) {
        self->x_speed = 0x20000;
    }
    if (((self->x_pos.i.hi - D_800970AA) < 0
             ? (D_800970AA - self->x_pos.i.hi)
             : (self->x_pos.i.hi - D_800970AA)) < 0x30 ||
        self->x_pos.i.hi > 0xE90) {
        self->y_speed = 0x10000;
        self->gravity = -0x1000;
        self->x_speed = 0;
        self->x_accel = 0;
        self->unk7C = 0x32;
        self->unk6++;
        return;
    }
    func_8002D230(self);
}
