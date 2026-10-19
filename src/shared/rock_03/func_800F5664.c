#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

M2C_UNK func_8002F288(M2C_UNK*);
extern void (*D_800F7D54[])(void*);

void func_800F5664(void* arg0) {
    M2C_FIELD(arg0, s8*, 3) = 0;
    D_800F7D54[M2C_FIELD(arg0, s8*, 4)](arg0);
    func_8002F288(arg0);
}
