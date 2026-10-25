#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
s32 func_8002D2D4();
extern s32 D_8007429C;
extern s32 D_800FE210;
extern s32 D_800FE214;
extern void* D_800FE298;

#define PARENT ((struct X4_MainObj*)D_800FE298)

void func_800FBD38(struct X4_MainObj* self) {
    // !FAKE: depin: dropping it breaks the match (88/96)
    register s32 t3c asm("$6");
    u8 dir;
    s32 v;
    struct X4_MainObj* p = PARENT;

    self->unk40 = p->unk40;
    self->unk42 = p->unk42 & 0x7FFF;
    M2C_FIELD(self, s32*, 0x30) = M2C_FIELD(p, s32*, 0x30);
    t3c = M2C_FIELD(p, s32*, 0x3C);
    self->unk16 = 4;
    self->bg_offset = 0;
    {
        struct X4_MainObj* q = PARENT;
        M2C_FIELD(self, s32*, 0x3C) = t3c;
        dir = q->unk15;
    }
    {
        void* a = &D_800FE210;
        // !FAKE: depin: dropping it breaks the match (83/96)
        register void* b asm("$3") = &D_800FE214;
        self->attack_box = a;
        self->air_state = 0;
        self->on_screen = 0;
        self->terrain_box = 0;
        self->hurt_box = b;
    }
    self->collision_data = &D_8007429C;
    self->unk15 = dir;
    if (dir == 0) {
        M2C_FIELD(self, u16*, 0xA) = M2C_FIELD(PARENT, u16*, 0xA) - 0x40;
    } else {
        M2C_FIELD(self, u16*, 0xA) = M2C_FIELD(PARENT, u16*, 0xA) + 0x40;
    }
    M2C_FIELD(self, u16*, 0xE) = M2C_FIELD(PARENT, u16*, 0xE) - 0x4C;
    if (func_8002D2D4() & 1) {
        if (self->unk15 == 0) {
            self->x_speed = 0xFFFE0000;
        } else {
            self->x_speed = 0x20000;
        }
    } else {
        if (self->unk15 == 0) {
            self->x_speed = 0xFFF80000;
        } else {
            self->x_speed = 0x80000;
        }
    }
    self->y_speed = 0;
    self->x_accel = 0;
    self->gravity = 0;
    self->hp = 1;
    self->contact_damage = 0xA;
    func_800179A4(self, 0xF);
    func_80016C48(2, 0x92, self);
    func_80016C48(2, 0x96, self);
    M2C_FIELD(self, s32*, 0x8C) = 0;
    self->unk5 = 0;
    self->state++;
}
#undef PARENT
