// prog SLUS_013.95 | system movement | range 0x800382C8-0x80039068
#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/pilot_globals.h"
#include "mmx6/weapon.h"
#define M2C_UNK s32

// 0x800382C8 func_800382C8: ceiling_jump_phase_table[2] (action 31 phase 2): animates; at the animation end advances the phase and sets animation 0x54.
// basis: none
// callers: none known
void func_800382C8(void* arg0) {
    struct X4_PlayerObj* self = arg0;

    ((void (*)())animate_object)();
    if (self->animation_step.fields.relative_step == 0) {
        (*(u8*)&self->action_phase)++;
        player_set_animation(arg0, 0x54);
    }
}

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/movement.h"
#include "mmx6/pilot_globals.h"
#include "mmx6/sound.h"

#define M2C_UNK s32

// 0x80038310 func_80038310: ceiling_jump_phase_table[4] (action 31 phase 4): animation event 0x40 calls func_8003D26C; event 0x80 plays sound 1/5, sets afterimage, advances the phase.
// basis: none
// callers: none known
void func_80038310(void* arg0) {
    struct X4_PlayerObj* self = arg0;
    u8 temp_v1;

    ((M2C_UNK(*)())animate_object)();
    temp_v1 = *(u8*)&self->animation_step.fields.event;
    if (temp_v1 & 0x40) {
        self->animation_step.fields.event = (u8)(temp_v1 & 0x3F);
        func_8003D26C(arg0);
    }
    if ((s8) * (u8*)&self->animation_step.fields.event & 0x80) {
        self->animation_step.fields.event =
            (u8)(*(u8*)&self->animation_step.fields.event & 0x3F);
        play_sound(1, 5, arg0);
        self->afterimage = 1;
        self->action_phase = (u8)(1 + *(u8*)&self->action_phase);
    }
}

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/dash.h"
#include "mmx6/movement.h"
#include "mmx6/pilot_globals.h"

#define M2C_UNK s32

// 0x80038390 func_80038390: ceiling_jump_phase_table[5] (action 31 phase 5): when check_dash_end ends the dash, func_8003B30C and action 13; event 0x40 calls func_8003D26C.
// basis: none
// callers: none known
void func_80038390(void* arg0) {
    struct X4_PlayerObj* self = arg0;
    u8 v;

    ((M2C_UNK(*)())animate_object)();
    if (check_dash_end(arg0) != 0) {
        ((void (*)(void*))func_8003B30C)(arg0);
        self->action = 0xD;
        return;
    }
    v = *(u8*)&self->animation_step.fields.event;
    if (v & 0x40) {
        self->animation_step.fields.event = v & 0x3F;
        func_8003D26C(arg0);
    }
}

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"
#include "addr.h" /* g_sp_sprite_frames */
#include "mmx6/effect.h"
#include "mmx6/sound.h"

// 0x800383F8 func_800383F8: spawns a visual object (find_free_visual_obj) at the caller, mirrored, with g_visual_animation_tables animations; the sound and variant follow the caller id.
// basis: none
// callers: none known
void func_800383F8(void* arg0) {
    struct X4_MainObj* self = arg0;
    struct X4_VisualObj* obj;
    s32* tbl;
    struct X4_Unk_unk68* p;
    s32 off;

    if (self->id == 0x3A) {
        play_sound(1, 9, self);
    } else if ((u8)(self->id - 0x38) >= 2) {
        play_sound(1, 0xC, self);
    }
    obj = find_free_visual_obj();
    if (obj != 0) {
        obj->active = 0x21;
        obj->id = 3;
        if (self->id == 0x12 || self->id == 0x14 || self->id == 0x2E) {
            obj->unk2 = 4;
        } else {
            obj->unk2 = 3;
        }
        obj->bg_offset = self->bg_offset;
        tbl = g_sp_sprite_frames;
        off = tbl[1];
        obj->animation_table = g_visual_animation_tables;
        obj->unk40 = 0;
        obj->unk42 = 0x7802;
        obj->unk16 = 0;
        obj->unk3C = (s8*)tbl + off;
        obj->x_pos.i.hi = self->x_pos.i.hi;
        obj->y_pos.i.hi = self->y_pos.i.hi;
        obj->unk15 = self->unk15 ^ 0x40;
        if ((u8)(self->id - 0x38) < 2) {
            obj->unk2 = 0xC;
        }
        if (self->id == 0x3A) {
            obj->unk2 = 0xC;
            p = self->terrain_box;
            if (p != 0) {
                if (self->unk15 != 0) {
                    obj->x_pos.i.hi -= p->unk0;
                } else {
                    obj->x_pos.i.hi += p->unk0;
                }
            }
        }
    }
}

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/collision.h"
#include "mmx6/movement.h"
#include "mmx6/sound.h"
#define M2C_UNK s32

