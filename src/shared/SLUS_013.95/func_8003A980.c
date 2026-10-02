#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8003CDBC();      /* extern */
M2C_UNK func_8003CE30(void*); /* extern */

void func_8003A980(void* arg0) {
    M2C_FIELD(arg0, s8*, 0xCF) = 1;
    M2C_FIELD(arg0, s8*, 0x84) = 0;
    M2C_FIELD(arg0, s8*, 0x8C) = 0;
    func_8003CDBC();
    func_8003CE30(arg0);
}
