#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK);
s32 func_8002D2D4();
void func_80042A9C(struct X4_MainObj* self, s32);
void func_80042C18(struct X4_MainObj* self);
s32 func_80065944(s32);
s32 func_80065A14(s32);
extern struct X4_PlayerObj D_800970A0;

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
        ang = func_8002D2D4() * 0x10;
        {
            struct X4_PlayerObj* p = &D_800970A0;
            M2C_FIELD(self, u16*, 0x84) = p->x_pos.i.hi;
            M2C_FIELD(self, u16*, 0x86) = p->y_pos.i.hi;
        }
        self->x_pos.i.hi =
            M2C_FIELD(self, u16*, 0x84) + (func_80065A14(ang) >> 6);
        t = func_80065944(ang) >> 6;
        self->unk7 = 0;
        self->y_pos.i.hi = M2C_FIELD(self, u16*, 0x86) + t;
        func_80042A9C(self, 0);
        func_80042A9C(self, 1);
        self->unk6++;
    }
}
