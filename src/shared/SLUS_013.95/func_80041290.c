#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002CBFC(struct X4_AnimatedObj* arg0, s32 arg1, s32 arg2);
void func_8002CCB0(struct X4_BaseObj* arg0, s32 arg1, s32 arg2);
extern u8 D_800760C4[];
extern struct X4_PlayerObj g_Player;

void func_80041290(struct X4_MainObj* self) {
    s32 ang;

    self->contact_damage = 4;
    self->hp = 1;
    self->collision_data = 0;
    self->unk16 = 3;
    self->air_state = 1;
    set_animation(self, 5);
    self->terrain_box = 0;
    self->attack_box = D_800760C4;
    self->hurt_box = 0;
    self->state = 1;
    self->unk5 = 0;
    self->unk6 = 0;
    self->unk7 = 0;
    if (self->unk15 == 0) {
        self->x_pos.i.hi -= 4;
        self->y_pos.i.hi += 0xB;
    } else {
        self->x_pos.i.hi += 4;
        self->y_pos.i.hi += 0xB;
    }
    {
        s32 px = g_Player.x_pos.i.hi;
        s32 py = g_Player.y_pos.i.hi;
        ang = ratan2(self->y_pos.i.hi - py, px - self->x_pos.i.hi);
    }
    self->x_accel = 0;
    self->gravity = 0;
    self->x_speed = (rcos(ang) << 4) * 5;
    self->y_speed = (rsin(ang) << 4) * 5;
    if (func_8002CBFC(self, 0x20, 0x20) == 0) {
        func_8002CCB0(self, 0x10, 0x10);
        return;
    }
    self->state++;
}
