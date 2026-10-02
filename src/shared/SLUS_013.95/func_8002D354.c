#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002D0D8(s32, s32); /* extern */

void func_8002D354(void* arg0, s32 arg1, s32 arg2) {
    func_8002D0D8(M2C_FIELD(arg0, s32*, 8) - arg1,
                  M2C_FIELD(arg0, s32*, 0xC) - arg2);
}
