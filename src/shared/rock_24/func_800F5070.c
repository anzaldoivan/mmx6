#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern u8 D_800F7528[];
extern s32 D_800F77DC;

void func_800F5070(void* arg0) {
    s16 n;

    n = ++M2C_FIELD(arg0, u16*, 0x7C);
    if (n == 0x5A) {
        M2C_FIELD(arg0, u8*, 0x84) = 0x28;
        D_800F77DC = 0;
        M2C_FIELD(arg0, u8*, 5) = D_800F7528[M2C_FIELD(arg0, u8*, 0x87)++ +
                                             M2C_FIELD(arg0, u8*, 0x86) * 6];
        M2C_FIELD(arg0, u8*, 6) = 0;
    }
}
