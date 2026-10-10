#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04(void*); /* extern */
M2C_UNK func_8002D2B0(void*); /* extern */

void func_800F18D8(void* arg0) {
    if (M2C_FIELD(arg0, u8*, 0x70) & 1) {
        M2C_FIELD(arg0, s32*, 0x20) = 0;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
        return;
    }
    func_80017A04(arg0);
    func_8002D2B0(arg0);
}
