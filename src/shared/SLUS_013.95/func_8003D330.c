#include "common.h"
#define M2C_UNK s32
#include "mmx6/x4.h"

extern struct X4_PlayerObj D_800970A0;
extern s8 D_800CCEEC;

M2C_UNK func_8003D330(void) {
    struct X4_PlayerObj* p = &D_800970A0;

    *((s8*)p + 0xD0) = 0;
    p->spike_immune = 0;
    D_800CCEEC = 0;
}
