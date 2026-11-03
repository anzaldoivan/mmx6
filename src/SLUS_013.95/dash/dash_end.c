// prog SLUS_013.95 | system dash | range 0x80039FFC-0x8003A0E4
#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32

s32 apply_player_motion(void* arg);

// 0x80039FFC check_dash_end: dash step: moves, keeps x_vel at least dash_base_speed; returns 1 when the dash ends (wall ahead, dash_timer out, nothing held, other side held).
// basis: code via=dash_timer; derived.tsv:99
// callers: none known
s32 check_dash_end(void* arg0) {
    struct X4_PlayerObj* self = arg0;
    s32 mask;
    // !FAKE: the limit stays in the second return register across both arms
    register s32 lim asm("$3");
    s32 cond;
    s32 bits;
    s32 ret;

    mask = 2;
    if (self->facing != 0) {
        mask = 1;
    }
    if (self->latched_collision_flags & mask) {
        return 1;
    }
    apply_player_motion(arg0);
    if (self->facing != 0) {
        cond = self->x_vel.val;
        lim = self->dash_base_speed;
        cond = cond < lim;
    } else {
        lim = -self->dash_base_speed;
        cond = lim < self->x_vel.val;
    }
    if (cond) {
        self->x_vel.val = lim;
    }
    if (--self->dash_timer == 0) {
        return 1;
    }
    bits = self->input.buttons.held & 0x103;
    if (bits == 0) {
        return 1;
    }
    if (self->facing != 0) {
        if ((bits & 2) == 0) {
            // !FAKE: the flag-2 zero test branches to the shared return-0 tail
            goto zero;
        }
    one:
        return 1;
    }
    bits &= 1;
    if (bits != 0) {
        // !FAKE: the flag-1 test branches to the shared return-1 block
        goto one;
    }
zero:
    return 0;
}
