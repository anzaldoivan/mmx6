#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

s32 func_8002CB50(struct X4_BaseObj*); /* extern */
extern u8 D_80097427;

void func_80046D78(void* arg0) {
    s16 var_v0;

    if (M2C_FIELD(arg0, s16*, 0xE) != 0x10) {
        var_v0 = 0x7C10;
        if (M2C_FIELD(arg0, s8*, 7) == D_80097427) {
            var_v0 = 0x7C12;
        }
        M2C_FIELD(arg0, s16*, 0x42) = var_v0;
    }
    ((s32(*)())func_8002CB50)(arg0, arg0);
}
