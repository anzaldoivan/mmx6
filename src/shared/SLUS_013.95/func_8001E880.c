#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80012890(M2C_UNK); /* extern */
M2C_UNK func_80013BF0();        /* extern */
M2C_UNK func_8002B838();        /* extern */

void func_8001E880(void* arg0) {
    func_80012890(0);
    func_8002B838();
    func_80013BF0();
    M2C_FIELD(arg0, s8*, 0) = 8;
    M2C_FIELD(arg0, s8*, 1) = 0;
    M2C_FIELD(arg0, s8*, 2) = 0;
    M2C_FIELD(arg0, s8*, 3) = 0;
}
