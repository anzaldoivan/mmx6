#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern struct X4_PlayerObj g_Player;
extern s8 D_800CCEEC;

M2C_UNK func_8003D308(M2C_UNK arg0, M2C_UNK arg1) {
    u8* p = (u8*)&g_Player;
    p[0xD0] = 1;
    p[0xD1] = arg0;
    p[0xD2] = arg1;
    p[0x7A] = 1;
    D_800CCEEC = 1;
}
