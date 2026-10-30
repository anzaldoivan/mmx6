#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002CBFC(struct X4_AnimatedObj* arg0, s32 arg1, s32 arg2);
s32 random_byte();
void func_80042A9C(struct X4_MainObj* self, s32);
void func_80042C18(struct X4_MainObj* self);
extern struct X4_PlayerObj g_Player;

void func_80041D5C(struct X4_MainObj* self) {
    s16 ang;
    s32 t;

    self->on_screen = 0;
    if (--self->unk7C == 0) {
        if (func_8002CBFC(self, 0x40, 0x40) == 1) {
            self->state = 3;
            return;
        }
        func_80042C18(self);
        ang = random_byte() * 0x10;
        {
            struct X4_PlayerObj* p = &g_Player;
            M2C_FIELD(self, u16*, 0x84) = p->x_pos.i.hi;
            M2C_FIELD(self, u16*, 0x86) = p->y_pos.i.hi;
        }
        self->x_pos.i.hi = M2C_FIELD(self, u16*, 0x84) + (rcos(ang) >> 6);
        t = rsin(ang) >> 6;
        self->unk7 = 0;
        self->y_pos.i.hi = M2C_FIELD(self, u16*, 0x86) + t;
        func_80042A9C(self, 0);
        func_80042A9C(self, 1);
        self->unk6++;
    }
}
