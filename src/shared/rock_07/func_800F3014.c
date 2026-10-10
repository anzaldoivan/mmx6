#include "common.h"
#include "mmx6/x4.h"

void func_800F6948(struct X4_AnimatedObj* self, s32 arg1, s32 arg2);
extern s16 D_800970AA;
extern struct X4_BackgroundObj D_800971F8[3];

void func_800F3014(struct X4_AnimatedObj* self) {
    s16 x;
    u16 t = D_800970AA;

    self->x_pos.i.hi = t;
    self->y_pos.i.hi = D_800971F8[0].unk2A + 0x80;
    if ((s16)t > D_800971F8[0].unk26 + 0xB0) {
        self->unk15 = 0x40;
        self->x_pos.i.hi = t - 0x70;
    } else {
        self->unk15 = 0;
        self->x_pos.i.hi = t + 0x70;
    }
    x = self->x_pos.i.hi;
    if (x < D_800971F8[0].unk26 + 0x28) {
        self->x_pos.i.hi = D_800971F8[0].unk26 + 0x28;
    } else if (D_800971F8[0].unk26 + 0x138 < x) {
        self->x_pos.i.hi = D_800971F8[0].unk26 + 0x138;
    }
    if (self->y_pos.i.hi < D_800971F8[0].unk2A + 0x20) {
        self->y_pos.i.hi = D_800971F8[0].unk2A + 0x20;
    }
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
