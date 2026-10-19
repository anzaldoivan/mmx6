#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_8002D2B0(s32);
extern s16 D_80097206;

void func_800F9E94(struct X4_MainObj* self) {
    func_8002D2B0((s32)self);
    if ((self->y_pos.i.hi + 0x16) <= (D_80097206 - 0x20)) {
        self->unk5++;
    }
}
