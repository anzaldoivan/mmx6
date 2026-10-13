#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_8002D230(void*);
extern s16 D_80097222;

void func_800ED040(struct X4_MainObj* self) {
    s32 v;

    if (self->unk7C != 0) {
        self->unk7C--;
        return;
    }
    if (self->y_speed > 0x2FFFF) {
        self->y_speed = 0x30000;
    }
    ((void (*)(void*))func_8002D230)(self);
    if (self->y_pos.i.hi < D_80097222 + 0x90) {
        v = self->gravity;
        if (v < 0) {
            self->gravity = -v;
        }
    }
    if (self->y_speed < 0) {
        self->y_speed = -0x10000;
        self->gravity = 0x1000;
        self->unk7C = 0x5A;
        self->unk6 = 4;
    }
}
