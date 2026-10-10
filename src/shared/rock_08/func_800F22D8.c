#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern void (*D_800F5FA0[])(void*);

void func_800F22D8(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x7) == 1) {
        M2C_FIELD(arg0, s8*, 0x5) = 7;
        M2C_FIELD(arg0, s8*, 0x6) = 0;
        M2C_FIELD(arg0, s8*, 0x7) = 0;
        return;
    }
    D_800F5FA0[M2C_FIELD(arg0, s8*, 0x6)](arg0);
}
