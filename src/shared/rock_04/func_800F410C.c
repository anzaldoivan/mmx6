#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800179A4(void*, M2C_UNK);
void func_800F5488(struct X4_MainObj* self);
extern s8 D_800970A2;

void func_800F410C(struct X4_MainObj* self) {
    func_800F5488(self);
    ((void (*)(void*, s32))func_800179A4)(self, D_800970A2 + 0xD);
    self->unk6++;
}
