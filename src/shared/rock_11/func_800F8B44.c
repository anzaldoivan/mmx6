#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_8002943C(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_8002D2B0(void*);
void func_800FA4C8(struct X4_MainObj* self);

void func_800F8B44(struct X4_MainObj* self) {
    func_800FA4C8(self);
    if (self->collision_flags & 8) {
        func_80016C48(2, 0x49, self);
        func_8002943C(8, 3, 1);
        func_800179A4(self, 4);
        {
            // !FAKE: the incremented byte lives in the first return register
            register s32 next asm("$2") = (u8)self->unk6 + 1;
            self->unk7 = 0;
            self->unk6 = next;
        }
        return;
    }
    func_8002D2B0(self);
}
