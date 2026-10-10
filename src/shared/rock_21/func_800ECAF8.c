#include "common.h"

#define NULL ((void*)0)
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* func_8002C530(); /* extern */

void func_800ECAF8(void* arg0) {
    void* temp_v0;

    temp_v0 = func_8002C530();
    if (temp_v0 != NULL) {
        M2C_FIELD(temp_v0, s8*, 0) = 0x41;
        M2C_FIELD(temp_v0, s8*, 1) = 0x38;
        M2C_FIELD(temp_v0, s8*, 2) = (s8)(M2C_FIELD(arg0, u8*, 2) + 1);
        M2C_FIELD(temp_v0, s32*, 0x54) = (s32)M2C_FIELD(arg0, s32*, 0x54);
    }
}
