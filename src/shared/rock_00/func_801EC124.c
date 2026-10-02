#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002D5D0(void*);          /* extern */
s32 func_8003A2CC(void*);              /* extern */
M2C_UNK func_8003F4C4(void*, M2C_UNK); /* extern */
M2C_UNK func_8003F508(void*, M2C_UNK); /* extern */
s32 func_801EC35C();                   /* extern */
s32 func_801EC3AC(void*);              /* extern */

void func_801EC124(void* arg0) {
    s32 temp_v0;
    s8 var_v0;

    if ((func_801EC35C() == 0) && (func_8003A2CC(arg0) == 0)) {
        temp_v0 = func_801EC3AC(arg0);
        if (temp_v0 != 0) {
            if (temp_v0 > 0) {
                func_8002D5D0(arg0);
                func_8003F508(arg0, 0x17);
                return;
            }
            func_8003F4C4(arg0, 0x19);
            var_v0 = 5;
            goto block_7;
        }
        func_8003F4C4(arg0, 0x18);
        var_v0 = 4;
    block_7:
        M2C_FIELD(arg0, s8*, 6) = var_v0;
    }
}
