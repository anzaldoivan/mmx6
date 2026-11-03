#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_800FA4F8(void* arg0, s16 arg1, s32 arg2) {
    s32 x = M2C_FIELD(arg0, s32*, 0);
    s32 h = arg1 << 0x10;
    s32 d = x - h;
    s16 cur;

    if (d >= 0 ? arg2 >= d : arg2 >= h - x) {
        M2C_FIELD(arg0, s16*, 2) = arg1;
        return 1;
    }
    cur = M2C_FIELD(arg0, s16*, 2);
    if (arg1 < cur) {
        M2C_FIELD(arg0, s32*, 0) = M2C_FIELD(arg0, s32*, 0) - arg2;
    } else if (cur < arg1) {
        M2C_FIELD(arg0, s32*, 0) = M2C_FIELD(arg0, s32*, 0) + arg2;
    }
    return 0;
}
