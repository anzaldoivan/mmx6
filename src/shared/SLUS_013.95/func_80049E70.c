#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002D2D4();                      /* extern */
M2C_UNK func_8004A0C0(s8, s16, s16, s32); /* extern */

void func_80049E70(void* arg0, s8 arg1) {
    func_8004A0C0(arg1, M2C_FIELD(arg0, s16*, 0xA), M2C_FIELD(arg0, s16*, 0xE),
                  (func_8002D2D4() & 1) ^ 1);
}