#define TURN(s)                                                                \
    {                                                                          \
        u16 f;                                                                 \
        s32 r;                                                                 \
        silence_sound(1, 5);                                                   \
        player_clear_dash(arg0);                                               \
        f = self->input.buttons.held;                                          \
        s = 0;                                                                 \
        if (f & 3) {                                                           \
            if (f & 2) {                                                       \
                s = 1;                                                         \
                self->x_vel.val = -self->unk124;                               \
            } else {                                                           \
                s = 2;                                                         \
                self->x_vel.val = self->unk124;                                \
            }                                                                  \
            move_by_velocity(arg0);                                            \
            r = (u8)(get_tile_attr_above(arg0) - 0x25) >= 0xB;                 \
            self->x_pos.val = self->unk18.val;                                 \
            if (r) {                                                           \
                s = 0;                                                         \
            } else {                                                           \
                move_by_velocity(arg0);                                        \
            }                                                                  \
        }                                                                      \
    }

// 0x80038594 func_80038594: horizontal step under overhead tiles 0x25-0x2F, at unk12C while dash_timer runs and the facing side is held, else by L/R at unk124; returns 0, 1 left, 2 right.
// basis: none
// callers: none known
s32 func_80038594(void* arg0) {
    struct X4_PlayerObj* self = arg0;
    s32 c;
    // !FAKE: depin: dropping it breaks the match (120/125)
    register s32 m asm("$4");
    s32 s;
    s32 w;
    s32 r;
    u16 f;
    s32 t;

    t = --self->dash_timer;
    if (t == 0) {
        c = 1;
    } else {
        f = self->input.buttons.held;
        if (!(f & 0x103)) {
            c = 1;
        } else {
            m = 1;
            if (self->facing != 0) {
                m = 2;
            }
            c = (f & m) != 0;
        }
    }
    if (c) {
        TURN(s);
        return s;
    }
    w = 2;
    if (self->facing == 0) {
        w = 1;
        self->x_vel.val = -self->unk12C;
    } else {
        self->x_vel.val = self->unk12C;
    }
    move_by_velocity(arg0);
    r = (u8)(get_tile_attr_above(arg0) - 0x25) >= 0xB;
    self->x_pos.val = self->unk18.val;
    if (r) {
        w = 0;
    } else {
        move_by_velocity(arg0);
    }
    if (w == 0) {
        TURN(s);
        return s;
    }
    return w;
}

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/collision.h"
#include "mmx6/movement.h"
#include "mmx6/sound.h"

#define M2C_UNK s32

static inline s32 func_80038788_turn(void* arg0) {
    struct X4_PlayerObj* self = arg0;
    s32 res;
    s32 bad;
    u16 flags;

    silence_sound(1, 5);
    player_clear_dash(arg0);
    flags = self->input.buttons.held;
    res = 0;
    if (flags & 0xC) {
        res = 1;
        if (flags & 4) {
            self->y_vel.val = self->unk128;
        } else {
            res = 2;
            self->y_vel.val = -self->unk128;
        }
        move_by_velocity(arg0);
        bad = get_tile_attr_above(arg0) != 0x2E;
        if (self->y_vel.val < 0 && (self->latched_collision_flags & 8)) {
            bad = 1;
        }
        self->y_pos.val = self->unk1C.val;
        if (bad) {
            res = 0;
        } else {
            move_by_velocity(arg0);
        }
    }
    return res;
}

// 0x80038788 func_80038788: vertical step under overhead tile 0x2E, at y_vel while dash_timer runs and its side is held, else by UP/DOWN at unk128; returns 0, 1 up, 2 down.
// basis: none
// callers: none known
s32 func_80038788(void* arg0) {
    struct X4_PlayerObj* self = arg0;
    s32 res;
    s32 go;
    s32 mask;
    s32 bad;

    if (--self->dash_timer != 0) {
        mask = 4;
        if (self->y_vel.val < 0) {
            mask = 8;
        }
        go = (self->input.buttons.held & mask) == 0;
    } else {
        go = 1;
    }
    if (go) {
        return func_80038788_turn(arg0);
    }
    res = 2;
    if (self->y_vel.val > 0) {
        res = 1;
    }
    move_by_velocity(arg0);
    bad = get_tile_attr_above(arg0) != 0x2E;
    if (self->y_vel.val < 0 && (self->latched_collision_flags & 8)) {
        bad = 1;
    }
    self->y_pos.val = self->unk1C.val;
    if (bad) {
        res = 0;
    } else {
        move_by_velocity(arg0);
    }
    if (res == 0) {
        res = func_80038788_turn(arg0);
        return res;
    }
    return res;
}

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/collision.h"
#include "mmx6/graphics.h"
#include "mmx6/movement.h"
#include "mmx6/pilot_globals.h"
#include "mmx6/weapon.h"

