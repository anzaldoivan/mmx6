#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32**)0x1F800020)

s32 set_animation(void*, s32);
s32 func_8002A47C(s32);
M2C_UNK clear_object_slot();
s32 random_byte();

extern M2C_UNK D_800743DC;
extern u32* D_80095098;
extern u8 D_800970B4;
extern s32 D_800F5A20;
extern s32 D_800F5A70;
extern s32 D_800F5A74;
extern s32 D_800F5A78;
extern s32 D_800F5A8C[];

void func_800ED9DC(struct X4_PlayerObj* self) {
    s32 a;
    s32 b;
    s8 kind;
    s32* tbl;

    if (!(random_byte() & 1)) {
        clear_object_slot(self);
        return;
    }
    if (self->unk2 == 0) {
        self->unk2 = (u32)random_byte() % 3;
    }
    self->unk5 = 2;
    self->active = 0x41;
    self->state++;
    self->bg_offset = D_800970B4;
    self->unk40 = D_80095098[func_8002A47C(0x85)] >> 7;
    self->unk3C = (u8*)SPAD20 + SPAD20[func_8002A47C(0x85)];
    a = func_8002A47C(0x85);
    b = func_8002A47C(0x85);
    self->unk42 = ((a * 4 + 0x20) % 16) | (((b + 8) / 4 + 0x1E0) << 6);
    tbl = D_800F5A8C;
    self->unk16 = 0x23;
    self->invincibility_timer = 0;
    self->unk68 = (struct X4_Unk_unk68*)tbl;
    self->unk58 = &D_800743DC;
    self->hp = 8;
    kind = self->unk2;
    self->animation_table = (u32**)&D_800F5A20;
    self->unk15 = 0;
    self->unk65 = 0;
    self->unk54 = 0;
    self->unk50 = 0;
    self->unk60 = 2;
    M2C_FIELD(self, u8*, 0x84) = 0;
    M2C_FIELD(self, u8*, 0x85) = 0;
    self->x_vel.val = 0;
    self->unk28 = 0;
    self->y_vel.val = 0;
    self->unk2C = 0;
    self->unk6 = 0;
    if (kind == 3 || kind == 6) {
        if (kind == 6) {
            self->unk16 = 0x22;
        }
        set_animation(self, 0xA);
        self->unk68 = (struct X4_Unk_unk68*)(tbl + 1);
        self->unk54 = (u32*)&D_800F5A70;
        self->unk50 = 0;
    } else if (kind == 4) {
        set_animation(self, 0xB);
        self->unk68 = (struct X4_Unk_unk68*)(tbl + 2);
        self->unk54 = (u32*)&D_800F5A74;
    } else {
        set_animation(self, 0xC);
        self->unk68 = (struct X4_Unk_unk68*)(tbl + 3);
        self->unk54 = (u32*)&D_800F5A78;
    }
    self->unk75 = 1;
    M2C_FIELD(self, u8*, 0xA2) = 1;
    self->invincibility_timer = 0;
    self->unk50 = 0;
    self->unk60 = 0x7F;
}
