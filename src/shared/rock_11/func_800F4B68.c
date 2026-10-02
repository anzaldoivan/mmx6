#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_8002D230();                    /* extern */

void func_800F4B68(void* arg0) {
    func_8002D230();
    if (func_8002CBFC(arg0, 0x20, 0x40) == 1) {
        M2C_FIELD(arg0, s8*, 3) = 0;
        M2C_FIELD(arg0, u8*, 4) = (u8)(M2C_FIELD(arg0, u8*, 4) + 1);
    }
}
