#include "common.h"
#include "mmx6/globals.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

void func_800F04A8(void* arg0) {
    M2C_FIELD(arg0, s8*, 3) = 1;
    M2C_FIELD(arg0, s8*, 0x47) = (s8)(default_options + 6);
}
