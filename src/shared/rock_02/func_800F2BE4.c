#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD4C (*(u8**)0x1F80004C)

M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
s32 func_80065944(s32);
s32 func_80065A14(s32);
s32 func_80065B74(s32, s32);
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern struct X4_BackgroundObj background_objects[3];

void func_800F2BE4(void* arg0) {
    s32 ang;

    g_Player.spike_immune = 1;
    M2C_FIELD(arg0, s32*, 0x68) = 0;
    M2C_FIELD(arg0, s32*, 0x54) = 0;
    M2C_FIELD(arg0, s32*, 0x50) = 0;
    if (g_Player.unk5 == 0x14) {
        func_800179A4(arg0, 2);
        M2C_FIELD(arg0, u8*, 0x15) = 0;
        if (background_objects[0].unk1E + 0x50 < g_Player.x_pos.i.hi) {
            func_8003D308(0x1D, 0);
        } else {
            func_8003D308(0x1D, 0x40);
        }
        ang = func_80065B74((s16)(background_objects[0].unk22 + 0x60) -
                                M2C_FIELD(arg0, s16*, 0xE),
                            (s16)(background_objects[0].unk1E + 0x100) -
                                M2C_FIELD(arg0, s16*, 0xA));
        M2C_FIELD(arg0, s32*, 0x20) = func_80065A14(ang) * 0x10;
        M2C_FIELD(arg0, s32*, 0x24) = -func_80065944(ang) * 0x10;
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
        SPAD4C[0x88] = 0;
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
    }
}
#undef g_Player
