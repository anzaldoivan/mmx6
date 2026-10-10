#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8003015C();               /* extern */
M2C_UNK func_8003CA70(void*, s16); /* extern */

void func_8003D34C(void* arg0) {
    if (func_8003015C() == 0x24) {
        func_8003CA70(arg0, (s16)(M2C_FIELD(arg0, u16*, 0xE) & 0xFFF0));
    }
}
