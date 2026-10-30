#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);
s32 random_byte();
extern s32 D_80097420;
extern u8 D_800CCF38;
extern s32 D_800F7694;
extern s32 D_800F7698;

void func_800F2AD4(struct X4_MainObj* self) {
    s32 a;
    s32 b;
    s32 c;
    s32 q;

    set_animation(self, ((u32)(D_80097420 + self->unk2) % 3) + 0x1C);
    if (D_800CCF38 >= 2) {
        self->hurt_box = &D_800F7694;
        self->attack_box = &D_800F7698;
    }
    self->terrain_box = 0;
    a = ((u32)random_byte() % 40 & 0xFF) + 10;
    b = ((u32)random_byte() % 30 & 0xFF) + 30;
    c = ((u32)random_byte() % 10 & 0xFF) + 15;
    q = (b << 16) / ((c * c) >> 1);
    self->y_speed = q * c;
    self->gravity = q;
    self->x_accel = 0;
    switch (self->unk2) {
    case 16:
        self->x_speed = (-a << 16) / c;
        break;
    case 18:
        if (random_byte() & 1) {
            self->x_speed = (-a << 16) / c;
            break;
        }
    case 17:
        self->x_speed = (a << 16) / c;
        break;
    }
    self->unk6++;
}
