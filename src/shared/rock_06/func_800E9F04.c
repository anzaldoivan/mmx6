// rolefeed (3.1 T4): func_800E9F04 of src/rock_06/E9860.c
// clang-format off

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"
#include "mmx6/globals.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32**)0x1F800020)

s32 func_8002A47C(s32);

extern u32* D_80095098;
extern s32 D_800F362C;
extern s32 D_800F3654[];
extern struct X4_Unk_unk68 D_800F365C;
extern struct X4_Unk_unk68 D_800F3660;

void func_800E9F04(struct X4_PlayerObj* self) {
    s32 t;

    if (self->character & 0x80) {
        self->action_timer = 1;
        self->unk16 = 0x22;
    } else {
        self->action_timer = 0;
        self->unk16 = 0x23;
    }
    self->action = 2;
    self->active = 0x41;
    self->action_phase = 0;
    self->character &= 0x7F;
    self->state++;
    self->bg_offset = D_800970B4;
    self->unk40 = D_80095098[func_8002A47C(0x8A)] >> 7;
    self->unk3C = (u8*)SPAD20 + SPAD20[func_8002A47C(0x8A)];
    self->unk42 = ((func_8002A47C(0x8A) * 4 + 0x20) % 16) |
                  (((func_8002A47C(0x8A) + 8) / 4 + 0x1E0) << 6);
    self->terrain_box = (struct X4_Unk_unk68*)((s8*)self + 0x80);
    if (self->character == 0) {
        M2C_FIELD(self, struct X4_Unk_unk68*, 0x80) = D_800F365C;
    } else {
        M2C_FIELD(self, struct X4_Unk_unk68*, 0x80) = D_800F3660;
    }
    t = (s32)&D_800F362C;
    self->animation_table = (u32**)t;
    t = 0x10;
    self->hp = t;
    M2C_FIELD(self, u8*, 0xA2) = 1;
    self->unk60 = 0x7F;
    self->unk75 = 1;
    self->unk58 = &D_800743DC;
    self->unk50 = 0;
    self->invincibility_timer = 0;
    self->unk76 = 0;
    self->facing = 0;
    self->unk65 = 0;
    self->unk54 = (const u32*)&D_800F3654[self->character];
    M2C_FIELD(self, u8*, 0x47) = self->character;
}
