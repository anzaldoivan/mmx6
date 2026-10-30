#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

s32 random_byte();
s32 func_8002D30C();
M2C_UNK func_8004A0C0(s8, s16, s16, s32);
extern u8 D_800E4470[];

void func_80049F98(struct X4_BaseObj* self, s8 arg1, u8 arg2, u8 arg3,
                   u8 arg4) {
    s16 x;
    s16 y;
    s32 r;
    s32 a3;
    s32 t;

    arg2 &= random_byte();
    if (random_byte() & 1) {
        x = self->x_pos.u.hi + arg2;
    } else {
        x = self->x_pos.u.hi - arg2;
    }
    arg3 &= random_byte();
    if (random_byte() & 1) {
        y = self->y_pos.u.hi + arg3;
    } else {
        y = self->y_pos.u.hi - arg3;
    }
    r = func_8002D30C();
    if (arg4 == 0 || r % arg4 == 0) {
        u8* p = &D_800E4470[1];
        t = *p + 1;
        *p = t;
        a3 = 3;
        if (t & 1) {
            a3 = 2;
        }
    } else {
        a3 = 0xFF;
    }
    func_8004A0C0(arg1, x, y, a3);
}
