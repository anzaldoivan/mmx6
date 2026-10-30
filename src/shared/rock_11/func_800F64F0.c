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
        self->unk6 += 2;
        return;
    }
    if (self->unk7E == 0) {
        a = self->y_pos.i.hi;
        b = g_Player.y_pos.i.hi;
        if (F8(self, 0x89) >= (a - b >= 0 ? a - b : b - a)) {
            ((void (*)(void*, s32))set_animation)(self, 2);
            self->unk6++;
            return;
        }
    } else {
        self->unk7E--;
    }
    func_800FA4F8(&self->y_pos, g_Player.y_pos.i.hi, 0x18000);
}
