#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32**)0x1F800020)

void func_80025FD8();
s32 func_8002A47C(s32);
struct X4_VisualObj* func_8002C398(void);
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern s32 D_800750FC;
extern u8 D_800970B4;
extern struct X4_BackgroundObj D_800971F8[3];
extern struct X4_EngineObj D_800CCED0;
extern u8 D_800FA000[];
extern s32 D_800FDE30;
extern s32 D_800FDE34;
extern s32 D_800FDE38;
extern s32 D_800FE070;
extern s16 D_800FE284;
extern s16 D_800FE286;
extern s16 D_800FE288;
extern u16 D_800FE28A;
extern u16 D_800FE28C;
extern s16 D_800FE28E;
extern s32 D_800FE290;
extern s32 D_800FE294;
extern void* D_800FE298;

void func_800FA054(struct X4_MainObj* self) {
    u8 tbl[4];
    u8 bg;
    register s32 k asm("$22");
    struct X4_MainObj* child;
    struct X4_MainObj* prev;
    s32 i;

    i = 0;
    __builtin_memcpy(tbl, D_800FA000 + 4, 4);
    self->unk40 = 0x140;
    self->unk42 = 0x7948;
    self->sprite_frames = (u8*)SPAD20 + SPAD20[func_8002A47C(self->id)];
    D_800FE284 = D_800971F8[0].unk26 + 0x10;
    D_800FE286 = D_800971F8[0].unk26 + 0x130;
    D_800FE288 = D_800971F8[0].unk2A + 0xC0;
    D_800FE28A = D_800971F8[0].unk26 + 0xE0;
    D_800FE28C = D_800971F8[0].unk2A + 0xA0;
    D_800FE28E = D_800971F8[0].unk2A - 0x20;
    self->animation_table = (void*)&D_800FE070;
    bg = D_800970B4;
    self->unk16 = 5;
    self->unk15 = 0;
    self->air_state = 0;
    self->on_screen = 0;
    self->terrain_box = (void*)&D_800FDE30;
    self->attack_box = &D_800FDE34;
    self->hurt_box = &D_800FDE38;
    self->unk62 = 0;
    self->invincibility_timer = 0;
    self->bg_offset = bg;
    self->collision_data = &D_800750FC;
    self->x_speed = 0;
    self->y_speed = 0;
    self->x_accel = 0;
    self->gravity = 0;
    self->x_pos.i.hi = D_800FE28A;
    self->y_pos.i.hi = D_800FE28C;
    self->hp = 0;
    self->contact_damage = 0xA;
    D_800CCED0.unk25 = 0;
    D_800CCED0.boss_ptr = self;
    M2C_FIELD(&D_800CCED0, u8*, 0x8C) = 0x30;
    func_80025FD8(0);
    k = 0x794C;
    M2C_FIELD(&D_800CCED0, u8*, 0x8C) += tbl[M2C_FIELD(&D_800CCED0, u8*, 0x8F)];
    M2C_FIELD(self, u8*, 0x87) = 0;
    M2C_FIELD(self, u8*, 0x86) = 0;
    M2C_FIELD(self, u8*, 0x84) = 0;
    func_8003D308(0x14, 0x40);
    D_800FE290 = 0;
    D_800FE294 = 0;
    D_800FE298 = self;
    M2C_FIELD(self, s16*, 0x8A) = 0;
    M2C_FIELD(self, u8*, 0x9A) = 0;
    do {
        child = (struct X4_MainObj*)func_8002C398();
        if (child != 0) {
            child->active = 0x51;
            child->id = 6;
            child->unk2 = i;
            child->bg_offset = self->bg_offset;
            M2C_FIELD(child, s32*, 0x38) = M2C_FIELD(self, s32*, 0x38);
            child->sprite_frames = self->sprite_frames;
            child->unk40 = self->unk40;
            child->unk42 = k;
            child->unk16 = 6;
            child->attack_box = self;
            if (i != 0) {
                M2C_FIELD(child, void**, 0x5C) = prev;
            } else {
                M2C_FIELD(child, void**, 0x5C) = self;
            }
            prev = child;
        }
        i++;
    } while (i < 3);
    self->unk5 = 2;
    self->state++;
}
