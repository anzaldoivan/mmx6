#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800FB900(); /* extern */

void func_800FEFD4(void* arg0) {
    M2C_FIELD(arg0, s8*, 0x16) = 5;
    func_800FB900();
}
