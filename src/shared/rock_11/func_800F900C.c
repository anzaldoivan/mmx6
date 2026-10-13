#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
extern s8 D_800CCF5C;

void func_800F900C(struct X4_MainObj* self) {
    if (--self->unk7C == 0) {
        func_80016C48(2, 0x25, self);
        self->unk7C = 8;
        self->unk7E = D_800CCF5C / 3;
        self->unk6++;
    }
}
