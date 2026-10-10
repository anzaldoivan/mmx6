#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04(void*); /* extern */
M2C_UNK func_8002D2B0();      /* extern */

void func_800EC8F8(void* arg0) {
    M2C_FIELD(arg0, s32*, 0x20) = 0;
    M2C_FIELD(arg0, s32*, 0x24) = 0x20000;
    ((M2C_UNK(*)())func_8002D2B0)();
    func_80017A04(arg0);
}
