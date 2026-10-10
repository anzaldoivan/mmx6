#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();             /* extern */
M2C_UNK func_8002CB50(void*, void*); /* extern */
#define func_8002CB50 ((M2C_UNK(*)(void*))func_8002CB50)
s32 func_8002CBFC(void*, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_8002D2B0(void*);               /* extern */

void func_800464C4(void* arg0) {
    ((M2C_UNK(*)())func_80017A04)();
    func_8002D2B0(arg0);
    if (func_8002CBFC(arg0, 0x10, 0x10) != 0) {
        M2C_FIELD(arg0, s8*, 4) = 3;
    }
    func_8002CB50(arg0);
}
#undef func_8002CB50
