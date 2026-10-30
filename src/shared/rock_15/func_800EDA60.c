#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);
s32 random_byte();
extern s32 D_800F6364;

void func_800EDA60(struct X4_MainObj* self) {
    s32 a;
    s32 b;
    s32 c;
    s32 q;

    set_animation(self, 0x12);
    self->on_screen = 1;
    self->terrain_box = (void*)&D_800F6364;
    a = ((u32)random_byte() % 40 & 0xFF) + 10;
    b = ((u32)random_byte() % 30 & 0xFF) + 30;
    c = ((u32)random_byte() % 10 & 0xFF) + 15;
    q = (b << 16) / ((c * c) >> 1);
    self->gravity = q;
    self->x_accel = 0;
    self->y_speed = q * c;
    switch (self->unk2 & 0xF) {
    case 0:
        self->x_speed = (-a << 16) / c;
        break;
    case 2:
        if (random_byte() & 1) {
            self->x_speed = (-a << 16) / c;
            break;
        }
    case 1:
        self->x_speed = (a << 16) / c;
        break;
    }
    self->unk6++;
}
