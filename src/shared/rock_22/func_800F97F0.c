#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04(); /* extern */

void func_800F97F0(void* arg0) {
    void* temp_s1;

    temp_s1 = M2C_FIELD(arg0, void**, 0x84);
    ((void (*)())func_80017A04)();
    M2C_FIELD(temp_s1, u8*, 7) = (u8)(M2C_FIELD(temp_s1, u8*, 7) + 1);
    M2C_FIELD(arg0, s32*, 0x54) = 0;
    M2C_FIELD(arg0, u8*, 6) = 0;
}
