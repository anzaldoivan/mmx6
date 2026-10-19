#include "common.h"
#include "mmx6/x4.h"

void func_800F402C(void* arg0, s32 arg1); /* extern */
extern s16 D_800FD516;
extern s16 D_800FD518;
extern s8 D_800FD51A;
extern s8 D_800FD51B;

void func_800F3908(struct X4_MainObj* self) {
    s8 v;

    if (--self->unk7C == 0) {
        self->on_screen = 0;
        D_800FD51A = 0;
        D_800FD51B = 2;
        self->state = 3;
        return;
    }
    v = D_800FD51B;
    if (v == 1) {
        D_800FD516 = self->x_pos.u.hi;
        D_800FD518 = self->y_pos.u.hi;
        self->on_screen = v;
        D_800FD51A = v;
        func_800F402C(self, 4);
    }
}
