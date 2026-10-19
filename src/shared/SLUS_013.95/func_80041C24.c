#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32

M2C_UNK func_800179A4(void*, M2C_UNK);
s32 func_8002D2D4();
void func_80042C18(struct X4_MainObj* self);

void func_80041C24(struct X4_MainObj* self) {
    s32 r;

    func_80042C18(self);
    func_800179A4(self, 1);
    r = func_8002D2D4();
    self->unk6++;
    self->unk7E = r % 7 + 6;
}
