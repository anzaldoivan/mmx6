#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002CB50(); /* extern */
extern s32 D_80097420;

void func_80048524(void* arg0) {
    M2C_FIELD(arg0, s8*, 3) = 0;
    if (D_80097420 & 0x10) {
        ((M2C_UNK(*)())func_8002CB50)();
    }
}
