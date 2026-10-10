#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80064C94(M2C_UNK*, u32); /* extern */
#define func_80064C94 ((M2C_UNK(*)(M2C_UNK*, u8))func_80064C94)
extern s8 D_800CC869;
#define D_800CC869 (*(u8*)&D_800CC869)
extern M2C_UNK D_800E2E10;
extern u8 D_800E2E15;

void func_800187A0(s32 arg0) {
    u32 temp_v1;
    u8 temp_a1;

    temp_a1 = arg0 & 0xFF;
    D_800E2E15 = temp_a1;
    if (D_800CC869 == 1) {
        M2C_FIELD(&D_800E2E10, u8*, 0) = temp_a1;
        M2C_FIELD(&D_800E2E10, s8*, 1) = 0;
        M2C_FIELD(&D_800E2E10, u8*, 2) = temp_a1;
        M2C_FIELD(&D_800E2E10, s8*, 3) = 0;
    } else {
        temp_v1 = temp_a1 >> 1;
        M2C_FIELD(&D_800E2E10, u8*, 0) = (u8)temp_v1;
        M2C_FIELD(&D_800E2E10, s8*, 1) = (s8)temp_v1;
        M2C_FIELD(&D_800E2E10, u8*, 2) = (u8)temp_v1;
        M2C_FIELD(&D_800E2E10, s8*, 3) = (s8)temp_v1;
    }
    func_80064C94(&D_800E2E10, temp_a1);
}
#undef D_800CC869
#undef func_80064C94
