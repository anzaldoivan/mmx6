#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_800ECD7C(s32, M2C_UNK, M2C_UNK); /* extern */
extern void (*D_800F8768[])(void*);

void func_800EC550(void* arg0) {
    D_800F8768[M2C_FIELD(arg0, s8*, 6)](arg0);
    M2C_FIELD(arg0, s8*, 0x90) = 2;
    func_800ECD7C(arg0 + 0x86, -0x40, 4);
}
