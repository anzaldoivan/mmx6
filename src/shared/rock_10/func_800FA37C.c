#include "common.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800FA37C(void* arg0) {
    s8 st = M2C_FIELD(M2C_FIELD(arg0, void**, 0x7C), s8*, 7);

    if (st == 1) {
        M2C_FIELD(arg0, u8*, 6) = 2;
    } else if (st == 2) {
        if (M2C_FIELD(arg0, u8*, 0x15) == 0) {
            M2C_FIELD(arg0, u8*, 0x15) = 0x40;
        } else {
            M2C_FIELD(arg0, u8*, 0x15) = 0;
        }
        M2C_FIELD(arg0, u8*, 6) = 3;
    }
}
