#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern u8 D_800CCF5F;
extern u8 D_800E9A74[];

void func_800F6354(void* arg0) {
    u16 tbl[4];
    u16 v;

    __builtin_memcpy((u8*)tbl, (u8*)D_800E9A74, 8);
    v = tbl[D_800CCF5F];
    M2C_FIELD(arg0, u8*, 6)++;
    M2C_FIELD(arg0, u16*, 0x7E) = v;
}
