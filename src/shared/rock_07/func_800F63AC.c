#include "common.h"
#include "mmx6/x4.h"

extern struct X4_BackgroundObj D_800971F8[3];
void func_800F6948(struct X4_AnimatedObj* self, s32 arg1, s32 arg2);

void func_800F63AC(struct X4_AnimatedObj* self) {
    if (D_800971F8[0].unk26 + 0xB0 < self->x_pos.i.hi) {
        self->x_pos.i.hi = D_800971F8[0].unk26 + 0x40;
        self->unk15 = 0x40;
    } else {
        self->x_pos.i.hi = D_800971F8[0].unk26 + 0x120;
        self->unk15 = 0;
    }
    self->y_pos.i.hi = D_800971F8[0].unk2A + 0x40;
    func_800F6948(self, 0x20, 0xA00);
    func_800F6948(self, 0x20, 0);
    func_800F6948(self, 0x20, 0x600);
    func_800F6948(self, 0x20, 0xAC8);
    func_800F6948(self, 0x20, 0xC8);
    func_800F6948(self, 0x20, 0x6C8);
    func_800F6948(self, 0x20, 0xB90);
    func_800F6948(self, 0x20, 0x190);
    func_800F6948(self, 0x20, 0x790);
    self->unk6++;
}
