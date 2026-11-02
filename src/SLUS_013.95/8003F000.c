#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8003DF58(void*); /* extern */
M2C_UNK func_8003F0BC(void*); /* extern */
M2C_UNK func_8003F480();      /* extern */

void func_8003F000(void* arg0) {
    if (M2C_FIELD(arg0, s8*, 2) == 0) {
        M2C_FIELD(arg0, s8*, 0x93) = 0;
        func_8003F480();
        func_8003DF58(arg0);
        func_8003F0BC(arg0);
    }
}
