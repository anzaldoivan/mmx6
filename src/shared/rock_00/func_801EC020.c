#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_80039EB0(void*);              /* extern */
s32 func_8003A2CC(void*);              /* extern */
M2C_UNK func_8003B298(void*);          /* extern */
M2C_UNK func_8003F508(void*, M2C_UNK); /* extern */
s32 func_801EC35C();                   /* extern */
s32 func_801EC3AC(void*);              /* extern */
M2C_UNK func_801EC478(void*, s32);     /* extern */

void func_801EC020(void* arg0) {
    s32 temp_v0;

    if ((func_801EC35C() == 0) && (func_8003A2CC(arg0) == 0)) {
        if ((func_80039EB0(arg0) != 0) && (M2C_FIELD(arg0, u8*, 0x92) == 0)) {
            func_8003B298(arg0);
            return;
        }
        temp_v0 = func_801EC3AC(arg0);
        if (temp_v0 != 0) {
            M2C_FIELD(arg0, s8*, 0xD9) = 0x28;
            func_801EC478(arg0, temp_v0);
            return;
        }
        func_8003F508(arg0, 0x15);
    }
}
