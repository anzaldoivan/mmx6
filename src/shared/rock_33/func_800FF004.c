#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_800179A4(void*, s32);
extern s8 D_800CCF5C;
extern u16* D_80100C24;
extern s32 D_80100C38;
extern s32 D_80100C3C;
extern s16 D_80100C40;
extern s16 D_80100C42;

void func_800FF004(void* arg0) {
    s32 n = D_800CCF5C;

    if (M2C_FIELD(arg0, s8*, 0x5C) < (s8)(n / 3)) {
        D_80100C24 = &D_80100C3C;
    } else if (M2C_FIELD(arg0, s8*, 0x5C) < (n * 2) / 3) {
        D_80100C24 = &D_80100C38;
    }
    func_800179A4(arg0, 0);
    if (D_80100C42 != 2) {
        D_80100C40 = 0;
        D_80100C42 = 1;
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
    } else {
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 2;
    }
}
