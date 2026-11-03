// prog SLUS_013.95 | system player | range 0x8003D598-0x8003D62C
#include "common.h"
#include "mmx6/x4.h"

// 0x8003D598 set_base_move_stats: writes the base movement speeds and gravity into the player.
// basis: xref derived.tsv:126; xref:caller=init_move_stats
// callers: init_move_stats
// unnamed callers: func_8003C1AC
void set_base_move_stats(void* arg0) {
    struct X4_PlayerObj* self = arg0;
    s32 k0 = 0x20000;
    // !FAKE: register order of a shared constant
    register s32 k1 asm("$2") = 0x4200;
    s32 k2 = 0x5D000;
    // !FAKE: register order of a shared constant
    register s32 k3 asm("$8") = 0xFFF98000;
    // !FAKE: register order of a shared constant
    register s32 k4 asm("$9") = 0x68000;
    // !FAKE: register order of a shared constant
    register s32 k5 asm("$11") = 0x42000;
    // !FAKE: register order of a shared constant
    register s32 k6 asm("$10") = 0xFFFE9000;
    // !FAKE: register order of a shared constant
    register s32 k7 asm("$7") = 0x5A000;
    s32 k8 = 0x18000;

    self->walk_start_speed = 0x8000;
    self->walk_speed = k0;
    self->jump_gravity = k1;
    self->base_gravity = k1;
    self->unk10C = -0x3000;
    self->jump_speed = k2;
    self->unkFC = k3;
    self->dash_speed = k4;
    self->dash_base_speed = k5;
    self->slide_down_speed = k6;
    self->wall_jump_y_speed = k7;
    self->unk118 = 0x10000;
    self->unk11C = k8;
    self->unk120 = k0;
    self->unk124 = k0;
    self->unk128 = k8;
    self->unk12C = k5;
    self->unk130 = k5;
}
