#include "common.h"
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F5940(u8* arg0) {
    if (M2C_FIELD(arg0, s8*, 0x2) != 2) {
        if (M2C_FIELD(arg0, s8*, 0x45) == 1) {
            M2C_FIELD(arg0, u8*, 0x4) = M2C_FIELD(arg0, u8*, 0x4) + 1;
        }
    } else if (M2C_FIELD(M2C_FIELD(arg0, u8**, 0x50), s8*, 0x45) == 4) {
        M2C_FIELD(arg0, u8*, 0x4) = M2C_FIELD(arg0, u8*, 0x4) + 1;
    }
}
