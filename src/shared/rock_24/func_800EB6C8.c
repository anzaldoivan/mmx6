#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)

void func_800EB6C8(void* arg0) {
    s32 d = g_Player.y_pos.i.hi - M2C_FIELD(arg0, s16*, 0xE);

    if (d >= 0) {
        if (d < 2) {
            M2C_FIELD(arg0, s32*, 0x24) = 0;
        } else {
            // !FAKE: inherited from src/shared/rock_11/func_800EA9B4.c
            goto far;
        }
    } else if (M2C_FIELD(arg0, s16*, 0xE) - g_Player.y_pos.i.hi >= 2) {
    far:
        if (g_Player.y_pos.i.hi >= M2C_FIELD(arg0, s16*, 0xE)) {
            M2C_FIELD(arg0, s32*, 0x24) = -0x18000;
        } else {
            M2C_FIELD(arg0, s32*, 0x24) = 0x18000;
        }
    } else {
        M2C_FIELD(arg0, s32*, 0x24) = 0;
    }
    if (--M2C_FIELD(arg0, s16*, 0x7C) == 0) {
        M2C_FIELD(arg0, s16*, 0x7C) = 10;
        M2C_FIELD(arg0, u8*, 0x6) = 0;
    }
}
#undef g_Player
