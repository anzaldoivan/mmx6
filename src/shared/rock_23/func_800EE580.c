#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_80017A04();
M2C_UNK func_8002D230();

extern s32 D_80097420;

void func_800EE580(struct X4_MainObj* self) {
    s32 v;
    s32 q;

    func_80017A04();
    func_8002D230(self);
    if (*(s16*)((u8*)self + 0x82) < self->x_pos.i.hi + 8 &&
        self->x_pos.i.hi - 8 < *(s16*)((u8*)self + 0x82)) {
        if (*(s16*)((u8*)self + 0x84) < self->y_pos.i.hi + 8 &&
            self->y_pos.i.hi - 8 < *(s16*)((u8*)self + 0x84)) {
            if (self->unk15 != 0) {
                v = -self->x_speed;
            } else {
                v = self->x_speed;
            }
            q = v >> 4;
            if (v < 0) {
                q = (v + 0xF) >> 4;
            }
            self->x_accel = q;
            self->gravity = self->y_speed / 16;
            *(s16*)((u8*)self + 0x80) = 0x10;
            self->unk7++;
        }
    }
    if (self->on_screen != 0 && !(D_80097420 & 0x1F)) {
        func_80016C48(2, 0xD, self);
    }
}
