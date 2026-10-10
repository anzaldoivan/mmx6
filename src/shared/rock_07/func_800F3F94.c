#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002D2B0(void*);
s32 func_80065944(s32);
s32 func_80065A14(s32);
s32 func_80065B74(s32, s32);
extern struct X4_PlayerObj D_800970A0;
extern s32 D_800F97A0;

void func_800F3F94(void* arg0) {
    struct X4_PlayerObj* p;
    s32 ang;
    s32 t;
    s32 pad[4];

    if (--M2C_FIELD(arg0, s16*, 0x88) == 0) {
        M2C_FIELD(arg0, void**, 0x50) = &D_800F97A0;
        M2C_FIELD(arg0, u8*, 0x3) = 0;
        M2C_FIELD(arg0, s32*, 0x54) = 0;
        M2C_FIELD(arg0, s32*, 0x68) = 0;
        M2C_FIELD(arg0, s16*, 0x88) = 0x22;
        M2C_FIELD(arg0, u8*, 0x6)++;
        return;
    }
    p = &D_800970A0;
    {
        s32 px = p->x_pos.i.hi;
        s32 py = p->y_pos.i.hi;
        ang = func_80065B74(M2C_FIELD(arg0, s16*, 0xE) - py,
                            px - M2C_FIELD(arg0, s16*, 0xA));
    }
    switch (M2C_FIELD(arg0, u8*, 0x2) & 0xF) {
    case 0:
        M2C_FIELD(arg0, s32*, 0x20) = (func_80065A14(ang) * 16) >> 1;
        M2C_FIELD(arg0, s32*, 0x24) = (func_80065944(ang) * 16) >> 1;
        break;
    case 1:
        M2C_FIELD(arg0, s32*, 0x20) = func_80065A14(ang) * 16;
        M2C_FIELD(arg0, s32*, 0x24) = func_80065944(ang) * 16;
        break;
    case 2:
        t = func_80065A14(ang) * 16;
        M2C_FIELD(arg0, s32*, 0x20) = ((t << 1) + t) >> 1;
        t = func_80065944(ang) * 16;
        M2C_FIELD(arg0, s32*, 0x24) = ((t << 1) + t) >> 1;
        break;
    case 3:
        M2C_FIELD(arg0, s32*, 0x20) = func_80065A14(ang) * 32;
        M2C_FIELD(arg0, s32*, 0x24) = func_80065944(ang) * 32;
        break;
    }
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    if (M2C_FIELD(arg0, s32*, 0x20) > 0) {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
    } else {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
    }
    func_8002D2B0(arg0);
}
