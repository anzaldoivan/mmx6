#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_800ED484(void*); /* extern */

void func_800EF048(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x45) == 2) {
        M2C_FIELD(arg0, s16*, 0x86) = 0x28;
        func_800ED484(arg0);
    }
}
