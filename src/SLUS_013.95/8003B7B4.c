// prog SLUS_013.95 | system movement | range 0x8003B7B4-0x8003BB90
#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void player_clear_dash();

M2C_UNK player_enter_ladder_climb_up(void* arg0) {
    M2C_FIELD(arg0, s16*, 8) = 0;
    M2C_FIELD(arg0, s16*, 0xC) = 0;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, u16*, 0xA) = (M2C_FIELD(arg0, u16*, 0xA) & 0xFFF0) + 8;
    M2C_FIELD(arg0, s32*, 0x24) = M2C_FIELD(arg0, s32*, 0x11C);
    ((void (*)())player_clear_dash)(arg0);
    M2C_FIELD(arg0, u8*, 5) = 0xF;
    M2C_FIELD(arg0, u8*, 6) = 0;
}

#include "common.h"
#define M2C_UNK s32

void player_clear_dash();

// 0x8003B810 player_enter_ladder_climb_down: enters action 16: x snapped to the tile column centre, y speed minus +0x11C.
// basis: xref derived.tsv:162; xref:caller=update_ladder_climb_up
// callers: update_ladder_climb_up, player_ladder_climb_on_top, rock_00 player_ladder_shoot
M2C_UNK player_enter_ladder_climb_down(void* arg0) {
    u8* p = (u8*)arg0;

    *(s16*)(p + 0x8) = 0;
    *(s16*)(p + 0xC) = 0;
    *(s32*)(p + 0x20) = 0;
    *(s32*)(p + 0x28) = 0;
    *(s32*)(p + 0x2C) = 0;
    *(u16*)(p + 0xA) = (*(u16*)(p + 0xA) & 0xFFF0) + 8;
    *(s32*)(p + 0x24) = -*(s32*)(p + 0x11C);
    ((void (*)())player_clear_dash)(p);
    p[5] = 0x10;
    p[6] = 0;
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK play_bgm_xa_track(M2C_UNK, M2C_UNK);
void func_8003B954(struct X4_PlayerObj* self);
M2C_UNK player_set_animation(void*, M2C_UNK);
void func_8003CDF0();
M2C_UNK set_stand_animation_by_hp(void*);
void func_8003F000(void* arg0);
M2C_UNK refresh_weapon_state(void*);
extern struct X4_EngineObj g_playthrough_state;

void func_8003B870(struct X4_PlayerObj* self) {
    ((void (*)())func_8003CDF0)();
    ((void (*)(void*))refresh_weapon_state)(self);
    g_playthrough_state.gameplay_locked = 1;
    if (g_playthrough_state.unkF & 0x10) {
        set_stand_animation_by_hp(self);
        func_8003F000(self);
        if (self->character == 0) {
            play_bgm_xa_track(4, 0x7F);
        } else {
            play_bgm_xa_track(5, 0x7F);
            self->weapon = 0;
        }
        self->action = 0x19;
        self->action_phase = 0;
        return;
    }
    if (g_playthrough_state.unkF & 0x40) {
        self->state = 3;
        self->action = 0;
        self->action_phase = 0;
        return;
    }
    player_set_animation(self, 3);
    func_8003F000(self);
    if (self->character != 0) {
        self->weapon = 0;
    }
    func_8003B954(self);
}

/* Adapted from sozud/mmx4 @4e16dfc src/main/player_enter.c:player_enter_beam_out, AGPL-3.0; proven shared with X6 by exact signature f6ae817e5d19 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
s32 play_sound(s32, s32, void*);

void func_8003B954(struct X4_PlayerObj* self) {
    ((s32(*)())play_sound)(1, 0xB, self);
    self->x_vel.val = 0;
    self->x_accel = 0;
    self->y_vel.val = FIXED(8);
    self->gravity = 0;
    self->terrain_box = 0;
    self->air_state = 1;
    self->action = PLAYER_BEAM_OUT;
    self->action_phase = 0;
}

#include "common.h"
#define M2C_UNK s32

s32 func_8003A628(void*);
M2C_UNK player_set_animation(void*, M2C_UNK);

// 0x8003B9AC func_8003B9AC: enters action 26 unless the override check func_8003A628 takes over.
// basis: none
// callers: check_crouch_input, rock_00 func_801EC754
M2C_UNK func_8003B9AC(void* arg0) {
    s32 var_a1;

    if (func_8003A628(arg0) == 0) {
        var_a1 = 0x51;
        if (*(s32*)((u8*)arg0 + 0x8C) & 0xFFFF0000) {
            var_a1 = 0x6D;
        }
        ((void (*)(void*, s32))player_set_animation)(arg0, var_a1);
        *((u8*)arg0 + 5) = 0x1A;
        *((u8*)arg0 + 6) = 0;
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);
extern u8 D_801EF620[];
extern u8 D_801F49F4[];

#define SCRATCH_14 (*(u8**)0x1F800014)
#define SCRATCH_1C (*(u8**)0x1F80001C)
#define F_U8(p, o) (*(u8*)((u8*)(p) + (o)))

M2C_UNK player_set_animation(void* arg0, M2C_UNK arg1) {
    struct X4_AnimatedObj* self = arg0;
    u8 kind;

    if (self->unk2 == 0) {
        if (D_801F49F4[arg1] == 0) {
            self->unk38 = SCRATCH_14 + *(s32*)(SCRATCH_14 + 0x0);
            self->unk3C = SCRATCH_1C + *(s32*)(SCRATCH_1C + 0x0);
            F_U8(self, 0xDC) = 5;
        } else {
            self->unk38 = SCRATCH_14 + *(s32*)(SCRATCH_14 + 0x28);
            self->unk3C = SCRATCH_1C + *(s32*)(SCRATCH_1C + 0x48);
            F_U8(self, 0xDC) = 0x13;
        }
    } else {
        kind = D_801EF620[arg1];
        if (kind == 0) {
            self->unk38 = SCRATCH_14 + *(s32*)(SCRATCH_14 + 0x0);
            self->unk3C = SCRATCH_1C + *(s32*)(SCRATCH_1C + 0x0);
        } else if (kind == 1) {
            self->unk38 = SCRATCH_14 + *(s32*)(SCRATCH_14 + 0x4);
            self->unk3C = SCRATCH_1C + *(s32*)(SCRATCH_1C + 0x14);
        } else if (kind == 2) {
            self->unk38 = SCRATCH_14 + *(s32*)(SCRATCH_14 + 0x8);
            self->unk3C = SCRATCH_1C + *(s32*)(SCRATCH_1C + 0x1C);
        }
    }
    ((void (*)(void*, s32))set_animation)(self, arg1);
}
