#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s16 D_800970AA;

void func_800EE524(void* arg0) {
    if ((D_800970AA - M2C_FIELD(arg0, s16*, 0xA)) >= 0xB0) {
        M2C_FIELD(arg0, s8*, 0x15) = 0x40;
        M2C_FIELD(arg0, s8*, 4) = 1;
        M2C_FIELD(arg0, s8*, 5) = 3;
    }
}
