#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))
#define SPAD20 (*(s32*)0x1F800020)

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*);
M2C_UNK func_800179A4(void*, M2C_UNK);
s32 func_8002A47C(s32);
extern M2C_UNK g_Player;
#define g_Player (*(struct X4_PlayerObj*)&g_Player)

void func_800EE58C(void* arg0) {
    s16 v;
    s16 w;

    if (g_Player.x_pos.i.hi > M2C_FIELD(arg0, s16*, 0xA)) {
        M2C_FIELD(arg0, u8*, 0x15) = 0x40;
    } else {
        M2C_FIELD(arg0, u8*, 0x15) = 0;
    }
    if (++M2C_FIELD(arg0, s16*, 0x7C) == 0xB4) {
        M2C_FIELD(arg0, s32*, 0x3C) =
            SPAD20 +
            *(s32*)(func_8002A47C(M2C_FIELD(arg0, s8*, 1)) * 4 + SPAD20);
        func_800179A4(arg0, 4);
        func_80016C48(2, 4, arg0);
        M2C_FIELD(arg0, s32*, 0x28) = 0x10000;
        M2C_FIELD(arg0, u8*, 0x6)++;
    }
    if (M2C_FIELD(arg0, s16*, 0xE) < g_Player.y_pos.i.hi) {
        M2C_FIELD(arg0, s16*, 0xE) = v = M2C_FIELD(arg0, s16*, 0xE) + 2;
        if (g_Player.y_pos.i.hi < v) {
            M2C_FIELD(arg0, s16*, 0xE) = g_Player.y_pos.i.hi;
        }
    } else if (g_Player.y_pos.i.hi < M2C_FIELD(arg0, s16*, 0xE)) {
        M2C_FIELD(arg0, s16*, 0xE) = w = M2C_FIELD(arg0, s16*, 0xE) - 2;
        if (w < g_Player.y_pos.i.hi) {
            M2C_FIELD(arg0, s16*, 0xE) = g_Player.y_pos.i.hi;
        }
    }
}
#undef g_Player
