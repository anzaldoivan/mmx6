#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK);
extern s8 D_800CCF5C;
extern u16* D_800F7DF0;
extern s32 D_800F7E04;
extern s32 D_800F7E08;
extern s16 D_800F7E0C;
extern s16 D_800F7E0E;

void func_800F4744(void* arg0) {
    s32 n = D_800CCF5C;

    if (M2C_FIELD(arg0, s8*, 0x5C) < (s8)(n / 3)) {
        D_800F7DF0 = &D_800F7E08;
    } else if (M2C_FIELD(arg0, s8*, 0x5C) < (n * 2) / 3) {
        D_800F7DF0 = &D_800F7E04;
    }
    func_800179A4(arg0, 0);
    if (D_800F7E0E != 2) {
        D_800F7E0C = 0;
        D_800F7E0E = 1;
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 1;
    } else {
        M2C_FIELD(arg0, u8*, 6) = M2C_FIELD(arg0, u8*, 6) + 2;
    }
}
