#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_8002D230(void*);
extern struct X4_PlayerObj g_Player;

void func_800F4B14(struct X4_MainObj* self) {
    s32 d450;
    s32 d30;
    s32 grav;
    s32 n;

    func_800179A4(self, 0x1C);
    n = 0x500000;
    d450 = 450;
    d30 = 30;
    self->contact_damage = 4;
    self->y_pos.u.hi -= 0x20;
    grav = n / d450;
    self->y_speed = 0x5553C;
    self->gravity = grav;
    self->x_accel = 0;
    if (self->x_pos.i.hi >= g_Player.x_pos.i.hi) {
        self->unk15 = 0x40;
        self->x_speed = 0x200000 / d30;
    } else {
        self->unk15 = 0;
        self->x_speed = -0x200000 / d30;
    }
    ((void (*)(void*))func_8002D230)(self);
    self->unk6++;
}
