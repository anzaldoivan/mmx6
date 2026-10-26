#include "common.h"
#include "psyq/libgte.h"
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern struct X4_PlayerObj g_Player;
extern s32 D_800F672C;
extern s32 D_800F6730;

void func_800EF48C(void* arg0) {
    s32 angle;

    if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
        M2C_FIELD(arg0, s16*, 0xA) -= 0x22;
    } else {
        M2C_FIELD(arg0, s16*, 0xA) += 0x22;
    }
    M2C_FIELD(arg0, s32**, 0x50) = &D_800F672C;
    M2C_FIELD(arg0, s32**, 0x68) = &D_800F6730;
    M2C_FIELD(arg0, s16*, 0xE) -= 0xF;
    angle = ratan2(M2C_FIELD(arg0, s16*, 0xE) - g_Player.y_pos.i.hi,
                   g_Player.x_pos.i.hi - M2C_FIELD(arg0, s16*, 0xA));
    M2C_FIELD(arg0, s32*, 0x28) = 0;
    M2C_FIELD(arg0, s32*, 0x2C) = 0;
    M2C_FIELD(arg0, s32*, 0x20) = rcos(angle) << 8;
    M2C_FIELD(arg0, s32*, 0x24) = rsin(angle) << 8;
    M2C_FIELD(arg0, u8*, 0x6)++;
}
