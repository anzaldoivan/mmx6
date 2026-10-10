#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD9C (*(s32**)0x1F80009C)

M2C_UNK func_800179A4(void*, M2C_UNK);
extern s32 D_800741FC[];
extern s32 D_8007519C;
extern u8 D_800970B4;
extern struct X4_BackgroundObj D_800971F8[3];
extern s16 D_80097222;
extern struct X4_EngineObj D_800CCED0;
extern s32 D_800F70B0;
extern s32 D_800F70B4;
extern s32 D_800F70B8;
extern s32 D_800F7478;
extern u32 D_800F7840;

#define ENG8F (((u8*)&D_800CCED0)[0x8F])

void func_800F14B0(struct X4_MainObj* self) {
    s8 type;
    s32* tbl;
    u8 b;

    if (D_800CCED0.stage == 0xC) {
        tbl = SPAD9C;
        self->sprite_frames = (const u8*)tbl + *tbl;
        self->unk42 = 0x7948;
    }
    self->contact_damage = 4;
    self->hp = 0;
    self->collision_data = &D_8007519C;
    self->invincibility_timer = 0;
    self->on_screen = 0;
    b = D_800970B4;
    type = self->unk2;
    self->x_speed = 0;
    self->y_speed = 0;
    self->x_accel = 0;
    self->gravity = 0;
    self->air_state = 0;
    self->animation_table = (void*)&D_800F7478;
    self->unk16 = 5;
    self->attack_box = 0;
    self->hurt_box = 0;
    self->terrain_box = 0;
    self->bg_offset = b;
    if (type == 0) {
        self->unk40 = 0x140;
        self->unk15 = 0;
        ((void (*)(void*, s32))func_800179A4)(self, 0);
        M2C_FIELD(self, u8*, 0x8B) = 0;
        M2C_FIELD(self, s8*, 0x8A) = -1;
        M2C_FIELD(self, u8*, 0x8C) = 0;
        D_800F7840 = 0;
        self->attack_box = &D_800F70B4;
        self->hurt_box = &D_800F70B8;
        self->terrain_box = (void*)&D_800F70B0;
        self->state = 1;
        self->unk5 = 2;
    } else if (type == 1) {
        self->unk16 = 6;
        self->on_screen = 0;
        self->unk7C = 0x14;
        self->state = 3;
        self->unk5 = 0;
        self->active |= 0x10;
    } else if ((type & 0xF0) == 0x10) {
        if (ENG8F < 2) {
            self->state = 5;
            self->unk5 = 0;
            return;
        }
        self->collision_data = D_800741FC;
        self->contact_damage = 6;
        self->hp = 2;
        switch (type) {
        case 0x10:
            ((void (*)(void*, s32))func_800179A4)(self, 0x1F);
            self->y_pos.i.hi = D_80097222 + 0xC0;
            break;
        case 0x11:
            ((void (*)(void*, s32))func_800179A4)(self, 0x20);
            if (D_800971F8[0].unk26 + 0xC0 >= self->x_pos.i.hi) {
                self->unk15 = 0;
                self->x_pos.i.hi = D_800971F8[0].unk26 + 0x20;
            } else {
                self->unk15 = 0x40;
                self->x_pos.i.hi = D_800971F8[0].unk26 + 0x160;
            }
            break;
        case 0x12:
            ((void (*)(void*, s32))func_800179A4)(self, 0x21);
            self->y_pos.i.hi = D_80097222 + 0x20;
            break;
        }
        self->unk16 = 4;
        self->state = 4;
        self->unk5 = 0;
    }
    self->unk6 = 0;
    self->unk7 = 0;
}
