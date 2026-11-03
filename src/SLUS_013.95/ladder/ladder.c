// prog SLUS_013.95 | system ladder | range 0x8003B63C-0x8003B6B0
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/movement.h"
#include "mmx6/weapon.h"

// 0x8003B63C grab_ladder: enters action 14: centres x on the tile, zeroes speeds, climb speed from unk118.
// basis: xref derived.tsv:112; xref:callee=try_enter_ladder
// callers: try_enter_ladder
void grab_ladder(void* arg0) {
    struct X4_PlayerObj* self = arg0;
    ((void (*)(void*, s32))player_set_animation)(arg0, 0x1B);
    self->air_state = 1;
    self->x_pos.i.lo = 0;
    self->y_pos.i.lo = 0;
    self->x_vel.val = 0;
    self->x_accel = 0;
    self->gravity = 0;
    {
        // !FAKE: pins the halfword read to the first return register as retail allocates it
        register s32 t asm("$2") = self->x_pos.u.hi;
        self->x_pos.u.hi = (t & 0xFFF0) + 8;
    }
    self->y_vel.val = self->unk118;
    ((void (*)())player_clear_dash)(arg0);
    ((void (*)())player_clear_attack)(arg0);
    self->action = 0xE;
    self->action_phase = 0;
}
