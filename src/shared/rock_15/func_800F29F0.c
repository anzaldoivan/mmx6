#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern u8 D_800F6DF8[];

void func_800F29F0(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        s8 t = ++M2C_FIELD(arg0, s8*, 0x89);
        u8 v = D_800F6DF8[t + M2C_FIELD(arg0, s8*, 0x88) * 4];
        M2C_FIELD(arg0, u8*, 0x8B) = 0;
        M2C_FIELD(arg0, u8*, 0x6) = 0;
        M2C_FIELD(arg0, u8*, 0x5) = v;
    }
}
