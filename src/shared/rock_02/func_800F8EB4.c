#include "common.h"
#include "psyq/libgte.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern M2C_UNK D_800FB304;
extern M2C_UNK D_800FB310;

void func_800F8EB4(void* arg0) {
    s32 ang;
    void* g;

    ((M2C_UNK(*)())func_80017A04)();
    g = &g_Player;
    M2C_FIELD(arg0, s32*, 0x24) = 0xFFFF0000;
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, void**, 0x54) = &D_800FB304;
    M2C_FIELD(arg0, void**, 0x50) = &D_800FB310;
    ang = ratan2(M2C_FIELD(g, s16*, 0xE) - M2C_FIELD(arg0, s16*, 0xE),
                 M2C_FIELD(g, s16*, 0xA) - M2C_FIELD(arg0, s16*, 0xA));
    M2C_FIELD(arg0, s32*, 0x20) = rcos(ang) << 7;
    M2C_FIELD(arg0, s32*, 0x24) = -rsin(ang) << 7;
    M2C_FIELD(arg0, u8*, 0x8D) = 0x14;
    M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
}
#undef g_Player
