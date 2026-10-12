#include "common.h"
#include "mmx6/x4.h"

void func_80041FB0(struct X4_MainObj* self) {
    self->unk7C--;
    if (self->unk7C == 0) {
        self->unk6++;
    }
}
