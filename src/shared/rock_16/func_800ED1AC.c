#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern u8 D_800F1CC4[];

void func_800ED1AC(void* arg0) {
    s32 temp_v0;

    temp_v0 = M2C_FIELD(arg0, u16*, 8) + 1;
    M2C_FIELD(arg0, u16*, 8) = temp_v0;
    if ((s16)temp_v0 >= 8) {
        u8* p = D_800F1CC4;
        p[2] = 0;
        p[5] = 0;
        M2C_FIELD(arg0, u16*, 8) = 0;
        M2C_FIELD(arg0, u8*, 2) = (u8)(M2C_FIELD(arg0, u8*, 2) + 1);
    }
}
