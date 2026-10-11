#include "common.h"

#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8*)(expr) + (offset)))

extern s8 D_8009716C;
extern u8 D_800FA900[];

void func_800EC970(void* arg0) {
    if (D_8009716C == 0) {
        ((void (**)(void*))(D_800FA900 + 0x16B0))[M2C_FIELD(arg0, s8*, 0x4)](
            arg0);
    }
}
