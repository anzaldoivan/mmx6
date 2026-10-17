#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
void func_800FA4C8(struct X4_MainObj* self);
extern struct X4_BackgroundObj D_800971F8[3];

void func_800F8A7C(struct X4_MainObj* self) {
    struct X4_BackgroundObj* bg;

    func_80016C48(2, 0x48, self);
    func_800179A4(self, 5);
    bg = &D_800971F8[0];
    self->x_pos.i.hi = bg->unk26 + 0xA8;
    self->y_pos.i.hi = bg->unk2A + 0x90;
    func_800FA4C8(self);
    self->unk6++;
}
