#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002C9B0(); /* extern */
extern u16 D_800FDA7C;
extern u16 D_800FDA7E;

void func_800F8638(void* arg0) {
    s32 temp_v1;

    temp_v1 = M2C_FIELD(arg0, s8*, 2) & 0xF0;
    if (temp_v1 == 0) {
        D_800FDA7C -= 1;
    } else if (temp_v1 == 0x10) {
        D_800FDA7E -= 1;
    }
    ((M2C_UNK(*)())func_8002C9B0)();
}
