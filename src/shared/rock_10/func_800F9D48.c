#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F74D8(void* arg0, s16 arg1, s16 arg2, u8 arg3);

void func_800F9D48(void* arg0) {
    u8 s = M2C_FIELD(arg0, u8*, 0x88);

    if (s == 1) {
        func_800F74D8(arg0, M2C_FIELD(arg0, s16*, 0xA),
                      M2C_FIELD(arg0, s16*, 0xE), 0x20);
        M2C_FIELD(arg0, u8*, 0x89) = s;
        M2C_FIELD(arg0, s16*, 0x7C) = 7;
        M2C_FIELD(arg0, u8*, 5) += 1;
    }
}
