#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002D2B0(void*);
s32 func_80065944(s32);
s32 func_80065A14(s32);
s32 func_80065B74(s32, s32);
extern struct X4_PlayerObj D_800970A0;

void func_800F65D8(void* arg0) {
    s32 angle;
    s32 d;

    {
        s16 px = D_800970A0.x_pos.i.hi;
        s16 py = D_800970A0.y_pos.i.hi;
        angle = func_80065B74(M2C_FIELD(arg0, s16*, 0xE) - py,
                              px - M2C_FIELD(arg0, s16*, 0xA));
    }
    M2C_FIELD(arg0, s32*, 0x20) = func_80065A14(angle) << 5;
    M2C_FIELD(arg0, s32*, 0x24) = func_80065944(angle) << 5;
    func_8002D2B0(arg0);
    d = D_800970A0.x_pos.i.hi - M2C_FIELD(arg0, s16*, 0xA);
    if (d >= 0) {
        if (d >= 4) {
            goto block;
        }
    } else if (M2C_FIELD(arg0, s16*, 0xA) - D_800970A0.x_pos.i.hi >= 4) {
    block:
        if (M2C_FIELD(arg0, s32*, 0x20) >= 0) {
            M2C_FIELD(arg0, u8*, 0x15) = 0x40;
        } else {
            M2C_FIELD(arg0, u8*, 0x15) = 0;
        }
    }
    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        M2C_FIELD(arg0, u8*, 0x6)++;
    }
}