#define M2C_UNK s32

// 0x800389B4 func_800389B4: action 27 move step (from func_8003605C): UP/DOWN under tile 0x2E (func_80038788 while dashing), then animation by direction, shot and attack.
// basis: none
// callers: none known
void func_800389B4(void* arg0) {
    struct X4_PlayerObj* self = arg0;
    s32 var_a2;
    s32 var_s1;
    s32 var_a0;
    s32 var_a1;
    s32 var_v1;
    // !FAKE: depin: dropping it breaks the match (68/125)
    register s32 var_v0 asm("$2");
    u16 temp_v1;

    if (self->dash_momentum != 0) {
        var_a2 = func_80038788(arg0);
    } else {
        temp_v1 = self->input.buttons.held;
        var_s1 = 0;
        if (temp_v1 & 0xC) {
            var_s1 = 1;
            if (temp_v1 & 4) {
                self->y_vel.val = self->unk128;
            } else {
                var_s1 = 2;
                self->y_vel.val = -self->unk128;
            }
            move_by_velocity(arg0);
            var_a0 = get_tile_attr_above(arg0) != 0x2E;
            if (self->y_vel.val < 0 && (self->latched_collision_flags & 8)) {
                var_a0 = 1;
            }
            self->y_pos.val = self->unk1C.val;
            if (var_a0 != 0) {
                var_s1 = 0;
            } else {
                move_by_velocity(arg0);
            }
        }
        var_a2 = var_s1;
    }
    if (self->character == 0) {
        if (self->shot_fired != 0) {
            player_set_animation(arg0, var_a2 + 0x91);
            return;
        }
        if (self->attacking != 0) {
            var_v0 = var_a2 - 0x6F;
            var_a1 = var_v0 & 0xFF;
            var_v1 = self->unk17;
        } else {
            var_v0 = self->unk17;
            var_a1 = 0x91;
            var_v1 = var_v0;
            if (var_v0 != var_a1) {
                var_v0 = var_a2 - 0x60;
                var_a1 = var_v0 & 0xFF;
            }
        }
    } else {
        var_v0 = var_a2 - 0x60;
        var_a1 = var_v0 & 0xFF;
        var_v1 = self->unk17;
    }
    if (var_a1 != var_v1) {
        if (var_a1 == 0xA0) {
            if (self->character == 0) {
                player_set_animation_frame(arg0, 0xA0, 2);
            } else {
                player_set_animation_frame(arg0, 0xA0, 3);
            }
        } else {
            player_set_animation(arg0, var_a1);
        }
    } else {
        animate_object(arg0);
    }
    if ((self->animation_step.fields.relative_step == 0) &&
        (self->attacking == 0)) {
        if (self->character == 0) {
            player_set_animation_frame(arg0, 0xA0, 2);
        } else {
            player_set_animation_frame(arg0, 0xA0, 3);
        }
    }
}

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/collision.h"
#include "mmx6/sound.h"

#define M2C_UNK s32

// 0x80038BA8 func_80038BA8: on dash press or double tap, starts a vertical dash under tile 0x2E: dash_momentum, air_action 1, dash_timer 30 (15 with part 0x10), sound; returns 1.
// basis: none
// callers: none known
s32 func_80038BA8(void* arg0) {
    struct X4_PlayerObj* self = arg0;
    s32 var_a0;

    if (self->move_lock != 0) {
        return 0;
    }
    if (self->dash_momentum != 0) {
        return 0;
    }
    if (self->double_tap_dash == 0 && !(self->pressed_input & 0x100)) {
        return 0;
    }
    if (self->input.buttons.held & 4) {
        self->y_vel.val = self->unk130;
    } else {
        self->y_vel.val = -self->unk130;
    }
    move_by_velocity(arg0);
    var_a0 = get_tile_attr_above(arg0) != 0x2E;
    if (self->y_vel.val < 0 && (self->latched_collision_flags & 8)) {
        var_a0 = 1;
    }
    self->y_pos.val = self->unk1C.val;
    if (var_a0 != 0) {
        return 0;
    }
    self->dash_momentum = 1;
    self->air_action = 1;
    if (self->equipped_parts & 0x10) {
        self->dash_timer = 0xF;
    } else {
        self->dash_timer = 0x1E;
    }
    self->afterimage = 1;
    play_sound(1, 5, arg0);
    return 1;
}

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/collision.h"
#include "mmx6/graphics.h"
#include "mmx6/movement.h"
#include "mmx6/pilot_globals.h"
#include "mmx6/weapon.h"

#define M2C_UNK s32

