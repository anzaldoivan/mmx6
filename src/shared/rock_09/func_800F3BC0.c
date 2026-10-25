#include "common.h"
#include "mmx6/x4.h"

extern s32 g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)

void func_800F3BC0(struct X4_MainObj* self) {
    if (++self->unk7C == 0x3C) {
        if (g_Player.x_pos.i.hi > self->x_pos.i.hi) {
            self->unk15 = 0x40;
        } else {
            self->unk15 = 0;
        }
        self->x_speed =
            (g_Player.x_pos.i.hi > self->x_pos.i.hi) ? 0x40000 : -0x40000;
        self->unk6 = 0xF;
    }
}
#undef g_Player
