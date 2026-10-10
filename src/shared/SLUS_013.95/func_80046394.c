#include "common.h"

#define NULL ((void*)0)
#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void* func_8003D480(M2C_UNK, s8, s8, void*); /* extern */

void func_80046394(void* arg0) {
    void* temp_s0;
    void* temp_v0;

    temp_s0 = M2C_FIELD(arg0, void**, 0x7C);
    if (M2C_FIELD(temp_s0, s8*, 0x91) != 0) {
        M2C_FIELD(arg0, s8*, 4) = 3;
        return;
    }
    if (M2C_FIELD(temp_s0, s8*, 0x8F) != 0) {
        temp_v0 = func_8003D480(1, M2C_FIELD(arg0, s8*, 1),
                                (s8)(M2C_FIELD(arg0, u8*, 2) + 4), arg0);
        if (temp_v0 != NULL) {
            M2C_FIELD(temp_s0, u8*, 7) = (u8)(M2C_FIELD(temp_s0, u8*, 7) + 1);
            M2C_FIELD(temp_v0, void**, 0x7C) = temp_s0;
        }
    } else if (M2C_FIELD(temp_s0, s8*, 0x8D) != 0) {
        M2C_FIELD(arg0, s8*, 0x8E) = 0;
        M2C_FIELD(arg0, u8*, 5) = (u8)(M2C_FIELD(arg0, u8*, 5) + 1);
    }
}
