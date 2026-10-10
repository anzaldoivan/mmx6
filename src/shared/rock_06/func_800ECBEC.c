#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32**)0x1F800020)

s32 func_8002A47C(s32);
M2C_UNK func_8002C9B0();
s32 func_800ECAB8(struct X4_PlayerObj*, s16, s16);

extern s32 D_80075B9C;
extern s32 D_80075D7C;
extern u32* D_80095098;
extern u8 D_800970B4;
extern s32 D_800C1220[];
extern s8 D_800CD30A;
extern s32 D_800F39F4;
extern struct X4_Unk_unk68 D_800F3A14;
extern s32 D_800F3A18;

void func_800ECBEC(struct X4_PlayerObj* self) {
    s8 mode;
    s8 kind;

    mode = D_800CD30A;
    if (mode != 5) {
        func_8002C9B0();
        return;
    }
    self->state = 1;
    self->unk5 = 2;
    self->active = 0x41;
    self->unk6 = 2;
    self->unk15 = 0;
    self->bg_offset = D_800970B4;
    self->unk40 = D_80095098[func_8002A47C(0x93)] >> 7;
    self->unk3C = (u8*)SPAD20 + SPAD20[func_8002A47C(0x93)];
    self->unk42 = ((func_8002A47C(0x93) * 4 + 0x20) % 16) |
                  (((func_8002A47C(0x93) + 8) / 4 + 0x1E0) << 6);
    self->unk16 = 0x20;
    kind = self->unk2;
    self->unk58 = &D_80075B9C;
    if (kind == 3) {
        self->unk58 = &D_80075D7C;
        M2C_FIELD(self, u8*, 0x47) = 0;
    } else if (kind == 2) {
        self->unk58 = &D_80075D7C;
        M2C_FIELD(self, u8*, 0x47) = 4;
    } else if (kind == 1) {
        M2C_FIELD(self, u8*, 0x47) = mode;
    } else if (kind == 0) {
        M2C_FIELD(self, u8*, 0x47) = 6;
    }
    self->animation_table = (u32**)&D_800F39F4;
    self->hp = 8;
    self->unk68 = (struct X4_Unk_unk68*)((s8*)self + 0x80);
    M2C_FIELD(self, struct X4_Unk_unk68*, 0x80) = D_800F3A14;
    self->unk54 = (const u32*)&D_800F3A18;
    self->unk50 = 0;
    self->invincibility_timer = 0;
    self->unk75 = 1;
    self->unk60 = 0x10;
    self->unk65 = 0;
    M2C_FIELD(self, u8*, 0xA2) = 1;
    self->x_vel.val = 0;
    self->y_vel.val = 0;
    self->unk28 = 0;
    self->unk2C = 0;
    M2C_FIELD(self, u8*, 0x85) = 0;
    if (func_800ECAB8(self, self->x_pos.i.hi, self->y_pos.i.hi) != 0) {
        self->state = 2;
    }
    if (self->unk2 == 0x11) {
        {
            s32* d = D_800C1220;
            __builtin_memcpy(d + 0xCA7, self, 0xA4);
        }
        func_8002C9B0(self);
    }
}
