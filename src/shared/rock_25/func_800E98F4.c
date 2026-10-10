#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD (*(u8**)0x1F80004C)
#define SPAD_SLOT ((u8**)0x1F80004C)

M2C_UNK func_800179A4(void*, M2C_UNK);
void func_800EAA5C(void*, s32, void*);
void func_800EABD0(struct X4_MainObj* self);
extern M2C_UNK D_800743DC;
extern u8 D_800970B4;
extern s32 D_800EF330;
extern s32 D_800EF334;
extern s32 D_800EF6D8;

void func_800E98F4(struct X4_MainObj* self) {
    u8** sp = SPAD_SLOT;
    s32 seven;
    s8 kind;
    u8 b;
    s32 x;
    s32 y;
    u8* p;

    self->contact_damage = 4;
    self->hp = 0x10;
    self->invincibility_timer = 0;
    self->on_screen = 0;
    self->animation_table = (const u8* const*)&D_800EF6D8;
    M2C_FIELD(*sp, u8*, 0x87) = 0;
    self->terrain_box = 0;
    self->hurt_box = 0;
    self->attack_box = 0;
    b = D_800970B4;
    x = self->x_pos.val;
    y = self->y_pos.val;
    seven = 7;
    self->unk15 = 0;
    self->unk16 = seven;
    self->air_state = 0;
    self->collision_data = &D_800743DC;
    self->x_speed = 0;
    self->y_speed = 0;
    self->x_accel = 0;
    self->gravity = 0;
    self->bg_offset = b;
    self->unk18.val = x;
    self->unk1C.val = y;
    func_800EABD0(self);
    self->state = 1;
    self->unk6 = 0;
    __builtin_memcpy(*sp + 0x80, &D_800EF334, 4);
    kind = self->unk2;
    if (kind == 0) {
        func_800179A4(self, 0);
        {
            register s32 two asm("$3") = 2;
            register s32 h asm("$2") = self->y_pos.u.hi;
            self->unk5 = two;
            self->y_pos.u.hi = h - 0x20;
        }
    } else if (kind == 1) {
        func_800179A4(self, 0xE);
        {
            register s32 two asm("$3") = 2;
            register s32 h asm("$2") = self->y_pos.u.hi;
            self->unk5 = two;
            self->y_pos.u.hi = h + 0x20;
        }
    } else if (kind == 2) {
        func_800179A4(self, 7);
        M2C_FIELD(SPAD, u8*, 0x86) = 3;
        p = SPAD;
        M2C_FIELD(p, u16*, 0x84) = self->y_pos.u.hi;
        func_800EAA5C(self, 0x10, p);
        self->unk5 = seven;
        self->terrain_box = 0;
        self->attack_box = &D_800EF330;
        self->hurt_box = &D_800EF334;
        self->y_pos.u.hi += 0x1A;
    }
}
