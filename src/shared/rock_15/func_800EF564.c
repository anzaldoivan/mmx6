#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK move_object(s32); /* extern */
M2C_UNK func_80049D90();  /* extern */

void func_800EF564(void* arg0) {
    if (M2C_FIELD(arg0, u8*, 0x70) != 0) {
        func_80049D90();
        M2C_FIELD(arg0, s8*, 3) = 0;
        M2C_FIELD(arg0, s8*, 4) = 2;
        return;
    }
    move_object(arg0);
}
