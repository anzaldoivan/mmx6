#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002D2B0(); /* extern */

void func_800EF950(void* arg0) {
    s32 temp_v0;
    s32 temp_v1;

    ((M2C_UNK(*)())func_8002D2B0)();
    temp_v1 = M2C_FIELD(arg0, s16*, 0xA) - M2C_FIELD(arg0, s16*, 0x8C);
    temp_v0 = M2C_FIELD(arg0, s16*, 0xE) - M2C_FIELD(arg0, s16*, 0x8E);
    if (((temp_v1 * temp_v1) + (temp_v0 * temp_v0)) >= 0x1000) {
        M2C_FIELD(arg0, s16*, 0x88) = 0x32;
        M2C_FIELD(arg0, u8*, 6) = (u8)(M2C_FIELD(arg0, u8*, 6) + 1);
    }
}
