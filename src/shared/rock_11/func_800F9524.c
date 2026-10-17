#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800F6E4C(); /* extern */
void func_800FA4C8(struct X4_MainObj* self);

void func_800F9524(struct X4_MainObj* self) {
    if (!(self->unk7C & 0xF)) {
        ((void (*)())func_800FA4C8)();
    }
    if (--self->unk7C == 0) {
        self->unk7 = 0;
        func_800F6E4C(self);
    }
}
