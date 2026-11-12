#include "common.h"
#include "mmx6/x4.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 check_dash_input(void*);     /* extern */
s32 try_enter_wall_cling(void*); /* extern */
M2C_UNK func_8003B298(void*);    /* extern */
s32 func_801EC35C();             /* extern */
s32 func_801EC3AC(void*);        /* extern */
void player_hover_set_direction(struct X4_PlayerObj* self,
                                s32 direction); /* extern */

void player_hover_idle(struct PlayerObj* arg0) {
    s32 temp_v0;

    if ((func_801EC35C() == 0) && (try_enter_wall_cling(arg0) == 0)) {
        if ((check_dash_input(arg0) != 0) && (arg0->shot_cooldown == 0)) {
            func_8003B298(arg0);
            return;
        }
        temp_v0 = func_801EC3AC(arg0);
        if (temp_v0 != 0) {
            arg0->is_clone = 0x28;
            player_hover_set_direction(arg0, temp_v0);
            return;
        }
        func_8003F508(arg0, 0x15);
    }
}

#include "common.h"

#define M2C_UNK s32

s32 try_enter_wall_cling(void*);       /* extern */
M2C_UNK func_8003F508(void*, M2C_UNK); /* extern */
s32 func_801EC35C();                   /* extern */
s32 func_801EC3AC(void*);              /* extern */
void player_hover_set_direction(struct X4_PlayerObj* self,
                                s32 direction); /* extern */

void player_hover_hold(s32 arg0) {
    s32 temp_v0;

    if ((func_801EC35C() == 0) && (try_enter_wall_cling(arg0) == 0)) {
        temp_v0 = func_801EC3AC(arg0);
        if (temp_v0 != 0) {
            player_hover_set_direction(arg0, temp_v0);
            return;
        }
        func_8003F508(arg0, 0x16);
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK move_by_velocity(void*);                       /* extern */
s32 try_enter_wall_cling(void*);                       /* extern */
M2C_UNK player_set_animation_shooting(void*, M2C_UNK); /* extern */
M2C_UNK func_8003F508(void*, M2C_UNK);                 /* extern */
s32 func_801EC35C();                                   /* extern */
s32 func_801EC3AC(void*);                              /* extern */

void player_hover_forward(void* arg0) {
    s32 temp_v0;
    s8 var_v0;

    if ((func_801EC35C() == 0) && (try_enter_wall_cling(arg0) == 0)) {
        temp_v0 = func_801EC3AC(arg0);
        if (temp_v0 != 0) {
            if (temp_v0 > 0) {
                move_by_velocity(arg0);
                func_8003F508(arg0, 0x17);
                return;
            }
            player_set_animation_shooting(arg0, 0x19);
            var_v0 = 5;
        } else {
            player_set_animation_shooting(arg0, 0x18);
            var_v0 = 4;
        }
        M2C_FIELD(arg0, s8*, 6) = var_v0;
    }
}

/* Adapted from sozud/mmx4 @4e16dfc src/main/player_special.c:player_hover_forward_stop, AGPL-3.0; proven shared with X6 by exact signature c351fcf586bf (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
s32 func_801EC35C();

s32 try_enter_wall_cling(void*);
#define M2C_UNK s32
M2C_UNK player_set_animation_shooting(void*, M2C_UNK);
s32 func_801EC3AC(void*);
void player_hover_set_direction(struct X4_PlayerObj* self, s32 direction);
void player_hover_forward_stop(struct X4_PlayerObj* self) {
    s32 action;

    if (func_801EC35C(self) == 0 && try_enter_wall_cling(self) == 0) {
        action = func_801EC3AC(self);
        if (action != PLAYER_BEAM_IN) {
            ((void (*)())player_hover_set_direction)(self, action);
            return;
        }
        if (self->animation_step.fields.relative_step == 0) {
            ((void (*)())player_set_animation_shooting)(self, 0x16);
            self->action_phase = 2;
            return;
        }
        func_8003F508(self, 0x18);
    }
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK move_by_velocity(void*);                       /* extern */
s32 try_enter_wall_cling(void*);                       /* extern */
M2C_UNK player_set_animation_shooting(void*, M2C_UNK); /* extern */
M2C_UNK func_8003F508(void*, M2C_UNK);                 /* extern */
s32 func_801EC35C();                                   /* extern */
s32 func_801EC3AC(void*);                              /* extern */

void player_hover_back(void* arg0) {
    s32 temp_v0;
    s8 var_v0;

    if ((func_801EC35C() == 0) && (try_enter_wall_cling(arg0) == 0)) {
        temp_v0 = func_801EC3AC(arg0);
        if (temp_v0 != 0) {
            if (temp_v0 > 0) {
                player_set_animation_shooting(arg0, 0x17);
                var_v0 = 3;
            } else {
                move_by_velocity(arg0);
                func_8003F508(arg0, 0x19);
                return;
            }
        } else {
            player_set_animation_shooting(arg0, 0x1A);
            var_v0 = 6;
        }
        M2C_FIELD(arg0, s8*, 6) = var_v0;
    }
}

/* Adapted from sozud/mmx4 @4e16dfc src/main/player_special.c:player_hover_back_stop, AGPL-3.0; proven shared with X6 by exact signature b28126054f46 (see THIRD_PARTY.md). */
#include "common.h"
#include "mmx6/x4.h"
s32 func_801EC35C(struct X4_PlayerObj*);

s32 try_enter_wall_cling(void*);
#define M2C_UNK s32
M2C_UNK player_set_animation_shooting(void*, M2C_UNK);
s32 func_801EC3AC(void*);
void player_hover_set_direction(struct X4_PlayerObj* self, s32 direction);
void player_hover_back_stop(struct X4_PlayerObj* self) {
    s32 action;

    if (func_801EC35C(self) == 0 && try_enter_wall_cling(self) == 0) {
        action = func_801EC3AC(self);
        if (action != PLAYER_BEAM_IN) {
            player_hover_set_direction(self, action);
            return;
        }
        if (self->animation_step.fields.relative_step == 0) {
            ((void (*)())player_set_animation_shooting)(self, 0x16);
            self->action_phase = 2;
            return;
        }
        func_8003F508(self, 0x1A);
    }
}
