#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK func_80017A04();
M2C_UNK move_object();
s32 func_8002D354(void* arg0, s32 arg1, s32 arg2);
void set_velocity_from_angle(void*, s32);
extern struct X4_PlayerObj g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)

void func_800E9C7C(struct X4_MainObj* self) {
    struct X4_PlayerObj* pl;
    s32 v;
    s32 dx;

    func_80017A04();
    move_object(self);
    pl = &g_Player;
    set_velocity_from_angle(
        self,
        func_8002D354(self, pl->x_pos.val, pl->y_pos.val + 0xFFB00000) & 0xFF);
    v = self->x_speed + self->x_speed / 2;
    self->x_speed = v;
    v = (v < 0 ? -v : v) + 0x20000;
    dx = pl->x_pos.val - self->x_pos.val;
    if (dx < 0) {
        dx = self->x_pos.val - pl->x_pos.val;
    }
    if (v >= dx || --self->unk7C == 0) {
        self->unk5 = 3;
        self->unk6 = 0;
    }
}
#undef g_Player
