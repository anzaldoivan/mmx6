#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK move_object(void*);
void func_800F6880(void* arg0, u8 arg1, s16 arg2, s16 arg3);
extern s16 D_800970AA;
extern s32 D_80097420;
extern M2C_UNK D_800F907C;
extern s32 D_800F986C;
extern s32 D_800F9870;

void func_800F2468(void* arg0) {
    struct X4_PlayerObj* self = arg0;
    s32 m;
    u16 x;

    move_object(arg0);
    {
        // !FAKE: depin: dropping it breaks the match (96/98)
        register s32 f asm("$2") = self->unk15;
        if (f == 0) {
            x = self->x_pos.u.hi;
            if (D_800970AA < self->x_pos.i.hi) {
                m = self->unk70 & 2;
                goto check;
            }
        } else {
            x = self->x_pos.u.hi;
            if (D_800970AA <= self->x_pos.i.hi) {
                goto set;
            }
            m = self->unk70 & 1;
        check:
            if (m == 0) {
                goto body;
            }
        }
    }
set:
    ((void (*)(void*, s32, u16))func_800179A4)(arg0, 0x27, x);
    self->input.buttons.held = 0x5A;
    self->attacking = 0;
    self->unk68 = (void*)&D_800F907C;
    self->x_vel.val = 0;
    self->unk28 = 0;
    self->y_pos.u.hi -= 0x1C;
    self->y_vel.val = D_800F986C;
    self->unk2C = D_800F9870;
    self->unk6 += 1;
    return;
body:
    if (!(D_80097420 & 7)) {
        if (self->unk15 == 0) {
            func_800F6880(arg0, 0x15, x - 0x1E, self->y_pos.u.hi + 0xC);
        } else {
            func_800F6880(arg0, 0x14, x + 0x1E, self->y_pos.u.hi + 0xC);
        }
    }
    if (--M2C_FIELD(self, s16*, 0x7C) == 0) {
        self->input.buttons.held = 0x32;
        func_80016C48(2, 0x5F, arg0);
    }
}
