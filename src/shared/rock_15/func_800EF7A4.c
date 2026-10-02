#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002D230(void*); /* extern */
M2C_UNK func_8002EE10();      /* extern */

void func_800EF7A4(void* arg0) {
    if ((M2C_FIELD(arg0, u8*, 0x70) != 0) ||
        (func_8002EE10(), (M2C_FIELD(arg0, u8*, 0x70) != 0))) {
        M2C_FIELD(arg0, s16*, 0x88) = 0x3C;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
        return;
    }
    func_8002D230(arg0);
}
