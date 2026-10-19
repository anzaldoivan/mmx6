#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32
M2C_UNK func_8002F288(M2C_UNK*);

s32 func_800F3FF8(struct X4_MainObj* self, s32 a1, s32 a2) {
    s16 arg1 = a1;
    s16 arg2 = a2;
    s32 x = self->x_pos.val;
    s32 y = self->y_pos.val;
    s32 sx = self->unk18.val;
    s32 sy = self->unk1C.val;
    u8 r;

    self->unk18.val = x;
    self->unk1C.val = y;
    self->x_pos.i.hi += arg1;
    self->y_pos.i.hi += arg2;
    func_8002F288((M2C_UNK*)self);
    r = self->collision_flags;
    self->x_pos.val = x;
    self->y_pos.val = y;
    self->unk18.val = sx;
    self->unk1C.val = sy;
    self->collision_flags = 0;
    return r;
}
