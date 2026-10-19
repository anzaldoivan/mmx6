#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s16 D_800970AA;

s32 func_800EF764(void* arg0) {
    s32 g = D_800970AA;
    s32 t = (M2C_FIELD(arg0, s16*, 0xA) < g) << 6;

    return M2C_FIELD(arg0, u8*, 0x15) != t;
}
