#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define SPAD (*(u8**)0x1F80004C)

s32 func_8002D2D4();
M2C_UNK func_8002F288(M2C_UNK*);
void func_8002F418(struct X4_PlayerObj* arg0);
extern M2C_UNK D_800743DC;
extern u8 D_800FC58C[];
extern s32 D_800FC62C[];
extern s32 D_800FC634[];
extern s32 D_800FC63C[];

void func_800F2410(struct X4_MainObj* self) {
    s32 i;

    self->state = 1;
    self->unk5 = 2;
    self->on_screen = 1;
    self->hp = 4;
    self->contact_damage = 3;
    self->unk6 = 0;
    self->unk7C = 0;
    self->invincibility_timer = 0;
    self->animation_table = (void*)D_800FC58C;
    self->unk18.val = self->x_pos.val;
    self->unk1C.val = self->y_pos.val;
    func_8002F288((M2C_UNK*)self);
    self->air_state = 0;
    self->x_speed = 0;
    self->y_speed = 0;
    self->x_accel = 0;
    self->gravity = 0;
    switch (self->unk2) {
    case 0:
        self->x_speed = 0x80000;
        self->unk15 = 0x40;
        break;
    case 1:
        self->x_speed = -0x80000;
        self->unk15 = 0;
        break;
    case 2:
        self->y_speed = 0x80000;
        break;
    }
    self->unk16 = 6;
    SPAD[0x80] = func_8002D2D4() & 1;
    SPAD[0x81] = self->unk2;
    self->hurt_box = (void*)D_800FC634[self->unk2 >> 1];
    self->attack_box = (void*)D_800FC63C[self->unk2 >> 1];
    self->terrain_box = (void*)D_800FC62C[self->unk2 >> 1];
    self->collision_data = &D_800743DC;
    func_8002F418((struct X4_PlayerObj*)self);
    if (self->collision_flags) {
        self->unk5 = 2;
    } else {
        self->unk5 = 5;
    }
}
