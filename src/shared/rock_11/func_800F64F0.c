// rolefeed (3.1 T4): func_800F64F0 of src/rock_11/E9860.c
#include "common.h"
#include "mmx6/rock_11.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK open_text_box(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK load_palette(M2C_UNK, M2C_UNK*, M2C_UNK);
M2C_UNK func_8002B410(M2C_UNK*, M2C_UNK*, M2C_UNK, s32, s32);
s32 is_text_box_seen(M2C_UNK);
M2C_UNK set_text_box_seen(M2C_UNK);

#define F(type, off) M2C_FIELD(self, type*, off)

#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

M2C_UNK set_animation(void*, M2C_UNK);
void func_800FA4C8(struct X4_MainObj* self);
s32 func_800FA4F8(void* arg0, s16 arg1, s32 arg2);
extern struct X4_PlayerObj g_Player;

#define F8(p, o) (*(s8*)((u8*)(p) + (o)))

void func_800F64F0(struct X4_MainObj* self) {
    s32 a;
    s32 b;

    func_800FA4C8(self);
    if (--self->unk7C == -1) {
        self->action_phase += 2;
        return;
    }
    if (self->unk7E == 0) {
        a = self->y_pos.i.hi;
        b = g_Player.y_pos.i.hi;
        if (F8(self, 0x89) >= (a - b >= 0 ? a - b : b - a)) {
            ((void (*)(void*, s32))set_animation)(self, 2);
            self->action_phase++;
            return;
        }
    } else {
        self->unk7E--;
    }
    func_800FA4F8(&self->y_pos, g_Player.y_pos.i.hi, 0x18000);
}
