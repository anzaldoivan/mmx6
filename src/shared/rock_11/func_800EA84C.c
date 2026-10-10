#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD (*(u8**)0x1F80004C)

M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_8002D2B0();
s32 func_80065944(s32);
s32 func_80065A14(s32);
s32 func_80065B74(s32, s32);
void func_800EABA4(struct X4_MainObj*);
extern struct X4_PlayerObj D_800970A0;

void func_800EA84C(void* arg0) {
    s32 angle;
    s32 v;
    s32 t;

    s16 px = D_800970A0.x_pos.i.hi;
    s16 py = D_800970A0.y_pos.i.hi;
    angle = func_80065B74(M2C_FIELD(arg0, s16*, 0xE) - py,
                          px - M2C_FIELD(arg0, s16*, 0xA));
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    v = func_80065A14(angle);
    t = v * 16;
    M2C_FIELD(arg0, s32*, 0x20) = v * 32 + t;
    v = func_80065944(angle);
    t = v * 16;
    M2C_FIELD(arg0, s32*, 0x24) = v * 32 + t;
    func_8002D2B0(arg0);
    v = M2C_FIELD(arg0, s32*, 0x24);
    if (v > 0) {
        func_800179A4(arg0, 1);
    } else {
        func_800179A4(arg0, 2);
    }
    func_800EABA4(arg0);
    M2C_FIELD(SPAD, s32*, 0x84) = angle;
    M2C_FIELD(arg0, u8*, 0x6)++;
}
