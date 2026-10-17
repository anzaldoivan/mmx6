#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern u8 D_800970B5;

void func_800F54E0(struct X4_MainObj* self) {
    self->unk7C = 0x7F;
    self->unk7E = 0x19;
    self->invincibility_timer = 0x19;
    self->unk42 &= 0x7FFF;
    func_800179A4(self, 7);
    func_80016C48(2, 0x20, self);
    self->unk5++;
    func_8003D308(0x14, D_800970B5);
    func_8002CCB0(self, 0x40, 0x40);
}
