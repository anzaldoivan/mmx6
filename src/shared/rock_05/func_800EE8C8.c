#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SCRATCH_9C (*(s32**)0x1F80009C)
#define SCRATCH_4C (*(u8**)0x1F80004C)

M2C_UNK set_animation(void*, M2C_UNK);
void* func_8002C458();
s32 random_byte();
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern s32 D_80074FBC;
extern u8 D_800970B4;
extern struct X4_BackgroundObj background_objects[3];
extern struct X4_EngineObj g_playthrough_state;
extern s32 D_800F414C;
extern s32 D_800F4154;
extern s32 D_800F42B4;
extern u16 D_800F447C;
extern u16 D_800F447E;
#define D_800F447E (*(s16*)&D_800F447E)
extern s16 D_800F4480;
#define D_800F4480 (*(u16*)&D_800F4480)
extern s16 D_800F4482;
extern s16 D_800F4484;
extern s16 D_800F4486;
extern s16 D_800F448E;
extern s32 D_800F4490;

void func_800EE8C8(struct X4_MainObj* self) {
    s32 i;
    u16 a;
    u16 e;
    void* o;
    s32* p;
    u8 t;
    u16 v;

    if (g_playthrough_state.stage == 0xC) {
        p = SCRATCH_9C;
        self->sprite_frames = (u8*)p + *p;
        self->unk42 = 0x7948;
    }
    D_800F447C = 0x1130;
    D_800F448E = 0;
    self->contact_damage = 4;
    self->hp = 0;
    self->unk62 = 0;
    self->unk40 = 0x140;
    if (g_playthrough_state.stage == 0xC) {
        D_800F447E = -0x810;
        D_800F4480 = 0x150;
        D_800F4482 = -0xA00;
        D_800F4484 = -0xF0;
        D_800F4486 = 0x800;
        background_objects[1].y_pos.i.hi = 0x800;
    } else {
        D_800F447E = 0;
        D_800F4480 = 0;
        D_800F4482 = 0;
        D_800F4484 = 0;
        D_800F4486 = 0x1010;
    }
    t = D_800970B4;
    self->unk16 = 5;
    self->unk15 = 0;
    self->hurt_box = &D_800F414C;
    self->attack_box = &D_800F4154;
    self->terrain_box = 0;
    self->collision_data = &D_80074FBC;
    self->invincibility_timer = 0;
    self->bg_offset = t;
    ((void (*)(s32, s32, s32))func_8003D308)(0x14, 0x40, t);
    a = D_800F447C + D_800F447E;
    e = D_800F4480 + 0x390;
    self->x_speed = 0;
    self->y_speed = 0;
    self->x_accel = 0;
    self->gravity = 0;
    self->animation_table = &D_800F42B4;
    self->x_pos.i.hi = a;
    self->y_pos.i.hi = e;
    for (i = 0; i < 3; i++) {
        o = func_8002C458();
        if (o != NULL) {
            M2C_FIELD(o, u8*, 0) = 0x41;
            M2C_FIELD(o, u8*, 1) = 0x12;
            M2C_FIELD(o, u8*, 2) = 3;
            v = D_800F447E;
            M2C_FIELD(o, void**, 0x7C) = self;
            M2C_FIELD(o, s16*, 0xA) = i * 0x70 + (v + 0x1058);
        }
    }
    for (i = 0; i < 3; i++) {
        o = func_8002C458();
        if (o != NULL) {
            M2C_FIELD(o, u8*, 0) = 0x41;
            M2C_FIELD(o, u8*, 1) = 0x12;
            M2C_FIELD(o, u8*, 2) = 4;
            v = D_800F447E;
            M2C_FIELD(o, void**, 0x7C) = self;
            M2C_FIELD(o, s16*, 0xA) = i * 0x70 + (v + 0x1058);
        }
    }
    for (i = 0; i < 4; i++) {
        M2C_FIELD(SCRATCH_4C + i, u8*, 0x90) =
            ((random_byte() & 3) + 1) * 0x1E;
    }
    M2C_FIELD(SCRATCH_4C, u8*, 0x89) = 0;
    M2C_FIELD(SCRATCH_4C, u8*, 0x8A) = 0;
    M2C_FIELD(SCRATCH_4C, u8*, 0x8B) = 0;
    M2C_FIELD(SCRATCH_4C, u8*, 0x86) = 0;
    M2C_FIELD(SCRATCH_4C, u8*, 0x94) = 0;
    M2C_FIELD(SCRATCH_4C, u16*, 0x96) = 0;
    M2C_FIELD(SCRATCH_4C, u16*, 0x84) = self->unk42;
    M2C_FIELD(SCRATCH_4C, void**, 0x8C) = self->sprite_frames;
    D_800F4490 = 0;
    background_objects[1].unk4 = 9;
    set_animation(self, 4);
    self->state = 1;
    self->unk5 = 2;
    self->unk6 = 0;
    self->unk7 = 0;
    self->on_screen = 1;
    background_objects[1].pad52[0] = -1;
    background_objects[1].unk3 = 1;
}
#undef D_800F447E
#undef D_800F4480
