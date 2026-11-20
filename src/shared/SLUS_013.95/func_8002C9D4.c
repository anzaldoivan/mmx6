#include "common.h"

#define NULL ((void*)0)
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002C9B0(); /* extern */

void func_8002C9D4(void* arg0) {
    u8* temp_v1;

    temp_v1 = M2C_FIELD(arg0, u8**, 0x10);
    if (temp_v1 != NULL) {
        *temp_v1 |= 0x80;
    }
    func_8002C9B0();
}
