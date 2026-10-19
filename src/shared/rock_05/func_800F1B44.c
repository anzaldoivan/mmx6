#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800179A4(void*, M2C_UNK);
M2C_UNK func_80017A04();
void func_800F2B4C();

void func_800F1B44(void* arg0) {
    func_800F2B4C();
    func_800179A4(arg0, 5);
    ((void (*)(void*))func_80017A04)(arg0);
    M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
}
