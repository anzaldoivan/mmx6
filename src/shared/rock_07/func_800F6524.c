#include "common.h"
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK);
void func_800F6E78(void*);

void func_800F6524(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
        ((void (*)())func_800F6E78)();
        ((void (*)(void*, s32))func_800179A4)(arg0, 0x19);
        M2C_FIELD(arg0, u8*, 0x6)++;
    }
}
