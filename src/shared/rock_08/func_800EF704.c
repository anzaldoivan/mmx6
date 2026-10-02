#include "common.h"

#define M2C_UNK s32
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_80016C48(M2C_UNK, M2C_UNK, void*); /* extern */
M2C_UNK func_8002CA14(void*);                   /* extern */

void func_800EF704(void* arg0) {
    func_80016C48(2, 0x54, arg0);
    M2C_FIELD(arg0, s8*, 3) = 0;
    func_8002CA14(arg0);
}
