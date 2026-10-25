#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern struct X4_PlayerObj g_Player;
extern s8 D_800CCEEC;

M2C_UNK func_8003D330(void) {
    struct X4_PlayerObj* p = &g_Player;

    *((s8*)p + 0xD0) = 0;
    p->spike_immune = 0;
    D_800CCEEC = 0;
}
