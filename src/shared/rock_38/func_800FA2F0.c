#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD9C (*(s32**)0x1F80009C)

void set_boss_level();
void* func_8002C458();
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern s32 D_800755FC;
extern u8 D_800970B4;
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj g_playthrough_state;
extern u8 D_800FA004[];
extern s32 D_800FE830;
extern s32 D_800FE838;
extern s32 D_800FEBAC;
extern s16 D_800FEEB0;
extern s16 D_800FEEB2;
extern s16 D_800FEEB4;
extern s16 D_800FEEB6;
extern u16 D_800FEEB8;
extern u16 D_800FEEBA;
extern s16 D_800FEEBC;
extern s16 D_800FEEBE;
extern s16 D_800FEEC0;
extern s32 D_800FEEC4;
extern s32 D_800FEEC8;
extern s16 D_800FEED0;
extern void* D_800FEED4;
extern s32 D_800FEED8;

void func_800FA2F0(struct X4_MainObj* self) {
    u8 tbl[4];
    u8* child;
    u16 yv;
    u16 xv;
    u8 bg;

    __builtin_memcpy(tbl, D_800FA004, 4);
    D_800FEEB0 = background_objects[0].unk26 + 0x10;
    D_800FEEB2 = background_objects[0].unk26 + 0x190;
    D_800FEEB4 = background_objects[0].unk26 + 0xD0;
    D_800FEEB6 = background_objects[0].unk2A + 0xF0;
    D_800FEEB8 = background_objects[0].unk26 + 0xF0;
    D_800FEEBA = background_objects[0].unk2A - 0x30;
    D_800FEEBC = background_objects[0].unk2A + 0x10;
    D_800FEEBE = background_objects[0].unk26 + 0x150;
    D_800FEEC0 = background_objects[0].unk26 + 0x50;
    if (g_playthrough_state.stage == 0xC) {
        self->sprite_frames = (u8*)SPAD9C + SPAD9C[0];
        self->unk42 = 0x7948;
    }
    self->animation_table = (void*)&D_800FEBAC;
    bg = D_800970B4;
    self->terrain_box = 0;
    self->unk16 = 5;
    self->unk15 = 0;
    self->air_state = 0;
    self->on_screen = 0;
    self->attack_box = &D_800FE830;
    self->hurt_box = &D_800FE838;
    self->unk62 = 0;
    self->invincibility_timer = 0;
    self->bg_offset = bg;
    self->collision_data = &D_800755FC;
    xv = D_800FEEB8;
    yv = D_800FEEBA;
    self->x_speed = 0;
    self->contact_damage = 6;
    self->y_speed = 0;
    self->x_accel = 0;
    self->gravity = 0;
    self->hp = 0;
    self->x_pos.i.hi = xv;
    self->y_pos.i.hi = yv;
    g_playthrough_state.unk25 = 0;
    g_playthrough_state.boss_ptr = self;
    M2C_FIELD(&g_playthrough_state, u8*, 0x8C) = 0x38;
    set_boss_level();
    {
        // !FAKE: depin: dropping it breaks the match (149/151)
        register s32 e asm("$2") = M2C_FIELD(&g_playthrough_state, u8*, 0x8C);
        M2C_FIELD(&g_playthrough_state, u8*, 0x8C) =
            e + tbl[M2C_FIELD(&g_playthrough_state, u8*, 0x8F)];
    }
    M2C_FIELD(self, u8*, 0x87) = 0;
    M2C_FIELD(self, u8*, 0x86) = 0;
    M2C_FIELD(self, u8*, 0x84) = 0;
    D_800FEED8 = 0;
    func_8003D308(0x14, 0x40);
    D_800FEEC4 = 0;
    D_800FEEC8 = 0;
    D_800FEED4 = self;
    child = func_8002C458();
    if (child != 0) {
        child[0] = self->active;
        child[1] = 0x17;
        child[2] = 0;
        *(void**)(child + 0x7C) = self;
    }
    child = func_8002C458();
    if (child != 0) {
        child[0] = self->active;
        child[1] = 0x17;
        child[2] = 1;
        *(void**)(child + 0x7C) = self;
    }
    D_800FEED0 = 0;
    self->unk5 = 2;
    self->state++;
}
