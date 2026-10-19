#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800179A4(void*, M2C_UNK);

void func_800F98A0(struct X4_MainObj* self) {
    ((void (*)(void*, M2C_UNK))func_800179A4)(self, 5);
    *((u8*)self + 0x8A) = 1;
    self->on_screen = 1;
    self->unk6++;
}
