#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80064C94(M2C_UNK*, u32); /* extern */
extern u32 D_80070CC0;
extern s8 D_800CC869;
#define D_800CC869 (*(u8*)&D_800CC869)
extern M2C_UNK D_800E2F3C;

void func_8001B90C(u32 arg0) {
    u32 temp_v1;

    D_80070CC0 = arg0;
    if (D_800CC869 != 0) {
        M2C_FIELD(&D_800E2F3C, s8*, 0) = (s8)arg0;
        M2C_FIELD(&D_800E2F3C, s8*, 1) = 0;
        M2C_FIELD(&D_800E2F3C, s8*, 2) = (s8)arg0;
        M2C_FIELD(&D_800E2F3C, s8*, 3) = 0;
    } else {
        temp_v1 = arg0 >> 1;
        M2C_FIELD(&D_800E2F3C, s8*, 0) = (s8)temp_v1;
        M2C_FIELD(&D_800E2F3C, s8*, 1) = (s8)temp_v1;
        M2C_FIELD(&D_800E2F3C, s8*, 2) = (s8)temp_v1;
        M2C_FIELD(&D_800E2F3C, s8*, 3) = (s8)temp_v1;
    }
    func_80064C94(&D_800E2F3C, arg0);
}
#undef D_800CC869
