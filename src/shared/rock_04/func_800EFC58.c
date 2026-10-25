#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK);
s32 func_80065944(s32);
s32 func_80065A14(s32);
s32 func_80065B74(s32, s32);
extern struct X4_PlayerObj g_Player;
extern s32 D_800F6D94;
extern s32 D_800F6DA0;

void func_800EFC58(void* arg0) {
    struct X4_PlayerObj* p;
    s32 ang;
    s32 face;

    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        if (M2C_FIELD(arg0, s8*, 0x2) == 0xB) {
            func_800179A4(arg0, 3);
        } else {
            func_800179A4(arg0, 1);
        }
        p = &g_Player;
        ang = func_80065B74(p->y_pos.i.hi - M2C_FIELD(arg0, s16*, 0xE),
                            p->x_pos.i.hi - M2C_FIELD(arg0, s16*, 0xA));
        M2C_FIELD(arg0, s32*, 0x20) = func_80065A14(ang) << 6;
        M2C_FIELD(arg0, s32*, 0x24) = -func_80065944(ang) << 6;
        face = p->x_pos.val >= M2C_FIELD(arg0, s32*, 0x8);
        M2C_FIELD(arg0, void**, 0x54) = &D_800F6DA0;
        M2C_FIELD(arg0, void**, 0x50) = &D_800F6D94;
        M2C_FIELD(arg0, s8*, 0x5) = 2;
        M2C_FIELD(arg0, s8*, 0x6) = 0;
        M2C_FIELD(arg0, u8*, 0x15) = face << 6;
    }
}
