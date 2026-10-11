#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
s32 func_80065944(s32);
s32 func_80065A14(s32);
s32 func_80065B74(s32, s32);
extern struct X4_PlayerObj D_800970A0;

void func_800F3A2C(void* arg0) {
    u16 px;
    u16 py;
    s32 ang;

    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        func_80016C48(2, 0x13, arg0);
        func_800179A4(arg0, 0xA);
        {
            register struct X4_PlayerObj* pl asm("$2") = &D_800970A0;
            px = pl->x_pos.u.hi;
            M2C_FIELD(arg0, u16*, 0x84) = px;
            py = pl->y_pos.u.hi;
            M2C_FIELD(arg0, u16*, 0x86) = py;
            ang = func_80065B74(M2C_FIELD(arg0, s16*, 0xE) - (s16)py,
                                (s16)px - M2C_FIELD(arg0, s16*, 0xA));
        }
        {
            s32 w = func_80065A14(ang);
            s32 e = w << 4;
            M2C_FIELD(arg0, s32*, 0x20) = ((w << 5) + e) << 1;
        }
        {
            s32 w = func_80065944(ang);
            s32 e = w << 4;
            M2C_FIELD(arg0, s32*, 0x24) = ((w << 5) + e) << 1;
        }
        if (M2C_FIELD(arg0, s32*, 0x20) >= 0) {
            M2C_FIELD(arg0, u8*, 0x15) = 0x40;
        } else {
            M2C_FIELD(arg0, u8*, 0x15) = 0;
        }
        M2C_FIELD(arg0, u8*, 0x6)++;
    }
}
