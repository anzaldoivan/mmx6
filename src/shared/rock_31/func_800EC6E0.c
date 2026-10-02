#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800EC6E0(void* arg0) {
    if (M2C_FIELD(arg0, u8*, 0x89) == 2) {
        M2C_FIELD(arg0, u8*, 0x89) = 0U;
        M2C_FIELD(arg0, s16*, 0x7C) = 0x78;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}
