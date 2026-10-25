#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK move_object(void*);
s32 func_8002D2D4();
s32 func_80065944(s32);
s32 func_80065A14(s32);
s32 func_80065B74(s32, s32);
extern struct X4_PlayerObj g_Player;
extern u8 D_800CCF38;

void func_800F6B5C(void* arg0) {
    s32 angle;
    s32 v;
    s32 t;

    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        s16 px = g_Player.x_pos.i.hi;
        s16 py = g_Player.y_pos.i.hi;
        angle = func_80065B74(M2C_FIELD(arg0, s16*, 0xE) - py,
                              px - M2C_FIELD(arg0, s16*, 0xA));
        v = func_80065A14(angle);
        t = v * 16;
        M2C_FIELD(arg0, s32*, 0x20) = ((v * 32 + t) << 1) / 4;
        v = func_80065944(angle);
        t = v * 16;
        M2C_FIELD(arg0, s32*, 0x24) = ((v * 32 + t) << 1) / 4;
        if (D_800CCF38 >= 2) {
            M2C_FIELD(arg0, s32*, 0x24) = M2C_FIELD(arg0, s32*, 0x24) * 2;
            M2C_FIELD(arg0, s32*, 0x20) = M2C_FIELD(arg0, s32*, 0x20) * 2;
        }
        move_object(arg0);
        v = M2C_FIELD(arg0, s32*, 0x20);
        if (v >= 0) {
            M2C_FIELD(arg0, u8*, 0x15) = 0x40;
        } else {
            M2C_FIELD(arg0, u8*, 0x15) = 0;
        }
        M2C_FIELD(arg0, u16*, 0x7C) = ((u32)func_8002D2D4() % 40 & 0xFF) + 0x32;
        M2C_FIELD(arg0, u8*, 0x5)++;
    }
}
