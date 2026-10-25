#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern M2C_UNK g_Player;

void func_800E9918(void* arg0) {
    struct X4_PlayerObj* pl = &g_Player;

    if (M2C_FIELD(pl, s16*, 0xA) >= 0x80) {
        M2C_FIELD(pl, s32*, 0xF4) += 0x8000;
        M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
    }
}
