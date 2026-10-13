#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* func_8003D3F8(s8 arg0, s8 arg1, s8 arg2, s32 arg3); /* extern */

void func_8003FA60(void* arg0) {
    func_8003D3F8(1, M2C_FIELD(arg0, s8*, 0x96), 0, arg0);
}
