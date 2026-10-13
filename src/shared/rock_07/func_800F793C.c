#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F793C(void* arg0) {
    if (--M2C_FIELD(arg0, s16*, 0x88) == 0) {
        M2C_FIELD(arg0, s16*, 0x88) = 0xB4;
        M2C_FIELD(arg0, s8*, 6) = (s8)((u8)M2C_FIELD(arg0, s8*, 6) + 1);
    }
}
