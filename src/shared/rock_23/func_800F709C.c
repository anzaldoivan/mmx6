#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();      /* extern */
M2C_UNK func_8002D2B0(void*); /* extern */
M2C_UNK func_8002EE10(void*); /* extern */
s32 func_80031474(void*);     /* extern */
M2C_UNK func_80049D90(void*); /* extern */

void func_800F709C(void* arg0) {
    ((M2C_UNK(*)())func_80017A04)();
    func_8002D2B0(arg0);
    if ((func_80031474(arg0) < 0) || (M2C_FIELD(arg0, u8*, 0x70) != 0) ||
        (func_8002EE10(arg0), (M2C_FIELD(arg0, u8*, 0x70) != 0))) {
        func_80049D90(arg0);
        M2C_FIELD(arg0, s8*, 4) = 2;
    }
}
