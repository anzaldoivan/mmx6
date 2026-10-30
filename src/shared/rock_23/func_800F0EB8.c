#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD4C (*(u8**)0x1F80004C)

void set_boss_level();
M2C_UNK func_8003D308(M2C_UNK, M2C_UNK);
extern struct X4_PlayerObj g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)
extern s16 D_8009721E;
extern struct X4_EngineObj g_playthrough_state;

void func_800F0EB8(void* arg0) {
    if (M2C_FIELD(arg0, s16*, 0x7C) != 0 &&
        ((g_Player.unk15 == 0 && D_8009721E + 0x48 >= g_Player.x_pos.i.hi) ||
         (g_Player.unk15 == 0x40 &&
          g_Player.x_pos.i.hi >= D_8009721E + 0x18))) {
        func_8003D308(0x14, 0x40);
        M2C_FIELD(arg0, s16*, 0x7C) = 0;
    }
    if (*M2C_FIELD(SPAD4C, s8**, 0x80) == 0) {
        g_playthrough_state.enable_boss = 1;
        g_playthrough_state.unk25 = 0;
        g_playthrough_state.boss_ptr = arg0;
        if (M2C_FIELD(arg0, s8*, 2) == 0) {
            M2C_FIELD(&g_playthrough_state, s8*, 0x8C) = 0x20;
        } else {
            M2C_FIELD(&g_playthrough_state, s8*, 0x8C) = 0x30;
            if (M2C_FIELD(&g_playthrough_state, u8*, 0x8F) != 0) {
                if (M2C_FIELD(&g_playthrough_state, u8*, 0x8F) == 1) {
                    M2C_FIELD(&g_playthrough_state, s8*, 0x8C) = 0x34;
                } else if (M2C_FIELD(&g_playthrough_state, u8*, 0x8F) == 2) {
                    M2C_FIELD(&g_playthrough_state, s8*, 0x8C) = 0x38;
                } else {
                    M2C_FIELD(&g_playthrough_state, s8*, 0x8C) = 0x40;
                }
            }
        }
        set_boss_level();
        {
            s32 k = 0xFFFF0000;
            M2C_FIELD(arg0, s32*, 0x24) = k;
            k = 1;
            M2C_FIELD(arg0, s8*, 3) = k;
        }
        M2C_FIELD(arg0, u8*, 6) += 1;
    }
}
#undef g_Player
