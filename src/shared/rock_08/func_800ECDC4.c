#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80017A04();
s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
void func_8002CCB0(struct X4_BaseObj*, s32, s32);
M2C_UNK func_8002D2B0(void*);
#define func_8002D2B0 ((void (*)(void*))func_8002D2B0)
M2C_UNK func_8002EE10(void*);
M2C_UNK func_80030ECC(void*);
s32 func_80031474(void*);
M2C_UNK func_80049D90(void*);
M2C_UNK func_80049E50(void*);

void func_800ECDC4(struct X4_PlayerObj* self) {
    func_80017A04();
    func_8002D2B0(self);
    self->unk42 &= 0x7FFF;

    if (func_80030ECC(self) != 0) {
        if (self->unk2 != 0) {
            func_80049E50(self);
        } else {
            func_80049D90(self);
        }
        self->state = 2;
        return;
    }
    if (self->unk2 != 0 && func_80031474(self) < 0) {
        func_80049E50(self);
        self->state = 2;
        return;
    }
    if (self->unk70 != 0 || (func_8002EE10(self), self->unk70 != 0)) {
        if (self->unk2 != 0) {
            func_80049E50(self);
        } else {
            func_80049D90(self);
        }
        self->state = 2;
        return;
    }
    if (func_8002CBFC(self, 0x20, 0x20) == 0) {
        func_8002CCB0((struct X4_BaseObj*)self, 0x10, 0x10);
        return;
    }
    self->state = 2;
}
#undef func_8002D2B0
