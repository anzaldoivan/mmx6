#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern void (*D_800F9808[])(void*);

void func_800F77C8(void* arg0) {
    if (M2C_FIELD(M2C_FIELD(arg0, void**, 0x8C), s8*, 7) == 1) {
        M2C_FIELD(arg0, s8*, 0x96) = 0;
    }
    D_800F9808[M2C_FIELD(arg0, s8*, 6)](arg0);
}
