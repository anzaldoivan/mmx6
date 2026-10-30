#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32

M2C_UNK clear_object_slot();
M2C_UNK func_80030ECC(void*);
extern void (*D_800F4458[])(struct X4_MainObj*);

void func_800F2E84(struct X4_MainObj* self) {
    s8* s0;

    s0 = *(s8**)&self->unk7C;
    self->unk42 &= 0x7FFF;
    ((void (*)())func_80030ECC)();
    D_800F4458[self->unk5](self);
    if (s0[4] == 2) {
        self->on_screen = 0;
        clear_object_slot(self);
    }
}
