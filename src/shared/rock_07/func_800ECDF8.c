#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK func_8002C9B0(void*);                   /* extern */

void func_800ECDF8(void* arg0) {
    if ((M2C_FIELD(arg0, s8*, 2) & 0xF0) == 0x30) {
        func_80016C48(2, 0x14, arg0);
    }
    func_8002C9B0(arg0);
}
