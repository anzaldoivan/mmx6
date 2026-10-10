#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define SPAD (*(u8**)0x1F80004C)

M2C_UNK func_800179A4(void*, M2C_UNK);
void func_800EBABC(u8* arg0, u8 arg1);
extern M2C_UNK D_800743DC;
extern u8 D_800970B4;
extern s32 D_800F7180;
extern s32 D_800F7184;
extern s32 D_800F7234;

void func_800EB37C(struct X4_MainObj* self) {
    self->contact_damage = 4;
    self->unk7C = 0;
    self->hp = 8;
    self->invincibility_timer = 0;
    self->on_screen = 0;
    if (self->unk2 == 0) {
        SPAD[0x88] = 1;
        self->unk5 = 2;
        self->terrain_box = 0;
        self->hurt_box = &D_800F7184;
        self->attack_box = &D_800F7180;
    } else {
        SPAD[0x88] = 0;
        self->unk5 = 5;
        self->terrain_box = 0;
        self->hurt_box = 0;
        self->attack_box = 0;
    }
    {
        u8 g;
        s32 y;
        g = D_800970B4;
        self->unk15 = 0;
        self->animation_table = (void*)&D_800F7234;
        self->unk16 = 5;
        self->air_state = 0;
        self->collision_data = &D_800743DC;
        self->bg_offset = g;
        self->unk18.val = self->x_pos.val;
        y = self->y_pos.val;
        self->unk1C.val = y;
        func_800179A4(self, 0);
    }
    self->x_speed = 0;
    self->y_speed = 0;
    self->x_accel = 0;
    self->gravity = 0;
    self->state = 1;
    self->unk6 = 0;
    func_800EBABC(self, 0);
}
