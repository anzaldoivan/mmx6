#include "common.h"
#include "mmx6/x4.h"

void func_800FA4C8(struct X4_MainObj* self);
extern s8 D_800CCF5C;

void func_800F90A0(struct X4_MainObj* self) {
    if (--self->unk7C == 0) {
        func_800FA4C8(self);
        self->unk7C = 8;
        if (self->unk7E != 0) {
            self->unk7E--;
            if (++self->hp >= D_800CCF5C) {
                self->hp = D_800CCF5C;
                self->unk6++;
            }
        } else {
            self->unk6++;
        }
    }
}
