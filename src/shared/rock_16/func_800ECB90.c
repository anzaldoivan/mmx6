#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern u8 D_800F1C90[];
extern u8 D_800F1CA9;

void func_800ECB90(void* arg0) {
    s32 i;
    M2C_FIELD(arg0, s16*, 8) = 0;
    M2C_FIELD(arg0, s16*, 0xA) = 0;
    M2C_FIELD(arg0, u8*, 2) = (u8)(M2C_FIELD(arg0, u8*, 2) + 1);
    for (i = 0; i < 9; i++) {
        D_800F1C90[i] = 0;
    }
    if (M2C_FIELD(arg0, u8*, 0x66) >= 3U) {
        D_800F1CA9 = 9;
        return;
    }
    D_800F1CA9 = 8;
}
