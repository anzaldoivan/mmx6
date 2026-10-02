#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();      /* extern */
M2C_UNK func_8002D2B0(void*); /* extern */

void func_800EEDD8(void* arg0) {
    M2C_FIELD(arg0, u8*, 7) = (u8)(M2C_FIELD(arg0, u8*, 7) + 1);
    func_80017A04();
    func_8002D2B0(arg0);
}
