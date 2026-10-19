#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
extern u8 D_800F6DF8[];

void func_800F31C0(struct X4_MainObj* self) {
    s32 t;
    s32 v;

    if (--self->unk7C == 0) {
        if (self->unk7E != 0) {
            func_800179A4(self, 2);
            func_80016C48(2, 0x26, self);
            self->unk6 = 2;
            return;
        }
        M2C_FIELD(self, s8*, 0x8B) = 0;
        t = M2C_FIELD(self, u8*, 0x89) + 1;
        M2C_FIELD(self, u8*, 0x89) = t;
        v = D_800F6DF8[(s8)t + M2C_FIELD(self, s8*, 0x88) * 4];
        self->unk6 = 0;
        self->unk5 = v;
    }
}
