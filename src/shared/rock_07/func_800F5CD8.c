#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern u8 D_800CCF5F;
extern u8 D_800E9A70[];

void func_800F5CD8(void* arg0) {
    u8 tbl[4];
    s32 n;

    __builtin_memcpy((u8*)tbl, (u8*)D_800E9A70, 4);
    n = tbl[D_800CCF5F];
    M2C_FIELD(arg0, u8*, 6)++;
    M2C_FIELD(arg0, s16*, 0x7E) = (s8)n;
}
