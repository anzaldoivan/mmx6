#include "common.h"
#include "mmx6/x4.h"

extern struct X4_PlayerObj D_800970A0;

#define ABSDIFF(a, b) ((a) - (b) >= 0 ? (a) - (b) : (b) - (a))

void func_800EA4DC(struct X4_PlayerObj* self) {
    if (ABSDIFF(D_800970A0.x_pos.i.hi, self->x_pos.i.hi) < 0x61) {
        if (ABSDIFF(D_800970A0.y_pos.i.hi, self->y_pos.i.hi) < 0x61) {
            self->unk5 = 3;
            self->unk6 = 0;
        }
    }
}
