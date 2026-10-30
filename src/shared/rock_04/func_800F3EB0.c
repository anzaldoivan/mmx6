#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);
void func_800F5488(struct X4_MainObj* self);

void func_800F3EB0(struct X4_MainObj* self) {
    func_800F5488(self);
    ((void (*)(void*, s32))set_animation)(self, 0x12);
    self->unk6++;
}
