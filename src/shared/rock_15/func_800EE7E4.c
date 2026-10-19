#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
s32 func_800ED484(void*);
void func_800EF0B0(void* arg0, s32 arg1);
void func_800EF2E8(struct X4_MainObj* self);

void func_800EE7E4(struct X4_MainObj* self) {
    switch (self->animation_step.fields.event) {
    case 1:
        func_80016C48(2, 0x85, self);
        func_800EF0B0(self, 0);
        break;
    case 2:
        if (--self->unk7C == 0) {
            func_800ED484(self);
            break;
        }
        func_800EF2E8(self);
        func_800179A4(self, 2);
        break;
    }
}
