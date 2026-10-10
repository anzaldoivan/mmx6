#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80017A04();      /* extern */
M2C_UNK func_8002D230(void*); /* extern */

void func_800EEE2C(void* arg0) {
    ((M2C_UNK(*)())func_80017A04)();
    func_8002D230(arg0);
    if (M2C_FIELD(arg0, s32*, 0x24) == 0) {
        M2C_FIELD(arg0, s16*, 0x7C) = 0x28;
        M2C_FIELD(arg0, s32*, 0x24) = 0;
        M2C_FIELD(arg0, s32*, 0x2C) = -0x1000;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}
