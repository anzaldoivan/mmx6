// rolefeed (3.1 T4): func_800EF13C of src/rock_08/E9860.c

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32**)0x1F800020)

s32 set_animation(void*, s32);
s32 func_8002A47C(s32);
M2C_UNK clear_object_slot();
s32 random_byte();

extern u32* D_80095098;
extern s32 D_800F5CBC;
extern s32 D_800F5D28;

void func_800EF13C(struct X4_PlayerObj* self) {
    s32 a;
    s32 b;

    if (!(random_byte() & 1)) {
        clear_object_slot(self);
        return;
    }
    if (self->character == 0) {
        self->character = (u32)random_byte() % 3;
    }
    self->action = 2;
    self->active = 0x41;
    self->state++;
    self->bg_offset = D_800970B4;
    self->unk40 = D_80095098[func_8002A47C(0x85)] >> 7;
    self->unk3C = (u8*)SPAD20 + SPAD20[func_8002A47C(0x85)];
    a = func_8002A47C(0x85);
    b = func_8002A47C(0x85);
    self->unk42 = ((a * 4 + 0x20) % 16) | (((b + 8) / 4 + 0x1E0) << 6);
    self->unk16 = 0x21;
    self->terrain_box = (struct X4_Unk_unk68*)&D_800F5D28;
    self->invincibility_timer = 0;
    self->unk58 = &D_800743DC;
    self->hp = 8;
    self->facing = 0;
    self->unk65 = 0;
    self->unk54 = 0;
    self->unk50 = 0;
    self->unk60 = 2;
    self->animation_table = (u32**)&D_800F5CBC;
    M2C_FIELD(self, u8*, 0x88) = 0;
    M2C_FIELD(self, u8*, 0x89) = 0;
    self->x_vel.val = 0;
    self->x_accel = 0;
    self->y_vel.val = 0;
    self->gravity = 0;
    self->action_phase = 0;
    if (self->character == 0) {
        set_animation(self, 0);
    } else if (self->character == 1) {
        set_animation(self, 1);
    } else if (self->character == 2) {
        set_animation(self, 0);
    }
}
