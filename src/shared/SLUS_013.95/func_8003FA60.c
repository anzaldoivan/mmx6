#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8003D3F8(M2C_UNK, s8, M2C_UNK, void*); /* extern */

void func_8003FA60(void* arg0) {
    func_8003D3F8(1, M2C_FIELD(arg0, s8*, 0x96), 0, arg0);
}
