#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800179A4(void*, M2C_UNK);
void func_800FA4C8(struct X4_MainObj* self);
void func_800FA4F8(void*, s16, s32);
extern struct X4_PlayerObj D_800970A0;

#define F8(p, o) (*(s8*)((u8*)(p) + (o)))

void func_800F64F0(struct X4_MainObj* self) {
    s32 a;
    s32 b;

    func_800FA4C8(self);
    if (--self->unk7C == -1) {
        self->unk6 += 2;
        return;
    }
    if (self->unk7E == 0) {
        a = self->y_pos.i.hi;
        b = D_800970A0.y_pos.i.hi;
        if (F8(self, 0x89) >= (a - b >= 0 ? a - b : b - a)) {
            ((void (*)(void*, s32))func_800179A4)(self, 2);
            self->unk6++;
            return;
        }
    } else {
        self->unk7E--;
    }
    func_800FA4F8(&self->y_pos, D_800970A0.y_pos.i.hi, 0x18000);
}
