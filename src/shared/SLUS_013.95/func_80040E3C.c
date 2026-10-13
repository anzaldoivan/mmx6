#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_8002D2B0(void*);
M2C_UNK func_800429D4();
void func_80042D3C(void*);
s32 func_80042E68(void*);
s32 func_80065944(s32);
s32 func_80065A14(s32);
s32 func_80065B74(s32, s32);

#define F8(p, o) (*(u8*)((u8*)(p) + (o)))
#define PTR(p, o) (*(struct X4_MainObj**)((u8*)(p) + (o)))

void func_80040E3C(struct X4_MainObj* self) {
    struct X4_MainObj* tgt;
    s32 ang;
    s32 d;
    s32 y;
    s32 y2;
    s32 pad[2];

    F8(self, 0x8D) = 0;
    if (func_80042E68(PTR(self, 0x80)) == 0) {
        func_800429D4(self);
        return;
    }
    tgt = PTR(self, 0x80);
    F8(self, 0x8D) = 1;
    y = self->y_pos.i.hi + 0x1C;
    ang =
        func_80065B74(y - tgt->y_pos.i.hi, tgt->x_pos.i.hi - self->x_pos.i.hi);
    self->x_accel = 0;
    self->gravity = 0;
    self->x_speed = (func_80065A14(ang) << 4) >> 1;
    self->y_speed = (func_80065944(ang) << 4) >> 1;
    if (self->x_speed > 0) {
        self->unk15 = 0x40;
    } else {
        self->unk15 = 0;
    }
    func_8002D2B0(self);
    d = tgt->x_pos.i.hi - self->x_pos.i.hi;
    if (d >= 0 ? d < 2 : self->x_pos.i.hi - tgt->x_pos.i.hi < 2) {
        y2 = self->y_pos.i.hi + 0x1C;
        d = tgt->y_pos.i.hi - y2;
        if (d >= 0 ? d < 2 : y2 - tgt->y_pos.i.hi < 2) {
            func_800179A4(self, 2);
            func_80042D3C(self);
            tgt->unk7 = 2;
            self->hurt_box = 0;
            self->unk42 &= 0x7FFF;
            self->unk6++;
        }
    }
}
#undef F8
#undef PTR
