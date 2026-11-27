// rolefeed (3.1 T4): func_800F90A0 of src/rock_11/E9860.c
#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK open_text_box(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);
M2C_UNK func_8002B410(M2C_UNK*, M2C_UNK*, M2C_UNK, s32, s32);
s32 is_text_box_seen(M2C_UNK);
M2C_UNK set_text_box_seen(M2C_UNK);

#define F(type, off) M2C_FIELD(self, type*, off)

#include "common.h"
#include "mmx6/x4.h"

void func_800FA4C8(struct X4_MainObj* self);
extern s8 D_800CCF5C;

void func_800F90A0(struct X4_MainObj* self) {
    if (--self->unk7C == 0) {
        func_800FA4C8(self);
        self->unk7C = 8;
        if (self->unk7E != 0) {
            self->unk7E--;
            if (++self->hp >= D_800CCF5C) {
                self->hp = D_800CCF5C;
                self->action_phase++;
            }
        } else {
            self->action_phase++;
        }
    }
}
