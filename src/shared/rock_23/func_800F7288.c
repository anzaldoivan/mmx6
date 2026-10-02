#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();      /* extern */
M2C_UNK func_8002D2B0(void*); /* extern */

void func_800F7288(void* arg0) {
    u8 temp_v0;

    ((M2C_UNK(*)())func_80017A04)();
    temp_v0 = M2C_FIELD(arg0, u8*, 0x8E);
    if (temp_v0 != 0) {
        M2C_FIELD(arg0, u8*, 0x8E) = (u8)(temp_v0 - 1);
        return;
    }
    func_8002D2B0(arg0);
}
