#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s16 D_800F7E0C;
extern s16 D_800F7E10;

void func_800F4824(void* arg0) {
    if (D_800F7E0C == D_800F7E10) {
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}
