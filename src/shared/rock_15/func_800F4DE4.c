#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04(); /* extern */
extern s32 D_800F6F60[];

void func_800F4DE4(void* arg0) {
    u8 t;
    void* p;

    func_80017A04();
    t = M2C_FIELD(arg0, u8*, 2);
    if ((u32)(t - 6) < 2U && M2C_FIELD(arg0, s8*, 0x45) == 0x10) {
        M2C_FIELD(arg0, s32**, 0x50) = &D_800F6F60[(s8)t];
    }
    p = M2C_FIELD(arg0, void**, 0x7C);
    if (--M2C_FIELD(arg0, s16*, 0x8C) == 0) {
        M2C_FIELD(arg0, u8*, 4) = 2;
        M2C_FIELD(p, u8*, 7)--;
    }
}
