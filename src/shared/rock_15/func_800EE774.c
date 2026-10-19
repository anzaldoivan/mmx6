#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800179A4(void*, M2C_UNK);
s32 func_8002D2D4();
void func_800EF2E8(struct X4_MainObj* self);

void func_800EE774(struct X4_MainObj* self) {
    u32 r;

    func_800179A4(self, 2);
    func_800EF2E8(self);
    r = func_8002D2D4();
    self->unk6++;
    self->unk7C = (u8)(r % 3) + 1;
}
