#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
s32 func_800ED484(void*);
void func_800EF2E8(struct X4_MainObj* self);

void func_800EE538(struct X4_MainObj* self) {
    if (--self->unk7C == -1) {
        // !FAKE: keeps the second call's constant argument in the branch delay slot
        register s32 k asm("$5") = 0x22;
        self->unk7C = 0x32;
        if (--self->unk7E == 0) {
            ((void (*)())func_800ED484)();
            return;
        }
        func_80016C48(2, k, self);
        func_800179A4(self, 1);
        func_800EF2E8(self);
        if (self->unk15 != 0) {
            self->x_speed = 0x4000;
        } else {
            self->x_speed = -0x4000;
        }
        self->unk6--;
    }
}
