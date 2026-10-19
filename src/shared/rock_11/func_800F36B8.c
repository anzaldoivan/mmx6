#include "common.h"

#include "mmx6/x4.h"

extern s8 D_800FD51B;

void func_800F36B8(struct X4_MainObj* self) {
    if (--self->unk7C == 0) {
        D_800FD51B = -1;
        self->unk6--;
    }
}
