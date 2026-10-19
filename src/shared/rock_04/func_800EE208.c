#include "common.h"
#define M2C_UNK s32

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s8 D_80097180;
extern void (*D_800F6C34[])(void*);

void func_800EE208(void* arg0) {
    if (D_80097180 != 2) {
        D_800F6C34[M2C_FIELD(arg0, s8*, 4)](arg0);
    }
}
