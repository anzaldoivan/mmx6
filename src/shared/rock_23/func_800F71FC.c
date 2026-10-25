#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
M2C_UNK func_80017A04();
M2C_UNK move_object(void*);

void func_800F71FC(struct X4_MainObj* self) {
    u8 t;
    s32 v;

    func_80017A04(self);
    t = ((u8*)self)[0x8E];
    if (t != 0) {
        ((u8*)self)[0x8E] = t - 1;
        return;
    }
    move_object((s32)self);
    v = self->unk15;
    if (v == 0) {
        v = self->collision_flags & 2;
    } else {
        v = self->collision_flags & 1;
    }
    if (v != 0) {
        self->x_speed = 0;
        self->y_speed = 0x30000;
        self->terrain_box = 0;
        self->unk6++;
    }
}
