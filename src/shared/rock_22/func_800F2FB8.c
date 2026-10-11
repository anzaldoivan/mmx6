#include "common.h"
#include "mmx6/x4.h"

s32 func_800F3FF8(struct X4_MainObj*, s32, s32);
u8 func_800F4094(struct X4_PlayerObj* self, s16 arg1, s16 arg2);

s32 func_800F2FB8(void* arg0, u8 arg1, s32 arg2) {
    struct X4_MainObj* self = arg0;
    register s32 d asm("$6");
    s16 dx;
    s16 x;
    s16 y;
    s32 t;
    u8 r;
    s32 ret;

    if ((u8)arg2 == 0) {
        if (arg1 == 0) {
            register s32 m asm("$3") = -SP_CUR_MAIN_OBJ->ext.main_19.unk8A;
            m <<= 16;
            y = (m >> 16) - self->terrain_box->unk3;
            d = m >> 16;
        } else {
            d = (s16)SP_CUR_MAIN_OBJ->ext.main_19.unk8A;
            y = self->terrain_box->unk3 + d;
        }
        dx = 1;
        if (self->unk15 == 0) {
            dx = -1;
            x = -4;
        } else {
            x = 4;
        }
        t = func_800F3FF8(self, dx, d);
        r = func_800F4094((struct X4_PlayerObj*)self, x, y);
        if ((t & 0xF) == (1 << SP_CUR_MAIN_OBJ->ext.main_19.animation_index)) {
            ret = r < 0x38;
        } else {
            ret = 1;
        }
    } else {
        s16 e;

        if (arg1 == 0) {
            e = -SP_CUR_MAIN_OBJ->ext.main_19.unk8A;
            x = e - self->terrain_box->unk2;
        } else {
            e = (s16)SP_CUR_MAIN_OBJ->ext.main_19.unk8A;
            x = self->terrain_box->unk2 + e;
        }
        t = func_800F3FF8(self, e, -1);
        r = func_800F4094((struct X4_PlayerObj*)self, x, -4);
        ret = 1;
        if ((t & 0xF) == 4) {
            ret = r < 0x38;
        }
    }
    return ret;
}
