#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_8002D2B0(s32);
extern s16 D_80097202;

void func_800FA1B4(struct X4_AnimatedObj* self) {
    func_8002D2B0(self);
    {
        // !FAKE: the flag byte is read into the first return register
        register s32 flag asm("$2") = self->unk15;
        if (flag == 0) {
            if (D_80097202 + 0x70 < self->x_pos.i.hi) {
                return;
            }
        } else if (self->x_pos.i.hi < D_80097202 + 0xD0) {
            return;
        }
    }
    self->unk6++;
}
