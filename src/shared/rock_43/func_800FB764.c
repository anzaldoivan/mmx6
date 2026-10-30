#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK play_sound(M2C_UNK, M2C_UNK, void*);
M2C_UNK set_animation(void*, M2C_UNK);
extern M2C_UNK D_8007433C;
extern struct X4_PlayerObj g_Player;
extern s32 D_800FDE30;

extern s32 D_800FE200;
extern s32 D_800FE204;
extern void* D_800FE298;

#define PARENT ((struct X4_MainObj*)D_800FE298)

void func_800FB764(struct X4_MainObj* self) {
    s32 x;
    s32 a;
    u16 y;
    u8 dir;
    // !FAKE: depin: dropping it breaks the match (113/128)
    register const u8* t asm("$6");
    struct X4_PlayerObj* pl;

    self->unk40 = PARENT->unk40;
    self->unk42 = PARENT->unk42 & 0x7FFF;
    self->animation_table = PARENT->animation_table;
    t = PARENT->sprite_frames;
    self->unk16 = 6;
    self->bg_offset = 0;
    self->sprite_frames = t;
    dir = PARENT->unk15;
    {
        // !FAKE: depin: dropping it breaks the match (115/128)
        register void* hb asm("$3") = &D_800FE204;
        self->attack_box = &D_800FE200;
        self->air_state = 0;
        self->on_screen = 0;
        self->terrain_box = 0;
        self->hurt_box = hb;
    }
    self->collision_data = &D_8007433C;
    self->unk15 = dir;
    if (dir == 0) {
        self->x_pos.i.hi = PARENT->x_pos.i.hi - 0x46;
    } else {
        self->x_pos.i.hi = PARENT->x_pos.i.hi + 0x46;
    }
    x = self->x_pos.i.hi;
    y = PARENT->y_pos.i.hi;
    self->y_pos.i.hi = y;
    pl = &g_Player;
    a = (pl->x_pos.i.hi >= x) << 6;
    if (self->unk15 == a) {
        x = pl->x_pos.i.hi - x;
    } else {
        x = x - pl->x_pos.i.hi;
    }
    a = (s16)ratan2(pl->y_pos.i.hi - (s16)y, x);
    if (a <= 0) {
        if (a >= -0x3FF) {
            if (a < -0x200) {
                a = -0x200;
            }
        } else if (a >= -0x5FF) {
            a = -0x600;
        }
    } else {
        if (a < 0x400) {
            a = 0;
        } else {
            a = -0x800;
        }
    }
    if (self->unk2 == 5) {
        a = (self->unk15 == 0) << 11;
    }
    self->x_speed = rcos(a) << 6;
    self->y_speed = -rsin(a) << 6;
    self->x_accel = 0;
    self->gravity = 0;
    self->hp = 1;
    self->contact_damage = 0x10;
    set_animation(self, 0xC);
    play_sound(2, 0x8F, self);
    M2C_FIELD(self, s32*, 0x8C) = 0;
    self->unk5 = 0;
    self->state++;
}

#undef PARENT
