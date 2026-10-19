#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002D2B0(void*);

void func_80041EBC(void* arg0) {
    if (--M2C_FIELD(arg0, s16*, 0x7C) != 0) {
        func_8002D2B0(arg0);
        return;
    }
    M2C_FIELD(arg0, u8*, 0x6) += 1;
}
