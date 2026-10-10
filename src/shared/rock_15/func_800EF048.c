#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_800ED484(); /* extern */

void func_800EF048(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x45) == 2) {
        M2C_FIELD(arg0, s16*, 0x86) = 0x28;
        ((M2C_UNK(*)())func_800ED484)();
    }
}
