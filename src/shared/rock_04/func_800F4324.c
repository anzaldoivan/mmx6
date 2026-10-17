#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80012D9C(M2C_UNK);
M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_8002D2B0(void*);
void func_800F5488(struct X4_MainObj* self);

void func_800F4324(struct X4_MainObj* self) {
    ((void (*)(void*))func_8002D2B0)(self);
    if (*((u8*)self + 0x70) & 4) {
        func_80016C48(2, 0x12, self);
        func_80012D9C(8);
        func_800F5488(self);
        ((void (*)(void*, s32))func_800179A4)(self, 0x14);
        self->unk6++;
    }
}
