#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern struct X4_PlayerObj D_800970A0;

void func_800F7EE4(struct X4_MainObj* self) {
    func_80016C48(2, 0x20, self);
    {
        struct X4_PlayerObj* p = &D_800970A0;
        ((u8*)p)[0xCA] = 0;
        func_8003D308(0x14, p->unk15);
    }
    func_800179A4(self, 8);
    self->unk5 = 1;
    self->unk7C = 0x7F;
    self->unk7E = 0x19;
    self->invincibility_timer = 0x19;
    self->unk42 &= 0x7FFF;
    func_8002CCB0(self, 0x60, 0x60);
}
