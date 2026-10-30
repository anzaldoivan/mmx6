#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);
s32 func_8002CBFC(s32, M2C_UNK, M2C_UNK);
M2C_UNK func_8002CCB0(void*, M2C_UNK, M2C_UNK);
extern s32 D_8007429C;
extern struct X4_PlayerObj g_Player;
extern s32 D_800F7154;
extern s32 D_800F7158;
extern s32 D_800F715C;

void func_800E9DCC(struct X4_MainObj* self) {
    s32 a;

    self->contact_damage = 4;
    self->hp = 1;
    self->collision_data = &D_8007429C;
    self->unk16 = 5;
    self->air_state = 1;
    set_animation(self, 0xA);
    {
        // !FAKE: depin: dropping it breaks the match (69/74)
        register void* r asm("$2") = &D_800F7154;
        // !FAKE: depin: dropping it breaks the match (65/74)
        register void* q asm("$3") = &D_800F7158;
        self->terrain_box = r;
        self->attack_box = q;
        self->state = 1;
        self->hurt_box = &D_800F715C;
    }
    self->unk5 = 0;
    self->unk6 = 0;
    self->unk7 = 0;
    {
        s32 px = g_Player.x_pos.i.hi;
        s32 py = g_Player.y_pos.i.hi;
        a = ratan2(self->y_pos.i.hi - py, px - self->x_pos.i.hi);
    }
    self->x_accel = 0;
    self->gravity = 0;
    {
        s32 t = rcos(a);
        s32 u = t << 4;
        self->x_speed = (t << 6) + u;
    }
    {
        s32 t = rsin(a);
        s32 u = t << 4;
        self->y_speed = (t << 6) + u;
    }
    if (func_8002CBFC(self, 0x20, 0x20) == 0) {
        func_8002CCB0(self, 0x10, 0x10);
        return;
    }
    self->state++;
}