// 0x80038CD0 func_80038CD0: action 28 move step (from func_800361D4): L/R under tiles 0x25-0x2F (func_80038594 while dashing), y snap by snap_to_tile_slope, animation by tile.
// basis: none
// callers: none known
void func_80038CD0(void* arg0) {
    struct X4_PlayerObj* self = arg0;
    s32 var_s2;
    // !FAKE: depin: dropping it breaks the match (110/165)
    register s32 var_s0 asm("$16");
    s32 temp_s3;
    s32 temp_v0;
    u16 temp_v1;

    if (self->dash_momentum != 0) {
        var_s2 = func_80038594(arg0);
    } else {
        temp_v1 = self->input.buttons.held;
        var_s0 = 0;
        if (temp_v1 & 3) {
            var_s0 = 1;
            if (temp_v1 & 2) {
                self->x_vel.val = -self->unk124;
            } else {
                var_s0 = 2;
                self->x_vel.val = self->unk124;
            }
            move_by_velocity(arg0);
            temp_v0 = (u8)(get_tile_attr_above(arg0) - 0x25) >= 0xB;
            self->x_pos.val = self->unk18.val;
            if (temp_v0) {
                var_s0 = 0;
            } else {
                move_by_velocity(arg0);
            }
        }
        var_s2 = var_s0;
    }
    if (var_s2 != 0) {
        snap_to_tile_slope(arg0, get_tile_attr_above(arg0));
    }
    temp_s3 = get_tile_attr_above(arg0);
    if (self->character == 0) {
        if (self->shot_fired != 0) {
            player_set_animation(arg0, func_8003A814(arg0, temp_s3) + 0x97);
            return;
        }
        if (self->attacking != 0) {
            var_s0 = 0x97;
            if (var_s2 != 0) {
                var_s0 = 0x9A;
            }
            var_s0 = (var_s0 + func_8003A814(arg0, temp_s3)) & 0xFF;
        } else if (var_s2 != 0) {
            var_s0 = (func_8003A814(arg0, temp_s3) - 0x5A) & 0xFF;
        } else {
            var_s0 = (func_8003A814(arg0, temp_s3) - 0x69) & 0xFF;
            if (self->unk17 != var_s0) {
                var_s0 = (func_8003A814(arg0, temp_s3) - 0x5D) & 0xFF;
            }
        }
    } else if (var_s2 != 0) {
        var_s0 = (func_8003A814(arg0, temp_s3) - 0x5A) & 0xFF;
    } else {
        var_s0 = (func_8003A814(arg0, temp_s3) - 0x5D) & 0xFF;
    }
    if (var_s0 != self->unk17) {
        if ((u8)(var_s0 + 0x5D) < 3U) {
            if (self->character == 0) {
                player_set_animation_frame(arg0, var_s0, 2);
            } else {
                player_set_animation_frame(arg0, var_s0, 3);
            }
        } else {
            player_set_animation(arg0, var_s0);
        }
    } else {
        animate_object(arg0);
    }
    if ((self->animation_step.fields.relative_step == 0) &&
        (self->attacking == 0)) {
        var_s0 = (func_8003A814(arg0, temp_s3) - 0x5D) & 0xFF;
        if (self->character == 0) {
            player_set_animation_frame(arg0, var_s0, 2);
        } else {
            player_set_animation_frame(arg0, var_s0, 3);
        }
    }
}

#include "common.h"
#include "mmx6/x4.h"
#include "mmx6/collision.h"
#include "mmx6/sound.h"

#define M2C_UNK s32

// 0x80038F64 func_80038F64: on dash press or double tap, starts a horizontal dash under tiles 0x25-0x2F, set up as in func_80038BA8; returns 1 when started.
// basis: none
// callers: none known
s32 func_80038F64(void* arg0) {
    struct X4_PlayerObj* self = arg0;
    s32 temp_v0;

    if (self->move_lock != 0) {
        return 0;
    }
    if (self->dash_momentum != 0) {
        return 0;
    }
    if (self->double_tap_dash == 0 && !(self->pressed_input & 0x100)) {
        return 0;
    }
    if (self->facing != 0) {
        self->x_vel.val = self->unk12C;
    } else {
        self->x_vel.val = -self->unk12C;
    }
    move_by_velocity(arg0);
    temp_v0 = (u8)(get_tile_attr_above(arg0) - 0x25) >= 0xB;
    self->x_pos.val = self->unk18.val;
    if (temp_v0) {
        return 0;
    }
    self->dash_momentum = 1;
    self->air_action = 1;
    if (self->equipped_parts & 0x10) {
        self->dash_timer = 0xF;
    } else {
        self->dash_timer = 0x1E;
    }
    self->afterimage = 1;
    play_sound(1, 5, arg0);
    return 1;
}
