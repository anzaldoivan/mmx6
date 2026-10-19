#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_8002D230(void*);
extern s16 D_800970AA;

void func_800ED370(struct X4_MainObj* self) {
    s32 d;
    s16 x;
    u16 xu;

    if (self->unk7C != 0) {
        self->unk7C--;
        return;
    }
    if (self->x_speed <= -0x20000) {
        self->x_speed = -0x20000;
    }
    x = self->x_pos.i.hi;
    xu = self->x_pos.u.hi;
    d = x - D_800970AA;
    if ((d < 0 ? D_800970AA - x : d) < 0x30 || (s16)xu < 0xCE0) {
        self->y_speed = 0x10000;
        self->gravity = -0x1000;
        self->x_speed = 0;
        self->x_accel = 0;
        self->unk7C = 0x32;
        self->unk6 = 2;
        return;
    }
    ((void (*)())func_8002D230)(self, x, xu);
}
