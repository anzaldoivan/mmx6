#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800F0050(s32);               /* extern */
void func_800F3E10(void* arg0, s32 arg1); /* extern */
extern u8 D_800CCF38;

void func_800F2DEC(struct X4_MainObj* self) {
    if (D_800CCF38 < 2) {
        func_800F0050((s32)self);
        return;
    }
    self->unk7 = 6;
    func_800F3E10(self, 2);
    func_800F3E10(self, 0x10);
    func_800F3E10(self, 0x11);
    func_800F3E10(self, 0x12);
    func_800F3E10(self, 0x13);
    self->unk7C = 0x28;
    self->unk6++;
}
