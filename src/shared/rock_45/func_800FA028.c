#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32**)0x1F800020)

void func_80025FD8();
s32 func_8002A47C(s32);
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern s32 D_80075A5C;
extern u8 D_800970B4;
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj D_800CCED0;
extern u8 D_800FA000[];
extern s32 D_800FCA88;
extern s32 D_800FCA94;
extern s32 D_800FCCD4;
extern u16 D_800FCE48;
extern u16 D_800FCE4A;
extern s16 D_800FCE4C;
extern s16 D_800FCE4E;
extern s16 D_800FCE50;
extern s16 D_800FCE52;
extern s16 D_800FCE54;
extern s32 D_800FCE58;
extern s32 D_800FCE5C;
extern void* D_800FCE60;

void func_800FA028(struct X4_MainObj* self) {
    u8 tbl[4][2];
    u16 yv;
    u16 xv;
    u8 bg;

    __builtin_memcpy(tbl, D_800FA000 + 4, 8);
    D_800FCE48 = background_objects[0].unk26 + 0x100;
    D_800FCE4A = background_objects[0].unk2A - 0x10;
    D_800FCE4C = background_objects[0].unk26 + 0x30;
    D_800FCE4E = background_objects[0].unk26 + 0x130;
    D_800FCE50 = background_objects[0].unk26 + 0xB0;
    D_800FCE52 = background_objects[0].unk2A + 0x10;
    D_800FCE54 = background_objects[0].unk2A + 0xB0;
    self->animation_table = (void*)&D_800FCCD4;
    self->unk40 = 0x140;
    self->unk42 = 0x7948;
    self->sprite_frames = (u8*)SPAD20 + SPAD20[func_8002A47C(self->id)];
    bg = D_800970B4;
    self->unk16 = 5;
    self->unk15 = 0;
    self->air_state = 0;
    self->on_screen = 0;
    self->terrain_box = 0;
    self->attack_box = &D_800FCA88;
    self->hurt_box = &D_800FCA94;
    self->unk62 = 0;
    self->invincibility_timer = 0;
    self->bg_offset = bg;
    self->collision_data = &D_80075A5C;
    xv = D_800FCE48;
    yv = D_800FCE4A;
    self->x_speed = 0;
    self->contact_damage = 4;
    self->y_speed = 0;
    self->x_accel = 0;
    self->gravity = 0;
    self->hp = 0;
    self->x_pos.i.hi = xv;
    self->y_pos.i.hi = yv;
    D_800CCED0.unk25 = 0;
    D_800CCED0.boss_ptr = self;
    M2C_FIELD(&D_800CCED0, u8*, 0x8C) = 0x3A;
    func_80025FD8(1);
    {
        // !FAKE: depin: dropping it breaks the match (126/133)
        register s32 i asm("$3") = M2C_FIELD(&D_800CCED0, u8*, 0x8F);
        M2C_FIELD(&D_800CCED0, u8*, 0x8C) += tbl[i][0];
    }
    M2C_FIELD(self, u8*, 0x88) = 0;
    func_8003D308(0x14, 0x40);
    M2C_FIELD(self, s32*, 0x90) = background_objects[0].unk48;
    background_objects[0].unk48 = 1;
    D_800FCE58 = 0;
    D_800FCE5C = 0;
    D_800FCE60 = self;
    self->unk5 = 2;
    self->state++;
}
