#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_8002D230(void*);
void func_800F6E78(void*);

void func_800F4A18(struct X4_MainObj* self) {
    if (self->collision_flags & 8) {
        func_80016C48(2, 0x14, self);
        func_80016C48(2, 0x5C, self);
        func_800F6E78(self);
        func_800179A4(self, 2);
        {
            // !FAKE: increment temp register
            register s32 t asm("$2") = (u8)self->unk6 + 1;
            self->unk7C = 0x32;
            self->unk6 = t;
        }
        return;
    }
    func_8002D230(self);
}
