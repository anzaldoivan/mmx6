#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800179A4(void*, M2C_UNK);
void func_800F5488(struct X4_MainObj* self);

void func_800F3478(struct X4_MainObj* self) {
    func_800F5488(self);
    ((void (*)(void*, s32))func_800179A4)(self, 2);
    self->unk6++;
}
