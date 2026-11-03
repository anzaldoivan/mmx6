// prog SLUS_013.95 | system damage | range 0x80037920-0x80037A5C
#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32

void func_80037B10(void* arg0);    /* extern */
void check_low_health(void* arg0); /* extern */

// 0x80037920 func_80037920: hurt handler for hurt type 5: x motion through func_80037B10; when invincibility_timer reaches 0x3C runs func_8003AFF4, then check_low_health unless locked.
// basis: none
// callers: player_hurt
// dispatch: D_80073C30[5] in player_hurt (hurt_type)
void func_80037920(void* arg0) {
    struct X4_PlayerObj* self = arg0;
    func_80037B10(arg0);
    func_8003D394(arg0);
    if (self->action_phase == 0) {
        *(u8*)&self->action_phase += 1;
        return;
    }
    if (self->invincibility_timer == 0x3C) {
        ((void (*)(s32))func_8003AFF4)((s32)arg0);
        if (self->move_lock != 0) {
            self->hurt_phase = 0;
            self->invincibility_timer = 0;
            return;
        }
        check_low_health(arg0);
        self->hurt_phase = -1;
    }
}

#include "common.h"
#include "mmx6/x4.h"
#define M2C_UNK s32

void end_dash(s32 arg0);                      /* extern */
M2C_UNK player_set_animation(void*, M2C_UNK); /* extern */

// 0x800379AC func_800379AC: hurt handler for hurt type 3: faces the held direction; steps unkCA through animations 0x25 and 0x24, and runs end_dash when it reaches 0.
// basis: none
// callers: player_hurt
// dispatch: D_80073C30[3] in player_hurt (hurt_type)
void func_800379AC(void* arg0) {
    struct X4_PlayerObj* self = arg0;
    s8 v;
    s8 r;

    if (self->input.buttons.held & 2) {
        self->facing = 0;
    }
    if (self->input.buttons.held & 1) {
        self->facing = 0x40;
    }
    v = self->unkCA;
    if (v > 0) {
        return;
    }
    if (v == 0) {
        self->hurt_phase = 0;
        end_dash((s32)arg0);
    } else {
        if (v == -1) {
            player_set_animation(arg0, 0x25);
            r = -2;
        } else {
            if (self->animation_step.fields.relative_step >= 0) {
                return;
            }
            player_set_animation(arg0, 0x24);
            r = 1;
        }
        self->unkCA = r;
    }
}
