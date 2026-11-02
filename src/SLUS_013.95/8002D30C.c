#include "common.h"

extern u16 D_80090E70;

s32 func_8002D30C(void) {
    s32 r;
    s32 ret;
    u32 t;
    u16 v;
    t = (u32)((D_80090E70 + D_80090E70 * 2) & 0xFFFF) >> 8;
    v = D_80090E70 + t;
    t <<= 8;
    v = (v & 0xFF) | t;
    D_80090E70 = v;
    r = v & 0xFF;
    ret = 1;
    if (r != 0) {
        ret = r;
    }
    return ret;
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002D0D8(s32, s32); /* extern */

void func_8002D354(void* arg0, s32 arg1, s32 arg2) {
    func_8002D0D8(M2C_FIELD(arg0, s32*, 8) - arg1,
                  M2C_FIELD(arg0, s32*, 0xC) - arg2);
}

#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002D0D8(s32, s32);
void func_8002D380(void* arg0, void* arg1) {
    s32 temp_a2;

    temp_a2 = M2C_FIELD(arg0, s32*, 8);
    ((s32(*)())func_8002D0D8)(
        temp_a2 - M2C_FIELD(arg1, s32*, 8),
        M2C_FIELD(arg0, s32*, 0xC) - M2C_FIELD(arg1, s32*, 0xC), temp_a2);
}
