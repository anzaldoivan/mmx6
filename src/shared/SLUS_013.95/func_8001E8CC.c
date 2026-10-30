#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void set_resolution(s32 arg0); /* extern */
M2C_UNK func_80013DE8();       /* extern */

void func_8001E8CC(void* arg0) {
    M2C_FIELD(arg0, s8*, 0) = 4;
    M2C_FIELD(arg0, s8*, 0xC) = 0xD;
    M2C_FIELD(arg0, s8*, 0xD) = 0;
    M2C_FIELD(arg0, s8*, 0x1D) = 0;
    func_80013DE8();
    set_resolution(1);
}
