#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

void func_800FA4C8(struct X4_MainObj* self);

void func_800F89E8(struct X4_MainObj* self) {
    ((void (*)())func_800FA4C8)();
    self->unk7C = 0x1E;
    ((u8*)self)[0x8A] = 1;
    self->unk6++;
}
